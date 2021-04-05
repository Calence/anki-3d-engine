// Copyright (C) 2009-2021, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

// Defines the pixel and vertex formats. Params:
// 1) Name
// 2) ID (same as Vulkan)
// 3) Component count
// 4) Texel size in bytes (for uncompressed)
// 5) Block width (for compressed)
// 6) Block height (for compressed)
// 7) Block size in bytes (for compressed)
// 8) Read type from inside the shader (0: float, 1: unsigned int, 2: signed int)
// 9) Aspect

// clang-format off
//              Name                        ID  CC  TS  BW  BH  BS  ST         ASPECT
ANKI_FORMAT_DEF(R4G4_UNORM_PACK8,            1,  2,  1,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R4G4B4A4_UNORM_PACK16,       2,  4,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B4G4R4A4_UNORM_PACK16,       3,  4,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R5G6B5_UNORM_PACK16,         4,  3,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B5G6R5_UNORM_PACK16,         5,  3,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R5G5B5A1_UNORM_PACK16,       6,  4,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B5G5R5A1_UNORM_PACK16,       7,  4,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A1R5G5B5_UNORM_PACK16,       8,  4,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8_UNORM,                    9,  1,  1,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8_SNORM,                   10,  1,  1,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8_USCALED,                 11,  1,  1,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8_SSCALED,                 12,  1,  1,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8_UINT,                    13,  1,  1,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8_SINT,                    14,  1,  1,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8_SRGB,                    15,  1,  1,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8_UNORM,                 16,  2,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8_SNORM,                 17,  2,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8_USCALED,               18,  2,  2,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8_SSCALED,               19,  2,  2,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8_UINT,                  20,  2,  2,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8_SINT,                  21,  2,  2,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8_SRGB,                  22,  2,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8_UNORM,               23,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8_SNORM,               24,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8_USCALED,             25,  3,  3,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8B8_SSCALED,             26,  3,  3,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8B8_UINT,                27,  3,  3,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8B8_SINT,                28,  3,  3,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8B8_SRGB,                29,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8_UNORM,               30,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8_SNORM,               31,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8_USCALED,             32,  3,  3,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(B8G8R8_SSCALED,             33,  3,  3,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(B8G8R8_UINT,                34,  3,  3,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(B8G8R8_SINT,                35,  3,  3,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(B8G8R8_SRGB,                36,  3,  3,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_UNORM,             37,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_SNORM,             38,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_USCALED,           39,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_SSCALED,           40,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_UINT,              41,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_SINT,              42,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R8G8B8A8_SRGB,              43,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_UNORM,             44,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_SNORM,             45,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_USCALED,           46,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_SSCALED,           47,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_UINT,              48,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_SINT,              49,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(B8G8R8A8_SRGB,              50,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_UNORM_PACK32,      51,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_SNORM_PACK32,      52,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_USCALED_PACK32,    53,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_SSCALED_PACK32,    54,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_UINT_PACK32,       55,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_SINT_PACK32,       56,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(A8B8G8R8_SRGB_PACK32,       57,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_UNORM_PACK32,   58,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_SNORM_PACK32,   59,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_USCALED_PACK32, 60,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_SSCALED_PACK32, 61,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_UINT_PACK32,    62,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A2R10G10B10_SINT_PACK32,    63,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_UNORM_PACK32,   64,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_SNORM_PACK32,   65,  4,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_USCALED_PACK32, 66,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_SSCALED_PACK32, 67,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_UINT_PACK32,    68,  4,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(A2B10G10R10_SINT_PACK32,    69,  4,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16_UNORM,                  70,  1,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16_SNORM,                  71,  1,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16_USCALED,                72,  1,  2,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16_SSCALED,                73,  1,  2,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16_UINT,                   74,  1,  2,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16_SINT,                   75,  1,  2,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16_SFLOAT,                 76,  1,  2,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16_UNORM,               77,  2,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16_SNORM,               78,  2,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16_USCALED,             79,  2,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16_SSCALED,             80,  2,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16_UINT,                81,  2,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16_SINT,                82,  2,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16_SFLOAT,              83,  2,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16_UNORM,            84,  3,  6,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16_SNORM,            85,  3,  6,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16_USCALED,          86,  3,  6,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16B16_SSCALED,          87,  3,  6,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16B16_UINT,             88,  3,  6,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16B16_SINT,             89,  3,  6,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16B16_SFLOAT,           90,  3,  6,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_UNORM,         91,  4,  8,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_SNORM,         92,  4,  8,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_USCALED,       93,  4,  8,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_SSCALED,       94,  4,  8,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_UINT,          95,  4,  8,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_SINT,          96,  4,  8,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R16G16B16A16_SFLOAT,        97,  4,  8,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R32_UINT,                   98,  1,  4,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R32_SINT,                   99,  1,  4,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R32_SFLOAT,                100,  1,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R32G32_UINT,               101,  2,  8,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R32G32_SINT,               102,  2,  8,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R32G32_SFLOAT,             103,  2,  8,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R32G32B32_UINT,            104,  3, 12,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R32G32B32_SINT,            105,  3, 12,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R32G32B32_SFLOAT,          106,  3, 12,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R32G32B32A32_UINT,         107,  4, 16,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R32G32B32A32_SINT,         108,  4, 16,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R32G32B32A32_SFLOAT,       109,  4, 16,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R64_UINT,                  110,  1,  8,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R64_SINT,                  111,  1,  8,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R64_SFLOAT,                112,  1,  8,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R64G64_UINT,               113,  2, 16,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R64G64_SINT,               114,  2, 16,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R64G64_SFLOAT,             115,  2, 16,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R64G64B64_UINT,            116,  3, 24,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R64G64B64_SINT,            117,  3, 24,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R64G64B64_SFLOAT,          118,  3, 24,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(R64G64B64A64_UINT,         119,  4, 32,  0,  0,  0,  1,          NONE)
ANKI_FORMAT_DEF(R64G64B64A64_SINT,         120,  4, 32,  0,  0,  0,  2,          NONE)
ANKI_FORMAT_DEF(R64G64B64A64_SFLOAT,       121,  4, 32,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(B10G11R11_UFLOAT_PACK32,   122,  3,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(E5B9G9R9_UFLOAT_PACK32,    123,  3,  4,  0,  0,  0,  0,          NONE)
ANKI_FORMAT_DEF(D16_UNORM,                 124,  0,  2,  0,  0,  0,  0,         DEPTH)
ANKI_FORMAT_DEF(X8_D24_UNORM_PACK32,       125,  0,  4,  0,  0,  0,  0,         DEPTH)
ANKI_FORMAT_DEF(D32_SFLOAT,                126,  0,  4,  0,  0,  0,  0,         DEPTH)
ANKI_FORMAT_DEF(S8_UINT,                   127,  0,  1,  0,  0,  0,  1,       STENCIL)
ANKI_FORMAT_DEF(D16_UNORM_S8_UINT,         128,  0,  3,  0,  0,  0,  0, DEPTH_STENCIL)
ANKI_FORMAT_DEF(D24_UNORM_S8_UINT,         129,  0,  4,  0,  0,  0,  0, DEPTH_STENCIL)
ANKI_FORMAT_DEF(D32_SFLOAT_S8_UINT,        130,  0,  0,  0,  0,  0,  0, DEPTH_STENCIL)
ANKI_FORMAT_DEF(BC1_RGB_UNORM_BLOCK,       131,  3,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC1_RGB_SRGB_BLOCK,        132,  3,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC1_RGBA_UNORM_BLOCK,      133,  4,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC1_RGBA_SRGB_BLOCK,       134,  4,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC2_UNORM_BLOCK,           135,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC2_SRGB_BLOCK,            136,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC3_UNORM_BLOCK,           137,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC3_SRGB_BLOCK,            138,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC4_UNORM_BLOCK,           139,  1,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC4_SNORM_BLOCK,           140,  1,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(BC5_UNORM_BLOCK,           141,  2,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC5_SNORM_BLOCK,           142,  2,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC6H_UFLOAT_BLOCK,         143,  3,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC6H_SFLOAT_BLOCK,         144,  3,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC7_UNORM_BLOCK,           145,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(BC7_SRGB_BLOCK,            146,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8_UNORM_BLOCK,   147,  3,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8_SRGB_BLOCK,    148,  3,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8A1_UNORM_BLOCK, 149,  4,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8A1_SRGB_BLOCK,  150,  4,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8A8_UNORM_BLOCK, 151,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ETC2_R8G8B8A8_SRGB_BLOCK,  152,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(EAC_R11_UNORM_BLOCK,       153,  1,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(EAC_R11_SNORM_BLOCK,       154,  1,  0,  4,  4,  8,  0,          NONE)
ANKI_FORMAT_DEF(EAC_R11G11_UNORM_BLOCK,    155,  2,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(EAC_R11G11_SNORM_BLOCK,    156,  2,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_4x4_UNORM_BLOCK,      157,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_4x4_SRGB_BLOCK,       158,  4,  0,  4,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_5x4_UNORM_BLOCK,      159,  4,  0,  5,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_5x4_SRGB_BLOCK,       160,  4,  0,  5,  4, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_5x5_UNORM_BLOCK,      161,  4,  0,  5,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_5x5_SRGB_BLOCK,       162,  4,  0,  5,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_6x5_UNORM_BLOCK,      163,  4,  0,  6,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_6x5_SRGB_BLOCK,       164,  4,  0,  6,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_6x6_UNORM_BLOCK,      165,  4,  0,  6,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_6x6_SRGB_BLOCK,       166,  4,  0,  6,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x5_UNORM_BLOCK,      167,  4,  0,  8,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x5_SRGB_BLOCK,       168,  4,  0,  8,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x6_UNORM_BLOCK,      169,  4,  0,  8,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x6_SRGB_BLOCK,       170,  4,  0,  8,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x8_UNORM_BLOCK,      171,  4,  0,  8,  8, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_8x8_SRGB_BLOCK,       172,  4,  0,  8,  8, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x5_UNORM_BLOCK,     173,  4,  0, 10,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x5_SRGB_BLOCK,      174,  4,  0, 10,  5, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x6_UNORM_BLOCK,     175,  4,  0, 10,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x6_SRGB_BLOCK,      176,  4,  0, 10,  6, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x8_UNORM_BLOCK,     177,  4,  0, 10,  8, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x8_SRGB_BLOCK,      178,  4,  0, 10,  8, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x10_UNORM_BLOCK,    179,  4,  0, 10, 10, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_10x10_SRGB_BLOCK,     180,  4,  0, 10, 10, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_12x10_UNORM_BLOCK,    181,  4,  0, 12, 10, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_12x10_SRGB_BLOCK,     182,  4,  0, 12, 10, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_12x12_UNORM_BLOCK,    183,  4,  0, 12, 12, 16,  0,          NONE)
ANKI_FORMAT_DEF(ASTC_12x12_SRGB_BLOCK,     184,  4,  0, 12, 12, 16,  0,          NONE)
// clang-format on
