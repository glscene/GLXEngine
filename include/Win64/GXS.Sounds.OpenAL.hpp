// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Sounds.OpenAL.pas' rev: 36.00 (Windows)

#ifndef GXS_Sounds_OpenALHPP
#define GXS_Sounds_OpenALHPP

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
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <OpenAL.Import.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.SoundManager.hpp>
#include <GXS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Sounds
{
namespace Openal
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSMOpenAL;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxSMOpenAL : public Gxs::Soundmanager::TgxSoundManager
{
	typedef Gxs::Soundmanager::TgxSoundManager inherited;
	
private:
	bool FActivated;
	
protected:
	virtual bool __fastcall DoActivate();
	virtual void __fastcall DoDeActivate();
	virtual void __fastcall NotifyMasterVolumeChange();
	virtual void __fastcall Notify3DFactorsChanged();
	virtual void __fastcall NotifyEnvironmentChanged();
	virtual void __fastcall KillSource(Gxs::Soundmanager::TgxBaseSoundSource* aSource);
	virtual void __fastcall UpdateSource(Gxs::Soundmanager::TgxBaseSoundSource* aSource);
	virtual void __fastcall MuteSource(Gxs::Soundmanager::TgxBaseSoundSource* aSource, bool muted);
	virtual void __fastcall PauseSource(Gxs::Soundmanager::TgxBaseSoundSource* aSource, bool paused);
	int __fastcall GetDefaultFrequency(Gxs::Soundmanager::TgxBaseSoundSource* aSource);
	int __fastcall GetALFormat(Gxs::Soundfileobjects::TgxSoundSampling* sampling);
	
public:
	__fastcall virtual TgxSMOpenAL(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSMOpenAL();
	virtual void __fastcall UpdateSources();
	virtual bool __fastcall EAXSupported();
};


typedef System::Sysutils::Exception EOpenALError;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Openal */
}	/* namespace Sounds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDS_OPENAL)
using namespace Gxs::Sounds::Openal;
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
#endif	// GXS_Sounds_OpenALHPP
