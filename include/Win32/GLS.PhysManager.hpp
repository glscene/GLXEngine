// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.PhysManager.pas' rev: 36.00 (Windows)

#ifndef GLS_PhysManagerHPP
#define GLS_PhysManagerHPP

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
#include <GLS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Scene.hpp>
#include <GLS.PhysForces.hpp>
#include <GLS.Behaviours.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
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
class DELPHICLASS TGLBaseInertia;
class DELPHICLASS TGLBaseForceFieldEmitter;
class DELPHICLASS TGLPhysManager;
class DELPHICLASS TGLForces;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TDESolverType : unsigned char { ssEuler, ssRungeKutta4, ssVerlet };

typedef System::DynamicArray<double> TStateArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolver : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int StateSize;
	TStateArray StateArray;
	TGLPhysManager* Owner;
	virtual TStateArray __fastcall StateToArray();
	virtual void __fastcall ArrayToState(TStateArray StateArray);
	virtual void __fastcall Solve(double DeltaTime) = 0 ;
	__fastcall TDESolver(TGLPhysManager* aOwner);
	__fastcall virtual ~TDESolver();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolverExplicit : public TDESolver
{
	typedef TDESolver inherited;
	
public:
	TStateArray StateArrayDot;
	virtual TStateArray __fastcall CalcStateDot();
public:
	/* TDESolver.Create */ inline __fastcall TDESolverExplicit(TGLPhysManager* aOwner) : TDESolver(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverExplicit() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolverEuler : public TDESolverExplicit
{
	typedef TDESolverExplicit inherited;
	
public:
	virtual void __fastcall Solve(double DeltaTime);
public:
	/* TDESolver.Create */ inline __fastcall TDESolverEuler(TGLPhysManager* aOwner) : TDESolverExplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverEuler() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolverRungeKutta4 : public TDESolverExplicit
{
	typedef TDESolverExplicit inherited;
	
public:
	virtual void __fastcall Solve(double DeltaTime);
public:
	/* TDESolver.Create */ inline __fastcall TDESolverRungeKutta4(TGLPhysManager* aOwner) : TDESolverExplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverRungeKutta4() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolverImplicit : public TDESolver
{
	typedef TDESolver inherited;
	
public:
	TStateArray LastStateArray;
public:
	/* TDESolver.Create */ inline __fastcall TDESolverImplicit(TGLPhysManager* aOwner) : TDESolver(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverImplicit() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDESolverVerlet : public TDESolverImplicit
{
	typedef TDESolverImplicit inherited;
	
public:
	/* TDESolver.Create */ inline __fastcall TDESolverVerlet(TGLPhysManager* aOwner) : TDESolverImplicit(aOwner) { }
	/* TDESolver.Destroy */ inline __fastcall virtual ~TDESolverVerlet() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseInertia : public Gls::Scene::TGLBehaviour
{
	typedef Gls::Scene::TGLBehaviour inherited;
	
private:
	bool FDampingEnabled;
	TGLPhysManager* FManager;
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
	virtual void __fastcall CalculateForceFieldForce(TGLBaseForceFieldEmitter* ForceFieldEmitter);
	virtual void __fastcall CalcAuxiliary();
	virtual void __fastcall SetUpStartingState();
	virtual double __fastcall CalculateKE();
	virtual double __fastcall CalculatePE();
	__fastcall virtual TGLBaseInertia(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLBaseInertia();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetManager(TGLPhysManager* const val);
	
__published:
	__property bool DampingEnabled = {read=FDampingEnabled, write=FDampingEnabled, nodefault};
	__property TGLPhysManager* Manager = {read=FManager, write=SetManager};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseForceFieldEmitter : public Gls::Scene::TGLBehaviour
{
	typedef Gls::Scene::TGLBehaviour inherited;
	
private:
	TGLPhysManager* FManager;
	System::UnicodeString FManagerName;
	
protected:
	DYNAMIC void __fastcall Loaded();
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TGLBaseForceFieldEmitter(Gls::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGLBaseForceFieldEmitter();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetManager(TGLPhysManager* const val);
	virtual Stage::Vectorgeometry::TAffineVector __fastcall CalculateForceField(Gls::Scene::TGLBaseSceneObject* Body);
	
__published:
	__property TGLPhysManager* Manager = {read=FManager, write=SetManager};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLPhysManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
protected:
	System::Classes::TList* fInertias;
	System::Classes::TList* fForceFieldEmitters;
	TGLForces* fForces;
	TDESolverType fDESolverType;
	TDESolver* DESolver;
	Gls::Scene::TGLScene* fScene;
	virtual void __fastcall Loaded();
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteForces(System::Classes::TStream* stream);
	void __fastcall ReadForces(System::Classes::TStream* stream);
	void __fastcall SetForces(TGLForces* const val);
	TGLForces* __fastcall GetForces();
	void __fastcall SetInertias(System::Classes::TList* const val);
	void __fastcall SetForceFieldEmitters(System::Classes::TList* const val);
	void __fastcall SetScene(Gls::Scene::TGLScene* const val);
	
public:
	void __fastcall RegisterInertia(TGLBaseInertia* aInertia);
	void __fastcall DeRegisterInertia(TGLBaseInertia* aInertia);
	void __fastcall DeRegisterAllInertias();
	void __fastcall RegisterForceFieldEmitter(TGLBaseForceFieldEmitter* aForceField);
	void __fastcall DeRegisterForceFieldEmitter(TGLBaseForceFieldEmitter* aForceField);
	void __fastcall DeRegisterAllForceFieldEmitters();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__fastcall virtual TGLPhysManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLPhysManager();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall CalculateNextState(double DeltaTime);
	double __fastcall CalculateKE();
	double __fastcall CalculatePE();
	void __fastcall SetDESolver(TDESolverType SolverType);
	Gls::Scene::TGLBaseSceneObject* __fastcall FindObjectByName(System::UnicodeString Name);
	Gls::Scene::TGLBaseSceneObject* __fastcall FindForceFieldEmitterByName(System::UnicodeString Name);
	__property System::Classes::TList* Inertias = {read=fInertias, write=SetInertias};
	__property System::Classes::TList* ForceFieldEmitters = {read=fForceFieldEmitters, write=SetForceFieldEmitters};
	
__published:
	__property TGLForces* Forces = {read=GetForces, write=SetForces};
	__property TDESolverType Solver = {read=fDESolverType, write=SetDESolver, nodefault};
	__property Gls::Scene::TGLScene* Scene = {read=fScene, write=SetScene};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLForces : public Gls::Xcollection::TXCollection
{
	typedef Gls::Xcollection::TXCollection inherited;
	
public:
	Gls::Physforces::TGLForce* operator[](int index) { return this->Force[index]; }
	
protected:
	Gls::Physforces::TGLForce* __fastcall GetForce(int index);
	
public:
	__fastcall virtual TGLForces(System::Classes::TPersistent* aOwner);
	__classmethod virtual Gls::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	__property Gls::Physforces::TGLForce* Force[int index] = {read=GetForce/*, default*/};
	virtual bool __fastcall CanAdd(Gls::Xcollection::TXCollectionItemClass aClass);
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TGLForces() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Physmanager */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_PHYSMANAGER)
using namespace Gls::Physmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PhysManagerHPP
