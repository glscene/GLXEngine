// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.WaterPlane.pas' rev: 36.00 (Windows)

#ifndef GXS_WaterPlaneHPP
#define GXS_WaterPlaneHPP

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
#include <Winapi.OpenGLext.hpp>
#include <Stage.OpenGL4.hpp>
#include <System.Classes.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Utils.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Waterplane
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxWaterPlane;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxWaterPlaneOption : unsigned char { wpoTextured };

typedef System::Set<TgxWaterPlaneOption, TgxWaterPlaneOption::wpoTextured, TgxWaterPlaneOption::wpoTextured> TgxWaterPlaneOptions;

class PASCALIMPLEMENTATION TgxWaterPlane : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<System::ByteBool> _TgxWaterPlane__1;
	
	typedef System::DynamicArray<float> _TgxWaterPlane__2;
	
	
private:
	_TgxWaterPlane__1 FLocks;
	_TgxWaterPlane__2 FPositions;
	_TgxWaterPlane__2 FVelocity;
	Gxs::Persistentclasses::TgxPersistentObjectList* FPlaneQuadIndices;
	Gxs::Vectorlists::TgxTexPointList* FPlaneQuadTexCoords;
	Gxs::Vectorlists::TgxAffineVectorList* FPlaneQuadVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FPlaneQuadNormals;
	bool FActive;
	int FRainTimeInterval;
	float FRainForce;
	float FViscosity;
	float FElastic;
	int FResolution;
	float FSimulationFrequency;
	float FTimeToNextUpdate;
	float FTimeToNextRainDrop;
	int FMaximumCatchupIterations;
	float FLastIterationStepTime;
	Fmx::Objects::TImage* FMask;
	TgxWaterPlaneOptions FOptions;
	
protected:
	void __fastcall SetElastic(const float value);
	void __fastcall SetResolution(const int value);
	void __fastcall SetRainTimeInterval(const int val);
	void __fastcall SetViscosity(const float val);
	void __fastcall SetRainForce(const float val);
	void __fastcall SetSimulationFrequency(const float val);
	void __fastcall SetMask(Fmx::Objects::TImage* val);
	void __fastcall SetOptions(const TgxWaterPlaneOptions val);
	void __fastcall DoMaskChanged(System::TObject* Sender);
	void __fastcall InitResolution();
	void __fastcall IterComputeVelocity();
	void __fastcall IterComputePositions();
	void __fastcall IterComputeNormals();
	void __fastcall Iterate();
	
public:
	__fastcall virtual TgxWaterPlane(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxWaterPlane();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall CreateRippleAtGridPos(int X, int Y);
	void __fastcall CreateRippleAtWorldPos(const float X, const float Y, const float z)/* overload */;
	void __fastcall CreateRippleAtWorldPos(const Stage::Vectortypes::TVector4f &pos)/* overload */;
	void __fastcall CreateRippleRandom();
	void __fastcall Reset();
	__property float LastIterationStepTime = {read=FLastIterationStepTime};
	
__published:
	__property bool Active = {read=FActive, write=FActive, default=1};
	__property int RainTimeInterval = {read=FRainTimeInterval, write=SetRainTimeInterval, default=500};
	__property float RainForce = {read=FRainForce, write=SetRainForce};
	__property float Viscosity = {read=FViscosity, write=SetViscosity};
	__property float Elastic = {read=FElastic, write=SetElastic};
	__property int Resolution = {read=FResolution, write=SetResolution, default=64};
	__property TgxWaterPlaneOptions Options = {read=FOptions, write=SetOptions, default=1};
	__property Fmx::Objects::TImage* Mask = {read=FMask, write=SetMask};
	__property float SimulationFrequency = {read=FSimulationFrequency, write=SetSimulationFrequency};
	__property int MaximumCatchupIterations = {read=FMaximumCatchupIterations, write=FMaximumCatchupIterations, default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxWaterPlane(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultWaterPlaneOptions (System::Set<TgxWaterPlaneOption, TgxWaterPlaneOption::wpoTextured, TgxWaterPlaneOption::wpoTextured>() << TgxWaterPlaneOption::wpoTextured )
}	/* namespace Waterplane */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_WATERPLANE)
using namespace Gxs::Waterplane;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_WaterPlaneHPP
