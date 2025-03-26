// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.EllipseCollision.pas' rev: 36.00 (Windows)

#ifndef GXS_EllipseCollisionHPP
#define GXS_EllipseCollisionHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Octree.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Ellipsecollision
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TECPlane;
struct TECObjectInfo;
struct TECTriangle;
struct TECTriMesh;
struct TECFreeForm;
struct TECCollider;
struct TECContact;
struct TECCollisionPacket;
struct TECMovePack;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TECPlane : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::StaticArray<float, 4> Equation;
	Stage::Vectorgeometry::TAffineVector Origin;
	Stage::Vectorgeometry::TAffineVector Normal;
	void __fastcall MakePlane(const Stage::Vectorgeometry::TAffineVector &nOrigin, const Stage::Vectorgeometry::TAffineVector &nNormal)/* overload */;
	void __fastcall MakePlane(const Stage::Vectorgeometry::TAffineVector &p1, const Stage::Vectorgeometry::TAffineVector &p2, const Stage::Vectorgeometry::TAffineVector &p3)/* overload */;
	bool __fastcall isFrontFacingTo(const Stage::Vectorgeometry::TAffineVector &Direction);
	float __fastcall signedDistanceTo(const Stage::Vectorgeometry::TAffineVector &Point);
public:
	/* TObject.Create */ inline __fastcall TECPlane() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TECPlane() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TECObjectInfo
{
public:
	Stage::Vectortypes::TMatrix4f AbsoluteMatrix;
	bool Solid;
	bool IsDynamic;
	int ObjectID;
};


struct DECLSPEC_DRECORD TECTriangle
{
public:
	Stage::Vectorgeometry::TAffineVector p1;
	Stage::Vectorgeometry::TAffineVector p2;
	Stage::Vectorgeometry::TAffineVector p3;
};


struct DECLSPEC_DRECORD TECTriMesh
{
	
private:
	typedef System::DynamicArray<TECTriangle> _TECTriMesh__1;
	
	
public:
	_TECTriMesh__1 Triangles;
	TECObjectInfo ObjectInfo;
};


typedef System::DynamicArray<TECTriMesh> TECTriMeshList;

struct DECLSPEC_DRECORD TECFreeForm
{
	
private:
	typedef System::DynamicArray<Gxs::Octree::PgxOctreeNode> _TECFreeForm__1;
	
	
public:
	_TECFreeForm__1 OctreeNodes;
	Gxs::Vectorlists::TgxAffineVectorList* *triangleFiler;
	bool InvertedNormals;
	TECObjectInfo ObjectInfo;
};


typedef System::DynamicArray<TECFreeForm> TECFreeFormList;

enum DECLSPEC_DENUM TECColliderShape : unsigned char { csEllipsoid, csPoint };

struct DECLSPEC_DRECORD TECCollider
{
public:
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector Radius;
	TECColliderShape Shape;
	TECObjectInfo ObjectInfo;
};


typedef System::DynamicArray<TECCollider> TECColliderList;

struct DECLSPEC_DRECORD TECContact
{
public:
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector SurfaceNormal;
	float Distance;
	TECObjectInfo ObjectInfo;
};


typedef System::DynamicArray<TECContact> TECContactList;

struct DECLSPEC_DRECORD TECCollisionPacket
{
public:
	Stage::Vectorgeometry::TAffineVector Velocity;
	Stage::Vectorgeometry::TAffineVector NormalizedVelocity;
	Stage::Vectorgeometry::TAffineVector BasePoint;
	bool FoundCollision;
	float NearestDistance;
	int NearestObject;
	Stage::Vectorgeometry::TAffineVector IntersectionPoint;
	Stage::Vectorgeometry::TAffineVector IntersectionNormal;
};


struct DECLSPEC_DRECORD TECMovePack
{
public:
	TECTriMeshList TriMeshes;
	TECFreeFormList Freeforms;
	TECColliderList Colliders;
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector Velocity;
	Stage::Vectorgeometry::TAffineVector Gravity;
	Stage::Vectorgeometry::TAffineVector Radius;
	TECObjectInfo ObjectInfo;
	float CollisionRange;
	double UnitScale;
	System::Byte MaxRecursionDepth;
	TECCollisionPacket CP;
	System::Byte collisionRecursionDepth;
	Stage::Vectorgeometry::TAffineVector ResultPos;
	int NearestObject;
	bool VelocityCollided;
	bool GravityCollided;
	Stage::Vectorgeometry::TAffineVector GroundNormal;
	TECContactList Contacts;
};


typedef System::DynamicArray<TECTriangle> Gxs_Ellipsecollision__2;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float cECCloseDistance;
extern DELPHI_PACKAGE Gxs_Ellipsecollision__2 Debug_tri;
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall VectorDivide(const Stage::Vectorgeometry::TAffineVector &v, const Stage::Vectorgeometry::TAffineVector &divider);
extern DELPHI_PACKAGE void __fastcall CollideAndSlide(TECMovePack &MP);
extern DELPHI_PACKAGE void __fastcall CollideWithWorld(TECMovePack &MP, const Stage::Vectorgeometry::TAffineVector &pos, const Stage::Vectorgeometry::TAffineVector &vel, bool &HasCollided);
}	/* namespace Ellipsecollision */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ELLIPSECOLLISION)
using namespace Gxs::Ellipsecollision;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_EllipseCollisionHPP
