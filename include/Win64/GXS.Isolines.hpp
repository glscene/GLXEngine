// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Isolines.pas' rev: 36.00 (Windows)

#ifndef GXS_IsolinesHPP
#define GXS_IsolinesHPP

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
#include <System.Generics.Collections.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <Stage.Spline.hpp>
#include <GXS.Objects.hpp>
#include <GXS.MultiPolygon.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Color.hpp>
#include <GXS.SpaceText.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Scene.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Isolines
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxIsoline;
class DELPHICLASS TgxIsolines;
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<float> TVectorArr;

typedef System::DynamicArray<System::Byte> TByteVectorArr;

typedef System::DynamicArray<float> Gxs_Isolines__1;

typedef System::DynamicArray<System::DynamicArray<float> > TMatrixArr;

typedef System::DynamicArray<System::Byte> Gxs_Isolines__2;

typedef System::DynamicArray<System::DynamicArray<System::Byte> > TByteMatrixArr;

typedef System::StaticArray<float, 5> TVectorL4D;

typedef System::StaticArray<int, 5> TVectorL4I;

typedef System::StaticArray<System::StaticArray<System::StaticArray<int, 3>, 3>, 3> TCastArray;

typedef System::StaticArray<Stage::Vectortypesext::TPoint2DRec, 32768> TVertex2DArr;

typedef TVertex2DArr *PVertex2DArr;

typedef TgxIsoline* *PVXIsoline;

class PASCALIMPLEMENTATION TgxIsoline : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int NP;
	PVertex2DArr Line;
	__fastcall virtual TgxIsoline(int LineSize);
	__fastcall virtual ~TgxIsoline();
};


enum DECLSPEC_DENUM TgxIsolineState : unsigned char { ilsEmpty, ilsCalculating, ilsReady };

class PASCALIMPLEMENTATION TgxIsolines : public Gxs::Objects::TgxLines
{
	typedef Gxs::Objects::TgxLines inherited;
	
	
private:
	typedef System::DynamicArray<Gxs::Spacetext::TgxSpaceText*> _TgxIsolines__1;
	
	
public:
	Stage::Vectorgeometry::TAffineVector IsoVertex;
	_TgxIsolines__1 SpaceTextSF;
	void __fastcall MakeIsolines(TMatrixArr &Depths, int bmSize, float StartDepth, float EndDepth, int Interval);
	void __fastcall FreeList();
	__fastcall virtual TgxIsolines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxIsolines();
	void __fastcall Conrec(int PlaneSFindex, Gxs::Vectorfileobjects::TgxFreeForm* PlaneSF, TMatrixArr Data, int ilb, int iub, int jlb, int jub, TVectorArr X, TVectorArr Y, int NC, TVectorArr HgtL, float Z_Kfix, float res3Dmax, float res3Dmin);
	
private:
	int CoordRange;
	System::Classes::TList* LineList;
	TgxIsolineState IsolineState;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxIsolines(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxLines(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Initialize_Contouring(TMatrixArr &DataGrid, int NXpoints, int NYpoints, float CurrentIsoline);
extern DELPHI_PACKAGE void __fastcall Release_Memory_Isoline(void);
extern DELPHI_PACKAGE bool __fastcall GetNextIsoline(TgxIsoline* &Isoline);
extern DELPHI_PACKAGE void __fastcall TriangleElevationSegments(const Stage::Vectorgeometry::TAffineVector &p1, const Stage::Vectorgeometry::TAffineVector &p2, const Stage::Vectorgeometry::TAffineVector &p3, float ElevationDelta, Gxs::Vectorlists::TgxAffineVectorList* Segments);
}	/* namespace Isolines */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ISOLINES)
using namespace Gxs::Isolines;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_IsolinesHPP
