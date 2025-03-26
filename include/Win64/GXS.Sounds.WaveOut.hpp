// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Sounds.WaveOut.pas' rev: 36.00 (Windows)

#ifndef GXS_Sounds_WaveOutHPP
#define GXS_Sounds_WaveOutHPP

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
#include <GXS.SoundManager.hpp>
#include <GXS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Sounds
{
namespace Waveout
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSMWaveOut;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxSMWaveOut : public Gxs::Soundmanager::TgxSoundManager
{
	typedef Gxs::Soundmanager::TgxSoundManager inherited;
	
protected:
	virtual bool __fastcall DoActivate();
	virtual void __fastcall DoDeActivate();
	virtual void __fastcall KillSource(Gxs::Soundmanager::TgxBaseSoundSource* aSource);
	
public:
	__fastcall virtual TgxSMWaveOut(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSMWaveOut();
	virtual void __fastcall UpdateSources();
	
__published:
	__property MaxChannels = {default=4};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE __int64 __fastcall PlayOnWaveOut(void * pcmData, int lengthInBytes, const tWAVEFORMATEX &waveFormat)/* overload */;
extern DELPHI_PACKAGE void __fastcall PlayOnWaveOut(void * pcmData, int lengthInBytes, Gxs::Soundfileobjects::TgxSoundSampling* sampling)/* overload */;
}	/* namespace Waveout */
}	/* namespace Sounds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDS_WAVEOUT)
using namespace Gxs::Sounds::Waveout;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDS)
using namespace Gxs::Sounds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_Sounds_WaveOutHPP
