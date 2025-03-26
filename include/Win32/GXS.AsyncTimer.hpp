// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.AsyncTimer.pas' rev: 36.00 (Windows)

#ifndef GXS_AsyncTimerHPP
#define GXS_AsyncTimerHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.SyncObjs.hpp>
#include <Stage.Utils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Asynctimer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxAsyncTimer;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxAsyncTimer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FEnabled;
	System::Classes::TNotifyEvent FOnTimer;
	System::Classes::TThread* FTimerThread;
	System::Syncobjs::TCriticalSection* FMutex;
	
protected:
	void __fastcall SetEnabled(bool Value);
	System::Word __fastcall GetInterval();
	void __fastcall SetInterval(System::Word Value);
	System::Classes::TThreadPriority __fastcall GetThreadPriority();
	void __fastcall SetThreadPriority(System::Classes::TThreadPriority Value);
	void __fastcall DoTimer();
	
public:
	__fastcall virtual TgxAsyncTimer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxAsyncTimer();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=0};
	__property System::Word Interval = {read=GetInterval, write=SetInterval, default=1000};
	__property System::Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=FOnTimer};
	__property System::Classes::TThreadPriority ThreadPriority = {read=GetThreadPriority, write=SetThreadPriority, default=6};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word cDEFAULT_TIMER_INTERVAL = System::Word(0x3e8);
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Asynctimer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ASYNCTIMER)
using namespace Gxs::Asynctimer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_AsyncTimerHPP
