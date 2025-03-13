// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.WinContext.pas' rev: 36.00 (Windows)

#ifndef GXS_WinContextHPP
#define GXS_WinContextHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Platform.Win.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.Strings.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Wincontext
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxWinContext;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxWinContext : public Gxs::Context::TgxContext
{
	typedef Gxs::Context::TgxContext inherited;
	
	
private:
	typedef System::DynamicArray<int> _TgxWinContext__1;
	
	typedef System::DynamicArray<float> _TgxWinContext__2;
	
	
protected:
	HDC FDC;
	HGLRC FRC;
	TgxWinContext* FShareContext;
	int FHPBUFFER;
	_TgxWinContext__1 FiAttribs;
	_TgxWinContext__2 FfAttribs;
	bool FLegacyContextsOnly;
	bool FSwapBufferSupported;
	void __fastcall SpawnLegacyContext(HDC aDC);
	virtual void __fastcall CreateOldContext(HDC aDC);
	virtual void __fastcall CreateNewContext(HDC aDC);
	void __fastcall ClearIAttribs();
	void __fastcall AddIAttrib(int attrib, int value);
	void __fastcall ChangeIAttrib(int attrib, int newValue);
	void __fastcall DropIAttrib(int attrib);
	void __fastcall ClearFAttribs();
	void __fastcall AddFAttrib(float attrib, float value);
	void __fastcall DestructionEarlyWarning(System::TObject* sender);
	void __fastcall ChooseWGLFormat(HDC DC, unsigned nMaxFormats, System::PInteger piFormats, int &nNumFormats, int BufferCount = 0x1);
	virtual void __fastcall DoCreateContext(Winapi::Windows::THandle ADeviceHandle);
	virtual void __fastcall DoCreateMemoryContext(Winapi::Windows::THandle OutputDevice, int Width, int Height, int BufferCount);
	virtual bool __fastcall DoShareLists(Gxs::Context::TgxContext* aContext);
	virtual void __fastcall DoDestroyContext();
	virtual void __fastcall DoActivate();
	virtual void __fastcall DoDeactivate();
	
public:
	__fastcall virtual TgxWinContext();
	__fastcall virtual ~TgxWinContext();
	virtual bool __fastcall IsValid();
	virtual void __fastcall SwapBuffers();
	virtual void * __fastcall RenderOutputDevice();
	__property HDC DC = {read=FDC};
	__property HGLRC RC = {read=FRC};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vUseWindowTrackingHook;
extern DELPHI_PACKAGE HWND __fastcall CreateTempWnd(void);
}	/* namespace Wincontext */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_WINCONTEXT)
using namespace Gxs::Wincontext;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_WinContextHPP
