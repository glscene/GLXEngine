// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SoundFileObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_SoundFileObjectsHPP
#define GXS_SoundFileObjectsHPP

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
#include <Winapi.MMSystem.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Soundfileobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSoundSampling;
class DELPHICLASS TgxSoundFile;
struct TgxSoundFileFormat;
class DELPHICLASS TgxSoundFileFormatsList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundSampling : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	int FFrequency;
	int FNbChannels;
	int FBitsPerSample;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall TgxSoundSampling(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxSoundSampling();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall BytesPerSec();
	int __fastcall BytesPerSample();
	tWAVEFORMATEX __fastcall WaveFormat();
	
__published:
	__property int Frequency = {read=FFrequency, write=FFrequency, default=22050};
	__property int NbChannels = {read=FNbChannels, write=FNbChannels, default=1};
	__property int BitsPerSample = {read=FBitsPerSample, write=FBitsPerSample, default=8};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxSoundFile : public Gxs::Applicationfileio::TgxDataFile
{
	typedef Gxs::Applicationfileio::TgxDataFile inherited;
	
private:
	TgxSoundSampling* FSampling;
	
protected:
	void __fastcall SetSampling(TgxSoundSampling* const val);
	
public:
	__fastcall virtual TgxSoundFile(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxSoundFile();
	virtual void __fastcall PlayOnWaveOut();
	virtual void * __fastcall WAVData() = 0 ;
	virtual int __fastcall WAVDataSize() = 0 ;
	virtual void * __fastcall PCMData() = 0 ;
	virtual int __fastcall LengthInBytes() = 0 ;
	int __fastcall LengthInSamples();
	float __fastcall LengthInSec();
	__property TgxSoundSampling* Sampling = {read=FSampling, write=SetSampling};
};


typedef System::TMetaClass* TgxSoundFileClass;

struct DECLSPEC_DRECORD TgxSoundFileFormat
{
public:
	TgxSoundFileClass SoundFileClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
};


typedef TgxSoundFileFormat *PSoundFileFormat;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundFileFormatsList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	__fastcall virtual ~TgxSoundFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TgxSoundFileClass AClass);
	TgxSoundFileClass __fastcall FindExt(System::UnicodeString Ext);
	HIDESBASE void __fastcall Remove(TgxSoundFileClass AClass);
	void __fastcall BuildFilterStrings(TgxSoundFileClass SoundFileClass, /* out */ System::UnicodeString &Descriptions, /* out */ System::UnicodeString &Filters);
public:
	/* TObject.Create */ inline __fastcall TgxSoundFileFormatsList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxSoundFileFormatsList* __fastcall GetGLSoundFileFormats(void);
extern DELPHI_PACKAGE void __fastcall RegisterSoundFileFormat(const System::UnicodeString AExtension, const System::UnicodeString ADescription, TgxSoundFileClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterSoundFileClass(TgxSoundFileClass AClass);
}	/* namespace Soundfileobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDFILEOBJECTS)
using namespace Gxs::Soundfileobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SoundFileObjectsHPP
