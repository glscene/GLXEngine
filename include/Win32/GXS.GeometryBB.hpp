// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.GeometryBB.pas' rev: 36.00 (Windows)

#ifndef GXS_GeometryBBHPP
#define GXS_GeometryBBHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Geometrybb
{
//-- forward type declarations -----------------------------------------------
struct THmgBoundingBox;
struct TAABB;
struct TBSphere;
struct TGClipRect;
//-- type declarations -------------------------------------------------------
typedef THmgBoundingBox *PHmgBoundingBox;

struct DECLSPEC_DRECORD THmgBoundingBox
{
public:
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> BBox;
};


struct DECLSPEC_DRECORD TAABB
{
public:
	Stage::Vectorgeometry::TAffineVector Min;
	Stage::Vectorgeometry::TAffineVector Max;
};


typedef TAABB *PAABB;

struct DECLSPEC_DRECORD TBSphere
{
public:
	Stage::Vectorgeometry::TAffineVector Center;
	float Radius;
};


struct DECLSPEC_DRECORD TGClipRect
{
public:
	float Left;
	float Top;
	float Right;
	float Bottom;
};


enum DECLSPEC_DENUM TSpaceContains : unsigned char { ScNoOverlap, ScContainsFully, ScContainsPartially };

typedef System::StaticArray<Stage::Vectortypes::TVector3f, 8> TAABBCorners;

typedef System::StaticArray<int, 4> TPlanIndices;

typedef System::StaticArray<System::StaticArray<int, 4>, 6> TPlanBB;

typedef System::StaticArray<int, 6> TDirPlan;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE THmgBoundingBox NullBoundingBox;
extern DELPHI_PACKAGE TPlanIndices CBBFront;
extern DELPHI_PACKAGE TPlanIndices CBBBack;
extern DELPHI_PACKAGE TPlanIndices CBBLeft;
extern DELPHI_PACKAGE TPlanIndices CBBRight;
extern DELPHI_PACKAGE TPlanIndices CBBTop;
extern DELPHI_PACKAGE TPlanIndices CBBBottom;
extern DELPHI_PACKAGE TPlanBB CBBPlans;
extern DELPHI_PACKAGE TDirPlan CDirPlan;
extern DELPHI_PACKAGE bool __fastcall BoundingBoxesAreEqual(const THmgBoundingBox &ABoundingBox1, const THmgBoundingBox &ABoundingBox2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall BoundingBoxesAreEqual(const PHmgBoundingBox ABoundingBox1, const PHmgBoundingBox ABoundingBox2)/* overload */;
extern DELPHI_PACKAGE THmgBoundingBox __fastcall AddBB(THmgBoundingBox &C1, const THmgBoundingBox &C2);
extern DELPHI_PACKAGE void __fastcall AddAABB(TAABB &Aabb, const TAABB &Aabb1);
extern DELPHI_PACKAGE void __fastcall SetBB(THmgBoundingBox &C, const Stage::Vectortypes::TGLVector &V);
extern DELPHI_PACKAGE void __fastcall SetAABB(TAABB &Bb, const Stage::Vectortypes::TGLVector &V);
extern DELPHI_PACKAGE void __fastcall BBTransform(THmgBoundingBox &C, const Stage::Vectortypes::TGLMatrix &M);
extern DELPHI_PACKAGE void __fastcall AABBTransform(TAABB &Bb, const Stage::Vectortypes::TGLMatrix &M);
extern DELPHI_PACKAGE void __fastcall AABBScale(TAABB &Bb, const Stage::Vectorgeometry::TAffineVector &V);
extern DELPHI_PACKAGE float __fastcall BBMinX(const THmgBoundingBox &C);
extern DELPHI_PACKAGE float __fastcall BBMaxX(const THmgBoundingBox &C);
extern DELPHI_PACKAGE float __fastcall BBMinY(const THmgBoundingBox &C);
extern DELPHI_PACKAGE float __fastcall BBMaxY(const THmgBoundingBox &C);
extern DELPHI_PACKAGE float __fastcall BBMinZ(const THmgBoundingBox &C);
extern DELPHI_PACKAGE float __fastcall BBMaxZ(const THmgBoundingBox &C);
extern DELPHI_PACKAGE void __fastcall AABBInclude(TAABB &Bb, const Stage::Vectorgeometry::TAffineVector &P);
extern DELPHI_PACKAGE void __fastcall AABBFromSweep(TAABB &SweepAABB, const Stage::Vectortypes::TGLVector &Start, const Stage::Vectortypes::TGLVector &Dest, const float Radius);
extern DELPHI_PACKAGE TAABB __fastcall AABBIntersection(const TAABB &Aabb1, const TAABB &Aabb2);
extern DELPHI_PACKAGE TAABB __fastcall BBToAABB(const THmgBoundingBox &ABB);
extern DELPHI_PACKAGE THmgBoundingBox __fastcall AABBToBB(const TAABB &AnAABB)/* overload */;
extern DELPHI_PACKAGE THmgBoundingBox __fastcall AABBToBB(const TAABB &AnAABB, const Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetAABB(TAABB &Aabb, const Stage::Vectorgeometry::TAffineVector &Delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetAABB(TAABB &Aabb, const Stage::Vectortypes::TGLVector &Delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetBB(THmgBoundingBox &Bb, const Stage::Vectorgeometry::TAffineVector &Delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetBB(THmgBoundingBox &Bb, const Stage::Vectortypes::TGLVector &Delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetBBPoint(THmgBoundingBox &Bb, const Stage::Vectortypes::TGLVector &Delta)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IntersectAABBs(const TAABB &Aabb1, const TAABB &Aabb2, const Stage::Vectortypes::TGLMatrix &M1To2, const Stage::Vectortypes::TGLMatrix &M2To1)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IntersectAABBsAbsoluteXY(const TAABB &Aabb1, const TAABB &Aabb2);
extern DELPHI_PACKAGE bool __fastcall IntersectAABBsAbsoluteXZ(const TAABB &Aabb1, const TAABB &Aabb2);
extern DELPHI_PACKAGE bool __fastcall IntersectAABBsAbsolute(const TAABB &Aabb1, const TAABB &Aabb2);
extern DELPHI_PACKAGE bool __fastcall AABBFitsInAABBAbsolute(const TAABB &Aabb1, const TAABB &Aabb2);
extern DELPHI_PACKAGE bool __fastcall PointInAABB(const Stage::Vectorgeometry::TAffineVector &P, const TAABB &Aabb)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PointInAABB(const Stage::Vectortypes::TGLVector &P, const TAABB &Aabb)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PlaneIntersectAABB(const Stage::Vectorgeometry::TAffineVector &Normal, float D, const TAABB &Aabb);
extern DELPHI_PACKAGE Gxs::Vectorlists::TgxAffineVectorList* __fastcall PlaneAABBIntersection(const Stage::Vectorgeometry::THmgPlane &plane, const TAABB &AABB);
extern DELPHI_PACKAGE bool __fastcall TriangleIntersectAABB(const TAABB &Aabb, const Stage::Vectorgeometry::TAffineVector &V1, const Stage::Vectorgeometry::TAffineVector &V2, const Stage::Vectorgeometry::TAffineVector &V3);
extern DELPHI_PACKAGE void __fastcall ExtractAABBCorners(const TAABB &AABB, TAABBCorners &AABBCorners);
extern DELPHI_PACKAGE void __fastcall AABBToBSphere(const TAABB &AABB, TBSphere &BSphere);
extern DELPHI_PACKAGE void __fastcall BSphereToAABB(const TBSphere &BSphere, TAABB &AABB)/* overload */;
extern DELPHI_PACKAGE TAABB __fastcall BSphereToAABB(const Stage::Vectorgeometry::TAffineVector &Center, float Radius)/* overload */;
extern DELPHI_PACKAGE TAABB __fastcall BSphereToAABB(const Stage::Vectortypes::TGLVector &Center, float Radius)/* overload */;
extern DELPHI_PACKAGE TSpaceContains __fastcall AABBContainsAABB(const TAABB &MainAABB, const TAABB &TestAABB);
extern DELPHI_PACKAGE TSpaceContains __fastcall AABBContainsBSphere(const TAABB &MainAABB, const TBSphere &TestBSphere);
extern DELPHI_PACKAGE TSpaceContains __fastcall PlaneContainsBSphere(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal, const TBSphere &TestBSphere);
extern DELPHI_PACKAGE TSpaceContains __fastcall FrustumContainsBSphere(const Stage::Vectorgeometry::TFrustum &Frustum, const TBSphere &TestBSphere);
extern DELPHI_PACKAGE TSpaceContains __fastcall FrustumContainsAABB(const Stage::Vectorgeometry::TFrustum &Frustum, const TAABB &TestAABB);
extern DELPHI_PACKAGE TSpaceContains __fastcall BSphereContainsAABB(const TBSphere &MainBSphere, const TAABB &TestAABB);
extern DELPHI_PACKAGE TSpaceContains __fastcall BSphereContainsBSphere(const TBSphere &MainBSphere, const TBSphere &TestBSphere);
extern DELPHI_PACKAGE bool __fastcall BSphereIntersectsBSphere(const TBSphere &MainBSphere, const TBSphere &TestBSphere);
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall ClipToAABB(const Stage::Vectorgeometry::TAffineVector &V, const TAABB &AABB);
extern DELPHI_PACKAGE void __fastcall IncludeInClipRect(TGClipRect &ClipRect, float X, float Y);
extern DELPHI_PACKAGE TGClipRect __fastcall AABBToClipRect(const TAABB &Aabb, const Stage::Vectortypes::TGLMatrix &ModelViewProjection, int ViewportSizeX, int ViewportSizeY);
extern DELPHI_PACKAGE bool __fastcall RayCastAABBIntersect(const Stage::Vectortypes::TGLVector &RayOrigin, const Stage::Vectortypes::TGLVector &RayDirection, const TAABB &Aabb, /* out */ float &TNear, /* out */ float &TFar)/* overload */;
extern DELPHI_PACKAGE bool __fastcall RayCastAABBIntersect(const Stage::Vectortypes::TGLVector &RayOrigin, const Stage::Vectortypes::TGLVector &RayDirection, const TAABB &Aabb, Stage::Vectortypes::PGLVector IntersectPoint = (Stage::Vectortypes::PGLVector)(0x0))/* overload */;
}	/* namespace Geometrybb */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GEOMETRYBB)
using namespace Gxs::Geometrybb;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GeometryBBHPP
