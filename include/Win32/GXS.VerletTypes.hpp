// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.VerletTypes.pas' rev: 36.00 (Windows)

#ifndef GXS_VerletTypesHPP
#define GXS_VerletTypesHPP

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
#include <System.Types.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.SpacePartition.hpp>
#include <GXS.GeometryBB.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Verlettypes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBaseVerletNode;
class DELPHICLASS TgxVerletNodeList;
class DELPHICLASS TgxVerletConstraint;
class DELPHICLASS TgxVerletDualConstraint;
class DELPHICLASS TgxVerletGroupConstraint;
class DELPHICLASS TgxVerletEdge;
class DELPHICLASS TgxVerletEdgeList;
class DELPHICLASS TgxVerletGlobalConstraint;
class DELPHICLASS TgxVerletGlobalFrictionConstraint;
class DELPHICLASS TgxVerletGlobalFrictionConstraintSP;
class DELPHICLASS TgxVerletGlobalFrictionConstraintSphere;
class DELPHICLASS TgxVerletGlobalFrictionConstraintBox;
class DELPHICLASS TgxVerletConstraintList;
class DELPHICLASS TgxVerletForce;
class DELPHICLASS TgxVerletDualForce;
class DELPHICLASS TgxVerletGroupForce;
class DELPHICLASS TgxVerletGlobalForce;
class DELPHICLASS TgxVerletForceList;
class DELPHICLASS TgxVerletWorld;
class DELPHICLASS TgxVerletGravity;
class DELPHICLASS TgxVerletAirResistance;
class DELPHICLASS TgxVerletSpring;
class DELPHICLASS TgxVerletFloor;
class DELPHICLASS TgxVerletHeightField;
class DELPHICLASS TgxVerletStick;
class DELPHICLASS TgxVerletRigidBody;
class DELPHICLASS TgxVerletSlider;
class DELPHICLASS TgxVerletFrictionSphere;
class DELPHICLASS TgxVerletFrictionCylinder;
class DELPHICLASS TgxVerletFrictionCube;
class DELPHICLASS TgxVerletFrictionCapsule;
class DELPHICLASS TgxVerletNode;
class DELPHICLASS TgxVerletHair;
class DELPHICLASS TgxVerletSkeletonCollider;
class DELPHICLASS TgxVerletSphere;
class DELPHICLASS TgxVerletCapsule;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxStiffnessVH : unsigned char { vhsFull, vhsSkip1Node, vhsSkip2Node, vhsSkip3Node, vhsSkip4Node, vhsSkip5Node, vhsSkip6Node, vhsSkip7Node, vhsSkip8Node, vhsSkip9Node };

