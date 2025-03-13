// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.OpenGLTokens.pas' rev: 36.00 (Windows)

#ifndef Stage_OpenGLTokensHPP
#define Stage_OpenGLTokensHPP

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
#include <Winapi.OpenGLext.hpp>
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Opengltokens
{
//-- forward type declarations -----------------------------------------------
struct _WGLSWAP;
struct TGPUDEVICE;
struct DECLSPEC_DRECORD TGLUNurbs
{
};


struct DECLSPEC_DRECORD TGLUQuadric
{
};


struct DECLSPEC_DRECORD TGLUTesselator
{
};


//-- type declarations -------------------------------------------------------
typedef System::ByteBool TGLboolean;

typedef System::ByteBool *PGLboolean;

typedef System::LongWord TGLbitfield;

typedef unsigned *PGLbitfield;

typedef System::Int8 TGLbyte;

typedef System::Int8 *PGLbyte;

typedef short TGLshort;

typedef short *PGLshort;

typedef int TGLint;

typedef System::PInteger PGLint;

typedef int TGLsizei;

typedef System::PInteger PGLsizei;

typedef __int64 TGLint64;

typedef System::PInt64 PGLint64;

typedef __int64 TGLint64EXT;

typedef System::PInt64 PGLint64EXT;

typedef unsigned __int64 TGLuint64;

typedef System::PUInt64 PGLuint64;

typedef unsigned __int64 TGLuint64EXT;

typedef System::PUInt64 PGLuint64EXT;

typedef System::Byte TGLubyte;

typedef System::PByte PGLubyte;

typedef System::Word TGLushort;

typedef System::PWord PGLushort;

typedef unsigned TGLenum;

typedef unsigned *PGLenum;

typedef unsigned TGLuint;

typedef System::PCardinal PGLuint;

typedef float TGLfloat;

typedef System::PSingle PGLfloat;

typedef double TGLdouble;

typedef System::PDouble PGLdouble;

typedef System::PSingle PGLclampf;

typedef double TGLclampd;

typedef System::PDouble PGLclampd;

typedef char * *PGLPCharArray;

typedef void * PGLvoid;

typedef void * *PGLPointer;

typedef unsigned TGLhandleARB;

typedef unsigned *PGLhandleARB;

typedef System::NativeInt TGLintptr;

typedef __int64 *PGLintptr;

typedef System::NativeInt TGLsizeiptr;

typedef __int64 *PGLsizeiptr;

typedef System::NativeInt TGLsync;

typedef __int64 *PGLsync;

typedef System::Byte TGLchar;

typedef char * PGLchar;

typedef System::Word TGLhalf;

typedef System::Word *PGLhalf;

typedef _WGLSWAP *PWGLswap;

#pragma pack(push,1)
struct DECLSPEC_DRECORD _WGLSWAP
{
public:
	HDC hdc;
	unsigned uiFlags;
};
#pragma pack(pop)


typedef _WGLSWAP TWGLswap;

typedef _WGLSWAP WGLSWAP;

typedef unsigned __int64 HPBUFFERARB;

typedef unsigned __int64 *PHGPUNV;

typedef Winapi::Windows::THandle HGPUNV;

typedef Winapi::Windows::THandle HVIDEOINPUTDEVICENV;

typedef unsigned __int64 *PHVIDEOINPUTDEVICENV;

typedef TGPUDEVICE *PGPUDEVICE;

struct DECLSPEC_DRECORD TGPUDEVICE
{
public:
	unsigned cb;
	System::StaticArray<char, 32> DeviceName;
	System::StaticArray<char, 128> DeviceString;
	unsigned Flags;
	Winapi::Windows::TRect rcVirtualScreen;
};


typedef void __stdcall (*TDebugProc)(unsigned source, unsigned type_, unsigned id, unsigned severity, TGLsizei length, const char * message, void * userParam);

typedef TDebugProc TGLDEBUGPROCARB;

typedef void __stdcall (*TDebugProcAMD)(unsigned id, unsigned category, unsigned severity, TGLsizei length, char * message, void * userParam);

typedef TGLintptr TGLvdpauSurfaceNV;

typedef __int64 *PGLvdpauSurfaceNV;

typedef TGLUNurbs *PGLUNurbs;

typedef TGLUQuadric *PGLUQuadric;

typedef TGLUTesselator *PGLUTesselator;

typedef TGLUNurbs TGLUNurbsObj;

typedef TGLUQuadric TGLUQuadricObj;

typedef TGLUTesselator TGLUTesselatorObj;

typedef TGLUTesselator TGLUTriangulatorObj;

typedef PGLUNurbs PGLUNurbsObj;

typedef PGLUQuadric PGLUQuadricObj;

typedef PGLUTesselator PGLUTesselatorObj;

typedef PGLUTesselator PGLUTriangulatorObj;

typedef void __stdcall (*TGLUQuadricErrorProc)(unsigned errorCode);

typedef void __stdcall (*TGLUTessBeginProc)(unsigned AType);

typedef void __stdcall (*TGLUTessEdgeFlagProc)(TGLboolean Flag);

typedef void __stdcall (*TGLUTessVertexProc)(void * VertexData);

typedef void __stdcall (*TGLUTessEndProc)(void);

typedef void __stdcall (*TGLUTessErrorProc)(unsigned ErrNo);

typedef void __stdcall (*TGLUTessCombineProc)(const Stage::Vectortypes::TVector3d &Coords, const Stage::Vectortypes::TVector4p &VertexData, const Stage::Vectortypes::TVector4f &Weight, PGLPointer OutData);

typedef void __stdcall (*TGLUTessBeginDataProc)(unsigned AType, void * UserData);

typedef void __stdcall (*TGLUTessEdgeFlagDataProc)(TGLboolean Flag, void * UserData);

typedef void __stdcall (*TGLUTessVertexDataProc)(void * VertexData, void * UserData);

typedef void __stdcall (*TGLUTessEndDataProc)(void * UserData);

typedef void __stdcall (*TGLUTessErrorDataProc)(unsigned ErrNo, void * UserData);

typedef void __stdcall (*TGLUTessCombineDataProc)(const Stage::Vectortypes::TVector3d &Coords, const Stage::Vectortypes::TVector4p &VertexData, const Stage::Vectortypes::TVector4f &Weight, PGLPointer OutData, void * UserData);

typedef void __stdcall (*TGLUNurbsErrorProc)(unsigned ErrorCode);

typedef void __stdcall (*PFNGLBLENDCOLORPROC)(float red, float green, float blue, float alpha);

typedef void __stdcall (*PFNGLBLENDEQUATIONPROC)(unsigned mode);

typedef void __stdcall (*PFNGLDRAWRANGEELEMENTSPROC)(unsigned mode, unsigned Astart, unsigned Aend, TGLsizei count, unsigned Atype, void * indices);

typedef void __stdcall (*PFNGLTEXIMAGE3DPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, unsigned format, unsigned Atype, void * pixels);

typedef void __stdcall (*PFNGLTEXSUBIMAGE3DPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, unsigned Atype, void * pixels);

typedef void __stdcall (*PFNGLCOPYTEXSUBIMAGE3DPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLCOLORTABLEPROC)(unsigned target, unsigned internalformat, TGLsizei width, unsigned format, unsigned Atype, void * table);

typedef void __stdcall (*PFNGLCOLORTABLEPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLCOLORTABLEPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLCOPYCOLORTABLEPROC)(unsigned target, unsigned internalformat, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLGETCOLORTABLEPROC)(unsigned target, unsigned format, unsigned Atype, void * table);

typedef void __stdcall (*PFNGLGETCOLORTABLEPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETCOLORTABLEPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLCOLORSUBTABLEPROC)(unsigned target, TGLsizei start, TGLsizei count, unsigned format, unsigned Atype, void * data);

typedef void __stdcall (*PFNGLCOPYCOLORSUBTABLEPROC)(unsigned target, TGLsizei start, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLCONVOLUTIONFILTER1DPROC)(unsigned target, unsigned internalformat, TGLsizei width, unsigned format, unsigned Atype, void * image);

typedef void __stdcall (*PFNGLCONVOLUTIONFILTER2DPROC)(unsigned target, unsigned internalformat, TGLsizei width, TGLsizei height, unsigned format, unsigned Atype, void * image);

typedef void __stdcall (*PFNGLCONVOLUTIONPARAMETERFPROC)(unsigned target, unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLCONVOLUTIONPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLCONVOLUTIONPARAMETERIPROC)(unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLCONVOLUTIONPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLCOPYCONVOLUTIONFILTER1DPROC)(unsigned target, unsigned internalformat, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLCOPYCONVOLUTIONFILTER2DPROC)(unsigned target, unsigned internalformat, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETCONVOLUTIONFILTERPROC)(unsigned target, unsigned internalformat, unsigned Atype, void * image);

typedef void __stdcall (*PFNGLGETCONVOLUTIONPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETCONVOLUTIONPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETSEPARABLEFILTERPROC)(unsigned target, unsigned format, unsigned Atype, void * row, void * column, void * span);

typedef void __stdcall (*PFNGLSEPARABLEFILTER2DPROC)(unsigned target, unsigned internalformat, TGLsizei width, TGLsizei height, unsigned format, unsigned Atype, void * row, void * column);

typedef void __stdcall (*PFNGLGETHISTOGRAMPROC)(unsigned target, TGLboolean reset, unsigned format, unsigned Atype, void * values);

typedef void __stdcall (*PFNGLGETHISTOGRAMPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETHISTOGRAMPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETMINMAXPROC)(unsigned target, TGLboolean reset, unsigned format, unsigned Atype, void * values);

typedef void __stdcall (*PFNGLGETMINMAXPARAMETERFVPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETMINMAXPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLHISTOGRAMPROC)(unsigned target, TGLsizei width, unsigned internalformat, TGLboolean sink);

typedef void __stdcall (*PFNGLMINMAXPROC)(unsigned target, unsigned internalformat, TGLboolean sink);

typedef void __stdcall (*PFNGLRESETHISTOGRAMPROC)(unsigned target);

typedef void __stdcall (*PFNGLRESETMINMAXPROC)(unsigned target);

typedef void __stdcall (*PFNGLACTIVETEXTUREPROC)(unsigned texture);

typedef void __stdcall (*PFNGLSAMPLECOVERAGEPROC)(float Value, TGLboolean invert);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE3DPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLsizei Height, TGLsizei depth, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE2DPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLsizei Height, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE1DPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLGETCOMPRESSEDTEXIMAGEPROC)(unsigned target, TGLint level, void * img);

typedef void __stdcall (*PFNGLCLIENTACTIVETEXTUREPROC)(unsigned texture);

typedef void __stdcall (*PFNGLMULTITEXCOORD1DPROC)(unsigned target, TGLdouble s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1DVPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1FPROC)(unsigned target, TGLfloat s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1FVPROC)(unsigned target, TGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1IPROC)(unsigned target, TGLint s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1IVPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1SPROC)(unsigned target, TGLshort s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1SVPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2DPROC)(unsigned target, TGLdouble s, TGLdouble t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2DVPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2FPROC)(unsigned target, TGLfloat s, TGLfloat t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2FVPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2IPROC)(unsigned target, TGLint s, TGLint t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2IVPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2SPROC)(unsigned target, TGLshort s, TGLshort t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2SVPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3DPROC)(unsigned target, TGLdouble s, TGLdouble t, TGLdouble r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3DVPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3FPROC)(unsigned target, TGLfloat s, TGLfloat t, TGLfloat r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3FVPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3IPROC)(unsigned target, TGLint s, TGLint t, TGLint r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3IVPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3SPROC)(unsigned target, TGLshort s, TGLshort t, TGLshort r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3SVPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4DPROC)(unsigned target, TGLdouble s, TGLdouble t, TGLdouble r, TGLdouble q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4DVPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4FPROC)(unsigned target, TGLfloat s, TGLfloat t, TGLfloat r, TGLfloat q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4FVPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4IPROC)(unsigned target, TGLint s, TGLint t, TGLint r, TGLint q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4IVPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4SPROC)(unsigned target, TGLshort s, TGLshort t, TGLshort r, TGLshort q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4SVPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLLOADTRANSPOSEMATRIXFPROC)(PGLfloat m);

typedef void __stdcall (*PFNGLLOADTRANSPOSEMATRIXDPROC)(PGLdouble m);

typedef void __stdcall (*PFNGLMULTTRANSPOSEMATRIXFPROC)(PGLfloat m);

typedef void __stdcall (*PFNGLMULTTRANSPOSEMATRIXDPROC)(PGLdouble m);

typedef void __stdcall (*PFNGLBLENDFUNCSEPARATEPROC)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);

typedef void __stdcall (*PFNGLMULTIDRAWARRAYSPROC)(unsigned mode, PGLint First, PGLsizei Count, TGLsizei primcount);

typedef void __stdcall (*PFNGLMULTIDRAWELEMENTSPROC)(unsigned mode, PGLsizei Count, unsigned AType, void *indices, TGLsizei primcount);

typedef void __stdcall (*PFNGLPOINTPARAMETERFPROC)(unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLPOINTPARAMETERFVPROC)(unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLPOINTPARAMETERIPROC)(unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLPOINTPARAMETERIVPROC)(unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLFOGCOORDFPROC)(TGLfloat coord);

typedef void __stdcall (*PFNGLFOGCOORDFVPROC)(PGLfloat coord);

typedef void __stdcall (*PFNGLFOGCOORDDPROC)(TGLdouble coord);

typedef void __stdcall (*PFNGLFOGCOORDDVPROC)(PGLdouble coord);

typedef void __stdcall (*PFNGLFOGCOORDPOINTERPROC)(unsigned AType, TGLsizei stride, void * p);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3BPROC)(TGLbyte red, TGLbyte green, TGLbyte blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3BVPROC)(PGLbyte v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3DPROC)(TGLdouble red, TGLdouble green, TGLdouble blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3DVPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3FPROC)(TGLfloat red, TGLfloat green, TGLfloat blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3FVPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3IPROC)(TGLint red, TGLint green, TGLint blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3IVPROC)(PGLint v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3SPROC)(TGLshort red, TGLshort green, TGLshort blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3SVPROC)(PGLshort v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UBPROC)(TGLubyte red, TGLubyte green, TGLubyte blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UBVPROC)(PGLubyte v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UIPROC)(unsigned red, unsigned green, unsigned blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UIVPROC)(PGLuint v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3USPROC)(TGLushort red, TGLushort green, TGLushort blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3USVPROC)(PGLushort v);

typedef void __stdcall (*PFNGLSECONDARYCOLORPOINTERPROC)(TGLint Size, unsigned Atype, TGLsizei stride, void * p);

typedef void __stdcall (*PFNGLWINDOWPOS2DPROC)(TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLWINDOWPOS2DVPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLWINDOWPOS2FPROC)(TGLfloat x, TGLfloat y);

typedef void __stdcall (*PFNGLWINDOWPOS2FVPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLWINDOWPOS2IPROC)(TGLint x, TGLint y);

typedef void __stdcall (*PFNGLWINDOWPOS2IVPROC)(PGLint v);

typedef void __stdcall (*PFNGLWINDOWPOS2SPROC)(TGLshort x, TGLshort y);

typedef void __stdcall (*PFNGLWINDOWPOS2SVPROC)(PGLshort v);

typedef void __stdcall (*PFNGLWINDOWPOS3DPROC)(TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLWINDOWPOS3DVPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLWINDOWPOS3FPROC)(TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLWINDOWPOS3FVPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLWINDOWPOS3IPROC)(TGLint x, TGLint y, TGLint z);

typedef void __stdcall (*PFNGLWINDOWPOS3IVPROC)(PGLint v);

typedef void __stdcall (*PFNGLWINDOWPOS3SPROC)(TGLshort x, TGLshort y, TGLshort z);

typedef void __stdcall (*PFNGLWINDOWPOS3SVPROC)(PGLshort v);

typedef void __stdcall (*PFNGLGENQUERIESPROC)(TGLsizei n, PGLuint ids);

typedef void __stdcall (*PFNGLDELETEQUERIESPROC)(TGLsizei n, const PGLuint ids);

typedef TGLboolean __stdcall (*PFNGLISQUERYPROC)(unsigned id);

typedef void __stdcall (*PFNGLBEGINQUERYPROC)(unsigned target, unsigned id);

typedef void __stdcall (*PFNGLENDQUERYPROC)(unsigned target);

typedef void __stdcall (*PFNGLGETQUERYIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTIVPROC)(unsigned id, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTUIVPROC)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLBINDBUFFERPROC)(unsigned target, unsigned buffer);

typedef void __stdcall (*PFNGLDELETEBUFFERSPROC)(TGLsizei n, const PGLuint buffers);

typedef void __stdcall (*PFNGLGENBUFFERSPROC)(TGLsizei n, PGLuint buffers);

typedef TGLboolean __stdcall (*PFNGLISBUFFERPROC)(unsigned buffer);

typedef void __stdcall (*PFNGLBUFFERDATAPROC)(unsigned target, TGLsizei size, const void * data, unsigned usage);

typedef void __stdcall (*PFNGLBUFFERSUBDATAPROC)(unsigned target, unsigned offset, TGLsizei size, const void * data);

typedef void __stdcall (*PFNGLGETBUFFERSUBDATAPROC)(unsigned target, unsigned offset, TGLsizei size, void * data);

typedef void * __stdcall (*PFNGLMAPBUFFERPROC)(unsigned target, unsigned access);

typedef TGLboolean __stdcall (*PFNGLUNMAPBUFFERPROC)(unsigned target);

typedef void __stdcall (*PFNGLGETBUFFERPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETBUFFERPOINTERVPROC)(unsigned target, unsigned pname, void * params);

typedef void __stdcall (*PFNGLBLENDEQUATIONSEPARATEPROC)(unsigned modeRGB, unsigned modeAlpha);

typedef void __stdcall (*PFNGLDRAWBUFFERSPROC)(TGLsizei n, const System::PCardinal bufs);

typedef void __stdcall (*PFNGLSTENCILOPSEPARATEPROC)(unsigned face, unsigned sfail, unsigned dpfail, unsigned dppass);

typedef void __stdcall (*PFNGLSTENCILFUNCSEPARATEPROC)(unsigned face, unsigned func, TGLint ref, unsigned mask);

typedef void __stdcall (*PFNGLSTENCILMASKSEPARATEPROC)(unsigned face, unsigned mask);

typedef void __stdcall (*PFNGLATTACHSHADERPROC)(unsigned _program, unsigned shader);

typedef void __stdcall (*PFNGLBINDATTRIBLOCATIONPROC)(unsigned _program, unsigned index, const char * name);

typedef void __stdcall (*PFNGLCOMPILESHADERPROC)(unsigned shader);

typedef unsigned __stdcall (*PFNGLCREATEPROGRAMPROC)(void);

typedef unsigned __stdcall (*PFNGLCREATESHADERPROC)(unsigned _type);

typedef void __stdcall (*PFNGLDELETEPROGRAMPROC)(unsigned _program);

typedef void __stdcall (*PFNGLDELETESHADERPROC)(unsigned shader);

typedef void __stdcall (*PFNGLDETACHSHADERPROC)(unsigned _program, unsigned shader);

typedef void __stdcall (*PFNGLDISABLEVERTEXATTRIBARRAYPROC)(unsigned index);

typedef void __stdcall (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(unsigned index);

typedef void __stdcall (*PFNGLGETACTIVEATTRIBPROC)(unsigned _program, unsigned index, TGLsizei bufSize, PGLsizei length, PGLint size, System::PCardinal _type, char * name);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMPROC)(unsigned _program, unsigned index, TGLsizei bufSize, PGLsizei length, PGLint size, System::PCardinal _type, char * name);

