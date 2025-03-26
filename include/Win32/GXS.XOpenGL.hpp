// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.XOpenGL.pas' rev: 36.00 (Windows)

#ifndef GXS_XOpenGLHPP
#define GXS_XOpenGLHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Xopengl
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMapTexCoordMode : unsigned char { mtcmUndefined, mtcmNull, mtcmMain, mtcmDual, mtcmSecond, mtcmArbitrary };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TMapTexCoordMode xglMapTexCoordMode;
extern DELPHI_PACKAGE bool vSecondTextureUnitForbidden;
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord2f)(float s, float t);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord2fv)(Winapi::Opengl::PGLfloat v);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord3f)(float s, float t, float r);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord3fv)(Winapi::Opengl::PGLfloat v);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord4f)(float s, float t, float r, float q);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoord4fv)(Winapi::Opengl::PGLfloat v);
extern DELPHI_PACKAGE void __stdcall (*xglTexGenf)(unsigned coord, unsigned pname, float param);
extern DELPHI_PACKAGE void __stdcall (*xglTexGenfv)(unsigned coord, unsigned pname, Winapi::Opengl::PGLfloat params);
extern DELPHI_PACKAGE void __stdcall (*xglTexGeni)(unsigned coord, unsigned pname, int param);
extern DELPHI_PACKAGE void __stdcall (*xglTexGeniv)(unsigned coord, unsigned pname, Winapi::Opengl::PGLInt params);
extern DELPHI_PACKAGE void __stdcall (*xglTexCoordPointer)(int size, unsigned atype, int stride, void * data);
extern DELPHI_PACKAGE void __stdcall (*xglEnableClientState)(unsigned aarray);
extern DELPHI_PACKAGE void __stdcall (*xglDisableClientState)(unsigned aarray);
extern DELPHI_PACKAGE void __stdcall (*xglEnable)(unsigned cap);
extern DELPHI_PACKAGE void __stdcall (*xglDisable)(unsigned cap);
extern DELPHI_PACKAGE void __fastcall xglBeginUpdate(void);
extern DELPHI_PACKAGE void __fastcall xglEndUpdate(void);
extern DELPHI_PACKAGE void __fastcall xglPushState(void);
extern DELPHI_PACKAGE void __fastcall xglPopState(void);
extern DELPHI_PACKAGE void __fastcall xglForbidSecondTextureUnit(void);
extern DELPHI_PACKAGE void __fastcall xglAllowSecondTextureUnit(void);
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToNull(void);
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToMain(void);
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToSecond(void);
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToDual(void);
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToArbitrary(const unsigned *units, const System::NativeInt units_High)/* overload */;
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToArbitrary(const unsigned bitWiseUnits)/* overload */;
extern DELPHI_PACKAGE void __fastcall xglMapTexCoordToArbitraryAdd(const unsigned bitWiseUnits);
extern DELPHI_PACKAGE unsigned __fastcall xglGetBitWiseMapping(void);
}	/* namespace Xopengl */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_XOPENGL)
using namespace Gxs::Xopengl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_XOpenGLHPP
