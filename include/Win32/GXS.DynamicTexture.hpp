// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.DynamicTexture.pas' rev: 36.00 (Windows)

#ifndef GXS_DynamicTextureHPP
#define GXS_DynamicTextureHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Context.hpp>
#include <GXS.Texture.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Dynamictexture
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxDynamicTextureImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxDynamicTextureImage : public Gxs::Texture::TgxBlankImage
{
	typedef Gxs::Texture::TgxBlankImage inherited;
	
private:
	int FUpdating;
	int FTexSize;
	void *FBuffer;
	Gxs::Context::TgxBufferObjectHandle* FPBO;
	void *FData;
	System::Types::TRect FDirtyRect;
	bool FUseBGR;
	bool FUsePBO;
	void __fastcall SetDirtyRectangle(const System::Types::TRect &Value);
	void __fastcall SetUsePBO(const bool Value);
	
protected:
	int __fastcall GetTexSize();
	int __fastcall GetBitsPerPixel();
	int __fastcall GetDataFormat();
	int __fastcall GetTextureFormat();
	void __fastcall FreePBO();
	void __fastcall FreeBuffer();
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property int DataFormat = {read=GetDataFormat, nodefault};
	__property int TextureFormat = {read=GetTextureFormat, nodefault};
	
public:
	__fastcall virtual TgxDynamicTextureImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxDynamicTextureImage();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	HIDESBASE void __fastcall BeginUpdate();
	HIDESBASE void __fastcall EndUpdate();
	__property void * Data = {read=FData};
	__property System::Types::TRect DirtyRectangle = {read=FDirtyRect, write=SetDirtyRectangle};
	__property bool UseBGR = {read=FUseBGR, write=FUseBGR, nodefault};
	__property bool UsePBO = {read=FUsePBO, write=SetUsePBO, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dynamictexture */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_DYNAMICTEXTURE)
using namespace Gxs::Dynamictexture;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_DynamicTextureHPP
