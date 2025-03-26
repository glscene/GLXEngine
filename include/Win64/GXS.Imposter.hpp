// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Imposter.pas' rev: 36.00 (Windows)

#ifndef GXS_ImposterHPP
#define GXS_ImposterHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------
typedef Glgraphics::TgxBitmap32* __fastcall (__closure *TLoadingImposterEvent)(System::TObject* Sender, Glscene::TgxBaseSceneObject* impostoredObject, TImposter* destImposter);

namespace Gxs
{
namespace Imposter
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TImposter;
class DELPHICLASS TgxImposterBuilder;
class DELPHICLASS TgxStaticImposterBuilderCorona;
struct TCoronaTangentLookup;
class DELPHICLASS TgxStaticImposterBuilderCoronas;
class DELPHICLASS TStaticImposter;
class DELPHICLASS TgxStaticImposterBuilder;
class DELPHICLASS TgxDynamicImposterBuilder;
class DELPHICLASS TgxImposter;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TImposterOption : unsigned char { impoBlended, impoAlphaTest, impoNearestFiltering, impoPerspectiveCorrection };

typedef System::Set<TImposterOption, TImposterOption::impoBlended, TImposterOption::impoPerspectiveCorrection> TImposterOptions;

class PASCALIMPLEMENTATION TImposter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FRequestCount;
	TgxImposterBuilder* FBuilder;
	Gxs::Context::TgxTextureHandle* FTexture;
	Gxs::Scene::TgxBaseSceneObject* FImpostoredObject;
	float FAspectRatio;
	bool FModulated;
	
protected:
	Stage::Vectortypes::TVector4f FVx;
	Stage::Vectortypes::TVector4f FVy;
	Stage::Vectortypes::TVector4f FStaticOffset;
	System::StaticArray<Stage::Vectortypes::TVector4f, 4> FQuad;
	float FStaticScale;
	virtual void __fastcall PrepareTexture(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall RenderQuad(const Stage::Vectortypes::TVector4f &texExtents, const Stage::Vectortypes::TVector4f &objPos, float size);
	
public:
	__fastcall virtual TImposter(TgxImposterBuilder* aBuilder);
	__fastcall virtual ~TImposter();
	virtual void __fastcall BeginRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const Stage::Vectortypes::TVector4f &objPos, const Stage::Vectortypes::TVector4f &localCameraPos, float size);
	virtual void __fastcall EndRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall RenderOnce(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const Stage::Vectortypes::TVector4f &objPos, const Stage::Vectortypes::TVector4f &localCameraPos, float size);
	__property float AspectRatio = {read=FAspectRatio, write=FAspectRatio};
	__property TgxImposterBuilder* Builder = {read=FBuilder};
	__property Gxs::Context::TgxTextureHandle* Texture = {read=FTexture};
	__property Gxs::Scene::TgxBaseSceneObject* ImpostoredObject = {read=FImpostoredObject, write=FImpostoredObject};
	__property bool Modulated = {read=FModulated, write=FModulated, nodefault};
};


typedef void __fastcall (__closure *TImposterLoadedEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* impostoredObject, TImposter* destImposter);

enum DECLSPEC_DENUM TImposterReference : unsigned char { irCenter, irTop, irBottom };

class PASCALIMPLEMENTATION TgxImposterBuilder : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	Gxs::Color::TgxColor* FBackColor;
	Gxs::Coordinates::TgxCoordinates* FBuildOffset;
	Gxs::Persistentclasses::TgxPersistentObjectList* FImposterRegister;
	Gxs::Scene::TgxRenderPoint* FRenderPoint;
	TImposterOptions FImposterOptions;
	float FAlphaTreshold;
	TImposterReference FImposterReference;
	TLoadingImposterEvent FOnLoadingImposter;
	TImposterLoadedEvent FOnImposterLoaded;
	
protected:
	void __fastcall SetRenderPoint(Gxs::Scene::TgxRenderPoint* AValue);
	void __fastcall RenderPointFreed(System::TObject* Sender);
	void __fastcall SetBackColor(Gxs::Color::TgxColor* AValue);
	void __fastcall SetBuildOffset(Gxs::Coordinates::TgxCoordinates* AValue);
	void __fastcall SetImposterReference(TImposterReference AValue);
	void __fastcall InitializeImpostorTexture(const System::Types::TPoint &TextureSize);
	__property Gxs::Persistentclasses::TgxPersistentObjectList* ImposterRegister = {read=FImposterRegister};
	void __fastcall UnregisterImposter(TImposter* imposter);
	virtual TImposter* __fastcall CreateNewImposter();
	virtual void __fastcall PrepareImposters(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoPrepareImposter(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Scene::TgxBaseSceneObject* impostoredObject, TImposter* destImposter) = 0 ;
	virtual void __fastcall DoUserSpecifiedImposter(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TImposter* destImposter, Gxs::Graphics::TgxBitmap32* bmp32);
	
public:
	__fastcall virtual TgxImposterBuilder(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxImposterBuilder();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	TImposter* __fastcall ImposterFor(Gxs::Scene::TgxBaseSceneObject* impostoredObject);
	void __fastcall RequestImposterFor(Gxs::Scene::TgxBaseSceneObject* impostoredObject);
	void __fastcall UnRequestImposterFor(Gxs::Scene::TgxBaseSceneObject* impostoredObject);
	
__published:
	__property Gxs::Scene::TgxRenderPoint* RenderPoint = {read=FRenderPoint, write=SetRenderPoint};
	__property Gxs::Color::TgxColor* BackColor = {read=FBackColor, write=SetBackColor};
	__property Gxs::Coordinates::TgxCoordinates* BuildOffset = {read=FBuildOffset, write=SetBuildOffset};
	__property TImposterOptions ImposterOptions = {read=FImposterOptions, write=FImposterOptions, default=3};
	__property TImposterReference ImposterReference = {read=FImposterReference, write=SetImposterReference, default=0};
	__property float AlphaTreshold = {read=FAlphaTreshold, write=FAlphaTreshold};
	__property TLoadingImposterEvent OnLoadingImposter = {read=FOnLoadingImposter, write=FOnLoadingImposter};
	__property TImposterLoadedEvent OnImposterLoaded = {read=FOnImposterLoaded, write=FOnImposterLoaded};
};


class PASCALIMPLEMENTATION TgxStaticImposterBuilderCorona : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	int FSamples;
	float FElevation;
	int FSampleBaseIndex;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetSamples(int AValue);
	void __fastcall SetElevation(float AValue);
	
public:
	__fastcall virtual TgxStaticImposterBuilderCorona(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxStaticImposterBuilderCorona();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int Samples = {read=FSamples, write=SetSamples, default=8};
	__property float Elevation = {read=FElevation, write=SetElevation};
};


struct DECLSPEC_DRECORD TCoronaTangentLookup
{
public:
	float minTan;
	float maxTan;
	TgxStaticImposterBuilderCorona* corona;
};


class PASCALIMPLEMENTATION TgxStaticImposterBuilderCoronas : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
	
private:
	typedef System::DynamicArray<TCoronaTangentLookup> _TgxStaticImposterBuilderCoronas__1;
	
	
public:
	TgxStaticImposterBuilderCorona* operator[](int AIndex) { return this->Items[AIndex]; }
	
private:
	_TgxStaticImposterBuilderCoronas__1 FCoronaTangentLookup;
	
protected:
	void __fastcall SetItems(int AIndex, TgxStaticImposterBuilderCorona* const AValue);
	TgxStaticImposterBuilderCorona* __fastcall GetItems(int AIndex);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	void __fastcall PrepareSampleBaseIndices();
	void __fastcall PrepareCoronaTangentLookup();
	TgxStaticImposterBuilderCorona* __fastcall CoronaForElevationTangent(float aTangent);
	
public:
	__fastcall TgxStaticImposterBuilderCoronas(System::Classes::TPersistent* AOwner);
	HIDESBASE TgxStaticImposterBuilderCorona* __fastcall Add()/* overload */;
	HIDESBASE TgxStaticImposterBuilderCorona* __fastcall Add(const float elevation, int samples)/* overload */;
	__property TgxStaticImposterBuilderCorona* Items[int AIndex] = {read=GetItems, write=SetItems/*, default*/};
	int __fastcall SampleCount();
	virtual void __fastcall NotifyChange();
	virtual void __fastcall EndUpdate();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxStaticImposterBuilderCoronas() { }
	
};


class PASCALIMPLEMENTATION TStaticImposter : public TImposter
{
	typedef TImposter inherited;
	
public:
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, const Stage::Vectortypes::TVector4f &objPos, const Stage::Vectortypes::TVector4f &localCameraPos, float size);
public:
	/* TImposter.Create */ inline __fastcall virtual TStaticImposter(TgxImposterBuilder* aBuilder) : TImposter(aBuilder) { }
	/* TImposter.Destroy */ inline __fastcall virtual ~TStaticImposter() { }
	
};


enum DECLSPEC_DENUM TSIBLigthing : unsigned char { siblNoLighting, siblStaticLighting, siblLocalLighting };

