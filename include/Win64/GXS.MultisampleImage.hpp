// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MultisampleImage.pas' rev: 36.00 (Windows)

#ifndef GXS_MultisampleImageHPP
#define GXS_MultisampleImageHPP

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
#include <System.Classes.hpp>
#include <GXS.Context.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Multisampleimage
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMultisampleImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxMultisampleImage : public Gxs::Texture::TgxTextureImage
{
	typedef Gxs::Texture::TgxTextureImage inherited;
	
private:
	Gxs::Graphics::TgxBitmap32* FBitmap;
	int FSamplesCount;
	int FWidth;
	int FHeight;
	int FDepth;
	System::Byte FFixedSamplesLocation;
	void __fastcall SetWidth(int val);
	void __fastcall SetHeight(int val);
	void __fastcall SetDepth(int val);
	void __fastcall SetSamplesCount(int val);
	void __fastcall SetFixedSamplesLocation(System::Byte val);
	
protected:
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	
public:
	__fastcall virtual TgxMultisampleImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxMultisampleImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall IsSelfLoading();
	virtual void __fastcall LoadTexture(Stage::Textureformat::TglInternalFormat AInternalFormat);
	virtual Gxs::Graphics::TgxBitmap32* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property NativeTextureTarget;
	
__published:
	__property int Width = {read=GetWidth, write=SetWidth, default=256};
	__property int Height = {read=GetHeight, write=SetHeight, default=256};
	__property int Depth = {read=GetDepth, write=SetDepth, default=0};
	__property int SamplesCount = {read=FSamplesCount, write=SetSamplesCount, default=0};
	__property System::Byte FixedSamplesLocation = {read=FFixedSamplesLocation, write=SetFixedSamplesLocation, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Multisampleimage */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MULTISAMPLEIMAGE)
using namespace Gxs::Multisampleimage;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MultisampleImageHPP
