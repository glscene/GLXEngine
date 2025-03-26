// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileVRML.pas' rev: 36.00 (Windows)

#ifndef GXS_FileVRMLHPP
#define GXS_FileVRMLHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Material.hpp>
#include <GXS.MeshUtils.hpp>
#include <Formatx.VRML.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filevrml
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxVRMLVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxVRMLVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxVRMLVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxVRMLVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filevrml */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEVRML)
using namespace Gxs::Filevrml;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileVRMLHPP
