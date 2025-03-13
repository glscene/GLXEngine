// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.RandomHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_RandomHDSHPP
#define GXS_RandomHDSHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <System.SysUtils.hpp>
#include <System.UITypes.hpp>
#include <System.UIConsts.hpp>
#include <System.Contnrs.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Forms.hpp>
#include <Stage.OpenGL4.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.TerrainRenderer.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Randomhds
{
//-- forward type declarations -----------------------------------------------
struct TSeaErosion;
struct TRainErosion;
struct TLifeErosion;
struct TFractionErosion;
struct TLandTileInfo;
struct TSteps;
class DELPHICLASS TgxBaseRandomHDS;
class DELPHICLASS TgxCustomRandomHDS;
class DELPHICLASS TgxFractalHDS;
struct TRelativeCoordinate;
class DELPHICLASS TgxTiledRndLandscape;
class DELPHICLASS TgxFractalArchipelago;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TSeaErosion
{
public:
	bool Enabled;
	float BeachHeight;
};


struct DECLSPEC_DRECORD TRainErosion
{
public:
	bool Enabled;
	float ErosionRate;
	float DepositRate;
};


struct DECLSPEC_DRECORD TLifeErosion
{
public:
	bool Enabled;
	float Robustness;
};


struct DECLSPEC_DRECORD TFractionErosion
{
public:
	bool Enabled;
	float Slope;
};


struct DECLSPEC_DRECORD TLandTileInfo
{
public:
	int x;
	int z;
	Gxs::Heightdata::TgxHeightDataState State;
};


struct DECLSPEC_DRECORD TSteps
{
public:
	bool Enabled;
	int Count;
};


typedef System::DynamicArray<float> Gxs_Randomhds__1;

typedef System::DynamicArray<System::DynamicArray<float> > TMapOfSingle;

typedef System::DynamicArray<Stage::Vectortypes::TVector4f> Gxs_Randomhds__2;

typedef System::DynamicArray<System::DynamicArray<Stage::Vectortypes::TVector4f> > TMapOfVector;

typedef Gxs::Color::TgxColorVector __fastcall (__closure *TOnDrawTexture)(TgxBaseRandomHDS* const Sender, int x, int y, double z, const Stage::Vectortypes::TVector4f &Normal);

typedef void __fastcall (__closure *TSingleClamp)(float &x, float &y);

typedef void __fastcall (__closure *TIntegerClamp)(int &x, int &y);

class PASCALIMPLEMENTATION TgxBaseRandomHDS : public Gxs::Heightdata::TgxHeightDataSource
{
	typedef Gxs::Heightdata::TgxHeightDataSource inherited;
	
private:
	TSteps FSteps;
	bool FLandCover;
	void __fastcall SetOnDrawTexture(const TOnDrawTexture Value);
	void __fastcall SetSteps(const TSteps &Value);
	void __fastcall SetLandCover(const bool Value);
	
protected:
	int FSeed;
	int FSize;
	System::UnicodeString FMaterialName;
	bool FLighting;
	Stage::Vectortypes::TVector4f FLightDirection;
	Gxs::Terrainrenderer::TgxTerrainRenderer* FTerrainRenderer;
	Gxs::Color::TgxColorVector FLightColor;
	bool FShadows;
	bool FSea;
	float FSeaLevel;
	float FAmbientLight;
	int FTaskProgress;
	int FTextureScale;
	TFractionErosion FErosionByFraction;
	bool FLightSmoothing;
	bool FCyclic;
	float FSeaTransparency;
	bool FPrimerLandscape;
	TLandTileInfo FLandTileInfo;
	TOnDrawTexture FOnDrawTexture;
	Gxs::Color::TgxColorVector __fastcall OnDrawTextureDefault(TgxBaseRandomHDS* const Sender, int x, int y, double z, const Stage::Vectortypes::TVector4f &Normal);
	void __fastcall SetSeed(const int Value);
	void __fastcall SetMaterialName(const System::UnicodeString Value);
	void __fastcall SetLighting(const bool Value);
	void __fastcall SetLightDirection(const Stage::Vectortypes::TVector4f &Value);
	virtual void __fastcall SetTerrainRenderer(Gxs::Terrainrenderer::TgxTerrainRenderer* const Value) = 0 ;
	void __fastcall SetLightColor(const Gxs::Color::TgxColorVector &Value);
	void __fastcall SetShadows(const bool Value);
	void __fastcall SetSea(const bool Value);
	void __fastcall SetSeaLevel(const float Value);
	void __fastcall SetAmbientLight(const float Value);
	void __fastcall SetErosionByRain(const TRainErosion &Value);
	TRainErosion __fastcall GetErosionByRain();
	void __fastcall SetErosionBySea(const TSeaErosion &Value);
	void __fastcall SetTextureScale(const int Value);
	void __fastcall SetErosionByLife(const TLifeErosion &Value);
	void __fastcall SetErosionByFraction(const TFractionErosion &Value);
	void __fastcall SetLightSmoothing(const bool Value);
	void __fastcall SetSeaTransparency(const float Value);
	void __fastcall SetPrimerLandscape(const bool Value);
	float __fastcall GetSeaLevel();
	float __fastcall GetSeaTransparency();
	void __fastcall SetLandTileInfo(const TLandTileInfo &Value);
	TLandTileInfo __fastcall GetLandTileInfo();
	virtual void __fastcall SetCyclic(const bool Value) = 0 ;
	
public:
	TRainErosion FErosionByRain;
	TSeaErosion FErosionBySea;
	TLifeErosion FErosionByLife;
	__fastcall virtual TgxBaseRandomHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBaseRandomHDS();
	__property Gxs::Color::TgxColorVector LightColor = {read=FLightColor, write=SetLightColor};
	__property Stage::Vectortypes::TVector4f LightDirection = {read=FLightDirection, write=SetLightDirection};
	__property TOnDrawTexture OnDrawTexture = {read=FOnDrawTexture, write=SetOnDrawTexture};
	
__published:
	__property float AmbientLight = {read=FAmbientLight, write=SetAmbientLight};
	__property bool Cyclic = {read=FCyclic, write=SetCyclic, nodefault};
	
public:
	__property TFractionErosion ErosionByFraction = {read=FErosionByFraction, write=SetErosionByFraction};
	__property TLifeErosion ErosionByLife = {read=FErosionByLife, write=SetErosionByLife};
	__property TRainErosion ErosionByRain = {read=FErosionByRain, write=SetErosionByRain};
	__property TSeaErosion ErosionBySea = {read=FErosionBySea, write=SetErosionBySea};
	
__published:
	__property bool LandCover = {read=FLandCover, write=SetLandCover, nodefault};
	__property bool Lighting = {read=FLighting, write=SetLighting, nodefault};
	__property bool LightSmoothing = {read=FLightSmoothing, write=SetLightSmoothing, nodefault};
	__property System::UnicodeString MaterialName = {read=FMaterialName, write=SetMaterialName};
	__property bool PrimerLandscape = {read=FPrimerLandscape, write=SetPrimerLandscape, nodefault};
	__property bool Sea = {read=FSea, write=SetSea, nodefault};
	__property float SeaLevel = {read=GetSeaLevel, write=SetSeaLevel};
	__property float SeaTransparency = {read=GetSeaTransparency, write=SetSeaTransparency};
	__property int Seed = {read=FSeed, write=SetSeed, nodefault};
	__property bool Shadows = {read=FShadows, write=SetShadows, nodefault};
	
public:
	__property TSteps Steps = {read=FSteps, write=SetSteps};
	
__published:
	__property Gxs::Terrainrenderer::TgxTerrainRenderer* TerrainRenderer = {read=FTerrainRenderer, write=SetTerrainRenderer};
	__property int TextureScale = {read=FTextureScale, write=SetTextureScale, nodefault};
};


class PASCALIMPLEMENTATION TgxCustomRandomHDS : public TgxBaseRandomHDS
{
	typedef TgxBaseRandomHDS inherited;
	
private:
	bool FSlave;
	float FMaxHeight;
	float FMinHeight;
	float FRangeHeight;
	System::UnicodeString FTask;
	TSingleClamp FSingleConstrain;
	TIntegerClamp FIntegerConstrain;
	bool FKeepNormals;
	float __fastcall GetHeight(int x, int y);
	void __fastcall SetHeight(int x, int y, const float Value);
	void __fastcall SetKeepNormals(const bool Value);
	
protected:
	virtual void __fastcall SetTerrainRenderer(Gxs::Terrainrenderer::TgxTerrainRenderer* const Value);
	virtual void __fastcall SetCyclic(const bool Value);
	void __fastcall BoundaryClamp(float &x, float &y)/* overload */;
	void __fastcall BoundaryClamp(int &x, int &y)/* overload */;
	void __fastcall CyclicClamp(float &x, float &y)/* overload */;
	void __fastcall CyclicClamp(int &x, int &y)/* overload */;
	void __fastcall GetTerrainBounds(float &l, float &t, float &r, float &b);
	void __fastcall SetSize(const int aSize);
	
public:
	TMapOfSingle FHeight;
	TMapOfSingle FLightMap;
	TMapOfVector FNormal;
	int __fastcall BoundaryX();
	int __fastcall BoundaryZ();
	virtual void __fastcall BuildHeightField() = 0 /* overload */;
	void __fastcall BuildLandscape();
	void __fastcall BuildLightMap()/* overload */;
	void __fastcall BuildLightMap(const Stage::Vectortypes::TVector4f &aLightDirection)/* overload */;
	void __fastcall BuildNormals();
	void __fastcall BuildTexture();
	void __fastcall ClearHeightField();
	void __fastcall ClearLightMap();
	void __fastcall ConstrainCoordinates(float &x, float &y)/* overload */;
	void __fastcall ConstrainCoordinates(int &x, int &y)/* overload */;
	__fastcall virtual TgxCustomRandomHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomRandomHDS();
	void __fastcall DoCyclicBoundaries();
	void __fastcall DoErosionByFraction();
	void __fastcall DoErosionByLife();
	void __fastcall DoErosionByRain();
	void __fastcall DoErosionBySea();
	void __fastcall DoSea();
	void __fastcall DoSteps();
	__property float Heights[int x][int y] = {read=GetHeight, write=SetHeight};
	float __fastcall Interpolate(float x, float y);
	__property bool KeepNormals = {read=FKeepNormals, write=SetKeepNormals, nodefault};
	__property TLandTileInfo LandTileInfo = {read=GetLandTileInfo, write=SetLandTileInfo};
	bool __fastcall PointInMap(const float x, const float y)/* overload */;
	bool __fastcall PointInMap(const int x, const int y)/* overload */;
	__property float MaxHeight = {read=FMaxHeight};
	__property float MinHeight = {read=FMinHeight};
	Stage::Vectortypes::TVector4f __fastcall Normal(const Stage::Vectortypes::TVector4f &Position);
	__property float RangeHeight = {read=FRangeHeight};
	Gxs::Coordinates::TgxCoordinates* __fastcall Scale();
	__property int Size = {read=FSize, nodefault};
	float __fastcall StandardisedHeight(const int x, const int y);
	__property System::UnicodeString Task = {read=FTask};
	__property int TaskProgress = {read=FTaskProgress, nodefault};
	float __fastcall XMoveBoundary();
	float __fastcall ZMoveBoundary();
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* heightData);
	
__published:
	__property bool Cyclic = {read=FCyclic, write=SetCyclic, nodefault};
};


