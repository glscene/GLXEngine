// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PersistentClasses.pas' rev: 36.00 (Windows)

#ifndef GXS_PersistentClassesHPP
#define GXS_PersistentClassesHPP

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

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Persistentclasses
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxVirtualReader;
class DELPHICLASS TgxVirtualWriter;
__interface DELPHIINTERFACE IgxPersistentObject;
typedef System::DelphiInterface<IgxPersistentObject> _di_IgxPersistentObject;
class DELPHICLASS TgxPersistentObject;
class DELPHICLASS TgxPersistentObjectList;
class DELPHICLASS TgxBinaryReader;
class DELPHICLASS TgxBinaryWriter;
class DELPHICLASS TgxTextReader;
class DELPHICLASS TgxTextWriter;
class DELPHICLASS TgxOwnedPersistent;
class DELPHICLASS TgxInterfacedPersistent;
class DELPHICLASS TgxInterfacedCollectionItem;
class DELPHICLASS EgxInvalidFileSignature;
class DELPHICLASS EgxFilerException;
//-- type declarations -------------------------------------------------------
typedef System::TObject* *PObject;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVirtualReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStream* FStream;
	
public:
	__fastcall virtual TgxVirtualReader(System::Classes::TStream* Stream);
	__property System::Classes::TStream* Stream = {read=FStream};
	void __fastcall ReadTypeError();
	virtual void __fastcall Read(void *Buf, System::LongInt Count) = 0 ;
	virtual System::Classes::TValueType __fastcall NextValue() = 0 ;
	virtual int __fastcall ReadInteger() = 0 ;
	virtual bool __fastcall ReadBoolean() = 0 ;
	virtual System::UnicodeString __fastcall ReadString() = 0 ;
	virtual System::Extended __fastcall ReadFloat() = 0 ;
	virtual void __fastcall ReadListBegin() = 0 ;
	virtual void __fastcall ReadListEnd() = 0 ;
	virtual bool __fastcall EndOfList() = 0 ;
	void __fastcall ReadTStrings(System::Classes::TStrings* aStrings);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxVirtualReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVirtualWriter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStream* FStream;
	
public:
	__fastcall virtual TgxVirtualWriter(System::Classes::TStream* Stream);
	__property System::Classes::TStream* Stream = {read=FStream};
	virtual void __fastcall Write(const void *Buf, System::LongInt Count) = 0 ;
	virtual void __fastcall WriteInteger(int anInteger) = 0 ;
	virtual void __fastcall WriteBoolean(bool aBoolean) = 0 ;
	virtual void __fastcall WriteString(const System::UnicodeString aString) = 0 ;
	virtual void __fastcall WriteFloat(const System::Extended aFloat) = 0 ;
	virtual void __fastcall WriteListBegin() = 0 ;
	virtual void __fastcall WriteListEnd() = 0 ;
	void __fastcall WriteTStrings(System::Classes::TStrings* const aStrings, bool storeObjects = true);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxVirtualWriter() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TgxVirtualReaderClass;

typedef System::TMetaClass* TgxVirtualWriterClass;

