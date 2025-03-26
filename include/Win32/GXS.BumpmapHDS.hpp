// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.BumpmapHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_BumpmapHDSHPP
#define GXS_BumpmapHDSHPP

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
#include <System.SyncObjs.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Bumpmaphds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBumpmapHDS;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TNewTilePreparedEvent)(TgxBumpmapHDS* Sender, Gxs::Heightdata::TgxHeightData* heightData, Gxs::Material::TgxLibMaterial* normalMapMaterial);

class PASCALIMPLEMENTATION TgxBumpmapHDS : public Gxs::Heightdata::TgxHeightDataSourceFilter
{
	typedef Gxs::Heightdata::TgxHeightDataSourceFilter inherited;
	
private:
	Gxs::Material::TgxMaterialLibrary* FBumpmapLibrary;
	TNewTilePreparedEvent FOnNewTilePrepared;
	float FBumpScale;
	int FSubSampling;
	int FMaxTextures;
	System::Syncobjs::TCriticalSection* Uno;
	
protected:
	void __fastcall SetBumpmapLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetBumpScale(const float val);
	bool __fastcall StoreBumpScale();
	void __fastcall SetSubSampling(const int val);
	void __fastcall Trim(int MaxTextureCount);
	
public:
	__fastcall virtual TgxBumpmapHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBumpmapHDS();
	virtual void __fastcall Release(Gxs::Heightdata::TgxHeightData* aHeightData);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall GenerateNormalMap(Gxs::Heightdata::TgxHeightData* heightData, Gxs::Graphics::TgxBitmap32* normalMap, float scale);
	void __fastcall TrimTextureCache(int MaxTextureCount);
	virtual void __fastcall PreparingData(Gxs::Heightdata::TgxHeightData* heightData);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* BumpmapLibrary = {read=FBumpmapLibrary, write=SetBumpmapLibrary};
	__property TNewTilePreparedEvent OnNewTilePrepared = {read=FOnNewTilePrepared, write=FOnNewTilePrepared};
	__property float BumpScale = {read=FBumpScale, write=SetBumpScale, stored=StoreBumpScale};
	__property int SubSampling = {read=FSubSampling, write=SetSubSampling, default=1};
	__property MaxPoolSize;
	__property int MaxTextures = {read=FMaxTextures, write=FMaxTextures, nodefault};
	__property OnSourceDataFetched;
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Bumpmaphds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BUMPMAPHDS)
using namespace Gxs::Bumpmaphds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BumpmapHDSHPP
