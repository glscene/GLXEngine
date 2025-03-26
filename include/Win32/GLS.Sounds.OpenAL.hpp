// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Sounds.OpenAL.pas' rev: 36.00 (Windows)

#ifndef GLS_Sounds_OpenALHPP
#define GLS_Sounds_OpenALHPP

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
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.SoundManager.hpp>
#include <GLS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Sounds
{
namespace Openal
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLSMOpenAL;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLSMOpenAL : public Gls::Soundmanager::TGLSoundManager
{
	typedef Gls::Soundmanager::TGLSoundManager inherited;
	
private:
	bool FActivated;
	
protected:
	virtual bool __fastcall DoActivate();
	virtual void __fastcall DoDeActivate();
	virtual void __fastcall NotifyMasterVolumeChange();
	virtual void __fastcall Notify3DFactorsChanged();
	virtual void __fastcall NotifyEnvironmentChanged();
	virtual void __fastcall KillSource(Gls::Soundmanager::TGLBaseSoundSource* aSource);
	virtual void __fastcall UpdateSource(Gls::Soundmanager::TGLBaseSoundSource* aSource);
	virtual void __fastcall MuteSource(Gls::Soundmanager::TGLBaseSoundSource* aSource, bool muted);
	virtual void __fastcall PauseSource(Gls::Soundmanager::TGLBaseSoundSource* aSource, bool paused);
	int __fastcall GetDefaultFrequency(Gls::Soundmanager::TGLBaseSoundSource* aSource);
	int __fastcall GetALFormat(Gls::Soundfileobjects::TGLSoundSampling* sampling);
	
public:
	__fastcall virtual TGLSMOpenAL(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLSMOpenAL();
	virtual void __fastcall UpdateSources();
	virtual bool __fastcall EAXSupported();
};


typedef System::Sysutils::Exception EOpenALError;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Openal */
}	/* namespace Sounds */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SOUNDS_OPENAL)
using namespace Gls::Sounds::Openal;
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
#endif	// GLS_Sounds_OpenALHPP
