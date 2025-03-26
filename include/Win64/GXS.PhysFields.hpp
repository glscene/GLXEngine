// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PhysFields.pas' rev: 36.00 (Windows)

#ifndef GXS_PhysFieldsHPP
#define GXS_PhysFieldsHPP

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
#include <GXS.XCollection.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Behaviours.hpp>
#include <GXS.PhysInertias.hpp>
#include <GXS.PhysManager.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Physfields
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLUniformGravityEmitter;
class DELPHICLASS TGLRadialGravityEmitter;
class DELPHICLASS TgxDampingFieldEmitter;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLUniformGravityEmitter : public Gxs::Physmanager::TgxBaseForceFieldEmitter
{
	typedef Gxs::Physmanager::TgxBaseForceFieldEmitter inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* fGravity;
	
protected:
	void __fastcall SetGravity(Gxs::Coordinates::TgxCoordinates* const val);
	
public:
	__fastcall virtual TGLUniformGravityEmitter(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLUniformGravityEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gxs::Scene::TgxBaseSceneObject* Body);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Gravity = {read=fGravity, write=SetGravity};
};


class PASCALIMPLEMENTATION TGLRadialGravityEmitter : public Gxs::Physmanager::TgxBaseForceFieldEmitter
{
	typedef Gxs::Physmanager::TgxBaseForceFieldEmitter inherited;
	
private:
	double fMass;
	double fMassOverG;
	
public:
	__fastcall virtual TGLRadialGravityEmitter(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLRadialGravityEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gxs::Scene::TgxBaseSceneObject* Body);
	
__published:
	__property double Mass = {read=fMass, write=fMass};
};


class PASCALIMPLEMENTATION TgxDampingFieldEmitter : public Gxs::Physmanager::TgxBaseForceFieldEmitter
{
	typedef Gxs::Physmanager::TgxBaseForceFieldEmitter inherited;
	
private:
	Gxs::Behaviours::TgxDamping* fDamping;
	
protected:
	void __fastcall SetDamping(Gxs::Behaviours::TgxDamping* const val);
	
public:
	__fastcall virtual TgxDampingFieldEmitter(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxDampingFieldEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gxs::Scene::TgxBaseSceneObject* Body);
	
__published:
	__property Gxs::Behaviours::TgxDamping* Damping = {read=fDamping, write=SetDamping};
};


//-- var, const, procedure ---------------------------------------------------
static const double GravitationalConstant = 6.672600E-11;
}	/* namespace Physfields */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PHYSFIELDS)
using namespace Gxs::Physfields;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PhysFieldsHPP
