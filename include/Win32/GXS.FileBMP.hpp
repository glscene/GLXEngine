// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileBMP.pas' rev: 36.00 (Windows)

#ifndef GXS_FileBMPHPP
#define GXS_FileBMPHPP

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
#include <System.SysUtils.hpp>
#include <GXS.Context.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filebmp
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBMPImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxBMPImage : public Gxs::Graphics::TgxBaseImage
{
	typedef Gxs::Graphics::TgxBaseImage inherited;
	
private:
	bool FTopDown;
	System::LongWord RedMask;
	System::LongWord GreenMask;
	System::LongWord BlueMask;
	System::Int8 RedShift;
	System::Int8 GreenShift;
	System::Int8 BlueShift;
	System::Sysutils::PByteArray FLineBuffer;
	int FReadSize;
	int FDeltaX;
	int FDeltaY;
	System::Int8 __fastcall CountBits(System::Byte Value);
	System::Int8 __fastcall ShiftCount(System::LongWord Mask);
	Gxs::Graphics::TgxPixel32 __fastcall ExpandColor(System::LongWord Value);
	void __fastcall ExpandRLE4ScanLine(int Row, System::Classes::TStream* Stream);
	void __fastcall ExpandRLE8ScanLine(int Row, System::Classes::TStream* Stream);
	int __fastcall Monochrome(int N);
	int __fastcall Quadrochrome(int N);
	int __fastcall Octochrome(int N);
	
public:
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* stream);
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	HIDESBASE void __fastcall AssignFromTexture(Gxs::Context::TgxContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
public:
	/* TgxBaseImage.Create */ inline __fastcall virtual TgxBMPImage() : Gxs::Graphics::TgxBaseImage() { }
	/* TgxBaseImage.Destroy */ inline __fastcall virtual ~TgxBMPImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filebmp */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEBMP)
using namespace Gxs::Filebmp;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileBMPHPP
