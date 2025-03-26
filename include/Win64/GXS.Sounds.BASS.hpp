// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Sounds.BASS.pas' rev: 36.00 (Windows)

#ifndef GXS_Sounds_BASSHPP
#define GXS_Sounds_BASSHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Forms.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.SoundManager.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <BASS.Import.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Sounds
{
namespace Bass
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSMBASS;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TBASS3DAlgorithm : unsigned char { algDefault, algOff, algFull, algLight };

class PASCALIMPLEMENTATION TgxSMBASS : public Gxs::Soundmanager::TgxSoundManager
{
	typedef Gxs::Soundmanager::TgxSoundManager inherited;
	
private:
	bool FActivated;
	TBASS3DAlgorithm FAlgorithm3D;
	
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
	
public:
	__fastcall virtual TgxSMBASS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSMBASS();
	virtual void __fastcall UpdateSources();
	virtual float __fastcall CPUUsagePercent();
	virtual bool __fastcall EAXSupported();
	
__published:
	__property TBASS3DAlgorithm Algorithm3D = {read=FAlgorithm3D, write=FAlgorithm3D, default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Bass */
}	/* namespace Sounds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDS_BASS)
using namespace Gxs::Sounds::Bass;
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
#endif	// GXS_Sounds_BASSHPP
