// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.VectorGeometry.pas' rev: 36.00 (Windows)

#ifndef Stage_VectorGeometryHPP
#define Stage_VectorGeometryHPP

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
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Vectorgeometry
{
//-- forward type declarations -----------------------------------------------
struct TTexPoint;
struct TQuaternion;
struct TRectangle;
struct TFrustum;
//-- type declarations -------------------------------------------------------
typedef System::PSingle PFloat;

typedef TTexPoint *PTexPoint;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TTexPoint
{
public:
	float S;
	float T;
};
#pragma pack(pop)


typedef System::StaticArray<System::Byte, 134217728> TByteVector;

typedef TByteVector *PByteVector;

typedef PByteVector PByteArray;

typedef System::StaticArray<System::Word, 134217728> TWordVector;

typedef TWordVector *PWordVector;

typedef System::StaticArray<int, 134217728> TIntegerVector;

typedef TIntegerVector *PIntegerVector;

typedef PIntegerVector PIntegerArray;

typedef System::StaticArray<float, 134217728> TFloatVector;

typedef TFloatVector *PFloatVector;

typedef PFloatVector PFloatArray;

typedef PFloatArray PSingleArray;

typedef System::DynamicArray<float> TSingleArray;

typedef System::StaticArray<double, 134217728> TDoubleVector;

typedef TDoubleVector *PDoubleVector;

typedef PDoubleVector PDoubleArray;

typedef System::StaticArray<System::Extended, 134217728> TExtendedVector;

typedef TExtendedVector *PExtendedVector;

typedef PExtendedVector PExtendedArray;

typedef System::StaticArray<void *, 134217728> TPointerVector;

typedef TPointerVector *PPointerVector;

typedef PPointerVector PPointerArray;

typedef System::StaticArray<unsigned, 134217728> TCardinalVector;

typedef TCardinalVector *PCardinalVector;

typedef PCardinalVector PCardinalArray;

typedef System::StaticArray<unsigned, 134217728> TLongWordVector;

typedef TLongWordVector *PLongWordVector;

typedef PLongWordVector PLongWordArray;

typedef Stage::Vectortypes::TVector4b *PHomogeneousByteVector;

typedef Stage::Vectortypes::TVector4b THomogeneousByteVector;

typedef Stage::Vectortypes::TVector4w *PHomogeneousWordVector;

typedef Stage::Vectortypes::TVector4w THomogeneousWordVector;

typedef Stage::Vectortypes::TVector4i *PHomogeneousIntVector;

typedef Stage::Vectortypes::TVector4i THomogeneousIntVector;

typedef Stage::Vectortypes::TVector4f *PHomogeneousFltVector;

typedef Stage::Vectortypes::TVector4f THomogeneousFltVector;

typedef Stage::Vectortypes::TVector4d *PHomogeneousDblVector;

typedef Stage::Vectortypes::TVector4d THomogeneousDblVector;

typedef Stage::Vectortypes::TVector4e *PHomogeneousExtVector;

typedef Stage::Vectortypes::TVector4e THomogeneousExtVector;

typedef Stage::Vectortypes::TVector4p *PHomogeneousPtrVector;

typedef Stage::Vectortypes::TVector4p THomogeneousPtrVector;

typedef Stage::Vectortypes::TVector3b *PAffineByteVector;

typedef Stage::Vectortypes::TVector3b TAffineByteVector;

typedef Stage::Vectortypes::TVector3w *PAffineWordVector;

typedef Stage::Vectortypes::TVector3w TAffineWordVector;

typedef Stage::Vectortypes::TVector3i *PAffineIntVector;

typedef Stage::Vectortypes::TVector3i TAffineIntVector;

typedef Stage::Vectortypes::TVector3f *PAffineFltVector;

typedef Stage::Vectortypes::TVector3f TAffineFltVector;

typedef Stage::Vectortypes::TVector3d *PAffineDblVector;

typedef Stage::Vectortypes::TVector3d TAffineDblVector;

typedef Stage::Vectortypes::TVector3e *PAffineExtVector;

typedef Stage::Vectortypes::TVector3e TAffineExtVector;

typedef Stage::Vectortypes::TVector3p *PAffinePtrVector;

typedef Stage::Vectortypes::TVector3p TAffinePtrVector;

typedef Stage::Vectortypes::TVector2f *PVector2f;

typedef Stage::Vectortypes::TVector4f *PHomogeneousVector;

typedef Stage::Vectortypes::TVector4f THomogeneousVector;

typedef Stage::Vectortypes::TVector3f *PAffineVector;

typedef Stage::Vectortypes::TVector3f TAffineVector;

typedef Stage::Vectortypes::TVector3f *PVertex;

typedef Stage::Vectortypes::TVector3f TVertex;

typedef System::StaticArray<Stage::Vectortypes::TVector3f, 134217728> TAffineVectorArray;

typedef TAffineVectorArray *PAffineVectorArray;

typedef System::StaticArray<Stage::Vectortypes::TVector4f, 67108864> TVectorArray;

typedef TVectorArray *PVectorArray;

typedef System::StaticArray<TTexPoint, 134217728> TTexPointArray;

typedef TTexPointArray *PTexPointArray;

typedef Stage::Vectortypes::TMatrix4b THomogeneousByteMatrix;

typedef System::StaticArray<Stage::Vectortypes::TVector4w, 4> THomogeneousWordMatrix;

typedef Stage::Vectortypes::TMatrix4i THomogeneousIntMatrix;

typedef Stage::Vectortypes::TMatrix4f THomogeneousFltMatrix;

typedef Stage::Vectortypes::TMatrix4d THomogeneousDblMatrix;

typedef System::StaticArray<Stage::Vectortypes::TVector4e, 4> THomogeneousExtMatrix;

typedef Stage::Vectortypes::TMatrix3b TAffineByteMatrix;

typedef System::StaticArray<Stage::Vectortypes::TVector3w, 3> TAffineWordMatrix;

typedef Stage::Vectortypes::TMatrix3i TAffineIntMatrix;

typedef Stage::Vectortypes::TMatrix3f TAffineFltMatrix;

typedef Stage::Vectortypes::TMatrix3d TAffineDblMatrix;

typedef System::StaticArray<Stage::Vectortypes::TVector3e, 3> TAffineExtMatrix;

typedef System::StaticArray<Stage::Vectortypes::TMatrix4f, 16777216> TMatrixArray;

typedef TMatrixArray *PMatrixArray;

typedef Stage::Vectortypes::TMatrix4f *PHomogeneousMatrix;

typedef Stage::Vectortypes::TMatrix4f THomogeneousMatrix;

typedef Stage::Vectortypes::TMatrix3f *PAffineMatrix;

typedef Stage::Vectortypes::TMatrix3f TAffineMatrix;

typedef Stage::Vectortypes::TVector4f THmgPlane;

typedef Stage::Vectortypes::TVector4d TDoubleHmgPlane;

typedef TQuaternion *PQuaternion;

struct DECLSPEC_DRECORD TQuaternion
{
	
public:
	union
	{
		struct 
		{
			float X;
			float Y;
			float Z;
			float W;
		};
		struct 
		{
			TAffineVector ImagPart;
			float RealPart;
		};
		
	};
};


typedef System::StaticArray<TQuaternion, 67108864> TQuaternionArray;

typedef TQuaternionArray *PQuaternionArray;

struct DECLSPEC_DRECORD TRectangle
{
public:
	int Left;
	int Top;
	int Width;
	int Height;
};


typedef TFrustum *PFrustum;

struct DECLSPEC_DRECORD TFrustum
{
public:
	THmgPlane pLeft;
	THmgPlane pTop;
	THmgPlane pRight;
	THmgPlane pBottom;
	THmgPlane pNear;
	THmgPlane pFar;
};


enum DECLSPEC_DENUM TTransType : unsigned char { ttScaleX, ttScaleY, ttScaleZ, ttShearXY, ttShearXZ, ttShearYZ, ttRotateX, ttRotateY, ttRotateZ, ttTranslateX, ttTranslateY, ttTranslateZ, ttPerspectiveX, ttPerspectiveY, ttPerspectiveZ, ttPerspectiveW };

typedef System::StaticArray<float, 16> TTransformations;

typedef System::StaticArray<short, 3> TPackedRotationMatrix;

enum DECLSPEC_DENUM TGLInterpolationType : unsigned char { itLinear, itPower, itSin, itSinAlt, itTan, itLn, itExp };

enum DECLSPEC_DENUM TEulerOrder : unsigned char { eulXYZ, eulXZY, eulYXZ, eulYZX, eulZXY, eulZYX };

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST int cMaxArray = int(0x7ffffff);
static const System::Extended cColinearBias = 1.000000E-08;
extern DELPHI_PACKAGE TTexPoint XTexPoint;
extern DELPHI_PACKAGE TTexPoint YTexPoint;
extern DELPHI_PACKAGE TTexPoint XYTexPoint;
extern DELPHI_PACKAGE TTexPoint NullTexPoint;
extern DELPHI_PACKAGE TTexPoint MidTexPoint;
extern DELPHI_PACKAGE TAffineVector XVector;
extern DELPHI_PACKAGE TAffineVector YVector;
extern DELPHI_PACKAGE TAffineVector ZVector;
extern DELPHI_PACKAGE TAffineVector XYVector;
extern DELPHI_PACKAGE TAffineVector XZVector;
extern DELPHI_PACKAGE TAffineVector YZVector;
extern DELPHI_PACKAGE TAffineVector XYZVector;
extern DELPHI_PACKAGE TAffineVector NullVector;
extern DELPHI_PACKAGE TAffineVector MinusXVector;
extern DELPHI_PACKAGE TAffineVector MinusYVector;
extern DELPHI_PACKAGE TAffineVector MinusZVector;
extern DELPHI_PACKAGE THomogeneousVector XHmgVector;
extern DELPHI_PACKAGE THomogeneousVector YHmgVector;
extern DELPHI_PACKAGE THomogeneousVector ZHmgVector;
extern DELPHI_PACKAGE THomogeneousVector WHmgVector;
extern DELPHI_PACKAGE THomogeneousVector XYHmgVector;
extern DELPHI_PACKAGE THomogeneousVector YZHmgVector;
extern DELPHI_PACKAGE THomogeneousVector XZHmgVector;
extern DELPHI_PACKAGE THomogeneousVector XYZHmgVector;
extern DELPHI_PACKAGE THomogeneousVector XYZWHmgVector;
extern DELPHI_PACKAGE THomogeneousVector NullHmgVector;
extern DELPHI_PACKAGE THomogeneousVector XHmgPoint;
extern DELPHI_PACKAGE THomogeneousVector YHmgPoint;
extern DELPHI_PACKAGE THomogeneousVector ZHmgPoint;
extern DELPHI_PACKAGE THomogeneousVector WHmgPoint;
extern DELPHI_PACKAGE THomogeneousVector NullHmgPoint;
extern DELPHI_PACKAGE TAffineMatrix IdentityMatrix;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix IdentityHmgMatrix;
extern DELPHI_PACKAGE THomogeneousDblMatrix IdentityHmgDblMatrix;
extern DELPHI_PACKAGE TAffineMatrix EmptyMatrix;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix EmptyHmgMatrix;
extern DELPHI_PACKAGE TQuaternion IdentityQuaternion;
extern DELPHI_PACKAGE float EPSILON;
extern DELPHI_PACKAGE float EPSILON2;
extern DELPHI_PACKAGE float cPI;
extern DELPHI_PACKAGE float cPIdiv180;
extern DELPHI_PACKAGE float c180divPI;
extern DELPHI_PACKAGE float c2PI;
extern DELPHI_PACKAGE float cPIdiv2;
extern DELPHI_PACKAGE float cPIdiv4;
extern DELPHI_PACKAGE float c3PIdiv2;
extern DELPHI_PACKAGE float c3PIdiv4;
extern DELPHI_PACKAGE float cInv2PI;
extern DELPHI_PACKAGE float cInv360;
extern DELPHI_PACKAGE float c180;
extern DELPHI_PACKAGE float c360;
extern DELPHI_PACKAGE float cOneHalf;
extern DELPHI_PACKAGE float cLn10;
static const System::Extended MinSingle = 1.500000E-45;
static const System::Extended MaxSingle = 3.400000E+38;
static const System::Extended MinDouble = 5.000000E-324;
static const System::Extended MaxDouble = 1.700000E+308;
static const System::Extended MinExtended = 3.400000E-4932;
static const System::Extended MaxExtended = 1.700000E+308;
static const System::Extended MinComp = -9.223372E+18;
static const System::Extended MaxComp = 9.223372E+18;
extern DELPHI_PACKAGE System::Byte vSIMD;
extern DELPHI_PACKAGE System::UnicodeString __fastcall GeometryOptimizationMode(void);
extern DELPHI_PACKAGE void __fastcall BeginFPUOnlySection(void);
extern DELPHI_PACKAGE void __fastcall EndFPUOnlySection(void);
extern DELPHI_PACKAGE TTexPoint __fastcall TexPointMake(const float S, const float T);
extern DELPHI_PACKAGE TAffineVector __fastcall AffineVectorMake(const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall AffineVectorMake(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetAffineVector(/* out */ TAffineVector &V, const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ TAffineVector &V, const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ TAffineVector &V, const Stage::Vectortypes::TGLVector &vSrc)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ TAffineVector &V, const TAffineVector &vSrc)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ TAffineDblVector &V, const TAffineVector &vSrc)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ TAffineDblVector &V, const Stage::Vectortypes::TGLVector &vSrc)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall VectorMake(const TAffineVector &V, float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorMake(const float X, const float Y, const float Z, float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorMake(const TQuaternion &Q)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall PointMake(const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PointMake(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PointMake(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ Stage::Vectortypes::TGLVector &V, const float X, const float Y, const float Z, float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ Stage::Vectortypes::TGLVector &V, const TAffineVector &av, float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetVector(/* out */ Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &vSrc)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakePoint(/* out */ Stage::Vectortypes::TGLVector &V, const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakePoint(/* out */ Stage::Vectortypes::TGLVector &V, const TAffineVector &av)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakePoint(/* out */ Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &av)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakeVector(/* out */ TAffineVector &V, const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakeVector(/* out */ Stage::Vectortypes::TGLVector &V, const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakeVector(/* out */ Stage::Vectortypes::TGLVector &V, const TAffineVector &av)/* overload */;
extern DELPHI_PACKAGE void __fastcall MakeVector(/* out */ Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &av)/* overload */;
extern DELPHI_PACKAGE void __fastcall RstVector(TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall RstVector(Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall VectorAdd(const Stage::Vectortypes::TVector2f &V1, const Stage::Vectortypes::TVector2f &V2)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorAdd(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorAdd(const TAffineVector &V1, const TAffineVector &V2, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorAdd(const TAffineVector &V1, const TAffineVector &V2, PAffineVector vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorAdd(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorAdd(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorAdd(const TAffineVector &V, const float f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorAdd(const Stage::Vectortypes::TGLVector &V, const float f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall PointAdd(Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddVector(TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddVector(TAffineVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddVector(Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddVector(TAffineVector &V, const float f)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddVector(Stage::Vectortypes::TGLVector &V, const float f)/* overload */;
extern DELPHI_PACKAGE void __fastcall AddPoint(Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall TexPointArrayAdd(const PTexPointArray src, const TTexPoint &delta, const int nb, PTexPointArray dest)/* overload */;
extern DELPHI_PACKAGE void __fastcall TexPointArrayScaleAndAdd(const PTexPointArray src, const TTexPoint &delta, const int nb, const TTexPoint &scale, PTexPointArray dest)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorArrayAdd(const PAffineVectorArray src, const TAffineVector &delta, const int nb, PAffineVectorArray dest)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorSubtract(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall VectorSubtract(const Stage::Vectortypes::TVector2f &V1, const Stage::Vectortypes::TVector2f &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorSubtract(const TAffineVector &V1, const TAffineVector &V2, TAffineVector &result)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorSubtract(const TAffineVector &V1, const TAffineVector &V2, Stage::Vectortypes::TGLVector &result)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorSubtract(const Stage::Vectortypes::TGLVector &V1, const TAffineVector &V2, Stage::Vectortypes::TGLVector &result)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorSubtract(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorSubtract(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, Stage::Vectortypes::TGLVector &result)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorSubtract(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, TAffineVector &result)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorSubtract(const TAffineVector &V1, float delta)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorSubtract(const Stage::Vectortypes::TGLVector &V1, float delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall SubtractVector(TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall SubtractVector(Stage::Vectortypes::TVector2f &V1, const Stage::Vectortypes::TVector2f &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall SubtractVector(Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall CombineVector(TAffineVector &vr, const TAffineVector &V, float &f)/* overload */;
extern DELPHI_PACKAGE void __fastcall CombineVector(TAffineVector &vr, const TAffineVector &V, PFloat pf)/* overload */;
extern DELPHI_PACKAGE TTexPoint __fastcall TexPointCombine(const TTexPoint &t1, const TTexPoint &t2, float f1, float f2);
extern DELPHI_PACKAGE TAffineVector __fastcall VectorCombine(const TAffineVector &V1, const TAffineVector &V2, const float f1, const float f2)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorCombine3(const TAffineVector &V1, const TAffineVector &V2, const TAffineVector &V3, const float f1, const float f2, const float F3)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCombine3(const TAffineVector &V1, const TAffineVector &V2, const TAffineVector &V3, const float f1, const float f2, const float F3, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall CombineVector(Stage::Vectortypes::TGLVector &vr, const Stage::Vectortypes::TGLVector &V, float &f)/* overload */;
extern DELPHI_PACKAGE void __fastcall CombineVector(Stage::Vectortypes::TGLVector &vr, const TAffineVector &V, float &f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorCombine(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, const float F1, const float F2)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorCombine(const Stage::Vectortypes::TGLVector &V1, const TAffineVector &V2, const float F1, const float F2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCombine(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, const float F1, const float F2, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCombine(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, const float F2, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCombine(const Stage::Vectortypes::TGLVector &V1, const TAffineVector &V2, const float F1, const float F2, Stage::Vectortypes::TGLVector &VR)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorCombine3(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, const Stage::Vectortypes::TGLVector &V3, const float F1, const float F2, const float F3)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCombine3(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, const Stage::Vectortypes::TGLVector &V3, const float F1, const float F2, const float F3, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDotProduct(const Stage::Vectortypes::TVector2f &V1, const Stage::Vectortypes::TVector2f &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDotProduct(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDotProduct(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDotProduct(const Stage::Vectortypes::TGLVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointProject(const TAffineVector &p, const TAffineVector &origin, const TAffineVector &direction)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointProject(const Stage::Vectortypes::TGLVector &p, const Stage::Vectortypes::TGLVector &origin, const Stage::Vectortypes::TGLVector &direction)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorCrossProduct(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorCrossProduct(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCrossProduct(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCrossProduct(const TAffineVector &V1, const TAffineVector &V2, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCrossProduct(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorCrossProduct(const TAffineVector &V1, const TAffineVector &V2, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE float __fastcall Lerp(const float start, const float stop, const float T);
extern DELPHI_PACKAGE float __fastcall AngleLerp(float start, float stop, float T);
extern DELPHI_PACKAGE float __fastcall DistanceBetweenAngles(float angle1, float angle2);
extern DELPHI_PACKAGE TTexPoint __fastcall TexPointLerp(const TTexPoint &t1, const TTexPoint &t2, float T)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorLerp(const TAffineVector &V1, const TAffineVector &V2, float T)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorLerp(const TAffineVector &V1, const TAffineVector &V2, float T, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorLerp(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, float T)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorLerp(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2, float T, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorAngleLerp(const TAffineVector &V1, const TAffineVector &V2, float T)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorAngleCombine(const TAffineVector &V1, const TAffineVector &V2, float f)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorArrayLerp(const PVectorArray src1, const PVectorArray src2, float T, int n, PVectorArray dest)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorArrayLerp(const PAffineVectorArray src1, const PAffineVectorArray src2, float T, int n, PAffineVectorArray dest)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorArrayLerp(const PTexPointArray src1, const PTexPointArray src2, float T, int n, PTexPointArray dest)/* overload */;
extern DELPHI_PACKAGE float __fastcall InterpolateCombined(const float start, const float stop, const float delta, const float DistortionDegree, const TGLInterpolationType InterpolationType);
extern DELPHI_PACKAGE float __fastcall InterpolateCombinedFastPower(const float OriginalStart, const float OriginalStop, const float OriginalCurrent, const float TargetStart, const float TargetStop, const float DistortionDegree);
extern DELPHI_PACKAGE float __fastcall InterpolateCombinedSafe(const float OriginalStart, const float OriginalStop, const float OriginalCurrent, const float TargetStart, const float TargetStop, const float DistortionDegree, const TGLInterpolationType InterpolationType);
extern DELPHI_PACKAGE float __fastcall InterpolateCombinedFast(const float OriginalStart, const float OriginalStop, const float OriginalCurrent, const float TargetStart, const float TargetStop, const float DistortionDegree, const TGLInterpolationType InterpolationType);
extern DELPHI_PACKAGE float __fastcall InterpolateLn(const float start, const float stop, const float delta, const float DistortionDegree);
extern DELPHI_PACKAGE float __fastcall InterpolateExp(const float start, const float stop, const float delta, const float DistortionDegree);
extern DELPHI_PACKAGE float __fastcall InterpolateSinAlt(const float start, const float stop, const float delta);
extern DELPHI_PACKAGE float __fastcall InterpolateSin(const float start, const float stop, const float delta);
extern DELPHI_PACKAGE float __fastcall InterpolateTan(const float start, const float stop, const float delta);
extern DELPHI_PACKAGE float __fastcall InterpolatePower(const float start, const float stop, const float delta, const float DistortionDegree);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall MatrixLerp(const Stage::Vectortypes::TGLMatrix &m1, const Stage::Vectortypes::TGLMatrix &m2, const float delta);
extern DELPHI_PACKAGE float __fastcall RSqrt(float V);
extern DELPHI_PACKAGE float __fastcall VectorLength(const float *V, const System::NativeInt V_High)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorLength(const float X, const float Y)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorLength(const float X, const float Y, const float Z)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorLength(const Stage::Vectortypes::TVector2f &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorLength(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorLength(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorNorm(const float X, const float Y)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorNorm(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorNorm(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorNorm(float *V, const System::NativeInt V_High)/* overload */;
extern DELPHI_PACKAGE void __fastcall NormalizeVector(Stage::Vectortypes::TVector2f &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall NormalizeVector(TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall VectorNormalize(const Stage::Vectortypes::TVector2f &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorNormalize(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall NormalizeVectorArray(PAffineVectorArray list, int n)/* overload */;
extern DELPHI_PACKAGE void __fastcall NormalizeVector(Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorNormalize(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorAngleCosine(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorAngleCosine(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorNegate(const TAffineVector &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorNegate(const Stage::Vectortypes::TGLVector &Vector)/* overload */;
extern DELPHI_PACKAGE void __fastcall NegateVector(TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall NegateVector(Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall NegateVector(float *V, const System::NativeInt V_High)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleVector(Stage::Vectortypes::TVector2f &V, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleVector(TAffineVector &V, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleVector(Stage::Vectortypes::TGLVector &V, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleVector(TAffineVector &V, const TAffineVector &factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleVector(Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &factor)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall VectorScale(const Stage::Vectortypes::TVector2f &V, float factor)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorScale(const TAffineVector &V, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorScale(const TAffineVector &V, float factor, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorScale(const Stage::Vectortypes::TGLVector &V, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorScale(const Stage::Vectortypes::TGLVector &V, float factor, Stage::Vectortypes::TGLVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorScale(const Stage::Vectortypes::TGLVector &V, float factor, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorScale(const TAffineVector &V, const TAffineVector &factor)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorScale(const Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall DivideVector(Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &divider)/* overload */;
extern DELPHI_PACKAGE void __fastcall DivideVector(TAffineVector &V, const TAffineVector &divider)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall VectorDivide(const Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &divider)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorDivide(const TAffineVector &V, const TAffineVector &divider)/* overload */;
extern DELPHI_PACKAGE bool __fastcall TexpointEquals(const TTexPoint &p1, const TTexPoint &p2);
extern DELPHI_PACKAGE bool __fastcall RectEquals(const System::Types::TRect &Rect1, const System::Types::TRect &Rect2);
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall AffineVectorEquals(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorIsNull(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorIsNull(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorSpacing(const TTexPoint &V1, const TTexPoint &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorSpacing(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorSpacing(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDistance(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDistance(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDistance2(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall VectorDistance2(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorPerpendicular(const TAffineVector &V, const TAffineVector &n);
extern DELPHI_PACKAGE TAffineVector __fastcall VectorReflect(const TAffineVector &V, const TAffineVector &n);
extern DELPHI_PACKAGE void __fastcall RotateVector(Stage::Vectortypes::TGLVector &Vector, const TAffineVector &axis, float angle)/* overload */;
extern DELPHI_PACKAGE void __fastcall RotateVector(Stage::Vectortypes::TGLVector &Vector, const Stage::Vectortypes::TGLVector &axis, float angle)/* overload */;
extern DELPHI_PACKAGE void __fastcall RotateVectorAroundY(TAffineVector &V, float alpha);
extern DELPHI_PACKAGE TAffineVector __fastcall VectorRotateAroundX(const TAffineVector &V, float alpha)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorRotateAroundY(const TAffineVector &V, float alpha)/* overload */;
extern DELPHI_PACKAGE void __fastcall VectorRotateAroundY(const TAffineVector &V, float alpha, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall VectorRotateAroundZ(const TAffineVector &V, float alpha)/* overload */;
extern DELPHI_PACKAGE void __fastcall AbsVector(Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall AbsVector(TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall VectorAbs(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorAbs(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsColinear(const Stage::Vectortypes::TVector2f &V1, const Stage::Vectortypes::TVector2f &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsColinear(const TAffineVector &V1, const TAffineVector &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsColinear(const Stage::Vectortypes::TGLVector &V1, const Stage::Vectortypes::TGLVector &V2)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetMatrix(THomogeneousDblMatrix &dest, const Stage::Vectortypes::TGLMatrix &src)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetMatrix(TAffineMatrix &dest, const Stage::Vectortypes::TGLMatrix &src)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetMatrix(Stage::Vectortypes::TGLMatrix &dest, const TAffineMatrix &src)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetMatrixRow(Stage::Vectortypes::TGLMatrix &dest, int rowNb, const Stage::Vectortypes::TGLVector &aRow)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateScaleMatrix(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateScaleMatrix(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateTranslationMatrix(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateTranslationMatrix(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateScaleAndTranslationMatrix(const Stage::Vectortypes::TGLVector &scale, const Stage::Vectortypes::TGLVector &offset)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateRotationMatrixX(const float sine, const float cosine)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateRotationMatrixX(const float angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateRotationMatrixY(const float sine, const float cosine)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateRotationMatrixY(const float angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateRotationMatrixZ(const float sine, const float cosine)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateRotationMatrixZ(const float angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateRotationMatrix(const TAffineVector &anAxis, float angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall CreateRotationMatrix(const Stage::Vectortypes::TGLVector &anAxis, float angle)/* overload */;
extern DELPHI_PACKAGE TAffineMatrix __fastcall CreateAffineRotationMatrix(const TAffineVector &anAxis, float angle);
extern DELPHI_PACKAGE TAffineMatrix __fastcall MatrixMultiply(const TAffineMatrix &m1, const TAffineMatrix &m2)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall MatrixMultiply(const Stage::Vectortypes::TGLMatrix &m1, const Stage::Vectortypes::TGLMatrix &m2)/* overload */;
extern DELPHI_PACKAGE void __fastcall MatrixMultiply(const Stage::Vectortypes::TGLMatrix &m1, const Stage::Vectortypes::TGLMatrix &m2, Stage::Vectortypes::TGLMatrix &MResult)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall VectorTransform(const Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall VectorTransform(const Stage::Vectortypes::TGLVector &V, const TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorTransform(const TAffineVector &V, const Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall VectorTransform(const TAffineVector &V, const TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE float __fastcall MatrixDeterminant(const TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE float __fastcall MatrixDeterminant(const Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall AdjointMatrix(Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall AdjointMatrix(TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleMatrix(TAffineMatrix &M, const float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleMatrix(Stage::Vectortypes::TGLMatrix &M, const float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall TranslateMatrix(Stage::Vectortypes::TGLMatrix &M, const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall TranslateMatrix(Stage::Vectortypes::TGLMatrix &M, const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE void __fastcall NormalizeMatrix(Stage::Vectortypes::TGLMatrix &M);
extern DELPHI_PACKAGE void __fastcall TransposeMatrix(TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall TransposeMatrix(Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall InvertMatrix(Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall MatrixInvert(const Stage::Vectortypes::TGLMatrix &M)/* overload */;
extern DELPHI_PACKAGE void __fastcall InvertMatrix(TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix3f __fastcall MatrixInvert(const TAffineMatrix &M)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall AnglePreservingMatrixInvert(const Stage::Vectortypes::TGLMatrix &mat);
extern DELPHI_PACKAGE bool __fastcall MatrixDecompose(const Stage::Vectortypes::TGLMatrix &M, TTransformations &Tran);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateLookAtMatrix(const Stage::Vectortypes::TGLVector &eye, const Stage::Vectortypes::TGLVector &center, const Stage::Vectortypes::TGLVector &normUp);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateMatrixFromFrustum(float Left, float Right, float Bottom, float Top, float ZNear, float ZFar);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreatePerspectiveMatrix(float FOV, float Aspect, float ZNear, float ZFar);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreateOrthoMatrix(float Left, float Right, float Bottom, float Top, float ZNear, float ZFar);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall CreatePickMatrix(float X, float Y, float deltax, float deltay, const Stage::Vectortypes::TVector4i &viewport);
extern DELPHI_PACKAGE bool __fastcall Project(const Stage::Vectortypes::TGLVector &objectVector, const Stage::Vectortypes::TGLMatrix &ViewProjMatrix, const Stage::Vectortypes::TVector4i &viewport, /* out */ Stage::Vectortypes::TGLVector &WindowVector);
extern DELPHI_PACKAGE bool __fastcall UnProject(const Stage::Vectortypes::TGLVector &WindowVector, const Stage::Vectortypes::TGLMatrix &ViewProjMatrix, const Stage::Vectortypes::TVector4i &viewport, /* out */ Stage::Vectortypes::TGLVector &objectVector);
extern DELPHI_PACKAGE TAffineVector __fastcall CalcPlaneNormal(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3)/* overload */;
extern DELPHI_PACKAGE void __fastcall CalcPlaneNormal(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE void __fastcall CalcPlaneNormal(const Stage::Vectortypes::TGLVector &p1, const Stage::Vectortypes::TGLVector &p2, const Stage::Vectortypes::TGLVector &p3, TAffineVector &vr)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PlaneMake(const TAffineVector &point, const TAffineVector &normal)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PlaneMake(const Stage::Vectortypes::TGLVector &point, const Stage::Vectortypes::TGLVector &normal)/* overload */;
extern DELPHI_PACKAGE THmgPlane __fastcall PlaneMake(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PlaneMake(const Stage::Vectortypes::TGLVector &p1, const Stage::Vectortypes::TGLVector &p2, const Stage::Vectortypes::TGLVector &p3)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetPlane(TDoubleHmgPlane &dest, const THmgPlane &src);
extern DELPHI_PACKAGE void __fastcall NormalizePlane(THmgPlane &plane);
extern DELPHI_PACKAGE float __fastcall PlaneEvaluatePoint(const THmgPlane &plane, const TAffineVector &point)/* overload */;
extern DELPHI_PACKAGE float __fastcall PlaneEvaluatePoint(const THmgPlane &plane, const Stage::Vectortypes::TGLVector &point)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PointIsInHalfSpace(const Stage::Vectortypes::TGLVector &point, const Stage::Vectortypes::TGLVector &planePoint, const Stage::Vectortypes::TGLVector &planeNormal)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PointIsInHalfSpace(const TAffineVector &point, const TAffineVector &planePoint, const TAffineVector &planeNormal)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PointIsInHalfSpace(const TAffineVector &point, const THmgPlane &plane)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointPlaneDistance(const Stage::Vectortypes::TGLVector &point, const Stage::Vectortypes::TGLVector &planePoint, const Stage::Vectortypes::TGLVector &planeNormal)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointPlaneDistance(const TAffineVector &point, const TAffineVector &planePoint, const TAffineVector &planeNormal)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointPlaneDistance(const TAffineVector &point, const THmgPlane &plane)/* overload */;
extern DELPHI_PACKAGE bool __fastcall PointPlaneOrthoProjection(const TAffineVector &point, const THmgPlane &plane, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall PointPlaneProjection(const TAffineVector &point, const TAffineVector &direction, const THmgPlane &plane, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall SegmentPlaneIntersection(const TAffineVector &ptA, const TAffineVector &ptB, const THmgPlane &plane, TAffineVector &inter);
extern DELPHI_PACKAGE bool __fastcall PointTriangleOrthoProjection(const TAffineVector &point, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall PointTriangleProjection(const TAffineVector &point, const TAffineVector &direction, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall IsLineIntersectTriangle(const TAffineVector &point, const TAffineVector &direction, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC);
extern DELPHI_PACKAGE bool __fastcall PointQuadOrthoProjection(const TAffineVector &point, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC, const TAffineVector &ptD, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall PointQuadProjection(const TAffineVector &point, const TAffineVector &direction, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC, const TAffineVector &ptD, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall IsLineIntersectQuad(const TAffineVector &point, const TAffineVector &direction, const TAffineVector &ptA, const TAffineVector &ptB, const TAffineVector &ptC, const TAffineVector &ptD);
extern DELPHI_PACKAGE bool __fastcall PointDiskOrthoProjection(const TAffineVector &point, const TAffineVector &center, const TAffineVector &up, const float radius, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE bool __fastcall PointDiskProjection(const TAffineVector &point, const TAffineVector &direction, const TAffineVector &center, const TAffineVector &up, const float radius, TAffineVector &inter, bool bothface = true);
extern DELPHI_PACKAGE TAffineVector __fastcall PointLineClosestPoint(const TAffineVector &point, const TAffineVector &linePoint, const TAffineVector &lineDirection);
extern DELPHI_PACKAGE float __fastcall PointLineDistance(const TAffineVector &point, const TAffineVector &linePoint, const TAffineVector &lineDirection);
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall PointSegmentClosestPoint(const Stage::Vectortypes::TGLVector &point, const Stage::Vectortypes::TGLVector &segmentStart, const Stage::Vectortypes::TGLVector &segmentStop)/* overload */;
extern DELPHI_PACKAGE TAffineVector __fastcall PointSegmentClosestPoint(const TAffineVector &point, const TAffineVector &segmentStart, const TAffineVector &segmentStop)/* overload */;
extern DELPHI_PACKAGE float __fastcall PointSegmentDistance(const TAffineVector &point, const TAffineVector &segmentStart, const TAffineVector &segmentStop);
extern DELPHI_PACKAGE void __fastcall SegmentSegmentClosestPoint(const TAffineVector &S0Start, const TAffineVector &S0Stop, const TAffineVector &S1Start, const TAffineVector &S1Stop, TAffineVector &Segment0Closest, TAffineVector &Segment1Closest);
extern DELPHI_PACKAGE float __fastcall SegmentSegmentDistance(const TAffineVector &S0Start, const TAffineVector &S0Stop, const TAffineVector &S1Start, const TAffineVector &S1Stop);
extern DELPHI_PACKAGE float __fastcall LineLineDistance(const TAffineVector &linePt0, const TAffineVector &lineDir0, const TAffineVector &linePt1, const TAffineVector &lineDir1);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionMake(const float *Imag, const System::NativeInt Imag_High, float Real)/* overload */;
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionMake(const float X, const float Y, const float Z, const float W)/* overload */;
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionMake(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionConjugate(const TQuaternion &Q);
extern DELPHI_PACKAGE float __fastcall QuaternionMagnitude(const TQuaternion &Q);
extern DELPHI_PACKAGE void __fastcall NormalizeQuaternion(TQuaternion &Q);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionFromPoints(const TAffineVector &V1, const TAffineVector &V2);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionFromMatrix(const Stage::Vectortypes::TGLMatrix &mat);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionMultiply(const TQuaternion &qL, const TQuaternion &qR);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall QuaternionToMatrix(const TQuaternion &quat);
extern DELPHI_PACKAGE TAffineMatrix __fastcall QuaternionToAffineMatrix(const TQuaternion &quat);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionFromAngleAxis(const float angle, const TAffineVector &axis);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionFromRollPitchYaw(const float r, const float p, const float Y);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionFromEuler(const float X, const float Y, const float Z, TEulerOrder eulerOrder);
extern DELPHI_PACKAGE void __fastcall QuaternionToPoints(const TQuaternion &Q, TAffineVector &ArcFrom, TAffineVector &ArcTo);
extern DELPHI_PACKAGE float __fastcall Logarithm2(const float X);
extern DELPHI_PACKAGE float __fastcall PowerSingle(const float Base, const float Exponent)/* overload */;
extern DELPHI_PACKAGE float __fastcall PowerInteger(float Base, int Exponent)/* overload */;
extern DELPHI_PACKAGE float __fastcall PowerInt64(float Base, __int64 Exponent)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall DegToRadian(const System::Extended Degrees)/* overload */;
extern DELPHI_PACKAGE float __fastcall DegToRadian(const float Degrees)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall RadianToDeg(const System::Extended Radians)/* overload */;
extern DELPHI_PACKAGE float __fastcall RadianToDeg(const float Radians)/* overload */;
extern DELPHI_PACKAGE float __fastcall NormalizeAngle(float angle);
extern DELPHI_PACKAGE float __fastcall NormalizeDegAngle(float angle);
extern DELPHI_PACKAGE void __fastcall SinCosine(const double Theta, /* out */ double &Sin, /* out */ double &Cos)/* overload */;
extern DELPHI_PACKAGE void __fastcall SinCosine(const float Theta, /* out */ float &Sin, /* out */ float &Cos)/* overload */;
extern DELPHI_PACKAGE void __fastcall SinCosine(const double Theta, const double radius, /* out */ double &Sin, /* out */ double &Cos)/* overload */;
extern DELPHI_PACKAGE void __fastcall SinCosine(const float Theta, const float radius, /* out */ float &Sin, /* out */ float &Cos)/* overload */;
extern DELPHI_PACKAGE void __fastcall PrepareSinCosCache(float *S, const System::NativeInt S_High, float *c, const System::NativeInt c_High, float startAngle, float stopAngle);
extern DELPHI_PACKAGE System::Extended __fastcall ArcCosine(const System::Extended X)/* overload */;
extern DELPHI_PACKAGE float __fastcall FastArcTangent2(float Y, float X);
extern DELPHI_PACKAGE int __fastcall ISqrt(int i);
extern DELPHI_PACKAGE int __fastcall ILength(int X, int Y)/* overload */;
extern DELPHI_PACKAGE int __fastcall ILength(int X, int Y, int Z)/* overload */;
extern DELPHI_PACKAGE float __fastcall RLength(float X, float Y);
extern DELPHI_PACKAGE void __fastcall RandomPointOnSphere(TAffineVector &p);
extern DELPHI_PACKAGE float __fastcall RoundInt(float V)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall RoundInt(System::Extended V)/* overload */;
extern DELPHI_PACKAGE int __fastcall SignStrict(float X);
extern DELPHI_PACKAGE int __fastcall ScaleAndRound(int i, float &S);
extern DELPHI_PACKAGE bool __fastcall IsInRange(const float X, const float a, const float b)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsInRange(const double X, const double a, const double b)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsInCube(const TAffineVector &p, const TAffineVector &d)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsInCube(const Stage::Vectortypes::TGLVector &p, const Stage::Vectortypes::TGLVector &d)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinFloat(PSingleArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE double __fastcall MinFloat(PDoubleArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall MinFloat(PExtendedArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinFloat(const float *V, const System::NativeInt V_High)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinFloat(const float V1, const float V2)/* overload */;
extern DELPHI_PACKAGE double __fastcall MinFloat(const double V1, const double V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinFloat(const float V1, const float V2, const float V3)/* overload */;
extern DELPHI_PACKAGE double __fastcall MinFloat(const double V1, const double V2, const double V3)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxFloat(PSingleArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE double __fastcall MaxFloat(PDoubleArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE System::Extended __fastcall MaxFloat(PExtendedArray values, int nbItems)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxFloat(const float *V, const System::NativeInt V_High)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxFloat(const float V1, const float V2)/* overload */;
extern DELPHI_PACKAGE double __fastcall MaxFloat(const double V1, const double V2)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxFloat(const float V1, const float V2, const float V3)/* overload */;
extern DELPHI_PACKAGE double __fastcall MaxFloat(const double V1, const double V2, const double V3)/* overload */;
extern DELPHI_PACKAGE int __fastcall MinInteger(const int V1, const int V2)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall MinInteger(const unsigned V1, const unsigned V2)/* overload */;
extern DELPHI_PACKAGE int __fastcall MinInteger(const int V1, const int V2, const int V3)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall MinInteger(const unsigned V1, const unsigned V2, const unsigned V3)/* overload */;
extern DELPHI_PACKAGE int __fastcall MaxInteger(const int V1, const int V2)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall MaxInteger(const unsigned V1, const unsigned V2)/* overload */;
extern DELPHI_PACKAGE int __fastcall MaxInteger(const int V1, const int V2, const int V3)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall MaxInteger(const unsigned V1, const unsigned V2, const unsigned V3)/* overload */;
extern DELPHI_PACKAGE int __fastcall ClampInteger(const int value, const int min, const int max)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall ClampInteger(const unsigned value, const unsigned min, const unsigned max)/* overload */;
extern DELPHI_PACKAGE float __fastcall TriangleArea(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3)/* overload */;
extern DELPHI_PACKAGE float __fastcall PolygonArea(const PAffineVectorArray p, int nSides)/* overload */;
extern DELPHI_PACKAGE float __fastcall TriangleSignedArea(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3)/* overload */;
extern DELPHI_PACKAGE float __fastcall PolygonSignedArea(const PAffineVectorArray p, int nSides)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleFloatArray(PSingleArray values, int nb, float &factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ScaleFloatArray(TSingleArray &values, float factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetFloatArray(PSingleArray values, int nb, float &delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetFloatArray(float *values, const System::NativeInt values_High, float delta)/* overload */;
extern DELPHI_PACKAGE void __fastcall OffsetFloatArray(PSingleArray valuesDest, PSingleArray valuesDelta, int nb)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxXYZComponent(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxXYZComponent(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinXYZComponent(const Stage::Vectortypes::TGLVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall MinXYZComponent(const TAffineVector &V)/* overload */;
extern DELPHI_PACKAGE float __fastcall MaxAbsXYZComponent(const Stage::Vectortypes::TGLVector &V);
extern DELPHI_PACKAGE float __fastcall MinAbsXYZComponent(const Stage::Vectortypes::TGLVector &V);
extern DELPHI_PACKAGE void __fastcall MaxVector(Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &V1)/* overload */;
extern DELPHI_PACKAGE void __fastcall MaxVector(TAffineVector &V, const TAffineVector &V1)/* overload */;
extern DELPHI_PACKAGE void __fastcall MinVector(Stage::Vectortypes::TGLVector &V, const Stage::Vectortypes::TGLVector &V1)/* overload */;
extern DELPHI_PACKAGE void __fastcall MinVector(TAffineVector &V, const TAffineVector &V1)/* overload */;
extern DELPHI_PACKAGE void __fastcall SortArrayAscending(System::Extended *a, const System::NativeInt a_High);
extern DELPHI_PACKAGE float __fastcall ClampValue(const float aValue, const float aMin, const float aMax)/* overload */;
extern DELPHI_PACKAGE float __fastcall ClampValue(const float aValue, const float aMin)/* overload */;
extern DELPHI_PACKAGE TAffineDblVector __fastcall MakeAffineDblVector(double *V, const System::NativeInt V_High);
extern DELPHI_PACKAGE THomogeneousDblVector __fastcall MakeDblVector(double *V, const System::NativeInt V_High);
extern DELPHI_PACKAGE bool __fastcall PointInPolygon(const float *xp, const System::NativeInt xp_High, const float *yp, const System::NativeInt yp_High, float X, float Y);
extern DELPHI_PACKAGE bool __fastcall IsPointInPolygon(const System::Types::TPoint *Polygon, const System::NativeInt Polygon_High, const System::Types::TPoint &p);
extern DELPHI_PACKAGE void __fastcall DivMod(int Dividend, System::Word Divisor, System::Word &result, System::Word &Remainder);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall ConvertRotation(const TAffineVector &Angles);
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionSlerp(const TQuaternion &QStart, const TQuaternion &QEnd, int Spin, float T)/* overload */;
extern DELPHI_PACKAGE TQuaternion __fastcall QuaternionSlerp(const TQuaternion &source, const TQuaternion &dest, const float T)/* overload */;
extern DELPHI_PACKAGE THomogeneousVector __fastcall VectorDblToFlt(const THomogeneousDblVector &V);
extern DELPHI_PACKAGE TAffineVector __fastcall VectorAffineDblToFlt(const TAffineDblVector &V);
extern DELPHI_PACKAGE TAffineDblVector __fastcall VectorAffineFltToDbl(const TAffineVector &V);
extern DELPHI_PACKAGE THomogeneousDblVector __fastcall VectorFltToDbl(const Stage::Vectortypes::TGLVector &V);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall Turn(const Stage::Vectortypes::TGLMatrix &Matrix, float Angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall Turn(const Stage::Vectortypes::TGLMatrix &Matrix, const TAffineVector &MasterUp, float Angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall Pitch(const Stage::Vectortypes::TGLMatrix &Matrix, float Angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall Pitch(const Stage::Vectortypes::TGLMatrix &Matrix, const TAffineVector &MasterRight, float Angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall Roll(const Stage::Vectortypes::TGLMatrix &Matrix, float Angle)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TMatrix4f __fastcall Roll(const Stage::Vectortypes::TGLMatrix &Matrix, const TAffineVector &MasterDirection, float Angle)/* overload */;
extern DELPHI_PACKAGE bool __fastcall RayCastPlaneIntersect(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const Stage::Vectortypes::TGLVector &planePoint, const Stage::Vectortypes::TGLVector &planeNormal, Stage::Vectortypes::PGLVector intersectPoint = (Stage::Vectortypes::PGLVector)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall RayCastPlaneXZIntersect(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const float planeY, Stage::Vectortypes::PGLVector intersectPoint = (Stage::Vectortypes::PGLVector)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall RayCastTriangleIntersect(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3, Stage::Vectortypes::PGLVector intersectPoint = (Stage::Vectortypes::PGLVector)(0x0), Stage::Vectortypes::PGLVector intersectNormal = (Stage::Vectortypes::PGLVector)(0x0))/* overload */;
extern DELPHI_PACKAGE float __fastcall RayCastMinDistToPoint(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const Stage::Vectortypes::TGLVector &point);
extern DELPHI_PACKAGE bool __fastcall RayCastIntersectsSphere(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const Stage::Vectortypes::TGLVector &sphereCenter, const float SphereRadius)/* overload */;
extern DELPHI_PACKAGE int __fastcall RayCastSphereIntersect(const Stage::Vectortypes::TGLVector &rayStart, const Stage::Vectortypes::TGLVector &rayVector, const Stage::Vectortypes::TGLVector &sphereCenter, const float SphereRadius, Stage::Vectortypes::TGLVector &i1, Stage::Vectortypes::TGLVector &i2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall RayCastBoxIntersect(const TAffineVector &rayStart, const TAffineVector &rayVector, const TAffineVector &aMinExtent, const TAffineVector &aMaxExtent, PAffineVector intersectPoint = (PAffineVector)(0x0));
extern DELPHI_PACKAGE float __fastcall SphereVisibleRadius(float distance, float radius);
extern DELPHI_PACKAGE int __fastcall IntersectLinePlane(const Stage::Vectortypes::TGLVector &point, const Stage::Vectortypes::TGLVector &direction, const THmgPlane &plane, Stage::Vectortypes::PGLVector intersectPoint = (Stage::Vectortypes::PGLVector)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall IntersectTriangleBox(const TAffineVector &p1, const TAffineVector &p2, const TAffineVector &p3, const TAffineVector &aMinExtent, const TAffineVector &aMaxExtent);
extern DELPHI_PACKAGE bool __fastcall IntersectSphereBox(const Stage::Vectortypes::TGLVector &SpherePos, const float SphereRadius, const Stage::Vectortypes::TGLMatrix &BoxMatrix, const TAffineVector &BoxScale, PAffineVector intersectPoint = (PAffineVector)(0x0), PAffineVector normal = (PAffineVector)(0x0), System::PSingle depth = (System::PSingle)(0x0));
extern DELPHI_PACKAGE TFrustum __fastcall ExtractFrustumFromModelViewProjection(const Stage::Vectortypes::TGLMatrix &modelViewProj);
extern DELPHI_PACKAGE bool __fastcall IsVolumeClipped(const TAffineVector &objPos, const float objRadius, const TFrustum &Frustum)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsVolumeClipped(const Stage::Vectortypes::TGLVector &objPos, const float objRadius, const TFrustum &Frustum)/* overload */;
extern DELPHI_PACKAGE bool __fastcall IsVolumeClipped(const TAffineVector &min, const TAffineVector &max, const TFrustum &Frustum)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall MakeParallelProjectionMatrix(const THmgPlane &plane, const Stage::Vectortypes::TGLVector &dir);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall MakeShadowMatrix(const Stage::Vectortypes::TGLVector &planePoint, const Stage::Vectortypes::TGLVector &planeNormal, const Stage::Vectortypes::TGLVector &lightPos);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall MakeReflectionMatrix(const TAffineVector &planePoint, const TAffineVector &planeNormal);
extern DELPHI_PACKAGE TPackedRotationMatrix __fastcall PackRotationMatrix(const Stage::Vectortypes::TGLMatrix &mat);
extern DELPHI_PACKAGE Stage::Vectortypes::TGLMatrix __fastcall UnPackRotationMatrix(const TPackedRotationMatrix &packedMatrix);
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall Vector2fMake(const float X, const float Y)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2i __fastcall Vector2iMake(const System::LongInt X, const System::LongInt Y)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2s __fastcall Vector2sMake(const short X, const short Y)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2d __fastcall Vector2dMake(const double X, const double Y)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2b __fastcall Vector2bMake(const System::Byte X, const System::Byte Y)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall Vector2fMake(const Stage::Vectortypes::TVector3f &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2i __fastcall Vector2iMake(const Stage::Vectortypes::TVector3i &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2s __fastcall Vector2sMake(const Stage::Vectortypes::TVector3s &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2d __fastcall Vector2dMake(const Stage::Vectortypes::TVector3d &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2b __fastcall Vector2bMake(const Stage::Vectortypes::TVector3b Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall Vector2fMake(const Stage::Vectortypes::TVector4f &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2i __fastcall Vector2iMake(const Stage::Vectortypes::TVector4i &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2s __fastcall Vector2sMake(const Stage::Vectortypes::TVector4s &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2d __fastcall Vector2dMake(const Stage::Vectortypes::TVector4d &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2b __fastcall Vector2bMake(const Stage::Vectortypes::TVector4b Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall Vector3fMake(const float X, const float Y = 0.000000E+00f, const float Z = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3i __fastcall Vector3iMake(const System::LongInt X, const System::LongInt Y = 0x0, const System::LongInt Z = 0x0)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3s __fastcall Vector3sMake(const short X, const short Y = (short)(0x0), const short Z = (short)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3d __fastcall Vector3dMake(const double X, const double Y = 0.000000E+00, const double Z = 0.000000E+00)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3b __fastcall Vector3bMake(const System::Byte X, const System::Byte Y = (System::Byte)(0x0), const System::Byte Z = (System::Byte)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall Vector3fMake(const Stage::Vectortypes::TVector2f &Vector, const float Z = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3i __fastcall Vector3iMake(const Stage::Vectortypes::TVector2i &Vector, const System::LongInt Z = 0x0)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3s __fastcall Vector3sMake(const Stage::Vectortypes::TVector2s Vector, const short Z = (short)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3d __fastcall Vector3dMake(const Stage::Vectortypes::TVector2d &Vector, const double Z = 0.000000E+00)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3b __fastcall Vector3bMake(const Stage::Vectortypes::TVector2b Vector, const System::Byte Z = (System::Byte)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall Vector3fMake(const Stage::Vectortypes::TVector4f &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3i __fastcall Vector3iMake(const Stage::Vectortypes::TVector4i &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3s __fastcall Vector3sMake(const Stage::Vectortypes::TVector4s &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3d __fastcall Vector3dMake(const Stage::Vectortypes::TVector4d &Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3b __fastcall Vector3bMake(const Stage::Vectortypes::TVector4b Vector)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall Vector4fMake(const float X, const float Y = 0.000000E+00f, const float Z = 0.000000E+00f, const float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4i __fastcall Vector4iMake(const System::LongInt X, const System::LongInt Y = 0x0, const System::LongInt Z = 0x0, const System::LongInt W = 0x0)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4s __fastcall Vector4sMake(const short X, const short Y = (short)(0x0), const short Z = (short)(0x0), const short W = (short)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4d __fastcall Vector4dMake(const double X, const double Y = 0.000000E+00, const double Z = 0.000000E+00, const double W = 0.000000E+00)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4b __fastcall Vector4bMake(const System::Byte X, const System::Byte Y = (System::Byte)(0x0), const System::Byte Z = (System::Byte)(0x0), const System::Byte W = (System::Byte)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall Vector4fMake(const Stage::Vectortypes::TVector3f &Vector, const float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4i __fastcall Vector4iMake(const Stage::Vectortypes::TVector3i &Vector, const System::LongInt W = 0x0)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4s __fastcall Vector4sMake(const Stage::Vectortypes::TVector3s &Vector, const short W = (short)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4d __fastcall Vector4dMake(const Stage::Vectortypes::TVector3d &Vector, const double W = 0.000000E+00)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4b __fastcall Vector4bMake(const Stage::Vectortypes::TVector3b Vector, const System::Byte W = (System::Byte)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall Vector4fMake(const Stage::Vectortypes::TVector2f &Vector, const float Z = 0.000000E+00f, const float W = 0.000000E+00f)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4i __fastcall Vector4iMake(const Stage::Vectortypes::TVector2i &Vector, const System::LongInt Z = 0x0, const System::LongInt W = 0x0)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4s __fastcall Vector4sMake(const Stage::Vectortypes::TVector2s Vector, const short Z = (short)(0x0), const short W = (short)(0x0))/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4d __fastcall Vector4dMake(const Stage::Vectortypes::TVector2d &Vector, const double Z = 0.000000E+00, const double W = 0.000000E+00)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4b __fastcall Vector4bMake(const Stage::Vectortypes::TVector2b Vector, const System::Byte Z = (System::Byte)(0x0), const System::Byte W = (System::Byte)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector2f &Vector1, const Stage::Vectortypes::TVector2f &Vector2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector2i &Vector1, const Stage::Vectortypes::TVector2i &Vector2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector2d &V1, const Stage::Vectortypes::TVector2d &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector2s V1, const Stage::Vectortypes::TVector2s V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector2b V1, const Stage::Vectortypes::TVector2b V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector3i &V1, const Stage::Vectortypes::TVector3i &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector3d &V1, const Stage::Vectortypes::TVector3d &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector3s &V1, const Stage::Vectortypes::TVector3s &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector3b V1, const Stage::Vectortypes::TVector3b V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector4i &V1, const Stage::Vectortypes::TVector4i &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector4d &V1, const Stage::Vectortypes::TVector4d &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector4s &V1, const Stage::Vectortypes::TVector4s &V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorEquals(const Stage::Vectortypes::TVector4b V1, const Stage::Vectortypes::TVector4b V2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix3f &Matrix1, const Stage::Vectortypes::TMatrix3f &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix3i &Matrix1, const Stage::Vectortypes::TMatrix3i &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix3d &Matrix1, const Stage::Vectortypes::TMatrix3d &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix3s &Matrix1, const Stage::Vectortypes::TMatrix3s &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix3b &Matrix1, const Stage::Vectortypes::TMatrix3b &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix4f &Matrix1, const Stage::Vectortypes::TMatrix4f &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix4i &Matrix1, const Stage::Vectortypes::TMatrix4i &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix4d &Matrix1, const Stage::Vectortypes::TMatrix4d &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix4s &Matrix1, const Stage::Vectortypes::TMatrix4s &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall MatrixEquals(const Stage::Vectortypes::TMatrix4b &Matrix1, const Stage::Vectortypes::TMatrix4b &Matrix2)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3f &SourceVector, const Stage::Vectortypes::TVector3f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3f &SourceVector, const Stage::Vectortypes::TVector3f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3f &SourceVector, const Stage::Vectortypes::TVector3f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3f &SourceVector, const Stage::Vectortypes::TVector3f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4f &SourceVector, const Stage::Vectortypes::TVector4f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4f &SourceVector, const Stage::Vectortypes::TVector4f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4f &SourceVector, const Stage::Vectortypes::TVector4f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4f &SourceVector, const Stage::Vectortypes::TVector4f &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3i &SourceVector, const Stage::Vectortypes::TVector3i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3i &SourceVector, const Stage::Vectortypes::TVector3i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3i &SourceVector, const Stage::Vectortypes::TVector3i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3i &SourceVector, const Stage::Vectortypes::TVector3i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4i &SourceVector, const Stage::Vectortypes::TVector4i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4i &SourceVector, const Stage::Vectortypes::TVector4i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4i &SourceVector, const Stage::Vectortypes::TVector4i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4i &SourceVector, const Stage::Vectortypes::TVector4i &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3s &SourceVector, const Stage::Vectortypes::TVector3s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3s &SourceVector, const Stage::Vectortypes::TVector3s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3s &SourceVector, const Stage::Vectortypes::TVector3s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3s &SourceVector, const Stage::Vectortypes::TVector3s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4s &SourceVector, const Stage::Vectortypes::TVector4s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4s &SourceVector, const Stage::Vectortypes::TVector4s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4s &SourceVector, const Stage::Vectortypes::TVector4s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4s &SourceVector, const Stage::Vectortypes::TVector4s &ComparedVector)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4f &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4i &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector3s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector3s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector3s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector3s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreThen(const Stage::Vectortypes::TVector4s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorMoreEqualThen(const Stage::Vectortypes::TVector4s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessThen(const Stage::Vectortypes::TVector4s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall VectorLessEqualThen(const Stage::Vectortypes::TVector4s &SourceVector, const float ComparedNumber)/* overload */;
extern DELPHI_PACKAGE bool __fastcall RectanglesIntersect(const Stage::Vectortypes::TVector2f &ACenterOfRect1, const Stage::Vectortypes::TVector2f &ACenterOfRect2, const Stage::Vectortypes::TVector2f &ASizeOfRect1, const Stage::Vectortypes::TVector2f &ASizeOfRect2);
extern DELPHI_PACKAGE bool __fastcall RectangleContains(const Stage::Vectortypes::TVector2f &ACenterOfBigRect1, const Stage::Vectortypes::TVector2f &ACenterOfSmallRect2, const Stage::Vectortypes::TVector2f &ASizeOfBigRect1, const Stage::Vectortypes::TVector2f &ASizeOfSmallRect2, const float AEps = 0.000000E+00f);
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall GetSafeTurnAngle(const Stage::Vectortypes::TGLVector &AOriginalPosition, const Stage::Vectortypes::TGLVector &AOriginalUpVector, const Stage::Vectortypes::TGLVector &ATargetPosition, const Stage::Vectortypes::TGLVector &AMoveAroundTargetCenter)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector2f __fastcall GetSafeTurnAngle(const TAffineVector &AOriginalPosition, const TAffineVector &AOriginalUpVector, const TAffineVector &ATargetPosition, const TAffineVector &AMoveAroundTargetCenter)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall MoveObjectAround(const Stage::Vectortypes::TGLVector &AMovingObjectPosition, const Stage::Vectortypes::TGLVector &AMovingObjectUp, const Stage::Vectortypes::TGLVector &ATargetPosition, float pitchDelta, float turnDelta);
extern DELPHI_PACKAGE float __fastcall AngleBetweenVectors(const Stage::Vectortypes::TGLVector &a, const Stage::Vectortypes::TGLVector &b, const Stage::Vectortypes::TGLVector &ACenterPoint)/* overload */;
extern DELPHI_PACKAGE float __fastcall AngleBetweenVectors(const TAffineVector &a, const TAffineVector &b, const TAffineVector &ACenterPoint)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TGLVector __fastcall ShiftObjectFromCenter(const Stage::Vectortypes::TGLVector &AOriginalPosition, const Stage::Vectortypes::TGLVector &ACenter, const float ADistance, const bool AFromCenterSpot)/* overload */;
extern DELPHI_PACKAGE Stage::Vectortypes::TVector3f __fastcall ShiftObjectFromCenter(const TAffineVector &AOriginalPosition, const TAffineVector &ACenter, const float ADistance, const bool AFromCenterSpot)/* overload */;
}	/* namespace Vectorgeometry */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_VECTORGEOMETRY)
using namespace Stage::Vectorgeometry;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_VectorGeometryHPP
