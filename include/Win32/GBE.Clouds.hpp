// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.Clouds.pas' rev: 36.00 (Windows)

#ifndef GBE_CloudsHPP
#define GBE_CloudsHPP

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
#include <System.Math.Vectors.hpp>
#include <System.Threading.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.MaterialSources.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Clouds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBEClouds;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGBEClouds : public Fmx::Objects3d::TDummy
{
	typedef Fmx::Objects3d::TDummy inherited;
	
private:
	System::Generics::Collections::TList__1<Fmx::Objects3d::TPlane*>* fListClouds;
	int fNbClouds;
	int fLimits;
	float fWindSpeed;
	bool fActiveWind;
	bool fUseTasks;
	System::Generics::Collections::TList__1<Fmx::Materialsources::TTextureMaterialSource*>* fTexturesClouds;
	int __fastcall GetNbClouds();
	float __fastcall GetWindSpeed();
	void __fastcall SetNbClouds(const int Value);
	void __fastcall SetWindSpeed(const float Value);
	int __fastcall GetLimits();
	void __fastcall SetLimits(const int Value);
	bool __fastcall GetActiveWind();
	void __fastcall SetActiveWind(const bool Value);
	void __fastcall DeplacementNuages();
	
public:
	__fastcall virtual TGBEClouds(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEClouds();
	void __fastcall DeleteTexturesClouds();
	void __fastcall AddTextureCloud(Fmx::Materialsources::TTextureMaterialSource* TextureMaterial);
	void __fastcall MoveClouds();
	void __fastcall GenerateClouds();
	
__published:
	__property bool ActiveWind = {read=GetActiveWind, write=SetActiveWind, nodefault};
	__property int Limits = {read=GetLimits, write=SetLimits, nodefault};
	__property int NbClouds = {read=GetNbClouds, write=SetNbClouds, nodefault};
	__property float WindSpeed = {read=GetWindSpeed, write=SetWindSpeed};
	__property bool UseTasks = {read=fUseTasks, write=fUseTasks, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Clouds */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_CLOUDS)
using namespace Gbe::Clouds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_CloudsHPP
