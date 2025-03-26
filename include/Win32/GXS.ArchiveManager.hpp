// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ArchiveManager.pas' rev: 36.00 (Windows)

#ifndef GXS_ArchiveManagerHPP
#define GXS_ArchiveManagerHPP

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
#include <Stage.Strings.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Archivemanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBaseArchive;
class DELPHICLASS TArchiveFileFormat;
class DELPHICLASS TgxArchiveFileFormatsList;
class DELPHICLASS TLibArchive;
class DELPHICLASS TLibArchives;
class DELPHICLASS TgxSArchiveManager;
class DELPHICLASS EInvalidArchiveFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TCompressionLevel : unsigned char { clNone, clFastest, clDefault, clMax, clLevel1, clLevel2, clLevel3, clLevel4, clLevel5, clLevel6, clLevel7, clLevel8, clLevel9 };

class PASCALIMPLEMENTATION TgxBaseArchive : public Gxs::Applicationfileio::TgxDataFile
{
	typedef Gxs::Applicationfileio::TgxDataFile inherited;
	
protected:
	System::UnicodeString FFileName;
	System::Classes::TStrings* FContentList;
	TCompressionLevel FCompressionLevel;
	virtual void __fastcall SetCompressionLevel(TCompressionLevel aValue);
	
public:
	__fastcall virtual TgxBaseArchive(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxBaseArchive();
	__property System::Classes::TStrings* ContentList = {read=FContentList};
	__property TCompressionLevel CompressionLevel = {read=FCompressionLevel, write=SetCompressionLevel, default=0};
	virtual void __fastcall Clear() = 0 ;
	virtual bool __fastcall ContentExists(System::UnicodeString ContentName) = 0 ;
	virtual System::Classes::TStream* __fastcall GetContent(System::Classes::TStream* Stream, int index) = 0 /* overload */;
	virtual System::Classes::TStream* __fastcall GetContent(System::UnicodeString ContentName) = 0 /* overload */;
	virtual System::Classes::TStream* __fastcall GetContent(int index) = 0 /* overload */;
	virtual int __fastcall GetContentSize(int index) = 0 /* overload */;
	virtual int __fastcall GetContentSize(System::UnicodeString ContentName) = 0 /* overload */;
	virtual void __fastcall AddFromStream(System::UnicodeString ContentName, System::UnicodeString Path, System::Classes::TStream* FS) = 0 ;
	virtual void __fastcall AddFromFile(System::UnicodeString FileName, System::UnicodeString Path) = 0 ;
	virtual void __fastcall RemoveContent(int index) = 0 /* overload */;
	virtual void __fastcall RemoveContent(System::UnicodeString ContentName) = 0 /* overload */;
	virtual void __fastcall Extract(int index, System::UnicodeString NewName) = 0 /* overload */;
	virtual void __fastcall Extract(System::UnicodeString ContentName, System::UnicodeString NewName) = 0 /* overload */;
};


typedef System::TMetaClass* TgxBaseArchiveClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TArchiveFileFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TgxBaseArchiveClass BaseArchiveClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
public:
	/* TObject.Create */ inline __fastcall TArchiveFileFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TArchiveFileFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxArchiveFileFormatsList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	__fastcall virtual ~TgxArchiveFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TgxBaseArchiveClass AClass);
	TgxBaseArchiveClass __fastcall FindExt(System::UnicodeString ext);
	TgxBaseArchiveClass __fastcall FindFromFileName(const System::UnicodeString fileName);
	HIDESBASE void __fastcall Remove(TgxBaseArchiveClass AClass);
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxArchiveFileFormatsList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxArchiveFileFormatsList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TLibArchive : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxBaseArchive* vArchive;
	TgxBaseArchiveClass ArcClass;
	System::UnicodeString FFileName;
	System::UnicodeString FName;
	void __fastcall SetCompressionLevel(TCompressionLevel aValue);
	TCompressionLevel __fastcall GetCompressionLevel();
	System::Classes::TStrings* __fastcall GetContentList();
	void __fastcall SetName(const System::UnicodeString val);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TLibArchive(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TLibArchive();
	__property TCompressionLevel CompressionLevel = {read=GetCompressionLevel, write=SetCompressionLevel, default=0};
	void __fastcall CreateArchive(System::UnicodeString FileName, bool OverwriteExistingFile = false);
	__property System::Classes::TStrings* ContentList = {read=GetContentList};
	void __fastcall LoadFromFile(System::UnicodeString aFileName)/* overload */;
	void __fastcall LoadFromFile(System::UnicodeString aFileName, System::UnicodeString aAchiverType)/* overload */;
	void __fastcall Clear();
	bool __fastcall ContentExists(System::UnicodeString aContentName);
	__property System::UnicodeString FileName = {read=FFileName};
	System::Classes::TStream* __fastcall GetContent(int aindex)/* overload */;
	System::Classes::TStream* __fastcall GetContent(System::UnicodeString aContentName)/* overload */;
	int __fastcall GetContentSize(int aindex)/* overload */;
	int __fastcall GetContentSize(System::UnicodeString aContentName)/* overload */;
	void __fastcall AddFromStream(System::UnicodeString aContentName, System::UnicodeString aPath, System::Classes::TStream* aF)/* overload */;
	void __fastcall AddFromStream(System::UnicodeString aContentName, System::Classes::TStream* aF)/* overload */;
	void __fastcall AddFromFile(System::UnicodeString aFileName, System::UnicodeString aPath)/* overload */;
	void __fastcall AddFromFile(System::UnicodeString aFileName)/* overload */;
	void __fastcall RemoveContent(int aindex)/* overload */;
	void __fastcall RemoveContent(System::UnicodeString aContentName)/* overload */;
	void __fastcall Extract(int aindex, System::UnicodeString aNewName)/* overload */;
	void __fastcall Extract(System::UnicodeString aContentName, System::UnicodeString aNewName)/* overload */;
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TLibArchives : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TLibArchive* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TLibArchive* const val);
	TLibArchive* __fastcall GetItems(int index);
	
public:
	__fastcall TLibArchives(System::Classes::TComponent* AOwner);
	HIDESBASE System::Classes::TPersistent* __fastcall Owner();
	int __fastcall IndexOf(TLibArchive* const Item);
	HIDESBASE TLibArchive* __fastcall Add();
	HIDESBASE TLibArchive* __fastcall FindItemID(int ID);
	__property TLibArchive* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TLibArchive* __fastcall GetArchiveByFileName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetFileNameOfArchive(TLibArchive* aValue);
	System::UnicodeString __fastcall MakeUniqueName(const System::UnicodeString nameRoot);
	TLibArchive* __fastcall GetLibArchiveByName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetNameOfLibArchive(TLibArchive* const Archive);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TLibArchives() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxSArchiveManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TLibArchives* FArchives;
	void __fastcall SetArchives(TLibArchives* aValue);
	
public:
	__fastcall virtual TgxSArchiveManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSArchiveManager();
	TLibArchive* __fastcall GetArchiveByFileName(const System::UnicodeString aName);
	System::UnicodeString __fastcall GetFileNameOfArchive(TLibArchive* const aArchive);
	System::Classes::TStream* __fastcall GetContent(System::UnicodeString aContentName);
	bool __fastcall ContentExists(System::UnicodeString aContentName);
	TLibArchive* __fastcall OpenArchive(System::UnicodeString aFileName)/* overload */;
	TLibArchive* __fastcall OpenArchive(System::UnicodeString aFileName, System::UnicodeString aAchiverType)/* overload */;
	void __fastcall CloseArchive(TLibArchive* aArchive);
	
__published:
	__property TLibArchives* Archives = {read=FArchives, write=SetArchives};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidArchiveFile : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidArchiveFile() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxArchiveFileFormatsList* __fastcall GetArchiveFileFormats(void);
extern DELPHI_PACKAGE void __fastcall RegisterArchiveFormat(const System::UnicodeString AExtension, const System::UnicodeString ADescription, TgxBaseArchiveClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterArchiveFormat(TgxBaseArchiveClass AClass);
extern DELPHI_PACKAGE TgxSArchiveManager* __fastcall GetArchiveManager(void);
extern DELPHI_PACKAGE System::Classes::TStream* __fastcall ArcCreateFileStream(const System::UnicodeString fileName, System::Word mode);
extern DELPHI_PACKAGE bool __fastcall ArcFileStreamExists(const System::UnicodeString fileName);
}	/* namespace Archivemanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ARCHIVEMANAGER)
using namespace Gxs::Archivemanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ArchiveManagerHPP
