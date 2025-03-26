// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.TextureFormat.pas' rev: 36.00 (Windows)

#ifndef Stage_TextureFormatHPP
#define Stage_TextureFormatHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Textureformat
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TglSeparateTextureWrap : unsigned char { twRepeat, twClampToEdge, twClampToBorder, twMirrorRepeat, twMirrorClampToEdge, twMirrorClampToBorder };

enum DECLSPEC_DENUM TglTextureCompareMode : unsigned char { tcmNone, tcmCompareRtoTexture };

enum DECLSPEC_DENUM TglTextureFilteringQuality : unsigned char { tfIsotropic, tfAnisotropic };

enum DECLSPEC_DENUM TglTextureTarget : unsigned char { ttNoShape, ttTexture1D, ttTexture2D, ttTexture3D, ttTexture1DArray, ttTexture2DArray, ttTextureRect, ttTextureBuffer, ttTextureCube, ttTexture2DMultisample, ttTexture2DMultisampleArray, ttTextureCubeArray };

enum DECLSPEC_DENUM TglTextureSwizzle : unsigned char { tswRed, tswGreen, tswBlue, tswAlpha, tswZero, tswOne };

typedef System::StaticArray<TglTextureSwizzle, 4> TglSwizzleVector;

enum DECLSPEC_DENUM TglInternalFormat : unsigned char { tfALPHA4, tfALPHA8, tfALPHA12, tfALPHA16, tfDEPTH_COMPONENT16, tfDEPTH_COMPONENT24, tfDEPTH_COMPONENT32, tfLUMINANCE4, tfLUMINANCE8, tfLUMINANCE12, tfLUMINANCE16, tfLUMINANCE4_ALPHA4, tfLUMINANCE6_ALPHA2, tfLUMINANCE8_ALPHA8, tfLUMINANCE12_ALPHA4, tfLUMINANCE12_ALPHA12, tfLUMINANCE16_ALPHA16, tfINTENSITY4, tfINTENSITY8, tfINTENSITY12, tfINTENSITY16, tfR3_G3_B2, tfRGB4, tfRGB5, tfRGB8, tfRGB10, tfRGB12, tfR16G16B16, tfRGBA2, tfRGBA4, tfRGB5_A1, tfRGBA8, tfRGB10_A2, tfRGBA12, tfR16G16B16A16, tfCOMPRESSED_RGB_S3TC_DXT1, tfCOMPRESSED_RGBA_S3TC_DXT1, tfCOMPRESSED_RGBA_S3TC_DXT3, tfCOMPRESSED_RGBA_S3TC_DXT5, tfSIGNED_LUMINANCE8, tfSIGNED_LUMINANCE8_ALPHA8, tfSIGNED_RGB8, tfSIGNED_RGBA8, 
	tfSIGNED_RGB8_UNSIGNED_ALPHA8, tfSIGNED_ALPHA8, tfSIGNED_INTENSITY8, tfHILO16, tfSIGNED_HILO16, tfDSDT8, tfDSDT8_MAG8, tfDSDT8_MAG8_INTENSITY8, tfHILO8, tfSIGNED_HILO8, tfFLOAT_R16, tfFLOAT_R32, tfFLOAT_RG16, tfFLOAT_RGB16, tfFLOAT_RGBA16, tfFLOAT_RG32, tfFLOAT_RGB32, tfFLOAT_RGBA32, tfRGBA_FLOAT32, tfRGB_FLOAT32, tfALPHA_FLOAT32, tfINTENSITY_FLOAT32, tfLUMINANCE_FLOAT32, tfLUMINANCE_ALPHA_FLOAT32, tfRGBA_FLOAT16, tfRGB_FLOAT16, tfALPHA_FLOAT16, tfINTENSITY_FLOAT16, tfLUMINANCE_FLOAT16, tfLUMINANCE_ALPHA_FLOAT16, tfDEPTH24_STENCIL8, tfDEPTH_COMPONENT32F, tfDEPTH32F_STENCIL8, tfSRGB8, tfSRGB8_ALPHA8, tfSLUMINANCE8, tfSLUMINANCE8_ALPHA8, tfCOMPRESSED_SRGB_S3TC_DXT1, tfCOMPRESSED_SRGB_ALPHA_S3TC_DXT1, tfCOMPRESSED_SRGB_ALPHA_S3TC_DXT3, 
	tfCOMPRESSED_SRGB_ALPHA_S3TC_DXT5, tfRGB9_E5, tfR11F_G11F_B10F, tfCOMPRESSED_LUMINANCE_LATC1, tfCOMPRESSED_SIGNED_LUMINANCE_LATC1, tfCOMPRESSED_LUMINANCE_ALPHA_LATC2, tfCOMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2, tfCOMPRESSED_LUMINANCE_ALPHA_3DC, tfRGBA32UI, tfRGB32UI, tfALPHA32UI, tfINTENSITY32UI, tfLUMINANCE32UI, tfLUMINANCE_ALPHA32UI, tfRGBA16UI, tfRGB16UI, tfALPHA16UI, tfINTENSITY16UI, tfLUMINANCE16UI, tfLUMINANCE_ALPHA16UI, tfRGBA8UI, tfRGB8UI, tfALPHA8UI, tfINTENSITY8UI, tfLUMINANCE8UI, tfLUMINANCE_ALPHA8UI, tfRGBA32I, tfRGB32I, tfALPHA32I, tfINTENSITY32I, tfLUMINANCE32I, tfLUMINANCE_ALPHA32I, tfRGBA16I, tfRGB16I, tfALPHA16I, tfINTENSITY16I, tfLUMINANCE16I, tfLUMINANCE_ALPHA16I, tfRGBA8I, tfRGB8I, tfALPHA8I, tfINTENSITY8I, tfLUMINANCE8I, 
	tfLUMINANCE_ALPHA8I, tfRG32UI, tfR32UI, tfRG16UI, tfR16UI, tfRG8UI, tfR8UI, tfRG32I, tfR32I, tfRG16I, tfR16I, tfRG8I, tfR8I, tfRG8, tfR8, tfRG16, tfR16, tfRG16F, tfR16F, tfRG32F, tfR32F, tfCOMPRESSED_RED_RGTC1, tfCOMPRESSED_SIGNED_RED_RGTC1, tfCOMPRESSED_RG_RGTC2, tfCOMPRESSED_SIGNED_RG_RGTC2, tfR8_SNORM, tfRG8_SNORM, tfRGB8_SNORM, tfRGBA8_SNORM, tfR16_SNORM, tfRG16_SNORM, tfRGB16_SNORM, tfRGBA16_SNORM };

