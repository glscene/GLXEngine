// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Texture.pas' rev: 36.00 (Windows)

#ifndef GXS_TextureHPP
#define GXS_TextureHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Objects.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Strings.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.ImageUtils.hpp>
#include <Stage.Utils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Texture
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IgxTextureNotifyAble;
typedef System::DelphiInterface<IgxTextureNotifyAble> _di_IgxTextureNotifyAble;
class DELPHICLASS TgxTextureImage;
class DELPHICLASS TgxBlankImage;
class DELPHICLASS TgxPictureImage;
class DELPHICLASS TgxPersistentImage;
class DELPHICLASS TgxPicFileImage;
class DELPHICLASS TgxCubeMapImage;
class DELPHICLASS TgxTexture;
class DELPHICLASS TgxTextureExItem;
class DELPHICLASS TgxTextureEx;
class DELPHICLASS ETexture;
class DELPHICLASS EShaderException;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxTextureMode : unsigned char { tmDecal, tmModulate, tmBlend, tmReplace, tmAdd };

enum DECLSPEC_DENUM TgxTextureWrap : unsigned char { twBoth, twNone, twVertical, twHorizontal, twSeparate };

enum DECLSPEC_DENUM TgxMinFilter : unsigned char { miNearest, miLinear, miNearestMipmapNearest, miLinearMipmapNearest, miNearestMipmapLinear, miLinearMipmapLinear };

enum DECLSPEC_DENUM TgxMagFilter : unsigned char { maNearest, maLinear };

enum DECLSPEC_DENUM TgxDepthTextureMode : unsigned char { dtmLuminance, dtmIntensity, dtmAlpha };

typedef Gxs::State::TgxComparisonFunction TgxDepthCompareFunc;

enum DECLSPEC_DENUM TgxTextureFormat : unsigned char { tfDefault, tfRGB, tfRGBA, tfRGB16, tfRGBA16, tfAlpha, tfLuminance, tfLuminanceAlpha, tfIntensity, tfNormalMap, tfRGBAFloat16, tfRGBAFloat32, tfExtended };

typedef Stage::Textureformat::TglInternalCompression TgxTextureCompression;

__interface  INTERFACE_UUID("{0D9DC0B0-ECE4-4513-A8A1-5AE7022C9426}") IgxTextureNotifyAble  : public Gxs::Baseclasses::IgxNotifyAble 
{
	virtual void __fastcall NotifyTexMapChange(System::TObject* Sender) = 0 ;
};

typedef void __fastcall (__closure *TgxTextureNeededEvent)(System::TObject* Sender, System::UnicodeString &TextureFileName);

enum DECLSPEC_DENUM TgxTextureChange : unsigned char { tcImage, tcParams };

typedef System::Set<TgxTextureChange, TgxTextureChange::tcImage, TgxTextureChange::tcParams> TgxTextureChanges;

enum DECLSPEC_DENUM TgxTextureImageAlpha : unsigned char { tiaDefault, tiaAlphaFromIntensity, tiaSuperBlackTransparent, tiaLuminance, tiaLuminanceSqrt, tiaOpaque, tiaTopLeftPointColorTransparent, tiaInverseLuminance, tiaInverseLuminanceSqrt, tiaBottomRightPointColorTransparent };

class PASCALIMPLEMENTATION TgxTextureImage : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	System::UnicodeString __fastcall GetResourceName();
	
protected:
	TgxTexture* FOwnerTexture;
	TgxTextureNeededEvent FOnTextureNeeded;
	System::UnicodeString FResourceFile;
	__classmethod virtual bool __fastcall IsSelfLoading();
	virtual void __fastcall LoadTexture(Stage::Textureformat::TglInternalFormat AInternalFormat);
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetDepth();
	__property TgxTextureNeededEvent OnTextureNeeded = {read=FOnTextureNeeded, write=FOnTextureNeeded};
	
