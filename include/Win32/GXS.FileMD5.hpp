// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileMD5.pas' rev: 36.00 (Windows)

#ifndef GXS_FileMD5HPP
#define GXS_FileMD5HPP

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
#include <GXS.VectorFileObjects.hpp>
#include <Stage.Utils.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filemd5
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMD5VectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxMD5VectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
private:
	System::Classes::TStringList* FMD5String;
	System::Classes::TStringList* FTempString;
	System::Classes::TStringList* FBoneNames;
	int FCurrentPos;
	Gxs::Vectorfileobjects::TgxSkeletonFrame* FBasePose;
	Gxs::Vectorlists::TgxAffineVectorList* FFramePositions;
	Gxs::Vectorlists::TGQuaternionList* FFrameQuaternions;
	Gxs::Vectorlists::TgxIntegerList* FJointFlags;
	int FNumFrames;
	int FFirstFrame;
	int FFrameRate;
	int FNumJoints;
	System::UnicodeString __fastcall ReadLine();
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxMD5VectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxMD5VectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Classes::TStringList* vMD5TextureExtensions;
}	/* namespace Filemd5 */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEMD5)
using namespace Gxs::Filemd5;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileMD5HPP
