// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CameraController.pas' rev: 36.00 (Windows)

#ifndef GXS_CameraControllerHPP
#define GXS_CameraControllerHPP

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
#include <System.Math.hpp>
#include <System.Contnrs.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.SmoothNavigator.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cameracontroller
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLCameraController;
class DELPHICLASS TgxCameraJobList;
class DELPHICLASS TgxCameraJob;
class DELPHICLASS TgxMoveToPosJob;
class DELPHICLASS TgxZoomToDistanceJob;
class DELPHICLASS TgxOrbitToPosJob;
class DELPHICLASS TgxSmoothOrbitToPos;
class DELPHICLASS TgxOrbitToPosAdvJob;
class DELPHICLASS TgxSmoothOrbitToPosAdvJob;
class DELPHICLASS TgxCameraController;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLCameraController : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLCameraController(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLCameraController(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLCameraController(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLCameraController(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLCameraController(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLCameraController(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLCameraController(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLCameraController(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLCameraController(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLCameraController(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLCameraController(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLCameraController(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLCameraController() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxCameraJobList : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
public:
	TgxCameraJob* operator[](const int AIndex) { return this->Items[AIndex]; }
	
private:
	TgxCameraController* FController;
	TgxCameraJob* __fastcall GetCameraJob(const int AIndex);
	void __fastcall SetCameraJob(const int AIndex, TgxCameraJob* const Value);
	
public:
	__fastcall TgxCameraJobList(TgxCameraController* AController);
	HIDESBASE int __fastcall Add(TgxCameraJob* ACameraJob);
	__property TgxCameraJob* Items[const int AIndex] = {read=GetCameraJob, write=SetCameraJob/*, default*/};
	HIDESBASE TgxCameraJob* __fastcall First();
	HIDESBASE TgxCameraJob* __fastcall Last();
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxCameraJobList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxCameraJob : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxCameraJobList* FJoblist;
	
protected:
	bool FAbort;
	bool FInit;
	bool FRunning;
	double FElapsedTime;
	double FDeltaTime;
	double FStartTime;
	double FProceedTime;
	
public:
	__fastcall virtual TgxCameraJob(TgxCameraJobList* const AJoblist);
	__fastcall virtual ~TgxCameraJob();
	void __fastcall Abort();
	virtual void __fastcall Step() = 0 ;
	virtual void __fastcall Init() = 0 ;
	__property bool Running = {read=FRunning, write=FRunning, nodefault};
	__property double ElapsedTime = {read=FElapsedTime, write=FElapsedTime};
	__property double StartTime = {read=FStartTime, write=FStartTime};
	__property double ProceedTime = {read=FProceedTime, write=FProceedTime};
};


class PASCALIMPLEMENTATION TgxMoveToPosJob : public TgxCameraJob
{
	typedef TgxCameraJob inherited;
	
private:
	Stage::Vectortypes::TVector4f FInitialPos;
	Stage::Vectortypes::TVector4f FFinalPos;
	
public:
	double X;
	double Y;
	double Z;
	double Time;
	virtual void __fastcall Step();
	virtual void __fastcall Init();
	__property Stage::Vectortypes::TVector4f InitialPos = {read=FInitialPos};
	__property Stage::Vectortypes::TVector4f FinalPos = {read=FFinalPos};
public:
	/* TgxCameraJob.Create */ inline __fastcall virtual TgxMoveToPosJob(TgxCameraJobList* const AJoblist) : TgxCameraJob(AJoblist) { }
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxMoveToPosJob() { }
	
};


class PASCALIMPLEMENTATION TgxZoomToDistanceJob : public TgxCameraJob
{
	typedef TgxCameraJob inherited;
	
private:
	Stage::Vectortypes::TVector4f FInitialPos;
	Stage::Vectortypes::TVector4f FFinalPos;
	
public:
	double Distance;
	double Time;
	virtual void __fastcall Step();
	virtual void __fastcall Init();
	__property Stage::Vectortypes::TVector4f InitialPos = {read=FInitialPos};
	__property Stage::Vectortypes::TVector4f FinalPos = {read=FFinalPos};
public:
	/* TgxCameraJob.Create */ inline __fastcall virtual TgxZoomToDistanceJob(TgxCameraJobList* const AJoblist) : TgxCameraJob(AJoblist) { }
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxZoomToDistanceJob() { }
	
};


class PASCALIMPLEMENTATION TgxOrbitToPosJob : public TgxCameraJob
{
	typedef TgxCameraJob inherited;
	
private:
	Stage::Vectortypes::TVector4f FFinalPos;
	Stage::Vectortypes::TVector2f FRotateSpeed;
	Stage::Vectortypes::TVector4f FCameraUpVector;
	Stage::Vectortypes::TVector4f FTargetPosition;
	double FTime;
	
public:
	virtual void __fastcall Step();
	virtual void __fastcall Init();
	__property Stage::Vectortypes::TVector2f RotateSpeed = {read=FRotateSpeed};
	__property Stage::Vectortypes::TVector4f CameraUpVector = {read=FCameraUpVector};
	__property Stage::Vectortypes::TVector4f TargetPosition = {read=FTargetPosition};
	__property Stage::Vectortypes::TVector4f FinalPos = {read=FFinalPos};
	__property double Time = {read=FTime};
public:
	/* TgxCameraJob.Create */ inline __fastcall virtual TgxOrbitToPosJob(TgxCameraJobList* const AJoblist) : TgxCameraJob(AJoblist) { }
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxOrbitToPosJob() { }
	
};


class PASCALIMPLEMENTATION TgxSmoothOrbitToPos : public TgxOrbitToPosJob
{
	typedef TgxOrbitToPosJob inherited;
	
private:
	float FCutoffAngle;
	bool FNeedToRecalculateZoom;
	Stage::Vectortypes::TMatrix4f FShouldBeMatrix;
	Gxs::Smoothnavigator::TgxNavigatorSmoothChangeVector* FSmoothNavigator;
	
public:
	__fastcall virtual TgxSmoothOrbitToPos(TgxCameraJobList* const AJoblist);
	virtual void __fastcall Step();
	__property float CutoffAngle = {read=FCutoffAngle, write=FCutoffAngle};
	__property bool NeedToRecalculateZoom = {read=FNeedToRecalculateZoom, write=FNeedToRecalculateZoom, nodefault};
public:
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxSmoothOrbitToPos() { }
	
};


class PASCALIMPLEMENTATION TgxOrbitToPosAdvJob : public TgxCameraJob
{
	typedef TgxCameraJob inherited;
	
private:
	Stage::Vectortypes::TVector4f FInitialPos;
	Stage::Vectortypes::TVector4f FFinalPos;
	Stage::Vectortypes::TVector4f FInitialUp;
	Stage::Vectortypes::TVector4f FInitialDir;
	Stage::Vectortypes::TVector4f FRotAxis;
	double FAngle;
	
public:
	double X;
	double Y;
	double Z;
	double Time;
	bool PreferUpAxis;
	virtual void __fastcall Step();
	virtual void __fastcall Init();
	__property Stage::Vectortypes::TVector4f InitialPos = {read=FInitialPos};
	__property Stage::Vectortypes::TVector4f InitialUp = {read=FInitialUp};
	__property Stage::Vectortypes::TVector4f InitialDir = {read=FInitialDir};
	__property Stage::Vectortypes::TVector4f FinalPos = {read=FFinalPos};
public:
	/* TgxCameraJob.Create */ inline __fastcall virtual TgxOrbitToPosAdvJob(TgxCameraJobList* const AJoblist) : TgxCameraJob(AJoblist) { }
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxOrbitToPosAdvJob() { }
	
};


class PASCALIMPLEMENTATION TgxSmoothOrbitToPosAdvJob : public TgxOrbitToPosAdvJob
{
	typedef TgxOrbitToPosAdvJob inherited;
	
private:
	Stage::Vectortypes::TVector4f FPreviousPosition;
	Gxs::Smoothnavigator::TgxNavigatorSmoothChangeVector* FSmoothNavigator;
	bool FRestoreUpVector;
	
public:
	virtual void __fastcall Step();
	virtual void __fastcall Init();
public:
	/* TgxCameraJob.Create */ inline __fastcall virtual TgxSmoothOrbitToPosAdvJob(TgxCameraJobList* const AJoblist) : TgxOrbitToPosAdvJob(AJoblist) { }
	/* TgxCameraJob.Destroy */ inline __fastcall virtual ~TgxSmoothOrbitToPosAdvJob() { }
	
};


typedef void __fastcall (__closure *TgxCameraJobEvent)(TgxCameraJob* Sender);

class PASCALIMPLEMENTATION TgxCameraController : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxCameraJobList* FCameraJobList;
	Gxs::Scene::TgxBaseSceneObject* FCamera;
	Gxs::Scene::TgxBaseSceneObject* FCameraTarget;
	TgxCameraJobEvent FOnJobAdded;
	TgxCameraJobEvent FOnJobFinished;
	TgxCameraJobEvent FOnJobStep;
	double FsoSafeDist;
	double FsoTimeToSafePlacement;
	double FsoTimeToOrbit;
	double FsoTimeToZoomBackIn;
	void __fastcall CheckAssignments(bool Extended);
	void __fastcall SetOnJobAdded(const TgxCameraJobEvent Value);
	void __fastcall SetOnJobFinished(const TgxCameraJobEvent Value);
	void __fastcall SetOnJobStep(const TgxCameraJobEvent Value);
	void __fastcall SetCamera(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetCameraTarget(Gxs::Scene::TgxBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxCameraController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCameraController();
	TgxMoveToPosJob* __fastcall MoveToPos(double x, double y, double z, double time);
	TgxOrbitToPosJob* __fastcall OrbitToPos(double x, double y, double z, double time);
	TgxSmoothOrbitToPos* __fastcall OrbitToPosSmooth(const Stage::Vectortypes::TVector4f &ATargetPosition, const double ATime, Gxs::Smoothnavigator::TgxNavigatorSmoothChangeVector* const ASmoothNavigator, const bool AFNeedToRecalculateZoom, const Stage::Vectortypes::PVector4f ACameraUpVector = (Stage::Vectortypes::PVector4f)(0x0));
	TgxOrbitToPosAdvJob* __fastcall OrbitToPosAdvanced(double x, double y, double z, double time, bool PreferUpAxis = true);
	TgxSmoothOrbitToPosAdvJob* __fastcall OrbitToPosAdvancedSmooth(const double x, const double y, const double z, const double time, Gxs::Smoothnavigator::TgxNavigatorSmoothChangeVector* const ASmoothNavigator, const bool PreferUpAxis = true);
	TgxZoomToDistanceJob* __fastcall ZoomToDistance(double Distance, double Time);
	void __fastcall SafeOrbitAndZoomToPos(double x, double y, double z);
	void __fastcall StopMovement();
	void __fastcall Step(const double deltaTime, const double newTime);
	__property TgxCameraJobList* CameraJobList = {read=FCameraJobList};
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* Camera = {read=FCamera, write=SetCamera};
	__property Gxs::Scene::TgxBaseSceneObject* CameraTarget = {read=FCameraTarget, write=SetCameraTarget};
	__property double soSafeDistance = {read=FsoSafeDist, write=FsoSafeDist};
	__property double soTimeToSafePlacement = {read=FsoTimeToSafePlacement, write=FsoTimeToSafePlacement};
	__property double soTimeToOrbit = {read=FsoTimeToOrbit, write=FsoTimeToOrbit};
	__property double soTimeToZoomBackIn = {read=FsoTimeToZoomBackIn, write=FsoTimeToZoomBackIn};
	__property TgxCameraJobEvent OnJobAdded = {read=FOnJobAdded, write=SetOnJobAdded};
	__property TgxCameraJobEvent OnJobStep = {read=FOnJobStep, write=SetOnJobStep};
	__property TgxCameraJobEvent OnJobFinished = {read=FOnJobFinished, write=SetOnJobFinished};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cameracontroller */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CAMERACONTROLLER)
using namespace Gxs::Cameracontroller;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CameraControllerHPP
