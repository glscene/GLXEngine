// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileLMTS.pas' rev: 36.00 (Windows)

#ifndef GXS_FileLMTSHPP
#define GXS_FileLMTSHPP

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
#include <FMX.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filelmts
{
//-- forward type declarations -----------------------------------------------
struct TLMTS_Header;
struct TLMTS_TexData;
struct TLMTS_Subset;
struct TLMTS_Vertex;
struct TLMTS;
struct TMaterialInfo;
class DELPHICLASS TgxLMTSVectorFile;
//-- type declarations -------------------------------------------------------
typedef TLMTS_Header *PLMTS_Header;

struct DECLSPEC_DRECORD TLMTS_Header
{
public:
	unsigned ID;
	unsigned Ver;
	unsigned headerSize;
	System::Word nTexts;
	System::Word nSubsets;
	unsigned nTris;
	System::Word subSize;
	System::Word vtxSize;
};


typedef TLMTS_TexData *PLMTS_TexData;

struct DECLSPEC_DRECORD TLMTS_TexData
{
public:
	System::StaticArray<char, 256> fName;
	System::Word Flags;
};


typedef TLMTS_Subset *PLMTS_Subset;

struct DECLSPEC_DRECORD TLMTS_Subset
{
public:
	System::LongInt Offset;
	System::LongInt Count;
	System::Word TextID1;
	System::Word TextID2;
};


typedef TLMTS_Vertex *PLMTS_Vertex;

struct DECLSPEC_DRECORD TLMTS_Vertex
{
public:
	float x;
	float y;
	float z;
	float u1;
	float v1;
	float u2;
	float v2;
};


typedef TLMTS *PLMTS;

struct DECLSPEC_DRECORD TLMTS
{
public:
	TLMTS_Header header;
	void *usrData;
	unsigned usrSize;
	void *texData;
	void *subsets;
	void *tris;
	bool ok;
};


struct DECLSPEC_DRECORD TMaterialInfo
{
public:
	Gxs::Material::TgxShininess FShininess;
	Gxs::Material::TgxShininess BShininess;
	Stage::Vectortypes::TVector4f FAmbient;
	Stage::Vectortypes::TVector4f FDiffuse;
	Stage::Vectortypes::TVector4f FEmission;
	Stage::Vectortypes::TVector4f FSpecular;
	Stage::Vectortypes::TVector4f BAmbient;
	Stage::Vectortypes::TVector4f BDiffuse;
	Stage::Vectortypes::TVector4f BEmission;
	Stage::Vectortypes::TVector4f BSpecular;
	Gxs::Texture::TgxTextureImageAlpha ImageAlpha;
	Gxs::Texture::TgxMagFilter magFilter;
	Gxs::Texture::TgxMinFilter minFilter;
	Gxs::Texture::TgxTextureMode TextureMode;
	Gxs::Texture::TgxTextureWrap TextureWrap;
	Gxs::Material::TgxBlendingMode Blendingmode;
	Gxs::Material::TgxFaceCulling FaceCulling;
	int mathash;
};


class PASCALIMPLEMENTATION TgxLMTSVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxLMTSVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxLMTSVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST int C_LMTS_ID = int(0x53544d4c);
static _DELPHI_CONST System::Int8 C_LMTS_VER = System::Int8(0x4);
static _DELPHI_CONST int C_LMTS_SUBS = int(0x53425553);
static _DELPHI_CONST int C_LMTS_TEXT = int(0x54584554);
static _DELPHI_CONST int C_LMTS_TRIS = int(0x53495254);
static _DELPHI_CONST System::Byte C_LMTS_TEXFNLEN = System::Byte(0xff);
}	/* namespace Filelmts */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILELMTS)
using namespace Gxs::Filelmts;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileLMTSHPP
