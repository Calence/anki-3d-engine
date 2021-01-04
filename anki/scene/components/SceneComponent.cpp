// Copyright (C) 2009-2020, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include <anki/scene/components/SceneComponent.h>

namespace anki
{

constexpr U32 MAX_SCENE_COMPONENT_CLASSES = 64;
static_assert(MAX_SCENE_COMPONENT_CLASSES < MAX_U8, "See file");
static SceneComponentRtti* g_rttis[MAX_SCENE_COMPONENT_CLASSES] = {};
static U32 g_rttiCount = 0;

SceneComponentRtti::SceneComponentRtti(const char* name, U32 size, U32 alignment, Constructor constructor)
{
	U32 index = g_rttiCount++;

	m_constructorCallback = constructor;
	m_className = name;
	m_classSize = size;
	m_classAlignment = alignment;
	m_classId = U8(index);

	if(index >= MAX_SCENE_COMPONENT_CLASSES)
	{
		// Force a crash because this function is called before main
		index = MAX_U32;
	}

	g_rttis[index] = this;
}

SceneComponent::SceneComponent(SceneNode* node, U8 classId)
	: m_classId(classId)
{
	ANKI_ASSERT(m_classId < g_rttiCount);
}

const SceneComponentRtti& SceneComponent::findClassRtti(CString className)
{
	for(U32 i = 0; i < g_rttiCount; ++i)
	{
		ANKI_ASSERT(g_rttis[i]);
		ANKI_ASSERT(g_rttis[i]->m_className);
		if(g_rttis[i]->m_className == className)
		{
			return *g_rttis[i];
		}
	}

	ANKI_ASSERT(0);
	return *g_rttis[0];
}

const SceneComponentRtti& SceneComponent::findClassRtti(U8 classId)
{
	ANKI_ASSERT(classId < g_rttiCount);
	ANKI_ASSERT(g_rttis[classId]);
	return *g_rttis[classId];
}

} // namespace anki
