// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BASS.Import.pas' rev: 36.00 (Windows)

#ifndef BASS_ImportHPP
#define BASS_ImportHPP

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

//-- user supplied -----------------------------------------------------------

namespace Bass
{
namespace Import
{
//-- forward type declarations -----------------------------------------------
struct BASS_DEVICEINFO;
struct BASS_INFO;
struct BASS_RECORDINFO;
struct BASS_SAMPLE;
struct BASS_CHANNELINFO;
struct BASS_PLUGINFORM;
struct BASS_PLUGININFO;
struct BASS_3DVECTOR;
struct BASS_FILEPROCS;
struct TAG_ID3;
struct TAG_APE_BINARY;
struct TAG_BEXT;
struct BASS_DX8_CHORUS;
struct BASS_DX8_COMPRESSOR;
struct BASS_DX8_DISTORTION;
struct BASS_DX8_ECHO;
struct BASS_DX8_FLANGER;
struct BASS_DX8_GARGLE;
struct BASS_DX8_I3DL2REVERB;
struct BASS_DX8_PARAMEQ;
struct BASS_DX8_REVERB;
struct BASS_FX_VOLUME_PARAM;
//-- type declarations -------------------------------------------------------
typedef unsigned DWORD;

typedef System::LongBool BOOL;

typedef __int64 QWORD;

typedef DWORD HMUSIC;

typedef DWORD HSAMPLE;

typedef DWORD HCHANNEL;

typedef DWORD HSTREAM;

typedef DWORD HRECORD;

typedef DWORD HSYNC;

typedef DWORD HDSP;

typedef DWORD HFX;

typedef DWORD HPLUGIN;

struct DECLSPEC_DRECORD BASS_DEVICEINFO
{
public:
	char *name;
	char *driver;
	DWORD flags;
};


struct DECLSPEC_DRECORD BASS_INFO
{
public:
	DWORD flags;
	DWORD hwsize;
	DWORD hwfree;
	DWORD freesam;
	DWORD free3d;
	DWORD minrate;
	DWORD maxrate;
	BOOL eax;
	DWORD minbuf;
	DWORD dsver;
	DWORD latency;
	DWORD initflags;
	DWORD speakers;
	DWORD freq;
};


struct DECLSPEC_DRECORD BASS_RECORDINFO
{
public:
	DWORD flags;
	DWORD formats;
	DWORD inputs;
	BOOL singlein;
	DWORD freq;
};


struct DECLSPEC_DRECORD BASS_SAMPLE
{
public:
	DWORD freq;
	float volume;
	float pan;
	DWORD flags;
	DWORD length;
	DWORD max;
	DWORD origres;
	DWORD chans;
	DWORD mingap;
	DWORD mode3d;
	float mindist;
	float maxdist;
	DWORD iangle;
	DWORD oangle;
	float outvol;
	DWORD vam;
	DWORD priority;
};


struct DECLSPEC_DRECORD BASS_CHANNELINFO
{
public:
	DWORD freq;
	DWORD chans;
	DWORD flags;
	DWORD ctype;
	DWORD origres;
	HPLUGIN plugin;
	HSAMPLE sample;
	System::WideChar *filename;
};


struct DECLSPEC_DRECORD BASS_PLUGINFORM
{
public:
	DWORD ctype;
	char *name;
	char *exts;
};


typedef System::StaticArray<BASS_PLUGINFORM, 178956970> TBASS_PLUGINFORMS;

typedef TBASS_PLUGINFORMS *PBASS_PLUGINFORMS;

typedef BASS_PLUGININFO *PBASS_PLUGININFO;

struct DECLSPEC_DRECORD BASS_PLUGININFO
{
public:
	DWORD version;
	DWORD formatc;
	PBASS_PLUGINFORMS formats;
};


struct DECLSPEC_DRECORD BASS_3DVECTOR
{
public:
	float x;
	float y;
	float z;
};


typedef void __stdcall (*FILECLOSEPROC)(void * user);

typedef QWORD __stdcall (*FILELENPROC)(void * user);

typedef DWORD __stdcall (*FILEREADPROC)(void * buffer, DWORD length, void * user);

typedef BOOL __stdcall (*FILESEEKPROC)(QWORD offset, void * user);

struct DECLSPEC_DRECORD BASS_FILEPROCS
{
public:
	FILECLOSEPROC close;
	FILELENPROC length;
	FILEREADPROC read;
	FILESEEKPROC seek;
};


typedef TAG_ID3 *PTAG_ID3;

struct DECLSPEC_DRECORD TAG_ID3
{
public:
	System::StaticArray<char, 3> id;
	System::StaticArray<char, 30> title;
	System::StaticArray<char, 30> artist;
	System::StaticArray<char, 30> album;
	System::StaticArray<char, 4> year;
	System::StaticArray<char, 30> comment;
	System::Byte genre;
};


typedef TAG_APE_BINARY *PTAG_APE_BINARY;

struct DECLSPEC_DRECORD TAG_APE_BINARY
{
public:
	char *key;
	char *data;
	DWORD length;
};


typedef TAG_BEXT *PTAG_BEXT;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TAG_BEXT
{
public:
	System::StaticArray<char, 256> Description;
	System::StaticArray<char, 32> Originator;
	System::StaticArray<char, 32> OriginatorReference;
	System::StaticArray<char, 10> OriginationDate;
	System::StaticArray<char, 8> OriginationTime;
	QWORD TimeReference;
	System::Word Version;
	System::StaticArray<System::Byte, 64> UMID;
	System::StaticArray<System::Byte, 190> Reserved;
	char CodingHistory;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD BASS_DX8_CHORUS
{
public:
	float fWetDryMix;
	float fDepth;
	float fFeedback;
	float fFrequency;
	DWORD lWaveform;
	float fDelay;
	DWORD lPhase;
};


struct DECLSPEC_DRECORD BASS_DX8_COMPRESSOR
{
public:
	float fGain;
	float fAttack;
	float fRelease;
	float fThreshold;
	float fRatio;
	float fPredelay;
};


struct DECLSPEC_DRECORD BASS_DX8_DISTORTION
{
public:
	float fGain;
	float fEdge;
	float fPostEQCenterFrequency;
	float fPostEQBandwidth;
	float fPreLowpassCutoff;
};


struct DECLSPEC_DRECORD BASS_DX8_ECHO
{
public:
	float fWetDryMix;
	float fFeedback;
	float fLeftDelay;
	float fRightDelay;
	BOOL lPanDelay;
};


struct DECLSPEC_DRECORD BASS_DX8_FLANGER
{
public:
	float fWetDryMix;
	float fDepth;
	float fFeedback;
	float fFrequency;
	DWORD lWaveform;
	float fDelay;
	DWORD lPhase;
};


struct DECLSPEC_DRECORD BASS_DX8_GARGLE
{
public:
	DWORD dwRateHz;
	DWORD dwWaveShape;
};


struct DECLSPEC_DRECORD BASS_DX8_I3DL2REVERB
{
public:
	int lRoom;
	int lRoomHF;
	float flRoomRolloffFactor;
	float flDecayTime;
	float flDecayHFRatio;
	int lReflections;
	float flReflectionsDelay;
	int lReverb;
	float flReverbDelay;
	float flDiffusion;
	float flDensity;
	float flHFReference;
};


struct DECLSPEC_DRECORD BASS_DX8_PARAMEQ
{
public:
	float fCenter;
	float fBandwidth;
	float fGain;
};


struct DECLSPEC_DRECORD BASS_DX8_REVERB
{
public:
	float fInGain;
	float fReverbMix;
	float fReverbTime;
	float fHighFreqRTRatio;
};


struct DECLSPEC_DRECORD BASS_FX_VOLUME_PARAM
{
public:
	float fTarget;
	float fCurrent;
	float fTime;
	DWORD lCurve;
};


typedef DWORD __stdcall (*STREAMPROC)(HSTREAM handle, void * buffer, DWORD length, void * user);

typedef void __stdcall (*DOWNLOADPROC)(void * buffer, DWORD length, void * user);

typedef void __stdcall (*SYNCPROC)(HSYNC handle, DWORD channel, DWORD data, void * user);

typedef void __stdcall (*DSPPROC)(HDSP handle, DWORD channel, void * buffer, DWORD length, void * user);

typedef BOOL __stdcall (*RECORDPROC)(HRECORD handle, void * buffer, DWORD length, void * user);

typedef Winapi::Windows::HINST TBASSModuleHandle;

//-- var, const, procedure ---------------------------------------------------
#define bassdll L"bass32.dll"
static _DELPHI_CONST System::Word BASSVERSION = System::Word(0x204);
#define BASSVERSIONTEXT L"2.4"
static _DELPHI_CONST unsigned DW_ERROR = unsigned(0xffffffff);
static _DELPHI_CONST __int64 QW_ERROR = -1LL;
static _DELPHI_CONST System::Int8 BASS_OK = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_ERROR_MEM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_ERROR_FILEOPEN = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_ERROR_DRIVER = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_ERROR_BUFLOST = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_ERROR_HANDLE = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_ERROR_FORMAT = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_ERROR_POSITION = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_ERROR_INIT = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_ERROR_START = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_ERROR_SSL = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_ERROR_REINIT = System::Int8(0xb);
static _DELPHI_CONST System::Int8 BASS_ERROR_ALREADY = System::Int8(0xe);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOTAUDIO = System::Int8(0x11);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOCHAN = System::Int8(0x12);
static _DELPHI_CONST System::Int8 BASS_ERROR_ILLTYPE = System::Int8(0x13);
static _DELPHI_CONST System::Int8 BASS_ERROR_ILLPARAM = System::Int8(0x14);
static _DELPHI_CONST System::Int8 BASS_ERROR_NO3D = System::Int8(0x15);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOEAX = System::Int8(0x16);
static _DELPHI_CONST System::Int8 BASS_ERROR_DEVICE = System::Int8(0x17);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOPLAY = System::Int8(0x18);
static _DELPHI_CONST System::Int8 BASS_ERROR_FREQ = System::Int8(0x19);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOTFILE = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOHW = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 BASS_ERROR_EMPTY = System::Int8(0x1f);
static _DELPHI_CONST System::Int8 BASS_ERROR_NONET = System::Int8(0x20);
static _DELPHI_CONST System::Int8 BASS_ERROR_CREATE = System::Int8(0x21);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOFX = System::Int8(0x22);
static _DELPHI_CONST System::Int8 BASS_ERROR_NOTAVAIL = System::Int8(0x25);
static _DELPHI_CONST System::Int8 BASS_ERROR_DECODE = System::Int8(0x26);
static _DELPHI_CONST System::Int8 BASS_ERROR_DX = System::Int8(0x27);
static _DELPHI_CONST System::Int8 BASS_ERROR_TIMEOUT = System::Int8(0x28);
static _DELPHI_CONST System::Int8 BASS_ERROR_FILEFORM = System::Int8(0x29);
static _DELPHI_CONST System::Int8 BASS_ERROR_SPEAKER = System::Int8(0x2a);
static _DELPHI_CONST System::Int8 BASS_ERROR_VERSION = System::Int8(0x2b);
static _DELPHI_CONST System::Int8 BASS_ERROR_CODEC = System::Int8(0x2c);
static _DELPHI_CONST System::Int8 BASS_ERROR_ENDED = System::Int8(0x2d);
static _DELPHI_CONST System::Int8 BASS_ERROR_BUSY = System::Int8(0x2e);
static _DELPHI_CONST System::Int8 BASS_ERROR_UNSTREAMABLE = System::Int8(0x2f);
static _DELPHI_CONST System::Int8 BASS_ERROR_PROTOCOL = System::Int8(0x30);
static _DELPHI_CONST System::Int8 BASS_ERROR_DENIED = System::Int8(0x31);
static _DELPHI_CONST System::Int8 BASS_ERROR_UNKNOWN = System::Int8(-1);
static _DELPHI_CONST System::Int8 BASS_CONFIG_BUFFER = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_CONFIG_UPDATEPERIOD = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_CONFIG_GVOL_SAMPLE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_CONFIG_GVOL_STREAM = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_CONFIG_GVOL_MUSIC = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_CONFIG_CURVE_VOL = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_CONFIG_CURVE_PAN = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_CONFIG_FLOATDSP = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_CONFIG_3DALGORITHM = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_TIMEOUT = System::Int8(0xb);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_BUFFER = System::Int8(0xc);
static _DELPHI_CONST System::Int8 BASS_CONFIG_PAUSE_NOPLAY = System::Int8(0xd);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PREBUF = System::Int8(0xf);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PASSIVE = System::Int8(0x12);
static _DELPHI_CONST System::Int8 BASS_CONFIG_REC_BUFFER = System::Int8(0x13);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PLAYLIST = System::Int8(0x15);
static _DELPHI_CONST System::Int8 BASS_CONFIG_MUSIC_VIRTUAL = System::Int8(0x16);
static _DELPHI_CONST System::Int8 BASS_CONFIG_VERIFY = System::Int8(0x17);
static _DELPHI_CONST System::Int8 BASS_CONFIG_UPDATETHREADS = System::Int8(0x18);
static _DELPHI_CONST System::Int8 BASS_CONFIG_DEV_BUFFER = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 BASS_CONFIG_REC_LOOPBACK = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 BASS_CONFIG_VISTA_TRUEPOS = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 BASS_CONFIG_IOS_SESSION = System::Int8(0x22);
static _DELPHI_CONST System::Int8 BASS_CONFIG_IOS_MIXAUDIO = System::Int8(0x22);
static _DELPHI_CONST System::Int8 BASS_CONFIG_DEV_DEFAULT = System::Int8(0x24);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_READTIMEOUT = System::Int8(0x25);
static _DELPHI_CONST System::Int8 BASS_CONFIG_VISTA_SPEAKERS = System::Int8(0x26);
static _DELPHI_CONST System::Int8 BASS_CONFIG_IOS_SPEAKER = System::Int8(0x27);
static _DELPHI_CONST System::Int8 BASS_CONFIG_MF_DISABLE = System::Int8(0x28);
static _DELPHI_CONST System::Int8 BASS_CONFIG_HANDLES = System::Int8(0x29);
static _DELPHI_CONST System::Int8 BASS_CONFIG_UNICODE = System::Int8(0x2a);
static _DELPHI_CONST System::Int8 BASS_CONFIG_SRC = System::Int8(0x2b);
static _DELPHI_CONST System::Int8 BASS_CONFIG_SRC_SAMPLE = System::Int8(0x2c);
static _DELPHI_CONST System::Int8 BASS_CONFIG_ASYNCFILE_BUFFER = System::Int8(0x2d);
static _DELPHI_CONST System::Int8 BASS_CONFIG_OGG_PRESCAN = System::Int8(0x2f);
static _DELPHI_CONST System::Int8 BASS_CONFIG_MF_VIDEO = System::Int8(0x30);
static _DELPHI_CONST System::Int8 BASS_CONFIG_AIRPLAY = System::Int8(0x31);
static _DELPHI_CONST System::Int8 BASS_CONFIG_DEV_NONSTOP = System::Int8(0x32);
static _DELPHI_CONST System::Int8 BASS_CONFIG_IOS_NOCATEGORY = System::Int8(0x33);
static _DELPHI_CONST System::Int8 BASS_CONFIG_VERIFY_NET = System::Int8(0x34);
static _DELPHI_CONST System::Int8 BASS_CONFIG_DEV_PERIOD = System::Int8(0x35);
static _DELPHI_CONST System::Int8 BASS_CONFIG_FLOAT = System::Int8(0x36);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_SEEK = System::Int8(0x38);
static _DELPHI_CONST System::Int8 BASS_CONFIG_AM_DISABLE = System::Int8(0x3a);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PLAYLIST_DEPTH = System::Int8(0x3b);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PREBUF_WAIT = System::Int8(0x3c);
static _DELPHI_CONST System::Int8 BASS_CONFIG_ANDROID_SESSIONID = System::Int8(0x3e);
static _DELPHI_CONST System::Int8 BASS_CONFIG_WASAPI_PERSIST = System::Int8(0x41);
static _DELPHI_CONST System::Int8 BASS_CONFIG_REC_WASAPI = System::Int8(0x42);
static _DELPHI_CONST System::Int8 BASS_CONFIG_ANDROID_AAUDIO = System::Int8(0x43);
static _DELPHI_CONST System::Int8 BASS_CONFIG_SAMPLE_ONEHANDLE = System::Int8(0x45);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_META = System::Int8(0x47);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_RESTRATE = System::Int8(0x48);
static _DELPHI_CONST System::Int8 BASS_CONFIG_REC_DEFAULT = System::Int8(0x49);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NORAMP = System::Int8(0x4a);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_AGENT = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_CONFIG_NET_PROXY = System::Int8(0x11);
static _DELPHI_CONST System::Int8 BASS_CONFIG_ANDROID_JAVAVM = System::Int8(0x3f);
static _DELPHI_CONST System::Int8 BASS_CONFIG_LIBSSL = System::Int8(0x40);
static _DELPHI_CONST System::Int8 BASS_CONFIG_FILENAME = System::Int8(0x4b);
static _DELPHI_CONST int BASS_CONFIG_THREAD = int(0x40000000);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_MIX = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_DUCK = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_AMBIENT = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_SPEAKER = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_DISABLE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_DEACTIVATE = System::Int8(0x20);
static _DELPHI_CONST System::Int8 BASS_IOS_SESSION_AIRPLAY = System::Int8(0x40);
static _DELPHI_CONST System::Byte BASS_IOS_SESSION_BTHFP = System::Byte(0x80);
static _DELPHI_CONST System::Word BASS_IOS_SESSION_BTA2DP = System::Word(0x100);
static _DELPHI_CONST System::Int8 BASS_DEVICE_8BITS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_DEVICE_MONO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_DEVICE_3D = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_DEVICE_16BITS = System::Int8(0x8);
static _DELPHI_CONST System::Byte BASS_DEVICE_REINIT = System::Byte(0x80);
static _DELPHI_CONST System::Word BASS_DEVICE_LATENCY = System::Word(0x100);
static _DELPHI_CONST System::Word BASS_DEVICE_CPSPEAKERS = System::Word(0x400);
static _DELPHI_CONST System::Word BASS_DEVICE_SPEAKERS = System::Word(0x800);
static _DELPHI_CONST System::Word BASS_DEVICE_NOSPEAKER = System::Word(0x1000);
static _DELPHI_CONST System::Word BASS_DEVICE_DMIX = System::Word(0x2000);
static _DELPHI_CONST System::Word BASS_DEVICE_FREQ = System::Word(0x4000);
static _DELPHI_CONST System::Word BASS_DEVICE_STEREO = System::Word(0x8000);
static _DELPHI_CONST int BASS_DEVICE_AUDIOTRACK = int(0x20000);
static _DELPHI_CONST int BASS_DEVICE_DSOUND = int(0x40000);
static _DELPHI_CONST int BASS_DEVICE_SOFTWARE = int(0x80000);
static _DELPHI_CONST System::Int8 BASS_OBJECT_DS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_OBJECT_DS3DL = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_DEVICE_ENABLED = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_DEVICE_DEFAULT = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_DEVICE_INIT = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_DEVICE_LOOPBACK = System::Int8(0x8);
static _DELPHI_CONST System::Byte BASS_DEVICE_DEFAULTCOM = System::Byte(0x80);
static _DELPHI_CONST unsigned BASS_DEVICE_TYPE_MASK = unsigned(0xff000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_NETWORK = int(0x1000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_SPEAKERS = int(0x2000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_LINE = int(0x3000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_HEADPHONES = int(0x4000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_MICROPHONE = int(0x5000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_HEADSET = int(0x6000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_HANDSET = int(0x7000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_DIGITAL = int(0x8000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_SPDIF = int(0x9000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_HDMI = int(0xa000000);
static _DELPHI_CONST int BASS_DEVICE_TYPE_DISPLAYPORT = int(0x40000000);
static _DELPHI_CONST int BASS_DEVICES_AIRPLAY = int(0x1000000);
static _DELPHI_CONST System::Int8 DSCAPS_EMULDRIVER = System::Int8(0x20);
static _DELPHI_CONST System::Int8 DSCAPS_CERTIFIED = System::Int8(0x40);
static _DELPHI_CONST unsigned DSCAPS_HARDWARE = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 DSCCAPS_EMULDRIVER = System::Int8(0x20);
static _DELPHI_CONST System::Int8 DSCCAPS_CERTIFIED = System::Int8(0x40);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_8BITS = System::Int8(0x1);
static _DELPHI_CONST System::Word BASS_SAMPLE_FLOAT = System::Word(0x100);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_MONO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_LOOP = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_3D = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_SOFTWARE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_MUTEMAX = System::Int8(0x20);
static _DELPHI_CONST System::Int8 BASS_SAMPLE_VAM = System::Int8(0x40);
static _DELPHI_CONST System::Byte BASS_SAMPLE_FX = System::Byte(0x80);
static _DELPHI_CONST int BASS_SAMPLE_OVER_VOL = int(0x10000);
static _DELPHI_CONST int BASS_SAMPLE_OVER_POS = int(0x20000);
static _DELPHI_CONST int BASS_SAMPLE_OVER_DIST = int(0x30000);
static _DELPHI_CONST int BASS_STREAM_PRESCAN = int(0x20000);
static _DELPHI_CONST int BASS_STREAM_AUTOFREE = int(0x40000);
static _DELPHI_CONST int BASS_STREAM_RESTRATE = int(0x80000);
static _DELPHI_CONST int BASS_STREAM_BLOCK = int(0x100000);
static _DELPHI_CONST int BASS_STREAM_DECODE = int(0x200000);
static _DELPHI_CONST int BASS_STREAM_STATUS = int(0x800000);
static _DELPHI_CONST System::Word BASS_MP3_IGNOREDELAY = System::Word(0x200);
static _DELPHI_CONST int BASS_MP3_SETPOS = int(0x20000);
static _DELPHI_CONST System::Word BASS_MUSIC_FLOAT = System::Word(0x100);
static _DELPHI_CONST System::Int8 BASS_MUSIC_MONO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_MUSIC_LOOP = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_MUSIC_3D = System::Int8(0x8);
static _DELPHI_CONST System::Byte BASS_MUSIC_FX = System::Byte(0x80);
static _DELPHI_CONST int BASS_MUSIC_AUTOFREE = int(0x40000);
static _DELPHI_CONST int BASS_MUSIC_DECODE = int(0x200000);
static _DELPHI_CONST int BASS_MUSIC_PRESCAN = int(0x20000);
static _DELPHI_CONST int BASS_MUSIC_CALCLEN = int(0x20000);
static _DELPHI_CONST System::Word BASS_MUSIC_RAMP = System::Word(0x200);
static _DELPHI_CONST System::Word BASS_MUSIC_RAMPS = System::Word(0x400);
static _DELPHI_CONST System::Word BASS_MUSIC_SURROUND = System::Word(0x800);
static _DELPHI_CONST System::Word BASS_MUSIC_SURROUND2 = System::Word(0x1000);
static _DELPHI_CONST System::Word BASS_MUSIC_FT2PAN = System::Word(0x2000);
static _DELPHI_CONST System::Word BASS_MUSIC_FT2MOD = System::Word(0x2000);
static _DELPHI_CONST System::Word BASS_MUSIC_PT1MOD = System::Word(0x4000);
static _DELPHI_CONST int BASS_MUSIC_NONINTER = int(0x10000);
static _DELPHI_CONST int BASS_MUSIC_SINCINTER = int(0x800000);
static _DELPHI_CONST System::Word BASS_MUSIC_POSRESET = System::Word(0x8000);
static _DELPHI_CONST int BASS_MUSIC_POSRESETEX = int(0x400000);
static _DELPHI_CONST int BASS_MUSIC_STOPBACK = int(0x80000);
static _DELPHI_CONST int BASS_MUSIC_NOSAMPLE = int(0x100000);
static _DELPHI_CONST int BASS_SPEAKER_FRONT = int(0x1000000);
static _DELPHI_CONST int BASS_SPEAKER_REAR = int(0x2000000);
static _DELPHI_CONST int BASS_SPEAKER_CENLFE = int(0x3000000);
static _DELPHI_CONST int BASS_SPEAKER_SIDE = int(0x4000000);
static _DELPHI_CONST int BASS_SPEAKER_LEFT = int(0x10000000);
static _DELPHI_CONST int BASS_SPEAKER_RIGHT = int(0x20000000);
static _DELPHI_CONST int BASS_SPEAKER_FRONTLEFT = int(0x11000000);
static _DELPHI_CONST int BASS_SPEAKER_FRONTRIGHT = int(0x21000000);
static _DELPHI_CONST int BASS_SPEAKER_REARLEFT = int(0x12000000);
static _DELPHI_CONST int BASS_SPEAKER_REARRIGHT = int(0x22000000);
static _DELPHI_CONST int BASS_SPEAKER_CENTER = int(0x13000000);
static _DELPHI_CONST int BASS_SPEAKER_LFE = int(0x23000000);
static _DELPHI_CONST int BASS_SPEAKER_SIDELEFT = int(0x14000000);
static _DELPHI_CONST int BASS_SPEAKER_SIDERIGHT = int(0x24000000);
static _DELPHI_CONST int BASS_SPEAKER_REAR2 = int(0x4000000);
static _DELPHI_CONST int BASS_SPEAKER_REAR2LEFT = int(0x14000000);
static _DELPHI_CONST int BASS_SPEAKER_REAR2RIGHT = int(0x24000000);
static _DELPHI_CONST int BASS_ASYNCFILE = int(0x40000000);
static _DELPHI_CONST unsigned BASS_UNICODE = unsigned(0x80000000);
static _DELPHI_CONST System::Word BASS_RECORD_PAUSE = System::Word(0x8000);
static _DELPHI_CONST System::Int8 BASS_VAM_HARDWARE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_VAM_SOFTWARE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_VAM_TERM_TIME = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_VAM_TERM_DIST = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_VAM_TERM_PRIO = System::Int8(0x10);
static _DELPHI_CONST int BASS_ORIGRES_FLOAT = int(0x10000);
static _DELPHI_CONST System::Int8 BASS_CTYPE_SAMPLE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_CTYPE_RECORD = System::Int8(0x2);
static _DELPHI_CONST int BASS_CTYPE_STREAM = int(0x10000);
static _DELPHI_CONST int BASS_CTYPE_STREAM_VORBIS = int(0x10002);
static _DELPHI_CONST int BASS_CTYPE_STREAM_OGG = int(0x10002);
static _DELPHI_CONST int BASS_CTYPE_STREAM_MP1 = int(0x10003);
static _DELPHI_CONST int BASS_CTYPE_STREAM_MP2 = int(0x10004);
static _DELPHI_CONST int BASS_CTYPE_STREAM_MP3 = int(0x10005);
static _DELPHI_CONST int BASS_CTYPE_STREAM_AIFF = int(0x10006);
static _DELPHI_CONST int BASS_CTYPE_STREAM_CA = int(0x10007);
static _DELPHI_CONST int BASS_CTYPE_STREAM_MF = int(0x10008);
static _DELPHI_CONST int BASS_CTYPE_STREAM_AM = int(0x10009);
static _DELPHI_CONST int BASS_CTYPE_STREAM_SAMPLE = int(0x1000a);
static _DELPHI_CONST int BASS_CTYPE_STREAM_DUMMY = int(0x18000);
static _DELPHI_CONST int BASS_CTYPE_STREAM_DEVICE = int(0x18001);
static _DELPHI_CONST int BASS_CTYPE_STREAM_WAV = int(0x40000);
static _DELPHI_CONST int BASS_CTYPE_STREAM_WAV_PCM = int(0x50001);
static _DELPHI_CONST int BASS_CTYPE_STREAM_WAV_FLOAT = int(0x50003);
static _DELPHI_CONST int BASS_CTYPE_MUSIC_MOD = int(0x20000);
static _DELPHI_CONST int BASS_CTYPE_MUSIC_MTM = int(0x20001);
static _DELPHI_CONST int BASS_CTYPE_MUSIC_S3M = int(0x20002);
static _DELPHI_CONST int BASS_CTYPE_MUSIC_XM = int(0x20003);
static _DELPHI_CONST int BASS_CTYPE_MUSIC_IT = int(0x20004);
static _DELPHI_CONST System::Word BASS_CTYPE_MUSIC_MO3 = System::Word(0x100);
static _DELPHI_CONST System::Int8 BASS_PLUGIN_PROC = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_3DMODE_NORMAL = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_3DMODE_RELATIVE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_3DMODE_OFF = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_3DALG_DEFAULT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_3DALG_OFF = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_3DALG_FULL = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_3DALG_LIGHT = System::Int8(0x3);
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
static _DELPHI_CONST unsigned BASS_STREAMPROC_END = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 STREAMFILE_NOBUFFER = System::Int8(0x0);
static _DELPHI_CONST System::Int8 STREAMFILE_BUFFER = System::Int8(0x1);
static _DELPHI_CONST System::Int8 STREAMFILE_BUFFERPUSH = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_FILEDATA_END = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_CURRENT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_DECODE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_DOWNLOAD = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_END = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_START = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_CONNECTED = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_BUFFER = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_SOCKET = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_ASYNCBUF = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_SIZE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_BUFFERING = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_FILEPOS_AVAILABLE = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_SYNC_POS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_SYNC_END = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_SYNC_META = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_SYNC_SLIDE = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_SYNC_STALL = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_SYNC_DOWNLOAD = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_SYNC_FREE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_SYNC_SETPOS = System::Int8(0xb);
static _DELPHI_CONST System::Int8 BASS_SYNC_MUSICPOS = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_SYNC_MUSICINST = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_SYNC_MUSICFX = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_SYNC_OGG_CHANGE = System::Int8(0xc);
static _DELPHI_CONST System::Int8 BASS_SYNC_DEV_FAIL = System::Int8(0xe);
static _DELPHI_CONST System::Int8 BASS_SYNC_DEV_FORMAT = System::Int8(0xf);
static _DELPHI_CONST int BASS_SYNC_THREAD = int(0x20000000);
static _DELPHI_CONST int BASS_SYNC_MIXTIME = int(0x40000000);
static _DELPHI_CONST unsigned BASS_SYNC_ONETIME = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 BASS_ACTIVE_STOPPED = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_ACTIVE_PLAYING = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_ACTIVE_STALLED = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_ACTIVE_PAUSED = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_ACTIVE_PAUSED_DEVICE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_FREQ = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_VOL = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_PAN = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_EAXMIX = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_NOBUFFER = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_VBR = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_CPU = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_SRC = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_NET_RESUME = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_SCANINFO = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_NORAMP = System::Int8(0xb);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_BITRATE = System::Int8(0xc);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_BUFFER = System::Int8(0xd);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_GRANULE = System::Int8(0xe);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_USER = System::Int8(0xf);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_TAIL = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_PUSH_LIMIT = System::Int8(0x11);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_DOWNLOADPROC = System::Int8(0x12);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_VOLDSP = System::Int8(0x13);
static _DELPHI_CONST System::Int8 BASS_ATTRIB_VOLDSP_PRIORITY = System::Int8(0x14);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_AMPLIFY = System::Word(0x100);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_PANSEP = System::Word(0x101);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_PSCALER = System::Word(0x102);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_BPM = System::Word(0x103);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_SPEED = System::Word(0x104);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_VOL_GLOBAL = System::Word(0x105);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_ACTIVE = System::Word(0x106);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_VOL_CHAN = System::Word(0x200);
static _DELPHI_CONST System::Word BASS_ATTRIB_MUSIC_VOL_INST = System::Word(0x300);
static _DELPHI_CONST int BASS_SLIDE_LOG = int(0x1000000);
static _DELPHI_CONST System::Int8 BASS_DATA_AVAILABLE = System::Int8(0x0);
static _DELPHI_CONST int BASS_DATA_NOREMOVE = int(0x10000000);
static _DELPHI_CONST int BASS_DATA_FIXED = int(0x20000000);
static _DELPHI_CONST int BASS_DATA_FLOAT = int(0x40000000);
static _DELPHI_CONST unsigned BASS_DATA_FFT256 = unsigned(0x80000000);
static _DELPHI_CONST unsigned BASS_DATA_FFT512 = unsigned(0x80000001);
static _DELPHI_CONST unsigned BASS_DATA_FFT1024 = unsigned(0x80000002);
static _DELPHI_CONST unsigned BASS_DATA_FFT2048 = unsigned(0x80000003);
static _DELPHI_CONST unsigned BASS_DATA_FFT4096 = unsigned(0x80000004);
static _DELPHI_CONST unsigned BASS_DATA_FFT8192 = unsigned(0x80000005);
static _DELPHI_CONST unsigned BASS_DATA_FFT16384 = unsigned(0x80000006);
static _DELPHI_CONST unsigned BASS_DATA_FFT32768 = unsigned(0x80000007);
static _DELPHI_CONST System::Int8 BASS_DATA_FFT_INDIVIDUAL = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_DATA_FFT_NOWINDOW = System::Int8(0x20);
static _DELPHI_CONST System::Int8 BASS_DATA_FFT_REMOVEDC = System::Int8(0x40);
static _DELPHI_CONST System::Byte BASS_DATA_FFT_COMPLEX = System::Byte(0x80);
static _DELPHI_CONST System::Word BASS_DATA_FFT_NYQUIST = System::Word(0x100);
static _DELPHI_CONST System::Int8 BASS_LEVEL_MONO = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_LEVEL_STEREO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_LEVEL_RMS = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_LEVEL_VOLPAN = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_LEVEL_NOREMOVE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_TAG_ID3 = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_TAG_ID3V2 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_TAG_OGG = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_TAG_HTTP = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_TAG_ICY = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_TAG_META = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_TAG_APE = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_TAG_MP4 = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_TAG_WMA = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_TAG_VENDOR = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_TAG_LYRICS3 = System::Int8(0xa);
static _DELPHI_CONST System::Int8 BASS_TAG_CA_CODEC = System::Int8(0xb);
static _DELPHI_CONST System::Int8 BASS_TAG_MF = System::Int8(0xd);
static _DELPHI_CONST System::Int8 BASS_TAG_WAVEFORMAT = System::Int8(0xe);
static _DELPHI_CONST System::Int8 BASS_TAG_AM_NAME = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_TAG_ID3V2_2 = System::Int8(0x11);
static _DELPHI_CONST System::Int8 BASS_TAG_AM_MIME = System::Int8(0x12);
static _DELPHI_CONST System::Int8 BASS_TAG_LOCATION = System::Int8(0x13);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_INFO = System::Word(0x100);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_BEXT = System::Word(0x101);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_CART = System::Word(0x102);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_DISP = System::Word(0x103);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_CUE = System::Word(0x104);
static _DELPHI_CONST System::Word BASS_TAG_RIFF_SMPL = System::Word(0x105);
static _DELPHI_CONST System::Word BASS_TAG_APE_BINARY = System::Word(0x1000);
static _DELPHI_CONST int BASS_TAG_MUSIC_NAME = int(0x10000);
static _DELPHI_CONST int BASS_TAG_MUSIC_MESSAGE = int(0x10001);
static _DELPHI_CONST int BASS_TAG_MUSIC_ORDERS = int(0x10002);
static _DELPHI_CONST int BASS_TAG_MUSIC_AUTH = int(0x10003);
static _DELPHI_CONST int BASS_TAG_MUSIC_INST = int(0x10100);
static _DELPHI_CONST int BASS_TAG_MUSIC_CHAN = int(0x10200);
static _DELPHI_CONST int BASS_TAG_MUSIC_SAMPLE = int(0x10300);
static _DELPHI_CONST System::Int8 BASS_POS_BYTE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_POS_MUSIC_ORDER = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_POS_OGG = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_POS_END = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BASS_POS_LOOP = System::Int8(0x11);
static _DELPHI_CONST int BASS_POS_FLUSH = int(0x1000000);
static _DELPHI_CONST int BASS_POS_RESET = int(0x2000000);
static _DELPHI_CONST int BASS_POS_RELATIVE = int(0x4000000);
static _DELPHI_CONST int BASS_POS_INEXACT = int(0x8000000);
static _DELPHI_CONST int BASS_POS_DECODE = int(0x10000000);
static _DELPHI_CONST int BASS_POS_DECODETO = int(0x20000000);
static _DELPHI_CONST int BASS_POS_SCAN = int(0x40000000);
static _DELPHI_CONST int BASS_NODEVICE = int(0x20000);
static _DELPHI_CONST int BASS_INPUT_OFF = int(0x10000);
static _DELPHI_CONST int BASS_INPUT_ON = int(0x20000);
static _DELPHI_CONST unsigned BASS_INPUT_TYPE_MASK = unsigned(0xff000000);
static _DELPHI_CONST System::Int8 BASS_INPUT_TYPE_UNDEF = System::Int8(0x0);
static _DELPHI_CONST int BASS_INPUT_TYPE_DIGITAL = int(0x1000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_LINE = int(0x2000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_MIC = int(0x3000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_SYNTH = int(0x4000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_CD = int(0x5000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_PHONE = int(0x6000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_SPEAKER = int(0x7000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_WAVE = int(0x8000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_AUX = int(0x9000000);
static _DELPHI_CONST int BASS_INPUT_TYPE_ANALOG = int(0xa000000);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_CHORUS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_COMPRESSOR = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_DISTORTION = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_ECHO = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_FLANGER = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_GARGLE = System::Int8(0x5);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_I3DL2REVERB = System::Int8(0x6);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_PARAMEQ = System::Int8(0x7);
static _DELPHI_CONST System::Int8 BASS_FX_DX8_REVERB = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BASS_FX_VOLUME = System::Int8(0x9);
static _DELPHI_CONST System::Int8 BASS_DX8_PHASE_NEG_180 = System::Int8(0x0);
static _DELPHI_CONST System::Int8 BASS_DX8_PHASE_NEG_90 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BASS_DX8_PHASE_ZERO = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BASS_DX8_PHASE_90 = System::Int8(0x3);
static _DELPHI_CONST System::Int8 BASS_DX8_PHASE_180 = System::Int8(0x4);
#define STREAMPROC_DUMMY (void *)(0)
#define STREAMPROC_PUSH (void *)(0xffffffff)
#define STREAMPROC_DEVICE (void *)(0xfffffffe)
#define STREAMPROC_DEVICE_3D (void *)(0xfffffffd)
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SetConfig)(DWORD option, DWORD value);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_GetConfig)(DWORD option);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SetConfigPtr)(DWORD option, void * value);
extern DELPHI_PACKAGE void * __stdcall (*BASS_GetConfigPtr)(DWORD option);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_GetVersion)(void);
extern DELPHI_PACKAGE int __stdcall (*BASS_ErrorGetCode)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_GetDeviceInfo)(DWORD device, BASS_DEVICEINFO &info);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Init)(System::LongInt device, DWORD freq, DWORD flags, HWND win, System::PGUID clsid);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SetDevice)(DWORD device);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_GetDevice)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Free)(void);
extern DELPHI_PACKAGE void * __stdcall (*BASS_GetDSoundObject)(DWORD obj);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_GetInfo)(BASS_INFO &info);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Update)(DWORD length);
extern DELPHI_PACKAGE float __stdcall (*BASS_GetCPU)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Start)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Stop)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Pause)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SetVolume)(float volume);
extern DELPHI_PACKAGE float __stdcall (*BASS_GetVolume)(void);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_PluginLoad)(System::WideChar * filename, DWORD flags);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_PluginFree)(HPLUGIN handle);
extern DELPHI_PACKAGE PBASS_PLUGININFO __stdcall (*BASS_PluginGetInfo)(HPLUGIN handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Set3DFactors)(float distf, float rollf, float doppf);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Get3DFactors)(float &distf, float &rollf, float &doppf);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Set3DPosition)(BASS_3DVECTOR &pos, BASS_3DVECTOR &vel, BASS_3DVECTOR &front, BASS_3DVECTOR &top);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_Get3DPosition)(BASS_3DVECTOR &pos, BASS_3DVECTOR &vel, BASS_3DVECTOR &front, BASS_3DVECTOR &top);
extern DELPHI_PACKAGE void __stdcall (*BASS_Apply3D)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SetEAXParameters)(System::LongInt env, float vol, float decay, float damp);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_GetEAXParameters)(DWORD &env, float &vol, float &decay, float &damp);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_MusicLoad)(BOOL mem, void * f, QWORD offset, DWORD length, DWORD flags, DWORD freq);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_MusicFree)(HMUSIC handle);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_SampleLoad)(BOOL mem, void * f, QWORD offset, DWORD length, DWORD max, DWORD flags);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_SampleCreate)(DWORD length, DWORD freq, DWORD chans, DWORD max, DWORD flags);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleFree)(HSAMPLE handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleSetData)(HSAMPLE handle, void * buffer);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleGetData)(HSAMPLE handle, void * buffer);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleGetInfo)(HSAMPLE handle, BASS_SAMPLE &info);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleSetInfo)(HSAMPLE handle, BASS_SAMPLE &info);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_SampleGetChannel)(HSAMPLE handle, BOOL onlynew);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_SampleGetChannels)(HSAMPLE handle, void * channels);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_SampleStop)(HSAMPLE handle);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamCreate)(DWORD freq, DWORD chans, DWORD flags, STREAMPROC proc, void * user);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamCreateFile)(BOOL mem, void * f, QWORD offset, QWORD length, DWORD flags);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamCreateURL)(char * url, DWORD offset, DWORD flags, DOWNLOADPROC proc, void * user);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamCreateFileUser)(DWORD system, DWORD flags, BASS_FILEPROCS &procs, void * user);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_StreamFree)(HSTREAM handle);
extern DELPHI_PACKAGE __int64 __stdcall (*BASS_StreamGetFilePosition)(HSTREAM handle, DWORD mode);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamPutData)(HSTREAM handle, void * buffer, DWORD length);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_StreamPutFileData)(HSTREAM handle, void * buffer, DWORD length);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordGetDeviceInfo)(DWORD device, BASS_DEVICEINFO &info);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordInit)(System::LongInt device);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordSetDevice)(DWORD device);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_RecordGetDevice)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordFree)(void);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordGetInfo)(BASS_RECORDINFO &info);
extern DELPHI_PACKAGE char * __stdcall (*BASS_RecordGetInputName)(System::LongInt input);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_RecordSetInput)(System::LongInt input, DWORD flags, float volume);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_RecordGetInput)(System::LongInt input, float &volume);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_RecordStart)(DWORD freq, DWORD chans, DWORD flags, RECORDPROC proc, void * user);
extern DELPHI_PACKAGE double __stdcall (*BASS_ChannelBytes2Seconds)(DWORD handle, QWORD pos);
extern DELPHI_PACKAGE __int64 __stdcall (*BASS_ChannelSeconds2Bytes)(DWORD handle, double pos);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelGetDevice)(DWORD handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSetDevice)(DWORD handle, DWORD device);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelIsActive)(DWORD handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelGetInfo)(DWORD handle, BASS_CHANNELINFO &info);
extern DELPHI_PACKAGE char * __stdcall (*BASS_ChannelGetTags)(HSTREAM handle, DWORD tags);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelFlags)(DWORD handle, DWORD flags, DWORD mask);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelUpdate)(DWORD handle, DWORD length);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelLock)(DWORD handle, BOOL lock);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelPlay)(DWORD handle, BOOL restart);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelStop)(DWORD handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelPause)(DWORD handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSetAttribute)(DWORD handle, DWORD attrib, float value);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelGetAttribute)(DWORD handle, DWORD attrib, float &value);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSlideAttribute)(DWORD handle, DWORD attrib, float value, DWORD time);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelIsSliding)(DWORD handle, DWORD attrib);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSetAttributeEx)(DWORD handle, DWORD attrib, void * value, DWORD size);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelGetAttributeEx)(DWORD handle, DWORD attrib, void * value, DWORD size);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSet3DAttributes)(DWORD handle, System::LongInt mode, float min, float max, System::LongInt iangle, System::LongInt oangle, System::LongInt outvol);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelGet3DAttributes)(DWORD handle, DWORD &mode, float &min, float &max, DWORD &iangle, DWORD &oangle, DWORD &outvol);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSet3DPosition)(DWORD handle, BASS_3DVECTOR &pos, BASS_3DVECTOR &orient, BASS_3DVECTOR &vel);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelGet3DPosition)(DWORD handle, BASS_3DVECTOR &pos, BASS_3DVECTOR &orient, BASS_3DVECTOR &vel);
extern DELPHI_PACKAGE __int64 __stdcall (*BASS_ChannelGetLength)(DWORD handle, DWORD mode);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSetPosition)(DWORD handle, QWORD pos, DWORD mode);
extern DELPHI_PACKAGE __int64 __stdcall (*BASS_ChannelGetPosition)(DWORD handle, DWORD mode);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelGetLevel)(DWORD handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelGetLevelEx)(DWORD handle, Winapi::Windows::PSingle levels, float length, DWORD flags);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelGetData)(DWORD handle, void * buffer, DWORD length);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelSetSync)(DWORD handle, DWORD type_, QWORD param, SYNCPROC proc, void * user);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelRemoveSync)(DWORD handle, HSYNC sync);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelSetDSP)(DWORD handle, DSPPROC proc, void * user, System::LongInt priority);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelRemoveDSP)(DWORD handle, HDSP dsp);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelSetLink)(DWORD handle, DWORD chan);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelRemoveLink)(DWORD handle, DWORD chan);
extern DELPHI_PACKAGE unsigned __stdcall (*BASS_ChannelSetFX)(DWORD handle, DWORD type_, System::LongInt priority);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_ChannelRemoveFX)(DWORD handle, HFX fx);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_FXSetParameters)(HFX handle, void * par);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_FXGetParameters)(HFX handle, void * par);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_FXReset)(HFX handle);
extern DELPHI_PACKAGE System::LongBool __stdcall (*BASS_FXSetPriority)(HFX handle, System::LongInt priority);
extern DELPHI_PACKAGE DWORD __fastcall BASS_SPEAKER_N(DWORD n);
extern DELPHI_PACKAGE BOOL __fastcall BASS_SetEAXPreset(System::LongInt env);
extern DELPHI_PACKAGE bool __fastcall BASS_Load(System::WideChar * LibName);
extern DELPHI_PACKAGE void __fastcall BASS_UnLoad(void);
extern DELPHI_PACKAGE bool __fastcall BASS_IsLoaded(void);
}	/* namespace Import */
}	/* namespace Bass */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_BASS_IMPORT)
using namespace Bass::Import;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_BASS)
using namespace Bass;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BASS_ImportHPP
