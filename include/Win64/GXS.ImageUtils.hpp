// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ImageUtils.pas' rev: 36.00 (Windows)

#ifndef GXS_ImageUtilsHPP
#define GXS_ImageUtilsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <System.SysUtils.hpp>
#include <System.UITypes.hpp>
#include <System.UIConsts.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <FMX.Types.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Consts.hpp>
#include <Stage.Strings.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Imageutils
{
//-- forward type declarations -----------------------------------------------
struct TIntermediateFormat;
class DELPHICLASS EGLImageUtils;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TIntermediateFormat
{
public:
	float R;
	float G;
	float B;
	float A;
};


typedef System::DynamicArray<void *> TPointerArray;

typedef TIntermediateFormat *PRGBA32F;

typedef System::StaticArray<TIntermediateFormat, 67108864> TIntermediateFormatArray;

typedef TIntermediateFormatArray *PIntermediateFormatArray;

typedef System::StaticArray<System::StaticArray<System::Byte, 4>, 4> TU48BitBlock;

typedef System::StaticArray<System::StaticArray<short, 4>, 4> T48BitBlock;

class PASCALIMPLEMENTATION EGLImageUtils : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLImageUtils(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLImageUtils(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLImageUtils(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLImageUtils(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLImageUtils(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLImageUtils(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLImageUtils(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLImageUtils(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLImageUtils(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLImageUtils(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLImageUtils(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLImageUtils(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLImageUtils() { }
	
};


typedef float __fastcall (*TImageFilterFunction)(float Value);

typedef void __fastcall (*TImageAlphaProc)(TIntermediateFormat &AColor);

_DECLARE_METACLASS(System::TMetaClass, TGraphicClass);

enum DECLSPEC_DENUM TgxTextLayout : unsigned char { tlTop, tlCenter, tlBottom };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int vImageScaleFilterWidth;
extern DELPHI_PACKAGE System::UnicodeString sAllFilter;
extern DELPHI_PACKAGE int __fastcall GLOKMessageBox(const System::UnicodeString Text, const System::UnicodeString Caption);
extern DELPHI_PACKAGE void __fastcall GLLoadBitmapFromInstance(System::LongInt Instance, Fmx::Graphics::TBitmap* ABitmap, const System::UnicodeString AName);
extern DELPHI_PACKAGE float __fastcall ImageBoxFilter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageTriangleFilter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageHermiteFilter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageBellFilter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageSplineFilter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageLanczos3Filter(float Value);
extern DELPHI_PACKAGE float __fastcall ImageMitchellFilter(float Value);
extern DELPHI_PACKAGE void __fastcall ImageAlphaFromIntensity(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaSuperBlackTransparent(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaLuminance(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaLuminanceSqrt(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaOpaque(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaTopLeftPointColorTransparent(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaInverseLuminance(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaInverseLuminanceSqrt(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ImageAlphaBottomRightPointColorTransparent(TIntermediateFormat &AColor);
extern DELPHI_PACKAGE void __fastcall ConvertImage(const void * ASrc, const void * ADst, unsigned ASrcColorFormat, unsigned ADstColorFormat, unsigned ASrcDataType, unsigned ADstDataType, int AWidth, int AHeight);
extern DELPHI_PACKAGE void __fastcall RescaleImage(const void * ASrc, const void * ADst, unsigned AColorFormat, unsigned ADataType, TImageFilterFunction AFilter, int ASrcWidth, int ASrcHeight, int ADstWidth, int ADstHeight);
extern DELPHI_PACKAGE void __fastcall Build2DMipmap(const void * ASrc, const TPointerArray ADst, unsigned AColorFormat, unsigned ADataType, TImageFilterFunction AFilter, int ASrcWidth, int ASrcHeight);
extern DELPHI_PACKAGE void __fastcall AlphaGammaBrightCorrection(const void * ASrc, unsigned AColorFormat, unsigned ADataType, int ASrcWidth, int ASrcHeight, TImageAlphaProc anAlphaProc, float ABrightness, float AGamma);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall StringToColorAdvancedSafe(const System::UnicodeString Str, const System::Uitypes::TColor Default);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall StringToColorAdvanced(const System::UnicodeString Str);
extern DELPHI_PACKAGE bool __fastcall TryStringToColorAdvanced(const System::UnicodeString Str, System::Uitypes::TColor &OutColor);
extern DELPHI_PACKAGE int __fastcall GetDeviceLogicalPixelsX(HDC device);
extern DELPHI_PACKAGE int __fastcall GetCurrentColorDepth(void);
extern DELPHI_PACKAGE int __fastcall PixelFormatToColorBits(Fmx::Types::TPixelFormat aPixelFormat);
extern DELPHI_PACKAGE void * __fastcall BitmapScanLine(Fmx::Graphics::TBitmap* aBitmap, int aRow);
extern DELPHI_PACKAGE void __fastcall InformationDlg(const System::UnicodeString msg);
extern DELPHI_PACKAGE bool __fastcall QuestionDlg(const System::UnicodeString msg);
extern DELPHI_PACKAGE System::UnicodeString __fastcall InputDlg(const System::UnicodeString aCaption, const System::UnicodeString aPrompt, const System::UnicodeString aDefault);
extern DELPHI_PACKAGE bool __fastcall SavePictureDialog(System::UnicodeString &aFileName, const System::UnicodeString aTitle = System::UnicodeString());
extern DELPHI_PACKAGE bool __fastcall OpenPictureDialog(System::UnicodeString &aFileName, const System::UnicodeString aTitle = System::UnicodeString());
}	/* namespace Imageutils */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_IMAGEUTILS)
using namespace Gxs::Imageutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ImageUtilsHPP
