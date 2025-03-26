// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MeshCSG.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshCSGHPP
#define GXS_MeshCSGHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BSP.hpp>
#include <GXS.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Meshcsg
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TCSGOperation : unsigned char { CSG_Union, CSG_Subtraction, CSG_Intersection };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall CSG_Operation(Gxs::Vectorfileobjects::TgxMeshObject* obj1, Gxs::Vectorfileobjects::TgxMeshObject* obj2, TCSGOperation Operation, Gxs::Vectorfileobjects::TgxMeshObject* Res, const System::UnicodeString MaterialName1, const System::UnicodeString MaterialName2);
}	/* namespace Meshcsg */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESHCSG)
using namespace Gxs::Meshcsg;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshCSGHPP
