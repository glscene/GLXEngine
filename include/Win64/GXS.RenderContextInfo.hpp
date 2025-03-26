// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.RenderContextInfo.pas' rev: 36.00 (Windows)

#ifndef GXS_RenderContextInfoHPP
#define GXS_RenderContextInfoHPP

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
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Rendercontextinfo
{
//-- forward type declarations -----------------------------------------------
struct TGXSize;
struct TGXRenderContextClippingInfo;
struct TgxRenderContextInfo;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGXDrawState : unsigned char { dsRendering, dsPicking, dsPrinting };

struct DECLSPEC_DRECORD TGXSize
{
public:
	System::LongInt cx;
	System::LongInt cy;
};


enum DECLSPEC_DENUM TgxObjectsSorting : unsigned char { osInherited, osNone, osRenderFarthestFirst, osRenderBlendedLast, osRenderNearestFirst };

enum DECLSPEC_DENUM TgxVisibilityCulling : unsigned char { vcInherited, vcNone, vcObjectBased, vcHierarchical };

struct DECLSPEC_DRECORD TGXRenderContextClippingInfo
{
public:
	Stage::Vectortypes::TVector4f origin;
	Stage::Vectortypes::TVector4f clippingDirection;
	float viewPortRadius;
	float nearClippingDistance;
	float farClippingDistance;
	Stage::Vectorgeometry::TFrustum frustum;
};


struct DECLSPEC_DRECORD TgxRenderContextInfo
{
public:
	System::TObject* scene;
	System::TObject* buffer;
	Stage::Vectortypes::TVector4f cameraPosition;
	Stage::Vectortypes::TVector4f cameraDirection;
	Stage::Vectortypes::TVector4f cameraUp;
	TGXSize viewPortSize;
	int renderDPI;
	System::TObject* materialLibrary;
	System::TObject* lightmapLibrary;
	int fogDisabledCounter;
	TGXDrawState drawState;
	TgxObjectsSorting objectsSorting;
	TgxVisibilityCulling visibilityCulling;
	Gxs::State::TgxStateCache* gxStates;
	Stage::Pipelinetransform::TgTransformation* PipelineTransformation;
	TGXRenderContextClippingInfo rcci;
	Gxs::Color::TgxColorVector sceneAmbientColor;
	bool bufferFaceCull;
	bool bufferLighting;
	bool bufferFog;
	bool bufferDepthTest;
	bool proxySubObject;
	bool ignoreMaterials;
	bool ignoreBlendingRequests;
	bool ignoreDepthRequests;
	bool amalgamating;
	Gxs::Persistentclasses::TgxPersistentObjectList* lights;
	Gxs::Persistentclasses::TgxPersistentObjectList* afterRenderEffects;
	Gxs::State::TgxMaterialLevel currentMaterialLevel;
	Gxs::State::TgxMeshPrimitives primitiveMask;
	int orderCounter;
};


typedef TgxRenderContextInfo *PGXRenderContextInfo;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Rendercontextinfo */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_RENDERCONTEXTINFO)
using namespace Gxs::Rendercontextinfo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_RenderContextInfoHPP
