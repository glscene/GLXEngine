// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.ShapeShaders.pas' rev: 36.00 (Windows)

#ifndef GXSL_ShapeShadersHPP
#define GXSL_ShapeShadersHPP

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
#include <GXS.Scene.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Color.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXSL.Shader.hpp>
#include <GXSL.CustomShader.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Shapeshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCelShader;
class DELPHICLASS TgxCustomGLSLSimpleErosionShader;
class DELPHICLASS TgxSLSimpleErosionShader;
class DELPHICLASS TgxCustomGLSLGlassShader;
class DELPHICLASS TgxSLGlassShader;
class DELPHICLASS TgxCustomGLSLSimpleGoochShader;
class DELPHICLASS TgxSLSimpleGoochShader;
class DELPHICLASS TgxCustomGLSLFurShader;
class DELPHICLASS TgxSLFurShader;
class DELPHICLASS TgxCustomGLSLIvoryShader;
class DELPHICLASS TgxSLIvoryShader;
class DELPHICLASS TgxCustomGLSLSimpleLatticeShader;
class DELPHICLASS TgxCustomGLSLLatticeShader;
class DELPHICLASS TgxSLSimpleLatticeShader;
class DELPHICLASS TgxSLLatticeShader;
class DELPHICLASS TgxCustomGLSLSemShader;
class DELPHICLASS TgxSLSemShader;
class DELPHICLASS TgxCustomGLSLToonShader;
class DELPHICLASS TgxSLToonShader;
class DELPHICLASS TgxCustomGLSLVertexDisplacementShader;
class DELPHICLASS TgxSLVertexDisplacementShader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxCelShaderOption : unsigned char { csoOutlines, csoTextured, csoNoBuildShadeTexture };

typedef System::Set<TgxCelShaderOption, TgxCelShaderOption::csoOutlines, TgxCelShaderOption::csoNoBuildShadeTexture> TgxCelShaderOptions;

typedef void __fastcall (__closure *TgxCelShaderGetIntensity)(System::TObject* Sender, System::Byte &intensity);

class PASCALIMPLEMENTATION TgxCelShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	float FOutlineWidth;
	TgxCelShaderOptions FCelShaderOptions;
	Gxs::Context::TgxVertexProgramHandle* FVPHandle;
	Gxs::Texture::TgxTexture* FShadeTexture;
	TgxCelShaderGetIntensity FOnGetIntensity;
	bool FOutlinePass;
	bool FUnApplyShadeTexture;
	Gxs::Color::TgxColor* FOutlineColor;
	
protected:
	void __fastcall SetCelShaderOptions(const TgxCelShaderOptions val);
	void __fastcall SetOutlineWidth(const float val);
	void __fastcall SetOutlineColor(Gxs::Color::TgxColor* const val);
	void __fastcall BuildShadeTexture();
	virtual void __fastcall Loaded();
	System::UnicodeString __fastcall GenerateVertexProgram();
	
public:
	__fastcall virtual TgxCelShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCelShader();
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property Gxs::Texture::TgxTexture* ShadeTexture = {read=FShadeTexture};
	
__published:
	__property TgxCelShaderOptions CelShaderOptions = {read=FCelShaderOptions, write=SetCelShaderOptions, nodefault};
	__property Gxs::Color::TgxColor* OutlineColor = {read=FOutlineColor, write=SetOutlineColor};
	__property float OutlineWidth = {read=FOutlineWidth, write=SetOutlineWidth};
	__property TgxCelShaderGetIntensity OnGetIntensity = {read=FOnGetIntensity, write=FOnGetIntensity};
};


class PASCALIMPLEMENTATION TgxCustomGLSLSimpleErosionShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTex;
	Gxs::Texture::TgxTexture* FNoiseTex;
	Gxs::Texture::TgxTexture* FErosionTex;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	Gxs::Material::TgxLibMaterialName FNoiseTexName;
	Gxs::Material::TgxLibMaterialName FErosionTexName;
	float FErosionScale;
	float FErosionFactor;
	float FIntensityFactor1;
	float FIntensityFactor2;
	Gxs::Color::TgxColor* FSpecularColor;
	Gxs::Color::TgxColor* FAmbientColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	float FSpecularRoughness;
	float FAnisotropicRoughness;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetNoiseTexTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetErosionTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetErosionTexName();
	void __fastcall SetErosionTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecularColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLSimpleErosionShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLSimpleErosionShader();
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTex, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gxs::Texture::TgxTexture* NoiseTexture = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gxs::Material::TgxLibMaterialName NoiseTextureName = {read=GetNoiseTexName, write=SetNoiseTexName};
	__property Gxs::Texture::TgxTexture* ErosionTexture = {read=FErosionTex, write=SetErosionTexTexture};
	__property Gxs::Material::TgxLibMaterialName ErosionTextureName = {read=GetErosionTexName, write=SetErosionTexName};
	__property float ErosionFactor = {read=FErosionFactor, write=FErosionFactor};
	__property float ErosionScale = {read=FErosionFactor, write=FErosionFactor};
	__property float IntensityFactor1 = {read=FIntensityFactor1, write=FIntensityFactor1};
	__property float IntensityFactor2 = {read=FIntensityFactor2, write=FIntensityFactor2};
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property float SpecularRoughness = {read=FSpecularRoughness, write=FSpecularRoughness};
	__property float AnisotropicRoughness = {read=FAnisotropicRoughness, write=FAnisotropicRoughness};
};


class PASCALIMPLEMENTATION TgxSLSimpleErosionShader : public TgxCustomGLSLSimpleErosionShader
{
	typedef TgxCustomGLSLSimpleErosionShader inherited;
	
__published:
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property NoiseTexture;
	__property NoiseTextureName = {default=0};
	__property ErosionTexture;
	__property ErosionTextureName = {default=0};
	__property ErosionScale = {default=0};
	__property ErosionFactor = {default=0};
	__property IntensityFactor1 = {default=0};
	__property IntensityFactor2 = {default=0};
	__property SpecularColor;
	__property AmbientColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property SpecularRoughness = {default=0};
	__property AnisotropicRoughness = {default=0};
public:
	/* TgxCustomGLSLSimpleErosionShader.Create */ inline __fastcall virtual TgxSLSimpleErosionShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLSimpleErosionShader(AOwner) { }
	/* TgxCustomGLSLSimpleErosionShader.Destroy */ inline __fastcall virtual ~TgxSLSimpleErosionShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLGlassShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Color::TgxColor* FDiffuseColor;
	float FDepth;
	float FMix;
	float FAlpha;
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	Gxs::Texture::TgxTexture* FRefractionTexture;
	Gxs::Material::TgxLibMaterialName FRefractionTexName;
	Gxs::Scene::TgxBaseSceneObject* FOwnerObject;
	Gxs::State::TgxBlendFunction FBlendSrc;
	Gxs::State::TgxBlendFunction FBlendDst;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetRefractionTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetRefractionTexName();
	void __fastcall SetRefractionTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetDiffuseColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLGlassShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLGlassShader();
	__property Gxs::Color::TgxColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property float Depth = {read=FDepth, write=FDepth};
	__property float Mix = {read=FMix, write=FMix};
	__property float Alpha = {read=FAlpha, write=FAlpha};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gxs::Texture::TgxTexture* RefractionTexture = {read=FRefractionTexture, write=SetRefractionTexTexture};
	__property Gxs::Material::TgxLibMaterialName RefractionTextureName = {read=GetRefractionTexName, write=SetRefractionTexName};
	__property Gxs::Scene::TgxBaseSceneObject* OwnerObject = {read=FOwnerObject, write=FOwnerObject};
	__property Gxs::State::TgxBlendFunction BlendSrc = {read=FBlendSrc, write=FBlendSrc, default=6};
	__property Gxs::State::TgxBlendFunction BlendDst = {read=FBlendDst, write=FBlendDst, default=8};
};


class PASCALIMPLEMENTATION TgxSLGlassShader : public TgxCustomGLSLGlassShader
{
	typedef TgxCustomGLSLGlassShader inherited;
	
__published:
	__property DiffuseColor;
	__property Depth = {default=0};
	__property Mix = {default=0};
	__property Alpha = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property RefractionTexture;
	__property RefractionTextureName = {default=0};
	__property OwnerObject;
	__property BlendSrc = {default=6};
	__property BlendDst = {default=8};
public:
	/* TgxCustomGLSLGlassShader.Create */ inline __fastcall virtual TgxSLGlassShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLGlassShader(AOwner) { }
	/* TgxCustomGLSLGlassShader.Destroy */ inline __fastcall virtual ~TgxSLGlassShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLSimpleGoochShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Color::TgxColor* FDiffuseColor;
	Gxs::Color::TgxColor* FWarmColor;
	Gxs::Color::TgxColor* FCoolColor;
	Gxs::Color::TgxColor* FSpecularColor;
	Gxs::Color::TgxColor* FAmbientColor;
	float FDiffuseWarm;
	float FDiffuseCool;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Gxsl::Customshader::TgxBlendingModeEx FBlendingMode;
	void __fastcall SetDiffuseColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecularColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetWarmColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetCoolColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxCustomGLSLSimpleGoochShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLSimpleGoochShader();
	__property Gxs::Color::TgxColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property Gxs::Color::TgxColor* WarmColor = {read=FWarmColor, write=SetWarmColor};
	__property Gxs::Color::TgxColor* CoolColor = {read=FCoolColor, write=SetCoolColor};
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float WarmFactor = {read=FDiffuseWarm, write=FDiffuseWarm};
	__property float CoolFactor = {read=FDiffuseCool, write=FDiffuseCool};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Gxsl::Customshader::TgxBlendingModeEx BlendingMode = {read=FBlendingMode, write=FBlendingMode, default=0};
};


class PASCALIMPLEMENTATION TgxSLSimpleGoochShader : public TgxCustomGLSLSimpleGoochShader
{
	typedef TgxCustomGLSLSimpleGoochShader inherited;
	
__published:
	__property DiffuseColor;
	__property WarmColor;
	__property CoolColor;
	__property SpecularColor;
	__property AmbientColor;
	__property WarmFactor = {default=0};
	__property CoolFactor = {default=0};
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
public:
	/* TgxCustomGLSLSimpleGoochShader.Create */ inline __fastcall virtual TgxSLSimpleGoochShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLSimpleGoochShader(AOwner) { }
	/* TgxCustomGLSLSimpleGoochShader.Destroy */ inline __fastcall virtual ~TgxSLSimpleGoochShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLFurShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	int FCurrentPass;
	float FPassCount;
	float FFurLength;
	float FMaxFurLength;
	float FFurScale;
	bool FRandomFurLength;
	Gxs::Color::TgxColor* FColorScale;
	Gxs::Color::TgxColor* FAmbient;
	Gxs::Coordinates::TgxCoordinates* FGravity;
	float FLightIntensity;
	Gxs::Texture::TgxTexture* FMainTex;
	Gxs::Texture::TgxTexture* FNoiseTex;
	Gxs::Material::TgxLibMaterialName FNoiseTexName;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	Gxs::State::TgxBlendFunction FBlendSrc;
	Gxs::State::TgxBlendFunction FBlendDst;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetNoiseTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetGravity(Gxs::Coordinates::TgxCoordinates* APosition);
	void __fastcall SetAmbient(Gxs::Color::TgxColor* AValue);
	void __fastcall SetColorScale(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLFurShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLFurShader();
	__property float PassCount = {read=FPassCount, write=FPassCount};
	__property float FurLength = {read=FFurLength, write=FFurLength};
	__property float MaxFurLength = {read=FMaxFurLength, write=FMaxFurLength};
	__property float FurDensity = {read=FFurScale, write=FFurScale};
	__property bool RandomFurLength = {read=FRandomFurLength, write=FRandomFurLength, nodefault};
	__property Gxs::Color::TgxColor* ColorScale = {read=FColorScale, write=SetColorScale};
	__property Gxs::Color::TgxColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTex, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gxs::Texture::TgxTexture* NoiseTexture = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gxs::Material::TgxLibMaterialName NoiseTextureName = {read=GetNoiseTexName, write=SetNoiseTexName};
	__property Gxs::State::TgxBlendFunction BlendSrc = {read=FBlendSrc, write=FBlendSrc, default=2};
	__property Gxs::State::TgxBlendFunction BlendDst = {read=FBlendDst, write=FBlendDst, default=5};
	__property Gxs::Coordinates::TgxCoordinates* Gravity = {read=FGravity, write=SetGravity};
	__property float LightIntensity = {read=FLightIntensity, write=FLightIntensity};
};


class PASCALIMPLEMENTATION TgxSLFurShader : public TgxCustomGLSLFurShader
{
	typedef TgxCustomGLSLFurShader inherited;
	
__published:
	__property PassCount = {default=0};
	__property FurLength = {default=0};
	__property MaxFurLength = {default=0};
	__property FurDensity = {default=0};
	__property RandomFurLength;
	__property ColorScale;
	__property Ambient;
	__property LightIntensity = {default=0};
	__property Gravity;
	__property BlendSrc = {default=2};
	__property BlendDst = {default=5};
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property NoiseTexture;
	__property NoiseTextureName = {default=0};
public:
	/* TgxCustomGLSLFurShader.Create */ inline __fastcall virtual TgxSLFurShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLFurShader(AOwner) { }
	/* TgxCustomGLSLFurShader.Destroy */ inline __fastcall virtual ~TgxSLFurShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLIvoryShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxCustomGLSLIvoryShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLIvoryShader();
};


class PASCALIMPLEMENTATION TgxSLIvoryShader : public TgxCustomGLSLIvoryShader
{
	typedef TgxCustomGLSLIvoryShader inherited;
	
public:
	/* TgxCustomGLSLIvoryShader.Create */ inline __fastcall virtual TgxSLIvoryShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLIvoryShader(AOwner) { }
	/* TgxCustomGLSLIvoryShader.Destroy */ inline __fastcall virtual ~TgxSLIvoryShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLSimpleLatticeShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates2* FLatticeScale;
	Gxs::Coordinates::TgxCoordinates2* FLatticeThreshold;
	void __fastcall SetLatticeScale(Gxs::Coordinates::TgxCoordinates2* const Value);
	void __fastcall SetLatticeThreshold(Gxs::Coordinates::TgxCoordinates2* const Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxCustomGLSLSimpleLatticeShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLSimpleLatticeShader();
	__property Gxs::Coordinates::TgxCoordinates2* LatticeScale = {read=FLatticeScale, write=SetLatticeScale};
	__property Gxs::Coordinates::TgxCoordinates2* LatticeThreshold = {read=FLatticeThreshold, write=SetLatticeThreshold};
};


class PASCALIMPLEMENTATION TgxCustomGLSLLatticeShader : public TgxCustomGLSLSimpleLatticeShader
{
	typedef TgxCustomGLSLSimpleLatticeShader inherited;
	
private:
	Gxs::Color::TgxColor* FAmbientColor;
	Gxs::Color::TgxColor* FDiffuseColor;
	Gxs::Color::TgxColor* FSpecularColor;
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	float FSpecularPower;
	float FLightPower;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetDiffuseColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecularColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLLatticeShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLLatticeShader();
	__property Gxs::Color::TgxColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property float SpecularPower = {read=FSpecularPower, write=FSpecularPower};
	__property float LightPower = {read=FLightPower, write=FLightPower};
};


class PASCALIMPLEMENTATION TgxSLSimpleLatticeShader : public TgxCustomGLSLSimpleLatticeShader
{
	typedef TgxCustomGLSLSimpleLatticeShader inherited;
	
__published:
	__property LatticeScale;
	__property LatticeThreshold;
public:
	/* TgxCustomGLSLSimpleLatticeShader.Create */ inline __fastcall virtual TgxSLSimpleLatticeShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLSimpleLatticeShader(AOwner) { }
	/* TgxCustomGLSLSimpleLatticeShader.Destroy */ inline __fastcall virtual ~TgxSLSimpleLatticeShader() { }
	
};


class PASCALIMPLEMENTATION TgxSLLatticeShader : public TgxCustomGLSLLatticeShader
{
	typedef TgxCustomGLSLLatticeShader inherited;
	
__published:
	__property LatticeScale;
	__property LatticeThreshold;
	__property AmbientColor;
	__property DiffuseColor;
	__property SpecularColor;
	__property MainTexture;
	__property SpecularPower = {default=0};
	__property LightPower = {default=0};
public:
	/* TgxCustomGLSLLatticeShader.Create */ inline __fastcall virtual TgxSLLatticeShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLLatticeShader(AOwner) { }
	/* TgxCustomGLSLLatticeShader.Destroy */ inline __fastcall virtual ~TgxSLLatticeShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLSemShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Color::TgxColor* FAmbientColor;
	Gxs::Color::TgxColor* FSpecularColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecularColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLSemShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLSemShader();
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
};


class PASCALIMPLEMENTATION TgxSLSemShader : public TgxCustomGLSLSemShader
{
	typedef TgxCustomGLSLSemShader inherited;
	
__published:
	__property AmbientColor;
	__property SpecularColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
public:
	/* TgxCustomGLSLSemShader.Create */ inline __fastcall virtual TgxSLSemShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLSemShader(AOwner) { }
	/* TgxCustomGLSLSemShader.Destroy */ inline __fastcall virtual ~TgxSLSemShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLToonShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Color::TgxColor* FHighlightColor;
	Gxs::Color::TgxColor* FMidColor;
	Gxs::Color::TgxColor* FLightenShadowColor;
	Gxs::Color::TgxColor* FDarkenShadowColor;
	Gxs::Color::TgxColor* FOutlineColor;
	float FHighlightSize;
	float FMidSize;
	float FShadowSize;
	float FOutlineWidth;
	void __fastcall SetHighLightColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetMidColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetLightenShadowColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetDarkenShadowColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetOutlineColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxCustomGLSLToonShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLToonShader();
	__property Gxs::Color::TgxColor* HighlightColor = {read=FHighlightColor, write=SetHighLightColor};
	__property Gxs::Color::TgxColor* MidColor = {read=FMidColor, write=SetMidColor};
	__property Gxs::Color::TgxColor* LightenShadowColor = {read=FLightenShadowColor, write=SetLightenShadowColor};
	__property Gxs::Color::TgxColor* DarkenShadowrColor = {read=FDarkenShadowColor, write=SetDarkenShadowColor};
	__property Gxs::Color::TgxColor* OutlinetColor = {read=FOutlineColor, write=SetOutlineColor};
	__property float HighlightSize = {read=FHighlightSize, write=FHighlightSize};
	__property float MidSize = {read=FMidSize, write=FMidSize};
	__property float ShadowSize = {read=FShadowSize, write=FShadowSize};
	__property float OutlineWidth = {read=FOutlineWidth, write=FOutlineWidth};
};


class PASCALIMPLEMENTATION TgxSLToonShader : public TgxCustomGLSLToonShader
{
	typedef TgxCustomGLSLToonShader inherited;
	
__published:
	__property HighlightColor;
	__property MidColor;
	__property LightenShadowColor;
	__property DarkenShadowrColor;
	__property OutlinetColor;
	__property HighlightSize = {default=0};
	__property MidSize = {default=0};
	__property ShadowSize = {default=0};
	__property OutlineWidth = {default=0};
public:
	/* TgxCustomGLSLToonShader.Create */ inline __fastcall virtual TgxSLToonShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLToonShader(AOwner) { }
	/* TgxCustomGLSLToonShader.Destroy */ inline __fastcall virtual ~TgxSLToonShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLVertexDisplacementShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Color::TgxColor* FAmbientColor;
	Gxs::Color::TgxColor* FSpecularColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTexName;
	float FElapsedTime;
	float FNoise;
	float FDisplacementScale;
	float FNoiseScale;
	float FTurbulenceFactor;
	float FNoisePeriod;
	float FTimeFactor;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecularColor(Gxs::Color::TgxColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCustomGLSLVertexDisplacementShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomGLSLVertexDisplacementShader();
	__property Gxs::Color::TgxColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property float ElapsedTime = {read=FElapsedTime, write=FElapsedTime};
	__property float NoiseFactor = {read=FNoise, write=FNoise};
	__property float NoiseScale = {read=FNoiseScale, write=FNoiseScale};
	__property float TurbulenceFactor = {read=FTurbulenceFactor, write=FTurbulenceFactor};
	__property float NoisePeriod = {read=FNoisePeriod, write=FNoisePeriod};
	__property float DisplacementScale = {read=FDisplacementScale, write=FDisplacementScale};
	__property float TimeFactor = {read=FTimeFactor, write=FTimeFactor};
};


class PASCALIMPLEMENTATION TgxSLVertexDisplacementShader : public TgxCustomGLSLVertexDisplacementShader
{
	typedef TgxCustomGLSLVertexDisplacementShader inherited;
	
__published:
	__property AmbientColor;
	__property SpecularColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property ElapsedTime = {default=0};
	__property NoiseFactor = {default=0};
	__property NoiseScale = {default=0};
	__property TurbulenceFactor = {default=0};
	__property NoisePeriod = {default=0};
	__property DisplacementScale = {default=0};
	__property TimeFactor = {default=0};
public:
	/* TgxCustomGLSLVertexDisplacementShader.Create */ inline __fastcall virtual TgxSLVertexDisplacementShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLVertexDisplacementShader(AOwner) { }
	/* TgxCustomGLSLVertexDisplacementShader.Destroy */ inline __fastcall virtual ~TgxSLVertexDisplacementShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shapeshaders */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_SHAPESHADERS)
using namespace Gxsl::Shapeshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_ShapeShadersHPP
