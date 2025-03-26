// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.HeightData.pas' rev: 36.00 (Windows)

#ifndef GXS_HeightDataHPP
#define GXS_HeightDataHPP

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
#include <FMX.Objects.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Material.hpp>
#include <System.Types.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Heightdata
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxHeightDataSource;
struct TgxHeightDataUser;
class DELPHICLASS TgxHeightData;
class DELPHICLASS TgxHeightDataThread;
class DELPHICLASS TgxBitmapHDS;
class DELPHICLASS TgxCustomHDS;
class DELPHICLASS TgxTerrainBaseHDS;
class DELPHICLASS TgxHeightDataSourceFilter;
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Byte, 1073741824> TByteArray;

typedef System::StaticArray<Stage::Vectorgeometry::PByteVector, 134217728> TByteRaster;

typedef TByteRaster *PByteRaster;

typedef System::StaticArray<short, 536870912> TSmallintArray;

typedef TSmallintArray *PSmallIntArray;

typedef System::StaticArray<PSmallIntArray, 134217728> TSmallIntRaster;

typedef TSmallIntRaster *PSmallIntRaster;

typedef System::StaticArray<Stage::Vectorgeometry::PFloatVector, 134217728> TSingleRaster;

typedef TSingleRaster *PSingleRaster;

_DECLARE_METACLASS(System::TMetaClass, TgxHeightDataClass);

enum DECLSPEC_DENUM TgxHeightDataType : unsigned char { hdtByte, hdtSmallInt, hdtSingle, hdtDefault };

class PASCALIMPLEMENTATION TgxHeightDataSource : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TThreadList* FData;
	System::StaticArray<System::Classes::TList*, 256> FDataHash;
	System::Classes::TThread* FThread;
	int FMaxThreads;
	int FMaxPoolSize;
	TgxHeightDataClass FHeightDataClass;
	float FDefaultHeight;
	
protected:
	void __fastcall SetMaxThreads(const int Val);
	int __fastcall HashKey(int XLeft, int YTop);
	__property TgxHeightDataClass HeightDataClass = {read=FHeightDataClass, write=FHeightDataClass};
	TgxHeightData* __fastcall FindMatchInList(int XLeft, int YTop, int size, TgxHeightDataType DataType);
	
public:
	__fastcall virtual TgxHeightDataSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHeightDataSource();
	__property System::Classes::TThreadList* Data = {read=FData};
	void __fastcall Clear();
	void __fastcall CleanUp();
	virtual TgxHeightData* __fastcall GetData(int XLeft, int YTop, int size, TgxHeightDataType DataType);
	virtual TgxHeightData* __fastcall PreLoad(int XLeft, int YTop, int size, TgxHeightDataType DataType);
	void __fastcall PreloadReplacement(TgxHeightData* aHeightData);
	virtual void __fastcall Release(TgxHeightData* aHeightData);
	virtual void __fastcall MarkDirty(const Winapi::Windows::TRect &Area)/* overload */;
	void __fastcall MarkDirty(int XLeft, int YTop, int xRight, int yBottom)/* overload */;
	void __fastcall MarkDirty()/* overload */;
	__property int MaxThreads = {read=FMaxThreads, write=SetMaxThreads, nodefault};
	__property int MaxPoolSize = {read=FMaxPoolSize, write=FMaxPoolSize, nodefault};
	__property float DefaultHeight = {read=FDefaultHeight, write=FDefaultHeight};
	virtual float __fastcall InterpolatedHeight(float x, float y, int tileSize);
	virtual int __fastcall Width() = 0 ;
	virtual int __fastcall Height() = 0 ;
	virtual void __fastcall ThreadIsIdle();
	virtual void __fastcall BeforePreparingData(TgxHeightData* HeightData);
	virtual void __fastcall StartPreparingData(TgxHeightData* HeightData);
	virtual void __fastcall AfterPreparingData(TgxHeightData* HeightData);
	void __fastcall TextureCoordinates(TgxHeightData* HeightData, bool Stretch = false);
};


