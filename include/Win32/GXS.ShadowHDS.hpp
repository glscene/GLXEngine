// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ShadowHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_ShadowHDSHPP
#define GXS_ShadowHDSHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Material.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Shadowhds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxShadowHDS;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TNewTilePreparedEvent)(TgxShadowHDS* Sender, Gxs::Heightdata::TgxHeightData* HeightData, Gxs::Material::TgxLibMaterial* ShadowMapMaterial);

typedef void __fastcall (__closure *TThreadBmp32)(TgxShadowHDS* Sender, Gxs::Heightdata::TgxHeightData* HeightData, Gxs::Graphics::TgxBitmap32* bmp32);

class PASCALIMPLEMENTATION TgxShadowHDS : public Gxs::Heightdata::TgxHeightDataSourceFilter
{
	typedef Gxs::Heightdata::TgxHeightDataSourceFilter inherited;
	
private:
	int FTileSize;
	Gxs::Material::TgxMaterialLibrary* FShadowmapLibrary;
	Gxs::Coordinates::TgxCoordinates* FLightVector;
	Gxs::Coordinates::TgxCoordinates* FScale;
	Stage::Vectortypes::TVector3f FScaleVec;
	TNewTilePreparedEvent FOnNewTilePrepared;
	TThreadBmp32 FOnThreadBmp32;
	int FMaxTextures;
	Stage::Vectortypes::TVector3f Step;
	int FScanDistance;
	unsigned FSoftRange;
	float FDiffuse;
	float FAmbient;
	Gxs::Heightdata::TgxHeightDataSource* OwnerHDS;
	
protected:
	void __fastcall SetShadowmapLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetScale(Gxs::Coordinates::TgxCoordinates* AValue);
	void __fastcall SetLightVector(Gxs::Coordinates::TgxCoordinates* AValue);
	void __fastcall SetSoftRange(unsigned AValue);
	void __fastcall SetDiffuse(float AValue);
	void __fastcall SetAmbient(float AValue);
	void __fastcall Trim(int MaxTextureCount);
	Gxs::Material::TgxLibMaterial* __fastcall FindUnusedMaterial();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcStep();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcScale();
	int __fastcall WrapDist(float Lx, float Ly);
	void __fastcall LocalToWorld(float Lx, float Ly, Gxs::Heightdata::TgxHeightData* HD, float &Wx, float &Wy);
	void __fastcall WorldToLocal(float Wx, float Wy, Gxs::Heightdata::TgxHeightData* &HD, float &Lx, float &Ly);
	
public:
	bool SkipGenerate;
	__fastcall virtual TgxShadowHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxShadowHDS();
	void __fastcall TrimTextureCache(int MaxTextureCount = 0x0);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall BeforePreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual void __fastcall PreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual void __fastcall AfterPreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	void __fastcall GenerateShadowMap(Gxs::Heightdata::TgxHeightData* HeightData, Gxs::Graphics::TgxBitmap32* ShadowMap, float scale);
	float __fastcall RayCastShadowHeight(Gxs::Heightdata::TgxHeightData* HD, float localX, float localY)/* overload */;
	void __fastcall RayCastLine(Gxs::Heightdata::TgxHeightData* HeightData, float Lx, float Ly, Gxs::Graphics::TgxBitmap32* ShadowMap);
	System::Byte __fastcall Shade(Gxs::Heightdata::TgxHeightData* HeightData, int x, int y, float ShadowHeight, float TerrainHeight);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* ShadowmapLibrary = {read=FShadowmapLibrary, write=SetShadowmapLibrary};
	__property TThreadBmp32 OnThreadBmp32 = {read=FOnThreadBmp32, write=FOnThreadBmp32};
	__property TNewTilePreparedEvent OnNewTilePrepared = {read=FOnNewTilePrepared, write=FOnNewTilePrepared};
	__property Gxs::Coordinates::TgxCoordinates* LightVector = {read=FLightVector, write=SetLightVector};
	__property Gxs::Coordinates::TgxCoordinates* scale = {read=FScale, write=FScale};
	__property int ScanDistance = {read=FScanDistance, write=FScanDistance, nodefault};
	__property unsigned SoftRange = {read=FSoftRange, write=SetSoftRange, nodefault};
	__property float Diffuse = {read=FDiffuse, write=SetDiffuse};
	__property float Ambient = {read=FAmbient, write=SetAmbient};
	__property int MaxTextures = {read=FMaxTextures, write=FMaxTextures, nodefault};
	__property OnSourceDataFetched;
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shadowhds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SHADOWHDS)
using namespace Gxs::Shadowhds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ShadowHDSHPP
