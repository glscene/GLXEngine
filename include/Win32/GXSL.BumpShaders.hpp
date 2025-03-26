// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.BumpShaders.pas' rev: 36.00 (Windows)

#ifndef GXSL_BumpShadersHPP
#define GXSL_BumpShadersHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Cadencer.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.State.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXSL.Shader.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Bumpshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EgxslBumpShaderException;
class DELPHICLASS TgxslBaseCustomBumpShader;
class DELPHICLASS TgxslBaseCustomBumpShaderMT;
class DELPHICLASS TgxslCustomBumpShaderAM;
class DELPHICLASS TgxslCustomBumpShaderMT;
class DELPHICLASS TgxslCustomBumpShader;
class DELPHICLASS TgxslCustomMLBumpShader;
class DELPHICLASS TgxslCustomMLBumpShaderMT;
class DELPHICLASS TgxslBumpShaderMT;
class DELPHICLASS TgxslBumpShader;
class DELPHICLASS TgxslBumpShaderAM;
class DELPHICLASS TgxslMLBumpShader;
class DELPHICLASS TgxslMLBumpShaderMT;
class DELPHICLASS TgxBumpShader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TBumpMethod : unsigned char { bmDot3TexCombiner, bmBasicARBFP };

enum DECLSPEC_DENUM TBumpSpace : unsigned char { bsObject, bsTangentExternal, bsTangentQuaternion };

enum DECLSPEC_DENUM TBumpOption : unsigned char { boDiffuseTexture2, boSpecularTexture3, boUseSecondaryTexCoords, boLightAttenuation, boParallaxMapping };

typedef System::Set<TBumpOption, TBumpOption::boDiffuseTexture2, TBumpOption::boParallaxMapping> TBumpOptions;

enum DECLSPEC_DENUM TSpecularMode : unsigned char { smOff, smBlinn, smPhong };

