// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Navigator.pas' rev: 36.00 (Windows)

#ifndef GLS_NavigatorHPP
#define GLS_NavigatorHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Forms.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Keyboard.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.Scene.hpp>
#include <GLS.SceneViewer.hpp>
#include <GLS.Objects.hpp>
#include <GLS.GeomObjects.hpp>
#include <GLS.Context.hpp>
#include <GLS.BaseClasses.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.HUDObjects.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.Screen.hpp>
#include <GLS.Material.hpp>
#include <GLS.Texture.hpp>
#include <GLS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Navigator
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLNavigator;
class DELPHICLASS TGLUserInterface;
class DELPHICLASS TGLNaviCube;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLNavigator : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Gls::Scene::TGLBaseSceneObject* FObject;
	Stage::Vectortypes::TGLVector FVirtualRight;
	Gls::Coordinates::TGLCoordinates* FVirtualUp;
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
	virtual void __fastcall SetObject(Gls::Scene::TGLBaseSceneObject* NewObject);
	void __fastcall SetUseVirtualUp(bool UseIt);
	void __fastcall SetVirtualUp(Gls::Coordinates::TGLCoordinates* Up);
	Stage::Vectortypes::TGLVector __fastcall CalcRight();
	
public:
	__fastcall virtual TGLNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLNavigator();
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
	__property Gls::Coordinates::TGLCoordinates* VirtualUp = {read=FVirtualUp, write=SetVirtualUp};
	__property Gls::Scene::TGLBaseSceneObject* MovingObject = {read=FObject, write=SetObject};
	__property bool UseVirtualUp = {read=FUseVirtualUp, write=SetUseVirtualUp, default=0};
	__property bool AutoUpdateObject = {read=FAutoUpdateObject, write=FAutoUpdateObject, default=0};
	__property float MaxAngle = {read=FMaxAngle, write=FMaxAngle};
	__property float MinAngle = {read=FMinAngle, write=FMinAngle};
	__property bool AngleLock = {read=FAngleLock, write=FAngleLock, default=0};
};


class PASCALIMPLEMENTATION TGLUserInterface : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Types::TPoint FPrevPoint;
	int midScreenX;
	int midScreenY;
	bool FMouseActive;
	float FMouseSpeed;
	TGLNavigator* FGLNavigator;
	TGLNavigator* FGLVertNavigator;
	bool FInvertMouse;
	void __fastcall MouseInitialize();
	void __fastcall SetMouseLookActive(const bool val);
	void __fastcall setNavigator(TGLNavigator* val);
	void __fastcall setVertNavigator(TGLNavigator* val);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLUserInterface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLUserInterface();
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
	__property TGLNavigator* GLNavigator = {read=FGLNavigator, write=setNavigator};
	__property TGLNavigator* GLVertNavigator = {read=FGLVertNavigator, write=setVertNavigator};
};


class PASCALIMPLEMENTATION TGLNaviCube : public Gls::Scene::TGLBaseSceneObject
{
	typedef Gls::Scene::TGLBaseSceneObject inherited;
	
private:
	float FDelta;
	float FFps;
	float FTimer;
	float FInactiveTime;
	Gls::Objects::TGLDummyCube* FCube;
	int FSel;
	Stage::Vectortypes::TGLVector FSelPos;
	Gls::Scene::TGLCamera* FCam;
	Gls::Scene::TGLCamera* FNaviCam;
	Gls::Hudobjects::TGLHUDSprite* FHud;
	Gls::Scene::TGLMemoryViewer* FMem;
	Gls::Sceneviewer::TGLSceneViewer* FViewer;
	bool FReady;
	bool FMouse;
	bool FMouseRotation;
	System::Types::TPoint FMousePos;
	Stage::Vectortypes::TGLVector FPosAnimationStart;
	Stage::Vectortypes::TGLVector FPosAnimationEnd;
	
public:
	__fastcall TGLNaviCube(Gls::Scene::TGLBaseSceneObject* aParentOwner);
	virtual void __fastcall DoProgress(const Gls::Baseclasses::TGLProgressTimes &pt);
	virtual void __fastcall DoRender(Gls::Rendercontextinfo::TGLRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__property Gls::Sceneviewer::TGLSceneViewer* SceneViewer = {read=FViewer, write=FViewer};
	__property Gls::Scene::TGLCamera* Camera = {read=FCam, write=FCam};
	__property float FPS = {read=FFps, write=FFps};
	__property bool ActiveMouse = {read=FMouse, write=FMouse, nodefault};
	__property float InactiveTime = {read=FInactiveTime, write=FInactiveTime};
public:
	/* TGLBaseSceneObject.Create */ inline __fastcall virtual TGLNaviCube(System::Classes::TComponent* AOwner) : Gls::Scene::TGLBaseSceneObject(AOwner) { }
	/* TGLBaseSceneObject.Destroy */ inline __fastcall virtual ~TGLNaviCube() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int sW2;
extern DELPHI_PACKAGE int sH2;
}	/* namespace Navigator */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_NAVIGATOR)
using namespace Gls::Navigator;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_NavigatorHPP
