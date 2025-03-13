// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MeshOptimizer.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshOptimizerHPP
#define GXS_MeshOptimizerHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.MeshUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Meshoptimizer
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMeshOptimizerOption : unsigned char { mooStandardize, mooVertexCache, mooSortByMaterials, mooMergeObjects };

typedef System::Set<TMeshOptimizerOption, TMeshOptimizerOption::mooStandardize, TMeshOptimizerOption::mooMergeObjects> TMeshOptimizerOptions;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TMeshOptimizerOptions vDefaultMeshOptimizerOptions;
extern DELPHI_PACKAGE void __fastcall OptimizeMesh(Gxs::Vectorfileobjects::TgxMeshObjectList* aList)/* overload */;
extern DELPHI_PACKAGE void __fastcall OptimizeMesh(Gxs::Vectorfileobjects::TgxMeshObjectList* aList, TMeshOptimizerOptions options)/* overload */;
extern DELPHI_PACKAGE void __fastcall OptimizeMesh(Gxs::Vectorfileobjects::TgxMeshObject* aMeshObject)/* overload */;
extern DELPHI_PACKAGE void __fastcall OptimizeMesh(Gxs::Vectorfileobjects::TgxMeshObject* aMeshObject, TMeshOptimizerOptions options)/* overload */;
extern DELPHI_PACKAGE void __fastcall FacesSmooth(Gxs::Vectorfileobjects::TgxMeshObject* aMeshObj, float aWeldDistance = 1.000000E-07f, float aThreshold = 3.500000E+01f, bool InvertNormals = false);
}	/* namespace Meshoptimizer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESHOPTIMIZER)
using namespace Gxs::Meshoptimizer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshOptimizerHPP
