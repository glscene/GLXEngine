// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ParticleFX.pas' rev: 36.00 (Windows)

#ifndef GXS_ParticleFXHPP
#define GXS_ParticleFXHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.Manager.hpp>
#include <GXS.Scene.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.State.hpp>
#include <GXS.Material.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Context.hpp>
#include <GXS.Color.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Particlefx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxParticle;
class DELPHICLASS TgxParticleList;
class DELPHICLASS TgxParticleFXManager;
class DELPHICLASS TgxParticleFXEffect;
struct TParticleReference;
struct TPFXRegion;
class DELPHICLASS TgxParticleFXRenderer;
class DELPHICLASS TgxSourcePFXEffect;
class DELPHICLASS TgxDynamicPFXManager;
class DELPHICLASS TPFXLifeColor;
class DELPHICLASS TPFXLifeColors;
class DELPHICLASS TgxLifeColoredPFXManager;
class DELPHICLASS TgxCustomPFXManager;
class DELPHICLASS TgxPolygonPFXManager;
class DELPHICLASS TgxBaseSpritePFXManager;
class DELPHICLASS TgxCustomSpritePFXManager;
class DELPHICLASS TgxPointLightPFXManager;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxParticle : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	int FID;
	int FTag;
	TgxParticleFXManager* FManager;
	Stage::Vectorgeometry::TAffineVector FPosition;
	Stage::Vectorgeometry::TAffineVector FVelocity;
	float FRotation;
	double FCreationTime;
	float FEffectScale;
	float __fastcall GetPosition(const int Index);
	void __fastcall WritePosition(const int Index, const float aValue);
	float __fastcall GetVelocity(const int Index);
	void __fastcall WriteVelocity(const int Index, const float aValue);
	
public:
	__fastcall virtual TgxParticle();
	__fastcall virtual ~TgxParticle();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxParticleFXManager* Manager = {read=FManager, write=FManager};
	__property int ID = {read=FID, nodefault};
	__property Stage::Vectorgeometry::TAffineVector Position = {read=FPosition, write=FPosition};
	__property Stage::Vectorgeometry::TAffineVector Velocity = {read=FVelocity, write=FVelocity};
	__property double CreationTime = {read=FCreationTime, write=FCreationTime};
	__property float PosX = {read=GetPosition, write=WritePosition, index=0};
	__property float PosY = {read=GetPosition, write=WritePosition, index=1};
	__property float PosZ = {read=GetPosition, write=WritePosition, index=2};
	__property float VelX = {read=GetVelocity, write=WriteVelocity, index=0};
	__property float VelY = {read=GetVelocity, write=WriteVelocity, index=1};
	__property float VelZ = {read=GetVelocity, write=WriteVelocity, index=2};
	__property int Tag = {read=FTag, write=FTag, nodefault};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxParticle(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxParticleClass);

typedef System::StaticArray<TgxParticle*, 134217728> TgxParticleArray;

typedef TgxParticleArray *PGLParticleArray;

class PASCALIMPLEMENTATION TgxParticleList : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
public:
	TgxParticle* operator[](int index) { return this->Items[index]; }
	
private:
	TgxParticleFXManager* FOwner;
	Gxs::Persistentclasses::TgxPersistentObjectList* FItemList;
	PGLParticleArray FDirectList;
	
protected:
	TgxParticle* __fastcall GetItems(int index);
	void __fastcall SetItems(int index, TgxParticle* val);
	void __fastcall AfterItemCreated(System::TObject* Sender);
	
public:
	__fastcall virtual TgxParticleList();
	__fastcall virtual ~TgxParticleList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxParticleFXManager* Owner = {read=FOwner, write=FOwner};
	__property TgxParticle* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	int __fastcall ItemCount();
	int __fastcall AddItem(TgxParticle* aItem);
	void __fastcall RemoveAndFreeItem(TgxParticle* aItem);
	int __fastcall IndexOfItem(TgxParticle* aItem);
	void __fastcall Pack();
	__property PGLParticleArray List = {read=FDirectList};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxParticleList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


typedef void __fastcall (__closure *TPFXCreateParticleEvent)(System::TObject* Sender, TgxParticle* aParticle);

