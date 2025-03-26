// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TimeEventsMgr.pas' rev: 36.00 (Windows)

#ifndef GXS_TimeEventsMgrHPP
#define GXS_TimeEventsMgrHPP

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
#include <GXS.Cadencer.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Timeeventsmgr
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTimeEventsMGR;
class DELPHICLASS TgxTimeEvents;
class DELPHICLASS TgxTimeEvent;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxTimeEventsMGR : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	Gxs::Cadencer::TgxCadencer* FCadencer;
	bool FEnabled;
	bool FFreeEventOnEnd;
	TgxTimeEvents* FEvents;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetCadencer(Gxs::Cadencer::TgxCadencer* const val);
	void __fastcall SetEvents(TgxTimeEvents* const val);
	
public:
	__fastcall virtual TgxTimeEventsMGR(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxTimeEventsMGR();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall Reset();
	
__published:
	__property Gxs::Cadencer::TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property bool FreeEventOnEnd = {read=FFreeEventOnEnd, write=FFreeEventOnEnd, default=0};
	__property TgxTimeEvents* Events = {read=FEvents, write=SetEvents};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTimeEvents : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxTimeEvent* operator[](int index) { return this->Items[index]; }
	
protected:
	System::Classes::TComponent* Owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxTimeEvent* const val);
	TgxTimeEvent* __fastcall GetItems(int index);
	
public:
	__fastcall TgxTimeEvents(System::Classes::TComponent* aOwner);
	HIDESBASE TgxTimeEvent* __fastcall Add();
	HIDESBASE TgxTimeEvent* __fastcall FindItemID(int ID);
	TgxTimeEvent* __fastcall EventByName(System::UnicodeString name);
	__property TgxTimeEvent* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxTimeEvents() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TgxTimeEventType : unsigned char { etOneShot, etContinuous, etPeriodic };

typedef void __fastcall (__closure *TgxTimeEventProc)(TgxTimeEvent* event);

class PASCALIMPLEMENTATION TgxTimeEvent : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	double FStartTime;
	double FEndTime;
	double FElapsedTime;
	double FPeriod;
	TgxTimeEventType FEventType;
	TgxTimeEventProc FOnEvent;
	bool FEnabled;
	unsigned FTickCount;
	void __fastcall SetEnabled(const bool Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetName(System::UnicodeString val);
	void __fastcall DoEvent(const double curTime);
	
public:
	__fastcall virtual TgxTimeEvent(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxTimeEvent();
	__property unsigned TickCount = {read=FTickCount, nodefault};
	__property double ElapsedTime = {read=FElapsedTime};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property double StartTime = {read=FStartTime, write=FStartTime};
	__property double EndTime = {read=FEndTime, write=FEndTime};
	__property double Period = {read=FPeriod, write=FPeriod};
	__property TgxTimeEventType EventType = {read=FEventType, write=FEventType, default=0};
	__property TgxTimeEventProc OnEvent = {read=FOnEvent, write=FOnEvent};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Timeeventsmgr */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TIMEEVENTSMGR)
using namespace Gxs::Timeeventsmgr;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TimeEventsMgrHPP
