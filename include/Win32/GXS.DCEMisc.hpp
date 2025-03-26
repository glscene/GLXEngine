// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.DCEMisc.pas' rev: 36.00 (Windows)

#ifndef GXS_DCEMiscHPP
#define GXS_DCEMiscHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.EllipseCollision.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Scene.hpp>
#include <GXS.TerrainRenderer.hpp>
#include <GXS.ProxyObjects.hpp>
#include <GXS.MultiProxy.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Dcemisc
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<Stage::Vectortypes::TVector3f, 36> DCEBox;
extern DELPHI_PACKAGE void __fastcall ECSetCollisionRange(Gxs::Ellipsecollision::TECMovePack &MovePack);
extern DELPHI_PACKAGE void __fastcall ECResetColliders(Gxs::Ellipsecollision::TECMovePack &MovePack);
extern DELPHI_PACKAGE void __fastcall ECAddFreeForm(Gxs::Ellipsecollision::TECMovePack &MovePack, Gxs::Scene::TgxBaseSceneObject* FreeForm, bool Solid, int ObjectID);
extern DELPHI_PACKAGE void __fastcall ECAddBox(Gxs::Ellipsecollision::TECMovePack &MovePack, Gxs::Scene::TgxBaseSceneObject* BoxObj, const Stage::Vectorgeometry::TAffineVector &BoxSize, bool Solid, int ObjectID);
extern DELPHI_PACKAGE void __fastcall ECAddTerrain(Gxs::Ellipsecollision::TECMovePack &MovePack, Gxs::Terrainrenderer::TgxTerrainRenderer* TerrainRenderer, float Resolution, bool Solid, int ObjectID);
extern DELPHI_PACKAGE void __fastcall ECAddEllipsoid(Gxs::Ellipsecollision::TECMovePack &MovePack, const Stage::Vectorgeometry::TAffineVector &ePos, const Stage::Vectorgeometry::TAffineVector &eRadius, bool Solid, int ObjectID);
}	/* namespace Dcemisc */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_DCEMISC)
using namespace Gxs::Dcemisc;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_DCEMiscHPP
