// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MultiProxy.pas' rev: 36.00 (Windows)

#ifndef GXS_MultiProxyHPP
#define GXS_MultiProxyHPP

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
#include <GXS.Context.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Multiproxy
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMultiProxyMaster;
class DELPHICLASS TgxMultiProxyMasters;
class DELPHICLASS TgxMultiProxy;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxMultiProxyMaster : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* FMasterObject;
	float FDistanceMin;
	float FDistanceMin2;
	float FDistanceMax;
	float FDistanceMax2;
	bool FVisible;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetMasterObject(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetDistanceMin(const float val);
	void __fastcall SetDistanceMax(const float val);
	void __fastcall SetVisible(const bool val);
	
public:
	__fastcall virtual TgxMultiProxyMaster(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxMultiProxyMaster();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TgxMultiProxy* __fastcall OwnerObject();
	void __fastcall NotifyChange();
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* MasterObject = {read=FMasterObject, write=SetMasterObject};
	__property float DistanceMin = {read=FDistanceMin, write=SetDistanceMin};
	__property float DistanceMax = {read=FDistanceMax, write=SetDistanceMax};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxMultiProxyMasters : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxMultiProxyMaster* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TgxMultiProxyMaster* const val);
	TgxMultiProxyMaster* __fastcall GetItems(int index);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TgxMultiProxyMasters(System::Classes::TPersistent* AOwner);
	HIDESBASE TgxMultiProxyMaster* __fastcall Add()/* overload */;
	HIDESBASE TgxMultiProxyMaster* __fastcall Add(Gxs::Scene::TgxBaseSceneObject* master, float DistanceMin, float DistanceMax)/* overload */;
	__property TgxMultiProxyMaster* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall Notification(System::Classes::TComponent* AComponent);
	void __fastcall NotifyChange();
	virtual void __fastcall EndUpdate();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxMultiProxyMasters() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxMultiProxy : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxMultiProxyMasters* FMasterObjects;
	bool FRendering;
	
protected:
	void __fastcall SetMasterObjects(TgxMultiProxyMasters* const val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	Gxs::Scene::TgxBaseSceneObject* __fastcall PrimaryMaster();
	
public:
	__fastcall virtual TgxMultiProxy(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMultiProxy();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TgxMultiProxyMasters* MasterObjects = {read=FMasterObjects, write=SetMasterObjects};
	__property ObjectsSorting = {default=0};
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
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMultiProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Multiproxy */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MULTIPROXY)
using namespace Gxs::Multiproxy;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MultiProxyHPP
