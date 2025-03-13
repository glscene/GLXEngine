// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.HUDObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_HUDObjectsHPP
#define GXS_HUDObjectsHPP

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
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Objects.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Hudobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxHUDSprite;
class DELPHICLASS TgxHUDText;
class DELPHICLASS TgxAbsoluteHUDText;
class DELPHICLASS TgxResolutionIndependantHUDText;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxHUDSprite : public Gxs::Objects::TgxSprite
{
	typedef Gxs::Objects::TgxSprite inherited;
	
private:
	int FXTiles;
	int FYTiles;
	bool __fastcall StoreWidth();
	bool __fastcall StoreHeight();
	
protected:
	void __fastcall SetXTiles(const int val);
	void __fastcall SetYTiles(const int val);
	
public:
	__fastcall virtual TgxHUDSprite(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property int XTiles = {read=FXTiles, write=SetXTiles, default=1};
	__property int YTiles = {read=FYTiles, write=SetYTiles, default=1};
	__property Width = {stored=StoreWidth, default=0};
	__property Height = {stored=StoreHeight, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxHUDSprite() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxHUDSprite(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxSprite(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxHUDText : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	Gxs::Bitmapfont::TgxCustomBitmapFont* FBitmapFont;
	System::UnicodeString FText;
	float FRotation;
	System::Classes::TAlignment FAlignment;
	Gxs::Imageutils::TgxTextLayout FLayout;
	Gxs::Color::TgxColor* FModulateColor;
	
protected:
	void __fastcall SetBitmapFont(Gxs::Bitmapfont::TgxCustomBitmapFont* const val);
	void __fastcall SetText(const System::UnicodeString val);
	HIDESBASE void __fastcall SetRotation(const float val);
	void __fastcall SetAlignment(const System::Classes::TAlignment val);
	void __fastcall SetLayout(const Gxs::Imageutils::TgxTextLayout val);
	void __fastcall SetModulateColor(Gxs::Color::TgxColor* const val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RenderTextAtPosition(const float X, const float Y, const float Z, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxHUDText(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHUDText();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* BitmapFont = {read=FBitmapFont, write=SetBitmapFont};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property float Rotation = {read=FRotation, write=SetRotation};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Gxs::Imageutils::TgxTextLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property Gxs::Color::TgxColor* ModulateColor = {read=FModulateColor, write=SetModulateColor};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxHUDText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxAbsoluteHUDText : public TgxHUDText
{
	typedef TgxHUDText inherited;
	
public:
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
public:
	/* TgxHUDText.Create */ inline __fastcall virtual TgxAbsoluteHUDText(System::Classes::TComponent* AOwner) : TgxHUDText(AOwner) { }
	/* TgxHUDText.Destroy */ inline __fastcall virtual ~TgxAbsoluteHUDText() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxAbsoluteHUDText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxHUDText(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxResolutionIndependantHUDText : public TgxHUDText
{
	typedef TgxHUDText inherited;
	
public:
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	__fastcall virtual TgxResolutionIndependantHUDText(System::Classes::TComponent* AOwner);
public:
	/* TgxHUDText.Destroy */ inline __fastcall virtual ~TgxResolutionIndependantHUDText() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxResolutionIndependantHUDText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxHUDText(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Hudobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_HUDOBJECTS)
using namespace Gxs::Hudobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_HUDObjectsHPP
