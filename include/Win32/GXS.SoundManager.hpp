// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SoundManager.pas' rev: 36.00 (Windows)

#ifndef GXS_SoundManagerHPP
#define GXS_SoundManagerHPP

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
#include <System.Types.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.XCollection.hpp>
#include <GXS.SoundFileObjects.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Cadencer.hpp>
#include <Stage.Utils.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Soundmanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSoundSample;
class DELPHICLASS TgxSoundSamples;
class DELPHICLASS TgxSoundLibrary;
class DELPHICLASS TgxBaseSoundSource;
class DELPHICLASS TgxSoundSource;
class DELPHICLASS TgxSoundSources;
class DELPHICLASS TgxSoundManager;
class DELPHICLASS TgxBSoundEmitter;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundSample : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	Gxs::Soundfileobjects::TgxSoundFile* FData;
	int FTag;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetData(Gxs::Soundfileobjects::TgxSoundFile* const val);
	
public:
	__fastcall virtual TgxSoundSample(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxSoundSample();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall PlayOnWaveOut();
	Gxs::Soundfileobjects::TgxSoundSampling* __fastcall Sampling();
	int __fastcall LengthInBytes();
	int __fastcall LengthInSamples();
	float __fastcall LengthInSec();
	__property int ManagerTag = {read=FTag, write=FTag, nodefault};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Gxs::Soundfileobjects::TgxSoundFile* Data = {read=FData, write=SetData, stored=false};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundSamples : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxSoundSample* operator[](int index) { return this->Items[index]; }
	
protected:
	System::Classes::TComponent* owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxSoundSample* const val);
	TgxSoundSample* __fastcall GetItems(int index);
	
public:
	__fastcall TgxSoundSamples(System::Classes::TComponent* AOwner);
	HIDESBASE TgxSoundSample* __fastcall Add();
	HIDESBASE TgxSoundSample* __fastcall FindItemID(int ID);
	__property TgxSoundSample* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TgxSoundSample* __fastcall GetByName(const System::UnicodeString aName);
	TgxSoundSample* __fastcall AddFile(const System::UnicodeString fileName, const System::UnicodeString sampleName = System::UnicodeString());
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxSoundSamples() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxSoundLibrary : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxSoundSamples* FSamples;
	
