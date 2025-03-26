// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.File3DSSceneObjects.pas' rev: 36.00 (Windows)

#ifndef GLS_File3DSSceneObjectsHPP
#define GLS_File3DSSceneObjectsHPP

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
#include <GLS.OpenGLAdapter.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Coordinates.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Context.hpp>
#include <GLS.Scene.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace File3dssceneobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLFile3DSLight;
class DELPHICLASS TGLFile3DSCamera;
class DELPHICLASS TGLFile3DSActor;
class DELPHICLASS TGLFile3DSFreeForm;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLFile3DSLight : public Gls::Scene::TGLLightSource
{
	typedef Gls::Scene::TGLLightSource inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FTargetPos;
	float FHotSpot;
	float FMultipler;
	
public:
	__fastcall virtual TGLFile3DSLight(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall CoordinateChanged(Gls::Coordinates::TGLCustomCoordinates* Sender);
	__fastcall virtual ~TGLFile3DSLight();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* SpotTargetPos = {read=FTargetPos};
	__property float HotSpot = {read=FHotSpot, write=FHotSpot};
	__property float Multipler = {read=FMultipler, write=FMultipler};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLFile3DSLight(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLLightSource(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLFile3DSCamera : public Gls::Scene::TGLCamera
{
	typedef Gls::Scene::TGLCamera inherited;
	
private:
	Gls::Coordinates::TGLCoordinates* FTargetPos;
	System::StaticArray<Stage::Opengltokens::PGLUQuadric, 2> FQuadCyl;
	System::StaticArray<Stage::Opengltokens::PGLUQuadric, 2> FQuadDisk;
	
public:
	__fastcall virtual TGLFile3DSCamera(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall CoordinateChanged(Gls::Coordinates::TGLCustomCoordinates* Sender);
	__fastcall virtual ~TGLFile3DSCamera();
	
__published:
	__property Gls::Coordinates::TGLCoordinates* CameraTargetPos = {read=FTargetPos};
	__property RollAngle = {default=0};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLFile3DSCamera(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLCamera(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLFile3DSActor : public Gls::Vectorfileobjects::TGLActor
{
	typedef Gls::Vectorfileobjects::TGLActor inherited;
	
private:
	void __fastcall ReadMesh(System::Classes::TStream* Stream);
	void __fastcall WriteMesh(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
public:
	/* TGLActor.Create */ inline __fastcall virtual TGLFile3DSActor(System::Classes::TComponent* aOwner) : Gls::Vectorfileobjects::TGLActor(aOwner) { }
	/* TGLActor.Destroy */ inline __fastcall virtual ~TGLFile3DSActor() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLFile3DSActor(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Vectorfileobjects::TGLActor(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLFile3DSFreeForm : public Gls::Vectorfileobjects::TGLFreeForm
{
	typedef Gls::Vectorfileobjects::TGLFreeForm inherited;
	
private:
	Stage::Vectortypes::TGLMatrix FTransfMat;
	Stage::Vectortypes::TGLMatrix FScaleMat;
	Stage::Vectortypes::TGLMatrix ParentMatrix;
	Gls::Coordinates::TGLCoordinates4* FS_Rot3DS;
	Gls::Coordinates::TGLCoordinates4* FRot3DS;
	Gls::Coordinates::TGLCoordinates4* FScale3DS;
	void __fastcall ReadMesh(System::Classes::TStream* Stream);
	void __fastcall WriteMesh(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	Stage::Vectortypes::TGLMatrix FRefMat;
	__fastcall virtual TGLFile3DSFreeForm(System::Classes::TComponent* AOWner);
	__fastcall virtual ~TGLFile3DSFreeForm();
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall CoordinateChanged(Gls::Coordinates::TGLCustomCoordinates* Sender);
	virtual Stage::Vectortypes::TGLVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual Stage::Vectortypes::TGLVector __fastcall BarycenterAbsolutePosition();
	
__published:
	__property Gls::Coordinates::TGLCoordinates4* S_Rot3DS = {read=FS_Rot3DS};
	__property Gls::Coordinates::TGLCoordinates4* Rot3DS = {read=FRot3DS};
	__property Gls::Coordinates::TGLCoordinates4* Scale3DS = {read=FScale3DS};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLFile3DSFreeForm(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Vectorfileobjects::TGLFreeForm(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vGLFile3DSSceneObjects_RenderCameraAndLights;
}	/* namespace File3dssceneobjects */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_FILE3DSSCENEOBJECTS)
using namespace Gls::File3dssceneobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_File3DSSceneObjectsHPP