typedef System::Set<TgxStiffnessVH, TgxStiffnessVH::vhsFull, TgxStiffnessVH::vhsSkip9Node> TgxStiffnessSetVH;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBaseVerletNode : public Gxs::Spacepartition::TSpacePartitionLeaf
{
	typedef Gxs::Spacepartition::TSpacePartitionLeaf inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FForce;
	TgxVerletWorld* FOwner;
	float FWeight;
	float FInvWeight;
	float FRadius;
	bool FNailedDown;
	float FFriction;
	int FChangedOnStep;
	Stage::Vectorgeometry::TAffineVector __fastcall GetSpeed();
	
protected:
	Stage::Vectorgeometry::TAffineVector FLocation;
	Stage::Vectorgeometry::TAffineVector FOldLocation;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	void __fastcall SetWeight(const float Value);
	virtual void __fastcall AfterProgress();
	
public:
	__fastcall virtual TgxBaseVerletNode(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxBaseVerletNode();
	void __fastcall ApplyFriction(const float friction, const float penetrationDepth, const Stage::Vectorgeometry::TAffineVector &surfaceNormal);
	void __fastcall OldApplyFriction(const float friction, const float penetrationDepth);
	virtual void __fastcall Verlet(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	DYNAMIC void __fastcall Initialize();
	float __fastcall DistanceToNode(TgxBaseVerletNode* const node);
	Stage::Vectorgeometry::TAffineVector __fastcall GetMovement();
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__property TgxVerletWorld* Owner = {read=FOwner};
	__property Stage::Vectorgeometry::TAffineVector Location = {read=FLocation, write=SetLocation};
	__property Stage::Vectorgeometry::TAffineVector OldLocation = {read=FOldLocation, write=FOldLocation};
	__property float Radius = {read=FRadius, write=FRadius};
	__property Stage::Vectorgeometry::TAffineVector Force = {read=FForce, write=FForce};
	__property bool NailedDown = {read=FNailedDown, write=FNailedDown, nodefault};
	__property float Weight = {read=FWeight, write=SetWeight};
	__property float InvWeight = {read=FInvWeight};
	__property Stage::Vectorgeometry::TAffineVector Speed = {read=GetSpeed};
	__property float friction = {read=FFriction, write=FFriction};
	__property int ChangedOnStep = {read=FChangedOnStep, nodefault};
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxBaseVerletNode() : Gxs::Spacepartition::TSpacePartitionLeaf() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxBaseVerletNode(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Spacepartition::TSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TgxVerletNodeClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletNodeList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TgxBaseVerletNode* operator[](int i) { return this->Items[i]; }
	
private:
	TgxBaseVerletNode* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TgxBaseVerletNode* const Value);
	
public:
	__property TgxBaseVerletNode* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxVerletNodeList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxVerletNodeList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletConstraint : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxVerletWorld* FOwner;
	bool FEnabled;
	int FTag;
	
public:
	__fastcall virtual TgxVerletConstraint(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxVerletConstraint();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations) = 0 ;
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode) = 0 ;
	virtual void __fastcall BeforeIterations();
	__property TgxVerletWorld* Owner = {read=FOwner};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletDualConstraint : public TgxVerletConstraint
{
	typedef TgxVerletConstraint inherited;
	
private:
	TgxBaseVerletNode* FNodeA;
	TgxBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	__property TgxBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TgxBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TgxVerletConstraint.Create */ inline __fastcall virtual TgxVerletDualConstraint(TgxVerletWorld* const aOwner) : TgxVerletConstraint(aOwner) { }
	/* TgxVerletConstraint.Destroy */ inline __fastcall virtual ~TgxVerletDualConstraint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGroupConstraint : public TgxVerletConstraint
{
	typedef TgxVerletConstraint inherited;
	
private:
	TgxVerletNodeList* FNodes;
	
public:
	__fastcall virtual TgxVerletGroupConstraint(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxVerletGroupConstraint();
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	__property TgxVerletNodeList* Nodes = {read=FNodes};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletEdge : public Gxs::Spacepartition::TSpacePartitionLeaf
{
	typedef Gxs::Spacepartition::TSpacePartitionLeaf inherited;
	
private:
	TgxBaseVerletNode* FNodeA;
	TgxBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__fastcall TgxVerletEdge(TgxBaseVerletNode* const aNodeA, TgxBaseVerletNode* const aNodeB);
	__property TgxBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TgxBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TSpacePartitionLeaf.CreateOwned */ inline __fastcall TgxVerletEdge(Gxs::Spacepartition::TBaseSpacePartition* SpacePartition) : Gxs::Spacepartition::TSpacePartitionLeaf(SpacePartition) { }
	/* TSpacePartitionLeaf.Destroy */ inline __fastcall virtual ~TgxVerletEdge() { }
	
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxVerletEdge() : Gxs::Spacepartition::TSpacePartitionLeaf() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVerletEdge(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Spacepartition::TSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletEdgeList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TgxVerletEdge* operator[](int i) { return this->Items[i]; }
	
private:
	TgxVerletEdge* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TgxVerletEdge* const Value);
	
public:
	__property TgxVerletEdge* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxVerletEdgeList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxVerletEdgeList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalConstraint : public TgxVerletConstraint
{
	typedef TgxVerletConstraint inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FKickbackForce;
	Stage::Vectorgeometry::TAffineVector FKickbackTorque;
	Stage::Vectorgeometry::TAffineVector FLocation;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TgxVerletGlobalConstraint(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxVerletGlobalConstraint();
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	virtual void __fastcall BeforeIterations();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations) = 0 ;
	virtual void __fastcall SatisfyConstraintForEdge(TgxVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Location = {read=FLocation, write=SetLocation};
	__property Stage::Vectorgeometry::TAffineVector KickbackForce = {read=FKickbackForce, write=FKickbackForce};
	__property Stage::Vectorgeometry::TAffineVector KickbackTorque = {read=FKickbackTorque, write=FKickbackTorque};
	void __fastcall AddKickbackForceAt(const Stage::Vectorgeometry::TAffineVector &Pos, const Stage::Vectorgeometry::TAffineVector &Force);
	Stage::Vectorgeometry::TAffineVector __fastcall TranslateKickbackTorque(const Stage::Vectorgeometry::TAffineVector &TorqueCenter);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalFrictionConstraint : public TgxVerletGlobalConstraint
{
	typedef TgxVerletGlobalConstraint inherited;
	
private:
	float FFrictionRatio;
	
public:
	__fastcall virtual TgxVerletGlobalFrictionConstraint(TgxVerletWorld* const aOwner);
	__property float FrictionRatio = {read=FFrictionRatio, write=FFrictionRatio};
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletGlobalFrictionConstraint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalFrictionConstraintSP : public TgxVerletGlobalFrictionConstraint
{
	typedef TgxVerletGlobalFrictionConstraint inherited;
	
public:
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	virtual void __fastcall PerformSpaceQuery() = 0 ;
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletGlobalFrictionConstraintSP(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraint(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletGlobalFrictionConstraintSP() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalFrictionConstraintSphere : public TgxVerletGlobalFrictionConstraintSP
{
	typedef TgxVerletGlobalFrictionConstraintSP inherited;
	
private:
	Gxs::Geometrybb::TBSphere FCachedBSphere;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	void __fastcall UpdateCachedBSphere();
	virtual void __fastcall PerformSpaceQuery();
	virtual Gxs::Geometrybb::TBSphere __fastcall GetBSphere() = 0 ;
	__property Gxs::Geometrybb::TBSphere CachedBSphere = {read=FCachedBSphere};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletGlobalFrictionConstraintSphere(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraintSP(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletGlobalFrictionConstraintSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalFrictionConstraintBox : public TgxVerletGlobalFrictionConstraintSP
{
	typedef TgxVerletGlobalFrictionConstraintSP inherited;
	
private:
	Gxs::Geometrybb::TAABB FCachedAABB;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	void __fastcall UpdateCachedAABB();
	virtual void __fastcall PerformSpaceQuery();
	virtual Gxs::Geometrybb::TAABB __fastcall GetAABB() = 0 ;
	__property Gxs::Geometrybb::TAABB CachedAABB = {read=FCachedAABB};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletGlobalFrictionConstraintBox(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraintSP(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletGlobalFrictionConstraintBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletConstraintList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TgxVerletConstraint* operator[](int i) { return this->Items[i]; }
	
private:
	TgxVerletConstraint* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TgxVerletConstraint* const Value);
	
public:
	__property TgxVerletConstraint* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxVerletConstraintList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxVerletConstraintList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletForce : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxVerletWorld* FOwner;
	
public:
	__fastcall virtual TgxVerletForce(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxVerletForce();
	virtual void __fastcall AddForce(const Gxs::Baseclasses::TgxProgressTimes &vpt) = 0 ;
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode) = 0 ;
	__property TgxVerletWorld* Owner = {read=FOwner};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletDualForce : public TgxVerletForce
{
	typedef TgxVerletForce inherited;
	
private:
	TgxBaseVerletNode* FNodeA;
	TgxBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	__property TgxBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TgxBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TgxVerletForce.Create */ inline __fastcall virtual TgxVerletDualForce(TgxVerletWorld* const aOwner) : TgxVerletForce(aOwner) { }
	/* TgxVerletForce.Destroy */ inline __fastcall virtual ~TgxVerletDualForce() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGroupForce : public TgxVerletForce
{
	typedef TgxVerletForce inherited;
	
private:
	TgxVerletNodeList* FNodes;
	
public:
	__fastcall virtual TgxVerletGroupForce(TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxVerletGroupForce();
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	__property TgxVerletNodeList* Nodes = {read=FNodes};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGlobalForce : public TgxVerletForce
{
	typedef TgxVerletForce inherited;
	
public:
	virtual void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	virtual void __fastcall AddForce(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	virtual void __fastcall AddForceToNode(TgxBaseVerletNode* const aNode) = 0 ;
public:
	/* TgxVerletForce.Create */ inline __fastcall virtual TgxVerletGlobalForce(TgxVerletWorld* const aOwner) : TgxVerletForce(aOwner) { }
	/* TgxVerletForce.Destroy */ inline __fastcall virtual ~TgxVerletGlobalForce() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletForceList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TgxVerletForce* operator[](int i) { return this->Items[i]; }
	
private:
	TgxVerletForce* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TgxVerletForce* const Value);
	
public:
	__property TgxVerletForce* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxVerletForceList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxVerletForceList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TUpdateSpacePartion : unsigned char { uspEveryIteration, uspEveryFrame, uspNever };

enum DECLSPEC_DENUM TCollisionConstraintTypes : unsigned char { cctEdge, cctNode };

typedef System::Set<TCollisionConstraintTypes, TCollisionConstraintTypes::cctEdge, TCollisionConstraintTypes::cctNode> TCollisionConstraintTypesSet;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletWorld : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIterations;
	TgxVerletNodeList* FNodes;
	TgxVerletConstraintList* FConstraints;
	TgxVerletForceList* FForces;
	float FMaxDeltaTime;
	float FSimTime;
	float FDrag;
	float FCurrentDeltaTime;
	float FInvCurrentDeltaTime;
	TgxVerletEdgeList* FSolidEdges;
	Gxs::Spacepartition::TBaseSpacePartition* FSpacePartition;
	int FCurrentStepCount;
	TUpdateSpacePartion FUpdateSpacePartion;
	TCollisionConstraintTypesSet FCollisionConstraintTypes;
	TgxVerletConstraintList* FConstraintsWithBeforeIterations;
	TgxVerletNodeClass FVerletNodeClass;
	bool FInertia;
	int FInertaPauseSteps;
	
protected:
	virtual void __fastcall AccumulateForces(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	virtual void __fastcall Verlet(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	virtual void __fastcall SatisfyConstraints(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	void __fastcall DoUpdateSpacePartition();
	
public:
	__fastcall virtual TgxVerletWorld();
	__fastcall virtual ~TgxVerletWorld();
	int __fastcall AddNode(TgxBaseVerletNode* const aNode);
	void __fastcall RemoveNode(TgxBaseVerletNode* const aNode);
	int __fastcall AddConstraint(TgxVerletConstraint* const aConstraint);
	void __fastcall RemoveConstraint(TgxVerletConstraint* const aConstraint);
	int __fastcall AddForce(TgxVerletForce* const aForce);
	void __fastcall RemoveForce(TgxVerletForce* const aForce);
	void __fastcall AddSolidEdge(TgxBaseVerletNode* const aNodeA, TgxBaseVerletNode* const aNodeB);
	void __fastcall PauseInertia(const int IterationSteps);
	TgxBaseVerletNode* __fastcall CreateOwnedNode(const Stage::Vectorgeometry::TAffineVector &Location, const float aRadius = 0.000000E+00f, const float aWeight = 1.000000E+00f);
	TgxVerletStick* __fastcall CreateStick(TgxBaseVerletNode* const aNodeA, TgxBaseVerletNode* const aNodeB, const float Slack = 0.000000E+00f);
	TgxVerletSpring* __fastcall CreateSpring(TgxBaseVerletNode* const aNodeA, TgxBaseVerletNode* const aNodeB, const float aStrength, const float aDamping, const float aSlack = 0.000000E+00f);
	TgxVerletSlider* __fastcall CreateSlider(TgxBaseVerletNode* const aNodeA, TgxBaseVerletNode* const aNodeB, const Stage::Vectorgeometry::TAffineVector &aSlideDirection);
	virtual void __fastcall Initialize();
	void __fastcall CreateOctree(const Stage::Vectorgeometry::TAffineVector &OctreeMin, const Stage::Vectorgeometry::TAffineVector &OctreeMax, const int LeafThreshold, const int MaxTreeDepth);
	virtual int __fastcall Progress(const double deltaTime, const double newTime);
	TgxBaseVerletNode* __fastcall FirstNode();
	TgxBaseVerletNode* __fastcall LastNode();
	__property float Drag = {read=FDrag, write=FDrag};
	__property int Iterations = {read=FIterations, write=FIterations, nodefault};
	__property TgxVerletNodeList* Nodes = {read=FNodes};
	__property TgxVerletConstraintList* Constraints = {read=FConstraints};
	__property TgxVerletConstraintList* ConstraintsWithBeforeIterations = {read=FConstraintsWithBeforeIterations};
	__property float SimTime = {read=FSimTime, write=FSimTime};
	__property float MaxDeltaTime = {read=FMaxDeltaTime, write=FMaxDeltaTime};
	__property float CurrentDeltaTime = {read=FCurrentDeltaTime};
	__property TgxVerletEdgeList* SolidEdges = {read=FSolidEdges, write=FSolidEdges};
	__property int CurrentStepCount = {read=FCurrentStepCount, nodefault};
	__property Gxs::Spacepartition::TBaseSpacePartition* SpacePartition = {read=FSpacePartition};
	__property TUpdateSpacePartion UpdateSpacePartion = {read=FUpdateSpacePartion, write=FUpdateSpacePartion, nodefault};
	__property TCollisionConstraintTypesSet CollisionConstraintTypes = {read=FCollisionConstraintTypes, write=FCollisionConstraintTypes, nodefault};
	__property TgxVerletNodeClass VerletNodeClass = {read=FVerletNodeClass, write=FVerletNodeClass};
	__property bool Inertia = {read=FInertia, write=FInertia, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletGravity : public TgxVerletGlobalForce
{
	typedef TgxVerletGlobalForce inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FGravity;
	
public:
	__fastcall virtual TgxVerletGravity(TgxVerletWorld* const aOwner);
	virtual void __fastcall AddForceToNode(TgxBaseVerletNode* const aNode);
	__property Stage::Vectorgeometry::TAffineVector Gravity = {read=FGravity, write=FGravity};
public:
	/* TgxVerletForce.Destroy */ inline __fastcall virtual ~TgxVerletGravity() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletAirResistance : public TgxVerletGlobalForce
{
	typedef TgxVerletGlobalForce inherited;
	
private:
	float FDragCoeff;
	Stage::Vectorgeometry::TAffineVector FWindDirection;
	float FWindMagnitude;
	float FWindChaos;
	void __fastcall SetWindDirection(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TgxVerletAirResistance(TgxVerletWorld* const aOwner);
	virtual void __fastcall AddForceToNode(TgxBaseVerletNode* const aNode);
	__property float DragCoeff = {read=FDragCoeff, write=FDragCoeff};
	__property Stage::Vectorgeometry::TAffineVector WindDirection = {read=FWindDirection, write=SetWindDirection};
	__property float WindMagnitude = {read=FWindMagnitude, write=FWindMagnitude};
	__property float WindChaos = {read=FWindChaos, write=FWindChaos};
public:
	/* TgxVerletForce.Destroy */ inline __fastcall virtual ~TgxVerletAirResistance() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletSpring : public TgxVerletDualForce
{
	typedef TgxVerletDualForce inherited;
	
private:
	float FRestLength;
	float FStrength;
	float FDamping;
	float FSlack;
	float FForceFactor;
	
protected:
	void __fastcall SetSlack(const float Value);
	
public:
	virtual void __fastcall AddForce(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	void __fastcall SetRestLengthToCurrent();
	__property float Strength = {read=FStrength, write=FStrength};
	__property float Damping = {read=FDamping, write=FDamping};
	__property float Slack = {read=FSlack, write=SetSlack};
public:
	/* TgxVerletForce.Create */ inline __fastcall virtual TgxVerletSpring(TgxVerletWorld* const aOwner) : TgxVerletDualForce(aOwner) { }
	/* TgxVerletForce.Destroy */ inline __fastcall virtual ~TgxVerletSpring() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletFloor : public TgxVerletGlobalFrictionConstraintSP
{
	typedef TgxVerletGlobalFrictionConstraintSP inherited;
	
private:
	float FBounceRatio;
	float FFloorLevel;
	Stage::Vectorgeometry::TAffineVector FNormal;
	
protected:
	void __fastcall SetNormal(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TgxVerletFloor(TgxVerletWorld* const aOwner);
	virtual void __fastcall PerformSpaceQuery();
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property float BounceRatio = {read=FBounceRatio, write=FBounceRatio};
	__property float FloorLevel = {read=FFloorLevel, write=FFloorLevel};
	__property Stage::Vectorgeometry::TAffineVector Normal = {read=FNormal, write=SetNormal};
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletFloor() { }
	
};

#pragma pack(pop)

typedef float __fastcall (__closure *TgxVerletHeightFieldOnNeedHeight)(TgxVerletHeightField* hfConstraint, TgxBaseVerletNode* node);

class PASCALIMPLEMENTATION TgxVerletHeightField : public TgxVerletFloor
{
	typedef TgxVerletFloor inherited;
	
private:
	TgxVerletHeightFieldOnNeedHeight FOnNeedHeight;
	
public:
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property TgxVerletHeightFieldOnNeedHeight OnNeedHeight = {read=FOnNeedHeight, write=FOnNeedHeight};
public:
	/* TgxVerletFloor.Create */ inline __fastcall virtual TgxVerletHeightField(TgxVerletWorld* const aOwner) : TgxVerletFloor(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletHeightField() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletStick : public TgxVerletDualConstraint
{
	typedef TgxVerletDualConstraint inherited;
	
private:
	float FSlack;
	float FRestLength;
	
public:
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	void __fastcall SetRestLengthToCurrent();
	__property float Slack = {read=FSlack, write=FSlack};
	__property float RestLength = {read=FRestLength, write=FRestLength};
public:
	/* TgxVerletConstraint.Create */ inline __fastcall virtual TgxVerletStick(TgxVerletWorld* const aOwner) : TgxVerletDualConstraint(aOwner) { }
	/* TgxVerletConstraint.Destroy */ inline __fastcall virtual ~TgxVerletStick() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletRigidBody : public TgxVerletGroupConstraint
{
	typedef TgxVerletGroupConstraint inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TgxVerletRigidBody__1;
	
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TgxVerletRigidBody__2;
	
	
private:
	_TgxVerletRigidBody__1 FNodeParams;
	_TgxVerletRigidBody__2 FNodeCoords;
	Stage::Vectorgeometry::TAffineMatrix FNatMatrix;
	Stage::Vectorgeometry::TAffineMatrix FInvNatMatrix;
	
protected:
	void __fastcall ComputeBarycenter(Stage::Vectorgeometry::TAffineVector &barycenter);
	void __fastcall ComputeNaturals(const Stage::Vectorgeometry::TAffineVector &barycenter, Stage::Vectorgeometry::TAffineVector &natX, Stage::Vectorgeometry::TAffineVector &natY, Stage::Vectorgeometry::TAffineVector &natZ);
	
public:
	void __fastcall ComputeRigidityParameters();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
public:
	/* TgxVerletGroupConstraint.Create */ inline __fastcall virtual TgxVerletRigidBody(TgxVerletWorld* const aOwner) : TgxVerletGroupConstraint(aOwner) { }
	/* TgxVerletGroupConstraint.Destroy */ inline __fastcall virtual ~TgxVerletRigidBody() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletSlider : public TgxVerletDualConstraint
{
	typedef TgxVerletDualConstraint inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FSlideDirection;
	bool FConstrained;
	
protected:
	void __fastcall SetSlideDirection(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector SlideDirection = {read=FSlideDirection, write=SetSlideDirection};
	__property bool Constrained = {read=FConstrained, write=FConstrained, nodefault};
public:
	/* TgxVerletConstraint.Create */ inline __fastcall virtual TgxVerletSlider(TgxVerletWorld* const aOwner) : TgxVerletDualConstraint(aOwner) { }
	/* TgxVerletConstraint.Destroy */ inline __fastcall virtual ~TgxVerletSlider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletFrictionSphere : public TgxVerletGlobalFrictionConstraintSphere
{
	typedef TgxVerletGlobalFrictionConstraintSphere inherited;
	
private:
	float FRadius;
	
public:
	virtual Gxs::Geometrybb::TBSphere __fastcall GetBSphere();
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TgxVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property float Radius = {read=FRadius, write=FRadius};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletFrictionSphere(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraintSphere(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletFrictionSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletFrictionCylinder : public TgxVerletGlobalFrictionConstraint
{
	typedef TgxVerletGlobalFrictionConstraint inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FAxis;
	float FRadius;
	float FRadius2;
	
protected:
	void __fastcall SetRadius(const float val);
	
public:
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis, write=FAxis};
	__property float Radius = {read=FRadius, write=SetRadius};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletFrictionCylinder(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraint(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletFrictionCylinder() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletFrictionCube : public TgxVerletGlobalFrictionConstraintBox
{
	typedef TgxVerletGlobalFrictionConstraintBox inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FHalfSides;
	Stage::Vectorgeometry::TAffineVector FSides;
	Stage::Vectorgeometry::TAffineVector FDirection;
	void __fastcall SetSides(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	virtual Gxs::Geometrybb::TAABB __fastcall GetAABB();
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TgxVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Direction = {read=FDirection, write=FDirection};
	__property Stage::Vectorgeometry::TAffineVector Sides = {read=FSides, write=SetSides};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletFrictionCube(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraintBox(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletFrictionCube() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletFrictionCapsule : public TgxVerletGlobalFrictionConstraintSphere
{
	typedef TgxVerletGlobalFrictionConstraintSphere inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FAxis;
	float FRadius;
	float FRadius2;
	float FLength;
	float FLengthDiv2;
	
protected:
	void __fastcall SetAxis(const Stage::Vectorgeometry::TAffineVector &val);
	void __fastcall SetRadius(const float val);
	void __fastcall SetLength(const float val);
	
public:
	virtual Gxs::Geometrybb::TBSphere __fastcall GetBSphere();
	virtual void __fastcall SatisfyConstraintForNode(TgxBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TgxVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis, write=SetAxis};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TgxVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TgxVerletFrictionCapsule(TgxVerletWorld* const aOwner) : TgxVerletGlobalFrictionConstraintSphere(aOwner) { }
	
public:
	/* TgxVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TgxVerletFrictionCapsule() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletNode : public TgxBaseVerletNode
{
	typedef TgxBaseVerletNode inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FRelativePosition;
	Gxs::Scene::TgxBaseSceneObject* FGXBaseSceneObject;
	void __fastcall SetBaseSceneObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	virtual void __fastcall Verlet(const Gxs::Baseclasses::TgxProgressTimes &vpt);
	__property Gxs::Scene::TgxBaseSceneObject* GXBaseSceneObject = {read=FGXBaseSceneObject, write=SetBaseSceneObject};
	__property Stage::Vectorgeometry::TAffineVector RelativePosition = {read=FRelativePosition, write=FRelativePosition};
public:
	/* TgxBaseVerletNode.CreateOwned */ inline __fastcall virtual TgxVerletNode(TgxVerletWorld* const aOwner) : TgxBaseVerletNode(aOwner) { }
	/* TgxBaseVerletNode.Destroy */ inline __fastcall virtual ~TgxVerletNode() { }
	
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxVerletNode() : TgxBaseVerletNode() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVerletNode(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxBaseVerletNode(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletHair : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxVerletNodeList* FNodeList;
	int FLinkCount;
	float FRootDepth;
	TgxVerletWorld* FVerletWorld;
	float FHairLength;
	void *FData;
	TgxStiffnessSetVH FStiffness;
	System::Classes::TList* FStiffnessList;
	TgxBaseVerletNode* __fastcall GetAnchor();
	TgxBaseVerletNode* __fastcall GetRoot();
	float __fastcall GetLinkLength();
	void __fastcall AddStickStiffness(const int ANodeSkip);
	void __fastcall SetStiffness(const TgxStiffnessSetVH Value);
	
public:
	void __fastcall BuildHair(const Stage::Vectorgeometry::TAffineVector &AAnchorPosition, const Stage::Vectorgeometry::TAffineVector &AHairDirection);
	void __fastcall BuildStiffness();
	void __fastcall ClearStiffness();
	void __fastcall Clear();
	__fastcall TgxVerletHair(TgxVerletWorld* const AVerletWorld, const float ARootDepth, const float AHairLength, int ALinkCount, const Stage::Vectorgeometry::TAffineVector &AAnchorPosition, const Stage::Vectorgeometry::TAffineVector &AHairDirection, const TgxStiffnessSetVH AStiffness);
	__fastcall virtual ~TgxVerletHair();
	__property TgxVerletNodeList* NodeList = {read=FNodeList};
	__property TgxVerletWorld* VerletWorld = {read=FVerletWorld};
	__property float RootDepth = {read=FRootDepth};
	__property float LinkLength = {read=GetLinkLength};
	__property int LinkCount = {read=FLinkCount, nodefault};
	__property float HairLength = {read=FHairLength};
	__property TgxStiffnessSetVH Stiffness = {read=FStiffness, write=SetStiffness, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property TgxBaseVerletNode* Anchor = {read=GetAnchor};
	__property TgxBaseVerletNode* Root = {read=GetRoot};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletSkeletonCollider : public Gxs::Vectorfileobjects::TgxSkeletonCollider
{
	typedef Gxs::Vectorfileobjects::TgxSkeletonCollider inherited;
	
private:
	TgxVerletConstraint* FVerletConstraint;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TgxVerletWorld* VerletWorld);
	__property TgxVerletConstraint* VerletConstraint = {read=FVerletConstraint};
public:
	/* TgxSkeletonCollider.Create */ inline __fastcall virtual TgxVerletSkeletonCollider() : Gxs::Vectorfileobjects::TgxSkeletonCollider() { }
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TgxVerletSkeletonCollider(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : Gxs::Vectorfileobjects::TgxSkeletonCollider(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVerletSkeletonCollider(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxSkeletonCollider(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxVerletSkeletonCollider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletSphere : public TgxVerletSkeletonCollider
{
	typedef TgxVerletSkeletonCollider inherited;
	
private:
	float FRadius;
	
protected:
	void __fastcall SetRadius(const float Val);
	
public:
	__fastcall virtual TgxVerletSphere();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TgxVerletWorld* VerletWorld);
	virtual void __fastcall AlignCollider();
	__property float Radius = {read=FRadius, write=SetRadius};
public:
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TgxVerletSphere(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : TgxVerletSkeletonCollider(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVerletSphere(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxVerletSkeletonCollider(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxVerletSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVerletCapsule : public TgxVerletSkeletonCollider
{
	typedef TgxVerletSkeletonCollider inherited;
	
private:
	float FRadius;
	float FLength;
	
protected:
	void __fastcall SetRadius(const float Val);
	void __fastcall SetLength(const float Val);
	
public:
	__fastcall virtual TgxVerletCapsule();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TgxVerletWorld* VerletWorld);
	virtual void __fastcall AlignCollider();
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TgxVerletCapsule(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : TgxVerletSkeletonCollider(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVerletCapsule(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxVerletSkeletonCollider(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxVerletCapsule() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define G_DRAG  (1.000000E-04)
#define cDEFAULT_CONSTRAINT_FRICTION  (6.000000E-01)
extern DELPHI_PACKAGE TgxVerletFloor* __fastcall CreateVerletPlaneFromGLPlane(Gxs::Objects::TgxPlane* Plane, TgxVerletWorld* VerletWorld, float Offset);
extern DELPHI_PACKAGE void __fastcall AddVerletConstriantsToVerletWorld(Gxs::Vectorfileobjects::TgxSkeletonColliderList* Colliders, TgxVerletWorld* World);
}	/* namespace Verlettypes */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_VERLETTYPES)
using namespace Gxs::Verlettypes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_VerletTypesHPP
