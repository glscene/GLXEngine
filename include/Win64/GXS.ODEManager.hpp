// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ODEManager.pas' rev: 36.00 (Windows)

#ifndef GXS_ODEManagerHPP
#define GXS_ODEManagerHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Manager.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Objects.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.TerrainRenderer.hpp>
#include <GXS.Graph.hpp>
#include <GXS.ODEUtils.hpp>
#include <ODE.Import.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Odemanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxODEManager;
class DELPHICLASS TgxODECollisionSurface;
class DELPHICLASS TgxODEBehaviour;
class DELPHICLASS TgxODEDynamic;
class DELPHICLASS TgxODEStatic;
class DELPHICLASS TgxODEElements;
class DELPHICLASS TgxODEElementBase;
class DELPHICLASS TgxODEElementBox;
class DELPHICLASS TgxODEElementSphere;
class DELPHICLASS TgxODEElementCapsule;
class DELPHICLASS TgxODEElementCylinder;
class DELPHICLASS TgxODEElementTriMesh;
class DELPHICLASS TgxODEElementPlane;
class DELPHICLASS TgxODEJoints;
class DELPHICLASS TgxODEJointList;
class DELPHICLASS TgxODEJointBase;
class DELPHICLASS TgxODEJointParams;
class DELPHICLASS TgxODEJointHinge;
class DELPHICLASS TgxODEJointBall;
class DELPHICLASS TgxODEJointSlider;
class DELPHICLASS TgxODEJointFixed;
class DELPHICLASS TgxODEJointHinge2;
class DELPHICLASS TgxODEJointUniversal;
class DELPHICLASS TgxODEContactPoint;
class DELPHICLASS TgxODECustomCollider;
class DELPHICLASS TgxODEHeightField;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TgxODECustomCollisionEvent)(Ode::Import::PdxGeom Geom1, Ode::Import::PdxGeom Geom2);

typedef void __fastcall (__closure *TgxODECollisionEvent)(System::TObject* Sender, System::TObject* Object1, System::TObject* Object2, Ode::Import::TdContact &Contact, bool &HandleCollision);

typedef void __fastcall (__closure *TgxODEObjectCollisionEvent)(System::TObject* Sender, System::TObject* Object2, Ode::Import::TdContact &Contact, bool &HandleCollision);

enum DECLSPEC_DENUM TgxODECollisionSurfaceMode : unsigned char { csmMu2, csmFDir1, csmBounce, csmSoftERP, csmSoftCFM, csmMotion1, csmMotion2, csmSlip1, csmSlip2 };

typedef System::Set<TgxODECollisionSurfaceMode, TgxODECollisionSurfaceMode::csmMu2, TgxODECollisionSurfaceMode::csmSlip2> TgxSurfaceModes;

enum DECLSPEC_DENUM TgxODESolverMethod : unsigned char { osmDefault, osmStepFast, osmQuickStep };

class PASCALIMPLEMENTATION TgxODEManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
	
private:
	typedef System::DynamicArray<Ode::Import::TdContact> _TgxODEManager__1;
	
	typedef System::DynamicArray<Ode::Import::TdContactGeom> _TgxODEManager__2;
	
	
private:
	Ode::Import::PdxWorld FWorld;
	Ode::Import::PdxSpace FSpace;
	Ode::Import::TdJointGroupID FContactGroup;
	Gxs::Coordinates::TgxCoordinates* FGravity;
	TgxODECollisionEvent FOnCollision;
	TgxODECustomCollisionEvent FOnCustomCollision;
	int FNumContactJoints;
	int FMaxContacts;
	Gxs::Persistentclasses::TgxPersistentObjectList* FODEBehaviours;
	System::Classes::TList* FRFContactList;
	int FIterations;
	TgxODESolverMethod FSolver;
	_TgxODEManager__1 FContacts;
	_TgxODEManager__2 FContactGeoms;
	Gxs::Scene::TgxRenderPoint* FRenderPoint;
	bool FVisible;
	bool FVisibleAtRunTime;
	Gxs::Color::TgxColor* FGeomColorDynD;
	Gxs::Color::TgxColor* FGeomColorDynE;
	Gxs::Color::TgxColor* FGeomColorStat;
	
