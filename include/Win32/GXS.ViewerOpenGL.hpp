// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ViewerOpenGL.pas' rev: 36.00 (Windows)

#ifndef GXS_ViewerOpenGLHPP
#define GXS_ViewerOpenGLHPP

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
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Platform.Win.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.WinContext.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Vieweropengl
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSceneViewport;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxSceneViewport : public Fmx::Controls::TControl
{
	typedef Fmx::Controls::TControl inherited;
	
private:
	Gxs::Scene::TgxSceneBuffer* FGLSBuffer;
	Fmx::Graphics::TBitmap* FFMXBuffer;
	Fmx::Types3d::TContext3D* FFMXContext;
	Fmx::Types3d::TMultisample FMultisample;
	HWND FParentHandle;
	HDC FOwnDC;
	bool FDrawing;
	System::Classes::TNotifyEvent FPostRender;
	void __fastcall SetBuffer(Gxs::Scene::TgxSceneBuffer* const Value);
	Gxs::Scene::TgxCamera* __fastcall GetSceneCamera();
	void __fastcall SetSceneCamera(Gxs::Scene::TgxCamera* const Value);
	void __fastcall CopyBuffer(System::TObject* Sender);
	void __fastcall SetBeforeRender(const System::Classes::TNotifyEvent Value);
	System::Classes::TNotifyEvent __fastcall GetBeforeRender();
	void __fastcall SetAfterRender(const System::Classes::TNotifyEvent Value);
	System::Classes::TNotifyEvent __fastcall GetAfterRender();
	
protected:
	virtual void __fastcall Paint();
	
public:
	__fastcall virtual TgxSceneViewport(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSceneViewport();
	HIDESBASE void __fastcall Realign();
	
__published:
	__property System::Classes::TNotifyEvent BeforeRender = {read=GetBeforeRender, write=SetBeforeRender};
	__property System::Classes::TNotifyEvent PostRender = {read=FPostRender, write=FPostRender};
	__property System::Classes::TNotifyEvent AfterRender = {read=GetAfterRender, write=SetAfterRender};
	__property Gxs::Scene::TgxSceneBuffer* Buffer = {read=FGLSBuffer, write=SetBuffer};
	__property Gxs::Scene::TgxCamera* SceneCamera = {read=GetSceneCamera, write=SetSceneCamera};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Vieweropengl */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_VIEWEROPENGL)
using namespace Gxs::Vieweropengl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ViewerOpenGLHPP
