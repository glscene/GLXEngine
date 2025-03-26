// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Silhouette.pas' rev: 36.00 (Windows)

#ifndef GLS_SilhouetteHPP
#define GLS_SilhouetteHPP

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
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Silhouette
{
//-- forward type declarations -----------------------------------------------
struct TGLSilhouetteParameters;
class DELPHICLASS TGLSilhouette;
class DELPHICLASS TGLBaseConnectivity;
class DELPHICLASS TGLConnectivity;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGSilhouetteStyle : unsigned char { ssOmni, ssParallel };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGLSilhouetteParameters
{
public:
	Stage::Vectorgeometry::TAffineVector SeenFrom;
	Stage::Vectorgeometry::TAffineVector LightDirection;
	TGSilhouetteStyle Style;
	bool CappingRequired;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSilhouette : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gls::Vectorlists::TGLVectorList* FVertices;
	Gls::Vectorlists::TGLIntegerList* FIndices;
	Gls::Vectorlists::TGLIntegerList* FCapIndices;
	TGLSilhouetteParameters FParameters;
	
protected:
	void __fastcall SetIndices(Gls::Vectorlists::TGLIntegerList* const value);
	void __fastcall SetCapIndices(Gls::Vectorlists::TGLIntegerList* const value);
	void __fastcall SetVertices(Gls::Vectorlists::TGLVectorList* const value);
	
public:
	__fastcall virtual TGLSilhouette();
	__fastcall virtual ~TGLSilhouette();
	__property TGLSilhouetteParameters Parameters = {read=FParameters, write=FParameters};
	__property Gls::Vectorlists::TGLVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Gls::Vectorlists::TGLIntegerList* Indices = {read=FIndices, write=SetIndices};
	__property Gls::Vectorlists::TGLIntegerList* CapIndices = {read=FCapIndices, write=SetCapIndices};
	virtual void __fastcall Flush();
	void __fastcall Clear();
	void __fastcall ExtrudeVerticesToInfinity(const Stage::Vectorgeometry::TAffineVector &origin);
	void __fastcall AddEdgeToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, bool tightButSlow);
	void __fastcall AddIndexedEdgeToSilhouette(const int Vi0, const int Vi1);
	void __fastcall AddCapToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2, bool tightButSlow);
	void __fastcall AddIndexedCapToSilhouette(const int Vi0, const int Vi1, const int vi2);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseConnectivity : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FPrecomputeFaceNormal;
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	
public:
	__property int EdgeCount = {read=GetEdgeCount, nodefault};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__property bool PrecomputeFaceNormal = {read=FPrecomputeFaceNormal, nodefault};
	virtual void __fastcall CreateSilhouette(const TGLSilhouetteParameters &ASilhouetteParameters, TGLSilhouette* &ASilhouette, bool AddToSilhouette);
	__fastcall virtual TGLBaseConnectivity(bool APrecomputeFaceNormal);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLBaseConnectivity() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLConnectivity : public TGLBaseConnectivity
{
	typedef TGLBaseConnectivity inherited;
	
protected:
	Gls::Vectorlists::TGLIntegerList* FEdgeVertices;
	Gls::Vectorlists::TGLIntegerList* FEdgeFaces;
	Gls::Vectorlists::TGLByteList* FFaceVisible;
	Gls::Vectorlists::TGLIntegerList* FFaceVertexIndex;
	Gls::Vectorlists::TGLAffineVectorList* FFaceNormal;
	Gls::Vectorlists::TGLIntegerList* FVertexMemory;
	Gls::Vectorlists::TGLAffineVectorList* FVertices;
	HIDESBASE int __fastcall GetEdgeCount();
	HIDESBASE int __fastcall GetFaceCount();
	int __fastcall ReuseOrFindVertexID(const Stage::Vectorgeometry::TAffineVector &SeenFrom, TGLSilhouette* ASilhouette, int index);
	
public:
	virtual void __fastcall Clear();
	HIDESBASE void __fastcall CreateSilhouette(const TGLSilhouetteParameters &silhouetteParameters, TGLSilhouette* &ASilhouette, bool AddToSilhouette);
	int __fastcall AddIndexedEdge(int vertexIndex0, int vertexIndex1, int FaceID);
	int __fastcall AddIndexedFace(int Vi0, int Vi1, int vi2);
	int __fastcall AddFace(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2);
	int __fastcall AddQuad(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2, const Stage::Vectorgeometry::TAffineVector &vertex3);
	__property int EdgeCount = {read=GetEdgeCount, nodefault};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__fastcall virtual TGLConnectivity(bool APrecomputeFaceNormal);
	__fastcall virtual ~TGLConnectivity();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Silhouette */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SILHOUETTE)
using namespace Gls::Silhouette;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_SilhouetteHPP
