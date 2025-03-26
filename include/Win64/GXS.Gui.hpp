// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Gui.pas' rev: 36.00 (Windows)

#ifndef GXS_GuiHPP
#define GXS_GuiHPP

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
#include <GXS.BitmapFont.hpp>
#include <GXS.Material.hpp>
#include <GXS.Context.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Gui
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBaseGuiObject;
struct TGUIRect;
class DELPHICLASS TgxGuiElement;
class DELPHICLASS TgxGuiElementList;
class DELPHICLASS TgxGuiComponent;
class DELPHICLASS TgxGuiComponentList;
class DELPHICLASS TgxGuiLayout;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxBaseGuiObject : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	bool FRecursiveVisible;
	float FWidth;
	float FHeight;
	
protected:
	virtual void __fastcall NotifyHide();
	virtual void __fastcall NotifyShow();
	void __fastcall SetLeft(const float Value);
	float __fastcall GetLeft();
	void __fastcall SetTop(const float Value);
	float __fastcall GetTop();
	void __fastcall SetWidth(const float val);
	void __fastcall SetHeight(const float val);
	virtual void __fastcall SetVisible(bool aValue);
	
public:
	__fastcall virtual TgxBaseGuiObject(System::Classes::TComponent* AOwner);
	virtual void __fastcall AddChild(Gxs::Scene::TgxBaseSceneObject* AChild);
	virtual void __fastcall Insert(int aIndex, Gxs::Scene::TgxBaseSceneObject* aChild);
	__property float Width = {read=FWidth, write=SetWidth};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Left = {read=GetLeft, write=SetLeft};
	__property float Top = {read=GetTop, write=SetTop};
	__property bool RecursiveVisible = {read=FRecursiveVisible, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseGuiObject(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	/* TgxBaseSceneObject.Destroy */ inline __fastcall virtual ~TgxBaseGuiObject() { }
	
};


enum DECLSPEC_DENUM TGUIAlignments : unsigned char { GLAlTopLeft, GLAlTop, GLAlTopRight, GLAlLeft, GLAlCenter, GLAlRight, GLAlBottomLeft, GLAlBottom, GLAlBottomRight, GLAlBorder };

struct DECLSPEC_DRECORD TGUIRect
{
public:
	float X1;
	float Y1;
	float X2;
	float Y2;
	float XTiles;
	float YTiles;
};


typedef System::StaticArray<TGUIRect, 10> TGUIDrawResult;

typedef System::UnicodeString TgxGuiElementName;

class PASCALIMPLEMENTATION TgxGuiElement : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates2* FTopLeft;
	Gxs::Coordinates::TgxCoordinates2* FBottomRight;
	Gxs::Coordinates::TgxCoordinates2* FScale;
	TGUIAlignments FAlign;
	TgxGuiElementName FName;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetName(const TgxGuiElementName val);
	
public:
	__fastcall virtual TgxGuiElement(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxGuiElement();
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates2* TopLeft = {read=FTopLeft, write=FTopLeft};
	__property Gxs::Coordinates::TgxCoordinates2* BottomRight = {read=FBottomRight, write=FBottomRight};
	__property Gxs::Coordinates::TgxCoordinates2* Scale = {read=FScale, write=FScale};
	__property TGUIAlignments Align = {read=FAlign, write=FAlign, nodefault};
	__property TgxGuiElementName Name = {read=FName, write=SetName};
};


class PASCALIMPLEMENTATION TgxGuiElementList : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxGuiElement* operator[](int index) { return this->Items[index]; }
	
private:
	TgxGuiComponent* FGuiComponent;
	
protected:
	void __fastcall SetItems(int index, TgxGuiElement* const val);
	TgxGuiElement* __fastcall GetItems(int index);
	
public:
	__fastcall TgxGuiElementList(TgxGuiComponent* AOwner);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	int __fastcall IndexOf(TgxGuiElement* const Item);
	__property TgxGuiElement* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxGuiElementList() { }
	
};


typedef System::UnicodeString TgxGuiComponentName;

class PASCALIMPLEMENTATION TgxGuiComponent : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxGuiElementList* FElements;
	TgxGuiComponentName FName;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetName(const TgxGuiComponentName val);
	
public:
	__fastcall virtual TgxGuiComponent(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxGuiComponent();
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	void __fastcall RenderToArea(float X1, float Y1, float X2, float Y2, TGUIDrawResult &Res, bool Refresh = true, float Scale = 1.000000E+00f);
	TgxGuiComponentList* __fastcall GetOwnerList();
	__property TgxGuiComponentList* Owner = {read=GetOwnerList};
	
__published:
	__property TgxGuiElementList* Elements = {read=FElements, write=FElements};
	__property TgxGuiComponentName Name = {read=FName, write=SetName};
};


class PASCALIMPLEMENTATION TgxGuiComponentList : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxGuiComponent* operator[](int index) { return this->Items[index]; }
	
private:
	TgxGuiLayout* FLayout;
	
protected:
	void __fastcall SetItems(int index, TgxGuiComponent* const val);
	TgxGuiComponent* __fastcall GetItems(int index);
	
public:
	__fastcall TgxGuiComponentList(TgxGuiLayout* AOwner);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	TgxGuiComponent* __fastcall FindItem(TgxGuiComponentName name);
	__property TgxGuiComponent* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxGuiComponentList() { }
	
};


class PASCALIMPLEMENTATION TgxGuiLayout : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	Gxs::Bitmapfont::TgxCustomBitmapFont* FBitmapFont;
	Gxs::Material::TgxMaterial* FMaterial;
	TgxGuiComponentList* FGuiComponents;
	System::UnicodeString FFileName;
	System::Classes::TList* FGuiComponentList;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetFileName(System::UnicodeString newName);
	
public:
	__fastcall virtual TgxGuiLayout(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxGuiLayout();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall LoadFromFile(System::UnicodeString FN);
	void __fastcall Clear();
	void __fastcall SaveToStream(System::Classes::TStream* Stream);
	void __fastcall SaveToFile(System::UnicodeString FN);
	void __fastcall AddGuiComponent(Gxs::Baseclasses::TgxUpdateAbleComponent* Component);
	void __fastcall RemoveGuiComponent(Gxs::Baseclasses::TgxUpdateAbleComponent* Component);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* BitmapFont = {read=FBitmapFont, write=FBitmapFont};
	__property Gxs::Material::TgxMaterial* Material = {read=FMaterial, write=FMaterial};
	__property TgxGuiComponentList* GuiComponents = {read=FGuiComponents, write=FGuiComponents};
	__property System::UnicodeString FileName = {read=FFileName, write=SetFileName};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGUIRect GuiNullRect;
extern DELPHI_PACKAGE bool __fastcall IsInRect(const TGUIRect &R, float X, float Y);
}	/* namespace Gui */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GUI)
using namespace Gxs::Gui;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GuiHPP
