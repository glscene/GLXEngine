// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TerrainRenderer.pas' rev: 36.00 (Windows)

#ifndef GXS_TerrainRendererHPP
#define GXS_TerrainRendererHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Scene.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.Material.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Context.hpp>
#include <GXS.ROAMPatch.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Terrainrenderer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTerrainRenderer;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TGetTerrainBoundsEvent)(float &l, float &t, float &r, float &b);

typedef void __fastcall (__closure *TPatchPostRenderEvent)(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Classes::TList* const patches);

typedef void __fastcall (__closure *TgxHeightDataPostRenderEvent)(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Classes::TList* &HeightDatas);

typedef void __fastcall (__closure *TMaxCLODTrianglesReachedEvent)(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);

enum DECLSPEC_DENUM TgxTerrainHighResStyle : unsigned char { hrsFullGeometry, hrsTesselated };

enum DECLSPEC_DENUM TgxTerrainOcclusionTesselate : unsigned char { totTesselateAlways, totTesselateIfVisible };

enum DECLSPEC_DENUM TgxTileManagementFlag : unsigned char { tmClearUsedFlags, tmMarkUsedTiles, tmReleaseUnusedTiles, tmAllocateNewTiles, tmWaitForPreparing };

typedef System::Set<TgxTileManagementFlag, TgxTileManagementFlag::tmClearUsedFlags, TgxTileManagementFlag::tmWaitForPreparing> TgxTileManagementFlags;

class PASCALIMPLEMENTATION TgxTerrainRenderer : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	Gxs::Heightdata::TgxHeightDataSource* FHeightDataSource;
	int FTileSize;
	float FQualityDistance;
	float FinvTileSize;
	int FLastTriangleCount;
	float FTilesPerTexture;
	int FMaxCLODTriangles;
	int FCLODPrecision;
	Gxs::Vectorlists::TgxAffineVectorList* FBufferVertices;
	Gxs::Vectorlists::TgxTexPointList* FBufferTexPoints;
	Gxs::Vectorlists::TgxIntegerList* FBufferVertexIndices;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	TGetTerrainBoundsEvent FOnGetTerrainBounds;
	TPatchPostRenderEvent FOnPatchPostRender;
	TgxHeightDataPostRenderEvent FOnHeightDataPostRender;
	TMaxCLODTrianglesReachedEvent FOnMaxCLODTrianglesReached;
	TgxTerrainHighResStyle FQualityStyle;
	int FOcclusionFrameSkip;
	TgxTerrainOcclusionTesselate FOcclusionTesselate;
	int FContourInterval;
	int FContourWidth;
	
protected:
	System::StaticArray<System::Classes::TList*, 256> FTilesHash;
	void __fastcall MarkAllTilesAsUnused();
	void __fastcall ReleaseAllUnusedTiles();
	void __fastcall MarkHashedTileAsUsed(const Stage::Vectorgeometry::TAffineVector &tilePos);
	Gxs::Heightdata::TgxHeightData* __fastcall HashedTile(const Stage::Vectorgeometry::TAffineVector &tilePos, bool canAllocate = true)/* overload */;
	Gxs::Heightdata::TgxHeightData* __fastcall HashedTile(const int xLeft, const int yTop, bool canAllocate = true)/* overload */;
	void __fastcall SetHeightDataSource(Gxs::Heightdata::TgxHeightDataSource* const val);
	void __fastcall SetTileSize(const int val);
	void __fastcall SetTilesPerTexture(const float val);
	void __fastcall SetCLODPrecision(const int val);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetQualityStyle(const TgxTerrainHighResStyle val);
	void __fastcall SetOcclusionFrameSkip(int val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DestroyHandle();
	virtual void __fastcall ReleaseAllTiles();
	virtual void __fastcall OnTileDestroyed(System::TObject* Sender);
	Gxs::Roampatch::TgxROAMPatch* __fastcall GetPreparedPatch(const Stage::Vectorgeometry::TAffineVector &tilePos, const Stage::Vectorgeometry::TAffineVector &EyePos, float TexFactor, System::Classes::TList* HDList);
	
public:
	TgxTileManagementFlags TileManagement;
	__fastcall virtual TgxTerrainRenderer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTerrainRenderer();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual float __fastcall InterpolatedHeight(const Stage::Vectortypes::TVector4f &p)/* overload */;
	float __fastcall InterpolatedHeight(const Stage::Vectorgeometry::TAffineVector &p)/* overload */;
	__property int LastTriangleCount = {read=FLastTriangleCount, nodefault};
	int __fastcall HashedTileCount();
	
__published:
	__property Gxs::Heightdata::TgxHeightDataSource* HeightDataSource = {read=FHeightDataSource, write=SetHeightDataSource};
	__property int TileSize = {read=FTileSize, write=SetTileSize, default=16};
	__property float TilesPerTexture = {read=FTilesPerTexture, write=SetTilesPerTexture};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property float QualityDistance = {read=FQualityDistance, write=FQualityDistance};
	__property TgxTerrainHighResStyle QualityStyle = {read=FQualityStyle, write=SetQualityStyle, default=0};
	__property int MaxCLODTriangles = {read=FMaxCLODTriangles, write=FMaxCLODTriangles, default=65536};
	__property int CLODPrecision = {read=FCLODPrecision, write=SetCLODPrecision, default=100};
	__property int OcclusionFrameSkip = {read=FOcclusionFrameSkip, write=SetOcclusionFrameSkip, default=0};
	__property TgxTerrainOcclusionTesselate OcclusionTesselate = {read=FOcclusionTesselate, write=FOcclusionTesselate, default=1};
	__property TGetTerrainBoundsEvent OnGetTerrainBounds = {read=FOnGetTerrainBounds, write=FOnGetTerrainBounds};
	__property TPatchPostRenderEvent OnPatchPostRender = {read=FOnPatchPostRender, write=FOnPatchPostRender};
	__property TgxHeightDataPostRenderEvent OnHeightDataPostRender = {read=FOnHeightDataPostRender, write=FOnHeightDataPostRender};
	__property TMaxCLODTrianglesReachedEvent OnMaxCLODTrianglesReached = {read=FOnMaxCLODTrianglesReached, write=FOnMaxCLODTrianglesReached};
	__property int ContourInterval = {read=FContourInterval, write=FContourInterval, default=0};
	__property int ContourWidth = {read=FContourWidth, write=FContourWidth, default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTerrainRenderer(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte cTilesHashSize = System::Byte(0xff);
}	/* namespace Terrainrenderer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TERRAINRENDERER)
using namespace Gxs::Terrainrenderer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TerrainRendererHPP
