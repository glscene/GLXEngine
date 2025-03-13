// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PhysInertias.pas' rev: 36.00 (Windows)

#ifndef GXS_PhysInertiasHPP
#define GXS_PhysInertiasHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.PhysManager.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Behaviours.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Physinertias
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxParticleInertia;
class DELPHICLASS TgxInertiaTensor;
class DELPHICLASS TgxRigidBodyInertia;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxParticleInertia : public Gxs::Physmanager::TgxBaseInertia
{
	typedef Gxs::Physmanager::TgxBaseInertia inherited;
	
private:
	float FMass;
	Gxs::Coordinates::TgxCoordinates* FTranslationSpeed;
	Gxs::Behaviours::TgxDamping* FTranslationDamping;
	
protected:
	Stage::Vectorgeometry::TAffineVector __fastcall CalcLinearPositionDot();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcLinearMomentumDot();
	void __fastcall SetTranslationSpeed(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetTranslationDamping(Gxs::Behaviours::TgxDamping* const val);
	
public:
	Stage::Vectorgeometry::TAffineVector fForce;
	Stage::Vectorgeometry::TAffineVector LinearPosition;
	Stage::Vectorgeometry::TAffineVector LinearMomentum;
	virtual void __fastcall StateToArray(Gxs::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall ArrayToState(Gxs::Physmanager::TStateArray StateArray, int StatePos);
	virtual void __fastcall CalcStateDot(Gxs::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall RemoveForces();
	virtual void __fastcall CalculateForceFieldForce(Gxs::Physmanager::TgxBaseForceFieldEmitter* ForceFieldEmitter);
	virtual void __fastcall CalcAuxiliary();
	virtual void __fastcall SetUpStartingState();
	virtual double __fastcall CalculateKE();
	virtual double __fastcall CalculatePE();
	virtual void __fastcall SetForce(double x, double y, double z);
	virtual void __fastcall ApplyForce(double x, double y, double z)/* overload */;
	virtual void __fastcall ApplyForce(const Stage::Vectorgeometry::TAffineVector &Force)/* overload */;
	virtual void __fastcall ApplyForce(const Stage::Vectorgeometry::TAffineVector &pos, const Stage::Vectorgeometry::TAffineVector &Force)/* overload */;
	virtual void __fastcall ApplyLocalForce(const Stage::Vectorgeometry::TAffineVector &pos, const Stage::Vectorgeometry::TAffineVector &Force);
	virtual void __fastcall ApplyImpulse(double j, double x, double y, double z)/* overload */;
	virtual void __fastcall ApplyImpulse(float j, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	virtual void __fastcall ApplyDamping(Gxs::Behaviours::TgxDamping* damping);
	__fastcall virtual TgxParticleInertia(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxParticleInertia();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall MirrorTranslation();
	void __fastcall SurfaceBounce(const Stage::Vectortypes::TGLVector &surfaceNormal, float restitution);
	
__published:
	__property float Mass = {read=FMass, write=FMass};
	__property Gxs::Coordinates::TgxCoordinates* TranslationSpeed = {read=FTranslationSpeed, write=SetTranslationSpeed};
	__property Gxs::Behaviours::TgxDamping* TranslationDamping = {read=FTranslationDamping, write=SetTranslationDamping};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxInertiaTensor : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	float fm11;
	float fm12;
	float fm13;
	float fm21;
	float fm22;
	float fm23;
	float fm31;
	float fm32;
	float fm33;
	
public:
	__fastcall virtual TgxInertiaTensor(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TgxInertiaTensor();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
__published:
	__property float m11 = {read=fm11, write=fm11};
	__property float m12 = {read=fm12, write=fm12};
	__property float m13 = {read=fm13, write=fm13};
	__property float m21 = {read=fm21, write=fm21};
	__property float m22 = {read=fm22, write=fm22};
	__property float m23 = {read=fm23, write=fm23};
	__property float m31 = {read=fm31, write=fm31};
	__property float m32 = {read=fm32, write=fm32};
	__property float m33 = {read=fm33, write=fm33};
};


class PASCALIMPLEMENTATION TgxRigidBodyInertia : public TgxParticleInertia
{
	typedef TgxParticleInertia inherited;
	
private:
	double fDensity;
	Stage::Vectorgeometry::TAffineMatrix fBodyInertiaTensor;
	Stage::Vectorgeometry::TAffineMatrix fBodyInverseInertiaTensor;
	TgxInertiaTensor* fInertiaTensor;
	Stage::Vectorgeometry::TAffineMatrix InverseInertiaTensor;
	Gxs::Coordinates::TgxCoordinates* fRotationSpeed;
	Gxs::Behaviours::TgxDamping* FRotationDamping;
	
protected:
	Stage::Vectorgeometry::TAffineVector fTorque;
	void __fastcall SetLinearDamping(Gxs::Behaviours::TgxDamping* const val);
	void __fastcall SetAngularDamping(Gxs::Behaviours::TgxDamping* const val);
	
public:
	Stage::Vectorgeometry::TQuaternion AngularOrientation;
	Stage::Vectortypes::TMatrix3f R;
	Stage::Vectorgeometry::TAffineVector AngularMomentum;
	virtual void __fastcall StateToArray(Gxs::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall ArrayToState(Gxs::Physmanager::TStateArray StateArray, int StatePos);
	virtual void __fastcall CalcStateDot(Gxs::Physmanager::TStateArray &StateArray, int StatePos);
	HIDESBASE void __fastcall ApplyImpulse(double j, double xpos, double ypos, double zpos, double x, double y, double z)/* overload */;
	HIDESBASE void __fastcall ApplyImpulse(float j, const Stage::Vectorgeometry::TAffineVector &position, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	virtual void __fastcall ApplyDamping(Gxs::Behaviours::TgxDamping* damping);
	Stage::Vectorgeometry::TQuaternion __fastcall CalcAngularOrientationDot();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcAngularVelocityDot();
	virtual double __fastcall CalculateKE();
	virtual double __fastcall CalculatePE();
	virtual void __fastcall CalcAuxiliary();
	virtual void __fastcall SetUpStartingState();
	__fastcall virtual TgxRigidBodyInertia(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxRigidBodyInertia();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	System::UnicodeString __fastcall QuaternionToString(const Stage::Vectorgeometry::TQuaternion &Quat);
	virtual void __fastcall RemoveForces();
	void __fastcall SetTorque(double x, double y, double z);
	void __fastcall ApplyTorque(double x, double y, double z);
	virtual void __fastcall ApplyForce(const Stage::Vectorgeometry::TAffineVector &pos, const Stage::Vectorgeometry::TAffineVector &Force)/* overload */;
	virtual void __fastcall ApplyLocalForce(const Stage::Vectortypes::TVector3f &pos, const Stage::Vectortypes::TVector3f &Force);
	void __fastcall ApplyLocalImpulse(double xpos, double ypos, double zpos, double x, double y, double z);
	void __fastcall SetInertiaTensor(TgxInertiaTensor* newVal);
	void __fastcall SetRotationSpeed(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetRotationDamping(Gxs::Behaviours::TgxDamping* const val);
	
__published:
	__property double Density = {read=fDensity, write=fDensity};
	__property TgxInertiaTensor* InertiaTensor = {read=fInertiaTensor, write=SetInertiaTensor};
	__property Gxs::Coordinates::TgxCoordinates* RotationSpeed = {read=fRotationSpeed, write=SetRotationSpeed};
	__property Gxs::Behaviours::TgxDamping* RotationDamping = {read=FRotationDamping, write=SetRotationDamping};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  ApplyImpulse(double j, double x, double y, double z){ TgxParticleInertia::ApplyImpulse(j, x, y, z); }
	inline void __fastcall  ApplyImpulse(float j, const Stage::Vectorgeometry::TAffineVector &normal){ TgxParticleInertia::ApplyImpulse(j, normal); }
	inline void __fastcall  ApplyForce(double x, double y, double z){ TgxParticleInertia::ApplyForce(x, y, z); }
	inline void __fastcall  ApplyForce(const Stage::Vectorgeometry::TAffineVector &Force){ TgxParticleInertia::ApplyForce(Force); }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST bool DebugMode = false;
extern DELPHI_PACKAGE TgxParticleInertia* __fastcall GetOrCreateParticleInertia(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxParticleInertia* __fastcall GetOrCreateParticleInertia(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
extern DELPHI_PACKAGE TgxRigidBodyInertia* __fastcall GetOrCreateRigidBodyInertia(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxRigidBodyInertia* __fastcall GetOrCreateRigidBodyInertia(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Physinertias */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PHYSINERTIAS)
using namespace Gxs::Physinertias;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PhysInertiasHPP
