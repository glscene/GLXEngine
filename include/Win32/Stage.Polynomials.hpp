// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Polynomials.pas' rev: 36.00 (Windows)

#ifndef Stage_PolynomialsHPP
#define Stage_PolynomialsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Polynomials
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<double> TDoubleArray;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE double __fastcall EvalPolynom(const TDoubleArray poly, const double x);
extern DELPHI_PACKAGE TDoubleArray __fastcall DerivatedPolynom(const TDoubleArray poly);
extern DELPHI_PACKAGE double __fastcall FindRoot(const TDoubleArray poly, double min, double max, double epsilon);
extern DELPHI_PACKAGE bool __fastcall MinPositiveCoef(const TDoubleArray coefs, double &aMin);
extern DELPHI_PACKAGE double __fastcall cbrt(const double x);
extern DELPHI_PACKAGE TDoubleArray __fastcall SolveQuadric(const Stage::Vectorgeometry::PDoubleArray c);
extern DELPHI_PACKAGE TDoubleArray __fastcall SolveCubic(const Stage::Vectorgeometry::PDoubleArray c);
extern DELPHI_PACKAGE TDoubleArray __fastcall SolveQuartic(const Stage::Vectorgeometry::PDoubleArray c);
}	/* namespace Polynomials */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_POLYNOMIALS)
using namespace Stage::Polynomials;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_PolynomialsHPP