public:
	__fastcall virtual TgxTextureImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxTextureImage();
	__property TgxTexture* OwnerTexture = {read=FOwnerTexture, write=FOwnerTexture};
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Invalidate();
	virtual Gxs::Graphics::TgxImage* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	Fmx::Graphics::TBitmap* __fastcall AsBitmap();
	void __fastcall AssignToBitmap(Fmx::Graphics::TBitmap* aBitmap);
	__property int Width = {read=GetWidth, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int Depth = {read=GetDepth, nodefault};
	__property Stage::Textureformat::TglTextureTarget NativeTextureTarget = {read=GetTextureTarget, nodefault};
	__property System::UnicodeString ResourceName = {read=GetResourceName};
};


_DECLARE_METACLASS(System::TMetaClass, TgxTextureImageClass);

class PASCALIMPLEMENTATION TgxBlankImage : public TgxTextureImage
{
	typedef TgxTextureImage inherited;
	
private:
	void __fastcall SetWidth(int val);
	void __fastcall SetHeight(int val);
	void __fastcall SetDepth(int val);
	void __fastcall SetCubeMap(const bool val);
	void __fastcall SetArray(const bool val);
	
protected:
	Gxs::Graphics::TgxImage* fBitmap;
	int fWidth;
	int fHeight;
	int fDepth;
	unsigned fColorFormat;
	bool fCubeMap;
	bool fArray;
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	
public:
	__fastcall virtual TgxBlankImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxBlankImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Gxs::Graphics::TgxImage* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property int Width = {read=GetWidth, write=SetWidth, default=256};
	__property int Height = {read=GetHeight, write=SetHeight, default=256};
	__property int Depth = {read=GetDepth, write=SetDepth, default=0};
	__property bool CubeMap = {read=fCubeMap, write=SetCubeMap, default=0};
	__property bool TextureArray = {read=fArray, write=SetArray, default=0};
	__property unsigned ColorFormat = {read=fColorFormat, write=fColorFormat, nodefault};
};


class PASCALIMPLEMENTATION TgxPictureImage : public TgxTextureImage
{
	typedef TgxTextureImage inherited;
	
private:
	Gxs::Graphics::TgxImage* FBitmap;
	Fmx::Objects::TImage* FVKPicture;
	int FUpdateCounter;
	
protected:
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetDepth();
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	Fmx::Objects::TImage* __fastcall GetPicture();
	void __fastcall SetPicture(Fmx::Objects::TImage* const aPicture);
	void __fastcall PictureChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TgxPictureImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxPictureImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE void __fastcall BeginUpdate();
	HIDESBASE void __fastcall EndUpdate();
	virtual Gxs::Graphics::TgxImage* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	__property Fmx::Objects::TImage* Picture = {read=GetPicture, write=SetPicture};
};


class PASCALIMPLEMENTATION TgxPersistentImage : public TgxPictureImage
{
	typedef TgxPictureImage inherited;
	
public:
	__fastcall virtual TgxPersistentImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxPersistentImage();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property NativeTextureTarget;
	
__published:
	__property Picture;
};


class PASCALIMPLEMENTATION TgxPicFileImage : public TgxPictureImage
{
	typedef TgxPictureImage inherited;
	
private:
	System::UnicodeString FPictureFileName;
	bool FAlreadyWarnedAboutMissingFile;
	int FWidth;
	int FHeight;
	
protected:
	void __fastcall SetPictureFileName(const System::UnicodeString val);
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	
public:
	__fastcall virtual TgxPicFileImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxPicFileImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property NativeTextureTarget;
	virtual Gxs::Graphics::TgxImage* __fastcall GetBitmap32();
	virtual void __fastcall Invalidate();
	
__published:
	__property System::UnicodeString PictureFileName = {read=FPictureFileName, write=SetPictureFileName};
};


typedef int TgxCubeMapTarget;

