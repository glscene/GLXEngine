// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FileDDS.pas' rev: 36.00 (Windows)

#ifndef GLS_FileDDSHPP
#define GLS_FileDDSHPP

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
#include <System.Math.hpp>
#include <GLS.Context.hpp>
#include <GLS.Graphics.hpp>
#include <GLS.Texture.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.CompositeImage.hpp>
#include <GLS.MultiSampleImage.hpp>
#include <Stage.RGBE.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.Material.hpp>
#include <Stage.Strings.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Filedds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLDDSImage;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLDDSDetailLevels : unsigned char { ddsHighDet, ddsMediumDet, ddsLowDet };

class PASCALIMPLEMENTATION TGLDDSImage : public Gls::Graphics::TGLBaseImage
{
	typedef Gls::Graphics::TGLBaseImage inherited;
	
private:
	void __fastcall FlipSurface(Winapi::Opengl::PGLubyte ChangeData, int W, int H, int D);
	
public:
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString Filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString Filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	HIDESBASE void __fastcall AssignFromTexture(Gls::Context::TGLContext* TextureContext, const unsigned TextureHandle, Stage::Textureformat::TglTextureTarget TextureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat IntFormat);
public:
	/* TGLBaseImage.Create */ inline __fastcall virtual TGLDDSImage() : Gls::Graphics::TGLBaseImage() { }
	/* TGLBaseImage.Destroy */ inline __fastcall virtual ~TGLDDSImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGLDDSDetailLevels vDDSDetailLevel;
extern DELPHI_PACKAGE Gls::Material::TGLLibMaterial* __fastcall GetOrCreateLibMaterial(Gls::Material::TGLMaterialLibrary* aMaterialLibrary, System::UnicodeString aMaterialName);
extern DELPHI_PACKAGE Gls::Material::TGLLibMaterial* __fastcall LibMat(Gls::Material::TGLMaterialLibrary* aMatLib, System::UnicodeString aMatName);
extern DELPHI_PACKAGE Gls::Material::TGLLibMaterial* __fastcall DDStex(Gls::Material::TGLMaterialLibrary* aMatLib, System::UnicodeString aTexName, System::UnicodeString aDDSFileName, System::UnicodeString aSecondTexName = System::UnicodeString(), int aDDSLevel = 0x0)/* overload */;
extern DELPHI_PACKAGE Gls::Texture::TGLTextureExItem* __fastcall DDStex(Gls::Texture::TGLTextureExItem* aTextureEx, System::UnicodeString aDDSFileName, int aDDSLevel = 0x0)/* overload */;
extern DELPHI_PACKAGE Gls::Texture::TGLTexture* __fastcall DDStex(Gls::Texture::TGLTexture* aTexture, System::UnicodeString aDDSFileName, int aDDSLevel = 0x0)/* overload */;
}	/* namespace Filedds */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILEDDS)
using namespace Gls::Filedds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_FileDDSHPP
