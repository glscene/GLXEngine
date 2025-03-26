// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CompositeImage.pas' rev: 36.00 (Windows)

#ifndef GXS_CompositeImageHPP
#define GXS_CompositeImageHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Context.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Compositeimage
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCompositeImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxCompositeImage : public Gxs::Texture::TgxTextureImage
{
	typedef Gxs::Texture::TgxTextureImage inherited;
	
private:
	Gxs::Graphics::TgxBitmap32* FBitmap;
	int FWidth;
	int FHeight;
	int FDepth;
	
protected:
	void __fastcall SetWidth(int val);
	void __fastcall SetHeight(int val);
	void __fastcall SetDepth(int val);
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	
public:
	__fastcall virtual TgxCompositeImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxCompositeImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Gxs::Graphics::TgxBitmap32* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall LoadFromStream(System::Classes::TStream* const AStream);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property NativeTextureTarget;
	
__published:
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Depth = {read=GetDepth, write=SetDepth, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Compositeimage */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_COMPOSITEIMAGE)
using namespace Gxs::Compositeimage;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CompositeImageHPP
