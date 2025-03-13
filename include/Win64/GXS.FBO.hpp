// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FBO.pas' rev: 36.00 (Windows)

#ifndef GXS_FBOHPP
#define GXS_FBOHPP

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
#include <System.SysUtils.hpp>
#include <FMX.Dialogs.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.MultisampleImage.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fbo
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxRenderbuffer;
class DELPHICLASS TgxDepthRBO;
class DELPHICLASS TgxStencilRBO;
class DELPHICLASS TgxFrameBuffer;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxRenderbuffer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gxs::Context::TgxRenderbufferHandle* FRenderbufferHandle;
	int FWidth;
	int FHeight;
	bool FStorageValid;
	unsigned __fastcall GetHandle();
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	virtual unsigned __fastcall GetInternalFormat() = 0 ;
	void __fastcall InvalidateStorage();
	
public:
	__fastcall TgxRenderbuffer();
	__fastcall virtual ~TgxRenderbuffer();
	void __fastcall Bind();
	void __fastcall Unbind();
	__property unsigned Handle = {read=GetHandle, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
};


class PASCALIMPLEMENTATION TgxDepthRBO : public TgxRenderbuffer
{
	typedef TgxRenderbuffer inherited;
	
private:
	Gxs::Scene::TgxDepthPrecision FDepthPrecision;
	void __fastcall SetDepthPrecision(const Gxs::Scene::TgxDepthPrecision Value);
	
protected:
	virtual unsigned __fastcall GetInternalFormat();
	
public:
	__fastcall TgxDepthRBO();
	__property Gxs::Scene::TgxDepthPrecision DepthPrecision = {read=FDepthPrecision, write=SetDepthPrecision, nodefault};
public:
	/* TgxRenderbuffer.Destroy */ inline __fastcall virtual ~TgxDepthRBO() { }
	
};


enum DECLSPEC_DENUM TgxStencilPrecision : unsigned char { spDefault, sp1bit, sp4bits, sp8bits, sp16bits };

class PASCALIMPLEMENTATION TgxStencilRBO : public TgxRenderbuffer
{
	typedef TgxRenderbuffer inherited;
	
private:
	TgxStencilPrecision FStencilPrecision;
	void __fastcall SetStencilPrecision(const TgxStencilPrecision Value);
	
protected:
	virtual unsigned __fastcall GetInternalFormat();
	
public:
	__fastcall TgxStencilRBO();
	__property TgxStencilPrecision StencilPrecision = {read=FStencilPrecision, write=SetStencilPrecision, nodefault};
public:
	/* TgxRenderbuffer.Destroy */ inline __fastcall virtual ~TgxStencilRBO() { }
	
};


class PASCALIMPLEMENTATION TgxFrameBuffer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gxs::Context::TgxFramebufferHandle* FFrameBufferHandle;
	unsigned FTarget;
	int FWidth;
	int FHeight;
	int FLayer;
	int FLevel;
	unsigned FTextureMipmap;
	System::StaticArray<Gxs::Texture::TgxTexture*, 32> FAttachedTexture;
	Gxs::Texture::TgxTexture* FDepthTexture;
	TgxDepthRBO* FDRBO;
	TgxStencilRBO* FSRBO;
	Gxs::Context::TgxFramebufferStatus __fastcall GetStatus();
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetLayer(const int Value);
	void __fastcall SetLevel(const int Value);
	
protected:
	void __fastcall AttachTexture(const unsigned attachment, const unsigned textarget, const unsigned texture, const int level, const int layer)/* overload */;
	void __fastcall ReattachTextures();
	
public:
	__fastcall TgxFrameBuffer();
	__fastcall virtual ~TgxFrameBuffer();
	void __fastcall AttachDepthBuffer(TgxDepthRBO* DepthBuffer)/* overload */;
	void __fastcall DetachDepthBuffer();
	void __fastcall AttachStencilBuffer(TgxStencilRBO* StencilBuffer)/* overload */;
	void __fastcall DetachStencilBuffer();
	void __fastcall AttachDepthTexture(Gxs::Texture::TgxTexture* Texture)/* overload */;
	void __fastcall DetachDepthTexture();
	void __fastcall AttachTexture(unsigned n, Gxs::Texture::TgxTexture* Texture)/* overload */;
	void __fastcall DetachTexture(unsigned n);
	Gxs::Context::TgxFramebufferStatus __fastcall GetStringStatus(/* out */ System::UnicodeString &clarification);
	__property Gxs::Context::TgxFramebufferStatus Status = {read=GetStatus, nodefault};
	void __fastcall Bind();
	void __fastcall Unbind();
	void __fastcall PreRender();
	void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Scene::TgxBaseSceneObject* baseObject);
	void __fastcall PostRender(const bool PostGenerateMipmap);
	__property Gxs::Context::TgxFramebufferHandle* Handle = {read=FFrameBufferHandle};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property int Layer = {read=FLayer, write=SetLayer, nodefault};
	__property int Level = {read=FLevel, write=SetLevel, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 MaxColorAttachments = System::Int8(0x20);
}	/* namespace Fbo */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FBO)
using namespace Gxs::Fbo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FBOHPP
