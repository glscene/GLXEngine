// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Navigator.pas' rev: 36.00 (Windows)

#ifndef GXS_NavigatorHPP
#define GXS_NavigatorHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Screen.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Navigator
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxNavigator;
class DELPHICLASS TgxUserInterface;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxNavigator : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* FObject;
	Stage::Vectortypes::TVector4f FVirtualRight;
	Gxs::Coordinates::TgxCoordinates* FVirtualUp;
	bool FUseVirtualUp;
	bool FAutoUpdateObject;
	float FMaxAngle;
	float FMinAngle;
	float FCurrentVAngle;
	float FCurrentHAngle;
	bool FAngleLock;
	bool FMoveUpWhenMovingForward;
	bool FInvertHorizontalSteeringWhenUpsideDown;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetObject(Gxs::Scene::TgxBaseSceneObject* NewObject);
	void __fastcall SetUseVirtualUp(bool UseIt);
	void __fastcall SetVirtualUp(Gxs::Coordinates::TgxCoordinates* Up);
	Stage::Vectortypes::TVector4f __fastcall CalcRight();
	
public:
	__fastcall virtual TgxNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxNavigator();
	void __fastcall TurnHorizontal(float Angle);
	void __fastcall TurnVertical(float Angle);
	void __fastcall MoveForward(float Distance);
	void __fastcall StrafeHorizontal(float Distance);
	void __fastcall StrafeVertical(float Distance);
	void __fastcall Straighten();
	void __fastcall FlyForward(float Distance);
	void __fastcall LoadState(System::Classes::TStream* Stream);
	void __fastcall SaveState(System::Classes::TStream* Stream);
	__property float CurrentVAngle = {read=FCurrentVAngle};
	__property float CurrentHAngle = {read=FCurrentHAngle};
	
__published:
	__property bool MoveUpWhenMovingForward = {read=FMoveUpWhenMovingForward, write=FMoveUpWhenMovingForward, default=0};
	__property bool InvertHorizontalSteeringWhenUpsideDown = {read=FInvertHorizontalSteeringWhenUpsideDown, write=FInvertHorizontalSteeringWhenUpsideDown, default=0};
	__property Gxs::Coordinates::TgxCoordinates* VirtualUp = {read=FVirtualUp, write=SetVirtualUp};
	__property Gxs::Scene::TgxBaseSceneObject* MovingObject = {read=FObject, write=SetObject};
	__property bool UseVirtualUp = {read=FUseVirtualUp, write=SetUseVirtualUp, default=0};
	__property bool AutoUpdateObject = {read=FAutoUpdateObject, write=FAutoUpdateObject, default=0};
	__property float MaxAngle = {read=FMaxAngle, write=FMaxAngle};
	__property float MinAngle = {read=FMinAngle, write=FMinAngle};
	__property bool AngleLock = {read=FAngleLock, write=FAngleLock, default=0};
};


class PASCALIMPLEMENTATION TgxUserInterface : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Types::TPoint FPrevPoint;
	int midScreenX;
	int midScreenY;
	bool FMouseActive;
	float FMouseSpeed;
	TgxNavigator* FGLNavigator;
	TgxNavigator* FGLVertNavigator;
	bool FInvertMouse;
	void __fastcall MouseInitialize();
	void __fastcall SetMouseLookActive(const bool val);
	void __fastcall setNavigator(TgxNavigator* val);
	void __fastcall setVertNavigator(TgxNavigator* val);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation operation);
	
public:
	__fastcall virtual TgxUserInterface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxUserInterface();
	void __fastcall MouseUpdate();
	bool __fastcall MouseLook();
	void __fastcall MouseLookActiveToggle();
	void __fastcall MouseLookActivate();
	void __fastcall MouseLookDeactivate();
	bool __fastcall IsMouseLookOn();
	void __fastcall TurnHorizontal(double Angle);
	void __fastcall TurnVertical(double Angle);
	__property bool MouseLookActive = {read=FMouseActive, write=SetMouseLookActive, nodefault};
	
__published:
	__property bool InvertMouse = {read=FInvertMouse, write=FInvertMouse, default=0};
	__property float MouseSpeed = {read=FMouseSpeed, write=FMouseSpeed};
	__property TgxNavigator* GLNavigator = {read=FGLNavigator, write=setNavigator};
	__property TgxNavigator* GLVertNavigator = {read=FGLVertNavigator, write=setVertNavigator};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Navigator */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_NAVIGATOR)
using namespace Gxs::Navigator;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_NavigatorHPP