class PASCALIMPLEMENTATION TgxCubeMapImage : public TgxTextureImage
{
	typedef TgxTextureImage inherited;
	
private:
	Gxs::Graphics::TgxImage* FImage;
	int FUpdateCounter;
	System::StaticArray<Fmx::Objects::TImage*, 6> FPicture;
	
protected:
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	void __fastcall SetPicture(TgxCubeMapTarget index, Fmx::Objects::TImage* const val);
	Fmx::Objects::TImage* __fastcall GetPicture(TgxCubeMapTarget index);
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	void __fastcall PictureChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TgxCubeMapImage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxCubeMapImage();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Gxs::Graphics::TgxImage* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	HIDESBASE void __fastcall BeginUpdate();
	HIDESBASE void __fastcall EndUpdate();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property NativeTextureTarget;
	__property Fmx::Objects::TImage* Picture[TgxCubeMapTarget index] = {read=GetPicture, write=SetPicture};
	
__published:
	__property Fmx::Objects::TImage* PicturePX = {read=GetPicture, write=SetPicture, index=0};
	__property Fmx::Objects::TImage* PictureNX = {read=GetPicture, write=SetPicture, index=1};
	__property Fmx::Objects::TImage* PicturePY = {read=GetPicture, write=SetPicture, index=2};
	__property Fmx::Objects::TImage* PictureNY = {read=GetPicture, write=SetPicture, index=3};
	__property Fmx::Objects::TImage* PicturePZ = {read=GetPicture, write=SetPicture, index=4};
	__property Fmx::Objects::TImage* PictureNZ = {read=GetPicture, write=SetPicture, index=5};
};


enum DECLSPEC_DENUM TgxTextureMappingMode : unsigned char { tmmUser, tmmObjectLinear, tmmEyeLinear, tmmSphere, tmmCubeMapReflection, tmmCubeMapNormal, tmmCubeMapLight0, tmmCubeMapCamera };

class PASCALIMPLEMENTATION TgxTexture : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	Gxs::Context::TgxTextureHandle* FTextureHandle;
	Gxs::Context::TgxVirtualHandle* FSamplerHandle;
	Stage::Textureformat::TglInternalFormat FTextureFormat;
	TgxTextureMode FTextureMode;
	TgxTextureWrap FTextureWrap;
	TgxMinFilter FMinFilter;
	TgxMagFilter FMagFilter;
	bool FDisabled;
	TgxTextureImage* FImage;
	TgxTextureImageAlpha FImageAlpha;
	float FImageBrightness;
	float FImageGamma;
	TgxTextureMappingMode FMappingMode;
	Gxs::Coordinates::TgxCoordinates4* FMapSCoordinates;
	Gxs::Coordinates::TgxCoordinates4* FMapTCoordinates;
	Gxs::Coordinates::TgxCoordinates4* FMapRCoordinates;
	Gxs::Coordinates::TgxCoordinates4* FMapQCoordinates;
	TgxTextureNeededEvent FOnTextureNeeded;
	TgxTextureCompression FCompression;
	int FRequiredMemorySize;
	Stage::Textureformat::TglTextureFilteringQuality FFilteringQuality;
	int FTexWidth;
	int FTexHeight;
	int FTexDepth;
	Gxs::Color::TgxColor* FEnvColor;
	Gxs::Color::TgxColor* FBorderColor;
	float FNormalMapScale;
	Stage::Textureformat::TglSeparateTextureWrap FTextureWrapS;
	Stage::Textureformat::TglSeparateTextureWrap FTextureWrapT;
	Stage::Textureformat::TglSeparateTextureWrap FTextureWrapR;
	Stage::Textureformat::TglTextureCompareMode fTextureCompareMode;
	TgxDepthCompareFunc fTextureCompareFunc;
	TgxDepthTextureMode fDepthTextureMode;
	bool FKeepImageAfterTransfer;
	
protected:
	void __fastcall SetImage(TgxTextureImage* AValue);
	void __fastcall SetImageAlpha(const TgxTextureImageAlpha val);
	void __fastcall SetImageBrightness(const float val);
	bool __fastcall StoreBrightness();
	void __fastcall SetImageGamma(const float val);
	bool __fastcall StoreGamma();
	void __fastcall SetMagFilter(TgxMagFilter AValue);
	void __fastcall SetMinFilter(TgxMinFilter AValue);
	void __fastcall SetTextureMode(TgxTextureMode AValue);
	void __fastcall SetTextureWrap(TgxTextureWrap AValue);
	void __fastcall SetTextureWrapS(Stage::Textureformat::TglSeparateTextureWrap AValue);
	void __fastcall SetTextureWrapT(Stage::Textureformat::TglSeparateTextureWrap AValue);
	void __fastcall SetTextureWrapR(Stage::Textureformat::TglSeparateTextureWrap AValue);
	TgxTextureFormat __fastcall GetTextureFormat();
	void __fastcall SetTextureFormat(const TgxTextureFormat val);
	void __fastcall SetTextureFormatEx(const Stage::Textureformat::TglInternalFormat val);
	bool __fastcall StoreTextureFormatEx();
	void __fastcall SetCompression(const TgxTextureCompression val);
	void __fastcall SetFilteringQuality(const Stage::Textureformat::TglTextureFilteringQuality val);
	void __fastcall SetMappingMode(const TgxTextureMappingMode val);
	Gxs::Coordinates::TgxCoordinates4* __fastcall GetMappingSCoordinates();
	void __fastcall SetMappingSCoordinates(Gxs::Coordinates::TgxCoordinates4* const val);
	bool __fastcall StoreMappingSCoordinates();
	Gxs::Coordinates::TgxCoordinates4* __fastcall GetMappingTCoordinates();
	void __fastcall SetMappingTCoordinates(Gxs::Coordinates::TgxCoordinates4* const val);
	bool __fastcall StoreMappingTCoordinates();
	Gxs::Coordinates::TgxCoordinates4* __fastcall GetMappingRCoordinates();
	void __fastcall SetMappingRCoordinates(Gxs::Coordinates::TgxCoordinates4* const val);
	bool __fastcall StoreMappingRCoordinates();
	Gxs::Coordinates::TgxCoordinates4* __fastcall GetMappingQCoordinates();
	void __fastcall SetMappingQCoordinates(Gxs::Coordinates::TgxCoordinates4* const val);
	bool __fastcall StoreMappingQCoordinates();
	void __fastcall SetDisabled(bool AValue);
	void __fastcall SetEnabled(const bool val);
	bool __fastcall GetEnabled();
	void __fastcall SetEnvColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetBorderColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetNormalMapScale(const float val);
	void __fastcall SetTextureCompareMode(const Stage::Textureformat::TglTextureCompareMode val);
	void __fastcall SetTextureCompareFunc(const TgxDepthCompareFunc val);
	void __fastcall SetDepthTextureMode(const TgxDepthTextureMode val);
	bool __fastcall StoreNormalMapScale();
	bool __fastcall StoreImageClassName();
	virtual unsigned __fastcall GetHandle();
	virtual void __fastcall PrepareImage(unsigned target);
	virtual void __fastcall PrepareParams(unsigned target);
	void __fastcall DoOnTextureNeeded(System::TObject* Sender, System::UnicodeString &textureFileName);
	void __fastcall OnSamplerAllocate(Gxs::Context::TgxVirtualHandle* Sender, unsigned &Handle);
	void __fastcall OnSamplerDestroy(Gxs::Context::TgxVirtualHandle* Sender, unsigned &Handle);
	void __fastcall SetTextureErrorImage();
	
