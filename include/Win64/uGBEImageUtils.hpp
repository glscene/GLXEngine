// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uGBEImageUtils.pas' rev: 36.00 (Windows)

#ifndef uGBEImageUtilsHPP
#define uGBEImageUtilsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <System.SysUtils.hpp>
#include <System.UIConsts.hpp>
#include <System.Types.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Graphics.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ugbeimageutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* TextureCanalNoir;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* TextureCanalRouge;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* TextureCanalVert;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* TextureCanalBleu;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmapData BitmapDataCanalNoir;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmapData BitmapDataCanalRouge;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmapData BitmapDataCanalVert;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmapData BitmapDataCanalBleu;
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall GenerateDiamondSquare(int size, int blurLevel, System::Uitypes::TAlphaColor color = (System::Uitypes::TAlphaColor)(0xffffffff), bool bordure = false, System::Uitypes::TAlphaColor colorBordure = (System::Uitypes::TAlphaColor)(0xff000000));
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall TileImage(Fmx::Graphics::TBitmap* imageOrigine, int nbX, int nbY);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall CropImage(Fmx::Graphics::TBitmap* originBitmap, int Xpos, int Ypos, int width, int height);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall MultiTexturing(Fmx::Graphics::TBitmap* imgCarte, Fmx::Graphics::TBitmap* imgFond, Fmx::Graphics::TBitmap* imgCanalRouge, Fmx::Graphics::TBitmap* imgCanalVert, Fmx::Graphics::TBitmap* imgCanalBleu, int tailleCrop);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall MultiTexturingZone(Fmx::Graphics::TBitmap* img);
extern DELPHI_PACKAGE System::Uitypes::TAlphaColor __fastcall MixerCouleurPixel(System::Uitypes::TAlphaColor cCarte, int x, int y);
}	/* namespace Ugbeimageutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UGBEIMAGEUTILS)
using namespace Ugbeimageutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uGBEImageUtilsHPP
