// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.SphereExtend.pas' rev: 36.00 (Windows)

#ifndef GBE_SphereExtendHPP
#define GBE_SphereExtendHPP

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
#include <System.RTLConsts.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.MaterialSources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Sphereextend
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomMeshHelper;
class DELPHICLASS TGBESphereExtend;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCustomMeshHelper : public Fmx::Objects3d::TCustomMesh
{
	typedef Fmx::Objects3d::TCustomMesh inherited;
	
public:
	/* TCustomMesh.Create */ inline __fastcall virtual TCustomMeshHelper(System::Classes::TComponent* AOwner) : Fmx::Objects3d::TCustomMesh(AOwner) { }
	/* TCustomMesh.Destroy */ inline __fastcall virtual ~TCustomMeshHelper() { }
	
};


enum DECLSPEC_DENUM TSpheroid : unsigned char { capsule, dome, culbuto, sphere, apple, pot, diamond };

class PASCALIMPLEMENTATION TGBESphereExtend : public Fmx::Objects3d::TMesh
{
	typedef Fmx::Objects3d::TMesh inherited;
	
private:
	int fSubdivisionsAxes;
	int fSubdivisionsHeight;
	TSpheroid fSpheroid;
	float fLongueur;
	bool fShowlines;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	void __fastcall CreateGBESphere(Fmx::Types3d::TMeshData* const aData, const TSpheroid aForme = (TSpheroid)(0x3), const float aLength = 1.000000E+00f);
	
protected:
	void __fastcall SetForme(TSpheroid Value);
	void __fastcall SetLongueur(float Value);
	void __fastcall SetSubdivisionsAxes(int Value);
	void __fastcall SetSubdivisionsHeight(int Value);
	
public:
	__fastcall virtual TGBESphereExtend(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBESphereExtend();
	virtual void __fastcall Render();
	
__published:
	__property int SubdivisionsAxes = {read=fSubdivisionsAxes, write=SetSubdivisionsAxes, nodefault};
	__property int SubdivisionsHeight = {read=fSubdivisionsHeight, write=SetSubdivisionsHeight, nodefault};
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property TSpheroid Forme = {read=fSpheroid, write=SetForme, nodefault};
	__property float Longueur = {read=fLongueur, write=SetLongueur};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Sphereextend */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_SPHEREEXTEND)
using namespace Gbe::Sphereextend;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_SphereExtendHPP
