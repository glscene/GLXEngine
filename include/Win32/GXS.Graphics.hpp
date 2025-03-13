// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Graphics.pas' rev: 36.00 (Windows)

#ifndef GXS_GraphicsHPP
#define GXS_GraphicsHPP

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
#include <System.SyncObjs.hpp>
#include <System.UITypes.hpp>
#include <System.Math.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Types.hpp>
#include <FMX.Consts.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Strings.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Context.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Color.hpp>
#include <GXS.BaseClasses.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Graphics
{
//-- forward type declarations -----------------------------------------------
struct TgxPixel24;
struct TgxPixel32;
struct TgxImageLevelDesc;
class DELPHICLASS TgxBaseImage;
class DELPHICLASS TgxImage;
class DELPHICLASS TRasterFileFormat;
class DELPHICLASS TRasterFileFormatsList;
class DELPHICLASS EInvalidRasterFile;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxPixel24
{
public:
	System::Byte r;
	System::Byte g;
	System::Byte b;
};
#pragma pack(pop)


typedef TgxPixel24 *PgxPixel24;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxPixel32
{
public:
	System::Byte r;
	System::Byte g;
	System::Byte b;
	System::Byte a;
};
#pragma pack(pop)


typedef TgxPixel32 *PgxPixel32;

typedef System::StaticArray<TgxPixel32, 268435456> TgxPixel32Array;

typedef TgxPixel32Array *PgxPixel32Array;

enum DECLSPEC_DENUM TgxLODStreamingState : unsigned char { ssKeeping, ssLoading, ssLoaded, ssTransfered };

struct DECLSPEC_DRECORD TgxImageLevelDesc
{
public:
	int Width;
	int Height;
	int Depth;
	Gxs::Context::TgxUnpackPBOHandle* PBO;
	void *MapAddress;
	System::LongWord Offset;
	System::LongWord StreamOffset;
	System::LongWord Size;
	TgxLODStreamingState State;
};


typedef System::Int8 TgxImageLODRange;

typedef System::StaticArray<TgxImageLevelDesc, 16> TgxImagePiramid;

class PASCALIMPLEMENTATION TgxBaseImage : public Gxs::Applicationfileio::TgxDataFile
{
	typedef Gxs::Applicationfileio::TgxDataFile inherited;
	
private:
	System::Classes::TStream* FSourceStream;
	TgxImageLODRange FStreamLevel;
	Gxs::Context::TgxFinishTaskEvent* FFinishEvent;
	
protected:
	PgxPixel32Array fData;
	TgxImagePiramid FLOD;
	TgxImageLODRange fLevelCount;
	unsigned fColorFormat;
	Stage::Textureformat::TglInternalFormat fInternalFormat;
	unsigned fDataType;
	int fElementSize;
	bool fCubeMap;
	bool fTextureArray;
	virtual PgxPixel32Array __fastcall GetData();
	int __fastcall GetWidth();
	int __fastcall GetHeight();
	int __fastcall GetDepth();
	void * __fastcall GetLevelAddress(System::Byte ALevel)/* overload */;
	void * __fastcall GetLevelAddress(System::Byte ALevel, System::Byte AFace)/* overload */;
	int __fastcall GetLevelWidth(TgxImageLODRange ALOD);
	int __fastcall GetLevelHeight(TgxImageLODRange ALOD);
	int __fastcall GetLevelDepth(TgxImageLODRange ALOD);
	Gxs::Context::TgxUnpackPBOHandle* __fastcall GetLevelPBO(TgxImageLODRange ALOD);
	int __fastcall GetLevelOffset(TgxImageLODRange ALOD);
	int __fastcall GetLevelSizeInByte(TgxImageLODRange ALOD);
	TgxLODStreamingState __fastcall GetLevelStreamingState(TgxImageLODRange ALOD);
	void __fastcall SetLevelStreamingState(TgxImageLODRange ALOD, TgxLODStreamingState AState);
	void __fastcall SaveHeader();
	void __fastcall LoadHeader();
	void __fastcall StartStreaming();
	void __fastcall DoStreaming();
	
public:
	__fastcall virtual TgxBaseImage();
	__fastcall virtual ~TgxBaseImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	virtual void __fastcall RegisterAsOpenRXTexture(Gxs::Context::TgxTextureHandle* AHandle, bool aMipmapGen, System::NativeUInt aTexFormat, /* out */ int &texWidth, /* out */ int &texHeight, /* out */ int &texDepth);
	virtual bool __fastcall AssignFromTexture(Gxs::Context::TgxTextureHandle* AHandle, const bool CastToFormat, const Stage::Textureformat::TglInternalFormat intFormat = (Stage::Textureformat::TglInternalFormat)(0x1f), const System::NativeUInt colorFormat = (unsigned)(0x0), const System::NativeUInt dataType = (unsigned)(0x0));
	bool __fastcall ConvertCrossToCubeMap();
	bool __fastcall ConvertToVolume(const int col, const int row, const bool MakeArray);
	unsigned __fastcall DataSize();
	bool __fastcall IsEmpty();
	bool __fastcall IsCompressed();
	bool __fastcall IsVolume();
	void __fastcall Narrow();
	virtual void __fastcall GenerateMipmap(Gxs::Imageutils::TImageFilterFunction AFilter);
	virtual void __fastcall UnMipmap();
	__property PgxPixel32Array Data = {read=GetData};
	void __fastcall SetErrorImage();
	void __fastcall UpdateLevelsInfo();
	__property int LevelWidth[TgxImageLODRange ALOD] = {read=GetLevelWidth};
	__property int LevelHeight[TgxImageLODRange ALOD] = {read=GetLevelHeight};
	__property int LevelDepth[TgxImageLODRange ALOD] = {read=GetLevelDepth};
	__property Gxs::Context::TgxUnpackPBOHandle* LevelPixelBuffer[TgxImageLODRange ALOD] = {read=GetLevelPBO};
	__property int LevelOffset[TgxImageLODRange ALOD] = {read=GetLevelOffset};
	__property int LevelSizeInByte[TgxImageLODRange ALOD] = {read=GetLevelSizeInByte};
	__property TgxLODStreamingState LevelStreamingState[TgxImageLODRange ALOD] = {read=GetLevelStreamingState, write=SetLevelStreamingState};
	__property TgxImageLODRange LevelCount = {read=fLevelCount, nodefault};
	__property Stage::Textureformat::TglInternalFormat InternalFormat = {read=fInternalFormat, nodefault};
	__property unsigned ColorFormat = {read=fColorFormat, nodefault};
	__property unsigned DataType = {read=fDataType, nodefault};
	__property int ElementSize = {read=fElementSize, nodefault};
	__property bool CubeMap = {read=fCubeMap, nodefault};
	__property bool TextureArray = {read=fTextureArray, nodefault};
};


typedef System::TMetaClass* TgxBaseImageClass;

class PASCALIMPLEMENTATION TgxImage : public TgxBaseImage
{
	typedef TgxBaseImage inherited;
	
private:
	bool FVerticalReverseOnAssignFromBitmap;
	bool FBlank;
	unsigned fOldColorFormat;
	unsigned fOldDataType;
	void __fastcall DataConvertTask();
	
protected:
	void __fastcall SetWidth(int val);
	void __fastcall SetHeight(const int val);
	void __fastcall SetDepth(const int val);
	void __fastcall SetBlank(const bool Value);
	void __fastcall SetCubeMap(const bool val);
	void __fastcall SetArray(const bool val);
	PgxPixel32Array __fastcall GetScanLine(int index);
	void __fastcall AssignFrom24BitsBitmap(Fmx::Graphics::TBitmap* aBitmap);
	void __fastcall AssignFrom32BitsBitmap(Fmx::Graphics::TBitmap* aBitmap);
	void __fastcall AssignFromPngImage(Fmx::Graphics::TBitmapImage* aPngImage);
	
public:
	__fastcall virtual TgxImage();
	__fastcall virtual ~TgxImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AssignFromBitmap24WithoutRGBSwap(Fmx::Graphics::TBitmap* aBitmap);
	void __fastcall AssignFromTexture2D(unsigned textureHandle)/* overload */;
	void __fastcall AssignFromTexture2D(Gxs::Context::TgxTextureHandle* textureHandle)/* overload */;
	Fmx::Graphics::TBitmap* __fastcall Create32BitsBitmap();
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Depth = {read=GetDepth, write=SetDepth, nodefault};
	__property unsigned ColorFormat = {read=fColorFormat, nodefault};
	__property Stage::Textureformat::TglInternalFormat InternalFormat = {read=fInternalFormat, write=fInternalFormat, nodefault};
	__property unsigned DataType = {read=fDataType, nodefault};
	__property int ElementSize = {read=fElementSize, nodefault};
	__property bool CubeMap = {read=fCubeMap, write=SetCubeMap, nodefault};
	__property bool TextureArray = {read=fTextureArray, write=SetArray, nodefault};
	__property PgxPixel32Array ScanLine[int index] = {read=GetScanLine};
	__property bool VerticalReverseOnAssignFromBitmap = {read=FVerticalReverseOnAssignFromBitmap, write=FVerticalReverseOnAssignFromBitmap, nodefault};
	__property bool Blank = {read=FBlank, write=SetBlank, nodefault};
	void __fastcall SetColorFormatDataType(const unsigned AColorFormat, const unsigned ADataType);
	void __fastcall SetAlphaFromIntensity();
	void __fastcall SetAlphaTransparentForColor(const System::Uitypes::TColor aColor)/* overload */;
	void __fastcall SetAlphaTransparentForColor(const TgxPixel32 aColor)/* overload */;
	void __fastcall SetAlphaTransparentForColor(const TgxPixel24 aColor)/* overload */;
	void __fastcall SetAlphaToValue(const System::Byte aValue);
	void __fastcall SetAlphaToFloatValue(const float aValue);
	void __fastcall InvertAlpha();
	void __fastcall SqrtAlpha();
	void __fastcall BrightnessCorrection(const float factor);
	void __fastcall GammaCorrection(const float gamma);
	void __fastcall DownSampleByFactor2();
	void __fastcall ReadPixels(const Winapi::Windows::TRect &area);
	void __fastcall DrawPixels(const float x, const float y);
	void __fastcall GrayScaleToNormalMap(const float scale, bool wrapX = true, bool wrapY = true);
	void __fastcall NormalizeNormalMap();
	void __fastcall AssignToBitmap(Fmx::Graphics::TBitmap* aBitmap);
	virtual void __fastcall GenerateMipmap(Gxs::Imageutils::TImageFilterFunction AFilter);
	virtual void __fastcall UnMipmap();
};


typedef TgxImage TgxBitmap32;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TRasterFileFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TgxBaseImageClass BaseImageClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
public:
	/* TObject.Create */ inline __fastcall TRasterFileFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TRasterFileFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TRasterFileFormatsList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	__fastcall virtual ~TRasterFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TgxBaseImageClass AClass);
	TgxBaseImageClass __fastcall FindExt(System::UnicodeString ext);
	TgxBaseImageClass __fastcall FindFromFileName(const System::UnicodeString fileName);
	TgxBaseImageClass __fastcall FindFromStream(System::Classes::TStream* const AStream);
	HIDESBASE void __fastcall Remove(TgxBaseImageClass AClass);
	void __fastcall BuildFilterStrings(TgxBaseImageClass imageFileClass, System::UnicodeString &descriptions, System::UnicodeString &filters, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
	System::UnicodeString __fastcall FindExtByIndex(int index, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TRasterFileFormatsList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TRasterFileFormatsList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidRasterFile : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidRasterFile(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidRasterFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidRasterFile(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidRasterFile(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidRasterFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidRasterFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidRasterFile(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidRasterFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidRasterFile(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidRasterFile(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidRasterFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidRasterFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidRasterFile() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vVerticalFlipDDS;
extern DELPHI_PACKAGE TRasterFileFormatsList* __fastcall GetRasterFileFormats(void);
extern DELPHI_PACKAGE void __fastcall RegisterRasterFormat(const System::UnicodeString AExtension, const System::UnicodeString ADescription, TgxBaseImageClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterRasterFormat(TgxBaseImageClass AClass);
extern DELPHI_PACKAGE System::UnicodeString __fastcall RasterFileFormatExtensionByIndex(int index);
extern DELPHI_PACKAGE void __fastcall Div2(int &Value);
extern DELPHI_PACKAGE int __fastcall GetImageLodNumber(int w, int h, int d, bool IsVolume);
extern DELPHI_PACKAGE void __fastcall GammaCorrectRGBArray(void * base, int pixelCount, float gamma);
extern DELPHI_PACKAGE void __fastcall BrightenRGBArray(void * base, int pixelCount, float factor);
extern DELPHI_PACKAGE void __fastcall BGR24ToRGB24(void * src, void * dest, int pixelCount);
extern DELPHI_PACKAGE void __fastcall BGR24ToRGBA32(void * src, void * dest, int pixelCount);
extern DELPHI_PACKAGE void __fastcall RGB24ToRGBA32(void * src, void * dest, int pixelCount);
extern DELPHI_PACKAGE void __fastcall BGRA32ToRGBA32(void * src, void * dest, int pixelCount);
}	/* namespace Graphics */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GRAPHICS)
using namespace Gxs::Graphics;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GraphicsHPP
