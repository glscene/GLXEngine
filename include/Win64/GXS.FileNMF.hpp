// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileNMF.pas' rev: 36.00 (Windows)

#ifndef GXS_FileNMFHPP
#define GXS_FileNMFHPP

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
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filenmf
{
//-- forward type declarations -----------------------------------------------
struct TNmHeader;
struct TNmRawTriangle;
class DELPHICLASS TFileNMF;
class DELPHICLASS TgxNMFVectorFile;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TNmHeader
{
public:
	System::StaticArray<char, 4> hdr;
	unsigned size;
};


struct DECLSPEC_DRECORD TNmRawTriangle
{
public:
	System::StaticArray<Stage::Vectortypes::TVector3f, 3> vert;
	System::StaticArray<Stage::Vectortypes::TVector3f, 3> norm;
	System::StaticArray<Stage::Vectorgeometry::TTexPoint, 3> texCoord;
};


class PASCALIMPLEMENTATION TFileNMF : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TNmRawTriangle> _TFileNMF__1;
	
	
public:
	TNmHeader FileHeader;
	TNmHeader TrisHeader;
	int NumTris;
	_TFileNMF__1 RawTriangles;
	void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall SaveToStream(System::Classes::TStream* Stream);
public:
	/* TObject.Create */ inline __fastcall TFileNMF() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TFileNMF() { }
	
};


class PASCALIMPLEMENTATION TgxNMFVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxNMFVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxNMFVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define NMF_HEADER_TAG L"NMF "
#define NMF_TRIANGLE_TAG L"TRIS"
}	/* namespace Filenmf */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILENMF)
using namespace Gxs::Filenmf;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileNMFHPP
