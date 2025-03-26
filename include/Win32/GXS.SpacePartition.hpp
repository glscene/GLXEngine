// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SpacePartition.pas' rev: 36.00 (Windows)

#ifndef GXS_SpacePartitionHPP
#define GXS_SpacePartitionHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Spacepartition
{
//-- forward type declarations -----------------------------------------------
struct TSPCone;
struct TExtendedFrustum;
class DELPHICLASS TSpacePartitionLeaf;
class DELPHICLASS TSpacePartitionLeafList;
class DELPHICLASS TBaseSpacePartition;
class DELPHICLASS TLeavedSpacePartition;
class DELPHICLASS TSectorNode;
class DELPHICLASS TSectoredSpacePartition;
class DELPHICLASS TSPOctreeNode;
class DELPHICLASS TOctreeSpacePartition;
class DELPHICLASS TSPQuadtreeNode;
class DELPHICLASS TQuadtreeSpacePartition;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TSPCone
{
public:
	Stage::Vectorgeometry::TAffineVector Base;
	Stage::Vectorgeometry::TAffineVector Axis;
	float Angle;
	float Length;
};


struct DECLSPEC_DRECORD TExtendedFrustum
{
public:
	Stage::Vectorgeometry::TFrustum Frustum;
	Gxs::Geometrybb::TBSphere BSphere;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSpacePartitionLeaf : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TBaseSpacePartition* FSpacePartition;
	void __fastcall SetSpacePartition(TBaseSpacePartition* const Value);
	
public:
	void *FPartitionTag;
	Gxs::Geometrybb::TAABB FCachedAABB;
	Gxs::Geometrybb::TBSphere FCachedBSphere;
	virtual void __fastcall Changed();
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__property TBaseSpacePartition* SpacePartition = {read=FSpacePartition, write=SetSpacePartition};
	__property void * PartitionTag = {read=FPartitionTag};
	__fastcall TSpacePartitionLeaf(TBaseSpacePartition* SpacePartition);
	__fastcall virtual ~TSpacePartitionLeaf();
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TSpacePartitionLeaf() : Gxs::Persistentclasses::TgxPersistentObject() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSpacePartitionLeaf(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSpacePartitionLeafList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TSpacePartitionLeaf* operator[](int I) { return this->Items[I]; }
	
private:
	TSpacePartitionLeaf* __fastcall GetItems(int I);
	void __fastcall SetItems(int I, TSpacePartitionLeaf* const Value);
	
public:
	__property TSpacePartitionLeaf* Items[int I] = {read=GetItems, write=SetItems/*, default*/};
	__fastcall virtual TSpacePartitionLeafList();
public:
	/* TgxPersistentObjectList.Destroy */ inline __fastcall virtual ~TSpacePartitionLeafList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSpacePartitionLeafList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TCullingMode : unsigned char { CmFineCulling, CmGrossCulling };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TBaseSpacePartition : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TCullingMode FCullingMode;
	virtual int __fastcall QueryCone(const TSPCone &ACone);
	
protected:
	TSpacePartitionLeafList* FQueryResult;
	int FQueryInterObjectTests;
	virtual void __fastcall FlushQueryResult();
	
public:
	__property TSpacePartitionLeafList* QueryResult = {read=FQueryResult};
	virtual void __fastcall Clear();
	virtual void __fastcall AddLeaf(TSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TSpacePartitionLeaf* ALeaf);
	virtual void __fastcall LeafChanged(TSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Gxs::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Gxs::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryLeaf(TSpacePartitionLeaf* const ALeaf);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal);
	virtual int __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum);
	virtual int __fastcall QueryFrustumEx(const TExtendedFrustum &ExtendedFrustum);
	__property int QueryInterObjectTests = {read=FQueryInterObjectTests, nodefault};
	virtual void __fastcall ProcessUpdated();
	__property TCullingMode CullingMode = {read=FCullingMode, write=FCullingMode, nodefault};
	__fastcall virtual TBaseSpacePartition();
	__fastcall virtual ~TBaseSpacePartition();
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TBaseSpacePartition(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TLeavedSpacePartition : public TBaseSpacePartition
{
	typedef TBaseSpacePartition inherited;
	
private:
	TSpacePartitionLeafList* FLeaves;
	virtual int __fastcall QueryCone(const TSPCone &ACone);
	
public:
	virtual void __fastcall Clear();
	virtual void __fastcall AddLeaf(TSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Gxs::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Gxs::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &FLocation, const Stage::Vectorgeometry::TAffineVector &FNormal);
	__fastcall virtual TLeavedSpacePartition();
	__fastcall virtual ~TLeavedSpacePartition();
	
__published:
	__property TSpacePartitionLeafList* Leaves = {read=FLeaves};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TLeavedSpacePartition(Gxs::Persistentclasses::TgxVirtualReader* reader) : TBaseSpacePartition(reader) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<TSectorNode*, 8> TSectorNodeArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSectorNode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TSpacePartitionLeafList* FLeaves;
	Gxs::Geometrybb::TAABB FAABB;
	TSectoredSpacePartition* FSectoredSpacePartition;
	int FRecursiveLeafCount;
	TSectorNode* FParent;
	int FNodeDepth;
	int FChildCount;
	TSectorNodeArray FChildren;
	Gxs::Geometrybb::TBSphere FBSphere;
	bool __fastcall GetNoChildren();
	void __fastcall SetAABB(const Gxs::Geometrybb::TAABB &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetCenter();
	
protected:
	int __fastcall CalcRecursiveLeafCount();
	TSectorNode* __fastcall PlaceLeafInChild(TSpacePartitionLeaf* ALeaf);
	System::UnicodeString __fastcall VerifyRecursiveLeafCount();
	virtual void __fastcall ChildrenChanged();
	
public:
	void __fastcall Clear();
	__property Gxs::Geometrybb::TAABB AABB = {read=FAABB, write=SetAABB};
	__property Gxs::Geometrybb::TBSphere BSphere = {read=FBSphere};
	__property Stage::Vectorgeometry::TAffineVector Center = {read=GetCenter};
	__property bool NoChildren = {read=GetNoChildren, nodefault};
	__property TSectorNodeArray Children = {read=FChildren};
	__property int ChildCount = {read=FChildCount, nodefault};
	virtual TSectorNode* __fastcall GetChildForAABB(const Gxs::Geometrybb::TAABB &AABB);
	__property TSpacePartitionLeafList* Leaves = {read=FLeaves};
	__property TSectoredSpacePartition* SectoredSpacePartition = {read=FSectoredSpacePartition};
	__property TSectorNode* Parent = {read=FParent};
	__property int RecursiveLeafCount = {read=FRecursiveLeafCount, nodefault};
	__property int NodeDepth = {read=FNodeDepth, nodefault};
	virtual bool __fastcall AABBFitsInNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual Gxs::Geometrybb::TSpaceContains __fastcall AABBContainsSector(const Gxs::Geometrybb::TAABB &AABB);
	virtual Gxs::Geometrybb::TSpaceContains __fastcall BSphereContainsSector(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual Gxs::Geometrybb::TSpaceContains __fastcall ContainsBSphere(const Gxs::Geometrybb::TBSphere &ABSphere);
	virtual Gxs::Geometrybb::TSpaceContains __fastcall ContainsAABB(const Gxs::Geometrybb::TAABB &AAABB);
	TSectorNode* __fastcall AddLeaf(TSpacePartitionLeaf* ALeaf);
	bool __fastcall RemoveLeaf(TSpacePartitionLeaf* ALeaf, bool OwnerByThis);
	void __fastcall QueryAABB(const Gxs::Geometrybb::TAABB &AAABB, TSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryBSphere(const Gxs::Geometrybb::TBSphere &ABSphere, TSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal, TSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum, TSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryFrustumEx(const TExtendedFrustum &ExtendedFrustum, TSpacePartitionLeafList* const QueryResult);
	void __fastcall AddAllLeavesRecursive(TSpacePartitionLeafList* const QueryResult);
	void __fastcall ExpandNode();
	virtual void __fastcall CreateChildren();
	void __fastcall CollapseNode();
	int __fastcall GetNodeCount();
	__fastcall TSectorNode(TSectoredSpacePartition* ASectoredSpacePartition, TSectorNode* AParent);
	__fastcall virtual ~TSectorNode();
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGrowMethod : unsigned char { gmNever, gmBestFit, gmIncreaseToFitAll };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSectoredSpacePartition : public TLeavedSpacePartition
{
	typedef TLeavedSpacePartition inherited;
	
private:
	TSectorNode* FRootNode;
	int FLeafThreshold;
	int FMaxTreeDepth;
	float FGrowGravy;
	TGrowMethod FGrowMethod;
	void __fastcall SetLeafThreshold(const int Value);
	void __fastcall SetMaxTreeDepth(const int Value);
	
protected:
	int FQueryNodeTests;
	virtual void __fastcall FlushQueryResult();
	
public:
	virtual void __fastcall AddLeaf(TSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TSpacePartitionLeaf* ALeaf);
	virtual void __fastcall LeafChanged(TSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Gxs::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Gxs::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryLeaf(TSpacePartitionLeaf* const ALeaf);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal);
	virtual int __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum);
	virtual int __fastcall QueryFrustumEx(const TExtendedFrustum &ExtendedFrustum);
	__property int QueryNodeTests = {read=FQueryNodeTests, nodefault};
	int __fastcall GetNodeCount();
	void __fastcall UpdateStructureSize(float Gravy);
	void __fastcall RebuildTree(const Gxs::Geometrybb::TAABB &NewAABB);
	Gxs::Geometrybb::TAABB __fastcall GetAABB();
	virtual TSectorNode* __fastcall CreateNewNode(TSectorNode* AParent);
	virtual void __fastcall Clear();
	__fastcall virtual TSectoredSpacePartition();
	__fastcall virtual ~TSectoredSpacePartition();
	
__published:
	__property TSectorNode* RootNode = {read=FRootNode};
	__property int MaxTreeDepth = {read=FMaxTreeDepth, write=SetMaxTreeDepth, nodefault};
	__property int LeafThreshold = {read=FLeafThreshold, write=SetLeafThreshold, nodefault};
	__property TGrowMethod GrowMethod = {read=FGrowMethod, write=FGrowMethod, nodefault};
	__property float GrowGravy = {read=FGrowGravy, write=FGrowGravy};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSectoredSpacePartition(Gxs::Persistentclasses::TgxVirtualReader* reader) : TLeavedSpacePartition(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSPOctreeNode : public TSectorNode
{
	typedef TSectorNode inherited;
	
public:
	virtual void __fastcall CreateChildren();
	virtual bool __fastcall AABBFitsInNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Gxs::Geometrybb::TBSphere &BSphere);
public:
	/* TSectorNode.Create */ inline __fastcall TSPOctreeNode(TSectoredSpacePartition* ASectoredSpacePartition, TSectorNode* AParent) : TSectorNode(ASectoredSpacePartition, AParent) { }
	/* TSectorNode.Destroy */ inline __fastcall virtual ~TSPOctreeNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TOctreeSpacePartition : public TSectoredSpacePartition
{
	typedef TSectoredSpacePartition inherited;
	
public:
	void __fastcall SetSize(const Stage::Vectorgeometry::TAffineVector &Min, const Stage::Vectorgeometry::TAffineVector &Max);
	virtual TSectorNode* __fastcall CreateNewNode(TSectorNode* AParent);
public:
	/* TSectoredSpacePartition.Create */ inline __fastcall virtual TOctreeSpacePartition() : TSectoredSpacePartition() { }
	/* TSectoredSpacePartition.Destroy */ inline __fastcall virtual ~TOctreeSpacePartition() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TOctreeSpacePartition(Gxs::Persistentclasses::TgxVirtualReader* reader) : TSectoredSpacePartition(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSPQuadtreeNode : public TSPOctreeNode
{
	typedef TSPOctreeNode inherited;
	
protected:
	virtual void __fastcall ChildrenChanged();
	
public:
	virtual void __fastcall CreateChildren();
	virtual bool __fastcall AABBFitsInNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Gxs::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Gxs::Geometrybb::TBSphere &BSphere);
	virtual TSectorNode* __fastcall GetChildForAABB(const Gxs::Geometrybb::TAABB &AABB);
public:
	/* TSectorNode.Create */ inline __fastcall TSPQuadtreeNode(TSectoredSpacePartition* ASectoredSpacePartition, TSectorNode* AParent) : TSPOctreeNode(ASectoredSpacePartition, AParent) { }
	/* TSectorNode.Destroy */ inline __fastcall virtual ~TSPQuadtreeNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TQuadtreeSpacePartition : public TSectoredSpacePartition
{
	typedef TSectoredSpacePartition inherited;
	
public:
	void __fastcall SetSize(const Stage::Vectorgeometry::TAffineVector &Min, const Stage::Vectorgeometry::TAffineVector &Max);
	virtual TSectorNode* __fastcall CreateNewNode(TSectorNode* AParent);
public:
	/* TSectoredSpacePartition.Create */ inline __fastcall virtual TQuadtreeSpacePartition() : TSectoredSpacePartition() { }
	/* TSectoredSpacePartition.Destroy */ inline __fastcall virtual ~TQuadtreeSpacePartition() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TQuadtreeSpacePartition(Gxs::Persistentclasses::TgxVirtualReader* reader) : TSectoredSpacePartition(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 COctree_LEAF_TRHESHOLD = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 COctree_MAX_TREE_DEPTH = System::Int8(0x8);
#define COctree_GROW_GRAVY  (1.000000E-01)
extern DELPHI_PACKAGE Gxs::Geometrybb::TSpaceContains __fastcall ConeContainsBSphere(const TSPCone &Cone, const Gxs::Geometrybb::TBSphere &BSphere);
extern DELPHI_PACKAGE bool __fastcall ExtendedFrustumIntersectsBSphere(const TExtendedFrustum &AExtendedFrustum, const Gxs::Geometrybb::TBSphere &ABSphere);
extern DELPHI_PACKAGE TExtendedFrustum __fastcall ExtendedFrustumMake(const Stage::Vectorgeometry::TFrustum &AFrustum, const float ANearDist, const float AFarDist, const float AFieldOfViewRadians, const Stage::Vectorgeometry::TAffineVector &ACameraPosition, const Stage::Vectorgeometry::TAffineVector &ALookVector);
}	/* namespace Spacepartition */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SPACEPARTITION)
using namespace Gxs::Spacepartition;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SpacePartitionHPP
