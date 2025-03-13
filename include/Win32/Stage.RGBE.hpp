// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.RGBE.pas' rev: 36.00 (Windows)

#ifndef Stage_RGBEHPP
#define Stage_RGBEHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Rgbe
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Float2rgbe(Stage::Vectortypes::TVector4b &RGBE, const float Red, const float Green, const float Blue);
extern DELPHI_PACKAGE void __fastcall Rgbe2float(float &Red, float &Green, float &Blue, const Stage::Vectortypes::TVector4b RGBE);
extern DELPHI_PACKAGE void __fastcall LoadRLEpixels(System::Classes::TStream* Stream, System::PSingle Dst, int Scanline_width, int Num_scanlines);
extern DELPHI_PACKAGE void __fastcall LoadRGBEpixels(System::Classes::TStream* Stream, System::PSingle Dst, int Numpixels);
}	/* namespace Rgbe */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_RGBE)
using namespace Stage::Rgbe;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_RGBEHPP
