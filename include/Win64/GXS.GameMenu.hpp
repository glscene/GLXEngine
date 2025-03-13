// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.GameMenu.pas' rev: 36.00 (Windows)

#ifndef GXS_GameMenuHPP
#define GXS_GameMenuHPP

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
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Material.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Canvas.hpp>
#include <GXS.Context.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Gamemenu
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxGameMenu;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxGameMenuScale : unsigned char { gmsNormal, gms1024x768 };

class PASCALIMPLEMENTATION TgxGameMenu : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	System::Classes::TStrings* FItems;
	int FSelected;
	Gxs::Bitmapfont::TgxCustomBitmapFont* FFont;
	int FMarginVert;
	int FMarginHorz;
	int FSpacing;
	TgxGameMenuScale FMenuScale;
	Gxs::Color::TgxColor* FBackColor;
	Gxs::Color::TgxColor* FInactiveColor;
	Gxs::Color::TgxColor* FActiveColor;
	Gxs::Color::TgxColor* FDisabledColor;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxLibMaterialName FTitleMaterialName;
	int FTitleWidth;
	int FTitleHeight;
	System::Classes::TNotifyEvent FOnSelectedChanged;
	int FBoxTop;
	int FBoxBottom;
	int FBoxLeft;
	int FBoxRight;
	int FMenuTop;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	void __fastcall SetMenuScale(TgxGameMenuScale AValue);
	void __fastcall SetMarginHorz(int AValue);
	void __fastcall SetMarginVert(int AValue);
	void __fastcall SetSpacing(int AValue);
	void __fastcall SetFont(Gxs::Bitmapfont::TgxCustomBitmapFont* AValue);
	void __fastcall SetBackColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetInactiveColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetActiveColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetDisabledColor(Gxs::Color::TgxColor* AValue);
	bool __fastcall GetEnabled(int AIndex);
	void __fastcall SetEnabled(int AIndex, bool AValue);
	void __fastcall SetItems(System::Classes::TStrings* AValue);
	void __fastcall SetSelected(int AValue);
	System::UnicodeString __fastcall GetSelectedText();
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* AValue);
	void __fastcall SetTitleMaterialName(const System::UnicodeString AValue);
	void __fastcall SetTitleWidth(int AValue);
	void __fastcall SetTitleHeight(int AValue);
	void __fastcall ItemsChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TgxGameMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxGameMenu();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool Enabled[int AIndex] = {read=GetEnabled, write=SetEnabled};
	__property System::UnicodeString SelectedText = {read=GetSelectedText};
	void __fastcall SelectNext();
	void __fastcall SelectPrev();
	void __fastcall MouseMenuSelect(const int X, const int Y);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property TgxGameMenuScale MenuScale = {read=FMenuScale, write=SetMenuScale, default=0};
	__property int MarginHorz = {read=FMarginHorz, write=SetMarginHorz, default=16};
	__property int MarginVert = {read=FMarginVert, write=SetMarginVert, default=16};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=16};
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* Font = {read=FFont, write=SetFont};
	__property System::UnicodeString TitleMaterialName = {read=FTitleMaterialName, write=SetTitleMaterialName};
	__property int TitleWidth = {read=FTitleWidth, write=SetTitleWidth, default=0};
	__property int TitleHeight = {read=FTitleHeight, write=SetTitleHeight, default=0};
	__property Gxs::Color::TgxColor* BackColor = {read=FBackColor, write=SetBackColor};
	__property Gxs::Color::TgxColor* InactiveColor = {read=FInactiveColor, write=SetInactiveColor};
	__property Gxs::Color::TgxColor* ActiveColor = {read=FActiveColor, write=SetActiveColor};
	__property Gxs::Color::TgxColor* DisabledColor = {read=FDisabledColor, write=SetDisabledColor};
	__property System::Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property int Selected = {read=FSelected, write=SetSelected, default=-1};
	__property System::Classes::TNotifyEvent OnSelectedChanged = {read=FOnSelectedChanged, write=FOnSelectedChanged};
	__property int BoxTop = {read=FBoxTop, nodefault};
	__property int BoxBottom = {read=FBoxBottom, nodefault};
	__property int BoxLeft = {read=FBoxLeft, nodefault};
	__property int BoxRight = {read=FBoxRight, nodefault};
	__property int MenuTop = {read=FMenuTop, nodefault};
	__property ObjectsSorting = {default=0};
	__property VisibilityCulling = {default=0};
	__property Position;
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGameMenu(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
private:
	void *__IgxMaterialLibrarySupported;	// Gxs::Material::IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gxs::Material::_di_IgxMaterialLibrarySupported()
	{
		Gxs::Material::_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Material::IgxMaterialLibrarySupported*(void) { return (Gxs::Material::IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gamemenu */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GAMEMENU)
using namespace Gxs::Gamemenu;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GameMenuHPP
