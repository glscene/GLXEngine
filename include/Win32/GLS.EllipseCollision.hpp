// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.EllipseCollision.pas' rev: 36.00 (Windows)

#ifndef GLS_EllipseCollisionHPP
#define GLS_EllipseCollisionHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Octree.hpp>
#include <GLS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
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
	Stage::Vectortypes::TGLMatrix AbsoluteMatrix;
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
	typedef System::DynamicArray<Gls::Octree::PGLOctreeNode> _TECFreeForm__1;
	
	
public:
	_TECFreeForm__1 OctreeNodes;
	Gls::Vectorlists::TGLAffineVectorList* *triangleFiler;
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
	Stage::Vectorgeometry::TAffineVector velocity;
	Stage::Vectorgeometry::TAffineVector normalizedVelocity;
	Stage::Vectorgeometry::TAffineVector basePoint;
	bool foundCollision;
	float nearestDistance;
	int NearestObject;
	Stage::Vectorgeometry::TAffineVector intersectionPoint;
	Stage::Vectorgeometry::TAffineVector intersectionNormal;
};


struct DECLSPEC_DRECORD TECMovePack
{
public:
	TECTriMeshList TriMeshes;
	TECFreeFormList Freeforms;
	TECColliderList Colliders;
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector velocity;
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


typedef System::DynamicArray<TECTriangle> Gls_Ellipsecollision__2;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float cECCloseDistance;
extern DELPHI_PACKAGE Gls_Ellipsecollision__2 Debug_Tri;
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall VectorDivide(const Stage::Vectorgeometry::TAffineVector &v, const Stage::Vectorgeometry::TAffineVector &divider);
extern DELPHI_PACKAGE void __fastcall CollideAndSlide(TECMovePack &MP);
extern DELPHI_PACKAGE void __fastcall CollideWithWorld(TECMovePack &MP, const Stage::Vectorgeometry::TAffineVector &pos, const Stage::Vectorgeometry::TAffineVector &vel, bool &HasCollided);
}	/* namespace Ellipsecollision */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ELLIPSECOLLISION)
using namespace Gls::Ellipsecollision;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_EllipseCollisionHPP
