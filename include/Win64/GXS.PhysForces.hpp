// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PhysForces.pas' rev: 36.00 (Windows)

#ifndef GXS_PhysForcesHPP
#define GXS_PhysForcesHPP

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
#include <Stage.VectorTypes.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Behaviours.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Physforces
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxForce;
class DELPHICLASS TgxHookesSpring;
class DELPHICLASS TgxHookesString;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxForceType : unsigned char { ftHookes, ftGravitation, ftCustom };

typedef void __fastcall (__closure *TOnCustomForce)(void);

class PASCALIMPLEMENTATION TgxForce : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* fObject1;
	Gxs::Scene::TgxBaseSceneObject* fObject2;
	Gxs::Coordinates::TgxCoordinates* fposition1;
	Gxs::Coordinates::TgxCoordinates* fposition2;
	System::UnicodeString object1Name;
	System::UnicodeString object2Name;
	
protected:
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall SetName(const System::UnicodeString val);
	
public:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__fastcall virtual TgxForce(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxForce();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall SetObject1(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetObject2(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetPosition1(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetPosition2(Gxs::Coordinates::TgxCoordinates* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* Object1 = {read=fObject1, write=SetObject1};
	__property Gxs::Scene::TgxBaseSceneObject* Object2 = {read=fObject2, write=SetObject2};
	__property Gxs::Coordinates::TgxCoordinates* Position1 = {read=fposition1, write=SetPosition1};
	__property Gxs::Coordinates::TgxCoordinates* Position2 = {read=fposition2, write=SetPosition2};
};


class PASCALIMPLEMENTATION TgxHookesSpring : public TgxForce
{
	typedef TgxForce inherited;
	
private:
	double fNaturalLength;
	double fElasticity;
	double fLength;
	double fExtension;
	Gxs::Behaviours::TgxDamping* fDamping;
	
public:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__fastcall virtual TgxHookesSpring(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxHookesSpring();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall SetDamping(Gxs::Behaviours::TgxDamping* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
	
__published:
	__property double NaturalLength = {read=fNaturalLength, write=fNaturalLength};
	__property double Elasticity = {read=fElasticity, write=fElasticity};
	__property Gxs::Behaviours::TgxDamping* Damping = {read=fDamping, write=SetDamping};
};


class PASCALIMPLEMENTATION TgxHookesString : public TgxHookesSpring
{
	typedef TgxHookesSpring inherited;
	
public:
	__fastcall virtual TgxHookesString(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxHookesString();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Physforces */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PHYSFORCES)
using namespace Gxs::Physforces;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PhysForcesHPP