class PASCALIMPLEMENTATION TgxStaticImposterBuilder : public TgxImposterBuilder
{
	typedef TgxImposterBuilder inherited;
	
private:
	TgxStaticImposterBuilderCoronas* FCoronas;
	int FSampleSize;
	System::Types::TPoint FTextureSize;
	System::Types::TPoint FSamplesPerAxis;
	Stage::Vectortypes::TVector2f FInvSamplesPerAxis;
	float FSamplingRatioBias;
	float FInvSamplingRatioBias;
	TSIBLigthing FLighting;
	float FSamplesAlphaScale;
	
protected:
	void __fastcall SetCoronas(TgxStaticImposterBuilderCoronas* AValue);
	void __fastcall SetSampleSize(int AValue);
	void __fastcall SetSamplingRatioBias(float AValue);
	bool __fastcall StoreSamplingRatioBias();
	void __fastcall SetLighting(TSIBLigthing AValue);
	void __fastcall SetSamplesAlphaScale(float AValue);
	bool __fastcall StoreSamplesAlphaScale();
	System::UnicodeString __fastcall GetTextureSizeInfo();
	void __fastcall SetTextureSizeInfo(const System::UnicodeString texSize);
	System::Types::TPoint __fastcall ComputeOptimalTextureSize();
	virtual TImposter* __fastcall CreateNewImposter();
	virtual void __fastcall DoPrepareImposter(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Scene::TgxBaseSceneObject* impostoredObject, TImposter* destImposter);
	virtual void __fastcall DoUserSpecifiedImposter(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TImposter* destImposter, Gxs::Graphics::TgxBitmap32* bmp32);
	void __fastcall ComputeStaticParams(TImposter* destImposter);
	
public:
	__fastcall virtual TgxStaticImposterBuilder(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxStaticImposterBuilder();
	void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Scene::TgxBaseSceneObject* impostoredObject, TImposter* destImposter);
	float __fastcall TextureFillRatio();
	__property System::Types::TPoint TextureSize = {read=FTextureSize};
	__property System::Types::TPoint SamplesPerAxis = {read=FSamplesPerAxis};
	
__published:
	__property TgxStaticImposterBuilderCoronas* Coronas = {read=FCoronas, write=SetCoronas};
	__property int SampleSize = {read=FSampleSize, write=SetSampleSize, default=32};
	__property float SamplingRatioBias = {read=FSamplingRatioBias, write=SetSamplingRatioBias, stored=StoreSamplingRatioBias};
	__property float SamplesAlphaScale = {read=FSamplesAlphaScale, write=SetSamplesAlphaScale, stored=StoreSamplesAlphaScale};
	__property TSIBLigthing Lighting = {read=FLighting, write=FLighting, default=1};
	__property System::UnicodeString TextureSizeInfo = {read=GetTextureSizeInfo, write=SetTextureSizeInfo, stored=false};
};


class PASCALIMPLEMENTATION TgxDynamicImposterBuilder : public TgxImposterBuilder
{
	typedef TgxImposterBuilder inherited;
	
private:
	int FMinTexSize;
	int FMaxTexSize;
	float FMinDistance;
	float FTolerance;
	bool FUseMatrixError;
	
protected:
	void __fastcall SetMinDistance(const float AValue);
	
public:
	__fastcall virtual TgxDynamicImposterBuilder(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxDynamicImposterBuilder();
	
__published:
	__property int MinTexSize = {read=FMinTexSize, write=FMinTexSize, nodefault};
	__property int MaxTexSize = {read=FMaxTexSize, write=FMaxTexSize, nodefault};
	__property float MinDistance = {read=FMinDistance, write=SetMinDistance};
	__property float Tolerance = {read=FTolerance, write=FTolerance};
	__property bool UseMatrixError = {read=FUseMatrixError, write=FUseMatrixError, nodefault};
};


class PASCALIMPLEMENTATION TgxImposter : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	TgxImposterBuilder* FBuilder;
	Gxs::Scene::TgxBaseSceneObject* FImpostoredObject;
	
protected:
	void __fastcall SetBuilder(TgxImposterBuilder* const AValue);
	void __fastcall SetImpostoredObject(Gxs::Scene::TgxBaseSceneObject* const AValue);
	
public:
	__fastcall virtual TgxImposter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxImposter();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	
__published:
	__property TgxImposterBuilder* Builder = {read=FBuilder, write=SetBuilder};
	__property Gxs::Scene::TgxBaseSceneObject* ImpostoredObject = {read=FImpostoredObject, write=SetImpostoredObject};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxImposter(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultImposterOptions (System::Set<TImposterOption, TImposterOption::impoBlended, TImposterOption::impoPerspectiveCorrection>() << TImposterOption::impoBlended << TImposterOption::impoAlphaTest )
}	/* namespace Imposter */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_IMPOSTER)
using namespace Gxs::Imposter;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ImposterHPP
