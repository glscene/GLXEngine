// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PasJSON.pas' rev: 36.00 (Windows)

#ifndef PasJSONHPP
#define PasJSONHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pasjson
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EPasJSONSyntaxError;
class DELPHICLASS EPasJSONMergeError;
class DELPHICLASS TPasJSONItem;
class DELPHICLASS TPasJSONItemNull;
class DELPHICLASS TPasJSONItemBoolean;
class DELPHICLASS TPasJSONItemNumber;
class DELPHICLASS TPasJSONItemString;
class DELPHICLASS TPasJSONItemObjectProperty;
class DELPHICLASS TPasJSONItemObject;
class DELPHICLASS TPasJSONItemArray;
class DELPHICLASS TPasJSON;
//-- type declarations -------------------------------------------------------
typedef System::Int8 *PPasJSONInt8;

typedef PPasJSONInt8 *PPPasJSONInt8;

typedef System::Int8 TPasJSONInt8;

typedef System::Byte *PPasJSONUInt8;

typedef PPasJSONUInt8 *PPPasJSONUInt8;

typedef System::Byte TPasJSONUInt8;

typedef System::StaticArray<System::Byte, 65536> TPasJSONUInt8Array;

typedef TPasJSONUInt8Array *PPasJSONUInt8Array;

typedef PPasJSONUInt8Array *PPPasJSONUInt8Array;

typedef short *PPasJSONInt16;

typedef PPasJSONInt16 *PPPasJSONInt16;

typedef short TPasJSONInt16;

typedef System::Word *PPasJSONUInt16;

typedef PPasJSONUInt16 *PPPasJSONUInt16;

typedef System::Word TPasJSONUInt16;

typedef int *PPasJSONInt32;

typedef PPasJSONInt32 *PPPasJSONInt32;

typedef System::LongInt TPasJSONInt32;

typedef unsigned *PPasJSONUInt32;

typedef PPasJSONUInt32 *PPPasJSONUInt32;

typedef System::LongWord TPasJSONUInt32;

typedef __int64 *PPasJSONInt64;

typedef PPasJSONInt64 *PPPasJSONInt64;

typedef __int64 TPasJSONInt64;

typedef unsigned __int64 *PPasJSONUInt64;

typedef PPasJSONUInt64 *PPPasJSONUInt64;

typedef unsigned __int64 TPasJSONUInt64;

typedef char * *PPPasJSONChar;

typedef char * PPasJSONChar;

typedef char TPasJSONChar;

typedef char * *PPPasJSONRawByteChar;

typedef char * PPasJSONRawByteChar;

typedef char TPasJSONRawByteChar;

typedef System::WideChar * *PPPasJSONUTF16Char;

typedef System::WideChar * PPasJSONUTF16Char;

typedef System::WideChar TPasJSONUTF16Char;

typedef void * *PPasJSONPointer;

typedef PPasJSONPointer *PPPasJSONPointer;

typedef void * TPasJSONPointer;

typedef System::StaticArray<void *, 65536> TPasJSONPointers;

typedef TPasJSONPointers *PPasJSONPointers;

typedef PPasJSONPointers *PPPasJSONPointers;

typedef void * *PPPasJSONVoid;

typedef TPasJSONPointer PPasJSONVoid;

typedef float *PPasJSONFloat;

typedef PPasJSONFloat *PPPasJSONFloat;

typedef float TPasJSONFloat;

typedef System::DynamicArray<float> TPasJSONFloats;

typedef double *PPasJSONDouble;

typedef PPasJSONDouble *PPPasJSONDouble;

typedef double TPasJSONDouble;

typedef unsigned *PPasJSONPtrUInt;

typedef PPasJSONPtrUInt *PPPasJSONPtrUInt;

typedef int *PPasJSONPtrInt;

typedef PPasJSONPtrInt *PPPasJSONPtrInt;

typedef System::NativeUInt TPasJSONPtrUInt;

typedef System::NativeInt TPasJSONPtrInt;

typedef unsigned *PPasJSONSizeUInt;

typedef PPasJSONSizeUInt *PPPasJSONSizeUInt;

typedef TPasJSONPtrUInt TPasJSONSizeUInt;

typedef int *PPasJSONSizeInt;

typedef PPasJSONSizeInt *PPPasJSONSizeInt;

