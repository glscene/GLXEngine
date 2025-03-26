// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Octree.pas' rev: 36.00 (Windows)

#ifndef GLS_OctreeHPP
#define GLS_OctreeHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Math.hpp>
#include <System.Classes.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.GeometryBB.hpp>
#include <GLS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Octree
{
//-- forward type declarations -----------------------------------------------
struct TOctreeTriangleInfo;
struct TGLOctreeNode;
class DELPHICLASS TGLOctree;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TProcInt)(int I);

typedef void __fastcall (__closure *TProcAffineAffineAffine)(const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);

typedef TOctreeTriangleInfo *POctreeTriangleInfo;

struct DECLSPEC_DRECORD TOctreeTriangleInfo
{
public:
	int Index;
	System::StaticArray<Stage::Vectortypes::TVector3f, 3> Vertex;
};


typedef TGLOctreeNode *PGLOctreeNode;

struct DECLSPEC_DRECORD TGLOctreeNode
{
	
private:
	typedef System::DynamicArray<int> _TGLOctreeNode__1;
	
	
public:
	Stage::Vectorgeometry::TAffineFltVector MinExtent;
	Stage::Vectorgeometry::TAffineFltVector MaxExtent;
	Gls::Context::TGLListHandle* ListHandle;
	bool WillDraw;
	_TGLOctreeNode__1 TriArray;
	System::StaticArray<PGLOctreeNode, 8> ChildArray;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLOctree : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<PGLOctreeNode> _TGLOctree__1;
	
	
private:
	int Intersections;
	
protected:
	float __fastcall GetMidPoint(float Min, float Max);
	bool __fastcall PointInNode(const Stage::Vectorgeometry::TAffineFltVector &Min, const Stage::Vectorgeometry::TAffineFltVector &Max, const Stage::Vectorgeometry::TAffineFltVector &APoint);
	bool __fastcall TriIntersectNode(const Stage::Vectorgeometry::TAffineFltVector &MinExtent, const Stage::Vectorgeometry::TAffineFltVector &MaxExtent, const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);
	bool __fastcall SphereInNode(const Stage::Vectorgeometry::TAffineVector &MinExtent, const Stage::Vectorgeometry::TAffineVector &MaxExtent, const Stage::Vectortypes::TGLVector &C, float Radius);
	void __fastcall WalkTriToLeafx(PGLOctreeNode Onode, const Stage::Vectorgeometry::TAffineFltVector &V1, const Stage::Vectorgeometry::TAffineFltVector &V2, const Stage::Vectorgeometry::TAffineFltVector &V3);
	void __fastcall WalkPointToLeafx(PGLOctreeNode ONode, const Stage::Vectorgeometry::TAffineVector &P);
	void __fastcall WalkSphereToLeafx(PGLOctreeNode Onode, const Stage::Vectortypes::TGLVector &P, float Radius);
	void __fastcall WalkRayToLeafx(PGLOctreeNode Onode, const Stage::Vectortypes::TGLVector &P, const Stage::Vectortypes::TGLVector &V);
	Stage::Vectorgeometry::TAffineFltVector __fastcall GetExtent(const System::Byte *Flags, const System::NativeInt Flags_High, PGLOctreeNode ParentNode);
	void __fastcall Refine(PGLOctreeNode ParentNode, int Level);
	void __fastcall WalkPointToLeaf(PGLOctreeNode ONode, const Stage::Vectorgeometry::TAffineVector &P);
	void __fastcall WalkTriToLeaf(PGLOctreeNode Onode, const Stage::Vectorgeometry::TAffineVector &V1, const Stage::Vectorgeometry::TAffineVector &V2, const Stage::Vectorgeometry::TAffineVector &V3);
	void __fastcall WalkRayToLeaf(PGLOctreeNode Onode, const Stage::Vectortypes::TGLVector &P, const Stage::Vectortypes::TGLVector &V);
	void __fastcall ConvertR4(PGLOctreeNode ONode, const Stage::Vectorgeometry::TAffineFltVector &Scale);
	void __fastcall CreateTree(int Depth);
	void __fastcall CutMesh();
	
public:
	Stage::Vectorgeometry::TAffineFltVector WorldMinExtent;
	Stage::Vectorgeometry::TAffineFltVector WorldMaxExtent;
	PGLOctreeNode RootNode;
	int MaxOlevel;
	int NodeCount;
	int TriCountMesh;
	int TriCountOctree;
	int MeshCount;
	_TGLOctree__1 ResultArray;
	Gls::Vectorlists::TGLAffineVectorList* TriangleFiler;
	void __fastcall WalkSphereToLeaf(PGLOctreeNode Onode, const Stage::Vectortypes::TGLVector &P, float Radius);
	void __fastcall InitializeTree(const Stage::Vectorgeometry::TAffineVector &AWorldMinExtent, const Stage::Vectorgeometry::TAffineVector &AWorldMaxExtent, Gls::Vectorlists::TGLAffineVectorList* const ATriangles, const int ATreeDepth);
	void __fastcall DisposeTree();
	__fastcall virtual ~TGLOctree();
	bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGLVector &RayStart, const Stage::Vectortypes::TGLVector &RayVector, Stage::Vectortypes::PGLVector IntersectPoint = (Stage::Vectortypes::PGLVector)(0x0), Stage::Vectortypes::PGLVector IntersectNormal = (Stage::Vectortypes::PGLVector)(0x0), POctreeTriangleInfo TriangleInfo = (POctreeTriangleInfo)(0x0));
	bool __fastcall SphereSweepIntersect(const Stage::Vectortypes::TGLVector &RayStart, const Stage::Vectortypes::TGLVector &RayVector, const float Velocity, const float Radius, Stage::Vectortypes::PGLVector IntersectPoint = (Stage::Vectortypes::PGLVector)(0x0), Stage::Vectortypes::PGLVector IntersectNormal = (Stage::Vectortypes::PGLVector)(0x0));
	bool __fastcall TriangleIntersect(const Stage::Vectorgeometry::TAffineVector &V1, const Stage::Vectorgeometry::TAffineVector &V2, const Stage::Vectorgeometry::TAffineVector &V3);
	Gls::Vectorlists::TGLAffineVectorList* __fastcall GetTrianglesFromNodesIntersectingAABB(const Gls::Geometrybb::TAABB &ObjAABB);
	Gls::Vectorlists::TGLAffineVectorList* __fastcall GetTrianglesFromNodesIntersectingCube(const Gls::Geometrybb::TAABB &ObjAABB, const Stage::Vectortypes::TGLMatrix &ObjToSelf, const Stage::Vectortypes::TGLMatrix &SelfToObj);
	bool __fastcall AABBIntersect(const Gls::Geometrybb::TAABB &AABB, const Stage::Vectortypes::TGLMatrix &M1to2, const Stage::Vectortypes::TGLMatrix &M2to1, Gls::Vectorlists::TGLAffineVectorList* Triangles = (Gls::Vectorlists::TGLAffineVectorList*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TGLOctree() : System::TObject() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Octree */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_OCTREE)
using namespace Gls::Octree;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_OctreeHPP
