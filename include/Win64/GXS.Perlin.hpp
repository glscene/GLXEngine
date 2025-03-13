// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Perlin.pas' rev: 36.00 (Windows)

#ifndef GXS_PerlinHPP
#define GXS_PerlinHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.HeightData.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Perlin
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBasePerlinOctav;
class DELPHICLASS TgxBasePerlin;
class DELPHICLASS Tgx1DPerlin;
class DELPHICLASS Tgx2DPerlinOctav;
class DELPHICLASS Tgx2DPerlin;
class DELPHICLASS TgxPerlinHDS;
class DELPHICLASS TgxPerlinHDSThread;
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<double> T1DPerlinArray;

typedef System::DynamicArray<T1DPerlinArray> T2DPerlinArray;

enum DECLSPEC_DENUM TgxPerlinInterpolation : unsigned char { pi_none, pi_simple, pi_linear, pi_Smoothed, pi_Cosine, pi_cubic };

class PASCALIMPLEMENTATION TgxBasePerlinOctav : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	double FAmplitude;
	double FScale;
	TgxPerlinInterpolation FInterpolation;
	TgxPerlinInterpolation FSmoothing;
	
public:
	virtual void __fastcall Generate() = 0 ;
	__property TgxPerlinInterpolation Interpolation = {read=FInterpolation, write=FInterpolation, nodefault};
	__property TgxPerlinInterpolation Smoothing = {read=FSmoothing, write=FSmoothing, nodefault};
	__property double Amplitude = {read=FAmplitude, write=FAmplitude};
	__property double Scale = {read=FScale, write=FScale};
public:
	/* TObject.Create */ inline __fastcall TgxBasePerlinOctav() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxBasePerlinOctav() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxPerlinOctav);

class PASCALIMPLEMENTATION TgxBasePerlin : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	double FPersistence;
	int FNumber_Of_Octaves;
	System::Classes::TList* FOctaves;
	TgxPerlinOctav FOctavClass;
	TgxPerlinInterpolation FInterpolation;
	TgxPerlinInterpolation FSmoothing;
	
protected:
	double __fastcall PerlinNoise_1D(double x);
	double __fastcall PerlinNoise_2D(double x, double y);
	TgxBasePerlinOctav* __fastcall GetOctave(int index);
	void __fastcall SetPersistence(double val);
	void __fastcall Set_Number_Of_Octaves(int val);
	
public:
	__fastcall virtual TgxBasePerlin(System::Classes::TComponent* AOwner);
	virtual void __fastcall Generate() = 0 ;
	__property TgxBasePerlinOctav* Octaves[int index] = {read=GetOctave};
	
__published:
	__property TgxPerlinInterpolation Smoothing = {read=FSmoothing, write=FSmoothing, nodefault};
	__property TgxPerlinInterpolation Interpolation = {read=FInterpolation, write=FInterpolation, nodefault};
	__property double Persistence = {read=FPersistence, write=SetPersistence};
	__property int Number_Of_Octaves = {read=FNumber_Of_Octaves, write=Set_Number_Of_Octaves, nodefault};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TgxBasePerlin() { }
	
};


class PASCALIMPLEMENTATION Tgx1DPerlin : public TgxBasePerlin
{
	typedef TgxBasePerlin inherited;
	
__published:
	double __fastcall GetPerlinValue_1D(double x);
public:
	/* TgxBasePerlin.Create */ inline __fastcall virtual Tgx1DPerlin(System::Classes::TComponent* AOwner) : TgxBasePerlin(AOwner) { }
	
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~Tgx1DPerlin() { }
	
};


class PASCALIMPLEMENTATION Tgx2DPerlinOctav : public TgxBasePerlinOctav
{
	typedef TgxBasePerlinOctav inherited;
	
public:
	T2DPerlinArray Data;
	int Width;
	int Height;
	int XStart;
	int YStart;
	int XStep;
	int YStep;
	int YRate;
	virtual void __fastcall Generate();
	double __fastcall GetDataSmoothed(int x, int y);
	double __fastcall GetData(int x, int y);
	double __fastcall GetCubic(double x, double y);
	double __fastcall GetCosine(double x, double y);
	double __fastcall GetPerling(double x, double y);
	void __fastcall Generate_CubicInterpolate();
	void __fastcall Generate_SmoothInterpolate();
	void __fastcall Generate_NonInterpolated();
public:
	/* TObject.Create */ inline __fastcall Tgx2DPerlinOctav() : TgxBasePerlinOctav() { }
	/* TObject.Destroy */ inline __fastcall virtual ~Tgx2DPerlinOctav() { }
	
};


