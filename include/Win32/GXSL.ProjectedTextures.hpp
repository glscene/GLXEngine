// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.ProjectedTextures.pas' rev: 36.00 (Windows)

#ifndef GXSL_ProjectedTexturesHPP
#define GXSL_ProjectedTexturesHPP

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
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Projectedtextures
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxslTextureEmitter;
class DELPHICLASS TgxslTextureEmitterItem;
class DELPHICLASS TgxslTextureEmitters;
class DELPHICLASS TgxslProjectedTextures;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxslProjectedTexturesStyle : unsigned char { ptsLight, ptsShadow };

class PASCALIMPLEMENTATION TgxslTextureEmitter : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	float FFOV;
	float FAspect;
	float FBrightness;
	float FAttenuation;
	TgxslProjectedTexturesStyle FStyle;
	Gxs::Color::TgxColor* FColor;
	bool FUseAttenuation;
	bool FAllowReverseProjection;
	bool FUseQuadraticAttenuation;
	
protected:
	TgxslProjectedTextures* ProjectedTexturesObject;
	Stage::Vectortypes::TMatrix4f TexMatrix;
	void __fastcall SetupTexMatrix();
	void __fastcall SetStyle(TgxslProjectedTexturesStyle val);
	void __fastcall SetUseAttenuation(bool val);
	void __fastcall SetUseQuadraticAttenuation(bool val);
	void __fastcall SetAllowReverseProjection(bool val);
	
public:
	__fastcall virtual TgxslTextureEmitter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxslTextureEmitter();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property float FOV = {read=FFOV, write=FFOV};
	__property float Aspect = {read=FAspect, write=FAspect};
	__property TgxslProjectedTexturesStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property float Attenuation = {read=FAttenuation, write=FAttenuation};
	__property float Brightness = {read=FBrightness, write=FBrightness};
	__property Gxs::Color::TgxColor* Color = {read=FColor, write=FColor};
	__property bool UseAttenuation = {read=FUseAttenuation, write=SetUseAttenuation, nodefault};
	__property bool UseQuadraticAttenuation = {read=FUseQuadraticAttenuation, write=SetUseQuadraticAttenuation, nodefault};
	__property bool AllowReverseProjection = {read=FAllowReverseProjection, write=SetAllowReverseProjection, nodefault};
	__property ObjectsSorting = {default=0};
	__property VisibilityCulling = {default=0};
	__property Direction;
	__property PitchAngle = {default=0};
	__property Position;
	__property RollAngle = {default=0};
	__property Scale;
	__property ShowAxes = {default=0};
	__property TurnAngle = {default=0};
	__property Up;
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxslTextureEmitter(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxslTextureEmitterItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxslTextureEmitter* FEmitter;
	
protected:
	void __fastcall SetEmitter(TgxslTextureEmitter* const val);
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxslTextureEmitterItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxslTextureEmitter* Emitter = {read=FEmitter, write=SetEmitter};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxslTextureEmitterItem() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxslTextureEmitters : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxslTextureEmitterItem* operator[](int index) { return this->Items[index]; }
	
private:
	TgxslProjectedTextures* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	TgxslTextureEmitterItem* __fastcall GetItems(int index);
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	
public:
	void __fastcall AddEmitter(TgxslTextureEmitter* texEmitter);
	__property TgxslTextureEmitterItem* Items[int index] = {read=GetItems/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TgxslTextureEmitters(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxslTextureEmitters() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxslProjectedTextures : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxslTextureEmitters* FEmitters;
	bool FUseLightmaps;
	Gxs::Context::TgxProgramHandle* Shader;
	Gxs::Color::TgxColor* FAmbient;
	void __fastcall SetupShader();
	
protected:
	bool ShaderChanged;
	void __fastcall SetUseLightmaps(bool val);
	
public:
	__fastcall virtual TgxslProjectedTextures(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxslProjectedTextures();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall StructureChanged();
	
__published:
	__property TgxslTextureEmitters* Emitters = {read=FEmitters, write=FEmitters};
	__property Gxs::Color::TgxColor* Ambient = {read=FAmbient, write=FAmbient};
	__property bool UseLightmaps = {read=FUseLightmaps, write=SetUseLightmaps, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxslProjectedTextures(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Projectedtextures */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_PROJECTEDTEXTURES)
using namespace Gxsl::Projectedtextures;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_ProjectedTexturesHPP