class PASCALIMPLEMENTATION TgxFractalHDS : public TgxCustomRandomHDS
{
	typedef TgxCustomRandomHDS inherited;
	
private:
	int FAmplitude;
	int FDepth;
	float FRoughness;
	void __fastcall SetAmplitude(const int Value);
	void __fastcall SetDepth(const int Value);
	void __fastcall SetRoughness(const float Value);
	
public:
	virtual void __fastcall BuildHeightField()/* overload */;
	HIDESBASE void __fastcall BuildHeightField(const int aDepth, const int aSeed, const int aAmplitude)/* overload */;
	__fastcall virtual TgxFractalHDS(System::Classes::TComponent* AOwner);
	
__published:
	__property int Amplitude = {read=FAmplitude, write=SetAmplitude, nodefault};
	__property int Depth = {read=FDepth, write=SetDepth, nodefault};
	__property float Roughness = {read=FRoughness, write=SetRoughness};
public:
	/* TgxCustomRandomHDS.Destroy */ inline __fastcall virtual ~TgxFractalHDS() { }
	
};


typedef TgxCustomRandomHDS TLandTile;

struct DECLSPEC_DRECORD TRelativeCoordinate
{
public:
	int DX;
	int DZ;
};


typedef void __fastcall (__closure *TOnCreateLandTile)(int x, int z, int Seed, TLandTile* &aLandscape);

