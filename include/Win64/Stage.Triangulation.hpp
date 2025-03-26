// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Triangulation.pas' rev: 36.00 (Windows)

#ifndef Stage_TriangulationHPP
#define Stage_TriangulationHPP

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
#include <System.Types.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Triangulation
{
//-- forward type declarations -----------------------------------------------
struct DVertex;
struct DTriangle;
class DELPHICLASS TGDelaunay2D;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TDProgressEvent)(System::UnicodeString State, int Pos, int Max, bool AlwaysUpdate/* = false*/);

struct DECLSPEC_DRECORD DVertex
{
public:
	float X;
	float Y;
	float Z;
	float U;
	float V;
	int MatIndex;
};


struct DECLSPEC_DRECORD DTriangle
{
public:
	System::LongInt vv0;
	System::LongInt vv1;
	System::LongInt vv2;
	int PreCalc;
	float Xc;
	float Yc;
	float R;
};


typedef System::DynamicArray<DVertex> TDVertex;

typedef System::DynamicArray<DTriangle> TDTriangle;

typedef System::DynamicArray<bool> TDComplete;

typedef System::DynamicArray<int> Stage_Triangulation__1;

typedef System::DynamicArray<System::DynamicArray<int> > TDEdges;

class PASCALIMPLEMENTATION TGDelaunay2D : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool __fastcall InCircle(float Xp, float Yp, float X1, float Y1, float X2, float Y2, float X3, float Y3, /* out */ float &Xc, /* out */ float &Yc, /* out */ float &R, int j);
	int __fastcall Triangulate(int nvert);
	
public:
	TDVertex Vertex;
	TDTriangle Triangle;
	int HowMany;
	int TPoints;
	TDProgressEvent OnProgress;
	__fastcall TGDelaunay2D();
	__fastcall virtual ~TGDelaunay2D();
	void __fastcall Mesh(bool sort);
	void __fastcall AddPoint(float X, float Y, float Z, float U, float V, int MatIndex);
	void __fastcall AddPointNoCheck(float X, float Y, float Z, float U, float V, int MatIndex);
	void __fastcall RemoveLastPoint();
	void __fastcall QuickSort(TDVertex &A, int Low, int High);
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST int MaxVertices = int(0x7a120);
static _DELPHI_CONST int MaxTriangles = int(0xf4240);
static const double ExPtTolerance = 1.000000E-06;
}	/* namespace Triangulation */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_TRIANGULATION)
using namespace Stage::Triangulation;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_TriangulationHPP
