// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileLWO.pas' rev: 36.00 (Windows)

#ifndef GXS_FileLWOHPP
#define GXS_FileLWOHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <Formatx.LWO.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filelwo
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxLWOVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxLWOVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
private:
	Formatx::Lwo::TLWObjectFile* FLWO;
	Formatx::Lwo::TLWPnts* FPnts;
	void __fastcall AddLayr(Formatx::Lwo::TLWLayr* Layr, Formatx::Lwo::TLWObjectFile* LWO);
	void __fastcall AddSurf(Formatx::Lwo::TLWSurf* Surf, Formatx::Lwo::TLWObjectFile* LWO);
	void __fastcall AddPnts(Formatx::Lwo::TLWPnts* Pnts, Gxs::Vectorfileobjects::TgxMeshObject* Mesh);
	void __fastcall AddPols(Formatx::Lwo::TLWPols* Pols, Gxs::Vectorfileobjects::TgxMeshObject* Mesh);
	void __fastcall AddVMap(Formatx::Lwo::TLWVMap* VMap, Gxs::Vectorfileobjects::TgxMeshObject* Mesh);
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxLWOVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxLWOVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filelwo */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILELWO)
using namespace Gxs::Filelwo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileLWOHPP
