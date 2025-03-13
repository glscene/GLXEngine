// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.PhysInertias.pas' rev: 36.00 (Windows)

#ifndef GLS_PhysInertiasHPP
#define GLS_PhysInertiasHPP

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
#include <GLS.PersistentClasses.hpp>
#include <GLS.XCollection.hpp>
#include <GLS.BaseClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.PhysManager.hpp>
#include <GLS.Coordinates.hpp>
#include <Stage.Strings.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Behaviours.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Physinertias
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLParticleInertia;
class DELPHICLASS TGLInertiaTensor;
class DELPHICLASS TGLRigidBodyInertia;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLParticleInertia : public Gls::Physmanager::TGLBaseInertia
{
	typedef Gls::Physmanager::TGLBaseInertia inherited;
	
private:
	float FMass;
	Gls::Coordinates::TGLCoordinates* FTranslationSpeed;
	Gls::Behaviours::TGLDamping* FTranslationDamping;
	
protected:
	Stage::Vectorgeometry::TAffineVector __fastcall CalcLinearPositionDot();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcLinearMomentumDot();
	void __fastcall SetTranslationSpeed(Gls::Coordinates::TGLCoordinates* const val);
	void __fastcall SetTranslationDamping(Gls::Behaviours::TGLDamping* const val);
	
public:
	Stage::Vectorgeometry::TAffineVector fForce;
	Stage::Vectorgeometry::TAffineVector LinearPosition;
	Stage::Vectorgeometry::TAffineVector LinearMomentum;
	virtual void __fastcall StateToArray(Gls::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall ArrayToState(Gls::Physmanager::TStateArray StateArray, int StatePos);
	virtual void __fastcall CalcStateDot(Gls::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall RemoveForces();
	virtual void __fastcall CalculateForceFieldForce(Gls::Physmanager::TGLBaseForceFieldEmitter* ForceFieldEmitter);
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
	virtual void __fastcall ApplyDamping(Gls::Behaviours::TGLDamping* damping);
	__fastcall virtual TGLParticleInertia(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLParticleInertia();
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
	__property Gls::Coordinates::TGLCoordinates* TranslationSpeed = {read=FTranslationSpeed, write=SetTranslationSpeed};
	__property Gls::Behaviours::TGLDamping* TranslationDamping = {read=FTranslationDamping, write=SetTranslationDamping};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLInertiaTensor : public Gls::Baseclasses::TGLUpdateAbleObject
{
	typedef Gls::Baseclasses::TGLUpdateAbleObject inherited;
	
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
	__fastcall virtual TGLInertiaTensor(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TGLInertiaTensor();
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


class PASCALIMPLEMENTATION TGLRigidBodyInertia : public TGLParticleInertia
{
	typedef TGLParticleInertia inherited;
	
private:
	double fDensity;
	Stage::Vectorgeometry::TAffineMatrix fBodyInertiaTensor;
	Stage::Vectorgeometry::TAffineMatrix fBodyInverseInertiaTensor;
	TGLInertiaTensor* fInertiaTensor;
	Stage::Vectorgeometry::TAffineMatrix InverseInertiaTensor;
	Gls::Coordinates::TGLCoordinates* fRotationSpeed;
	Gls::Behaviours::TGLDamping* FRotationDamping;
	
protected:
	Stage::Vectorgeometry::TAffineVector fTorque;
	void __fastcall SetLinearDamping(Gls::Behaviours::TGLDamping* const val);
	void __fastcall SetAngularDamping(Gls::Behaviours::TGLDamping* const val);
	
public:
	Stage::Vectorgeometry::TQuaternion AngularOrientation;
	Stage::Vectortypes::TMatrix3f R;
	Stage::Vectorgeometry::TAffineVector AngularMomentum;
	virtual void __fastcall StateToArray(Gls::Physmanager::TStateArray &StateArray, int StatePos);
	virtual void __fastcall ArrayToState(Gls::Physmanager::TStateArray StateArray, int StatePos);
	virtual void __fastcall CalcStateDot(Gls::Physmanager::TStateArray &StateArray, int StatePos);
	HIDESBASE void __fastcall ApplyImpulse(double j, double xpos, double ypos, double zpos, double x, double y, double z)/* overload */;
	HIDESBASE void __fastcall ApplyImpulse(float j, const Stage::Vectorgeometry::TAffineVector &position, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	virtual void __fastcall ApplyDamping(Gls::Behaviours::TGLDamping* damping);
	Stage::Vectorgeometry::TQuaternion __fastcall CalcAngularOrientationDot();
	Stage::Vectorgeometry::TAffineVector __fastcall CalcAngularVelocityDot();
	virtual double __fastcall CalculateKE();
	virtual double __fastcall CalculatePE();
	virtual void __fastcall CalcAuxiliary();
	virtual void __fastcall SetUpStartingState();
	__fastcall virtual TGLRigidBodyInertia(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLRigidBodyInertia();
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
	void __fastcall SetInertiaTensor(TGLInertiaTensor* newVal);
	void __fastcall SetRotationSpeed(Gls::Coordinates::TGLCoordinates* const val);
	void __fastcall SetRotationDamping(Gls::Behaviours::TGLDamping* const val);
	
__published:
	__property double Density = {read=fDensity, write=fDensity};
	__property TGLInertiaTensor* InertiaTensor = {read=fInertiaTensor, write=SetInertiaTensor};
	__property Gls::Coordinates::TGLCoordinates* RotationSpeed = {read=fRotationSpeed, write=SetRotationSpeed};
	__property Gls::Behaviours::TGLDamping* RotationDamping = {read=FRotationDamping, write=SetRotationDamping};
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  ApplyImpulse(double j, double x, double y, double z){ TGLParticleInertia::ApplyImpulse(j, x, y, z); }
	inline void __fastcall  ApplyImpulse(float j, const Stage::Vectorgeometry::TAffineVector &normal){ TGLParticleInertia::ApplyImpulse(j, normal); }
	inline void __fastcall  ApplyForce(double x, double y, double z){ TGLParticleInertia::ApplyForce(x, y, z); }
	inline void __fastcall  ApplyForce(const Stage::Vectorgeometry::TAffineVector &Force){ TGLParticleInertia::ApplyForce(Force); }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST bool DebugMode = false;
extern DELPHI_PACKAGE TGLParticleInertia* __fastcall GetOrCreateParticleInertia(Gls::Scene::TGLBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TGLParticleInertia* __fastcall GetOrCreateParticleInertia(Gls::Scene::TGLBaseSceneObject* obj)/* overload */;
extern DELPHI_PACKAGE TGLRigidBodyInertia* __fastcall GetOrCreateRigidBodyInertia(Gls::Scene::TGLBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TGLRigidBodyInertia* __fastcall GetOrCreateRigidBodyInertia(Gls::Scene::TGLBaseSceneObject* obj)/* overload */;
}	/* namespace Physinertias */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_PHYSINERTIAS)
using namespace Gls::Physinertias;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PhysInertiasHPP
