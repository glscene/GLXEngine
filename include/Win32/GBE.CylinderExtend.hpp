// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.CylinderExtend.pas' rev: 36.00 (Windows)

#ifndef GBE_CylinderExtendHPP
#define GBE_CylinderExtendHPP

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
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.MaterialSources.hpp>
#include <System.Math.Vectors.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Cylinderextend
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomMeshHelper;
class DELPHICLASS TGBECylinderExtend;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCustomMeshHelper : public Fmx::Objects3d::TCustomMesh
{
	typedef Fmx::Objects3d::TCustomMesh inherited;
	
public:
	/* TCustomMesh.Create */ inline __fastcall virtual TCustomMeshHelper(System::Classes::TComponent* AOwner) : Fmx::Objects3d::TCustomMesh(AOwner) { }
	/* TCustomMesh.Destroy */ inline __fastcall virtual ~TCustomMeshHelper() { }
	
};


class PASCALIMPLEMENTATION TGBECylinderExtend : public Fmx::Objects3d::TCylinder
{
	typedef Fmx::Objects3d::TCylinder inherited;
	
private:
	Fmx::Objects3d::TDisk* fDiskTop;
	Fmx::Objects3d::TDisk* fDiskBottom;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceTop;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceBottom;
	void __fastcall CreateGBECylinder();
	void __fastcall SetMaterialSourceBottom(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceTop(Fmx::Materialsources::TMaterialSource* const Value);
	
public:
	__fastcall virtual TGBECylinderExtend(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBECylinderExtend();
	virtual void __fastcall Render();
	
__published:
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceTop = {read=FMaterialSourceTop, write=SetMaterialSourceTop};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceBottom = {read=FMaterialSourceBottom, write=SetMaterialSourceBottom};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Cylinderextend */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_CYLINDEREXTEND)
using namespace Gbe::Cylinderextend;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_CylinderExtendHPP
