// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.HeightTileFile.pas' rev: 36.00 (Windows)

#ifndef GXS_HeightTileFileHPP
#define GXS_HeightTileFileHPP

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
#include <GXS.ApplicationFileIO.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Heighttilefile
{
//-- forward type declarations -----------------------------------------------
struct TgxHeightTileInfo;
struct TgxHeightTile;
struct THTFHeader;
class DELPHICLASS TgxHeightTileFile;
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<int, 268435456> TIntegerArray;

typedef TIntegerArray *PIntegerArray;

typedef System::StaticArray<short, 536870912> TSmallIntArray;

typedef TSmallIntArray *PSmallIntArray;

typedef System::StaticArray<System::Int8, 536870912> TShortIntArray;

typedef TShortIntArray *PShortIntArray;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxHeightTileInfo
{
public:
	int left;
	int top;
	int width;
	int height;
	short min;
	short max;
	short average;
	__int64 fileOffset;
};
#pragma pack(pop)


typedef TgxHeightTileInfo *PgxHeightTileInfo;

typedef PgxHeightTileInfo *PPHeightTileInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxHeightTile
{
	
private:
	typedef System::DynamicArray<short> _TgxHeightTile__1;
	
	
public:
	TgxHeightTileInfo info;
	_TgxHeightTile__1 data;
};
#pragma pack(pop)


typedef TgxHeightTile *PHeightTile;

#pragma pack(push,1)
struct DECLSPEC_DRECORD THTFHeader
{
public:
	System::StaticArray<char, 6> FileVersion;
	__int64 TileIndexOffset;
	int SizeX;
	int SizeY;
	int TileSize;
	short DefaultZ;
};
#pragma pack(pop)


typedef System::DynamicArray<int> _TgxHeightTileFile__3;

class PASCALIMPLEMENTATION TgxHeightTileFile : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TgxHeightTileInfo> _TgxHeightTileFile__1;
	
	typedef System::DynamicArray<unsigned> _TgxHeightTileFile__2;
	
	typedef System::StaticArray<_TgxHeightTileFile__3, 1024> _TgxHeightTileFile__4;
	
	typedef System::DynamicArray<int> _TgxHeightTileFile__5;
	
	typedef System::StaticArray<System::StaticArray<_TgxHeightTileFile__5, 32>, 32> _TgxHeightTileFile__6;
	
	typedef System::DynamicArray<System::Int8> _TgxHeightTileFile__7;
	
	
private:
	System::Classes::TStream* FFile;
	THTFHeader FHeader;
	_TgxHeightTileFile__1 FTileIndex;
	_TgxHeightTileFile__2 FTileMark;
	unsigned FLastMark;
	_TgxHeightTileFile__4 FHashTable;
	_TgxHeightTileFile__6 FQuadTable;
	bool FCreating;
	TgxHeightTile FHeightTile;
	_TgxHeightTileFile__7 FInBuf;
	
protected:
	PgxHeightTileInfo __fastcall GetTiles(int index);
	int __fastcall QuadTableX(int x);
	int __fastcall QuadTableY(int y);
	void __fastcall PackTile(int aWidth, int aHeight, PSmallIntArray src);
	void __fastcall UnPackTile(PShortIntArray source);
	__property __int64 TileIndexOffset = {read=FHeader.TileIndexOffset, write=FHeader.TileIndexOffset};
	
public:
	__fastcall TgxHeightTileFile(const System::UnicodeString fileName, int aSizeX, int aSizeY, int aTileSize);
	__fastcall TgxHeightTileFile(const System::UnicodeString fileName);
	__fastcall virtual ~TgxHeightTileFile();
	int __fastcall GetTileIndex(int aLeft, int aTop);
	PHeightTile __fastcall GetTile(int aLeft, int aTop, PPHeightTileInfo pTileInfo = (PPHeightTileInfo)(0x0));
	void __fastcall CompressTile(int aLeft, int aTop, int aWidth, int aHeight, PSmallIntArray aData);
	void __fastcall ExtractRow(int x, int y, int len, PSmallIntArray dest);
	PgxHeightTileInfo __fastcall XYTileInfo(int anX, int anY);
	short __fastcall XYHeight(int anX, int anY);
	void __fastcall TilesInRect(int aLeft, int aTop, int aRight, int aBottom, System::Classes::TList* destList);
	int __fastcall TileCount();
	__property PgxHeightTileInfo Tiles[int index] = {read=GetTiles};
	int __fastcall IndexOfTile(PgxHeightTileInfo aTile);
	int __fastcall TileCompressedSize(int tileIndex);
	__property int SizeX = {read=FHeader.SizeX, nodefault};
	__property int SizeY = {read=FHeader.SizeY, nodefault};
	__property int TileSize = {read=FHeader.TileSize, nodefault};
	__property short DefaultZ = {read=FHeader.DefaultZ, write=FHeader.DefaultZ, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word cHTFHashTableSize = System::Word(0x3ff);
static _DELPHI_CONST System::Int8 cHTFQuadTableSize = System::Int8(0x1f);
}	/* namespace Heighttilefile */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_HEIGHTTILEFILE)
using namespace Gxs::Heighttilefile;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_HeightTileFileHPP
