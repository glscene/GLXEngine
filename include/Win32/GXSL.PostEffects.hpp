// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.PostEffects.pas' rev: 36.00 (Windows)

#ifndef GXSL_PostEffectsHPP
#define GXSL_PostEffectsHPP

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
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Graphics.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Posteffects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLPostShaderHolderException;
class DELPHICLASS TgxPostShaderCollectionItem;
class DELPHICLASS TgxPostShaderCollection;
class DELPHICLASS TgxPostShaderHolder;
struct TgxPostEffectColor;
class DELPHICLASS TgxPostEffect;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLPostShaderHolderException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLPostShaderHolderException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLPostShaderHolderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLPostShaderHolderException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLPostShaderHolderException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLPostShaderHolderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLPostShaderHolderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLPostShaderHolderException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLPostShaderHolderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLPostShaderHolderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLPostShaderHolderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLPostShaderHolderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLPostShaderHolderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLPostShaderHolderException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPostShaderCollectionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Material::TgxShader* FShader;
	Gxsl::Customshader::_di_IgxPostShader FPostShaderInterface;
	void __fastcall SetShader(Gxs::Material::TgxShader* const Value);
	
protected:
	TgxPostShaderHolder* __fastcall GetRealOwner();
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Material::TgxShader* Shader = {read=FShader, write=SetShader};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TgxPostShaderCollectionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxPostShaderCollectionItem() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPostShaderCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxPostShaderCollectionItem* operator[](const int Index) { return this->Items[Index]; }
	
private:
	TgxPostShaderCollectionItem* __fastcall GetItems(const int Index);
	void __fastcall SetItems(const int Index, TgxPostShaderCollectionItem* const Value);
	
public:
	void __fastcall Remove(Gxs::Material::TgxShader* const Item);
	HIDESBASE TgxPostShaderCollectionItem* __fastcall Add();
	__property TgxPostShaderCollectionItem* Items[const int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxPostShaderCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxPostShaderCollection() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxPostShaderHolder : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	TgxPostShaderCollection* FShaders;
	Gxs::Context::TgxTextureHandle* FTempTexture;
	Gxs::Rendercontextinfo::TGXSize FPreviousViewportSize;
	Stage::Textureformat::TglTextureTarget FTempTextureTarget;
	void __fastcall SetShaders(TgxPostShaderCollection* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxPostShaderHolder(System::Classes::TComponent* Owner);
	__fastcall virtual ~TgxPostShaderHolder();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property Stage::Textureformat::TglTextureTarget TempTextureTarget = {read=FTempTextureTarget, write=FTempTextureTarget, default=2};
	__property TgxPostShaderCollection* Shaders = {read=FShaders, write=SetShaders};
	__property Visible = {default=1};
	__property OnProgress;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPostShaderHolder(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


struct DECLSPEC_DRECORD TgxPostEffectColor
{
public:
	System::Byte R;
	System::Byte G;
	System::Byte B;
	System::Byte A;
};


typedef System::DynamicArray<TgxPostEffectColor> TgxPostEffectBuffer;

typedef void __fastcall (__closure *TgxOnCustomPostEffectEvent)(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxPostEffectBuffer &Buffer);

enum DECLSPEC_DENUM TgxPostEffectPreset : unsigned char { pepNone, pepGray, pepNegative, pepDistort, pepNoise, pepNightVision, pepBlur, pepCustom };

class PASCALIMPLEMENTATION TgxPostEffect : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	TgxOnCustomPostEffectEvent FOnCustomEffect;
	TgxPostEffectPreset FPreset;
	TgxPostEffectBuffer FRenderBuffer;
	
protected:
	virtual void __fastcall MakeGrayEffect();
	virtual void __fastcall MakeNegativeEffect();
	virtual void __fastcall MakeDistortEffect();
	virtual void __fastcall MakeNoiseEffect();
	virtual void __fastcall MakeNightVisionEffect();
	virtual void __fastcall MakeBlurEffect(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoOnCustomEffect(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxPostEffectBuffer &Buffer);
	
public:
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxPostEffectPreset Preset = {read=FPreset, write=FPreset, default=0};
	__property TgxOnCustomPostEffectEvent OnCustomEffect = {read=FOnCustomEffect, write=FOnCustomEffect};
	__property Visible = {default=1};
	__property OnProgress;
public:
	/* TgxBaseSceneObject.Create */ inline __fastcall virtual TgxPostEffect(System::Classes::TComponent* AOwner) : Gxs::Scene::TgxBaseSceneObject(AOwner) { }
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPostEffect(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	/* TgxBaseSceneObject.Destroy */ inline __fastcall virtual ~TgxPostEffect() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Posteffects */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_POSTEFFECTS)
using namespace Gxsl::Posteffects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_PostEffectsHPP
