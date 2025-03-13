// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.Joystick.pas' rev: 36.00 (Windows)

#ifndef GBE_JoystickHPP
#define GBE_JoystickHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Layouts.hpp>
#include <GBE.PlayerPosition.hpp>
#include <System.Math.Vectors.hpp>
#include <System.Types.hpp>
#include <FMX.Viewport3D.hpp>
#include <System.UITypes.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Ani.hpp>
#include <uGBEUtils3D.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Joystick
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBEJoystick;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGBEJoystickType : unsigned char { jtOrientation, jtDeplacement, jtOrientationDeplacement };

class PASCALIMPLEMENTATION TGBEJoystick : public Fmx::Layouts::TLayout
{
	typedef Fmx::Layouts::TLayout inherited;
	
private:
	Gbe::Playerposition::TGBEPlayerPosition* fPlayerPosition;
	System::Types::TPointF FPosDepartCurseur;
	Fmx::Viewport3d::TViewport3D* fViewport3D;
	Fmx::Objects::TCircle* fCircle;
	Fmx::Objects::TCircle* fCircle2;
	int fSensitivity;
	bool fShowIntegrateJoystick;
	bool useJoystick;
	bool fMouseCapture;
	System::Math::Vectors::TPoint3D fPoint;
	TGBEJoystickType fJoystickType;
	System::Types::TPointF Offset;
	float fAcceleration;
	void __fastcall SetAngleDeVue(const System::Types::TPointF &Value);
	System::Math::Vectors::TPoint3D __fastcall GetDirection();
	void __fastcall SetShowIntegrateJoystick(const bool Value);
	void __fastcall SetJoystickType(const TGBEJoystickType Value);
	System::Math::Vectors::TPoint3D __fastcall GetDirectionSidewayRight();
	System::Math::Vectors::TPoint3D __fastcall GetDirectionSidewayLeft();
	bool __fastcall GetMouseCapture();
	void __fastcall SetMouseCapture(const bool Value);
	
public:
	__fastcall virtual TGBEJoystick(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEJoystick();
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, float X, float Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, float X, float Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, float X, float Y);
	virtual void __fastcall DoMouseLeave();
	virtual void __fastcall Resize();
	virtual void __fastcall Paint();
	void __fastcall InitialiserJoystick();
	float __fastcall OrientationKeyManagement(bool rightKey, bool leftKey, bool upKey, bool downKey, bool goUp, bool goDown, bool sideWayRight, bool sideWayLeft, float sensibility, float speed, float maxspeed);
	
__published:
	__property Gbe::Playerposition::TGBEPlayerPosition* PlayerPosition = {read=fPlayerPosition, write=fPlayerPosition};
	__property TGBEJoystickType JoystickType = {read=fJoystickType, write=SetJoystickType, nodefault};
	
public:
	__property System::Types::TPointF AngleDeVue = {write=SetAngleDeVue};
	__property System::Math::Vectors::TPoint3D Direction = {read=GetDirection};
	__property System::Math::Vectors::TPoint3D DirectionSidewayRight = {read=GetDirectionSidewayRight};
	__property System::Math::Vectors::TPoint3D DirectionSidewayLeft = {read=GetDirectionSidewayLeft};
	__property System::Math::Vectors::TPoint3D Deplacement = {read=fPoint, write=fPoint};
	
__published:
	__property HitTest = {default=1};
	__property Fmx::Viewport3d::TViewport3D* Viewport3D = {read=fViewport3D, write=fViewport3D};
	__property bool ShowIntegrateJoystick = {read=fShowIntegrateJoystick, write=SetShowIntegrateJoystick, nodefault};
	__property float Acceleration = {read=fAcceleration, write=fAcceleration};
	__property int Sensitivity = {read=fSensitivity, write=fSensitivity, nodefault};
	__property bool MouseCapture = {read=GetMouseCapture, write=SetMouseCapture, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Joystick */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_JOYSTICK)
using namespace Gbe::Joystick;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_JoystickHPP
