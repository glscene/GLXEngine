// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.OceanWaves.pas' rev: 36.00 (Windows)

#ifndef GXS_OceanWavesHPP
#define GXS_OceanWavesHPP

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
#include <System.Types.hpp>
#include <System.Threading.hpp>
#include <System.Math.Vectors.hpp>
#include <System.Generics.Collections.hpp>
#include <System.RTLConsts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.MaterialSources.hpp>
#include <GBE.PlaneExtend.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Oceanwaves
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxWaveSystem;
class DELPHICLASS TgxOceanSurface;
class DELPHICLASS TgxWindArrowSurface;
class DELPHICLASS TgxTwoWavesOceanSurface;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxWaveSystem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	float fTime;
	float fAmplitude;
	float fLongueur;
	float fVitesse;
	System::Math::Vectors::TPoint3D fOrigine;
	float fAmplitude2;
	float fLongueur2;
	float fVitesse2;
	System::Math::Vectors::TPoint3D fOrigine2;
	float fAmplitude3;
	float fLongueur3;
	float fVitesse3;
	System::Math::Vectors::TPoint3D fOrigine3;
	float fAmplitude4;
	float fLongueur4;
	float fVitesse4;
	System::Math::Vectors::TPoint3D fOrigine4;
	float fAmplitude5;
	float fLongueur5;
	float fVitesse5;
	System::Math::Vectors::TPoint3D fOrigine5;
	
protected:
	System::Math::Vectors::TPoint3D __fastcall GetWaveParams1();
	System::Math::Vectors::TPoint3D __fastcall GetWaveParams2();
	System::Math::Vectors::TPoint3D __fastcall GetWaveParams3();
	System::Math::Vectors::TPoint3D __fastcall GetWaveParams4();
	System::Math::Vectors::TPoint3D __fastcall GetWaveParams5();
	
public:
	__fastcall virtual TgxWaveSystem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxWaveSystem();
	void __fastcall IncTime();
	__property float WaveTime = {read=fTime, write=fTime};
	__property System::Math::Vectors::TPoint3D Origine = {read=fOrigine, write=fOrigine};
	
__published:
	__property float Amplitude = {read=fAmplitude, write=fAmplitude};
	__property float Longueur = {read=fLongueur, write=fLongueur};
	__property float Vitesse = {read=fVitesse, write=fVitesse};
	
public:
	__property System::Math::Vectors::TPoint3D Origine2 = {read=fOrigine2, write=fOrigine2};
	
__published:
	__property float Amplitude2 = {read=fAmplitude2, write=fAmplitude2};
	__property float Longueur2 = {read=fLongueur2, write=fLongueur2};
	__property float Vitesse2 = {read=fVitesse2, write=fVitesse2};
	
public:
	__property System::Math::Vectors::TPoint3D Origine3 = {read=fOrigine3, write=fOrigine3};
	
__published:
	__property float Amplitude3 = {read=fAmplitude3, write=fAmplitude3};
	__property float Longueur3 = {read=fLongueur3, write=fLongueur3};
	__property float Vitesse3 = {read=fVitesse3, write=fVitesse3};
	
public:
	__property System::Math::Vectors::TPoint3D Origine4 = {read=fOrigine4, write=fOrigine4};
	
__published:
	__property float Amplitude4 = {read=fAmplitude4, write=fAmplitude4};
	__property float Longueur4 = {read=fLongueur4, write=fLongueur4};
	__property float Vitesse4 = {read=fVitesse4, write=fVitesse4};
	
public:
	__property System::Math::Vectors::TPoint3D Origine5 = {read=fOrigine5, write=fOrigine5};
	
__published:
	__property float Amplitude5 = {read=fAmplitude5, write=fAmplitude5};
	__property float Longueur5 = {read=fLongueur5, write=fLongueur5};
	__property float Vitesse5 = {read=fVitesse5, write=fVitesse5};
};


class PASCALIMPLEMENTATION TgxOceanSurface : public Fmx::Objects3d::TPlane
{
	typedef Fmx::Objects3d::TPlane inherited;
	
private:
	TgxWaveSystem* fWaveSystem;
	void __fastcall CalcWaves();
	
protected:
	int fNbMesh;
	bool fActiveWaves;
	bool fShowlines;
	bool fUseTasks;
	System::Math::Vectors::TPoint3D fDivPerM;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	
public:
	System::Math::Vectors::TPoint3D fVirtualSeaOrigin;
	__fastcall virtual TgxOceanSurface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxOceanSurface();
	bool __fastcall calcWaveAmplitudeAndPitch(const System::Math::Vectors::TPoint3D &P, const float aCap, float &aAmplitude, float &aPitch);
	virtual void __fastcall Render();
	void __fastcall MoveTextureBy(float &dx, float &dy);
	void __fastcall GetPointsTexCoordinates(System::UnicodeString &P, System::UnicodeString &TC);
	
__published:
	__property bool ActiveWaves = {read=fActiveWaves, write=fActiveWaves, nodefault};
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property TgxWaveSystem* WaveSystem = {read=fWaveSystem, write=fWaveSystem};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
	
public:
	__property System::Math::Vectors::TPoint3D DivPerM = {read=fDivPerM};
};


class PASCALIMPLEMENTATION TgxWindArrowSurface : public Fmx::Objects3d::TPlane
{
	typedef Fmx::Objects3d::TPlane inherited;
	
private:
	int fVersion;
	TgxWaveSystem* fWaveSystem;
	void __fastcall CalcArrowMesh();
	void __fastcall setVersion(const int Value);
	
protected:
	int fNbMesh;
	bool fActiveWaves;
	bool fShowlines;
	bool fUseTasks;
	System::Math::Vectors::TPoint3D fDivPerM;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	virtual void __fastcall SetDepth(const float Value);
	
public:
	__fastcall virtual TgxWindArrowSurface(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxWindArrowSurface();
	virtual void __fastcall Render();
	
__published:
	__property bool ActiveWaves = {read=fActiveWaves, write=fActiveWaves, nodefault};
	__property bool ShowLines = {read=fShowlines, write=fShowlines, nodefault};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
	
public:
	__property System::Math::Vectors::TPoint3D DivPerM = {read=fDivPerM};
	
__published:
	__property int version = {read=fVersion, write=setVersion, nodefault};
};


class PASCALIMPLEMENTATION TgxTwoWavesOceanSurface : public TgxOceanSurface
{
	typedef TgxOceanSurface inherited;
	
public:
	/* TgxOceanSurface.Create */ inline __fastcall virtual TgxTwoWavesOceanSurface(System::Classes::TComponent* AOwner) : TgxOceanSurface(AOwner) { }
	/* TgxOceanSurface.Destroy */ inline __fastcall virtual ~TgxTwoWavesOceanSurface() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Oceanwaves */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_OCEANWAVES)
using namespace Gxs::Oceanwaves;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_OceanWavesHPP
