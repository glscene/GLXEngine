// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.TimeLine.pas' rev: 36.00 (Windows)

#ifndef GBE_TimeLineHPP
#define GBE_TimeLineHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Timeline
{
//-- forward type declarations -----------------------------------------------
struct TGBEStep;
class DELPHICLASS TGBETimeline;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TGBEStep
{
public:
	float Duration;
	float Delay;
	System::UnicodeString PropertyName;
	float StartValue;
	float StopValue;
	bool AutoReverse;
	bool Inverse;
	bool StartFromCurrent;
	Fmx::Types::TInterpolationType Interpolation;
	Fmx::Types::TAnimationType AnimationType;
};


class PASCALIMPLEMENTATION TGBETimeline : public Fmx::Ani::TFloatAnimation
{
	typedef Fmx::Ani::TFloatAnimation inherited;
	
private:
	System::Generics::Collections::TList__1<TGBEStep>* fListeAnimation;
	bool fLoopSteps;
	int __fastcall GetCount();
	void __fastcall RunAnimation(int Indice);
	void __fastcall Finish(System::TObject* Sender);
	
public:
	__fastcall virtual TGBETimeline(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBETimeline();
	void __fastcall Clear();
	void __fastcall AddStep(const TGBEStep &aStep);
	void __fastcall Run();
	
__published:
	__property int count = {read=GetCount, nodefault};
	__property bool loopSteps = {read=fLoopSteps, write=fLoopSteps, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Timeline */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_TIMELINE)
using namespace Gbe::Timeline;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_TimeLineHPP
