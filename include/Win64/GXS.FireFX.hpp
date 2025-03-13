// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FireFX.pas' rev: 36.00 (Windows)

#ifndef GXS_FireFXHPP
#define GXS_FireFXHPP

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
#include <GXS.XCollection.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Manager.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Firefx
{
//-- forward type declarations -----------------------------------------------
struct TFireParticle;
class DELPHICLASS TgxFireFXManager;
class DELPHICLASS TgxBFireFX;
//-- type declarations -------------------------------------------------------
typedef TFireParticle *PFireParticle;

struct DECLSPEC_DRECORD TFireParticle
{
public:
	Stage::Vectortypes::TVector4f Position;
	Stage::Vectortypes::TVector4f Speed;
	float Alpha;
	float TimeToLive;
	float LifeLength;
};


typedef System::StaticArray<TFireParticle, 33554432> TFireParticleArray;

typedef TFireParticleArray *PFireParticleArray;

class PASCALIMPLEMENTATION TgxFireFXManager : public Gxs::Baseclasses::TgxCadenceAbleComponent
{
	typedef Gxs::Baseclasses::TgxCadenceAbleComponent inherited;
	
private:
	System::Classes::TList* FClients;
	PFireParticleArray FFireParticles;
	Gxs::Coordinates::TgxCoordinates* FFireDir;
	Gxs::Coordinates::TgxCoordinates* FInitialDir;
	Gxs::Cadencer::TgxCadencer* FCadencer;
	int FMaxParticles;
	int FParticleLife;
	float FParticleSize;
	float FFireDensity;
	float FFireEvaporation;
	float FFireCrown;
	float FParticleInterval;
	float IntervalDelta;
	int NP;
	Gxs::Color::TgxColor* FInnerColor;
	Gxs::Color::TgxColor* FOuterColor;
	float FFireBurst;
	float FFireRadius;
	bool FDisabled;
	bool FPaused;
	bool FUseInterval;
	Gxs::Scene::TgxBaseSceneObject* FReference;
	bool FNoZWrite;
	
protected:
	void __fastcall RegisterClient(TgxBFireFX* aClient);
	void __fastcall DeRegisterClient(TgxBFireFX* aClient);
	void __fastcall DeRegisterAllClients();
	void __fastcall SetFireDir(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetInitialDir(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetCadencer(Gxs::Cadencer::TgxCadencer* const val);
	bool __fastcall StoreParticleSize();
	void __fastcall SetInnerColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetOuterColor(Gxs::Color::TgxColor* const val);
	HIDESBASE void __fastcall SetReference(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetMaxParticles(const int val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall CalcFire(double deltaTime, float ParticleInterval, float ParticleLife, float FireAlpha);
	void __fastcall AffParticle3d(const Gxs::Color::TgxColorVector &Color2, const Stage::Vectortypes::TMatrix4f &mat);
	
public:
	__fastcall virtual TgxFireFXManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxFireFXManager();
	void __fastcall FireInit();
	void __fastcall IsotropicExplosion(float minInitialSpeed, float maxInitialSpeed, float lifeBoostFactor, int nbParticles = 0xffffffff);
	void __fastcall RingExplosion(float minInitialSpeed, float maxInitialSpeed, float lifeBoostFactor, const Stage::Vectorgeometry::TAffineVector &ringVectorX, const Stage::Vectorgeometry::TAffineVector &ringVectorY, int nbParticles = 0xffffffff);
	__property int ParticleCount = {read=NP, nodefault};
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* FireDir = {read=FFireDir, write=SetFireDir};
	__property Gxs::Coordinates::TgxCoordinates* InitialDir = {read=FInitialDir, write=SetInitialDir};
	__property Gxs::Cadencer::TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	__property int MaxParticles = {read=FMaxParticles, write=SetMaxParticles, default=256};
	__property float ParticleSize = {read=FParticleSize, write=FParticleSize, stored=StoreParticleSize};
	__property Gxs::Color::TgxColor* InnerColor = {read=FInnerColor, write=SetInnerColor};
	__property Gxs::Color::TgxColor* OuterColor = {read=FOuterColor, write=SetOuterColor};
	__property float FireDensity = {read=FFireDensity, write=FFireDensity};
	__property float FireEvaporation = {read=FFireEvaporation, write=FFireEvaporation};
	__property float FireCrown = {read=FFireCrown, write=FFireCrown};
	__property int ParticleLife = {read=FParticleLife, write=FParticleLife, default=3};
	__property float FireBurst = {read=FFireBurst, write=FFireBurst};
	__property float FireRadius = {read=FFireRadius, write=FFireRadius};
	__property bool Disabled = {read=FDisabled, write=FDisabled, nodefault};
	__property bool Paused = {read=FPaused, write=FPaused, nodefault};
	__property float ParticleInterval = {read=FParticleInterval, write=FParticleInterval};
	__property bool UseInterval = {read=FUseInterval, write=FUseInterval, nodefault};
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, default=1};
	__property Gxs::Scene::TgxBaseSceneObject* Reference = {read=FReference, write=SetReference};
};


class PASCALIMPLEMENTATION TgxBFireFX : public Gxs::Scene::TgxObjectPostEffect
{
	typedef Gxs::Scene::TgxObjectPostEffect inherited;
	
private:
	TgxFireFXManager* FManager;
	System::UnicodeString FManagerName;
	
protected:
	void __fastcall SetManager(TgxFireFXManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TgxBFireFX(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBFireFX();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TgxFireFXManager* Manager = {read=FManager, write=SetManager};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxBFireFX* __fastcall GetOrCreateFireFX(Gxs::Scene::TgxEffects* effects)/* overload */;
extern DELPHI_PACKAGE TgxBFireFX* __fastcall GetOrCreateFireFX(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Firefx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FIREFX)
using namespace Gxs::Firefx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FireFXHPP
