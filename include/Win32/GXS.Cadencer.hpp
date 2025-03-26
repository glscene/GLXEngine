// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Cadencer.pas' rev: 36.00 (Windows)

#ifndef GXS_CadencerHPP
#define GXS_CadencerHPP

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
#include <System.Messaging.hpp>
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Forms.hpp>
#include <GXS.Scene.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cadencer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCadencer;
class DELPHICLASS TgxCustomCadencedComponent;
class DELPHICLASS TgxCadencedComponent;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxCadencerMode : unsigned char { cmManual, cmASAP, cmApplicationIdle };

enum DECLSPEC_DENUM TgxCadencerTimeReference : unsigned char { cmRTC, cmPerformanceCounter, cmExternal };

class PASCALIMPLEMENTATION TgxCadencer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* FSubscribedCadenceableComponents;
	Gxs::Scene::TgxScene* FScene;
	double FTimeMultiplier;
	double lastTime;
	double downTime;
	double lastMultiplier;
	bool FEnabled;
	int FSleepLength;
	TgxCadencerMode FMode;
	TgxCadencerTimeReference FTimeReference;
	double FCurrentTime;
	double FOriginTime;
	double FMaxDeltaTime;
	double FMinDeltaTime;
	double FFixedDeltaTime;
	Gxs::Baseclasses::TgxProgressEvent FOnProgress;
	Gxs::Baseclasses::TgxProgressEvent FOnTotalProgress;
	int FProgressing;
	void __fastcall SetCurrentTime(const double Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	bool __fastcall StoreTimeMultiplier();
	void __fastcall SetEnabled(const bool val);
	void __fastcall SetScene(Gxs::Scene::TgxScene* const val);
	void __fastcall SetMode(const TgxCadencerMode val);
	void __fastcall SetTimeReference(const TgxCadencerTimeReference val);
	void __fastcall SetTimeMultiplier(const double val);
	double __fastcall GetRawReferenceTime();
	void __fastcall RestartASAP();
	virtual void __fastcall Loaded();
	void __fastcall OnIdleEvent(System::TObject* Sender, bool &Done);
	
public:
	__fastcall virtual TgxCadencer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCadencer();
	void __fastcall Subscribe(Gxs::Baseclasses::TgxCadenceAbleComponent* aComponent);
	void __fastcall UnSubscribe(Gxs::Baseclasses::TgxCadenceAbleComponent* aComponent);
	void __fastcall Progress();
	double __fastcall GetCurrenttime();
	bool __fastcall IsBusy();
	void __fastcall Reset();
	__property double OriginTime = {read=FOriginTime, write=FOriginTime};
	__property double CurrentTime = {read=FCurrentTime, write=SetCurrentTime};
	
__published:
	__property Gxs::Scene::TgxScene* Scene = {read=FScene, write=SetScene};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TgxCadencerTimeReference TimeReference = {read=FTimeReference, write=SetTimeReference, default=1};
	__property double TimeMultiplier = {read=FTimeMultiplier, write=SetTimeMultiplier, stored=StoreTimeMultiplier};
	__property double MaxDeltaTime = {read=FMaxDeltaTime, write=FMaxDeltaTime};
	__property double MinDeltaTime = {read=FMinDeltaTime, write=FMinDeltaTime};
	__property double FixedDeltaTime = {read=FFixedDeltaTime, write=FFixedDeltaTime};
	__property TgxCadencerMode Mode = {read=FMode, write=SetMode, default=1};
	__property int SleepLength = {read=FSleepLength, write=FSleepLength, default=-1};
	__property Gxs::Baseclasses::TgxProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property Gxs::Baseclasses::TgxProgressEvent OnTotalProgress = {read=FOnTotalProgress, write=FOnTotalProgress};
};


class PASCALIMPLEMENTATION TgxCustomCadencedComponent : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	TgxCadencer* FCadencer;
	
protected:
	void __fastcall SetCadencer(TgxCadencer* const val);
	__property TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	
public:
	__fastcall virtual ~TgxCustomCadencedComponent();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
public:
	/* TComponent.Create */ inline __fastcall virtual TgxCustomCadencedComponent(System::Classes::TComponent* AOwner) : Gxs::Baseclasses::TgxUpdateAbleComponent(AOwner) { }
	
};


class PASCALIMPLEMENTATION TgxCadencedComponent : public TgxCustomCadencedComponent
{
	typedef TgxCustomCadencedComponent inherited;
	
__published:
	__property Cadencer;
public:
	/* TgxCustomCadencedComponent.Destroy */ inline __fastcall virtual ~TgxCadencedComponent() { }
	
public:
	/* TComponent.Create */ inline __fastcall virtual TgxCadencedComponent(System::Classes::TComponent* AOwner) : TgxCustomCadencedComponent(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cadencer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CADENCER)
using namespace Gxs::Cadencer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CadencerHPP
