// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OpenAL.Import.pas' rev: 36.00 (Windows)

#ifndef OpenAL_ImportHPP
#define OpenAL_ImportHPP

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
#include <Winapi.Windows.hpp>

//-- user supplied -----------------------------------------------------------

namespace Openal
{
namespace Import
{
//-- forward type declarations -----------------------------------------------
struct TEaxListenerProperties;
struct TEaxBufferProperties;
struct _EFXEAXREVERBPROPERTIES;
struct _EFXLOWPASSFILTER;
//-- type declarations -------------------------------------------------------
typedef bool TALboolean;

typedef bool *PALboolean;

typedef System::WideChar TALchar;

typedef char * PALchar;

typedef System::Int8 TALbyte;

typedef System::Int8 *PALbyte;

typedef System::WideChar TALuByte;

typedef char * PALuByte;

typedef short TALshort;

typedef short *PALshort;

typedef System::Word TALushort;

typedef System::Word *PALushort;

typedef unsigned TALuint;

typedef unsigned *PALuint;

typedef int TALint;

typedef int *PALint;

typedef float TALfloat;

typedef float *PALfloat;

typedef double TALdouble;

typedef double *PALdouble;

typedef unsigned TALsizei;

typedef unsigned *PALsizei;

typedef void * TALvoid;

typedef void * *PALvoid;

typedef PALvoid *PPALvoid;

typedef int TALenum;

typedef int *PALenum;

typedef unsigned TALbitfield;

typedef unsigned *PALbitfield;

typedef TALfloat TALclampf;

typedef float *PALclampf;

typedef TALdouble TALclampd;

typedef double *PALclampd;

typedef int TALCenum;

typedef int *PALCenum;

typedef bool TALCboolean;

typedef bool *PALCboolean;

typedef System::WideChar TALCchar;

typedef char * PALCchar;

typedef System::Int8 TALCbyte;

typedef System::Int8 *PALCbyte;

typedef System::WideChar TALCubyte;

typedef char * PALCubyte;

typedef short TALCshort;

typedef short *PALCshort;

typedef System::Word TALCushort;

typedef System::Word *PALCushort;

typedef unsigned TALCuint;

typedef unsigned *PALCuint;

typedef int TALCint;

typedef int *PALCint;

typedef float TALCfloat;

typedef float *PALCfloat;

typedef double TALCdouble;

typedef double *PALCdouble;

typedef int TALCsizei;

typedef int *PALCsizei;

typedef void * TALCvoid;

typedef void * *PALCvoid;

typedef TALCvoid TALCdevice;

typedef void * *PALCdevice;

typedef TALCvoid TALCcontext;

typedef void * *PALCcontext;

typedef System::LongWord DSPROPERTY_EAX_LISTENERPROPERTY;

typedef System::LongWord DSPROPERTY_EAX_BUFFERPROPERTY;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TEaxListenerProperties
{
public:
	int lRoom;
	int lRoomHF;
	double flRoomRolloffFactor;
	double flDecayTime;
	double flDecayHFRatio;
	int lReflections;
	double flReflectionsDelay;
	int lReverb;
	double flReverbDelay;
	unsigned dwEnvironment;
	double flEnvironmentSize;
	double flEnvironmentDiffusion;
	double flAirAbsorptionHF;
	unsigned dwFlags;
};
#pragma pack(pop)


typedef TEaxListenerProperties *PEaxListenerProperties;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TEaxBufferProperties
{
public:
	int lDirect;
	int lDirectHF;
	int lRoom;
	int lRoomHF;
	double flRoomRolloffFactor;
	int lObstruction;
	double flObstructionLFRatio;
	int lOcclusion;
	double flOcclusionLFRatio;
	double flOcclusionRoomRatio;
	int lOutsideVolumeHF;
	double flAirAbsorptionFactor;
	unsigned dwFlags;
};
#pragma pack(pop)


typedef TEaxBufferProperties *PEaxBufferProperties;

#pragma pack(push,1)
struct DECLSPEC_DRECORD _EFXEAXREVERBPROPERTIES
{
public:
	float flDensity;
	float flDiffusion;
	float flGain;
	float flGainHF;
	float flGainLF;
	float flDecayTime;
	float flDecayHFRatio;
	float flDecayLFRatio;
	float flReflectionsGain;
	float flReflectionsDelay;
	System::StaticArray<float, 3> flReflectionsPan;
	float flLateReverbGain;
	float flLateReverbDelay;
	System::StaticArray<float, 3> flLateReverbPan;
	float flEchoTime;
	float flEchoDepth;
	float flModulationTime;
	float flModulationDepth;
	float flAirAbsorptionGainHF;
	float flHFReference;
	float flLFReference;
	float flRoomRolloffFactor;
	int iDecayHFLimit;
};
#pragma pack(pop)


typedef _EFXEAXREVERBPROPERTIES EFXEAXREVERBPROPERTIES;

typedef _EFXEAXREVERBPROPERTIES *PEFXEAXREVERBPROPERTIES;

#pragma pack(push,1)
struct DECLSPEC_DRECORD _EFXLOWPASSFILTER
{
public:
	float flGain;
	float flGainHF;
};
#pragma pack(pop)


typedef _EFXLOWPASSFILTER EFXLOWPASSFILTER;

typedef _EFXLOWPASSFILTER *PEFXLOWPASSFILTER;

typedef Winapi::Windows::THandle HMODULE;

//-- var, const, procedure ---------------------------------------------------
#define callibname L"OpenAL32.dll"
#define calutlibname L"Alut.dll"
static _DELPHI_CONST System::Int8 AL_INVALID = System::Int8(-1);
static _DELPHI_CONST System::Int8 AL_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FALSE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_TRUE = System::Int8(0x1);
static _DELPHI_CONST System::Word AL_SOURCE_ABSOLUTE = System::Word(0x201);
static _DELPHI_CONST System::Word AL_SOURCE_RELATIVE = System::Word(0x202);
static _DELPHI_CONST System::Word AL_CONE_INNER_ANGLE = System::Word(0x1001);
static _DELPHI_CONST System::Word AL_CONE_OUTER_ANGLE = System::Word(0x1002);
static _DELPHI_CONST System::Word AL_PITCH = System::Word(0x1003);
static _DELPHI_CONST System::Word AL_POSITION = System::Word(0x1004);
static _DELPHI_CONST System::Word AL_DIRECTION = System::Word(0x1005);
static _DELPHI_CONST System::Word AL_VELOCITY = System::Word(0x1006);
static _DELPHI_CONST System::Word AL_LOOPING = System::Word(0x1007);
static _DELPHI_CONST System::Word AL_BUFFER = System::Word(0x1009);
static _DELPHI_CONST System::Word AL_GAIN = System::Word(0x100a);
static _DELPHI_CONST System::Word AL_MIN_GAIN = System::Word(0x100d);
static _DELPHI_CONST System::Word AL_MAX_GAIN = System::Word(0x100e);
static _DELPHI_CONST System::Word AL_ORIENTATION = System::Word(0x100f);
static _DELPHI_CONST System::Word AL_CHANNEL_MASK = System::Word(0x3000);
static _DELPHI_CONST System::Word AL_SOURCE_STATE = System::Word(0x1010);
static _DELPHI_CONST System::Word AL_INITIAL = System::Word(0x1011);
static _DELPHI_CONST System::Word AL_PLAYING = System::Word(0x1012);
static _DELPHI_CONST System::Word AL_PAUSED = System::Word(0x1013);
static _DELPHI_CONST System::Word AL_STOPPED = System::Word(0x1014);
static _DELPHI_CONST System::Word AL_BUFFERS_QUEUED = System::Word(0x1015);
static _DELPHI_CONST System::Word AL_BUFFERS_PROCESSED = System::Word(0x1016);
static _DELPHI_CONST System::Word AL_SEC_OFFSET = System::Word(0x1024);
static _DELPHI_CONST System::Word AL_SAMPLE_OFFSET = System::Word(0x1025);
static _DELPHI_CONST System::Word AL_BYTE_OFFSET = System::Word(0x1026);
static _DELPHI_CONST System::Word AL_SOURCE_TYPE = System::Word(0x1027);
static _DELPHI_CONST System::Word AL_STATIC = System::Word(0x1028);
static _DELPHI_CONST System::Word AL_STREAMING = System::Word(0x1029);
static _DELPHI_CONST System::Word AL_UNDETERMINED = System::Word(0x1030);
static _DELPHI_CONST System::Word AL_FORMAT_MONO8 = System::Word(0x1100);
static _DELPHI_CONST System::Word AL_FORMAT_MONO16 = System::Word(0x1101);
static _DELPHI_CONST System::Word AL_FORMAT_STEREO8 = System::Word(0x1102);
static _DELPHI_CONST System::Word AL_FORMAT_STEREO16 = System::Word(0x1103);
static _DELPHI_CONST System::Word AL_REFERENCE_DISTANCE = System::Word(0x1020);
static _DELPHI_CONST System::Word AL_ROLLOFF_FACTOR = System::Word(0x1021);
static _DELPHI_CONST System::Word AL_CONE_OUTER_GAIN = System::Word(0x1022);
static _DELPHI_CONST System::Word AL_MAX_DISTANCE = System::Word(0x1023);
static _DELPHI_CONST System::Word AL_FREQUENCY = System::Word(0x2001);
static _DELPHI_CONST System::Word AL_BITS = System::Word(0x2002);
static _DELPHI_CONST System::Word AL_CHANNELS = System::Word(0x2003);
static _DELPHI_CONST System::Word AL_SIZE = System::Word(0x2004);
static _DELPHI_CONST System::Word AL_UNUSED = System::Word(0x2010);
static _DELPHI_CONST System::Word AL_PENDING = System::Word(0x2011);
static _DELPHI_CONST System::Word AL_PROCESSED = System::Word(0x2012);
static _DELPHI_CONST System::Int8 AL_NO_ERROR = System::Int8(0x0);
static _DELPHI_CONST System::Word AL_INVALID_NAME = System::Word(0xa001);
static _DELPHI_CONST System::Word AL_ILLEGAL_ENUM = System::Word(0xa002);
static _DELPHI_CONST System::Word AL_INVALID_ENUM = System::Word(0xa002);
static _DELPHI_CONST System::Word AL_INVALID_VALUE = System::Word(0xa003);
static _DELPHI_CONST System::Word AL_ILLEGAL_COMMAND = System::Word(0xa004);
static _DELPHI_CONST System::Word AL_INVALID_OPERATION = System::Word(0xa004);
static _DELPHI_CONST System::Word AL_OUT_OF_MEMORY = System::Word(0xa005);
static _DELPHI_CONST System::Word AL_VENDOR = System::Word(0xb001);
static _DELPHI_CONST System::Word AL_VERSION = System::Word(0xb002);
static _DELPHI_CONST System::Word AL_RENDERER = System::Word(0xb003);
static _DELPHI_CONST System::Word AL_EXTENSIONS = System::Word(0xb004);
static _DELPHI_CONST System::Word AL_DOPPLER_FACTOR = System::Word(0xc000);
static _DELPHI_CONST System::Word AL_DOPPLER_VELOCITY = System::Word(0xc001);
static _DELPHI_CONST System::Word AL_SPEED_OF_SOUND = System::Word(0xc003);
static _DELPHI_CONST System::Word AL_DISTANCE_MODEL = System::Word(0xd000);
static _DELPHI_CONST System::Word AL_INVERSE_DISTANCE = System::Word(0xd001);
static _DELPHI_CONST System::Word AL_INVERSE_DISTANCE_CLAMPED = System::Word(0xd002);
static _DELPHI_CONST System::Word AL_LINEAR_DISTANCE = System::Word(0xd003);
static _DELPHI_CONST System::Word AL_LINEAR_DISTANCE_CLAMPED = System::Word(0xd004);
static _DELPHI_CONST System::Word AL_EXPONENT_DISTANCE = System::Word(0xd005);
static _DELPHI_CONST System::Word AL_EXPONENT_DISTANCE_CLAMPED = System::Word(0xd006);
static _DELPHI_CONST System::Int8 ALC_INVALID = System::Int8(0x0);
static _DELPHI_CONST System::Int8 ALC_FALSE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 ALC_TRUE = System::Int8(0x1);
static _DELPHI_CONST System::Word ALC_FREQUENCY = System::Word(0x1007);
static _DELPHI_CONST System::Word ALC_REFRESH = System::Word(0x1008);
static _DELPHI_CONST System::Word ALC_SYNC = System::Word(0x1009);
static _DELPHI_CONST System::Word ALC_MONO_SOURCES = System::Word(0x1010);
static _DELPHI_CONST System::Word ALC_STEREO_SOURCES = System::Word(0x1011);
static _DELPHI_CONST System::Int8 ALC_NO_ERROR = System::Int8(0x0);
static _DELPHI_CONST System::Word ALC_INVALID_DEVICE = System::Word(0xa001);
static _DELPHI_CONST System::Word ALC_INVALID_CONTEXT = System::Word(0xa002);
static _DELPHI_CONST System::Word ALC_INVALID_ENUM = System::Word(0xa003);
static _DELPHI_CONST System::Word ALC_INVALID_VALUE = System::Word(0xa004);
static _DELPHI_CONST System::Word ALC_OUT_OF_MEMORY = System::Word(0xa005);
static _DELPHI_CONST System::Word ALC_DEFAULT_DEVICE_SPECIFIER = System::Word(0x1004);
static _DELPHI_CONST System::Word ALC_DEVICE_SPECIFIER = System::Word(0x1005);
static _DELPHI_CONST System::Word ALC_EXTENSIONS = System::Word(0x1006);
static _DELPHI_CONST System::Word ALC_MAJOR_VERSION = System::Word(0x1000);
static _DELPHI_CONST System::Word ALC_MINOR_VERSION = System::Word(0x1001);
static _DELPHI_CONST System::Word ALC_ATTRIBUTES_SIZE = System::Word(0x1002);
static _DELPHI_CONST System::Word ALC_ALL_ATTRIBUTES = System::Word(0x1003);
static _DELPHI_CONST System::Word ALC_DEFAULT_ALL_DEVICES_SPECIFIER = System::Word(0x1012);
static _DELPHI_CONST System::Word ALC_ALL_DEVICES_SPECIFIER = System::Word(0x1013);
static _DELPHI_CONST System::Word ALC_CAPTURE_DEVICE_SPECIFIER = System::Word(0x310);
static _DELPHI_CONST System::Word ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER = System::Word(0x311);
static _DELPHI_CONST System::Word ALC_CAPTURE_SAMPLES = System::Word(0x312);
#define ALC_EXT_EFX_NAME L"ALC_EXT_EFX"
static _DELPHI_CONST int ALC_EFX_MAJOR_VERSION = int(0x20001);
static _DELPHI_CONST int ALC_EFX_MINOR_VERSION = int(0x20002);
static _DELPHI_CONST int ALC_MAX_AUXILIARY_SENDS = int(0x20003);
static _DELPHI_CONST int AL_METERS_PER_UNIT = int(0x20004);
static _DELPHI_CONST int AL_DIRECT_FILTER = int(0x20005);
static _DELPHI_CONST int AL_AUXILIARY_SEND_FILTER = int(0x20006);
static _DELPHI_CONST int AL_AIR_ABSORPTION_FACTOR = int(0x20007);
static _DELPHI_CONST int AL_ROOM_ROLLOFF_FACTOR = int(0x20008);
static _DELPHI_CONST int AL_CONE_OUTER_GAINHF = int(0x20009);
static _DELPHI_CONST int AL_DIRECT_FILTER_GAINHF_AUTO = int(0x2000a);
static _DELPHI_CONST int AL_AUXILIARY_SEND_FILTER_GAIN_AUTO = int(0x2000b);
static _DELPHI_CONST int AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO = int(0x2000c);
static _DELPHI_CONST System::Int8 AL_REVERB_DENSITY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_REVERB_DIFFUSION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_REVERB_GAIN = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_REVERB_GAINHF = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_REVERB_DECAY_TIME = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_REVERB_DECAY_HFRATIO = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_REVERB_REFLECTIONS_GAIN = System::Int8(0x7);
static _DELPHI_CONST System::Int8 AL_REVERB_REFLECTIONS_DELAY = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AL_REVERB_LATE_REVERB_GAIN = System::Int8(0x9);
static _DELPHI_CONST System::Int8 AL_REVERB_LATE_REVERB_DELAY = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_REVERB_AIR_ABSORPTION_GAINHF = System::Int8(0xb);
static _DELPHI_CONST System::Int8 AL_REVERB_ROOM_ROLLOFF_FACTOR = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_REVERB_DECAY_HFLIMIT = System::Int8(0xd);
static _DELPHI_CONST System::Int8 AL_CHORUS_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_CHORUS_PHASE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_CHORUS_RATE = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_CHORUS_DEPTH = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_CHORUS_FEEDBACK = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_CHORUS_DELAY = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_DISTORTION_EDGE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_DISTORTION_GAIN = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_DISTORTION_LOWPASS_CUTOFF = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_DISTORTION_EQCENTER = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_DISTORTION_EQBANDWIDTH = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_ECHO_DELAY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_ECHO_LRDELAY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_ECHO_DAMPING = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_ECHO_FEEDBACK = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_ECHO_SPREAD = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_FLANGER_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FLANGER_PHASE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_FLANGER_RATE = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_FLANGER_DEPTH = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_FLANGER_FEEDBACK = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_FLANGER_DELAY = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_FREQUENCY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_LEFT_DIRECTION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_RIGHT_DIRECTION = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEMEA = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEMEA_COARSE_TUNING = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEMEB = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEMEB_COARSE_TUNING = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_WAVEFORM = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_RATE = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_COARSE_TUNE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_FINE_TUNE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_FREQUENCY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_HIGHPASS_CUTOFF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_WAVEFORM = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_AUTOWAH_ATTACK_TIME = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_AUTOWAH_RELEASE_TIME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_AUTOWAH_RESONANCE = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_AUTOWAH_PEAK_GAIN = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_COMPRESSOR_ONOFF = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_LOW_GAIN = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_LOW_CUTOFF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID1_GAIN = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID1_CENTER = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID1_WIDTH = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID2_GAIN = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID2_CENTER = System::Int8(0x7);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_MID2_WIDTH = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_HIGH_GAIN = System::Int8(0x9);
static _DELPHI_CONST System::Int8 AL_EQUALIZER_HIGH_CUTOFF = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_EFFECT_FIRST_PARAMETER = System::Int8(0x0);
static _DELPHI_CONST System::Word AL_EFFECT_LAST_PARAMETER = System::Word(0x8000);
static _DELPHI_CONST System::Word AL_EFFECT_TYPE = System::Word(0x8001);
static _DELPHI_CONST System::Int8 AL_EFFECT_NULL = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_EFFECT_REVERB = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EFFECT_CHORUS = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_EFFECT_DISTORTION = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_EFFECT_ECHO = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_EFFECT_FLANGER = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_EFFECT_FREQUENCY_SHIFTER = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_EFFECT_VOCAL_MORPHER = System::Int8(0x7);
static _DELPHI_CONST System::Int8 AL_EFFECT_PITCH_SHIFTER = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AL_EFFECT_RING_MODULATOR = System::Int8(0x9);
static _DELPHI_CONST System::Int8 AL_EFFECT_AUTOWAH = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_EFFECT_COMPRESSOR = System::Int8(0xb);
static _DELPHI_CONST System::Int8 AL_EFFECT_EQUALIZER = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_EFFECTSLOT_EFFECT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EFFECTSLOT_GAIN = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_EFFECTSLOT_AUXILIARY_SEND_AUTO = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_EFFECTSLOT_NULL = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_LOWPASS_GAIN = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_LOWPASS_GAINHF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_HIGHPASS_GAIN = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_HIGHPASS_GAINLF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_BANDPASS_GAIN = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_BANDPASS_GAINLF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_BANDPASS_GAINHF = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_FILTER_FIRST_PARAMETER = System::Int8(0x0);
static _DELPHI_CONST System::Word AL_FILTER_LAST_PARAMETER = System::Word(0x8000);
static _DELPHI_CONST System::Word AL_FILTER_TYPE = System::Word(0x8001);
static _DELPHI_CONST System::Int8 AL_FILTER_NULL = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FILTER_LOWPASS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FILTER_HIGHPASS = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_FILTER_BANDPASS = System::Int8(0x3);
#define LOWPASS_MIN_GAIN  (0.000000E+00)
#define LOWPASS_MAX_GAIN  (1.000000E+00)
#define LOWPASS_DEFAULT_GAIN  (1.000000E+00)
#define LOWPASS_MIN_GAINHF  (0.000000E+00)
#define LOWPASS_MAX_GAINHF  (1.000000E+00)
#define LOWPASS_DEFAULT_GAINHF  (1.000000E+00)
#define HIGHPASS_MIN_GAIN  (0.000000E+00)
#define HIGHPASS_MAX_GAIN  (1.000000E+00)
#define HIGHPASS_DEFAULT_GAIN  (1.000000E+00)
#define HIGHPASS_MIN_GAINLF  (0.000000E+00)
#define HIGHPASS_MAX_GAINLF  (1.000000E+00)
#define HIGHPASS_DEFAULT_GAINLF  (1.000000E+00)
#define BANDPASS_MIN_GAIN  (0.000000E+00)
#define BANDPASS_MAX_GAIN  (1.000000E+00)
#define BANDPASS_DEFAULT_GAIN  (1.000000E+00)
#define BANDPASS_MIN_GAINHF  (0.000000E+00)
#define BANDPASS_MAX_GAINHF  (1.000000E+00)
#define BANDPASS_DEFAULT_GAINHF  (1.000000E+00)
#define BANDPASS_MIN_GAINLF  (0.000000E+00)
#define BANDPASS_MAX_GAINLF  (1.000000E+00)
#define BANDPASS_DEFAULT_GAINLF  (1.000000E+00)
#define AL_REVERB_MIN_DENSITY  (0.000000E+00)
#define AL_REVERB_MAX_DENSITY  (1.000000E+00)
#define AL_REVERB_DEFAULT_DENSITY  (1.000000E+00)
#define AL_REVERB_MIN_DIFFUSION  (0.000000E+00)
#define AL_REVERB_MAX_DIFFUSION  (1.000000E+00)
#define AL_REVERB_DEFAULT_DIFFUSION  (1.000000E+00)
#define AL_REVERB_MIN_GAIN  (0.000000E+00)
#define AL_REVERB_MAX_GAIN  (1.000000E+00)
#define AL_REVERB_DEFAULT_GAIN  (3.200000E-01)
#define AL_REVERB_MIN_GAINHF  (0.000000E+00)
#define AL_REVERB_MAX_GAINHF  (1.000000E+00)
#define AL_REVERB_DEFAULT_GAINHF  (8.900000E-01)
#define AL_REVERB_MIN_DECAY_TIME  (1.000000E-01)
#define AL_REVERB_MAX_DECAY_TIME  (2.000000E+01)
#define AL_REVERB_DEFAULT_DECAY_TIME  (1.490000E+00)
#define AL_REVERB_MIN_DECAY_HFRATIO  (1.000000E-01)
#define AL_REVERB_MAX_DECAY_HFRATIO  (2.000000E+00)
#define AL_REVERB_DEFAULT_DECAY_HFRATIO  (8.300000E-01)
#define AL_REVERB_MIN_REFLECTIONS_GAIN  (0.000000E+00)
#define AL_REVERB_MAX_REFLECTIONS_GAIN  (3.160000E+00)
#define AL_REVERB_DEFAULT_REFLECTIONS_GAIN  (5.000000E-02)
#define AL_REVERB_MIN_REFLECTIONS_DELAY  (0.000000E+00)
#define AL_REVERB_MAX_REFLECTIONS_DELAY  (3.000000E-01)
#define AL_REVERB_DEFAULT_REFLECTIONS_DELAY  (7.000000E-03)
#define AL_REVERB_MIN_LATE_REVERB_GAIN  (0.000000E+00)
#define AL_REVERB_MAX_LATE_REVERB_GAIN  (1.000000E+01)
#define AL_REVERB_DEFAULT_LATE_REVERB_GAIN  (1.260000E+00)
#define AL_REVERB_MIN_LATE_REVERB_DELAY  (0.000000E+00)
#define AL_REVERB_MAX_LATE_REVERB_DELAY  (1.000000E-01)
#define AL_REVERB_DEFAULT_LATE_REVERB_DELAY  (1.100000E-02)
#define AL_REVERB_MIN_AIR_ABSORPTION_GAINHF  (8.920000E-01)
#define AL_REVERB_MAX_AIR_ABSORPTION_GAINHF  (1.000000E+00)
#define AL_REVERB_DEFAULT_AIR_ABSORPTION_GAINHF  (9.940000E-01)
#define AL_REVERB_MIN_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
#define AL_REVERB_MAX_ROOM_ROLLOFF_FACTOR  (1.000000E+01)
#define AL_REVERB_DEFAULT_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
static _DELPHI_CONST System::Int8 AL_REVERB_MIN_DECAY_HFLIMIT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_REVERB_MAX_DECAY_HFLIMIT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_REVERB_DEFAULT_DECAY_HFLIMIT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_CHORUS_MIN_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_CHORUS_MAX_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_CHORUS_DEFAULT_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_CHORUS_WAVEFORM_SINUSOID = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_CHORUS_WAVEFORM_TRIANGLE = System::Int8(0x1);
static _DELPHI_CONST short AL_CHORUS_MIN_PHASE = short(-180);
static _DELPHI_CONST System::Byte AL_CHORUS_MAX_PHASE = System::Byte(0xb4);
static _DELPHI_CONST System::Int8 AL_CHORUS_DEFAULT_PHASE = System::Int8(0x5a);
#define AL_CHORUS_MIN_RATE  (0.000000E+00)
#define AL_CHORUS_MAX_RATE  (1.000000E+01)
#define AL_CHORUS_DEFAULT_RATE  (1.100000E+00)
#define AL_CHORUS_MIN_DEPTH  (0.000000E+00)
#define AL_CHORUS_MAX_DEPTH  (1.000000E+00)
#define AL_CHORUS_DEFAULT_DEPTH  (1.000000E-01)
#define AL_CHORUS_MIN_FEEDBACK  (-1.000000E+00)
#define AL_CHORUS_MAX_FEEDBACK  (1.000000E+00)
#define AL_CHORUS_DEFAULT_FEEDBACK  (2.500000E-01)
#define AL_CHORUS_MIN_DELAY  (0.000000E+00)
#define AL_CHORUS_MAX_DELAY  (1.600000E-02)
#define AL_CHORUS_DEFAULT_DELAY  (1.600000E-02)
#define AL_DISTORTION_MIN_EDGE  (0.000000E+00)
#define AL_DISTORTION_MAX_EDGE  (1.000000E+00)
#define AL_DISTORTION_DEFAULT_EDGE  (2.000000E-01)
#define AL_DISTORTION_MIN_GAIN  (1.000000E-02)
#define AL_DISTORTION_MAX_GAIN  (1.000000E+00)
#define AL_DISTORTION_DEFAULT_GAIN  (5.000000E-02)
#define AL_DISTORTION_MIN_LOWPASS_CUTOFF  (8.000000E+01)
#define AL_DISTORTION_MAX_LOWPASS_CUTOFF  (2.400000E+04)
#define AL_DISTORTION_DEFAULT_LOWPASS_CUTOFF  (8.000000E+03)
#define AL_DISTORTION_MIN_EQCENTER  (8.000000E+01)
#define AL_DISTORTION_MAX_EQCENTER  (2.400000E+04)
#define AL_DISTORTION_DEFAULT_EQCENTER  (3.600000E+03)
#define AL_DISTORTION_MIN_EQBANDWIDTH  (8.000000E+01)
#define AL_DISTORTION_MAX_EQBANDWIDTH  (2.400000E+04)
#define AL_DISTORTION_DEFAULT_EQBANDWIDTH  (3.600000E+03)
#define AL_ECHO_MIN_DELAY  (0.000000E+00)
#define AL_ECHO_MAX_DELAY  (2.070000E-01)
#define AL_ECHO_DEFAULT_DELAY  (1.000000E-01)
#define AL_ECHO_MIN_LRDELAY  (0.000000E+00)
#define AL_ECHO_MAX_LRDELAY  (4.040000E-01)
#define AL_ECHO_DEFAULT_LRDELAY  (1.000000E-01)
#define AL_ECHO_MIN_DAMPING  (0.000000E+00)
#define AL_ECHO_MAX_DAMPING  (9.900000E-01)
#define AL_ECHO_DEFAULT_DAMPING  (5.000000E-01)
#define AL_ECHO_MIN_FEEDBACK  (0.000000E+00)
#define AL_ECHO_MAX_FEEDBACK  (1.000000E+00)
#define AL_ECHO_DEFAULT_FEEDBACK  (5.000000E-01)
#define AL_ECHO_MIN_SPREAD  (-1.000000E+00)
#define AL_ECHO_MAX_SPREAD  (1.000000E+00)
#define AL_ECHO_DEFAULT_SPREAD  (-1.000000E+00)
static _DELPHI_CONST System::Int8 AL_FLANGER_MIN_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FLANGER_MAX_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FLANGER_DEFAULT_WAVEFORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FLANGER_WAVEFORM_SINUSOID = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FLANGER_WAVEFORM_TRIANGLE = System::Int8(0x1);
static _DELPHI_CONST short AL_FLANGER_MIN_PHASE = short(-180);
static _DELPHI_CONST System::Byte AL_FLANGER_MAX_PHASE = System::Byte(0xb4);
static _DELPHI_CONST System::Int8 AL_FLANGER_DEFAULT_PHASE = System::Int8(0x0);
#define AL_FLANGER_MIN_RATE  (0.000000E+00)
#define AL_FLANGER_MAX_RATE  (1.000000E+01)
#define AL_FLANGER_DEFAULT_RATE  (2.700000E-01)
#define AL_FLANGER_MIN_DEPTH  (0.000000E+00)
#define AL_FLANGER_MAX_DEPTH  (1.000000E+00)
#define AL_FLANGER_DEFAULT_DEPTH  (1.000000E+00)
#define AL_FLANGER_MIN_FEEDBACK  (-1.000000E+00)
#define AL_FLANGER_MAX_FEEDBACK  (1.000000E+00)
#define AL_FLANGER_DEFAULT_FEEDBACK  (-5.000000E-01)
#define AL_FLANGER_MIN_DELAY  (0.000000E+00)
#define AL_FLANGER_MAX_DELAY  (4.000000E-03)
#define AL_FLANGER_DEFAULT_DELAY  (2.000000E-03)
#define AL_FREQUENCY_SHIFTER_MIN_FREQUENCY  (0.000000E+00)
#define AL_FREQUENCY_SHIFTER_MAX_FREQUENCY  (2.400000E+04)
#define AL_FREQUENCY_SHIFTER_DEFAULT_FREQUENCY  (0.000000E+00)
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_MIN_LEFT_DIRECTION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_MAX_LEFT_DIRECTION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_DEFAULT_LEFT_DIRECTION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_MIN_RIGHT_DIRECTION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_MAX_RIGHT_DIRECTION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_DEFAULT_RIGHT_DIRECTION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_DIRECTION_DOWN = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_DIRECTION_UP = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_FREQUENCY_SHIFTER_DIRECTION_OFF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MIN_PHONEMEA = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MAX_PHONEMEA = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_DEFAULT_PHONEMEA = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MIN_PHONEMEA_COARSE_TUNING = System::Int8(-24);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MAX_PHONEMEA_COARSE_TUNING = System::Int8(0x18);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_DEFAULT_PHONEMEA_COARSE_TUNING = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MIN_PHONEMEB = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MAX_PHONEMEB = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_DEFAULT_PHONEMEB = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_A = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_E = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_I = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_O = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_U = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_AA = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_AE = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_AH = System::Int8(0x7);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_AO = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_EH = System::Int8(0x9);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_ER = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_IH = System::Int8(0xb);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_IY = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_UH = System::Int8(0xd);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_UW = System::Int8(0xe);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_B = System::Int8(0xf);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_D = System::Int8(0x10);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_F = System::Int8(0x11);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_G = System::Int8(0x12);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_J = System::Int8(0x13);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_K = System::Int8(0x14);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_L = System::Int8(0x15);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_M = System::Int8(0x16);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_N = System::Int8(0x17);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_P = System::Int8(0x18);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_R = System::Int8(0x19);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_S = System::Int8(0x1a);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_T = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_V = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_PHONEME_Z = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MIN_PHONEMEB_COARSE_TUNING = System::Int8(-24);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MAX_PHONEMEB_COARSE_TUNING = System::Int8(0x18);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_DEFAULT_PHONEMEB_COARSE_TUNING = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MIN_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_MAX_WAVEFORM = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_DEFAULT_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_WAVEFORM_SINUSOID = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_WAVEFORM_TRIANGLE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_VOCAL_MORPHER_WAVEFORM_SAWTOOTH = System::Int8(0x2);
#define AL_VOCAL_MORPHER_MIN_RATE  (0.000000E+00)
#define AL_VOCAL_MORPHER_MAX_RATE  (1.000000E+01)
#define AL_VOCAL_MORPHER_DEFAULT_RATE  (1.410000E+00)
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_MIN_COARSE_TUNE = System::Int8(-12);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_MAX_COARSE_TUNE = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_DEFAULT_COARSE_TUNE = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_MIN_FINE_TUNE = System::Int8(-50);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_MAX_FINE_TUNE = System::Int8(0x32);
static _DELPHI_CONST System::Int8 AL_PITCH_SHIFTER_DEFAULT_FINE_TUNE = System::Int8(0x0);
#define AL_RING_MODULATOR_MIN_FREQUENCY  (0.000000E+00)
#define AL_RING_MODULATOR_MAX_FREQUENCY  (8.000000E+03)
#define AL_RING_MODULATOR_DEFAULT_FREQUENCY  (4.400000E+02)
#define AL_RING_MODULATOR_MIN_HIGHPASS_CUTOFF  (0.000000E+00)
#define AL_RING_MODULATOR_MAX_HIGHPASS_CUTOFF  (2.400000E+04)
#define AL_RING_MODULATOR_DEFAULT_HIGHPASS_CUTOFF  (8.000000E+02)
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_MIN_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_MAX_WAVEFORM = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_DEFAULT_WAVEFORM = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_SINUSOID = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_SAWTOOTH = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_RING_MODULATOR_SQUARE = System::Int8(0x2);
#define AL_AUTOWAH_MIN_ATTACK_TIME  (1.000000E-04)
#define AL_AUTOWAH_MAX_ATTACK_TIME  (1.000000E+00)
#define AL_AUTOWAH_DEFAULT_ATTACK_TIME  (6.000000E-02)
#define AL_AUTOWAH_MIN_RELEASE_TIME  (1.000000E-04)
#define AL_AUTOWAH_MAX_RELEASE_TIME  (1.000000E+00)
#define AL_AUTOWAH_DEFAULT_RELEASE_TIME  (6.000000E-02)
#define AL_AUTOWAH_MIN_RESONANCE  (2.000000E+00)
#define AL_AUTOWAH_MAX_RESONANCE  (1.000000E+03)
#define AL_AUTOWAH_DEFAULT_RESONANCE  (1.000000E+03)
static const System::Extended AL_AUTOWAH_MIN_PEAK_GAIN = 3.000000E-05;
#define AL_AUTOWAH_MAX_PEAK_GAIN  (3.162100E+04)
#define AL_AUTOWAH_DEFAULT_PEAK_GAIN  (1.122000E+01)
static _DELPHI_CONST System::Int8 AL_COMPRESSOR_MIN_ONOFF = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_COMPRESSOR_MAX_ONOFF = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_COMPRESSOR_DEFAULT_ONOFF = System::Int8(0x1);
#define AL_EQUALIZER_MIN_LOW_GAIN  (1.260000E-01)
#define AL_EQUALIZER_MAX_LOW_GAIN  (7.943000E+00)
#define AL_EQUALIZER_DEFAULT_LOW_GAIN  (1.000000E+00)
#define AL_EQUALIZER_MIN_LOW_CUTOFF  (5.000000E+01)
#define AL_EQUALIZER_MAX_LOW_CUTOFF  (8.000000E+02)
#define AL_EQUALIZER_DEFAULT_LOW_CUTOFF  (2.000000E+02)
#define AL_EQUALIZER_MIN_MID1_GAIN  (1.260000E-01)
#define AL_EQUALIZER_MAX_MID1_GAIN  (7.943000E+00)
#define AL_EQUALIZER_DEFAULT_MID1_GAIN  (1.000000E+00)
#define AL_EQUALIZER_MIN_MID1_CENTER  (2.000000E+02)
#define AL_EQUALIZER_MAX_MID1_CENTER  (3.000000E+03)
#define AL_EQUALIZER_DEFAULT_MID1_CENTER  (5.000000E+02)
#define AL_EQUALIZER_MIN_MID1_WIDTH  (1.000000E-02)
#define AL_EQUALIZER_MAX_MID1_WIDTH  (1.000000E+00)
#define AL_EQUALIZER_DEFAULT_MID1_WIDTH  (1.000000E+00)
#define AL_EQUALIZER_MIN_MID2_GAIN  (1.260000E-01)
#define AL_EQUALIZER_MAX_MID2_GAIN  (7.943000E+00)
#define AL_EQUALIZER_DEFAULT_MID2_GAIN  (1.000000E+00)
#define AL_EQUALIZER_MIN_MID2_CENTER  (1.000000E+03)
#define AL_EQUALIZER_MAX_MID2_CENTER  (8.000000E+03)
#define AL_EQUALIZER_DEFAULT_MID2_CENTER  (3.000000E+03)
#define AL_EQUALIZER_MIN_MID2_WIDTH  (1.000000E-02)
#define AL_EQUALIZER_MAX_MID2_WIDTH  (1.000000E+00)
#define AL_EQUALIZER_DEFAULT_MID2_WIDTH  (1.000000E+00)
#define AL_EQUALIZER_MIN_HIGH_GAIN  (1.260000E-01)
#define AL_EQUALIZER_MAX_HIGH_GAIN  (7.943000E+00)
#define AL_EQUALIZER_DEFAULT_HIGH_GAIN  (1.000000E+00)
#define AL_EQUALIZER_MIN_HIGH_CUTOFF  (4.000000E+03)
#define AL_EQUALIZER_MAX_HIGH_CUTOFF  (1.600000E+04)
#define AL_EQUALIZER_DEFAULT_HIGH_CUTOFF  (6.000000E+03)
#define AL_MIN_AIR_ABSORPTION_FACTOR  (0.000000E+00)
#define AL_MAX_AIR_ABSORPTION_FACTOR  (1.000000E+01)
#define AL_DEFAULT_AIR_ABSORPTION_FACTOR  (0.000000E+00)
#define AL_MIN_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
#define AL_MAX_ROOM_ROLLOFF_FACTOR  (1.000000E+01)
#define AL_DEFAULT_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
#define AL_MIN_CONE_OUTER_GAINHF  (0.000000E+00)
#define AL_MAX_CONE_OUTER_GAINHF  (1.000000E+00)
#define AL_DEFAULT_CONE_OUTER_GAINHF  (1.000000E+00)
static _DELPHI_CONST System::Int8 AL_MIN_DIRECT_FILTER_GAINHF_AUTO = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_MAX_DIRECT_FILTER_GAINHF_AUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_DEFAULT_DIRECT_FILTER_GAINHF_AUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_MIN_AUXILIARY_SEND_FILTER_GAIN_AUTO = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_MAX_AUXILIARY_SEND_FILTER_GAIN_AUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_DEFAULT_AUXILIARY_SEND_FILTER_GAIN_AUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_MIN_AUXILIARY_SEND_FILTER_GAINHF_AUTO = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_MAX_AUXILIARY_SEND_FILTER_GAINHF_AUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_DEFAULT_AUXILIARY_SEND_FILTER_GAINHF_AUTO = System::Int8(0x1);
#define AL_DEFAULT_METERS_PER_UNIT  (1.000000E+00)
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DENSITY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DIFFUSION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_GAIN = System::Int8(0x3);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_GAINHF = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_GAINLF = System::Int8(0x5);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DECAY_TIME = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DECAY_HFRATIO = System::Int8(0x7);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DECAY_LFRATIO = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_REFLECTIONS_GAIN = System::Int8(0x9);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_REFLECTIONS_DELAY = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_REFLECTIONS_PAN = System::Int8(0xb);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_LATE_REVERB_GAIN = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_LATE_REVERB_DELAY = System::Int8(0xd);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_LATE_REVERB_PAN = System::Int8(0xe);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_ECHO_TIME = System::Int8(0xf);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_ECHO_DEPTH = System::Int8(0x10);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_MODULATION_TIME = System::Int8(0x11);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_MODULATION_DEPTH = System::Int8(0x12);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_AIR_ABSORPTION_GAINHF = System::Int8(0x13);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_HFREFERENCE = System::Int8(0x14);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_LFREFERENCE = System::Int8(0x15);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_ROOM_ROLLOFF_FACTOR = System::Int8(0x16);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DECAY_HFLIMIT = System::Int8(0x17);
static _DELPHI_CONST System::Word AL_EFFECT_EAXREVERB = System::Word(0x8000);
#define AL_EAXREVERB_MIN_DENSITY  (0.000000E+00)
#define AL_EAXREVERB_MAX_DENSITY  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_DENSITY  (1.000000E+00)
#define AL_EAXREVERB_MIN_DIFFUSION  (0.000000E+00)
#define AL_EAXREVERB_MAX_DIFFUSION  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_DIFFUSION  (1.000000E+00)
#define AL_EAXREVERB_MIN_GAIN  (0.000000E+00)
#define AL_EAXREVERB_MAX_GAIN  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_GAIN  (3.200000E-01)
#define AL_EAXREVERB_MIN_GAINHF  (0.000000E+00)
#define AL_EAXREVERB_MAX_GAINHF  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_GAINHF  (8.900000E-01)
#define AL_EAXREVERB_MIN_GAINLF  (0.000000E+00)
#define AL_EAXREVERB_MAX_GAINLF  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_GAINLF  (1.000000E+00)
#define AL_EAXREVERB_MIN_DECAY_TIME  (1.000000E-01)
#define AL_EAXREVERB_MAX_DECAY_TIME  (2.000000E+01)
#define AL_EAXREVERB_DEFAULT_DECAY_TIME  (1.490000E+00)
#define AL_EAXREVERB_MIN_DECAY_HFRATIO  (1.000000E-01)
#define AL_EAXREVERB_MAX_DECAY_HFRATIO  (2.000000E+00)
#define AL_EAXREVERB_DEFAULT_DECAY_HFRATIO  (8.300000E-01)
#define AL_EAXREVERB_MIN_DECAY_LFRATIO  (1.000000E-01)
#define AL_EAXREVERB_MAX_DECAY_LFRATIO  (2.000000E+00)
#define AL_EAXREVERB_DEFAULT_DECAY_LFRATIO  (1.000000E+00)
#define AL_EAXREVERB_MIN_REFLECTIONS_GAIN  (0.000000E+00)
#define AL_EAXREVERB_MAX_REFLECTIONS_GAIN  (3.160000E+00)
#define AL_EAXREVERB_DEFAULT_REFLECTIONS_GAIN  (5.000000E-02)
#define AL_EAXREVERB_MIN_REFLECTIONS_DELAY  (0.000000E+00)
#define AL_EAXREVERB_MAX_REFLECTIONS_DELAY  (3.000000E-01)
#define AL_EAXREVERB_DEFAULT_REFLECTIONS_DELAY  (7.000000E-03)
extern DELPHI_PACKAGE System::StaticArray<float, 3> AL_EAXREVERB_DEFAULT_REFLECTIONS_PAN;
#define AL_EAXREVERB_MIN_LATE_REVERB_GAIN  (0.000000E+00)
#define AL_EAXREVERB_MAX_LATE_REVERB_GAIN  (1.000000E+01)
#define AL_EAXREVERB_DEFAULT_LATE_REVERB_GAIN  (1.260000E+00)
#define AL_EAXREVERB_MIN_LATE_REVERB_DELAY  (0.000000E+00)
#define AL_EAXREVERB_MAX_LATE_REVERB_DELAY  (1.000000E-01)
#define AL_EAXREVERB_DEFAULT_LATE_REVERB_DELAY  (1.100000E-02)
extern DELPHI_PACKAGE System::StaticArray<float, 3> AL_EAXREVERB_DEFAULT_LATE_REVERB_PAN;
#define AL_EAXREVERB_MIN_ECHO_TIME  (7.500000E-02)
#define AL_EAXREVERB_MAX_ECHO_TIME  (2.500000E-01)
#define AL_EAXREVERB_DEFAULT_ECHO_TIME  (2.500000E-01)
#define AL_EAXREVERB_MIN_ECHO_DEPTH  (0.000000E+00)
#define AL_EAXREVERB_MAX_ECHO_DEPTH  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_ECHO_DEPTH  (0.000000E+00)
#define AL_EAXREVERB_MIN_MODULATION_TIME  (4.000000E-02)
#define AL_EAXREVERB_MAX_MODULATION_TIME  (4.000000E+00)
#define AL_EAXREVERB_DEFAULT_MODULATION_TIME  (2.500000E-01)
#define AL_EAXREVERB_MIN_MODULATION_DEPTH  (0.000000E+00)
#define AL_EAXREVERB_MAX_MODULATION_DEPTH  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_MODULATION_DEPTH  (0.000000E+00)
#define AL_EAXREVERB_MIN_AIR_ABSORPTION_GAINHF  (8.920000E-01)
#define AL_EAXREVERB_MAX_AIR_ABSORPTION_GAINHF  (1.000000E+00)
#define AL_EAXREVERB_DEFAULT_AIR_ABSORPTION_GAINHF  (9.940000E-01)
#define AL_EAXREVERB_MIN_HFREFERENCE  (1.000000E+03)
#define AL_EAXREVERB_MAX_HFREFERENCE  (2.000000E+04)
#define AL_EAXREVERB_DEFAULT_HFREFERENCE  (5.000000E+03)
#define AL_EAXREVERB_MIN_LFREFERENCE  (2.000000E+01)
#define AL_EAXREVERB_MAX_LFREFERENCE  (1.000000E+03)
#define AL_EAXREVERB_DEFAULT_LFREFERENCE  (2.500000E+02)
#define AL_EAXREVERB_MIN_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
#define AL_EAXREVERB_MAX_ROOM_ROLLOFF_FACTOR  (1.000000E+01)
#define AL_EAXREVERB_DEFAULT_ROOM_ROLLOFF_FACTOR  (0.000000E+00)
static _DELPHI_CONST System::Int8 AL_EAXREVERB_MIN_DECAY_HFLIMIT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_MAX_DECAY_HFLIMIT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AL_EAXREVERB_DEFAULT_DECAY_HFLIMIT = System::Int8(0x1);
extern DELPHI_PACKAGE GUID DSPROPSETID_EAX20_ListenerProperties;
extern DELPHI_PACKAGE GUID DSPROPSETID_EAX20_BufferProperties;
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ALLPARAMETERS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ROOM = System::Int8(0x2);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ROOMHF = System::Int8(0x3);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ROOMROLLOFFFACTOR = System::Int8(0x4);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_DECAYTIME = System::Int8(0x5);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_DECAYHFRATIO = System::Int8(0x6);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_REFLECTIONS = System::Int8(0x7);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_REFLECTIONSDELAY = System::Int8(0x8);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_REVERB = System::Int8(0x9);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_REVERBDELAY = System::Int8(0xa);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ENVIRONMENT = System::Int8(0xb);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ENVIRONMENTSIZE = System::Int8(0xc);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_ENVIRONMENTDIFFUSION = System::Int8(0xd);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_AIRABSORPTIONHF = System::Int8(0xe);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_FLAGS = System::Int8(0xf);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_IMMEDIATE = System::Int8(0x0);
static _DELPHI_CONST unsigned DSPROPERTY_EAXLISTENER_DEFERRED = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXLISTENER_COMMITDEFERREDSETTINGS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_GENERIC = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_PADDEDCELL = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_ROOM = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_BATHROOM = System::Int8(0x3);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_LIVINGROOM = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_STONEROOM = System::Int8(0x5);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_AUDITORIUM = System::Int8(0x6);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_CONCERTHALL = System::Int8(0x7);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_CAVE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_ARENA = System::Int8(0x9);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_HANGAR = System::Int8(0xa);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_CARPETEDHALLWAY = System::Int8(0xb);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_HALLWAY = System::Int8(0xc);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_STONECORRIDOR = System::Int8(0xd);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_ALLEY = System::Int8(0xe);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_FOREST = System::Int8(0xf);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_CITY = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_MOUNTAINS = System::Int8(0x11);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_QUARRY = System::Int8(0x12);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_PLAIN = System::Int8(0x13);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_PARKINGLOT = System::Int8(0x14);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_SEWERPIPE = System::Int8(0x15);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_UNDERWATER = System::Int8(0x16);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_DRUGGED = System::Int8(0x17);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_DIZZY = System::Int8(0x18);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_PSYCHOTIC = System::Int8(0x19);
static _DELPHI_CONST System::Int8 EAX_ENVIRONMENT_COUNT = System::Int8(0x1a);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_DECAYTIMESCALE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_REFLECTIONSSCALE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_REFLECTIONSDELAYSCALE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_REVERBSCALE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_REVERBDELAYSCALE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EAXLISTENERFLAGS_DECAYHFLIMIT = System::Int8(0x20);
static _DELPHI_CONST unsigned EAXLISTENERFLAGS_RESERVED = unsigned(0xffffffc0);
static _DELPHI_CONST short EAXLISTENER_MINROOM = short(-10000);
static _DELPHI_CONST System::Int8 EAXLISTENER_MAXROOM = System::Int8(0x0);
static _DELPHI_CONST short EAXLISTENER_DEFAULTROOM = short(-1000);
static _DELPHI_CONST short EAXLISTENER_MINROOMHF = short(-10000);
static _DELPHI_CONST System::Int8 EAXLISTENER_MAXROOMHF = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXLISTENER_DEFAULTROOMHF = System::Int8(-100);
#define EAXLISTENER_MINROOMROLLOFFFACTOR  (0.000000E+00)
#define EAXLISTENER_MAXROOMROLLOFFFACTOR  (1.000000E+01)
#define EAXLISTENER_DEFAULTROOMROLLOFFFACTOR  (0.000000E+00)
#define EAXLISTENER_MINDECAYTIME  (1.000000E-01)
#define EAXLISTENER_MAXDECAYTIME  (2.000000E+01)
#define EAXLISTENER_DEFAULTDECAYTIME  (1.490000E+00)
#define EAXLISTENER_MINDECAYHFRATIO  (1.000000E-01)
#define EAXLISTENER_MAXDECAYHFRATIO  (2.000000E+00)
#define EAXLISTENER_DEFAULTDECAYHFRATIO  (8.300000E-01)
static _DELPHI_CONST short EAXLISTENER_MINREFLECTIONS = short(-10000);
static _DELPHI_CONST System::Word EAXLISTENER_MAXREFLECTIONS = System::Word(0x3e8);
static _DELPHI_CONST short EAXLISTENER_DEFAULTREFLECTIONS = short(-2602);
#define EAXLISTENER_MINREFLECTIONSDELAY  (0.000000E+00)
#define EAXLISTENER_MAXREFLECTIONSDELAY  (3.000000E-01)
#define EAXLISTENER_DEFAULTREFLECTIONSDELAY  (7.000000E-03)
static _DELPHI_CONST short EAXLISTENER_MINREVERB = short(-10000);
static _DELPHI_CONST System::Word EAXLISTENER_MAXREVERB = System::Word(0x7d0);
static _DELPHI_CONST System::Byte EAXLISTENER_DEFAULTREVERB = System::Byte(0xc8);
#define EAXLISTENER_MINREVERBDELAY  (0.000000E+00)
#define EAXLISTENER_MAXREVERBDELAY  (1.000000E-01)
#define EAXLISTENER_DEFAULTREVERBDELAY  (1.100000E-02)
static _DELPHI_CONST System::Int8 EAXLISTENER_MINENVIRONMENT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXLISTENER_MAXENVIRONMENT = System::Int8(0x19);
static _DELPHI_CONST System::Int8 EAXLISTENER_DEFAULTENVIRONMENT = System::Int8(0x0);
#define EAXLISTENER_MINENVIRONMENTSIZE  (1.000000E+00)
#define EAXLISTENER_MAXENVIRONMENTSIZE  (1.000000E+02)
#define EAXLISTENER_DEFAULTENVIRONMENTSIZE  (7.500000E+00)
#define EAXLISTENER_MINENVIRONMENTDIFFUSION  (0.000000E+00)
#define EAXLISTENER_MAXENVIRONMENTDIFFUSION  (1.000000E+00)
#define EAXLISTENER_DEFAULTENVIRONMENTDIFFUSION  (1.000000E+00)
#define EAXLISTENER_MINAIRABSORPTIONHF  (-1.000000E+02)
#define EAXLISTENER_MAXAIRABSORPTIONHF  (0.000000E+00)
#define EAXLISTENER_DEFAULTAIRABSORPTIONHF  (-5.000000E+00)
static _DELPHI_CONST System::Int8 EAXLISTENER_DEFAULTFLAGS = System::Int8(0x3f);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_ALLPARAMETERS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_DIRECT = System::Int8(0x2);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_DIRECTHF = System::Int8(0x3);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_ROOM = System::Int8(0x4);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_ROOMHF = System::Int8(0x5);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_ROOMROLLOFFFACTOR = System::Int8(0x6);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OBSTRUCTION = System::Int8(0x7);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OBSTRUCTIONLFRATIO = System::Int8(0x8);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OCCLUSION = System::Int8(0x9);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OCCLUSIONLFRATIO = System::Int8(0xa);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OCCLUSIONROOMRATIO = System::Int8(0xb);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_OUTSIDEVOLUMEHF = System::Int8(0xc);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_AIRABSORPTIONFACTOR = System::Int8(0xd);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_FLAG = System::Int8(0xe);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_IMMEDIATE = System::Int8(0x0);
static _DELPHI_CONST unsigned DSPROPERTY_EAXBUFFER_DEFERRED = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 DSPROPERTY_EAXBUFFER_COMMITDEFERREDSETTINGS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFERFLAGS_DIRECTHFAUTO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EAXBUFFERFLAGS_ROOMAUTO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EAXBUFFERFLAGS_ROOMHFAUTO = System::Int8(0x4);
static _DELPHI_CONST unsigned EAXBUFFERFLAGS_RESERVED = unsigned(0xfffffff8);
static _DELPHI_CONST short EAXBUFFER_MINDIRECT = short(-10000);
static _DELPHI_CONST System::Word EAXBUFFER_MAXDIRECT = System::Word(0x3e8);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTDIRECT = System::Int8(0x0);
static _DELPHI_CONST short EAXBUFFER_MINDIRECTHF = short(-10000);
static _DELPHI_CONST System::Int8 EAXBUFFER_MAXDIRECTHF = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTDIRECTHF = System::Int8(0x0);
static _DELPHI_CONST short EAXBUFFER_MINROOM = short(-10000);
static _DELPHI_CONST System::Word EAXBUFFER_MAXROOM = System::Word(0x3e8);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTROOM = System::Int8(0x0);
static _DELPHI_CONST short EAXBUFFER_MINROOMHF = short(-10000);
static _DELPHI_CONST System::Int8 EAXBUFFER_MAXROOMHF = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTROOMHF = System::Int8(0x0);
#define EAXBUFFER_MINROOMROLLOFFFACTOR  (0.000000E+00)
#define EAXBUFFER_MAXROOMROLLOFFFACTOR  (1.000000E+01)
#define EAXBUFFER_DEFAULTROOMROLLOFFFACTOR  (0.000000E+00)
static _DELPHI_CONST short EAXBUFFER_MINOBSTRUCTION = short(-10000);
static _DELPHI_CONST System::Int8 EAXBUFFER_MAXOBSTRUCTION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTOBSTRUCTION = System::Int8(0x0);
#define EAXBUFFER_MINOBSTRUCTIONLFRATIO  (0.000000E+00)
#define EAXBUFFER_MAXOBSTRUCTIONLFRATIO  (1.000000E+00)
#define EAXBUFFER_DEFAULTOBSTRUCTIONLFRATIO  (0.000000E+00)
static _DELPHI_CONST short EAXBUFFER_MINOCCLUSION = short(-10000);
static _DELPHI_CONST System::Int8 EAXBUFFER_MAXOCCLUSION = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTOCCLUSION = System::Int8(0x0);
#define EAXBUFFER_MINOCCLUSIONLFRATIO  (0.000000E+00)
#define EAXBUFFER_MAXOCCLUSIONLFRATIO  (1.000000E+00)
#define EAXBUFFER_DEFAULTOCCLUSIONLFRATIO  (2.500000E-01)
#define EAXBUFFER_MINOCCLUSIONROOMRATIO  (0.000000E+00)
#define EAXBUFFER_MAXOCCLUSIONROOMRATIO  (1.000000E+01)
#define EAXBUFFER_DEFAULTOCCLUSIONROOMRATIO  (5.000000E-01)
static _DELPHI_CONST short EAXBUFFER_MINOUTSIDEVOLUMEHF = short(-10000);
static _DELPHI_CONST System::Int8 EAXBUFFER_MAXOUTSIDEVOLUMEHF = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTOUTSIDEVOLUMEHF = System::Int8(0x0);
#define EAXBUFFER_MINAIRABSORPTIONFACTOR  (0.000000E+00)
#define EAXBUFFER_MAXAIRABSORPTIONFACTOR  (1.000000E+01)
#define EAXBUFFER_DEFAULTAIRABSORPTIONFACTOR  (1.000000E+00)
static _DELPHI_CONST System::Int8 EAXBUFFER_DEFAULTFLAGS = System::Int8(0x7);
static _DELPHI_CONST short EAX_MATERIAL_SINGLEWINDOW = short(-2800);
#define EAX_MATERIAL_SINGLEWINDOWLF  (7.100000E-01)
#define EAX_MATERIAL_SINGLEWINDOWROOMRATIO  (4.300000E-01)
static _DELPHI_CONST short EAX_MATERIAL_DOUBLEWINDOW = short(-5000);
#define EAX_MATERIAL_DOUBLEWINDOWHF  (4.000000E-01)
#define EAX_MATERIAL_DOUBLEWINDOWROOMRATIO  (2.400000E-01)
static _DELPHI_CONST short EAX_MATERIAL_THINDOOR = short(-1800);
#define EAX_MATERIAL_THINDOORLF  (6.600000E-01)
#define EAX_MATERIAL_THINDOORROOMRATIO  (6.600000E-01)
static _DELPHI_CONST short EAX_MATERIAL_THICKDOOR = short(-4400);
#define EAX_MATERIAL_THICKDOORLF  (6.400000E-01)
#define EAX_MATERIAL_THICKDOORROOMRTATION  (2.700000E-01)
static _DELPHI_CONST short EAX_MATERIAL_WOODWALL = short(-4000);
#define EAX_MATERIAL_WOODWALLLF  (5.000000E-01)
#define EAX_MATERIAL_WOODWALLROOMRATIO  (3.000000E-01)
static _DELPHI_CONST short EAX_MATERIAL_BRICKWALL = short(-5000);
#define EAX_MATERIAL_BRICKWALLLF  (6.000000E-01)
#define EAX_MATERIAL_BRICKWALLROOMRATIO  (2.400000E-01)
static _DELPHI_CONST short EAX_MATERIAL_STONEWALL = short(-6000);
#define EAX_MATERIAL_STONEWALLLF  (6.800000E-01)
#define EAX_MATERIAL_STONEWALLROOMRATIO  (2.000000E-01)
static _DELPHI_CONST short EAX_MATERIAL_CURTAIN = short(-1200);
#define EAX_MATERIAL_CURTAINLF  (1.500000E-01)
#define EAX_MATERIAL_CURTAINROOMRATIO  (1.000000E+00)
extern DELPHI_PACKAGE void __cdecl (*alEnable)(TALenum capability);
extern DELPHI_PACKAGE void __cdecl (*alDisable)(TALenum capability);
extern DELPHI_PACKAGE bool __cdecl (*alIsEnabled)(TALenum capability);
extern DELPHI_PACKAGE void __cdecl (*alHint)(TALenum target, TALenum mode);
extern DELPHI_PACKAGE void __cdecl (*alGetBooleanv)(TALenum param, PALboolean data);
extern DELPHI_PACKAGE void __cdecl (*alGetIntegerv)(TALenum param, PALint data);
extern DELPHI_PACKAGE void __cdecl (*alGetFloatv)(TALenum param, PALfloat data);
extern DELPHI_PACKAGE void __cdecl (*alGetDoublev)(TALenum param, PALdouble data);
extern DELPHI_PACKAGE char * __cdecl (*alGetString)(TALenum param);
extern DELPHI_PACKAGE bool __cdecl (*alGetBoolean)(TALenum param);
extern DELPHI_PACKAGE int __cdecl (*alGetInteger)(TALenum param);
extern DELPHI_PACKAGE float __cdecl (*alGetFloat)(TALenum param);
extern DELPHI_PACKAGE double __cdecl (*alGetDouble)(TALenum param);
extern DELPHI_PACKAGE int __cdecl (*alGetError)(void);
extern DELPHI_PACKAGE bool __cdecl (*alIsExtensionPresent)(char * fname);
extern DELPHI_PACKAGE void * __cdecl (*alGetProcAddress)(PALuByte fname);
extern DELPHI_PACKAGE int __cdecl (*alGetEnumValue)(PALuByte ename);
extern DELPHI_PACKAGE void __cdecl (*alListenerf)(TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alListener3f)(TALenum param, TALfloat f1, TALfloat f2, TALfloat f3);
extern DELPHI_PACKAGE void __cdecl (*alListenerfv)(TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alListeneri)(TALenum param, TALint value);
extern DELPHI_PACKAGE void __fastcall (*alListener3i)(TALenum param, TALint value1, TALint value2, TALint value3);
extern DELPHI_PACKAGE void __fastcall (*alListeneriv)(TALenum param, const PALint values);
extern DELPHI_PACKAGE void __cdecl (*alGetListeneriv)(TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*alGetListenerfv)(TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alGenSources)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE void __cdecl (*alDeleteSources)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE bool __cdecl (*alIsSource)(TALuint id);
extern DELPHI_PACKAGE void __cdecl (*alSourcei)(TALuint source, TALenum param, TALint value);
extern DELPHI_PACKAGE void __cdecl (*alSource3i)(TALuint source, TALenum param, TALint v1, TALint v2, TALint v3);
extern DELPHI_PACKAGE void __cdecl (*alSourceiv)(TALuint source, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*alSourcef)(TALuint source, TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alSource3f)(TALuint source, TALenum param, TALfloat v1, TALfloat v2, TALfloat v3);
extern DELPHI_PACKAGE void __cdecl (*alSourcefv)(TALuint source, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alGetSourcei)(TALuint source, TALenum param, PALint value);
extern DELPHI_PACKAGE void __cdecl (*alGetSource3i)(TALuint source, TALenum param, PALint v1, PALint v2, PALint v3);
extern DELPHI_PACKAGE void __cdecl (*alGetSourceiv)(TALuint source, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*alGetSourcef)(TALuint source, TALenum param, PALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alGetSource3f)(TALuint source, TALenum param, PALfloat v1, PALfloat v2, PALfloat v3);
extern DELPHI_PACKAGE void __cdecl (*alGetSourcefv)(TALuint source, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alSourcePlay)(TALuint source);
extern DELPHI_PACKAGE void __cdecl (*alSourcePause)(TALuint source);
extern DELPHI_PACKAGE void __cdecl (*alSourceStop)(TALuint source);
extern DELPHI_PACKAGE void __cdecl (*alSourceRewind)(TALuint source);
extern DELPHI_PACKAGE void __cdecl (*alSourcePlayv)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE void __cdecl (*alSourceStopv)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE void __cdecl (*alSourceRewindv)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE void __cdecl (*alSourcePausev)(TALsizei n, PALuint sources);
extern DELPHI_PACKAGE void __cdecl (*alSourceQueueBuffers)(TALuint source, TALsizei n, PALuint buffers);
extern DELPHI_PACKAGE void __cdecl (*alSourceUnqueueBuffers)(TALuint source, TALsizei n, PALuint buffers);
extern DELPHI_PACKAGE void __cdecl (*alGenBuffers)(TALsizei n, PALuint buffers);
extern DELPHI_PACKAGE void __cdecl (*alDeleteBuffers)(TALsizei n, PALuint buffers);
extern DELPHI_PACKAGE bool __cdecl (*alIsBuffer)(TALuint buffer);
extern DELPHI_PACKAGE void __cdecl (*alBufferData)(TALuint buffer, TALenum format, void * data, TALsizei size, TALsizei freq);
extern DELPHI_PACKAGE void __cdecl (*alBufferi)(TALuint buffer, TALenum param, TALint value);
extern DELPHI_PACKAGE void __cdecl (*alBuffer3i)(TALuint buffer, TALenum param, TALint v1, TALint v2, TALint v3);
extern DELPHI_PACKAGE void __cdecl (*alBufferiv)(TALuint buffer, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*alBufferf)(TALuint buffer, TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alBuffer3f)(TALuint buffer, TALenum param, TALfloat v1, TALfloat v2, TALfloat v3);
extern DELPHI_PACKAGE void __cdecl (*alBufferfv)(TALuint buffer, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alGetBufferi)(TALuint buffer, TALenum param, PALint value);
extern DELPHI_PACKAGE void __cdecl (*alGetBuffer3i)(TALuint buffer, TALenum param, PALint v1, PALint v2, PALint v3);
extern DELPHI_PACKAGE void __cdecl (*alGetBufferiv)(TALuint buffer, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*alGetBufferf)(TALuint buffer, TALenum param, PALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alGetBuffer3f)(TALuint buffer, TALenum param, PALfloat v1, PALfloat v2, PALfloat v3);
extern DELPHI_PACKAGE void __cdecl (*alGetBufferfv)(TALuint buffer, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*alDistanceModel)(TALenum value);
extern DELPHI_PACKAGE void __cdecl (*alDopplerFactor)(TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alDopplerVelocity)(TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*alSpeedOfSound)(TALfloat value);
extern DELPHI_PACKAGE void * __cdecl (*alcCreateContext)(TALCdevice device, PALCint attrlist);
extern DELPHI_PACKAGE int __cdecl (*alcMakeContextCurrent)(TALCcontext context);
extern DELPHI_PACKAGE void __cdecl (*alcProcessContext)(TALCcontext context);
extern DELPHI_PACKAGE void __cdecl (*alcSuspendContext)(TALCcontext context);
extern DELPHI_PACKAGE void __cdecl (*alcDestroyContext)(TALCcontext context);
extern DELPHI_PACKAGE void * __cdecl (*alcGetCurrentContext)(void);
extern DELPHI_PACKAGE void * __cdecl (*alcGetContextsDevice)(TALCcontext context);
extern DELPHI_PACKAGE void * __cdecl (*alcOpenDevice)(PALCubyte deviceName);
extern DELPHI_PACKAGE void __cdecl (*alcCloseDevice)(TALCdevice device);
extern DELPHI_PACKAGE int __cdecl (*alcGetError)(TALCdevice device);
extern DELPHI_PACKAGE bool __cdecl (*alcIsExtensionPresent)(TALCdevice device, PALuByte extName);
extern DELPHI_PACKAGE void * __cdecl (*alcGetProcAddress)(TALCdevice device, PALuByte funcName);
extern DELPHI_PACKAGE int __cdecl (*alcGetEnumValue)(TALCdevice device, PALuByte enumName);
extern DELPHI_PACKAGE char * __cdecl (*alcGetString)(TALCdevice device, TALCenum param);
extern DELPHI_PACKAGE void __cdecl (*alcGetIntegerv)(TALCdevice device, TALCenum param, TALCsizei size, PALCint data);
extern DELPHI_PACKAGE PALCdevice __cdecl (*alcCaptureOpenDevice)(const PALCchar devicename, TALCuint frequency, TALCenum format, TALCsizei buffersize);
extern DELPHI_PACKAGE bool __cdecl (*alcCaptureCloseDevice)(PALCdevice device);
extern DELPHI_PACKAGE void __cdecl (*alcCaptureStart)(PALCdevice device);
extern DELPHI_PACKAGE void __cdecl (*alcCaptureStop)(PALCdevice device);
extern DELPHI_PACKAGE void __cdecl (*alcCaptureSamples)(PALCdevice device, TALCvoid buffer, TALCsizei samples);
extern DELPHI_PACKAGE int __cdecl (*EAXSet)(const GUID &Guid, TALuint ALuint1, TALuint ALuint2, void * point, TALuint ALuint3);
extern DELPHI_PACKAGE int __cdecl (*EAXGet)(const GUID &Guid, TALuint ALuint1, TALuint ALuint2, void * point, TALuint ALuint3);
extern DELPHI_PACKAGE TALenum AL_EAX_RAM_SIZE;
extern DELPHI_PACKAGE TALenum AL_EAX_RAM_FREE;
extern DELPHI_PACKAGE TALenum AL_STORAGE_AUTOMATIC;
extern DELPHI_PACKAGE TALenum AL_STORAGE_HARDWARE;
extern DELPHI_PACKAGE TALenum AL_STORAGE_ACCESSIBLE;
extern DELPHI_PACKAGE bool __cdecl (*EAXSetBufferMode)(TALsizei n, PALuint buffers, TALint value);
extern DELPHI_PACKAGE int __cdecl (*EAXGetBufferMode)(TALuint buffer, PALint value);
extern DELPHI_PACKAGE void __cdecl (*ALGENEFFECTS)(TALsizei n, PALuint effects);
extern DELPHI_PACKAGE void __cdecl (*ALDELETEEFFECTS)(TALsizei n, PALuint effects);
extern DELPHI_PACKAGE bool __cdecl (*ALISEFFECT)(TALuint eid);
extern DELPHI_PACKAGE void __cdecl (*ALEFFECTI)(TALuint eid, TALCenum param, TALint value);
extern DELPHI_PACKAGE void __cdecl (*ALEFFECTIV)(TALuint eid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALEFFECTF)(TALuint eid, TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALEFFECTFV)(TALuint eid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*ALGETEFFECTI)(TALuint eid, TALenum param, PALint value);
extern DELPHI_PACKAGE void __cdecl (*ALGETEFFECTIV)(TALuint eid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALGETEFFECTF)(TALuint eid, TALenum param, PALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALGETEFFECTFV)(TALuint eid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*ALGENFILTERS)(TALsizei n, PALuint filters);
extern DELPHI_PACKAGE void __cdecl (*ALDELETEFILTERS)(TALsizei n, PALuint filters);
extern DELPHI_PACKAGE bool __cdecl (*ALISFILTER)(TALuint fid);
extern DELPHI_PACKAGE void __cdecl (*ALFILTERI)(TALuint fid, TALenum param, TALint value);
extern DELPHI_PACKAGE void __cdecl (*ALFILTERIV)(TALuint fid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALFILTERF)(TALuint fid, TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALFILTERFV)(TALuint fid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*ALGETFILTERI)(TALuint fid, TALenum param, PALint value);
extern DELPHI_PACKAGE void __cdecl (*ALGETFILTERIV)(TALuint fid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALGETFILTERF)(TALuint fid, TALenum param, PALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALGETFILTERFV)(TALuint fid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*ALGENAUXILIARYEFFECTSLOTS)(TALsizei n, PALuint slots);
extern DELPHI_PACKAGE void __cdecl (*ALDELETEAUXILIARYEFFECTSLOTS)(TALsizei n, PALuint slots);
extern DELPHI_PACKAGE bool __cdecl (*ALISAUXILIARYEFFECTSLOT)(TALuint slot);
extern DELPHI_PACKAGE void __cdecl (*ALAUXILIARYEFFECTSLOTI)(TALuint asid, TALenum param, TALint value);
extern DELPHI_PACKAGE void __cdecl (*ALAUXILIARYEFFECTSLOTIV)(TALuint asid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALAUXILIARYEFFECTSLOTF)(TALuint asid, TALenum param, TALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALAUXILIARYEFFECTSLOTFV)(TALuint asid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE void __cdecl (*ALGETAUXILIARYEFFECTSLOTI)(TALuint asid, TALenum param, PALint value);
extern DELPHI_PACKAGE void __cdecl (*ALGETAUXILIARYEFFECTSLOTIV)(TALuint asid, TALenum param, PALint values);
extern DELPHI_PACKAGE void __cdecl (*ALGETAUXILIARYEFFECTSLOTF)(TALuint asid, TALenum param, PALfloat value);
extern DELPHI_PACKAGE void __cdecl (*ALGETAUXILIARYEFFECTSLOTFV)(TALuint asid, TALenum param, PALfloat values);
extern DELPHI_PACKAGE Winapi::Windows::THandle LibHandle;
extern DELPHI_PACKAGE Winapi::Windows::THandle EFXUtilLibHandle;
extern DELPHI_PACKAGE bool __fastcall InitOpenAL(System::UnicodeString LibName = L"OpenAL32.dll");
extern DELPHI_PACKAGE void __fastcall ReadOpenALExtensions(void);
extern DELPHI_PACKAGE void __fastcall alutInit(PALint argc, PALbyte *argv, const System::NativeInt argv_High);
extern DELPHI_PACKAGE void __fastcall alutExit(void);
extern DELPHI_PACKAGE void __fastcall alutLoadWAVFile(System::UnicodeString fname, TALenum &format, TALvoid &data, TALsizei &size, TALsizei &freq, TALint &loop);
extern DELPHI_PACKAGE void __fastcall alutLoadWAVMemory(PALbyte memory, TALenum &format, TALvoid &data, TALsizei &size, TALsizei &freq, TALint &loop);
extern DELPHI_PACKAGE void __fastcall alutUnloadWAV(TALenum format, TALvoid data, TALsizei size, TALsizei freq);
}	/* namespace Import */
}	/* namespace Openal */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENAL_IMPORT)
using namespace Openal::Import;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENAL)
using namespace Openal;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OpenAL_ImportHPP
