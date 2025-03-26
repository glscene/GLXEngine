// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileTGA.pas' rev: 36.00 (Windows)

#ifndef GXS_FileTGAHPP
#define GXS_FileTGAHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <GXS.Graphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filetga
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TTGAImage;
class DELPHICLASS ETGAException;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TTGAImage : public Fmx::Graphics::TBitmap
{
	typedef Fmx::Graphics::TBitmap inherited;
	
public:
	__fastcall virtual TTGAImage()/* overload */;
	__fastcall virtual ~TTGAImage();
	HIDESBASE void __fastcall LoadFromStream(System::Classes::TStream* stream);
	HIDESBASE void __fastcall SaveToStream(System::Classes::TStream* stream);
public:
	/* TBitmap.Create */ inline __fastcall virtual TTGAImage(const int AWidth, const int AHeight)/* overload */ : Fmx::Graphics::TBitmap(AWidth, AHeight) { }
	/* TBitmap.CreateFromStream */ inline __fastcall virtual TTGAImage(System::Classes::TStream* const AStream) : Fmx::Graphics::TBitmap(AStream) { }
	/* TBitmap.CreateFromFile */ inline __fastcall virtual TTGAImage(const System::UnicodeString AFileName) : Fmx::Graphics::TBitmap(AFileName) { }
	/* TBitmap.CreateFromBitmapAndMask */ inline __fastcall TTGAImage(Fmx::Graphics::TBitmap* const Bitmap, Fmx::Graphics::TBitmap* const Mask) : Fmx::Graphics::TBitmap(Bitmap, Mask) { }
	
};


class PASCALIMPLEMENTATION ETGAException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ETGAException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ETGAException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ETGAException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ETGAException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ETGAException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ETGAException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ETGAException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ETGAException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETGAException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETGAException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETGAException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETGAException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ETGAException() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filetga */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILETGA)
using namespace Gxs::Filetga;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileTGAHPP
