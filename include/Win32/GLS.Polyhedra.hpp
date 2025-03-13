// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Polyhedra.pas' rev: 36.00 (Windows)

#ifndef GLS_PolyhedraHPP
#define GLS_PolyhedraHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <Vcl.Consts.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Scene.hpp>
#include <GLS.BaseClasses.hpp>
#include <GLS.Objects.hpp>
#include <GLS.GeomObjects.hpp>
#include <GLS.Portal.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Silhouette.hpp>
#include <Stage.Strings.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Material.hpp>
#include <GLS.Mesh.hpp>
#include <Stage.Logger.hpp>
#include <GLS.Octree.hpp>
#include <GLS.GeometryBB.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.Context.hpp>
#include <GLS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Polyhedra
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLPolyTet;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLPolyTet : public Gls::Geomobjects::TGLPolygon
{
	typedef Gls::Geomobjects::TGLPolygon inherited;
	
public:
	__fastcall TGLPolyTet(Gls::Geomobjects::TGLPolygon* AOwner);
	__fastcall virtual ~TGLPolyTet();
public:
	/* TGLPolygon.Create */ inline __fastcall virtual TGLPolyTet(System::Classes::TComponent* AOwner) : Gls::Geomobjects::TGLPolygon(AOwner) { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLPolyTet(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Geomobjects::TGLPolygon(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Polyhedra */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_POLYHEDRA)
using namespace Gls::Polyhedra;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_PolyhedraHPP
