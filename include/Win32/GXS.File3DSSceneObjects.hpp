// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.File3DSSceneObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_File3DSSceneObjectsHPP
#define GXS_File3DSSceneObjectsHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Context.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace File3dssceneobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFile3DSLight;
class DELPHICLASS TgxFile3DSCamera;
class DELPHICLASS TgxFile3DSActor;
class DELPHICLASS TgxFile3DSFreeForm;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxFile3DSLight : public Gxs::Scene::TgxLightSource
{
	typedef Gxs::Scene::TgxLightSource inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FTargetPos;
	float FHotSpot;
	float FMultipler;
	
public:
	__fastcall virtual TgxFile3DSLight(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall CoordinateChanged(Gxs::Coordinates::TgxCustomCoordinates* Sender);
	__fastcall virtual ~TgxFile3DSLight();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* SpotTargetPos = {read=FTargetPos};
	__property float HotSpot = {read=FHotSpot, write=FHotSpot};
	__property float Multipler = {read=FMultipler, write=FMultipler};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFile3DSLight(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxLightSource(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSCamera : public Gxs::Scene::TgxCamera
{
	typedef Gxs::Scene::TgxCamera inherited;
	
private:
	Gxs::Coordinates::TgxCoordinates* FTargetPos;
	System::StaticArray<GLUquadricObj, 2> FQuadCyl;
	System::StaticArray<GLUquadricObj, 2> FQuadDisk;
	
public:
	__fastcall virtual TgxFile3DSCamera(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall CoordinateChanged(Gxs::Coordinates::TgxCustomCoordinates* Sender);
	__fastcall virtual ~TgxFile3DSCamera();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* CameraTargetPos = {read=FTargetPos};
	__property RollAngle = {default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFile3DSCamera(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxCamera(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSActor : public Gxs::Vectorfileobjects::TgxActor
{
	typedef Gxs::Vectorfileobjects::TgxActor inherited;
	
private:
	void __fastcall ReadMesh(System::Classes::TStream* Stream);
	void __fastcall WriteMesh(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
public:
	/* TgxActor.Create */ inline __fastcall virtual TgxFile3DSActor(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxActor(aOwner) { }
	/* TgxActor.Destroy */ inline __fastcall virtual ~TgxFile3DSActor() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFile3DSActor(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxActor(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSFreeForm : public Gxs::Vectorfileobjects::TgxFreeForm
{
	typedef Gxs::Vectorfileobjects::TgxFreeForm inherited;
	
private:
	Stage::Vectortypes::TMatrix4f FTransfMat;
	Stage::Vectortypes::TMatrix4f FScaleMat;
	Stage::Vectortypes::TMatrix4f ParentMatrix;
	Gxs::Coordinates::TgxCoordinates4* FS_Rot3DS;
	Gxs::Coordinates::TgxCoordinates4* FRot3DS;
	Gxs::Coordinates::TgxCoordinates4* FScale3DS;
	void __fastcall ReadMesh(System::Classes::TStream* Stream);
	void __fastcall WriteMesh(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	Stage::Vectortypes::TMatrix4f FRefMat;
	__fastcall virtual TgxFile3DSFreeForm(System::Classes::TComponent* AOWner);
	__fastcall virtual ~TgxFile3DSFreeForm();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall CoordinateChanged(Gxs::Coordinates::TgxCustomCoordinates* Sender);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	
__published:
	__property Gxs::Coordinates::TgxCoordinates4* S_Rot3DS = {read=FS_Rot3DS};
	__property Gxs::Coordinates::TgxCoordinates4* Rot3DS = {read=FRot3DS};
	__property Gxs::Coordinates::TgxCoordinates4* Scale3DS = {read=FScale3DS};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFile3DSFreeForm(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxFreeForm(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vFile3DSSceneObjects_RenderCameraAndLights;
}	/* namespace File3dssceneobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILE3DSSCENEOBJECTS)
using namespace Gxs::File3dssceneobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_File3DSSceneObjectsHPP
