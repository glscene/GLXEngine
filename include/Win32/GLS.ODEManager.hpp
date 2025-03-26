// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ODEManager.pas' rev: 36.00 (Windows)

#ifndef GLS_ODEManagerHPP
#define GLS_ODEManagerHPP

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
#include <System.Types.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GLS.PersistentClasses.hpp>
#include <Stage.Manager.hpp>
#include <GLS.XCollection.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Objects.hpp>
#include <GLS.Color.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.State.hpp>
#include <GLS.TerrainRenderer.hpp>
#include <GLS.Graph.hpp>
#include <ODE.Import.hpp>
#include <GLS.ODEUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Odemanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLODEManager;
class DELPHICLASS TGLODECollisionSurface;
class DELPHICLASS TGLODEBehaviour;
class DELPHICLASS TGLODEDynamic;
class DELPHICLASS TGLODEStatic;
class DELPHICLASS TGLODEElements;
class DELPHICLASS TGLODEElementBase;
class DELPHICLASS TGLODEElementBox;
class DELPHICLASS TGLODEElementSphere;
class DELPHICLASS TGLODEElementCapsule;
class DELPHICLASS TGLODEElementCylinder;
class DELPHICLASS TGLODEElementTriMesh;
class DELPHICLASS TGLODEElementPlane;
class DELPHICLASS TGLODEJoints;
class DELPHICLASS TGLODEJointList;
class DELPHICLASS TGLODEJointBase;
class DELPHICLASS TGLODEJointParams;
class DELPHICLASS TGLODEJointHinge;
class DELPHICLASS TGLODEJointBall;
class DELPHICLASS TGLODEJointSlider;
class DELPHICLASS TGLODEJointFixed;
class DELPHICLASS TGLODEJointHinge2;
class DELPHICLASS TGLODEJointUniversal;
class DELPHICLASS TGLODEContactPoint;
class DELPHICLASS TGLODECustomCollider;
class DELPHICLASS TGLODEHeightField;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TGLODECustomCollisionEvent)(Ode::Import::PdxGeom Geom1, Ode::Import::PdxGeom Geom2);

typedef void __fastcall (__closure *TGLODECollisionEvent)(System::TObject* Sender, System::TObject* Object1, System::TObject* Object2, Ode::Import::TdContact &Contact, bool &HandleCollision);

typedef void __fastcall (__closure *TGLODEObjectCollisionEvent)(System::TObject* Sender, System::TObject* Object2, Ode::Import::TdContact &Contact, bool &HandleCollision);

enum DECLSPEC_DENUM TGLODECollisionSurfaceMode : unsigned char { csmMu2, csmFDir1, csmBounce, csmSoftERP, csmSoftCFM, csmMotion1, csmMotion2, csmSlip1, csmSlip2 };

typedef System::Set<TGLODECollisionSurfaceMode, TGLODECollisionSurfaceMode::csmMu2, TGLODECollisionSurfaceMode::csmSlip2> TGLODESurfaceModes;

enum DECLSPEC_DENUM TGLODESolverMethod : unsigned char { osmDefault, osmStepFast, osmQuickStep };

class PASCALIMPLEMENTATION TGLODEManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
	
private:
	typedef System::DynamicArray<Ode::Import::TdContact> _TGLODEManager__1;
	
	typedef System::DynamicArray<Ode::Import::TdContactGeom> _TGLODEManager__2;
	
	
private:
	Ode::Import::PdxWorld FWorld;
	Ode::Import::PdxSpace FSpace;
	Ode::Import::TdJointGroupID FContactGroup;
	Gls::Coordinates::TGLCoordinates* FGravity;
	TGLODECollisionEvent FOnCollision;
	TGLODECustomCollisionEvent FOnCustomCollision;
	int FNumContactJoints;
	int FMaxContacts;
	Gls::Persistentclasses::TGLPersistentObjectList* FODEBehaviours;
	System::Classes::TList* FRFContactList;
	int FIterations;
	TGLODESolverMethod FSolver;
	_TGLODEManager__1 FContacts;
	_TGLODEManager__2 FContactGeoms;
	Gls::Scene::TGLRenderPoint* FRenderPoint;
	bool FVisible;
	bool FVisibleAtRunTime;
	Gls::Color::TGLColor* FGeomColorDynD;
	Gls::Color::TGLColor* FGeomColorDynE;
	Gls::Color::TGLColor* FGeomColorStat;
	
