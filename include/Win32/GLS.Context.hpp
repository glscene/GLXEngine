// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Context.pas' rev: 36.00 (Windows)

#ifndef GLS_ContextHPP
#define GLS_ContextHPP

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
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.SyncObjs.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Consts.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.OpenGLAdapter.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GLS.State.hpp>
#include <GLS.XOpenGL.hpp>
#include <Stage.Logger.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Context
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TFinishTaskEvent;
struct TServiceContextTask;
class DELPHICLASS TGLContext;
class DELPHICLASS TGLScreenControlingContext;
struct TGLRCHandle;
class DELPHICLASS TGLContextHandle;
class DELPHICLASS TGLVirtualHandle;
class DELPHICLASS TGLVirtualHandleTransf;
class DELPHICLASS TGLListHandle;
class DELPHICLASS TGLTextureHandle;
class DELPHICLASS TGLSamplerHandle;
class DELPHICLASS TGLQueryHandle;
class DELPHICLASS TGLOcclusionQueryHandle;
class DELPHICLASS TGLBooleanOcclusionQueryHandle;
class DELPHICLASS TGLTimerQueryHandle;
class DELPHICLASS TGLPrimitiveQueryHandle;
class DELPHICLASS TGLBufferObjectHandle;
class DELPHICLASS TGLVBOHandle;
class DELPHICLASS TGLVBOArrayBufferHandle;
class DELPHICLASS TGLVBOElementArrayHandle;
class DELPHICLASS TGLPackPBOHandle;
class DELPHICLASS TGLUnpackPBOHandle;
class DELPHICLASS TGLTransformFeedbackBufferHandle;
class DELPHICLASS TGLTextureBufferHandle;
class DELPHICLASS TGLUniformBufferHandle;
class DELPHICLASS TGLVertexArrayHandle;
class DELPHICLASS TGLFramebufferHandle;
class DELPHICLASS TGLRenderbufferHandle;
class DELPHICLASS TGLARBProgramHandle;
class DELPHICLASS TGLARBVertexProgramHandle;
class DELPHICLASS TGLARBFragmentProgramHandle;
class DELPHICLASS TGLARBGeometryProgramHandle;
class DELPHICLASS TGLSLHandle;
class DELPHICLASS TGLShaderHandle;
class DELPHICLASS TGLVertexShaderHandle;
class DELPHICLASS TGLGeometryShaderHandle;
class DELPHICLASS TGLFragmentShaderHandle;
class DELPHICLASS TGLTessControlShaderHandle;
class DELPHICLASS TGLTessEvaluationShaderHandle;
class DELPHICLASS TGLProgramHandle;
struct TGLContextNotification;
class DELPHICLASS TGLContextManager;
class DELPHICLASS EGLContext;
class DELPHICLASS EGLShader;
class DELPHICLASS EPBuffer;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLRCOption : unsigned char { rcoDoubleBuffered, rcoStereo, rcoDebug, rcoOGL_ES };

typedef System::Set<TGLRCOption, TGLRCOption::rcoDoubleBuffered, TGLRCOption::rcoOGL_ES> TGLRCOptions;

enum DECLSPEC_DENUM TGLContextLayer : unsigned char { clUnderlay2, clUnderlay1, clMainPlane, clOverlay1, clOverlay2 };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFinishTaskEvent : public System::Syncobjs::TEvent
{
	typedef System::Syncobjs::TEvent inherited;
	
public:
	__fastcall TFinishTaskEvent();
public:
	/* THandleObject.Destroy */ inline __fastcall virtual ~TFinishTaskEvent() { }
	
};

#pragma pack(pop)

typedef void __stdcall (__closure *TTaskProcedure)(void);

struct DECLSPEC_DRECORD TServiceContextTask
{
public:
	TTaskProcedure Task;
	TFinishTaskEvent* Event;
};


enum DECLSPEC_DENUM TGLContextAcceleration : unsigned char { chaUnknown, chaHardware, chaSoftware };

enum DECLSPEC_DENUM TGLAntiAliasing : unsigned char { aaDefault, aaNone, aa2x, aa2xHQ, aa4x, aa4xHQ, aa6x, aa8x, aa16x, csa8x, csa8xHQ, csa16x, csa16xHQ };

enum DECLSPEC_DENUM TGLVSyncMode : unsigned char { vsmSync, vsmNoSync };