enum DECLSPEC_DENUM TglInternalCompression : unsigned char { tcDefault, tcNone, tcStandard, tcHighQuality, tcHighSpeed };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TglInternalFormat vDefaultTextureFormat;
extern DELPHI_PACKAGE TglInternalCompression vDefaultTextureCompression;
extern DELPHI_PACKAGE TglSwizzleVector cDefaultSwizzleVector;
extern DELPHI_PACKAGE unsigned __fastcall InternalFormatToOpenGLFormat(TglInternalFormat intFormat);
extern DELPHI_PACKAGE TglInternalFormat __fastcall OpenGLFormatToInternalFormat(unsigned glFormat);
extern DELPHI_PACKAGE int __fastcall GetTextureElementSize(TglInternalFormat intFormat)/* overload */;
extern DELPHI_PACKAGE int __fastcall GetTextureElementSize(unsigned colorFormat, unsigned dataType)/* overload */;
extern DELPHI_PACKAGE int __fastcall CompressedInternalFormatToOpenGL(TglInternalFormat intFormat);
extern DELPHI_PACKAGE void __fastcall FindCompatibleDataFormat(TglInternalFormat intFormat, /* out */ unsigned &dFormat, /* out */ unsigned &dType);
extern DELPHI_PACKAGE bool __fastcall IsTargetSupported(TglTextureTarget target)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsTargetSupported(unsigned glTarget)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsFormatSupported(TglInternalFormat intFormat);
extern DELPHI_PACKAGE bool __fastcall IsFloatFormat(TglInternalFormat intFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsFloatFormat(unsigned glFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsDepthFormat(TglInternalFormat intFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsDepthFormat(unsigned glFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsCompressedFormat(TglInternalFormat intFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsCompressedFormat(unsigned glFormat)/* overload */;
extern DELPHI_PACKAGE bool __fastcall GetGenericCompressedFormat(const TglInternalFormat intFormat, const unsigned colorFormat, /* out */ unsigned &internalFormat);
extern DELPHI_PACKAGE bool __fastcall GetUncompressedFormat(const TglInternalFormat intFormat, /* out */ TglInternalFormat &internalFormat, /* out */ unsigned &colorFormat);
extern DELPHI_PACKAGE unsigned __fastcall DecodeTextureTarget(const TglTextureTarget TextureTarget);
extern DELPHI_PACKAGE TglTextureTarget __fastcall EncodeGLTextureTarget(const unsigned glTarget);
extern DELPHI_PACKAGE bool __fastcall IsTargetSupportMipmap(const TglTextureTarget TextureTarget)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsTargetSupportMipmap(const unsigned glTarget)/* overload */;
}	/* namespace Textureformat */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_TEXTUREFORMAT)
using namespace Stage::Textureformat;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_TextureFormatHPP
