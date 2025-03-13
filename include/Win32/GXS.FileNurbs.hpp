// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileNurbs.pas' rev: 36.00 (Windows)

#ifndef GXS_FileNurbsHPP
#define GXS_FileNurbsHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.ParametricSurfaces.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filenurbs
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxNurbsVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxNurbsVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxNurbsVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxNurbsVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filenurbs */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILENURBS)
using namespace Gxs::Filenurbs;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileNurbsHPP
