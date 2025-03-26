// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.WindowsFont.pas' rev: 36.00 (Windows)

#ifndef GXS_WindowsFontHPP
#define GXS_WindowsFontHPP

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
#include <System.Math.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.Utils.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.BaseClasses.hpp>
#include <FMX.Objects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Windowsfont
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxWindowsBitmapFont;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxWindowsBitmapFont : public Gxs::Bitmapfont::TgxCustomBitmapFont
{
	typedef Gxs::Bitmapfont::TgxCustomBitmapFont inherited;
	
private:
	Fmx::Graphics::TFont* FFont;
	void __fastcall SetList(Gxs::Vectorlists::TgxIntegerList* const AList);
	
protected:
	void __fastcall SetFont(Fmx::Graphics::TFont* value);
	virtual void __fastcall LoadWindowsFont();
	bool __fastcall StoreRanges();
	virtual void __fastcall PrepareImage(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual int __fastcall TextureFormat();
	void __fastcall StreamlineRanges();
	
public:
	__fastcall virtual TgxWindowsBitmapFont(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxWindowsBitmapFont();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	int __fastcall FontTextureWidth();
	int __fastcall FontTextureHeight();
	void __fastcall EnsureString(const System::UnicodeString s)/* overload */;
	void __fastcall EnsureChars(const System::WideChar AStart, const System::WideChar AEnd);
	__property Glyphs;
	
__published:
	__property Fmx::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property HSpace = {default=1};
	__property VSpace = {default=1};
	__property MagFilter = {default=1};
	__property MinFilter = {default=1};
	__property Ranges = {stored=StoreRanges};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Windowsfont */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_WINDOWSFONT)
using namespace Gxs::Windowsfont;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_WindowsFontHPP
