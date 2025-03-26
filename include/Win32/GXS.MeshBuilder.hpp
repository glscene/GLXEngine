// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MeshBuilder.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshBuilderHPP
#define GXS_MeshBuilderHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Meshbuilder
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall BuildCube(Gxs::Vectorfileobjects::TgxMeshObject* Mesh, const Stage::Vectorgeometry::TAffineVector &Position, const Stage::Vectorgeometry::TAffineVector &Scale);
extern DELPHI_PACKAGE void __fastcall BuildCylinder(Gxs::Vectorfileobjects::TgxMeshObject* Mesh, const Stage::Vectorgeometry::TAffineVector &Position, const Stage::Vectorgeometry::TAffineVector &Scale, int Slices);
extern DELPHI_PACKAGE void __fastcall BuildCylinder2(Gxs::Vectorfileobjects::TgxMeshObject* Mesh, const Stage::Vectorgeometry::TAffineVector &Position, const Stage::Vectorgeometry::TAffineVector &Scale, float TopRadius, float BottomRadius, float Height, int Slices);
}	/* namespace Meshbuilder */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESHBUILDER)
using namespace Gxs::Meshbuilder;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshBuilderHPP
