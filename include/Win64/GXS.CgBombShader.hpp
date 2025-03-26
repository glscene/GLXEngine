// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CgBombShader.pas' rev: 36.00 (Windows)

#ifndef GXS_CgBombShaderHPP
#define GXS_CgBombShaderHPP

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
#include <GXS.Texture.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Context.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Material.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.State.hpp>
#include <Cg.GL.hpp>
#include <GXS.CgShader.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cgbombshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS ECGxBombShaderException;
class DELPHICLASS TCGxCustomBombShader;
class DELPHICLASS TCGxBombShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION ECGxBombShaderException : public Gxs::Cgshader::ECGxShaderException
{
	typedef Gxs::Cgshader::ECGxShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECGxBombShaderException(const System::UnicodeString Msg) : Gxs::Cgshader::ECGxShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECGxBombShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxs::Cgshader::ECGxShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECGxBombShaderException(System::NativeUInt Ident)/* overload */ : Gxs::Cgshader::ECGxShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECGxBombShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxs::Cgshader::ECGxShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECGxBombShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Cgshader::ECGxShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECGxBombShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Cgshader::ECGxShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECGxBombShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxs::Cgshader::ECGxShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECGxBombShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxs::Cgshader::ECGxShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECGxBombShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxs::Cgshader::ECGxShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECGxBombShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxs::Cgshader::ECGxShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECGxBombShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Cgshader::ECGxShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECGxBombShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Cgshader::ECGxShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECGxBombShaderException() { }
	
};


enum DECLSPEC_DENUM TCGxBombShaderTextureSource : unsigned char { stsPrimaryTexture, stsSecondadyTexture, stsThirdTexture, stsUserSelectedTexture };

class PASCALIMPLEMENTATION TCGxCustomBombShader : public Gxs::Cgshader::TCGxCadencableCustomShader
{
	typedef Gxs::Cgshader::TCGxCadencableCustomShader inherited;
	
private:
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FGradientTexture;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTextureName;
	Gxs::Material::TgxLibMaterialName FGradientTextureName;
	float FSharpness;
	float FColorRange;
	float FSpeed;
	float FDisplacement;
	float FAlpha;
	float FTurbDensity;
	float FColorSharpness;
	float FGradientTextureShare;
	float FMainTextureShare;
	TCGxBombShaderTextureSource FMainTextureSource;
	void __fastcall SetGradientTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetMainTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTextureName();
	void __fastcall SetMainTextureName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetGradientTextureName();
	void __fastcall SetGradientTextureName(const Gxs::Material::TgxLibMaterialName Value);
	bool __fastcall StoreColorRange();
	bool __fastcall StoreColorSharpness();
	bool __fastcall StoreDisplacement();
	bool __fastcall StoreGradientTextureShare();
	bool __fastcall StoreSharpness();
	bool __fastcall StoreSpeed();
	bool __fastcall StoreTurbDensity();
	bool __fastcall StoreMainTextureShare();
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnApplyVP(Gxs::Cgshader::TCGxProgram* CgProgram, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnApplyFP(Gxs::Cgshader::TCGxProgram* CgProgram, System::TObject* Sender);
	HIDESBASE virtual void __fastcall OnUnApplyFP(Gxs::Cgshader::TCGxProgram* CgProgram);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TCGxCustomBombShader(System::Classes::TComponent* AOwner);
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=SetMainTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTextureName, write=SetMainTextureName};
	__property Gxs::Texture::TgxTexture* GradientTexture = {read=FGradientTexture, write=SetGradientTexture};
	__property Gxs::Material::TgxLibMaterialName GradientTextureName = {read=GetGradientTextureName, write=SetGradientTextureName};
	__property float GradientTextureShare = {read=FGradientTextureShare, write=FGradientTextureShare, stored=StoreGradientTextureShare};
	__property float MainTextureShare = {read=FMainTextureShare, write=FMainTextureShare, stored=StoreMainTextureShare};
	__property float Alpha = {read=FAlpha, write=FAlpha};
	__property float Displacement = {read=FDisplacement, write=FDisplacement, stored=StoreDisplacement};
	__property float Sharpness = {read=FSharpness, write=FSharpness, stored=StoreSharpness};
	__property float ColorSharpness = {read=FColorSharpness, write=FColorSharpness, stored=StoreColorSharpness};
	__property float Speed = {read=FSpeed, write=FSpeed, stored=StoreSpeed};
	__property float TurbDensity = {read=FTurbDensity, write=FTurbDensity, stored=StoreTurbDensity};
	__property float ColorRange = {read=FColorRange, write=FColorRange, stored=StoreColorRange};
	__property TCGxBombShaderTextureSource MainTextureSource = {read=FMainTextureSource, write=FMainTextureSource, nodefault};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
public:
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxCustomBombShader() { }
	
private:
	void *__IgxMaterialLibrarySupported;	// Gxs::Material::IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gxs::Material::_di_IgxMaterialLibrarySupported()
	{
		Gxs::Material::_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Material::IgxMaterialLibrarySupported*(void) { return (Gxs::Material::IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TCGxBombShader : public TCGxCustomBombShader
{
	typedef TCGxCustomBombShader inherited;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall OnApplyVP(Gxs::Cgshader::TCGxProgram* CgProgram, System::TObject* Sender);
	virtual void __fastcall OnApplyFP(Gxs::Cgshader::TCGxProgram* CgProgram, System::TObject* Sender);
	virtual void __fastcall OnUnApplyFP(Gxs::Cgshader::TCGxProgram* CgProgram);
	
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
	/* TCGxCustomBombShader.Create */ inline __fastcall virtual TCGxBombShader(System::Classes::TComponent* AOwner) : TCGxCustomBombShader(AOwner) { }
	
public:
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxBombShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cgbombshader */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CGBOMBSHADER)
using namespace Gxs::Cgbombshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CgBombShaderHPP