#pragma pack(push,4)
class PASCALIMPLEMENTATION EgxslBumpShaderException : public Gxsl::Shader::EGXSLShaderException
{
	typedef Gxsl::Shader::EGXSLShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EgxslBumpShaderException(const System::UnicodeString Msg) : Gxsl::Shader::EGXSLShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EgxslBumpShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxsl::Shader::EGXSLShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EgxslBumpShaderException(System::NativeUInt Ident)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EgxslBumpShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxslBumpShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxslBumpShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EgxslBumpShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxsl::Shader::EGXSLShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EgxslBumpShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxsl::Shader::EGXSLShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxslBumpShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxslBumpShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxslBumpShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxslBumpShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EgxslBumpShaderException() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxslBaseCustomBumpShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FBumpHeight;
	int FBumpSmoothness;
	float FSpecularPower;
	float FSpecularSpread;
	float FLightPower;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FNormalTexture;
	Gxs::Texture::TgxTexture* FSpecularTexture;
	Gxs::Material::TgxLibMaterialName FNormalTextureName;
	Gxs::Material::TgxLibMaterialName FSpecularTextureName;
	Gxs::Material::TgxLibMaterialName __fastcall GetNormalTextureName();
	Gxs::Material::TgxLibMaterialName __fastcall GetSpecularTextureName();
	void __fastcall SetNormalTextureName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetSpecularTextureName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetSpecularTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetNormalTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxslBaseCustomBumpShader(System::Classes::TComponent* AOwner);
	__property float BumpHeight = {read=FBumpHeight, write=FBumpHeight};
	__property int BumpSmoothness = {read=FBumpSmoothness, write=FBumpSmoothness, nodefault};
	__property float SpecularPower = {read=FSpecularPower, write=FSpecularPower};
	__property float SpecularSpread = {read=FSpecularSpread, write=FSpecularSpread};
	__property float LightPower = {read=FLightPower, write=FLightPower};
	__property Gxs::Texture::TgxTexture* NormalTexture = {read=FNormalTexture, write=SetNormalTexture};
	__property Gxs::Texture::TgxTexture* SpecularTexture = {read=FSpecularTexture, write=SetSpecularTexture};
	__property Gxs::Material::TgxLibMaterialName NormalTextureName = {read=GetNormalTextureName, write=SetNormalTextureName};
	__property Gxs::Material::TgxLibMaterialName SpecularTextureName = {read=GetSpecularTextureName, write=SetSpecularTextureName};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslBaseCustomBumpShader() { }
	
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


class PASCALIMPLEMENTATION TgxslBaseCustomBumpShaderMT : public TgxslBaseCustomBumpShader
{
	typedef TgxslBaseCustomBumpShader inherited;
	
private:
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTextureName;
	System::UnicodeString __fastcall GetMainTextureName();
	void __fastcall SetMainTextureName(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=FMainTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTextureName, write=SetMainTextureName};
public:
	/* TgxslBaseCustomBumpShader.Create */ inline __fastcall virtual TgxslBaseCustomBumpShaderMT(System::Classes::TComponent* AOwner) : TgxslBaseCustomBumpShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslBaseCustomBumpShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomBumpShaderAM : public TgxslBaseCustomBumpShaderMT
{
	typedef TgxslBaseCustomBumpShaderMT inherited;
	
private:
	Gxs::Color::TgxColor* FAmbientColor;
	Gxs::Color::TgxColor* FDiffuseColor;
	Gxs::Color::TgxColor* FSpecularColor;
	float __fastcall GetAlpha();
	void __fastcall SetAlpha(const float Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxslCustomBumpShaderAM(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxslCustomBumpShaderAM();
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor};
	__property Gxs::Color::TgxColor* DiffuseColor = {read=FDiffuseColor};
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor};
	__property float Alpha = {read=GetAlpha, write=SetAlpha};
};


class PASCALIMPLEMENTATION TgxslCustomBumpShaderMT : public TgxslBaseCustomBumpShaderMT
{
	typedef TgxslBaseCustomBumpShaderMT inherited;
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
public:
	/* TgxslBaseCustomBumpShader.Create */ inline __fastcall virtual TgxslCustomBumpShaderMT(System::Classes::TComponent* AOwner) : TgxslBaseCustomBumpShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomBumpShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomBumpShader : public TgxslBaseCustomBumpShader
{
	typedef TgxslBaseCustomBumpShader inherited;
	
private:
	void __fastcall SetShaderTextures(Gxs::Texture::TgxTexture* const *Textures, const System::NativeInt Textures_High);
	void __fastcall GetShaderTextures(Gxs::Texture::TgxTexture* *Textures, const System::NativeInt Textures_High);
	void __fastcall SetShaderColorParams(const Stage::Vectortypes::TVector4f &AAmbientColor, const Stage::Vectortypes::TVector4f &ADiffuseColor, const Stage::Vectortypes::TVector4f &ASpecularcolor);
	void __fastcall GetShaderColorParams(Stage::Vectortypes::TVector4f &AAmbientColor, Stage::Vectortypes::TVector4f &ADiffuseColor, Stage::Vectortypes::TVector4f &ASpecularcolor);
	void __fastcall SetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* const ACadencer, Gxs::Material::TgxMaterialLibrary* const AMatLib, const Gxsl::Customshader::TgxLightSourceSet ALightSources);
	void __fastcall GetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* &ACadencer, Gxs::Material::TgxMaterialLibrary* &AMatLib, Gxsl::Customshader::TgxLightSourceSet &ALightSources);
	float __fastcall GetShaderAlpha();
	void __fastcall SetShaderAlpha(const float Value);
	System::UnicodeString __fastcall GetShaderDescription();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
public:
	/* TgxslBaseCustomBumpShader.Create */ inline __fastcall virtual TgxslCustomBumpShader(System::Classes::TComponent* AOwner) : TgxslBaseCustomBumpShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomBumpShader() { }
	
private:
	void *__IgxShaderDescription;	// Gxsl::Customshader::IgxShaderDescription 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {04089C64-60C2-43F5-AC9C-38ED46264812}
	operator Gxsl::Customshader::_di_IgxShaderDescription()
	{
		Gxsl::Customshader::_di_IgxShaderDescription intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxShaderDescription*(void) { return (Gxsl::Customshader::IgxShaderDescription*)&__IgxShaderDescription; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslCustomMLBumpShader : public TgxslBaseCustomBumpShader
{
	typedef TgxslBaseCustomBumpShader inherited;
	
private:
	Gxsl::Customshader::TgxLightSourceSet FLightSources;
	float FLightCompensation;
	void __fastcall SetLightSources(const Gxsl::Customshader::TgxLightSourceSet Value);
	void __fastcall SetLightCompensation(const float Value);
	void __fastcall SetShaderTextures(Gxs::Texture::TgxTexture* const *Textures, const System::NativeInt Textures_High);
	void __fastcall GetShaderTextures(Gxs::Texture::TgxTexture* *Textures, const System::NativeInt Textures_High);
	void __fastcall SetShaderColorParams(const Stage::Vectortypes::TVector4f &AAmbientColor, const Stage::Vectortypes::TVector4f &ADiffuseColor, const Stage::Vectortypes::TVector4f &ASpecularcolor);
	void __fastcall GetShaderColorParams(Stage::Vectortypes::TVector4f &AAmbientColor, Stage::Vectortypes::TVector4f &ADiffuseColor, Stage::Vectortypes::TVector4f &ASpecularcolor);
	void __fastcall SetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* const ACadencer, Gxs::Material::TgxMaterialLibrary* const AMatLib, const Gxsl::Customshader::TgxLightSourceSet ALightSources);
	void __fastcall GetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* &ACadencer, Gxs::Material::TgxMaterialLibrary* &AMatLib, Gxsl::Customshader::TgxLightSourceSet &ALightSources);
	float __fastcall GetShaderAlpha();
	void __fastcall SetShaderAlpha(const float Value);
	System::UnicodeString __fastcall GetShaderDescription();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxslCustomMLBumpShader(System::Classes::TComponent* AOwner);
	__property Gxsl::Customshader::TgxLightSourceSet LightSources = {read=FLightSources, write=SetLightSources, default=2};
	__property float LightCompensation = {read=FLightCompensation, write=SetLightCompensation};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomMLBumpShader() { }
	
private:
	void *__IgxShaderDescription;	// Gxsl::Customshader::IgxShaderDescription 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {04089C64-60C2-43F5-AC9C-38ED46264812}
	operator Gxsl::Customshader::_di_IgxShaderDescription()
	{
		Gxsl::Customshader::_di_IgxShaderDescription intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxShaderDescription*(void) { return (Gxsl::Customshader::IgxShaderDescription*)&__IgxShaderDescription; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslCustomMLBumpShaderMT : public TgxslBaseCustomBumpShaderMT
{
	typedef TgxslBaseCustomBumpShaderMT inherited;
	
private:
	Gxsl::Customshader::TgxLightSourceSet FLightSources;
	float FLightCompensation;
	void __fastcall SetLightSources(const Gxsl::Customshader::TgxLightSourceSet Value);
	void __fastcall SetLightCompensation(const float Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxslCustomMLBumpShaderMT(System::Classes::TComponent* AOwner);
	__property Gxsl::Customshader::TgxLightSourceSet LightSources = {read=FLightSources, write=SetLightSources, default=2};
	__property float LightCompensation = {read=FLightCompensation, write=SetLightCompensation};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomMLBumpShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxslBumpShaderMT : public TgxslCustomBumpShaderMT
{
	typedef TgxslCustomBumpShaderMT inherited;
	
__published:
	__property MainTextureName = {default=0};
	__property NormalTextureName = {default=0};
	__property SpecularTextureName = {default=0};
	__property MaterialLibrary;
	__property BumpHeight = {default=0};
	__property BumpSmoothness;
	__property SpecularPower = {default=0};
	__property SpecularSpread = {default=0};
	__property LightPower = {default=0};
public:
	/* TgxslBaseCustomBumpShader.Create */ inline __fastcall virtual TgxslBumpShaderMT(System::Classes::TComponent* AOwner) : TgxslCustomBumpShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslBumpShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxslBumpShader : public TgxslCustomBumpShader
{
	typedef TgxslCustomBumpShader inherited;
	
__published:
	__property NormalTextureName = {default=0};
	__property SpecularTextureName = {default=0};
	__property MaterialLibrary;
	__property BumpHeight = {default=0};
	__property BumpSmoothness;
	__property SpecularPower = {default=0};
	__property SpecularSpread = {default=0};
	__property LightPower = {default=0};
public:
	/* TgxslBaseCustomBumpShader.Create */ inline __fastcall virtual TgxslBumpShader(System::Classes::TComponent* AOwner) : TgxslCustomBumpShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslBumpShader() { }
	
};


class PASCALIMPLEMENTATION TgxslBumpShaderAM : public TgxslCustomBumpShaderAM
{
	typedef TgxslCustomBumpShaderAM inherited;
	
__published:
	__property AmbientColor;
	__property DiffuseColor;
	__property SpecularColor;
	__property Alpha = {stored=false, default=0};
	__property MainTextureName = {default=0};
	__property NormalTextureName = {default=0};
	__property SpecularTextureName = {default=0};
	__property MaterialLibrary;
	__property BumpHeight = {default=0};
	__property BumpSmoothness;
	__property SpecularPower = {default=0};
	__property SpecularSpread = {default=0};
	__property LightPower = {default=0};
public:
	/* TgxslCustomBumpShaderAM.Create */ inline __fastcall virtual TgxslBumpShaderAM(System::Classes::TComponent* AOwner) : TgxslCustomBumpShaderAM(AOwner) { }
	/* TgxslCustomBumpShaderAM.Destroy */ inline __fastcall virtual ~TgxslBumpShaderAM() { }
	
};


class PASCALIMPLEMENTATION TgxslMLBumpShader : public TgxslCustomMLBumpShader
{
	typedef TgxslCustomMLBumpShader inherited;
	
__published:
	__property NormalTextureName = {default=0};
	__property SpecularTextureName = {default=0};
	__property MaterialLibrary;
	__property BumpHeight = {default=0};
	__property BumpSmoothness;
	__property SpecularPower = {default=0};
	__property SpecularSpread = {default=0};
	__property LightPower = {default=0};
	__property LightSources = {default=2};
	__property LightCompensation = {default=0};
public:
	/* TgxslCustomMLBumpShader.Create */ inline __fastcall virtual TgxslMLBumpShader(System::Classes::TComponent* AOwner) : TgxslCustomMLBumpShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslMLBumpShader() { }
	
};


class PASCALIMPLEMENTATION TgxslMLBumpShaderMT : public TgxslCustomMLBumpShaderMT
{
	typedef TgxslCustomMLBumpShaderMT inherited;
	
__published:
	__property MainTextureName = {default=0};
	__property NormalTextureName = {default=0};
	__property SpecularTextureName = {default=0};
	__property MaterialLibrary;
	__property BumpHeight = {default=0};
	__property BumpSmoothness;
	__property SpecularPower = {default=0};
	__property SpecularSpread = {default=0};
	__property LightPower = {default=0};
	__property LightSources = {default=2};
	__property LightCompensation = {default=0};
public:
	/* TgxslCustomMLBumpShaderMT.Create */ inline __fastcall virtual TgxslMLBumpShaderMT(System::Classes::TComponent* AOwner) : TgxslCustomMLBumpShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslMLBumpShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxBumpShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	Gxs::Context::TgxVertexProgramHandle* FVertexProgramHandle;
	Gxs::Context::TgxFragmentProgramHandle* FFragmentProgramHandle;
	Gxs::Vectorlists::TgxIntegerList* FLightIDs;
	int FLightsEnabled;
	TBumpMethod FBumpMethod;
	TBumpSpace FBumpSpace;
	TBumpOptions FBumpOptions;
	TSpecularMode FSpecularMode;
	bool FDesignTimeEnabled;
	bool FAmbientPass;
	bool FDiffusePass;
	System::Classes::TStringList* FVertexProgram;
	System::Classes::TStringList* FFragmentProgram;
	float FParallaxOffset;
	System::UnicodeString __fastcall GenerateVertexProgram();
	System::UnicodeString __fastcall GenerateFragmentProgram();
	void __fastcall DoLightPass(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, unsigned lightID);
	
protected:
	void __fastcall SetBumpMethod(const TBumpMethod Value);
	void __fastcall SetBumpSpace(const TBumpSpace Value);
	void __fastcall SetBumpOptions(const TBumpOptions Value);
	void __fastcall SetSpecularMode(const TSpecularMode Value);
	void __fastcall SetDesignTimeEnabled(const bool Value);
	void __fastcall SetParallaxOffset(const float Value);
	virtual void __fastcall Loaded();
	void __fastcall DeleteVertexPrograms();
	void __fastcall DeleteFragmentPrograms();
	
public:
	__fastcall virtual TgxBumpShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBumpShader();
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TBumpMethod BumpMethod = {read=FBumpMethod, write=SetBumpMethod, nodefault};
	__property TBumpSpace BumpSpace = {read=FBumpSpace, write=SetBumpSpace, nodefault};
	__property TBumpOptions BumpOptions = {read=FBumpOptions, write=SetBumpOptions, nodefault};
	__property TSpecularMode SpecularMode = {read=FSpecularMode, write=SetSpecularMode, nodefault};
	__property bool DesignTimeEnabled = {read=FDesignTimeEnabled, write=SetDesignTimeEnabled, nodefault};
	__property float ParallaxOffset = {read=FParallaxOffset, write=SetParallaxOffset};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Bumpshaders */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_BUMPSHADERS)
using namespace Gxsl::Bumpshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_BumpShadersHPP
