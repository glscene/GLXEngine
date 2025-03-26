// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Particles.pas' rev: 36.00 (Windows)

#ifndef GXS_ParticlesHPP
#define GXS_ParticlesHPP

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
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Particles
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxParticles;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TgxParticleEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* particle);

class PASCALIMPLEMENTATION TgxParticles : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	float FCubeSize;
	Gxs::Color::TgxColor* FEdgeColor;
	bool FVisibleAtRunTime;
	System::Classes::TList* particlePool;
	int FParticlePoolSize;
	TgxParticleEvent FOnCreateParticle;
	TgxParticleEvent FOnActivateParticle;
	TgxParticleEvent FOnKillParticle;
	TgxParticleEvent FOnDestroyParticle;
	Gxs::Scene::TDirectRenderEvent FOnBeforeRenderParticles;
	Gxs::Scene::TDirectRenderEvent FOnAfterRenderParticles;
	
protected:
	void __fastcall SetCubeSize(const float val);
	void __fastcall SetEdgeColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetVisibleAtRunTime(const bool val);
	void __fastcall SetParticlePoolSize(int val);
	void __fastcall ClearParticlePool();
	
public:
	__fastcall virtual TgxParticles(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxParticles();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	Gxs::Scene::TgxBaseSceneObject* __fastcall CreateParticle();
	void __fastcall KillParticle(Gxs::Scene::TgxBaseSceneObject* aParticle);
	void __fastcall KillParticles();
	
__published:
	__property float CubeSize = {read=FCubeSize, write=SetCubeSize};
	__property Gxs::Color::TgxColor* EdgeColor = {read=FEdgeColor, write=SetEdgeColor};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, default=0};
	__property int ParticlePoolSize = {read=FParticlePoolSize, write=SetParticlePoolSize, default=0};
	__property TgxParticleEvent OnCreateParticle = {read=FOnCreateParticle, write=FOnCreateParticle};
	__property TgxParticleEvent OnActivateParticle = {read=FOnActivateParticle, write=FOnActivateParticle};
	__property TgxParticleEvent OnKillParticle = {read=FOnKillParticle, write=FOnKillParticle};
	__property TgxParticleEvent OnDestroyParticle = {read=FOnDestroyParticle, write=FOnDestroyParticle};
	__property Gxs::Scene::TDirectRenderEvent OnBeforeRenderParticles = {read=FOnBeforeRenderParticles, write=FOnBeforeRenderParticles};
	__property Gxs::Scene::TDirectRenderEvent OnAfterRenderParticles = {read=FOnAfterRenderParticles, write=FOnAfterRenderParticles};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxParticles(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Particles */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PARTICLES)
using namespace Gxs::Particles;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ParticlesHPP
