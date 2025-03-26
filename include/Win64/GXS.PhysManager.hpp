// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PhysManager.pas' rev: 36.00 (Windows)

#ifndef GXS_PhysManagerHPP
#define GXS_PhysManagerHPP

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
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.PhysForces.hpp>
#include <GXS.Behaviours.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Physmanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TDESolver;
class DELPHICLASS TDESolverExplicit;
class DELPHICLASS TDESolverEuler;
class DELPHICLASS TDESolverRungeKutta4;
class DELPHICLASS TDESolverImplicit;
class DELPHICLASS TDESolverVerlet;
class DELPHICLASS TgxBaseInertia;
class DELPHICLASS TgxBaseForceFieldEmitter;
class DELPHICLASS TgxPhysManager;
class DELPHICLASS TgxForces;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TDESolverType : unsigned char { ssEuler, ssRungeKutta4, ssVerlet };

typedef System::DynamicArray<double> TStateArray;

class PASCALIMPLEMENTATION TDESolver : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int StateSize;
	TStateArray StateArray;
	TgxPhysManager* Owner;
	virtual TStateArray __fastcall StateToArray();
	virtual void __fastcall ArrayToState(TStateArray StateArray);
	virtual void __fastcall Solve(double DeltaTime) = 0 ;
	__fastcall TDESolver(TgxPhysManager* aOwner);
	__fastcall virtual ~TDESolver();
};


