// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Context.pas' rev: 36.00 (Windows)

#ifndef GXS_ContextHPP
#define GXS_ContextHPP

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
#include <System.StrUtils.hpp>
#include <FMX.Consts.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Context
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFinishTaskEvent;
struct TgxServiceContextTask;
class DELPHICLASS TgxAbstractMultitextureCoordinator;
class DELPHICLASS TgxContext;
class DELPHICLASS TgxScreenControlingContext;
struct TgxRCHandle;
class DELPHICLASS TgxContextHandle;
class DELPHICLASS TgxVirtualHandle;
class DELPHICLASS TgxVirtualHandleTransf;
class DELPHICLASS TgxListHandle;
class DELPHICLASS TgxTextureHandle;
class DELPHICLASS TgxSamplerHandle;
class DELPHICLASS TgxQueryHandle;
class DELPHICLASS TgxOcclusionQueryHandle;
class DELPHICLASS TgxBooleanOcclusionQueryHandle;
class DELPHICLASS TgxTimerQueryHandle;
class DELPHICLASS TgxPrimitiveQueryHandle;
class DELPHICLASS TgxBufferObjectHandle;
class DELPHICLASS TgxVBOHandle;
class DELPHICLASS TgxVBOArrayBufferHandle;
class DELPHICLASS TgxVBOElementArrayHandle;
class DELPHICLASS TgxPackPBOHandle;
class DELPHICLASS TgxUnpackPBOHandle;
class DELPHICLASS TgxTransformFeedbackBufferHandle;
class DELPHICLASS TgxTextureBufferHandle;
class DELPHICLASS TgxUniformBufferHandle;
class DELPHICLASS TgxVertexArrayHandle;
class DELPHICLASS TgxFramebufferHandle;
class DELPHICLASS TgxRenderbufferHandle;
class DELPHICLASS TgxProgramHandleEXT;
class DELPHICLASS TgxVertexProgramHandle;
class DELPHICLASS TgxFragmentProgramHandle;
class DELPHICLASS TgxGeometryProgramHandle;
class DELPHICLASS TgxSLHandle;
class DELPHICLASS TgxShaderHandle;
class DELPHICLASS TgxVertexShaderHandle;
class DELPHICLASS TgxGeometryShaderHandle;
class DELPHICLASS TgxFragmentShaderHandle;
class DELPHICLASS TgxTessControlShaderHandle;
class DELPHICLASS TgxTessEvaluationShaderHandle;
class DELPHICLASS TgxProgramHandle;
struct TgxContextNotification;
class DELPHICLASS TgxContextManager;
class DELPHICLASS EVXContext;
class DELPHICLASS EPBuffer;
class DELPHICLASS EVXShader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxRCOption : unsigned char { rcoDoubleBuffered, rcoStereo, rcoDebug, rcoOGL_ES };

typedef System::Set<TgxRCOption, TgxRCOption::rcoDoubleBuffered, TgxRCOption::rcoOGL_ES> TgxRCOptions;

enum DECLSPEC_DENUM TgxContextLayer : unsigned char { clUnderlay2, clUnderlay1, clMainPlane, clOverlay1, clOverlay2 };

class PASCALIMPLEMENTATION TgxFinishTaskEvent : public System::Syncobjs::TEvent
{
	typedef System::Syncobjs::TEvent inherited;
	
public:
	__fastcall TgxFinishTaskEvent();
public:
	/* THandleObject.Destroy */ inline __fastcall virtual ~TgxFinishTaskEvent() { }
	
};


typedef void __stdcall (__closure *TgxTaskProcedure)(void);

struct DECLSPEC_DRECORD TgxServiceContextTask
{
public:
	TgxTaskProcedure Task;
	TgxFinishTaskEvent* Event;
};


class PASCALIMPLEMENTATION TgxAbstractMultitextureCoordinator : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TgxContext* FOwner;
	
public:
	__fastcall virtual TgxAbstractMultitextureCoordinator(TgxContext* AOwner);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxAbstractMultitextureCoordinator() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxAbstractMultitextureCoordinatorClass);

enum DECLSPEC_DENUM TgxContextAcceleration : unsigned char { chaUnknown, chaHardware, chaSoftware };

enum DECLSPEC_DENUM TgxAntiAliasing : unsigned char { aaDefault, aaNone, aa2x, aa2xHQ, aa4x, aa4xHQ, aa6x, aa8x, aa16x, csa8x, csa8xHQ, csa16x, csa16xHQ };

enum DECLSPEC_DENUM TgxSyncMode : unsigned char { vsmSync, vsmNoSync };

class PASCALIMPLEMENTATION TgxContext : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FColorBits;
	int FAlphaBits;
	int FDepthBits;
	int FStencilBits;
	int FAccumBits;
	int FAuxBuffers;
	TgxAntiAliasing FAntiAliasing;
	TgxRCOptions FOptions;
	System::Classes::TNotifyEvent FOnDestroyContext;
	TgxContextManager* FManager;
	int FActivationCount;
	int FOwnedHandlesCount;
	bool FIsPraparationNeed;
	void __fastcall SetColorBits(const int aColorBits);
	void __fastcall SetAlphaBits(const int aAlphaBits);
	void __fastcall SetDepthBits(const int val);
	void __fastcall SetStencilBits(const int aStencilBits);
	void __fastcall SetAccumBits(const int aAccumBits);
	void __fastcall SetAuxBuffers(const int aAuxBuffers);
	void __fastcall SetOptions(const TgxRCOptions aOptions);
	void __fastcall SetAntiAliasing(const TgxAntiAliasing val);
	void __fastcall SetAcceleration(const TgxContextAcceleration val);
	bool __fastcall GetActive();
	void __fastcall SetActive(const bool aActive);
	void __fastcall SetLayer(const TgxContextLayer Value);
	
protected:
	TgxAbstractMultitextureCoordinator* FGXS;
	Gxs::State::TgxStateCache* FgxStates;
	Stage::Pipelinetransform::TgTransformation* FTransformation;
	TgxContextAcceleration FAcceleration;
	TgxContextLayer FLayer;
	System::Classes::TList* FSharedContexts;
	System::Classes::TList* FOwnedHandles;
	void __fastcall PropagateSharedContext();
	virtual void __fastcall DoCreateContext(Winapi::Windows::THandle ADeviceHandle) = 0 ;
	virtual void __fastcall DoCreateMemoryContext(Winapi::Windows::THandle OutputDevice, int Width, int Height, int BufferCount = 0x1) = 0 ;
	virtual bool __fastcall DoShareLists(TgxContext* aContext) = 0 ;
	virtual void __fastcall DoDestroyContext() = 0 ;
	virtual void __fastcall DoActivate() = 0 ;
	virtual void __fastcall DoDeactivate() = 0 ;
	__classmethod TgxContext* __fastcall ServiceContext();
	void __fastcall MakeGLCurrent();
	TgxAbstractMultitextureCoordinator* __fastcall GetGXS();
	
public:
	__fastcall virtual TgxContext();
	__fastcall virtual ~TgxContext();
	__property Gxs::State::TgxStateCache* GXStates = {read=FgxStates};
	__property Stage::Pipelinetransform::TgTransformation* PipelineTransformation = {read=FTransformation};
	__property TgxContextManager* Manager = {read=FManager};
	__property int ColorBits = {read=FColorBits, write=SetColorBits, nodefault};
	__property int AlphaBits = {read=FAlphaBits, write=SetAlphaBits, nodefault};
	__property int DepthBits = {read=FDepthBits, write=SetDepthBits, nodefault};
	__property int StencilBits = {read=FStencilBits, write=SetStencilBits, nodefault};
	__property int AccumBits = {read=FAccumBits, write=SetAccumBits, nodefault};
	__property int AuxBuffers = {read=FAuxBuffers, write=SetAuxBuffers, nodefault};
	__property TgxAntiAliasing AntiAliasing = {read=FAntiAliasing, write=SetAntiAliasing, nodefault};
	__property TgxContextLayer Layer = {read=FLayer, write=SetLayer, nodefault};
	__property TgxRCOptions Options = {read=FOptions, write=SetOptions, nodefault};
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property TgxContextAcceleration Acceleration = {read=FAcceleration, write=SetAcceleration, nodefault};
	__property System::Classes::TNotifyEvent OnDestroyContext = {read=FOnDestroyContext, write=FOnDestroyContext};
	void __fastcall CreateContext(Winapi::Windows::THandle ADeviceHandle)/* overload */;
	void __fastcall CreateMemoryContext(Winapi::Windows::THandle OutputDevice, int Width, int Height, int BufferCount = 0x1);
	void __fastcall ShareLists(TgxContext* aContext);
	void __fastcall DestroyContext();
	void __fastcall Activate();
	void __fastcall Deactivate();
	void __fastcall PrepareHandlesData();
	virtual bool __fastcall IsValid() = 0 ;
	virtual void __fastcall SwapBuffers() = 0 ;
	TgxContext* __fastcall FindCompatibleContext();
	void __fastcall DestroyAllHandles();
	virtual void * __fastcall RenderOutputDevice() = 0 ;
	__property TgxAbstractMultitextureCoordinator* MultitextureCoordinator = {read=GetGXS};
	__property bool IsPraparationNeed = {read=FIsPraparationNeed, nodefault};
};


_DECLARE_METACLASS(System::TMetaClass, TgxContextClass);

class PASCALIMPLEMENTATION TgxScreenControlingContext : public TgxContext
{
	typedef TgxContext inherited;
	
private:
	int FWidth;
	int FHeight;
	bool FFullScreen;
	
public:
	__property int Width = {read=FWidth, write=FWidth, nodefault};
	__property int Height = {read=FHeight, write=FHeight, nodefault};
	__property bool FullScreen = {read=FFullScreen, write=FFullScreen, nodefault};
public:
	/* TgxContext.Create */ inline __fastcall virtual TgxScreenControlingContext() : TgxContext() { }
	/* TgxContext.Destroy */ inline __fastcall virtual ~TgxScreenControlingContext() { }
	
};


typedef TgxRCHandle *PgxRCHandle;

struct DECLSPEC_DRECORD TgxRCHandle
{
public:
	TgxContext* FRenderingContext;
	unsigned FHandle;
	bool FChanged;
};


typedef void __fastcall (__closure *TOnPrepareHandleData)(TgxContext* aContext);

class PASCALIMPLEMENTATION TgxContextHandle : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FHandles;
	PgxRCHandle FLastHandle;
	TOnPrepareHandleData FOnPrepare;
	unsigned __fastcall GetHandle();
	TgxContext* __fastcall GetContext();
	PgxRCHandle __fastcall SearchRC(TgxContext* aContext);
	PgxRCHandle __fastcall RCItem(int AIndex);
	void __fastcall CheckCurrentRC();
	
protected:
	void __fastcall ContextDestroying();
	__classmethod virtual bool __fastcall Transferable();
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	virtual System::LongWord __fastcall DoAllocateHandle() = 0 ;
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle) = 0 ;
	
public:
	__fastcall virtual TgxContextHandle();
	__fastcall TgxContextHandle(bool failIfAllocationFailed);
	__fastcall virtual ~TgxContextHandle();
	__property System::LongWord Handle = {read=GetHandle, nodefault};
	__property TgxContext* RenderingContext = {read=GetContext};
	bool __fastcall IsDataNeedUpdate();
	bool __fastcall IsDataComplitelyUpdated();
	void __fastcall NotifyDataUpdated();
	void __fastcall NotifyChangesOfData();
	__classmethod virtual bool __fastcall IsSupported();
	bool __fastcall IsAllocatedForContext(TgxContext* aContext = (TgxContext*)(0x0));
	bool __fastcall IsShared();
	unsigned __fastcall AllocateHandle();
	void __fastcall DestroyHandle();
	__property TOnPrepareHandleData OnPrapare = {read=FOnPrepare, write=FOnPrepare};
};


typedef void __fastcall (__closure *TgxVirtualHandleEvent)(TgxVirtualHandle* Sender, System::LongWord &Handle);

class PASCALIMPLEMENTATION TgxVirtualHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
private:
	TgxVirtualHandleEvent FOnAllocate;
	TgxVirtualHandleEvent FOnDestroy;
	int FTag;
	
protected:
	virtual unsigned __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(unsigned &AHandle);
	__classmethod virtual bool __fastcall Transferable();
	
public:
	__property TgxVirtualHandleEvent OnAllocate = {read=FOnAllocate, write=FOnAllocate};
	__property TgxVirtualHandleEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property int Tag = {read=FTag, write=FTag, nodefault};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVirtualHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVirtualHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVirtualHandle() { }
	
};


class PASCALIMPLEMENTATION TgxVirtualHandleTransf : public TgxVirtualHandle
{
	typedef TgxVirtualHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVirtualHandleTransf() : TgxVirtualHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVirtualHandleTransf(bool failIfAllocationFailed) : TgxVirtualHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVirtualHandleTransf() { }
	
};


class PASCALIMPLEMENTATION TgxListHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	void __fastcall NewList(unsigned mode);
	void __fastcall EndList();
	void __fastcall CallList();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxListHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxListHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxListHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTextureHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