__interface  INTERFACE_UUID("{A9A0198A-F11B-4325-A92C-2F24DB41652B}") IgxPersistentObject  : public System::IInterface 
{
	virtual void __fastcall WriteToFiler(TgxVirtualWriter* writer) = 0 ;
	virtual void __fastcall ReadFromFiler(TgxVirtualReader* reader) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPersistentObject : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	void __fastcall RaiseFilerException(const int archiveVersion);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	
public:
	__fastcall virtual TgxPersistentObject();
	__fastcall TgxPersistentObject(TgxVirtualReader* reader);
	__fastcall virtual ~TgxPersistentObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* source);
	DYNAMIC TgxPersistentObject* __fastcall CreateClone();
	__classmethod virtual System::UnicodeString __fastcall FileSignature();
	__classmethod virtual TgxVirtualWriterClass __fastcall FileVirtualWriter();
	__classmethod virtual TgxVirtualReaderClass __fastcall FileVirtualReader();
	DYNAMIC void __fastcall WriteToFiler(TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(TgxVirtualReader* reader);
	DYNAMIC void __fastcall SaveToStream(System::Classes::TStream* stream, TgxVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromStream(System::Classes::TStream* stream, TgxVirtualReaderClass readerClass = 0x0);
	DYNAMIC void __fastcall SaveToFile(const System::UnicodeString fileName, TgxVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromFile(const System::UnicodeString fileName, TgxVirtualReaderClass readerClass = 0x0);
	DYNAMIC System::UnicodeString __fastcall SaveToString(TgxVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromString(const System::UnicodeString data, TgxVirtualReaderClass readerClass = 0x0);
private:
	void *__IgxPersistentObject;	// IgxPersistentObject 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A9A0198A-F11B-4325-A92C-2F24DB41652B}
	operator _di_IgxPersistentObject()
	{
		_di_IgxPersistentObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxPersistentObject*(void) { return (IgxPersistentObject*)&__IgxPersistentObject; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TgxPersistentObjectClass;

typedef System::StaticArray<System::TObject*, 268435456> TgxPointerObjectList;

typedef TgxPointerObjectList *PgxPointerObjectList;

typedef int __fastcall (*TgxObjectListSortCompare)(System::TObject* item1, System::TObject* item2);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPersistentObjectList : public TgxPersistentObject
{
	typedef TgxPersistentObject inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	PgxPointerObjectList FList;
	int FCount;
	int FCapacity;
	int FGrowthDelta;
	
protected:
	virtual void __fastcall Error();
	System::TObject* __fastcall Get(int Index);
	void __fastcall Put(int Index, System::TObject* Item);
	void __fastcall SetCapacity(int newCapacity);
	void __fastcall SetCount(int NewCount);
	System::TObject* __fastcall GetFirst();
	void __fastcall SetFirst(System::TObject* item);
	System::TObject* __fastcall GetLast();
	void __fastcall SetLast(System::TObject* item);
	virtual void __fastcall AfterObjectCreatedByReader(System::TObject* Sender);
	void __fastcall DoClean();
	
public:
	__fastcall virtual TgxPersistentObjectList();
	__fastcall virtual ~TgxPersistentObjectList();
	DYNAMIC void __fastcall WriteToFiler(TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(TgxVirtualReader* reader);
	void __fastcall ReadFromFilerWithEvent(TgxVirtualReader* reader, System::Classes::TNotifyEvent afterSenderObjectCreated);
	int __fastcall Add(System::TObject* const item);
	void __fastcall AddNils(unsigned nbVals);
	void __fastcall Delete(int index);
	void __fastcall DeleteItems(int index, unsigned nbVals);
	void __fastcall Exchange(int Index1, int Index2);
	void __fastcall Insert(int Index, System::TObject* Item);
	void __fastcall InsertNils(int index, unsigned nbVals);
	void __fastcall Move(int CurIndex, int NewIndex);
	int __fastcall Remove(System::TObject* Item);
	void __fastcall DeleteAndFree(int index);
	void __fastcall DeleteAndFreeItems(int index, unsigned nbVals);
	int __fastcall RemoveAndFree(System::TObject* item);
	__property int GrowthDelta = {read=FGrowthDelta, write=FGrowthDelta, nodefault};
	TgxPersistentObjectList* __fastcall Expand();
	__property System::TObject* Items[int Index] = {read=Get, write=Put/*, default*/};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property PgxPointerObjectList List = {read=FList};
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	void __fastcall RequiredCapacity(int aCapacity);
	void __fastcall Pack();
	virtual void __fastcall Clear();
	virtual void __fastcall Clean();
	void __fastcall CleanFree();
	int __fastcall IndexOf(System::TObject* Item);
	__property System::TObject* First = {read=GetFirst, write=SetFirst};
	__property System::TObject* Last = {read=GetLast, write=SetLast};
	void __fastcall Push(System::TObject* item);
	System::TObject* __fastcall Pop();
	void __fastcall PopAndFree();
	int __fastcall AddObjects(TgxPersistentObjectList* const objectList);
	void __fastcall RemoveObjects(TgxPersistentObjectList* const objectList);
	void __fastcall Sort(TgxObjectListSortCompare compareFunc);
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxPersistentObjectList(TgxVirtualReader* reader) : TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBinaryReader : public TgxVirtualReader
{
	typedef TgxVirtualReader inherited;
	
protected:
	System::Classes::TValueType __fastcall ReadValue();
	System::WideString __fastcall ReadWideString(System::Classes::TValueType vType);
	
public:
	virtual void __fastcall Read(void *Buf, System::LongInt Count);
	virtual System::Classes::TValueType __fastcall NextValue();
	virtual int __fastcall ReadInteger();
	virtual bool __fastcall ReadBoolean();
	virtual System::UnicodeString __fastcall ReadString();
	virtual System::Extended __fastcall ReadFloat();
	virtual void __fastcall ReadListBegin();
	virtual void __fastcall ReadListEnd();
	virtual bool __fastcall EndOfList();
public:
	/* TgxVirtualReader.Create */ inline __fastcall virtual TgxBinaryReader(System::Classes::TStream* Stream) : TgxVirtualReader(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxBinaryReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBinaryWriter : public TgxVirtualWriter
{
	typedef TgxVirtualWriter inherited;
	
protected:
	virtual void __fastcall WriteAnsiString(const System::AnsiString aString);
	virtual void __fastcall WriteWideString(const System::WideString aString);
	
public:
	virtual void __fastcall Write(const void *Buf, System::LongInt Count);
	virtual void __fastcall WriteInteger(int anInteger);
	virtual void __fastcall WriteBoolean(bool aBoolean);
	virtual void __fastcall WriteString(const System::UnicodeString aString);
	virtual void __fastcall WriteFloat(const System::Extended aFloat);
	virtual void __fastcall WriteListBegin();
	virtual void __fastcall WriteListEnd();
public:
	/* TgxVirtualWriter.Create */ inline __fastcall virtual TgxBinaryWriter(System::Classes::TStream* Stream) : TgxVirtualWriter(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxBinaryWriter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTextReader : public TgxVirtualReader
{
	typedef TgxVirtualReader inherited;
	
private:
	System::UnicodeString FValueType;
	System::UnicodeString FData;
	
protected:
	void __fastcall ReadLine(const System::UnicodeString requestedType = System::UnicodeString());
	
public:
	virtual void __fastcall Read(void *Buf, System::LongInt Count);
	virtual System::Classes::TValueType __fastcall NextValue();
	virtual int __fastcall ReadInteger();
	virtual bool __fastcall ReadBoolean();
	virtual System::UnicodeString __fastcall ReadString();
	virtual System::Extended __fastcall ReadFloat();
	virtual void __fastcall ReadListBegin();
	virtual void __fastcall ReadListEnd();
	virtual bool __fastcall EndOfList();
public:
	/* TgxVirtualReader.Create */ inline __fastcall virtual TgxTextReader(System::Classes::TStream* Stream) : TgxVirtualReader(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxTextReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTextWriter : public TgxVirtualWriter
{
	typedef TgxVirtualWriter inherited;
	
private:
	int FIndentLevel;
	
protected:
	void __fastcall WriteLine(const System::UnicodeString valueType, const System::UnicodeString data);
	
public:
	__fastcall virtual TgxTextWriter(System::Classes::TStream* aStream);
	__fastcall virtual ~TgxTextWriter();
	virtual void __fastcall Write(const void *Buf, System::LongInt Count);
	virtual void __fastcall WriteInteger(int anInteger);
	virtual void __fastcall WriteBoolean(bool aBoolean);
	virtual void __fastcall WriteString(const System::UnicodeString aString);
	virtual void __fastcall WriteFloat(const System::Extended aFloat);
	virtual void __fastcall WriteListBegin();
	virtual void __fastcall WriteListEnd();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxOwnedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TgxOwnedPersistent(System::Classes::TPersistent* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxOwnedPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxInterfacedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxInterfacedPersistent() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxInterfacedPersistent() : System::Classes::TPersistent() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxInterfacedCollectionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TgxInterfacedCollectionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxInterfacedCollectionItem() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EgxInvalidFileSignature : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EgxInvalidFileSignature(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EgxInvalidFileSignature(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EgxInvalidFileSignature(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EgxInvalidFileSignature(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxInvalidFileSignature(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxInvalidFileSignature(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EgxInvalidFileSignature(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EgxInvalidFileSignature(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxInvalidFileSignature(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxInvalidFileSignature(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxInvalidFileSignature(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxInvalidFileSignature(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EgxInvalidFileSignature() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EgxFilerException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EgxFilerException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EgxFilerException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EgxFilerException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EgxFilerException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxFilerException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxFilerException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EgxFilerException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EgxFilerException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxFilerException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxFilerException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxFilerException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxFilerException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EgxFilerException() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall RaiseFilerException(System::TClass aClass, int archiveVersion);
extern DELPHI_PACKAGE System::WideString __fastcall UTF8ToWideString(const System::AnsiString s);
}	/* namespace Persistentclasses */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PERSISTENTCLASSES)
using namespace Gxs::Persistentclasses;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PersistentClassesHPP
