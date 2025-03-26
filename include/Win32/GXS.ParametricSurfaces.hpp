// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ParametricSurfaces.pas' rev: 36.00 (Windows)

#ifndef GXS_ParametricSurfacesHPP
#define GXS_ParametricSurfacesHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.CurvesAndSurfaces.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Parametricsurfaces
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TMOParametricSurface;
class DELPHICLASS TFGBezierSurface;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TParametricSurfaceRenderer : unsigned char { psrGLXcene, psrOpenVX };

enum DECLSPEC_DENUM TParametricSurfaceBasis : unsigned char { psbBezier, psbBSpline };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TMOParametricSurface : public Gxs::Vectorfileobjects::TgxMeshObject
{
	typedef Gxs::Vectorfileobjects::TgxMeshObject inherited;
	
private:
	Gxs::Vectorlists::TgxAffineVectorList* FControlPoints;
	Gxs::Vectorlists::TgxAffineVectorList* FWeightedControlPoints;
	Gxs::Vectorlists::TgxSingleList* FKnotsU;
	Gxs::Vectorlists::TgxSingleList* FKnotsV;
	Gxs::Vectorlists::TgxSingleList* FWeights;
	int FOrderU;
	int FOrderV;
	int FCountU;
	int FCountV;
	int FResolution;
	bool FAutoKnots;
	Gxs::Curvesandsurfaces::TBSplineContinuity FContinuity;
	TParametricSurfaceRenderer FRenderer;
	TParametricSurfaceBasis FBasis;
	void __fastcall SetControlPoints(Gxs::Vectorlists::TgxAffineVectorList* Value);
	void __fastcall SetKnotsU(Gxs::Vectorlists::TgxSingleList* Value);
	void __fastcall SetKnotsV(Gxs::Vectorlists::TgxSingleList* Value);
	void __fastcall SetWeights(Gxs::Vectorlists::TgxSingleList* Value);
	void __fastcall SetRenderer(TParametricSurfaceRenderer Value);
	void __fastcall SetBasis(TParametricSurfaceBasis Value);
	
public:
	__fastcall virtual TMOParametricSurface();
	__fastcall virtual ~TMOParametricSurface();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall Prepare();
	virtual void __fastcall Clear();
	void __fastcall GenerateMesh();
	__property Gxs::Vectorlists::TgxAffineVectorList* ControlPoints = {read=FControlPoints, write=SetControlPoints};
	__property Gxs::Vectorlists::TgxSingleList* KnotsU = {read=FKnotsU, write=SetKnotsU};
	__property Gxs::Vectorlists::TgxSingleList* KnotsV = {read=FKnotsV, write=SetKnotsV};
	__property Gxs::Vectorlists::TgxSingleList* Weights = {read=FWeights, write=SetWeights};
	__property int OrderU = {read=FOrderU, write=FOrderU, nodefault};
	__property int OrderV = {read=FOrderV, write=FOrderV, nodefault};
	__property int CountU = {read=FCountU, write=FCountU, nodefault};
	__property int CountV = {read=FCountV, write=FCountV, nodefault};
	__property int Resolution = {read=FResolution, write=FResolution, nodefault};
	__property bool AutoKnots = {read=FAutoKnots, write=FAutoKnots, nodefault};
	__property Gxs::Curvesandsurfaces::TBSplineContinuity Continuity = {read=FContinuity, write=FContinuity, nodefault};
	__property TParametricSurfaceRenderer Renderer = {read=FRenderer, write=SetRenderer, nodefault};
	__property TParametricSurfaceBasis Basis = {read=FBasis, write=SetBasis, nodefault};
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TMOParametricSurface(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : Gxs::Vectorfileobjects::TgxMeshObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TMOParametricSurface(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGBezierSurface : public Gxs::Vectorfileobjects::TgxFaceGroup
{
	typedef Gxs::Vectorfileobjects::TgxFaceGroup inherited;
	
private:
	int FCountU;
	int FCountV;
	Gxs::Vectorlists::TgxIntegerList* FControlPointIndices;
	Gxs::Vectorlists::TgxIntegerList* FTexCoordIndices;
	int FResolution;
	float FMinU;
	float FMaxU;
	float FMinV;
	float FMaxV;
	Gxs::Vectorlists::TgxAffineVectorList* FTempControlPoints;
	Gxs::Vectorlists::TgxAffineVectorList* FTempTexCoords;
	
protected:
	void __fastcall SetControlPointIndices(Gxs::Vectorlists::TgxIntegerList* const Value);
	void __fastcall SetTexCoordIndices(Gxs::Vectorlists::TgxIntegerList* const Value);
	
public:
	__fastcall virtual TFGBezierSurface();
	__fastcall virtual ~TFGBezierSurface();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall Prepare();
	__property int CountU = {read=FCountU, write=FCountU, nodefault};
	__property int CountV = {read=FCountV, write=FCountV, nodefault};
	__property int Resolution = {read=FResolution, write=FResolution, nodefault};
	__property float MinU = {read=FMinU, write=FMinU};
	__property float MaxU = {read=FMaxU, write=FMaxU};
	__property float MinV = {read=FMinV, write=FMinV};
	__property float MaxV = {read=FMaxV, write=FMaxV};
	__property Gxs::Vectorlists::TgxIntegerList* ControlPointIndices = {read=FControlPointIndices, write=SetControlPointIndices};
	__property Gxs::Vectorlists::TgxIntegerList* TexCoordIndices = {read=FTexCoordIndices, write=SetTexCoordIndices};
public:
	/* TgxFaceGroup.CreateOwned */ inline __fastcall virtual TFGBezierSurface(Gxs::Vectorfileobjects::TgxFaceGroups* aOwner) : Gxs::Vectorfileobjects::TgxFaceGroup(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TFGBezierSurface(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxFaceGroup(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Parametricsurfaces */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PARAMETRICSURFACES)
using namespace Gxs::Parametricsurfaces;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ParametricSurfacesHPP
