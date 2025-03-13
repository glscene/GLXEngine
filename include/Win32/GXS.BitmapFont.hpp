// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.BitmapFont.pas' rev: 36.00 (Windows)

#ifndef GXS_BitmapFontHPP
#define GXS_BitmapFontHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.Texture.hpp>
#include <GXS.State.hpp>
#include <Stage.Utils.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Color.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Bitmapfont
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBitmapFontRange;
class DELPHICLASS TgxBitmapFontRanges;
struct TCharInfo;
class DELPHICLASS TgxCustomBitmapFont;
class DELPHICLASS TgxBitmapFont;
class DELPHICLASS TgxFlatText;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBitmapFontRange : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::WideString __fastcall GetStartASCII();
	System::WideString __fastcall GetStopASCII();
	
protected:
	System::WideChar FStartASCII;
	System::WideChar FStopASCII;
	int FStartGlyphIdx;
	int FStopGlyphIdx;
	int FCharCount;
	void __fastcall SetStartASCII(const System::WideString val);
	void __fastcall SetStopASCII(const System::WideString val);
	void __fastcall SetStartGlyphIdx(int val);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxBitmapFontRange(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxBitmapFontRange();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall NotifyChange();
	
__published:
	__property System::WideString StartASCII = {read=GetStartASCII, write=SetStartASCII};
	__property System::WideString StopASCII = {read=GetStopASCII, write=SetStopASCII};
	__property int StartGlyphIdx = {read=FStartGlyphIdx, write=SetStartGlyphIdx, nodefault};
	__property int StopGlyphIdx = {read=FStopGlyphIdx, nodefault};
	__property int CharCount = {read=FCharCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBitmapFontRanges : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxBitmapFontRange* operator[](int index) { return this->Items[index]; }
	
private:
	int FCharCount;
	
protected:
	System::Classes::TComponent* FOwner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxBitmapFontRange* const val);
	TgxBitmapFontRange* __fastcall GetItems(int index);
	int __fastcall CalcCharacterCount();
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TgxBitmapFontRanges(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBitmapFontRanges();
	HIDESBASE TgxBitmapFontRange* __fastcall Add()/* overload */;
	HIDESBASE TgxBitmapFontRange* __fastcall Add(const System::WideChar StartASCII, const System::WideChar StopASCII)/* overload */;
	HIDESBASE TgxBitmapFontRange* __fastcall Add(const char StartASCII, const char StopASCII)/* overload */;
	HIDESBASE TgxBitmapFontRange* __fastcall FindItemID(int ID);
	__property TgxBitmapFontRange* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	int __fastcall CharacterToTileIndex(System::WideChar aChar);
	System::WideChar __fastcall TileIndexToChar(int aIndex);
	void __fastcall NotifyChange();
	__property int CharacterCount = {read=FCharCount, nodefault};
};

#pragma pack(pop)

typedef TCharInfo *PCharInfo;

struct DECLSPEC_DRECORD TCharInfo
{
public:
	System::Word l;
	System::Word t;
	System::Word w;
};


class PASCALIMPLEMENTATION TgxCustomBitmapFont : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
	
private:
	typedef System::DynamicArray<TCharInfo> _TgxCustomBitmapFont__1;
	
	
private:
	TgxBitmapFontRanges* FRanges;
	Fmx::Objects::TImage* FGlyphs;
	int FCharWidth;
	int FCharHeight;
	int FGlyphsIntervalX;
	int FGlyphsIntervalY;
	int FHSpace;
	int FVSpace;
	int FHSpaceFix;
	System::Classes::TList* FUsers;
	Gxs::Texture::TgxMinFilter FMinFilter;
	Gxs::Texture::TgxMagFilter FMagFilter;
	int FTextureWidth;
	int FTextureHeight;
	int FTextRows;
	int FTextCols;
	Gxs::Texture::TgxTextureImageAlpha FGlyphsAlpha;
	System::Classes::TList* FTextures;
	bool FTextureModified;
	Gxs::Context::TgxTextureHandle* FLastTexture;
	
protected:
	_TgxCustomBitmapFont__1 FChars;
	bool FCharsLoaded;
	void __fastcall ResetCharWidths(int w = 0xffffffff);
	void __fastcall SetCharWidths(int index, int value);
	void __fastcall SetRanges(TgxBitmapFontRanges* const val);
	void __fastcall SetGlyphs(Fmx::Objects::TImage* const val);
	void __fastcall SetCharWidth(const int val);
	void __fastcall SetCharHeight(const int val);
	void __fastcall SetGlyphsIntervalX(const int val);
	void __fastcall SetGlyphsIntervalY(const int val);
	void __fastcall OnGlyphsChanged(System::TObject* Sender);
	void __fastcall SetHSpace(const int val);
	void __fastcall SetVSpace(const int val);
	void __fastcall SetMagFilter(Gxs::Texture::TgxMagFilter AValue);
	void __fastcall SetMinFilter(Gxs::Texture::TgxMinFilter AValue);
	void __fastcall SetGlyphsAlpha(Gxs::Texture::TgxTextureImageAlpha val);
	void __fastcall TextureChanged();
	virtual void __fastcall FreeTextureHandle();
	virtual int __fastcall TextureFormat();
	void __fastcall InvalidateUsers();
	int __fastcall CharactersPerRow();
	void __fastcall GetCharTexCoords(System::WideChar Ch, Stage::Vectorgeometry::TTexPoint &TopLeft, Stage::Vectorgeometry::TTexPoint &BottomRight);
	void __fastcall GetICharTexCoords(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, int Chi, /* out */ Stage::Vectorgeometry::TTexPoint &TopLeft, /* out */ Stage::Vectorgeometry::TTexPoint &BottomRight);
	virtual void __fastcall PrepareImage(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall PrepareParams(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	__property Fmx::Objects::TImage* Glyphs = {read=FGlyphs, write=SetGlyphs};
	__property int GlyphsIntervalX = {read=FGlyphsIntervalX, write=SetGlyphsIntervalX, nodefault};
	__property int GlyphsIntervalY = {read=FGlyphsIntervalY, write=SetGlyphsIntervalY, nodefault};
	__property TgxBitmapFontRanges* Ranges = {read=FRanges, write=SetRanges};
	__property int CharWidth = {read=FCharWidth, write=SetCharWidth, default=16};
	__property int HSpace = {read=FHSpace, write=SetHSpace, default=1};
	__property int VSpace = {read=FVSpace, write=SetVSpace, default=1};
	__property int HSpaceFix = {read=FHSpaceFix, write=FHSpaceFix, nodefault};
	__property Gxs::Texture::TgxMagFilter MagFilter = {read=FMagFilter, write=SetMagFilter, default=1};
	__property Gxs::Texture::TgxMinFilter MinFilter = {read=FMinFilter, write=SetMinFilter, default=1};
	__property Gxs::Texture::TgxTextureImageAlpha GlyphsAlpha = {read=FGlyphsAlpha, write=FGlyphsAlpha, default=0};
	
public:
	__fastcall virtual TgxCustomBitmapFont(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomBitmapFont();
	virtual void __fastcall RegisterUser(Gxs::Scene::TgxBaseSceneObject* anObject);
	virtual void __fastcall UnRegisterUser(Gxs::Scene::TgxBaseSceneObject* anObject);
	virtual void __fastcall RenderString(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, const System::UnicodeString aText, System::Classes::TAlignment aAlignment, Gxs::Imageutils::TgxTextLayout aLayout, const Gxs::Color::TgxColorVector &aColor, Stage::Vectortypes::PVector4f aPosition = (Stage::Vectortypes::PVector4f)(0x0), bool aReverseY = false)/* overload */;
	void __fastcall TextOut(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, float X, float Y, const System::UnicodeString Text, const Gxs::Color::TgxColorVector &Color)/* overload */;
	void __fastcall TextOut(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, float X, float Y, const System::UnicodeString Text, const System::Uitypes::TColor Color)/* overload */;
	int __fastcall TextWidth(const System::UnicodeString Text);
	virtual int __fastcall CharacterToTileIndex(System::WideChar aChar);
	virtual System::WideChar __fastcall TileIndexToChar(int aIndex);
	virtual int __fastcall CharacterCount();
	int __fastcall GetCharWidth(System::WideChar Ch);
	virtual int __fastcall CalcStringWidth(const System::UnicodeString aText)/* overload */;
	void __fastcall CheckTexture(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	__property int CharHeight = {read=FCharHeight, write=SetCharHeight, default=16};
	__property int TextureWidth = {read=FTextureWidth, write=FTextureWidth, nodefault};
	__property int TextureHeight = {read=FTextureHeight, write=FTextureHeight, nodefault};
};


class PASCALIMPLEMENTATION TgxBitmapFont : public TgxCustomBitmapFont
{
	typedef TgxCustomBitmapFont inherited;
	
__published:
	__property Glyphs;
	__property GlyphsIntervalX;
	__property GlyphsIntervalY;
	__property Ranges;
	__property CharWidth = {default=16};
	__property CharHeight = {default=16};
	__property HSpace = {default=1};
	__property VSpace = {default=1};
	__property MagFilter = {default=1};
	__property MinFilter = {default=1};
	__property GlyphsAlpha = {default=0};
public:
	/* TgxCustomBitmapFont.Create */ inline __fastcall virtual TgxBitmapFont(System::Classes::TComponent* AOwner) : TgxCustomBitmapFont(AOwner) { }
	/* TgxCustomBitmapFont.Destroy */ inline __fastcall virtual ~TgxBitmapFont() { }
	
};


enum DECLSPEC_DENUM TgxFlatTextOption : unsigned char { ftoTwoSided };

typedef System::Set<TgxFlatTextOption, TgxFlatTextOption::ftoTwoSided, TgxFlatTextOption::ftoTwoSided> TgxFlatTextOptions;

class PASCALIMPLEMENTATION TgxFlatText : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	TgxCustomBitmapFont* FBitmapFont;
	System::UnicodeString FText;
	System::Classes::TAlignment FAlignment;
	Gxs::Imageutils::TgxTextLayout FLayout;
	Gxs::Color::TgxColor* FModulateColor;
	TgxFlatTextOptions FOptions;
	
protected:
	void __fastcall SetBitmapFont(TgxCustomBitmapFont* const val);
	void __fastcall SetText(const System::UnicodeString val);
	void __fastcall SetAlignment(const System::Classes::TAlignment val);
	void __fastcall SetLayout(const Gxs::Imageutils::TgxTextLayout val);
	void __fastcall SetModulateColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetOptions(const TgxFlatTextOptions val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxFlatText(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxFlatText();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxCustomBitmapFont* BitmapFont = {read=FBitmapFont, write=SetBitmapFont};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property Gxs::Imageutils::TgxTextLayout Layout = {read=FLayout, write=SetLayout, nodefault};
	__property Gxs::Color::TgxColor* ModulateColor = {read=FModulateColor, write=SetModulateColor};
	__property TgxFlatTextOptions Options = {read=FOptions, write=SetOptions, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFlatText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Bitmapfont */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BITMAPFONT)
using namespace Gxs::Bitmapfont;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BitmapFontHPP
