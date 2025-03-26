// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Color.pas' rev: 36.00 (Windows)

#ifndef GXS_ColorHPP
#define GXS_ColorHPP

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
#include <System.UITypes.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Color
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxColor;
struct TgxColorEntry;
class DELPHICLASS TgxColorManager;
//-- type declarations -------------------------------------------------------
typedef Stage::Vectortypes::TVector4f *PgxColorVector;

typedef Stage::Vectortypes::TVector4f TgxColorVector;

typedef Stage::Vectortypes::TVector3b *PRGBColor;

typedef Stage::Vectortypes::TVector3b TRGBColor;

class PASCALIMPLEMENTATION TgxColor : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	TgxColorVector FColor;
	PgxColorVector FPDefaultColor;
	void __fastcall SetColorVector(const TgxColorVector &aColor)/* overload */;
	void __fastcall SetColorComponent(int index, float value);
	float __fastcall GetColorComponent(const int index);
	void __fastcall SetAsWinColor(const System::Uitypes::TColor val);
	System::Uitypes::TColor __fastcall GetAsWinColor();
	void __fastcall SetDirectColorVector(const TgxColorVector &aColor);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	Stage::Vectortypes::TGLVector __fastcall GetHSVA();
	void __fastcall SetHSVA(const Stage::Vectortypes::TGLVector &hsva);
	
public:
	__fastcall virtual TgxColor(System::Classes::TPersistent* AOwner);
	__fastcall TgxColor(System::Classes::TPersistent* AOwner, const TgxColorVector &Color, System::Classes::TNotifyEvent changeEvent);
	__fastcall virtual ~TgxColor();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Initialize(const TgxColorVector &color);
	System::PSingle __fastcall AsAddress();
	void __fastcall RandomColor();
	void __fastcall SetColor(float Red, float Green, float Blue, float Alpha = 1.000000E+00f)/* overload */;
	__property TgxColorVector Color = {read=FColor, write=SetColorVector};
	__property TgxColorVector DirectColor = {read=FColor, write=SetDirectColorVector};
	__property System::Uitypes::TColor AsWinColor = {read=GetAsWinColor, write=SetAsWinColor, nodefault};
	__property Stage::Vectortypes::TGLVector hsva = {read=GetHSVA, write=SetHSVA};
	__property TgxColorVector DefaultColor = {read=FColor};
	
__published:
	__property float Red = {read=GetColorComponent, write=SetColorComponent, stored=false, index=0};
	__property float Green = {read=GetColorComponent, write=SetColorComponent, stored=false, index=1};
	__property float Blue = {read=GetColorComponent, write=SetColorComponent, stored=false, index=2};
	__property float Alpha = {read=GetColorComponent, write=SetColorComponent, stored=false, index=3};
};


typedef TgxColorEntry *PgxColorEntry;

struct DECLSPEC_DRECORD TgxColorEntry
{
public:
	System::UnicodeString Name;
	TgxColorVector Color;
};


class PASCALIMPLEMENTATION TgxColorManager : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	__fastcall virtual ~TgxColorManager();
	void __fastcall AddColor(const System::UnicodeString aName, const TgxColorVector &aColor);
	void __fastcall EnumColors(System::Classes::TGetStrProc Proc)/* overload */;
	void __fastcall EnumColors(System::Classes::TStrings* AValues)/* overload */;
	TgxColorVector __fastcall FindColor(const System::UnicodeString aName);
	TgxColorVector __fastcall GetColor(const System::UnicodeString aName);
	System::UnicodeString __fastcall GetColorName(const TgxColorVector &aColor);
	void __fastcall RegisterDefaultColors();
	void __fastcall RemoveColor(const System::UnicodeString aName);
public:
	/* TObject.Create */ inline __fastcall TgxColorManager() : System::Classes::TList() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Uitypes::TColor clForeground = System::Uitypes::TColor(-1);