private:
	Stage::Textureformat::TglTextureTarget FTarget;
	void __fastcall SetTarget(Stage::Textureformat::TglTextureTarget ATarget);
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	__property Stage::Textureformat::TglTextureTarget Target = {read=FTarget, write=SetTarget, nodefault};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxTextureHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTextureHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTextureHandle() { }
	
};


class PASCALIMPLEMENTATION TgxSamplerHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxSamplerHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxSamplerHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxSamplerHandle() { }
	
};


class PASCALIMPLEMENTATION TgxQueryHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
private:
	bool FActive;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	virtual System::LongWord __fastcall GetTarget() = 0 ;
	virtual Gxs::State::TgxQueryType __fastcall GetQueryType() = 0 ;
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	void __fastcall BeginQuery();
	void __fastcall EndQuery();
	bool __fastcall IsResultAvailable();
	int __fastcall CounterBits();
	int __fastcall QueryResultInt();
	System::LongWord __fastcall QueryResultUInt();
	__int64 __fastcall QueryResultInt64();
	unsigned __int64 __fastcall QueryResultUInt64();
	System::ByteBool __fastcall QueryResultBool();
	__property System::LongWord Target = {read=GetTarget, nodefault};
	__property Gxs::State::TgxQueryType QueryType = {read=GetQueryType, nodefault};
	__property bool Active = {read=FActive, nodefault};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxQueryHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxQueryHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TgxOcclusionQueryHandle : public TgxQueryHandle
{
	typedef TgxQueryHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	virtual Gxs::State::TgxQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall PixelCount();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxOcclusionQueryHandle() : TgxQueryHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxOcclusionQueryHandle(bool failIfAllocationFailed) : TgxQueryHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxOcclusionQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TgxBooleanOcclusionQueryHandle : public TgxQueryHandle
{
	typedef TgxQueryHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	virtual Gxs::State::TgxQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxBooleanOcclusionQueryHandle() : TgxQueryHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxBooleanOcclusionQueryHandle(bool failIfAllocationFailed) : TgxQueryHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxBooleanOcclusionQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTimerQueryHandle : public TgxQueryHandle
{
	typedef TgxQueryHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	virtual Gxs::State::TgxQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall Time();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxTimerQueryHandle() : TgxQueryHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTimerQueryHandle(bool failIfAllocationFailed) : TgxQueryHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTimerQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TgxPrimitiveQueryHandle : public TgxQueryHandle
{
	typedef TgxQueryHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	virtual Gxs::State::TgxQueryType __fastcall GetQueryType();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	int __fastcall PrimitivesGenerated();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxPrimitiveQueryHandle() : TgxQueryHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxPrimitiveQueryHandle(bool failIfAllocationFailed) : TgxQueryHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxPrimitiveQueryHandle() { }
	
};


class PASCALIMPLEMENTATION TgxBufferObjectHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
private:
	int FSize;
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	virtual System::LongWord __fastcall GetTarget() = 0 ;
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	__fastcall TgxBufferObjectHandle(void * p, int size, System::LongWord bufferUsage);
	virtual void __fastcall Bind() = 0 ;
	virtual void __fastcall UnBind() = 0 ;
	virtual void __fastcall BindRange(System::LongWord index, Winapi::Opengl::PGLInt offset, Winapi::Opengl::PGLSizei size);
	virtual void __fastcall BindBase(System::LongWord index);
	virtual void __fastcall UnBindBase(System::LongWord index);
	void __fastcall BufferData(void * p, int size, System::LongWord bufferUsage);
	void __fastcall BindBufferData(void * p, int size, System::LongWord bufferUsage);
	void __fastcall BufferSubData(int offset, int size, void * p);
	void * __fastcall MapBuffer(System::LongWord access);
	void * __fastcall MapBufferRange(int offset, int len, unsigned access);
	void __fastcall Flush(int offset, int len);
	System::ByteBool __fastcall UnmapBuffer();
	__classmethod virtual bool __fastcall IsSupported();
	__property System::LongWord Target = {read=GetTarget, nodefault};
	__property int BufferSize = {read=FSize, nodefault};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxBufferObjectHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxBufferObjectHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxBufferObjectHandle() { }
	
};


class PASCALIMPLEMENTATION TgxVBOHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
private:
	System::LongWord __fastcall GetVBOTarget();
	
public:
	__property System::LongWord VBOTarget = {read=GetVBOTarget, nodefault};
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxVBOHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVBOHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVBOHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVBOHandle() { }
	
};


class PASCALIMPLEMENTATION TgxVBOArrayBufferHandle : public TgxVBOHandle
{
	typedef TgxVBOHandle inherited;
	
protected:
	virtual unsigned __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxVBOArrayBufferHandle(void * p, int size, System::LongWord bufferUsage) : TgxVBOHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVBOArrayBufferHandle() : TgxVBOHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVBOArrayBufferHandle(bool failIfAllocationFailed) : TgxVBOHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVBOArrayBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxVBOElementArrayHandle : public TgxVBOHandle
{
	typedef TgxVBOHandle inherited;
	
protected:
	virtual unsigned __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxVBOElementArrayHandle(void * p, int size, System::LongWord bufferUsage) : TgxVBOHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVBOElementArrayHandle() : TgxVBOHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVBOElementArrayHandle(bool failIfAllocationFailed) : TgxVBOHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVBOElementArrayHandle() { }
	
};


class PASCALIMPLEMENTATION TgxPackPBOHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
protected:
	virtual unsigned __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxPackPBOHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxPackPBOHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxPackPBOHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxPackPBOHandle() { }
	
};


class PASCALIMPLEMENTATION TgxUnpackPBOHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
protected:
	virtual unsigned __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxUnpackPBOHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxUnpackPBOHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxUnpackPBOHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxUnpackPBOHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTransformFeedbackBufferHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	void __fastcall BeginTransformFeedback(unsigned primitiveMode);
	void __fastcall EndTransformFeedback();
	virtual void __fastcall BindRange(System::LongWord index, Winapi::Opengl::PGLInt offset, Winapi::Opengl::PGLSizei size);
	virtual void __fastcall BindBase(System::LongWord index);
	virtual void __fastcall UnBindBase(System::LongWord index);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxTransformFeedbackBufferHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxTransformFeedbackBufferHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTransformFeedbackBufferHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTransformFeedbackBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTextureBufferHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxTextureBufferHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxTextureBufferHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTextureBufferHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTextureBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxUniformBufferHandle : public TgxBufferObjectHandle
{
	typedef TgxBufferObjectHandle inherited;
	
protected:
	virtual System::LongWord __fastcall GetTarget();
	
public:
	virtual void __fastcall Bind();
	virtual void __fastcall UnBind();
	virtual void __fastcall BindRange(System::LongWord index, Winapi::Opengl::PGLInt offset, Winapi::Opengl::PGLSizei size);
	virtual void __fastcall BindBase(unsigned index);
	virtual void __fastcall UnBindBase(unsigned index);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxBufferObjectHandle.CreateFromData */ inline __fastcall TgxUniformBufferHandle(void * p, int size, System::LongWord bufferUsage) : TgxBufferObjectHandle(p, size, bufferUsage) { }
	
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxUniformBufferHandle() : TgxBufferObjectHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxUniformBufferHandle(bool failIfAllocationFailed) : TgxBufferObjectHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxUniformBufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxVertexArrayHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual unsigned __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(unsigned &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const unsigned ID);
	
public:
	void __fastcall Bind();
	void __fastcall UnBind();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVertexArrayHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVertexArrayHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVertexArrayHandle() { }
	
};


enum DECLSPEC_DENUM TgxFramebufferStatus : unsigned char { fsComplete, fsIncompleteAttachment, fsIncompleteMissingAttachment, fsIncompleteDuplicateAttachment, fsIncompleteDimensions, fsIncompleteFormats, fsIncompleteDrawBuffer, fsIncompleteReadBuffer, fsUnsupported, fsIncompleteMultisample, fsStatusError };

class PASCALIMPLEMENTATION TgxFramebufferHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	__classmethod virtual bool __fastcall Transferable();
	virtual unsigned __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(unsigned &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const unsigned ID);
	
public:
	void __fastcall Bind();
	void __fastcall BindForDrawing();
	void __fastcall BindForReading();
	void __fastcall UnBind();
	void __fastcall UnBindForDrawing();
	void __fastcall UnBindForReading();
	void __fastcall Attach1DTexture(unsigned Target, unsigned attachment, unsigned textarget, System::LongWord texture, int level);
	void __fastcall Attach2DTexture(unsigned Target, unsigned attachment, unsigned textarget, System::LongWord texture, int level);
	void __fastcall Attach3DTexture(unsigned Target, unsigned attachment, unsigned textarget, System::LongWord texture, int level, int Layer);
	void __fastcall AttachLayer(unsigned Target, unsigned attachment, System::LongWord texture, int level, int Layer);
	void __fastcall AttachRenderBuffer(unsigned Target, unsigned attachment, unsigned renderbuffertarget, System::LongWord renderbuffer);
	void __fastcall AttachTexture(unsigned Target, unsigned attachment, System::LongWord texture, int level);
	void __fastcall AttachTextureLayer(unsigned Target, unsigned attachment, System::LongWord texture, int level, int Layer);
	void __fastcall Blit(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned mask, unsigned filter);
	int __fastcall GetAttachmentParameter(unsigned Target, unsigned attachment, unsigned pname);
	int __fastcall GetAttachmentObjectType(unsigned Target, unsigned attachment);
	int __fastcall GetAttachmentObjectName(unsigned Target, unsigned attachment);
	TgxFramebufferStatus __fastcall GetStatus();
	TgxFramebufferStatus __fastcall GetStringStatus(/* out */ System::UnicodeString &clarification);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxFramebufferHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxFramebufferHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxFramebufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxRenderbufferHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	virtual unsigned __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(unsigned &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	void __fastcall Bind();
	void __fastcall UnBind();
	void __fastcall SetStorage(unsigned internalformat, int Width, int Height);
	void __fastcall SetStorageMultisample(unsigned internalformat, int samples, int Width, int Height);
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxRenderbufferHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxRenderbufferHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxRenderbufferHandle() { }
	
};


class PASCALIMPLEMENTATION TgxProgramHandleEXT : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
private:
	bool FReady;
	System::UnicodeString FInfoLog;
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	virtual __classmethod unsigned __fastcall GetTarget() = 0 ;
	
public:
	void __fastcall LoadARBProgram(System::UnicodeString AText);
	void __fastcall Enable();
	void __fastcall Disable();
	void __fastcall Bind();
	__property bool Ready = {read=FReady, nodefault};
	__property System::UnicodeString InfoLog = {read=FInfoLog};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxProgramHandleEXT() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxProgramHandleEXT(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxProgramHandleEXT() { }
	
};


class PASCALIMPLEMENTATION TgxVertexProgramHandle : public TgxProgramHandleEXT
{
	typedef TgxProgramHandleEXT inherited;
	
protected:
	__classmethod virtual unsigned __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxVertexProgramHandle() : TgxProgramHandleEXT() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVertexProgramHandle(bool failIfAllocationFailed) : TgxProgramHandleEXT(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVertexProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TgxFragmentProgramHandle : public TgxProgramHandleEXT
{
	typedef TgxProgramHandleEXT inherited;
	
protected:
	__classmethod virtual unsigned __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxFragmentProgramHandle() : TgxProgramHandleEXT() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxFragmentProgramHandle(bool failIfAllocationFailed) : TgxProgramHandleEXT(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxFragmentProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TgxGeometryProgramHandle : public TgxProgramHandleEXT
{
	typedef TgxProgramHandleEXT inherited;
	
protected:
	__classmethod virtual unsigned __fastcall GetTarget();
	
public:
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxGeometryProgramHandle() : TgxProgramHandleEXT() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxGeometryProgramHandle(bool failIfAllocationFailed) : TgxProgramHandleEXT(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxGeometryProgramHandle() { }
	
};


class PASCALIMPLEMENTATION TgxSLHandle : public TgxContextHandle
{
	typedef TgxContextHandle inherited;
	
protected:
	virtual void __fastcall DoDestroyHandle(System::LongWord &AHandle);
	
public:
	System::UnicodeString __fastcall InfoLog();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxSLHandle() : TgxContextHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxSLHandle(bool failIfAllocationFailed) : TgxContextHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxSLHandle() { }
	
};


class PASCALIMPLEMENTATION TgxShaderHandle : public TgxSLHandle
{
	typedef TgxSLHandle inherited;
	
private:
	unsigned FShaderType;
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
public:
	void __fastcall ShaderSource(const System::AnsiString source)/* overload */;
	bool __fastcall CompileShader();
	__property unsigned ShaderType = {read=FShaderType, nodefault};
public:
	/* TgxContextHandle.Create */ inline __fastcall virtual TgxShaderHandle() : TgxSLHandle() { }
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxShaderHandle(bool failIfAllocationFailed) : TgxSLHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxShaderHandle() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxShaderHandleClass);

class PASCALIMPLEMENTATION TgxVertexShaderHandle : public TgxShaderHandle
{
	typedef TgxShaderHandle inherited;
	
public:
	__fastcall virtual TgxVertexShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxVertexShaderHandle(bool failIfAllocationFailed) : TgxShaderHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxVertexShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TgxGeometryShaderHandle : public TgxShaderHandle
{
	typedef TgxShaderHandle inherited;
	
public:
	__fastcall virtual TgxGeometryShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxGeometryShaderHandle(bool failIfAllocationFailed) : TgxShaderHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxGeometryShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TgxFragmentShaderHandle : public TgxShaderHandle
{
	typedef TgxShaderHandle inherited;
	
public:
	__fastcall virtual TgxFragmentShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxFragmentShaderHandle(bool failIfAllocationFailed) : TgxShaderHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxFragmentShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTessControlShaderHandle : public TgxShaderHandle
{
	typedef TgxShaderHandle inherited;
	
public:
	__fastcall virtual TgxTessControlShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTessControlShaderHandle(bool failIfAllocationFailed) : TgxShaderHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTessControlShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TgxTessEvaluationShaderHandle : public TgxShaderHandle
{
	typedef TgxShaderHandle inherited;
	
public:
	__fastcall virtual TgxTessEvaluationShaderHandle();
	__classmethod virtual bool __fastcall IsSupported();
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxTessEvaluationShaderHandle(bool failIfAllocationFailed) : TgxShaderHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxTessEvaluationShaderHandle() { }
	
};


class PASCALIMPLEMENTATION TgxProgramHandle : public TgxSLHandle
{
	typedef TgxSLHandle inherited;
	
public:
	__classmethod virtual System::ByteBool __fastcall IsValid(const System::LongWord ID);
	
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
	Stage::Vectortypes::TVector4f __fastcall GetUniform4f(const System::UnicodeString index);
	void __fastcall SetUniform4f(const System::UnicodeString index, const Stage::Vectortypes::TVector4f &val);
	Stage::Vectortypes::TMatrix2f __fastcall GetUniformMatrix2fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix2fv(const System::UnicodeString index, const Stage::Vectortypes::TMatrix2f &val);
	Stage::Vectortypes::TMatrix3f __fastcall GetUniformMatrix3fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix3fv(const System::UnicodeString index, const Stage::Vectortypes::TMatrix3f &val);
	Stage::Vectortypes::TMatrix4f __fastcall GetUniformMatrix4fv(const System::UnicodeString index);
	void __fastcall SetUniformMatrix4fv(const System::UnicodeString index, const Stage::Vectortypes::TMatrix4f &val);
	unsigned __fastcall GetUniformTextureHandle(const System::UnicodeString index, const int TextureIndex, const Stage::Textureformat::TglTextureTarget TextureTarget);
	void __fastcall SetUniformTextureHandle(const System::UnicodeString index, const int TextureIndex, const Stage::Textureformat::TglTextureTarget TextureTarget, const unsigned Value);
	void __fastcall SetUniformBuffer(const System::UnicodeString index, TgxUniformBufferHandle* Value);
	
protected:
	virtual System::LongWord __fastcall DoAllocateHandle();
	
public:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__fastcall virtual TgxProgramHandle();
	void __fastcall AddShader(TgxShaderHandleClass ShaderType, const System::UnicodeString ShaderSource, bool treatWarningsAsErrors = false);
	void __fastcall AttachObject(TgxShaderHandle* shader);
	void __fastcall DetachAllObject();
	void __fastcall BindAttribLocation(int index, const System::UnicodeString aName);
	void __fastcall BindFragDataLocation(int index, const System::UnicodeString aName);
	bool __fastcall LinkProgram();
	bool __fastcall ValidateProgram();
	int __fastcall GetAttribLocation(const System::UnicodeString aName);
	int __fastcall GetUniformLocation(const System::UnicodeString aName);
	int __fastcall GetUniformOffset(const System::UnicodeString aName);
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
	__property Stage::Vectortypes::TVector4f Uniform4f[const System::UnicodeString index] = {read=GetUniform4f, write=SetUniform4f};
	__property Stage::Vectortypes::TMatrix2f UniformMatrix2fv[const System::UnicodeString index] = {read=GetUniformMatrix2fv, write=SetUniformMatrix2fv};
	__property Stage::Vectortypes::TMatrix3f UniformMatrix3fv[const System::UnicodeString index] = {read=GetUniformMatrix3fv, write=SetUniformMatrix3fv};
	__property Stage::Vectortypes::TMatrix4f UniformMatrix4fv[const System::UnicodeString index] = {read=GetUniformMatrix4fv, write=SetUniformMatrix4fv};
	__property System::LongWord UniformTextureHandle[const System::UnicodeString index][const int TextureIndex][const Stage::Textureformat::TglTextureTarget TextureTarget] = {read=GetUniformTextureHandle, write=SetUniformTextureHandle};
	__property TgxUniformBufferHandle* UniformBuffer[const System::UnicodeString index] = {write=SetUniformBuffer};
public:
	/* TgxContextHandle.CreateAndAllocate */ inline __fastcall TgxProgramHandle(bool failIfAllocationFailed) : TgxSLHandle(failIfAllocationFailed) { }
	/* TgxContextHandle.Destroy */ inline __fastcall virtual ~TgxProgramHandle() { }
	
};


struct DECLSPEC_DRECORD TgxContextNotification
{
public:
	System::TObject* obj;
	System::Classes::TNotifyEvent Event;
};


class PASCALIMPLEMENTATION TgxContextManager : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TgxContextNotification> _TgxContextManager__1;
	
	
private:
	System::Classes::TThreadList* FList;
	bool FTerminated;
	_TgxContextManager__1 FNotifications;
	int FCreatedRCCount;
	System::Classes::TThreadList* FHandles;
	System::Classes::TThread* FThread;
	System::Syncobjs::TEvent* FServiceStarter;
	TgxContext* FServiceContext;
	
protected:
	void __fastcall Lock();
	void __fastcall UnLock();
	void __fastcall RegisterContext(TgxContext* aContext);
	void __fastcall UnRegisterContext(TgxContext* aContext);
	void __fastcall ContextCreatedBy(TgxContext* aContext);
	void __fastcall DestroyingContextBy(TgxContext* aContext);
	__property TgxContext* ServiceContext = {read=FServiceContext};
	
public:
	__fastcall TgxContextManager();
	__fastcall virtual ~TgxContextManager();
	TgxContext* __fastcall CreateContext(TgxContextClass AClass = 0x0);
	int __fastcall ContextCount();
	void __fastcall LastContextDestroyNotification(System::TObject* anObject, System::Classes::TNotifyEvent anEvent);
	void __fastcall RemoveNotification(System::TObject* anObject);
	void __fastcall Terminate();
	void __fastcall DestroyAllHandles();
	void __fastcall NotifyPreparationNeed();
};


class PASCALIMPLEMENTATION EVXContext : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EVXContext(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EVXContext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EVXContext(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EVXContext(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EVXContext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EVXContext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EVXContext(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EVXContext(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EVXContext(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EVXContext(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EVXContext(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EVXContext(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EVXContext() { }
	
};


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


class PASCALIMPLEMENTATION EVXShader : public EVXContext
{
	typedef EVXContext inherited;
	
public:
	/* Exception.Create */ inline __fastcall EVXShader(const System::UnicodeString Msg) : EVXContext(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EVXShader(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EVXContext(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EVXShader(System::NativeUInt Ident)/* overload */ : EVXContext(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EVXShader(System::PResStringRec ResStringRec)/* overload */ : EVXContext(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EVXShader(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EVXContext(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EVXShader(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EVXContext(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EVXShader(const System::UnicodeString Msg, int AHelpContext) : EVXContext(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EVXShader(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EVXContext(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EVXShader(System::NativeUInt Ident, int AHelpContext)/* overload */ : EVXContext(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EVXShader(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EVXContext(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EVXShader(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EVXContext(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EVXShader(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EVXContext(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EVXShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<unsigned, 4> MRT_BUFFERS;
extern DELPHI_PACKAGE TgxContextManager* GXContextManager;
extern DELPHI_PACKAGE bool vIgnoreOpenGXErrors;
extern DELPHI_PACKAGE bool vContextActivationFailureOccurred;
extern DELPHI_PACKAGE TgxAbstractMultitextureCoordinatorClass vMultitextureCoordinatorClass;
extern DELPHI_PACKAGE TgxContext* vCurrentContext;
extern DELPHI_PACKAGE TgxContext* __fastcall CurrentContext(void);
extern DELPHI_PACKAGE TgxContext* __fastcall SafeCurrentContext(void);
extern DELPHI_PACKAGE bool __fastcall IsMainThread(void);
extern DELPHI_PACKAGE bool __fastcall IsServiceContextAvaible(void);
extern DELPHI_PACKAGE Fmx::Forms::TForm* __fastcall GetServiceWindow(void);
extern DELPHI_PACKAGE void __fastcall RegisterContextClass(TgxContextClass aContextClass);
}	/* namespace Context */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CONTEXT)
using namespace Gxs::Context;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ContextHPP
