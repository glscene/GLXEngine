// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileDXF.pas' rev: 36.00 (Windows)

#ifndef GXS_FileDXFHPP
#define GXS_FileDXFHPP

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
#include <Stage.VectorTypes.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filedxf
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxDXFVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxDXFVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
private:
	System::Classes::TStream* FSourceStream;
	System::UnicodeString FBuffer;
	int FLineNo;
	bool FEof;
	int FBufPos;
	bool HasPushedCode;
	int PushedCode;
	System::Classes::TStringList* FLayers;
	System::Classes::TStringList* FBlocks;
	System::Byte FLastpercentdone;
	
protected:
	void __fastcall PushCode(int code);
	int __fastcall GetCode();
	void __fastcall SkipTable();
	void __fastcall SkipSection();
	Gxs::Vectorfileobjects::TgxMeshObject* __fastcall NeedMesh(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh, System::UnicodeString layer);
	Gxs::Vectorfileobjects::TgxFGVertexIndexList* __fastcall NeedFaceGroup(Gxs::Vectorfileobjects::TgxMeshObject* m, Gxs::Vectorfileobjects::TgxFaceGroupMeshMode fgmode, System::UnicodeString fgmat);
	void __fastcall NeedMeshAndFaceGroup(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh, System::UnicodeString layer, Gxs::Vectorfileobjects::TgxFaceGroupMeshMode fgmode, System::UnicodeString fgmat, Gxs::Vectorfileobjects::TgxMeshObject* &m, Gxs::Vectorfileobjects::TgxFGVertexIndexList* &fg);
	System::UnicodeString __fastcall ReadLine();
	int __fastcall ReadInt();
	double __fastcall ReadDouble();
	void __fastcall ReadTables();
	void __fastcall ReadLayer();
	void __fastcall ReadLayerTable();
	void __fastcall ReadBlocks();
	void __fastcall ReadInsert(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh);
	void __fastcall ReadEntity3Dface(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh);
	void __fastcall ReadEntityPolyLine(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh);
	void __fastcall ReadEntities(Gxs::Vectorfileobjects::TgxBaseMesh* basemesh);
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxDXFVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxDXFVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filedxf */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEDXF)
using namespace Gxs::Filedxf;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileDXFHPP
