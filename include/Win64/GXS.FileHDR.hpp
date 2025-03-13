// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileHDR.pas' rev: 36.00 (Windows)

#ifndef GXS_FileHDRHPP
#define GXS_FileHDRHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.RGBE.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Strings.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Context.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filehdr
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxHDRImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxHDRImage : public Gxs::Graphics::TgxBaseImage
{
	typedef Gxs::Graphics::TgxBaseImage inherited;
	
private:
	System::AnsiString __fastcall GetProgramType();
	void __fastcall SetProgramType(System::AnsiString aval);
	
protected:
	float fGamma;
	float fExposure;
	System::SmallString<16> fProgramType;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	HIDESBASE void __fastcall AssignFromTexture(Gxs::Context::TgxContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
	__property float Gamma = {read=fGamma};
	__property float Exposure = {read=fExposure};
	__property System::AnsiString ProgramType = {read=GetProgramType, write=SetProgramType};
public:
	/* TgxBaseImage.Create */ inline __fastcall virtual TgxHDRImage() : Gxs::Graphics::TgxBaseImage() { }
	/* TgxBaseImage.Destroy */ inline __fastcall virtual ~TgxHDRImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filehdr */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEHDR)
using namespace Gxs::Filehdr;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileHDRHPP
