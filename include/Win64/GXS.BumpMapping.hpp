// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.BumpMapping.pas' rev: 36.00 (Windows)

#ifndef GXS_BumpMappingHPP
#define GXS_BumpMappingHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <GXS.Color.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Bumpmapping
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TNormalMapSpace : unsigned char { nmsObject, nmsTangent };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall CalcObjectSpaceLightVectors(const Stage::Vectorgeometry::TAffineVector &Light, Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxVectorList* Colors);
extern DELPHI_PACKAGE void __fastcall SetupTangentSpace(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxAffineVectorList* Normals, Gxs::Vectorlists::TgxAffineVectorList* TexCoords, Gxs::Vectorlists::TgxAffineVectorList* Tangents, Gxs::Vectorlists::TgxAffineVectorList* BiNormals);
extern DELPHI_PACKAGE void __fastcall CalcTangentSpaceLightVectors(const Stage::Vectorgeometry::TAffineVector &Light, Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxAffineVectorList* Normals, Gxs::Vectorlists::TgxAffineVectorList* Tangents, Gxs::Vectorlists::TgxAffineVectorList* BiNormals, Gxs::Vectorlists::TgxVectorList* Colors);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall CreateObjectSpaceNormalMap(int Width, int Height, Gxs::Vectorlists::TgxAffineVectorList* HiNormals, Gxs::Vectorlists::TgxAffineVectorList* HiTexCoords);
extern DELPHI_PACKAGE Fmx::Graphics::TBitmap* __fastcall CreateTangentSpaceNormalMap(int Width, int Height, Gxs::Vectorlists::TgxAffineVectorList* HiNormals, Gxs::Vectorlists::TgxAffineVectorList* HiTexCoords, Gxs::Vectorlists::TgxAffineVectorList* LoNormals, Gxs::Vectorlists::TgxAffineVectorList* LoTexCoords, Gxs::Vectorlists::TgxAffineVectorList* Tangents, Gxs::Vectorlists::TgxAffineVectorList* BiNormals);
}	/* namespace Bumpmapping */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BUMPMAPPING)
using namespace Gxs::Bumpmapping;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BumpMappingHPP