class PASCALIMPLEMENTATION TGLContext : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FColorBits;
	int FAlphaBits;
	int FDepthBits;
	int FStencilBits;
	int FAccumBits;
	int FAuxBuffers;
	TGLAntiAliasing FAntiAliasing;
	TGLRCOptions FOptions;
	System::Classes::TNotifyEvent FOnDestroyContext;
	TGLContextManager* FManager;
	int FActivationCount;
	int FOwnedHandlesCount;
	bool FIsPraparationNeed;
	void __fastcall SetColorBits(const int aColorBits);
	void __fastcall SetAlphaBits(const int aAlphaBits);
	void __fastcall SetDepthBits(const int val);
	void __fastcall SetStencilBits(const int aStencilBits);
	void __fastcall SetAccumBits(const int aAccumBits);
	void __fastcall SetAuxBuffers(const int aAuxBuffers);
	void __fastcall SetOptions(const TGLRCOptions aOptions);
	void __fastcall SetAntiAliasing(const TGLAntiAliasing val);
	void __fastcall SetAcceleration(const TGLContextAcceleration val);
	bool __fastcall GetActive();
	void __fastcall SetActive(const bool aActive);
	void __fastcall SetLayer(const TGLContextLayer Value);
	
protected:
	Gls::Opengladapter::TGLExtensionsAndEntryPoints* Fgl;
	Gls::Xopengl::TGLMultitextureCoordinator* Fxgl;
	Gls::State::TGLStateCache* FGLStates;
	Stage::Pipelinetransform::TgTransformation* FTransformation;
	TGLContextAcceleration FAcceleration;
	TGLContextLayer FLayer;
	System::Classes::TList* FSharedContexts;
	void __fastcall PropagateSharedContext();
	virtual void __fastcall DoCreateContext(HDC ADeviceHandle) = 0 ;
	virtual void __fastcall DoCreateMemoryContext(HWND outputDevice, int width, int height, int BufferCount = 0x1) = 0 ;
	virtual bool __fastcall DoShareLists(TGLContext* aContext) = 0 ;
	virtual void __fastcall DoDestroyContext() = 0 ;
	virtual void __fastcall DoActivate() = 0 ;
	virtual void __fastcall DoDeactivate() = 0 ;
	__classmethod TGLContext* __fastcall ServiceContext();
	void __fastcall MakeGLCurrent();
	
public:
	__fastcall virtual TGLContext();
	__fastcall virtual ~TGLContext();
	__property Gls::State::TGLStateCache* GLStates = {read=FGLStates};
	__property Stage::Pipelinetransform::TgTransformation* PipelineTransformation = {read=FTransformation};
	__property TGLContextManager* Manager = {read=FManager};
	__property int ColorBits = {read=FColorBits, write=SetColorBits, nodefault};
	__property int AlphaBits = {read=FAlphaBits, write=SetAlphaBits, nodefault};
	__property int DepthBits = {read=FDepthBits, write=SetDepthBits, nodefault};
	__property int StencilBits = {read=FStencilBits, write=SetStencilBits, nodefault};
	__property int AccumBits = {read=FAccumBits, write=SetAccumBits, nodefault};
	__property int AuxBuffers = {read=FAuxBuffers, write=SetAuxBuffers, nodefault};
	__property TGLAntiAliasing AntiAliasing = {read=FAntiAliasing, write=SetAntiAliasing, nodefault};
	__property TGLContextLayer Layer = {read=FLayer, write=SetLayer, nodefault};
	__property TGLRCOptions Options = {read=FOptions, write=SetOptions, nodefault};
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property TGLContextAcceleration Acceleration = {read=FAcceleration, write=SetAcceleration, nodefault};
	__property System::Classes::TNotifyEvent OnDestroyContext = {read=FOnDestroyContext, write=FOnDestroyContext};
	void __fastcall CreateContext(HDC ADeviceHandle)/* overload */;
	void __fastcall CreateMemoryContext(HWND outputDevice, int width, int height, int BufferCount = 0x1);
	void __fastcall ShareLists(TGLContext* aContext);
	void __fastcall DestroyContext();
	void __fastcall Activate();
	void __fastcall Deactivate();
	void __fastcall PrepareHandlesData();
	virtual bool __fastcall IsValid() = 0 ;
	virtual void __fastcall SwapBuffers() = 0 ;
	TGLContext* __fastcall FindCompatibleContext();
	void __fastcall DestroyAllHandles();
	virtual void * __fastcall RenderOutputDevice() = 0 ;
	__property Gls::Opengladapter::TGLExtensionsAndEntryPoints* GL = {read=Fgl};
	__property Gls::Xopengl::TGLMultitextureCoordinator* MultitextureCoordinator = {read=Fxgl};
	__property bool IsPraparationNeed = {read=FIsPraparationNeed, nodefault};
};


typedef System::TMetaClass* TGLContextClass;

class PASCALIMPLEMENTATION TGLScreenControlingContext : public TGLContext
{
	typedef TGLContext inherited;
	
private:
	int FWidth;
	int FHeight;
	bool FFullScreen;
	
public:
	__property int Width = {read=FWidth, write=FWidth, nodefault};
	__property int Height = {read=FHeight, write=FHeight, nodefault};
	__property bool FullScreen = {read=FFullScreen, write=FFullScreen, nodefault};
public:
	/* TGLContext.Create */ inline __fastcall virtual TGLScreenControlingContext() : TGLContext() { }
	/* TGLContext.Destroy */ inline __fastcall virtual ~TGLScreenControlingContext() { }
	
};


