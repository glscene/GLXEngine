// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.CgBombShader.pas' rev: 36.00 (Windows)

#ifndef GLS_CgBombShaderHPP
#define GLS_CgBombShaderHPP

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
#include <GLS.Texture.hpp>
#include <GLS.Cadencer.hpp>
#include <GLS.Context.hpp>
#include <Stage.Strings.hpp>
#include <GLS.Material.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.State.hpp>
#include <Cg.GL.hpp>
#include <GLS.CgShader.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Cgbombshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS ECgBombShaderException;
class DELPHICLASS TCgCustomBombShader;
class DELPHICLASS TCgBombShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION ECgBombShaderException : public Gls::Cgshader::ECgShaderException
{
	typedef Gls::Cgshader::ECgShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECgBombShaderException(const System::UnicodeString Msg) : Gls::Cgshader::ECgShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECgBombShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gls::Cgshader::ECgShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECgBombShaderException(System::NativeUInt Ident)/* overload */ : Gls::Cgshader::ECgShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECgBombShaderException(System::PResStringRec ResStringRec)/* overload */ : Gls::Cgshader::ECgShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECgBombShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gls::Cgshader::ECgShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECgBombShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gls::Cgshader::ECgShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECgBombShaderException(const System::UnicodeString Msg, int AHelpContext) : Gls::Cgshader::ECgShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECgBombShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gls::Cgshader::ECgShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECgBombShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gls::Cgshader::ECgShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECgBombShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gls::Cgshader::ECgShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECgBombShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gls::Cgshader::ECgShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECgBombShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gls::Cgshader::ECgShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECgBombShaderException() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLCgBombShaderTextureSource : unsigned char { stsPrimaryTexture, stsSecondadyTexture, stsThirdTexture, stsUserSelectedTexture };

class PASCALIMPLEMENTATION TCgCustomBombShader : public Gls::Cgshader::TCadencableCustomCgShader
{
	typedef Gls::Cgshader::TCadencableCustomCgShader inherited;
	
private:
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FGradientTexture;
	Gls::Texture::TGLTexture* FMainTexture;
	Gls::Material::TGLLibMaterialName FMainTextureName;
	Gls::Material::TGLLibMaterialName FGradientTextureName;
	float FSharpness;
	float FColorRange;
	float FSpeed;
	float FDisplacement;
	float FAlpha;
	float FTurbDensity;
	float FColorSharpness;
	float FGradientTextureShare;
	float FMainTextureShare;
	TGLCgBombShaderTextureSource FMainTextureSource;
	void __fastcall SetGradientTexture(Gls::Texture::TGLTexture* const Value);
	void __fastcall SetMainTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTextureName();
	void __fastcall SetMainTextureName(const Gls::Material::TGLLibMaterialName Value);
	Gls::Material::TGLLibMaterialName __fastcall GetGradientTextureName();
	void __fastcall SetGradientTextureName(const Gls::Material::TGLLibMaterialName Value);
	bool __fastcall StoreColorRange();
	bool __fastcall StoreColorSharpness();
	bool __fastcall StoreDisplacement();
	bool __fastcall StoreGradientTextureShare();
	bool __fastcall StoreSharpness();
	bool __fastcall StoreSpeed();
	bool __fastcall StoreTurbDensity();
	bool __fastcall StoreMainTextureShare();
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual void __fastcall DoInitialize(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnApplyVP(Gls::Cgshader::TCgProgram* CgProgram, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnApplyFP(Gls::Cgshader::TCgProgram* CgProgram, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnUnApplyFP(Gls::Cgshader::TCgProgram* CgProgram);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TCgCustomBombShader(System::Classes::TComponent* AOwner);
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTexture, write=SetMainTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTextureName, write=SetMainTextureName};
	__property Gls::Texture::TGLTexture* GradientTexture = {read=FGradientTexture, write=SetGradientTexture};
	__property Gls::Material::TGLLibMaterialName GradientTextureName = {read=GetGradientTextureName, write=SetGradientTextureName};
	__property float GradientTextureShare = {read=FGradientTextureShare, write=FGradientTextureShare, stored=StoreGradientTextureShare};
	__property float MainTextureShare = {read=FMainTextureShare, write=FMainTextureShare, stored=StoreMainTextureShare};
	__property float Alpha = {read=FAlpha, write=FAlpha};
	__property float Displacement = {read=FDisplacement, write=FDisplacement, stored=StoreDisplacement};
	__property float Sharpness = {read=FSharpness, write=FSharpness, stored=StoreSharpness};
	__property float ColorSharpness = {read=FColorSharpness, write=FColorSharpness, stored=StoreColorSharpness};
	__property float Speed = {read=FSpeed, write=FSpeed, stored=StoreSpeed};
	__property float TurbDensity = {read=FTurbDensity, write=FTurbDensity, stored=StoreTurbDensity};
	__property float ColorRange = {read=FColorRange, write=FColorRange, stored=StoreColorRange};
	__property TGLCgBombShaderTextureSource MainTextureSource = {read=FMainTextureSource, write=FMainTextureSource, nodefault};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
public:
	/* TCustomCgShader.Destroy */ inline __fastcall virtual ~TCgCustomBombShader() { }
	
private:
	void *__IGLMaterialLibrarySupported;	// Gls::Material::IGLMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gls::Material::_di_IGLMaterialLibrarySupported()
	{
		Gls::Material::_di_IGLMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gls::Material::IGLMaterialLibrarySupported*(void) { return (Gls::Material::IGLMaterialLibrarySupported*)&__IGLMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TCgBombShader : public TCgCustomBombShader
{
	typedef TCgCustomBombShader inherited;
	
protected:
	virtual void __fastcall DoInitialize(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall OnApplyVP(Gls::Cgshader::TCgProgram* CgProgram, System::TObject* Sender);
	virtual void __fastcall OnApplyFP(Gls::Cgshader::TCgProgram* CgProgram, System::TObject* Sender);
	virtual void __fastcall OnUnApplyFP(Gls::Cgshader::TCgProgram* CgProgram);
	
__published:
	__property MainTextureShare = {default=0};
	__property MainTextureName = {default=0};
	__property GradientTextureShare = {default=0};
	__property GradientTextureName = {default=0};
	__property Alpha = {default=0};
	__property Cadencer;
	__property Displacement = {default=0};
	__property Sharpness = {default=0};
	__property ColorSharpness = {default=0};
	__property Speed = {default=0};
	__property TurbDensity = {default=0};
	__property ColorRange = {default=0};
	__property MaterialLibrary;
	__property DesignEnable = {default=0};
public:
	/* TCgCustomBombShader.Create */ inline __fastcall virtual TCgBombShader(System::Classes::TComponent* AOwner) : TCgCustomBombShader(AOwner) { }
	
public:
	/* TCustomCgShader.Destroy */ inline __fastcall virtual ~TCgBombShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cgbombshader */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_CGBOMBSHADER)
using namespace Gls::Cgbombshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_CgBombShaderHPP