typedef bool __fastcall (__closure *TIsDefaultTile)(int x, int z);

class PASCALIMPLEMENTATION TgxTiledRndLandscape : public TgxBaseRandomHDS
{
	typedef TgxBaseRandomHDS inherited;
	
	
private:
	typedef System::DynamicArray<TRelativeCoordinate> _TgxTiledRndLandscape__1;
	
	
private:
	bool FLandTileComputing;
	int FExtentX;
	int FExtentZ;
	int FExtentXhalf;
	int FExtentZhalf;
	int fLandTileSize;
	TSingleClamp FSingleConstrain;
	TIntegerClamp FIntegerConstrain;
	Gxs::Terrainrenderer::TgxTerrainRenderer* FTerrainRenderer;
	Gxs::Scene::TgxCamera* FCamera;
	TOnCreateLandTile fOnCreateLandTile;
	Gxs::Heightdata::TStartPreparingDataEvent fOnCreateDefaultTile;
	TIsDefaultTile FIsDefaultTile;
	int FSeed;
	int fBaseSeed;
	TLandTile* fComputedLandTile;
	int FLandTileCapacity;
	int FGenerationRadius;
	float FLandTileDensity;
	void __fastcall fDefaultOnCreateDefaultTile(Gxs::Heightdata::TgxHeightData* HeightData);
	bool __fastcall fDefaultIsDefaultTile(int x, int z);
	void __fastcall SetExtentX(const int Value);
	void __fastcall SetExtentZ(const int Value);
	void __fastcall SetOnCreateLandTile(const TOnCreateLandTile Value);
	void __fastcall SetCamera(Gxs::Scene::TgxCamera* const Value);
	void __fastcall SetIsDefaultTile(const TIsDefaultTile Value);
	HIDESBASE void __fastcall SetSeed(const int Value);
	void __fastcall SetOnCreateDefaultTile(const Gxs::Heightdata::TStartPreparingDataEvent Value);
	System::UnicodeString __fastcall GetTask();
	int __fastcall GetTaskProgress();
	void __fastcall SetLandTileCapacity(const int Value);
	void __fastcall SetGenerationRadius(const int Value);
	void __fastcall SetLandTileDensity(const float Value);
	
protected:
	_TgxTiledRndLandscape__1 FGenRadius;
	int FOldCamX;
	int FOldCamZ;
	bool FMapUpdating;
	System::Contnrs::TComponentList* FLandTiles;
	void __fastcall BoundaryClamp(float &x, float &z)/* overload */;
	void __fastcall BoundaryClamp(int &x, int &z)/* overload */;
	virtual void __fastcall ComputeLandTile(const int aX, const int aZ, TLandTile* &NewLandTile);
	void __fastcall CyclicClamp(float &x, float &z)/* overload */;
	void __fastcall CyclicClamp(int &x, int &z)/* overload */;
	void __fastcall GetTerrainBounds(float &l, float &t, float &r, float &b);
	int __fastcall LandTileSeed(int x, int z);
	__property Gxs::Heightdata::TStartPreparingDataEvent OnCreateDefaultTile = {read=fOnCreateDefaultTile, write=SetOnCreateDefaultTile};
	virtual void __fastcall SetCyclic(const bool Value);
	void __fastcall SetSize(const int aSize);
	int __fastcall fSortLandscapes(void * Item1, void * Item2);
	virtual void __fastcall SetTerrainRenderer(Gxs::Terrainrenderer::TgxTerrainRenderer* const Value);
	
public:
	void __fastcall ApplyLighting(TLandTile* &aLandTile);
	void __fastcall ApplyTexture(TLandTile* &aLandTile);
	void __fastcall ApplyTopography(TLandTile* &aLandTile);
	void __fastcall CameraPosition(int &TileX, int &TileZ);
	HIDESBASE void __fastcall CleanUp();
	void __fastcall ConstrainCoordinates(float &x, float &z)/* overload */;
	void __fastcall ConstrainCoordinates(int &x, int &z)/* overload */;
	__fastcall virtual TgxTiledRndLandscape(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTiledRndLandscape();
	void __fastcall FindLandTile(const float x, const float z, int &TileX, int &TileZ);
	virtual void __fastcall Initialize(const float aX, const float aZ);
	__property TIsDefaultTile IsDefaultTile = {read=FIsDefaultTile, write=SetIsDefaultTile};
	int __fastcall LandtileCount();
	__property int LandTileSize = {read=fLandTileSize, nodefault};
	__property TOnCreateLandTile OnCreateLandTile = {read=fOnCreateLandTile, write=SetOnCreateLandTile};
	__property System::UnicodeString Task = {read=GetTask};
	__property int TaskProgress = {read=GetTaskProgress, nodefault};
	float __fastcall TileDistance(const int x1, const int z1, const int x2, const int z2);
	int __fastcall TileDistanceSquared(const int x1, const int z1, const int x2, const int z2);
	void __fastcall Update();
	__property bool MapUpdating = {read=FMapUpdating, nodefault};
	float __fastcall XMoveBoundary();
	float __fastcall ZMoveBoundary();
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	
__published:
	__property Gxs::Scene::TgxCamera* Camera = {read=FCamera, write=SetCamera};
	__property bool Cyclic = {read=FCyclic, write=SetCyclic, nodefault};
	__property int ExtentX = {read=FExtentX, write=SetExtentX, nodefault};
	__property int ExtentZ = {read=FExtentZ, write=SetExtentZ, nodefault};
	__property int GenerationRadius = {read=FGenerationRadius, write=SetGenerationRadius, nodefault};
	__property int LandTileCapacity = {read=FLandTileCapacity, write=SetLandTileCapacity, nodefault};
	__property float LandTileDensity = {read=FLandTileDensity, write=SetLandTileDensity};
	__property int Seed = {read=FSeed, write=SetSeed, nodefault};
	__property Gxs::Terrainrenderer::TgxTerrainRenderer* TerrainRenderer = {read=FTerrainRenderer, write=SetTerrainRenderer};
};


class PASCALIMPLEMENTATION TgxFractalArchipelago : public TgxTiledRndLandscape
{
	typedef TgxTiledRndLandscape inherited;
	
private:
	int FDepth;
	float FRoughnessMax;
	float FRoughnessMin;
	int FAmplitudeMin;
	int FAmplitudeMax;
	bool FSeaDynamic;
	System::UnicodeString FSeaMaterialName;
	float FWaveAmplitude;
	float FWaveSpeed;
	float __fastcall GetIslandDensity();
	void __fastcall FPostRenderSeaStatic(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Classes::TList* &HeightDatas);
	void __fastcall FPostRenderSeaDynamic(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Classes::TList* &HeightDatas);
	void __fastcall SetIslandDensity(const float Value);
	void __fastcall SetDepth(const int Value);
	void __fastcall SetRoughnessMax(const float Value);
	void __fastcall SetRoughnessMin(const float Value);
	void __fastcall SetAmplitudeMax(const int Value);
	void __fastcall SetAmplitudeMin(const int Value);
	void __fastcall SetSeaDynamic(const bool Value);
	void __fastcall SetSeaMaterialName(const System::UnicodeString Value);
	void __fastcall SetWaveAmplitude(const float Value);
	void __fastcall SetWaveSpeed(const float Value);
	
protected:
	virtual void __fastcall SetTerrainRenderer(Gxs::Terrainrenderer::TgxTerrainRenderer* const Value);
	HIDESBASE void __fastcall fOnCreateLandTile(int aX, int aZ, int aSeed, TLandTile* &aLandscape);
	HIDESBASE void __fastcall fOnCreateDefaultTile(Gxs::Heightdata::TgxHeightData* heightData);
	
public:
	virtual void __fastcall ComputeLandTile(const int aX, const int aZ, TLandTile* &NewLandTile);
	__fastcall virtual TgxFractalArchipelago(System::Classes::TComponent* AOwner);
	
__published:
	__property int AmplitudeMax = {read=FAmplitudeMax, write=SetAmplitudeMax, nodefault};
	__property int AmplitudeMin = {read=FAmplitudeMin, write=SetAmplitudeMin, nodefault};
	__property int Depth = {read=FDepth, write=SetDepth, nodefault};
	__property float IslandDensity = {read=GetIslandDensity, write=SetIslandDensity};
	__property float RoughnessMax = {read=FRoughnessMax, write=SetRoughnessMax};
	__property float RoughnessMin = {read=FRoughnessMin, write=SetRoughnessMin};
	__property bool SeaDynamic = {read=FSeaDynamic, write=SetSeaDynamic, nodefault};
	__property System::UnicodeString SeaMaterialName = {read=FSeaMaterialName, write=SetSeaMaterialName};
	__property float WaveAmplitude = {read=FWaveAmplitude, write=SetWaveAmplitude};
	__property float WaveSpeed = {read=FWaveSpeed, write=SetWaveSpeed};
public:
	/* TgxTiledRndLandscape.Destroy */ inline __fastcall virtual ~TgxFractalArchipelago() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte VerticalScalingFactor = System::Byte(0x80);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall NoisyColor(const System::Uitypes::TColor Color, const float Noise = 5.000000E-02f);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureSand(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureBrownSoil(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureDarkGreen(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureDarkGray(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureWhite(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureBlue(const int x, const int y);
extern DELPHI_PACKAGE Gxs::Color::TgxColorVector __fastcall TextureGreen(const int x, const int y);
extern DELPHI_PACKAGE void __fastcall InitializeRandomGenerator(const int Seed);
extern DELPHI_PACKAGE void __fastcall FractalMiddlePointHDS(const int aDepth, const int aSeed, const int aAmplitude, const float aRoughness, bool aCyclic, TMapOfSingle &z, float &MinZ, float &MaxZ);
extern DELPHI_PACKAGE void __fastcall PrimerNull(TMapOfSingle &z);
extern DELPHI_PACKAGE void __fastcall PrimerIsland(float LowZ, float HighZ, TMapOfSingle &z);
}	/* namespace Randomhds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_RANDOMHDS)
using namespace Gxs::Randomhds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_RandomHDSHPP
