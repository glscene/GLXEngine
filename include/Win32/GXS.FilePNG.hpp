// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FilePNG.pas' rev: 36.00 (Windows)

#ifndef GXS_FilePNGHPP
#define GXS_FilePNGHPP

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
#include <GXS.Context.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filepng
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxPNGImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxPNGImage : public Gxs::Graphics::TgxBaseImage
{
	typedef Gxs::Graphics::TgxBaseImage inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* stream);
	HIDESBASE void __fastcall AssignFromTexture(Gxs::Context::TgxContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
public:
	/* TgxBaseImage.Create */ inline __fastcall virtual TgxPNGImage() : Gxs::Graphics::TgxBaseImage() { }
	/* TgxBaseImage.Destroy */ inline __fastcall virtual ~TgxPNGImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filepng */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEPNG)
using namespace Gxs::Filepng;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FilePNGHPP