class PASCALIMPLEMENTATION TgxParticleFXManager : public Gxs::Cadencer::TgxCadencedComponent
{
	typedef Gxs::Cadencer::TgxCadencedComponent inherited;
	
private:
	Gxs::Material::TgxBlendingMode FBlendingMode;
	TgxParticleFXRenderer* FRenderer;
	TgxParticleList* FParticles;
	int FNextID;
	TPFXCreateParticleEvent FOnCreateParticle;
	bool FAutoFreeWhenEmpty;
	System::Classes::TList* FUsers;
	
protected:
	void __fastcall SetRenderer(TgxParticleFXRenderer* const val);
	void __fastcall SetParticles(TgxParticleList* const aParticles);
	virtual unsigned __fastcall TexturingMode() = 0 ;
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci) = 0 ;
	virtual void __fastcall BeginParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci) = 0 ;
	virtual void __fastcall RenderParticle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxParticle* aParticle) = 0 ;
	virtual void __fastcall EndParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci) = 0 ;
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci) = 0 ;
	__property int NextID = {read=FNextID, write=FNextID, nodefault};
	__property Gxs::Material::TgxBlendingMode BlendingMode = {read=FBlendingMode, write=FBlendingMode, nodefault};
	void __fastcall ApplyBlendingMode(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnapplyBlendingMode(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall registerUser(TgxParticleFXEffect* obj);
	void __fastcall unregisterUser(TgxParticleFXEffect* obj);
	
public:
	__fastcall virtual TgxParticleFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxParticleFXManager();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__classmethod virtual TgxParticleClass __fastcall ParticlesClass();
	virtual TgxParticle* __fastcall CreateParticle();
	void __fastcall CreateParticles(int nbParticles);
	__property TgxParticleList* Particles = {read=FParticles, write=SetParticles};
	virtual int __fastcall ParticleCount();
	__property bool AutoFreeWhenEmpty = {read=FAutoFreeWhenEmpty, write=FAutoFreeWhenEmpty, nodefault};
	
__published:
	__property TgxParticleFXRenderer* Renderer = {read=FRenderer, write=SetRenderer};
	__property TPFXCreateParticleEvent OnCreateParticle = {read=FOnCreateParticle, write=FOnCreateParticle};
	__property Cadencer;
};


class PASCALIMPLEMENTATION TgxParticleFXEffect : public Gxs::Scene::TgxObjectPostEffect
{
	typedef Gxs::Scene::TgxObjectPostEffect inherited;
	
private:
	TgxParticleFXManager* FManager;
	System::UnicodeString FManagerName;
	float FEffectScale;
	void __fastcall SetEffectScale(const float Value);
	
protected:
	void __fastcall SetManager(TgxParticleFXManager* val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall managerNotification(TgxParticleFXManager* aManager, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxParticleFXEffect(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxParticleFXEffect();
	
__published:
	__property TgxParticleFXManager* Manager = {read=FManager, write=SetManager};
	__property float EffectScale = {read=FEffectScale, write=SetEffectScale};
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TParticleReference
{
public:
	TgxParticle* particle;
	int distance;
};
#pragma pack(pop)


typedef TParticleReference *PParticleReference;

typedef System::StaticArray<TParticleReference, 8388607> TParticleReferenceArray;

typedef TParticleReferenceArray *PParticleReferenceArray;

typedef System::StaticArray<void *, 8388607> TFXPointerList;

typedef TFXPointerList *PFXPointerList;

struct DECLSPEC_DRECORD TPFXRegion
{
public:
	int count;
	int capacity;
	PParticleReferenceArray particleRef;
	PFXPointerList particleOrder;
};


typedef TPFXRegion *PPFXRegion;

enum DECLSPEC_DENUM TPFXSortAccuracy : unsigned char { saLow, saOneTenth, saOneThird, saOneHalf, saHigh };

class PASCALIMPLEMENTATION TgxParticleFXRenderer : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	System::Classes::TList* FManagerList;
	double FLastSortTime;
	int FLastParticleCount;
	bool FZWrite;
	bool FZTest;
	bool FZCull;
	TPFXSortAccuracy FZSortAccuracy;
	float FZMaxDistance;
	Gxs::Material::TgxBlendingMode FBlendingMode;
	System::StaticArray<TPFXRegion, 128> FRegions;
	
protected:
	bool __fastcall StoreZMaxDistance();
	void __fastcall RegisterManager(TgxParticleFXManager* aManager);
	void __fastcall UnRegisterManager(TgxParticleFXManager* aManager);
	void __fastcall UnRegisterAll();
	
public:
	__fastcall virtual TgxParticleFXRenderer(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxParticleFXRenderer();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property double LastSortTime = {read=FLastSortTime};
	__property int LastParticleCount = {read=FLastParticleCount, nodefault};
	
__published:
	__property bool ZWrite = {read=FZWrite, write=FZWrite, default=0};
	__property bool ZTest = {read=FZTest, write=FZTest, default=1};
	__property bool ZCull = {read=FZCull, write=FZCull, default=1};
	__property TPFXSortAccuracy ZSortAccuracy = {read=FZSortAccuracy, write=FZSortAccuracy, default=4};
	__property float ZMaxDistance = {read=FZMaxDistance, write=FZMaxDistance, stored=StoreZMaxDistance};
	__property Gxs::Material::TgxBlendingMode BlendingMode = {read=FBlendingMode, write=FBlendingMode, default=2};
	__property Visible = {default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxParticleFXRenderer(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxSourcePFXVelocityMode : unsigned char { svmAbsolute, svmRelative };

enum DECLSPEC_DENUM TgxSourcePFXPositionMode : unsigned char { spmAbsoluteOffset, spmRelative };

enum DECLSPEC_DENUM TgxSourcePFXDispersionMode : unsigned char { sdmFast, sdmIsotropic };

class PASCALIMPLEMENTATION TgxSourcePFXEffect : public TgxParticleFXEffect
{
	typedef TgxParticleFXEffect inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FInitialVelocity;
	Gxs::Coordinates::TgxCoordinates* FInitialPosition;
	Gxs::Coordinates::TgxCoordinates* FPositionDispersionRange;
	float FVelocityDispersion;
	float FPositionDispersion;
	float FParticleInterval;
	TgxSourcePFXVelocityMode FVelocityMode;
	TgxSourcePFXPositionMode FPositionMode;
	TgxSourcePFXDispersionMode FDispersionMode;
	bool FEnabled;
	bool FDisabledIfOwnerInvisible;
	double FTimeRemainder;
	float FRotationDispersion;
	
protected:
	void __fastcall SetInitialVelocity(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetInitialPosition(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetPositionDispersionRange(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetParticleInterval(const float val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	Stage::Vectorgeometry::TAffineVector __fastcall ParticleAbsoluteInitialPos();
	
public:
	__fastcall virtual TgxSourcePFXEffect(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxSourcePFXEffect();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall Burst(double time, int nb);
	void __fastcall RingExplosion(double time, float minInitialSpeed, float maxInitialSpeed, int nbParticles);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* InitialVelocity = {read=FInitialVelocity, write=SetInitialVelocity};
	__property float VelocityDispersion = {read=FVelocityDispersion, write=FVelocityDispersion};
	__property Gxs::Coordinates::TgxCoordinates* InitialPosition = {read=FInitialPosition, write=SetInitialPosition};
	__property float PositionDispersion = {read=FPositionDispersion, write=FPositionDispersion};
	__property Gxs::Coordinates::TgxCoordinates* PositionDispersionRange = {read=FPositionDispersionRange, write=SetPositionDispersionRange};
	__property float ParticleInterval = {read=FParticleInterval, write=SetParticleInterval};
	__property TgxSourcePFXVelocityMode VelocityMode = {read=FVelocityMode, write=FVelocityMode, default=0};
	__property TgxSourcePFXPositionMode PositionMode = {read=FPositionMode, write=FPositionMode, default=0};
	__property TgxSourcePFXDispersionMode DispersionMode = {read=FDispersionMode, write=FDispersionMode, default=0};
	__property float RotationDispersion = {read=FRotationDispersion, write=FRotationDispersion};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property bool DisabledIfOwnerInvisible = {read=FDisabledIfOwnerInvisible, write=FDisabledIfOwnerInvisible, nodefault};
};


class PASCALIMPLEMENTATION TgxDynamicPFXManager : public TgxParticleFXManager
{
	typedef TgxParticleFXManager inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAcceleration;
	float FFriction;
	double FCurrentTime;
	
protected:
	void __fastcall SetAcceleration(Gxs::Coordinates::TgxCoordinates* const val);
	virtual float __fastcall MaxParticleAge() = 0 ;
	__property double CurrentTime = {read=FCurrentTime};
	
public:
	__fastcall virtual TgxDynamicPFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxDynamicPFXManager();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Acceleration = {read=FAcceleration, write=SetAcceleration};
	__property float Friction = {read=FFriction, write=FFriction};
};


class PASCALIMPLEMENTATION TPFXLifeColor : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Color::TgxColor* FColorInner;
	Gxs::Color::TgxColor* FColorOuter;
	float FLifeTime;
	float FInvLifeTime;
	float FIntervalRatio;
	float FSizeScale;
	bool FDoScale;
	bool FDoRotate;
	float FRotateAngle;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetColorInner(Gxs::Color::TgxColor* const val);
	void __fastcall SetColorOuter(Gxs::Color::TgxColor* const val);
	void __fastcall SetLifeTime(const float val);
	void __fastcall SetSizeScale(const float val);
	void __fastcall SetRotateAngle(const float Value);
	
public:
	__fastcall virtual TPFXLifeColor(System::Classes::TCollection* Collection);
	__fastcall virtual ~TPFXLifeColor();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property float InvLifeTime = {read=FInvLifeTime};
	__property float InvIntervalRatio = {read=FIntervalRatio};
	
__published:
	__property Gxs::Color::TgxColor* ColorInner = {read=FColorInner, write=SetColorInner};
	__property Gxs::Color::TgxColor* ColorOuter = {read=FColorOuter, write=SetColorOuter};
	__property float LifeTime = {read=FLifeTime, write=SetLifeTime};
	__property float SizeScale = {read=FSizeScale, write=SetSizeScale};
	__property float RotateAngle = {read=FRotateAngle, write=SetRotateAngle};
};


class PASCALIMPLEMENTATION TPFXLifeColors : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TPFXLifeColor* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TPFXLifeColor* const val);
	TPFXLifeColor* __fastcall GetItems(int index);
	
public:
	__fastcall TPFXLifeColors(System::Classes::TPersistent* AOwner);
	HIDESBASE TPFXLifeColor* __fastcall Add();
	HIDESBASE TPFXLifeColor* __fastcall FindItemID(int ID);
	__property TPFXLifeColor* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	double __fastcall MaxLifeTime();
	bool __fastcall RotationsDefined();
	bool __fastcall ScalingDefined();
	void __fastcall PrepareIntervalRatios();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TPFXLifeColors() { }
	
};


class PASCALIMPLEMENTATION TgxLifeColoredPFXManager : public TgxDynamicPFXManager
{
	typedef TgxDynamicPFXManager inherited;
	
private:
	TPFXLifeColors* FLifeColors;
	System::Classes::TList* FLifeColorsLookup;
	bool FLifeRotations;
	bool FLifeScaling;
	Gxs::Color::TgxColor* FColorInner;
	Gxs::Color::TgxColor* FColorOuter;
	float FParticleSize;
	
protected:
	void __fastcall SetLifeColors(TPFXLifeColors* const val);
	void __fastcall SetColorInner(Gxs::Color::TgxColor* const val);
	void __fastcall SetColorOuter(Gxs::Color::TgxColor* const val);
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual float __fastcall MaxParticleAge();
	void __fastcall ComputeColors(float &lifeTime, Gxs::Color::TgxColorVector &inner, Gxs::Color::TgxColorVector &outer);
	void __fastcall ComputeInnerColor(float &lifeTime, Gxs::Color::TgxColorVector &inner);
	void __fastcall ComputeOuterColor(float &lifeTime, Gxs::Color::TgxColorVector &outer);
	bool __fastcall ComputeSizeScale(float &lifeTime, float &sizeScale);
	bool __fastcall ComputeRotateAngle(float &lifeTime, float &rotateAngle);
	void __fastcall RotateVertexBuf(Gxs::Vectorlists::TgxAffineVectorList* buf, float lifeTime, const Stage::Vectorgeometry::TAffineVector &axis, float offsetAngle);
	
public:
	__fastcall virtual TgxLifeColoredPFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxLifeColoredPFXManager();
	__property float ParticleSize = {read=FParticleSize, write=FParticleSize};
	__property Gxs::Color::TgxColor* ColorInner = {read=FColorInner, write=SetColorInner};
	__property Gxs::Color::TgxColor* ColorOuter = {read=FColorOuter, write=SetColorOuter};
	__property TPFXLifeColors* LifeColors = {read=FLifeColors, write=SetLifeColors};
	
__published:
	__property BlendingMode = {default=2};
};


typedef void __fastcall (__closure *TPFXDirectRenderEvent)(System::TObject* Sender, TgxParticle* aParticle, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);

typedef void __fastcall (__closure *TPFXProgressEvent)(System::TObject* Sender, const Gxs::Baseclasses::TgxProgressTimes &progressTime, bool &defaultProgress);

typedef void __fastcall (__closure *TPFXParticleProgress)(System::TObject* Sender, const Gxs::Baseclasses::TgxProgressTimes &progressTime, TgxParticle* aParticle, bool &killParticle);

typedef int __fastcall (__closure *TPFXGetParticleCountEvent)(System::TObject* Sender);

class PASCALIMPLEMENTATION TgxCustomPFXManager : public TgxLifeColoredPFXManager
{
	typedef TgxLifeColoredPFXManager inherited;
	
private:
	Gxs::Scene::TDirectRenderEvent FOnInitializeRendering;
	Gxs::Scene::TDirectRenderEvent FOnBeginParticles;
	TPFXDirectRenderEvent FOnRenderParticle;
	Gxs::Scene::TDirectRenderEvent FOnEndParticles;
	Gxs::Scene::TDirectRenderEvent FOnFinalizeRendering;
	TPFXProgressEvent FOnProgress;
	TPFXParticleProgress FOnParticleProgress;
	TPFXGetParticleCountEvent FOnGetParticleCountEvent;
	
protected:
	virtual unsigned __fastcall TexturingMode();
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall BeginParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall RenderParticle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxParticle* aParticle);
	virtual void __fastcall EndParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual int __fastcall ParticleCount();
	
__published:
	__property Gxs::Scene::TDirectRenderEvent OnInitializeRendering = {read=FOnInitializeRendering, write=FOnInitializeRendering};
	__property Gxs::Scene::TDirectRenderEvent OnBeginParticles = {read=FOnBeginParticles, write=FOnBeginParticles};
	__property TPFXDirectRenderEvent OnRenderParticle = {read=FOnRenderParticle, write=FOnRenderParticle};
	__property Gxs::Scene::TDirectRenderEvent OnEndParticles = {read=FOnEndParticles, write=FOnEndParticles};
	__property Gxs::Scene::TDirectRenderEvent OnFinalizeRendering = {read=FOnFinalizeRendering, write=FOnFinalizeRendering};
	__property TPFXProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TPFXParticleProgress OnParticleProgress = {read=FOnParticleProgress, write=FOnParticleProgress};
	__property TPFXGetParticleCountEvent OnGetParticleCountEvent = {read=FOnGetParticleCountEvent, write=FOnGetParticleCountEvent};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
public:
	/* TgxLifeColoredPFXManager.Create */ inline __fastcall virtual TgxCustomPFXManager(System::Classes::TComponent* aOwner) : TgxLifeColoredPFXManager(aOwner) { }
	/* TgxLifeColoredPFXManager.Destroy */ inline __fastcall virtual ~TgxCustomPFXManager() { }
	
};


class PASCALIMPLEMENTATION TgxPolygonPFXManager : public TgxLifeColoredPFXManager
{
	typedef TgxLifeColoredPFXManager inherited;
	
private:
	int FNbSides;
	Stage::Vectorgeometry::TAffineVector Fvx;
	Stage::Vectorgeometry::TAffineVector Fvy;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FVertBuf;
	
protected:
	void __fastcall SetNbSides(const int val);
	virtual unsigned __fastcall TexturingMode();
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall BeginParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall RenderParticle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxParticle* aParticle);
	virtual void __fastcall EndParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxPolygonPFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxPolygonPFXManager();
	
__published:
	__property int NbSides = {read=FNbSides, write=SetNbSides, default=6};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


enum DECLSPEC_DENUM TSpriteColorMode : unsigned char { scmFade, scmInner, scmOuter, scmNone };

enum DECLSPEC_DENUM TSpritesPerTexture : unsigned char { sptOne, sptFour };

class PASCALIMPLEMENTATION TgxBaseSpritePFXManager : public TgxLifeColoredPFXManager
{
	typedef TgxLifeColoredPFXManager inherited;
	
private:
	Gxs::Context::TgxTextureHandle* FTexHandle;
	Stage::Vectorgeometry::TAffineVector Fvx;
	Stage::Vectorgeometry::TAffineVector Fvy;
	Stage::Vectorgeometry::TAffineVector Fvz;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FVertBuf;
	float FAspectRatio;
	float FRotation;
	TgxBaseSpritePFXManager* FShareSprites;
	TSpritesPerTexture FSpritesPerTexture;
	TSpriteColorMode FColorMode;
	
protected:
	virtual void __fastcall PrepareImage(Gxs::Graphics::TgxBitmap32* bmp32, int &texFormat) = 0 ;
	void __fastcall BindTexture(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall SetSpritesPerTexture(const TSpritesPerTexture val);
	void __fastcall SetColorMode(const TSpriteColorMode val);
	void __fastcall SetAspectRatio(const float val);
	bool __fastcall StoreAspectRatio();
	void __fastcall SetRotation(const float val);
	void __fastcall SetShareSprites(TgxBaseSpritePFXManager* const val);
	virtual unsigned __fastcall TexturingMode();
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall BeginParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall RenderParticle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TgxParticle* aParticle);
	virtual void __fastcall EndParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property TSpritesPerTexture SpritesPerTexture = {read=FSpritesPerTexture, write=SetSpritesPerTexture, nodefault};
	
public:
	__fastcall virtual TgxBaseSpritePFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxBaseSpritePFXManager();
	__property TSpriteColorMode ColorMode = {read=FColorMode, write=SetColorMode, nodefault};
	
__published:
	__property float AspectRatio = {read=FAspectRatio, write=SetAspectRatio, stored=StoreAspectRatio};
	__property float Rotation = {read=FRotation, write=SetRotation};
	__property TgxBaseSpritePFXManager* ShareSprites = {read=FShareSprites, write=FShareSprites};
};


typedef void __fastcall (__closure *TPFXPrepareTextureImageEvent)(System::TObject* Sender, Gxs::Graphics::TgxBitmap32* destBmp32, int &texFormat);

class PASCALIMPLEMENTATION TgxCustomSpritePFXManager : public TgxBaseSpritePFXManager
{
	typedef TgxBaseSpritePFXManager inherited;
	
private:
	TPFXPrepareTextureImageEvent FOnPrepareTextureImage;
	
protected:
	virtual void __fastcall PrepareImage(Gxs::Graphics::TgxBitmap32* bmp32, int &texFormat);
	
public:
	__fastcall virtual TgxCustomSpritePFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxCustomSpritePFXManager();
	
__published:
	__property TPFXPrepareTextureImageEvent OnPrepareTextureImage = {read=FOnPrepareTextureImage, write=FOnPrepareTextureImage};
	__property ColorMode = {default=1};
	__property SpritesPerTexture = {default=0};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


class PASCALIMPLEMENTATION TgxPointLightPFXManager : public TgxBaseSpritePFXManager
{
	typedef TgxBaseSpritePFXManager inherited;
	
private:
	int FTexMapSize;
	
protected:
	virtual void __fastcall PrepareImage(Gxs::Graphics::TgxBitmap32* bmp32, int &texFormat);
	void __fastcall SetTexMapSize(const int val);
	
public:
	__fastcall virtual TgxPointLightPFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxPointLightPFXManager();
	
__published:
	__property int TexMapSize = {read=FTexMapSize, write=SetTexMapSize, default=5};
	__property ColorMode = {default=1};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte cPFXNbRegions = System::Byte(0x80);
static _DELPHI_CONST System::Byte cPFXGranularity = System::Byte(0x80);
extern DELPHI_PACKAGE TgxSourcePFXEffect* __fastcall GetOrCreateSourcePFX(Gxs::Scene::TgxBaseSceneObject* obj, const System::UnicodeString name = System::UnicodeString());
}	/* namespace Particlefx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PARTICLEFX)
using namespace Gxs::Particlefx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ParticleFXHPP