typedef TPasJSONPtrInt TPasJSONSizeInt;

typedef unsigned *PPasJSONNativeUInt;

typedef PPasJSONNativeUInt *PPPasJSONNativeUInt;

typedef TPasJSONPtrUInt TPasJSONNativeUInt;

typedef int *PPasJSONNativeInt;

typedef PPasJSONNativeInt *PPPasJSONNativeInt;

typedef TPasJSONPtrInt TPasJSONNativeInt;

typedef PPasJSONSizeUInt *PPPasJSONSize;

typedef unsigned *PPasJSONSize;

typedef TPasJSONPtrUInt TPasJSONSize;

typedef int *PPasJSONPtrDiff;

typedef PPasJSONPtrDiff *PPPasJSONPtrDiff;

typedef TPasJSONPtrInt TPasJSONPtrDiff;

typedef System::RawByteString *PPasJSONRawByteString;

typedef PPasJSONRawByteString *PPPasJSONRawByteString;

typedef System::RawByteString TPasJSONRawByteString;

typedef System::UTF8String *PPasJSONUTF8String;

typedef PPasJSONUTF8String *PPPasJSONUTF8String;

typedef System::UTF8String TPasJSONUTF8String;

typedef System::UnicodeString *PPasJSONUTF16String;

typedef PPasJSONUTF16String *PPPasJSONUTF16String;

typedef System::UnicodeString TPasJSONUTF16String;

#pragma pack(push,4)
class PASCALIMPLEMENTATION EPasJSONSyntaxError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
private:
	TPasJSONSizeInt fPosition;
	
public:
	__fastcall EPasJSONSyntaxError(const System::UnicodeString aMessage, const TPasJSONSizeInt aPosition);
	
__published:
	__property TPasJSONSizeInt Position = {read=fPosition, write=fPosition, nodefault};
public:
	/* Exception.CreateFmt */ inline __fastcall EPasJSONSyntaxError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EPasJSONSyntaxError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EPasJSONSyntaxError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EPasJSONSyntaxError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EPasJSONSyntaxError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EPasJSONSyntaxError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EPasJSONSyntaxError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPasJSONSyntaxError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPasJSONSyntaxError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPasJSONSyntaxError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPasJSONSyntaxError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EPasJSONSyntaxError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EPasJSONMergeError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EPasJSONMergeError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EPasJSONMergeError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EPasJSONMergeError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EPasJSONMergeError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EPasJSONMergeError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EPasJSONMergeError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EPasJSONMergeError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EPasJSONMergeError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPasJSONMergeError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPasJSONMergeError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPasJSONMergeError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPasJSONMergeError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EPasJSONMergeError() { }
	
};

#pragma pack(pop)

enum class DECLSPEC_DENUM TPasJSONMergeFlag : unsigned char { ForceObjectPropertyValueDestinationType };

typedef System::Set<TPasJSONMergeFlag, _DELPHI_SET_ENUMERATOR(TPasJSONMergeFlag::ForceObjectPropertyValueDestinationType), _DELPHI_SET_ENUMERATOR(TPasJSONMergeFlag::ForceObjectPropertyValueDestinationType)> TPasJSONMergeFlags;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall TPasJSONItem();
	__fastcall virtual ~TPasJSONItem();
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
};

#pragma pack(pop)

typedef System::DynamicArray<TPasJSONItem*> TPasJSONItems;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemNull : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
public:
	__fastcall TPasJSONItemNull();
	__fastcall virtual ~TPasJSONItemNull();
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemBoolean : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
private:
	bool fValue;
	
public:
	__fastcall TPasJSONItemBoolean(const bool AValue);
	__fastcall virtual ~TPasJSONItemBoolean();
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
	
__published:
	__property bool Value = {read=fValue, write=fValue, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TPasJSONItemNumber : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
private:
	TPasJSONDouble fValue;
	
public:
	__fastcall TPasJSONItemNumber(const TPasJSONDouble AValue);
	__fastcall virtual ~TPasJSONItemNumber();
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
	
__published:
	__property TPasJSONDouble Value = {read=fValue, write=fValue};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemString : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
private:
	TPasJSONUTF8String fValue;
	
public:
	__fastcall TPasJSONItemString(const TPasJSONUTF8String AValue);
	__fastcall virtual ~TPasJSONItemString();
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
	
__published:
	__property TPasJSONUTF8String Value = {read=fValue, write=fValue};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemObjectProperty : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TPasJSONUTF8String fKey;
	TPasJSONItem* fValue;
	
public:
	__fastcall TPasJSONItemObjectProperty();
	__fastcall virtual ~TPasJSONItemObjectProperty();
	
__published:
	__property TPasJSONUTF8String Key = {read=fKey, write=fKey};
	__property TPasJSONItem* Value = {read=fValue, write=fValue};
};

#pragma pack(pop)

typedef System::DynamicArray<TPasJSONItemObjectProperty*> TPasJSONItemObjectProperties;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemObject : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
	
public:
	struct TPasJSONItemObjectEnumerator;
	typedef TPasJSONItemObjectEnumerator *PPasJSONItemObjectEnumerator;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TPasJSONItemObjectEnumerator
	{
	private:
		TPasJSONItemObject* fOwner;
		TPasJSONSizeInt fIndex;
		TPasJSONItemObjectProperty* __fastcall GetCurrent();
		
	public:
		__fastcall TPasJSONItemObjectEnumerator(TPasJSONItemObject* const aOwner);
		bool __fastcall MoveNext();
		__property TPasJSONItemObjectProperty* Current = {read=GetCurrent};
		TPasJSONItemObjectEnumerator() {}
	};
	#pragma pack(pop)
	
	
	
public:
	TPasJSONItem* operator[](const TPasJSONUTF8String Key) { return this->Properties[Key]; }
	
private:
	TPasJSONItemObjectProperties fProperties;
	TPasJSONSizeInt fCount;
	TPasJSONInt32 __fastcall GetKeyIndex(const TPasJSONUTF8String aKey);
	TPasJSONUTF8String __fastcall GetKey(const TPasJSONSizeInt aIndex);
	void __fastcall SetKey(const TPasJSONSizeInt aIndex, const TPasJSONUTF8String aKey);
	TPasJSONItem* __fastcall GetValue(const TPasJSONSizeInt aIndex);
	void __fastcall SetValue(const TPasJSONSizeInt aIndex, TPasJSONItem* const aItem);
	TPasJSONItem* __fastcall GetProperty(const TPasJSONUTF8String aKey);
	void __fastcall SetProperty(const TPasJSONUTF8String aKey, TPasJSONItem* const aItem);
	
public:
	__fastcall TPasJSONItemObject();
	__fastcall virtual ~TPasJSONItemObject();
	TPasJSONItemObjectEnumerator __fastcall GetEnumerator();
	void __fastcall Clear();
	void __fastcall Add(const TPasJSONUTF8String aKey, TPasJSONItem* const AValue);
	void __fastcall Delete(const TPasJSONSizeInt aIndex)/* overload */;
	void __fastcall Delete(const TPasJSONUTF8String aKey)/* overload */;
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
	__property TPasJSONSizeInt Count = {read=fCount, nodefault};
	__property TPasJSONInt32 Indices[const TPasJSONUTF8String Key] = {read=GetKeyIndex};
	__property TPasJSONUTF8String Keys[const TPasJSONSizeInt Index] = {read=GetKey, write=SetKey};
	__property TPasJSONItem* Values[const TPasJSONSizeInt Index] = {read=GetValue, write=SetValue};
	__property TPasJSONItem* Properties[const TPasJSONUTF8String Key] = {read=GetProperty, write=SetProperty/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSONItemArray : public TPasJSONItem
{
	typedef TPasJSONItem inherited;
	
	
public:
	struct TPasJSONItemArrayEnumerator;
	typedef TPasJSONItemArrayEnumerator *PPasJSONItemArrayEnumerator;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD TPasJSONItemArrayEnumerator
	{
	private:
		TPasJSONItemArray* fOwner;
		TPasJSONSizeInt fIndex;
		TPasJSONItem* __fastcall GetCurrent();
		
	public:
		__fastcall TPasJSONItemArrayEnumerator(TPasJSONItemArray* const aOwner);
		bool __fastcall MoveNext();
		__property TPasJSONItem* Current = {read=GetCurrent};
		TPasJSONItemArrayEnumerator() {}
	};
	#pragma pack(pop)
	
	
	
public:
	TPasJSONItem* operator[](const TPasJSONInt32 Index) { return this->Items[Index]; }
	
private:
	TPasJSONItems fItems;
	TPasJSONInt32 fCount;
	TPasJSONItem* __fastcall GetValue(const TPasJSONInt32 Index);
	void __fastcall SetValue(const TPasJSONInt32 Index, TPasJSONItem* const Item);
	
public:
	__fastcall TPasJSONItemArray();
	__fastcall virtual ~TPasJSONItemArray();
	TPasJSONItemArrayEnumerator __fastcall GetEnumerator();
	void __fastcall Clear();
	void __fastcall Add(TPasJSONItem* const AValue);
	void __fastcall Delete(const TPasJSONSizeInt aIndex);
	virtual void __fastcall Merge(TPasJSONItem* const aWith, const TPasJSONMergeFlags aFlags = TPasJSONMergeFlags() );
	__property TPasJSONInt32 Count = {read=fCount, nodefault};
	__property TPasJSONItem* Items[const TPasJSONInt32 Index] = {read=GetValue, write=SetValue/*, default*/};
};

#pragma pack(pop)

enum class DECLSPEC_DENUM TPasJSONModeFlag : unsigned char { UnquotedKeys, Comments, ImplicitRootObject, OptionalCommas, EqualsForColon, MultilineStrings, HexadecimalNumbers };

typedef TPasJSONModeFlag *PPasJSONModeFlag;

typedef TPasJSONModeFlag *PPasJSONModeFlags;

typedef System::Set<TPasJSONModeFlag, _DELPHI_SET_ENUMERATOR(TPasJSONModeFlag::UnquotedKeys), _DELPHI_SET_ENUMERATOR(TPasJSONModeFlag::HexadecimalNumbers)> TPasJSONModeFlags;

enum class DECLSPEC_DENUM TPasJSONEncoding : unsigned char { AutomaticDetection, Latin1, UTF8, UTF16LE, UTF16BE, UTF32LE, UTF32BE };

typedef TPasJSONEncoding *PPasJSONEncoding;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPasJSON : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static TPasJSONModeFlags SimplifiedJSONModeFlags;
	static TPasJSONRawByteString __fastcall StringQuote(const TPasJSONUTF8String aString);
	static TPasJSONItem* __fastcall Parse(const TPasJSONRawByteString aSource, const TPasJSONModeFlags aModeFlags = (TPasJSONModeFlags() << TPasJSONModeFlag::Comments ), const TPasJSONEncoding aEncoding = (TPasJSONEncoding)(0x0))/* overload */;
	static TPasJSONItem* __fastcall Parse(System::Classes::TStream* const aStream, const TPasJSONModeFlags aModeFlags = (TPasJSONModeFlags() << TPasJSONModeFlag::Comments ), const TPasJSONEncoding aEncoding = (TPasJSONEncoding)(0x0))/* overload */;
	static TPasJSONRawByteString __fastcall Stringify(TPasJSONItem* const aJSONItem, const bool aFormatting = false, const TPasJSONModeFlags aModeFlags = TPasJSONModeFlags() , const TPasJSONInt32 aLevel = 0x0);
	static void __fastcall StringifyToStream(System::Classes::TStream* const aStream, TPasJSONItem* const aJSONItem, const bool aFormatting = false, const TPasJSONModeFlags aModeFlags = TPasJSONModeFlags() , const TPasJSONInt32 aLevel = 0x0);
	static TPasJSONDouble __fastcall GetNumber(TPasJSONItem* const aItem, const TPasJSONDouble aDefault = 0.000000E+00);
	static TPasJSONInt64 __fastcall GetInt64(TPasJSONItem* const aItem, const TPasJSONInt64 aDefault = 0LL);
	static TPasJSONUTF8String __fastcall GetString(TPasJSONItem* const aItem, const TPasJSONUTF8String aDefault = System::UTF8String());
	static bool __fastcall GetBoolean(TPasJSONItem* const aItem, const bool aDefault = false);
	static TPasJSONItem* __fastcall LoadBinaryFromStream(System::Classes::TStream* const aStream);
	static void __fastcall SaveBinaryToStream(System::Classes::TStream* const aStream, TPasJSONItem* const aJSONItem);
public:
	/* TObject.Create */ inline __fastcall TPasJSON() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TPasJSON() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Pasjson */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PASJSON)
using namespace Pasjson;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PasJSONHPP
