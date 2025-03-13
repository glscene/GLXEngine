// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.AnimationUtils.pas' rev: 36.00 (Windows)

#ifndef Stage_AnimationUtilsHPP
#define Stage_AnimationUtilsHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Animationutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TEaseType : unsigned char { etLinear, etQuadIn, etQuadOut, etQuadInOut, etQuadOutIn, etCubicIn, etCubicOut, etCubicInOut, etCubicOutIn, etQuintIn, etQuintOut, etQuintInOut, etQuintOutIn, etSineIn, etSineOut, etSineInOut, etSineOutIn, etCircIn, etCircOut, etCircInOut, etCircOutIn, etExpoIn, etExpoOut, etExpoInOut, etExpoOutIn, etElasticIn, etElasticOut, etElasticInOut, etElasticOutIn, etBackIn, etBackOut, etBackInOut, etBackOutIn, etBounceIn, etBounceOut, etBounceInOut, etBounceOutIn };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall Tweener(const Stage::Vectorgeometry::TAffineVector &Current, const Stage::Vectorgeometry::TAffineVector &Target, float Time, float Duration, TEaseType EaseType)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall Tweener(const Stage::Vectortypes::TGLVector &Current, const Stage::Vectortypes::TGLVector &Target, float Time, float Duration, TEaseType EaseType)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall Tweener(const Stage::Vectortypes::TVector2f &Current, const Stage::Vectortypes::TVector2f &Target, float Time, float Duration, TEaseType EaseType)/* overload */;
extern DELPHI_PACKAGE float __fastcall Tweener(float Current, float Target, float Time, float Duration, TEaseType EaseType)/* overload */;
}	/* namespace Animationutils */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_ANIMATIONUTILS)
using namespace Stage::Animationutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_AnimationUtilsHPP