enum DECLSPEC_DENUM THDTextureCoordinatesMode : unsigned char { tcmWorld, tcmLocal };

enum DECLSPEC_DENUM TgxHeightDataState : unsigned char { hdsQueued, hdsPreparing, hdsReady, hdsNone };

typedef void __fastcall (__closure *TOnHeightDataDirtyEvent)(TgxHeightData* sender);

struct DECLSPEC_DRECORD TgxHeightDataUser
{
public:
	System::TObject* user;
	TOnHeightDataDirtyEvent event;
};


class PASCALIMPLEMENTATION TgxHeightData : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
	
private:
	typedef System::DynamicArray<TgxHeightDataUser> _TgxHeightData__1;
	
	
private:
	_TgxHeightData__1 FUsers;
	TgxHeightDataSource* FOwner;
	TgxHeightDataState FDataState;
	int FSize;
	int FXLeft;
	int FYTop;
	int FUseCounter;
	TgxHeightDataType FDataType;
	int FDataSize;
	Stage::Vectorgeometry::PByteArray FByteData;
	PByteRaster FByteRaster;
	PSmallIntArray FSmallIntData;
	PSmallIntRaster FSmallIntRaster;
	Stage::Vectorgeometry::PSingleArray FSingleData;
	PSingleRaster FSingleRaster;
	THDTextureCoordinatesMode FTextureCoordinatesMode;
	Stage::Vectorgeometry::TTexPoint FTCOffset;
	Stage::Vectorgeometry::TTexPoint FTCScale;
	System::UnicodeString FMaterialName;
	Gxs::Material::TgxLibMaterial* FLibMaterial;
	System::TObject* FObjectTag;
	int FTag;
	int FTag2;
	System::Classes::TNotifyEvent FOnDestroy;
	bool FDirty;
	float FHeightMin;
	float FHeightMax;
	void __fastcall BuildByteRaster();
	void __fastcall BuildSmallIntRaster();
	void __fastcall BuildSingleRaster();
	void __fastcall ConvertByteToSmallInt();
	void __fastcall ConvertByteToSingle();
	void __fastcall ConvertSmallIntToByte();
	void __fastcall ConvertSmallIntToSingle();
	void __fastcall ConvertSingleToByte();
	void __fastcall ConvertSingleToSmallInt();
	
protected:
	TgxHeightDataThread* FThread;
	void __fastcall SetDataType(const TgxHeightDataType Val);
	void __fastcall SetMaterialName(const System::UnicodeString MaterialName);
	void __fastcall SetLibMaterial(Gxs::Material::TgxLibMaterial* LibMaterial);
	float __fastcall GetHeightMin();
	float __fastcall GetHeightMax();
	
public:
	TgxHeightData* OldVersion;
	TgxHeightData* NewVersion;
	bool DontUse;
	__fastcall virtual TgxHeightData(TgxHeightDataSource* AOwner, int aXLeft, int aYTop, int aSize, TgxHeightDataType aDataType);
	__fastcall virtual ~TgxHeightData();
	__property TgxHeightDataSource* Owner = {read=FOwner};
	__property System::Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property int UseCounter = {read=FUseCounter, nodefault};
	void __fastcall RegisterUse();
	virtual void __fastcall Allocate(const TgxHeightDataType Val);
	void __fastcall Release();
	void __fastcall MarkDirty();
	__property int XLeft = {read=FXLeft, nodefault};
	__property int YTop = {read=FYTop, nodefault};
	__property TgxHeightDataType DataType = {read=FDataType, write=SetDataType, nodefault};
	__property TgxHeightDataState DataState = {read=FDataState, write=FDataState, nodefault};
	__property int Size = {read=FSize, nodefault};
	__property bool Dirty = {read=FDirty, write=FDirty, nodefault};
	__property int DataSize = {read=FDataSize, nodefault};
	__property Stage::Vectorgeometry::PByteArray ByteData = {read=FByteData};
	__property PByteRaster ByteRaster = {read=FByteRaster};
	__property PSmallIntArray SmallIntData = {read=FSmallIntData};
	__property PSmallIntRaster SmallIntRaster = {read=FSmallIntRaster};
	__property Stage::Vectorgeometry::PSingleArray SingleData = {read=FSingleData};
	__property PSingleRaster SingleRaster = {read=FSingleRaster};
	__property System::UnicodeString MaterialName = {read=FMaterialName, write=SetMaterialName};
	__property Gxs::Material::TgxLibMaterial* LibMaterial = {read=FLibMaterial, write=SetLibMaterial};
	__property THDTextureCoordinatesMode TextureCoordinatesMode = {read=FTextureCoordinatesMode, write=FTextureCoordinatesMode, nodefault};
	__property Stage::Vectorgeometry::TTexPoint TextureCoordinatesOffset = {read=FTCOffset, write=FTCOffset};
	__property Stage::Vectorgeometry::TTexPoint TextureCoordinatesScale = {read=FTCScale, write=FTCScale};
	System::Byte __fastcall ByteHeight(int x, int y);
	short __fastcall SmallIntHeight(int x, int y);
	float __fastcall SingleHeight(int x, int y);
	float __fastcall InterpolatedHeight(float x, float y);
	__property float HeightMin = {read=GetHeightMin, write=FHeightMin};
	__property float HeightMax = {read=GetHeightMax, write=FHeightMax};
	float __fastcall Height(int x, int y);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall Normal(int x, int y, const Stage::Vectorgeometry::TAffineVector &scale);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall NormalAtNode(int x, int y, const Stage::Vectorgeometry::TAffineVector &scale);
	bool __fastcall OverlapsArea(const Winapi::Windows::TRect &Area);
	__property System::TObject* ObjectTag = {read=FObjectTag, write=FObjectTag};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property int Tag2 = {read=FTag2, write=FTag2, nodefault};
	__property TgxHeightDataThread* Thread = {read=FThread, write=FThread};
};


class PASCALIMPLEMENTATION TgxHeightDataThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
protected:
	TgxHeightData* FHeightData;
	
public:
	__fastcall virtual ~TgxHeightDataThread();
	__property TgxHeightData* HeightData = {read=FHeightData, write=FHeightData};
public:
	/* TThread.Create */ inline __fastcall TgxHeightDataThread()/* overload */ : System::Classes::TThread() { }
	/* TThread.Create */ inline __fastcall TgxHeightDataThread(bool CreateSuspended)/* overload */ : System::Classes::TThread(CreateSuspended) { }
	/* TThread.Create */ inline __fastcall TgxHeightDataThread(bool CreateSuspended, System::NativeUInt ReservedStackSize)/* overload */ : System::Classes::TThread(CreateSuspended, ReservedStackSize) { }
	
};


class PASCALIMPLEMENTATION TgxBitmapHDS : public TgxHeightDataSource
{
	typedef TgxHeightDataSource inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectorgeometry::PByteVector> _TgxBitmapHDS__1;
	
	
private:
	_TgxBitmapHDS__1 FScanLineCache;
	Fmx::Graphics::TBitmap* FBitmap;
	Fmx::Objects::TImage* FPicture;
	bool FInfiniteWrap;
	bool FInverted;
	
protected:
	void __fastcall SetPicture(Fmx::Objects::TImage* const Val);
	void __fastcall OnPictureChanged(System::TObject* sender);
	void __fastcall SetInfiniteWrap(bool Val);
	void __fastcall SetInverted(bool Val);
	void __fastcall CreateMonochromeBitmap(int size);
	void __fastcall FreeMonochromeBitmap();
	Stage::Vectorgeometry::PByteArray __fastcall GetScanLine(int y);
	
public:
	__fastcall virtual TgxBitmapHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBitmapHDS();
	virtual void __fastcall StartPreparingData(TgxHeightData* HeightData);
	virtual void __fastcall MarkDirty(const Winapi::Windows::TRect &Area)/* overload */;
	virtual int __fastcall Width();
	virtual int __fastcall Height();
	
__published:
	__property Fmx::Objects::TImage* Picture = {read=FPicture, write=SetPicture};
	__property bool InfiniteWrap = {read=FInfiniteWrap, write=SetInfiniteWrap, default=1};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=1};
	__property MaxPoolSize;
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  MarkDirty(int XLeft, int YTop, int xRight, int yBottom){ TgxHeightDataSource::MarkDirty(XLeft, YTop, xRight, yBottom); }
	inline void __fastcall  MarkDirty(){ TgxHeightDataSource::MarkDirty(); }
	
};


