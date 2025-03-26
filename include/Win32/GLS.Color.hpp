// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Color.pas' rev: 36.00 (Windows)

#ifndef GLS_ColorHPP
#define GLS_ColorHPP

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
#include <GLS.PersistentClasses.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Color
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLColor;
struct TGLColorEntry;
class DELPHICLASS TGLColorManager;
//-- type declarations -------------------------------------------------------
typedef Stage::Vectortypes::TVector4f *PGLColorVector;

typedef Stage::Vectortypes::TVector4f TGLColorVector;

typedef Stage::Vectortypes::TVector3b *PRGBColor;

typedef Stage::Vectortypes::TVector3b TRGBColor;

class PASCALIMPLEMENTATION TGLColor : public Gls::Baseclasses::TGLUpdateAbleObject
{
	typedef Gls::Baseclasses::TGLUpdateAbleObject inherited;
	
private:
	TGLColorVector FColor;
	PGLColorVector FPDefaultColor;
	void __fastcall SetColorVector(const TGLColorVector &aColor)/* overload */;
	void __fastcall SetColorComponent(int index, float value);
	float __fastcall GetColorComponent(const int index);
	void __fastcall SetAsWinColor(const System::Uitypes::TColor val);
	System::Uitypes::TColor __fastcall GetAsWinColor();
	void __fastcall SetDirectColorVector(const TGLColorVector &aColor);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	Stage::Vectortypes::TGLVector __fastcall GetHSVA();
	void __fastcall SetHSVA(const Stage::Vectortypes::TGLVector &hsva);
	
public:
	__fastcall virtual TGLColor(System::Classes::TPersistent* AOwner);
	__fastcall TGLColor(System::Classes::TPersistent* AOwner, const TGLColorVector &Color, System::Classes::TNotifyEvent changeEvent);
	__fastcall virtual ~TGLColor();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Initialize(const TGLColorVector &color);
	System::PSingle __fastcall AsAddress();
	void __fastcall RandomColor();
	void __fastcall SetColor(float Red, float Green, float Blue, float Alpha = 1.000000E+00f)/* overload */;
	__property TGLColorVector Color = {read=FColor, write=SetColorVector};
	__property TGLColorVector DirectColor = {read=FColor, write=SetDirectColorVector};
	__property System::Uitypes::TColor AsWinColor = {read=GetAsWinColor, write=SetAsWinColor, nodefault};
	__property Stage::Vectortypes::TGLVector hsva = {read=GetHSVA, write=SetHSVA};
	__property TGLColorVector DefaultColor = {read=FColor};
	
__published:
	__property float Red = {read=GetColorComponent, write=SetColorComponent, stored=false, index=0};
	__property float Green = {read=GetColorComponent, write=SetColorComponent, stored=false, index=1};
	__property float Blue = {read=GetColorComponent, write=SetColorComponent, stored=false, index=2};
	__property float Alpha = {read=GetColorComponent, write=SetColorComponent, stored=false, index=3};
};


typedef TGLColorEntry *PGLColorEntry;

struct DECLSPEC_DRECORD TGLColorEntry
{
public:
	System::UnicodeString Name;
	TGLColorVector Color;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLColorManager : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	__fastcall virtual ~TGLColorManager();
	void __fastcall AddColor(const System::UnicodeString aName, const TGLColorVector &aColor);
	void __fastcall EnumColors(System::Classes::TGetStrProc Proc)/* overload */;
	void __fastcall EnumColors(System::Classes::TStrings* AValues)/* overload */;
	TGLColorVector __fastcall FindColor(const System::UnicodeString aName);
	TGLColorVector __fastcall GetColor(const System::UnicodeString aName);
	System::UnicodeString __fastcall GetColorName(const TGLColorVector &aColor);
	void __fastcall RegisterDefaultColors();
	void __fastcall RemoveColor(const System::UnicodeString aName);
public:
	/* TObject.Create */ inline __fastcall TGLColorManager() : System::Classes::TList() { }
	
};

