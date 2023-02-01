﻿// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FileMD5.pas' rev: 35.00 (Windows)

#ifndef Gls_Filemd5HPP
#define Gls_Filemd5HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Utils.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.VectorTypes.hpp>
#include <GLS.VectorGeometry.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Filemd5
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLMD5VectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLMD5VectorFile : public Gls::Vectorfileobjects::TGLVectorFile
{
	typedef Gls::Vectorfileobjects::TGLVectorFile inherited;
	
private:
	System::Classes::TStringList* FMD5String;
	System::Classes::TStringList* FTempString;
	System::Classes::TStringList* FBoneNames;
	int FCurrentPos;
	Gls::Vectorfileobjects::TGLSkeletonFrame* FBasePose;
	Gls::Vectorlists::TGLAffineVectorList* FFramePositions;
	Gls::Vectorlists::TGLQuaternionList* FFrameQuaternions;
	Gls::Vectorlists::TGLIntegerList* FJointFlags;
	int FNumFrames;
	int FFirstFrame;
	int FFrameRate;
	int FNumJoints;
	System::UnicodeString __fastcall ReadLine();
	
public:
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TGLVectorFile.Create */ inline __fastcall virtual TGLMD5VectorFile(System::Classes::TPersistent* AOwner) : Gls::Vectorfileobjects::TGLVectorFile(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLMD5VectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Classes::TStringList* vMD5TextureExtensions;
}	/* namespace Filemd5 */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILEMD5)
using namespace Gls::Filemd5;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Gls_Filemd5HPP