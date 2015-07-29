// Copyright (C) 2009-2015, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include "anki/scene/Common.h"
#include "anki/scene/SceneComponent.h"
#include "anki/util/Bitset.h"
#include "anki/util/Enum.h"
#include "anki/Math.h"

namespace anki {

/// @addtogroup scene
/// @{

enum class MoveComponentFlag: U8
{
	NONE = 0,

	/// Get the parent's world transform
	IGNORE_LOCAL_TRANSFORM = 1 << 1,

	/// Ignore parent's transform
	IGNORE_PARENT_TRANSFORM = 1 << 2,

	/// If dirty then is marked for update
	MARKED_FOR_UPDATE = 1 << 3,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(MoveComponentFlag, inline)

/// Interface for movable scene nodes
class MoveComponent: public SceneComponent, public Bitset<MoveComponentFlag>
{
public:
	using Flag = MoveComponentFlag;

	static Bool classof(const SceneComponent& c)
	{
		return c.getType() == Type::MOVE;
	}

	/// The one and only constructor
	/// @param node The scene node to steal it's allocators
	/// @param flags The flags
	MoveComponent(SceneNode* node, Flag flags = Flag::NONE);

	~MoveComponent();

	const Transform& getLocalTransform() const
	{
		return m_ltrf;
	}

	void setLocalTransform(const Transform& x)
	{
		m_ltrf = x;
		markForUpdate();
	}

	void setLocalOrigin(const Vec4& x)
	{
		m_ltrf.setOrigin(x);
		markForUpdate();
	}

	const Vec4& getLocalOrigin() const
	{
		return m_ltrf.getOrigin();
	}

	void setLocalRotation(const Mat3x4& x)
	{
		m_ltrf.setRotation(x);
		markForUpdate();
	}

	const Mat3x4& getLocalRotation() const
	{
		return m_ltrf.getRotation();
	}

	void setLocalScale(F32 x)
	{
		m_ltrf.setScale(x);
		markForUpdate();
	}

	F32 getLocalScale() const
	{
		return m_ltrf.getScale();
	}

	const Transform& getWorldTransform() const
	{
		return m_wtrf;
	}

	const Transform& getPreviousWorldTransform() const
	{
		return m_prevWTrf;
	}

	/// Called when there is an update in the world transformation.
	virtual ANKI_USE_RESULT Error onMoveComponentUpdate(
		SceneNode& node, F32 prevTime, F32 crntTime)
	{
		return ErrorCode::NONE;
	}

	/// @name SceneComponent overrides
	/// @{

	/// Update self and children world transform recursively, if root node.
	/// Need to call this at every frame.
	/// @note Don't update if child because we start from roots and go to
	///       children and we don't want a child to be updated before the
	///       parent
	ANKI_USE_RESULT Error update(SceneNode&, F32, F32, Bool& updated) override;

	ANKI_USE_RESULT Error onUpdate(
		SceneNode& node, F32 prevTime, F32 crntTime) final
	{
		return onMoveComponentUpdate(node, prevTime, crntTime);
	}
	/// @}

	/// @name Mess with the local transform
	/// @{
	void rotateLocalX(F32 angDegrees)
	{
		m_ltrf.getRotation().rotateXAxis(angDegrees);
		markForUpdate();
	}
	void rotateLocalY(F32 angDegrees)
	{
		m_ltrf.getRotation().rotateYAxis(angDegrees);
		markForUpdate();
	}
	void rotateLocalZ(F32 angDegrees)
	{
		m_ltrf.getRotation().rotateZAxis(angDegrees);
		markForUpdate();
	}
	void moveLocalX(F32 distance)
	{
		Vec3 x_axis = m_ltrf.getRotation().getColumn(0);
		m_ltrf.getOrigin() += Vec4(x_axis, 0.0) * distance;
		markForUpdate();
	}
	void moveLocalY(F32 distance)
	{
		Vec3 y_axis = m_ltrf.getRotation().getColumn(1);
		m_ltrf.getOrigin() += Vec4(y_axis, 0.0) * distance;
		markForUpdate();
	}
	void moveLocalZ(F32 distance)
	{
		Vec3 z_axis = m_ltrf.getRotation().getColumn(2);
		m_ltrf.getOrigin() += Vec4(z_axis, 0.0) * distance;
		markForUpdate();
	}
	void scale(F32 s)
	{
		m_ltrf.getScale() *= s;
		markForUpdate();
	}
	/// @}

private:
	/// The transformation in local space
	Transform m_ltrf = Transform::getIdentity();

	/// The transformation in world space (local combined with parent's
	/// transformation)
	Transform m_wtrf = Transform::getIdentity();

	/// Keep the previous transformation for checking if it moved
	Transform m_prevWTrf = Transform::getIdentity();

	void markForUpdate()
	{
		enableBits(Flag::MARKED_FOR_UPDATE);
	}

	/// Called every frame. It updates the @a m_wtrf if @a shouldUpdateWTrf
	/// is true. Then it moves to the children.
	Bool updateWorldTransform(SceneNode& node);
};
/// @}

} // end namespace anki

