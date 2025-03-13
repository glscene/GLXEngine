// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FileLMTS.pas' rev: 36.00 (Windows)

#ifndef GLS_FileLMTSHPP
#define GLS_FileLMTSHPP

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
#include <Vcl.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Texture.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Graphics.hpp>
#include <GLS.Material.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
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
class DELPHICLASS TGLLMTSVectorFile;
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
	Gls::Material::TGLShininess FShininess;
	Gls::Material::TGLShininess BShininess;
	Stage::Vectortypes::TGLVector FAmbient;
	Stage::Vectortypes::TGLVector FDiffuse;
	Stage::Vectortypes::TGLVector FEmission;
	Stage::Vectortypes::TGLVector FSpecular;
	Stage::Vectortypes::TGLVector BAmbient;
	Stage::Vectortypes::TGLVector BDiffuse;
	Stage::Vectortypes::TGLVector BEmission;
	Stage::Vectortypes::TGLVector BSpecular;
	Gls::Texture::TGLTextureImageAlpha ImageAlpha;
	Gls::Texture::TGLMagFilter magFilter;
	Gls::Texture::TGLMinFilter minFilter;
	Gls::Texture::TGLTextureMode TextureMode;
	Gls::Texture::TGLTextureWrap TextureWrap;
	Gls::Material::TGLBlendingMode Blendingmode;
	Gls::Material::TGLFaceCulling FaceCulling;
	int mathash;
};


class PASCALIMPLEMENTATION TGLLMTSVectorFile : public Gls::Vectorfileobjects::TGLVectorFile
{
	typedef Gls::Vectorfileobjects::TGLVectorFile inherited;
	
public:
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TGLVectorFile.Create */ inline __fastcall virtual TGLLMTSVectorFile(System::Classes::TPersistent* AOwner) : Gls::Vectorfileobjects::TGLVectorFile(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLLMTSVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST int C_LMTS_ID = int(0x53544d4c);
static _DELPHI_CONST System::Int8 C_LMTS_VER = System::Int8(0x4);
static _DELPHI_CONST int C_LMTS_SUBS = int(0x53425553);
static _DELPHI_CONST int C_LMTS_TEXT = int(0x54584554);
static _DELPHI_CONST int C_LMTS_TRIS = int(0x53495254);
static _DELPHI_CONST System::Byte C_LMTS_TEXFNLEN = System::Byte(0xff);
}	/* namespace Filelmts */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILELMTS)
using namespace Gls::Filelmts;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_FileLMTSHPP
