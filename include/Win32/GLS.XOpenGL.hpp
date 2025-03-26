// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.XOpenGL.pas' rev: 36.00 (Windows)

#ifndef GLS_XOpenGLHPP
#define GLS_XOpenGLHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGLext.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Xopengl
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLMultitextureCoordinator;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMapTexCoordMode : unsigned char { mtcmUndefined, mtcmNull, mtcmMain, mtcmDual, mtcmSecond, mtcmArbitrary };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMultitextureCoordinator : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TMapTexCoordMode> _TGLMultitextureCoordinator__1;
	
	typedef System::DynamicArray<unsigned> _TGLMultitextureCoordinator__2;
	
	
private:
	TMapTexCoordMode FMapTexCoordMode;
	bool FSecondTextureUnitForbidden;
	int FUpdCount;
	TMapTexCoordMode FUpdNewMode;
	_TGLMultitextureCoordinator__1 FStateStack;
	_TGLMultitextureCoordinator__2 FComplexMapping;
	int FComplexMappingN;
	
public:
	void __stdcall (*TexCoord2f)(Stage::Opengltokens::TGLfloat s, Stage::Opengltokens::TGLfloat t);
	void __stdcall (*TexCoord2fv)(Stage::Opengltokens::PGLfloat v);
	void __stdcall (*TexCoord3f)(Stage::Opengltokens::TGLfloat s, Stage::Opengltokens::TGLfloat t, Stage::Opengltokens::TGLfloat r);
	void __stdcall (*TexCoord3fv)(Stage::Opengltokens::PGLfloat v);
	void __stdcall (*TexCoord4f)(Stage::Opengltokens::TGLfloat s, Stage::Opengltokens::TGLfloat t, Stage::Opengltokens::TGLfloat r, Stage::Opengltokens::TGLfloat q);
	void __stdcall (*TexCoord4fv)(Stage::Opengltokens::PGLfloat v);
	void __stdcall (*TexGenf)(unsigned coord, unsigned pname, Stage::Opengltokens::TGLfloat param);
	void __stdcall (*TexGenfv)(unsigned coord, unsigned pname, Stage::Opengltokens::PGLfloat params);
	void __stdcall (*TexGeni)(unsigned coord, unsigned pname, Stage::Opengltokens::TGLint param);
	void __stdcall (*TexGeniv)(unsigned coord, unsigned pname, Stage::Opengltokens::PGLint params);
	void __stdcall (*TexCoordPointer)(Stage::Opengltokens::TGLint size, unsigned atype, Stage::Opengltokens::TGLsizei stride, void * data);
	void __stdcall (*EnableClientState)(unsigned aarray);
	void __stdcall (*DisableClientState)(unsigned aarray);
	void __stdcall (*Enable)(unsigned cap);
	void __stdcall (*Disable)(unsigned cap);
	__fastcall TGLMultitextureCoordinator();
	void __fastcall MapTexCoordToNull();
	void __fastcall MapTexCoordToMain();
	void __fastcall MapTexCoordToSecond();
	void __fastcall MapTexCoordToDual();
	void __fastcall MapTexCoordToArbitrary(const unsigned *units, const System::NativeInt units_High)/* overload */;
	void __fastcall MapTexCoordToArbitrary(const unsigned bitWiseUnits)/* overload */;
	void __fastcall MapTexCoordToArbitraryAdd(const unsigned bitWiseUnits);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	void __fastcall PushState();
	void __fastcall PopState();
	void __fastcall ForbidSecondTextureUnit();
	void __fastcall AllowSecondTextureUnit();
	unsigned __fastcall GetBitWiseMapping();
	__property TMapTexCoordMode MapTexCoordMode = {read=FMapTexCoordMode, write=FMapTexCoordMode, nodefault};
	__property bool SecondTextureUnitForbidden = {read=FSecondTextureUnitForbidden, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLMultitextureCoordinator() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Xopengl */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_XOPENGL)
using namespace Gls::Xopengl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_XOpenGLHPP
