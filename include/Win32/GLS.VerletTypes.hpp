// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.VerletTypes.pas' rev: 36.00 (Windows)

#ifndef GLS_VerletTypesHPP
#define GLS_VerletTypesHPP

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
#include <GLS.PersistentClasses.hpp>
#include <GLS.BaseClasses.hpp>
#include <GLS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.GeometryBB.hpp>
#include <GLS.Objects.hpp>
#include <GLS.Scene.hpp>
#include <GLS.SpacePartition.hpp>
#include <GLS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Verlettypes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLBaseVerletNode;
class DELPHICLASS TGLVerletNodeList;
class DELPHICLASS TGLVerletConstraint;
class DELPHICLASS TGLVerletDualConstraint;
class DELPHICLASS TGLVerletGroupConstraint;
class DELPHICLASS TGLVerletEdge;
class DELPHICLASS TGLVerletEdgeList;
class DELPHICLASS TGLVerletGlobalConstraint;
class DELPHICLASS TGLVerletGlobalFrictionConstraint;
class DELPHICLASS TGLVerletGlobalFrictionConstraintSP;
class DELPHICLASS TGLVerletGlobalFrictionConstraintSphere;
class DELPHICLASS TGLVerletGlobalFrictionConstraintBox;
class DELPHICLASS TGLVerletConstraintList;
class DELPHICLASS TGLVerletForce;
class DELPHICLASS TGLVerletDualForce;
class DELPHICLASS TGLVerletGroupForce;
class DELPHICLASS TGLVerletGlobalForce;
class DELPHICLASS TGLVerletForceList;
class DELPHICLASS TGLVerletWorld;
class DELPHICLASS TGLVerletGravity;
class DELPHICLASS TGLVerletAirResistance;
class DELPHICLASS TGLVerletSpring;
class DELPHICLASS TGLVerletFloor;
class DELPHICLASS TGLVerletHeightField;
class DELPHICLASS TGLVerletStick;
class DELPHICLASS TGLVerletRigidBody;
class DELPHICLASS TGLVerletSlider;
class DELPHICLASS TGLVerletFrictionSphere;
class DELPHICLASS TGLVerletFrictionCylinder;
class DELPHICLASS TGLVerletFrictionCube;
class DELPHICLASS TGLVerletFrictionCapsule;
class DELPHICLASS TGLVerletNode;
class DELPHICLASS TGLVerletHair;
class DELPHICLASS TGLVerletSkeletonCollider;
class DELPHICLASS TGLVerletSphere;
class DELPHICLASS TGLVerletCapsule;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLStiffnessVH : unsigned char { vhsFull, vhsSkip1Node, vhsSkip2Node, vhsSkip3Node, vhsSkip4Node, vhsSkip5Node, vhsSkip6Node, vhsSkip7Node, vhsSkip8Node, vhsSkip9Node };

