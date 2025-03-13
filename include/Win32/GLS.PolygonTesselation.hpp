// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.PolygonTesselation.pas' rev: 36.00 (Windows)

#ifndef GLS_PolygonTesselationHPP
#define GLS_PolygonTesselationHPP

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
#include <System.SysUtils.hpp>
#include <GLS.OpenGLAdapter.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Polygontesselation
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall DoTesselate(Gls::Vectorlists::TGLAffineVectorList* Vertexes, Gls::Vectorfileobjects::TGLBaseMesh* Mesh, Stage::Vectorgeometry::PAffineVector normal = (Stage::Vectorgeometry::PAffineVector)(0x0), bool invertNormals = false);
}	/* namespace Polygontesselation */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_POLYGONTESSELATION)
using namespace Gls::Polygontesselation;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PolygonTesselationHPP
