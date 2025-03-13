// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.PostShaders.pas' rev: 36.00 (Windows)

#ifndef GXSL_PostShadersHPP
#define GXSL_PostShadersHPP

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
#include <GXS.Texture.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>
#include <GXSL.Shader.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Postshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxslCustomPostBlurShader;
class DELPHICLASS TgxslPostBlurShader;
class DELPHICLASS TgxslCustomPostThermalVisionShader;
class DELPHICLASS TgxslPostThermalVisionShader;
class DELPHICLASS TgxslCustomPostDreamVisionShader;
class DELPHICLASS TgxSLPostDreamVisionShader;
class DELPHICLASS TgxslCustomPostNightVisionShader;
class DELPHICLASS TgxslPostNightVisionShader;
class DELPHICLASS TgxslCustomPostPixelateShader;
class DELPHICLASS TgxslPostPixelateShader;
class DELPHICLASS TgxslCustomPostPosterizeShader;
class DELPHICLASS TgxslPostPosterizeShader;
class DELPHICLASS TgxslCustomPostFrostShader;
class DELPHICLASS TgxslPostFrostShader;
class DELPHICLASS TgxslCustomPostTroubleShader;
class DELPHICLASS TgxslPostTroubleShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxslCustomPostBlurShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FThreshold;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreThreshold();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostBlurShader(System::Classes::TComponent* AOwner);
	__property float Threshold = {read=FThreshold, write=FThreshold, stored=StoreThreshold};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostBlurShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostBlurShader : public TgxslCustomPostBlurShader
{
	typedef TgxslCustomPostBlurShader inherited;
	
__published:
	__property Threshold = {default=0};
public:
	/* TgxslCustomPostBlurShader.Create */ inline __fastcall virtual TgxslPostBlurShader(System::Classes::TComponent* AOwner) : TgxslCustomPostBlurShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostBlurShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostThermalVisionShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FThreshold;
	float Fintensity;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreThreshold();
	bool __fastcall StoreIntensity();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostThermalVisionShader(System::Classes::TComponent* AOwner);
	__property float Threshold = {read=FThreshold, write=FThreshold, stored=StoreThreshold};
	__property float Intensity = {read=Fintensity, write=Fintensity, stored=StoreIntensity};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostThermalVisionShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostThermalVisionShader : public TgxslCustomPostThermalVisionShader
{
	typedef TgxslCustomPostThermalVisionShader inherited;
	
__published:
	__property Threshold = {default=0};
	__property Intensity = {default=0};
public:
	/* TgxslCustomPostThermalVisionShader.Create */ inline __fastcall virtual TgxslPostThermalVisionShader(System::Classes::TComponent* AOwner) : TgxslCustomPostThermalVisionShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostThermalVisionShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostDreamVisionShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FThreshold;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreThreshold();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostDreamVisionShader(System::Classes::TComponent* AOwner);
	__property float Threshold = {read=FThreshold, write=FThreshold, stored=StoreThreshold};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostDreamVisionShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxSLPostDreamVisionShader : public TgxslCustomPostDreamVisionShader
{
	typedef TgxslCustomPostDreamVisionShader inherited;
	
__published:
	__property Threshold = {default=0};
public:
	/* TgxslCustomPostDreamVisionShader.Create */ inline __fastcall virtual TgxSLPostDreamVisionShader(System::Classes::TComponent* AOwner) : TgxslCustomPostDreamVisionShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxSLPostDreamVisionShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostNightVisionShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	float FLuminanceThreshold;
	float FColorAmplification;
	float FElapsedTime;
	int FUseMask;
	Gxs::Texture::TgxTexture* FNoiseTex;
	Gxs::Texture::TgxTexture* FMaskTex;
	Gxs::Material::TgxLibMaterialName FNoiseTexName;
	Gxs::Material::TgxLibMaterialName FMaskTexName;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreLuminanceThreshold();
	bool __fastcall StoreColorAmplification();
	void __fastcall SetMaskTexTexture(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetNoiseTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMaskTexName();
	void __fastcall SetMaskTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxslCustomPostNightVisionShader(System::Classes::TComponent* AOwner);
	__property float LuminanceThreshold = {read=FLuminanceThreshold, write=FLuminanceThreshold, stored=StoreLuminanceThreshold};
	__property float ColorAmplification = {read=FColorAmplification, write=FColorAmplification, stored=StoreColorAmplification};
	__property float ElapsedTime = {read=FElapsedTime, write=FElapsedTime, stored=false};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* NoiseTex = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gxs::Material::TgxLibMaterialName NoiseTexName = {read=GetNoiseTexName, write=SetNoiseTexName};
	__property Gxs::Texture::TgxTexture* MaskTex = {read=FMaskTex, write=SetMaskTexTexture};
	__property Gxs::Material::TgxLibMaterialName MaskTexName = {read=GetMaskTexName, write=SetMaskTexName};
	__property int UseMask = {read=FUseMask, write=FUseMask, nodefault};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostNightVisionShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostNightVisionShader : public TgxslCustomPostNightVisionShader
{
	typedef TgxslCustomPostNightVisionShader inherited;
	
__published:
	__property LuminanceThreshold = {default=0};
	__property ColorAmplification = {default=0};
	__property ElapsedTime = {default=0};
	__property MaterialLibrary;
	__property NoiseTexName = {default=0};
	__property MaskTexName = {default=0};
	__property UseMask;
public:
	/* TgxslCustomPostNightVisionShader.Create */ inline __fastcall virtual TgxslPostNightVisionShader(System::Classes::TComponent* AOwner) : TgxslCustomPostNightVisionShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostNightVisionShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostPixelateShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FPixelWidth;
	float FPixelHeight;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StorePixelWidth();
	bool __fastcall StorePixelHeight();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostPixelateShader(System::Classes::TComponent* AOwner);
	__property float PixelWidth = {read=FPixelWidth, write=FPixelWidth, stored=StorePixelWidth};
	__property float PixelHeight = {read=FPixelHeight, write=FPixelHeight, stored=StorePixelHeight};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostPixelateShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostPixelateShader : public TgxslCustomPostPixelateShader
{
	typedef TgxslCustomPostPixelateShader inherited;
	
__published:
	__property PixelWidth = {default=0};
	__property PixelHeight = {default=0};
public:
	/* TgxslCustomPostPixelateShader.Create */ inline __fastcall virtual TgxslPostPixelateShader(System::Classes::TComponent* AOwner) : TgxslCustomPostPixelateShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostPixelateShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostPosterizeShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FGamma;
	float FNumColors;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreGamma();
	bool __fastcall StoreNumColors();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostPosterizeShader(System::Classes::TComponent* AOwner);
	__property float Gamma = {read=FGamma, write=FGamma, stored=StoreGamma};
	__property float NumColors = {read=FNumColors, write=FNumColors, stored=StoreNumColors};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostPosterizeShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostPosterizeShader : public TgxslCustomPostPosterizeShader
{
	typedef TgxslCustomPostPosterizeShader inherited;
	
__published:
	__property Gamma = {default=0};
	__property NumColors = {default=0};
public:
	/* TgxslCustomPostPosterizeShader.Create */ inline __fastcall virtual TgxslPostPosterizeShader(System::Classes::TComponent* AOwner) : TgxslCustomPostPosterizeShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostPosterizeShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostFrostShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FRandScale;
	float FRandFactor;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	bool __fastcall StoreRandScale();
	bool __fastcall StoreRandFactor();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxslCustomPostFrostShader(System::Classes::TComponent* AOwner);
	__property float RandScale = {read=FRandScale, write=FRandScale, stored=StoreRandScale};
	__property float RandFactor = {read=FRandFactor, write=FRandFactor, stored=StoreRandFactor};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostFrostShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostFrostShader : public TgxslCustomPostFrostShader
{
	typedef TgxslCustomPostFrostShader inherited;
	
__published:
	__property RandScale = {default=0};
	__property RandFactor = {default=0};
public:
	/* TgxslCustomPostFrostShader.Create */ inline __fastcall virtual TgxslPostFrostShader(System::Classes::TComponent* AOwner) : TgxslCustomPostFrostShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostFrostShader() { }
	
};


class PASCALIMPLEMENTATION TgxslCustomPostTroubleShader : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FPixelX;
	float FPixelY;
	float FFreq;
	Gxs::Material::TgxAbstractMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FNoiseTex;
	Gxs::Material::TgxLibMaterialName FNoiseTexName;
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	void __fastcall SetNoiseTexTexture(Gxs::Texture::TgxTexture* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	bool __fastcall StorePixelX();
	bool __fastcall StorePixelY();
	bool __fastcall StoreFreq();
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxslCustomPostTroubleShader(System::Classes::TComponent* AOwner);
	__property float PixelX = {read=FPixelX, write=FPixelX, stored=StorePixelX};
	__property float PixelY = {read=FPixelY, write=FPixelY, stored=StorePixelY};
	__property float Freq = {read=FFreq, write=FFreq, stored=StoreFreq};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Texture::TgxTexture* NoiseTex = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gxs::Material::TgxLibMaterialName NoiseTexName = {read=GetNoiseTexName, write=SetNoiseTexName};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslCustomPostTroubleShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxslPostTroubleShader : public TgxslCustomPostTroubleShader
{
	typedef TgxslCustomPostTroubleShader inherited;
	
__published:
	__property PixelX = {default=0};
	__property PixelY = {default=0};
	__property Freq = {default=0};
	__property MaterialLibrary;
	__property NoiseTexName = {default=0};
public:
	/* TgxslCustomPostTroubleShader.Create */ inline __fastcall virtual TgxslPostTroubleShader(System::Classes::TComponent* AOwner) : TgxslCustomPostTroubleShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxslPostTroubleShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Postshaders */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_POSTSHADERS)
using namespace Gxsl::Postshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_PostShadersHPP
