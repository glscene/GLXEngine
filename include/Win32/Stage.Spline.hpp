// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Spline.pas' rev: 36.00 (Windows)

#ifndef Stage_SplineHPP
#define Stage_SplineHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Spline
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCubicSpline;
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<System::StaticArray<float, 4> > TCubicSplineMatrix;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TCubicSpline : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCubicSplineMatrix matX;
	TCubicSplineMatrix matY;
	TCubicSplineMatrix matZ;
	TCubicSplineMatrix matW;
	int FNb;
	
public:
	__fastcall TCubicSpline(const Stage::Vectorgeometry::PFloatArray X, const Stage::Vectorgeometry::PFloatArray Y, const Stage::Vectorgeometry::PFloatArray Z, const Stage::Vectorgeometry::PFloatArray W, const int nb);
	__fastcall virtual ~TCubicSpline();
	float __fastcall SplineX(const float t);
	float __fastcall SplineY(const float t);
	float __fastcall SplineZ(const float t);
	float __fastcall SplineW(const float t);
	void __fastcall SplineXY(const float t, /* out */ float &X, /* out */ float &Y);
	void __fastcall SplineXYZ(const float t, /* out */ float &X, /* out */ float &Y, /* out */ float &Z);
	void __fastcall SplineXYZW(const float t, /* out */ float &X, /* out */ float &Y, /* out */ float &Z, /* out */ float &W);
	Stage::Vectorgeometry::TAffineVector __fastcall SplineAffineVector(const float t)/* overload */;
	void __fastcall SplineAffineVector(const float t, Stage::Vectorgeometry::TAffineVector &vector)/* overload */;
	Stage::Vectortypes::TGLVector __fastcall SplineVector(const float t)/* overload */;
	void __fastcall SplineVector(const float t, Stage::Vectortypes::TGLVector &vector)/* overload */;
	float __fastcall SplineSlopeX(const float t);
	float __fastcall SplineSlopeY(const float t);
	float __fastcall SplineSlopeZ(const float t);
	float __fastcall SplineSlopeW(const float t);
	Stage::Vectorgeometry::TAffineVector __fastcall SplineSlopeVector(const float t)/* overload */;
	bool __fastcall SplineIntersecYZ(float X, float &Y, float &Z);
	bool __fastcall SplineIntersecXZ(float Y, float &X, float &Z);
	bool __fastcall SplineIntersecXY(float Z, float &X, float &Y);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Spline */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_SPLINE)
using namespace Stage::Spline;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_SplineHPP
