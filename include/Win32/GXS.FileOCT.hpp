// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileOCT.pas' rev: 36.00 (Windows)

#ifndef GXS_FileOCTHPP
#define GXS_FileOCTHPP

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
#include <FMX.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.State.hpp>
#include <GXS.ImageUtils.hpp>
#include <Formatx.OCT.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fileoct
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxOCTgxVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxOCTgxVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxOCTgxVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxOCTgxVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float vFileOCTLightmapBrightness;
extern DELPHI_PACKAGE float vFileOCTLightmapGammaCorrection;
extern DELPHI_PACKAGE bool vFileOCTAllocateMaterials;
}	/* namespace Fileoct */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEOCT)
using namespace Gxs::Fileoct;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileOCTHPP
