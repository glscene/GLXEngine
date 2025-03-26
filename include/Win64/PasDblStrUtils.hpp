// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PasDblStrUtils.pas' rev: 36.00 (Windows)

#ifndef PasDblStrUtilsHPP
#define PasDblStrUtilsHPP

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
#include <System.Math.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pasdblstrutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef System::Int8 *PPasDblStrUtilsInt8;

typedef System::Int8 TPasDblStrUtilsInt8;

typedef System::Byte *PPasDblStrUtilsUInt8;

typedef System::Byte TPasDblStrUtilsUInt8;

typedef short *PPasDblStrUtilsInt16;

typedef short TPasDblStrUtilsInt16;

typedef System::Word *PPasDblStrUtilsUInt16;

typedef System::Word TPasDblStrUtilsUInt16;

typedef int *PPasDblStrUtilsInt32;

typedef System::LongInt TPasDblStrUtilsInt32;

typedef unsigned *PPasDblStrUtilsUInt32;

typedef System::LongWord TPasDblStrUtilsUInt32;

typedef __int64 *PPasDblStrUtilsInt64;

typedef __int64 TPasDblStrUtilsInt64;

typedef unsigned __int64 *PPasDblStrUtilsUInt64;

typedef unsigned __int64 TPasDblStrUtilsUInt64;

typedef double *PPasDblStrUtilsDouble;

typedef double TPasDblStrUtilsDouble;

typedef bool *PPasDblStrUtilsBoolean;

typedef bool TPasDblStrUtilsBoolean;

typedef unsigned __int64 *PPasDblStrUtilsPtrUInt;

typedef __int64 *PPasDblStrUtilsPtrInt;

typedef System::NativeUInt TPasDblStrUtilsPtrUInt;

typedef System::NativeInt TPasDblStrUtilsPtrInt;

typedef unsigned __int64 *PPasDblStrUtilsNativeUInt;

typedef __int64 *PPasDblStrUtilsNativeInt;

typedef TPasDblStrUtilsPtrUInt TPasDblStrUtilsNativeUInt;

typedef TPasDblStrUtilsPtrInt TPasDblStrUtilsNativeInt;

typedef char * PPasDblStrUtilsRawByteChar;

typedef char TPasDblStrUtilsRawByteChar;

typedef System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)> TPasDblStrUtilsRawByteCharSet;

typedef TPasDblStrUtilsRawByteCharSet *PPasDblStrUtilsRawByteCharSet;

typedef System::RawByteString *PPasDblStrUtilsRawByteString;

typedef System::RawByteString TPasDblStrUtilsRawByteString;

typedef char * PPasDblStrUtilsUTF8Char;

typedef char TPasDblStrUtilsUTF8Char;

typedef System::UTF8String *PPasDblStrUtilsUTF8String;

typedef System::UTF8String TPasDblStrUtilsUTF8String;

typedef System::WideChar * PPasDblStrUtilsUTF16Char;

typedef System::WideChar TPasDblStrUtilsUTF16Char;

typedef System::UnicodeString *PPasDblStrUtilsUTF16String;

typedef System::UnicodeString TPasDblStrUtilsUTF16String;

typedef char * PPasDblStrUtilsChar;

typedef char TPasDblStrUtilsChar;

typedef System::RawByteString *PPasDblStrUtilsString;

typedef System::RawByteString TPasDblStrUtilsString;

typedef void * *PPasDblStrUtilsPointer;

typedef void * TPasDblStrUtilsPointer;

typedef System::Math::TRoundingMode TPasDblStrUtilsRoundingMode;

typedef TPasDblStrUtilsRoundingMode *PPasDblStrUtilsRoundingMode;

enum DECLSPEC_DENUM TPasDblStrUtilsOutputMode : unsigned char { omStandard, omStandardExponential, omFixed, omExponential, omPrecision, omRadix };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TPasDblStrUtilsDouble __fastcall FallbackStringToDouble(const PPasDblStrUtilsChar aStringValue, const TPasDblStrUtilsInt32 aStringLength, const TPasDblStrUtilsRoundingMode aRoundingMode = (TPasDblStrUtilsRoundingMode)(0x0), const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE double __fastcall FallbackStringToDouble(const TPasDblStrUtilsString aStringValue, const TPasDblStrUtilsRoundingMode aRoundingMode = (TPasDblStrUtilsRoundingMode)(0x0), const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE TPasDblStrUtilsDouble __fastcall AlgorithmMStringToDouble(const PPasDblStrUtilsChar aStringValue, const TPasDblStrUtilsInt32 aStringLength, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE double __fastcall AlgorithmMStringToDouble(const TPasDblStrUtilsString aStringValue, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE TPasDblStrUtilsDouble __fastcall EiselLemireStringToDouble(const PPasDblStrUtilsChar aStringValue, const TPasDblStrUtilsInt32 aStringLength, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0))/* overload */;
extern DELPHI_PACKAGE double __fastcall EiselLemireStringToDouble(const TPasDblStrUtilsString aStringValue, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0))/* overload */;
extern DELPHI_PACKAGE TPasDblStrUtilsDouble __fastcall RyuStringToDouble(const PPasDblStrUtilsChar aStringValue, const TPasDblStrUtilsInt32 aStringLength, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const PPasDblStrUtilsInt32 aCountDigits = (PPasDblStrUtilsInt32)(0x0))/* overload */;
extern DELPHI_PACKAGE double __fastcall RyuStringToDouble(const TPasDblStrUtilsString aStringValue, const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const PPasDblStrUtilsInt32 aCountDigits = (PPasDblStrUtilsInt32)(0x0))/* overload */;
extern DELPHI_PACKAGE TPasDblStrUtilsString __fastcall RyuDoubleToString(const TPasDblStrUtilsDouble aValue, const bool aExponential = true);
extern DELPHI_PACKAGE TPasDblStrUtilsDouble __fastcall ConvertStringToDouble(const PPasDblStrUtilsChar aStringValue, const TPasDblStrUtilsInt32 aStringLength, const TPasDblStrUtilsRoundingMode aRoundingMode = (TPasDblStrUtilsRoundingMode)(0x0), const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE double __fastcall ConvertStringToDouble(const TPasDblStrUtilsString aStringValue, const TPasDblStrUtilsRoundingMode aRoundingMode = (TPasDblStrUtilsRoundingMode)(0x0), const PPasDblStrUtilsBoolean aOK = (PPasDblStrUtilsBoolean)(0x0), const TPasDblStrUtilsInt32 aBase = 0xffffffff)/* overload */;
extern DELPHI_PACKAGE TPasDblStrUtilsString __fastcall ConvertDoubleToString(const TPasDblStrUtilsDouble aValue, const TPasDblStrUtilsOutputMode aOutputMode = (TPasDblStrUtilsOutputMode)(0x0), TPasDblStrUtilsInt32 aRequestedDigits = 0xffffffff);
}	/* namespace Pasdblstrutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PASDBLSTRUTILS)
using namespace Pasdblstrutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PasDblStrUtilsHPP
