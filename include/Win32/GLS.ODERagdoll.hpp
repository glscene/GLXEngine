// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ODERagdoll.pas' rev: 36.00 (Windows)

#ifndef GLS_ODERagdollHPP
#define GLS_ODERagdollHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Ragdoll.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Objects.hpp>
#include <GLS.Texture.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <ODE.Import.hpp>
#include <GLS.ODEUtils.hpp>
#include <System.Classes.hpp>
#include <GLS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Oderagdoll
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLODERagdollCube;
class DELPHICLASS TGLODERagdollWorld;
class DELPHICLASS TGLODERagdollDummyJoint;
class DELPHICLASS TGLODERagdollHingeJoint;
class DELPHICLASS TGLODERagdollUniversalJoint;
class DELPHICLASS TGLODERagdollBone;
class DELPHICLASS TGLODERagdoll;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLODERagdollCube : public Gls::Objects::TGLCube
{
	typedef Gls::Objects::TGLCube inherited;
	
public:
	TGLODERagdollBone* Bone;
	TGLODERagdoll* Ragdoll;
public:
	/* TGLCube.Create */ inline __fastcall virtual TGLODERagdollCube(System::Classes::TComponent* AOwner) : Gls::Objects::TGLCube(AOwner) { }
	
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLODERagdollCube() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLODERagdollCube(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Objects::TGLCube(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdollWorld : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Ode::Import::PdxSpace FSpace;
	Ode::Import::PdxWorld FWorld;
	Ode::Import::TdJointGroupID FContactGroup;
	TGLODERagdoll* FRagdoll;
	bool isWorldCreated;
	
public:
	__fastcall TGLODERagdollWorld();
	__fastcall TGLODERagdollWorld(Ode::Import::PdxWorld World, Ode::Import::PdxSpace Space, Ode::Import::TdJointGroupID ContactGroup);
	__fastcall virtual ~TGLODERagdollWorld();
	void __fastcall WorldUpdate();
	__property Ode::Import::PdxWorld World = {read=FWorld};
	__property Ode::Import::PdxSpace Space = {read=FSpace};
	__property Ode::Import::TdJointGroupID ContactGroup = {read=FContactGroup};
	__property TGLODERagdoll* Ragdoll = {read=FRagdoll};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdollDummyJoint : public Gls::Ragdoll::TGLRagdolJoint
{
	typedef Gls::Ragdoll::TGLRagdolJoint inherited;
	
public:
	/* TObject.Create */ inline __fastcall TGLODERagdollDummyJoint() : Gls::Ragdoll::TGLRagdolJoint() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLODERagdollDummyJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdollHingeJoint : public Gls::Ragdoll::TGLRagdolJoint
{
	typedef Gls::Ragdoll::TGLRagdolJoint inherited;
	
private:
	float FParamHiStop;
	float FParamLoStop;
	Stage::Vectorgeometry::TAffineVector FAxis;
	
public:
	__fastcall TGLODERagdollHingeJoint(const Stage::Vectorgeometry::TAffineVector &Axis, float ParamLoStop, float ParamHiStop);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis};
	__property float ParamLoStop = {read=FParamLoStop, write=FParamLoStop};
	__property float ParamHiStop = {read=FParamHiStop, write=FParamHiStop};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLODERagdollHingeJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdollUniversalJoint : public TGLODERagdollHingeJoint
{
	typedef TGLODERagdollHingeJoint inherited;
	
private:
	float FParamHiStop2;
	float FParamLoStop2;
	Stage::Vectorgeometry::TAffineVector FAxis2;
	
public:
	__fastcall TGLODERagdollUniversalJoint(const Stage::Vectorgeometry::TAffineVector &Axis, float ParamLoStop, float ParamHiStop, const Stage::Vectorgeometry::TAffineVector &Axis2, float ParamLoStop2, float ParamHiStop2);
	__property Stage::Vectorgeometry::TAffineVector Axis2 = {read=FAxis2};
	__property float ParamLoStop2 = {read=FParamLoStop2, write=FParamLoStop2};
	__property float ParamHiStop2 = {read=FParamHiStop2, write=FParamHiStop2};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLODERagdollUniversalJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdollBone : public Gls::Ragdoll::TGLRagdolBone
{
	typedef Gls::Ragdoll::TGLRagdolBone inherited;
	
private:
	TGLODERagdollBone* FOwner;
	TGLODERagdoll* FRagdoll;
	Ode::Import::PdxBody FBody;
	Ode::Import::PdxGeom FGeom;
	Ode::Import::TdJointID FJointId;
	void __fastcall AlignBodyToMatrix(const Stage::Vectortypes::TGLMatrix &Mat);
	
protected:
	virtual void __fastcall Start();
	virtual void __fastcall Align();
	virtual void __fastcall Update();
	virtual void __fastcall Stop();
	
public:
	__fastcall TGLODERagdollBone(TGLODERagdollBone* aOwner);
	__fastcall TGLODERagdollBone(TGLODERagdoll* Ragdoll);
	__property Ode::Import::PdxBody Body = {read=FBody};
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
public:
	/* TGLRagdolBone.Destroy */ inline __fastcall virtual ~TGLODERagdollBone() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLODERagdollBone(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Ragdoll::TGLRagdolBone(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODERagdoll : public Gls::Ragdoll::TGLRagdoll
{
	typedef Gls::Ragdoll::TGLRagdoll inherited;
	
private:
	TGLODERagdollWorld* FODEWorld;
	Gls::Scene::TGLBaseSceneObject* FGLSceneRoot;
	bool FShowBoundingBoxes;
	bool FEnabled;
	
public:
	__fastcall TGLODERagdoll(Gls::Vectorfileobjects::TGLBaseMesh* aOwner);
	__property TGLODERagdollWorld* ODEWorld = {read=FODEWorld, write=FODEWorld};
	__property Gls::Scene::TGLBaseSceneObject* GLSceneRoot = {read=FGLSceneRoot, write=FGLSceneRoot};
	__property bool ShowBoundingBoxes = {read=FShowBoundingBoxes, write=FShowBoundingBoxes, nodefault};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
public:
	/* TGLRagdoll.Destroy */ inline __fastcall virtual ~TGLODERagdoll() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLODERagdoll(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Ragdoll::TGLRagdoll(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 cMaxContacts = System::Int8(0x4);
extern DELPHI_PACKAGE float vODERagdoll_cDensity;
extern DELPHI_PACKAGE float vODERagdoll_cMass;
}	/* namespace Oderagdoll */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ODERAGDOLL)
using namespace Gls::Oderagdoll;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ODERagdollHPP
