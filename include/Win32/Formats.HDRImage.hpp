// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formats.HDRImage.pas' rev: 36.00 (Windows)

#ifndef Formats_HDRImageHPP
#define Formats_HDRImageHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.FileHDR.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formats
{
namespace Hdrimage
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS THDRImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION THDRImage : public Vcl::Graphics::TBitmap
{
	typedef Vcl::Graphics::TBitmap inherited;
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* stream);
public:
	/* TBitmap.Create */ inline __fastcall virtual THDRImage()/* overload */ : Vcl::Graphics::TBitmap() { }
	/* TBitmap.Create */ inline __fastcall THDRImage(int AWidth, int AHeight)/* overload */ : Vcl::Graphics::TBitmap(AWidth, AHeight) { }
	/* TBitmap.Destroy */ inline __fastcall virtual ~THDRImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Hdrimage */
}	/* namespace Formats */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS_HDRIMAGE)
using namespace Formats::Hdrimage;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS)
using namespace Formats;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formats_HDRImageHPP
