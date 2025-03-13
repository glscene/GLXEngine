// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FileHDR.pas' rev: 36.00 (Windows)

#ifndef GLS_FileHDRHPP
#define GLS_FileHDRHPP

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
#include <Stage.TextureFormat.hpp>
#include <Stage.RGBE.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Context.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.Graphics.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Filehdr
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLHDRImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLHDRImage : public Gls::Graphics::TGLBaseImage
{
	typedef Gls::Graphics::TGLBaseImage inherited;
	
private:
	System::AnsiString __fastcall GetProgramType();
	void __fastcall SetProgramType(System::AnsiString aval);
	
protected:
	float fGamma;
	float fExposure;
	System::SmallString<16> fProgramType;
	
public:
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	HIDESBASE void __fastcall AssignFromTexture(Gls::Context::TGLContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
	__property float Gamma = {read=fGamma};
	__property float Exposure = {read=fExposure};
	__property System::AnsiString ProgramType = {read=GetProgramType, write=SetProgramType};
public:
	/* TGLBaseImage.Create */ inline __fastcall virtual TGLHDRImage() : Gls::Graphics::TGLBaseImage() { }
	/* TGLBaseImage.Destroy */ inline __fastcall virtual ~TGLHDRImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filehdr */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILEHDR)
using namespace Gls::Filehdr;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_FileHDRHPP
