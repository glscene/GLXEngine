// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.BaseMeshSilhouette.pas' rev: 36.00 (Windows)

#ifndef GXS_BaseMeshSilhouetteHPP
#define GXS_BaseMeshSilhouetteHPP

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
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Silhouette.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Basemeshsilhouette
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFaceGroupConnectivity;
class DELPHICLASS TgxBaseMeshConnectivity;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxFaceGroupConnectivity : public Gxs::Silhouette::TConnectivity
{
	typedef Gxs::Silhouette::TConnectivity inherited;
	
private:
	Gxs::Vectorfileobjects::TgxMeshObject* FMeshObject;
	bool FOwnsVertices;
	void __fastcall SetMeshObject(Gxs::Vectorfileobjects::TgxMeshObject* const Value);
	
public:
	virtual void __fastcall Clear();
	void __fastcall RebuildEdgeList();
	__property Gxs::Vectorfileobjects::TgxMeshObject* MeshObject = {read=FMeshObject, write=SetMeshObject};
	__fastcall virtual TgxFaceGroupConnectivity(bool APrecomputeFaceNormal);
	__fastcall TgxFaceGroupConnectivity(Gxs::Vectorfileobjects::TgxMeshObject* aMeshObject, bool APrecomputeFaceNormal);
	__fastcall virtual ~TgxFaceGroupConnectivity();
};


class PASCALIMPLEMENTATION TgxBaseMeshConnectivity : public Gxs::Silhouette::TBaseConnectivity
{
	typedef Gxs::Silhouette::TBaseConnectivity inherited;
	
private:
	Gxs::Vectorfileobjects::TgxBaseMesh* FBaseMesh;
	System::Classes::TList* FFaceGroupConnectivityList;
	TgxFaceGroupConnectivity* __fastcall GetFaceGroupConnectivity(int i);
	int __fastcall GetConnectivityCount();
	void __fastcall SetBaseMesh(Gxs::Vectorfileobjects::TgxBaseMesh* const Value);
	
protected:
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	
public:
	__property int ConnectivityCount = {read=GetConnectivityCount, nodefault};
	__property TgxFaceGroupConnectivity* FaceGroupConnectivity[int i] = {read=GetFaceGroupConnectivity};
	__property Gxs::Vectorfileobjects::TgxBaseMesh* BaseMesh = {read=FBaseMesh, write=SetBaseMesh};
	void __fastcall Clear(bool SaveFaceGroupConnectivity);
	void __fastcall RebuildEdgeList();
	HIDESBASE void __fastcall CreateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &SilhouetteParameters, Gxs::Silhouette::TgxSilhouette* &aSilhouette, bool AddToSilhouette);
	__fastcall virtual TgxBaseMeshConnectivity(bool APrecomputeFaceNormal);
	__fastcall TgxBaseMeshConnectivity(Gxs::Vectorfileobjects::TgxBaseMesh* aBaseMesh);
	__fastcall virtual ~TgxBaseMeshConnectivity();
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Basemeshsilhouette */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BASEMESHSILHOUETTE)
using namespace Gxs::Basemeshsilhouette;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BaseMeshSilhouetteHPP
