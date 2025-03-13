// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.FileJPEG.pas' rev: 36.00 (Windows)

#ifndef GLS_FileJPEGHPP
#define GLS_FileJPEGHPP

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
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.Context.hpp>
#include <GLS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Filejpeg
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLJPEGImage;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLJPEGImage : public Gls::Graphics::TGLBaseImage
{
	typedef Gls::Graphics::TGLBaseImage inherited;
	
private:
	bool FAbortLoading;
	System::LongWord FDivScale;
	bool FDither;
	bool FSmoothing;
	bool FProgressiveEncoding;
	void __fastcall SetSmoothing(const bool AValue);
	
public:
	__fastcall virtual TGLJPEGImage();
	__classmethod virtual Gls::Applicationfileio::TGLDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	HIDESBASE void __fastcall AssignFromTexture(Gls::Context::TGLContext* textureContext, const unsigned textureHandle, Stage::Textureformat::TglTextureTarget textureTarget, const bool CurrentFormat, const Stage::Textureformat::TglInternalFormat intFormat);
	__property System::LongWord DivScale = {read=FDivScale, write=FDivScale, nodefault};
	__property bool Dither = {read=FDither, write=FDither, nodefault};
	__property bool Smoothing = {read=FSmoothing, write=SetSmoothing, nodefault};
	__property bool ProgressiveEncoding = {read=FProgressiveEncoding, nodefault};
public:
	/* TGLBaseImage.Destroy */ inline __fastcall virtual ~TGLJPEGImage() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Jpeg2Bmp(const System::UnicodeString BmpFileName, const System::UnicodeString JpgFileName);
}	/* namespace Filejpeg */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILEJPEG)
using namespace Gls::Filejpeg;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_FileJPEGHPP
