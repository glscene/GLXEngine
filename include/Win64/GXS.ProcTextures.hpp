// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ProcTextures.pas' rev: 36.00 (Windows)

#ifndef GXS_ProcTexturesHPP
#define GXS_ProcTexturesHPP

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
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Graphics.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Proctextures
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxProcTextureNoise;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxProcTextureNoise : public Gxs::Texture::TgxTextureImage
{
	typedef Gxs::Texture::TgxTextureImage inherited;
	
private:
	Gxs::Graphics::TgxBitmap32* FNoiseMap;
	int FWidth;
	int FHeight;
	System::Byte FMinCut;
	float FNoiseSharpness;
	float FNoiseAnimate;
	bool FSeamless;
	System::LongInt FNoiseRandSeed;
	
protected:
	System::StaticArray<float, 768> FGradients;
	System::StaticArray<System::Byte, 256> PERM;
	virtual int __fastcall GetWidth();
	virtual int __fastcall GetHeight();
	virtual int __fastcall GetDepth();
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	float __fastcall Noise(float x, float y);
	void __fastcall SetMinCut(const System::Byte val);
	void __fastcall SetSeamless(const bool val);
	void __fastcall SetWidth(const int val);
	void __fastcall SetHeight(const int val);
	void __fastcall SetNoiseSharpness(const float val);
	void __fastcall SetNoiseRandSeed(const System::LongInt val);
	void __fastcall UpdateNoise();
	
public:
	__fastcall virtual TgxProcTextureNoise(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxProcTextureNoise();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Gxs::Graphics::TgxBitmap32* __fastcall GetBitmap32();
	virtual void __fastcall ReleaseBitmap32();
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall NoiseAnimate(float speed);
	void __fastcall SetPermFromData(System::Byte *inPERM, const System::NativeInt inPERM_High);
	void __fastcall SetPermToDefault();
	
__published:
	__property int Width = {read=GetWidth, write=SetWidth, default=128};
	__property int Height = {read=GetHeight, write=SetHeight, default=128};
	__property int Depth = {read=GetDepth, nodefault};
	__property System::Byte MinCut = {read=FMinCut, write=SetMinCut, nodefault};
	__property float NoiseSharpness = {read=FNoiseSharpness, write=SetNoiseSharpness};
	__property bool Seamless = {read=FSeamless, write=SetSeamless, nodefault};
	__property System::LongInt NoiseRandSeed = {read=FNoiseRandSeed, write=SetNoiseRandSeed, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word GRADIENT_TABLE_SIZE = System::Word(0x100);
static _DELPHI_CONST System::Int8 DAMP_SHIFT = System::Int8(0x14);
}	/* namespace Proctextures */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PROCTEXTURES)
using namespace Gxs::Proctextures;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ProcTexturesHPP