protected:
	virtual void __fastcall Loaded();
	void __fastcall CalcContact(System::TObject* Object1, System::TObject* Object2, Ode::Import::TdContact &Contact);
	void __fastcall Collision(Ode::Import::PdxGeom g1, Ode::Import::PdxGeom g2);
	void __fastcall GravityChange(System::TObject* Sender);
	void __fastcall SetMaxContacts(const int Value);
	void __fastcall SetGravity(Gxs::Coordinates::TgxCoordinates* Value);
	void __fastcall SetIterations(const int val);
	TgxODEBehaviour* __fastcall GetODEBehaviour(int index);
	void __fastcall RegisterODEBehaviour(TgxODEBehaviour* ODEBehaviour);
	void __fastcall UnregisterODEBehaviour(TgxODEBehaviour* ODEBehaviour);
	void __fastcall SetRenderPoint(Gxs::Scene::TgxRenderPoint* const Value);
	void __fastcall RenderEvent(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall RenderPointFreed(System::TObject* Sender);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetVisibleAtRunTime(const bool Value);
	void __fastcall SetGeomColorDynE(Gxs::Color::TgxColor* const Value);
	void __fastcall GeomColorChangeDynE(System::TObject* Sender);
	void __fastcall SetGeomColorDynD(Gxs::Color::TgxColor* const Value);
	void __fastcall GeomColorChangeDynD(System::TObject* Sender);
	void __fastcall SetGeomColorStat(Gxs::Color::TgxColor* const Value);
	void __fastcall GeomColorChangeStat(System::TObject* Sender);
	__property TgxODEBehaviour* ODEBehaviours[int index] = {read=GetODEBehaviour};
	
public:
	__fastcall virtual TgxODEManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxODEManager();
	void __fastcall Step(double deltaTime);
	void __fastcall NotifyChange(System::TObject* Sender);
	__property Ode::Import::PdxWorld World = {read=FWorld};
	__property Ode::Import::PdxSpace Space = {read=FSpace};
	__property Ode::Import::TdJointGroupID ContactGroup = {read=FContactGroup};
	__property int NumContactJoints = {read=FNumContactJoints, nodefault};
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Gravity = {read=FGravity, write=SetGravity};
	__property TgxODECollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
	__property TgxODECustomCollisionEvent OnCustomCollision = {read=FOnCustomCollision, write=FOnCustomCollision};
	__property TgxODESolverMethod Solver = {read=FSolver, write=FSolver, nodefault};
	__property int Iterations = {read=FIterations, write=SetIterations, nodefault};
	__property int MaxContacts = {read=FMaxContacts, write=SetMaxContacts, nodefault};
	__property Gxs::Scene::TgxRenderPoint* RenderPoint = {read=FRenderPoint, write=SetRenderPoint};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, nodefault};
	__property Gxs::Color::TgxColor* GeomColorDynD = {read=FGeomColorDynD, write=SetGeomColorDynD};
	__property Gxs::Color::TgxColor* GeomColorDynE = {read=FGeomColorDynE, write=SetGeomColorDynE};
	__property Gxs::Color::TgxColor* GeomColorStat = {read=FGeomColorStat, write=SetGeomColorStat};
};


class PASCALIMPLEMENTATION TgxODECollisionSurface : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	Ode::Import::TdSurfaceParameters FSurfaceParams;
	float FRFCoeff;
	bool FRFEnabled;
	
protected:
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	TgxSurfaceModes __fastcall GetSurfaceMode();
	Ode::Import::TdReal __fastcall GetMu();
	Ode::Import::TdReal __fastcall GetMu2();
	Ode::Import::TdReal __fastcall GetBounce();
	Ode::Import::TdReal __fastcall GetBounce_Vel();
	Ode::Import::TdReal __fastcall GetSoftERP();
	Ode::Import::TdReal __fastcall GetSoftCFM();
	Ode::Import::TdReal __fastcall GetMotion1();
	Ode::Import::TdReal __fastcall GetMotion2();
	Ode::Import::TdReal __fastcall GetSlip1();
	Ode::Import::TdReal __fastcall GetSlip2();
	void __fastcall SetSurfaceMode(TgxSurfaceModes Value);
	void __fastcall SetMu(Ode::Import::TdReal Value);
	void __fastcall SetMu2(Ode::Import::TdReal Value);
	void __fastcall SetBounce(Ode::Import::TdReal Value);
	void __fastcall SetBounce_Vel(Ode::Import::TdReal Value);
	void __fastcall SetSoftERP(Ode::Import::TdReal Value);
	void __fastcall SetSoftCFM(Ode::Import::TdReal Value);
	void __fastcall SetMotion1(Ode::Import::TdReal Value);
	void __fastcall SetMotion2(Ode::Import::TdReal Value);
	void __fastcall SetSlip1(Ode::Import::TdReal Value);
	void __fastcall SetSlip2(Ode::Import::TdReal Value);
	
public:
	__fastcall TgxODECollisionSurface(System::Classes::TPersistent* AOwner);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float RollingFrictionCoeff = {read=FRFCoeff, write=FRFCoeff};
	__property bool RollingFrictionEnabled = {read=FRFEnabled, write=FRFEnabled, nodefault};
	__property TgxSurfaceModes SurfaceMode = {read=GetSurfaceMode, write=SetSurfaceMode, nodefault};
	__property Ode::Import::TdReal Mu = {read=GetMu, write=SetMu};
	__property Ode::Import::TdReal Mu2 = {read=GetMu2, write=SetMu2};
	__property Ode::Import::TdReal Bounce = {read=GetBounce, write=SetBounce};
	__property Ode::Import::TdReal Bounce_Vel = {read=GetBounce_Vel, write=SetBounce_Vel};
	__property Ode::Import::TdReal SoftERP = {read=GetSoftERP, write=SetSoftERP};
	__property Ode::Import::TdReal SoftCFM = {read=GetSoftCFM, write=SetSoftCFM};
	__property Ode::Import::TdReal Motion1 = {read=GetMotion1, write=SetMotion1};
	__property Ode::Import::TdReal Motion2 = {read=GetMotion2, write=SetMotion2};
	__property Ode::Import::TdReal Slip1 = {read=GetSlip1, write=SetSlip1};
	__property Ode::Import::TdReal Slip2 = {read=GetSlip2, write=SetSlip2};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxODECollisionSurface() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxODEElementClass);

