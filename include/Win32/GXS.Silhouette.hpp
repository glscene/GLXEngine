// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Silhouette.pas' rev: 36.00 (Windows)

#ifndef GXS_SilhouetteHPP
#define GXS_SilhouetteHPP

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
#include <GXS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Silhouette
{
//-- forward type declarations -----------------------------------------------
struct TgxSilhouetteParameters;
class DELPHICLASS TgxSilhouette;
class DELPHICLASS TBaseConnectivity;
class DELPHICLASS TConnectivity;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSilhouetteStyle : unsigned char { ssOmni, ssParallel };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxSilhouetteParameters
{
public:
	Stage::Vectorgeometry::TAffineVector SeenFrom;
	Stage::Vectorgeometry::TAffineVector LightDirection;
	TgxSilhouetteStyle Style;
	bool CappingRequired;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSilhouette : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gxs::Vectorlists::TgxVectorList* FVertices;
	Gxs::Vectorlists::TgxIntegerList* FIndices;
	Gxs::Vectorlists::TgxIntegerList* FCapIndices;
	TgxSilhouetteParameters FParameters;
	
protected:
	void __fastcall SetIndices(Gxs::Vectorlists::TgxIntegerList* const value);
	void __fastcall SetCapIndices(Gxs::Vectorlists::TgxIntegerList* const value);
	void __fastcall SetVertices(Gxs::Vectorlists::TgxVectorList* const value);
	
public:
	__fastcall virtual TgxSilhouette();
	__fastcall virtual ~TgxSilhouette();
	__property TgxSilhouetteParameters Parameters = {read=FParameters, write=FParameters};
	__property Gxs::Vectorlists::TgxVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Gxs::Vectorlists::TgxIntegerList* Indices = {read=FIndices, write=SetIndices};
	__property Gxs::Vectorlists::TgxIntegerList* CapIndices = {read=FCapIndices, write=SetCapIndices};
	void __fastcall Flush();
	void __fastcall Clear();
	void __fastcall ExtrudeVerticesToInfinity(const Stage::Vectorgeometry::TAffineVector &origin);
	void __fastcall AddEdgeToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, bool tightButSlow);
	void __fastcall AddIndexedEdgeToSilhouette(const int Vi0, const int Vi1);
	void __fastcall AddCapToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2, bool tightButSlow);
	void __fastcall AddIndexedCapToSilhouette(const int Vi0, const int Vi1, const int vi2);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TBaseConnectivity : public System::TObject
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
	virtual void __fastcall CreateSilhouette(const TgxSilhouetteParameters &ASilhouetteParameters, TgxSilhouette* &ASilhouette, bool AddToSilhouette);
	__fastcall virtual TBaseConnectivity(bool APrecomputeFaceNormal);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseConnectivity() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TConnectivity : public TBaseConnectivity
{
	typedef TBaseConnectivity inherited;
	
protected:
	Gxs::Vectorlists::TgxIntegerList* FEdgeVertices;
	Gxs::Vectorlists::TgxIntegerList* FEdgeFaces;
	Gxs::Vectorlists::TGByteList* FFaceVisible;
	Gxs::Vectorlists::TgxIntegerList* FFaceVertexIndex;
	Gxs::Vectorlists::TgxAffineVectorList* FFaceNormal;
	Gxs::Vectorlists::TgxIntegerList* FVertexMemory;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	int __fastcall ReuseOrFindVertexID(const Stage::Vectorgeometry::TAffineVector &SeenFrom, TgxSilhouette* ASilhouette, int index);
	
public:
	virtual void __fastcall Clear();
	virtual void __fastcall CreateSilhouette(const TgxSilhouetteParameters &silhouetteParameters, TgxSilhouette* &ASilhouette, bool AddToSilhouette);
	int __fastcall AddIndexedEdge(int vertexIndex0, int vertexIndex1, int FaceID);
	int __fastcall AddIndexedFace(int Vi0, int Vi1, int vi2);
	int __fastcall AddFace(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2);
	int __fastcall AddQuad(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2, const Stage::Vectorgeometry::TAffineVector &vertex3);
	__property int EdgeCount = {read=GetEdgeCount, nodefault};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__fastcall virtual TConnectivity(bool APrecomputeFaceNormal);
	__fastcall virtual ~TConnectivity();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Silhouette */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SILHOUETTE)
using namespace Gxs::Silhouette;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SilhouetteHPP
