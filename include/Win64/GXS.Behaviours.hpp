// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Behaviours.pas' rev: 36.00 (Windows)

#ifndef GXS_BehavioursHPP
#define GXS_BehavioursHPP

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
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Behaviours
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxDamping;
class DELPHICLASS TgxBInertia;
class DELPHICLASS TgxBAcceleration;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxDamping : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	float FConstant;
	float FLinear;
	float FQuadratic;
	
public:
	__fastcall virtual TgxDamping(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TgxDamping();
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	double __fastcall Calculate(double speed, double deltaTime);
	System::UnicodeString __fastcall AsString(TgxDamping* const damping);
	void __fastcall SetDamping(const float constant = 0.000000E+00f, const float linear = 0.000000E+00f, const float quadratic = 0.000000E+00f);
	
__published:
	__property float Constant = {read=FConstant, write=FConstant};
	__property float Linear = {read=FLinear, write=FLinear};
	__property float Quadratic = {read=FQuadratic, write=FQuadratic};
};


class PASCALIMPLEMENTATION TgxBInertia : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	float FMass;
	Gxs::Coordinates::TgxCoordinates* FTranslationSpeed;
	float FTurnSpeed;
	float FRollSpeed;
	float FPitchSpeed;
	TgxDamping* FTranslationDamping;
	TgxDamping* FRotationDamping;
	bool FDampingEnabled;
	
protected:
	void __fastcall SetTranslationSpeed(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetTranslationDamping(TgxDamping* const val);
	void __fastcall SetRotationDamping(TgxDamping* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TgxBInertia(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBInertia();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall ApplyTranslationAcceleration(const double deltaTime, const Stage::Vectortypes::TVector4f &accel);
	void __fastcall ApplyForce(const double deltaTime, const Stage::Vectortypes::TVector4f &force);
	void __fastcall ApplyTorque(const double deltaTime, const float turnTorque, const float rollTorque, const float pitchTorque);
	void __fastcall MirrorTranslation();
	void __fastcall SurfaceBounce(const Stage::Vectortypes::TVector4f &surfaceNormal, float restitution);
	
__published:
	__property float Mass = {read=FMass, write=FMass};
	__property Gxs::Coordinates::TgxCoordinates* TranslationSpeed = {read=FTranslationSpeed, write=SetTranslationSpeed};
	__property float TurnSpeed = {read=FTurnSpeed, write=FTurnSpeed};
	__property float RollSpeed = {read=FRollSpeed, write=FRollSpeed};
	__property float PitchSpeed = {read=FPitchSpeed, write=FPitchSpeed};
	__property bool DampingEnabled = {read=FDampingEnabled, write=FDampingEnabled, nodefault};
	__property TgxDamping* TranslationDamping = {read=FTranslationDamping, write=SetTranslationDamping};
	__property TgxDamping* RotationDamping = {read=FRotationDamping, write=SetRotationDamping};
};


class PASCALIMPLEMENTATION TgxBAcceleration : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAcceleration;
	
protected:
	void __fastcall SetAcceleration(Gxs::Coordinates::TgxCoordinates* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TgxBAcceleration(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBAcceleration();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Acceleration = {read=FAcceleration, write=FAcceleration};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxBInertia* __fastcall GetInertia(Gxs::Scene::TgxBaseSceneObject* const AGLXceneObject);
extern DELPHI_PACKAGE TgxBInertia* __fastcall GetOrCreateInertia(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBInertia* __fastcall GetOrCreateInertia(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
extern DELPHI_PACKAGE TgxBAcceleration* __fastcall GetOrCreateAcceleration(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBAcceleration* __fastcall GetOrCreateAcceleration(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Behaviours */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BEHAVIOURS)
using namespace Gxs::Behaviours;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BehavioursHPP
