// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FPSMovement.pas' rev: 36.00 (Windows)

#ifndef GXS_FPSMovementHPP
#define GXS_FPSMovementHPP

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
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Manager.hpp>
#include <GXS.Context.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.Navigator.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.XCollection.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fpsmovement
{
//-- forward type declarations -----------------------------------------------
struct TContactPoint;
class DELPHICLASS TCollisionState;
class DELPHICLASS TCollisionStates;
class DELPHICLASS TgxMapCollectionItem;
class DELPHICLASS TgxMapCollection;
class DELPHICLASS TgxFPSMovementManager;
class DELPHICLASS TgxBFPSMovement;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TContactPoint
{
public:
	Stage::Vectortypes::TVector4f intPoint;
	Stage::Vectortypes::TVector4f intNormal;
};


class PASCALIMPLEMENTATION TCollisionState : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Stage::Vectortypes::TVector4f Position;
	TContactPoint Contact;
	__int64 Time;
public:
	/* TObject.Create */ inline __fastcall TCollisionState() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCollisionState() { }
	
};


class PASCALIMPLEMENTATION TCollisionStates : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TCollisionStates() { }
	
public:
	/* TObject.Create */ inline __fastcall TCollisionStates() : System::Classes::TList() { }
	
};


class PASCALIMPLEMENTATION TgxMapCollectionItem : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	Gxs::Vectorfileobjects::TgxFreeForm* FMap;
	System::UnicodeString FMapName;
	int FCollisionGroup;
	void __fastcall setMap(Gxs::Vectorfileobjects::TgxFreeForm* value);
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TgxMapCollectionItem(Gxs::Xcollection::TXCollection* aOwner);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	
__published:
	__property Gxs::Vectorfileobjects::TgxFreeForm* Map = {read=FMap, write=setMap};
	__property int CollisionGroup = {read=FCollisionGroup, write=FCollisionGroup, nodefault};
public:
	/* TXCollectionItem.Destroy */ inline __fastcall virtual ~TgxMapCollectionItem() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxMapCollectionItemClass);

class PASCALIMPLEMENTATION TgxMapCollection : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	TgxMapCollectionItem* __fastcall addMap(Gxs::Vectorfileobjects::TgxFreeForm* Map, int CollisionGroup = 0x0);
	TgxMapCollectionItem* __fastcall findMap(Gxs::Vectorfileobjects::TgxFreeForm* mapFreeForm);
public:
	/* TXCollection.Create */ inline __fastcall virtual TgxMapCollection(System::Classes::TPersistent* aOwner) : Gxs::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxMapCollection() { }
	
};


class PASCALIMPLEMENTATION TgxFPSMovementManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Gxs::Navigator::TgxNavigator* FNavigator;
	int FDisplayTime;
	float FMovementScale;
	TgxMapCollection* FMaps;
	Gxs::Scene::TgxScene* FScene;
	void __fastcall SetNavigator(Gxs::Navigator::TgxNavigator* value);
	void __fastcall setScene(Gxs::Scene::TgxScene* value);
	void __fastcall DrawArrows(const Stage::Vectortypes::TVector4f &intPoint, const Stage::Vectortypes::TVector4f &intNormal, const Stage::Vectortypes::TVector4f &Ray, Gxs::Geomobjects::TgxArrowLine* Arrow1, Gxs::Geomobjects::TgxArrowLine* Arrow2);
	
protected:
	virtual void __fastcall Loaded();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteMaps(System::Classes::TStream* stream);
	void __fastcall ReadMaps(System::Classes::TStream* stream);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxFPSMovementManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxFPSMovementManager();
	bool __fastcall SphereSweepAndSlide(Gxs::Vectorfileobjects::TgxFreeForm* freeform, TgxBFPSMovement* behaviour, const Stage::Vectortypes::TVector4f &SphereStart, Stage::Vectortypes::TVector4f &Velocity, Stage::Vectortypes::TVector4f &newPosition, float sphereRadius)/* overload */;
	void __fastcall SphereSweepAndSlide(TgxBFPSMovement* behaviour, const Stage::Vectortypes::TVector4f &SphereStart, Stage::Vectortypes::TVector4f &Velocity, Stage::Vectortypes::TVector4f &newPosition, float sphereRadius)/* overload */;
	
__published:
	__property TgxMapCollection* Maps = {read=FMaps, write=FMaps};
	__property Gxs::Navigator::TgxNavigator* Navigator = {read=FNavigator, write=SetNavigator};
	__property Gxs::Scene::TgxScene* Scene = {read=FScene, write=setScene};
	__property int DisplayTime = {read=FDisplayTime, write=FDisplayTime, nodefault};
	__property float MovementScale = {read=FMovementScale, write=FMovementScale};
};


class PASCALIMPLEMENTATION TgxBFPSMovement : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxFPSMovementManager* FManager;
	TCollisionStates* CollisionStates;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine1;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine2;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine3;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine4;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine5;
	Gxs::Geomobjects::TgxArrowLine* ArrowLine6;
	Gxs::Scene::TgxDirectOpenGL* dirGl;
	__int64 tickCount;
	Stage::Vectortypes::TVector4f oldPosition;
	bool FGravityEnabled;
	float FSphereRadius;
	bool FShowArrows;
	int FCollisionGroup;
	System::UnicodeString FManagerName;
	void __fastcall setShowArrows(bool value);
	void __fastcall RenderArrowLines(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	Stage::Vectortypes::TVector4f Velocity;
	__fastcall virtual TgxBFPSMovement(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBFPSMovement();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	void __fastcall TurnHorizontal(float Angle);
	void __fastcall TurnVertical(float Angle);
	void __fastcall MoveForward(float Distance);
	void __fastcall StrafeHorizontal(float Distance);
	void __fastcall StrafeVertical(float Distance);
	void __fastcall Straighten();
	
__published:
	__property TgxFPSMovementManager* Manager = {read=FManager, write=FManager};
	__property float sphereRadius = {read=FSphereRadius, write=FSphereRadius};
	__property bool ShowArrows = {read=FShowArrows, write=setShowArrows, nodefault};
	__property int CollisionGroup = {read=FCollisionGroup, write=FCollisionGroup, nodefault};
	__property bool GravityEnabled = {read=FGravityEnabled, write=FGravityEnabled, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxBFPSMovement* __fastcall GetFPSMovement(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBFPSMovement* __fastcall GetFPSMovement(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
extern DELPHI_PACKAGE TgxBFPSMovement* __fastcall GetOrCreateFPSMovement(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBFPSMovement* __fastcall GetOrCreateFPSMovement(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Fpsmovement */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FPSMOVEMENT)
using namespace Gxs::Fpsmovement;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FPSMovementHPP
