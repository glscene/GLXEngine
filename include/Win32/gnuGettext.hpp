// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'gnugettext.pas' rev: 36.00 (Windows)

#ifndef gnugettextHPP
#define gnugettextHPP

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
#include <System.StrUtils.hpp>
#include <System.SysUtils.hpp>
#include <System.TypInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gnugettext
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGnuGettext;
class DELPHICLASS EGGProgrammingError;
class DELPHICLASS EGGComponentError;
class DELPHICLASS EGGIOError;
class DELPHICLASS EGGAnsi2WideConvError;
class DELPHICLASS TMoFile;
class DELPHICLASS TDomain;
class DELPHICLASS TExecutable;
__interface DELPHIINTERFACE IGnuGettextInstanceWhenNewLanguageListener;
typedef System::DelphiInterface<IGnuGettextInstanceWhenNewLanguageListener> _di_IGnuGettextInstanceWhenNewLanguageListener;
class DELPHICLASS TGnuGettextInstance;
//-- type declarations -------------------------------------------------------
typedef System::RawByteString RawUtf8String;

typedef System::UnicodeString DomainString;

typedef System::UnicodeString LanguageString;

typedef System::UnicodeString ComponentNameString;

typedef System::UnicodeString FilenameString;

typedef System::UnicodeString MsgIdString;

typedef System::UnicodeString TranslatedUnicodeString;

