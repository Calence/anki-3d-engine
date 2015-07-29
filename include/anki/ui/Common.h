// Copyright (C) 2009-2015, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include "anki/Math.h"
#include "anki/util/Allocator.h"

namespace anki {

// Forward
class Widget;
class Canvas;

/// @addtogroup ui
/// @{

using UiAllocator = GenericMemoryPoolAllocator<U8>;

/// Color.
using Color = Vec4;

/// Used in widget classes.
#define ANKI_WIDGET \
	friend class Canvas;
/// @}

} // end namespace anki

