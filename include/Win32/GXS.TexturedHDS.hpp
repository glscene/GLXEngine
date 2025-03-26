// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TexturedHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_TexturedHDSHPP
#define GXS_TexturedHDSHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.Material.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Texturedhds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTexturedHDS;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxTexturedHDS : public Gxs::Heightdata::TgxHeightDataSource
{
	typedef Gxs::Heightdata::TgxHeightDataSource inherited;
	
private:
	Gxs::Heightdata::TStartPreparingDataEvent FOnStartPreparingData;
	Gxs::Heightdata::TMarkDirtyEvent FOnMarkDirty;
	Gxs::Heightdata::TgxHeightDataSource* FHeightDataSource;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	bool FWholeTilesOnly;
	int FTileSize;
	int FTilesPerTexture;
	
protected:
	void __fastcall SetHeightDataSource(Gxs::Heightdata::TgxHeightDataSource* val);
	
public:
	__fastcall virtual TgxTexturedHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTexturedHDS();
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual void __fastcall MarkDirty(const System::Types::TRect &area)/* overload */;
	
__published:
	__property MaxPoolSize;
	__property Gxs::Heightdata::TStartPreparingDataEvent OnStartPreparingData = {read=FOnStartPreparingData, write=FOnStartPreparingData};
	__property Gxs::Heightdata::TMarkDirtyEvent OnMarkDirtyEvent = {read=FOnMarkDirty, write=FOnMarkDirty};
	__property Gxs::Heightdata::TgxHeightDataSource* HeightDataSource = {read=FHeightDataSource, write=SetHeightDataSource};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=FMaterialLibrary};
	__property bool WholeTilesOnly = {read=FWholeTilesOnly, write=FWholeTilesOnly, nodefault};
	__property int TileSize = {read=FTileSize, write=FTileSize, nodefault};
	__property int TilesPerTexture = {read=FTilesPerTexture, write=FTilesPerTexture, nodefault};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  MarkDirty(int XLeft, int YTop, int xRight, int yBottom){ Gxs::Heightdata::TgxHeightDataSource::MarkDirty(XLeft, YTop, xRight, yBottom); }
	inline void __fastcall  MarkDirty(){ Gxs::Heightdata::TgxHeightDataSource::MarkDirty(); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Texturedhds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TEXTUREDHDS)
using namespace Gxs::Texturedhds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TexturedHDSHPP
