// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.ConeExtend.pas' rev: 36.00 (Windows)

#ifndef GBE_ConeExtendHPP
#define GBE_ConeExtendHPP

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
#include <System.Math.Vectors.hpp>
#include <FMX.MaterialSources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Coneextend
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomMeshHelper;
class DELPHICLASS TGBEConeExtend;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCustomMeshHelper : public Fmx::Objects3d::TCustomMesh
{
	typedef Fmx::Objects3d::TCustomMesh inherited;
	
public:
	/* TCustomMesh.Create */ inline __fastcall virtual TCustomMeshHelper(System::Classes::TComponent* AOwner) : Fmx::Objects3d::TCustomMesh(AOwner) { }
	/* TCustomMesh.Destroy */ inline __fastcall virtual ~TCustomMeshHelper() { }
	
};


enum DECLSPEC_DENUM TConeForme : unsigned char { PyramidTriangle, PyramidSquare, Tipi, Cone };

class PASCALIMPLEMENTATION TGBEConeExtend : public Fmx::Objects3d::TCone
{
	typedef Fmx::Objects3d::TCone inherited;
	
private:
	TConeForme fForme;
	bool fShowlines;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	void __fastcall SetForme(const TConeForme Value);
	void __fastcall CreateGBECone(Fmx::Types3d::TMeshData* const aData, const TConeForme aForme = (TConeForme)(0x3));
	
public:
	__fastcall virtual TGBEConeExtend(System::Classes::TComponent* AOwner);
	virtual void __fastcall Render();
	
__published:
	__property TConeForme Forme = {read=fForme, write=SetForme, nodefault};
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
public:
	/* TCustomMesh.Destroy */ inline __fastcall virtual ~TGBEConeExtend() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Coneextend */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_CONEEXTEND)
using namespace Gbe::Coneextend;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_ConeExtendHPP
