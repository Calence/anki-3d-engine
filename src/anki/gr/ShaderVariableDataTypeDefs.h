// Copyright (C) 2009-2020, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

// ShaderVariableDataType defines

#if defined(ANKI_SVDT_MACRO)
ANKI_SVDT_MACRO(INT, I32)
ANKI_SVDT_MACRO(UINT, U32)
ANKI_SVDT_MACRO(FLOAT, F32)

ANKI_SVDT_MACRO(IVEC2, IVec2)
ANKI_SVDT_MACRO(UVEC2, UVec2)
ANKI_SVDT_MACRO(VEC2, Vec2)

ANKI_SVDT_MACRO(IVEC3, IVec3)
ANKI_SVDT_MACRO(UVEC3, UVec3)
ANKI_SVDT_MACRO(VEC3, Vec3)

ANKI_SVDT_MACRO(IVEC4, IVec4)
ANKI_SVDT_MACRO(UVEC4, UVec4)
ANKI_SVDT_MACRO(VEC4, Vec4)

ANKI_SVDT_MACRO(MAT3, Mat3)
ANKI_SVDT_MACRO(MAT3X4, Mat3x4)
ANKI_SVDT_MACRO(MAT4, Mat4)
#endif

#if defined(ANKI_SVDT_MACRO_2)
ANKI_SVDT_MACRO_2(TEXTURE_1D, texture1D)
ANKI_SVDT_MACRO_2(TEXTURE_1D_ARRAY, texture1DArray)
ANKI_SVDT_MACRO_2(TEXTURE_2D, texture2D)
ANKI_SVDT_MACRO_2(TEXTURE_2D_ARRAY, texture2DArray)
ANKI_SVDT_MACRO_2(TEXTURE_3D, texture3D)
ANKI_SVDT_MACRO_2(TEXTURE_CUBE, textureCube)
ANKI_SVDT_MACRO_2(TEXTURE_CUBE_ARRAY, textureCubeArray)

ANKI_SVDT_MACRO_2(IMAGE_1D, image1D)
ANKI_SVDT_MACRO_2(IMAGE_1D_ARRAY, image1DArray)
ANKI_SVDT_MACRO_2(IMAGE_2D, image2D)
ANKI_SVDT_MACRO_2(IMAGE_2D_ARRAY, image2DArray)
ANKI_SVDT_MACRO_2(IMAGE_3D, image3D)
ANKI_SVDT_MACRO_2(IMAGE_CUBE, imageCube)
ANKI_SVDT_MACRO_2(IMAGE_CUBE_ARRAY, imageCubeArray)

ANKI_SVDT_MACRO_2(SAMPLER, sampler)
#endif