class PASCALIMPLEMENTATION Tgx2DPerlin : public TgxBasePerlin
{
	typedef TgxBasePerlin inherited;
	
public:
	int Width;
	int Height;
	int XStart;
	int YStart;
	int XStep;
	int YStep;
	double MaxValue;
	double MinValue;
	__fastcall virtual Tgx2DPerlin(System::Classes::TComponent* AOwner);
	virtual void __fastcall Generate();
	double __fastcall GetPerlinValue_2D(double x, double y);
	void __fastcall MakeBitmap(Fmx::Graphics::TBitmap* Param);
	void __fastcall SetHeightData(Gxs::Heightdata::TgxHeightData* heightData);
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~Tgx2DPerlin() { }
	
};


class PASCALIMPLEMENTATION TgxPerlinHDS : public Gxs::Heightdata::TgxHeightDataSource
{
	typedef Gxs::Heightdata::TgxHeightDataSource inherited;
	
private:
	TgxPerlinInterpolation FInterpolation;
	TgxPerlinInterpolation FSmoothing;
	double FPersistence;
	int FNumber_Of_Octaves;
	System::Classes::TStrings* FLines;
	bool FLinesChanged;
	int FXStart;
	int FYStart;
	
public:
	double MaxValue;
	double MinValue;
	bool Stall;
	__fastcall virtual TgxPerlinHDS(System::Classes::TComponent* AOwner);
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* heightData);
	void __fastcall WaitFor();
	__property System::Classes::TStrings* Lines = {read=FLines};
	__property bool LinesChanged = {read=FLinesChanged, write=FLinesChanged, nodefault};
	
__published:
	__property TgxPerlinInterpolation Interpolation = {read=FInterpolation, write=FInterpolation, nodefault};
	__property TgxPerlinInterpolation Smoothing = {read=FSmoothing, write=FSmoothing, nodefault};
	__property double Persistence = {read=FPersistence, write=FPersistence};
	__property int Number_Of_Octaves = {read=FNumber_Of_Octaves, write=FNumber_Of_Octaves, nodefault};
	__property MaxPoolSize;
	__property int XStart = {read=FXStart, write=FXStart, nodefault};
	__property int YStart = {read=FYStart, write=FYStart, nodefault};
public:
	/* TgxHeightDataSource.Destroy */ inline __fastcall virtual ~TgxPerlinHDS() { }
	
};


class PASCALIMPLEMENTATION TgxPerlinHDSThread : public Gxs::Heightdata::TgxHeightDataThread
{
	typedef Gxs::Heightdata::TgxHeightDataThread inherited;
	
public:
	Tgx2DPerlin* Perlin;
	TgxPerlinHDS* PerlinSource;
	void __fastcall OpdateOutSide();
	virtual void __fastcall Execute();
public:
	/* TgxHeightDataThread.Destroy */ inline __fastcall virtual ~TgxPerlinHDSThread() { }
	
public:
	/* TThread.Create */ inline __fastcall TgxPerlinHDSThread()/* overload */ : Gxs::Heightdata::TgxHeightDataThread() { }
	/* TThread.Create */ inline __fastcall TgxPerlinHDSThread(bool CreateSuspended)/* overload */ : Gxs::Heightdata::TgxHeightDataThread(CreateSuspended) { }
	/* TThread.Create */ inline __fastcall TgxPerlinHDSThread(bool CreateSuspended, System::NativeUInt ReservedStackSize)/* overload */ : Gxs::Heightdata::TgxHeightDataThread(CreateSuspended, ReservedStackSize) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall ExponateCrap(int root, int exponant);
extern DELPHI_PACKAGE double __fastcall Perlin_Random1(int x);
extern DELPHI_PACKAGE double __fastcall Perlin_Random2(const int x, const int Y);
extern DELPHI_PACKAGE void __fastcall Perlin_Random1DStrip(int x, int Width, int Step, double Amp, T1DPerlinArray Res);
extern DELPHI_PACKAGE void __fastcall Smooth_Interpolate_Strip(T1DPerlinArray B1, T1DPerlinArray B2, T1DPerlinArray B3, T1DPerlinArray Res, int Width);
extern DELPHI_PACKAGE void __fastcall Cubic_Interpolate_Strip(T1DPerlinArray B1, T1DPerlinArray B2, T1DPerlinArray B3, T1DPerlinArray B4, T1DPerlinArray Res, int Width);
extern DELPHI_PACKAGE double __fastcall Linear_Interpolate(const double a, const double b, const double x);
extern DELPHI_PACKAGE double __fastcall Cosine_Interpolate(const double a, const double b, const double x);
extern DELPHI_PACKAGE double __fastcall Cubic_Interpolate(double v0, double v1, double v2, double v3, double x);
}	/* namespace Perlin */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PERLIN)
using namespace Gxs::Perlin;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_PerlinHPP
