// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Octree.pas' rev: 36.00 (Windows)

#ifndef GXS_OctreeHPP
#define GXS_OctreeHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Octree
{
//-- forward type declarations -----------------------------------------------
struct TgxOctreeTriangleInfo;
struct TgxOctreeNode;
class DELPHICLASS TgxOctree;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TProcInt)(int I);

typedef void __fastcall (__closure *TProcAffineAffineAffine)(const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);

struct DECLSPEC_DRECORD TgxOctreeTriangleInfo
{
public:
	int Index;
	System::StaticArray<Stage::Vectortypes::TVector3f, 3> Vertex;
};


typedef TgxOctreeTriangleInfo *PgxOctreeTriangleInfo;

typedef TgxOctreeNode *PgxOctreeNode;

struct DECLSPEC_DRECORD TgxOctreeNode
{
	
private:
	typedef System::DynamicArray<int> _TgxOctreeNode__1;
	
	
public:
	Stage::Vectorgeometry::TAffineFltVector MinExtent;
	Stage::Vectorgeometry::TAffineFltVector MaxExtent;
	Gxs::Context::TgxListHandle* ListHandle;
	bool WillDraw;
	_TgxOctreeNode__1 TriArray;
	System::StaticArray<PgxOctreeNode, 8> ChildArray;
};


class PASCALIMPLEMENTATION TgxOctree : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<PgxOctreeNode> _TgxOctree__1;
	
	
private:
	int Intersections;
	
protected:
	float __fastcall GetMidPoint(float Min, float Max);
	bool __fastcall PointInNode(const Stage::Vectorgeometry::TAffineFltVector &Min, const Stage::Vectorgeometry::TAffineFltVector &Max, const Stage::Vectorgeometry::TAffineFltVector &APoint);
	bool __fastcall TriIntersectNode(const Stage::Vectorgeometry::TAffineFltVector &MinExtent, const Stage::Vectorgeometry::TAffineFltVector &MaxExtent, const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);
	bool __fastcall SphereInNode(const Stage::Vectorgeometry::TAffineVector &MinExtent, const Stage::Vectorgeometry::TAffineVector &MaxExtent, const Stage::Vectortypes::TVector4f &C, float Radius);
	void __fastcall WalkTriToLeafx(PgxOctreeNode Onode, const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);
	void __fastcall WalkPointToLeafx(PgxOctreeNode ONode, const Stage::Vectorgeometry::TAffineVector &P);
	void __fastcall WalkSphereToLeafx(PgxOctreeNode Onode, const Stage::Vectortypes::TVector4f &P, float Radius);
	void __fastcall WalkRayToLeafx(PgxOctreeNode Onode, const Stage::Vectortypes::TVector4f &P, const Stage::Vectortypes::TVector4f &V);
	Stage::Vectorgeometry::TAffineFltVector __fastcall GetExtent(const System::Byte *Flags, const System::NativeInt Flags_High, PgxOctreeNode ParentNode);
	void __fastcall Refine(PgxOctreeNode ParentNode, int Level);
	void __fastcall WalkPointToLeaf(PgxOctreeNode ONode, const Stage::Vectorgeometry::TAffineVector &P);
	void __fastcall WalkTriToLeaf(PgxOctreeNode Onode, const Stage::Vectorgeometry::TAffineVector &V1, const Stage::Vectorgeometry::TAffineVector &V2, const Stage::Vectorgeometry::TAffineVector &V3);
	void __fastcall WalkRayToLeaf(PgxOctreeNode Onode, const Stage::Vectortypes::TVector4f &P, const Stage::Vectortypes::TVector4f &V);
	void __fastcall ConvertR4(PgxOctreeNode ONode, const Stage::Vectorgeometry::TAffineFltVector &Scale);
	void __fastcall CreateTree(int Depth);
	void __fastcall CutMesh();
	
public:
	Stage::Vectorgeometry::TAffineFltVector WorldMinExtent;
	Stage::Vectorgeometry::TAffineFltVector WorldMaxExtent;
	PgxOctreeNode RootNode;
	int MaxOlevel;
	int NodeCount;
	int TriCountMesh;
	int TriCountOctree;
	int MeshCount;
	_TgxOctree__1 ResultArray;
	Gxs::Vectorlists::TgxAffineVectorList* TriangleFiler;
	void __fastcall WalkSphereToLeaf(PgxOctreeNode Onode, const Stage::Vectortypes::TVector4f &P, float Radius);
	void __fastcall InitializeTree(const Stage::Vectorgeometry::TAffineVector &AWorldMinExtent, const Stage::Vectorgeometry::TAffineVector &AWorldMaxExtent, Gxs::Vectorlists::TgxAffineVectorList* const ATriangles, const int ATreeDepth);
	void __fastcall DisposeTree();
	__fastcall virtual ~TgxOctree();
	bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &RayStart, const Stage::Vectortypes::TVector4f &RayVector, Stage::Vectortypes::PVector4f IntersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f IntersectNormal = (Stage::Vectortypes::PVector4f)(0x0), PgxOctreeTriangleInfo TriangleInfo = (PgxOctreeTriangleInfo)(0x0));
	bool __fastcall SphereSweepIntersect(const Stage::Vectortypes::TVector4f &RayStart, const Stage::Vectortypes::TVector4f &RayVector, const float Velocity, const float Radius, Stage::Vectortypes::PVector4f IntersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f IntersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	bool __fastcall TriangleIntersect(const Stage::Vectorgeometry::TAffineVector &V1, const Stage::Vectorgeometry::TAffineVector &V2, const Stage::Vectorgeometry::TAffineVector &V3);
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall GetTrianglesFromNodesIntersectingAABB(const Gxs::Geometrybb::TAABB &ObjAABB);
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall GetTrianglesFromNodesIntersectingCube(const Gxs::Geometrybb::TAABB &ObjAABB, const Stage::Vectortypes::TMatrix4f &ObjToSelf, const Stage::Vectortypes::TMatrix4f &SelfToObj);
	bool __fastcall AABBIntersect(const Gxs::Geometrybb::TAABB &AABB, const Stage::Vectortypes::TMatrix4f &M1to2, const Stage::Vectortypes::TMatrix4f &M2to1, Gxs::Vectorlists::TgxAffineVectorList* Triangles = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TgxOctree() : System::TObject() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Octree */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_OCTREE)
using namespace Gxs::Octree;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_OctreeHPP
