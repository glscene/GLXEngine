// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileB3D.pas' rev: 36.00 (Windows)

#ifndef GXS_FileB3DHPP
#define GXS_FileB3DHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <Formatx.B3D.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fileb3d
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxB3DVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxB3DVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxB3DVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxB3DVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Fileb3d */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEB3D)
using namespace Gxs::Fileb3d;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileB3DHPP
