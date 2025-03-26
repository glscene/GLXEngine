// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MeshUtils.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshUtilsHPP
#define GXS_MeshUtilsHPP

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
#include <System.Math.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Meshutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TSubdivideEdgeEvent)(const int idxA, const int idxB, const int newIdx);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vImprovedFixingOpenTriangleEdge;
extern DELPHI_PACKAGE System::LongWord vEdgeInfoReserveSize;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Gxs::Vectorlists::TgxAffineVectorList* const strip, Gxs::Vectorlists::TgxAffineVectorList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Gxs::Vectorlists::TgxIntegerList* const strip, Gxs::Vectorlists::TgxIntegerList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Gxs::Vectorlists::TgxAffineVectorList* const strip, Gxs::Vectorlists::TgxIntegerList* const indices, Gxs::Vectorlists::TgxAffineVectorList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertIndexedListToList(Gxs::Vectorlists::TgxAffineVectorList* const data, Gxs::Vectorlists::TgxIntegerList* const indices, Gxs::Vectorlists::TgxAffineVectorList* list);
extern DELPHI_PACKAGE Gxs::Vectorlists::TgxIntegerList* __fastcall BuildVectorCountOptimizedIndices(Gxs::Vectorlists::TgxAffineVectorList* const vertices, Gxs::Vectorlists::TgxAffineVectorList* const normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* const texCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
extern DELPHI_PACKAGE void __fastcall RemapReferences(Gxs::Vectorlists::TgxAffineVectorList* reference, Gxs::Vectorlists::TgxIntegerList* const indices)/* overload */;
extern DELPHI_PACKAGE void __fastcall RemapReferences(Gxs::Vectorlists::TgxIntegerList* reference, Gxs::Vectorlists::TgxIntegerList* const indices)/* overload */;
extern DELPHI_PACKAGE void __fastcall RemapAndCleanupReferences(Gxs::Vectorlists::TgxAffineVectorList* reference, Gxs::Vectorlists::TgxIntegerList* indices);
extern DELPHI_PACKAGE Gxs::Vectorlists::TgxIntegerList* __fastcall RemapIndicesToIndicesMap(Gxs::Vectorlists::TgxIntegerList* remapIndices);
extern DELPHI_PACKAGE void __fastcall RemapTrianglesIndices(Gxs::Vectorlists::TgxIntegerList* indices, Gxs::Vectorlists::TgxIntegerList* indicesMap);
extern DELPHI_PACKAGE void __fastcall remapIndices(Gxs::Vectorlists::TgxIntegerList* indices, Gxs::Vectorlists::TgxIntegerList* indicesMap);
extern DELPHI_PACKAGE void __fastcall UnifyTrianglesWinding(Gxs::Vectorlists::TgxIntegerList* indices);
extern DELPHI_PACKAGE void __fastcall InvertTrianglesWinding(Gxs::Vectorlists::TgxIntegerList* indices);
extern DELPHI_PACKAGE Gxs::Vectorlists::TgxAffineVectorList* __fastcall BuildNormals(Gxs::Vectorlists::TgxAffineVectorList* reference, Gxs::Vectorlists::TgxIntegerList* indices);
extern DELPHI_PACKAGE Gxs::Vectorlists::TgxIntegerList* __fastcall BuildNonOrientedEdgesList(Gxs::Vectorlists::TgxIntegerList* triangleIndices, Gxs::Vectorlists::TgxIntegerList* triangleEdges = (Gxs::Vectorlists::TgxIntegerList*)(0x0), Gxs::Vectorlists::TgxIntegerList* edgesTriangles = (Gxs::Vectorlists::TgxIntegerList*)(0x0));
extern DELPHI_PACKAGE void __fastcall IncreaseCoherency(Gxs::Vectorlists::TgxIntegerList* indices, int cacheSize);
extern DELPHI_PACKAGE void __fastcall WeldVertices(Gxs::Vectorlists::TgxAffineVectorList* vertices, Gxs::Vectorlists::TgxIntegerList* indicesMap, float weldRadius);
extern DELPHI_PACKAGE Gxs::Persistentclasses::TgxPersistentObjectList* __fastcall StripifyMesh(Gxs::Vectorlists::TgxIntegerList* indices, int maxVertexIndex, bool agglomerateLoneTriangles = false);
extern DELPHI_PACKAGE void __fastcall SubdivideTriangles(float smoothFactor, Gxs::Vectorlists::TgxAffineVectorList* vertices, Gxs::Vectorlists::TgxIntegerList* triangleIndices, Gxs::Vectorlists::TgxAffineVectorList* normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), TSubdivideEdgeEvent onSubdivideEdge = 0x0);
extern DELPHI_PACKAGE Gxs::Vectorlists::TGLongWordList* __fastcall MakeTriangleAdjacencyList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, const Stage::Vectorgeometry::PAffineVectorArray AVerticesList);
extern DELPHI_PACKAGE Gxs::Vectorlists::TGLongWordList* __fastcall ConvertStripToList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, System::LongWord RestartIndex)/* overload */;
extern DELPHI_PACKAGE Gxs::Vectorlists::TGLongWordList* __fastcall ConvertFansToList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, System::LongWord RestartIndex);
}	/* namespace Meshutils */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESHUTILS)
using namespace Gxs::Meshutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshUtilsHPP
