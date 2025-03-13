// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TilePlane.pas' rev: 36.00 (Windows)

#ifndef GXS_TilePlaneHPP
#define GXS_TilePlaneHPP

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
#include <GXS.XOpenGL.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>
#include <GXS.Objects.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Tileplane
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTiledAreaRow;
class DELPHICLASS TgxTiledArea;
class DELPHICLASS TgxTilePlane;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTiledAreaRow : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
public:
	int operator[](int col) { return this->Cell[col]; }
	
private:
	int FColMin;
	int FColMax;
	Gxs::Vectorlists::TgxIntegerList* FData;
	
protected:
	void __fastcall SetColMin(const int val);
	void __fastcall SetColMax(const int val);
	int __fastcall GetCell(int col);
	void __fastcall SetCell(int col, int val);
	
public:
	__fastcall virtual TgxTiledAreaRow();
	__fastcall virtual ~TgxTiledAreaRow();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property int Cell[int col] = {read=GetCell, write=SetCell/*, default*/};
	__property int ColMin = {read=FColMin, write=SetColMin, nodefault};
	__property int ColMax = {read=FColMax, write=SetColMax, nodefault};
	__property Gxs::Vectorlists::TgxIntegerList* Data = {read=FData};
	void __fastcall Pack();
	bool __fastcall Empty();
	void __fastcall RemapTiles(Gxs::Vectorlists::TgxIntegerList* remapList);
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxTiledAreaRow(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTiledArea : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	int FRowMin;
	int FRowMax;
	Gxs::Persistentclasses::TgxPersistentObjectList* FRows;
	
protected:
	void __fastcall SetRowMin(const int val);
	void __fastcall SetRowMax(const int val);
	int __fastcall GetTile(int col, int row);
	void __fastcall SetTile(int col, int row, int val);
	TgxTiledAreaRow* __fastcall GetRow(int index);
	
public:
	__fastcall virtual TgxTiledArea();
	__fastcall virtual ~TgxTiledArea();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property int Tile[int col][int row] = {read=GetTile, write=SetTile/*, default*/};
	__property TgxTiledAreaRow* row[int index] = {read=GetRow};
	__property int RowMin = {read=FRowMin, write=SetRowMin, nodefault};
	__property int RowMax = {read=FRowMax, write=SetRowMax, nodefault};
	void __fastcall Pack();
	void __fastcall Clear();
	bool __fastcall Empty();
	void __fastcall RemapTiles(Gxs::Vectorlists::TgxIntegerList* remapList);
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxTiledArea(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxTilePlane : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	bool FNoZWrite;
	TgxTiledArea* FTiles;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	bool FSortByMaterials;
	
protected:
	void __fastcall SetNoZWrite(const bool val);
	void __fastcall SetTiles(TgxTiledArea* const val);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetSortByMaterials(const bool val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxTilePlane(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTilePlane();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property TgxTiledArea* Tiles = {read=FTiles, write=SetTiles};
	__property bool SortByMaterials = {read=FSortByMaterials, write=SetSortByMaterials, nodefault};
	
__published:
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, nodefault};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTilePlane(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Tileplane */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TILEPLANE)
using namespace Gxs::Tileplane;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TilePlaneHPP
