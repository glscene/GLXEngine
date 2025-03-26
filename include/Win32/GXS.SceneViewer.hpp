// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SceneViewer.pas' rev: 36.00 (Windows)

#ifndef GXS_SceneViewerHPP
#define GXS_SceneViewerHPP

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
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Dialogs.Win.hpp>
#include <FMX.Viewport3D.hpp>
#include <Stage.OpenGL4.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.WinContext.hpp>
#include <FMX.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Sceneviewer
{
//-- forward type declarations -----------------------------------------------
struct TgxCreateParams;
class DELPHICLASS TgxSceneViewer;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TgxCreateParams
{
public:
	System::WideChar *Caption;
	unsigned Style;
	unsigned ExStyle;
	int X;
	int Y;
	int Width;
	int Height;
	void *Param;
	System::StaticArray<System::WideChar, 64> WinClassName;
};


typedef void __fastcall (__closure *TgxTouchEvent)(int X, int Y, int TouchWidth, int TouchHeight, unsigned TouchID, bool MultiTouch);

class PASCALIMPLEMENTATION TgxSceneViewer : public Fmx::Viewport3d::TViewport3D
{
	typedef Fmx::Viewport3d::TViewport3D inherited;
	
private:
	Gxs::Scene::TgxSceneBuffer* FBuffer;
	Gxs::Context::TgxSyncMode FVSync;
	HDC FOwnDC;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	bool FMouseInControl;
	System::Types::TPoint FLastScreenPos;
	bool FPenAsTouch;
	TgxTouchEvent FOnTouchMove;
	TgxTouchEvent FOnTouchUp;
	TgxTouchEvent FOnTouchDown;
	MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	MESSAGE void __fastcall WMGetDglCode(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMDestroy(Winapi::Messages::TWMDestroy &Message);
	MESSAGE void __fastcall WMTouch(Winapi::Messages::TMessage &Message);
	void __fastcall CMMouseEnter(Winapi::Messages::TMessage &msg);
	void __fastcall CMMouseLeave(Winapi::Messages::TMessage &msg);
	float __fastcall GetFieldOfView();
	void __fastcall SetFieldOfView(const float Value);
	bool __fastcall GetIsRenderingContextAvailable();
	
protected:
	void __fastcall SetBeforeRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetBeforeRender();
	void __fastcall SetPostRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetPostRender();
	void __fastcall SetAfterRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetAfterRender();
	HIDESBASE void __fastcall SetCamera(Gxs::Scene::TgxCamera* const val);
	HIDESBASE Gxs::Scene::TgxCamera* __fastcall GetCamera();
	void __fastcall SetBuffer(Gxs::Scene::TgxSceneBuffer* const val);
	void __fastcall CreateParams(TgxCreateParams &Params);
	void __fastcall CreateWnd();
	void __fastcall DestroyWnd();
	virtual void __fastcall Loaded();
	virtual void __fastcall DoBeforeRender(System::TObject* Sender);
	virtual void __fastcall DoBufferChange(System::TObject* Sender);
	virtual void __fastcall DoBufferStructuralChange(System::TObject* Sender);
	HIDESBASE void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TgxSceneViewer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSceneViewer();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RecreateWnd();
	__property bool IsRenderingContextAvailable = {read=GetIsRenderingContextAvailable, nodefault};
	float __fastcall LastFrameTime();
	float __fastcall FramesPerSecond();
	System::UnicodeString __fastcall FramesPerSecondText(int decimals = 0x1);
	void __fastcall ResetPerformanceMonitor();
	Fmx::Graphics::TBitmap* __fastcall CreateSnapShotBitmap();
	void __fastcall RegisterTouch();
	void __fastcall UnregisterTouch();
	__property HDC RenderDC = {read=FOwnDC, nodefault};
	__property bool MouseInControl = {read=FMouseInControl, nodefault};
	
__published:
	__property Gxs::Scene::TgxCamera* Camera = {read=GetCamera, write=SetCamera};
	__property Gxs::Context::TgxSyncMode VSync = {read=FVSync, write=FVSync, default=1};
	__property System::Classes::TNotifyEvent BeforeRender = {read=GetBeforeRender, write=SetBeforeRender};
	__property System::Classes::TNotifyEvent PostRender = {read=GetPostRender, write=SetPostRender};
	__property System::Classes::TNotifyEvent AfterRender = {read=GetAfterRender, write=SetAfterRender};
	__property Gxs::Scene::TgxSceneBuffer* Buffer = {read=FBuffer, write=SetBuffer};
	__property float FieldOfView = {read=GetFieldOfView, write=SetFieldOfView};
	__property bool PenAsTouch = {read=FPenAsTouch, write=FPenAsTouch, nodefault};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property TgxTouchEvent OnTouchMove = {read=FOnTouchMove, write=FOnTouchMove};
	__property TgxTouchEvent OnTouchUp = {read=FOnTouchUp, write=FOnTouchUp};
	__property TgxTouchEvent OnTouchDown = {read=FOnTouchDown, write=FOnTouchDown};
	__property Align = {default=0};
	__property Anchors;
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Hint = {default=0};
	__property PopupMenu;
	__property Visible = {default=1};
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnKeyDown;
	__property OnKeyUp;
	__property TabStop = {default=1};
	__property TabOrder = {default=-1};
	__property OnEnter;
	__property OnExit;
	__property OnGesture;
	__property Touch;
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE HWND Handle;
extern DELPHI_PACKAGE void __fastcall SetupVSync(const Gxs::Context::TgxSyncMode AVSyncMode);
}	/* namespace Sceneviewer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SCENEVIEWER)
using namespace Gxs::Sceneviewer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SceneViewerHPP