public:
	__fastcall virtual TgxTexture(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxTexture();
	__property TgxTextureNeededEvent OnTextureNeeded = {read=FOnTextureNeeded, write=FOnTextureNeeded};
	void __fastcall PrepareBuildList();
	void __fastcall ApplyMappingMode();
	void __fastcall UnApplyMappingMode();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall ApplyAsTexture2(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Stage::Vectortypes::PMatrix4f textureMatrix = (Stage::Vectortypes::PMatrix4f)(0x0));
	void __fastcall UnApplyAsTexture2(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool reloadIdentityTextureMatrix);
	void __fastcall ApplyAsTextureN(int n, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Stage::Vectortypes::PMatrix4f textureMatrix = (Stage::Vectortypes::PMatrix4f)(0x0));
	void __fastcall UnApplyAsTextureN(int n, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool reloadIdentityTextureMatrix);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall NotifyImageChange();
	void __fastcall NotifyParamsChange();
	void __fastcall DestroyHandles();
	void __fastcall SetImageClassName(const System::UnicodeString val);
	System::UnicodeString __fastcall GetImageClassName();
	int __fastcall TextureImageRequiredMemory();
	unsigned __fastcall AllocateHandle();
	bool __fastcall IsHandleAllocated();
	int __fastcall OpenGLTextureFormat();
	bool __fastcall IsFloatType();
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property unsigned Handle = {read=GetHandle, nodefault};
	__property Gxs::Context::TgxTextureHandle* TextureHandle = {read=FTextureHandle};
	__property int TexWidth = {read=FTexWidth, nodefault};
	__property int TexHeight = {read=FTexHeight, nodefault};
	__property int TexDepth = {read=FTexDepth, nodefault};
	
__published:
	__property System::UnicodeString ImageClassName = {read=GetImageClassName, write=SetImageClassName, stored=StoreImageClassName};
	__property TgxTextureImage* Image = {read=FImage, write=SetImage};
	__property TgxTextureImageAlpha ImageAlpha = {read=FImageAlpha, write=SetImageAlpha, default=0};
	__property float ImageBrightness = {read=FImageBrightness, write=SetImageBrightness, stored=StoreBrightness};
	__property float ImageGamma = {read=FImageGamma, write=SetImageGamma, stored=StoreGamma};
	__property TgxMagFilter MagFilter = {read=FMagFilter, write=SetMagFilter, default=1};
	__property TgxMinFilter MinFilter = {read=FMinFilter, write=SetMinFilter, default=5};
	__property TgxTextureMode TextureMode = {read=FTextureMode, write=SetTextureMode, default=0};
	__property TgxTextureWrap TextureWrap = {read=FTextureWrap, write=SetTextureWrap, default=0};
	__property Stage::Textureformat::TglSeparateTextureWrap TextureWrapS = {read=FTextureWrapS, write=SetTextureWrapS, default=0};
	__property Stage::Textureformat::TglSeparateTextureWrap TextureWrapT = {read=FTextureWrapT, write=SetTextureWrapT, default=0};
	__property Stage::Textureformat::TglSeparateTextureWrap TextureWrapR = {read=FTextureWrapR, write=SetTextureWrapR, default=0};
	__property TgxTextureFormat TextureFormat = {read=GetTextureFormat, write=SetTextureFormat, default=0};
	__property Stage::Textureformat::TglInternalFormat TextureFormatEx = {read=FTextureFormat, write=SetTextureFormatEx, stored=StoreTextureFormatEx, nodefault};
	__property TgxTextureCompression Compression = {read=FCompression, write=SetCompression, default=0};
	__property Stage::Textureformat::TglTextureFilteringQuality FilteringQuality = {read=FFilteringQuality, write=SetFilteringQuality, default=0};
	__property TgxTextureMappingMode MappingMode = {read=FMappingMode, write=SetMappingMode, default=0};
	__property Gxs::Coordinates::TgxCoordinates4* MappingSCoordinates = {read=GetMappingSCoordinates, write=SetMappingSCoordinates, stored=StoreMappingSCoordinates};
	__property Gxs::Coordinates::TgxCoordinates4* MappingTCoordinates = {read=GetMappingTCoordinates, write=SetMappingTCoordinates, stored=StoreMappingTCoordinates};
	__property Gxs::Coordinates::TgxCoordinates4* MappingRCoordinates = {read=GetMappingRCoordinates, write=SetMappingRCoordinates, stored=StoreMappingRCoordinates};
	__property Gxs::Coordinates::TgxCoordinates4* MappingQCoordinates = {read=GetMappingQCoordinates, write=SetMappingQCoordinates, stored=StoreMappingQCoordinates};
	__property Gxs::Color::TgxColor* EnvColor = {read=FEnvColor, write=SetEnvColor};
	__property Gxs::Color::TgxColor* BorderColor = {read=FBorderColor, write=SetBorderColor};
	__property bool Disabled = {read=FDisabled, write=SetDisabled, default=1};
	__property float NormalMapScale = {read=FNormalMapScale, write=SetNormalMapScale, stored=StoreNormalMapScale};
	__property Stage::Textureformat::TglTextureCompareMode TextureCompareMode = {read=fTextureCompareMode, write=SetTextureCompareMode, default=0};
	__property TgxDepthCompareFunc TextureCompareFunc = {read=fTextureCompareFunc, write=SetTextureCompareFunc, default=3};
	__property TgxDepthTextureMode DepthTextureMode = {read=fDepthTextureMode, write=SetDepthTextureMode, default=0};
	__property bool KeepImageAfterTransfer = {read=FKeepImageAfterTransfer, write=FKeepImageAfterTransfer, default=0};
};