protected:
	virtual void __fastcall Loaded();
	void __fastcall CalcContact(System::TObject* Object1, System::TObject* Object2, Ode::Import::TdContact &Contact);
	void __fastcall Collision(Ode::Import::PdxGeom g1, Ode::Import::PdxGeom g2);
	void __fastcall GravityChange(System::TObject* Sender);
	void __fastcall SetMaxContacts(const int Value);
	void __fastcall SetGravity(Gls::Coordinates::TGLCoordinates* Value);
	void __fastcall SetIterations(const int val);
	TGLODEBehaviour* __fastcall GetODEBehaviour(int index);
	void __fastcall RegisterODEBehaviour(TGLODEBehaviour* ODEBehaviour);
	void __fastcall UnregisterODEBehaviour(TGLODEBehaviour* ODEBehaviour);
	void __fastcall SetRenderPoint(Gls::Scene::TGLRenderPoint* const Value);
	void __fastcall RenderEvent(System::TObject* Sender, Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	void __fastcall RenderPointFreed(System::TObject* Sender);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetVisibleAtRunTime(const bool Value);
	void __fastcall SetGeomColorDynE(Gls::Color::TGLColor* const Value);
	void __fastcall GeomColorChangeDynE(System::TObject* Sender);
	void __fastcall SetGeomColorDynD(Gls::Color::TGLColor* const Value);
	void __fastcall GeomColorChangeDynD(System::TObject* Sender);
	void __fastcall SetGeomColorStat(Gls::Color::TGLColor* const Value);
	void __fastcall GeomColorChangeStat(System::TObject* Sender);
	__property TGLODEBehaviour* ODEBehaviours[int index] = {read=GetODEBehaviour};
	
public:
	__fastcall virtual TGLODEManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLODEManager();
	void __fastcall Step(double deltaTime);
	void __fastcall NotifyChange(System::TObject* Sender);
	__property Ode::Import::PdxWorld World = {read=FWorld};
	__property Ode::Import::PdxSpace Space = {read=FSpace};
	__property Ode::Import::TdJointGroupID ContactGroup = {read=FContactGroup};
	__property int NumContactJoints = {read=FNumContactJoints, nodefault};
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Gravity = {read=FGravity, write=SetGravity};
	__property TGLODECollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
	__property TGLODECustomCollisionEvent OnCustomCollision = {read=FOnCustomCollision, write=FOnCustomCollision};
	__property TGLODESolverMethod Solver = {read=FSolver, write=FSolver, nodefault};
	__property int Iterations = {read=FIterations, write=SetIterations, nodefault};
	__property int MaxContacts = {read=FMaxContacts, write=SetMaxContacts, nodefault};
	__property Gls::Scene::TGLRenderPoint* RenderPoint = {read=FRenderPoint, write=SetRenderPoint};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, nodefault};
	__property Gls::Color::TGLColor* GeomColorDynD = {read=FGeomColorDynD, write=SetGeomColorDynD};
	__property Gls::Color::TGLColor* GeomColorDynE = {read=FGeomColorDynE, write=SetGeomColorDynE};
	__property Gls::Color::TGLColor* GeomColorStat = {read=FGeomColorStat, write=SetGeomColorStat};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODECollisionSurface : public System::Classes::TPersistent
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
	TGLODESurfaceModes __fastcall GetSurfaceMode();
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
	void __fastcall SetSurfaceMode(TGLODESurfaceModes Value);
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
	__fastcall TGLODECollisionSurface(System::Classes::TPersistent* AOwner);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float RollingFrictionCoeff = {read=FRFCoeff, write=FRFCoeff};
	__property bool RollingFrictionEnabled = {read=FRFEnabled, write=FRFEnabled, nodefault};
	__property TGLODESurfaceModes SurfaceMode = {read=GetSurfaceMode, write=SetSurfaceMode, nodefault};
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
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLODECollisionSurface() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGLODEElementClass;

