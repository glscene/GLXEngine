// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PolygonTesselation.pas' rev: 36.00 (Windows)

#ifndef GXS_PolygonTesselationHPP
#define GXS_PolygonTesselationHPP

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
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Polygontesselation
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall DoTesselate(Gxs::Vectorlists::TgxAffineVectorList* Vertexes, Gxs::Vectorfileobjects::TgxBaseMesh* Mesh, Stage::Vectorgeometry::PAffineVector normal = (Stage::Vectorgeometry::PAffineVector)(0x0), bool invertNormals = false);
}	/* namespace Polygontesselation */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_POLYGONTESSELATION)
using namespace Gxs::Polygontesselation;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PolygonTesselationHPP