typedef System::Set<TGLStiffnessVH, TGLStiffnessVH::vhsFull, TGLStiffnessVH::vhsSkip9Node> TGLStiffnessSetVH;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseVerletNode : public Gls::Spacepartition::TGLSpacePartitionLeaf
{
	typedef Gls::Spacepartition::TGLSpacePartitionLeaf inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FForce;
	TGLVerletWorld* FOwner;
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
	__fastcall virtual TGLBaseVerletNode(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLBaseVerletNode();
	void __fastcall ApplyFriction(const float friction, const float penetrationDepth, const Stage::Vectorgeometry::TAffineVector &surfaceNormal);
	void __fastcall OldApplyFriction(const float friction, const float penetrationDepth);
	virtual void __fastcall Verlet(const Gls::Baseclasses::TGLProgressTimes &vpt);
	DYNAMIC void __fastcall Initialize();
	float __fastcall DistanceToNode(TGLBaseVerletNode* const node);
	Stage::Vectorgeometry::TAffineVector __fastcall GetMovement();
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__property TGLVerletWorld* Owner = {read=FOwner};
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
	/* TGLPersistentObject.Create */ inline __fastcall virtual TGLBaseVerletNode() : Gls::Spacepartition::TGLSpacePartitionLeaf() { }
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLBaseVerletNode(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Spacepartition::TGLSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGLVerletNodeClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletNodeList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TGLBaseVerletNode* operator[](int i) { return this->Items[i]; }
	
private:
	TGLBaseVerletNode* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TGLBaseVerletNode* const Value);
	
public:
	__property TGLBaseVerletNode* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TGLVerletNodeList() { }
	
public:
	/* TObject.Create */ inline __fastcall TGLVerletNodeList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletConstraint : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLVerletWorld* FOwner;
	bool FEnabled;
	int FTag;
	
public:
	__fastcall virtual TGLVerletConstraint(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLVerletConstraint();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations) = 0 ;
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode) = 0 ;
	virtual void __fastcall BeforeIterations();
	__property TGLVerletWorld* Owner = {read=FOwner};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletDualConstraint : public TGLVerletConstraint
{
	typedef TGLVerletConstraint inherited;
	
private:
	TGLBaseVerletNode* FNodeA;
	TGLBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	__property TGLBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TGLBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TGLVerletConstraint.Create */ inline __fastcall virtual TGLVerletDualConstraint(TGLVerletWorld* const aOwner) : TGLVerletConstraint(aOwner) { }
	/* TGLVerletConstraint.Destroy */ inline __fastcall virtual ~TGLVerletDualConstraint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGroupConstraint : public TGLVerletConstraint
{
	typedef TGLVerletConstraint inherited;
	
private:
	TGLVerletNodeList* FNodes;
	
public:
	__fastcall virtual TGLVerletGroupConstraint(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLVerletGroupConstraint();
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	__property TGLVerletNodeList* Nodes = {read=FNodes};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletEdge : public Gls::Spacepartition::TGLSpacePartitionLeaf
{
	typedef Gls::Spacepartition::TGLSpacePartitionLeaf inherited;
	
private:
	TGLBaseVerletNode* FNodeA;
	TGLBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__fastcall TGLVerletEdge(TGLBaseVerletNode* const aNodeA, TGLBaseVerletNode* const aNodeB);
	__property TGLBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TGLBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TGLSpacePartitionLeaf.CreateOwned */ inline __fastcall TGLVerletEdge(Gls::Spacepartition::TGLBaseSpacePartition* SpacePartition) : Gls::Spacepartition::TGLSpacePartitionLeaf(SpacePartition) { }
	/* TGLSpacePartitionLeaf.Destroy */ inline __fastcall virtual ~TGLVerletEdge() { }
	
public:
	/* TGLPersistentObject.Create */ inline __fastcall virtual TGLVerletEdge() : Gls::Spacepartition::TGLSpacePartitionLeaf() { }
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVerletEdge(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Spacepartition::TGLSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletEdgeList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TGLVerletEdge* operator[](int i) { return this->Items[i]; }
	
private:
	TGLVerletEdge* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TGLVerletEdge* const Value);
	
public:
	__property TGLVerletEdge* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TGLVerletEdgeList() { }
	
public:
	/* TObject.Create */ inline __fastcall TGLVerletEdgeList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalConstraint : public TGLVerletConstraint
{
	typedef TGLVerletConstraint inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FKickbackForce;
	Stage::Vectorgeometry::TAffineVector FKickbackTorque;
	Stage::Vectorgeometry::TAffineVector FLocation;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TGLVerletGlobalConstraint(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLVerletGlobalConstraint();
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	virtual void __fastcall BeforeIterations();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations) = 0 ;
	virtual void __fastcall SatisfyConstraintForEdge(TGLVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Location = {read=FLocation, write=SetLocation};
	__property Stage::Vectorgeometry::TAffineVector KickbackForce = {read=FKickbackForce, write=FKickbackForce};
	__property Stage::Vectorgeometry::TAffineVector KickbackTorque = {read=FKickbackTorque, write=FKickbackTorque};
	void __fastcall AddKickbackForceAt(const Stage::Vectorgeometry::TAffineVector &Pos, const Stage::Vectorgeometry::TAffineVector &Force);
	Stage::Vectorgeometry::TAffineVector __fastcall TranslateKickbackTorque(const Stage::Vectorgeometry::TAffineVector &TorqueCenter);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalFrictionConstraint : public TGLVerletGlobalConstraint
{
	typedef TGLVerletGlobalConstraint inherited;
	
private:
	float FFrictionRatio;
	
public:
	__fastcall virtual TGLVerletGlobalFrictionConstraint(TGLVerletWorld* const aOwner);
	__property float FrictionRatio = {read=FFrictionRatio, write=FFrictionRatio};
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletGlobalFrictionConstraint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalFrictionConstraintSP : public TGLVerletGlobalFrictionConstraint
{
	typedef TGLVerletGlobalFrictionConstraint inherited;
	
public:
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	virtual void __fastcall PerformSpaceQuery() = 0 ;
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletGlobalFrictionConstraintSP(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraint(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletGlobalFrictionConstraintSP() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalFrictionConstraintSphere : public TGLVerletGlobalFrictionConstraintSP
{
	typedef TGLVerletGlobalFrictionConstraintSP inherited;
	
private:
	Gls::Geometrybb::TBSphere FCachedBSphere;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	void __fastcall UpdateCachedBSphere();
	virtual void __fastcall PerformSpaceQuery();
	virtual Gls::Geometrybb::TBSphere __fastcall GetBSphere() = 0 ;
	__property Gls::Geometrybb::TBSphere CachedBSphere = {read=FCachedBSphere};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletGlobalFrictionConstraintSphere(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraintSP(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletGlobalFrictionConstraintSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalFrictionConstraintBox : public TGLVerletGlobalFrictionConstraintSP
{
	typedef TGLVerletGlobalFrictionConstraintSP inherited;
	
private:
	Gls::Geometrybb::TAABB FCachedAABB;
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	void __fastcall UpdateCachedAABB();
	virtual void __fastcall PerformSpaceQuery();
	virtual Gls::Geometrybb::TAABB __fastcall GetAABB() = 0 ;
	__property Gls::Geometrybb::TAABB CachedAABB = {read=FCachedAABB};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletGlobalFrictionConstraintBox(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraintSP(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletGlobalFrictionConstraintBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletConstraintList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TGLVerletConstraint* operator[](int i) { return this->Items[i]; }
	
private:
	TGLVerletConstraint* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TGLVerletConstraint* const Value);
	
public:
	__property TGLVerletConstraint* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TGLVerletConstraintList() { }
	
public:
	/* TObject.Create */ inline __fastcall TGLVerletConstraintList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletForce : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLVerletWorld* FOwner;
	
public:
	__fastcall virtual TGLVerletForce(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLVerletForce();
	virtual void __fastcall AddForce(const Gls::Baseclasses::TGLProgressTimes &vpt) = 0 ;
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode) = 0 ;
	__property TGLVerletWorld* Owner = {read=FOwner};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletDualForce : public TGLVerletForce
{
	typedef TGLVerletForce inherited;
	
private:
	TGLBaseVerletNode* FNodeA;
	TGLBaseVerletNode* FNodeB;
	
public:
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	__property TGLBaseVerletNode* NodeA = {read=FNodeA, write=FNodeA};
	__property TGLBaseVerletNode* NodeB = {read=FNodeB, write=FNodeB};
public:
	/* TGLVerletForce.Create */ inline __fastcall virtual TGLVerletDualForce(TGLVerletWorld* const aOwner) : TGLVerletForce(aOwner) { }
	/* TGLVerletForce.Destroy */ inline __fastcall virtual ~TGLVerletDualForce() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGroupForce : public TGLVerletForce
{
	typedef TGLVerletForce inherited;
	
private:
	TGLVerletNodeList* FNodes;
	
public:
	__fastcall virtual TGLVerletGroupForce(TGLVerletWorld* const aOwner);
	__fastcall virtual ~TGLVerletGroupForce();
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	__property TGLVerletNodeList* Nodes = {read=FNodes};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGlobalForce : public TGLVerletForce
{
	typedef TGLVerletForce inherited;
	
public:
	virtual void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	virtual void __fastcall AddForce(const Gls::Baseclasses::TGLProgressTimes &vpt);
	virtual void __fastcall AddForceToNode(TGLBaseVerletNode* const aNode) = 0 ;
public:
	/* TGLVerletForce.Create */ inline __fastcall virtual TGLVerletGlobalForce(TGLVerletWorld* const aOwner) : TGLVerletForce(aOwner) { }
	/* TGLVerletForce.Destroy */ inline __fastcall virtual ~TGLVerletGlobalForce() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletForceList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TGLVerletForce* operator[](int i) { return this->Items[i]; }
	
private:
	TGLVerletForce* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TGLVerletForce* const Value);
	
public:
	__property TGLVerletForce* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TGLVerletForceList() { }
	
public:
	/* TObject.Create */ inline __fastcall TGLVerletForceList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TUpdateSpacePartion : unsigned char { uspEveryIteration, uspEveryFrame, uspNever };

enum DECLSPEC_DENUM TCollisionConstraintTypes : unsigned char { cctEdge, cctNode };

typedef System::Set<TCollisionConstraintTypes, TCollisionConstraintTypes::cctEdge, TCollisionConstraintTypes::cctNode> TCollisionConstraintTypesSet;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletWorld : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIterations;
	TGLVerletNodeList* FNodes;
	TGLVerletConstraintList* FConstraints;
	TGLVerletForceList* FForces;
	float FMaxDeltaTime;
	float FSimTime;
	float FDrag;
	float FCurrentDeltaTime;
	float FInvCurrentDeltaTime;
	TGLVerletEdgeList* FSolidEdges;
	Gls::Spacepartition::TGLBaseSpacePartition* FSpacePartition;
	int FCurrentStepCount;
	TUpdateSpacePartion FUpdateSpacePartion;
	TCollisionConstraintTypesSet FCollisionConstraintTypes;
	TGLVerletConstraintList* FConstraintsWithBeforeIterations;
	TGLVerletNodeClass FVerletNodeClass;
	bool FInertia;
	int FInertaPauseSteps;
	
protected:
	virtual void __fastcall AccumulateForces(const Gls::Baseclasses::TGLProgressTimes &vpt);
	virtual void __fastcall Verlet(const Gls::Baseclasses::TGLProgressTimes &vpt);
	virtual void __fastcall SatisfyConstraints(const Gls::Baseclasses::TGLProgressTimes &vpt);
	void __fastcall DoUpdateSpacePartition();
	
public:
	__fastcall virtual TGLVerletWorld();
	__fastcall virtual ~TGLVerletWorld();
	int __fastcall AddNode(TGLBaseVerletNode* const aNode);
	void __fastcall RemoveNode(TGLBaseVerletNode* const aNode);
	int __fastcall AddConstraint(TGLVerletConstraint* const aConstraint);
	void __fastcall RemoveConstraint(TGLVerletConstraint* const aConstraint);
	int __fastcall AddForce(TGLVerletForce* const aForce);
	void __fastcall RemoveForce(TGLVerletForce* const aForce);
	void __fastcall AddSolidEdge(TGLBaseVerletNode* const aNodeA, TGLBaseVerletNode* const aNodeB);
	void __fastcall PauseInertia(const int IterationSteps);
	TGLBaseVerletNode* __fastcall CreateOwnedNode(const Stage::Vectorgeometry::TAffineVector &Location, const float aRadius = 0.000000E+00f, const float aWeight = 1.000000E+00f);
	TGLVerletStick* __fastcall CreateStick(TGLBaseVerletNode* const aNodeA, TGLBaseVerletNode* const aNodeB, const float Slack = 0.000000E+00f);
	TGLVerletSpring* __fastcall CreateSpring(TGLBaseVerletNode* const aNodeA, TGLBaseVerletNode* const aNodeB, const float aStrength, const float aDamping, const float aSlack = 0.000000E+00f);
	TGLVerletSlider* __fastcall CreateSlider(TGLBaseVerletNode* const aNodeA, TGLBaseVerletNode* const aNodeB, const Stage::Vectorgeometry::TAffineVector &aSlideDirection);
	virtual void __fastcall Initialize();
	void __fastcall CreateOctree(const Stage::Vectorgeometry::TAffineVector &OctreeMin, const Stage::Vectorgeometry::TAffineVector &OctreeMax, const int LeafThreshold, const int MaxTreeDepth);
	virtual int __fastcall Progress(const double deltaTime, const double newTime);
	TGLBaseVerletNode* __fastcall FirstNode();
	TGLBaseVerletNode* __fastcall LastNode();
	__property float Drag = {read=FDrag, write=FDrag};
	__property int Iterations = {read=FIterations, write=FIterations, nodefault};
	__property TGLVerletNodeList* Nodes = {read=FNodes};
	__property TGLVerletConstraintList* Constraints = {read=FConstraints};
	__property TGLVerletConstraintList* ConstraintsWithBeforeIterations = {read=FConstraintsWithBeforeIterations};
	__property float SimTime = {read=FSimTime, write=FSimTime};
	__property float MaxDeltaTime = {read=FMaxDeltaTime, write=FMaxDeltaTime};
	__property float CurrentDeltaTime = {read=FCurrentDeltaTime};
	__property TGLVerletEdgeList* SolidEdges = {read=FSolidEdges, write=FSolidEdges};
	__property int CurrentStepCount = {read=FCurrentStepCount, nodefault};
	__property Gls::Spacepartition::TGLBaseSpacePartition* SpacePartition = {read=FSpacePartition};
	__property TUpdateSpacePartion UpdateSpacePartion = {read=FUpdateSpacePartion, write=FUpdateSpacePartion, nodefault};
	__property TCollisionConstraintTypesSet CollisionConstraintTypes = {read=FCollisionConstraintTypes, write=FCollisionConstraintTypes, nodefault};
	__property TGLVerletNodeClass VerletNodeClass = {read=FVerletNodeClass, write=FVerletNodeClass};
	__property bool Inertia = {read=FInertia, write=FInertia, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletGravity : public TGLVerletGlobalForce
{
	typedef TGLVerletGlobalForce inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FGravity;
	
public:
	__fastcall virtual TGLVerletGravity(TGLVerletWorld* const aOwner);
	virtual void __fastcall AddForceToNode(TGLBaseVerletNode* const aNode);
	__property Stage::Vectorgeometry::TAffineVector Gravity = {read=FGravity, write=FGravity};
public:
	/* TGLVerletForce.Destroy */ inline __fastcall virtual ~TGLVerletGravity() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletAirResistance : public TGLVerletGlobalForce
{
	typedef TGLVerletGlobalForce inherited;
	
private:
	float FDragCoeff;
	Stage::Vectorgeometry::TAffineVector FWindDirection;
	float FWindMagnitude;
	float FWindChaos;
	void __fastcall SetWindDirection(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TGLVerletAirResistance(TGLVerletWorld* const aOwner);
	virtual void __fastcall AddForceToNode(TGLBaseVerletNode* const aNode);
	__property float DragCoeff = {read=FDragCoeff, write=FDragCoeff};
	__property Stage::Vectorgeometry::TAffineVector WindDirection = {read=FWindDirection, write=SetWindDirection};
	__property float WindMagnitude = {read=FWindMagnitude, write=FWindMagnitude};
	__property float WindChaos = {read=FWindChaos, write=FWindChaos};
public:
	/* TGLVerletForce.Destroy */ inline __fastcall virtual ~TGLVerletAirResistance() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletSpring : public TGLVerletDualForce
{
	typedef TGLVerletDualForce inherited;
	
private:
	float FRestLength;
	float FStrength;
	float FDamping;
	float FSlack;
	float FForceFactor;
	
protected:
	void __fastcall SetSlack(const float Value);
	
public:
	virtual void __fastcall AddForce(const Gls::Baseclasses::TGLProgressTimes &vpt);
	void __fastcall SetRestLengthToCurrent();
	__property float Strength = {read=FStrength, write=FStrength};
	__property float Damping = {read=FDamping, write=FDamping};
	__property float Slack = {read=FSlack, write=SetSlack};
public:
	/* TGLVerletForce.Create */ inline __fastcall virtual TGLVerletSpring(TGLVerletWorld* const aOwner) : TGLVerletDualForce(aOwner) { }
	/* TGLVerletForce.Destroy */ inline __fastcall virtual ~TGLVerletSpring() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletFloor : public TGLVerletGlobalFrictionConstraintSP
{
	typedef TGLVerletGlobalFrictionConstraintSP inherited;
	
private:
	float FBounceRatio;
	float FFloorLevel;
	Stage::Vectorgeometry::TAffineVector FNormal;
	
protected:
	void __fastcall SetNormal(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	__fastcall virtual TGLVerletFloor(TGLVerletWorld* const aOwner);
	virtual void __fastcall PerformSpaceQuery();
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property float BounceRatio = {read=FBounceRatio, write=FBounceRatio};
	__property float FloorLevel = {read=FFloorLevel, write=FFloorLevel};
	__property Stage::Vectorgeometry::TAffineVector Normal = {read=FNormal, write=SetNormal};
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletFloor() { }
	
};

#pragma pack(pop)

typedef float __fastcall (__closure *TGLVerletHeightFieldOnNeedHeight)(TGLVerletHeightField* hfConstraint, TGLBaseVerletNode* node);

class PASCALIMPLEMENTATION TGLVerletHeightField : public TGLVerletFloor
{
	typedef TGLVerletFloor inherited;
	
private:
	TGLVerletHeightFieldOnNeedHeight FOnNeedHeight;
	
public:
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property TGLVerletHeightFieldOnNeedHeight OnNeedHeight = {read=FOnNeedHeight, write=FOnNeedHeight};
public:
	/* TGLVerletFloor.Create */ inline __fastcall virtual TGLVerletHeightField(TGLVerletWorld* const aOwner) : TGLVerletFloor(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletHeightField() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletStick : public TGLVerletDualConstraint
{
	typedef TGLVerletDualConstraint inherited;
	
private:
	float FSlack;
	float FRestLength;
	
public:
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
	void __fastcall SetRestLengthToCurrent();
	__property float Slack = {read=FSlack, write=FSlack};
	__property float RestLength = {read=FRestLength, write=FRestLength};
public:
	/* TGLVerletConstraint.Create */ inline __fastcall virtual TGLVerletStick(TGLVerletWorld* const aOwner) : TGLVerletDualConstraint(aOwner) { }
	/* TGLVerletConstraint.Destroy */ inline __fastcall virtual ~TGLVerletStick() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletRigidBody : public TGLVerletGroupConstraint
{
	typedef TGLVerletGroupConstraint inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TGLVerletRigidBody__1;
	
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TGLVerletRigidBody__2;
	
	
private:
	_TGLVerletRigidBody__1 FNodeParams;
	_TGLVerletRigidBody__2 FNodeCoords;
	Stage::Vectorgeometry::TAffineMatrix FNatMatrix;
	Stage::Vectorgeometry::TAffineMatrix FInvNatMatrix;
	
protected:
	void __fastcall ComputeBarycenter(Stage::Vectorgeometry::TAffineVector &barycenter);
	void __fastcall ComputeNaturals(const Stage::Vectorgeometry::TAffineVector &barycenter, Stage::Vectorgeometry::TAffineVector &natX, Stage::Vectorgeometry::TAffineVector &natY, Stage::Vectorgeometry::TAffineVector &natZ);
	
public:
	void __fastcall ComputeRigidityParameters();
	virtual void __fastcall SatisfyConstraint(const int iteration, const int maxIterations);
public:
	/* TGLVerletGroupConstraint.Create */ inline __fastcall virtual TGLVerletRigidBody(TGLVerletWorld* const aOwner) : TGLVerletGroupConstraint(aOwner) { }
	/* TGLVerletGroupConstraint.Destroy */ inline __fastcall virtual ~TGLVerletRigidBody() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletSlider : public TGLVerletDualConstraint
{
	typedef TGLVerletDualConstraint inherited;
	
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
	/* TGLVerletConstraint.Create */ inline __fastcall virtual TGLVerletSlider(TGLVerletWorld* const aOwner) : TGLVerletDualConstraint(aOwner) { }
	/* TGLVerletConstraint.Destroy */ inline __fastcall virtual ~TGLVerletSlider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletFrictionSphere : public TGLVerletGlobalFrictionConstraintSphere
{
	typedef TGLVerletGlobalFrictionConstraintSphere inherited;
	
private:
	float FRadius;
	
public:
	virtual Gls::Geometrybb::TBSphere __fastcall GetBSphere();
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TGLVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property float Radius = {read=FRadius, write=FRadius};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletFrictionSphere(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraintSphere(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletFrictionSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletFrictionCylinder : public TGLVerletGlobalFrictionConstraint
{
	typedef TGLVerletGlobalFrictionConstraint inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FAxis;
	float FRadius;
	float FRadius2;
	
protected:
	void __fastcall SetRadius(const float val);
	
public:
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis, write=FAxis};
	__property float Radius = {read=FRadius, write=SetRadius};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletFrictionCylinder(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraint(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletFrictionCylinder() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletFrictionCube : public TGLVerletGlobalFrictionConstraintBox
{
	typedef TGLVerletGlobalFrictionConstraintBox inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FHalfSides;
	Stage::Vectorgeometry::TAffineVector FSides;
	Stage::Vectorgeometry::TAffineVector FDirection;
	void __fastcall SetSides(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	virtual Gls::Geometrybb::TAABB __fastcall GetAABB();
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TGLVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Direction = {read=FDirection, write=FDirection};
	__property Stage::Vectorgeometry::TAffineVector Sides = {read=FSides, write=SetSides};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletFrictionCube(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraintBox(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletFrictionCube() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletFrictionCapsule : public TGLVerletGlobalFrictionConstraintSphere
{
	typedef TGLVerletGlobalFrictionConstraintSphere inherited;
	
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
	virtual Gls::Geometrybb::TBSphere __fastcall GetBSphere();
	virtual void __fastcall SatisfyConstraintForNode(TGLBaseVerletNode* const aNode, const int iteration, const int maxIterations);
	virtual void __fastcall SatisfyConstraintForEdge(TGLVerletEdge* const aEdge, const int iteration, const int maxIterations);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis, write=SetAxis};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TGLVerletGlobalFrictionConstraint.Create */ inline __fastcall virtual TGLVerletFrictionCapsule(TGLVerletWorld* const aOwner) : TGLVerletGlobalFrictionConstraintSphere(aOwner) { }
	
public:
	/* TGLVerletGlobalConstraint.Destroy */ inline __fastcall virtual ~TGLVerletFrictionCapsule() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletNode : public TGLBaseVerletNode
{
	typedef TGLBaseVerletNode inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FRelativePosition;
	Gls::Scene::TGLBaseSceneObject* FGLBaseSceneObject;
	void __fastcall SetGLBaseSceneObject(Gls::Scene::TGLBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall SetLocation(const Stage::Vectorgeometry::TAffineVector &Value);
	
public:
	virtual void __fastcall Verlet(const Gls::Baseclasses::TGLProgressTimes &vpt);
	__property Gls::Scene::TGLBaseSceneObject* GLBaseSceneObject = {read=FGLBaseSceneObject, write=SetGLBaseSceneObject};
	__property Stage::Vectorgeometry::TAffineVector RelativePosition = {read=FRelativePosition, write=FRelativePosition};
public:
	/* TGLBaseVerletNode.CreateOwned */ inline __fastcall virtual TGLVerletNode(TGLVerletWorld* const aOwner) : TGLBaseVerletNode(aOwner) { }
	/* TGLBaseVerletNode.Destroy */ inline __fastcall virtual ~TGLVerletNode() { }
	
public:
	/* TGLPersistentObject.Create */ inline __fastcall virtual TGLVerletNode() : TGLBaseVerletNode() { }
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVerletNode(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseVerletNode(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletHair : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLVerletNodeList* FNodeList;
	int FLinkCount;
	float FRootDepth;
	TGLVerletWorld* FVerletWorld;
	float FHairLength;
	void *FData;
	TGLStiffnessSetVH FStiffness;
	System::Classes::TList* FStiffnessList;
	TGLBaseVerletNode* __fastcall GetAnchor();
	TGLBaseVerletNode* __fastcall GetRoot();
	float __fastcall GetLinkLength();
	void __fastcall AddStickStiffness(const int ANodeSkip);
	void __fastcall SetStiffness(const TGLStiffnessSetVH Value);
	
public:
	void __fastcall BuildHair(const Stage::Vectorgeometry::TAffineVector &AAnchorPosition, const Stage::Vectorgeometry::TAffineVector &AHairDirection);
	void __fastcall BuildStiffness();
	void __fastcall ClearStiffness();
	void __fastcall Clear();
	__fastcall TGLVerletHair(TGLVerletWorld* const AVerletWorld, const float ARootDepth, const float AHairLength, int ALinkCount, const Stage::Vectorgeometry::TAffineVector &AAnchorPosition, const Stage::Vectorgeometry::TAffineVector &AHairDirection, const TGLStiffnessSetVH AStiffness);
	__fastcall virtual ~TGLVerletHair();
	__property TGLVerletNodeList* NodeList = {read=FNodeList};
	__property TGLVerletWorld* VerletWorld = {read=FVerletWorld};
	__property float RootDepth = {read=FRootDepth};
	__property float LinkLength = {read=GetLinkLength};
	__property int LinkCount = {read=FLinkCount, nodefault};
	__property float HairLength = {read=FHairLength};
	__property TGLStiffnessSetVH Stiffness = {read=FStiffness, write=SetStiffness, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property TGLBaseVerletNode* Anchor = {read=GetAnchor};
	__property TGLBaseVerletNode* Root = {read=GetRoot};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletSkeletonCollider : public Gls::Vectorfileobjects::TGLSkeletonCollider
{
	typedef Gls::Vectorfileobjects::TGLSkeletonCollider inherited;
	
private:
	TGLVerletConstraint* FVerletConstraint;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TGLVerletWorld* VerletWorld);
	__property TGLVerletConstraint* VerletConstraint = {read=FVerletConstraint};
public:
	/* TGLSkeletonCollider.Create */ inline __fastcall virtual TGLVerletSkeletonCollider() : Gls::Vectorfileobjects::TGLSkeletonCollider() { }
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TGLVerletSkeletonCollider(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : Gls::Vectorfileobjects::TGLSkeletonCollider(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVerletSkeletonCollider(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Vectorfileobjects::TGLSkeletonCollider(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TGLVerletSkeletonCollider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletSphere : public TGLVerletSkeletonCollider
{
	typedef TGLVerletSkeletonCollider inherited;
	
private:
	float FRadius;
	
protected:
	void __fastcall SetRadius(const float Val);
	
public:
	__fastcall virtual TGLVerletSphere();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TGLVerletWorld* VerletWorld);
	virtual void __fastcall AlignCollider();
	__property float Radius = {read=FRadius, write=SetRadius};
public:
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TGLVerletSphere(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : TGLVerletSkeletonCollider(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVerletSphere(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLVerletSkeletonCollider(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TGLVerletSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVerletCapsule : public TGLVerletSkeletonCollider
{
	typedef TGLVerletSkeletonCollider inherited;
	
private:
	float FRadius;
	float FLength;
	
protected:
	void __fastcall SetRadius(const float Val);
	void __fastcall SetLength(const float Val);
	
public:
	__fastcall virtual TGLVerletCapsule();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* Reader);
	virtual void __fastcall AddToVerletWorld(TGLVerletWorld* VerletWorld);
	virtual void __fastcall AlignCollider();
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TGLVerletCapsule(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : TGLVerletSkeletonCollider(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVerletCapsule(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLVerletSkeletonCollider(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TGLVerletCapsule() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define G_DRAG  (1.000000E-04)
#define cDEFAULT_CONSTRAINT_FRICTION  (6.000000E-01)
extern DELPHI_PACKAGE TGLVerletFloor* __fastcall CreateVerletPlaneFromGLPlane(Gls::Objects::TGLPlane* Plane, TGLVerletWorld* VerletWorld, float Offset);
extern DELPHI_PACKAGE void __fastcall AddVerletConstriantsToVerletWorld(Gls::Vectorfileobjects::TGLSkeletonColliderList* Colliders, TGLVerletWorld* World);
}	/* namespace Verlettypes */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_VERLETTYPES)
using namespace Gls::Verlettypes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_VerletTypesHPP