class PASCALIMPLEMENTATION TgxODEBehaviour : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxODEManager* FManager;
	System::UnicodeString FManagerName;
	TgxODECollisionSurface* FSurface;
	TgxODEObjectCollisionEvent FOnCollision;
	bool FInitialized;
	Gxs::Scene::TgxBaseSceneObject* FOwnerBaseSceneObject;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetManager(TgxODEManager* Value);
	void __fastcall SetSurface(TgxODECollisionSurface* Value);
	Stage::Vectortypes::TMatrix4f __fastcall GetAbsoluteMatrix();
	
public:
	__fastcall virtual TgxODEBehaviour(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEBehaviour();
	void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall Reinitialize();
	__property bool Initialized = {read=FInitialized, nodefault};
	__property Stage::Vectortypes::TMatrix4f AbsoluteMatrix = {read=GetAbsoluteMatrix};
	
__published:
	__property TgxODEManager* Manager = {read=FManager, write=SetManager};
	__property TgxODECollisionSurface* Surface = {read=FSurface, write=SetSurface};
	__property TgxODEObjectCollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
};


class PASCALIMPLEMENTATION TgxODEDynamic : public TgxODEBehaviour
{
	typedef TgxODEBehaviour inherited;
	
private:
	Ode::Import::PdxBody FBody;
	Ode::Import::TdMass FMass;
	TgxODEElements* FElements;
	bool FEnabled;
	System::Classes::TList* FJointRegister;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetMass(const Ode::Import::TdMass &Value);
	Ode::Import::TdMass __fastcall GetMass();
	void __fastcall AlignBodyToMatrix(const Stage::Vectortypes::TMatrix4f &Mat);
	void __fastcall SetEnabled(const bool Value);
	bool __fastcall GetEnabled();
	void __fastcall RegisterJoint(TgxODEJointBase* Joint);
	void __fastcall UnregisterJoint(TgxODEJointBase* Joint);
	
public:
	__fastcall virtual TgxODEDynamic(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEDynamic();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual TgxODEElementBase* __fastcall AddNewElement(TgxODEElementClass AChild);
	void __fastcall AlignObject();
	Ode::Import::TdMass __fastcall CalculateMass();
	void __fastcall CalibrateCenterOfMass();
	void __fastcall AddForce(const Stage::Vectorgeometry::TAffineVector &Force);
	void __fastcall AddForceAtPos(const Stage::Vectorgeometry::TAffineVector &Force, const Stage::Vectorgeometry::TAffineVector &Pos);
	void __fastcall AddForceAtRelPos(const Stage::Vectorgeometry::TAffineVector &Force, const Stage::Vectorgeometry::TAffineVector &Pos);
	void __fastcall AddRelForce(const Stage::Vectorgeometry::TAffineVector &Force);
	void __fastcall AddRelForceAtPos(const Stage::Vectorgeometry::TAffineVector &Force, const Stage::Vectorgeometry::TAffineVector &Pos);
	void __fastcall AddRelForceAtRelPos(const Stage::Vectorgeometry::TAffineVector &Force, const Stage::Vectorgeometry::TAffineVector &Pos);
	void __fastcall AddTorque(const Stage::Vectorgeometry::TAffineVector &Torque);
	void __fastcall AddRelTorque(const Stage::Vectorgeometry::TAffineVector &Torque);
	__property Ode::Import::PdxBody Body = {read=FBody};
	__property Ode::Import::TdMass Mass = {read=GetMass, write=SetMass};
	
__published:
	__property TgxODEElements* Elements = {read=FElements};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
};


class PASCALIMPLEMENTATION TgxODEStatic : public TgxODEBehaviour
{
	typedef TgxODEBehaviour inherited;
	
private:
	TgxODEElements* FElements;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall AlignElements();
	
public:
	__fastcall virtual TgxODEStatic(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEStatic();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual bool __fastcall UniqueItem();
	virtual TgxODEElementBase* __fastcall AddNewElement(TgxODEElementClass AChild);
	
__published:
	__property TgxODEElements* Elements = {read=FElements};
};


class PASCALIMPLEMENTATION TgxODEElements : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
private:
	TgxODEElementBase* __fastcall GetElement(int index);
	
public:
	__fastcall virtual ~TgxODEElements();
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	void __fastcall Initialize();
	void __fastcall Finalize();
	void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property TgxODEElementBase* Element[int index] = {read=GetElement};
public:
	/* TXCollection.Create */ inline __fastcall virtual TgxODEElements(System::Classes::TPersistent* aOwner) : Gxs::Xcollection::TXCollection(aOwner) { }
	
};


class PASCALIMPLEMENTATION TgxODEElementBase : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	Ode::Import::TdMass FMass;
	Ode::Import::TdReal FDensity;
	Ode::Import::PdxGeom FGeomTransform;
	Ode::Import::PdxGeom FGeomElement;
	Gxs::Coordinates::TgxCoordinates* FPosition;
	Gxs::Coordinates::TgxCoordinates* FDirection;
	Gxs::Coordinates::TgxCoordinates* FUp;
	Stage::Vectortypes::TMatrix4f FLocalMatrix;
	bool FRealignODE;
	bool FInitialized;
	bool FDynamic;
	bool FIsCalculating;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall ODERebuild();
	void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall CoordinateChanged(System::TObject* Sender);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	bool __fastcall IsODEInitialized();
	virtual void __fastcall AlignGeomElementToMatrix(const Stage::Vectortypes::TMatrix4f &Mat);
	void __fastcall SetGeomElement(Ode::Import::PdxGeom aGeom);
	void __fastcall RebuildMatrix();
	void __fastcall RebuildVectors();
	void __fastcall SetDensity(const Ode::Import::TdReal Value);
	void __fastcall SetMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	Stage::Vectortypes::TMatrix4f __fastcall GetMatrix();
	void __fastcall SetPosition(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetDirection(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetUp(Gxs::Coordinates::TgxCoordinates* const Value);
	
public:
	__fastcall virtual TgxODEElementBase(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEElementBase();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	Stage::Vectortypes::TMatrix4f __fastcall AbsoluteMatrix();
	Stage::Vectorgeometry::TAffineVector __fastcall AbsolutePosition();
	__property Stage::Vectortypes::TMatrix4f Matrix = {read=GetMatrix, write=SetMatrix};
	__property Ode::Import::PdxGeom GeomTransform = {read=FGeomTransform};
	__property Ode::Import::PdxGeom Geom = {read=FGeomElement};
	__property bool Initialized = {read=FInitialized, nodefault};
	
__published:
	__property Ode::Import::TdReal Density = {read=FDensity, write=SetDensity};
	__property Gxs::Coordinates::TgxCoordinates* Position = {read=FPosition, write=SetPosition};
	__property Gxs::Coordinates::TgxCoordinates* Direction = {read=FDirection, write=SetDirection};
	__property Gxs::Coordinates::TgxCoordinates* Up = {read=FUp, write=SetUp};
};


class PASCALIMPLEMENTATION TgxODEElementBox : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
private:
	Ode::Import::TdReal FBoxWidth;
	Ode::Import::TdReal FBoxHeight;
	Ode::Import::TdReal FBoxDepth;
	
protected:
	virtual void __fastcall Initialize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall ODERebuild();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	Ode::Import::TdReal __fastcall GetBoxWidth();
	Ode::Import::TdReal __fastcall GetBoxHeight();
	Ode::Import::TdReal __fastcall GetBoxDepth();
	void __fastcall SetBoxWidth(const Ode::Import::TdReal Value);
	void __fastcall SetBoxHeight(const Ode::Import::TdReal Value);
	void __fastcall SetBoxDepth(const Ode::Import::TdReal Value);
	
public:
	__fastcall virtual TgxODEElementBox(Gxs::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal BoxWidth = {read=GetBoxWidth, write=SetBoxWidth};
	__property Ode::Import::TdReal BoxHeight = {read=GetBoxHeight, write=SetBoxHeight};
	__property Ode::Import::TdReal BoxDepth = {read=GetBoxDepth, write=SetBoxDepth};
public:
	/* TgxODEElementBase.Destroy */ inline __fastcall virtual ~TgxODEElementBox() { }
	
};


class PASCALIMPLEMENTATION TgxODEElementSphere : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
private:
	Ode::Import::TdReal FRadius;
	
protected:
	virtual void __fastcall Initialize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall ODERebuild();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	Ode::Import::TdReal __fastcall GetRadius();
	void __fastcall SetRadius(const Ode::Import::TdReal Value);
	
public:
	__fastcall virtual TgxODEElementSphere(Gxs::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
public:
	/* TgxODEElementBase.Destroy */ inline __fastcall virtual ~TgxODEElementSphere() { }
	
};


class PASCALIMPLEMENTATION TgxODEElementCapsule : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
private:
	Ode::Import::TdReal FRadius;
	Ode::Import::TdReal FLength;
	
protected:
	virtual void __fastcall Initialize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall ODERebuild();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	Ode::Import::TdReal __fastcall GetRadius();
	Ode::Import::TdReal __fastcall GetLength();
	void __fastcall SetRadius(const Ode::Import::TdReal Value);
	void __fastcall SetLength(const Ode::Import::TdReal Value);
	
public:
	__fastcall virtual TgxODEElementCapsule(Gxs::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
	__property Ode::Import::TdReal Length = {read=GetLength, write=SetLength};
public:
	/* TgxODEElementBase.Destroy */ inline __fastcall virtual ~TgxODEElementCapsule() { }
	
};


class PASCALIMPLEMENTATION TgxODEElementCylinder : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
private:
	Ode::Import::TdReal FRadius;
	Ode::Import::TdReal FLength;
	
protected:
	virtual void __fastcall Initialize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall ODERebuild();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	Ode::Import::TdReal __fastcall GetRadius();
	Ode::Import::TdReal __fastcall GetLength();
	void __fastcall SetRadius(const Ode::Import::TdReal Value);
	void __fastcall SetLength(const Ode::Import::TdReal Value);
	
public:
	__fastcall virtual TgxODEElementCylinder(Gxs::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
	__property Ode::Import::TdReal Length = {read=GetLength, write=SetLength};
public:
	/* TgxODEElementBase.Destroy */ inline __fastcall virtual ~TgxODEElementCylinder() { }
	
};


class PASCALIMPLEMENTATION TgxODEElementTriMesh : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
private:
	Ode::Import::PdxTriMeshData FTriMeshData;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxIntegerList* FIndices;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetVertices(Gxs::Vectorlists::TgxAffineVectorList* const Value);
	void __fastcall SetIndices(Gxs::Vectorlists::TgxIntegerList* const Value);
	
public:
	__fastcall virtual TgxODEElementTriMesh(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEElementTriMesh();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	void __fastcall RefreshTriMeshData();
	__property Gxs::Vectorlists::TgxAffineVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Gxs::Vectorlists::TgxIntegerList* Indices = {read=FIndices, write=SetIndices};
};


class PASCALIMPLEMENTATION TgxODEElementPlane : public TgxODEElementBase
{
	typedef TgxODEElementBase inherited;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual void __fastcall AlignGeomElementToMatrix(const Stage::Vectortypes::TMatrix4f &Mat);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	__classmethod virtual bool __fastcall CanAddTo(Gxs::Xcollection::TXCollection* collection);
public:
	/* TgxODEElementBase.Create */ inline __fastcall virtual TgxODEElementPlane(Gxs::Xcollection::TXCollection* AOwner) : TgxODEElementBase(AOwner) { }
	/* TgxODEElementBase.Destroy */ inline __fastcall virtual ~TgxODEElementPlane() { }
	
};


class PASCALIMPLEMENTATION TgxODEJoints : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	TgxODEJointBase* operator[](int index) { return this->Joint[index]; }
	
protected:
	TgxODEJointBase* __fastcall GetJoint(int index);
	
public:
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	void __fastcall Initialize();
	void __fastcall Finalize();
	__property TgxODEJointBase* Joint[int index] = {read=GetJoint/*, default*/};
public:
	/* TXCollection.Create */ inline __fastcall virtual TgxODEJoints(System::Classes::TPersistent* aOwner) : Gxs::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxODEJoints() { }
	
};


class PASCALIMPLEMENTATION TgxODEJointList : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxODEJoints* FJoints;
	
protected:
	void __fastcall WriteJoints(System::Classes::TStream* stream);
	void __fastcall ReadJoints(System::Classes::TStream* stream);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxODEJointList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxODEJointList();
	
__published:
	__property TgxODEJoints* Joints = {read=FJoints};
};


enum DECLSPEC_DENUM TJointOption : unsigned char { joBothObjectsMustBeAssigned };

typedef System::Set<TJointOption, TJointOption::joBothObjectsMustBeAssigned, TJointOption::joBothObjectsMustBeAssigned> TJointOptions;

class PASCALIMPLEMENTATION TgxODEJointBase : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	Ode::Import::TdJointID FJointID;
	Gxs::Scene::TgxBaseSceneObject* FObject1;
	Gxs::Scene::TgxBaseSceneObject* FObject2;
	TgxODEManager* FManager;
	System::UnicodeString FObject1Name;
	System::UnicodeString FObject2Name;
	System::UnicodeString FManagerName;
	bool FInitialized;
	bool FEnabled;
	TJointOptions FJointOptions;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	bool __fastcall IsODEInitialized();
	void __fastcall RegisterJointWithObject(Gxs::Scene::TgxBaseSceneObject* Obj);
	void __fastcall UnregisterJointWithObject(Gxs::Scene::TgxBaseSceneObject* Obj);
	void __fastcall Attach();
	void __fastcall SetManager(TgxODEManager* const Value);
	void __fastcall SetObject1(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetObject2(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetJointOptions(const TJointOptions Value);
	__property TJointOptions JointOptions = {read=FJointOptions, write=SetJointOptions, nodefault};
	
public:
	__fastcall virtual TgxODEJointBase(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointBase();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	bool __fastcall IsAttached();
	void __fastcall DoLoaded();
	__property Ode::Import::TdJointID JointID = {read=FJointID};
	__property bool Initialized = {read=FInitialized, nodefault};
	
__published:
	__property TgxODEManager* Manager = {read=FManager, write=SetManager};
	__property Gxs::Scene::TgxBaseSceneObject* Object1 = {read=FObject1, write=SetObject1};
	__property Gxs::Scene::TgxBaseSceneObject* Object2 = {read=FObject2, write=SetObject2};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
};


typedef bool __fastcall (__closure *TgxODESetParamCallback)(int Param, const Ode::Import::TdReal Value);

typedef bool __fastcall (__closure *TgxODEGetParamCallback)(int Param, Ode::Import::TdReal &Value);

class PASCALIMPLEMENTATION TgxODEJointParams : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	TgxODESetParamCallback FSetCallback;
	TgxODEGetParamCallback FGetCallback;
	Ode::Import::TdReal FLoStop;
	Ode::Import::TdReal FHiStop;
	Ode::Import::TdReal FVel;
	Ode::Import::TdReal FFMax;
	Ode::Import::TdReal FFudgeFactor;
	Ode::Import::TdReal FBounce;
	Ode::Import::TdReal FCFM;
	Ode::Import::TdReal FStopERP;
	Ode::Import::TdReal FStopCFM;
	Ode::Import::TdReal FSuspensionERP;
	Ode::Import::TdReal FSuspensionCFM;
	bool FFlagLoStop;
	bool FFlagHiStop;
	bool FFlagVel;
	bool FFlagFMax;
	bool FFlagFudgeFactor;
	bool FFlagBounce;
	bool FFlagCFM;
	bool FFlagStopERP;
	bool FFlagStopCFM;
	bool FFlagSuspensionERP;
	bool FFlagSuspensionCFM;
	
protected:
	Ode::Import::TdReal __fastcall GetLoStop();
	Ode::Import::TdReal __fastcall GetHiStop();
	Ode::Import::TdReal __fastcall GetVel();
	Ode::Import::TdReal __fastcall GetFMax();
	Ode::Import::TdReal __fastcall GetFudgeFactor();
	Ode::Import::TdReal __fastcall GetBounce();
	Ode::Import::TdReal __fastcall GetCFM();
	Ode::Import::TdReal __fastcall GetStopERP();
	Ode::Import::TdReal __fastcall GetStopCFM();
	Ode::Import::TdReal __fastcall GetSuspensionERP();
	Ode::Import::TdReal __fastcall GetSuspensionCFM();
	void __fastcall SetLoStop(const Ode::Import::TdReal Value);
	void __fastcall SetHiStop(const Ode::Import::TdReal Value);
	void __fastcall SetVel(const Ode::Import::TdReal Value);
	void __fastcall SetFMax(const Ode::Import::TdReal Value);
	void __fastcall SetFudgeFactor(const Ode::Import::TdReal Value);
	void __fastcall SetBounce(const Ode::Import::TdReal Value);
	void __fastcall SetCFM(const Ode::Import::TdReal Value);
	void __fastcall SetStopERP(const Ode::Import::TdReal Value);
	void __fastcall SetStopCFM(const Ode::Import::TdReal Value);
	void __fastcall SetSuspensionERP(const Ode::Import::TdReal Value);
	void __fastcall SetSuspensionCFM(const Ode::Import::TdReal Value);
	void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall TgxODEJointParams(System::Classes::TPersistent* AOwner);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyFlagged();
	__property TgxODESetParamCallback SetCallback = {read=FSetCallback, write=FSetCallback};
	__property TgxODEGetParamCallback GetCallback = {read=FGetCallback, write=FGetCallback};
	
__published:
	__property Ode::Import::TdReal LoStop = {read=GetLoStop, write=SetLoStop};
	__property Ode::Import::TdReal HiStop = {read=GetHiStop, write=SetHiStop};
	__property Ode::Import::TdReal Vel = {read=GetVel, write=SetVel};
	__property Ode::Import::TdReal FMax = {read=GetFMax, write=SetFMax};
	__property Ode::Import::TdReal FudgeFactor = {read=GetFudgeFactor, write=SetFudgeFactor};
	__property Ode::Import::TdReal Bounce = {read=GetBounce, write=SetBounce};
	__property Ode::Import::TdReal CFM = {read=GetCFM, write=SetCFM};
	__property Ode::Import::TdReal StopERP = {read=GetStopERP, write=SetStopERP};
	__property Ode::Import::TdReal StopCFM = {read=GetStopCFM, write=SetStopCFM};
	__property Ode::Import::TdReal SuspensionERP = {read=GetSuspensionERP, write=SetSuspensionERP};
	__property Ode::Import::TdReal SuspensionCFM = {read=GetSuspensionCFM, write=SetSuspensionCFM};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxODEJointParams() { }
	
};


class PASCALIMPLEMENTATION TgxODEJointHinge : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAnchor;
	Gxs::Coordinates::TgxCoordinates* FAxis;
	TgxODEJointParams* FAxisParams;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetAxis(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall AxisChange(System::TObject* Sender);
	void __fastcall SetAxisParams(TgxODEJointParams* const Value);
	bool __fastcall SetAxisParam(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxisParam(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TgxODEJointHinge(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointHinge();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gxs::Coordinates::TgxCoordinates* Axis = {read=FAxis, write=SetAxis};
	__property TgxODEJointParams* AxisParams = {read=FAxisParams, write=SetAxisParams};
};


class PASCALIMPLEMENTATION TgxODEJointBall : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAnchor;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxODEJointBall(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointBall();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
};


class PASCALIMPLEMENTATION TgxODEJointSlider : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAxis;
	TgxODEJointParams* FAxisParams;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAxis(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall AxisChange(System::TObject* Sender);
	void __fastcall SetAxisParams(TgxODEJointParams* const Value);
	bool __fastcall SetAxisParam(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxisParam(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TgxODEJointSlider(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointSlider();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Axis = {read=FAxis, write=SetAxis};
	__property TgxODEJointParams* AxisParams = {read=FAxisParams, write=SetAxisParams};
};


class PASCALIMPLEMENTATION TgxODEJointFixed : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Initialize();
public:
	/* TgxODEJointBase.Create */ inline __fastcall virtual TgxODEJointFixed(Gxs::Xcollection::TXCollection* AOwner) : TgxODEJointBase(AOwner) { }
	/* TgxODEJointBase.Destroy */ inline __fastcall virtual ~TgxODEJointFixed() { }
	
};


class PASCALIMPLEMENTATION TgxODEJointHinge2 : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAnchor;
	Gxs::Coordinates::TgxCoordinates* FAxis1;
	Gxs::Coordinates::TgxCoordinates* FAxis2;
	TgxODEJointParams* FAxis1Params;
	TgxODEJointParams* FAxis2Params;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetAxis1(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetAxis2(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall Axis1Change(System::TObject* Sender);
	void __fastcall Axis2Change(System::TObject* Sender);
	void __fastcall SetAxis1Params(TgxODEJointParams* const Value);
	void __fastcall SetAxis2Params(TgxODEJointParams* const Value);
	bool __fastcall SetAxis1Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall SetAxis2Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxis1Param(int Param, Ode::Import::TdReal &Value);
	bool __fastcall GetAxis2Param(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TgxODEJointHinge2(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointHinge2();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gxs::Coordinates::TgxCoordinates* Axis1 = {read=FAxis1, write=SetAxis1};
	__property Gxs::Coordinates::TgxCoordinates* Axis2 = {read=FAxis2, write=SetAxis2};
	__property TgxODEJointParams* Axis1Params = {read=FAxis1Params, write=SetAxis1Params};
	__property TgxODEJointParams* Axis2Params = {read=FAxis2Params, write=SetAxis2Params};
};


class PASCALIMPLEMENTATION TgxODEJointUniversal : public TgxODEJointBase
{
	typedef TgxODEJointBase inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FAnchor;
	Gxs::Coordinates::TgxCoordinates* FAxis1;
	Gxs::Coordinates::TgxCoordinates* FAxis2;
	TgxODEJointParams* FAxis1Params;
	TgxODEJointParams* FAxis2Params;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetAxis1(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetAxis2(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall Axis1Change(System::TObject* Sender);
	void __fastcall Axis2Change(System::TObject* Sender);
	void __fastcall SetAxis1Params(TgxODEJointParams* const Value);
	void __fastcall SetAxis2Params(TgxODEJointParams* const Value);
	bool __fastcall SetAxis1Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall SetAxis2Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxis1Param(int Param, Ode::Import::TdReal &Value);
	bool __fastcall GetAxis2Param(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TgxODEJointUniversal(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODEJointUniversal();
	virtual void __fastcall Initialize();
	virtual void __fastcall StructureChanged();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gxs::Coordinates::TgxCoordinates* Axis1 = {read=FAxis1, write=SetAxis1};
	__property Gxs::Coordinates::TgxCoordinates* Axis2 = {read=FAxis2, write=SetAxis2};
	__property TgxODEJointParams* Axis1Params = {read=FAxis1Params, write=SetAxis1Params};
	__property TgxODEJointParams* Axis2Params = {read=FAxis2Params, write=SetAxis2Params};
};


class PASCALIMPLEMENTATION TgxODEContactPoint : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector Normal;
	float Depth;
public:
	/* TObject.Create */ inline __fastcall TgxODEContactPoint() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxODEContactPoint() { }
	
};


class PASCALIMPLEMENTATION TgxODECustomCollider : public TgxODEBehaviour
{
	typedef TgxODEBehaviour inherited;
	
private:
	Ode::Import::PdxGeom FGeom;
	System::Classes::TList* FContactList;
	System::Classes::TList* FContactCache;
	Stage::Vectortypes::TMatrix4f FTransform;
	float FContactResolution;
	bool FRenderContacts;
	Gxs::Vectorlists::TgxAffineVectorList* FContactRenderPoints;
	float FPointSize;
	Gxs::Color::TgxColor* FContactColor;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual bool __fastcall Collide(const Stage::Vectorgeometry::TAffineVector &aPos, float &Depth, Stage::Vectorgeometry::TAffineVector &cPos, Stage::Vectorgeometry::TAffineVector &cNorm) = 0 ;
	void __fastcall ClearContacts();
	void __fastcall AddContact(Ode::Import::TdReal x, Ode::Import::TdReal y, Ode::Import::TdReal z)/* overload */;
	void __fastcall AddContact(const Stage::Vectorgeometry::TAffineVector &pos)/* overload */;
	int __fastcall ApplyContacts(Ode::Import::PdxGeom o1, Ode::Import::PdxGeom o2, int flags, Ode::Import::PdContactGeom contact, int skip);
	void __fastcall SetTransform(const Stage::Vectortypes::TMatrix4f &ATransform);
	void __fastcall SetContactResolution(const float Value);
	void __fastcall SetRenderContacts(const bool Value);
	void __fastcall SetPointSize(const float Value);
	void __fastcall SetContactColor(Gxs::Color::TgxColor* const Value);
	
public:
	__fastcall virtual TgxODECustomCollider(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxODECustomCollider();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
	
__published:
	__property float ContactResolution = {read=FContactResolution, write=SetContactResolution};
	__property bool RenderContacts = {read=FRenderContacts, write=SetRenderContacts, nodefault};
	__property float PointSize = {read=FPointSize, write=SetPointSize};
	__property Gxs::Color::TgxColor* ContactColor = {read=FContactColor, write=SetContactColor};
};


class PASCALIMPLEMENTATION TgxODEHeightField : public TgxODECustomCollider
{
	typedef TgxODECustomCollider inherited;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual bool __fastcall Collide(const Stage::Vectorgeometry::TAffineVector &aPos, float &Depth, Stage::Vectorgeometry::TAffineVector &cPos, Stage::Vectorgeometry::TAffineVector &cNorm);
	
public:
	__fastcall virtual TgxODEHeightField(Gxs::Xcollection::TXCollection* AOwner);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	__classmethod virtual bool __fastcall CanAddTo(Gxs::Xcollection::TXCollection* collection);
public:
	/* TgxODECustomCollider.Destroy */ inline __fastcall virtual ~TgxODEHeightField() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Classes::TList* vODEObjectRegister;
extern DELPHI_PACKAGE Ode::Import::TdGeomClass vCustomColliderClass;
extern DELPHI_PACKAGE int vCustomColliderClassNum;
extern DELPHI_PACKAGE void __cdecl nearCallBack(void * Data, Ode::Import::PdxGeom o1, Ode::Import::PdxGeom o2);
extern DELPHI_PACKAGE Ode::Import::PdxBody __fastcall GetBodyFromObject(System::TObject* anObject);
extern DELPHI_PACKAGE Ode::Import::PdxBody __fastcall GetBodyFromGLXceneObject(Gxs::Scene::TgxBaseSceneObject* anObject);
extern DELPHI_PACKAGE TgxODECollisionSurface* __fastcall GetSurfaceFromObject(System::TObject* anObject);
extern DELPHI_PACKAGE void __fastcall RegisterGLXceneObject(Gxs::Scene::TgxBaseSceneObject* anObject);
extern DELPHI_PACKAGE void __fastcall UnregisterGLXceneObject(Gxs::Scene::TgxBaseSceneObject* anObject);
extern DELPHI_PACKAGE Gxs::Scene::TgxBaseSceneObject* __fastcall GetGLXceneObject(System::UnicodeString anObjectName);
extern DELPHI_PACKAGE TgxODEStatic* __fastcall GetOdeStatic(Gxs::Scene::TgxBaseSceneObject* obj);
extern DELPHI_PACKAGE TgxODEStatic* __fastcall GetOrCreateOdeStatic(Gxs::Scene::TgxBaseSceneObject* obj);
extern DELPHI_PACKAGE TgxODEDynamic* __fastcall GetOdeDynamic(Gxs::Scene::TgxBaseSceneObject* obj);
extern DELPHI_PACKAGE TgxODEDynamic* __fastcall GetOrCreateOdeDynamic(Gxs::Scene::TgxBaseSceneObject* obj);
extern DELPHI_PACKAGE TgxODEHeightField* __fastcall GetODEHeightField(Gxs::Scene::TgxBaseSceneObject* obj);
extern DELPHI_PACKAGE TgxODEHeightField* __fastcall GetOrCreateODEHeightField(Gxs::Scene::TgxBaseSceneObject* obj);
}	/* namespace Odemanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ODEMANAGER)
using namespace Gxs::Odemanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ODEManagerHPP