class PASCALIMPLEMENTATION TGLODEBehaviour : public Gls::Scene::TGLBehaviour
{
	typedef Gls::Scene::TGLBehaviour inherited;
	
private:
	TGLODEManager* FManager;
	System::UnicodeString FManagerName;
	TGLODECollisionSurface* FSurface;
	TGLODEObjectCollisionEvent FOnCollision;
	bool FInitialized;
	Gls::Scene::TGLBaseSceneObject* FOwnerBaseSceneObject;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetManager(TGLODEManager* Value);
	void __fastcall SetSurface(TGLODECollisionSurface* Value);
	Stage::Vectortypes::TGLMatrix __fastcall GetAbsoluteMatrix();
	
public:
	__fastcall virtual TGLODEBehaviour(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEBehaviour();
	void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	void __fastcall Reinitialize();
	__property bool Initialized = {read=FInitialized, nodefault};
	__property Stage::Vectortypes::TGLMatrix AbsoluteMatrix = {read=GetAbsoluteMatrix};
	
__published:
	__property TGLODEManager* Manager = {read=FManager, write=SetManager};
	__property TGLODECollisionSurface* Surface = {read=FSurface, write=SetSurface};
	__property TGLODEObjectCollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
};


class PASCALIMPLEMENTATION TGLODEDynamic : public TGLODEBehaviour
{
	typedef TGLODEBehaviour inherited;
	
private:
	Ode::Import::PdxBody FBody;
	Ode::Import::TdMass FMass;
	TGLODEElements* FElements;
	bool FEnabled;
	System::Classes::TList* FJointRegister;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetMass(const Ode::Import::TdMass &Value);
	Ode::Import::TdMass __fastcall GetMass();
	void __fastcall AlignBodyToMatrix(const Stage::Vectortypes::TGLMatrix &Mat);
	void __fastcall SetEnabled(const bool Value);
	bool __fastcall GetEnabled();
	void __fastcall RegisterJoint(TGLODEJointBase* Joint);
	void __fastcall UnregisterJoint(TGLODEJointBase* Joint);
	
public:
	__fastcall virtual TGLODEDynamic(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEDynamic();
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual bool __fastcall UniqueItem();
	DYNAMIC TGLODEElementBase* __fastcall AddNewElement(TGLODEElementClass AChild);
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
	__property TGLODEElements* Elements = {read=FElements};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
};


class PASCALIMPLEMENTATION TGLODEStatic : public TGLODEBehaviour
{
	typedef TGLODEBehaviour inherited;
	
private:
	TGLODEElements* FElements;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall AlignElements();
	
public:
	__fastcall virtual TGLODEStatic(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEStatic();
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual bool __fastcall UniqueItem();
	DYNAMIC TGLODEElementBase* __fastcall AddNewElement(TGLODEElementClass AChild);
	
__published:
	__property TGLODEElements* Elements = {read=FElements};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElements : public Gls::Xcollection::TXCollection
{
	typedef Gls::Xcollection::TXCollection inherited;
	
private:
	TGLODEElementBase* __fastcall GetElement(int index);
	
public:
	__fastcall virtual ~TGLODEElements();
	__classmethod virtual Gls::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	void __fastcall Initialize();
	void __fastcall Finalize();
	void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__property TGLODEElementBase* Element[int index] = {read=GetElement};
public:
	/* TXCollection.Create */ inline __fastcall virtual TGLODEElements(System::Classes::TPersistent* aOwner) : Gls::Xcollection::TXCollection(aOwner) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementBase : public Gls::Xcollection::TXCollectionItem
{
	typedef Gls::Xcollection::TXCollectionItem inherited;
	
private:
	Ode::Import::TdMass FMass;
	Ode::Import::TdReal FDensity;
	Ode::Import::PdxGeom FGeomTransform;
	Ode::Import::PdxGeom FGeomElement;
	Gls::Coordinates::TGLCoordinates* FPosition;
	Gls::Coordinates::TGLCoordinates* FDirection;
	Gls::Coordinates::TGLCoordinates* FUp;
	Stage::Vectortypes::TGLMatrix FLocalMatrix;
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
	virtual void __fastcall AlignGeomElementToMatrix(const Stage::Vectortypes::TGLMatrix &Mat);
	void __fastcall SetGeomElement(Ode::Import::PdxGeom aGeom);
	void __fastcall RebuildMatrix();
	void __fastcall RebuildVectors();
	void __fastcall SetDensity(const Ode::Import::TdReal Value);
	void __fastcall SetMatrix(const Stage::Vectortypes::TGLMatrix &Value);
	Stage::Vectortypes::TGLMatrix __fastcall GetMatrix();
	void __fastcall SetPosition(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetDirection(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetUp(Gls::Coordinates::TGLCoordinates* const Value);
	
public:
	__fastcall virtual TGLODEElementBase(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEElementBase();
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	Stage::Vectortypes::TGLMatrix __fastcall AbsoluteMatrix();
	Stage::Vectorgeometry::TAffineVector __fastcall AbsolutePosition();
	__property Stage::Vectortypes::TGLMatrix Matrix = {read=GetMatrix, write=SetMatrix};
	__property Ode::Import::PdxGeom GeomTransform = {read=FGeomTransform};
	__property Ode::Import::PdxGeom Geom = {read=FGeomElement};
	__property bool Initialized = {read=FInitialized, nodefault};
	
__published:
	__property Ode::Import::TdReal Density = {read=FDensity, write=SetDensity};
	__property Gls::Coordinates::TGLCoordinates* Position = {read=FPosition, write=SetPosition};
	__property Gls::Coordinates::TGLCoordinates* Direction = {read=FDirection, write=SetDirection};
	__property Gls::Coordinates::TGLCoordinates* Up = {read=FUp, write=SetUp};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementBox : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
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
	__fastcall virtual TGLODEElementBox(Gls::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal BoxWidth = {read=GetBoxWidth, write=SetBoxWidth};
	__property Ode::Import::TdReal BoxHeight = {read=GetBoxHeight, write=SetBoxHeight};
	__property Ode::Import::TdReal BoxDepth = {read=GetBoxDepth, write=SetBoxDepth};
public:
	/* TGLODEElementBase.Destroy */ inline __fastcall virtual ~TGLODEElementBox() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementSphere : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
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
	__fastcall virtual TGLODEElementSphere(Gls::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
public:
	/* TGLODEElementBase.Destroy */ inline __fastcall virtual ~TGLODEElementSphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementCapsule : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
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
	__fastcall virtual TGLODEElementCapsule(Gls::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
	__property Ode::Import::TdReal Length = {read=GetLength, write=SetLength};
public:
	/* TGLODEElementBase.Destroy */ inline __fastcall virtual ~TGLODEElementCapsule() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementCylinder : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
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
	__fastcall virtual TGLODEElementCylinder(Gls::Xcollection::TXCollection* AOwner);
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	
__published:
	__property Ode::Import::TdReal Radius = {read=GetRadius, write=SetRadius};
	__property Ode::Import::TdReal Length = {read=GetLength, write=SetLength};
public:
	/* TGLODEElementBase.Destroy */ inline __fastcall virtual ~TGLODEElementCylinder() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementTriMesh : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
private:
	Ode::Import::PdxTriMeshData FTriMeshData;
	Gls::Vectorlists::TGLAffineVectorList* FVertices;
	Gls::Vectorlists::TGLIntegerList* FIndices;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	virtual Ode::Import::TdMass __fastcall CalculateMass();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetVertices(Gls::Vectorlists::TGLAffineVectorList* const Value);
	void __fastcall SetIndices(Gls::Vectorlists::TGLIntegerList* const Value);
	
public:
	__fastcall virtual TGLODEElementTriMesh(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEElementTriMesh();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	void __fastcall RefreshTriMeshData();
	__property Gls::Vectorlists::TGLAffineVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Gls::Vectorlists::TGLIntegerList* Indices = {read=FIndices, write=SetIndices};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEElementPlane : public TGLODEElementBase
{
	typedef TGLODEElementBase inherited;
	
protected:
	virtual void __fastcall Initialize();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual void __fastcall AlignGeomElementToMatrix(const Stage::Vectortypes::TGLMatrix &Mat);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual System::UnicodeString __fastcall ItemCategory();
	__classmethod virtual bool __fastcall CanAddTo(Gls::Xcollection::TXCollection* collection);
public:
	/* TGLODEElementBase.Create */ inline __fastcall virtual TGLODEElementPlane(Gls::Xcollection::TXCollection* AOwner) : TGLODEElementBase(AOwner) { }
	/* TGLODEElementBase.Destroy */ inline __fastcall virtual ~TGLODEElementPlane() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJoints : public Gls::Xcollection::TXCollection
{
	typedef Gls::Xcollection::TXCollection inherited;
	
public:
	TGLODEJointBase* operator[](int index) { return this->Joint[index]; }
	
protected:
	TGLODEJointBase* __fastcall GetJoint(int index);
	
public:
	__classmethod virtual Gls::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	void __fastcall Initialize();
	void __fastcall Finalize();
	__property TGLODEJointBase* Joint[int index] = {read=GetJoint/*, default*/};
public:
	/* TXCollection.Create */ inline __fastcall virtual TGLODEJoints(System::Classes::TPersistent* aOwner) : Gls::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TGLODEJoints() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLODEJointList : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TGLODEJoints* FJoints;
	
protected:
	void __fastcall WriteJoints(System::Classes::TStream* stream);
	void __fastcall ReadJoints(System::Classes::TStream* stream);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLODEJointList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLODEJointList();
	
__published:
	__property TGLODEJoints* Joints = {read=FJoints};
};


enum DECLSPEC_DENUM TGLODEJointOption : unsigned char { joBothObjectsMustBeAssigned };

typedef System::Set<TGLODEJointOption, TGLODEJointOption::joBothObjectsMustBeAssigned, TGLODEJointOption::joBothObjectsMustBeAssigned> TGLODEJointOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointBase : public Gls::Xcollection::TXCollectionItem
{
	typedef Gls::Xcollection::TXCollectionItem inherited;
	
private:
	Ode::Import::TdJointID FJointID;
	Gls::Scene::TGLBaseSceneObject* FObject1;
	Gls::Scene::TGLBaseSceneObject* FObject2;
	TGLODEManager* FManager;
	System::UnicodeString FObject1Name;
	System::UnicodeString FObject2Name;
	System::UnicodeString FManagerName;
	bool FInitialized;
	bool FEnabled;
	TGLODEJointOptions FJointOptions;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	bool __fastcall IsODEInitialized();
	void __fastcall RegisterJointWithObject(Gls::Scene::TGLBaseSceneObject* Obj);
	void __fastcall UnregisterJointWithObject(Gls::Scene::TGLBaseSceneObject* Obj);
	void __fastcall Attach();
	void __fastcall SetManager(TGLODEManager* const Value);
	void __fastcall SetObject1(Gls::Scene::TGLBaseSceneObject* const Value);
	void __fastcall SetObject2(Gls::Scene::TGLBaseSceneObject* const Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetJointOptions(const TGLODEJointOptions Value);
	__property TGLODEJointOptions JointOptions = {read=FJointOptions, write=SetJointOptions, nodefault};
	
public:
	__fastcall virtual TGLODEJointBase(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointBase();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	virtual void __fastcall Finalize();
	bool __fastcall IsAttached();
	void __fastcall DoLoaded();
	__property Ode::Import::TdJointID JointID = {read=FJointID};
	__property bool Initialized = {read=FInitialized, nodefault};
	
__published:
	__property TGLODEManager* Manager = {read=FManager, write=SetManager};
	__property Gls::Scene::TGLBaseSceneObject* Object1 = {read=FObject1, write=SetObject1};
	__property Gls::Scene::TGLBaseSceneObject* Object2 = {read=FObject2, write=SetObject2};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
};

#pragma pack(pop)

typedef bool __fastcall (__closure *TGLODESetParamCallback)(int Param, const Ode::Import::TdReal Value);

typedef bool __fastcall (__closure *TGLODEGetParamCallback)(int Param, Ode::Import::TdReal &Value);

class PASCALIMPLEMENTATION TGLODEJointParams : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	TGLODESetParamCallback FSetCallback;
	TGLODEGetParamCallback FGetCallback;
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
	__fastcall TGLODEJointParams(System::Classes::TPersistent* AOwner);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyFlagged();
	__property TGLODESetParamCallback SetCallback = {read=FSetCallback, write=FSetCallback};
	__property TGLODEGetParamCallback GetCallback = {read=FGetCallback, write=FGetCallback};
	
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
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLODEJointParams() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointHinge : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FAnchor;
	Gls::Coordinates::TGLCoordinates* FAxis;
	TGLODEJointParams* FAxisParams;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetAxis(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall AxisChange(System::TObject* Sender);
	void __fastcall SetAxisParams(TGLODEJointParams* const Value);
	bool __fastcall SetAxisParam(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxisParam(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TGLODEJointHinge(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointHinge();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gls::Coordinates::TGLCoordinates* Axis = {read=FAxis, write=SetAxis};
	__property TGLODEJointParams* AxisParams = {read=FAxisParams, write=SetAxisParams};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointBall : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FAnchor;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	
public:
	__fastcall virtual TGLODEJointBall(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointBall();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointSlider : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FAxis;
	TGLODEJointParams* FAxisParams;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAxis(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall AxisChange(System::TObject* Sender);
	void __fastcall SetAxisParams(TGLODEJointParams* const Value);
	bool __fastcall SetAxisParam(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxisParam(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TGLODEJointSlider(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointSlider();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Axis = {read=FAxis, write=SetAxis};
	__property TGLODEJointParams* AxisParams = {read=FAxisParams, write=SetAxisParams};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointFixed : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Initialize();
public:
	/* TGLODEJointBase.Create */ inline __fastcall virtual TGLODEJointFixed(Gls::Xcollection::TXCollection* AOwner) : TGLODEJointBase(AOwner) { }
	/* TGLODEJointBase.Destroy */ inline __fastcall virtual ~TGLODEJointFixed() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointHinge2 : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FAnchor;
	Gls::Coordinates::TGLCoordinates* FAxis1;
	Gls::Coordinates::TGLCoordinates* FAxis2;
	TGLODEJointParams* FAxis1Params;
	TGLODEJointParams* FAxis2Params;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetAxis1(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetAxis2(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall Axis1Change(System::TObject* Sender);
	void __fastcall Axis2Change(System::TObject* Sender);
	void __fastcall SetAxis1Params(TGLODEJointParams* const Value);
	void __fastcall SetAxis2Params(TGLODEJointParams* const Value);
	bool __fastcall SetAxis1Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall SetAxis2Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxis1Param(int Param, Ode::Import::TdReal &Value);
	bool __fastcall GetAxis2Param(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TGLODEJointHinge2(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointHinge2();
	virtual void __fastcall StructureChanged();
	virtual void __fastcall Initialize();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gls::Coordinates::TGLCoordinates* Axis1 = {read=FAxis1, write=SetAxis1};
	__property Gls::Coordinates::TGLCoordinates* Axis2 = {read=FAxis2, write=SetAxis2};
	__property TGLODEJointParams* Axis1Params = {read=FAxis1Params, write=SetAxis1Params};
	__property TGLODEJointParams* Axis2Params = {read=FAxis2Params, write=SetAxis2Params};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEJointUniversal : public TGLODEJointBase
{
	typedef TGLODEJointBase inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FAnchor;
	Gls::Coordinates::TGLCoordinates* FAxis1;
	Gls::Coordinates::TGLCoordinates* FAxis2;
	TGLODEJointParams* FAxis1Params;
	TGLODEJointParams* FAxis2Params;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetAnchor(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetAxis1(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall SetAxis2(Gls::Coordinates::TGLCoordinates* const Value);
	void __fastcall AnchorChange(System::TObject* Sender);
	void __fastcall Axis1Change(System::TObject* Sender);
	void __fastcall Axis2Change(System::TObject* Sender);
	void __fastcall SetAxis1Params(TGLODEJointParams* const Value);
	void __fastcall SetAxis2Params(TGLODEJointParams* const Value);
	bool __fastcall SetAxis1Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall SetAxis2Param(int Param, const Ode::Import::TdReal Value);
	bool __fastcall GetAxis1Param(int Param, Ode::Import::TdReal &Value);
	bool __fastcall GetAxis2Param(int Param, Ode::Import::TdReal &Value);
	
public:
	__fastcall virtual TGLODEJointUniversal(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODEJointUniversal();
	virtual void __fastcall Initialize();
	virtual void __fastcall StructureChanged();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* Anchor = {read=FAnchor, write=SetAnchor};
	__property Gls::Coordinates::TGLCoordinates* Axis1 = {read=FAxis1, write=SetAxis1};
	__property Gls::Coordinates::TGLCoordinates* Axis2 = {read=FAxis2, write=SetAxis2};
	__property TGLODEJointParams* Axis1Params = {read=FAxis1Params, write=SetAxis1Params};
	__property TGLODEJointParams* Axis2Params = {read=FAxis2Params, write=SetAxis2Params};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLODEContactPoint : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Stage::Vectorgeometry::TAffineVector Position;
	Stage::Vectorgeometry::TAffineVector Normal;
	float Depth;
public:
	/* TObject.Create */ inline __fastcall TGLODEContactPoint() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLODEContactPoint() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLODECustomCollider : public TGLODEBehaviour
{
	typedef TGLODEBehaviour inherited;
	
private:
	Ode::Import::PdxGeom FGeom;
	System::Classes::TList* FContactList;
	System::Classes::TList* FContactCache;
	Stage::Vectortypes::TGLMatrix FTransform;
	float FContactResolution;
	bool FRenderContacts;
	Gls::Vectorlists::TGLAffineVectorList* FContactRenderPoints;
	float FPointSize;
	Gls::Color::TGLColor* FContactColor;
	
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
	void __fastcall SetTransform(const Stage::Vectortypes::TGLMatrix &ATransform);
	void __fastcall SetContactResolution(const float Value);
	void __fastcall SetRenderContacts(const bool Value);
	void __fastcall SetPointSize(const float Value);
	void __fastcall SetContactColor(Gls::Color::TGLColor* const Value);
	
public:
	__fastcall virtual TGLODECustomCollider(Gls::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLODECustomCollider();
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
	
__published:
	__property float ContactResolution = {read=FContactResolution, write=SetContactResolution};
	__property bool RenderContacts = {read=FRenderContacts, write=SetRenderContacts, nodefault};
	__property float PointSize = {read=FPointSize, write=SetPointSize};
	__property Gls::Color::TGLColor* ContactColor = {read=FContactColor, write=SetContactColor};
};


class PASCALIMPLEMENTATION TGLODEHeightField : public TGLODECustomCollider
{
	typedef TGLODECustomCollider inherited;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual bool __fastcall Collide(const Stage::Vectorgeometry::TAffineVector &aPos, float &Depth, Stage::Vectorgeometry::TAffineVector &cPos, Stage::Vectorgeometry::TAffineVector &cNorm);
	
public:
	__fastcall virtual TGLODEHeightField(Gls::Xcollection::TXCollection* AOwner);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__classmethod virtual bool __fastcall UniqueItem();
	__classmethod virtual bool __fastcall CanAddTo(Gls::Xcollection::TXCollection* collection);
public:
	/* TGLODECustomCollider.Destroy */ inline __fastcall virtual ~TGLODEHeightField() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Classes::TList* vODEObjectRegister;
extern DELPHI_PACKAGE Ode::Import::TdGeomClass vCustomColliderClass;
extern DELPHI_PACKAGE int vCustomColliderClassNum;
extern DELPHI_PACKAGE void __cdecl nearCallBack(void * Data, Ode::Import::PdxGeom o1, Ode::Import::PdxGeom o2);
extern DELPHI_PACKAGE Ode::Import::PdxBody __fastcall GetBodyFromObject(System::TObject* anObject);
extern DELPHI_PACKAGE Ode::Import::PdxBody __fastcall GetBodyFromGLSceneObject(Gls::Scene::TGLBaseSceneObject* anObject);
extern DELPHI_PACKAGE TGLODECollisionSurface* __fastcall GetSurfaceFromObject(System::TObject* anObject);
extern DELPHI_PACKAGE void __fastcall RegisterGLSceneObject(Gls::Scene::TGLBaseSceneObject* anObject);
extern DELPHI_PACKAGE void __fastcall UnregisterGLSceneObject(Gls::Scene::TGLBaseSceneObject* anObject);
extern DELPHI_PACKAGE Gls::Scene::TGLBaseSceneObject* __fastcall GetGLSceneObject(System::UnicodeString anObjectName);
extern DELPHI_PACKAGE TGLODEStatic* __fastcall GetOdeStatic(Gls::Scene::TGLBaseSceneObject* obj);
extern DELPHI_PACKAGE TGLODEStatic* __fastcall GetOrCreateOdeStatic(Gls::Scene::TGLBaseSceneObject* obj);
extern DELPHI_PACKAGE TGLODEDynamic* __fastcall GetOdeDynamic(Gls::Scene::TGLBaseSceneObject* obj);
extern DELPHI_PACKAGE TGLODEDynamic* __fastcall GetOrCreateOdeDynamic(Gls::Scene::TGLBaseSceneObject* obj);
extern DELPHI_PACKAGE TGLODEHeightField* __fastcall GetODEHeightField(Gls::Scene::TGLBaseSceneObject* obj);
extern DELPHI_PACKAGE TGLODEHeightField* __fastcall GetOrCreateODEHeightField(Gls::Scene::TGLBaseSceneObject* obj);
}	/* namespace Odemanager */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ODEMANAGER)
using namespace Gls::Odemanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ODEManagerHPP
