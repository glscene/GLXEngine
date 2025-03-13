// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.RenderContextInfo.pas' rev: 36.00 (Windows)

#ifndef GLS_RenderContextInfoHPP
#define GLS_RenderContextInfoHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <GLS.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GLS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Rendercontextinfo
{
//-- forward type declarations -----------------------------------------------
struct TGLSize;
struct TGLRenderContextClippingInfo;
struct TGLRenderContextInfo;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLDrawState : unsigned char { dsRendering, dsPicking, dsPrinting };

struct DECLSPEC_DRECORD TGLSize
{
public:
	System::LongInt cx;
	System::LongInt cy;
};


enum DECLSPEC_DENUM TGLObjectsSorting : unsigned char { osInherited, osNone, osRenderFarthestFirst, osRenderBlendedLast, osRenderNearestFirst };

enum DECLSPEC_DENUM TGLVisibilityCulling : unsigned char { vcInherited, vcNone, vcObjectBased, vcHierarchical };

struct DECLSPEC_DRECORD TGLRenderContextClippingInfo
{
public:
	Stage::Vectortypes::TGLVector Origin;
	Stage::Vectortypes::TGLVector ClippingDirection;
	float ViewPortRadius;
	float NearClippingDistance;
	float FarClippingDistance;
	Stage::Vectorgeometry::TFrustum Frustum;
};


struct DECLSPEC_DRECORD TGLRenderContextInfo
{
public:
	System::TObject* Scene;
	System::TObject* Buffer;
	Stage::Vectortypes::TGLVector CameraPosition;
	Stage::Vectortypes::TGLVector CameraDirection;
	Stage::Vectortypes::TGLVector CameraUp;
	TGLSize ViewPortSize;
	int RenderDPI;
	System::TObject* MaterialLibrary;
	System::TObject* LightMapLibrary;
	int FogDisabledCounter;
	TGLDrawState DrawState;
	TGLObjectsSorting ObjectsSorting;
	TGLVisibilityCulling VisibilityCulling;
	Gls::State::TGLStateCache* GLStates;
	Stage::Pipelinetransform::TgTransformation* PipelineTransformation;
	TGLRenderContextClippingInfo Rcci;
	Gls::Color::TGLColorVector SceneAmbientColor;
	bool BufferFaceCull;
	bool BufferLighting;
	bool BufferFog;
	bool BufferDepthTest;
	bool ProxySubObject;
	bool IgnoreMaterials;
	bool IgnoreBlendingRequests;
	bool IgnoreDepthRequests;
	bool Amalgamating;
	Gls::Persistentclasses::TGLPersistentObjectList* Lights;
	Gls::Persistentclasses::TGLPersistentObjectList* AfterRenderEffects;
	Gls::State::TGLMaterialLevel CurrentMaterialLevel;
	Gls::State::TGLMeshPrimitives PrimitiveMask;
	int OrderCounter;
};


typedef TGLRenderContextInfo *PGLRenderContextInfo;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Rendercontextinfo */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_RENDERCONTEXTINFO)
using namespace Gls::Rendercontextinfo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_RenderContextInfoHPP