class PASCALIMPLEMENTATION TDESolverExplicit : public TDESolver
{
	typedef TDESolver inherited;
	
public:
	TStateArray StateArrayDot;
	virtual TStateArray __fastcall CalcStateDot();
public:
	/* TDESolver.Create */ inline __fastcall TDESolverExplicit(TgxPhysManager* aOwner) : TDESolver(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverExplicit() { }
	
};


class PASCALIMPLEMENTATION TDESolverEuler : public TDESolverExplicit
{
	typedef TDESolverExplicit inherited;
	
public:
	virtual void __fastcall Solve(double DeltaTime);
public:
	/* TDESolver.Create */ inline __fastcall TDESolverEuler(TgxPhysManager* aOwner) : TDESolverExplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverEuler() { }
	
};


class PASCALIMPLEMENTATION TDESolverRungeKutta4 : public TDESolverExplicit
{
	typedef TDESolverExplicit inherited;
	
public:
	virtual void __fastcall Solve(double DeltaTime);
public:
	/* TDESolver.Create */ inline __fastcall TDESolverRungeKutta4(TgxPhysManager* aOwner) : TDESolverExplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverRungeKutta4() { }
	
};


class PASCALIMPLEMENTATION TDESolverImplicit : public TDESolver
{
	typedef TDESolver inherited;
	
public:
	TStateArray LastStateArray;
public:
	/* TDESolver.Create */ inline __fastcall TDESolverImplicit(TgxPhysManager* aOwner) : TDESolver(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverImplicit() { }
	
};


class PASCALIMPLEMENTATION TDESolverVerlet : public TDESolverImplicit
{
	typedef TDESolverImplicit inherited;
	
public:
	/* TDESolver.Create */ inline __fastcall TDESolverVerlet(TgxPhysManager* aOwner) : TDESolverImplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverVerlet() { }
	
};


class PASCALIMPLEMENTATION TgxBaseInertia : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	bool FDampingEnabled;
	TgxPhysManager* FManager;
	System::UnicodeString FManagerName;
	
protected:
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	int StateSize;
	virtual void __fastcall StateToArray(TStateArray &StateArray, int StatePos);
	virtual void __fastcall ArrayToState(TStateArray StateArray, int StatePos);
	virtual void __fastcall CalcStateDot(TStateArray &StateArray, int StatePos);
	virtual void __fastcall RemoveForces();
	virtual void __fastcall CalculateForceFieldForce(TgxBaseForceFieldEmitter* ForceFieldEmitter);
	virtual void __fastcall CalcAuxiliary();
	virtual void __fastcall SetUpStartingState();
	virtual double __fastcall CalculateKE();
	virtual double __fastcall CalculatePE();
	__fastcall virtual TgxBaseInertia(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBaseInertia();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetManager(TgxPhysManager* const val);
	
__published:
	__property bool DampingEnabled = {read=FDampingEnabled, write=FDampingEnabled, nodefault};
	__property TgxPhysManager* Manager = {read=FManager, write=SetManager};
};


class PASCALIMPLEMENTATION TgxBaseForceFieldEmitter : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TgxPhysManager* FManager;
	System::UnicodeString FManagerName;
	
protected:
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TgxBaseForceFieldEmitter(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBaseForceFieldEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetManager(TgxPhysManager* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gxs::Scene::TgxBaseSceneObject* Body);
	
__published:
	__property TgxPhysManager* Manager = {read=FManager, write=SetManager};
};


class PASCALIMPLEMENTATION TgxPhysManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
protected:
	System::Classes::TList* fInertias;
	System::Classes::TList* fForceFieldEmitters;
	TgxForces* fForces;
	TDESolverType fDESolverType;
	TDESolver* DESolver;
	Gxs::Scene::TgxScene* fScene;
	virtual void __fastcall Loaded();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteForces(System::Classes::TStream* stream);
	void __fastcall ReadForces(System::Classes::TStream* stream);
	void __fastcall SetForces(TgxForces* const val);
	TgxForces* __fastcall GetForces();
	void __fastcall SetInertias(System::Classes::TList* const val);
	void __fastcall SetForceFieldEmitters(System::Classes::TList* const val);
	void __fastcall SetScene(Gxs::Scene::TgxScene* const val);
	
public:
	void __fastcall RegisterInertia(TgxBaseInertia* aInertia);
	void __fastcall DeRegisterInertia(TgxBaseInertia* aInertia);
	void __fastcall DeRegisterAllInertias();
	void __fastcall RegisterForceFieldEmitter(TgxBaseForceFieldEmitter* aForceField);
	void __fastcall DeRegisterForceFieldEmitter(TgxBaseForceFieldEmitter* aForceField);
	void __fastcall DeRegisterAllForceFieldEmitters();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__fastcall virtual TgxPhysManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxPhysManager();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall CalculateNextState(double DeltaTime);
	double __fastcall CalculateKE();
	double __fastcall CalculatePE();
	void __fastcall SetDESolver(TDESolverType SolverType);
	Gxs::Scene::TgxBaseSceneObject* __fastcall FindObjectByName(System::UnicodeString Name);
	Gxs::Scene::TgxBaseSceneObject* __fastcall FindForceFieldEmitterByName(System::UnicodeString Name);
	__property System::Classes::TList* Inertias = {read=fInertias, write=SetInertias};
	__property System::Classes::TList* ForceFieldEmitters = {read=fForceFieldEmitters, write=SetForceFieldEmitters};
	
__published:
	__property TgxForces* Forces = {read=GetForces, write=SetForces};
	__property TDESolverType Solver = {read=fDESolverType, write=SetDESolver, nodefault};
	__property Gxs::Scene::TgxScene* Scene = {read=fScene, write=SetScene};
};


class PASCALIMPLEMENTATION TgxForces : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	Gxs::Physforces::TgxForce* operator[](int index) { return this->Force[index]; }
	
protected:
	Gxs::Physforces::TgxForce* __fastcall GetForce(int index);
	
public:
	__fastcall virtual TgxForces(System::Classes::TPersistent* aOwner);
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	__property Gxs::Physforces::TgxForce* Force[int index] = {read=GetForce/*, default*/};
	virtual bool __fastcall CanAdd(Gxs::Xcollection::TXCollectionItemClass aClass);
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxForces() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Physmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PHYSMANAGER)
using namespace Gxs::Physmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PhysManagerHPP
