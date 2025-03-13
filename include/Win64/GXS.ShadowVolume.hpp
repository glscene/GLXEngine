// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ShadowVolume.pas' rev: 36.00 (Windows)

#ifndef GXS_ShadowVolumeHPP
#define GXS_ShadowVolumeHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.State.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Shadowvolume
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxShadowVolumeCaster;
class DELPHICLASS TgxShadowVolumeOccluder;
class DELPHICLASS TgxShadowVolumeLight;
class DELPHICLASS TgxShadowVolumeCasters;
class DELPHICLASS TgxShadowVolume;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxShadowVolumeCapping : unsigned char { svcDefault, svcAlways, svcNever };

enum DECLSPEC_DENUM TgxShadowCastingMode : unsigned char { scmAlways, scmVisible, scmRecursivelyVisible, scmParentVisible, scmParentRecursivelyVisible };

class PASCALIMPLEMENTATION TgxShadowVolumeCaster : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* FCaster;
	float FEffectiveRadius;
	TgxShadowVolumeCapping FCapping;
	TgxShadowCastingMode FCastingMode;
	
protected:
	void __fastcall SetCaster(Gxs::Scene::TgxBaseSceneObject* const val);
	TgxShadowVolume* __fastcall GetGLShadowVolume();
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxShadowVolumeCaster(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxShadowVolumeCaster();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Gxs::Scene::TgxBaseSceneObject* Caster = {read=FCaster, write=SetCaster};
	__property TgxShadowVolume* GLShadowVolume = {read=GetGLShadowVolume};
	
__published:
	__property float EffectiveRadius = {read=FEffectiveRadius, write=FEffectiveRadius};
	__property TgxShadowVolumeCapping Capping = {read=FCapping, write=FCapping, default=0};
	__property TgxShadowCastingMode CastingMode = {read=FCastingMode, write=FCastingMode, default=2};
};


class PASCALIMPLEMENTATION TgxShadowVolumeOccluder : public TgxShadowVolumeCaster
{
	typedef TgxShadowVolumeCaster inherited;
	
__published:
	__property Caster;
public:
	/* TgxShadowVolumeCaster.Create */ inline __fastcall virtual TgxShadowVolumeOccluder(System::Classes::TCollection* ACollection) : TgxShadowVolumeCaster(ACollection) { }
	/* TgxShadowVolumeCaster.Destroy */ inline __fastcall virtual ~TgxShadowVolumeOccluder() { }
	
};


class PASCALIMPLEMENTATION TgxShadowVolumeLight : public TgxShadowVolumeCaster
{
	typedef TgxShadowVolumeCaster inherited;
	
private:
	Gxs::Persistentclasses::TgxPersistentObjectList* FSilhouettes;
	
protected:
	Gxs::Scene::TgxLightSource* __fastcall GetLightSource();
	void __fastcall SetLightSource(Gxs::Scene::TgxLightSource* const ls);
	Gxs::Silhouette::TgxSilhouette* __fastcall GetCachedSilhouette(int AIndex);
	void __fastcall StoreCachedSilhouette(int AIndex, Gxs::Silhouette::TgxSilhouette* ASil);
	bool __fastcall SetupScissorRect(Gxs::Geometrybb::PAABB worldAABB, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxShadowVolumeLight(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxShadowVolumeLight();
	void __fastcall FlushSilhouetteCache();
	
__published:
	__property Gxs::Scene::TgxLightSource* LightSource = {read=GetLightSource, write=SetLightSource};
};


class PASCALIMPLEMENTATION TgxShadowVolumeCasters : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxShadowVolumeCaster* operator[](int index) { return this->Items[index]; }
	
protected:
	TgxShadowVolumeCaster* __fastcall GetItems(int index);
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	
public:
	TgxShadowVolumeCaster* __fastcall AddCaster(Gxs::Scene::TgxBaseSceneObject* obj, float effectiveRadius = 0.000000E+00f, TgxShadowCastingMode CastingMode = (TgxShadowCastingMode)(0x2));
	void __fastcall RemoveCaster(Gxs::Scene::TgxBaseSceneObject* obj);
	int __fastcall IndexOfCaster(Gxs::Scene::TgxBaseSceneObject* obj);
	__property TgxShadowVolumeCaster* Items[int index] = {read=GetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxShadowVolumeCasters(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxShadowVolumeCasters() { }
	
};


enum DECLSPEC_DENUM TgxShadowVolumeOption : unsigned char { svoShowVolumes, svoCacheSilhouettes, svoScissorClips, svoWorldScissorClip, svoDesignVisible };

typedef System::Set<TgxShadowVolumeOption, TgxShadowVolumeOption::svoShowVolumes, TgxShadowVolumeOption::svoDesignVisible> TgxShadowVolumeOptions;

enum DECLSPEC_DENUM TgxShadowVolumeMode : unsigned char { svmAccurate, svmDarkening, svmOff };

class PASCALIMPLEMENTATION TgxShadowVolume : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	bool FActive;
	bool FRendering;
	TgxShadowVolumeCasters* FLights;
	TgxShadowVolumeCasters* FOccluders;
	TgxShadowVolumeCapping FCapping;
	TgxShadowVolumeOptions FOptions;
	TgxShadowVolumeMode FMode;
	Gxs::Color::TgxColor* FDarkeningColor;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetActive(const bool val);
	void __fastcall SetLights(TgxShadowVolumeCasters* const val);
	void __fastcall SetOccluders(TgxShadowVolumeCasters* const val);
	void __fastcall SetOptions(const TgxShadowVolumeOptions val);
	void __fastcall SetMode(const TgxShadowVolumeMode val);
	void __fastcall SetDarkeningColor(Gxs::Color::TgxColor* const val);
	
public:
	__fastcall virtual TgxShadowVolume(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxShadowVolume();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall FlushSilhouetteCache();
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property TgxShadowVolumeCasters* Lights = {read=FLights, write=SetLights};
	__property TgxShadowVolumeCasters* Occluders = {read=FOccluders, write=SetOccluders};
	__property TgxShadowVolumeCapping Capping = {read=FCapping, write=FCapping, default=1};
	__property TgxShadowVolumeOptions Options = {read=FOptions, write=SetOptions, default=6};
	__property TgxShadowVolumeMode Mode = {read=FMode, write=SetMode, default=0};
	__property Gxs::Color::TgxColor* DarkeningColor = {read=FDarkeningColor, write=SetDarkeningColor};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxShadowVolume(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shadowvolume */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SHADOWVOLUME)
using namespace Gxs::Shadowvolume;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ShadowVolumeHPP
