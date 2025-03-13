// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.AsyncHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_AsyncHDSHPP
#define GXS_AsyncHDSHPP

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
#include <GXS.HeightData.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Asynchds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxAsyncHDS;
class DELPHICLASS TgxAsyncHDThread;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIdleEvent)(TgxAsyncHDS* Sender, bool TilesUpdated);

typedef void __fastcall (__closure *TNewTilePreparedEvent)(TgxAsyncHDS* Sender, Gxs::Heightdata::TgxHeightData* HeightData);

enum DECLSPEC_DENUM TUseDirtyTiles : unsigned char { dtNever, dtUntilReplaced, dtUntilAllReplaced };

class PASCALIMPLEMENTATION TgxAsyncHDS : public Gxs::Heightdata::TgxHeightDataSourceFilter
{
	typedef Gxs::Heightdata::TgxHeightDataSourceFilter inherited;
	
private:
	TIdleEvent FOnIdleEvent;
	TNewTilePreparedEvent FOnNewTilePrepared;
	TUseDirtyTiles FUseDirtyTiles;
	bool FTilesUpdated;
	
public:
	__fastcall virtual TgxAsyncHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxAsyncHDS();
	virtual void __fastcall BeforePreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual void __fastcall ThreadIsIdle();
	void __fastcall NewTilePrepared(Gxs::Heightdata::TgxHeightData* HeightData);
	int __fastcall ThreadCount();
	void __fastcall WaitFor(int TimeOut = 0x7d0);
	bool __fastcall TilesUpdated();
	void __fastcall TilesUpdatedFlagReset();
	
__published:
	__property TIdleEvent OnIdle = {read=FOnIdleEvent, write=FOnIdleEvent};
	__property TNewTilePreparedEvent OnNewTilePrepared = {read=FOnNewTilePrepared, write=FOnNewTilePrepared};
	__property TUseDirtyTiles UseDirtyTiles = {read=FUseDirtyTiles, write=FUseDirtyTiles, nodefault};
	__property MaxThreads;
	__property Active;
};


class PASCALIMPLEMENTATION TgxAsyncHDThread : public Gxs::Heightdata::TgxHeightDataThread
{
	typedef Gxs::Heightdata::TgxHeightDataThread inherited;
	
public:
	TgxAsyncHDS* Owner;
	Gxs::Heightdata::TgxHeightDataSource* HDS;
	virtual void __fastcall Execute();
	void __fastcall Sync();
public:
	/* TgxHeightDataThread.Destroy */ inline __fastcall virtual ~TgxAsyncHDThread() { }
	
public:
	/* TThread.Create */ inline __fastcall TgxAsyncHDThread()/* overload */ : Gxs::Heightdata::TgxHeightDataThread() { }
	/* TThread.Create */ inline __fastcall TgxAsyncHDThread(bool CreateSuspended)/* overload */ : Gxs::Heightdata::TgxHeightDataThread(CreateSuspended) { }
	/* TThread.Create */ inline __fastcall TgxAsyncHDThread(bool CreateSuspended, System::NativeUInt ReservedStackSize)/* overload */ : Gxs::Heightdata::TgxHeightDataThread(CreateSuspended, ReservedStackSize) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Asynchds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ASYNCHDS)
using namespace Gxs::Asynchds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_AsyncHDSHPP
