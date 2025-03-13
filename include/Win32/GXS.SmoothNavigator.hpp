// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SmoothNavigator.pas' rev: 36.00 (Windows)

#ifndef GXS_SmoothNavigatorHPP
#define GXS_SmoothNavigatorHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Navigator.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Screen.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Smoothnavigator
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxNavigatorAbstractParameters;
class DELPHICLASS TgxNavigatorSmoothChangeItem;
class DELPHICLASS TgxNavigatorSmoothChangeSingle;
class DELPHICLASS TgxNavigatorSmoothChangeVector;
class DELPHICLASS TgxNavigatorSmoothChangeItems;
class DELPHICLASS TgxNavigatorAdjustDistanceParameters;
class DELPHICLASS TgxNavigatorAdjustDistanceParametersEx;
class DELPHICLASS TgxNavigatorInertiaParameters;
class DELPHICLASS TgxNavigatorGeneralParameters;
class DELPHICLASS TgxNavigatorMoveAroundParameters;
class DELPHICLASS TgxSmoothNavigator;
class DELPHICLASS TgxSmoothUserInterface;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorAbstractParameters : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	float FInertia;
	float FSpeed;
	float FCutoff;
	bool __fastcall StoreCutoff();
	
protected:
	virtual bool __fastcall StoreInertia();
	virtual bool __fastcall StoreSpeed();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TgxNavigatorAbstractParameters(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ScaleParameters(const float Value);
	
__published:
	__property float Inertia = {read=FInertia, write=FInertia, stored=StoreInertia};
	__property float Speed = {read=FSpeed, write=FSpeed, stored=StoreSpeed};
	__property float Cutoff = {read=FCutoff, write=FCutoff, stored=StoreCutoff};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorAbstractParameters() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxNavigatorSmoothChangeItem : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	float FInertia;
	float FSpeed;
	bool FEnabled;
	float FSpeedLimit;
	double FCutoff;
	bool __fastcall StoreInertia();
	bool __fastcall StoreSpeed();
	bool __fastcall StoreSpeedLimit();
	bool __fastcall StoreCutoff();
	
protected:
	TgxSmoothNavigator* __fastcall GetNavigator();
	
public:
	virtual bool __fastcall Proceed(double ADeltaTime) = 0 ;
	__fastcall virtual TgxNavigatorSmoothChangeItem(Gxs::Xcollection::TXCollection* aOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ScaleParameters(const float Value);
	virtual void __fastcall ResetTargetValue() = 0 ;
	
__published:
	__property float Inertia = {read=FInertia, write=FInertia, stored=StoreInertia};
	__property float Speed = {read=FSpeed, write=FSpeed, stored=StoreSpeed};
	__property float SpeedLimit = {read=FSpeedLimit, write=FSpeedLimit, stored=StoreSpeedLimit};
	__property double Cutoff = {read=FCutoff, write=FCutoff, stored=StoreCutoff};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
public:
	/* TXCollectionItem.Destroy */ inline __fastcall virtual ~TgxNavigatorSmoothChangeItem() { }
	
};


typedef float __fastcall (__closure *TgxNavigatorSmoothChangeSingleGetEvent)(TgxNavigatorSmoothChangeSingle* const ASender);

typedef void __fastcall (__closure *TgxNavigatorSmoothChangeSingleSetEvent)(TgxNavigatorSmoothChangeSingle* const ASender, const float AValue);

class PASCALIMPLEMENTATION TgxNavigatorSmoothChangeSingle : public TgxNavigatorSmoothChangeItem
{
	typedef TgxNavigatorSmoothChangeItem inherited;
	
private:
	float FTargetValue;
	TgxNavigatorSmoothChangeSingleGetEvent FOnGetCurrentValue;
	TgxNavigatorSmoothChangeSingleSetEvent FOnSetCurrentValue;
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	virtual bool __fastcall Proceed(double ADeltaTime);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ResetTargetValue();
	
__published:
	__property float TargetValue = {read=FTargetValue, write=FTargetValue};
	__property TgxNavigatorSmoothChangeSingleGetEvent OnGetCurrentValue = {read=FOnGetCurrentValue, write=FOnGetCurrentValue};
	__property TgxNavigatorSmoothChangeSingleSetEvent OnSetCurrentValue = {read=FOnSetCurrentValue, write=FOnSetCurrentValue};
public:
	/* TgxNavigatorSmoothChangeItem.Create */ inline __fastcall virtual TgxNavigatorSmoothChangeSingle(Gxs::Xcollection::TXCollection* aOwner) : TgxNavigatorSmoothChangeItem(aOwner) { }
	
public:
	/* TXCollectionItem.Destroy */ inline __fastcall virtual ~TgxNavigatorSmoothChangeSingle() { }
	
};


typedef Stage::Vectortypes::TVector4f __fastcall (__closure *TgxNavigatorSmoothChangeVectorGetEvent)(TgxNavigatorSmoothChangeVector* const ASender);

typedef void __fastcall (__closure *TgxNavigatorSmoothChangeVectorSetEvent)(TgxNavigatorSmoothChangeVector* const ASender, const Stage::Vectortypes::TVector4f &AValue);

class PASCALIMPLEMENTATION TgxNavigatorSmoothChangeVector : public TgxNavigatorSmoothChangeItem
{
	typedef TgxNavigatorSmoothChangeItem inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FTargetValue;
	TgxNavigatorSmoothChangeVectorGetEvent FOnGetCurrentValue;
	TgxNavigatorSmoothChangeVectorSetEvent FOnSetCurrentValue;
	void __fastcall SetTargetValue(Gxs::Coordinates::TgxCoordinates* const Value);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	virtual bool __fastcall Proceed(double ADeltaTime);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__fastcall virtual TgxNavigatorSmoothChangeVector(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxNavigatorSmoothChangeVector();
	virtual void __fastcall ResetTargetValue();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* TargetValue = {read=FTargetValue, write=SetTargetValue};
	__property TgxNavigatorSmoothChangeVectorGetEvent OnGetCurrentValue = {read=FOnGetCurrentValue, write=FOnGetCurrentValue};
	__property TgxNavigatorSmoothChangeVectorSetEvent OnSetCurrentValue = {read=FOnSetCurrentValue, write=FOnSetCurrentValue};
};


typedef System::TMetaClass* TgxNavigatorSmoothChangeItemClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorSmoothChangeItems : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	TgxNavigatorSmoothChangeItem* operator[](const int Index) { return this->Items[Index]; }
	
private:
	HIDESBASE TgxNavigatorSmoothChangeItem* __fastcall GetItems(const int Index);
	void __fastcall SetItems(const int Index, TgxNavigatorSmoothChangeItem* const Value);
	
protected:
	void __fastcall DoProceed(double ADeltaTime);
	
public:
	HIDESBASE TgxNavigatorSmoothChangeItem* __fastcall Add(TgxNavigatorSmoothChangeItemClass AClass);
	virtual bool __fastcall CanAdd(Gxs::Xcollection::TXCollectionItemClass AClass);
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	__property TgxNavigatorSmoothChangeItem* Items[const int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TXCollection.Create */ inline __fastcall virtual TgxNavigatorSmoothChangeItems(System::Classes::TPersistent* aOwner) : Gxs::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxNavigatorSmoothChangeItems() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorAdjustDistanceParameters : public TgxNavigatorAbstractParameters
{
	typedef TgxNavigatorAbstractParameters inherited;
	
private:
	float FOldDistanceRatio;
	float FImpulseSpeed;
	bool __fastcall StoreImpulseSpeed();
	
public:
	__fastcall virtual TgxNavigatorAdjustDistanceParameters(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ScaleParameters(const float Value);
	virtual void __fastcall AddImpulse(const float Impulse);
	
__published:
	__property float ImpulseSpeed = {read=FImpulseSpeed, write=FImpulseSpeed, stored=StoreImpulseSpeed};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorAdjustDistanceParameters() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorAdjustDistanceParametersEx : public TgxNavigatorAbstractParameters
{
	typedef TgxNavigatorAbstractParameters inherited;
	
private:
	float FSpeedLimit;
	float FTargetDistance;
	bool __fastcall StoreSpeedLimit();
	bool __fastcall StoreTargetDistance();
	
protected:
	virtual bool __fastcall StoreSpeed();
	virtual bool __fastcall StoreInertia();
	
public:
	__fastcall virtual TgxNavigatorAdjustDistanceParametersEx(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float TargetDistance = {read=FTargetDistance, write=FTargetDistance, stored=StoreTargetDistance};
	__property float SpeedLimit = {read=FSpeedLimit, write=FSpeedLimit, stored=StoreSpeedLimit};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorAdjustDistanceParametersEx() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorInertiaParameters : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	float OldTurnHorizontalAngle;
	float OldTurnVerticalAngle;
	float OldMoveForwardDistance;
	float OldStrafeHorizontalDistance;
	float OldStrafeVerticalDistance;
	float FTurnInertia;
	float FTurnSpeed;
	float FTurnMaxAngle;
	float FMovementAcceleration;
	float FMovementInertia;
	float FMovementSpeed;
	bool __fastcall StoreTurnMaxAngle();
	bool __fastcall StoreMovementAcceleration();
	bool __fastcall StoreMovementInertia();
	bool __fastcall StoreMovementSpeed();
	bool __fastcall StoreTurnInertia();
	bool __fastcall StoreTurnSpeed();
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TgxNavigatorInertiaParameters(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ScaleParameters(const float Value);
	
__published:
	__property float MovementAcceleration = {read=FMovementAcceleration, write=FMovementAcceleration, stored=StoreMovementAcceleration};
	__property float MovementInertia = {read=FMovementInertia, write=FMovementInertia, stored=StoreMovementInertia};
	__property float MovementSpeed = {read=FMovementSpeed, write=FMovementSpeed, stored=StoreMovementSpeed};
	__property float TurnMaxAngle = {read=FTurnMaxAngle, write=FTurnMaxAngle, stored=StoreTurnMaxAngle};
	__property float TurnInertia = {read=FTurnInertia, write=FTurnInertia, stored=StoreTurnInertia};
	__property float TurnSpeed = {read=FTurnSpeed, write=FTurnSpeed, stored=StoreTurnSpeed};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorInertiaParameters() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNavigatorGeneralParameters : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	float FAutoScaleMin;
	float FAutoScaleMax;
	float FAutoScaleMult;
	bool __fastcall StoreAutoScaleMax();
	bool __fastcall StoreAutoScaleMin();
	bool __fastcall StoreAutoScaleMult();
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TgxNavigatorGeneralParameters(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float AutoScaleMin = {read=FAutoScaleMin, write=FAutoScaleMin, stored=StoreAutoScaleMin};
	__property float AutoScaleMax = {read=FAutoScaleMax, write=FAutoScaleMax, stored=StoreAutoScaleMax};
	__property float AutoScaleMult = {read=FAutoScaleMult, write=FAutoScaleMult, stored=StoreAutoScaleMult};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorGeneralParameters() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxNavigatorMoveAroundParameters : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	Gxs::Scene::TgxBaseSceneObject* FTargetObject;
	float FOldPitchInertiaAngle;
	float FOldTurnInertiaAngle;
	float FPitchSpeed;
	float FTurnSpeed;
	float FInertia;
	float FMaxAngle;
	double FCutoff;
	bool __fastcall StoreInertia();
	bool __fastcall StoreMaxAngle();
	bool __fastcall StorePitchSpeed();
	bool __fastcall StoreTurnSpeed();
	void __fastcall SetTargetObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	bool __fastcall StoreCutoff();
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TgxNavigatorMoveAroundParameters(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ScaleParameters(const float Value);
	
__published:
	__property float Inertia = {read=FInertia, write=FInertia, stored=StoreInertia};
	__property float MaxAngle = {read=FMaxAngle, write=FMaxAngle, stored=StoreMaxAngle};
	__property float PitchSpeed = {read=FPitchSpeed, write=FPitchSpeed, stored=StorePitchSpeed};
	__property float TurnSpeed = {read=FTurnSpeed, write=FTurnSpeed, stored=StoreTurnSpeed};
	__property Gxs::Scene::TgxBaseSceneObject* TargetObject = {read=FTargetObject, write=SetTargetObject};
	__property double Cutoff = {read=FCutoff, write=FCutoff, stored=StoreCutoff};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxNavigatorMoveAroundParameters() { }
	
};


class PASCALIMPLEMENTATION TgxSmoothNavigator : public Gxs::Navigator::TgxNavigator
{
	typedef Gxs::Navigator::TgxNavigator inherited;
	
private:
	double FMaxExpectedDeltaTime;
	TgxNavigatorInertiaParameters* FInertiaParams;
	TgxNavigatorGeneralParameters* FGeneralParams;
	TgxNavigatorMoveAroundParameters* FMoveAroundParams;
	TgxNavigatorAdjustDistanceParameters* FAdjustDistanceParams;
	TgxNavigatorAdjustDistanceParametersEx* FAdjustDistanceParamsEx;
	TgxNavigatorSmoothChangeItems* FCustomAnimatedItems;
	void __fastcall SetInertiaParams(TgxNavigatorInertiaParameters* const Value);
	bool __fastcall StoreMaxExpectedDeltaTime();
	void __fastcall SetGeneralParams(TgxNavigatorGeneralParameters* const Value);
	void __fastcall SetMoveAroundParams(TgxNavigatorMoveAroundParameters* const Value);
	void __fastcall SetAdjustDistanceParams(TgxNavigatorAdjustDistanceParameters* const Value);
	void __fastcall SetAdjustDistanceParamsEx(TgxNavigatorAdjustDistanceParametersEx* const Value);
	void __fastcall SetCustomAnimatedItems(TgxNavigatorSmoothChangeItems* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxSmoothNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSmoothNavigator();
	virtual void __fastcall SetObject(Gxs::Scene::TgxBaseSceneObject* Value);
	HIDESBASE virtual void __fastcall TurnHorizontal(float Angle, double ADeltaTime);
	HIDESBASE virtual void __fastcall TurnVertical(float Angle, double ADeltaTime);
	HIDESBASE virtual void __fastcall FlyForward(const bool Plus, const bool Minus, double ADeltaTime, const bool Accelerate = false);
	HIDESBASE virtual void __fastcall MoveForward(const bool Plus, const bool Minus, double ADeltaTime, const bool Accelerate = false);
	HIDESBASE virtual void __fastcall StrafeHorizontal(const bool Plus, const bool Minus, double ADeltaTime, const bool Accelerate = false);
	HIDESBASE virtual void __fastcall StrafeVertical(const bool Plus, const bool Minus, double ADeltaTime, const bool Accelerate = false);
	virtual bool __fastcall MoveAroundTarget(const float PitchDelta, const float TurnDelta, const double ADeltaTime);
	virtual bool __fastcall MoveObjectAround(Gxs::Scene::TgxBaseSceneObject* const AObject, float PitchDelta, float TurnDelta, double ADeltaTime);
	virtual bool __fastcall AdjustDistanceToPoint(const Stage::Vectortypes::TVector4f &APoint, const float DistanceRatio, double ADeltaTime);
	virtual bool __fastcall AdjustDistanceToTarget(const float DistanceRatio, const double ADeltaTime);
	virtual bool __fastcall AdjustDistanceToPointEx(const Stage::Vectortypes::TVector4f &APoint, double ADeltaTime);
	virtual bool __fastcall AdjustDistanceToTargetEx(const double ADeltaTime);
	virtual void __fastcall AnimateCustomItems(const double ADeltaTime);
	virtual void __fastcall ScaleParameters(const float Value);
	virtual void __fastcall AutoScaleParameters(const float FPS);
	virtual void __fastcall AutoScaleParametersUp(const float FPS);
	
__published:
	__property double MaxExpectedDeltaTime = {read=FMaxExpectedDeltaTime, write=FMaxExpectedDeltaTime, stored=StoreMaxExpectedDeltaTime};
	__property TgxNavigatorInertiaParameters* InertiaParams = {read=FInertiaParams, write=SetInertiaParams};
	__property TgxNavigatorGeneralParameters* GeneralParams = {read=FGeneralParams, write=SetGeneralParams};
	__property TgxNavigatorMoveAroundParameters* MoveAroundParams = {read=FMoveAroundParams, write=SetMoveAroundParams};
	__property TgxNavigatorAdjustDistanceParameters* AdjustDistanceParams = {read=FAdjustDistanceParams, write=SetAdjustDistanceParams};
	__property TgxNavigatorAdjustDistanceParametersEx* AdjustDistanceParamsEx = {read=FAdjustDistanceParamsEx, write=SetAdjustDistanceParamsEx};
	__property TgxNavigatorSmoothChangeItems* CustomAnimatedItems = {read=FCustomAnimatedItems, write=SetCustomAnimatedItems};
};


class PASCALIMPLEMENTATION TgxSmoothUserInterface : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FAutoUpdateMouse;
	bool FMouseLookActive;
	TgxSmoothNavigator* FSmoothNavigator;
	TgxSmoothNavigator* FSmoothVertNavigator;
	bool FInvertMouse;
	Gxs::Coordinates::TgxCoordinates2* FOriginalMousePos;
	virtual void __fastcall SetSmoothNavigator(TgxSmoothNavigator* const Value);
	virtual void __fastcall SetOriginalMousePos(Gxs::Coordinates::TgxCoordinates2* const Value);
	virtual void __fastcall SetSmoothVertNavigator(TgxSmoothNavigator* const Value);
	virtual void __fastcall SetMouseLookActive(const bool Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxSmoothUserInterface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSmoothUserInterface();
	virtual void __fastcall TurnHorizontal(const float Angle, const double ADeltaTime);
	virtual void __fastcall TurnVertical(const float Angle, const double ADeltaTime);
	virtual void __fastcall MouseLookActiveToggle();
	bool __fastcall MouseLook(const double ADeltaTime)/* overload */;
	bool __fastcall MouseLook(const System::Types::TPoint &NewXY, const double ADeltaTime)/* overload */;
	bool __fastcall MouseLook(const int NewX, const int NewY, const double ADeltaTime)/* overload */;
	
__published:
	__property bool AutoUpdateMouse = {read=FAutoUpdateMouse, write=FAutoUpdateMouse, default=1};
	__property bool MouseLookActive = {read=FMouseLookActive, write=SetMouseLookActive, default=0};
	__property TgxSmoothNavigator* SmoothVertNavigator = {read=FSmoothVertNavigator, write=SetSmoothVertNavigator};
	__property TgxSmoothNavigator* SmoothNavigator = {read=FSmoothNavigator, write=SetSmoothNavigator};
	__property bool InvertMouse = {read=FInvertMouse, write=FInvertMouse, default=0};
	__property Gxs::Coordinates::TgxCoordinates2* OriginalMousePos = {read=FOriginalMousePos, write=SetOriginalMousePos};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Smoothnavigator */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SMOOTHNAVIGATOR)
using namespace Gxs::Smoothnavigator;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SmoothNavigatorHPP
