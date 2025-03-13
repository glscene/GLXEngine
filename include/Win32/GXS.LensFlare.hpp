// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.LensFlare.pas' rev: 36.00 (Windows)

#ifndef GXS_LensFlareHPP
#define GXS_LensFlareHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Context.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.ImageUtils.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Lensflare
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFlareGradient;
class DELPHICLASS TgxLensFlare;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TFlareElement : unsigned char { feGlow, feRing, feStreaks, feRays, feSecondaries };

typedef System::Set<TFlareElement, TFlareElement::feGlow, TFlareElement::feSecondaries> TFlareElements;

class PASCALIMPLEMENTATION TgxFlareGradient : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	Gxs::Color::TgxColor* FFromColor;
	Gxs::Color::TgxColor* FToColor;
	
protected:
	void __fastcall SetFromColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetToColor(Gxs::Color::TgxColor* const val);
	
public:
	__fastcall virtual TgxFlareGradient(System::Classes::TPersistent* AOwner);
	__fastcall TgxFlareGradient(System::Classes::TPersistent* AOwner, const Gxs::Color::TgxColorVector &fromColor, const Gxs::Color::TgxColorVector &toColor);
	__fastcall virtual ~TgxFlareGradient();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Color::TgxColor* fromColor = {read=FFromColor, write=SetFromColor};
	__property Gxs::Color::TgxColor* toColor = {read=FToColor, write=SetToColor};
};


class PASCALIMPLEMENTATION TgxLensFlare : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<float> _TgxLensFlare__1;
	
	typedef System::DynamicArray<float> _TgxLensFlare__2;
	
	
private:
	int FSize;
	float FDeltaTime;
	float FCurrSize;
	int FSeed;
	float FSqueeze;
	int FNumStreaks;
	float FStreakWidth;
	float FStreakAngle;
	int FNumSecs;
	int FResolution;
	bool FAutoZTest;
	TFlareElements FElements;
	_TgxLensFlare__1 FSin20Res;
	_TgxLensFlare__1 FCos20Res;
	_TgxLensFlare__2 FSinRes;
	_TgxLensFlare__2 FCosRes;
	Gxs::Context::TgxTextureHandle* FTexRays;
	bool FFlareIsNotOccluded;
	Gxs::Context::TgxOcclusionQueryHandle* FOcclusionQuery;
	TgxFlareGradient* FGlowGradient;
	TgxFlareGradient* FRingGradient;
	TgxFlareGradient* FStreaksGradient;
	TgxFlareGradient* FRaysGradient;
	TgxFlareGradient* FSecondariesGradient;
	bool FDynamic;
	Gxs::Scene::TgxRenderPoint* FPreRenderPoint;
	
protected:
	void __fastcall SetGlowGradient(TgxFlareGradient* const val);
	void __fastcall SetRingGradient(TgxFlareGradient* const val);
	void __fastcall SetStreaksGradient(TgxFlareGradient* const val);
	void __fastcall SetRaysGradient(TgxFlareGradient* const val);
	void __fastcall SetSecondariesGradient(TgxFlareGradient* const val);
	void __fastcall SetSize(int aValue);
	void __fastcall SetSeed(int aValue);
	void __fastcall SetSqueeze(float aValue);
	bool __fastcall StoreSqueeze();
	void __fastcall SetNumStreaks(int aValue);
	void __fastcall SetStreakWidth(float aValue);
	bool __fastcall StoreStreakWidth();
	void __fastcall SetStreakAngle(float aValue);
	void __fastcall SetNumSecs(int aValue);
	void __fastcall SetResolution(int aValue);
	void __fastcall SetAutoZTest(bool aValue);
	void __fastcall SetElements(TFlareElements aValue);
	void __fastcall SetDynamic(bool aValue);
	void __fastcall SetPreRenderPoint(Gxs::Scene::TgxRenderPoint* const val);
	void __fastcall PreRenderEvent(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall PreRenderPointFreed(System::TObject* Sender);
	void __fastcall SetupRenderingOptions(Gxs::State::TgxStateCache* StateCache);
	void __fastcall RenderRays(Gxs::State::TgxStateCache* StateCache, const float size);
	void __fastcall RenderStreaks(Gxs::State::TgxStateCache* StateCache);
	void __fastcall RenderRing();
	void __fastcall RenderSecondaries(const Stage::Vectorgeometry::TAffineVector &posVector);
	
public:
	__fastcall virtual TgxLensFlare(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxLensFlare();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall PreRender(Gxs::Scene::TgxSceneBuffer* activeBuffer);
	__property float FlareInstantaneousSize = {read=FCurrSize, write=FCurrSize};
	
__published:
	__property TgxFlareGradient* GlowGradient = {read=FGlowGradient, write=SetGlowGradient};
	__property TgxFlareGradient* RingGradient = {read=FRingGradient};
	__property TgxFlareGradient* StreaksGradient = {read=FStreaksGradient};
	__property TgxFlareGradient* RaysGradient = {read=FRaysGradient};
	__property TgxFlareGradient* SecondariesGradient = {read=FSecondariesGradient};
	__property int size = {read=FSize, write=SetSize, default=50};
	__property int Seed = {read=FSeed, write=SetSeed, nodefault};
	__property float Squeeze = {read=FSqueeze, write=SetSqueeze, stored=StoreSqueeze};
	__property int NumStreaks = {read=FNumStreaks, write=SetNumStreaks, default=4};
	__property float StreakWidth = {read=FStreakWidth, write=SetStreakWidth, stored=StoreStreakWidth};
	__property float StreakAngle = {read=FStreakAngle, write=SetStreakAngle};
	__property int NumSecs = {read=FNumSecs, write=SetNumSecs, default=8};
	__property int Resolution = {read=FResolution, write=SetResolution, default=64};
	__property bool AutoZTest = {read=FAutoZTest, write=SetAutoZTest, default=1};
	__property bool FlareIsNotOccluded = {read=FFlareIsNotOccluded, write=FFlareIsNotOccluded, nodefault};
	__property TFlareElements Elements = {read=FElements, write=SetElements, default=31};
	__property bool Dynamic = {read=FDynamic, write=FDynamic, default=1};
	__property Gxs::Scene::TgxRenderPoint* PreRenderPoint = {read=FPreRenderPoint, write=SetPreRenderPoint};
	__property ObjectsSorting = {default=0};
	__property Position;
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxLensFlare(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultFlareElements (System::Set<TFlareElement, TFlareElement::feGlow, TFlareElement::feSecondaries>() << TFlareElement::feGlow << TFlareElement::feRing << TFlareElement::feStreaks << TFlareElement::feRays << TFlareElement::feSecondaries )
}	/* namespace Lensflare */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_LENSFLARE)
using namespace Gxs::Lensflare;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_LensFlareHPP
