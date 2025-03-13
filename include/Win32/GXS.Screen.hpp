// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Screen.pas' rev: 36.00 (Windows)

#ifndef GXS_ScreenHPP
#define GXS_ScreenHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Forms.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Screen
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxDisplayOptions;
struct TgxVideoMode;
//-- type declarations -------------------------------------------------------
typedef System::Byte TResolution;

enum DECLSPEC_DENUM TgxWindowAttribute : unsigned char { woDesktop, woStayOnTop, woTransparent };

typedef System::Set<TgxWindowAttribute, TgxWindowAttribute::woDesktop, TgxWindowAttribute::woTransparent> TgxWindowAttributes;

enum DECLSPEC_DENUM TgxWindowFitting : unsigned char { wfDefault, wfFitWindowToScreen, wfFitScreenToWindow };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxDisplayOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FFullScreen;
	TResolution FScreenResolution;
	TgxWindowAttributes FWindowAttributes;
	TgxWindowFitting FWindowFitting;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool FullScreen = {read=FFullScreen, write=FFullScreen, default=0};
	__property TResolution ScreenResolution = {read=FScreenResolution, write=FScreenResolution, default=0};
	__property TgxWindowAttributes WindowAttributes = {read=FWindowAttributes, write=FWindowAttributes, default=0};
	__property TgxWindowFitting WindowFitting = {read=FWindowFitting, write=FWindowFitting, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxDisplayOptions() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxDisplayOptions() : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxVideoMode
{
public:
	System::Word Width;
	System::Word Height;
	System::Byte ColorDepth;
	System::Byte MaxFrequency;
	System::UnicodeString Description;
};
#pragma pack(pop)


typedef TgxVideoMode *PgxVideoMode;

typedef System::DynamicArray<TgxVideoMode> Gxs_Screen__2;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte MaxVideoModes = System::Byte(0xc8);
static _DELPHI_CONST System::Int8 lcl_release = System::Int8(0x0);
extern DELPHI_PACKAGE int vNumberVideoModes;
extern DELPHI_PACKAGE int vCurrentVideoMode;
extern DELPHI_PACKAGE Gxs_Screen__2 vVideoModes;
extern DELPHI_PACKAGE TResolution __fastcall GetIndexFromResolution(int XRes, int YRes, int BPP);
extern DELPHI_PACKAGE void __fastcall ReadVideoModes(void);
extern DELPHI_PACKAGE bool __fastcall SetFullscreenMode(TResolution modeIndex, int displayFrequency = 0x0);
extern DELPHI_PACKAGE void __fastcall ReadScreenImage(HDC Dest, int DestLeft, int DestTop, const Stage::Vectorgeometry::TRectangle &SrcRect);
extern DELPHI_PACKAGE void __fastcall RestoreDefaultMode(void);
extern DELPHI_PACKAGE void __fastcall GLShowCursor(bool AShow);
extern DELPHI_PACKAGE void __fastcall GLSetCursorPos(int AScreenX, int AScreenY);
extern DELPHI_PACKAGE void __fastcall GLGetCursorPos(Winapi::Windows::TPoint &point);
extern DELPHI_PACKAGE int __fastcall GLGetScreenWidth(void);
extern DELPHI_PACKAGE int __fastcall GLGetScreenHeight(void);
}	/* namespace Screen */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SCREEN)
using namespace Gxs::Screen;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ScreenHPP
