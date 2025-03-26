// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MaterialMultiProxy.pas' rev: 36.00 (Windows)

#ifndef GXS_MaterialMultiProxyHPP
#define GXS_MaterialMultiProxyHPP

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
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.Scene.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Materialmultiproxy
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMaterialMultiProxyMaster;
class DELPHICLASS TgxMaterialMultiProxyMasters;
class DELPHICLASS TgxMaterialMultiProxy;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxMaterialMultiProxyMaster : public Gxs::Persistentclasses::TgxInterfacedCollectionItem
{
	typedef Gxs::Persistentclasses::TgxInterfacedCollectionItem inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* FMasterObject;
	Gxs::Material::TgxLibMaterial* FMasterLibMaterial;
	Gxs::Material::TgxLibMaterialName FTempLibMaterialName;
	float FDistanceMin2;
	float FDistanceMax2;
	void __fastcall SetMasterLibMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMasterLibMaterialName();
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetMasterObject(Gxs::Scene::TgxBaseSceneObject* const Val);
	void __fastcall SetDistanceMin(const float Val);
	void __fastcall SetDistanceMax(const float Val);
	float __fastcall GetDistanceMin();
	float __fastcall GetDistanceMax();
	
public:
	__fastcall virtual TgxMaterialMultiProxyMaster(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxMaterialMultiProxyMaster();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TgxMaterialMultiProxy* __fastcall OwnerObject();
	void __fastcall NotifyChange();
	__property Gxs::Material::TgxLibMaterial* MasterLibMaterial = {read=FMasterLibMaterial, write=FMasterLibMaterial, stored=false};
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* MasterObject = {read=FMasterObject, write=SetMasterObject};
	__property Gxs::Material::TgxLibMaterialName MasterLibMaterialName = {read=GetMasterLibMaterialName, write=SetMasterLibMaterialName};
	__property float DistanceMin = {read=GetDistanceMin, write=SetDistanceMin};
	__property float DistanceMax = {read=GetDistanceMax, write=SetDistanceMax};
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

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxMaterialMultiProxyMasters : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxMaterialMultiProxyMaster* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TgxMaterialMultiProxyMaster* const Val);
	TgxMaterialMultiProxyMaster* __fastcall GetItems(int index);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent);
	
public:
	__fastcall TgxMaterialMultiProxyMasters(System::Classes::TPersistent* AOwner);
	HIDESBASE TgxMaterialMultiProxyMaster* __fastcall Add()/* overload */;
	HIDESBASE TgxMaterialMultiProxyMaster* __fastcall Add(Gxs::Scene::TgxBaseSceneObject* Master, float DistanceMin, float DistanceMax)/* overload */;
	HIDESBASE TgxMaterialMultiProxyMaster* __fastcall Add(Gxs::Scene::TgxBaseSceneObject* Master, Gxs::Material::TgxLibMaterial* MasterLibMaterial, float DistanceMin, float DistanceMax)/* overload */;
	__property TgxMaterialMultiProxyMaster* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall NotifyChange();
	virtual void __fastcall EndUpdate();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxMaterialMultiProxyMasters() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxMaterialMultiProxy : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	TgxMaterialMultiProxyMasters* FMasterObjects;
	bool FRendering;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	
protected:
	void __fastcall SetMasterObjects(TgxMaterialMultiProxyMasters* const Val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	Gxs::Scene::TgxBaseSceneObject* __fastcall PrimaryMaster();
	
public:
	__fastcall virtual TgxMaterialMultiProxy(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMaterialMultiProxy();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TgxMaterialMultiProxyMasters* MasterObjects = {read=FMasterObjects, write=SetMasterObjects};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
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
	__property Effects;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMaterialMultiProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Materialmultiproxy */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MATERIALMULTIPROXY)
using namespace Gxs::Materialmultiproxy;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MaterialMultiProxyHPP
