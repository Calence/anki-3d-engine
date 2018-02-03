// Copyright (C) 2009-2018, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include <anki/gr/vulkan/ShaderImpl.h>
#include <anki/gr/vulkan/GrManagerImpl.h>
#include <anki/gr/common/Misc.h>
#include <anki/core/Trace.h>
#include <SPIRV-Cross/spirv_cross.hpp>

#define ANKI_DUMP_SHADERS ANKI_EXTRA_CHECKS

#if ANKI_DUMP_SHADERS
#include <anki/util/File.h>
#include <anki/gr/GrManager.h>
#endif

namespace anki
{

ShaderImpl::~ShaderImpl()
{
	for(auto& x : m_bindings)
	{
		x.destroy(getAllocator());
	}

	if(m_handle)
	{
		vkDestroyShaderModule(getDevice(), m_handle, nullptr);
	}
}

Error ShaderImpl::init(const ShaderInitInfo& inf)
{
	ANKI_ASSERT(inf.m_binary.getSize() > 0);
	ANKI_ASSERT(m_handle == VK_NULL_HANDLE);
	m_shaderType = inf.m_shaderType;

#if ANKI_DUMP_SHADERS
	{
		static U32 name = 0;
		SpinLock m_nameLock;

		U32 newName;
		{
			LockGuard<SpinLock> lock(m_nameLock);
			newName = name++;
		}

		StringAuto fnameSpirv(getAllocator());
		fnameSpirv.sprintf("%s/%05u.spv", getManager().getCacheDirectory().cstr(), newName);

		File fileSpirv;
		ANKI_CHECK(fileSpirv.open(fnameSpirv.toCString(), FileOpenFlag::BINARY | FileOpenFlag::WRITE));
		ANKI_CHECK(fileSpirv.write(&inf.m_binary[0], inf.m_binary.getSize()));
	}
#endif

	VkShaderModuleCreateInfo ci = {VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
		nullptr,
		0,
		inf.m_binary.getSize(),
		reinterpret_cast<const uint32_t*>(&inf.m_binary[0])};

	ANKI_VK_CHECK(vkCreateShaderModule(getDevice(), &ci, nullptr, &m_handle));

	// Get reflection info
	doReflection(inf.m_binary);

	return Error::NONE;
}

void ShaderImpl::doReflection(ConstWeakArray<U8> spirv)
{
	spirv_cross::Compiler spvc(reinterpret_cast<const uint32_t*>(&spirv[0]), spirv.getSize() / sizeof(unsigned int));
	spirv_cross::ShaderResources rsrc = spvc.get_shader_resources();
	spirv_cross::ShaderResources rsrcActive = spvc.get_shader_resources(spvc.get_active_interface_variables());

	Array<U, MAX_DESCRIPTOR_SETS> counts = {{
		0,
	}};
	Array2d<DescriptorBinding, MAX_DESCRIPTOR_SETS, MAX_BINDINGS_PER_DESCRIPTOR_SET> descriptors;

	auto func = [&](const std::vector<spirv_cross::Resource>& resources, DescriptorType type) -> void {
		for(const spirv_cross::Resource& r : resources)
		{
			const U32 id = r.id;
			const U32 set = spvc.get_decoration(id, spv::Decoration::DecorationDescriptorSet);
			const U32 binding = spvc.get_decoration(id, spv::Decoration::DecorationBinding);

			m_descriptorSetMask.set(set);
			m_activeBindingMask[set].set(set);

			// Check that there are no other descriptors with the same binding
			for(U i = 0; i < counts[set]; ++i)
			{
				ANKI_ASSERT(descriptors[set][i].m_binding != binding);
			}

			DescriptorBinding& descriptor = descriptors[set][counts[set]++];
			descriptor.m_binding = binding;
			descriptor.m_type = type;
			descriptor.m_stageMask = static_cast<ShaderTypeBit>(1 << m_shaderType);
		}
	};

	func(rsrc.uniform_buffers, DescriptorType::UNIFORM_BUFFER);
	func(rsrc.sampled_images, DescriptorType::TEXTURE);
	func(rsrc.storage_buffers, DescriptorType::STORAGE_BUFFER);
	func(rsrc.storage_images, DescriptorType::IMAGE);

	for(U set = 0; set < MAX_DESCRIPTOR_SETS; ++set)
	{
		if(counts[set])
		{
			m_bindings[set].create(getAllocator(), counts[set]);
			memcpy(&m_bindings[set][0], &descriptors[set][0], counts[set] * sizeof(DescriptorBinding));
		}
	}

	// Color attachments
	if(m_shaderType == ShaderType::FRAGMENT)
	{
		for(const spirv_cross::Resource& r : rsrc.stage_outputs)
		{
			const U32 id = r.id;
			const U32 location = spvc.get_decoration(id, spv::Decoration::DecorationLocation);

			m_colorAttachmentWritemask.set(location);
		}
	}

	// Attribs
	if(m_shaderType == ShaderType::VERTEX)
	{
		for(const spirv_cross::Resource& r : rsrcActive.stage_inputs)
		{
			const U32 id = r.id;
			const U32 location = spvc.get_decoration(id, spv::Decoration::DecorationLocation);

			m_attributeMask.set(location);
		}
	}
}

} // end namespace anki