#pragma pack(pop)

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
extern DELPHI_PACKAGE TGLColorVector clrScrollBar;
extern DELPHI_PACKAGE TGLColorVector clrBackground;
extern DELPHI_PACKAGE TGLColorVector clrActiveCaption;
extern DELPHI_PACKAGE TGLColorVector clrInactiveCaption;
extern DELPHI_PACKAGE TGLColorVector clrMenu;
extern DELPHI_PACKAGE TGLColorVector clrWindow;
extern DELPHI_PACKAGE TGLColorVector clrWindowFrame;
extern DELPHI_PACKAGE TGLColorVector clrMenuText;
extern DELPHI_PACKAGE TGLColorVector clrWindowText;
extern DELPHI_PACKAGE TGLColorVector clrCaptionText;
extern DELPHI_PACKAGE TGLColorVector clrActiveBorder;
extern DELPHI_PACKAGE TGLColorVector clrInactiveBorder;
extern DELPHI_PACKAGE TGLColorVector clrAppWorkSpace;
extern DELPHI_PACKAGE TGLColorVector clrHighlight;
extern DELPHI_PACKAGE TGLColorVector clrHighlightText;
extern DELPHI_PACKAGE TGLColorVector clrBtnFace;
extern DELPHI_PACKAGE TGLColorVector clrBtnShadow;
extern DELPHI_PACKAGE TGLColorVector clrGrayText;
extern DELPHI_PACKAGE TGLColorVector clrBtnText;
extern DELPHI_PACKAGE TGLColorVector clrInactiveCaptionText;
extern DELPHI_PACKAGE TGLColorVector clrBtnHighlight;
extern DELPHI_PACKAGE TGLColorVector clr3DDkShadow;
extern DELPHI_PACKAGE TGLColorVector clr3DLight;
extern DELPHI_PACKAGE TGLColorVector clrInfoText;
extern DELPHI_PACKAGE TGLColorVector clrInfoBk;
extern DELPHI_PACKAGE TGLColorVector clrTransparent;
extern DELPHI_PACKAGE TGLColorVector clrBlack;
extern DELPHI_PACKAGE TGLColorVector clrGray05;
extern DELPHI_PACKAGE TGLColorVector clrGray10;
extern DELPHI_PACKAGE TGLColorVector clrGray15;
extern DELPHI_PACKAGE TGLColorVector clrGray20;
extern DELPHI_PACKAGE TGLColorVector clrGray25;
extern DELPHI_PACKAGE TGLColorVector clrGray30;
extern DELPHI_PACKAGE TGLColorVector clrGray35;
extern DELPHI_PACKAGE TGLColorVector clrGray40;
extern DELPHI_PACKAGE TGLColorVector clrGray45;
extern DELPHI_PACKAGE TGLColorVector clrGray50;
extern DELPHI_PACKAGE TGLColorVector clrGray55;
extern DELPHI_PACKAGE TGLColorVector clrGray60;
extern DELPHI_PACKAGE TGLColorVector clrGray65;
extern DELPHI_PACKAGE TGLColorVector clrGray70;
extern DELPHI_PACKAGE TGLColorVector clrGray75;
extern DELPHI_PACKAGE TGLColorVector clrGray80;
extern DELPHI_PACKAGE TGLColorVector clrGray85;
extern DELPHI_PACKAGE TGLColorVector clrGray90;
extern DELPHI_PACKAGE TGLColorVector clrGray95;
extern DELPHI_PACKAGE TGLColorVector clrWhite;
extern DELPHI_PACKAGE TGLColorVector clrDimGray;
extern DELPHI_PACKAGE TGLColorVector clrGray;
extern DELPHI_PACKAGE TGLColorVector clrLightGray;
extern DELPHI_PACKAGE TGLColorVector clrAqua;
extern DELPHI_PACKAGE TGLColorVector clrAquamarine;
extern DELPHI_PACKAGE TGLColorVector clrBakersChoc;
extern DELPHI_PACKAGE TGLColorVector clrBlue;
extern DELPHI_PACKAGE TGLColorVector clrBlueViolet;
extern DELPHI_PACKAGE TGLColorVector clrBrown;
extern DELPHI_PACKAGE TGLColorVector clrCadetBlue;
extern DELPHI_PACKAGE TGLColorVector clrCoral;
extern DELPHI_PACKAGE TGLColorVector clrCornflowerBlue;
extern DELPHI_PACKAGE TGLColorVector clrDarkGreen;
extern DELPHI_PACKAGE TGLColorVector clrDarkOliveGreen;
extern DELPHI_PACKAGE TGLColorVector clrDarkOrchid;
extern DELPHI_PACKAGE TGLColorVector clrDarkSlateBlue;
extern DELPHI_PACKAGE TGLColorVector clrDarkSlateGray;
extern DELPHI_PACKAGE TGLColorVector clrDarkSlateGrey;
extern DELPHI_PACKAGE TGLColorVector clrDarkTurquoise;
extern DELPHI_PACKAGE TGLColorVector clrFirebrick;
extern DELPHI_PACKAGE TGLColorVector clrForestGreen;
extern DELPHI_PACKAGE TGLColorVector clrFuchsia;
extern DELPHI_PACKAGE TGLColorVector clrGold;
extern DELPHI_PACKAGE TGLColorVector clrGoldenrod;
extern DELPHI_PACKAGE TGLColorVector clrGreenYellow;
extern DELPHI_PACKAGE TGLColorVector clrIndian;
extern DELPHI_PACKAGE TGLColorVector clrKhaki;
extern DELPHI_PACKAGE TGLColorVector clrLightBlue;
extern DELPHI_PACKAGE TGLColorVector clrLightSteelBlue;
extern DELPHI_PACKAGE TGLColorVector clrLime;
extern DELPHI_PACKAGE TGLColorVector clrLimeGreen;
extern DELPHI_PACKAGE TGLColorVector clrMaroon;
extern DELPHI_PACKAGE TGLColorVector clrMediumAquamarine;
extern DELPHI_PACKAGE TGLColorVector clrMediumBlue;
extern DELPHI_PACKAGE TGLColorVector clrMediumForestGreen;
extern DELPHI_PACKAGE TGLColorVector clrMediumGoldenrod;
extern DELPHI_PACKAGE TGLColorVector clrMediumOrchid;
extern DELPHI_PACKAGE TGLColorVector clrMediumSeaGreen;
extern DELPHI_PACKAGE TGLColorVector clrMediumSlateBlue;
extern DELPHI_PACKAGE TGLColorVector clrMediumSpringGreen;
extern DELPHI_PACKAGE TGLColorVector clrMediumTurquoise;
extern DELPHI_PACKAGE TGLColorVector clrMediumViolet;
extern DELPHI_PACKAGE TGLColorVector clrMediumPurple;
extern DELPHI_PACKAGE TGLColorVector clrMidnightBlue;
extern DELPHI_PACKAGE TGLColorVector clrNavy;
extern DELPHI_PACKAGE TGLColorVector clrNavyBlue;
extern DELPHI_PACKAGE TGLColorVector clrOrange;
extern DELPHI_PACKAGE TGLColorVector clrOrangeRed;
extern DELPHI_PACKAGE TGLColorVector clrOrchid;
extern DELPHI_PACKAGE TGLColorVector clrPaleGreen;
extern DELPHI_PACKAGE TGLColorVector clrPink;
extern DELPHI_PACKAGE TGLColorVector clrPlum;
extern DELPHI_PACKAGE TGLColorVector clrSalmon;
extern DELPHI_PACKAGE TGLColorVector clrSeaGreen;
extern DELPHI_PACKAGE TGLColorVector clrSienna;
extern DELPHI_PACKAGE TGLColorVector clrSkyBlue;
extern DELPHI_PACKAGE TGLColorVector clrSlateBlue;
extern DELPHI_PACKAGE TGLColorVector clrSpringGreen;
extern DELPHI_PACKAGE TGLColorVector clrSteelBlue;
extern DELPHI_PACKAGE TGLColorVector clrTan;
extern DELPHI_PACKAGE TGLColorVector clrThistle;
extern DELPHI_PACKAGE TGLColorVector clrTurquoise;
extern DELPHI_PACKAGE TGLColorVector clrViolet;
extern DELPHI_PACKAGE TGLColorVector clrVioletRed;
extern DELPHI_PACKAGE TGLColorVector clrYellowGreen;
extern DELPHI_PACKAGE TGLColorVector clrSummerSky;
extern DELPHI_PACKAGE TGLColorVector clrRichBlue;
extern DELPHI_PACKAGE TGLColorVector clrBrass;
extern DELPHI_PACKAGE TGLColorVector clrCopper;
extern DELPHI_PACKAGE TGLColorVector clrBronze;
extern DELPHI_PACKAGE TGLColorVector clrBronze2;
extern DELPHI_PACKAGE TGLColorVector clrSilver;
extern DELPHI_PACKAGE TGLColorVector clrBrightGold;
extern DELPHI_PACKAGE TGLColorVector clrOldGold;
extern DELPHI_PACKAGE TGLColorVector clrFeldspar;
extern DELPHI_PACKAGE TGLColorVector clrQuartz;
extern DELPHI_PACKAGE TGLColorVector clrNeonPink;
extern DELPHI_PACKAGE TGLColorVector clrDarkPurple;
extern DELPHI_PACKAGE TGLColorVector clrNeonBlue;
extern DELPHI_PACKAGE TGLColorVector clrCoolCopper;
extern DELPHI_PACKAGE TGLColorVector clrMandarinOrange;
extern DELPHI_PACKAGE TGLColorVector clrLightWood;
extern DELPHI_PACKAGE TGLColorVector clrMediumWood;
extern DELPHI_PACKAGE TGLColorVector clrDarkWood;
extern DELPHI_PACKAGE TGLColorVector clrSpicyPink;
extern DELPHI_PACKAGE TGLColorVector clrSemiSweetChoc;
extern DELPHI_PACKAGE TGLColorVector clrFlesh;
extern DELPHI_PACKAGE TGLColorVector clrNewTan;
extern DELPHI_PACKAGE TGLColorVector clrNewMidnightBlue;
extern DELPHI_PACKAGE TGLColorVector clrVeryDarkBrown;
extern DELPHI_PACKAGE TGLColorVector clrDarkBrown;
extern DELPHI_PACKAGE TGLColorVector clrDarkTan;
extern DELPHI_PACKAGE TGLColorVector clrGreenCopper;
extern DELPHI_PACKAGE TGLColorVector clrDkGreenCopper;
extern DELPHI_PACKAGE TGLColorVector clrDustyRose;
extern DELPHI_PACKAGE TGLColorVector clrHuntersGreen;
extern DELPHI_PACKAGE TGLColorVector clrScarlet;
extern DELPHI_PACKAGE TGLColorVector clrLightPurple;
extern DELPHI_PACKAGE TGLColorVector clrVeryLightPurple;
extern DELPHI_PACKAGE TGLColorVector clrGreen;
extern DELPHI_PACKAGE TGLColorVector clrOlive;
extern DELPHI_PACKAGE TGLColorVector clrPurple;
extern DELPHI_PACKAGE TGLColorVector clrTeal;
extern DELPHI_PACKAGE TGLColorVector clrRed;
extern DELPHI_PACKAGE TGLColorVector clrYellow;
extern DELPHI_PACKAGE TGLColorVector clrWheat;
#define cDefaultNormalMapScale  (1.250000E-01)
extern DELPHI_PACKAGE bool vUseDefaultColorSets;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall RGB2Color(const System::Byte r, const System::Byte g, const System::Byte b);
extern DELPHI_PACKAGE TGLColorManager* __fastcall ColorManager(void);
extern DELPHI_PACKAGE TGLColorVector __fastcall ConvertWinColor(System::Uitypes::TColor aColor, float Alpha = 1.000000E+00f);
extern DELPHI_PACKAGE void __fastcall InitGLSceneColors(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TGLColorVector &aColor)/* overload */;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TGLColorVector &aColor, float intensity)/* overload */;
extern DELPHI_PACKAGE TGLColorVector __fastcall ConvertRGBColor(const System::Byte *aColor, const System::NativeInt aColor_High);
extern DELPHI_PACKAGE void __fastcall RegisterColor(const System::UnicodeString aName, const TGLColorVector &aColor);
extern DELPHI_PACKAGE void __fastcall UnRegisterColor(const System::UnicodeString aName);
}	/* namespace Color */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_COLOR)
using namespace Gls::Color;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ColorHPP
