// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.PerlinPFX.pas' rev: 36.00 (Windows)

#ifndef GXS_PerlinPFXHPP
#define GXS_PerlinPFXHPP

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
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.ParticleFX.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Perlinpfx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxPerlinPFXManager;
class DELPHICLASS TgxPerlin3DNoise;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxPerlinPFXManager : public Gxs::Particlefx::TgxBaseSpritePFXManager
{
	typedef Gxs::Particlefx::TgxBaseSpritePFXManager inherited;
	
private:
	int FTexMapSize;
	int FNoiseSeed;
	int FNoiseScale;
	int FNoiseAmplitude;
	float FSmoothness;
	float FBrightness;
	float FGamma;
	
protected:
	virtual void __fastcall PrepareImage(Gxs::Graphics::TgxBitmap32* bmp32, int &texFormat);
	void __fastcall SetTexMapSize(const int val);
	void __fastcall SetNoiseSeed(const int val);
	void __fastcall SetNoiseScale(const int val);
	void __fastcall SetNoiseAmplitude(const int val);
	void __fastcall SetSmoothness(const float val);
	void __fastcall SetBrightness(const float val);
	void __fastcall SetGamma(const float val);
	
public:
	__fastcall virtual TgxPerlinPFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxPerlinPFXManager();
	
__published:
	__property int TexMapSize = {read=FTexMapSize, write=SetTexMapSize, default=6};
	__property float Smoothness = {read=FSmoothness, write=SetSmoothness};
	__property float Brightness = {read=FBrightness, write=SetBrightness};
	__property float Gamma = {read=FGamma, write=SetGamma};
	__property int NoiseSeed = {read=FNoiseSeed, write=SetNoiseSeed, default=0};
	__property int NoiseScale = {read=FNoiseScale, write=SetNoiseScale, default=100};
	__property int NoiseAmplitude = {read=FNoiseAmplitude, write=SetNoiseAmplitude, default=50};
	__property ColorMode = {default=1};
	__property SpritesPerTexture = {default=1};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPerlin3DNoise : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::StaticArray<int, 256> FPermutations;
	System::StaticArray<float, 768> FGradients;
	float __fastcall Lattice(int ix, int iy, int iz, float fx, float fy, float fz)/* overload */;
	float __fastcall Lattice(int ix, int iy, float fx, float fy)/* overload */;
	
public:
	__fastcall TgxPerlin3DNoise(int randomSeed);
	void __fastcall Initialize(int randomSeed);
	float __fastcall Noise(const float x, const float y)/* overload */;
	float __fastcall Noise(const float x, const float y, const float z)/* overload */;
	float __fastcall Noise(const Stage::Vectorgeometry::TAffineVector &v)/* overload */;
	float __fastcall Noise(const Stage::Vectortypes::TVector4f &v)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxPerlin3DNoise() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word cPERLIN_TABLE_SIZE = System::Word(0x100);
}	/* namespace Perlinpfx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PERLINPFX)
using namespace Gxs::Perlinpfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PerlinPFXHPP
