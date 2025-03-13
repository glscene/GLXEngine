// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.NGDManager.pas' rev: 36.00 (Windows)

#ifndef GXS_NGDManagerHPP
#define GXS_NGDManagerHPP

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
#include <System.Types.hpp>
#include <NGD.Import.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Manager.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.XCollection.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Objects.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Ngdmanager
{
//-- forward type declarations -----------------------------------------------
struct TgxNGDHeightField;
class DELPHICLASS TgxNGDBehaviourList;
class DELPHICLASS TgxNGDDebugOption;
class DELPHICLASS TgxNGDManager;
class DELPHICLASS TgxNGDBehaviour;
class DELPHICLASS TgxNGDDynamic;
class DELPHICLASS TgxNGDStatic;
class DELPHICLASS TgxNGDSurfaceItem;
class DELPHICLASS TgxNGDSurfacePair;
class DELPHICLASS TgxNGDJointPivot;
class DELPHICLASS TgxNGDJointPin;
class DELPHICLASS TgxNGDJointPin2;
class DELPHICLASS TgxNGDJointBallAndSocket;
class DELPHICLASS TgxNGDJointHinge;
class DELPHICLASS TgxNGDJointSlider;
class DELPHICLASS TgxNGDJointKinematicController;
class DELPHICLASS TgxNGDJoint;
//-- type declarations -------------------------------------------------------
typedef float *PdFloat;

struct DECLSPEC_DRECORD TgxNGDHeightField
{
	
private:
	typedef System::DynamicArray<System::Word> _TgxNGDHeightField__1;
	
	
public:
	_TgxNGDHeightField__1 heightArray;
	int width;
	int depth;
	bool gridDiagonals;
	float widthDepthScale;
	float heightScale;
};


enum DECLSPEC_DENUM TgxNGDSolverModels : unsigned char { smExact, smLinear1, smLinear2, smLinear3, smLinear4, smLinear5, smLinear6, smLinear7, smLinear8, smLinear9 };

enum DECLSPEC_DENUM TgxNGDFrictionModels : unsigned char { fmExact, fmAdaptive };

enum DECLSPEC_DENUM TgxNGDPickedActions : unsigned char { paAttach, paMove, paDetach };

enum DECLSPEC_DENUM TgxNGDManagerDebug : unsigned char { mdShowGeometry, mdShowAABB, mdShowCenterOfMass, mdShowContact, mdShowJoint, mdShowForce, mdShowAppliedForce, mdShowAppliedVelocity };

typedef System::Set<TgxNGDManagerDebug, TgxNGDManagerDebug::mdShowGeometry, TgxNGDManagerDebug::mdShowAppliedVelocity> TgxNGDManagerDebugs;

enum DECLSPEC_DENUM TgxNGDCollisions : unsigned char { nc_Primitive, nc_Convex, nc_BBox, nc_BSphere, nc_Tree, nc_Mesh, nc_Null, nc_HeightField, nc_NGDFile };

enum DECLSPEC_DENUM TgxNGDJoints : unsigned char { nj_BallAndSocket, nj_Hinge, nj_Slider, nj_Corkscrew, nj_Universal, nj_CustomBallAndSocket, nj_CustomHinge, nj_CustomSlider, nj_UpVector, nj_KinematicController };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDBehaviourList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TgxNGDBehaviour* operator[](int index) { return this->ItemsBehav[index]; }
	
protected:
	TgxNGDBehaviour* __fastcall GetBehav(int index);
	void __fastcall PutBehav(int index, TgxNGDBehaviour* Item);
	
public:
	__property TgxNGDBehaviour* ItemsBehav[int index] = {read=GetBehav, write=PutBehav/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxNGDBehaviourList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxNGDBehaviourList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TCollisionIteratorEvent)(const void * userData, int vertexCount, const PdFloat cfaceArray, int faceId);

typedef void __fastcall (__closure *TApplyForceAndTorqueEvent)(const Ngd::Import::PNewtonBody cbody, Ngd::Import::dFloat timestep, int threadIndex);

typedef void __fastcall (__closure *TSetTransformEvent)(const Ngd::Import::PNewtonBody cbody, const PdFloat cmatrix, int threadIndex);

typedef void __fastcall (__closure *TSerializeEvent)(void * serializeHandle, const void * cbuffer, unsigned size);

typedef void __fastcall (__closure *TDeSerializeEvent)(void * serializeHandle, void * buffer, unsigned size);

typedef bool __fastcall (__closure *TAABBOverlapEvent)(const Ngd::Import::PNewtonMaterial cmaterial, const Ngd::Import::PNewtonBody cbody0, const Ngd::Import::PNewtonBody cbody1, int threadIndex);

typedef void __fastcall (__closure *TContactProcessEvent)(const Ngd::Import::PNewtonJoint ccontact, Ngd::Import::dFloat timestep, int threadIndex);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDDebugOption : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TgxNGDManager* FManager;
	Gxs::Color::TgxColor* FGeomColorDyn;
	Gxs::Color::TgxColor* FGeomColorStat;
	Gxs::Color::TgxColor* FAABBColor;
	Gxs::Color::TgxColor* FAABBColorSleep;
	Gxs::Color::TgxColor* FCenterOfMassColor;
	Gxs::Color::TgxColor* FContactColor;
	Gxs::Color::TgxColor* FJointAxisColor;
	Gxs::Color::TgxColor* FJointPivotColor;
	Gxs::Color::TgxColor* FForceColor;
	Gxs::Color::TgxColor* FAppliedForceColor;
	Gxs::Color::TgxColor* FAppliedVelocityColor;
	Gxs::Color::TgxColor* FCustomColor;
	float FDotAxisSize;
	TgxNGDManagerDebugs FManagerDebugs;
	void __fastcall SetManagerDebugs(const TgxNGDManagerDebugs Value);
	void __fastcall SetDotAxisSize(const float Value);
	bool __fastcall StoredDotAxis();
	
public:
	__fastcall TgxNGDDebugOption(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxNGDDebugOption();
	
__published:
	__property Gxs::Color::TgxColor* GeomColorDyn = {read=FGeomColorDyn, write=FGeomColorDyn};
	__property Gxs::Color::TgxColor* GeomColorStat = {read=FGeomColorStat, write=FGeomColorStat};
	__property Gxs::Color::TgxColor* AABBColor = {read=FAABBColor, write=FAABBColor};
	__property Gxs::Color::TgxColor* AABBColorSleep = {read=FAABBColorSleep, write=FAABBColorSleep};
	__property Gxs::Color::TgxColor* CenterOfMassColor = {read=FCenterOfMassColor, write=FCenterOfMassColor};
	__property Gxs::Color::TgxColor* ContactColor = {read=FContactColor, write=FContactColor};
	__property Gxs::Color::TgxColor* JointAxisColor = {read=FJointAxisColor, write=FJointAxisColor};
	__property Gxs::Color::TgxColor* JointPivotColor = {read=FJointPivotColor, write=FJointPivotColor};
	__property Gxs::Color::TgxColor* ForceColor = {read=FForceColor, write=FForceColor};
	__property Gxs::Color::TgxColor* AppliedForceColor = {read=FAppliedForceColor, write=FAppliedForceColor};
	__property Gxs::Color::TgxColor* AppliedVelocityColor = {read=FAppliedVelocityColor, write=FAppliedVelocityColor};
	__property Gxs::Color::TgxColor* CustomColor = {read=FCustomColor, write=FCustomColor};
	__property TgxNGDManagerDebugs NGDManagerDebugs = {read=FManagerDebugs, write=SetManagerDebugs, default=0};
	__property float DotAxisSize = {read=FDotAxisSize, write=SetDotAxisSize, stored=StoredDotAxis};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxNGDManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FVisible;
	bool FVisibleAtRunTime;
	int FDllVersion;
	TgxNGDSolverModels FSolverModel;
	TgxNGDFrictionModels FFrictionModel;
	int FMinimumFrameRate;
	Gxs::Coordinates::TgxCoordinates* FWorldSizeMin;
	Gxs::Coordinates::TgxCoordinates* FWorldSizeMax;
	int FThreadCount;
	Gxs::Coordinates::TgxCoordinates* FGravity;
	System::Classes::TCollection* FNewtonSurfaceItem;
	System::Classes::TOwnedCollection* FNewtonSurfacePair;
	System::Classes::TOwnedCollection* FNewtonJointGroup;
	TgxNGDDebugOption* FNewtonDebugOption;
	Gxs::Objects::TgxLines* FGLLines;
	
private:
	Ngd::Import::PNewtonWorld FNewtonWorld;
	TgxNGDBehaviourList* FNGDBehaviours;
	Gxs::Color::TgxColor* FCurrentColor;
	
protected:
	virtual void __fastcall Loaded();
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetVisibleAtRunTime(const bool Value);
	void __fastcall SetSolverModel(const TgxNGDSolverModels Value);
	void __fastcall SetFrictionModel(const TgxNGDFrictionModels Value);
	void __fastcall SetMinimumFrameRate(const int Value);
	void __fastcall SetThreadCount(const int Value);
	void __fastcall SetGXLines(Gxs::Objects::TgxLines* const Value);
	int __fastcall GetBodyCount();
	int __fastcall GetConstraintCount();
	void __fastcall AddNode(Gxs::Coordinates::TgxCustomCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const float X, const float Y, const float Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TVector4f &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	void __fastcall RebuildAllMaterial();
	void __fastcall RebuildAllJoint(System::TObject* Sender);
	void __fastcall NotifyWorldSizeChange(System::TObject* Sender);
	void __fastcall NotifyChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxNGDManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxNGDManager();
	void __fastcall Step(float deltatime);
	
__published:
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, default=0};
	__property TgxNGDSolverModels SolverModel = {read=FSolverModel, write=SetSolverModel, default=0};
	__property TgxNGDFrictionModels FrictionModel = {read=FFrictionModel, write=SetFrictionModel, default=0};
	__property int MinimumFrameRate = {read=FMinimumFrameRate, write=SetMinimumFrameRate, default=60};
	__property int ThreadCount = {read=FThreadCount, write=SetThreadCount, default=1};
	__property int DllVersion = {read=FDllVersion, nodefault};
	__property int NewtonBodyCount = {read=GetBodyCount, nodefault};
	__property int NewtonConstraintCount = {read=GetConstraintCount, nodefault};
	__property Gxs::Coordinates::TgxCoordinates* Gravity = {read=FGravity, write=FGravity};
	__property Gxs::Coordinates::TgxCoordinates* WorldSizeMin = {read=FWorldSizeMin, write=FWorldSizeMin};
	__property Gxs::Coordinates::TgxCoordinates* WorldSizeMax = {read=FWorldSizeMax, write=FWorldSizeMax};
	__property System::Classes::TCollection* NewtonSurfaceItem = {read=FNewtonSurfaceItem, write=FNewtonSurfaceItem};
	__property System::Classes::TOwnedCollection* NewtonSurfacePair = {read=FNewtonSurfacePair, write=FNewtonSurfacePair};
	__property TgxNGDDebugOption* DebugOption = {read=FNewtonDebugOption, write=FNewtonDebugOption};
	__property Gxs::Objects::TgxLines* Line = {read=FGLLines, write=SetGXLines};
	__property System::Classes::TOwnedCollection* NewtonJoint = {read=FNewtonJointGroup, write=FNewtonJointGroup};
};


class PASCALIMPLEMENTATION TgxNGDBehaviour : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxNGDManager* FManager;
	System::UnicodeString FManagerName;
	bool FInitialized;
	Ngd::Import::PNewtonBody FNewtonBody;
	Ngd::Import::PNewtonCollision FCollision;
	Stage::Vectortypes::TMatrix4f FNewtonBodyMatrix;
	bool FContinuousCollisionMode;
	TgxNGDCollisions FNewtonCollisions;
	TCollisionIteratorEvent FCollisionIteratorEvent;
	Gxs::Scene::TgxBaseSceneObject* FOwnerBaseSceneObject;
	bool FTreeCollisionOptimize;
	float FConvexCollisionTolerance;
	System::UnicodeString FFileCollision;
	TgxNGDSurfaceItem* FSurfaceItem;
	TgxNGDHeightField FHeightFieldOptions;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetManager(TgxNGDManager* Value);
	void __fastcall SetNewtonBodyMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	void __fastcall SetContinuousCollisionMode(const bool Value);
	Stage::Vectortypes::TMatrix4f __fastcall GetNewtonBodyMatrix();
	Gxs::Geometrybb::TAABB __fastcall GetNewtonBodyAABB();
	virtual void __fastcall UpdCollision();
	virtual void __fastcall Render();
	void __fastcall SetNewtonCollisions(const TgxNGDCollisions Value);
	void __fastcall SetNewtonSurfaceItem(TgxNGDSurfaceItem* const Value);
	void __fastcall SetHeightFieldOptions(const TgxNGDHeightField &Value);
	Ngd::Import::PNewtonCollision __fastcall GetPrimitiveCollision();
	Ngd::Import::PNewtonCollision __fastcall GetConvexCollision();
	Ngd::Import::PNewtonCollision __fastcall GetBBoxCollision();
	Ngd::Import::PNewtonCollision __fastcall GetBSphereCollision();
	Ngd::Import::PNewtonCollision __fastcall GetTreeCollision();
	Ngd::Import::PNewtonCollision __fastcall GetMeshCollision();
	Ngd::Import::PNewtonCollision __fastcall GetNullCollision();
	Ngd::Import::PNewtonCollision __fastcall GetHeightFieldCollision();
	Ngd::Import::PNewtonCollision __fastcall GetNGDFileCollision();
	bool __fastcall StoredTolerance();
	void __fastcall OnCollisionIteratorEvent(const void * userData, int vertexCount, const PdFloat cfaceArray, int faceId);
	static void __cdecl NewtonCollisionIterator(const void * userData, int vertexCount, const PdFloat faceArray, int faceId);
	static void __cdecl NewtonSerialize(void * serializeHandle, const void * buffer, unsigned size);
	static void __cdecl NewtonDeserialize(void * serializeHandle, void * buffer, unsigned size);
	
public:
	__fastcall virtual TgxNGDBehaviour(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxNGDBehaviour();
	void __fastcall Reinitialize();
	__property bool Initialized = {read=FInitialized, nodefault};
	__classmethod virtual bool __fastcall UniqueItem();
	__property Stage::Vectortypes::TMatrix4f NewtonBodyMatrix = {read=GetNewtonBodyMatrix, write=SetNewtonBodyMatrix};
	__property Gxs::Geometrybb::TAABB NewtonBodyAABB = {read=GetNewtonBodyAABB};
	void __fastcall Serialize(System::UnicodeString filename);
	void __fastcall DeSerialize(System::UnicodeString filename);
	__property TgxNGDHeightField HeightFieldOptions = {read=FHeightFieldOptions, write=SetHeightFieldOptions};
	
__published:
	__property TgxNGDManager* Manager = {read=FManager, write=SetManager};
	__property bool ContinuousCollisionMode = {read=FContinuousCollisionMode, write=SetContinuousCollisionMode, default=0};
	__property TgxNGDCollisions NGDNewtonCollisions = {read=FNewtonCollisions, write=SetNewtonCollisions, default=0};
	__property bool TreeCollisionOptimize = {read=FTreeCollisionOptimize, write=FTreeCollisionOptimize, default=1};
	__property float ConvexCollisionTolerance = {read=FConvexCollisionTolerance, write=FConvexCollisionTolerance, stored=StoredTolerance};
	__property System::UnicodeString FileCollision = {read=FFileCollision, write=FFileCollision};
	__property TgxNGDSurfaceItem* NGDSurfaceItem = {read=FSurfaceItem, write=SetNewtonSurfaceItem};
};


class PASCALIMPLEMENTATION TgxNGDDynamic : public TgxNGDBehaviour
{
	typedef TgxNGDBehaviour inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAABBmin;
	Gxs::Coordinates::TgxCoordinates* FAABBmax;
	Gxs::Coordinates::TgxCoordinates* FForce;
	Gxs::Coordinates::TgxCoordinates* FTorque;
	Gxs::Coordinates::TgxCoordinates* FCenterOfMass;
	bool FAutoSleep;
	float FLinearDamping;
	Gxs::Coordinates::TgxCoordinates* FAngularDamping;
	float FDensity;
	bool FUseGravity;
	float FNullCollisionVolume;
	TApplyForceAndTorqueEvent FApplyForceAndTorqueEvent;
	TSetTransformEvent FSetTransformEvent;
	TApplyForceAndTorqueEvent FCustomForceAndTorqueEvent;
	float FVolume;
	float FMass;
	Gxs::Coordinates::TgxCoordinates* FAppliedForce;
	Gxs::Coordinates::TgxCoordinates* FAppliedTorque;
	Gxs::Coordinates::TgxCoordinates* FAppliedOmega;
	Gxs::Coordinates::TgxCoordinates* FAppliedVelocity;
	bool __fastcall StoredDensity();
	bool __fastcall StoredLinearDamping();
	bool __fastcall StoredNullCollisionVolume();
	
protected:
	void __fastcall SetAutoSleep(const bool Value);
	void __fastcall SetLinearDamping(const float Value);
	virtual void __fastcall SetDensity(const float Value);
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall Render();
	void __fastcall NotifyCenterOfMassChange(System::TObject* Sender);
	void __fastcall NotifyAngularDampingChange(System::TObject* Sender);
	void __fastcall OnApplyForceAndTorqueEvent(const Ngd::Import::PNewtonBody cbody, Ngd::Import::dFloat timestep, int threadIndex);
	void __fastcall OnSetTransformEvent(const Ngd::Import::PNewtonBody cbody, const PdFloat cmatrix, int threadIndex);
	static void __cdecl NewtonApplyForceAndTorque(const Ngd::Import::PNewtonBody body, Ngd::Import::dFloat timestep, int threadIndex);
	static void __cdecl NewtonSetTransform(const Ngd::Import::PNewtonBody body, const PdFloat matrix, int threadIndex);
	
public:
	__fastcall virtual TgxNGDDynamic(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxNGDDynamic();
	void __fastcall AddImpulse(const Stage::Vectortypes::TVector4f &veloc, const Stage::Vectortypes::TVector4f &pointposit);
	Stage::Vectortypes::TVector4f __fastcall GetOmega();
	void __fastcall SetOmega(const Stage::Vectortypes::TVector4f &Omega);
	Stage::Vectortypes::TVector4f __fastcall GetVelocity();
	void __fastcall SetVelocity(const Stage::Vectortypes::TVector4f &Velocity);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__property TApplyForceAndTorqueEvent CustomForceAndTorqueEvent = {read=FCustomForceAndTorqueEvent, write=FCustomForceAndTorqueEvent};
	__property Stage::Vectortypes::TVector4f Velocity = {read=GetVelocity, write=SetVelocity};
	__property Stage::Vectortypes::TVector4f Omega = {read=GetOmega, write=SetOmega};
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Force = {read=FForce, write=FForce};
	__property Gxs::Coordinates::TgxCoordinates* Torque = {read=FTorque, write=FTorque};
	__property Gxs::Coordinates::TgxCoordinates* CenterOfMass = {read=FCenterOfMass, write=FCenterOfMass};
	__property bool AutoSleep = {read=FAutoSleep, write=SetAutoSleep, default=1};
	__property float LinearDamping = {read=FLinearDamping, write=SetLinearDamping, stored=StoredLinearDamping};
	__property Gxs::Coordinates::TgxCoordinates* AngularDamping = {read=FAngularDamping, write=FAngularDamping};
	__property float Density = {read=FDensity, write=SetDensity, stored=StoredDensity};
	__property bool UseGravity = {read=FUseGravity, write=FUseGravity, default=1};
	__property float NullCollisionVolume = {read=FNullCollisionVolume, write=FNullCollisionVolume, stored=StoredNullCollisionVolume};
	__property Gxs::Coordinates::TgxCoordinates* AppliedOmega = {read=FAppliedOmega};
	__property Gxs::Coordinates::TgxCoordinates* AppliedVelocity = {read=FAppliedVelocity};
	__property Gxs::Coordinates::TgxCoordinates* AppliedForce = {read=FAppliedForce};
	__property Gxs::Coordinates::TgxCoordinates* AppliedTorque = {read=FAppliedTorque};
	__property float Volume = {read=FVolume};
	__property float Mass = {read=FMass};
};


class PASCALIMPLEMENTATION TgxNGDStatic : public TgxNGDBehaviour
{
	typedef TgxNGDBehaviour inherited;
	
protected:
	virtual void __fastcall Render();
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
public:
	/* TgxNGDBehaviour.Create */ inline __fastcall virtual TgxNGDStatic(Gxs::Xcollection::TXCollection* AOwner) : TgxNGDBehaviour(AOwner) { }
	/* TgxNGDBehaviour.Destroy */ inline __fastcall virtual ~TgxNGDStatic() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDSurfaceItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FDisplayName;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	virtual void __fastcall SetDisplayName(const System::UnicodeString Value);
	
__published:
	__property DisplayName = {default=0};
	__property ID;
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TgxNGDSurfaceItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxNGDSurfaceItem() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxNGDSurfacePair : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxNGDManager* FManager;
	TgxNGDSurfaceItem* FSurfaceItem1;
	TgxNGDSurfaceItem* FSurfaceItem2;
	TAABBOverlapEvent FAABBOverlapEvent;
	TContactProcessEvent FContactProcessEvent;
	float FSoftness;
	float FElasticity;
	bool FCollidable;
	float FStaticFriction;
	float FKineticFriction;
	bool FContinuousCollisionMode;
	bool FThickness;
	void __fastcall SetCollidable(const bool Value);
	void __fastcall SetElasticity(const float Value);
	void __fastcall SetKineticFriction(const float Value);
	void __fastcall SetSoftness(const float Value);
	void __fastcall SetStaticFriction(const float Value);
	void __fastcall SetContinuousCollisionMode(const bool Value);
	void __fastcall SetThickness(const bool Value);
	bool __fastcall StoredElasticity();
	bool __fastcall StoredKineticFriction();
	bool __fastcall StoredSoftness();
	bool __fastcall StoredStaticFriction();
	
private:
	static int __cdecl NewtonAABBOverlap(const Ngd::Import::PNewtonMaterial material, const Ngd::Import::PNewtonBody body0, const Ngd::Import::PNewtonBody body1, int threadIndex);
	static void __cdecl NewtonContactsProcess(const Ngd::Import::PNewtonJoint contact, Ngd::Import::dFloat timestep, int threadIndex);
	bool __fastcall OnNewtonAABBOverlapEvent(const Ngd::Import::PNewtonMaterial cmaterial, const Ngd::Import::PNewtonBody cbody0, const Ngd::Import::PNewtonBody cbody1, int threadIndex);
	void __fastcall OnNewtonContactsProcessEvent(const Ngd::Import::PNewtonJoint ccontact, Ngd::Import::dFloat timestep, int threadIndex);
	
public:
	__fastcall virtual TgxNGDSurfacePair(System::Classes::TCollection* Collection);
	void __fastcall SetMaterialItems(TgxNGDSurfaceItem* const item1, TgxNGDSurfaceItem* const item2);
	__property TgxNGDSurfaceItem* NGDSurfaceItem1 = {read=FSurfaceItem1};
	__property TgxNGDSurfaceItem* NGDSurfaceItem2 = {read=FSurfaceItem2};
	
__published:
	__property float Softness = {read=FSoftness, write=SetSoftness, stored=StoredSoftness};
	__property float Elasticity = {read=FElasticity, write=SetElasticity, stored=StoredElasticity};
	__property bool Collidable = {read=FCollidable, write=SetCollidable, default=1};
	__property float StaticFriction = {read=FStaticFriction, write=SetStaticFriction, stored=StoredStaticFriction};
	__property float KineticFriction = {read=FKineticFriction, write=SetKineticFriction, stored=StoredKineticFriction};
	__property bool ContinuousCollisionMode = {read=FContinuousCollisionMode, write=SetContinuousCollisionMode, default=0};
	__property bool Thickness = {read=FThickness, write=SetThickness, default=0};
	__property TContactProcessEvent ContactProcessEvent = {read=FContactProcessEvent, write=FContactProcessEvent};
	__property TAABBOverlapEvent AABBOverlapEvent = {read=FAABBOverlapEvent, write=FAABBOverlapEvent};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxNGDSurfacePair() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointPivot : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TgxNGDManager* FManager;
	Gxs::Coordinates::TgxCoordinates* FPivotPoint;
	TgxNGDJoint* FOuter;
	
public:
	__fastcall virtual TgxNGDJointPivot(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	__fastcall virtual ~TgxNGDJointPivot();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* PivotPoint = {read=FPivotPoint, write=FPivotPoint};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointPin : public TgxNGDJointPivot
{
	typedef TgxNGDJointPivot inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FPinDirection;
	
public:
	__fastcall virtual TgxNGDJointPin(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	__fastcall virtual ~TgxNGDJointPin();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* PinDirection = {read=FPinDirection, write=FPinDirection};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointPin2 : public TgxNGDJointPin
{
	typedef TgxNGDJointPin inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FPinDirection2;
	
public:
	__fastcall virtual TgxNGDJointPin2(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	__fastcall virtual ~TgxNGDJointPin2();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* PinDirection2 = {read=FPinDirection2, write=FPinDirection2};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointBallAndSocket : public TgxNGDJointPivot
{
	typedef TgxNGDJointPivot inherited;
	
private:
	float FConeAngle;
	float FMinTwistAngle;
	float FMaxTwistAngle;
	void __fastcall SetConeAngle(const float Value);
	void __fastcall SetMaxTwistAngle(const float Value);
	void __fastcall SetMinTwistAngle(const float Value);
	bool __fastcall StoredMaxTwistAngle();
	bool __fastcall StoredMinTwistAngle();
	bool __fastcall StoredConeAngle();
	
public:
	__fastcall virtual TgxNGDJointBallAndSocket(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	
__published:
	__property float ConeAngle = {read=FConeAngle, write=SetConeAngle, stored=StoredConeAngle};
	__property float MinTwistAngle = {read=FMinTwistAngle, write=SetMinTwistAngle, stored=StoredMinTwistAngle};
	__property float MaxTwistAngle = {read=FMaxTwistAngle, write=SetMaxTwistAngle, stored=StoredMaxTwistAngle};
public:
	/* TgxNGDJointPivot.Destroy */ inline __fastcall virtual ~TgxNGDJointBallAndSocket() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointHinge : public TgxNGDJointPin
{
	typedef TgxNGDJointPin inherited;
	
private:
	float FMinAngle;
	float FMaxAngle;
	void __fastcall SetMaxAngle(const float Value);
	void __fastcall SetMinAngle(const float Value);
	bool __fastcall StoredMaxAngle();
	bool __fastcall StoredMinAngle();
	
public:
	__fastcall virtual TgxNGDJointHinge(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	
__published:
	__property float MinAngle = {read=FMinAngle, write=SetMinAngle, stored=StoredMinAngle};
	__property float MaxAngle = {read=FMaxAngle, write=SetMaxAngle, stored=StoredMaxAngle};
public:
	/* TgxNGDJointPin.Destroy */ inline __fastcall virtual ~TgxNGDJointHinge() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointSlider : public TgxNGDJointPin
{
	typedef TgxNGDJointPin inherited;
	
private:
	float FMinDistance;
	float FMaxDistance;
	void __fastcall SetMaxDistance(const float Value);
	void __fastcall SetMinDistance(const float Value);
	bool __fastcall StoredMaxDistance();
	bool __fastcall StoredMinDistance();
	
public:
	__fastcall virtual TgxNGDJointSlider(System::Classes::TComponent* AOwner, TgxNGDJoint* aOuter);
	
__published:
	__property float MinDistance = {read=FMinDistance, write=SetMinDistance, stored=StoredMinDistance};
	__property float MaxDistance = {read=FMaxDistance, write=SetMaxDistance, stored=StoredMaxDistance};
public:
	/* TgxNGDJointPin.Destroy */ inline __fastcall virtual ~TgxNGDJointSlider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJointKinematicController : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FPickModeLinear;
	float FLinearFriction;
	float FAngularFriction;
	bool __fastcall StoredAngularFriction();
	bool __fastcall StoredLinearFriction();
	
public:
	__fastcall TgxNGDJointKinematicController();
	
__published:
	__property bool PickModeLinear = {read=FPickModeLinear, write=FPickModeLinear, default=0};
	__property float LinearFriction = {read=FLinearFriction, write=FLinearFriction, stored=StoredLinearFriction};
	__property float AngularFriction = {read=FAngularFriction, write=FAngularFriction, stored=StoredAngularFriction};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNGDJointKinematicController() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNGDJoint : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxNGDManager* FManager;
	Gxs::Scene::TgxBaseSceneObject* FParentObject;
	TgxNGDJoints FJointType;
	float FStiffness;
	Gxs::Scene::TgxBaseSceneObject* FChildObject;
	bool FCollisionState;
	Ngd::Import::PNewtonJoint FNewtonJoint;
	void *FNewtonUserJoint;
	Gxs::Coordinates::TgxCoordinates* FUPVectorDirection;
	TgxNGDJointPivot* FBallAndSocketOptions;
	TgxNGDJointPin* FHingeOptions;
	TgxNGDJointPin* FSliderOptions;
	TgxNGDJointPin* FCorkscrewOptions;
	TgxNGDJointPin2* FUniversalOptions;
	TgxNGDJointBallAndSocket* FCustomBallAndSocketOptions;
	TgxNGDJointHinge* FCustomHingeOptions;
	TgxNGDJointSlider* FCustomSliderOptions;
	TgxNGDJointKinematicController* FKinematicOptions;
	void __fastcall SetJointType(const TgxNGDJoints Value);
	void __fastcall SetChildObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetCollisionState(const bool Value);
	void __fastcall SetParentObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetStiffness(const float Value);
	void __fastcall Render();
	bool __fastcall StoredStiffness();
	void __fastcall DestroyNewtonData();
	
public:
	__fastcall virtual TgxNGDJoint(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxNGDJoint();
	void __fastcall KinematicControllerPick(const Stage::Vectortypes::TVector4f &pickpoint, TgxNGDPickedActions PickedActions);
	
__published:
	__property TgxNGDJointPivot* BallAndSocketOptions = {read=FBallAndSocketOptions, write=FBallAndSocketOptions};
	__property TgxNGDJointPin* HingeOptions = {read=FHingeOptions, write=FHingeOptions};
	__property TgxNGDJointPin* SliderOptions = {read=FSliderOptions, write=FSliderOptions};
	__property TgxNGDJointPin* CorkscrewOptions = {read=FCorkscrewOptions, write=FCorkscrewOptions};
	__property TgxNGDJointPin2* UniversalOptions = {read=FUniversalOptions, write=FUniversalOptions};
	__property TgxNGDJointBallAndSocket* CustomBallAndSocketOptions = {read=FCustomBallAndSocketOptions, write=FCustomBallAndSocketOptions};
	__property TgxNGDJointHinge* CustomHingeOptions = {read=FCustomHingeOptions, write=FCustomHingeOptions};
	__property TgxNGDJointSlider* CustomSliderOptions = {read=FCustomSliderOptions, write=FCustomSliderOptions};
	__property TgxNGDJointKinematicController* KinematicControllerOptions = {read=FKinematicOptions, write=FKinematicOptions};
	__property TgxNGDJoints JointType = {read=FJointType, write=SetJointType, nodefault};
	__property Gxs::Scene::TgxBaseSceneObject* ParentObject = {read=FParentObject, write=SetParentObject};
	__property Gxs::Scene::TgxBaseSceneObject* ChildObject = {read=FChildObject, write=SetChildObject};
	__property bool CollisionState = {read=FCollisionState, write=SetCollisionState, default=0};
	__property float Stiffness = {read=FStiffness, write=SetStiffness, stored=StoredStiffness};
	__property Gxs::Coordinates::TgxCoordinates* UPVectorDirection = {read=FUPVectorDirection, write=FUPVectorDirection};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxNGDStatic* __fastcall GetNGDStatic(Gxs::Scene::TgxBaseSceneObject* Obj);
extern DELPHI_PACKAGE TgxNGDStatic* __fastcall GetOrCreateNGDStatic(Gxs::Scene::TgxBaseSceneObject* Obj);
extern DELPHI_PACKAGE TgxNGDDynamic* __fastcall GetNGDDynamic(Gxs::Scene::TgxBaseSceneObject* Obj);
extern DELPHI_PACKAGE TgxNGDDynamic* __fastcall GetOrCreateNGDDynamic(Gxs::Scene::TgxBaseSceneObject* Obj);
extern DELPHI_PACKAGE Ngd::Import::PNewtonBody __fastcall GetBodyFromGLXceneObject(Gxs::Scene::TgxBaseSceneObject* Obj);
}	/* namespace Ngdmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_NGDMANAGER)
using namespace Gxs::Ngdmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_NGDManagerHPP
