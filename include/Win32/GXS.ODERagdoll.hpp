// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ODERagdoll.pas' rev: 36.00 (Windows)

#ifndef GXS_ODERagdollHPP
#define GXS_ODERagdollHPP

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
#include <GXS.Ragdoll.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <ODE.Import.hpp>
#include <GXS.ODEUtils.hpp>
#include <System.Classes.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Oderagdoll
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxODERagdollCube;
class DELPHICLASS TgxODERagdollWorld;
class DELPHICLASS TgxODERagdollDummyJoint;
class DELPHICLASS TgxODERagdollHingeJoint;
class DELPHICLASS TgxODERagdollUniversalJoint;
class DELPHICLASS TgxODERagdollBone;
class DELPHICLASS TgxODERagdoll;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxODERagdollCube : public Gxs::Objects::TgxCube
{
	typedef Gxs::Objects::TgxCube inherited;
	
public:
	TgxODERagdollBone* Bone;
	TgxODERagdoll* Ragdoll;
public:
	/* TgxCube.Create */ inline __fastcall virtual TgxODERagdollCube(System::Classes::TComponent* AOwner) : Gxs::Objects::TgxCube(AOwner) { }
	
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxODERagdollCube() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxODERagdollCube(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxCube(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdollWorld : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Ode::Import::PdxSpace FSpace;
	Ode::Import::PdxWorld FWorld;
	Ode::Import::TdJointGroupID FContactGroup;
	TgxODERagdoll* FRagdoll;
	bool isWorldCreated;
	
public:
	__fastcall TgxODERagdollWorld();
	__fastcall TgxODERagdollWorld(Ode::Import::PdxWorld World, Ode::Import::PdxSpace Space, Ode::Import::TdJointGroupID ContactGroup);
	__fastcall virtual ~TgxODERagdollWorld();
	void __fastcall WorldUpdate();
	__property Ode::Import::PdxWorld World = {read=FWorld};
	__property Ode::Import::PdxSpace Space = {read=FSpace};
	__property Ode::Import::TdJointGroupID ContactGroup = {read=FContactGroup};
	__property TgxODERagdoll* Ragdoll = {read=FRagdoll};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdollDummyJoint : public Gxs::Ragdoll::TgxRagdolJoint
{
	typedef Gxs::Ragdoll::TgxRagdolJoint inherited;
	
public:
	/* TObject.Create */ inline __fastcall TgxODERagdollDummyJoint() : Gxs::Ragdoll::TgxRagdolJoint() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxODERagdollDummyJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdollHingeJoint : public Gxs::Ragdoll::TgxRagdolJoint
{
	typedef Gxs::Ragdoll::TgxRagdolJoint inherited;
	
private:
	float FParamHiStop;
	float FParamLoStop;
	Stage::Vectorgeometry::TAffineVector FAxis;
	
public:
	__fastcall TgxODERagdollHingeJoint(const Stage::Vectorgeometry::TAffineVector &Axis, float ParamLoStop, float ParamHiStop);
	__property Stage::Vectorgeometry::TAffineVector Axis = {read=FAxis};
	__property float ParamLoStop = {read=FParamLoStop, write=FParamLoStop};
	__property float ParamHiStop = {read=FParamHiStop, write=FParamHiStop};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxODERagdollHingeJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdollUniversalJoint : public TgxODERagdollHingeJoint
{
	typedef TgxODERagdollHingeJoint inherited;
	
private:
	float FParamHiStop2;
	float FParamLoStop2;
	Stage::Vectorgeometry::TAffineVector FAxis2;
	
public:
	__fastcall TgxODERagdollUniversalJoint(const Stage::Vectorgeometry::TAffineVector &Axis, float ParamLoStop, float ParamHiStop, const Stage::Vectorgeometry::TAffineVector &Axis2, float ParamLoStop2, float ParamHiStop2);
	__property Stage::Vectorgeometry::TAffineVector Axis2 = {read=FAxis2};
	__property float ParamLoStop2 = {read=FParamLoStop2, write=FParamLoStop2};
	__property float ParamHiStop2 = {read=FParamHiStop2, write=FParamHiStop2};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxODERagdollUniversalJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdollBone : public Gxs::Ragdoll::TgxRagdolBone
{
	typedef Gxs::Ragdoll::TgxRagdolBone inherited;
	
private:
	TgxODERagdollBone* FOwner;
	TgxODERagdoll* FRagdoll;
	Ode::Import::PdxBody FBody;
	Ode::Import::PdxGeom FGeom;
	Ode::Import::TdJointID FJointId;
	void __fastcall AlignBodyToMatrix(const Stage::Vectortypes::TMatrix4f &Mat);
	
protected:
	virtual void __fastcall Start();
	virtual void __fastcall Align();
	virtual void __fastcall Update();
	virtual void __fastcall Stop();
	
public:
	__fastcall TgxODERagdollBone(TgxODERagdollBone* aOwner);
	__fastcall TgxODERagdollBone(TgxODERagdoll* Ragdoll);
	__property Ode::Import::PdxBody Body = {read=FBody};
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
public:
	/* TgxRagdolBone.Destroy */ inline __fastcall virtual ~TgxODERagdollBone() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxODERagdollBone(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Ragdoll::TgxRagdolBone(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxODERagdoll : public Gxs::Ragdoll::TgxRagdoll
{
	typedef Gxs::Ragdoll::TgxRagdoll inherited;
	
private:
	TgxODERagdollWorld* FODEWorld;
	Gxs::Scene::TgxBaseSceneObject* FGLXceneRoot;
	bool FShowBoundingBoxes;
	
public:
	__fastcall TgxODERagdoll(Gxs::Vectorfileobjects::TgxBaseMesh* aOwner);
	__property TgxODERagdollWorld* ODEWorld = {read=FODEWorld, write=FODEWorld};
	__property Gxs::Scene::TgxBaseSceneObject* GLXceneRoot = {read=FGLXceneRoot, write=FGLXceneRoot};
	__property bool ShowBoundingBoxes = {read=FShowBoundingBoxes, write=FShowBoundingBoxes, nodefault};
public:
	/* TgxRagdoll.Destroy */ inline __fastcall virtual ~TgxODERagdoll() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxODERagdoll(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Ragdoll::TgxRagdoll(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 cMaxContacts = System::Int8(0x4);
extern DELPHI_PACKAGE float vODERagdoll_cDensity;
extern DELPHI_PACKAGE float vODERagdoll_cMass;
}	/* namespace Oderagdoll */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ODERAGDOLL)
using namespace Gxs::Oderagdoll;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ODERagdollHPP
