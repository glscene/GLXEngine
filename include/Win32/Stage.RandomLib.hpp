// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.RandomLib.pas' rev: 36.00 (Windows)

#ifndef Stage_RandomLibHPP
#define Stage_RandomLibHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Math.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Randomlib
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<System::Extended> TAMFloatVector;

typedef System::Extended __fastcall (*TRandomGenFunction)(void);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Extended __fastcall GenRandom(void);
extern DELPHI_PACKAGE float __fastcall RandUniform(float RLow, float RHigh)/* overload */;
extern DELPHI_PACKAGE int __fastcall RandUniform(int RLow, int RHigh)/* overload */;
extern DELPHI_PACKAGE float __fastcall RandExponent(float Mean);
extern DELPHI_PACKAGE float __fastcall RandNorm(float Mean, float StDev);
extern DELPHI_PACKAGE float __fastcall RandGauss(float Mean, float StdDev);
extern DELPHI_PACKAGE float __fastcall RandLogNorm(float Mean, float StDev);
extern DELPHI_PACKAGE float __fastcall RandEmpiric(float *X, const System::NativeInt X_High, float *Fx, const System::NativeInt Fx_High, int NClass);
extern DELPHI_PACKAGE System::Extended __fastcall Random_Normal(TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Normal(void)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Normal(const System::Extended Mean, const System::Extended StdDev, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Normal(const System::Extended Mean, const System::Extended StdDev)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_LogNormal(const System::Extended Mean, const System::Extended StdDev, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_LogNormal(const System::Extended Mean, const System::Extended StdDev)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Gamma1(const System::Extended Shape, TRandomGenFunction RandomGenerator);
extern DELPHI_PACKAGE System::Extended __fastcall Random_Gamma(const System::Extended Shape, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Gamma(const System::Extended Shape)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_ChiSq(const int DF, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_ChiSq(const int DF)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Exponential(TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Exponential(void)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Weibull(const System::Extended a, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Weibull(const System::Extended a)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Beta(const System::Extended aa, const System::Extended bb, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Beta(const System::Extended aa, const System::Extended bb)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_T(const int DF, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_T(const int DF)/* overload */;
extern DELPHI_PACKAGE void __fastcall Random_MVNorm(const TAMFloatVector h, const TAMFloatVector d, TAMFloatVector &f, TAMFloatVector &x, int &ier, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE void __fastcall Random_MVNorm(const TAMFloatVector h, const TAMFloatVector d, TAMFloatVector &f, TAMFloatVector &x, int &ier)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Inv_Gauss(const System::Extended h, const System::Extended b, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Inv_Gauss(const System::Extended h, const System::Extended b)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall LnGamma(const System::Extended x);
extern DELPHI_PACKAGE __int64 __fastcall Random_Binomial1(const int n, const System::Extended p, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Binomial1(const int n, const System::Extended p)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Binomial2(const __int64 n, const System::Extended pp, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Binomial2(const __int64 n, const System::Extended pp)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Neg_Binomial(const System::Extended sk, const System::Extended p, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Neg_Binomial(const System::Extended sk, const System::Extended p)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_von_Mises(const System::Extended k, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_von_Mises(const System::Extended k)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Cauchy(TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall Random_Cauchy(void)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Poisson(System::Extended &mu, TRandomGenFunction RandomGenerator)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall Random_Poisson(System::Extended &mu)/* overload */;
}	/* namespace Randomlib */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_RANDOMLIB)
using namespace Stage::Randomlib;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_RandomLibHPP
