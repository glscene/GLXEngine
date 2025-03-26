// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Sounds.WaveOut.pas' rev: 36.00 (Windows)

#ifndef GLS_Sounds_WaveOutHPP
#define GLS_Sounds_WaveOutHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.MMSystem.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GLS.SoundManager.hpp>
#include <GLS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Sounds
{
namespace Waveout
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLSMWaveOut;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLSMWaveOut : public Gls::Soundmanager::TGLSoundManager
{
	typedef Gls::Soundmanager::TGLSoundManager inherited;
	
protected:
	virtual bool __fastcall DoActivate();
	virtual void __fastcall DoDeActivate();
	virtual void __fastcall KillSource(Gls::Soundmanager::TGLBaseSoundSource* aSource);
	
public:
	__fastcall virtual TGLSMWaveOut(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLSMWaveOut();
	virtual void __fastcall UpdateSources();
	
__published:
	__property MaxChannels = {default=4};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall PlayOnWaveOut(void * pcmData, int lengthInBytes, const tWAVEFORMATEX &waveFormat)/* overload */;
extern DELPHI_PACKAGE void __fastcall PlayOnWaveOut(void * pcmData, int lengthInBytes, Gls::Soundfileobjects::TGLSoundSampling* sampling)/* overload */;
}	/* namespace Waveout */
}	/* namespace Sounds */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SOUNDS_WAVEOUT)
using namespace Gls::Sounds::Waveout;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SOUNDS)
using namespace Gls::Sounds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_Sounds_WaveOutHPP
