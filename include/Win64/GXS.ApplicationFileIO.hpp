// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ApplicationFileIO.pas' rev: 36.00 (Windows)

#ifndef GXS_ApplicationFileIOHPP
#define GXS_ApplicationFileIOHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GXS.BaseClasses.hpp>
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Applicationfileio
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxApplicationFileIO;
class DELPHICLASS TgxDataFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxApplicationResource : unsigned char { aresNone, aresSplash, aresTexture, aresMaterial, aresSampler, aresFont, aresMesh };

typedef System::Classes::TStream* __fastcall (*TgxAFIOCreateFileStream)(const System::UnicodeString fileName, System::Word mode);

typedef bool __fastcall (*TgxAFIOFileStreamExists)(const System::UnicodeString fileName);

typedef void __fastcall (__closure *TgxAFIOFileStreamEvent)(const System::UnicodeString fileName, System::Word mode, System::Classes::TStream* &Stream);

typedef bool __fastcall (__closure *TgxAFIOFileStreamExistsEvent)(const System::UnicodeString fileName);

class PASCALIMPLEMENTATION TgxApplicationFileIO : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxAFIOFileStreamEvent FOnFileStream;
	TgxAFIOFileStreamExistsEvent FOnFileStreamExists;
	
public:
	__fastcall virtual TgxApplicationFileIO(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxApplicationFileIO();
	
__published:
	__property TgxAFIOFileStreamEvent OnFileStream = {read=FOnFileStream, write=FOnFileStream};
	__property TgxAFIOFileStreamExistsEvent OnFileStreamExists = {read=FOnFileStreamExists, write=FOnFileStreamExists};
};


enum DECLSPEC_DENUM TgxDataFileCapability : unsigned char { dfcRead, dfcWrite };

typedef System::Set<TgxDataFileCapability, TgxDataFileCapability::dfcRead, TgxDataFileCapability::dfcWrite> TDataFileCapabilities;

class PASCALIMPLEMENTATION TgxDataFile : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	System::UnicodeString FResourceName;
	
protected:
	HIDESBASE System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetResourceName(const System::UnicodeString AName);
	
public:
	__fastcall virtual TgxDataFile(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxDataFile();
	__classmethod virtual TDataFileCapabilities __fastcall Capabilities();
	virtual TgxDataFile* __fastcall CreateCopy(System::Classes::TPersistent* AOwner);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	__property System::UnicodeString ResourceName = {read=FResourceName, write=SetResourceName};
};


_DECLARE_METACLASS(System::TMetaClass, TgxDataFileClass);

typedef System::Classes::TResourceStream TgxResourceStream;

//-- var, const, procedure ---------------------------------------------------
#define RC_DDS_Type (System::WideChar *)(0x000000000000000aULL)
#define RC_JPG_Type (System::WideChar *)(0x000000000000000aULL)
#define RC_XML_Type (System::WideChar *)(0x000000000000000aULL)
#define RC_String_Type (System::WideChar *)(0x000000000000000aULL)
extern DELPHI_PACKAGE TgxAFIOCreateFileStream vGXAFIOCreateFileStream;
extern DELPHI_PACKAGE TgxAFIOFileStreamExists vGXAFIOFileStreamExists;
extern DELPHI_PACKAGE bool __fastcall ApplicationFileIODefined(void);
extern DELPHI_PACKAGE bool __fastcall FileStreamExists(const System::UnicodeString fileName);
extern DELPHI_PACKAGE TgxResourceStream* __fastcall CreateResourceStream(const System::UnicodeString ResName, System::WideChar * ResType);
extern DELPHI_PACKAGE TgxApplicationResource __fastcall StrToResType(const System::UnicodeString AStrRes);
}	/* namespace Applicationfileio */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_APPLICATIONFILEIO)
using namespace Gxs::Applicationfileio;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ApplicationFileIOHPP
