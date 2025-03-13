// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Windows.pas' rev: 36.00 (Windows)

#ifndef GXS_WindowsHPP
#define GXS_WindowsHPP

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
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <Stage.Utils.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.HUDObjects.hpp>
#include <GXS.Material.hpp>
#include <GXS.Context.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.WindowsFont.hpp>
#include <GXS.Gui.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Objects.hpp>
#include <GXS.State.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Windows
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBaseComponent;
class DELPHICLASS TgxBaseControl;
class DELPHICLASS TgxBaseFontControl;
class DELPHICLASS TgxBaseTextControl;
class DELPHICLASS TgxFocusControl;
class DELPHICLASS TgxCustomControl;
class DELPHICLASS TgxPopupMenu;
class DELPHICLASS TgxForm;
class DELPHICLASS TgxPanel;
class DELPHICLASS TgxCheckBox;
class DELPHICLASS TgxButton;
class DELPHICLASS TgxEdit;
class DELPHICLASS TgxLabel;
class DELPHICLASS TgxAdvancedLabel;
class DELPHICLASS TgxScrollbar;
class DELPHICLASS StringGrid;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxBaseComponent : public Gxs::Gui::TgxBaseGuiObject
{
	typedef Gxs::Gui::TgxBaseGuiObject inherited;
	
private:
	bool FGUIRedraw;
	Gxs::Gui::TgxGuiLayout* FGuiLayout;
	Gxs::Gui::TgxGuiComponentName FGuiLayoutName;
	Gxs::Gui::TgxGuiComponent* FGuiComponent;
	bool FReBuildGui;
	bool FRedrawAtOnce;
	float MoveX;
	float MoveY;
	Gxs::Gui::TGUIDrawResult FRenderStatus;
	float FAlphaChannel;
	float FRotation;
	bool FNoZWrite;
	bool BlockRendering;
	int RenderingCount;
	int BlockedCount;
	bool GuiDestroying;
	bool FDoChangesOnProgress;
	bool FAutosize;
	void __fastcall SetGUIRedraw(bool value);
	void __fastcall SetDoChangesOnProgress(const bool Value);
	void __fastcall SetAutosize(const bool Value);
	
protected:
	void __fastcall RenderHeader(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	void __fastcall RenderFooter(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall SetGuiLayout(Gxs::Gui::TgxGuiLayout* NewGui);
	void __fastcall SetGuiLayoutName(Gxs::Gui::TgxGuiComponentName NewName);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	HIDESBASE void __fastcall SetRotation(const float val);
	void __fastcall SetAlphaChannel(const float val);
	bool __fastcall StoreAlphaChannel();
	void __fastcall SetNoZWrite(const bool val);
	
public:
	void __fastcall BlockRender();
	void __fastcall UnBlockRender();
	__fastcall virtual TgxBaseComponent(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBaseComponent();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall DoChanges();
	void __fastcall MoveGUI(float XRel, float YRel);
	void __fastcall PlaceGUI(float XPos, float YPos);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	__property bool GUIRedraw = {read=FGUIRedraw, write=SetGUIRedraw, nodefault};
	__property bool ReBuildGui = {read=FReBuildGui, write=FReBuildGui, nodefault};
	
__published:
	__property bool Autosize = {read=FAutosize, write=SetAutosize, nodefault};
	__property bool RedrawAtOnce = {read=FRedrawAtOnce, write=FRedrawAtOnce, nodefault};
	__property Gxs::Gui::TgxGuiLayout* GuiLayout = {read=FGuiLayout, write=SetGuiLayout};
	__property Gxs::Gui::TgxGuiComponentName GuiLayoutName = {read=FGuiLayoutName, write=SetGuiLayoutName};
	__property float Rotation = {read=FRotation, write=SetRotation};
	__property float AlphaChannel = {read=FAlphaChannel, write=SetAlphaChannel, stored=StoreAlphaChannel};
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, nodefault};
	__property bool DoChangesOnProgress = {read=FDoChangesOnProgress, write=SetDoChangesOnProgress, nodefault};
	__property Visible = {default=1};
	__property Width = {default=0};
	__property Height = {default=0};
	__property Left = {default=0};
	__property Top = {default=0};
	__property Position;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseComponent(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Gui::TgxBaseGuiObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxMouseAction : unsigned char { ma_mouseup, ma_mousedown, ma_mousemove };

typedef void __fastcall (__closure *TgxAcceptMouseQuery)(TgxBaseControl* Sender, System::Classes::TShiftState Shift, TgxMouseAction Action, System::Uitypes::TMouseButton Button, int X, int Y, bool &Accept);

class PASCALIMPLEMENTATION TgxBaseControl : public TgxBaseComponent
{
	typedef TgxBaseComponent inherited;
	
private:
	Fmx::Types::TMouseEvent FOnMouseDown;
	Fmx::Types::TMouseMoveEvent FOnMouseMove;
	Fmx::Types::TMouseEvent FOnMouseUp;
	bool FKeepMouseEvents;
	TgxBaseControl* FActiveControl;
	TgxFocusControl* FFocusedControl;
	TgxAcceptMouseQuery FOnAcceptMouseQuery;
	System::Classes::TNotifyEvent FOnMouseLeave;
	System::Classes::TNotifyEvent FOnMouseEnter;
	TgxBaseControl* FEnteredControl;
	
protected:
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseUp(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall SetActiveControl(TgxBaseControl* NewControl);
	void __fastcall SetFocusedControl(TgxFocusControl* NewControl);
	TgxBaseControl* __fastcall FindFirstGui();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall DoMouseEnter();
	void __fastcall DoMouseLeave();
	
public:
	virtual bool __fastcall MouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall KeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall KeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	__property TgxBaseControl* ActiveControl = {read=FActiveControl, write=SetActiveControl};
	__property bool KeepMouseEvents = {read=FKeepMouseEvents, write=FKeepMouseEvents, default=0};
	
__published:
	__property TgxFocusControl* FocusedControl = {read=FFocusedControl, write=SetFocusedControl};
	__property Fmx::Types::TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property Fmx::Types::TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property Fmx::Types::TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property TgxAcceptMouseQuery OnAcceptMouseQuery = {read=FOnAcceptMouseQuery, write=FOnAcceptMouseQuery};
public:
	/* TgxBaseComponent.Create */ inline __fastcall virtual TgxBaseControl(System::Classes::TComponent* AOwner) : TgxBaseComponent(AOwner) { }
	/* TgxBaseComponent.Destroy */ inline __fastcall virtual ~TgxBaseControl() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseControl(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseComponent(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxBaseFontControl : public TgxBaseControl
{
	typedef TgxBaseControl inherited;
	
private:
	Gxs::Bitmapfont::TgxCustomBitmapFont* FBitmapFont;
	Gxs::Color::TgxColorVector FDefaultColor;
	
protected:
	System::Uitypes::TColor __fastcall GetDefaultColor();
	void __fastcall SetDefaultColor(System::Uitypes::TColor value);
	void __fastcall SetBitmapFont(Gxs::Bitmapfont::TgxCustomBitmapFont* NewFont);
	Gxs::Bitmapfont::TgxCustomBitmapFont* __fastcall GetBitmapFont();
	void __fastcall WriteTextAt(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const float X, const float Y, const System::UnicodeString Data, const Gxs::Color::TgxColorVector &Color)/* overload */;
	void __fastcall WriteTextAt(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const float X1, const float Y1, const float X2, const float Y2, const System::UnicodeString Data, const Gxs::Color::TgxColorVector &Color)/* overload */;
	int __fastcall GetFontHeight();
	
public:
	__fastcall virtual TgxBaseFontControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBaseFontControl();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
__published:
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* BitmapFont = {read=GetBitmapFont, write=SetBitmapFont};
	__property System::Uitypes::TColor DefaultColor = {read=GetDefaultColor, write=SetDefaultColor, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseFontControl(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxBaseTextControl : public TgxBaseFontControl
{
	typedef TgxBaseFontControl inherited;
	
private:
	System::UnicodeString FCaption;
	
protected:
	void __fastcall SetCaption(const System::UnicodeString NewCaption);
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
public:
	/* TgxBaseFontControl.Create */ inline __fastcall virtual TgxBaseTextControl(System::Classes::TComponent* AOwner) : TgxBaseFontControl(AOwner) { }
	/* TgxBaseFontControl.Destroy */ inline __fastcall virtual ~TgxBaseTextControl() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseTextControl(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseFontControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFocusControl : public TgxBaseTextControl
{
	typedef TgxBaseTextControl inherited;
	
private:
	TgxBaseControl* FRootControl;
	bool FFocused;
	Fmx::Types::TKeyEvent FOnKeyDown;
	Fmx::Types::TKeyEvent FOnKeyUp;
	Fmx::Types::TKeyEvent FOnKeyPress;
	System::Classes::TShiftState FShiftState;
	Gxs::Color::TgxColorVector FFocusedColor;
	
protected:
	virtual void __fastcall InternalKeyPress(System::WideChar &Key);
	virtual void __fastcall InternalKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall InternalKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall SetFocused(bool Value);
	TgxBaseControl* __fastcall GetRootControl();
	System::Uitypes::TColor __fastcall GetFocusedColor();
	void __fastcall SetFocusedColor(const System::Uitypes::TColor Val);
	
public:
	__fastcall virtual ~TgxFocusControl();
	virtual void __fastcall NotifyHide();
	virtual void __fastcall MoveTo(Gxs::Scene::TgxBaseSceneObject* newParent);
	void __fastcall ReGetRootControl();
	void __fastcall SetFocus();
	void __fastcall PrevControl();
	void __fastcall NextControl();
	virtual void __fastcall KeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall KeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
__published:
	__property TgxBaseControl* RootControl = {read=GetRootControl};
	__property bool Focused = {read=FFocused, write=SetFocused, nodefault};
	__property System::Uitypes::TColor FocusedColor = {read=GetFocusedColor, write=SetFocusedColor, nodefault};
	__property Fmx::Types::TKeyEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
	__property Fmx::Types::TKeyEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
	__property Fmx::Types::TKeyEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
public:
	/* TgxBaseFontControl.Create */ inline __fastcall virtual TgxFocusControl(System::Classes::TComponent* AOwner) : TgxBaseTextControl(AOwner) { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFocusControl(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseTextControl(aParentOwner) { }
	
};


typedef void __fastcall (__closure *TgxCustomRenderEvent)(TgxCustomControl* Sender, Fmx::Graphics::TBitmap* Bitmap);

class PASCALIMPLEMENTATION TgxCustomControl : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	void *FCustomData;
	System::TObject* FCustomObject;
	TgxCustomRenderEvent FOnRender;
	Gxs::Material::TgxMaterial* FMaterial;
	Fmx::Graphics::TBitmap* FBitmap;
	Fmx::Graphics::TBitmap* FInternalBitmap;
	bool FBitmapChanged;
	float FXTexCoord;
	float FYTexCoord;
	int FInvalidRenderCount;
	int FMaxInvalidRenderCount;
	bool FCentered;
	void __fastcall SetCentered(const bool Value);
	
protected:
	void __fastcall OnBitmapChanged(System::TObject* Sender);
	void __fastcall SetBitmap(Fmx::Graphics::TBitmap* ABitmap);
	
public:
	__fastcall virtual TgxCustomControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomControl();
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	void __fastcall SetMaterial(Gxs::Material::TgxMaterial* AMaterial);
	__property void * CustomData = {read=FCustomData, write=FCustomData};
	__property System::TObject* CustomObject = {read=FCustomObject, write=FCustomObject};
	
__published:
	__property TgxCustomRenderEvent OnRender = {read=FOnRender, write=FOnRender};
	__property bool Centered = {read=FCentered, write=SetCentered, nodefault};
	__property Gxs::Material::TgxMaterial* Material = {read=FMaterial, write=SetMaterial};
	__property Fmx::Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	__property int MaxInvalidRenderCount = {read=FMaxInvalidRenderCount, write=FMaxInvalidRenderCount, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCustomControl(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


typedef void __fastcall (__closure *TgxPopupMenuClick)(TgxPopupMenu* Sender, int index, const System::UnicodeString MenuItemText);

class PASCALIMPLEMENTATION TgxPopupMenu : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	TgxPopupMenuClick FOnClick;
	System::Classes::TStrings* FMenuItems;
	int FSelIndex;
	float FMarginSize;
	float NewHeight;
	
protected:
	virtual void __fastcall SetFocused(bool Value);
	void __fastcall SetMenuItems(System::Classes::TStrings* Value);
	void __fastcall SetMarginSize(const float val);
	void __fastcall SetSelIndex(const int val);
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall OnStringListChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPopupMenu();
	void __fastcall PopUp(int Px, int Py);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual bool __fastcall MouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
__published:
	__property System::Classes::TStrings* MenuItems = {read=FMenuItems, write=SetMenuItems};
	__property TgxPopupMenuClick OnClick = {read=FOnClick, write=FOnClick};
	__property float MarginSize = {read=FMarginSize, write=SetMarginSize};
	__property int SelIndex = {read=FSelIndex, write=SetSelIndex, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPopupMenu(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


typedef void __fastcall (__closure *TgxFormCanRequest)(TgxForm* Sender, bool &Can);

enum DECLSPEC_DENUM TgxFormCloseOptions : unsigned char { co_Hide, co_Ignore, co_Destroy };

typedef void __fastcall (__closure *TgxFormCanClose)(TgxForm* Sender, TgxFormCloseOptions &CanClose);

typedef void __fastcall (__closure *TgxFormNotify)(TgxForm* Sender);

typedef void __fastcall (__closure *TgxFormMove)(TgxForm* Sender, float &Left, float &Top);

class PASCALIMPLEMENTATION TgxForm : public TgxBaseTextControl
{
	typedef TgxBaseTextControl inherited;
	
private:
	TgxFormCanRequest FOnCanMove;
	TgxFormCanRequest FOnCanResize;
	TgxFormCanClose FOnCanClose;
	TgxFormNotify FOnShow;
	TgxFormNotify FOnHide;
	TgxFormMove FOnMoving;
	bool Moving;
	int OldX;
	int OldY;
	Gxs::Color::TgxColorVector FTitleColor;
	float FTitleOffset;
	
protected:
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseUp(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	System::Uitypes::TColor __fastcall GetTitleColor();
	void __fastcall SetTitleColor(System::Uitypes::TColor value);
	
public:
	__fastcall virtual TgxForm(System::Classes::TComponent* AOwner);
	void __fastcall Close();
	virtual void __fastcall NotifyShow();
	virtual void __fastcall NotifyHide();
	virtual bool __fastcall MouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property System::Uitypes::TColor TitleColor = {read=GetTitleColor, write=SetTitleColor, nodefault};
	__property TgxFormCanRequest OnCanMove = {read=FOnCanMove, write=FOnCanMove};
	__property TgxFormCanRequest OnCanResize = {read=FOnCanResize, write=FOnCanResize};
	__property TgxFormCanClose OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property TgxFormNotify OnShow = {read=FOnShow, write=FOnShow};
	__property TgxFormNotify OnHide = {read=FOnHide, write=FOnHide};
	__property TgxFormMove OnMoving = {read=FOnMoving, write=FOnMoving};
	__property float TitleOffset = {read=FTitleOffset, write=FTitleOffset};
public:
	/* TgxBaseFontControl.Destroy */ inline __fastcall virtual ~TgxForm() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxForm(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseTextControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxPanel : public TgxBaseControl
{
	typedef TgxBaseControl inherited;
	
public:
	/* TgxBaseComponent.Create */ inline __fastcall virtual TgxPanel(System::Classes::TComponent* AOwner) : TgxBaseControl(AOwner) { }
	/* TgxBaseComponent.Destroy */ inline __fastcall virtual ~TgxPanel() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPanel(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxCheckBox : public TgxBaseControl
{
	typedef TgxBaseControl inherited;
	
private:
	bool FChecked;
	System::Classes::TNotifyEvent FOnChange;
	Gxs::Gui::TgxGuiComponentName FGuiLayoutNameChecked;
	Gxs::Gui::TgxGuiComponent* FGuiCheckedComponent;
	int FGroup;
	
protected:
	void __fastcall SetChecked(bool NewChecked);
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseUp(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	void __fastcall SetGuiLayoutNameChecked(Gxs::Gui::TgxGuiComponentName newName);
	virtual void __fastcall SetGuiLayout(Gxs::Gui::TgxGuiLayout* NewGui);
	void __fastcall SetGroup(const int val);
	
public:
	__fastcall virtual TgxCheckBox(System::Classes::TComponent* AOwner);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property int Group = {read=FGroup, write=SetGroup, nodefault};
	__property bool Checked = {read=FChecked, write=SetChecked, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Gxs::Gui::TgxGuiComponentName GuiLayoutNameChecked = {read=FGuiLayoutNameChecked, write=SetGuiLayoutNameChecked};
public:
	/* TgxBaseComponent.Destroy */ inline __fastcall virtual ~TgxCheckBox() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCheckBox(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxButton : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	bool FPressed;
	System::Classes::TNotifyEvent FOnButtonClick;
	Gxs::Gui::TgxGuiComponentName FGuiLayoutNamePressed;
	Gxs::Gui::TgxGuiComponent* FGuiPressedComponent;
	Gxs::Material::TgxMaterial* FBitBtn;
	int FGroup;
	float FLogicWidth;
	float FLogicHeight;
	float FXOffSet;
	float FYOffSet;
	bool FAllowUp;
	
protected:
	void __fastcall SetPressed(bool NewPressed);
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseUp(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall InternalKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall SetFocused(bool Value);
	void __fastcall SetGuiLayoutNamePressed(Gxs::Gui::TgxGuiComponentName newName);
	virtual void __fastcall SetGuiLayout(Gxs::Gui::TgxGuiLayout* NewGui);
	void __fastcall SetBitBtn(Gxs::Material::TgxMaterial* AValue);
	virtual void __fastcall DestroyHandle();
	void __fastcall SetGroup(const int val);
	void __fastcall SetLogicWidth(const float val);
	void __fastcall SetLogicHeight(const float val);
	void __fastcall SetXOffset(const float val);
	void __fastcall SetYOffset(const float val);
	
public:
	__fastcall virtual TgxButton(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxButton();
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property int Group = {read=FGroup, write=SetGroup, nodefault};
	__property Gxs::Material::TgxMaterial* BitBtn = {read=FBitBtn, write=SetBitBtn};
	__property bool Pressed = {read=FPressed, write=SetPressed, nodefault};
	__property System::Classes::TNotifyEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property Gxs::Gui::TgxGuiComponentName GuiLayoutNamePressed = {read=FGuiLayoutNamePressed, write=SetGuiLayoutNamePressed};
	__property float LogicWidth = {read=FLogicWidth, write=SetLogicWidth};
	__property float LogicHeight = {read=FLogicHeight, write=SetLogicHeight};
	__property float XOffset = {read=FXOffSet, write=SetXOffset};
	__property float YOffset = {read=FYOffSet, write=SetYOffset};
	__property bool AllowUp = {read=FAllowUp, write=FAllowUp, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxButton(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxEdit : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	int FSelStart;
	bool FReadOnly;
	System::UnicodeString FEditChar;
	
protected:
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalKeyPress(System::WideChar &Key);
	virtual void __fastcall InternalKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall InternalKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall SetFocused(bool Value);
	void __fastcall SetSelStart(const int Value);
	void __fastcall SetEditChar(const System::UnicodeString Value);
	
public:
	__fastcall virtual TgxEdit(System::Classes::TComponent* AOwner);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property System::UnicodeString EditChar = {read=FEditChar, write=SetEditChar};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property int SelStart = {read=FSelStart, write=SetSelStart, nodefault};
public:
	/* TgxFocusControl.Destroy */ inline __fastcall virtual ~TgxEdit() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxEdit(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxLabel : public TgxBaseTextControl
{
	typedef TgxBaseTextControl inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	Gxs::Imageutils::TgxTextLayout FTextLayout;
	void __fastcall SetAlignment(const System::Classes::TAlignment Value);
	void __fastcall SetTextLayout(const Gxs::Imageutils::TgxTextLayout Value);
	
public:
	__fastcall virtual TgxLabel(System::Classes::TComponent* AOwner);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property Gxs::Imageutils::TgxTextLayout TextLayout = {read=FTextLayout, write=SetTextLayout, nodefault};
public:
	/* TgxBaseFontControl.Destroy */ inline __fastcall virtual ~TgxLabel() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxLabel(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseTextControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxAdvancedLabel : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
public:
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
public:
	/* TgxFocusControl.Destroy */ inline __fastcall virtual ~TgxAdvancedLabel() { }
	
public:
	/* TgxBaseFontControl.Create */ inline __fastcall virtual TgxAdvancedLabel(System::Classes::TComponent* AOwner) : TgxFocusControl(AOwner) { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxAdvancedLabel(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxScrollbar : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	float FMin;
	float FMax;
	float FStep;
	float FPos;
	float FPageSize;
	System::Classes::TNotifyEvent FOnChange;
	Gxs::Gui::TgxGuiComponentName FGuiLayoutKnobName;
	Gxs::Gui::TgxGuiComponent* FGuiKnobComponent;
	Gxs::Gui::TGUIDrawResult FKnobRenderStatus;
	float FScrollOffs;
	bool FScrolling;
	bool FHorizontal;
	bool FLocked;
	
protected:
	void __fastcall SetMin(const float val);
	void __fastcall SetMax(const float val);
	void __fastcall SetPos(const float val);
	void __fastcall SetPageSize(const float val);
	void __fastcall SetHorizontal(const bool val);
	void __fastcall SetGuiLayoutKnobName(Gxs::Gui::TgxGuiComponentName newName);
	virtual void __fastcall SetGuiLayout(Gxs::Gui::TgxGuiLayout* NewGui);
	float __fastcall GetScrollPosY(float ScrollPos);
	float __fastcall GetYScrollPos(float Y);
	float __fastcall GetScrollPosX(float ScrollPos);
	float __fastcall GetXScrollPos(float X);
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseUp(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	virtual void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TgxScrollbar(System::Classes::TComponent* AOwner);
	void __fastcall StepUp();
	void __fastcall StepDown();
	void __fastcall PageUp();
	void __fastcall PageDown();
	virtual bool __fastcall MouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	
__published:
	__property bool Horizontal = {read=FHorizontal, write=SetHorizontal, nodefault};
	__property float Pos = {read=FPos, write=SetPos};
	__property float Min = {read=FMin, write=SetMin};
	__property float Max = {read=FMax, write=SetMax};
	__property float Step = {read=FStep, write=FStep};
	__property float PageSize = {read=FPageSize, write=SetPageSize};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Gxs::Gui::TgxGuiComponentName GuiLayoutKnobName = {read=FGuiLayoutKnobName, write=SetGuiLayoutKnobName};
	__property bool Locked = {read=FLocked, write=FLocked, default=0};
public:
	/* TgxFocusControl.Destroy */ inline __fastcall virtual ~TgxScrollbar() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxScrollbar(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION StringGrid : public TgxFocusControl
{
	typedef TgxFocusControl inherited;
	
private:
	int FSelCol;
	int FSelRow;
	bool FRowSelect;
	bool FColSelect;
	System::Classes::TStrings* FColumns;
	System::Classes::TList* FRows;
	Gxs::Color::TgxColorVector FHeaderColor;
	int FMarginSize;
	int FColumnSize;
	int FRowHeight;
	TgxScrollbar* FScrollbar;
	bool FDrawHeader;
	
protected:
	bool __fastcall GetCell(int X, int Y, /* out */ int &oCol, /* out */ int &oRow);
	virtual void __fastcall InternalMouseDown(System::Classes::TShiftState Shift, System::Uitypes::TMouseButton Button, int X, int Y);
	void __fastcall SetColumns(System::Classes::TStrings* const val);
	void __fastcall SetColSelect(const bool val);
	System::Classes::TStringList* __fastcall GetRow(int index);
	void __fastcall SetRow(int index, System::Classes::TStringList* const val);
	int __fastcall GetRowCount();
	void __fastcall SetRowCount(const int val);
	void __fastcall SetSelCol(const int val);
	void __fastcall SetSelRow(const int val);
	void __fastcall SetRowSelect(const bool val);
	void __fastcall SetDrawHeader(const bool val);
	System::Uitypes::TColor __fastcall GetHeaderColor();
	void __fastcall SetHeaderColor(const System::Uitypes::TColor val);
	void __fastcall SetMarginSize(const int val);
	void __fastcall SetColumnSize(const int val);
	void __fastcall SetRowHeight(const int val);
	void __fastcall SetScrollbar(TgxScrollbar* const val);
	virtual void __fastcall SetGuiLayout(Gxs::Gui::TgxGuiLayout* NewGui);
	
public:
	__fastcall virtual StringGrid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~StringGrid();
	void __fastcall Clear();
	int __fastcall Add(System::UnicodeString *Data, const System::NativeInt Data_High)/* overload */;
	int __fastcall Add(const System::UnicodeString Data)/* overload */;
	void __fastcall SetText(System::UnicodeString Data);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall InternalRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	void __fastcall OnStringListChange(System::TObject* Sender);
	__property System::Classes::TStringList* Row[int index] = {read=GetRow, write=SetRow};
	
__published:
	__property System::Uitypes::TColor HeaderColor = {read=GetHeaderColor, write=SetHeaderColor, nodefault};
	__property System::Classes::TStrings* Columns = {read=FColumns, write=SetColumns};
	__property int MarginSize = {read=FMarginSize, write=SetMarginSize, nodefault};
	__property int ColumnSize = {read=FColumnSize, write=SetColumnSize, nodefault};
	__property int RowHeight = {read=FRowHeight, write=SetRowHeight, nodefault};
	__property int RowCount = {read=GetRowCount, write=SetRowCount, nodefault};
	__property int SelCol = {read=FSelCol, write=SetSelCol, nodefault};
	__property int SelRow = {read=FSelRow, write=SetSelRow, nodefault};
	__property bool RowSelect = {read=FRowSelect, write=SetRowSelect, nodefault};
	__property bool ColSelect = {read=FColSelect, write=SetColSelect, nodefault};
	__property bool DrawHeader = {read=FDrawHeader, write=SetDrawHeader, nodefault};
	__property TgxScrollbar* Scrollbar = {read=FScrollbar, write=SetScrollbar};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall StringGrid(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxFocusControl(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall UnpressGroup(Gxs::Scene::TgxBaseSceneObject* CurrentObject, int AGroupID);
}	/* namespace Windows */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_WINDOWS)
using namespace Gxs::Windows;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_WindowsHPP
