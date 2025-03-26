// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uGBESound.pas' rev: 36.00 (Windows)

#ifndef uGBESoundHPP
#define uGBESoundHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <FMX.Media.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ugbesound
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall PlaySound(Fmx::Media::TMediaPlayer* MediaPlayer, System::UnicodeString Son, float Volume = 1.000000E+00f);
extern DELPHI_PACKAGE void __fastcall RePlaySound(Fmx::Media::TMediaPlayer* MediaPlayer, System::UnicodeString Son, float Volume = 1.000000E+00f);
}	/* namespace Ugbesound */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UGBESOUND)
using namespace Ugbesound;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uGBESoundHPP
