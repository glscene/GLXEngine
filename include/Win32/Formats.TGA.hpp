// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formats.TGA.pas' rev: 36.00 (Windows)

#ifndef Formats_TGAHPP
#define Formats_TGAHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.Context.hpp>
#include <GLS.Graphics.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formats
{
namespace Tga
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLTGAImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLTGAImage : public Gls::Graphics::TGLBaseImage
{
	typedef Gls::Graphics::TGLBaseImage inherited;
	
public:
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* stream);
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	HIDESBASE void __fastcall AssignFromTexture(Gls::Context::TGLContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
public:
	/* TGLBaseImage.Create */ inline __fastcall virtual TGLTGAImage() : Gls::Graphics::TGLBaseImage() { }
	/* TGLBaseImage.Destroy */ inline __fastcall virtual ~TGLTGAImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Tga */
}	/* namespace Formats */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS_TGA)
using namespace Formats::Tga;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS)
using namespace Formats;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formats_TGAHPP