typedef TGLRCHandle *PGLRCHandle;

struct DECLSPEC_DRECORD TGLRCHandle
{
public:
	TGLContext* FRenderingContext;
	Stage::Opengltokens::TGLuint FHandle;
	bool FChanged;
};


typedef void __fastcall (__closure *TOnPrepareHandleData)(TGLContext* aContext);

class PASCALIMPLEMENTATION TGLContextHandle : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FHandles;
	PGLRCHandle FLastHandle;
	TOnPrepareHandleData FOnPrepare;
	Stage::Opengltokens::TGLuint __fastcall GetHandle();
	TGLContext* __fastcall GetContext();
	PGLRCHandle __fastcall SearchRC(TGLContext* aContext);
	PGLRCHandle __fastcall RCItem(int AIndex);
	void __fastcall CheckCurrentRC();
	
protected:
	void __fastcall ContextDestroying();
	__classmethod virtual bool __fastcall Transferable();
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle() = 0 ;
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle) = 0 ;
	
public:
	__fastcall virtual TGLContextHandle();
	__fastcall TGLContextHandle(bool failIfAllocationFailed);
	__fastcall virtual ~TGLContextHandle();
	__property Stage::Opengltokens::TGLuint Handle = {read=GetHandle, nodefault};
	__property TGLContext* RenderingContext = {read=GetContext};
	bool __fastcall IsDataNeedUpdate();
	bool __fastcall IsDataComplitelyUpdated();
	void __fastcall NotifyDataUpdated();
	void __fastcall NotifyChangesOfData();
	__classmethod virtual bool __fastcall IsSupported();
	bool __fastcall IsAllocatedForContext(TGLContext* aContext = (TGLContext*)(0x0));
	bool __fastcall IsShared();
	Stage::Opengltokens::TGLuint __fastcall AllocateHandle();
	void __fastcall DestroyHandle();
	__property TOnPrepareHandleData OnPrapare = {read=FOnPrepare, write=FOnPrepare};
};


typedef void __fastcall (__closure *TGLVirtualHandleEvent)(TGLVirtualHandle* Sender, Stage::Opengltokens::TGLuint &Handle);

class PASCALIMPLEMENTATION TGLVirtualHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
private:
	TGLVirtualHandleEvent FOnAllocate;
	TGLVirtualHandleEvent FOnDestroy;
	int FTag;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall Transferable();
	
public:
	__property TGLVirtualHandleEvent OnAllocate = {read=FOnAllocate, write=FOnAllocate};
	__property TGLVirtualHandleEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property int Tag = {read=FTag, write=FTag, nodefault};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVirtualHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVirtualHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVirtualHandle() { }
	
};


class PASCALIMPLEMENTATION TGLVirtualHandleTransf : public TGLVirtualHandle
{
	typedef TGLVirtualHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVirtualHandleTransf() : TGLVirtualHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVirtualHandleTransf(bool failIfAllocationFailed) : TGLVirtualHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVirtualHandleTransf() { }
	
};


class PASCALIMPLEMENTATION TGLListHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall NewList(Stage::Opengltokens::TGLuint mode);
	void __fastcall EndList();
	void __fastcall CallList();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLListHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLListHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLListHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTextureHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
private:
	Stage::Textureformat::TglTextureTarget FTarget;
	void __fastcall SetTarget(Stage::Textureformat::TglTextureTarget ATarget);
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	__property Stage::Textureformat::TglTextureTarget Target = {read=FTarget, write=SetTarget, nodefault};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLTextureHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTextureHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTextureHandle() { }
	
};


class PASCALIMPLEMENTATION TGLSamplerHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLSamplerHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLSamplerHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLSamplerHandle() { }
	
};


class PASCALIMPLEMENTATION TGLQueryHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
private:
	bool FActive;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget() = 0 ;
	virtual Gls::State::TGLQueryType __fastcall GetQueryType() = 0 ;
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall BeginQuery();
	void __fastcall EndQuery();
	bool __fastcall IsResultAvailable();
	int __fastcall CounterBits();
	Stage::Opengltokens::TGLint __fastcall QueryResultInt();
	Stage::Opengltokens::TGLuint __fastcall QueryResultUInt();
	Stage::Opengltokens::TGLint64EXT __fastcall QueryResultInt64();
	Stage::Opengltokens::TGLuint64EXT __fastcall QueryResultUInt64();
	Stage::Opengltokens::TGLboolean __fastcall QueryResultBool();
	__property Stage::Opengltokens::TGLuint Target = {read=GetTarget, nodefault};
	__property Gls::State::TGLQueryType QueryType = {read=GetQueryType, nodefault};
	__property bool Active = {read=FActive, nodefault};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLQueryHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLQueryHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TGLOcclusionQueryHandle : public TGLQueryHandle
{
	typedef TGLQueryHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	virtual Gls::State::TGLQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall PixelCount();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLOcclusionQueryHandle() : TGLQueryHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLOcclusionQueryHandle(bool failIfAllocationFailed) : TGLQueryHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLOcclusionQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TGLBooleanOcclusionQueryHandle : public TGLQueryHandle
{
	typedef TGLQueryHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	virtual Gls::State::TGLQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLBooleanOcclusionQueryHandle() : TGLQueryHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLBooleanOcclusionQueryHandle(bool failIfAllocationFailed) : TGLQueryHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLBooleanOcclusionQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTimerQueryHandle : public TGLQueryHandle
{
	typedef TGLQueryHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	virtual Gls::State::TGLQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall Time();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLTimerQueryHandle() : TGLQueryHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTimerQueryHandle(bool failIfAllocationFailed) : TGLQueryHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTimerQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TGLPrimitiveQueryHandle : public TGLQueryHandle
{
	typedef TGLQueryHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	virtual Gls::State::TGLQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall PrimitivesGenerated();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLPrimitiveQueryHandle() : TGLQueryHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLPrimitiveQueryHandle(bool failIfAllocationFailed) : TGLQueryHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLPrimitiveQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TGLBufferObjectHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
private:
	int FSize;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget() = 0 ;
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	__fastcall TGLBufferObjectHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage);
	virtual void __fastcall Bind() = 0 ;
	virtual void __fastcall UnBind() = 0 ;
	virtual void __fastcall BindRange(Stage::Opengltokens::TGLuint index, Stage::Opengltokens::TGLintptr offset, Stage::Opengltokens::TGLsizeiptr size);
	virtual void __fastcall BindBase(Stage::Opengltokens::TGLuint index);
	virtual void __fastcall UnBindBase(Stage::Opengltokens::TGLuint index);
	void __fastcall BufferData(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage);
	void __fastcall BindBufferData(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage);
	void __fastcall BufferSubData(int offset, int size, void * p);
	void * __fastcall MapBuffer(Stage::Opengltokens::TGLuint access);
	void * __fastcall MapBufferRange(Stage::Opengltokens::TGLint offset, Stage::Opengltokens::TGLsizei len, Stage::Opengltokens::TGLbitfield access);
	void __fastcall Flush(Stage::Opengltokens::TGLint offset, Stage::Opengltokens::TGLsizei len);
	bool __fastcall UnmapBuffer();
	__classmethod virtual bool __fastcall IsSupported();
	__property Stage::Opengltokens::TGLuint Target = {read=GetTarget, nodefault};
	__property int BufferSize = {read=FSize, nodefault};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLBufferObjectHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLBufferObjectHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLBufferObjectHandle() { }
	
};


class PASCALIMPLEMENTATION TGLVBOHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
private:
	Stage::Opengltokens::TGLuint __fastcall GetVBOTarget();
	
public:
	__property Stage::Opengltokens::TGLuint VBOTarget = {read=GetVBOTarget, nodefault};
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLVBOHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVBOHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVBOHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVBOHandle() { }
	
};


class PASCALIMPLEMENTATION TGLVBOArrayBufferHandle : public TGLVBOHandle
{
	typedef TGLVBOHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLVBOArrayBufferHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLVBOHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVBOArrayBufferHandle() : TGLVBOHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVBOArrayBufferHandle(bool failIfAllocationFailed) : TGLVBOHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVBOArrayBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLVBOElementArrayHandle : public TGLVBOHandle
{
	typedef TGLVBOHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLVBOElementArrayHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLVBOHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVBOElementArrayHandle() : TGLVBOHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVBOElementArrayHandle(bool failIfAllocationFailed) : TGLVBOHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVBOElementArrayHandle() { }
	
};


class PASCALIMPLEMENTATION TGLPackPBOHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLPackPBOHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLPackPBOHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLPackPBOHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLPackPBOHandle() { }
	
};


class PASCALIMPLEMENTATION TGLUnpackPBOHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLUnpackPBOHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLUnpackPBOHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLUnpackPBOHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLUnpackPBOHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTransformFeedbackBufferHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	void __fastcall BeginTransformFeedback(Stage::Opengltokens::TGLuint primitiveMode);
	void __fastcall EndTransformFeedback();
	virtual void __fastcall BindRange(Stage::Opengltokens::TGLuint index, Stage::Opengltokens::TGLintptr offset, Stage::Opengltokens::TGLsizeiptr size);
	virtual void __fastcall BindBase(Stage::Opengltokens::TGLuint index);
	virtual void __fastcall UnBindBase(Stage::Opengltokens::TGLuint index);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLTransformFeedbackBufferHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLTransformFeedbackBufferHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTransformFeedbackBufferHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTransformFeedbackBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTextureBufferHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLTextureBufferHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLTextureBufferHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTextureBufferHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTextureBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLUniformBufferHandle : public TGLBufferObjectHandle
{
	typedef TGLBufferObjectHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	virtual void __fastcall BindRange(Stage::Opengltokens::TGLuint index, Stage::Opengltokens::TGLintptr offset, Stage::Opengltokens::TGLsizeiptr size);
	virtual void __fastcall BindBase(Stage::Opengltokens::TGLuint index);
	virtual void __fastcall UnBindBase(Stage::Opengltokens::TGLuint index);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLBufferObjectHandle.CreateFromData */ inline __fastcall TGLUniformBufferHandle(void * p, int size, Stage::Opengltokens::TGLuint bufferUsage) : TGLBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLUniformBufferHandle() : TGLBufferObjectHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLUniformBufferHandle(bool failIfAllocationFailed) : TGLBufferObjectHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLUniformBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLVertexArrayHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall Bind();
	void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLVertexArrayHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVertexArrayHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVertexArrayHandle() { }
	
};


enum DECLSPEC_DENUM TGLFramebufferStatus : unsigned char { fsComplete, fsIncompleteAttachment, fsIncompleteMissingAttachment, fsIncompleteDuplicateAttachment, fsIncompleteDimensions, fsIncompleteFormats, fsIncompleteDrawBuffer, fsIncompleteReadBuffer, fsUnsupported, fsIncompleteMultisample, fsStatusError };

class PASCALIMPLEMENTATION TGLFramebufferHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall Bind();
	void __fastcall BindForDrawing();
	void __fastcall BindForReading();
	void __fastcall UnBind();
	void __fastcall UnBindForDrawing();
	void __fastcall UnBindForReading();
	void __fastcall Attach1DTexture(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint textarget, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level);
	void __fastcall Attach2DTexture(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint textarget, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level);
	void __fastcall Attach3DTexture(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint textarget, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level, Stage::Opengltokens::TGLint Layer);
	void __fastcall AttachLayer(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level, Stage::Opengltokens::TGLint Layer);
	void __fastcall AttachRenderBuffer(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint renderbuffertarget, Stage::Opengltokens::TGLuint renderbuffer);
	void __fastcall AttachTexture(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level);
	void __fastcall AttachTextureLayer(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint texture, Stage::Opengltokens::TGLint level, Stage::Opengltokens::TGLint Layer);
	void __fastcall Blit(Stage::Opengltokens::TGLint srcX0, Stage::Opengltokens::TGLint srcY0, Stage::Opengltokens::TGLint srcX1, Stage::Opengltokens::TGLint srcY1, Stage::Opengltokens::TGLint dstX0, Stage::Opengltokens::TGLint dstY0, Stage::Opengltokens::TGLint dstX1, Stage::Opengltokens::TGLint dstY1, Stage::Opengltokens::TGLbitfield mask, Stage::Opengltokens::TGLuint filter);
	Stage::Opengltokens::TGLint __fastcall GetAttachmentParameter(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment, Stage::Opengltokens::TGLuint pname);
	Stage::Opengltokens::TGLint __fastcall GetAttachmentObjectType(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment);
	Stage::Opengltokens::TGLint __fastcall GetAttachmentObjectName(Stage::Opengltokens::TGLuint Target, Stage::Opengltokens::TGLuint attachment);
	TGLFramebufferStatus __fastcall GetStatus();
	TGLFramebufferStatus __fastcall GetStringStatus(/* out */ System::UnicodeString &clarification);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLFramebufferHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLFramebufferHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLFramebufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLRenderbufferHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall Bind();
	void __fastcall UnBind();
	void __fastcall SetStorage(Stage::Opengltokens::TGLuint internalformat, Stage::Opengltokens::TGLsizei width, Stage::Opengltokens::TGLsizei height);
	void __fastcall SetStorageMultisample(Stage::Opengltokens::TGLuint internalformat, Stage::Opengltokens::TGLsizei samples, Stage::Opengltokens::TGLsizei width, Stage::Opengltokens::TGLsizei height);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLRenderbufferHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLRenderbufferHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLRenderbufferHandle() { }
	
};