typedef void __stdcall (*PFNGLGETATTACHEDSHADERSPROC)(unsigned _program, TGLsizei maxCount, PGLsizei count, PGLuint obj);

typedef TGLint __stdcall (*PFNGLGETATTRIBLOCATIONPROC)(unsigned _program, const char * name);

typedef void __stdcall (*PFNGLGETPROGRAMIVPROC)(unsigned _program, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETPROGRAMINFOLOGPROC)(unsigned _program, TGLsizei bufSize, PGLsizei length, char * infoLog);

typedef void __stdcall (*PFNGLGETSHADERIVPROC)(unsigned shader, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETSHADERINFOLOGPROC)(unsigned shader, TGLsizei bufSize, PGLsizei length, char * infoLog);

typedef void __stdcall (*PFNGLGETSHADERSOURCEPROC)(unsigned shader, TGLsizei bufSize, PGLsizei length, char * source);

typedef TGLint __stdcall (*PFNGLGETUNIFORMLOCATIONPROC)(unsigned _program, const char * name);

typedef void __stdcall (*PFNGLGETUNIFORMFVPROC)(unsigned _program, TGLint location, PGLfloat params);

typedef void __stdcall (*PFNGLGETUNIFORMIVPROC)(unsigned _program, TGLint location, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBDVPROC)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBFVPROC)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIVPROC)(unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBPOINTERVPROC)(unsigned index, unsigned pname, void * _pointer);

typedef TGLboolean __stdcall (*PFNGLISPROGRAMPROC)(unsigned _program);

typedef TGLboolean __stdcall (*PFNGLISSHADERPROC)(unsigned shader);

typedef void __stdcall (*PFNGLLINKPROGRAMPROC)(unsigned _program);

typedef void __stdcall (*PFNGLSHADERSOURCEPROC)(unsigned shader, TGLsizei count, const PGLPCharArray _string, const PGLint length);

typedef void __stdcall (*PFNGLUSEPROGRAMPROC)(unsigned _program);

typedef void __stdcall (*PFNGLUNIFORM1FPROC)(TGLint location, TGLfloat v0);

typedef void __stdcall (*PFNGLUNIFORM2FPROC)(TGLint location, TGLfloat v0, TGLfloat v1);

typedef void __stdcall (*PFNGLUNIFORM3FPROC)(TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2);

typedef void __stdcall (*PFNGLUNIFORM4FPROC)(TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2, TGLfloat v3);

typedef void __stdcall (*PFNGLUNIFORM1IPROC)(TGLint location, TGLint v0);

typedef void __stdcall (*PFNGLUNIFORM2IPROC)(TGLint location, TGLint v0, TGLint v1);

typedef void __stdcall (*PFNGLUNIFORM3IPROC)(TGLint location, TGLint v0, TGLint v1, TGLint v2);

typedef void __stdcall (*PFNGLUNIFORM4IPROC)(TGLint location, TGLint v0, TGLint v1, TGLint v2, TGLint v3);

typedef void __stdcall (*PFNGLUNIFORM1FVPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM2FVPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM3FVPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM4FVPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM1IVPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM2IVPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM3IVPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM4IVPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLVALIDATEPROGRAMPROC)(unsigned _program);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DPROC)(unsigned index, TGLdouble x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FPROC)(unsigned index, TGLfloat x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SPROC)(unsigned index, TGLshort x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DPROC)(unsigned index, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FPROC)(unsigned index, TGLfloat x, TGLfloat y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SPROC)(unsigned index, TGLshort x, TGLshort y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SPROC)(unsigned index, TGLshort x, TGLshort y, TGLshort z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NBVPROC)(unsigned index, PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NIVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NSVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUBPROC)(unsigned index, TGLubyte x, TGLubyte y, TGLubyte z, TGLubyte w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUBVPROC)(unsigned index, PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUSVPROC)(unsigned index, PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4BVPROC)(unsigned index, PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4IVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SPROC)(unsigned index, TGLshort x, TGLshort y, TGLshort z, TGLshort w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4UBVPROC)(unsigned index, PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4UIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4USVPROC)(unsigned index, PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBPOINTERPROC)(unsigned index, TGLint size, unsigned _type, TGLboolean normalized, TGLsizei stride, void * _pointer);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2X3FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3X2FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2X4FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4X2FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3X4FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4X3FVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1IPROC)(unsigned index, TGLint x);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2IPROC)(unsigned index, TGLint x, TGLint y);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3IPROC)(unsigned index, TGLint x, TGLint y, TGLint z);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4IPROC)(unsigned index, TGLint x, TGLint y, TGLint z, TGLint w);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1UIPROC)(unsigned index, unsigned x);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2UIPROC)(unsigned index, unsigned x, unsigned y);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3UIPROC)(unsigned index, unsigned x, unsigned y, unsigned z);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UIPROC)(unsigned index, unsigned x, unsigned y, unsigned z, unsigned w);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1IVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2IVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3IVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4IVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1UIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2UIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3UIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UIVPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4BVPROC)(unsigned index, PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4SVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UBVPROC)(unsigned index, PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4USVPROC)(unsigned index, PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBIPOINTERPROC)(unsigned index, TGLint size, unsigned _type, TGLsizei stride, void * _pointer);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIIVPROC)(unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIUIVPROC)(unsigned index, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLUNIFORM1UIPROC)(TGLint location, unsigned v0);

typedef void __stdcall (*PFNGLUNIFORM2UIPROC)(TGLint location, unsigned v0, unsigned v1);

typedef void __stdcall (*PFNGLUNIFORM3UIPROC)(TGLint location, unsigned v0, unsigned v1, unsigned v2);

typedef void __stdcall (*PFNGLUNIFORM4UIPROC)(TGLint location, unsigned v0, unsigned v1, unsigned v2, unsigned v3);

typedef void __stdcall (*PFNGLUNIFORM1UIVPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM2UIVPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM3UIVPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM4UIVPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLGETUNIFORMUIVPROC)(unsigned _program, TGLint location, PGLuint params);

typedef void __stdcall (*PFNGLBINDFRAGDATALOCATIONPROC)(unsigned _program, unsigned colorNumber, char * name);

typedef TGLint __stdcall (*PFNGLGETFRAGDATALOCATIONPROC)(unsigned _program, char * name);

typedef void __stdcall (*PFNGLBEGINCONDITIONALRENDERPROC)(unsigned id, unsigned mode);

typedef void __stdcall (*PFNGLENDCONDITIONALRENDERPROC)(void);

typedef void __stdcall (*PFNGLCLAMPCOLORPROC)(unsigned target, unsigned clamp);

typedef void __stdcall (*PFNGLTEXPARAMETERIIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLTEXPARAMETERIUIVPROC)(unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLGETTEXPARAMETERIIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETTEXPARAMETERIUIVPROC)(unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLCOLORMASKIPROC)(unsigned index, TGLboolean r, TGLboolean g, TGLboolean b, TGLboolean a);

typedef void __stdcall (*PFNGLGETBOOLEANI_VPROC)(unsigned target, unsigned index, PGLboolean data);

typedef void __stdcall (*PFNGLGETINTEGERI_VPROC)(unsigned target, unsigned index, PGLint data);

typedef void __stdcall (*PFNGLENABLEIPROC)(unsigned target, unsigned index);

typedef void __stdcall (*PFNGLDISABLEIPROC)(unsigned target, unsigned index);

typedef TGLboolean __stdcall (*PFNGLISENABLEDIPROC)(unsigned target, unsigned index);

typedef void __stdcall (*PFNGLBINDBUFFERRANGEPROC)(unsigned target, unsigned index, unsigned buffer, TGLintptr offset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLBINDBUFFERBASEPROC)(unsigned target, unsigned index, unsigned buffer);

typedef void __stdcall (*PFNGLBEGINTRANSFORMFEEDBACKPROC)(unsigned primitiveMode);

typedef void __stdcall (*PFNGLENDTRANSFORMFEEDBACKPROC)(void);

typedef void __stdcall (*PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(unsigned _program, TGLsizei count, const PGLPCharArray varyings, unsigned bufferMode);

typedef void __stdcall (*PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(unsigned _program, unsigned index, TGLsizei bufSize, PGLsizei length, PGLsizei size, System::PCardinal _type, char * name);

typedef void __stdcall (*PFNGLCLEARBUFFERIVPROC)(unsigned buffer, TGLint drawbuffer, PGLint value);

typedef void __stdcall (*PFNGLCLEARBUFFERUIVPROC)(unsigned buffer, TGLint drawbuffer, PGLuint value);

typedef void __stdcall (*PFNGLCLEARBUFFERFVPROC)(unsigned buffer, TGLint drawbuffer, PGLfloat value);

typedef void __stdcall (*PFNGLCLEARBUFFERFIPROC)(unsigned buffer, TGLint drawbuffer, TGLfloat depth, TGLint stencil);

typedef char * __stdcall (*PFNGLGETSTRINGIPROC)(unsigned name, unsigned index);

typedef void __stdcall (*PFNGLDRAWARRAYSINSTANCEDPROC)(unsigned mode, TGLint first, TGLsizei count, TGLsizei primcount);

typedef void __stdcall (*PFNGLDRAWELEMENTSINSTANCEDPROC)(unsigned mode, TGLsizei count, unsigned _type, PGLvoid indices, TGLsizei primcount);

typedef void __stdcall (*PFNGLTEXBUFFERPROC)(unsigned target, unsigned internalformat, unsigned buffer);

typedef void __stdcall (*PFNGLPRIMITIVERESTARTINDEXPROC)(unsigned index);

typedef void __stdcall (*PFNGLGETINTEGER64I_VPROC)(unsigned target, unsigned index, PGLint64 data);

typedef void __stdcall (*PFNGLGETBUFFERPARAMETERI64VPROC)(unsigned target, unsigned pname, PGLint64 params);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTUREPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLVERTEXATTRIBDIVISORPROC)(unsigned index, unsigned divisor);

typedef void __stdcall (*PFNGLBLENDEQUATIONIPROC)(unsigned buf, unsigned mode);

typedef void __stdcall (*PFNGLBLENDEQUATIONSEPARATEIPROC)(unsigned buf, unsigned modeRGB, unsigned modeAlpha);

typedef void __stdcall (*PFNGLBLENDFUNCIPROC)(unsigned buf, unsigned src, unsigned dst);

typedef void __stdcall (*PFNGLBLENDFUNCSEPARATEIPROC)(unsigned buf, unsigned srcRGB, unsigned dstRGB, unsigned srcAlpha, unsigned dstAlpha);

typedef void __stdcall (*PFNGLMINSAMPLESHADINGPROC)(float value);

typedef void __stdcall (*PFNGLUNURBSCALLBACKDATAEXTPROC)(PGLUNurbs nurb, void * userData);

typedef PGLUNurbs __stdcall (*PFNGLUNEWNURBSTESSELLATOREXTPROC)(void);

typedef void __stdcall (*PFNGLUDELETENURBSTESSELLATOREXTPROC)(PGLUNurbs nurb);

typedef int __stdcall (*PFNWGLCREATEBUFFERREGIONARBPROC)(HDC DC, int iLayerPlane, unsigned uType);

typedef void __stdcall (*PFNWGLDELETEBUFFERREGIONARBPROC)(int hRegion);

typedef System::LongBool __stdcall (*PFNWGLSAVEBUFFERREGIONARBPROC)(int hRegion, int x, int y, int width, int height);

typedef System::LongBool __stdcall (*PFNWGLRESTOREBUFFERREGIONARBPROC)(int hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

typedef char * __stdcall (*PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC DC);

typedef System::LongBool __stdcall (*PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC DC, int iPixelFormat, int iLayerPlane, unsigned nAttributes, const PGLint piAttributes, PGLint piValues);

typedef System::LongBool __stdcall (*PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC DC, int iPixelFormat, int iLayerPlane, unsigned nAttributes, const PGLint piAttributes, PGLfloat piValues);

typedef System::LongBool __stdcall (*PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC DC, const PGLint piAttribIList, const PGLfloat pfAttribFList, unsigned nMaxFormats, PGLint piFormats, System::PCardinal nNumFormats);

typedef System::LongBool __stdcall (*PFNWGLMAKECONTEXTCURRENTARBPROC)(HDC hDrawDC, HDC hReadDC, HGLRC _hglrc);

typedef HDC __stdcall (*PFNWGLGETCURRENTREADDCARBPROC)(void);

typedef HPBUFFERARB __stdcall (*PFNWGLCREATEPBUFFERARBPROC)(HDC DC, TGLint iPixelFormat, TGLint iWidth, TGLint iHeight, const PGLint piAttribList);

typedef HDC __stdcall (*PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer);

typedef int __stdcall (*PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer, HDC DC);

typedef System::LongBool __stdcall (*PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB hPbuffer);

typedef System::LongBool __stdcall (*PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB hPbuffer, int iAttribute, PGLint piValue);

typedef System::LongBool __stdcall (*PFNWGLBINDTEXIMAGEARBPROC)(HPBUFFERARB hPbuffer, int iBuffer);

typedef System::LongBool __stdcall (*PFNWGLRELEASETEXIMAGEARBPROC)(HPBUFFERARB hpBuffer, int iBuffer);

typedef System::LongBool __stdcall (*PFNWGLSETPBUFFERATTRIBARBPROC)(HPBUFFERARB hpBuffer, const PGLint piAttribList);

typedef HGLRC __stdcall (*PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC DC, HGLRC hShareContext, PGLint attribList);

typedef System::LongBool __stdcall (*PFNWGLSWAPINTERVALEXTPROC)(int interval);

typedef int __stdcall (*PFNWGLGETSWAPINTERVALEXTPROC)(void);

typedef bool __stdcall (*PFNWGLENUMGPUSNVPROC)(unsigned iGpuIndex, HGPUNV &hGpu);

typedef bool __stdcall (*PFNWGLENUMGPUDEVICESNVPROC)(HGPUNV hGpu, unsigned iDeviceIndex, PGPUDEVICE lpGpuDevice);

typedef HDC __stdcall (*PFNWGLCREATEAFFINITYDCNVPROC)(PHGPUNV hGpuList);

typedef bool __stdcall (*PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)(HDC hAffinityDC, unsigned iGpuIndex, HGPUNV &hGpu);

typedef bool __stdcall (*PFNWGLDELETEDCNVPROC)(HDC hdc);

typedef System::LongBool __stdcall (*PFNWGLDXSETRESOURCESHAREHANDLEPROC)(void * dxObject, Winapi::Windows::THandle shareHandle);

typedef Winapi::Windows::THandle __stdcall (*PFNWGLDXOPENDEVICEPROC)(void * dxDevice);

typedef System::LongBool __stdcall (*PFNWGLDXCLOSEDEVICEPROC)(Winapi::Windows::THandle hDevice);

typedef Winapi::Windows::THandle __stdcall (*PFNWGLDXREGISTEROBJECTPROC)(Winapi::Windows::THandle hDevice, void * dxObject, unsigned name, unsigned atype, unsigned access);

typedef System::LongBool __stdcall (*PFNWGLDXUNREGISTEROBJECTPROC)(Winapi::Windows::THandle hDevice, Winapi::Windows::THandle hObject);

typedef System::LongBool __stdcall (*PFNWGLDXOBJECTACCESSPROC)(Winapi::Windows::THandle hObject, unsigned access);

typedef System::LongBool __stdcall (*PFNWGLDXLOCKOBJECTSPROC)(Winapi::Windows::THandle hDevice, TGLint count, Winapi::Windows::PHandle hObjects);

typedef System::LongBool __stdcall (*PFNWGLDXUNLOCKOBJECTSNVPROC)(Winapi::Windows::THandle hDevice, TGLint count, Winapi::Windows::PHandle hObjects);

typedef void __stdcall (*PFNGLSAMPLEPASSARBPROC)(unsigned pass);

typedef void __stdcall (*PFNGLACTIVETEXTUREARBPROC)(unsigned target);

typedef void __stdcall (*PFNGLCLIENTACTIVETEXTUREARBPROC)(unsigned target);

typedef void __stdcall (*PFNGLMULTITEXCOORD1DARBPROC)(unsigned target, TGLdouble s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1DVARBPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1FARBPROC)(unsigned target, TGLfloat s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1FVARBPROC)(unsigned target, TGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1IARBPROC)(unsigned target, TGLint s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1IVARBPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD1SARBPROC)(unsigned target, TGLshort s);

typedef void __stdcall (*PFNGLMULTITEXCOORD1SVARBPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2DARBPROC)(unsigned target, TGLdouble s, TGLdouble t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2DVARBPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2FARBPROC)(unsigned target, TGLfloat s, TGLfloat t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2FVARBPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2IARBPROC)(unsigned target, TGLint s, TGLint t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2IVARBPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD2SARBPROC)(unsigned target, TGLshort s, TGLshort t);

typedef void __stdcall (*PFNGLMULTITEXCOORD2SVARBPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3DARBPROC)(unsigned target, TGLdouble s, TGLdouble t, TGLdouble r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3DVARBPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3FARBPROC)(unsigned target, TGLfloat s, TGLfloat t, TGLfloat r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3FVARBPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3IARBPROC)(unsigned target, TGLint s, TGLint t, TGLint r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3IVARBPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD3SARBPROC)(unsigned target, TGLshort s, TGLshort t, TGLshort r);

typedef void __stdcall (*PFNGLMULTITEXCOORD3SVARBPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4DARBPROC)(unsigned target, TGLdouble s, TGLdouble t, TGLdouble r, TGLdouble q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4DVARBPROC)(unsigned target, PGLdouble v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4FARBPROC)(unsigned target, TGLfloat s, TGLfloat t, TGLfloat r, TGLfloat q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4FVARBPROC)(unsigned target, PGLfloat v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4IARBPROC)(unsigned target, TGLint s, TGLint t, TGLint r, TGLint q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4IVARBPROC)(unsigned target, PGLint v);

typedef void __stdcall (*PFNGLMULTITEXCOORD4SARBPROC)(unsigned target, TGLshort s, TGLshort t, TGLshort r, TGLshort q);

typedef void __stdcall (*PFNGLMULTITEXCOORD4SVARBPROC)(unsigned target, PGLshort v);

typedef void __stdcall (*PFNGLLOADTRANSPOSEMATRIXFARBPROC)(PGLfloat m);

typedef void __stdcall (*PFNGLLOADTRANSPOSEMATRIXDARBPROC)(PGLdouble m);

typedef void __stdcall (*PFNGLMULTTRANSPOSEMATRIXFARBPROC)(PGLfloat m);

typedef void __stdcall (*PFNGLMULTTRANSPOSEMATRIXDARBPROC)(PGLdouble m);

typedef void __stdcall (*PFNGLSAMPLECOVERAGEARBPROC)(float Value, TGLboolean invert);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLsizei Height, TGLsizei depth, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLsizei Height, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei Width, TGLint border, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned Format, TGLsizei imageSize, void * data);

typedef void __stdcall (*PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(unsigned target, TGLint level, void * img);

typedef void __stdcall (*PFNGLPOINTPARAMETERFARBPROC)(unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLPOINTPARAMETERFVARBPROC)(unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLWEIGHTBVARBPROC)(TGLint size, PGLbyte weights);

typedef void __stdcall (*PFNGLWEIGHTSVARBPROC)(TGLint size, PGLshort weights);

typedef void __stdcall (*PFNGLWEIGHTIVARBPROC)(TGLint size, PGLint weights);

typedef void __stdcall (*PFNGLWEIGHTFVARBPROC)(TGLint size, PGLfloat weights);

typedef void __stdcall (*PFNGLWEIGHTDVARBPROC)(TGLint size, PGLdouble weights);

typedef void __stdcall (*PFNGLWEIGHTUBVARBPROC)(TGLint size, PGLubyte weights);

typedef void __stdcall (*PFNGLWEIGHTUSVARBPROC)(TGLint size, PGLushort weights);

typedef void __stdcall (*PFNGLWEIGHTUIVARBPROC)(TGLint size, PGLuint weights);

typedef void __stdcall (*PFNGLWEIGHTPOINTERARBPROC)(TGLint size, unsigned _type, TGLsizei stride, void * _pointer);

typedef void __stdcall (*PFNGLVERTEXBLENDARBPROC)(TGLint count);

typedef void __stdcall (*PFNGLCURRENTPALETTEMATRIXARBPROC)(TGLint index);

typedef void __stdcall (*PFNGLMATRIXINDEXUBVARBPROC)(TGLint size, PGLubyte indices);

typedef void __stdcall (*PFNGLMATRIXINDEXUSVARBPROC)(TGLint size, PGLushort indices);

typedef void __stdcall (*PFNGLMATRIXINDEXUIVARBPROC)(TGLint size, PGLuint indices);

typedef void __stdcall (*PFNGLMATRIXINDEXPOINTERARBPROC)(TGLint size, unsigned _type, TGLsizei stride, void * _pointer);

typedef void __stdcall (*PFNGLWINDOWPOS2DARBPROC)(TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLWINDOWPOS2DVARBPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLWINDOWPOS2FARBPROC)(TGLfloat x, TGLfloat y);

typedef void __stdcall (*PFNGLWINDOWPOS2FVARBPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLWINDOWPOS2IARBPROC)(TGLint x, TGLint y);

typedef void __stdcall (*PFNGLWINDOWPOS2IVARBPROC)(PGLint v);

typedef void __stdcall (*PFNGLWINDOWPOS2SARBPROC)(TGLshort x, TGLshort y);

typedef void __stdcall (*PFNGLWINDOWPOS2SVARBPROC)(PGLshort v);

typedef void __stdcall (*PFNGLWINDOWPOS3DARBPROC)(TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLWINDOWPOS3DVARBPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLWINDOWPOS3FARBPROC)(TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLWINDOWPOS3FVARBPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLWINDOWPOS3IARBPROC)(TGLint x, TGLint y, TGLint z);

typedef void __stdcall (*PFNGLWINDOWPOS3IVARBPROC)(PGLint v);

typedef void __stdcall (*PFNGLWINDOWPOS3SARBPROC)(TGLshort x, TGLshort y, TGLshort z);

typedef void __stdcall (*PFNGLWINDOWPOS3SVARBPROC)(PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DARBPROC)(unsigned index, TGLdouble x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DVARBPROC)(unsigned index, const PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FARBPROC)(unsigned index, TGLfloat x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FVARBPROC)(unsigned index, const PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SARBPROC)(unsigned index, TGLshort x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SVARBPROC)(unsigned index, const PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DARBPROC)(unsigned index, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DVARBPROC)(unsigned index, const PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FARBPROC)(unsigned index, TGLfloat x, TGLfloat y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FVARBPROC)(unsigned index, const PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SARBPROC)(unsigned index, TGLshort x, TGLshort y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SVARBPROC)(unsigned index, const PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DARBPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DVARBPROC)(unsigned index, const PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FARBPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FVARBPROC)(unsigned index, const PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SARBPROC)(unsigned index, TGLshort x, TGLshort y, TGLshort z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SVARBPROC)(unsigned index, const PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NBVARBPROC)(unsigned index, const PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NIVARBPROC)(unsigned index, const PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NSVARBPROC)(unsigned index, const PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUBARBPROC)(unsigned index, TGLubyte x, TGLubyte y, TGLubyte z, TGLubyte w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUBVARBPROC)(unsigned index, const PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUIVARBPROC)(unsigned index, const PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4NUSVARBPROC)(unsigned index, const PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4BVARBPROC)(unsigned index, const PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DARBPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DVARBPROC)(unsigned index, const PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FARBPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FVARBPROC)(unsigned index, const PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4IVARBPROC)(unsigned index, const PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SARBPROC)(unsigned index, TGLshort x, TGLshort y, TGLshort z, TGLshort w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SVARBPROC)(unsigned index, const PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4UBVARBPROC)(unsigned index, const PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4UIVARBPROC)(unsigned index, const PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4USVARBPROC)(unsigned index, const PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBPOINTERARBPROC)(unsigned index, TGLint size, unsigned _type, TGLboolean normalized, TGLsizei stride, const void * _pointer);

typedef void __stdcall (*PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(unsigned index);

typedef void __stdcall (*PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(unsigned index);

typedef void __stdcall (*PFNGLPROGRAMSTRINGARBPROC)(unsigned target, unsigned format, TGLsizei len, const void * _string);

typedef void __stdcall (*PFNGLBINDPROGRAMARBPROC)(unsigned target, unsigned _program);

typedef void __stdcall (*PFNGLDELETEPROGRAMSARBPROC)(TGLsizei n, const PGLuint programs);

typedef void __stdcall (*PFNGLGENPROGRAMSARBPROC)(TGLsizei n, PGLuint programs);

typedef void __stdcall (*PFNGLPROGRAMENVPARAMETER4DARBPROC)(unsigned target, unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLPROGRAMENVPARAMETER4DVARBPROC)(unsigned target, unsigned index, const PGLdouble params);

typedef void __stdcall (*PFNGLPROGRAMENVPARAMETER4FARBPROC)(unsigned target, unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLPROGRAMENVPARAMETER4FVARBPROC)(unsigned target, unsigned index, const PGLfloat params);

typedef void __stdcall (*PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(unsigned target, unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(unsigned target, unsigned index, const PGLdouble params);

typedef void __stdcall (*PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(unsigned target, unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(unsigned target, unsigned index, const PGLfloat params);

typedef void __stdcall (*PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(unsigned target, unsigned index, PGLdouble params);

typedef void __stdcall (*PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(unsigned target, unsigned index, PGLfloat params);

typedef void __stdcall (*PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(unsigned target, unsigned index, PGLdouble params);

typedef void __stdcall (*PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(unsigned target, unsigned index, PGLfloat params);

typedef void __stdcall (*PFNGLGETPROGRAMIVARBPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETPROGRAMSTRINGARBPROC)(unsigned target, unsigned pname, void * _string);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBDVARBPROC)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBFVARBPROC)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIVARBPROC)(unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(unsigned index, unsigned pname, void * _pointer);

typedef TGLboolean __stdcall (*PFNGLISPROGRAMARBPROC)(unsigned _program);

typedef void __stdcall (*PFNGLBINDBUFFERARBPROC)(unsigned target, unsigned buffer);

typedef void __stdcall (*PFNGLDELETEBUFFERSARBPROC)(TGLsizei n, const PGLuint buffers);

typedef void __stdcall (*PFNGLGENBUFFERSARBPROC)(TGLsizei n, PGLuint buffers);

typedef TGLboolean __stdcall (*PFNGLISBUFFERARBPROC)(unsigned buffer);

typedef void __stdcall (*PFNGLBUFFERDATAARBPROC)(unsigned target, TGLsizei size, const void * data, unsigned usage);

typedef void __stdcall (*PFNGLBUFFERSUBDATAARBPROC)(unsigned target, unsigned offset, TGLsizei size, const void * data);

typedef void __stdcall (*PFNGLGETBUFFERSUBDATAARBPROC)(unsigned target, unsigned offset, TGLsizei size, void * data);

typedef void * __stdcall (*PFNGLMAPBUFFERARBPROC)(unsigned target, unsigned access);

typedef TGLboolean __stdcall (*PFNGLUNMAPBUFFERARBPROC)(unsigned target);

typedef void __stdcall (*PFNGLGETBUFFERPARAMETERIVARBPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETBUFFERPOINTERVARBPROC)(unsigned target, unsigned pname, void * params);

typedef void __stdcall (*PFNGLGENQUERIESARBPROC)(TGLsizei n, PGLuint ids);

typedef void __stdcall (*PFNGLDELETEQUERIESARBPROC)(TGLsizei n, const PGLuint ids);

typedef TGLboolean __stdcall (*PFNGLISQUERYARBPROC)(unsigned id);

typedef void __stdcall (*PFNGLBEGINQUERYARBPROC)(unsigned target, unsigned id);

typedef void __stdcall (*PFNGLENDQUERYARBPROC)(unsigned target);

typedef void __stdcall (*PFNGLGETQUERYIVARBPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTIVARBPROC)(unsigned id, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTUIVARBPROC)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLDELETEOBJECTARBPROC)(TGLhandleARB obj);

typedef TGLhandleARB __stdcall (*PFNGLGETHANDLEARBPROC)(unsigned pname);

typedef void __stdcall (*PFNGLDETACHOBJECTARBPROC)(TGLhandleARB containerObj, TGLhandleARB attachedObj);

typedef TGLhandleARB __stdcall (*PFNGLCREATESHADEROBJECTARBPROC)(unsigned shaderType);

typedef void __stdcall (*PFNGLSHADERSOURCEARBPROC)(TGLhandleARB shaderObj, TGLsizei count, const PGLPCharArray _string, const PGLint length);

typedef void __stdcall (*PFNGLCOMPILESHADERARBPROC)(TGLhandleARB shaderObj);

typedef TGLhandleARB __stdcall (*PFNGLCREATEPROGRAMOBJECTARBPROC)(void);

typedef void __stdcall (*PFNGLATTACHOBJECTARBPROC)(TGLhandleARB containerObj, TGLhandleARB obj);

typedef void __stdcall (*PFNGLLINKPROGRAMARBPROC)(TGLhandleARB programObj);

typedef void __stdcall (*PFNGLUSEPROGRAMOBJECTARBPROC)(TGLhandleARB programObj);

typedef void __stdcall (*PFNGLVALIDATEPROGRAMARBPROC)(TGLhandleARB programObj);

typedef void __stdcall (*PFNGLUNIFORM1FARBPROC)(TGLint location, TGLfloat v0);

typedef void __stdcall (*PFNGLUNIFORM2FARBPROC)(TGLint location, TGLfloat v0, TGLfloat v1);

typedef void __stdcall (*PFNGLUNIFORM3FARBPROC)(TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2);

typedef void __stdcall (*PFNGLUNIFORM4FARBPROC)(TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2, TGLfloat v3);

typedef void __stdcall (*PFNGLUNIFORM1IARBPROC)(TGLint location, TGLint v0);

typedef void __stdcall (*PFNGLUNIFORM2IARBPROC)(TGLint location, TGLint v0, TGLint v1);

typedef void __stdcall (*PFNGLUNIFORM3IARBPROC)(TGLint location, TGLint v0, TGLint v1, TGLint v2);

typedef void __stdcall (*PFNGLUNIFORM4IARBPROC)(TGLint location, TGLint v0, TGLint v1, TGLint v2, TGLint v3);

typedef void __stdcall (*PFNGLUNIFORM1FVARBPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM2FVARBPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM3FVARBPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM4FVARBPROC)(TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORM1IVARBPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM2IVARBPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM3IVARBPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORM4IVARBPROC)(TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2FVARBPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3FVARBPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4FVARBPROC)(TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLGETOBJECTPARAMETERFVARBPROC)(TGLhandleARB obj, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETOBJECTPARAMETERIVARBPROC)(TGLhandleARB obj, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETINFOLOGARBPROC)(TGLhandleARB obj, TGLsizei maxLength, PGLsizei length, char * infoLog);

typedef void __stdcall (*PFNGLGETATTACHEDOBJECTSARBPROC)(TGLhandleARB containerObj, TGLsizei maxCount, PGLsizei count, PGLhandleARB obj);

typedef TGLint __stdcall (*PFNGLGETUNIFORMLOCATIONARBPROC)(TGLhandleARB programObj, const char * name);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMARBPROC)(TGLhandleARB programObj, unsigned index, TGLsizei maxLength, PGLsizei length, PGLint size, System::PCardinal _type, char * name);

typedef void __stdcall (*PFNGLGETUNIFORMFVARBPROC)(TGLhandleARB programObj, TGLint location, PGLfloat params);

typedef void __stdcall (*PFNGLGETUNIFORMIVARBPROC)(TGLhandleARB programObj, TGLint location, PGLint params);

typedef void __stdcall (*PFNGLGETSHADERSOURCEARBPROC)(TGLhandleARB obj, TGLsizei maxLength, PGLsizei length, char * source);

typedef void __stdcall (*PFNGLBINDATTRIBLOCATIONARBPROC)(TGLhandleARB programObj, unsigned index, const char * name);

typedef void __stdcall (*PFNGLGETACTIVEATTRIBARBPROC)(TGLhandleARB programObj, unsigned index, TGLsizei maxLength, PGLsizei length, PGLint size, System::PCardinal _type, char * name);

typedef TGLint __stdcall (*PFNGLGETATTRIBLOCATIONARBPROC)(TGLhandleARB programObj, const char * name);

typedef void __stdcall (*PFNGLDRAWBUFFERSARBPROC)(TGLsizei n, const System::PCardinal bufs);

typedef void __stdcall (*PFNGLCLAMPCOLORARBPROC)(unsigned target, unsigned clamp);

typedef void __stdcall (*PFNGLDRAWARRAYSINSTANCEDARBPROC)(unsigned mode, TGLint first, TGLsizei count, TGLsizei primcount);

typedef void __stdcall (*PFNGLDRAWELEMENTSINSTANCEDARBPROC)(unsigned mode, TGLsizei count, unsigned _type, PGLvoid indices, TGLsizei primcount);

typedef TGLboolean __stdcall (*PFNGLISRENDERBUFFERPROC)(unsigned renderbuffer);

typedef void __stdcall (*PFNGLBINDRENDERBUFFERPROC)(unsigned target, unsigned renderbuffer);

typedef void __stdcall (*PFNGLDELETERENDERBUFFERSPROC)(TGLsizei n, PGLuint renderbuffers);

typedef void __stdcall (*PFNGLGENRENDERBUFFERSPROC)(TGLsizei n, PGLuint renderbuffers);

typedef void __stdcall (*PFNGLRENDERBUFFERSTORAGEPROC)(unsigned target, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETRENDERBUFFERPARAMETERIVPROC)(unsigned target, unsigned pname, PGLint params);

typedef TGLboolean __stdcall (*PFNGLISFRAMEBUFFERPROC)(unsigned framebuffer);

typedef void __stdcall (*PFNGLBINDFRAMEBUFFERPROC)(unsigned target, unsigned framebuffer);

typedef void __stdcall (*PFNGLDELETEFRAMEBUFFERSPROC)(TGLsizei n, PGLuint framebuffers);

typedef void __stdcall (*PFNGLGENFRAMEBUFFERSPROC)(TGLsizei n, PGLuint framebuffers);

typedef unsigned __stdcall (*PFNGLCHECKFRAMEBUFFERSTATUSPROC)(unsigned target);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE1DPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE2DPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE3DPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level, TGLint layer);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURELAYERPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level, TGLint layer);

typedef void __stdcall (*PFNGLFRAMEBUFFERRENDERBUFFERPROC)(unsigned target, unsigned attachment, unsigned renderbuffertarget, unsigned renderbuffer);

typedef void __stdcall (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(unsigned target, unsigned attachment, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLBLITFRAMEBUFFERPROC)(TGLint srcX0, TGLint srcY0, TGLint srcX1, TGLint srcY1, TGLint dstX0, TGLint dstY0, TGLint dstX1, TGLint dstY1, TGLbitfield mask, unsigned filter);

typedef void __stdcall (*PFNGLGENERATEMIPMAPPROC)(unsigned target);

typedef void __stdcall (*PFNGLPROGRAMPARAMETERIARBPROC)(unsigned _program, unsigned pname, TGLint value);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTUREARBPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level, TGLint layer);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level, unsigned face);

typedef void __stdcall (*PFNGLVERTEXATTRIBDIVISORARBPROC)(unsigned index, unsigned divisor);

typedef void * __stdcall (*PFNGLMAPBUFFERRANGEPROC)(unsigned target, TGLint offset, TGLsizei length, TGLbitfield access);

typedef void __stdcall (*PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(unsigned target, TGLint offset, TGLsizei length);

typedef void __stdcall (*PFNGLTEXBUFFERARBPROC)(unsigned target, unsigned internalformat, unsigned buffer);

typedef void __stdcall (*PFNGLBINDVERTEXARRAYPROC)(unsigned _array);

typedef void __stdcall (*PFNGLDELETEVERTEXARRAYSPROC)(TGLsizei n, PGLuint arrays);

typedef void __stdcall (*PFNGLGENVERTEXARRAYSPROC)(TGLsizei n, PGLuint arrays);

typedef TGLboolean __stdcall (*PFNGLISVERTEXARRAYPROC)(unsigned _array);

typedef void __stdcall (*PFNGLGETUNIFORMINDICESPROC)(unsigned _program, TGLsizei uniformCount, PGLPCharArray uniformNames, PGLuint uniformIndices);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMSIVPROC)(unsigned _program, TGLsizei uniformCount, PGLuint uniformIndices, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMNAMEPROC)(unsigned _program, unsigned uniformIndex, TGLsizei bufSize, PGLsizei length, char * uniformName);

typedef unsigned __stdcall (*PFNGLGETUNIFORMBLOCKINDEXPROC)(unsigned _program, char * uniformBlockName);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(unsigned _program, unsigned uniformBlockIndex, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(unsigned _program, unsigned uniformBlockIndex, TGLsizei bufSize, PGLsizei length, char * uniformBlockName);

typedef void __stdcall (*PFNGLUNIFORMBLOCKBINDINGPROC)(unsigned _program, unsigned uniformBlockIndex, unsigned uniformBlockBinding);

typedef void __stdcall (*PFNGLCOPYBUFFERSUBDATAPROC)(unsigned readTarget, unsigned writeTarget, TGLintptr readOffset, TGLintptr writeOffset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLDRAWELEMENTSBASEVERTEXPROC)(unsigned mode, TGLsizei count, unsigned _type, PGLvoid indices, TGLint basevertex);

typedef void __stdcall (*PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(unsigned mode, unsigned start, unsigned _end, TGLsizei count, unsigned _type, PGLvoid indices, TGLint basevertex);

typedef void __stdcall (*PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(unsigned mode, TGLsizei count, unsigned _type, PGLvoid indices, TGLsizei primcount, TGLint basevertex);

typedef void __stdcall (*PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(unsigned mode, PGLsizei count, unsigned _type, void *indices, TGLsizei primcount, PGLint basevertex);

typedef void __stdcall (*PFNGLPROVOKINGVERTEXPROC)(unsigned mode);

typedef TGLsync __stdcall (*PFNGLFENCESYNCPROC)(unsigned condition, TGLbitfield flags);

typedef TGLboolean __stdcall (*PFNGLISSYNCPROC)(TGLsync sync);

typedef void __stdcall (*PFNGLDELETESYNCPROC)(TGLsync sync);

typedef unsigned __stdcall (*PFNGLCLIENTWAITSYNCPROC)(TGLsync sync, TGLbitfield flags, TGLuint64 timeout);

typedef void __stdcall (*PFNGLWAITSYNCPROC)(TGLsync sync, TGLbitfield flags, TGLuint64 timeout);

typedef void __stdcall (*PFNGLGETINTEGER64VPROC)(unsigned pname, PGLint64 params);

typedef void __stdcall (*PFNGLGETSYNCIVPROC)(TGLsync sync, unsigned pname, TGLsizei bufSize, PGLsizei length, PGLint values);

typedef void __stdcall (*PFNGLTEXIMAGE2DMULTISAMPLEPROC)(unsigned target, TGLsizei samples, TGLint internalformat, TGLsizei width, TGLsizei height, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLTEXIMAGE3DMULTISAMPLEPROC)(unsigned target, TGLsizei samples, TGLint internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLGETMULTISAMPLEFVPROC)(unsigned pname, unsigned index, PGLfloat val);

typedef void __stdcall (*PFNGLSAMPLEMASKIPROC)(unsigned index, TGLbitfield mask);

typedef void __stdcall (*PFNGLBLENDEQUATIONIARBPROC)(unsigned buf, unsigned mode);

typedef void __stdcall (*PFNGLBLENDEQUATIONSEPARATEIARBPROC)(unsigned buf, unsigned modeRGB, unsigned modeAlpha);

typedef void __stdcall (*PFNGLBLENDFUNCIARBPROC)(unsigned buf, unsigned src, unsigned dst);

typedef void __stdcall (*PFNGLBLENDFUNCSEPARATEIARBPROC)(unsigned buf, unsigned srcRGB, unsigned dstRGB, unsigned srcAlpha, unsigned dstAlpha);

typedef void __stdcall (*PFNGLMINSAMPLESHADINGARBPROC)(float value);

typedef void __stdcall (*PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(unsigned _program, unsigned colorNumber, unsigned index, const char * name);

typedef TGLint __stdcall (*PFNGLGETFRAGDATAINDEXPROC)(unsigned _program, const char * name);

typedef void __stdcall (*PFNGLGENSAMPLERSPROC)(TGLsizei count, PGLuint samplers);

typedef void __stdcall (*PFNGLDELETESAMPLERSPROC)(TGLsizei count, const PGLuint samplers);

typedef TGLboolean __stdcall (*PFNGLISSAMPLERPROC)(unsigned sampler);

typedef void __stdcall (*PFNGLBINDSAMPLERPROC)(unsigned _unit, unsigned sampler);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERIPROC)(unsigned sampler, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERIVPROC)(unsigned sampler, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERFPROC)(unsigned sampler, unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERFVPROC)(unsigned sampler, unsigned pname, const PGLfloat params);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERIIVPROC)(unsigned sampler, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLSAMPLERPARAMETERIUIVPROC)(unsigned sampler, unsigned pname, const PGLuint params);

typedef void __stdcall (*PFNGLGETSAMPLERPARAMETERIVPROC)(unsigned sampler, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETSAMPLERPARAMETERIIVPROC)(unsigned sampler, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETSAMPLERPARAMETERFVPROC)(unsigned sampler, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETSAMPLERPARAMETERIFVPROC)(unsigned sampler, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLQUERYCOUNTERPROC)(unsigned id, unsigned target);

typedef void __stdcall (*PFNGLGETQUERYOBJECTI64VPROC)(unsigned id, unsigned pname, PGLint64 params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTUI64VPROC)(unsigned id, unsigned pname, PGLuint64 params);

typedef void __stdcall (*PFNGLVERTEXP2UIPROC)(unsigned _type, unsigned value);

typedef void __stdcall (*PFNGLVERTEXP2UIVPROC)(unsigned _type, const PGLuint value);

typedef void __stdcall (*PFNGLVERTEXP3UIPROC)(unsigned _type, unsigned value);

typedef void __stdcall (*PFNGLVERTEXP3UIVPROC)(unsigned _type, const PGLuint value);

typedef void __stdcall (*PFNGLVERTEXP4UIPROC)(unsigned _type, unsigned value);

typedef void __stdcall (*PFNGLVERTEXP4UIVPROC)(unsigned _type, const PGLuint value);

typedef void __stdcall (*PFNGLTEXCOORDP1UIPROC)(unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLTEXCOORDP1UIVPROC)(unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLTEXCOORDP2UIPROC)(unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLTEXCOORDP2UIVPROC)(unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLTEXCOORDP3UIPROC)(unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLTEXCOORDP3UIVPROC)(unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLTEXCOORDP4UIPROC)(unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLTEXCOORDP4UIVPROC)(unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP1UIPROC)(unsigned texture, unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP1UIVPROC)(unsigned texture, unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP2UIPROC)(unsigned texture, unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP2UIVPROC)(unsigned texture, unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP3UIPROC)(unsigned texture, unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP3UIVPROC)(unsigned texture, unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP4UIPROC)(unsigned texture, unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLMULTITEXCOORDP4UIVPROC)(unsigned texture, unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLNORMALP3UIPROC)(unsigned _type, unsigned coords);

typedef void __stdcall (*PFNGLNORMALP3UIVPROC)(unsigned _type, const PGLuint coords);

typedef void __stdcall (*PFNGLCOLORP3UIPROC)(unsigned _type, unsigned color);

typedef void __stdcall (*PFNGLCOLORP3UIVPROC)(unsigned _type, const PGLuint color);

typedef void __stdcall (*PFNGLCOLORP4UIPROC)(unsigned _type, unsigned color);

typedef void __stdcall (*PFNGLCOLORP4UIVPROC)(unsigned _type, const PGLuint color);

typedef void __stdcall (*PFNGLSECONDARYCOLORP3UIPROC)(unsigned _type, unsigned color);

typedef void __stdcall (*PFNGLSECONDARYCOLORP3UIVPROC)(unsigned _type, const PGLuint color);

typedef void __stdcall (*PFNGLVERTEXATTRIBP1UIPROC)(unsigned index, unsigned _type, TGLboolean normalized, unsigned value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP1UIVPROC)(unsigned index, unsigned _type, TGLboolean normalized, const PGLuint value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP2UIPROC)(unsigned index, unsigned _type, TGLboolean normalized, unsigned value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP2UIVPROC)(unsigned index, unsigned _type, TGLboolean normalized, const PGLuint value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP3UIPROC)(unsigned index, unsigned _type, TGLboolean normalized, unsigned value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP3UIVPROC)(unsigned index, unsigned _type, TGLboolean normalized, const PGLuint value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP4UIPROC)(unsigned index, unsigned _type, TGLboolean normalized, unsigned value);

typedef void __stdcall (*PFNGLVERTEXATTRIBP4UIVPROC)(unsigned index, unsigned _type, TGLboolean normalized, const PGLuint value);

typedef void __stdcall (*PFNGLDRAWARRAYSINDIRECTPROC)(unsigned mode, const PGLvoid indirect);

typedef void __stdcall (*PFNGLDRAWELEMENTSINDIRECTPROC)(unsigned mode, unsigned _type, const PGLvoid indirect);

typedef void __stdcall (*PFNGLUNIFORM1DPROC)(TGLint location, TGLdouble x);

typedef void __stdcall (*PFNGLUNIFORM2DPROC)(TGLint location, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLUNIFORM3DPROC)(TGLint location, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLUNIFORM4DPROC)(TGLint location, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLUNIFORM1DVPROC)(TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORM2DVPROC)(TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORM3DVPROC)(TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORM4DVPROC)(TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2X3DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX2X4DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3X2DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX3X4DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4X2DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLUNIFORMMATRIX4X3DVPROC)(TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLGETUNIFORMDVPROC)(unsigned _program, TGLint location, PGLdouble params);

typedef void __stdcall (*PFNGLCLIENTATTRIBDEFAULTEXTPROC)(TGLbitfield mask);

typedef void __stdcall (*PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(TGLbitfield mask);

typedef void __stdcall (*PFNGLMATRIXLOADFEXTPROC)(unsigned mode, const PGLfloat m);

typedef void __stdcall (*PFNGLMATRIXLOADDEXTPROC)(unsigned mode, const PGLdouble m);

typedef void __stdcall (*PFNGLMATRIXMULTFEXTPROC)(unsigned mode, const PGLfloat m);

typedef void __stdcall (*PFNGLMATRIXMULTDEXTPROC)(unsigned mode, const PGLdouble m);

typedef void __stdcall (*PFNGLMATRIXLOADIDENTITYEXTPROC)(unsigned mode);

typedef void __stdcall (*PFNGLMATRIXROTATEFEXTPROC)(unsigned mode, TGLfloat angle, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLMATRIXROTATEDEXTPROC)(unsigned mode, TGLdouble angle, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLMATRIXSCALEFEXTPROC)(unsigned mode, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLMATRIXSCALEDEXTPROC)(unsigned mode, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLMATRIXTRANSLATEFEXTPROC)(unsigned mode, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLMATRIXTRANSLATEDEXTPROC)(unsigned mode, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLMATRIXFRUSTUMEXTPROC)(unsigned mode, TGLdouble left, TGLdouble right, TGLdouble bottom, TGLdouble top, TGLdouble zNear, TGLdouble zFar);

typedef void __stdcall (*PFNGLMATRIXORTHOEXTPROC)(unsigned mode, TGLdouble left, TGLdouble right, TGLdouble bottom, TGLdouble top, TGLdouble zNear, TGLdouble zFar);

typedef void __stdcall (*PFNGLMATRIXPOPEXTPROC)(unsigned mode);

typedef void __stdcall (*PFNGLMATRIXPUSHEXTPROC)(unsigned mode);

typedef void __stdcall (*PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(unsigned mode, const PGLfloat m);

typedef void __stdcall (*PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(unsigned mode, const PGLdouble m);

typedef void __stdcall (*PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(unsigned mode, const PGLfloat m);

typedef void __stdcall (*PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(unsigned mode, const PGLdouble m);

typedef void __stdcall (*PFNGLTEXTUREPARAMETERFVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*PFNGLTEXTUREPARAMETERIEXTPROC)(unsigned texture, unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLTEXTUREPARAMETERIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLTEXTUREIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLTEXTUREIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLTEXTURESUBIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLTEXTURESUBIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLint x, TGLint y, TGLsizei width, TGLint border);

typedef void __stdcall (*PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLint x, TGLint y, TGLsizei width, TGLsizei height, TGLint border);

typedef void __stdcall (*PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETTEXTUREIMAGEEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned format, unsigned type_, PGLvoid pixels);

typedef void __stdcall (*PFNGLGETTEXTUREPARAMETERFVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETTEXTUREPARAMETERIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned pname, TGLint params);

typedef void __stdcall (*PFNGLTEXTUREIMAGE3DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLTEXTURESUBIMAGE3DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERFEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERFVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERIEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERIVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLMULTITEXIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLMULTITEXIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLMULTITEXSUBIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLMULTITEXSUBIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLint x, TGLint y, TGLsizei width, TGLint border);

typedef void __stdcall (*PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLint x, TGLint y, TGLsizei width, TGLsizei height, TGLint border);

typedef void __stdcall (*PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETMULTITEXIMAGEEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned format, unsigned type_, PGLvoid pixels);

typedef void __stdcall (*PFNGLGETMULTITEXPARAMETERFVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETMULTITEXPARAMETERIVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLMULTITEXIMAGE3DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLMULTITEXSUBIMAGE3DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, unsigned type_, const PGLvoid pixels);

typedef void __stdcall (*PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLBINDMULTITEXTUREEXTPROC)(unsigned texunit, unsigned target, unsigned texture);

typedef void __stdcall (*PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(unsigned array_, unsigned index_);

typedef void __stdcall (*PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(unsigned array_, unsigned index_);

typedef void __stdcall (*PFNGLMULTITEXCOORDPOINTEREXTPROC)(unsigned texunit, TGLint size, unsigned type_, TGLsizei stride, const PGLvoid pointer);

typedef void __stdcall (*PFNGLMULTITEXENVFEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLMULTITEXENVFVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*PFNGLMULTITEXENVIEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLMULTITEXENVIVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLMULTITEXGENDEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLdouble param);

typedef void __stdcall (*PFNGLMULTITEXGENDVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLdouble params);

typedef void __stdcall (*PFNGLMULTITEXGENFEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLMULTITEXGENFVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLfloat params);

typedef void __stdcall (*PFNGLMULTITEXGENIEXTPROC)(unsigned texunit, unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLMULTITEXGENIVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLGETMULTITEXENVFVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETMULTITEXENVIVEXTPROC)(unsigned texunit, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETMULTITEXGENDVEXTPROC)(unsigned texunit, unsigned coord, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLGETMULTITEXGENFVEXTPROC)(unsigned texunit, unsigned coord, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETMULTITEXGENIVEXTPROC)(unsigned texunit, unsigned coord, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETFLOATINDEXEDVEXTPROC)(unsigned target, unsigned index_, PGLfloat data);

typedef void __stdcall (*PFNGLGETDOUBLEINDEXEDVEXTPROC)(unsigned target, unsigned index_, PGLdouble data);

typedef void __stdcall (*PFNGLGETPOINTERINDEXEDVEXTPROC)(unsigned target, unsigned index_, PGLvoid data);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(unsigned texture, unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(unsigned texture, unsigned target, TGLint lod, PGLvoid img);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLint border, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(unsigned texunit, unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned format, TGLsizei imageSize, const PGLvoid bits);

typedef void __stdcall (*PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(unsigned texunit, unsigned target, TGLint lod, PGLvoid img);

typedef void __stdcall (*PFNGLNAMEDPROGRAMSTRINGEXTPROC)(unsigned program_, unsigned target, unsigned format, TGLsizei len, const PGLvoid string_);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(unsigned program_, unsigned target, unsigned index_, const PGLdouble params);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(unsigned program_, unsigned target, unsigned index_, const PGLfloat params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(unsigned program_, unsigned target, unsigned index_, PGLdouble params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(unsigned program_, unsigned target, unsigned index_, PGLfloat params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMIVEXTPROC)(unsigned program_, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(unsigned program_, unsigned target, unsigned pname, PGLvoid string_);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLsizei count, const PGLfloat params);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLint x, TGLint y, TGLint z, TGLint w);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(unsigned program_, unsigned target, unsigned index_, const PGLint params);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLsizei count, const PGLint params);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(unsigned program_, unsigned target, unsigned index_, unsigned x, unsigned y, unsigned z, unsigned w);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(unsigned program_, unsigned target, unsigned index_, const PGLuint params);

typedef void __stdcall (*PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(unsigned program_, unsigned target, unsigned index_, TGLsizei count, const PGLuint params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(unsigned program_, unsigned target, unsigned index_, PGLint params);

typedef void __stdcall (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(unsigned program_, unsigned target, unsigned index_, PGLuint params);

typedef void __stdcall (*PFNGLTEXTUREPARAMETERIIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLTEXTUREPARAMETERIUIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLuint params);

typedef void __stdcall (*PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERIIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLint params);

typedef void __stdcall (*PFNGLMULTITEXPARAMETERIUIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, const PGLuint params);

typedef void __stdcall (*PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(unsigned texture, unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLNAMEDBUFFERDATAEXTPROC)(unsigned buffer, TGLsizei size, const PGLvoid data, unsigned usage);

typedef void __stdcall (*PFNGLNAMEDBUFFERSUBDATAEXTPROC)(unsigned buffer, TGLintptr offset, TGLsizeiptr size, const PGLvoid data);

typedef PGLvoid __stdcall (*PFNGLMAPNAMEDBUFFEREXTPROC)(unsigned buffer, unsigned access);

typedef TGLboolean __stdcall (*PFNGLUNMAPNAMEDBUFFEREXTPROC)(unsigned buffer);

typedef PGLvoid __stdcall (*PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(unsigned buffer, TGLintptr offset, TGLsizeiptr length, TGLbitfield access);

typedef void __stdcall (*PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(unsigned buffer, TGLintptr offset, TGLsizeiptr length);

typedef void __stdcall (*PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(unsigned readBuffer, unsigned writeBuffer, TGLintptr readOffset, TGLintptr writeOffset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(unsigned buffer, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(unsigned buffer, unsigned pname, PGLvoid params);

typedef void __stdcall (*PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(unsigned buffer, TGLintptr offset, TGLsizeiptr size, PGLvoid data);

typedef void __stdcall (*PFNGLTEXTUREBUFFEREXTPROC)(unsigned texture, unsigned target, unsigned internalformat, unsigned buffer);

typedef void __stdcall (*PFNGLMULTITEXBUFFEREXTPROC)(unsigned texunit, unsigned target, unsigned interformat, unsigned buffer);

typedef void __stdcall (*PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(unsigned renderbuffer, unsigned interformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(unsigned renderbuffer, unsigned pname, PGLint params);

typedef unsigned __stdcall (*PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(unsigned framebuffer, unsigned target);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned textarget, unsigned texture, TGLint level, TGLint zoffset);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(unsigned framebuffer, unsigned attachment, unsigned renderbuffertarget, unsigned renderbuffer);

typedef void __stdcall (*PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGENERATETEXTUREMIPMAPEXTPROC)(unsigned texture, unsigned target);

typedef void __stdcall (*PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(unsigned texunit, unsigned target);

typedef void __stdcall (*PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(unsigned framebuffer, unsigned mode);

typedef void __stdcall (*PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(unsigned framebuffer, TGLsizei n, const System::PCardinal bufs);

typedef void __stdcall (*PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(unsigned framebuffer, unsigned mode);

typedef void __stdcall (*PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(unsigned framebuffer, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(unsigned renderbuffer, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(unsigned renderbuffer, TGLsizei coverageSamples, TGLsizei colorSamples, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(unsigned framebuffer, unsigned attachment, unsigned texture, TGLint level, TGLint layer);

typedef void __stdcall (*PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(unsigned framebuffer, unsigned attachment, unsigned texture, TGLint level, unsigned face);

typedef void __stdcall (*PFNGLTEXTURERENDERBUFFEREXTPROC)(unsigned texture, unsigned target, unsigned renderbuffer);

typedef void __stdcall (*PFNGLMULTITEXRENDERBUFFEREXTPROC)(unsigned texunit, unsigned target, unsigned renderbuffer);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1DEXTPROC)(unsigned _program, TGLint location, TGLdouble x);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2DEXTPROC)(unsigned _program, TGLint location, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3DEXTPROC)(unsigned _program, TGLint location, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4DEXTPROC)(unsigned _program, TGLint location, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, const PGLdouble value);

typedef TGLint __stdcall (*PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(unsigned _program, unsigned shadertype, const char * name);

typedef unsigned __stdcall (*PFNGLGETSUBROUTINEINDEXPROC)(unsigned _program, unsigned shadertype, const char * name);

typedef void __stdcall (*PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(unsigned _program, unsigned shadertype, unsigned index, unsigned pname, PGLint values);

typedef void __stdcall (*PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(unsigned _program, unsigned shadertype, unsigned index, TGLsizei bufsize, PGLsizei length, char * name);

typedef void __stdcall (*PFNGLGETACTIVESUBROUTINENAMEPROC)(unsigned _program, unsigned shadertype, unsigned index, TGLsizei bufsize, PGLsizei length, char * name);

typedef void __stdcall (*PFNGLUNIFORMSUBROUTINESUIVPROC)(unsigned shadertype, TGLsizei count, const PGLuint indices);

typedef void __stdcall (*PFNGLGETUNIFORMSUBROUTINEUIVPROC)(unsigned shadertype, TGLint location, PGLuint params);

typedef void __stdcall (*PFNGLGETPROGRAMSTAGEIVPROC)(unsigned _program, unsigned shadertype, unsigned pname, PGLint values);

typedef void __stdcall (*PFNGLPATCHPARAMETERIPROC)(unsigned pname, TGLint value);

typedef void __stdcall (*PFNGLPATCHPARAMETERFVPROC)(unsigned pname, const PGLfloat values);

typedef void __stdcall (*PFNGLBINDTRANSFORMFEEDBACKPROC)(unsigned target, unsigned id);

typedef void __stdcall (*PFNGLDELETETRANSFORMFEEDBACKSPROC)(TGLsizei n, const PGLuint ids);

typedef void __stdcall (*PFNGLGENTRANSFORMFEEDBACKSPROC)(TGLsizei n, PGLuint ids);

typedef TGLboolean __stdcall (*PFNGLISTRANSFORMFEEDBACKPROC)(unsigned id);

typedef void __stdcall (*PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);

typedef void __stdcall (*PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);

typedef void __stdcall (*PFNGLDRAWTRANSFORMFEEDBACKPROC)(unsigned mode, unsigned id);

typedef void __stdcall (*PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(unsigned mode, unsigned id, unsigned stream);

typedef void __stdcall (*PFNGLBEGINQUERYINDEXEDPROC)(unsigned target, unsigned index, unsigned id);

typedef void __stdcall (*PFNGLENDQUERYINDEXEDPROC)(unsigned target, unsigned index);

typedef void __stdcall (*PFNGLGETQUERYINDEXEDIVPROC)(unsigned target, unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLRELEASESHADERCOMPILERPROC)(void);

typedef void __stdcall (*PFNGLSHADERBINARYPROC)(TGLsizei count, PGLuint shaders, unsigned binaryformat, void * binary, TGLsizei length);

typedef void __stdcall (*PFNGLGETSHADERPRECISIONFORMATPROC)(unsigned shadertype, unsigned precisiontype, PGLint range, PGLint precision);

typedef void __stdcall (*PFNGLDEPTHRANGEFPROC)(float n, float f);

typedef void __stdcall (*PFNGLCLEARDEPTHFPROC)(TGLclampd depth);

typedef void __stdcall (*PFNGLGETPROGRAMBINARYPROC)(unsigned _program, TGLsizei bufSize, PGLsizei length, System::PCardinal binaryFormat, void * binary);

typedef void __stdcall (*PFNGLPROGRAMBINARYPROC)(unsigned _program, unsigned binaryFormat, void * binary, TGLsizei length);

typedef void __stdcall (*PFNGLPROGRAMPARAMETERIPROC)(unsigned _program, unsigned pname, TGLint value);

typedef void __stdcall (*PFNGLUSEPROGRAMSTAGESPROC)(unsigned pipeline, TGLbitfield stages, unsigned _program);

typedef void __stdcall (*PFNGLACTIVESHADERPROGRAMPROC)(unsigned pipeline, unsigned _program);

typedef unsigned __stdcall (*PFNGLCREATESHADERPROGRAMVPROC)(unsigned _type, TGLsizei count, const PGLPCharArray strings);

typedef void __stdcall (*PFNGLBINDPROGRAMPIPELINEPROC)(unsigned pipeline);

typedef void __stdcall (*PFNGLDELETEPROGRAMPIPELINESPROC)(TGLsizei n, PGLuint pipelines);

typedef void __stdcall (*PFNGLGENPROGRAMPIPELINESPROC)(TGLsizei n, PGLuint pipelines);

typedef TGLboolean __stdcall (*PFNGLISPROGRAMPIPELINEPROC)(unsigned pipeline);

typedef void __stdcall (*PFNGLGETPROGRAMPIPELINEIVPROC)(unsigned pipeline, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1IPROC)(unsigned _program, TGLint location, TGLint v0);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1IVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1FPROC)(unsigned _program, TGLint location, TGLfloat v0);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1FVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1DPROC)(unsigned _program, TGLint location, TGLdouble v0);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1DVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1UIPROC)(unsigned _program, TGLint location, unsigned v0);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM1UIVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2IPROC)(unsigned _program, TGLint location, TGLint v0, TGLint v1);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2IVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2FPROC)(unsigned _program, TGLint location, TGLfloat v0, TGLfloat v1);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2FVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2DPROC)(unsigned _program, TGLint location, TGLdouble v0, TGLdouble v1);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2DVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2UIPROC)(unsigned _program, TGLint location, unsigned v0, unsigned v1);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM2UIVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3IPROC)(unsigned _program, TGLint location, TGLint v0, TGLint v1, TGLint v2);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3IVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3FPROC)(unsigned _program, TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3FVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3DPROC)(unsigned _program, TGLint location, TGLdouble v0, TGLdouble v1, TGLdouble v2);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3DVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3UIPROC)(unsigned _program, TGLint location, unsigned v0, unsigned v1, unsigned v2);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM3UIVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4IPROC)(unsigned _program, TGLint location, TGLint v0, TGLint v1, TGLint v2, TGLint v3);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4IVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4FPROC)(unsigned _program, TGLint location, TGLfloat v0, TGLfloat v1, TGLfloat v2, TGLfloat v3);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4FVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4DPROC)(unsigned _program, TGLint location, TGLdouble v0, TGLdouble v1, TGLdouble v2, TGLdouble v3);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4DVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4UIPROC)(unsigned _program, TGLint location, unsigned v0, unsigned v1, unsigned v2, unsigned v3);

typedef void __stdcall (*PFNGLPROGRAMUNIFORM4UIVPROC)(unsigned _program, TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLfloat value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(unsigned _program, TGLint location, TGLsizei count, TGLboolean transpose, PGLdouble value);

typedef void __stdcall (*PFNGLVALIDATEPROGRAMPIPELINEPROC)(unsigned pipeline);

typedef void __stdcall (*PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(unsigned pipeline, TGLsizei bufSize, PGLsizei length, char * infoLog);

typedef void __stdcall (*PFNGLVERTEXATTRIBL1DPROC)(unsigned index, TGLdouble x);

typedef void __stdcall (*PFNGLVERTEXATTRIBL2DPROC)(unsigned index, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLVERTEXATTRIBL3DPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLVERTEXATTRIBL4DPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLVERTEXATTRIBL1DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBL2DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBL3DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBL4DVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBLPOINTERPROC)(unsigned index, TGLint size, unsigned _type, TGLsizei stride, void * ptr);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBLDVPROC)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(unsigned vaobj, unsigned buffer, unsigned index, TGLint size, unsigned _type, TGLsizei stride, TGLintptr offset);

typedef void __stdcall (*PFNGLVIEWPORTARRAYVPROC)(unsigned first, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLVIEWPORTINDEXEDFPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat w, TGLfloat h);

typedef void __stdcall (*PFNGLVIEWPORTINDEXEDFVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLSCISSORARRAYVPROC)(unsigned first, TGLsizei count, PGLint v);

typedef void __stdcall (*PFNGLSCISSORINDEXEDPROC)(unsigned index, TGLint left, TGLint bottom, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLSCISSORINDEXEDVPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLDEPTHRANGEARRAYVPROC)(unsigned first, TGLsizei count, PGLclampd v);

typedef void __stdcall (*PFNGLDEPTHRANGEINDEXEDPROC)(unsigned index, TGLclampd n, TGLclampd f);

typedef void __stdcall (*PFNGLGETFLOATI_VPROC)(unsigned target, unsigned index, PGLfloat data);

typedef void __stdcall (*PFNGLGETDOUBLEI_VPROC)(unsigned target, unsigned index, PGLdouble data);

typedef void __stdcall (*PFNGLDEBUGMESSAGECONTROLARBPROC)(unsigned source, unsigned _type, unsigned severity, TGLsizei count, PGLuint ids, TGLboolean enabled);

typedef void __stdcall (*PFNGLDEBUGMESSAGEINSERTARBPROC)(unsigned source, unsigned _type, unsigned id, unsigned severity, TGLsizei length, char * buf);

typedef void __stdcall (*PFNGLDEBUGMESSAGECALLBACKARBPROC)(TGLDEBUGPROCARB callback, void * userParam);

typedef unsigned __stdcall (*PFNGLGETDEBUGMESSAGELOGARBPROC)(unsigned count, TGLsizei bufsize, System::PCardinal sources, System::PCardinal types, PGLuint ids, System::PCardinal severities, PGLsizei lengths, char * messageLog);

typedef unsigned __stdcall (*PFNGLGETGRAPHICSRESETSTATUSARBPROC)(void);

typedef void __stdcall (*PFNGLGETNMAPDVARBPROC)(unsigned target, unsigned query, TGLsizei bufSize, PGLdouble v);

typedef void __stdcall (*PFNGLGETNMAPFVARBPROC)(unsigned target, unsigned query, TGLsizei bufSize, PGLfloat v);

typedef void __stdcall (*PFNGLGETNMAPIVARBPROC)(unsigned target, unsigned query, TGLsizei bufSize, PGLint v);

typedef void __stdcall (*PFNGLGETNPIXELMAPFVARBPROC)(unsigned map, TGLsizei bufSize, PGLfloat values);

typedef void __stdcall (*PFNGLGETNPIXELMAPUIVARBPROC)(unsigned map, TGLsizei bufSize, PGLuint values);

typedef void __stdcall (*PFNGLGETNPIXELMAPUSVARBPROC)(unsigned map, TGLsizei bufSize, PGLushort values);

typedef void __stdcall (*PFNGLGETNPOLYGONSTIPPLEARBPROC)(TGLsizei bufSize, PGLubyte pattern);

typedef void __stdcall (*PFNGLGETNCOLORTABLEARBPROC)(unsigned target, unsigned format, unsigned _type, TGLsizei bufSize, void * table);

typedef void __stdcall (*PFNGLGETNCONVOLUTIONFILTERARBPROC)(unsigned target, unsigned format, unsigned _type, TGLsizei bufSize, void * image);

typedef void __stdcall (*PFNGLGETNSEPARABLEFILTERARBPROC)(unsigned target, unsigned format, unsigned _type, TGLsizei rowBufSize, void * row, TGLsizei columnBufSize, void * column, void * span);

typedef void __stdcall (*PFNGLGETNHISTOGRAMARBPROC)(unsigned target, TGLboolean reset, unsigned format, unsigned _type, TGLsizei bufSize, void * values);

typedef void __stdcall (*PFNGLGETNMINMAXARBPROC)(unsigned target, TGLboolean reset, unsigned format, unsigned _type, TGLsizei bufSize, void * values);

typedef void __stdcall (*PFNGLGETNTEXIMAGEARBPROC)(unsigned target, TGLint level, unsigned format, unsigned _type, TGLsizei bufSize, void * img);

typedef void __stdcall (*PFNGLREADNPIXELSARBPROC)(TGLint x, TGLint y, TGLsizei width, TGLsizei height, unsigned format, unsigned _type, TGLsizei bufSize, void * data);

typedef void __stdcall (*PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(unsigned target, TGLint lod, TGLsizei bufSize, void * img);

typedef void __stdcall (*PFNGLGETNUNIFORMFVARBPROC)(unsigned _program, TGLint location, TGLsizei bufSize, PGLfloat params);

typedef void __stdcall (*PFNGLGETNUNIFORMIVARBPROC)(unsigned _program, TGLint location, TGLsizei bufSize, PGLint params);

typedef void __stdcall (*PFNGLGETNUNIFORMUIVARBPROC)(unsigned _program, TGLint location, TGLsizei bufSize, PGLuint params);

typedef void __stdcall (*PFNGLGETNUNIFORMDVARBPROC)(unsigned _program, TGLint location, TGLsizei bufSize, PGLdouble params);

typedef void __stdcall (*PFNGLPushDebugGroup)(unsigned source, unsigned id, TGLsizei length, const char * message_);

typedef void __stdcall (*PFNGLPopDebugGroup)(void);

typedef void __stdcall (*PFNGLObjectLabel)(unsigned identifier, unsigned name, TGLsizei length, const char * label_);

typedef void __stdcall (*PFNGLGetObjectLabel)(unsigned identifier, unsigned name, TGLsizei bufsize, PGLsizei length, char * label_);

typedef void __stdcall (*PFNGLObjectPtrLabel)(const void * ptr, TGLsizei length, const char * label_);

typedef void __stdcall (*PFNGLGetObjectPtrLabel)(const void * ptr, TGLsizei bufSize, PGLsizei length, char * label_);

typedef void __stdcall (*PFNGLClearBufferData)(unsigned target, unsigned internalformat, unsigned format, unsigned type_, const void * data);

typedef void __stdcall (*PFNGLClearBufferSubData)(unsigned target, unsigned internalformat, TGLintptr offset, TGLsizeiptr size, unsigned format, unsigned type_, const void * data);

typedef void __stdcall (*PFNGLClearNamedBufferData)(unsigned buffer, unsigned internalformat, unsigned format, unsigned type_, const void * data);

typedef void __stdcall (*PFNGLClearNamedBufferSubData)(unsigned buffer, unsigned internalformat, unsigned format, unsigned type_, TGLsizeiptr offset, TGLsizeiptr size, const void * data);

typedef void __stdcall (*PFNGLDispatchCompute)(unsigned num_groups_x, unsigned num_groups_y, unsigned num_groups_z);

typedef void __stdcall (*PFNGLDispatchComputeIndirect)(TGLintptr indirect);

typedef void __stdcall (*PFNGLCopyImageSubData)(unsigned srcName, unsigned srcTarget, TGLint srcLevel, TGLint srcX, TGLint srcY, TGLint srcZ, unsigned dstName, unsigned dstTarget, TGLint dstLevel, TGLint dstX, TGLint dstY, TGLint dstZ, TGLsizei srcWidth, TGLsizei srcHeight, TGLsizei srcDepth);

typedef void __stdcall (*PFNGLFramebufferParameteri)(unsigned target, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLGetFramebufferParameteriv)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLNamedFramebufferParameteri)(unsigned framebuffer, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLGetNamedFramebufferParameteriv)(unsigned framebuffer, unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLGetInternalformati64v)(unsigned target, unsigned internalformat, unsigned pname, TGLsizei bufSize, PGLint64 params);

typedef void __stdcall (*PFNGLInvalidateTexSubImage)(unsigned texture, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth);

typedef void __stdcall (*PFNGLInvalidateTexImage)(unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLInvalidateBufferSubData)(unsigned buffer, TGLintptr offset, TGLsizeiptr length);

typedef void __stdcall (*PFNGLInvalidateBufferData)(unsigned buffer);

typedef void __stdcall (*PFNGLInvalidateFramebuffer)(unsigned target, TGLsizei numAttachments, const System::PCardinal attachments);

typedef void __stdcall (*PFNGLInvalidateSubFramebuffer)(unsigned target, TGLsizei numAttachments, const System::PCardinal attachments, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLMultiDrawArraysIndirect)(unsigned mode, const void * indirect, TGLsizei drawcount, TGLsizei stride);

typedef void __stdcall (*PFNGLMultiDrawElementsIndirect)(unsigned mode, unsigned type_, const void * indirect, TGLsizei drawcount, TGLsizei stride);

typedef void __stdcall (*PFNGLGetProgramInterfaceiv)(unsigned program_, unsigned programInterface, unsigned pname, PGLint params);

typedef unsigned __stdcall (*PFNGLGetProgramResourceIndex)(unsigned program_, unsigned programInterface, const char * name);

typedef void __stdcall (*PFNGLGetProgramResourceName)(unsigned program_, unsigned programInterface, unsigned index, TGLsizei bufSize, PGLsizei length, char * name);

typedef void __stdcall (*PFNGLGetProgramResourceiv)(unsigned program_, unsigned programInterface, unsigned index, TGLsizei propCount, const System::PCardinal props, TGLsizei bufSize, PGLsizei length, PGLint params);

typedef TGLint __stdcall (*PFNGLGetProgramResourceLocation)(unsigned program_, unsigned programInterface, const char * name);

typedef TGLint __stdcall (*PFNGLGetProgramResourceLocationIndex)(unsigned program_, unsigned programInterface, const char * name);

typedef void __stdcall (*PFNGLShaderStorageBlockBinding)(unsigned program_, unsigned storageBlockIndex, unsigned storageBlockBinding);

typedef void __stdcall (*PFNGLTexBufferRange)(unsigned target, unsigned internalformat, unsigned buffer, TGLintptr offset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLTextureBufferRange)(unsigned texture, unsigned target, unsigned internalformat, unsigned buffer, TGLintptr offset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLTexStorage2DMultisample)(unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLTexStorage3DMultisample)(unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLTextureStorage2DMultisample)(unsigned texture, unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLTextureStorage3DMultisample)(unsigned texture, unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLboolean fixedsamplelocations);

typedef void __stdcall (*PFNGLBufferStorage)(unsigned target, TGLsizeiptr size, const void * data, TGLbitfield flags);

typedef void __stdcall (*PFNGLClearTexImage)(unsigned texture, TGLint level, unsigned format, unsigned _type, const void * data);

typedef void __stdcall (*PFNGLClearTexSubImage)(unsigned texture, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, unsigned _type, const void * Data);

typedef void __stdcall (*PFNGLBindBuffersBase)(unsigned target, unsigned first, TGLsizei count, const PGLuint buffers);

typedef void __stdcall (*PFNGLBindBuffersRange)(unsigned target, unsigned first, TGLsizei count, const PGLuint buffers, const TGLintptr offsets, const TGLsizeiptr sizes);

typedef void __stdcall (*PFNGLBindTextures)(unsigned first, TGLsizei count, const PGLuint textures);

typedef void __stdcall (*PFNGLBindSamplers)(unsigned first, TGLsizei count, const PGLuint samplers);

typedef void __stdcall (*PFNGLBindImageTextures)(unsigned first, TGLsizei count, const PGLuint textures);

typedef void __stdcall (*PFNGLBindVertexBuffers)(unsigned first, TGLsizei count, const unsigned buffers, const TGLintptr offsets, const PGLsizei strides);

typedef void __stdcall (*PFNGLTextureView)(unsigned texture, unsigned target, unsigned origtexture, unsigned internalformat, unsigned minlevel, unsigned numlevels, unsigned minlayer, unsigned numlayers);

typedef void __stdcall (*PFNGLBindVertexBuffer)(unsigned bindingindex, unsigned buffer, TGLintptr offset, TGLsizei stride);

typedef void __stdcall (*PFNGLVertexAttribFormat)(unsigned attribindex, TGLint size, unsigned type_, TGLboolean normalized, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexAttribIFormat)(unsigned attribindex, TGLint size, unsigned type_, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexAttribLFormat)(unsigned attribindex, TGLint size, unsigned type_, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexAttribBinding)(unsigned attribindex, unsigned bindingindex);

typedef void __stdcall (*PFNGLVertexBindingDivisor)(unsigned bindingindex, unsigned divisor);

typedef void __stdcall (*PFNGLVertexArrayBindVertexBuffer)(unsigned vaobj, unsigned bindingindex, unsigned buffer, TGLintptr offset, TGLsizei stride);

typedef void __stdcall (*PFNGLVertexArrayVertexAttribFormat)(unsigned vaobj, unsigned attribindex, TGLint size, unsigned type_, TGLboolean normalized, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexArrayVertexAttribIFormat)(unsigned vaobj, unsigned attribindex, TGLint size, unsigned type_, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexArrayVertexAttribLFormat)(unsigned vaobj, unsigned attribindex, TGLint size, unsigned type_, unsigned relativeoffset);

typedef void __stdcall (*PFNGLVertexArrayVertexAttribBinding)(unsigned vaobj, unsigned attribindex, unsigned bindingindex);

typedef void __stdcall (*PFNGLVertexArrayVertexBindingDivisor)(unsigned vaobj, unsigned bindingindex, unsigned divisor);

typedef TGLsync __stdcall (*PFNGLCreateSyncFromCLevent)(Winapi::Openglext::p_cl_context context, Winapi::Openglext::p_cl_event event, TGLbitfield flags);

typedef void __stdcall (*PFNGLARRAYELEMENTARRAYEXTPROC)(unsigned mode, TGLsizei count, void * pi);

typedef void __stdcall (*PFNGLADDSWAPHINTRECTWINPROC)(TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLBLENDCOLOREXTPROC)(float red, float green, float blue, float alpha);

typedef void __stdcall (*PFNGLPOLYGONOFFSETEXTPROC)(TGLfloat factor, TGLfloat bias);

typedef void __stdcall (*PFNGLTEXIMAGE3DEXTPROC)(unsigned target, TGLint level, unsigned internalformat, TGLsizei width, TGLsizei height, TGLsizei depth, TGLint border, unsigned Format, unsigned AType, void * pixels);

typedef void __stdcall (*PFNGLTEXSUBIMAGE1DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLsizei width, unsigned format, unsigned Atype, void * pixels);

typedef void __stdcall (*PFNGLTEXSUBIMAGE2DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLsizei width, TGLsizei height, unsigned format, unsigned Atype, void * pixels);

typedef void __stdcall (*PFNGLTEXSUBIMAGE3DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLsizei width, TGLsizei height, TGLsizei depth, unsigned format, unsigned Atype, void * pixels);

typedef void __stdcall (*PFNGLCOPYTEXIMAGE1DEXTPROC)(unsigned target, TGLint level, unsigned internalFormat, TGLint x, TGLint y, TGLsizei width, TGLint border);

typedef void __stdcall (*PFNGLCOPYTEXIMAGE2DEXTPROC)(unsigned target, TGLint level, unsigned internalFormat, TGLint x, TGLint y, TGLsizei width, TGLsizei height, TGLint border);

typedef void __stdcall (*PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint x, TGLint y, TGLsizei width);

typedef void __stdcall (*PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(unsigned target, TGLint level, TGLint xoffset, TGLint yoffset, TGLint zoffset, TGLint x, TGLint y, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGENTEXTURESEXTPROC)(TGLsizei n, PGLuint textures);

typedef void __stdcall (*PFNGLDELETETEXTURESEXTPROC)(TGLsizei n, PGLuint textures);

typedef void __stdcall (*PFNGLBINDTEXTUREEXTPROC)(unsigned target, unsigned texture);

typedef void __stdcall (*PFNGLPRIORITIZETEXTURESEXTPROC)(TGLsizei n, PGLuint textures, Winapi::Windows::PSingle priorities);

typedef TGLboolean __stdcall (*PFNGLARETEXTURESRESIDENTEXTPROC)(TGLsizei n, PGLuint textures, PGLboolean residences);

typedef TGLboolean __stdcall (*PFNGLISTEXTUREEXTPROC)(unsigned texture);

typedef void __stdcall (*PFNGLSAMPLEMASKSGISPROC)(float Value, TGLboolean invert);

typedef void __stdcall (*PFNGLSAMPLEPATTERNSGISPROC)(unsigned pattern);

typedef void __stdcall (*PFNGLBLENDEQUATIONEXTPROC)(unsigned mode);

typedef void __stdcall (*PFNGLCOLORTABLEEXTPROC)(unsigned target, unsigned internalFormat, TGLsizei width, unsigned format, unsigned atype, void * data);

typedef void __stdcall (*PFNGLCOLORSUBTABLEEXTPROC)(unsigned target, TGLsizei start, TGLsizei count, unsigned format, unsigned atype, void * data);

typedef void __stdcall (*PFNGLGETCOLORTABLEEXTPROC)(unsigned target, unsigned format, unsigned atype, void * data);

typedef void __stdcall (*PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(unsigned target, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLINDEXMATERIALEXTPROC)(unsigned face, unsigned mode);

typedef void __stdcall (*PFNGLINDEXFUNCEXTPROC)(unsigned func, TGLfloat ref);

typedef void __stdcall (*PFNGLLOCKARRAYSEXTPROC)(TGLint first, TGLsizei count);

typedef void __stdcall (*PFNGLUNLOCKARRAYSEXTPROC)(void);

typedef void __stdcall (*PFNGLDRAWRANGEELEMENTSEXTPROC)(unsigned mode, unsigned start, unsigned Aend, TGLsizei Count, unsigned Atype, void * indices);

typedef void __stdcall (*PFNGLBEGINSCENEEXTPROC)(void);

typedef void __stdcall (*PFNGLENDSCENEEXTPROC)(void);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3BEXTPROC)(TGLbyte red, TGLbyte green, TGLbyte blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3BVEXTPROC)(PGLbyte v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3DEXTPROC)(TGLdouble red, TGLdouble green, TGLdouble blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3DVEXTPROC)(PGLdouble v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3FEXTPROC)(TGLfloat red, TGLfloat green, TGLfloat blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3FVEXTPROC)(PGLfloat v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3IEXTPROC)(TGLint red, TGLint green, TGLint blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3IVEXTPROC)(PGLint v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3SEXTPROC)(TGLshort red, TGLshort green, TGLshort blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3SVEXTPROC)(PGLshort v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UBEXTPROC)(TGLubyte red, TGLubyte green, TGLubyte blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UBVEXTPROC)(PGLubyte v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UIEXTPROC)(unsigned red, unsigned green, unsigned blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3UIVEXTPROC)(PGLuint v);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3USEXTPROC)(TGLushort red, TGLushort green, TGLushort blue);

typedef void __stdcall (*PFNGLSECONDARYCOLOR3USVEXTPROC)(PGLushort v);

typedef void __stdcall (*PFNGLSECONDARYCOLORPOINTEREXTPROC)(TGLint Size, unsigned Atype, TGLsizei stride, void * p);

typedef void __stdcall (*PFNGLMULTIDRAWARRAYSEXTPROC)(unsigned mode, PGLint First, PGLsizei Count, TGLsizei primcount);

typedef void __stdcall (*PFNGLMULTIDRAWELEMENTSEXTPROC)(unsigned mode, PGLsizei Count, unsigned AType, void *indices, TGLsizei primcount);

typedef void __stdcall (*PFNGLFOGCOORDFEXTPROC)(TGLfloat coord);

typedef void __stdcall (*PFNGLFOGCOORDFVEXTPROC)(PGLfloat coord);

typedef void __stdcall (*PFNGLFOGCOORDDEXTPROC)(TGLdouble coord);

typedef void __stdcall (*PFNGLFOGCOORDDVEXTPROC)(PGLdouble coord);

typedef void __stdcall (*PFNGLFOGCOORDPOINTEREXTPROC)(unsigned AType, TGLsizei stride, void * p);

typedef void __stdcall (*PFNGLBLENDFUNCSEPARATEEXTPROC)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);

typedef void __stdcall (*PFNGLFLUSHVERTEXARRAYRANGENVPROC)(void);

typedef void __stdcall (*PFNGLVERTEXARRAYRANGENVPROC)(TGLsizei Size, void * p);

typedef void * __stdcall (*PFNWGLALLOCATEMEMORYNVPROC)(TGLsizei size, float readFrequency, float writeFrequency, float priority);

typedef void __stdcall (*PFNWGLFREEMEMORYNVPROC)(void * ptr);

typedef void __stdcall (*PFNGLCOMBINERPARAMETERFVNVPROC)(unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLCOMBINERPARAMETERFNVPROC)(unsigned pname, TGLfloat param);

typedef void __stdcall (*PFNGLCOMBINERPARAMETERIVNVPROC)(unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLCOMBINERPARAMETERINVPROC)(unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLCOMBINERINPUTNVPROC)(unsigned stage, unsigned portion, unsigned variable, unsigned input, unsigned mapping, unsigned componentUsage);

typedef void __stdcall (*PFNGLCOMBINEROUTPUTNVPROC)(unsigned stage, unsigned portion, unsigned abOutput, unsigned cdOutput, unsigned sumOutput, unsigned scale, unsigned bias, TGLboolean abDotProduct, TGLboolean cdDotProduct, TGLboolean muxSum);

typedef void __stdcall (*PFNGLFINALCOMBINERINPUTNVPROC)(unsigned variable, unsigned input, unsigned mapping, unsigned componentUsage);

typedef void __stdcall (*PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(unsigned stage, unsigned portion, unsigned variable, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(unsigned stage, unsigned portion, unsigned variable, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(unsigned stage, unsigned portion, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(unsigned stage, unsigned portion, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(unsigned variable, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(unsigned variable, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLRESIZEBUFFERSMESAPROC)(void);

typedef void __stdcall (*PFNGLTBUFFERMASK3DFXPROC)(unsigned mask);

typedef void __stdcall (*PFNGLSAMPLEMASKEXTPROC)(float Value, TGLboolean invert);

typedef void __stdcall (*PFNGLSAMPLEPATTERNEXTPROC)(unsigned pattern);

typedef void __stdcall (*PFNGLTEXTURECOLORMASKSGISPROC)(TGLboolean red, TGLboolean green, TGLboolean blue, TGLboolean alpha);

typedef void __stdcall (*PFNGLGENFENCESNVPROC)(TGLsizei n, PGLuint fences);

typedef void __stdcall (*PFNGLDELETEFENCESNVPROC)(TGLsizei n, PGLuint fences);

typedef void __stdcall (*PFNGLSETFENCENVPROC)(unsigned fence, unsigned condition);

typedef TGLboolean __stdcall (*PFNGLTESTFENCENVPROC)(unsigned fence);

typedef void __stdcall (*PFNGLFINISHFENCENVPROC)(unsigned fence);

typedef TGLboolean __stdcall (*PFNGLISFENCENVPROC)(unsigned fence);

typedef void __stdcall (*PFNGLGETFENCEIVNVPROC)(unsigned fence, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLAREPROGRAMSRESIDENTNVPROC)(TGLsizei n, PGLuint programs, PGLboolean residences);

typedef void __stdcall (*PFNGLBINDPROGRAMNVPROC)(unsigned target, unsigned id);

typedef void __stdcall (*PFNGLDELETEPROGRAMSNVPROC)(TGLsizei n, PGLuint programs);

typedef void __stdcall (*PFNGLEXECUTEPROGRAMNVPROC)(unsigned target, unsigned id, PGLfloat params);

typedef void __stdcall (*PFNGLGENPROGRAMSNVPROC)(TGLsizei n, PGLuint programs);

typedef void __stdcall (*PFNGLGETPROGRAMPARAMETERDVNVPROC)(unsigned target, unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLGETPROGRAMPARAMETERFVNVPROC)(unsigned target, unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETPROGRAMIVNVPROC)(unsigned id, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETPROGRAMSTRINGNVPROC)(unsigned id, unsigned pname, PGLubyte programIdx);

typedef void __stdcall (*PFNGLGETTRACKMATRIXIVNVPROC)(unsigned target, unsigned address, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBDVNVPROC)(unsigned index, unsigned pname, PGLdouble params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBFVNVPROC)(unsigned index, unsigned pname, PGLfloat params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIVNVPROC)(unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(unsigned index, unsigned pname, PGLPointer pointer);

typedef TGLboolean __stdcall (*PFNGLISPROGRAMNVPROC)(unsigned id);

typedef void __stdcall (*PFNGLLOADPROGRAMNVPROC)(unsigned target, unsigned id, TGLsizei len, PGLubyte programIdx);

typedef void __stdcall (*PFNGLPROGRAMPARAMETER4DNVPROC)(unsigned target, unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLPROGRAMPARAMETER4DVNVPROC)(unsigned target, unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLPROGRAMPARAMETER4FNVPROC)(unsigned target, unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLPROGRAMPARAMETER4FVNVPROC)(unsigned target, unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLPROGRAMPARAMETERS4DVNVPROC)(unsigned target, unsigned index, TGLsizei count, PGLdouble v);

typedef void __stdcall (*PFNGLPROGRAMPARAMETERS4FVNVPROC)(unsigned target, unsigned index, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(TGLsizei n, PGLuint programs);

typedef void __stdcall (*PFNGLTRACKMATRIXNVPROC)(unsigned target, unsigned address, unsigned matrix, unsigned transform);

typedef void __stdcall (*PFNGLVERTEXATTRIBPOINTERNVPROC)(unsigned index, TGLint fsize, unsigned vertextype, TGLsizei stride, void * pointer);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DNVPROC)(unsigned index, TGLdouble x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1DVNVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FNVPROC)(unsigned index, TGLfloat x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1FVNVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SNVPROC)(unsigned index, TGLshort x);

typedef void __stdcall (*PFNGLVERTEXATTRIB1SVNVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DNVPROC)(unsigned index, TGLdouble x, TGLdouble y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2DVNVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FNVPROC)(unsigned index, TGLfloat x, TGLfloat y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2FVNVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SNVPROC)(unsigned index, TGLshort x, TGLshort y);

typedef void __stdcall (*PFNGLVERTEXATTRIB2SVNVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DNVPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3DVNVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FNVPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3FVNVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SNVPROC)(unsigned index, TGLshort x, TGLshort y, TGLshort z);

typedef void __stdcall (*PFNGLVERTEXATTRIB3SVNVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DNVPROC)(unsigned index, TGLdouble x, TGLdouble y, TGLdouble z, TGLdouble w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4DVNVPROC)(unsigned index, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FNVPROC)(unsigned index, TGLfloat x, TGLfloat y, TGLfloat z, TGLfloat w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4FVNVPROC)(unsigned index, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SNVPROC)(unsigned index, TGLshort x, TGLshort y, TGLdouble z, TGLshort w);

typedef void __stdcall (*PFNGLVERTEXATTRIB4SVNVPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIB4UBVNVPROC)(unsigned index, PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS1DVNVPROC)(unsigned index, TGLsizei count, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS1FVNVPROC)(unsigned index, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS1SVNVPROC)(unsigned index, TGLsizei count, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS2DVNVPROC)(unsigned index, TGLsizei count, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS2FVNVPROC)(unsigned index, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS2SVNVPROC)(unsigned index, TGLsizei count, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS3DVNVPROC)(unsigned index, TGLsizei count, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS3FVNVPROC)(unsigned index, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS3SVNVPROC)(unsigned index, TGLsizei count, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS4DVNVPROC)(unsigned index, TGLsizei count, PGLdouble v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS4FVNVPROC)(unsigned index, TGLsizei count, PGLfloat v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS4SVNVPROC)(unsigned index, TGLsizei count, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBS4UBVNVPROC)(unsigned index, TGLsizei count, PGLubyte v);

typedef void __stdcall (*PFNGLGENOCCLUSIONQUERIESNVPROC)(TGLsizei n, PGLuint ids);

typedef void __stdcall (*PFNGLDELETEOCCLUSIONQUERIESNVPROC)(TGLsizei n, const PGLuint ids);

typedef TGLboolean __stdcall (*PFNGLISOCCLUSIONQUERYNVPROC)(unsigned id);

typedef void __stdcall (*PFNGLBEGINOCCLUSIONQUERYNVPROC)(unsigned id);

typedef void __stdcall (*PFNGLENDOCCLUSIONQUERYNVPROC)(void);

typedef void __stdcall (*PFNGLGETOCCLUSIONQUERYIVNVPROC)(unsigned id, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETOCCLUSIONQUERYUIVNVPROC)(unsigned id, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLPOINTPARAMETERINVPROC)(unsigned pname, TGLint param);

typedef void __stdcall (*PFNGLPOINTPARAMETERIVNVPROC)(unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLACTIVESTENCILFACEEXTPROC)(unsigned face);

typedef void __stdcall (*PFNGLDRAWBUFFERSATIPROC)(TGLsizei n, const System::PCardinal bufs);

typedef void __stdcall (*PFNGLPRIMITIVERESTARTNVPROC)(void);

typedef void __stdcall (*PFNGLPRIMITIVERESTARTINDEXNVPROC)(unsigned index);

typedef void __stdcall (*PFNGLDEPTHBOUNDSEXTPROC)(TGLclampd zmin, TGLclampd zmax);

typedef void __stdcall (*PFNGLBLENDEQUATIONSEPARATEEXTPROC)(unsigned modeRGB, unsigned modeAlpha);

typedef TGLboolean __stdcall (*PFNGLISRENDERBUFFEREXTPROC)(unsigned renderbuffer);

typedef void __stdcall (*PFNGLBINDRENDERBUFFEREXTPROC)(unsigned target, unsigned renderbuffer);

typedef void __stdcall (*PFNGLDELETERENDERBUFFERSEXTPROC)(TGLsizei n, PGLuint renderbuffers);

typedef void __stdcall (*PFNGLGENRENDERBUFFERSEXTPROC)(TGLsizei n, PGLuint renderbuffers);

typedef void __stdcall (*PFNGLRENDERBUFFERSTORAGEEXTPROC)(unsigned target, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(unsigned target, unsigned pname, PGLint params);

typedef TGLboolean __stdcall (*PFNGLISFRAMEBUFFEREXTPROC)(unsigned framebuffer);

typedef void __stdcall (*PFNGLBINDFRAMEBUFFEREXTPROC)(unsigned target, unsigned framebuffer);

typedef void __stdcall (*PFNGLDELETEFRAMEBUFFERSEXTPROC)(TGLsizei n, PGLuint framebuffers);

typedef void __stdcall (*PFNGLGENFRAMEBUFFERSEXTPROC)(TGLsizei n, PGLuint framebuffers);

typedef unsigned __stdcall (*PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(unsigned target);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(unsigned target, unsigned attachment, unsigned textarget, unsigned texture, TGLint level, TGLint zoffset);

typedef void __stdcall (*PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(unsigned target, unsigned attachment, unsigned renderbuffertarget, unsigned renderbuffer);

typedef void __stdcall (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(unsigned target, unsigned attachment, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGENERATEMIPMAPEXTPROC)(unsigned target);

typedef void __stdcall (*PFNGLSTRINGMARKERGREMEDYPROC)(TGLsizei len, char * str);

typedef void __stdcall (*PFNGLSTENCILCLEARTAGEXTPROC)(TGLsizei stencilTagBits, unsigned stencilClearTag);

typedef void __stdcall (*PFNGLBLITFRAMEBUFFEREXTPROC)(TGLint srcX0, TGLint srcY0, TGLint srcX1, TGLint srcY1, TGLint dstX0, TGLint dstY0, TGLint dstX1, TGLint dstY1, TGLbitfield mask, unsigned filter);

typedef void __stdcall (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(unsigned target, TGLsizei samples, unsigned internalformat, TGLsizei width, TGLsizei height);

typedef void __stdcall (*PFNGLGETQUERYOBJECTI64VEXTPROC)(unsigned id, unsigned pname, PGLint64EXT params);

typedef void __stdcall (*PFNGLGETQUERYOBJECTUI64VEXTPROC)(unsigned id, unsigned pname, PGLuint64EXT params);

typedef void __stdcall (*PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(unsigned target, unsigned index, TGLsizei count, const PGLfloat params);

typedef void __stdcall (*PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(unsigned target, unsigned index, TGLsizei count, const PGLfloat params);

typedef void __stdcall (*PFNGLPROGRAMVERTEXLIMITNVPROC)(unsigned target, TGLint limit);

typedef void __stdcall (*PFNGLPROGRAMPARAMETERIEXTPROC)(unsigned _program, unsigned pname, TGLint value);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTUREEXTPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level, TGLint layer);

typedef void __stdcall (*PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(unsigned target, unsigned attachment, unsigned texture, TGLint level, unsigned face);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1IEXTPROC)(unsigned index, TGLint x);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2IEXTPROC)(unsigned index, TGLint x, TGLint y);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3IEXTPROC)(unsigned index, TGLint x, TGLint y, TGLint z);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4IEXTPROC)(unsigned index, TGLint x, TGLint y, TGLint z, TGLint w);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1UIEXTPROC)(unsigned index, unsigned x);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2UIEXTPROC)(unsigned index, unsigned x, unsigned y);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3UIEXTPROC)(unsigned index, unsigned x, unsigned y, unsigned z);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UIEXTPROC)(unsigned index, unsigned x, unsigned y, unsigned z, unsigned w);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1IVEXTPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2IVEXTPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3IVEXTPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4IVEXTPROC)(unsigned index, PGLint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI1UIVEXTPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI2UIVEXTPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI3UIVEXTPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UIVEXTPROC)(unsigned index, PGLuint v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4BVEXTPROC)(unsigned index, PGLbyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4SVEXTPROC)(unsigned index, PGLshort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4UBVEXTPROC)(unsigned index, PGLubyte v);

typedef void __stdcall (*PFNGLVERTEXATTRIBI4USVEXTPROC)(unsigned index, PGLushort v);

typedef void __stdcall (*PFNGLVERTEXATTRIBIPOINTEREXTPROC)(unsigned index, TGLint size, unsigned _type, TGLsizei stride, void * _pointer);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIIVEXTPROC)(unsigned index, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETVERTEXATTRIBIUIVEXTPROC)(unsigned index, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLUNIFORM1UIEXTPROC)(TGLint location, unsigned v0);

typedef void __stdcall (*PFNGLUNIFORM2UIEXTPROC)(TGLint location, unsigned v0, unsigned v1);

typedef void __stdcall (*PFNGLUNIFORM3UIEXTPROC)(TGLint location, unsigned v0, unsigned v1, unsigned v2);

typedef void __stdcall (*PFNGLUNIFORM4UIEXTPROC)(TGLint location, unsigned v0, unsigned v1, unsigned v2, unsigned v3);

typedef void __stdcall (*PFNGLUNIFORM1UIVEXTPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM2UIVEXTPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM3UIVEXTPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLUNIFORM4UIVEXTPROC)(TGLint location, TGLsizei count, PGLuint value);

typedef void __stdcall (*PFNGLGETUNIFORMUIVEXTPROC)(unsigned _program, TGLint location, PGLuint params);

typedef void __stdcall (*PFNGLBINDFRAGDATALOCATIONEXTPROC)(unsigned _program, unsigned colorNumber, char * name);

typedef TGLint __stdcall (*PFNGLGETFRAGDATALOCATIONEXTPROC)(unsigned _program, char * name);

typedef void __stdcall (*PFNGLDRAWARRAYSINSTANCEDEXTPROC)(unsigned mode, TGLint first, TGLsizei count, TGLsizei primcount);

typedef void __stdcall (*PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(unsigned mode, TGLsizei count, unsigned _type, PGLvoid indices, TGLsizei primcount);

typedef void __stdcall (*PFNGLTEXBUFFEREXTPROC)(unsigned target, unsigned internalformat, unsigned buffer);

typedef void __stdcall (*PFNGLCOLORMASKINDEXEDEXTPROC)(unsigned buf, TGLboolean r, TGLboolean g, TGLboolean b, TGLboolean a);

typedef void __stdcall (*PFNGLGETBOOLEANINDEXEDVEXTPROC)(unsigned value, unsigned index, PGLboolean data);

typedef void __stdcall (*PFNGLGETINTEGERINDEXEDVEXTPROC)(unsigned value, unsigned index, PGLint data);

typedef void __stdcall (*PFNGLENABLEINDEXEDEXTPROC)(unsigned target, unsigned index);

typedef void __stdcall (*PFNGLDISABLEINDEXEDEXTPROC)(unsigned target, unsigned index);

typedef TGLboolean __stdcall (*PFNGLISENABLEDINDEXEDEXTPROC)(unsigned target, unsigned index);

typedef void __stdcall (*PFNGLBINDBUFFERRANGENVPROC)(unsigned target, unsigned index, unsigned buffer, TGLintptr offset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLBINDBUFFEROFFSETNVPROC)(unsigned target, unsigned index, unsigned buffer, TGLintptr offset);

typedef void __stdcall (*PFNGLBINDBUFFERBASENVPROC)(unsigned target, unsigned index, unsigned buffer);

typedef void __stdcall (*PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(TGLsizei count, PGLint attribs, unsigned bufferMode);

typedef void __stdcall (*PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(unsigned _program, TGLsizei count, PGLint locations, unsigned bufferMode);

typedef void __stdcall (*PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(unsigned primitiveMode);

typedef void __stdcall (*PFNGLENDTRANSFORMFEEDBACKNVPROC)(void);

typedef TGLint __stdcall (*PFNGLGETVARYINGLOCATIONNVPROC)(unsigned _program, char * name);

typedef void __stdcall (*PFNGLGETACTIVEVARYINGNVPROC)(unsigned _program, unsigned index, TGLsizei bufSize, PGLsizei length, PGLsizei size, unsigned _type, char * name);

typedef void __stdcall (*PFNGLACTIVEVARYINGNVPROC)(unsigned _program, char * name);

typedef void __stdcall (*PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(unsigned _program, unsigned index, PGLint location);

typedef void __stdcall (*PFNGLUNIFORMBUFFEREXTPROC)(unsigned _program, TGLint location, unsigned buffer);

typedef TGLint __stdcall (*PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(unsigned _program, TGLint location);

typedef PGLint __stdcall (*PFNGLGETUNIFORMOFFSETEXTPROC)(unsigned _program, TGLint location);

typedef void __stdcall (*PFNGLCLEARCOLORIIEXTPROC)(TGLint r, TGLint g, TGLint b, TGLint a);

typedef void __stdcall (*PFNGLCLEARCOLORIUIEXTPROC)(unsigned r, unsigned g, unsigned b, unsigned a);

typedef void __stdcall (*PFNGLTEXPARAMETERIIVEXTPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLTEXPARAMETERIUIVEXTPROC)(unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLGETTEXPARAMETERIIVEXTPROC)(unsigned target, unsigned pname, PGLint params);

typedef void __stdcall (*PFNGLGETTEXPARAMETERIUIVEXTPROC)(unsigned target, unsigned pname, PGLuint params);

typedef void __stdcall (*PFNGLFRAMETERMINATORGREMEDYPROC)(void);

typedef void __stdcall (*PFNGLBEGINCONDITIONALRENDERNVPROC)(unsigned id, unsigned mode);

typedef void __stdcall (*PFNGLENDCONDITIONALRENDERNVPROC)(void);

typedef void __stdcall (*PFNGLBINDBUFFERRANGEEXTPROC)(unsigned target, unsigned index, unsigned buffer, TGLintptr offset, TGLsizeiptr size);

typedef void __stdcall (*PFNGLBINDBUFFEROFFSETEXTPROC)(unsigned target, unsigned index, unsigned buffer, TGLintptr offset);

typedef void __stdcall (*PFNGLBINDBUFFERBASEEXTPROC)(unsigned target, unsigned index, unsigned buffer);

typedef void __stdcall (*PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(unsigned primitiveMode);

typedef void __stdcall (*PFNGLENDTRANSFORMFEEDBACKEXTPROC)(void);

typedef void __stdcall (*PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(unsigned _program, TGLsizei count, const PGLPCharArray varyings, unsigned bufferMode);

typedef void __stdcall (*PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(unsigned _program, unsigned index, TGLsizei bufSize, PGLsizei length, PGLsizei size, System::PCardinal _type, char * name);

typedef void __stdcall (*PFNGLTESSELLATIONFACTORAMDPROC)(TGLfloat factor);

typedef void __stdcall (*PFNGLTESSELLATIONMODEAMDPROC)(unsigned mode);

typedef void __stdcall (*PFNGLCOPYIMAGESUBDATANVPROC)(unsigned srcName, unsigned srcTarget, TGLint srcLevel, TGLint srcX, TGLint srcY, TGLint srcZ, unsigned dstName, unsigned dstTarget, TGLint dstLevel, TGLint dstX, TGLint dstY, TGLint dstZ, TGLsizei width, TGLsizei height, TGLsizei depth);

typedef void __stdcall (*PFNGLMAKEBUFFERRESIDENTNVPROC)(unsigned target, unsigned access);

typedef void __stdcall (*PFNGLMAKEBUFFERNONRESIDENTNVPROC)(unsigned target);

typedef TGLboolean __stdcall (*PFNGLISBUFFERRESIDENTNVPROC)(unsigned target);

typedef void __stdcall (*PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(unsigned buffer, unsigned access);

typedef void __stdcall (*PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(unsigned buffer);

typedef TGLboolean __stdcall (*PFNGLISNAMEDBUFFERRESIDENTNVPROC)(unsigned buffer);

typedef void __stdcall (*PFNGLGETBUFFERPARAMETERUI64VNVPROC)(unsigned target, unsigned pname, PGLuint64EXT params);

typedef void __stdcall (*PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(unsigned buffer, unsigned pname, PGLuint64EXT params);

typedef void __stdcall (*PFNGLGETINTEGERUI64VNVPROC)(unsigned value, PGLuint64EXT result);

typedef void __stdcall (*PFNGLUNIFORMUI64NVPROC)(TGLint location, TGLuint64EXT value);

typedef void __stdcall (*PFNGLUNIFORMUI64VNVPROC)(TGLint location, TGLsizei count, const PGLuint64EXT value);

typedef void __stdcall (*PFNGLGETUNIFORMUI64VNVPROC)(unsigned _program, TGLint location, PGLuint64EXT params);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMUI64NVPROC)(unsigned _program, TGLint location, TGLuint64EXT value);

typedef void __stdcall (*PFNGLPROGRAMUNIFORMUI64VNVPROC)(unsigned _program, TGLint location, TGLsizei count, const PGLuint64EXT value);

typedef void __stdcall (*PFNGLBUFFERADDRESSRANGENVPROC)(unsigned pname, unsigned index, TGLuint64EXT address, TGLsizeiptr length);

typedef void __stdcall (*PFNGLVERTEXFORMATNVPROC)(TGLint size, unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLNORMALFORMATNVPROC)(unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLCOLORFORMATNVPROC)(TGLint size, unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLINDEXFORMATNVPROC)(unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLTEXCOORDFORMATNVPROC)(TGLint size, unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLEDGEFLAGFORMATNVPROC)(TGLsizei stride);

typedef void __stdcall (*PFNGLSECONDARYCOLORFORMATNVPROC)(TGLint size, unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLFOGCOORDFORMATNVPROC)(unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLVERTEXATTRIBFORMATNVPROC)(unsigned index, TGLint size, unsigned _type, TGLboolean normalized, TGLsizei stride);

typedef void __stdcall (*PFNGLVERTEXATTRIBIFORMATNVPROC)(unsigned index, TGLint size, unsigned _type, TGLsizei stride);

typedef void __stdcall (*PFNGLGETINTEGERUI64I_VNVPROC)(unsigned value, unsigned index, PGLuint64EXT result);

typedef void __stdcall (*PGNGLGETBUFFERPARAMETERUI64VNV)(unsigned value, unsigned index, PGLuint64EXT result);

typedef unsigned __stdcall (*PFNGLGENPATHSNVPROC)(TGLsizei range);

typedef void __stdcall (*PFNGLDELETEPATHSNVPROC)(unsigned path, TGLsizei range);

typedef TGLboolean __stdcall (*PFNGLISPATHNVPROC)(unsigned path);

typedef void __stdcall (*PFNGLPATHCOMMANDSNVPROC)(unsigned path, TGLsizei numCommands, PGLubyte commands, TGLsizei numCoords, unsigned coordType, PGLvoid coords);

typedef void __stdcall (*PFNGLPATHCOORDSNVPROC)(unsigned path, TGLsizei numCoords, unsigned coordType, PGLvoid coords);

typedef void __stdcall (*PFNGLPATHSUBCOMMANDSNVPROC)(unsigned path, TGLsizei commandStart, TGLsizei commandsToDelete, TGLsizei numCommands, PGLubyte commands, TGLsizei numCoords, unsigned coordType, PGLvoid coords);

typedef void __stdcall (*PFNGLPATHSUBCOORDSNVPROC)(unsigned path, TGLsizei coordStart, TGLsizei numCoords, unsigned coordType, PGLvoid coords);

typedef void __stdcall (*PFNGLPATHSTRINGNVPROC)(unsigned path, unsigned format, TGLsizei length, PGLvoid pathString);

typedef void __stdcall (*PFNGLPATHGLYPHSNVPROC)(unsigned firstPathName, unsigned fontTarget, PGLvoid fontName, TGLbitfield fontStyle, TGLsizei numGlyphs, unsigned _type, PGLvoid charcodes, unsigned handleMissingGlyphs, unsigned pathParameterTemplate, TGLfloat emScale);

typedef void __stdcall (*PFNGLPATHGLYPHRANGENVPROC)(unsigned firstPathName, unsigned fontTarget, char * fontName, TGLbitfield fontStyle, unsigned firstGlyph, TGLsizei numGlyphs, unsigned handleMissingGlyphs, unsigned pathParameterTemplate, TGLfloat emScale);

typedef void __stdcall (*PFNGLWEIGHTPATHSNVPROC)(unsigned resultPath, TGLsizei numPaths, PGLuint paths, PGLfloat weights);

typedef void __stdcall (*PFNGLCOPYPATHNVPROC)(unsigned resultPath, unsigned srcPath);

typedef void __stdcall (*PFNGLINTERPOLATEPATHSNVPROC)(unsigned resultPath, unsigned pathA, unsigned pathB, TGLfloat weight);

typedef void __stdcall (*PFNGLTRANSFORMPATHNVPROC)(unsigned resultPath, unsigned srcPath, unsigned transformType, PGLfloat transformValues);

typedef void __stdcall (*PFNGLPATHPARAMETERIVNVPROC)(unsigned path, unsigned pname, PGLint value);

typedef void __stdcall (*PFNGLPATHPARAMETERINVPROC)(unsigned path, unsigned pname, TGLint value);

typedef void __stdcall (*PFNGLPATHPARAMETERFVNVPROC)(unsigned path, unsigned pname, PGLfloat value);

typedef void __stdcall (*PFNGLPATHPARAMETERFNVPROC)(unsigned path, unsigned pname, TGLfloat value);

typedef void __stdcall (*PFNGLPATHDASHARRAYNVPROC)(unsigned path, TGLsizei dashCount, PGLfloat dashArray);

typedef void __stdcall (*PFNGLPATHSTENCILFUNCNVPROC)(unsigned func, TGLint ref, unsigned mask);

typedef void __stdcall (*PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(TGLfloat factor, TGLfloat units);

typedef void __stdcall (*PFNGLSTENCILFILLPATHNVPROC)(unsigned path, unsigned fillMode, unsigned mask);

typedef void __stdcall (*PFNGLSTENCILSTROKEPATHNVPROC)(unsigned path, TGLint reference, unsigned mask);

typedef void __stdcall (*PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, unsigned fillMode, unsigned mask, unsigned transformType, PGLfloat transformValues);

typedef void __stdcall (*PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, TGLint reference, unsigned mask, unsigned transformType, PGLfloat transformValues);

typedef void __stdcall (*PFNGLPATHCOVERDEPTHFUNCNVPROC)(unsigned func);

typedef void __stdcall (*PFNGLPATHCOLORGENNVPROC)(unsigned color, unsigned genMode, unsigned colorFormat, PGLfloat coeffs);

typedef void __stdcall (*PFNGLPATHTEXGENNVPROC)(unsigned texCoordSet, unsigned genMode, TGLint components, PGLfloat coeffs);

typedef void __stdcall (*PFNGLPATHFOGGENNVPROC)(unsigned genMode);

typedef void __stdcall (*PFNGLCOVERFILLPATHNVPROC)(unsigned path, unsigned coverMode);

typedef void __stdcall (*PFNGLCOVERSTROKEPATHNVPROC)(unsigned path, unsigned coverMode);

typedef void __stdcall (*PFNGLCOVERFILLPATHINSTANCEDNVPROC)(TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, unsigned coverMode, unsigned transformType, PGLfloat transformValues);

typedef void __stdcall (*PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, unsigned coverMode, unsigned transformType, PGLfloat transformValues);

typedef void __stdcall (*PFNGLGETPATHPARAMETERIVNVPROC)(unsigned path, unsigned pname, PGLint value);

typedef void __stdcall (*PFNGLGETPATHPARAMETERFVNVPROC)(unsigned path, unsigned pname, PGLfloat value);

typedef void __stdcall (*PFNGLGETPATHCOMMANDSNVPROC)(unsigned path, PGLubyte commands);

typedef void __stdcall (*PFNGLGETPATHCOORDSNVPROC)(unsigned path, PGLfloat coords);

typedef void __stdcall (*PFNGLGETPATHDASHARRAYNVPROC)(unsigned path, PGLfloat dashArray);

typedef void __stdcall (*PFNGLGETPATHMETRICSNVPROC)(TGLbitfield metricQueryMask, TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, TGLsizei stride, PGLfloat metrics);

typedef void __stdcall (*PFNGLGETPATHMETRICRANGENVPROC)(TGLbitfield metricQueryMask, unsigned firstPathName, TGLsizei numPaths, TGLsizei stride, PGLfloat metrics);

typedef void __stdcall (*PFNGLGETPATHSPACINGNVPROC)(unsigned pathListMode, TGLsizei numPaths, unsigned pathNameType, PGLvoid paths, unsigned pathBase, TGLfloat advanceScale, TGLfloat kerningScale, unsigned transformType, PGLfloat returnedSpacing);

typedef void __stdcall (*PFNGLGETPATHCOLORGENIVNVPROC)(unsigned color, unsigned pname, PGLint value);

typedef void __stdcall (*PFNGLGETPATHCOLORGENFVNVPROC)(unsigned color, unsigned pname, PGLfloat value);

typedef void __stdcall (*PFNGLGETPATHTEXGENIVNVPROC)(unsigned texCoordSet, unsigned pname, PGLint value);

typedef void __stdcall (*PFNGLGETPATHTEXGENFVNVPROC)(unsigned texCoordSet, unsigned pname, PGLfloat value);

typedef TGLboolean __stdcall (*PFNGLISPOINTINFILLPATHNVPROC)(unsigned path, unsigned mask, TGLfloat x, TGLfloat y);

typedef TGLboolean __stdcall (*PFNGLISPOINTINSTROKEPATHNVPROC)(unsigned path, TGLfloat x, TGLfloat y);

typedef TGLfloat __stdcall (*PFNGLGETPATHLENGTHNVPROC)(unsigned path, TGLsizei startSegment, TGLsizei numSegments);

typedef TGLboolean __stdcall (*PFNGLPOINTALONGPATHNVPROC)(unsigned path, TGLsizei startSegment, TGLsizei numSegments, TGLfloat distance, PGLfloat x, PGLfloat y, PGLfloat tangentX, PGLfloat tangentY);

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 WGL_FRONT_COLOR_BUFFER_BIT_ARB = System::Int8(0x1);
static _DELPHI_CONST System::Int8 WGL_BACK_COLOR_BUFFER_BIT_ARB = System::Int8(0x2);
static _DELPHI_CONST System::Int8 WGL_DEPTH_BUFFER_BIT_ARB = System::Int8(0x4);
static _DELPHI_CONST System::Int8 WGL_STENCIL_BUFFER_BIT_ARB = System::Int8(0x8);
static _DELPHI_CONST System::Word WGL_SAMPLE_BUFFERS_ARB = System::Word(0x2041);
static _DELPHI_CONST System::Word WGL_SAMPLES_ARB = System::Word(0x2042);
static _DELPHI_CONST System::Word WGL_NUMBER_PIXEL_FORMATS_ARB = System::Word(0x2000);
static _DELPHI_CONST System::Word WGL_DRAW_TO_WINDOW_ARB = System::Word(0x2001);
static _DELPHI_CONST System::Word WGL_DRAW_TO_BITMAP_ARB = System::Word(0x2002);
static _DELPHI_CONST System::Word WGL_ACCELERATION_ARB = System::Word(0x2003);
static _DELPHI_CONST System::Word WGL_NEED_PALETTE_ARB = System::Word(0x2004);
static _DELPHI_CONST System::Word WGL_NEED_SYSTEM_PALETTE_ARB = System::Word(0x2005);
static _DELPHI_CONST System::Word WGL_SWAP_LAYER_BUFFERS_ARB = System::Word(0x2006);
static _DELPHI_CONST System::Word WGL_SWAP_METHOD_ARB = System::Word(0x2007);
static _DELPHI_CONST System::Word WGL_NUMBER_OVERLAYS_ARB = System::Word(0x2008);
static _DELPHI_CONST System::Word WGL_NUMBER_UNDERLAYS_ARB = System::Word(0x2009);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_ARB = System::Word(0x200a);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_RED_VALUE_ARB = System::Word(0x2037);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_GREEN_VALUE_ARB = System::Word(0x2038);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_BLUE_VALUE_ARB = System::Word(0x2039);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_ALPHA_VALUE_ARB = System::Word(0x203a);
static _DELPHI_CONST System::Word WGL_TRANSPARENT_INDEX_VALUE_ARB = System::Word(0x203b);
static _DELPHI_CONST System::Word WGL_SHARE_DEPTH_ARB = System::Word(0x200c);
static _DELPHI_CONST System::Word WGL_SHARE_STENCIL_ARB = System::Word(0x200d);
static _DELPHI_CONST System::Word WGL_SHARE_ACCUM_ARB = System::Word(0x200e);
static _DELPHI_CONST System::Word WGL_SUPPORT_GDI_ARB = System::Word(0x200f);
static _DELPHI_CONST System::Word WGL_SUPPORT_OPENGL_ARB = System::Word(0x2010);
static _DELPHI_CONST System::Word WGL_DOUBLE_BUFFER_ARB = System::Word(0x2011);
static _DELPHI_CONST System::Word WGL_STEREO_ARB = System::Word(0x2012);
static _DELPHI_CONST System::Word WGL_PIXEL_TYPE_ARB = System::Word(0x2013);
static _DELPHI_CONST System::Word WGL_COLOR_BITS_ARB = System::Word(0x2014);
static _DELPHI_CONST System::Word WGL_RED_BITS_ARB = System::Word(0x2015);
static _DELPHI_CONST System::Word WGL_RED_SHIFT_ARB = System::Word(0x2016);
static _DELPHI_CONST System::Word WGL_GREEN_BITS_ARB = System::Word(0x2017);
static _DELPHI_CONST System::Word WGL_GREEN_SHIFT_ARB = System::Word(0x2018);
static _DELPHI_CONST System::Word WGL_BLUE_BITS_ARB = System::Word(0x2019);
static _DELPHI_CONST System::Word WGL_BLUE_SHIFT_ARB = System::Word(0x201a);
static _DELPHI_CONST System::Word WGL_ALPHA_BITS_ARB = System::Word(0x201b);
static _DELPHI_CONST System::Word WGL_ALPHA_SHIFT_ARB = System::Word(0x201c);
static _DELPHI_CONST System::Word WGL_ACCUM_BITS_ARB = System::Word(0x201d);
static _DELPHI_CONST System::Word WGL_ACCUM_RED_BITS_ARB = System::Word(0x201e);
static _DELPHI_CONST System::Word WGL_ACCUM_GREEN_BITS_ARB = System::Word(0x201f);
static _DELPHI_CONST System::Word WGL_ACCUM_BLUE_BITS_ARB = System::Word(0x2020);
static _DELPHI_CONST System::Word WGL_ACCUM_ALPHA_BITS_ARB = System::Word(0x2021);
static _DELPHI_CONST System::Word WGL_DEPTH_BITS_ARB = System::Word(0x2022);
static _DELPHI_CONST System::Word WGL_STENCIL_BITS_ARB = System::Word(0x2023);
static _DELPHI_CONST System::Word WGL_AUX_BUFFERS_ARB = System::Word(0x2024);
static _DELPHI_CONST System::Word WGL_NO_ACCELERATION_ARB = System::Word(0x2025);
static _DELPHI_CONST System::Word WGL_GENERIC_ACCELERATION_ARB = System::Word(0x2026);
static _DELPHI_CONST System::Word WGL_FULL_ACCELERATION_ARB = System::Word(0x2027);
static _DELPHI_CONST System::Word WGL_SWAP_EXCHANGE_ARB = System::Word(0x2028);
static _DELPHI_CONST System::Word WGL_SWAP_COPY_ARB = System::Word(0x2029);
static _DELPHI_CONST System::Word WGL_SWAP_UNDEFINED_ARB = System::Word(0x202a);
static _DELPHI_CONST System::Word WGL_TYPE_RGBA_ARB = System::Word(0x202b);
static _DELPHI_CONST System::Word WGL_TYPE_COLORINDEX_ARB = System::Word(0x202c);
static _DELPHI_CONST System::Word WGL_DRAW_TO_PBUFFER_ARB = System::Word(0x202d);
static _DELPHI_CONST System::Word WGL_MAX_PBUFFER_PIXELS_ARB = System::Word(0x202e);
static _DELPHI_CONST System::Word WGL_MAX_PBUFFER_WIDTH_ARB = System::Word(0x202f);
static _DELPHI_CONST System::Word WGL_MAX_PBUFFER_HEIGHT_ARB = System::Word(0x2030);
static _DELPHI_CONST System::Word WGL_PBUFFER_LARGEST_ARB = System::Word(0x2033);
static _DELPHI_CONST System::Word WGL_PBUFFER_WIDTH_ARB = System::Word(0x2034);
static _DELPHI_CONST System::Word WGL_PBUFFER_HEIGHT_ARB = System::Word(0x2035);
static _DELPHI_CONST System::Word WGL_PBUFFER_LOST_ARB = System::Word(0x2036);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RGB_ARB = System::Word(0x2070);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RGBA_ARB = System::Word(0x2071);
static _DELPHI_CONST System::Word WGL_TEXTURE_FORMAT_ARB = System::Word(0x2072);
static _DELPHI_CONST System::Word WGL_TEXTURE_TARGET_ARB = System::Word(0x2073);
static _DELPHI_CONST System::Word WGL_MIPMAP_TEXTURE_ARB = System::Word(0x2074);
static _DELPHI_CONST System::Word WGL_TEXTURE_RGB_ARB = System::Word(0x2075);
static _DELPHI_CONST System::Word WGL_TEXTURE_RGBA_ARB = System::Word(0x2076);
static _DELPHI_CONST System::Word WGL_NO_TEXTURE_ARB = System::Word(0x2077);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_ARB = System::Word(0x2078);
static _DELPHI_CONST System::Word WGL_TEXTURE_1D_ARB = System::Word(0x2079);
static _DELPHI_CONST System::Word WGL_TEXTURE_2D_ARB = System::Word(0x207a);
static _DELPHI_CONST System::Word WGL_MIPMAP_LEVEL_ARB = System::Word(0x207b);
static _DELPHI_CONST System::Word WGL_CUBE_MAP_FACE_ARB = System::Word(0x207c);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB = System::Word(0x207d);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = System::Word(0x207e);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = System::Word(0x207f);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = System::Word(0x2080);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = System::Word(0x2081);
static _DELPHI_CONST System::Word WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = System::Word(0x2082);
static _DELPHI_CONST System::Word WGL_FRONT_LEFT_ARB = System::Word(0x2083);
static _DELPHI_CONST System::Word WGL_FRONT_RIGHT_ARB = System::Word(0x2084);
static _DELPHI_CONST System::Word WGL_BACK_LEFT_ARB = System::Word(0x2085);
static _DELPHI_CONST System::Word WGL_BACK_RIGHT_ARB = System::Word(0x2086);
static _DELPHI_CONST System::Word WGL_AUX0_ARB = System::Word(0x2087);
static _DELPHI_CONST System::Word WGL_AUX1_ARB = System::Word(0x2088);
static _DELPHI_CONST System::Word WGL_AUX2_ARB = System::Word(0x2089);
static _DELPHI_CONST System::Word WGL_AUX3_ARB = System::Word(0x208a);
static _DELPHI_CONST System::Word WGL_AUX4_ARB = System::Word(0x208b);
static _DELPHI_CONST System::Word WGL_AUX5_ARB = System::Word(0x208c);
static _DELPHI_CONST System::Word WGL_AUX6_ARB = System::Word(0x208d);
static _DELPHI_CONST System::Word WGL_AUX7_ARB = System::Word(0x208e);
static _DELPHI_CONST System::Word WGL_AUX8_ARB = System::Word(0x208f);
static _DELPHI_CONST System::Word WGL_AUX9_ARB = System::Word(0x2090);
static _DELPHI_CONST System::Word WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB = System::Word(0x20a9);
static _DELPHI_CONST System::Word WGL_COLOR_SAMPLES_NV = System::Word(0x20b9);
static _DELPHI_CONST System::Word WGL_CONTEXT_MAJOR_VERSION_ARB = System::Word(0x2091);
static _DELPHI_CONST System::Word WGL_CONTEXT_MINOR_VERSION_ARB = System::Word(0x2092);
static _DELPHI_CONST System::Word WGL_CONTEXT_LAYER_PLANE_ARB = System::Word(0x2093);
static _DELPHI_CONST System::Word WGL_CONTEXT_FLAGS_ARB = System::Word(0x2094);
static _DELPHI_CONST System::Int8 WGL_CONTEXT_DEBUG_BIT_ARB = System::Int8(0x1);
static _DELPHI_CONST System::Int8 WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = System::Int8(0x2);
static _DELPHI_CONST System::Word ERROR_INVALID_VERSION_ARB = System::Word(0x2095);
static _DELPHI_CONST System::Int8 WGL_CONTEXT_ES2_PROFILE_BIT_EXT = System::Int8(0x4);
static _DELPHI_CONST System::Word WGL_CONTEXT_PROFILE_MASK_ARB = System::Word(0x9126);
static _DELPHI_CONST System::Int8 WGL_CONTEXT_CORE_PROFILE_BIT_ARB = System::Int8(0x1);
static _DELPHI_CONST System::Int8 WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = System::Int8(0x2);
static _DELPHI_CONST System::Word ERROR_INVALID_PROFILE_ARB = System::Word(0x2096);
static _DELPHI_CONST System::Word WGL_TYPE_RGBA_FLOAT_ATI = System::Word(0x21a0);
static _DELPHI_CONST System::Word WGL_FLOAT_COMPONENTS_NV = System::Word(0x20b0);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV = System::Word(0x20b1);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV = System::Word(0x20b2);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV = System::Word(0x20b3);
static _DELPHI_CONST System::Word WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV = System::Word(0x20b4);
static _DELPHI_CONST System::Word WGL_TEXTURE_FLOAT_R_NV = System::Word(0x20b5);
static _DELPHI_CONST System::Word WGL_TEXTURE_FLOAT_RG_NV = System::Word(0x20b6);
static _DELPHI_CONST System::Word WGL_TEXTURE_FLOAT_RGB_NV = System::Word(0x20b7);
static _DELPHI_CONST System::Word WGL_TEXTURE_FLOAT_RGBA_NV = System::Word(0x20b8);
static _DELPHI_CONST System::Word WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT = System::Word(0x20a8);
static _DELPHI_CONST System::Word GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT = System::Word(0x8cd8);
static _DELPHI_CONST System::Word GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI = System::Word(0x8837);
static _DELPHI_CONST System::Int8 WGL_ACCESS_READ_ONLY_NV = System::Int8(0x0);
static _DELPHI_CONST System::Int8 WGL_ACCESS_READ_WRITE_NV = System::Int8(0x1);
static _DELPHI_CONST System::Int8 WGL_ACCESS_WRITE_DISCARD_NV = System::Int8(0x2);
static _DELPHI_CONST int GLU_TESS_BEGIN = int(0x18704);
static _DELPHI_CONST int GLU_TESS_VERTEX = int(0x18705);
static _DELPHI_CONST int GLU_TESS_END = int(0x18706);
static _DELPHI_CONST int GLU_TESS_ERROR = int(0x18707);
static _DELPHI_CONST int GLU_TESS_EDGE_FLAG = int(0x18708);
static _DELPHI_CONST int GLU_TESS_COMBINE = int(0x18709);
static _DELPHI_CONST int GLU_TESS_BEGIN_DATA = int(0x1870a);
static _DELPHI_CONST int GLU_TESS_VERTEX_DATA = int(0x1870b);
static _DELPHI_CONST int GLU_TESS_END_DATA = int(0x1870c);
static _DELPHI_CONST int GLU_TESS_ERROR_DATA = int(0x1870d);
static _DELPHI_CONST int GLU_TESS_EDGE_FLAG_DATA = int(0x1870e);
static _DELPHI_CONST int GLU_TESS_COMBINE_DATA = int(0x1870f);
static _DELPHI_CONST int GLU_TESS_ERROR1 = int(0x18737);
static _DELPHI_CONST int GLU_TESS_ERROR2 = int(0x18738);
static _DELPHI_CONST int GLU_TESS_ERROR3 = int(0x18739);
static _DELPHI_CONST int GLU_TESS_ERROR4 = int(0x1873a);
static _DELPHI_CONST int GLU_TESS_ERROR5 = int(0x1873b);
static _DELPHI_CONST int GLU_TESS_ERROR6 = int(0x1873c);
static _DELPHI_CONST int GLU_TESS_ERROR7 = int(0x1873d);
static _DELPHI_CONST int GLU_TESS_ERROR8 = int(0x1873e);
static _DELPHI_CONST int GLU_TESS_MISSING_BEGIN_POLYGON = int(0x18737);
static _DELPHI_CONST int GLU_TESS_MISSING_BEGIN_CONTOUR = int(0x18738);
static _DELPHI_CONST int GLU_TESS_MISSING_END_POLYGON = int(0x18739);
static _DELPHI_CONST int GLU_TESS_MISSING_END_CONTOUR = int(0x1873a);
static _DELPHI_CONST int GLU_TESS_COORD_TOO_LARGE = int(0x1873b);
static _DELPHI_CONST int GLU_TESS_NEED_COMBINE_CALLBACK = int(0x1873c);
static _DELPHI_CONST int GLU_AUTO_LOAD_MATRIX = int(0x18768);
static _DELPHI_CONST int GLU_CULLING = int(0x18769);
static _DELPHI_CONST int GLU_SAMPLING_TOLERANCE = int(0x1876b);
static _DELPHI_CONST int GLU_DISPLAY_MODE = int(0x1876c);
static _DELPHI_CONST int GLU_PARAMETRIC_TOLERANCE = int(0x1876a);
static _DELPHI_CONST int GLU_SAMPLING_METHOD = int(0x1876d);
static _DELPHI_CONST int GLU_U_STEP = int(0x1876e);
static _DELPHI_CONST int GLU_V_STEP = int(0x1876f);
static _DELPHI_CONST int GLU_PATH_LENGTH = int(0x18777);
static _DELPHI_CONST int GLU_PARAMETRIC_ERROR = int(0x18778);
static _DELPHI_CONST int GLU_DOMAIN_DISTANCE = int(0x18779);
static _DELPHI_CONST int GLU_MAP1_TRIM_2 = int(0x18772);
static _DELPHI_CONST int GLU_MAP1_TRIM_3 = int(0x18773);
static _DELPHI_CONST int GLU_OUTLINE_POLYGON = int(0x18790);
static _DELPHI_CONST int GLU_OUTLINE_PATCH = int(0x18791);
static _DELPHI_CONST int GLU_NURBS_ERROR1 = int(0x1879b);
static _DELPHI_CONST int GLU_NURBS_ERROR2 = int(0x1879c);
static _DELPHI_CONST int GLU_NURBS_ERROR3 = int(0x1879d);
static _DELPHI_CONST int GLU_NURBS_ERROR4 = int(0x1879e);
static _DELPHI_CONST int GLU_NURBS_ERROR5 = int(0x1879f);
static _DELPHI_CONST int GLU_NURBS_ERROR6 = int(0x187a0);
static _DELPHI_CONST int GLU_NURBS_ERROR7 = int(0x187a1);
static _DELPHI_CONST int GLU_NURBS_ERROR8 = int(0x187a2);
static _DELPHI_CONST int GLU_NURBS_ERROR9 = int(0x187a3);
static _DELPHI_CONST int GLU_NURBS_ERROR10 = int(0x187a4);
static _DELPHI_CONST int GLU_NURBS_ERROR11 = int(0x187a5);
static _DELPHI_CONST int GLU_NURBS_ERROR12 = int(0x187a6);
static _DELPHI_CONST int GLU_NURBS_ERROR13 = int(0x187a7);
static _DELPHI_CONST int GLU_NURBS_ERROR14 = int(0x187a8);
static _DELPHI_CONST int GLU_NURBS_ERROR15 = int(0x187a9);
static _DELPHI_CONST int GLU_NURBS_ERROR16 = int(0x187aa);
static _DELPHI_CONST int GLU_NURBS_ERROR17 = int(0x187ab);
static _DELPHI_CONST int GLU_NURBS_ERROR18 = int(0x187ac);
static _DELPHI_CONST int GLU_NURBS_ERROR19 = int(0x187ad);
static _DELPHI_CONST int GLU_NURBS_ERROR20 = int(0x187ae);
static _DELPHI_CONST int GLU_NURBS_ERROR21 = int(0x187af);
static _DELPHI_CONST int GLU_NURBS_ERROR22 = int(0x187b0);
static _DELPHI_CONST int GLU_NURBS_ERROR23 = int(0x187b1);
static _DELPHI_CONST int GLU_NURBS_ERROR24 = int(0x187b2);
static _DELPHI_CONST int GLU_NURBS_ERROR25 = int(0x187b3);
static _DELPHI_CONST int GLU_NURBS_ERROR26 = int(0x187b4);
static _DELPHI_CONST int GLU_NURBS_ERROR27 = int(0x187b5);
static _DELPHI_CONST int GLU_NURBS_ERROR28 = int(0x187b6);
static _DELPHI_CONST int GLU_NURBS_ERROR29 = int(0x187b7);
static _DELPHI_CONST int GLU_NURBS_ERROR30 = int(0x187b8);
static _DELPHI_CONST int GLU_NURBS_ERROR31 = int(0x187b9);
static _DELPHI_CONST int GLU_NURBS_ERROR32 = int(0x187ba);
static _DELPHI_CONST int GLU_NURBS_ERROR33 = int(0x187bb);
static _DELPHI_CONST int GLU_NURBS_ERROR34 = int(0x187bc);
static _DELPHI_CONST int GLU_NURBS_ERROR35 = int(0x187bd);
static _DELPHI_CONST int GLU_NURBS_ERROR36 = int(0x187be);
static _DELPHI_CONST int GLU_NURBS_ERROR37 = int(0x187bf);
static _DELPHI_CONST int GLU_CW = int(0x18718);
static _DELPHI_CONST int GLU_CCW = int(0x18719);
static _DELPHI_CONST int GLU_INTERIOR = int(0x1871a);
static _DELPHI_CONST int GLU_EXTERIOR = int(0x1871b);
static _DELPHI_CONST int GLU_UNKNOWN = int(0x1871c);
static _DELPHI_CONST int GLU_BEGIN = int(0x18704);
static _DELPHI_CONST int GLU_VERTEX = int(0x18705);
static _DELPHI_CONST int GLU_END = int(0x18706);
static _DELPHI_CONST int GLU_ERROR = int(0x18707);
static _DELPHI_CONST int GLU_EDGE_FLAG = int(0x18708);
}	/* namespace Opengltokens */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_OPENGLTOKENS)
using namespace Stage::Opengltokens;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_OpenGLTokensHPP
