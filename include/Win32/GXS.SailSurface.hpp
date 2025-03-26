// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SailSurface.pas' rev: 36.00 (Windows)

#ifndef GXS_SailSurfaceHPP
#define GXS_SailSurfaceHPP

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
#include <System.Math.Vectors.hpp>
#include <System.Threading.hpp>
#include <System.Types.hpp>
#include <System.Generics.Collections.hpp>
#include <System.RTLConsts.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.MaterialSources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Sailsurface
{
//-- forward type declarations -----------------------------------------------
struct TSailParams;
class DELPHICLASS TgxSailSurface;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TSailShape : unsigned char { ShapeMain, ShapeSimetric, ShapeJib };

typedef System::DynamicArray<System::Types::TPointF> TPointF_Array;

struct DECLSPEC_DRECORD TSailParams
{
public:
	float Lb;
	float Lt;
	float Lm;
	float Ht;
	float Hx;
	float Lx;
	float __fastcall GetSailChord(TSailShape aType, const float H);
};


class PASCALIMPLEMENTATION TgxSailSurface : public Fmx::Objects3d::TPlane
{
	typedef Fmx::Objects3d::TPlane inherited;
	
private:
	TSailShape fSailShape;
	int fVersion;
	float __fastcall GetChordBottom();
	float __fastcall GetChordMid();
	float __fastcall GetChordTop();
	float __fastcall GetSailHeight();
	void __fastcall SetChordBottom(const float Value);
	void __fastcall SetChordMid(const float Value);
	void __fastcall SetChordTop(const float Value);
	void __fastcall SetSailHeight(const float Value);
	void __fastcall SetSailShape(const TSailShape Value);
	void __fastcall CalcSailSurfaceMesh();
	float __fastcall GetChordX();
	float __fastcall GetHeightX();
	void __fastcall SetChordX(const float Value);
	void __fastcall SetHeightX(const float Value);
	void __fastcall setVersion(const int Value);
	
protected:
	float fTime;
	int fNbMesh;
	TSailParams fSailParams;
	bool fShowlines;
	bool fUseTasks;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	System::Math::Vectors::TPoint3D fCenter;
	bool fCamberRight;
	virtual void __fastcall SetDepth(const float Value);
	
public:
	__fastcall virtual TgxSailSurface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSailSurface();
	virtual void __fastcall Render();
	float __fastcall Altura(const System::Math::Vectors::TPoint3D &P);
	void __fastcall SetSailParams(const TSailParams &aSailParams);
	void __fastcall SetMeshWith2Dline(TPointF_Array aPtArray);
	
__published:
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property bool UseTasks = {read=fUseTasks, write=fUseTasks, nodefault};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
	__property TSailShape SailShape = {read=fSailShape, write=SetSailShape, default=0};
	__property bool CamberRight = {read=fCamberRight, write=fCamberRight, nodefault};
	__property float SailHeight = {read=GetSailHeight, write=SetSailHeight};
	__property float ChordTop = {read=GetChordTop, write=SetChordTop};
	__property float ChordMid = {read=GetChordMid, write=SetChordMid};
	__property float ChordBottom = {read=GetChordBottom, write=SetChordBottom};
	__property float HeightX = {read=GetHeightX, write=SetHeightX};
	__property float ChordX = {read=GetChordX, write=SetChordX};
	__property int version = {read=fVersion, write=setVersion, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall CalcQuadraticInterpolation(const float x0, const float y0, const float x1, const float y1, const float x2, const float y2, const float x, float &y);
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Sailsurface */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SAILSURFACE)
using namespace Gxs::Sailsurface;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SailSurfaceHPP
