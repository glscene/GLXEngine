// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SpatialPartitioning.pas' rev: 36.00 (Windows)

#ifndef GXS_SpatialPartitioningHPP
#define GXS_SpatialPartitioningHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.SpacePartition.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.PersistentClasses.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Spatialpartitioning
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSceneObj;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSceneObj : public Gxs::Spacepartition::TSpacePartitionLeaf
{
	typedef Gxs::Spacepartition::TSpacePartitionLeaf inherited;
	
public:
	Gxs::Scene::TgxBaseSceneObject* Obj;
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__fastcall TgxSceneObj(Gxs::Spacepartition::TSectoredSpacePartition* Owner, Gxs::Scene::TgxBaseSceneObject* aObj);
	__fastcall virtual ~TgxSceneObj();
public:
	/* TSpacePartitionLeaf.CreateOwned */ inline __fastcall TgxSceneObj(Gxs::Spacepartition::TBaseSpacePartition* SpacePartition) : Gxs::Spacepartition::TSpacePartitionLeaf(SpacePartition) { }
	
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxSceneObj() : Gxs::Spacepartition::TSpacePartitionLeaf() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSceneObj(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Spacepartition::TSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall RenderAABB(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const Gxs::Geometrybb::TAABB &AABB)/* overload */;
extern DELPHI_PACKAGE void __fastcall RenderAABB(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const Gxs::Geometrybb::TAABB &AABB, float w, float r, float g, float b)/* overload */;
extern DELPHI_PACKAGE void __fastcall RenderSpatialPartitioning(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Spacepartition::TSectoredSpacePartition* const Space);
extern DELPHI_PACKAGE Gxs::Spacepartition::TExtendedFrustum __fastcall ExtendedFrustumMakeFromSceneViewer(const Stage::Vectorgeometry::TFrustum &AFrustum, Gxs::Sceneviewer::TgxSceneViewer* const AGLXceneViewer)/* overload */;
extern DELPHI_PACKAGE Gxs::Spacepartition::TExtendedFrustum __fastcall ExtendedFrustumMakeFromSceneViewer(const Stage::Vectorgeometry::TFrustum &AFrustum, const int vWidth, const int vHeight, Gxs::Scene::TgxCamera* AVKCamera)/* overload */;
}	/* namespace Spatialpartitioning */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SPATIALPARTITIONING)
using namespace Gxs::Spatialpartitioning;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SpatialPartitioningHPP
