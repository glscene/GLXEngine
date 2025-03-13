// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Portal.pas' rev: 36.00 (Windows)

#ifndef GXS_PortalHPP
#define GXS_PortalHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Material.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Portal
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxPortalMeshObjectList;
class DELPHICLASS TgxSectorMeshObject;
class DELPHICLASS TFGPolygon;
class DELPHICLASS TFGPortalPolygon;
class DELPHICLASS TgxPortal;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPortalMeshObjectList : public Gxs::Vectorfileobjects::TgxMeshObjectList
{
	typedef Gxs::Vectorfileobjects::TgxMeshObjectList inherited;
	
public:
	__fastcall TgxPortalMeshObjectList(Gxs::Vectorfileobjects::TgxBaseMesh* AOwner);
	__fastcall virtual ~TgxPortalMeshObjectList();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxPortalMeshObjectList() : Gxs::Vectorfileobjects::TgxMeshObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxPortalMeshObjectList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxMeshObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSectorMeshObject : public Gxs::Vectorfileobjects::TgxMorphableMeshObject
{
	typedef Gxs::Vectorfileobjects::TgxMorphableMeshObject inherited;
	
private:
	bool FRenderDone;
	
public:
	__fastcall TgxSectorMeshObject(Gxs::Vectorfileobjects::TgxMeshObjectList* AOwner);
	__fastcall virtual ~TgxSectorMeshObject();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall Prepare();
	__property bool RenderDone = {read=FRenderDone, write=FRenderDone, nodefault};
public:
	/* TgxMorphableMeshObject.Create */ inline __fastcall virtual TgxSectorMeshObject() : Gxs::Vectorfileobjects::TgxMorphableMeshObject() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSectorMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxMorphableMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGPolygon : public Gxs::Vectorfileobjects::TFGVertexNormalTexIndexList
{
	typedef Gxs::Vectorfileobjects::TFGVertexNormalTexIndexList inherited;
	
public:
	__fastcall virtual TFGPolygon(Gxs::Vectorfileobjects::TgxFaceGroups* AOwner);
	__fastcall virtual ~TFGPolygon();
	virtual void __fastcall Prepare();
public:
	/* TFGVertexNormalTexIndexList.Create */ inline __fastcall virtual TFGPolygon() : Gxs::Vectorfileobjects::TFGVertexNormalTexIndexList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TFGPolygon(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TFGVertexNormalTexIndexList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGPortalPolygon : public TFGPolygon
{
	typedef TFGPolygon inherited;
	
private:
	int FDestinationSectorIndex;
	Stage::Vectorgeometry::TAffineVector FCenter;
	Stage::Vectorgeometry::TAffineVector FNormal;
	float FRadius;
	
public:
	__fastcall virtual TFGPortalPolygon(Gxs::Vectorfileobjects::TgxFaceGroups* AOwner);
	__fastcall virtual ~TFGPortalPolygon();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall Prepare();
	__property int DestinationSectorIndex = {read=FDestinationSectorIndex, write=FDestinationSectorIndex, nodefault};
public:
	/* TFGVertexNormalTexIndexList.Create */ inline __fastcall virtual TFGPortalPolygon() : TFGPolygon() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TFGPortalPolygon(Gxs::Persistentclasses::TgxVirtualReader* reader) : TFGPolygon(reader) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxPortal : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	__fastcall virtual TgxPortal(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPortal();
	
__published:
	__property MaterialLibrary;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPortal(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Portal */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PORTAL)
using namespace Gxs::Portal;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PortalHPP