class PASCALIMPLEMENTATION TgxTextureExItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxTexture* FTexture;
	int FTextureIndex;
	Gxs::Coordinates::TgxCoordinates* FTextureOffset;
	Gxs::Coordinates::TgxCoordinates* FTextureScale;
	bool FTextureMatrixIsIdentity;
	Stage::Vectortypes::TMatrix4f FTextureMatrix;
	bool FApplied;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetTexture(TgxTexture* const Value);
	void __fastcall SetTextureIndex(const int Value);
	void __fastcall SetTextureOffset(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetTextureScale(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall NotifyTexMapChange(System::TObject* Sender);
	void __fastcall CalculateTextureMatrix();
	void __fastcall OnNotifyChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxTextureExItem(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxTextureExItem();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TgxTexture* Texture = {read=FTexture, write=SetTexture};
	__property int TextureIndex = {read=FTextureIndex, write=SetTextureIndex, nodefault};
	__property Gxs::Coordinates::TgxCoordinates* TextureOffset = {read=FTextureOffset, write=SetTextureOffset};
	__property Gxs::Coordinates::TgxCoordinates* TextureScale = {read=FTextureScale, write=SetTextureScale};
private:
	void *__IgxTextureNotifyAble;	// IgxTextureNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0D9DC0B0-ECE4-4513-A8A1-5AE7022C9426}
	operator _di_IgxTextureNotifyAble()
	{
		_di_IgxTextureNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxTextureNotifyAble*(void) { return (IgxTextureNotifyAble*)&__IgxTextureNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxTextureEx : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxTextureExItem* operator[](int index) { return this->Items[index]; }
	
private:
	Gxs::Baseclasses::TgxUpdateAbleObject* FOwner;
	
protected:
	void __fastcall SetItems(int index, TgxTextureExItem* const Value);
	TgxTextureExItem* __fastcall GetItems(int index);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall TgxTextureEx(Gxs::Baseclasses::TgxUpdateAbleObject* AOwner);
	void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	bool __fastcall IsTextureEnabled(int Index);
	HIDESBASE TgxTextureExItem* __fastcall Add();
	__property TgxTextureExItem* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall Loaded();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxTextureEx() { }
	
};


class PASCALIMPLEMENTATION ETexture : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ETexture(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ETexture(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ETexture(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ETexture(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ETexture(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ETexture(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ETexture(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ETexture(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETexture(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETexture(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETexture(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETexture(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ETexture() { }
	
};


class PASCALIMPLEMENTATION EShaderException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EShaderException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EShaderException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EShaderException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EShaderException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EShaderException() { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultNormalMapScale  (1.250000E-01)
static _DELPHI_CONST System::Int8 CmtPX = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CmtNX = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CmtPY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CmtNY = System::Int8(0x3);
static _DELPHI_CONST System::Int8 CmtPZ = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CmtNZ = System::Int8(0x5);
extern DELPHI_PACKAGE void __fastcall RegisterTGraphicClassFileExtension(const System::UnicodeString extension, const Gxs::Imageutils::TGraphicClass aClass);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall CreateGraphicFromFile(const System::UnicodeString fileName);
extern DELPHI_PACKAGE void __fastcall RegisterTextureImageClass(TgxTextureImageClass textureImageClass);
extern DELPHI_PACKAGE TgxTextureImageClass __fastcall FindTextureImageClass(const System::UnicodeString className);
extern DELPHI_PACKAGE TgxTextureImageClass __fastcall FindTextureImageClassByFriendlyName(const System::UnicodeString friendlyName);
extern DELPHI_PACKAGE void __fastcall SetTextureImageClassesToStrings(System::Classes::TStrings* aStrings);
extern DELPHI_PACKAGE System::Classes::TStrings* __fastcall GetTextureImageClassesAsStrings(void);
}	/* namespace Texture */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TEXTURE)
using namespace Gxs::Texture;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TextureHPP
