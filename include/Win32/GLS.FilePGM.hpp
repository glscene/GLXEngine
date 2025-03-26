// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FilePGM.pas' rev: 36.00 (Windows)

#ifndef GLS_FilePGMHPP
#define GLS_FilePGMHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GLS.Context.hpp>
#include <GLS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Strings.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <CUDA.Utility.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Filepgm
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLPGMImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLPGMImage : public Gls::Graphics::TGLBaseImage
{
	typedef Gls::Graphics::TGLBaseImage inherited;
	
public:
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* stream);
	HIDESBASE void __fastcall AssignFromTexture(Gls::Context::TGLContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
public:
	/* TGLBaseImage.Create */ inline __fastcall virtual TGLPGMImage() : Gls::Graphics::TGLBaseImage() { }
	/* TGLBaseImage.Destroy */ inline __fastcall virtual ~TGLPGMImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filepgm */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILEPGM)
using namespace Gls::Filepgm;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_FilePGMHPP
