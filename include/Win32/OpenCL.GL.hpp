// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OpenCL.GL.pas' rev: 36.00 (Windows)

#ifndef OpenCL_GLHPP
#define OpenCL_GLHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <OpenCL.Import.hpp>
#include <OpenCL.Platform.hpp>

//-- user supplied -----------------------------------------------------------

namespace Opencl
{
namespace Gl
{
//-- forward type declarations -----------------------------------------------
struct DECLSPEC_DRECORD __GLsync
{
};


//-- type declarations -------------------------------------------------------
typedef unsigned *PGLuint;

typedef Opencl::Platform::Tcl_uint Tcl_gl_object_type;

typedef unsigned *Pcl_gl_object_type;

typedef Opencl::Platform::Tcl_uint Tcl_gl_texture_info;

typedef unsigned *Pcl_gl_texture_info;

typedef Opencl::Platform::Tcl_uint Tcl_gl_platform_info;

typedef unsigned *Pcl_gl_platform_info;

typedef __GLsync *Pcl_GLsync;

typedef Opencl::Platform::Tcl_uint Tcl_gl_context_info;

typedef unsigned *Pcl_gl_context_info;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word CL_GL_OBJECT_BUFFER = System::Word(0x2000);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE2D = System::Word(0x2001);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE3D = System::Word(0x2002);
static _DELPHI_CONST System::Word CL_GL_OBJECT_RENDERBUFFER = System::Word(0x2003);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE2D_ARRAY = System::Word(0x200e);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE1D = System::Word(0x200f);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE1D_ARRAY = System::Word(0x2010);
static _DELPHI_CONST System::Word CL_GL_OBJECT_TEXTURE_BUFFER = System::Word(0x2011);
static _DELPHI_CONST System::Word CL_GL_TEXTURE_TARGET = System::Word(0x2004);
static _DELPHI_CONST System::Word CL_GL_MIPMAP_LEVEL = System::Word(0x2005);
static _DELPHI_CONST System::Word CL_GL_NUM_SAMPLES = System::Word(0x2012);
extern "C" Opencl::Import::Tcl_mem __stdcall clCreateFromGLBuffer(Opencl::Import::Tcl_context context, Opencl::Import::Tcl_mem_flags flags, unsigned bufobj, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Import::Tcl_mem __stdcall clCreateFromGLTexture3D(Opencl::Import::Tcl_context context, Opencl::Import::Tcl_mem_flags flags, unsigned target, int miplevel, unsigned texture, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Import::Tcl_mem __stdcall clCreateFromGLRenderbuffer(Opencl::Import::Tcl_context context, Opencl::Import::Tcl_mem_flags flags, unsigned renderbuffer, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetGLObjectInfo(Opencl::Import::Tcl_mem memobj, Pcl_gl_object_type gl_object_type, PGLuint gl_object_name);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetGLTextureInfo(Opencl::Import::Tcl_mem memobj, Tcl_gl_texture_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueAcquireGLObjects(Opencl::Import::Tcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_objects, Opencl::Import::Pcl_mem mem_objects, Opencl::Platform::Tcl_uint num_events_in_wait_list, Opencl::Import::Pcl_event event_wait_list, Opencl::Import::Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueReleaseGLObjects(Opencl::Import::Tcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_objects, Opencl::Import::Pcl_mem mem_objects, Opencl::Platform::Tcl_uint num_events_in_wait_list, Opencl::Import::Pcl_event event_wait_list, Opencl::Import::Pcl_event event);
static _DELPHI_CONST System::Int8 cl_khr_gl_sharing = System::Int8(0x1);
static _DELPHI_CONST short CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR = short(-1000);
static _DELPHI_CONST System::Word CL_CURRENT_DEVICE_FOR_GL_CONTEXT_KHR = System::Word(0x2006);
static _DELPHI_CONST System::Word CL_DEVICES_FOR_GL_CONTEXT_KHR = System::Word(0x2007);
static _DELPHI_CONST System::Word CL_GL_CONTEXT_KHR = System::Word(0x2008);
static _DELPHI_CONST System::Word CL_EGL_DISPLAY_KHR = System::Word(0x2009);
static _DELPHI_CONST System::Word CL_GLX_DISPLAY_KHR = System::Word(0x200a);
static _DELPHI_CONST System::Word CL_WGL_HDC_KHR = System::Word(0x200b);
static _DELPHI_CONST System::Word CL_CGL_SHAREGROUP_KHR = System::Word(0x200c);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetGLContextInfoKHR(Opencl::Import::Tcl_context_properties properties, Tcl_gl_context_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
}	/* namespace Gl */
}	/* namespace Opencl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENCL_GL)
using namespace Opencl::Gl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENCL)
using namespace Opencl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OpenCL_GLHPP
