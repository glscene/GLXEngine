// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FullScreenViewer.pas' rev: 36.00 (Windows)

#ifndef GXS_FullScreenViewerHPP
#define GXS_FullScreenViewerHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Types.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Menus.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.WinContext.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Screen.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fullscreenviewer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFullScreenViewer;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxScreenDepth : unsigned char { sd8bits, sd16bits, sd24bits, sd32bits };

class PASCALIMPLEMENTATION TgxFullScreenViewer : public Gxs::Scene::TgxNonVisualViewer
{
	typedef Gxs::Scene::TgxNonVisualViewer inherited;
	
private:
	bool FFormIsOwned;
	Fmx::Forms::TForm* FForm;
	Winapi::Windows::THandle FOwnDC;
	TgxScreenDepth FScreenDepth;
	bool FActive;
	bool FSwitchedResolution;
	bool FManualRendering;
	int FUpdateCount;
	Fmx::Types::TMouseEvent FOnMouseDown;
	Fmx::Types::TMouseEvent FOnMouseUp;
	Fmx::Types::TMouseMoveEvent FOnMouseMove;
	Fmx::Types::TMouseWheelEvent FOnMouseWheel;
	Fmx::Types::TMouseWheelEvent FOnMouseWheelDown;
	Fmx::Types::TMouseWheelEvent FOnMouseWheelUp;
	System::Classes::TNotifyEvent FOnClick;
	System::Classes::TNotifyEvent FOnDblClick;
	Fmx::Types::TKeyEvent FOnKeyDown;
	Fmx::Types::TKeyEvent FOnKeyUp;
	Fmx::Types::TKeyEvent FOnKeyPress;
	Fmx::Forms::TCloseEvent FOnClose;
	Fmx::Forms::TCloseQueryEvent FOnCloseQuery;
	bool FStayOnTop;
	Gxs::Context::TgxSyncMode FVSync;
	int FRefreshRate;
	Fmx::Menus::TPopupMenu* FPopupMenu;
	void __fastcall SetScreenDepth(const TgxScreenDepth val);
	void __fastcall SetActive(const bool val);
	void __fastcall SetOnMouseDown(const Fmx::Types::TMouseEvent val);
	void __fastcall SetOnMouseUp(const Fmx::Types::TMouseEvent val);
	void __fastcall SetOnMouseMove(const Fmx::Types::TMouseMoveEvent val);
	void __fastcall SetOnMouseWheel(const Fmx::Types::TMouseWheelEvent val);
	void __fastcall SetOnMouseWheelDown(const Fmx::Types::TMouseWheelEvent val);
	void __fastcall SetOnMouseWheelUp(const Fmx::Types::TMouseWheelEvent val);
	void __fastcall SetOnClick(const System::Classes::TNotifyEvent val);
	void __fastcall SetOnDblClick(const System::Classes::TNotifyEvent val);
	void __fastcall SetOnCloseQuery(const Fmx::Forms::TCloseQueryEvent val);
	void __fastcall SetOnClose(const Fmx::Forms::TCloseEvent val);
	void __fastcall SetOnKeyUp(const Fmx::Types::TKeyEvent val);
	void __fastcall SetOnKeyDown(const Fmx::Types::TKeyEvent val);
	void __fastcall SetOnKeyPress(const Fmx::Types::TKeyEvent val);
	void __fastcall SetStayOnTop(const bool val);
	void __fastcall SetPopupMenu(Fmx::Menus::TPopupMenu* const val);
	void __fastcall SetForm(Fmx::Forms::TForm* aVal);
	void __fastcall SetManualRendering(const bool val);
	
protected:
	Fmx::Types::TWindowHandle* __fastcall GetHandle();
	void __fastcall DoBeforeRender(System::TObject* Sender);
	virtual void __fastcall DoBufferChange(System::TObject* Sender);
	virtual void __fastcall DoBufferStructuralChange(System::TObject* Sender);
	void __fastcall Startup();
	void __fastcall Shutdown();
	void __fastcall BindFormEvents();
	void __fastcall DoCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall DoPaint(System::TObject* Sender);
	void __fastcall DoActivate(System::TObject* Sender);
	void __fastcall DoDeactivate(System::TObject* Sender);
	void __fastcall DoFormDestroy(System::TObject* Sender);
	
public:
	__fastcall virtual TgxFullScreenViewer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxFullScreenViewer();
	virtual void __fastcall Render(Gxs::Scene::TgxBaseSceneObject* baseObject = (Gxs::Scene::TgxBaseSceneObject*)(0x0));
	void __fastcall UseCurrentResolution();
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	void __fastcall ReActivate();
	__property Fmx::Types::TWindowHandle* Handle = {read=GetHandle};
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	float __fastcall LastFrameTime();
	float __fastcall FramesPerSecond();
	System::UnicodeString __fastcall FramesPerSecondText(int decimals = 0x1);
	void __fastcall ResetPerformanceMonitor();
	__property Winapi::Windows::THandle RenderDC = {read=FOwnDC, nodefault};
	
__published:
	__property Fmx::Forms::TForm* Form = {read=FForm, write=SetForm};
	__property bool ManualRendering = {read=FManualRendering, write=SetManualRendering, nodefault};
	__property TgxScreenDepth ScreenDepth = {read=FScreenDepth, write=SetScreenDepth, default=3};
	__property bool StayOnTop = {read=FStayOnTop, write=SetStayOnTop, default=0};
	__property Gxs::Context::TgxSyncMode VSync = {read=FVSync, write=FVSync, default=0};
	__property int RefreshRate = {read=FRefreshRate, write=FRefreshRate, nodefault};
	__property Fmx::Menus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property Fmx::Forms::TCloseEvent OnClose = {read=FOnClose, write=SetOnClose};
	__property Fmx::Types::TKeyEvent OnKeyUp = {read=FOnKeyUp, write=SetOnKeyUp};
	__property Fmx::Types::TKeyEvent OnKeyDown = {read=FOnKeyDown, write=SetOnKeyDown};
	__property Fmx::Types::TKeyEvent OnKeyPress = {read=FOnKeyPress, write=SetOnKeyPress};
	__property Fmx::Forms::TCloseQueryEvent OnCloseQuery = {read=FOnCloseQuery, write=SetOnCloseQuery};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=SetOnClick};
	__property System::Classes::TNotifyEvent OnDblClick = {read=FOnDblClick, write=SetOnDblClick};
	__property Fmx::Types::TMouseEvent OnMouseDown = {read=FOnMouseDown, write=SetOnMouseDown};
	__property Fmx::Types::TMouseEvent OnMouseUp = {read=FOnMouseUp, write=SetOnMouseUp};
	__property Fmx::Types::TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=SetOnMouseMove};
	__property Fmx::Types::TMouseWheelEvent OnMouseWheel = {read=FOnMouseWheel, write=SetOnMouseWheel};
	__property Fmx::Types::TMouseWheelEvent OnMouseWheelDown = {read=FOnMouseWheelDown, write=SetOnMouseWheelDown};
	__property Fmx::Types::TMouseWheelEvent OnMouseWheelUp = {read=FOnMouseWheelUp, write=SetOnMouseWheelUp};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Fullscreenviewer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FULLSCREENVIEWER)
using namespace Gxs::Fullscreenviewer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FullScreenViewerHPP