typedef void __fastcall (__closure *TStartPreparingDataEvent)(TgxHeightData* HeightData);

typedef void __fastcall (__closure *TMarkDirtyEvent)(const Winapi::Windows::TRect &Area);

class PASCALIMPLEMENTATION TgxCustomHDS : public TgxHeightDataSource
{
	typedef TgxHeightDataSource inherited;
	
private:
	TStartPreparingDataEvent FOnStartPreparingData;
	TMarkDirtyEvent FOnMarkDirty;
	
public:
	__fastcall virtual TgxCustomHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomHDS();
	virtual void __fastcall StartPreparingData(TgxHeightData* HeightData);
	virtual void __fastcall MarkDirty(const Winapi::Windows::TRect &Area)/* overload */;
	
__published:
	__property MaxPoolSize;
	__property TStartPreparingDataEvent OnStartPreparingData = {read=FOnStartPreparingData, write=FOnStartPreparingData};
	__property TMarkDirtyEvent OnMarkDirtyEvent = {read=FOnMarkDirty, write=FOnMarkDirty};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  MarkDirty(int XLeft, int YTop, int xRight, int yBottom){ TgxHeightDataSource::MarkDirty(XLeft, YTop, xRight, yBottom); }
	inline void __fastcall  MarkDirty(){ TgxHeightDataSource::MarkDirty(); }
	
};


class PASCALIMPLEMENTATION TgxTerrainBaseHDS : public TgxHeightDataSource
{
	typedef TgxHeightDataSource inherited;
	
public:
	__fastcall virtual TgxTerrainBaseHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTerrainBaseHDS();
	virtual void __fastcall StartPreparingData(TgxHeightData* HeightData);
	
__published:
	__property MaxPoolSize;
};


typedef void __fastcall (__closure *TSourceDataFetchedEvent)(TgxHeightDataSourceFilter* sender, TgxHeightData* HeightData);

class PASCALIMPLEMENTATION TgxHeightDataSourceFilter : public TgxHeightDataSource
{
	typedef TgxHeightDataSource inherited;
	
private:
	TgxHeightDataSource* FHDS;
	TSourceDataFetchedEvent FOnSourceDataFetched;
	bool FActive;
	
protected:
	virtual void __fastcall PreparingData(TgxHeightData* HeightData) = 0 ;
	void __fastcall SetHDS(TgxHeightDataSource* Val);
	
public:
	__fastcall virtual TgxHeightDataSourceFilter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHeightDataSourceFilter();
	virtual void __fastcall Release(TgxHeightData* aHeightData);
	virtual void __fastcall StartPreparingData(TgxHeightData* HeightData);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual int __fastcall Width();
	virtual int __fastcall Height();
	__property TSourceDataFetchedEvent OnSourceDataFetched = {read=FOnSourceDataFetched, write=FOnSourceDataFetched};
	
__published:
	__property MaxPoolSize;
	__property TgxHeightDataSource* HeightDataSource = {read=FHDS, write=SetHDS};
	__property bool Active = {read=FActive, write=FActive, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Heightdata */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_HEIGHTDATA)
using namespace Gxs::Heightdata;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_HeightDataHPP
