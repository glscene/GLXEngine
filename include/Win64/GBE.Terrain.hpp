// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.Terrain.pas' rev: 36.00 (Windows)

#ifndef GBE_TerrainHPP
#define GBE_TerrainHPP

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
#include <System.Types.hpp>
#include <System.Math.Vectors.hpp>
#include <System.RTLConsts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Graphics.hpp>
#include <System.Math.hpp>
#include <uGBEUtils3D.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Terrain
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBETerrain;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGBETerrain : public Fmx::Objects3d::TMesh
{
	typedef Fmx::Objects3d::TMesh inherited;
	
private:
	float fAmplitude;
	float fRoughness;
	float fScalling;
	int fOctaves;
	int fSubdivX;
	int fSubdivZ;
	int fSeed;
	int fXOffset;
	int fZOffset;
	bool FUseRamp;
	float __fastcall GetInterpolatedNoise(float X, float Z);
	float __fastcall Interpolate(float a, float b, float blend);
	float __fastcall Noise(int X, int Z);
	float __fastcall SmoothNoise(int X, int Z);
	void __fastcall SetUseRamp(const bool Value);
	float __fastcall GenerateHeight(int X, int Z);
	
public:
	__fastcall virtual TGBETerrain(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBETerrain();
	void __fastcall Clean();
	void __fastcall GenerateTerrain();
	float __fastcall GetHeight(const System::Math::Vectors::TPoint3D &P);
	
__published:
	__property float Amplitude = {read=fAmplitude, write=fAmplitude};
	__property float Roughness = {read=fRoughness, write=fRoughness};
	__property int Octaves = {read=fOctaves, write=fOctaves, nodefault};
	__property int XOffset = {read=fXOffset, write=fXOffset, nodefault};
	__property int ZOffset = {read=fZOffset, write=fZOffset, nodefault};
	__property int Seed = {read=fSeed, write=fSeed, nodefault};
	__property int SubdivX = {read=fSubdivX, write=fSubdivX, nodefault};
	__property int SubdivZ = {read=fSubdivZ, write=fSubdivZ, nodefault};
	__property bool UseRamp = {read=FUseRamp, write=SetUseRamp, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Terrain */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_TERRAIN)
using namespace Gbe::Terrain;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_TerrainHPP