protected:
	void __fastcall SetSamples(TgxSoundSamples* const val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxSoundLibrary(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSoundLibrary();
	
__published:
	__property TgxSoundSamples* Samples = {read=FSamples, write=SetSamples};
};


enum DECLSPEC_DENUM TgxSoundSourceChange : unsigned char { sscTransformation, sscSample, sscStatus };

typedef System::Set<TgxSoundSourceChange, TgxSoundSourceChange::sscTransformation, TgxSoundSourceChange::sscStatus> TgxSoundSourceChanges;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBaseSoundSource : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxBSoundEmitter* FBehaviourToNotify;
	int FPriority;
	Gxs::Scene::TgxBaseSceneObject* FOrigin;
	float FVolume;
	float FMinDistance;
	float FMaxDistance;
	float FInsideConeAngle;
	float FOutsideConeAngle;
	float FConeOutsideVolume;
	System::UnicodeString FSoundLibraryName;
	TgxSoundLibrary* FSoundLibrary;
	System::UnicodeString FSoundName;
	bool FMute;
	bool FPause;
	TgxSoundSourceChanges FChanges;
	int FNbLoops;
	unsigned FTag;
	int FFrequency;
	
protected:
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetPriority(const int val);
	void __fastcall SetOrigin(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetVolume(const float val);
	void __fastcall SetMinDistance(const float val);
	void __fastcall SetMaxDistance(const float val);
	void __fastcall SetInsideConeAngle(const float val);
	void __fastcall SetOutsideConeAngle(const float val);
	void __fastcall SetConeOutsideVolume(const float val);
	TgxSoundLibrary* __fastcall GetSoundLibrary();
	void __fastcall SetSoundLibrary(TgxSoundLibrary* const val);
	void __fastcall SetSoundName(const System::UnicodeString val);
	void __fastcall SetMute(const bool val);
	void __fastcall SetPause(const bool val);
	void __fastcall SetNbLoops(const int val);
	void __fastcall SetFrequency(const int val);
	
public:
	__fastcall virtual TgxBaseSoundSource(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxBaseSoundSource();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TgxSoundSourceChanges Changes = {read=FChanges, nodefault};
	TgxSoundSample* __fastcall Sample();
	__property unsigned ManagerTag = {read=FTag, write=FTag, nodefault};
	__property Gxs::Scene::TgxBaseSceneObject* Origin = {read=FOrigin, write=SetOrigin};
	
__published:
	__property TgxSoundLibrary* SoundLibrary = {read=GetSoundLibrary, write=SetSoundLibrary};
	__property System::UnicodeString SoundName = {read=FSoundName, write=SetSoundName};
	__property float Volume = {read=FVolume, write=SetVolume};
	__property int NbLoops = {read=FNbLoops, write=SetNbLoops, default=1};
	__property bool Mute = {read=FMute, write=SetMute, default=0};
	__property bool Pause = {read=FPause, write=SetPause, default=0};
	__property int Priority = {read=FPriority, write=SetPriority, default=0};
	__property float MinDistance = {read=FMinDistance, write=SetMinDistance};
	__property float MaxDistance = {read=FMaxDistance, write=SetMaxDistance};
	__property float InsideConeAngle = {read=FInsideConeAngle, write=SetInsideConeAngle};
	__property float OutsideConeAngle = {read=FOutsideConeAngle, write=SetOutsideConeAngle};
	__property float ConeOutsideVolume = {read=FConeOutsideVolume, write=SetConeOutsideVolume};
	__property int Frequency = {read=FFrequency, write=SetFrequency, default=-1};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundSource : public TgxBaseSoundSource
{
	typedef TgxBaseSoundSource inherited;
	
public:
	__fastcall virtual ~TgxSoundSource();
	
__published:
	__property Origin;
public:
	/* TgxBaseSoundSource.Create */ inline __fastcall virtual TgxSoundSource(System::Classes::TCollection* Collection) : TgxBaseSoundSource(Collection) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxSoundSources : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxSoundSource* operator[](int index) { return this->Items[index]; }
	
protected:
	System::Classes::TComponent* owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxSoundSource* const val);
	TgxSoundSource* __fastcall GetItems(int index);
	HIDESBASE TgxSoundSource* __fastcall Add();
	HIDESBASE TgxSoundSource* __fastcall FindItemID(int ID);
	
public:
	__fastcall TgxSoundSources(System::Classes::TComponent* AOwner);
	__property TgxSoundSource* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxSoundSources() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TgxSoundEnvironment : unsigned char { seDefault, sePaddedCell, seRoom, seBathroom, seLivingRoom, seStoneroom, seAuditorium, seConcertHall, seCave, seArena, seHangar, seCarpetedHallway, seHallway, seStoneCorridor, seAlley, seForest, seCity, seMountains, seQuarry, sePlain, seParkingLot, seSewerPipe, seUnderWater, seDrugged, seDizzy, sePsychotic };

class PASCALIMPLEMENTATION TgxSoundManager : public Gxs::Baseclasses::TgxCadenceAbleComponent
{
	typedef Gxs::Baseclasses::TgxCadenceAbleComponent inherited;
	
private:
	bool FActive;
	bool FMute;
	bool FPause;
	float FMasterVolume;
	Gxs::Scene::TgxBaseSceneObject* FListener;
	Stage::Vectortypes::TVector4f FLastListenerPosition;
	TgxSoundSources* FSources;
	int FMaxChannels;
	int FOutputFrequency;
	float FUpdateFrequency;
	float FDistanceFactor;
	float FRollOffFactor;
	float FDopplerFactor;
	TgxSoundEnvironment FSoundEnvironment;
	float FLastUpdateTime;
	float FLastDeltaTime;
	Gxs::Cadencer::TgxCadencer* FCadencer;
	void __fastcall SetActive(const bool val);
	void __fastcall SetMute(const bool val);
	void __fastcall SetPause(const bool val);
	void __fastcall WriteDoppler(System::Classes::TWriter* writer);
	void __fastcall ReadDoppler(System::Classes::TReader* reader);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetSources(TgxSoundSources* const val);
	void __fastcall SetMasterVolume(const float val);
	void __fastcall SetListener(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetMaxChannels(const int val);
	void __fastcall SetOutputFrequency(const int val);
	void __fastcall SetUpdateFrequency(const float val);
	bool __fastcall StoreUpdateFrequency();
	void __fastcall SetCadencer(Gxs::Cadencer::TgxCadencer* const val);
	void __fastcall SetDistanceFactor(const float val);
	bool __fastcall StoreDistanceFactor();
	void __fastcall SetRollOffFactor(const float val);
	bool __fastcall StoreRollOffFactor();
	void __fastcall SetDopplerFactor(const float val);
	void __fastcall SetSoundEnvironment(const TgxSoundEnvironment val);
	virtual void __fastcall Loaded();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ListenerCoordinates(Stage::Vectortypes::TVector4f &position, Stage::Vectortypes::TVector4f &velocity, Stage::Vectortypes::TVector4f &direction, Stage::Vectortypes::TVector4f &up);
	virtual bool __fastcall DoActivate();
	virtual void __fastcall DoDeActivate();
	virtual bool __fastcall DoMute();
	virtual void __fastcall DoUnMute();
	virtual bool __fastcall DoPause();
	virtual void __fastcall DoUnPause();
	virtual void __fastcall NotifyMasterVolumeChange();
	virtual void __fastcall Notify3DFactorsChanged();
	virtual void __fastcall NotifyEnvironmentChanged();
	virtual void __fastcall KillSource(TgxBaseSoundSource* aSource);
	virtual void __fastcall UpdateSource(TgxBaseSoundSource* aSource);
	virtual void __fastcall MuteSource(TgxBaseSoundSource* aSource, bool muted);
	virtual void __fastcall PauseSource(TgxBaseSoundSource* aSource, bool paused);
	
public:
	__fastcall virtual TgxSoundManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSoundManager();
	virtual void __fastcall UpdateSources();
	void __fastcall StopAllSources();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual float __fastcall CPUUsagePercent();
	virtual bool __fastcall EAXSupported();
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property int MaxChannels = {read=FMaxChannels, write=SetMaxChannels, default=8};
	__property int OutputFrequency = {read=FOutputFrequency, write=SetOutputFrequency, default=44100};
	__property bool Mute = {read=FMute, write=SetMute, default=0};
	__property bool Pause = {read=FPause, write=SetPause, default=0};
	__property float MasterVolume = {read=FMasterVolume, write=SetMasterVolume};
	__property Gxs::Scene::TgxBaseSceneObject* Listener = {read=FListener, write=SetListener};
	__property TgxSoundSources* Sources = {read=FSources, write=SetSources};
	__property float UpdateFrequency = {read=FUpdateFrequency, write=SetUpdateFrequency, stored=StoreUpdateFrequency};
	__property Gxs::Cadencer::TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	__property float DistanceFactor = {read=FDistanceFactor, write=SetDistanceFactor, stored=StoreDistanceFactor};
	__property float RollOffFactor = {read=FRollOffFactor, write=SetRollOffFactor, stored=StoreRollOffFactor};
	__property float DopplerFactor = {read=FDopplerFactor, write=SetDopplerFactor, stored=false};
	__property TgxSoundEnvironment Environment = {read=FSoundEnvironment, write=SetSoundEnvironment, default=0};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBSoundEmitter : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	bool FPlaying;
	TgxBaseSoundSource* FSource;
	TgxSoundSource* FPlayingSource;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetSource(TgxBaseSoundSource* const val);
	void __fastcall SetPlaying(const bool val);
	bool __fastcall GetPlaying();
	void __fastcall NotifySourceDestruction(TgxSoundSource* aSource);
	
public:
	__fastcall virtual TgxBSoundEmitter(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBSoundEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__property TgxSoundSource* PlayingSource = {read=FPlayingSource};
	
__published:
	__property TgxBaseSoundSource* Source = {read=FSource, write=SetSource};
	__property bool Playing = {read=GetPlaying, write=SetPlaying, default=0};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vVerboseGLSMErrors;
extern DELPHI_PACKAGE TgxSoundManager* __fastcall ActiveSoundManager(void);
extern DELPHI_PACKAGE TgxSoundLibrary* __fastcall GetSoundLibraryByName(const System::UnicodeString aName);
extern DELPHI_PACKAGE TgxBSoundEmitter* __fastcall GetOrCreateSoundEmitter(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBSoundEmitter* __fastcall GetOrCreateSoundEmitter(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Soundmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SOUNDMANAGER)
using namespace Gxs::Soundmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SoundManagerHPP
