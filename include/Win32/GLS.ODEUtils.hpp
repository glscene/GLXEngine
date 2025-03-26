// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ODEUtils.pas' rev: 36.00 (Windows)

#ifndef GLS_ODEUtilsHPP
#define GLS_ODEUtilsHPP

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
#include <System.Classes.hpp>
#include <ODE.Import.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.Objects.hpp>
#include <GLS.VerletClothify.hpp>
#include <GLS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Odeutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall ODERToGLSceneMatrix(Stage::Vectortypes::TGLMatrix &m, const Ode::Import::TdMatrix3_As3x4 &R, const Ode::Import::TdVector3 &pos)/* overload */;
extern DELPHI_PACKAGE void __fastcall ODERToGLSceneMatrix(Stage::Vectortypes::TGLMatrix &m, Ode::Import::PdMatrix3 R, Ode::Import::PdVector3 pos)/* overload */;
extern DELPHI_PACKAGE void __fastcall ODERToGLSceneMatrix(Stage::Vectortypes::TGLMatrix &m, const Ode::Import::TdMatrix3 &R, const Ode::Import::TdVector3 &pos)/* overload */;
extern DELPHI_PACKAGE void __fastcall DrawBox(const Ode::Import::TdVector3 &Sides);
extern DELPHI_PACKAGE Ode::Import::TdMatrix3 __fastcall GLSceneMatrixToODER(const Stage::Vectortypes::TGLMatrix &m);
extern DELPHI_PACKAGE void __fastcall dsDrawBox(Ode::Import::PdVector3 pos, Ode::Import::PdMatrix3 R, const Ode::Import::TdVector3 &Sides)/* overload */;
extern DELPHI_PACKAGE void __fastcall dsDrawBox(const Ode::Import::TdVector3 &pos, const Ode::Import::TdMatrix3 &R, const Ode::Import::TdVector3 &Sides)/* overload */;
extern DELPHI_PACKAGE void __fastcall setTransform(const Ode::Import::TdVector3 &pos, const Ode::Import::TdMatrix3 &R);
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall ConvertdVector3ToVector3f(const Ode::Import::TdVector3 &R)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall ConvertdVector3ToVector3f(Ode::Import::PdVector3 R)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall ConvertdVector3ToVector4f(const Ode::Import::TdVector3 &R)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall ConvertdVector3ToVector4f(Ode::Import::PdVector3 R)/* overload */;
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall ConvertdVector3ToAffineVector(Ode::Import::PdVector3 R)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall ConvertdVector3ToAffineVector(const Ode::Import::TdVector3 &R)/* overload */;
extern DELPHI_PACKAGE Ode::Import::TdVector3 __fastcall ConvertVector3fTodVector3(const Stage::Vectortypes::TVector3f &R);
extern DELPHI_PACKAGE Ode::Import::PdVector3 __fastcall ConvertVector3fToPdVector3(const Stage::Vectortypes::TVector3f &R);
extern DELPHI_PACKAGE Ode::Import::TdVector3 __fastcall ConvertVector4fTodVector3(const Stage::Vectortypes::TVector4f &R);
extern DELPHI_PACKAGE Ode::Import::PdVector3 __fastcall ConvertVector4fToPdVector3(const Stage::Vectortypes::TVector4f &R);
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall GetBodyPositionAsAffineVector(Ode::Import::PdxBody Body);
extern DELPHI_PACKAGE void __fastcall PositionSceneObjectForGeom(Ode::Import::PdxGeom Geom);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall GLMatrixFromGeom(Ode::Import::PdxGeom Geom);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall GLDirectionFromGeom(Ode::Import::PdxGeom Geom);
extern DELPHI_PACKAGE void __fastcall PositionSceneObject(Gls::Scene::TGLBaseSceneObject* GLBaseSceneObject, Ode::Import::PdxGeom Geom);
extern DELPHI_PACKAGE void __fastcall CopyCubeSizeFromBox(Gls::Objects::TGLCube* Cube, Ode::Import::PdxGeom Geom);
extern DELPHI_PACKAGE void __fastcall CopyPosFromGeomToGL(Ode::Import::PdxGeom Geom, Gls::Scene::TGLBaseSceneObject* GLBaseSceneObject);
extern DELPHI_PACKAGE Ode::Import::PdxGeom __fastcall CreateGeomFromCube(Gls::Objects::TGLCube* Cube, Ode::Import::PdxSpace Space);
extern DELPHI_PACKAGE Ode::Import::PdxBody __fastcall CreateBodyFromCube(Ode::Import::PdxGeom &Geom, Gls::Objects::TGLCube* Cube, Ode::Import::PdxWorld World, Ode::Import::PdxSpace Space);
extern DELPHI_PACKAGE Ode::Import::PdxGeom __fastcall CreateTriMeshFromBaseMesh(Gls::Vectorfileobjects::TGLBaseMesh* GLBaseMesh, Ode::Import::PdxSpace Space, Ode::Import::PdVector3Array &Vertices, Ode::Import::PdIntegerArray &Indices);
extern DELPHI_PACKAGE void __fastcall CopyBodyFromCube(Ode::Import::PdxBody Body, Ode::Import::PdxGeom &Geom, Gls::Objects::TGLCube* Cube, Ode::Import::PdxSpace Space);
extern DELPHI_PACKAGE Ode::Import::TdReal __fastcall dBodyToBodyDistance(Ode::Import::PdxBody Body1, Ode::Import::PdxBody Body2);
extern DELPHI_PACKAGE float __fastcall dVector3Length(const Ode::Import::TdVector3 &R)/* overload */;
extern DELPHI_PACKAGE float __fastcall dVector3Length(Ode::Import::PdVector3 R)/* overload */;
extern DELPHI_PACKAGE void __fastcall RenderGeomList(Ode::Import::TGeomList* GeomList);
extern DELPHI_PACKAGE Ode::Import::PdxGeom __fastcall CreateODEPlaneFromGLPlane(Gls::Objects::TGLPlane* Plane, Ode::Import::PdxSpace Space);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall RandomColorVector(void);
}	/* namespace Odeutils */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ODEUTILS)
using namespace Gls::Odeutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ODEUtilsHPP
