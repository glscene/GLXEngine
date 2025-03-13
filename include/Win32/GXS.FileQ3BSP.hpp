// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileQ3BSP.pas' rev: 36.00 (Windows)

#ifndef GXS_FileQ3BSPHPP
#define GXS_FileQ3BSPHPP

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
#include <GXS.VectorFileObjects.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.BSP.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.State.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Material.hpp>
#include <Stage.TextureFormat.hpp>
#include <Formatx.Q3BSP.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fileq3bsp
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxQ3BSPVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxQ3BSPVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxQ3BSPVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxQ3BSPVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float vQ3BSPLightmapGammaCorrection;
extern DELPHI_PACKAGE float vQ3BSPLightmapBrightness;
extern DELPHI_PACKAGE bool vFileQ3BSPLoadMaterials;
}	/* namespace Fileq3bsp */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEQ3BSP)
using namespace Gxs::Fileq3bsp;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileQ3BSPHPP
