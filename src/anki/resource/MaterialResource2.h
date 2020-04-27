// Copyright (C) 2009-2020, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include <anki/resource/ResourceObject.h>
#include <anki/resource/RenderingKey.h>
#include <anki/resource/ShaderProgramResource2.h>
#include <anki/Math.h>
#include <anki/util/Enum.h>

namespace anki
{

// Forward
class XmlElement;

/// @addtogroup resource
/// @{

/// The ID of a buildin material variable
enum class BuiltinMaterialVariableId2 : U8
{
	NONE = 0,
	MODEL_VIEW_PROJECTION_MATRIX,
	PREVIOUS_MODEL_VIEW_PROJECTION_MATRIX,
	MODEL_MATRIX,
	VIEW_MATRIX,
	PROJECTION_MATRIX,
	MODEL_VIEW_MATRIX,
	VIEW_PROJECTION_MATRIX,
	NORMAL_MATRIX,
	ROTATION_MATRIX,
	CAMERA_ROTATION_MATRIX,
	CAMERA_POSITION,
	GLOBAL_SAMPLER,

	COUNT,
	FIRST = 0,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(BuiltinMaterialVariableId2, inline)

/// Holds the shader variables. It's a container for shader program variables that share the same name.
class MaterialVariable2 : public NonCopyable
{
	friend class MaterialVariant2;
	friend class MaterialResource2;

public:
	MaterialVariable2();

	MaterialVariable2(MaterialVariable2&& b)
	{
		*this = std::move(b);
	}

	~MaterialVariable2();

	MaterialVariable2& operator=(MaterialVariable2&& b)
	{
		m_name = std::move(b.m_name);
		m_index = b.m_index;
		m_indexInBinary = b.m_indexInBinary;
		m_indexInBinary2ndElement = b.m_indexInBinary2ndElement;
		m_constant = b.m_constant;
		m_instanced = b.m_instanced;
		m_dataType = b.m_dataType;
		m_builtin = b.m_builtin;
		m_mat4 = b.m_mat4;
		m_tex = std::move(b.m_tex);
		return *this;
	}

	/// Get the builtin info.
	BuiltinMaterialVariableId2 getBuiltin() const
	{
		return m_builtin;
	}

	CString getName() const
	{
		return m_name;
	}

	template<typename T>
	const T& getValue() const;

	Bool isTexture() const
	{
		return m_dataType >= ShaderVariableDataType::TEXTURE_FIRST
			   && m_dataType <= ShaderVariableDataType::TEXTURE_LAST;
	}

	Bool isSampler() const
	{
		return m_dataType == ShaderVariableDataType::SAMPLER;
	}

	Bool inBlock() const
	{
		return !m_constant && !isTexture() && !isSampler();
	}

	Bool isConstant() const
	{
		return m_constant;
	}

	Bool isInstanced() const
	{
		return m_instanced;
	}

	Bool isBuildin() const
	{
		return m_builtin != BuiltinMaterialVariableId2::NONE;
	}

	ShaderVariableDataType getDataType() const
	{
		ANKI_ASSERT(m_dataType != ShaderVariableDataType::NONE);
		return m_dataType;
	}

protected:
	static constexpr F32 NO_VALUE = 1234.5678f;

	String m_name;
	U32 m_index = MAX_U32;
	U32 m_indexInBinary = MAX_U32;
	U32 m_indexInBinary2ndElement = MAX_U32;
	Bool m_constant = false;
	Bool m_instanced = false;
	ShaderVariableDataType m_dataType = ShaderVariableDataType::NONE;
	BuiltinMaterialVariableId2 m_builtin = BuiltinMaterialVariableId2::NONE;

	/// Values for non-builtins
	/// @{
	union
	{
		I32 m_int;
		IVec2 m_ivec2;
		IVec3 m_ivec3;
		IVec4 m_ivec4;
		U32 m_uint;
		UVec2 m_uvec2;
		UVec3 m_uvec3;
		UVec4 m_uvec4;
		F32 m_float;
		Vec2 m_vec2;
		Vec3 m_vec3;
		Vec4 m_vec4;
		Mat3 m_mat3;
		Mat4 m_mat4;
	};

	TextureResourcePtr m_tex;
	/// @}

	Bool valueSetByMaterial() const
	{
		return m_tex.isCreated() || m_mat4(3, 3) != NO_VALUE;
	}
};

// Specialize the MaterialVariable::getValue
#define ANKI_SPECIALIZE_GET_VALUE(t_, var_, shaderType_) \
	template<> \
	inline const t_& MaterialVariable2::getValue<t_>() const \
	{ \
		ANKI_ASSERT(m_dataType == ShaderVariableDataType::shaderType_); \
		ANKI_ASSERT(m_builtin == BuiltinMaterialVariableId2::NONE); \
		return var_; \
	}

ANKI_SPECIALIZE_GET_VALUE(I32, m_int, INT)
ANKI_SPECIALIZE_GET_VALUE(IVec2, m_ivec2, IVEC2)
ANKI_SPECIALIZE_GET_VALUE(IVec3, m_ivec3, IVEC3)
ANKI_SPECIALIZE_GET_VALUE(IVec4, m_ivec4, IVEC4)
ANKI_SPECIALIZE_GET_VALUE(U32, m_uint, UINT)
ANKI_SPECIALIZE_GET_VALUE(UVec2, m_uvec2, UVEC2)
ANKI_SPECIALIZE_GET_VALUE(UVec3, m_uvec3, UVEC3)
ANKI_SPECIALIZE_GET_VALUE(UVec4, m_uvec4, UVEC4)
ANKI_SPECIALIZE_GET_VALUE(F32, m_float, FLOAT)
ANKI_SPECIALIZE_GET_VALUE(Vec2, m_vec2, VEC2)
ANKI_SPECIALIZE_GET_VALUE(Vec3, m_vec3, VEC3)
ANKI_SPECIALIZE_GET_VALUE(Vec4, m_vec4, VEC4)
ANKI_SPECIALIZE_GET_VALUE(Mat3, m_mat3, MAT3)
ANKI_SPECIALIZE_GET_VALUE(Mat4, m_mat4, MAT4)

template<>
inline const TextureResourcePtr& MaterialVariable2::getValue() const
{
	ANKI_ASSERT(isTexture());
	ANKI_ASSERT(m_builtin == BuiltinMaterialVariableId2::NONE);
	return m_tex;
}

#undef ANKI_SPECIALIZE_GET_VALUE

/// Material variant.
class MaterialVariant2 : public NonCopyable
{
	friend class MaterialResource2;

public:
	/// Return true of the the variable is active.
	Bool isVariableActive(const MaterialVariable2& var) const
	{
		return m_activeVars.get(var.m_index);
	}

	const ShaderProgramPtr& getShaderProgram() const
	{
		return m_prog;
	}

	U32 getUniformBlockSize() const
	{
		return m_uniBlockSize;
	}

	U32 getOpaqueBinding(const MaterialVariable2& var) const
	{
		ANKI_ASSERT(m_opaqueBindings[var.m_index] >= 0);
		return U32(m_opaqueBindings[var.m_index]);
	}