typedef void __fastcall (__closure *TTranslator)(System::TObject* obj);

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGnuGettext : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGnuGettext(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGnuGettext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGnuGettext(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGnuGettext(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGnuGettext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGnuGettext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGnuGettext(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGnuGettext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGnuGettext(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGnuGettext(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGnuGettext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGnuGettext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGnuGettext() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGGProgrammingError : public EGnuGettext
{
	typedef EGnuGettext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGGProgrammingError(const System::UnicodeString Msg) : EGnuGettext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGGProgrammingError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EGnuGettext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGGProgrammingError(System::NativeUInt Ident)/* overload */ : EGnuGettext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGGProgrammingError(System::PResStringRec ResStringRec)/* overload */ : EGnuGettext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGProgrammingError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGProgrammingError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGGProgrammingError(const System::UnicodeString Msg, int AHelpContext) : EGnuGettext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGGProgrammingError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EGnuGettext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGProgrammingError(System::NativeUInt Ident, int AHelpContext)/* overload */ : EGnuGettext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGProgrammingError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGProgrammingError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGProgrammingError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGGProgrammingError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGGComponentError : public EGnuGettext
{
	typedef EGnuGettext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGGComponentError(const System::UnicodeString Msg) : EGnuGettext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGGComponentError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EGnuGettext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGGComponentError(System::NativeUInt Ident)/* overload */ : EGnuGettext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGGComponentError(System::PResStringRec ResStringRec)/* overload */ : EGnuGettext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGComponentError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGComponentError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGGComponentError(const System::UnicodeString Msg, int AHelpContext) : EGnuGettext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGGComponentError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EGnuGettext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGComponentError(System::NativeUInt Ident, int AHelpContext)/* overload */ : EGnuGettext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGComponentError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGComponentError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGComponentError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGGComponentError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGGIOError : public EGnuGettext
{
	typedef EGnuGettext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGGIOError(const System::UnicodeString Msg) : EGnuGettext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGGIOError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EGnuGettext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGGIOError(System::NativeUInt Ident)/* overload */ : EGnuGettext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGGIOError(System::PResStringRec ResStringRec)/* overload */ : EGnuGettext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGIOError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGIOError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGGIOError(const System::UnicodeString Msg, int AHelpContext) : EGnuGettext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGGIOError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EGnuGettext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGIOError(System::NativeUInt Ident, int AHelpContext)/* overload */ : EGnuGettext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGIOError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGIOError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGIOError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGGIOError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGGAnsi2WideConvError : public EGnuGettext
{
	typedef EGnuGettext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGGAnsi2WideConvError(const System::UnicodeString Msg) : EGnuGettext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGGAnsi2WideConvError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EGnuGettext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGGAnsi2WideConvError(System::NativeUInt Ident)/* overload */ : EGnuGettext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGGAnsi2WideConvError(System::PResStringRec ResStringRec)/* overload */ : EGnuGettext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGAnsi2WideConvError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGGAnsi2WideConvError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGGAnsi2WideConvError(const System::UnicodeString Msg, int AHelpContext) : EGnuGettext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGGAnsi2WideConvError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EGnuGettext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGAnsi2WideConvError(System::NativeUInt Ident, int AHelpContext)/* overload */ : EGnuGettext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGGAnsi2WideConvError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGAnsi2WideConvError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGGAnsi2WideConvError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGnuGettext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGGAnsi2WideConvError() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TOnDebugLine)(System::TObject* Sender, const System::UnicodeString Line, bool &Discard);

typedef int __fastcall (*TGetPluralForm)(System::LongInt Number);

typedef void __fastcall (__closure *TDebugLogger)(System::AnsiString Line);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TMoFile : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool doswap;
	
public:
	int Users;
	__fastcall TMoFile(const FilenameString filename, const __int64 Offset, __int64 Size, const bool xUseMemoryMappedFiles);
	__fastcall virtual ~TMoFile();
	RawUtf8String __fastcall gettext(const RawUtf8String msgid, bool &found);
	__property bool isSwappedArchitecture = {read=doswap, nodefault};
	
private:
	unsigned N;
	unsigned O;
	unsigned T;
	int startindex;
	int startstep;
	bool FUseMemoryMappedFiles;
	Winapi::Windows::THandle mo;
	Winapi::Windows::THandle momapping;
	char *momemoryHandle;
	char *momemory;
	unsigned __fastcall autoswap32(unsigned i);
	unsigned __fastcall CardinalInMem(char * baseptr, unsigned Offset);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TDomain : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool enabled;
	FilenameString vDirectory;
	void __fastcall setDirectory(const FilenameString dir);
	
public:
	TDebugLogger DebugLogger;
	DomainString domain;
	__property FilenameString Directory = {read=vDirectory, write=setDirectory};
	__fastcall TDomain();
	__fastcall virtual ~TDomain();
	void __fastcall SetLanguageCode(const LanguageString langcode);
	void __fastcall SetFilename(const FilenameString filename);
	void __fastcall GetListOfLanguages(System::Classes::TStrings* list);
	TranslatedUnicodeString __fastcall GetTranslationProperty(ComponentNameString propertyname);
	RawUtf8String __fastcall gettext(const RawUtf8String msgid);
	
private:
	TMoFile* mofile;
	FilenameString SpecificFilename;
	LanguageString curlang;
	bool OpenHasFailedBefore;
	void __fastcall OpenMoFile();
	void __fastcall CloseMoFile();
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TExecutable : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall Execute() = 0 ;
public:
	/* TObject.Create */ inline __fastcall TExecutable() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TExecutable() { }
	
};

#pragma pack(pop)

__interface IGnuGettextInstanceWhenNewLanguageListener  : public System::IInterface 
{
	virtual void __fastcall WhenNewLanguage(const LanguageString LanguageID) = 0 ;
};

class PASCALIMPLEMENTATION TGnuGettextInstance : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TOnDebugLine fOnDebugLine;
	
public:
	bool enabled;
	int DesignTimeCodePage;
	__fastcall TGnuGettextInstance();
	__fastcall virtual ~TGnuGettextInstance();
	void __fastcall UseLanguage(LanguageString LanguageCode);
	void __fastcall GetListOfLanguages(const DomainString domain, System::Classes::TStrings* list);
	virtual TranslatedUnicodeString __fastcall gettext(const MsgIdString szMsgId)/* overload */;
	TranslatedUnicodeString __fastcall gettext_NoExtract(const MsgIdString szMsgId);
	TranslatedUnicodeString __fastcall gettext_NoOp(const MsgIdString szMsgId);
	virtual TranslatedUnicodeString __fastcall ngettext(const MsgIdString singular, const MsgIdString plural, System::LongInt Number)/* overload */;
	TranslatedUnicodeString __fastcall ngettext_NoExtract(const MsgIdString singular, const MsgIdString plural, System::LongInt Number);
	LanguageString __fastcall GetCurrentLanguage();
	TranslatedUnicodeString __fastcall GetTranslationProperty(const ComponentNameString propertyname);
	TranslatedUnicodeString __fastcall GetTranslatorNameAndEmail();
	void __fastcall TP_Ignore(System::TObject* AnObject, const ComponentNameString name);
	void __fastcall TP_IgnoreClass(System::TClass IgnClass);
	void __fastcall TP_IgnoreClassProperty(System::TClass IgnClass, ComponentNameString propertyname);
	void __fastcall TP_GlobalIgnoreClass(System::TClass IgnClass);
	void __fastcall TP_GlobalIgnoreClassProperty(System::TClass IgnClass, ComponentNameString propertyname);
	void __fastcall TP_GlobalHandleClass(System::TClass HClass, TTranslator Handler);
	void __fastcall TranslateProperties(System::TObject* AnObject, DomainString textdomain = System::UnicodeString());
	void __fastcall TranslateComponent(System::Classes::TComponent* AnObject, const DomainString textdomain = System::UnicodeString());
	void __fastcall RetranslateComponent(System::Classes::TComponent* AnObject, const DomainString textdomain = System::UnicodeString());
	virtual TranslatedUnicodeString __fastcall dgettext(const DomainString szDomain, const MsgIdString szMsgId)/* overload */;
	TranslatedUnicodeString __fastcall dgettext_NoExtract(const DomainString szDomain, const MsgIdString szMsgId);
	virtual TranslatedUnicodeString __fastcall dngettext(const DomainString szDomain, const MsgIdString singular, const MsgIdString plural, System::LongInt Number)/* overload */;
	TranslatedUnicodeString __fastcall dngettext_NoExtract(const DomainString szDomain, const MsgIdString singular, const MsgIdString plural, System::LongInt Number);
	void __fastcall textdomain(const DomainString szDomain);
	DomainString __fastcall getcurrenttextdomain();
	void __fastcall bindtextdomain(const DomainString szDomain, const FilenameString szDirectory);
	void __fastcall bindtextdomainToFile(const DomainString szDomain, const FilenameString filename);
	System::UnicodeString __fastcall LoadResString(System::PResStringRec ResStringRec);
	void __fastcall DebugLogToFile(const FilenameString filename, bool append = false);
	void __fastcall DebugLogPause(bool PauseEnabled);
	__property TOnDebugLine OnDebugLine = {read=fOnDebugLine, write=fOnDebugLine};
	void __fastcall RegisterWhenNewLanguageListener(_di_IGnuGettextInstanceWhenNewLanguageListener Listener);
	void __fastcall UnregisterWhenNewLanguageListener(_di_IGnuGettextInstanceWhenNewLanguageListener Listener);
	
protected:
	void __fastcall TranslateStrings(System::Classes::TStrings* sl, const DomainString textdomain);
	virtual void __fastcall WhenNewLanguage(const LanguageString LanguageID);
	virtual void __fastcall WhenNewDomain(const DomainString textdomain);
	virtual void __fastcall WhenNewDomainDirectory(const DomainString textdomain, const FilenameString Directory);
	
private:
	LanguageString curlang;
	TGetPluralForm curGetPluralForm;
	DomainString curmsgdomain;
	System::Sysutils::TMultiReadExclusiveWriteSynchronizer* savefileCS;
	System::TextFile savefile;
	System::Classes::TStringList* savememory;
	FilenameString DefaultDomainDirectory;
	System::Classes::TStringList* domainlist;
	System::Classes::TStringList* TP_IgnoreList;
	System::Classes::TList* TP_ClassHandling;
	System::Classes::TList* TP_GlobalClassHandling;
	TExecutable* TP_Retranslator;
	System::Classes::TInterfaceList* fWhenNewLanguageListeners;
	TExecutable* __fastcall TP_CreateRetranslator();
	void __fastcall FreeTP_ClassHandlingItems();
	void __fastcall TranslateProperty(System::TObject* AnObject, System::Typinfo::PPropInfo PropInfo, System::Classes::TStrings* TodoList, const DomainString textdomain);
	TDomain* __fastcall Getdomain(const DomainString domain, const FilenameString DefaultDomainDirectory, const LanguageString curlang);
};


//-- var, const, procedure ---------------------------------------------------
#define DefaultTextDomain L"default"
extern DELPHI_PACKAGE FilenameString ExecutableFilename;
static _DELPHI_CONST bool PreferExternal = true;
static _DELPHI_CONST bool UseMemoryMappedFiles = true;
static _DELPHI_CONST bool ReReadMoFileOnSameLanguage = true;
#define VCSVersion L"$LastChangedRevision: 220 $"
static _DELPHI_CONST bool AutoCreateHooks = true;
extern DELPHI_PACKAGE TGnuGettextInstance* DefaultInstance;
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall gettext(const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall gettext_NoExtract(const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall gettext_NoOp(const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall _(const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall dgettext(const DomainString szDomain, const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall dgettext_NoExtract(const DomainString szDomain, const MsgIdString szMsgId);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall dngettext(const DomainString szDomain, const MsgIdString singular, const MsgIdString plural, System::LongInt Number);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall ngettext(const MsgIdString singular, const MsgIdString plural, System::LongInt Number);
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall ngettext_NoExtract(const MsgIdString singular, const MsgIdString plural, System::LongInt Number);
extern DELPHI_PACKAGE void __fastcall textdomain(const DomainString szDomain);
extern DELPHI_PACKAGE DomainString __fastcall getcurrenttextdomain(void);
extern DELPHI_PACKAGE void __fastcall bindtextdomain(const DomainString szDomain, const FilenameString szDirectory);
extern DELPHI_PACKAGE void __fastcall TP_Ignore(System::TObject* AnObject, const ComponentNameString name);
extern DELPHI_PACKAGE void __fastcall TP_GlobalIgnoreClass(System::TClass IgnClass);
extern DELPHI_PACKAGE void __fastcall TP_IgnoreClass(System::TClass IgnClass);
extern DELPHI_PACKAGE void __fastcall TP_IgnoreClassProperty(System::TClass IgnClass, const ComponentNameString propertyname);
extern DELPHI_PACKAGE void __fastcall TP_GlobalIgnoreClassProperty(System::TClass IgnClass, const ComponentNameString propertyname);
extern DELPHI_PACKAGE void __fastcall TP_GlobalHandleClass(System::TClass HClass, TTranslator Handler);
extern DELPHI_PACKAGE void __fastcall TranslateComponent(System::Classes::TComponent* AnObject, const DomainString textdomain = System::UnicodeString());
extern DELPHI_PACKAGE void __fastcall RetranslateComponent(System::Classes::TComponent* AnObject, const DomainString textdomain = System::UnicodeString());
extern DELPHI_PACKAGE TranslatedUnicodeString __fastcall GetTranslatorNameAndEmail(void);
extern DELPHI_PACKAGE void __fastcall UseLanguage(LanguageString LanguageCode);
extern DELPHI_PACKAGE System::WideString __fastcall LoadResString(System::PResStringRec ResStringRec);
extern DELPHI_PACKAGE System::UnicodeString __fastcall LoadResStringW(System::PResStringRec ResStringRec);
extern DELPHI_PACKAGE LanguageString __fastcall GetCurrentLanguage(void);
extern DELPHI_PACKAGE void __fastcall AddDomainForResourceString(const DomainString domain);
extern DELPHI_PACKAGE void __fastcall RemoveDomainForResourceString(const DomainString domain);
extern DELPHI_PACKAGE void __fastcall AddDomains(const System::UnicodeString *Domains, const System::NativeInt Domains_High);
extern DELPHI_PACKAGE void __fastcall AddDomainForComponent(const DomainString domain);
extern DELPHI_PACKAGE void __fastcall RemoveDomainForComponent(const DomainString domain);
extern DELPHI_PACKAGE void __fastcall HookIntoResourceStrings(bool enabled = true, bool SupportPackages = false);
}	/* namespace Gnugettext */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GNUGETTEXT)
using namespace Gnugettext;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// gnugettextHPP
