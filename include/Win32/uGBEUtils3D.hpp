// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uGBEUtils3D.pas' rev: 36.00 (Windows)

#ifndef uGBEUtils3DHPP
#define uGBEUtils3DHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Math.Vectors.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types3D.hpp>
#include <System.UITypes.hpp>
#include <FMX.Effects.hpp>
#include <System.UIConsts.hpp>
#include <System.SysUtils.hpp>
#include <System.RTLConsts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Viewport3D.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ugbeutils3d
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomMeshHelper;
struct TGBECollisionRetour;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCustomMeshHelper : public Fmx::Objects3d::TCustomMesh
{
	typedef Fmx::Objects3d::TCustomMesh inherited;
	
public:
	/* TCustomMesh.Create */ inline __fastcall virtual TCustomMeshHelper(System::Classes::TComponent* AOwner) : Fmx::Objects3d::TCustomMesh(AOwner) { }
	/* TCustomMesh.Destroy */ inline __fastcall virtual ~TCustomMeshHelper() { }
	
};


struct DECLSPEC_DRECORD TGBECollisionRetour
{
public:
	bool Bool;
	Fmx::Controls3d::TControl3D* objet;
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float __fastcall Barycentre(const System::Math::Vectors::TPoint3D &p1, const System::Math::Vectors::TPoint3D &p2, const System::Math::Vectors::TPoint3D &p3, const System::Types::TPointF &p4);
extern DELPHI_PACKAGE float __fastcall CalculateHeight(Fmx::Objects3d::TMesh* Mesh, const System::Math::Vectors::TPoint3D &P, float miseAEchelle, int subDivX, int subDivZ);
extern DELPHI_PACKAGE System::Math::Vectors::TPoint3D __fastcall SizeOf3D(Fmx::Controls3d::TControl3D* const unObjet3D);
extern DELPHI_PACKAGE TGBECollisionRetour __fastcall DetectionCollisionObstacle(Fmx::Objects3d::TMesh* Mesh, Fmx::Controls3d::TControl3D* objet);
extern DELPHI_PACKAGE void __fastcall InteractionIHM(Fmx::Viewport3d::TViewport3D* viewport);
extern DELPHI_PACKAGE TGBECollisionRetour __fastcall CollisionDummyChilds(Fmx::Objects3d::TDummy* aDummy, Fmx::Controls3d::TControl3D* objet3D);
extern DELPHI_PACKAGE TGBECollisionRetour __fastcall CollisionEntre2Objets(Fmx::Controls3d::TControl3D* objet1, Fmx::Controls3d::TControl3D* objet2);
}	/* namespace Ugbeutils3d */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UGBEUTILS3D)
using namespace Ugbeutils3d;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uGBEUtils3DHPP