	const ShaderVariableBlockInfo& getBlockInfo(const MaterialVariable2& var) const
	{
		ANKI_ASSERT(var.inBlock());
		ANKI_ASSERT(m_blockInfos[var.m_index].m_offset >= 0);
		return m_blockInfos[var.m_index];
	}

private:
	ShaderProgramPtr m_prog;
	DynamicArray<ShaderVariableBlockInfo> m_blockInfos;
	DynamicArray<I16> m_opaqueBindings;
	BitSet<128, U32> m_activeVars = {false};
	U32 m_uniBlockSize = 0;
};

/// Material resource.
///
/// Material XML file format:
/// @code
/// <material
///		[shadow="0 | 1"]
///		[forwardShading="0 | 1"]
///		<shaderProgram="path"/>
///
///		[<mutation>
///			<mutator name="str" value="value"/>
///		</mutation>]
///
///		[<inputs>
///			<input shaderVar="name to shaderProg var" value="values"/> (1)
///		</inputs>]
/// </material>
/// @endcode
/// (1): Only for non-builtins.
class MaterialResource2 : public ResourceObject
{
public:
	MaterialResource2(ResourceManager* manager);

	~MaterialResource2();

	/// Load a material file
	ANKI_USE_RESULT Error load(const ResourceFilename& filename, Bool async);

	U32 getLodCount() const
	{
		return m_lodCount;
	}

	Bool castsShadow() const
	{
		return m_shadow;
	}

	Bool hasTessellation() const
	{
		return m_prog;
	}

	Bool isForwardShading() const
	{
		return m_forwardShading;
	}

	Bool isInstanced() const
	{
		return m_instancingMutator != nullptr;
	}

	ConstWeakArray<MaterialVariable2> getVariables() const
	{
		return m_vars;
	}

	U32 getDescriptorSetIndex() const
	{
		return m_descriptorSetIdx;
	}

	const MaterialVariant2& getOrCreateVariant(const RenderingKey& key) const;

private:
	class SubMutation
	{
	public:
		const ShaderProgramResourceMutator2* m_mutator;
		MutatorValue m_value;
	};

	ShaderProgramResource2Ptr m_prog;

	const ShaderProgramResourceMutator2* m_instancingMutator = nullptr;
	const ShaderProgramResourceMutator2* m_passMutator = nullptr;
	const ShaderProgramResourceMutator2* m_lodMutator = nullptr;
	const ShaderProgramResourceMutator2* m_bonesMutator = nullptr;
	const ShaderProgramResourceMutator2* m_velocityMutator = nullptr;

	Bool m_shadow = true;
	Bool m_forwardShading = false;
	U8 m_lodCount = 1;
	U8 m_descriptorSetIdx = 0; ///< The material set.
	U32 m_uboIdx = MAX_U32; ///< The b_ankiMaterial UBO inside the binary.

	/// Matrix of variants.
	mutable Array5d<MaterialVariant2, U(Pass::COUNT), MAX_LOD_COUNT, MAX_INSTANCE_GROUPS, 2, 2> m_variantMatrix;
	mutable RWMutex m_variantMatrixMtx;

	DynamicArray<MaterialVariable2> m_vars;

	DynamicArray<SubMutation> m_nonBuiltinsMutation;

	ANKI_USE_RESULT Error createVars();

	static ANKI_USE_RESULT Error parseVariable(CString fullVarName, Bool& instanced, U32& idx, CString& name);

	/// Parse whatever is inside the <inputs> tag.
	ANKI_USE_RESULT Error parseInputs(XmlElement inputsEl, Bool async);

	ANKI_USE_RESULT Error parseMutators(XmlElement mutatorsEl);

	static U32 getInstanceGroupIdx(U32 instanceCount);

	void initVariant(
		const ShaderProgramResourceVariant2& progVariant, MaterialVariant2& variant, U32 instanceCount) const;

	const MaterialVariable2* tryFindVariableInternal(CString name) const
	{
		for(const MaterialVariable2& v : m_vars)
		{
			if(v.m_name == name)
			{
				return &v;
			}
		}

		return nullptr;
	}

	const MaterialVariable2* tryFindVariable(CString name) const
	{
		return tryFindVariableInternal(name);
	}

	MaterialVariable2* tryFindVariable(CString name)
	{
		return const_cast<MaterialVariable2*>(tryFindVariableInternal(name));
	}
};
/// @}

} // end namespace anki
