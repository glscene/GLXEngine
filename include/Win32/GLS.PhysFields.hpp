// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.PhysFields.pas' rev: 36.00 (Windows)

#ifndef GLS_PhysFieldsHPP
#define GLS_PhysFieldsHPP

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
#include <Stage.VectorGeometry.hpp>
#include <GLS.XCollection.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Behaviours.hpp>
#include <GLS.PhysInertias.hpp>
#include <GLS.PhysManager.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Physfields
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLUniformGravityEmitter;
class DELPHICLASS TGLRadialGravityEmitter;
class DELPHICLASS TGLDampingFieldEmitter;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLUniformGravityEmitter : public Gls::Physmanager::TGLBaseForceFieldEmitter
{
	typedef Gls::Physmanager::TGLBaseForceFieldEmitter inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* fGravity;
	
protected:
	void __fastcall SetGravity(Gls::Coordinates::TGLCoordinates* const val);
	
public:
	__fastcall virtual TGLUniformGravityEmitter(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLUniformGravityEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gls::Scene::TGLBaseSceneObject* Body);
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Gravity = {read=fGravity, write=SetGravity};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLRadialGravityEmitter : public Gls::Physmanager::TGLBaseForceFieldEmitter
{
	typedef Gls::Physmanager::TGLBaseForceFieldEmitter inherited;
	
private:
	double fMass;
	double fMassOverG;
	
public:
	__fastcall virtual TGLRadialGravityEmitter(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLRadialGravityEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gls::Scene::TGLBaseSceneObject* Body);
	
__published:
	__property double Mass = {read=fMass, write=fMass};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLDampingFieldEmitter : public Gls::Physmanager::TGLBaseForceFieldEmitter
{
	typedef Gls::Physmanager::TGLBaseForceFieldEmitter inherited;
	
private:
	Gls::Behaviours::TGLDamping* fDamping;
	
protected:
	void __fastcall SetDamping(Gls::Behaviours::TGLDamping* const val);
	
public:
	__fastcall virtual TGLDampingFieldEmitter(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLDampingFieldEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gls::Scene::TGLBaseSceneObject* Body);
	
__published:
	__property Gls::Behaviours::TGLDamping* Damping = {read=fDamping, write=SetDamping};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Extended GravitationalConstant = 6.672600E-11;
}	/* namespace Physfields */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_PHYSFIELDS)
using namespace Gls::Physfields;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PhysFieldsHPP
