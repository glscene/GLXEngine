// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileGRD.pas' rev: 36.00 (Windows)

#ifndef GXS_FileGRDHPP
#define GXS_FileGRDHPP

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
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Graph.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filegrd
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxGRDVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxGRDVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectorgeometry::TSingleArray> _TgxGRDVectorFile__1;
	
	
public:
	Gxs::Graph::TgxHeightField* HeightField;
	_TgxGRDVectorFile__1 Nodes;
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	
private:
	System::UnicodeString StrVal;
	System::UnicodeString StrLine;
	float MaxZ;
	System::UnicodeString __fastcall ExtractWord(int N, const System::UnicodeString S, const System::Sysutils::TSysCharSet &WordDelims);
	int __fastcall WordPosition(const int N, const System::UnicodeString S, const System::Sysutils::TSysCharSet &WordDelims);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxGRDVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxGRDVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filegrd */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEGRD)
using namespace Gxs::Filegrd;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileGRDHPP
