// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Movement.pas' rev: 36.00 (Windows)

#ifndef GXS_MovementHPP
#define GXS_MovementHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GXS.XCollection.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Spline.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <Stage.Utils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Movement
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxPathNode;
class DELPHICLASS TgxPathNodes;
class DELPHICLASS TgxMovementPath;
class DELPHICLASS TgxMovementPaths;
class DELPHICLASS TgxMovement;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxPathNode : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Stage::Vectortypes::TVector4f FPosition;
	Stage::Vectortypes::TVector4f FScale;
	Stage::Vectortypes::TVector4f FRotation;
	Stage::Vectortypes::TVector4f FDirection;
	Stage::Vectortypes::TVector4f FUp;
	float FSpeed;
	void __fastcall SetPositionAsVector(const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetRotationAsVector(const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetScaleAsVector(const Stage::Vectortypes::TVector4f &Value);
	float __fastcall GetPositionCoordinate(const int Index);
	void __fastcall SetPositionCoordinate(const int Index, const float AValue);
	float __fastcall GetRotationCoordinate(const int Index);
	void __fastcall SetRotationCoordinate(const int Index, const float AValue);
	float __fastcall GetScaleCoordinate(const int Index);
	void __fastcall SetScaleCoordinate(const int Index, const float AValue);
	void __fastcall SetSpeed(const float Value);
	float __fastcall GetDirectionCoordinate(const int Index);
	void __fastcall SetDirectionCoordinate(const int Index, const float AValue);
	float __fastcall GetUpCoordinate(const int Index);
	void __fastcall SetUpCoordinate(const int Index, const float AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TgxPathNode(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxPathNode();
	Winapi::Opengl::PGLfloat __fastcall PositionAsAddress();
	Winapi::Opengl::PGLfloat __fastcall RotationAsAddress();
	Winapi::Opengl::PGLfloat __fastcall ScaleAsAddress();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall InitializeByObject(Gxs::Scene::TgxBaseSceneObject* const Obj);
	bool __fastcall EqualNode(TgxPathNode* const aNode);
	__property Stage::Vectortypes::TVector4f RotationAsVector = {read=FRotation, write=SetRotationAsVector};
	__property Stage::Vectortypes::TVector4f PositionAsVector = {read=FPosition, write=SetPositionAsVector};
	__property Stage::Vectortypes::TVector4f ScaleAsVector = {read=FScale, write=SetScaleAsVector};
	__property Stage::Vectortypes::TVector4f UpAsVector = {read=FUp, write=FUp};
	__property Stage::Vectortypes::TVector4f DirectionAsVector = {read=FDirection, write=FDirection};
	
__published:
	__property float X = {read=GetPositionCoordinate, write=SetPositionCoordinate, index=0};
	__property float Y = {read=GetPositionCoordinate, write=SetPositionCoordinate, index=1};
	__property float Z = {read=GetPositionCoordinate, write=SetPositionCoordinate, index=2};
	__property float PitchAngle = {read=GetRotationCoordinate, write=SetRotationCoordinate, index=0};
	__property float TurnAngle = {read=GetRotationCoordinate, write=SetRotationCoordinate, index=1};
	__property float RollAngle = {read=GetRotationCoordinate, write=SetRotationCoordinate, index=2};
	__property float ScaleX = {read=GetScaleCoordinate, write=SetScaleCoordinate, index=0};
	__property float ScaleY = {read=GetScaleCoordinate, write=SetScaleCoordinate, index=1};
	__property float ScaleZ = {read=GetScaleCoordinate, write=SetScaleCoordinate, index=2};
	__property float DirectionX = {read=GetDirectionCoordinate, write=SetDirectionCoordinate, index=0};
	__property float DirectionY = {read=GetDirectionCoordinate, write=SetDirectionCoordinate, index=1};
	__property float DirectionZ = {read=GetDirectionCoordinate, write=SetDirectionCoordinate, index=2};
	__property float UpX = {read=GetUpCoordinate, write=SetUpCoordinate, index=0};
	__property float UpY = {read=GetUpCoordinate, write=SetUpCoordinate, index=1};
	__property float UpZ = {read=GetUpCoordinate, write=SetUpCoordinate, index=2};
	__property float Speed = {read=FSpeed, write=SetSpeed};
};


enum DECLSPEC_DENUM TgxMovementRotationMode : unsigned char { rmTurnPitchRoll, rmUpDirection };

class PASCALIMPLEMENTATION TgxPathNodes : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxPathNode* operator[](const int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(const int index, TgxPathNode* const val);
	TgxPathNode* __fastcall GetItems(const int index);
	
public:
	__fastcall TgxPathNodes(TgxMovementPath* aOwner);
	TgxMovementPath* __fastcall GetOwnerMovementPath();
	HIDESBASE TgxPathNode* __fastcall Add();
	HIDESBASE TgxPathNode* __fastcall FindItemID(const int ID);
	__property TgxPathNode* Items[const int index] = {read=GetItems, write=SetItems/*, default*/};
	virtual void __fastcall NotifyChange();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxPathNodes() { }
	
};


class PASCALIMPLEMENTATION TgxMovementPath : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Objects::TgxLines* FPathLine;
	bool FShowPath;
	Gxs::Objects::TgxLineSplineMode FPathSplineMode;
	TgxPathNodes* FNodes;
	bool FStartTimeApplied;
	double FStartTime;
	double FInitialTime;
	double FEstimateTime;
	TgxPathNode* FCurrentNode;
	bool FInTravel;
	bool FLooped;
	System::UnicodeString FName;
	TgxMovementRotationMode FRotationMode;
	Stage::Spline::TCubicSpline* MotionSplineControl;
	Stage::Spline::TCubicSpline* RotationSplineControl;
	Stage::Spline::TCubicSpline* ScaleSplineControl;
	Stage::Spline::TCubicSpline* DirectionSplineControl;
	Stage::Spline::TCubicSpline* UpSplineControl;
	System::Classes::TNotifyEvent FOnTravelStart;
	System::Classes::TNotifyEvent FOnTravelStop;
	int FCurrentNodeIndex;
	int __fastcall GetNodeCount();
	void __fastcall SetStartTime(const double Value);
	void __fastcall SetCurrentNodeIndex(const int Value);
	void __fastcall SetShowPath(const bool Value);
	void __fastcall SetPathSplineMode(const Gxs::Objects::TgxLineSplineMode Value);
	
protected:
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	bool __fastcall CanTravel();
	TgxMovementPaths* __fastcall GetCollection();
	
public:
	__fastcall virtual TgxMovementPath(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxMovementPath();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TgxMovement* __fastcall GetMovement();
	TgxPathNode* __fastcall AddNode()/* overload */;
	TgxPathNode* __fastcall AddNode(TgxPathNode* const Node)/* overload */;
	TgxPathNode* __fastcall AddNodeFromObject(Gxs::Scene::TgxBaseSceneObject* const Obj);
	TgxPathNode* __fastcall InsertNodeFromObject(Gxs::Scene::TgxBaseSceneObject* const Obj, const int Index);
	TgxPathNode* __fastcall InsertNode(TgxPathNode* const Node, const int Index)/* overload */;
	TgxPathNode* __fastcall InsertNode(const int Index)/* overload */;
	TgxPathNode* __fastcall DeleteNode(const int Index)/* overload */;
	TgxPathNode* __fastcall DeleteNode(TgxPathNode* const Node)/* overload */;
	void __fastcall ClearNodes();
	void __fastcall UpdatePathLine();
	double __fastcall NodeDistance(TgxPathNode* const Node1, TgxPathNode* const Node2);
	void __fastcall CalculateState(const double CurrentTime);
	void __fastcall TravelPath(const bool Start)/* overload */;
	void __fastcall TravelPath(const bool Start, const double aStartTime)/* overload */;
	__property int NodeCount = {read=GetNodeCount, nodefault};
	__property TgxPathNode* CurrentNode = {read=FCurrentNode};
	__property bool InTravel = {read=FInTravel, nodefault};
	int __fastcall PrevNode();
	int __fastcall NextNode();
	__property int CurrentNodeIndex = {read=FCurrentNodeIndex, write=SetCurrentNodeIndex, nodefault};
	__property System::Classes::TNotifyEvent OnTravelStart = {read=FOnTravelStart, write=FOnTravelStart};
	__property System::Classes::TNotifyEvent OnTravelStop = {read=FOnTravelStop, write=FOnTravelStop};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Gxs::Objects::TgxLineSplineMode PathSplineMode = {read=FPathSplineMode, write=SetPathSplineMode, default=0};
	__property TgxMovementRotationMode RotationMode = {read=FRotationMode, write=FRotationMode, default=0};
	__property double StartTime = {read=FStartTime, write=SetStartTime};
	__property double EstimateTime = {read=FEstimateTime};
	__property bool Looped = {read=FLooped, write=FLooped, nodefault};
	__property TgxPathNodes* Nodes = {read=FNodes};
	__property bool ShowPath = {read=FShowPath, write=SetShowPath, nodefault};
};


class PASCALIMPLEMENTATION TgxMovementPaths : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxMovementPath* operator[](const int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(const int index, TgxMovementPath* const val);
	TgxMovementPath* __fastcall GetItems(const int index);
	TgxMovement* __fastcall GetMovement();
	
public:
	__fastcall TgxMovementPaths(TgxMovement* aOwner);
	HIDESBASE TgxMovementPath* __fastcall Add();
	HIDESBASE TgxMovementPath* __fastcall FindItemID(const int ID);
	__property TgxMovementPath* Items[const int index] = {read=GetItems, write=SetItems/*, default*/};
	virtual void __fastcall NotifyChange();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxMovementPaths() { }
	
};


typedef void __fastcall (__closure *TPathTravelStartEvent)(System::TObject* Sender, TgxMovementPath* Path);

typedef void __fastcall (__closure *TPathTravelStopEvent)(System::TObject* Sender, TgxMovementPath* Path, bool &Looped);

class PASCALIMPLEMENTATION TgxMovement : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxMovementPaths* FPaths;
	bool FAutoStartNextPath;
	int FActivePathIndex;
	System::Classes::TNotifyEvent FOnAllPathTravelledOver;
	TPathTravelStartEvent FOnPathTravelStart;
	TPathTravelStopEvent FOnPathTravelStop;
	int __fastcall GetPathCount();
	void __fastcall SetActivePathIndex(int Value);
	TgxMovementPath* __fastcall GetActivePath();
	void __fastcall SetActivePath(TgxMovementPath* Value);
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall PathTravelStart(System::TObject* Sender);
	void __fastcall PathTravelStop(System::TObject* Sender);
	Gxs::Scene::TgxBaseSceneObject* __fastcall GetSceneObject();
	
public:
	__fastcall virtual TgxMovement(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxMovement();
	TgxMovementPath* __fastcall AddPath()/* overload */;
	TgxMovementPath* __fastcall AddPath(Gxs::Scene::TgxBaseSceneObject* aObject)/* overload */;
	TgxMovementPath* __fastcall AddPath(TgxMovementPath* Path)/* overload */;
	void __fastcall ClearPaths();
	TgxMovementPath* __fastcall DeletePath(TgxMovementPath* Path)/* overload */;
	TgxMovementPath* __fastcall DeletePath(int Index)/* overload */;
	TgxMovementPath* __fastcall DeletePath()/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall StartPathTravel();
	void __fastcall StopPathTravel();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	int __fastcall NextPath();
	int __fastcall PrevPath();
	int __fastcall FirstPath();
	int __fastcall LastPath();
	__property int PathCount = {read=GetPathCount, nodefault};
	__property System::Classes::TNotifyEvent OnAllPathTravelledOver = {read=FOnAllPathTravelledOver, write=FOnAllPathTravelledOver};
	__property TPathTravelStartEvent OnPathTravelStart = {read=FOnPathTravelStart, write=FOnPathTravelStart};
	__property TPathTravelStopEvent OnPathTravelStop = {read=FOnPathTravelStop, write=FOnPathTravelStop};
	
__published:
	__property TgxMovementPaths* Paths = {read=FPaths};
	__property bool AutoStartNextPath = {read=FAutoStartNextPath, write=FAutoStartNextPath, nodefault};
	__property int ActivePathIndex = {read=FActivePathIndex, write=SetActivePathIndex, nodefault};
	__property TgxMovementPath* ActivePath = {read=GetActivePath, write=SetActivePath};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxMovement* __fastcall GetMovement(Gxs::Scene::TgxBehaviours* const behaviours)/* overload */;
extern DELPHI_PACKAGE TgxMovement* __fastcall GetMovement(Gxs::Scene::TgxBaseSceneObject* const obj)/* overload */;
extern DELPHI_PACKAGE TgxMovement* __fastcall GetOrCreateMovement(Gxs::Scene::TgxBehaviours* const behaviours)/* overload */;
extern DELPHI_PACKAGE TgxMovement* __fastcall GetOrCreateMovement(Gxs::Scene::TgxBaseSceneObject* const obj)/* overload */;
extern DELPHI_PACKAGE void __fastcall StartAllMovements(Gxs::Scene::TgxScene* const Scene, const bool StartCamerasMove, const bool StartObjectsMove);
extern DELPHI_PACKAGE void __fastcall StopAllMovements(Gxs::Scene::TgxScene* const Scene, const bool StopCamerasMove, const bool StopObjectsMove);
}	/* namespace Movement */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MOVEMENT)
using namespace Gxs::Movement;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MovementHPP
