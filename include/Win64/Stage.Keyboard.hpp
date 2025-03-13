// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Keyboard.pas' rev: 36.00 (Windows)

#ifndef Stage_KeyboardHPP
#define Stage_KeyboardHPP

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
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Keyboard
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef int TVirtualKeyCode;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte VK_MOUSEWHEELUP = System::Byte(0x86);
static _DELPHI_CONST System::Byte VK_MOUSEWHEELDOWN = System::Byte(0x87);
extern DELPHI_PACKAGE int vLastWheelDelta;
extern DELPHI_PACKAGE bool __fastcall IsKeyDown(System::WideChar c)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsKeyDown(TVirtualKeyCode vk)/* overload */;
extern DELPHI_PACKAGE TVirtualKeyCode __fastcall KeyPressed(TVirtualKeyCode minVkCode = 0x0);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VirtualKeyCodeToKeyName(TVirtualKeyCode vk);
extern DELPHI_PACKAGE TVirtualKeyCode __fastcall KeyNameToVirtualKeyCode(const System::UnicodeString keyName);
extern DELPHI_PACKAGE TVirtualKeyCode __fastcall CharToVirtualKeyCode(System::WideChar c);
extern DELPHI_PACKAGE void __fastcall KeyboardNotifyWheelMoved(int wheelDelta);
}	/* namespace Keyboard */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_KEYBOARD)
using namespace Stage::Keyboard;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_KeyboardHPP