static _DELPHI_CONST System::Uitypes::TColor clButton = System::Uitypes::TColor(-2);
static _DELPHI_CONST System::Uitypes::TColor clLight = System::Uitypes::TColor(-3);
static _DELPHI_CONST System::Uitypes::TColor clMidlight = System::Uitypes::TColor(-4);
static _DELPHI_CONST System::Uitypes::TColor clDark = System::Uitypes::TColor(-5);
static _DELPHI_CONST System::Uitypes::TColor clMid = System::Uitypes::TColor(-6);
static _DELPHI_CONST System::Uitypes::TColor clText = System::Uitypes::TColor(-7);
static _DELPHI_CONST System::Uitypes::TColor clBrightText = System::Uitypes::TColor(-8);
static _DELPHI_CONST System::Uitypes::TColor clButtonText = System::Uitypes::TColor(-9);
static _DELPHI_CONST System::Uitypes::TColor clBase = System::Uitypes::TColor(-10);
static _DELPHI_CONST System::Uitypes::TColor clBackground = System::Uitypes::TColor(-11);
static _DELPHI_CONST System::Uitypes::TColor clShadow = System::Uitypes::TColor(-12);
static _DELPHI_CONST System::Uitypes::TColor clHighlight = System::Uitypes::TColor(-13);
static _DELPHI_CONST System::Uitypes::TColor clHighlightedText = System::Uitypes::TColor(-14);
static _DELPHI_CONST System::Int8 cloNormal = System::Int8(0x20);
static _DELPHI_CONST System::Int8 cloDisabled = System::Int8(0x40);
static _DELPHI_CONST System::Int8 cloActive = System::Int8(0x60);
static _DELPHI_CONST System::Uitypes::TColor clNormalForeground = System::Uitypes::TColor(-33);
static _DELPHI_CONST System::Uitypes::TColor clNormalButton = System::Uitypes::TColor(-34);
static _DELPHI_CONST System::Uitypes::TColor clNormalLight = System::Uitypes::TColor(-35);
static _DELPHI_CONST System::Uitypes::TColor clNormalMidlight = System::Uitypes::TColor(-36);
static _DELPHI_CONST System::Uitypes::TColor clNormalDark = System::Uitypes::TColor(-37);
static _DELPHI_CONST System::Uitypes::TColor clNormalMid = System::Uitypes::TColor(-38);
static _DELPHI_CONST System::Uitypes::TColor clNormalText = System::Uitypes::TColor(-39);
static _DELPHI_CONST System::Uitypes::TColor clNormalBrightText = System::Uitypes::TColor(-40);
static _DELPHI_CONST System::Uitypes::TColor clNormalButtonText = System::Uitypes::TColor(-41);
static _DELPHI_CONST System::Uitypes::TColor clNormalBase = System::Uitypes::TColor(-42);
static _DELPHI_CONST System::Uitypes::TColor clNormalBackground = System::Uitypes::TColor(-43);
static _DELPHI_CONST System::Uitypes::TColor clNormalShadow = System::Uitypes::TColor(-44);
static _DELPHI_CONST System::Uitypes::TColor clNormalHighlight = System::Uitypes::TColor(-45);
static _DELPHI_CONST System::Uitypes::TColor clNormalHighlightedText = System::Uitypes::TColor(-46);
static _DELPHI_CONST System::Uitypes::TColor clDisabledForeground = System::Uitypes::TColor(-65);
static _DELPHI_CONST System::Uitypes::TColor clDisabledButton = System::Uitypes::TColor(-66);
static _DELPHI_CONST System::Uitypes::TColor clDisabledLight = System::Uitypes::TColor(-67);
static _DELPHI_CONST System::Uitypes::TColor clDisabledMidlight = System::Uitypes::TColor(-68);
static _DELPHI_CONST System::Uitypes::TColor clDisabledDark = System::Uitypes::TColor(-69);
static _DELPHI_CONST System::Uitypes::TColor clDisabledMid = System::Uitypes::TColor(-70);
static _DELPHI_CONST System::Uitypes::TColor clDisabledText = System::Uitypes::TColor(-71);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBrightText = System::Uitypes::TColor(-72);
static _DELPHI_CONST System::Uitypes::TColor clDisabledButtonText = System::Uitypes::TColor(-73);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBase = System::Uitypes::TColor(-74);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBackground = System::Uitypes::TColor(-75);
static _DELPHI_CONST System::Uitypes::TColor clDisabledShadow = System::Uitypes::TColor(-76);
static _DELPHI_CONST System::Uitypes::TColor clDisabledHighlight = System::Uitypes::TColor(-77);
static _DELPHI_CONST System::Uitypes::TColor clDisabledHighlightedText = System::Uitypes::TColor(-78);
static _DELPHI_CONST System::Uitypes::TColor clActiveForeground = System::Uitypes::TColor(-97);
static _DELPHI_CONST System::Uitypes::TColor clActiveButton = System::Uitypes::TColor(-98);
static _DELPHI_CONST System::Uitypes::TColor clActiveLight = System::Uitypes::TColor(-99);
static _DELPHI_CONST System::Uitypes::TColor clActiveMidlight = System::Uitypes::TColor(-100);
static _DELPHI_CONST System::Uitypes::TColor clActiveDark = System::Uitypes::TColor(-101);
static _DELPHI_CONST System::Uitypes::TColor clActiveMid = System::Uitypes::TColor(-102);
static _DELPHI_CONST System::Uitypes::TColor clActiveText = System::Uitypes::TColor(-103);
static _DELPHI_CONST System::Uitypes::TColor clActiveBrightText = System::Uitypes::TColor(-104);
static _DELPHI_CONST System::Uitypes::TColor clActiveButtonText = System::Uitypes::TColor(-105);
static _DELPHI_CONST System::Uitypes::TColor clActiveBase = System::Uitypes::TColor(-106);
static _DELPHI_CONST System::Uitypes::TColor clActiveBackground = System::Uitypes::TColor(-107);
static _DELPHI_CONST System::Uitypes::TColor clActiveShadow = System::Uitypes::TColor(-108);
static _DELPHI_CONST System::Uitypes::TColor clActiveHighlight = System::Uitypes::TColor(-109);
static _DELPHI_CONST System::Uitypes::TColor clActiveHighlightedText = System::Uitypes::TColor(-110);
static _DELPHI_CONST System::Uitypes::TColor clFirstSpecialColor = System::Uitypes::TColor(-110);
static _DELPHI_CONST System::Uitypes::TColor clMask = System::Uitypes::TColor(0);
static _DELPHI_CONST System::Uitypes::TColor clDontMask = System::Uitypes::TColor(16777215);
extern DELPHI_PACKAGE TgxColorVector clrScrollBar;
extern DELPHI_PACKAGE TgxColorVector clrBackground;
extern DELPHI_PACKAGE TgxColorVector clrActiveCaption;
extern DELPHI_PACKAGE TgxColorVector clrInactiveCaption;
extern DELPHI_PACKAGE TgxColorVector clrMenu;
extern DELPHI_PACKAGE TgxColorVector clrWindow;
extern DELPHI_PACKAGE TgxColorVector clrWindowFrame;
extern DELPHI_PACKAGE TgxColorVector clrMenuText;
extern DELPHI_PACKAGE TgxColorVector clrWindowText;
extern DELPHI_PACKAGE TgxColorVector clrCaptionText;
extern DELPHI_PACKAGE TgxColorVector clrActiveBorder;
extern DELPHI_PACKAGE TgxColorVector clrInactiveBorder;
extern DELPHI_PACKAGE TgxColorVector clrAppWorkSpace;
extern DELPHI_PACKAGE TgxColorVector clrHighlight;
extern DELPHI_PACKAGE TgxColorVector clrHighlightText;
extern DELPHI_PACKAGE TgxColorVector clrBtnFace;
extern DELPHI_PACKAGE TgxColorVector clrBtnShadow;
extern DELPHI_PACKAGE TgxColorVector clrGrayText;
extern DELPHI_PACKAGE TgxColorVector clrBtnText;
extern DELPHI_PACKAGE TgxColorVector clrInactiveCaptionText;
extern DELPHI_PACKAGE TgxColorVector clrBtnHighlight;
extern DELPHI_PACKAGE TgxColorVector clr3DDkShadow;
extern DELPHI_PACKAGE TgxColorVector clr3DLight;
extern DELPHI_PACKAGE TgxColorVector clrInfoText;
extern DELPHI_PACKAGE TgxColorVector clrInfoBk;
extern DELPHI_PACKAGE TgxColorVector clrTransparent;
extern DELPHI_PACKAGE TgxColorVector clrBlack;
extern DELPHI_PACKAGE TgxColorVector clrGray05;
extern DELPHI_PACKAGE TgxColorVector clrGray10;
extern DELPHI_PACKAGE TgxColorVector clrGray15;
extern DELPHI_PACKAGE TgxColorVector clrGray20;
extern DELPHI_PACKAGE TgxColorVector clrGray25;
extern DELPHI_PACKAGE TgxColorVector clrGray30;
extern DELPHI_PACKAGE TgxColorVector clrGray35;
extern DELPHI_PACKAGE TgxColorVector clrGray40;
extern DELPHI_PACKAGE TgxColorVector clrGray45;
extern DELPHI_PACKAGE TgxColorVector clrGray50;
extern DELPHI_PACKAGE TgxColorVector clrGray55;
extern DELPHI_PACKAGE TgxColorVector clrGray60;
extern DELPHI_PACKAGE TgxColorVector clrGray65;
extern DELPHI_PACKAGE TgxColorVector clrGray70;
extern DELPHI_PACKAGE TgxColorVector clrGray75;
extern DELPHI_PACKAGE TgxColorVector clrGray80;
extern DELPHI_PACKAGE TgxColorVector clrGray85;
extern DELPHI_PACKAGE TgxColorVector clrGray90;
extern DELPHI_PACKAGE TgxColorVector clrGray95;
extern DELPHI_PACKAGE TgxColorVector clrWhite;
extern DELPHI_PACKAGE TgxColorVector clrDimGray;
extern DELPHI_PACKAGE TgxColorVector clrGray;
extern DELPHI_PACKAGE TgxColorVector clrLightGray;
extern DELPHI_PACKAGE TgxColorVector clrAqua;
extern DELPHI_PACKAGE TgxColorVector clrAquamarine;
extern DELPHI_PACKAGE TgxColorVector clrBakersChoc;
extern DELPHI_PACKAGE TgxColorVector clrBlue;
extern DELPHI_PACKAGE TgxColorVector clrBlueViolet;
extern DELPHI_PACKAGE TgxColorVector clrBrown;
extern DELPHI_PACKAGE TgxColorVector clrCadetBlue;
extern DELPHI_PACKAGE TgxColorVector clrCoral;
extern DELPHI_PACKAGE TgxColorVector clrCornflowerBlue;
extern DELPHI_PACKAGE TgxColorVector clrDarkGreen;
extern DELPHI_PACKAGE TgxColorVector clrDarkOliveGreen;
extern DELPHI_PACKAGE TgxColorVector clrDarkOrchid;
extern DELPHI_PACKAGE TgxColorVector clrDarkSlateBlue;
extern DELPHI_PACKAGE TgxColorVector clrDarkSlateGray;
extern DELPHI_PACKAGE TgxColorVector clrDarkSlateGrey;
extern DELPHI_PACKAGE TgxColorVector clrDarkTurquoise;
extern DELPHI_PACKAGE TgxColorVector clrFirebrick;
extern DELPHI_PACKAGE TgxColorVector clrForestGreen;
extern DELPHI_PACKAGE TgxColorVector clrFuchsia;
extern DELPHI_PACKAGE TgxColorVector clrGold;
extern DELPHI_PACKAGE TgxColorVector clrGoldenrod;
extern DELPHI_PACKAGE TgxColorVector clrGreenYellow;
extern DELPHI_PACKAGE TgxColorVector clrIndian;
extern DELPHI_PACKAGE TgxColorVector clrKhaki;
extern DELPHI_PACKAGE TgxColorVector clrLightBlue;
extern DELPHI_PACKAGE TgxColorVector clrLightSteelBlue;
extern DELPHI_PACKAGE TgxColorVector clrLime;
extern DELPHI_PACKAGE TgxColorVector clrLimeGreen;
extern DELPHI_PACKAGE TgxColorVector clrMaroon;
extern DELPHI_PACKAGE TgxColorVector clrMediumAquamarine;
extern DELPHI_PACKAGE TgxColorVector clrMediumBlue;
extern DELPHI_PACKAGE TgxColorVector clrMediumForestGreen;
extern DELPHI_PACKAGE TgxColorVector clrMediumGoldenrod;
extern DELPHI_PACKAGE TgxColorVector clrMediumOrchid;
extern DELPHI_PACKAGE TgxColorVector clrMediumSeaGreen;
extern DELPHI_PACKAGE TgxColorVector clrMediumSlateBlue;
extern DELPHI_PACKAGE TgxColorVector clrMediumSpringGreen;
extern DELPHI_PACKAGE TgxColorVector clrMediumTurquoise;
extern DELPHI_PACKAGE TgxColorVector clrMediumViolet;
extern DELPHI_PACKAGE TgxColorVector clrMediumPurple;
extern DELPHI_PACKAGE TgxColorVector clrMidnightBlue;
extern DELPHI_PACKAGE TgxColorVector clrNavy;
extern DELPHI_PACKAGE TgxColorVector clrNavyBlue;
extern DELPHI_PACKAGE TgxColorVector clrOrange;
extern DELPHI_PACKAGE TgxColorVector clrOrangeRed;
extern DELPHI_PACKAGE TgxColorVector clrOrchid;
extern DELPHI_PACKAGE TgxColorVector clrPaleGreen;
extern DELPHI_PACKAGE TgxColorVector clrPink;
extern DELPHI_PACKAGE TgxColorVector clrPlum;
extern DELPHI_PACKAGE TgxColorVector clrSalmon;
extern DELPHI_PACKAGE TgxColorVector clrSeaGreen;
extern DELPHI_PACKAGE TgxColorVector clrSienna;
extern DELPHI_PACKAGE TgxColorVector clrSkyBlue;
extern DELPHI_PACKAGE TgxColorVector clrSlateBlue;
extern DELPHI_PACKAGE TgxColorVector clrSpringGreen;
extern DELPHI_PACKAGE TgxColorVector clrSteelBlue;
extern DELPHI_PACKAGE TgxColorVector clrTan;
extern DELPHI_PACKAGE TgxColorVector clrThistle;
extern DELPHI_PACKAGE TgxColorVector clrTurquoise;
extern DELPHI_PACKAGE TgxColorVector clrViolet;
extern DELPHI_PACKAGE TgxColorVector clrVioletRed;
extern DELPHI_PACKAGE TgxColorVector clrYellowGreen;
extern DELPHI_PACKAGE TgxColorVector clrSummerSky;
extern DELPHI_PACKAGE TgxColorVector clrRichBlue;
extern DELPHI_PACKAGE TgxColorVector clrBrass;
extern DELPHI_PACKAGE TgxColorVector clrCopper;
extern DELPHI_PACKAGE TgxColorVector clrBronze;
extern DELPHI_PACKAGE TgxColorVector clrBronze2;
extern DELPHI_PACKAGE TgxColorVector clrSilver;
extern DELPHI_PACKAGE TgxColorVector clrBrightGold;
extern DELPHI_PACKAGE TgxColorVector clrOldGold;
extern DELPHI_PACKAGE TgxColorVector clrFeldspar;
extern DELPHI_PACKAGE TgxColorVector clrQuartz;
extern DELPHI_PACKAGE TgxColorVector clrNeonPink;
extern DELPHI_PACKAGE TgxColorVector clrDarkPurple;
extern DELPHI_PACKAGE TgxColorVector clrNeonBlue;
extern DELPHI_PACKAGE TgxColorVector clrCoolCopper;
extern DELPHI_PACKAGE TgxColorVector clrMandarinOrange;
extern DELPHI_PACKAGE TgxColorVector clrLightWood;
extern DELPHI_PACKAGE TgxColorVector clrMediumWood;
extern DELPHI_PACKAGE TgxColorVector clrDarkWood;
extern DELPHI_PACKAGE TgxColorVector clrSpicyPink;
extern DELPHI_PACKAGE TgxColorVector clrSemiSweetChoc;
extern DELPHI_PACKAGE TgxColorVector clrFlesh;
extern DELPHI_PACKAGE TgxColorVector clrNewTan;
extern DELPHI_PACKAGE TgxColorVector clrNewMidnightBlue;
extern DELPHI_PACKAGE TgxColorVector clrVeryDarkBrown;
extern DELPHI_PACKAGE TgxColorVector clrDarkBrown;
extern DELPHI_PACKAGE TgxColorVector clrDarkTan;
extern DELPHI_PACKAGE TgxColorVector clrGreenCopper;
extern DELPHI_PACKAGE TgxColorVector clrDkGreenCopper;
extern DELPHI_PACKAGE TgxColorVector clrDustyRose;
extern DELPHI_PACKAGE TgxColorVector clrHuntersGreen;
extern DELPHI_PACKAGE TgxColorVector clrScarlet;
extern DELPHI_PACKAGE TgxColorVector clrLightPurple;
extern DELPHI_PACKAGE TgxColorVector clrVeryLightPurple;
extern DELPHI_PACKAGE TgxColorVector clrGreen;
extern DELPHI_PACKAGE TgxColorVector clrOlive;
extern DELPHI_PACKAGE TgxColorVector clrPurple;
extern DELPHI_PACKAGE TgxColorVector clrTeal;
extern DELPHI_PACKAGE TgxColorVector clrRed;
extern DELPHI_PACKAGE TgxColorVector clrYellow;
extern DELPHI_PACKAGE TgxColorVector clrWheat;
#define cDefaultNormalMapScale  (1.250000E-01)
extern DELPHI_PACKAGE bool vUseDefaultColorSets;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall RGB2Color(const System::Byte r, const System::Byte g, const System::Byte b);
extern DELPHI_PACKAGE TgxColorManager* __fastcall ColorManager(void);
extern DELPHI_PACKAGE TgxColorVector __fastcall ConvertWinColor(System::Uitypes::TColor aColor, float Alpha = 1.000000E+00f);
extern DELPHI_PACKAGE void __fastcall InitGLSceneColors(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TgxColorVector &aColor)/* overload */;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TgxColorVector &aColor, float intensity)/* overload */;
extern DELPHI_PACKAGE TgxColorVector __fastcall ConvertRGBColor(const System::Byte *aColor, const System::NativeInt aColor_High);
extern DELPHI_PACKAGE void __fastcall RegisterColor(const System::UnicodeString aName, const TgxColorVector &aColor);
extern DELPHI_PACKAGE void __fastcall UnRegisterColor(const System::UnicodeString aName);
}	/* namespace Color */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_COLOR)
using namespace Gxs::Color;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ColorHPP
