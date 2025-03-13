// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.PlayerPosition.pas' rev: 36.00 (Windows)

#ifndef GBE_PlayerPositionHPP
#define GBE_PlayerPositionHPP

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
#include <System.Math.Vectors.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Playerposition
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBEPlayerPosition;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGBETypePosition : unsigned char { firstPerson, thirdPerson, other };

class PASCALIMPLEMENTATION TGBEPlayerPosition : public Fmx::Objects3d::TDummy
{
	typedef Fmx::Objects3d::TDummy inherited;
	
private:
	Fmx::Objects3d::TDummy* fDummyOrientation;
	Fmx::Objects3d::TDummy* fNextPosition;
	Fmx::Objects3d::TDummy* fPositionDirection;
	Fmx::Controls3d::TCamera* fCamera;
	TGBETypePosition fTypePosition;
	float fWidth;
	float fDepth;
	float fHeight;
	System::Math::Vectors::TPoint3D __fastcall GetPositionCamera();
	void __fastcall SetPositionCamera(const System::Math::Vectors::TPoint3D &Value);
	float __fastcall GetAngleOfView();
	void __fastcall SetAngleOfView(const float Value);
	void __fastcall SetTypePosition(const TGBETypePosition Value);
	HIDESBASE void __fastcall SetWidth(const float Value);
	HIDESBASE void __fastcall SetDepth(const float Value);
	HIDESBASE void __fastcall SetHeight(const float Value);
	
public:
	__fastcall virtual TGBEPlayerPosition(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEPlayerPosition();
	Fmx::Objects3d::TDummy* __fastcall GetDummyOrientation();
	Fmx::Controls3d::TCamera* __fastcall GetCamera();
	Fmx::Objects3d::TDummy* __fastcall GetPositionDirection();
	__property System::Math::Vectors::TPoint3D PositionCameraThirdPerson = {read=GetPositionCamera, write=SetPositionCamera};
	
__published:
	__property float AngleOfView = {read=GetAngleOfView, write=SetAngleOfView};
	__property TGBETypePosition TypePosition = {read=fTypePosition, write=SetTypePosition, nodefault};
	__property Fmx::Objects3d::TDummy* NextPosition = {read=fNextPosition, write=fNextPosition};
	__property HitTest = {default=0};
	__property float Width = {read=fWidth, write=SetWidth};
	__property float Height = {read=fHeight, write=SetHeight};
	__property float Depth = {read=fDepth, write=SetDepth};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Playerposition */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_PLAYERPOSITION)
using namespace Gbe::Playerposition;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_PlayerPositionHPP
