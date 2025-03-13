// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.PhysForces.pas' rev: 36.00 (Windows)

#ifndef GLS_PhysForcesHPP
#define GLS_PhysForcesHPP

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
#include <GLS.XCollection.hpp>
#include <GLS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Behaviours.hpp>
#include <GLS.Coordinates.hpp>
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Physforces
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLForce;
class DELPHICLASS TGLHookesSpring;
class DELPHICLASS TGLHookesString;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLForceType : unsigned char { ftHookes, ftGravitation, ftCustom };

typedef void __fastcall (__closure *TOnCustomForce)(void);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLForce : public Gls::Xcollection::TXCollectionItem
{
	typedef Gls::Xcollection::TXCollectionItem inherited;
	
private:
	Gls::Scene::TGLBaseSceneObject* fObject1;
	Gls::Scene::TGLBaseSceneObject* fObject2;
	Gls::Coordinates::TGLCoordinates* fposition1;
	Gls::Coordinates::TGLCoordinates* fposition2;
	System::UnicodeString object1Name;
	System::UnicodeString object2Name;
	
protected:
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall SetName(const System::UnicodeString val);
	
public:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__fastcall virtual TGLForce(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLForce();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall SetObject1(Gls::Scene::TGLBaseSceneObject* const val);
	void __fastcall SetObject2(Gls::Scene::TGLBaseSceneObject* const val);
	void __fastcall SetPosition1(Gls::Coordinates::TGLCoordinates* const val);
	void __fastcall SetPosition2(Gls::Coordinates::TGLCoordinates* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
	
__published:
	__property Gls::Scene::TGLBaseSceneObject* Object1 = {read=fObject1, write=SetObject1};
	__property Gls::Scene::TGLBaseSceneObject* Object2 = {read=fObject2, write=SetObject2};
	__property Gls::Coordinates::TGLCoordinates* Position1 = {read=fposition1, write=SetPosition1};
	__property Gls::Coordinates::TGLCoordinates* Position2 = {read=fposition2, write=SetPosition2};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLHookesSpring : public TGLForce
{
	typedef TGLForce inherited;
	
private:
	double fNaturalLength;
	double fElasticity;
	double fLength;
	double fExtension;
	Gls::Behaviours::TGLDamping* fDamping;
	
public:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	__fastcall virtual TGLHookesSpring(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLHookesSpring();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	void __fastcall SetDamping(Gls::Behaviours::TGLDamping* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
	
__published:
	__property double NaturalLength = {read=fNaturalLength, write=fNaturalLength};
	__property double Elasticity = {read=fElasticity, write=fElasticity};
	__property Gls::Behaviours::TGLDamping* Damping = {read=fDamping, write=SetDamping};
};


class PASCALIMPLEMENTATION TGLHookesString : public TGLHookesSpring
{
	typedef TGLHookesSpring inherited;
	
public:
	__fastcall virtual TGLHookesString(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLHookesString();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForce();
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Physforces */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_PHYSFORCES)
using namespace Gls::Physforces;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PhysForcesHPP
