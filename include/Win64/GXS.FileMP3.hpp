// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileMP3.pas' rev: 36.00 (Windows)

#ifndef GXS_FileMP3HPP
#define GXS_FileMP3HPP

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
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.SoundFileObjects.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filemp3
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMP3File;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxMP3File : public Gxs::Soundfileobjects::TgxSoundFile
{
	typedef Gxs::Soundfileobjects::TgxSoundFile inherited;
	
	
private:
	typedef System::DynamicArray<System::Byte> _TgxMP3File__1;
	
	
private:
	_TgxMP3File__1 data;
	
public:
	virtual Gxs::Applicationfileio::TgxDataFile* __fastcall CreateCopy(System::Classes::TPersistent* AOwner);
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall PlayOnWaveOut();
	virtual void * __fastcall WAVData();
	virtual int __fastcall WAVDataSize();
	virtual void * __fastcall PCMData();
	virtual int __fastcall LengthInBytes();
public:
	/* TgxSoundFile.Create */ inline __fastcall virtual TgxMP3File(System::Classes::TPersistent* AOwner) : Gxs::Soundfileobjects::TgxSoundFile(AOwner) { }
	/* TgxSoundFile.Destroy */ inline __fastcall virtual ~TgxMP3File() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filemp3 */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEMP3)
using namespace Gxs::Filemp3;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileMP3HPP