class PASCALIMPLEMENTATION TGLARBProgramHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
private:
	bool FReady;
	System::UnicodeString FInfoLog;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	virtual __classmethod Stage::Opengltokens::TGLuint __fastcall GetTarget() = 0 ;
	
public:
	void __fastcall LoadARBProgram(const System::UnicodeString AText);
	void __fastcall Enable();
	void __fastcall Disable();
	void __fastcall Bind();
	__property bool Ready = {read=FReady, nodefault};
	__property System::UnicodeString InfoLog = {read=FInfoLog};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLARBProgramHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLARBProgramHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLARBProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TGLARBVertexProgramHandle : public TGLARBProgramHandle
{
	typedef TGLARBProgramHandle inherited;
	
protected:
	__classmethod virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLARBVertexProgramHandle() : TGLARBProgramHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLARBVertexProgramHandle(bool failIfAllocationFailed) : TGLARBProgramHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLARBVertexProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TGLARBFragmentProgramHandle : public TGLARBProgramHandle
{
	typedef TGLARBProgramHandle inherited;
	
protected:
	__classmethod virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLARBFragmentProgramHandle() : TGLARBProgramHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLARBFragmentProgramHandle(bool failIfAllocationFailed) : TGLARBProgramHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLARBFragmentProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TGLARBGeometryProgramHandle : public TGLARBProgramHandle
{
	typedef TGLARBProgramHandle inherited;
	
protected:
	__classmethod virtual Stage::Opengltokens::TGLuint __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLARBGeometryProgramHandle() : TGLARBProgramHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLARBGeometryProgramHandle(bool failIfAllocationFailed) : TGLARBProgramHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLARBGeometryProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TGLSLHandle : public TGLContextHandle
{
	typedef TGLContextHandle inherited;
	
protected:
	virtual void __fastcall DoDestroyHandle(Stage::Opengltokens::TGLuint &AHandle);
	
public:
	System::UnicodeString __fastcall InfoLog();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLSLHandle() : TGLContextHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLSLHandle(bool failIfAllocationFailed) : TGLContextHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLSLHandle() { }
	
};


class PASCALIMPLEMENTATION TGLShaderHandle : public TGLSLHandle
{
	typedef TGLSLHandle inherited;
	
private:
	Stage::Opengltokens::TGLuint FShaderType;
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
public:
	void __fastcall ShaderSource(const System::AnsiString source)/* overload */;
	bool __fastcall CompileShader();
	__property Stage::Opengltokens::TGLuint ShaderType = {read=FShaderType, nodefault};
public:
	/* TGLContextHandle.Create */ inline __fastcall virtual TGLShaderHandle() : TGLSLHandle() { }
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLShaderHandle(bool failIfAllocationFailed) : TGLSLHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLShaderHandle() { }
	
};


typedef System::TMetaClass* TGLShaderHandleClass;

class PASCALIMPLEMENTATION TGLVertexShaderHandle : public TGLShaderHandle
{
	typedef TGLShaderHandle inherited;
	
public:
	__fastcall virtual TGLVertexShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLVertexShaderHandle(bool failIfAllocationFailed) : TGLShaderHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLVertexShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TGLGeometryShaderHandle : public TGLShaderHandle
{
	typedef TGLShaderHandle inherited;
	
public:
	__fastcall virtual TGLGeometryShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLGeometryShaderHandle(bool failIfAllocationFailed) : TGLShaderHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLGeometryShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TGLFragmentShaderHandle : public TGLShaderHandle
{
	typedef TGLShaderHandle inherited;
	
public:
	__fastcall virtual TGLFragmentShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLFragmentShaderHandle(bool failIfAllocationFailed) : TGLShaderHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLFragmentShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTessControlShaderHandle : public TGLShaderHandle
{
	typedef TGLShaderHandle inherited;
	
public:
	__fastcall virtual TGLTessControlShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTessControlShaderHandle(bool failIfAllocationFailed) : TGLShaderHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTessControlShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TGLTessEvaluationShaderHandle : public TGLShaderHandle
{
	typedef TGLShaderHandle inherited;
	
public:
	__fastcall virtual TGLTessEvaluationShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLTessEvaluationShaderHandle(bool failIfAllocationFailed) : TGLShaderHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLTessEvaluationShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TGLProgramHandle : public TGLSLHandle
{
	typedef TGLSLHandle inherited;
	
public:
	__classmethod virtual bool __fastcall IsValid(const Stage::Opengltokens::TGLuint ID);
	
private:
	System::UnicodeString FName;
	int __fastcall GetUniform1i(const System::UnicodeString index);
	void __fastcall SetUniform1i(const System::UnicodeString index, int val);
	Stage::Vectortypes::TVector2i __fastcall GetUniform2i(const System::UnicodeString index);
	void __fastcall SetUniform2i(const System::UnicodeString index, const Stage::Vectortypes::TVector2i &Value);
	Stage::Vectortypes::TVector3i __fastcall GetUniform3i(const System::UnicodeString index);
	void __fastcall SetUniform3i(const System::UnicodeString index, const Stage::Vectortypes::TVector3i &Value);
	Stage::Vectortypes::TVector4i __fastcall GetUniform4i(const System::UnicodeString index);
	void __fastcall SetUniform4i(const System::UnicodeString index, const Stage::Vectortypes::TVector4i &Value);
	float __fastcall GetUniform1f(const System::UnicodeString index);
	void __fastcall SetUniform1f(const System::UnicodeString index, float val);
	Stage::Vectortypes::TVector2f __fastcall GetUniform2f(const System::UnicodeString index);
	void __fastcall SetUniform2f(const System::UnicodeString index, const Stage::Vectortypes::TVector2f &val);
	Stage::Vectorgeometry::TAffineVector __fastcall GetUniform3f(const System::UnicodeString index);
	void __fastcall SetUniform3f(const System::UnicodeString index, const Stage::Vectorgeometry::TAffineVector &val);
	Stage::Vectortypes::TGLVector __fastcall GetUniform4f(const System::UnicodeString index);
	void __fastcall SetUniform4f(const System::UnicodeString index, const Stage::Vectortypes::TGLVector &val);
	Stage::Vectortypes::TMatrix2f __fastcall GetUniformMatrix2fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix2fv(const System::UnicodeString index, const Stage::Vectortypes::TMatrix2f &val);
	Stage::Vectortypes::TMatrix3f __fastcall GetUniformMatrix3fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix3fv(const System::UnicodeString index, const Stage::Vectortypes::TMatrix3f &val);
	Stage::Vectortypes::TGLMatrix __fastcall GetUniformMatrix4fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix4fv(const System::UnicodeString index, const Stage::Vectortypes::TGLMatrix &val);
	Stage::Opengltokens::TGLuint __fastcall GetUniformTextureHandle(const System::UnicodeString Index, const int TextureIndex, const Stage::Textureformat::TglTextureTarget TextureTarget);
	void __fastcall SetUniformTextureHandle(const System::UnicodeString Index, const int TextureIndex, const Stage::Textureformat::TglTextureTarget TextureTarget, const Stage::Opengltokens::TGLuint Value);
	void __fastcall SetUniformBuffer(const System::UnicodeString Index, TGLUniformBufferHandle* Value);
	
protected:
	virtual Stage::Opengltokens::TGLuint __fastcall DoAllocateHandle();
	
public:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__fastcall virtual TGLProgramHandle();
	void __fastcall AddShader(TGLShaderHandleClass ShaderType, const System::UnicodeString ShaderSource, bool treatWarningsAsErrors = false);
	void __fastcall AttachObject(TGLShaderHandle* shader);
	void __fastcall DetachAllObject();
	void __fastcall BindAttribLocation(int index, const System::UnicodeString aName);
	void __fastcall BindFragDataLocation(int index, const System::UnicodeString aName);
	bool __fastcall LinkProgram();
	bool __fastcall ValidateProgram();
	int __fastcall GetAttribLocation(const System::UnicodeString aName);
	int __fastcall GetUniformLocation(const System::UnicodeString aName);
	Stage::Opengltokens::PGLint __fastcall GetUniformOffset(const System::UnicodeString aName);
	int __fastcall GetUniformBlockIndex(const System::UnicodeString aName);
	int __fastcall GetVaryingLocation(const System::UnicodeString aName);
	void __fastcall AddActiveVarying(const System::UnicodeString aName);
	int __fastcall GetUniformBufferSize(const System::UnicodeString aName);
	void __fastcall UseProgramObject();
	void __fastcall EndUseProgramObject();
	void __fastcall SetUniformi(const System::UnicodeString index, const int val)/* overload */;
	void __fastcall SetUniformi(const System::UnicodeString index, const Stage::Vectortypes::TVector2i &val)/* overload */;
	void __fastcall SetUniformi(const System::UnicodeString index, const Stage::Vectortypes::TVector3i &val)/* overload */;
	void __fastcall SetUniformi(const System::UnicodeString index, const Stage::Vectortypes::TVector4i &val)/* overload */;
	void __fastcall SetUniformf(const System::UnicodeString index, const float val)/* overload */;
	void __fastcall SetUniformf(const System::UnicodeString index, const Stage::Vectortypes::TVector2f &val)/* overload */;
	void __fastcall SetUniformf(const System::UnicodeString index, const Stage::Vectortypes::TVector3f &val)/* overload */;
	void __fastcall SetUniformf(const System::UnicodeString index, const Stage::Vectortypes::TVector4f &val)/* overload */;
	__property int Uniform1i[const System::UnicodeString index] = {read=GetUniform1i, write=SetUniform1i};
	__property Stage::Vectortypes::TVector2i Uniform2i[const System::UnicodeString index] = {read=GetUniform2i, write=SetUniform2i};
	__property Stage::Vectortypes::TVector3i Uniform3i[const System::UnicodeString index] = {read=GetUniform3i, write=SetUniform3i};
	__property Stage::Vectortypes::TVector4i Uniform4i[const System::UnicodeString index] = {read=GetUniform4i, write=SetUniform4i};
	__property float Uniform1f[const System::UnicodeString index] = {read=GetUniform1f, write=SetUniform1f};
	__property Stage::Vectortypes::TVector2f Uniform2f[const System::UnicodeString index] = {read=GetUniform2f, write=SetUniform2f};
	__property Stage::Vectorgeometry::TAffineVector Uniform3f[const System::UnicodeString index] = {read=GetUniform3f, write=SetUniform3f};
	__property Stage::Vectortypes::TGLVector Uniform4f[const System::UnicodeString index] = {read=GetUniform4f, write=SetUniform4f};
	__property Stage::Vectortypes::TMatrix2f UniformMatrix2fv[const System::UnicodeString index] = {read=GetUniformMatrix2fv, write=SetUniformMatrix2fv};
	__property Stage::Vectortypes::TMatrix3f UniformMatrix3fv[const System::UnicodeString index] = {read=GetUniformMatrix3fv, write=SetUniformMatrix3fv};
	__property Stage::Vectortypes::TGLMatrix UniformMatrix4fv[const System::UnicodeString index] = {read=GetUniformMatrix4fv, write=SetUniformMatrix4fv};
	__property Stage::Opengltokens::TGLuint UniformTextureHandle[const System::UnicodeString index][const int TextureIndex][const Stage::Textureformat::TglTextureTarget TextureTarget] = {read=GetUniformTextureHandle, write=SetUniformTextureHandle};
	__property TGLUniformBufferHandle* UniformBuffer[const System::UnicodeString index] = {write=SetUniformBuffer};
public:
	/* TGLContextHandle.CreateAndAllocate */ inline __fastcall TGLProgramHandle(bool failIfAllocationFailed) : TGLSLHandle(failIfAllocationFailed) { }
	/* TGLContextHandle.Destroy */ inline __fastcall virtual ~TGLProgramHandle() { }
	
};


struct DECLSPEC_DRECORD TGLContextNotification
{
public:
	System::TObject* obj;
	System::Classes::TNotifyEvent Event;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLContextManager : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TGLContextNotification> _TGLContextManager__1;
	
	
private:
	System::Classes::TThreadList* FList;
	bool FTerminated;
	_TGLContextManager__1 FNotifications;
	int FCreatedRCCount;
	System::Classes::TList* FHandles;
	TGLContext* FServiceContext;
	
protected:
	void __fastcall Lock();
	void __fastcall UnLock();
	void __fastcall RegisterContext(TGLContext* aContext);
	void __fastcall UnRegisterContext(TGLContext* aContext);
	void __fastcall ContextCreatedBy(TGLContext* aContext);
	void __fastcall DestroyingContextBy(TGLContext* aContext);
	__property TGLContext* ServiceContext = {read=FServiceContext};
	
public:
	__fastcall TGLContextManager();
	__fastcall virtual ~TGLContextManager();
	TGLContext* __fastcall CreateContext(TGLContextClass AClass = 0x0);
	int __fastcall ContextCount();
	void __fastcall LastContextDestroyNotification(System::TObject* anObject, System::Classes::TNotifyEvent anEvent);
	void __fastcall RemoveNotification(System::TObject* anObject);
	void __fastcall Terminate();
	void __fastcall DestroyAllHandles();
	void __fastcall NotifyPreparationNeed();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLContext : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLContext(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLContext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLContext(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLContext(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLContext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLContext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLContext(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLContext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLContext(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLContext(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLContext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLContext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLContext() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLShader : public EGLContext
{
	typedef EGLContext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLShader(const System::UnicodeString Msg) : EGLContext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLShader(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EGLContext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLShader(System::NativeUInt Ident)/* overload */ : EGLContext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLShader(System::PResStringRec ResStringRec)/* overload */ : EGLContext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLShader(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGLContext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLShader(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EGLContext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLShader(const System::UnicodeString Msg, int AHelpContext) : EGLContext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLShader(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EGLContext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLShader(System::NativeUInt Ident, int AHelpContext)/* overload */ : EGLContext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLShader(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EGLContext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLShader(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGLContext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLShader(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EGLContext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLShader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EPBuffer : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EPBuffer(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EPBuffer(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EPBuffer(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EPBuffer(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EPBuffer(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EPBuffer(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EPBuffer(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EPBuffer(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPBuffer(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EPBuffer(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPBuffer(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EPBuffer(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EPBuffer() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<unsigned, 4> MRT_BUFFERS;
extern DELPHI_PACKAGE TGLContextManager* GLContextManager;
extern DELPHI_PACKAGE bool vIgnoreOpenGLErrors;
extern DELPHI_PACKAGE bool vContextActivationFailureOccurred;
extern DELPHI_PACKAGE TGLContext* vCurrentGLContext;
extern DELPHI_PACKAGE Gls::Opengladapter::TGLExtensionsAndEntryPoints* GL;
extern DELPHI_PACKAGE Gls::Xopengl::TGLMultitextureCoordinator* xgl;
extern DELPHI_PACKAGE bool vMainThread;
extern DELPHI_PACKAGE Gls::Opengladapter::TGLExtensionsAndEntryPoints* GLwithoutContext;
extern DELPHI_PACKAGE TGLContext* __fastcall CurrentGLContext(void);
extern DELPHI_PACKAGE TGLContext* __fastcall SafeCurrentGLContext(void);
extern DELPHI_PACKAGE bool __fastcall IsMainThread(void);
extern DELPHI_PACKAGE bool __fastcall IsServiceContextAvaible(void);
extern DELPHI_PACKAGE Vcl::Forms::TForm* __fastcall GetServiceWindow(void);
extern DELPHI_PACKAGE void __fastcall RegisterGLContextClass(TGLContextClass aGLContextClass);
}	/* namespace Context */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_CONTEXT)
using namespace Gls::Context;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ContextHPP
