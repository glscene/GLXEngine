// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.DCE.pas' rev: 36.00 (Windows)

#ifndef GXS_DCEHPP
#define GXS_DCEHPP

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
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.BaseClasses.hpp>
#include <Stage.Manager.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.DCEMisc.hpp>
#include <GXS.EllipseCollision.hpp>
#include <GXS.TerrainRenderer.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Dce
{
//-- forward type declarations -----------------------------------------------
struct TgxDCECollision;
class DELPHICLASS TgxDCEManager;
class DELPHICLASS TgxDCEStatic;
class DELPHICLASS TgxDCEDynamic;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxDCEShape : unsigned char { csEllipsoid, csBox, csFreeform, csTerrain };

enum DECLSPEC_DENUM TgxDCECollisionSelection : unsigned char { ccsDCEStandard, ccsCollisionStandard, ccsHybrid };

struct DECLSPEC_DRECORD TgxDCECollision
{
public:
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector Normal;
	Stage::Vectorgeometry::TAffineVector Bounce;
	bool Nearest;
	bool RootCollision;
	float Distance;
};


typedef void __fastcall (__closure *TgxDCECollisionEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* object1, Gxs::Scene::TgxBaseSceneObject* object2, const TgxDCECollision &CollisionInfo);

typedef void __fastcall (__closure *TgxDCEObjectCollisionEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* ObjectCollided, const TgxDCECollision &CollisionInfo);

class PASCALIMPLEMENTATION TgxDCEManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* FStatics;
	System::Classes::TList* FDynamics;
	float FGravity;
	Gxs::Coordinates::TgxCoordinates* FWorldDirection;
	float FWorldScale;
	float FMovimentScale;
	TgxDCECollisionSelection FStandardiseLayers;
	bool FManualStep;
	TgxDCECollisionEvent FOnCollision;
	void __fastcall SetWorldDirection(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetWorldScale(const float Value);
	int __fastcall GetDynamicCount();
	int __fastcall GetStaticCount();
	
protected:
	void __fastcall RegisterStatic(TgxDCEStatic* aClient);
	void __fastcall DeRegisterStatic(TgxDCEStatic* aClient);
	void __fastcall DeRegisterAllStatics();
	void __fastcall RegisterDynamic(TgxDCEDynamic* aClient);
	void __fastcall DeRegisterDynamic(TgxDCEDynamic* aClient);
	void __fastcall DeRegisterAllDynamics();
	
public:
	__fastcall virtual TgxDCEManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxDCEManager();
	float __fastcall MoveByDistance(TgxDCEDynamic* &Body, const Stage::Vectorgeometry::TAffineVector &deltaS, const Stage::Vectorgeometry::TAffineVector &deltaAbsS);
	void __fastcall Step(double deltaTime);
	__property int DynamicCount = {read=GetDynamicCount, nodefault};
	__property int StaticCount = {read=GetStaticCount, nodefault};
	
__published:
	__property float Gravity = {read=FGravity, write=FGravity};
	__property Gxs::Coordinates::TgxCoordinates* WorldDirection = {read=FWorldDirection, write=SetWorldDirection};
	__property float WorldScale = {read=FWorldScale, write=SetWorldScale};
	__property float MovimentScale = {read=FMovimentScale, write=FMovimentScale};
	__property TgxDCECollisionSelection StandardiseLayers = {read=FStandardiseLayers, write=FStandardiseLayers, nodefault};
	__property bool ManualStep = {read=FManualStep, write=FManualStep, nodefault};
	__property TgxDCECollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
};


class PASCALIMPLEMENTATION TgxDCEStatic : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxDCEManager* FManager;
	System::UnicodeString FManagerName;
	bool FActive;
	TgxDCEShape FShape;
	int FLayer;
	bool FSolid;
	float FFriction;
	float FBounceFactor;
	Gxs::Coordinates::TgxCoordinates* FSize;
	TgxDCEObjectCollisionEvent FOnCollision;
	void __fastcall SetShape(const TgxDCEShape Value);
	void __fastcall SetFriction(const float Value);
	void __fastcall SetBounceFactor(const float Value);
	void __fastcall SetSize(Gxs::Coordinates::TgxCoordinates* const Value);
	
protected:
	void __fastcall SetManager(TgxDCEManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TgxDCEStatic(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxDCEStatic();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property TgxDCEObjectCollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
	
__published:
	__property bool Active = {read=FActive, write=FActive, nodefault};
	__property TgxDCEManager* Manager = {read=FManager, write=SetManager};
	__property TgxDCEShape Shape = {read=FShape, write=SetShape, nodefault};
	__property int Layer = {read=FLayer, write=FLayer, nodefault};
	__property bool Solid = {read=FSolid, write=FSolid, nodefault};
	__property float Friction = {read=FFriction, write=SetFriction};
	__property float BounceFactor = {read=FBounceFactor, write=SetBounceFactor};
	__property Gxs::Coordinates::TgxCoordinates* Size = {read=FSize, write=SetSize};
};


enum DECLSPEC_DENUM TgxDCESlideOrBounce : unsigned char { csbSlide, csbBounce };

class PASCALIMPLEMENTATION TgxDCEDynamic : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxDCEManager* FManager;
	System::UnicodeString FManagerName;
	bool FActive;
	bool FUseGravity;
	int FLayer;
	bool FSolid;
	float FFriction;
	float FBounceFactor;
	Gxs::Coordinates::TgxCoordinates* FSize;
	System::Byte FMaxRecursionDepth;
	TgxDCESlideOrBounce FSlideOrBounce;
	Stage::Vectorgeometry::TAffineVector FAccel;
	Stage::Vectorgeometry::TAffineVector FSpeed;
	Stage::Vectorgeometry::TAffineVector FAbsAccel;
	Stage::Vectorgeometry::TAffineVector FAbsSpeed;
	Stage::Vectorgeometry::TAffineVector FGravSpeed;
	float FTotalFriction;
	bool FInGround;
	Stage::Vectorgeometry::TAffineVector FGroundNormal;
	float FJumpHeight;
	float FJumpForce;
	float FJumpSpeed;
	bool FJumping;
	TgxDCEObjectCollisionEvent FOnCollision;
	void __fastcall SetFriction(const float Value);
	void __fastcall SetBounceFactor(const float Value);
	void __fastcall SetSize(Gxs::Coordinates::TgxCoordinates* const Value);
	
protected:
	void __fastcall SetManager(TgxDCEManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TgxDCEDynamic(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxDCEDynamic();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	void __fastcall ApplyAccel(const Stage::Vectorgeometry::TAffineVector &NewAccel)/* overload */;
	void __fastcall ApplyAccel(float x, float y, float z)/* overload */;
	void __fastcall ApplyAbsAccel(const Stage::Vectorgeometry::TAffineVector &NewAccel)/* overload */;
	void __fastcall ApplyAbsAccel(float x, float y, float z)/* overload */;
	void __fastcall StopAccel();
	void __fastcall StopAbsAccel();
	void __fastcall Jump(float jHeight, float jSpeed);
	void __fastcall Move(const Stage::Vectorgeometry::TAffineVector &deltaS, double deltaTime);
	void __fastcall MoveTo(const Stage::Vectorgeometry::TAffineVector &Position, float Amount);
	void __fastcall DoMove(double deltaTime);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__property Stage::Vectorgeometry::TAffineVector Speed = {read=FSpeed, write=FSpeed};
	__property bool InGround = {read=FInGround, nodefault};
	__property System::Byte MaxRecursionDepth = {read=FMaxRecursionDepth, write=FMaxRecursionDepth, nodefault};
	__property TgxDCEObjectCollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
	
__published:
	__property bool Active = {read=FActive, write=FActive, nodefault};
	__property TgxDCEManager* Manager = {read=FManager, write=SetManager};
	__property bool UseGravity = {read=FUseGravity, write=FUseGravity, nodefault};
	__property int Layer = {read=FLayer, write=FLayer, nodefault};
	__property bool Solid = {read=FSolid, write=FSolid, nodefault};
	__property float Friction = {read=FFriction, write=SetFriction};
	__property float BounceFactor = {read=FBounceFactor, write=SetBounceFactor};
	__property Gxs::Coordinates::TgxCoordinates* Size = {read=FSize, write=SetSize};
	__property TgxDCESlideOrBounce SlideOrBounce = {read=FSlideOrBounce, write=FSlideOrBounce, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxDCEStatic* __fastcall GetOrCreateDCEStatic(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxDCEStatic* __fastcall GetOrCreateDCEStatic(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
extern DELPHI_PACKAGE TgxDCEDynamic* __fastcall GetOrCreateDCEDynamic(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxDCEDynamic* __fastcall GetOrCreateDCEDynamic(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Dce */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_DCE)
using namespace Gxs::Dce;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_DCEHPP
