// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.PlaneExtend.pas' rev: 36.00 (Windows)

#ifndef GBE_PlaneExtendHPP
#define GBE_PlaneExtendHPP

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
#include <System.Generics.Collections.hpp>
#include <System.Threading.hpp>
#include <System.Math.Vectors.hpp>
#include <System.RTLConsts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.MaterialSources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Planeextend
{
//-- forward type declarations -----------------------------------------------
struct TWaveRec;
class DELPHICLASS TGBEPlaneExtend;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TWaveRec
{
public:
	System::Math::Vectors::TPoint3D P;
	System::Math::Vectors::TPoint3D D;
	float __fastcall Wave(float aSum, float aX, float aY, float aT);
	bool __fastcall calcWaveAmplitudeAndPitch(float aCap, float aX, float aY, float aT, float &aSumAmplitude, float &aSumDerivative);
};


class PASCALIMPLEMENTATION TGBEPlaneExtend : public Fmx::Objects3d::TPlane
{
	typedef Fmx::Objects3d::TPlane inherited;
	
private:
	float fAmplitude;
	float fLongueur;
	float fVitesse;
	System::Math::Vectors::TPoint3D fOrigine;
	void __fastcall CalcWaves(const System::Math::Vectors::TPoint3D &D);
	
protected:
	float fTime;
	int fNbMesh;
	bool fActiveWaves;
	bool fShowlines;
	bool fUseTasks;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	System::Math::Vectors::TPoint3D fCenter;
	
public:
	__fastcall virtual TGBEPlaneExtend(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEPlaneExtend();
	virtual void __fastcall Render();
	float __fastcall Altura(const System::Math::Vectors::TPoint3D &P);
	
__published:
	__property bool ActiveWaves = {read=fActiveWaves, write=fActiveWaves, nodefault};
	
public:
	__property System::Math::Vectors::TPoint3D Origine = {read=fOrigine, write=fOrigine};
	
__published:
	__property float Amplitude = {read=fAmplitude, write=fAmplitude};
	__property float Longueur = {read=fLongueur, write=fLongueur};
	__property float Vitesse = {read=fVitesse, write=fVitesse};
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property bool UseTasks = {read=fUseTasks, write=fUseTasks, nodefault};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Planeextend */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_PLANEEXTEND)
using namespace Gbe::Planeextend;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_PlaneExtendHPP
