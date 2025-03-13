// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.Heightmap.pas' rev: 36.00 (Windows)

#ifndef GBE_HeightmapHPP
#define GBE_HeightmapHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.RTLConsts.hpp>
#include <System.Math.hpp>
#include <System.UITypes.hpp>
#include <System.UIConsts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Graphics.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Effects.hpp>
#include <FMX.MaterialSources.hpp>
#include <uGBEUtils3D.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Heightmap
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBEHeightmap;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGBEHeightmap : public Fmx::Objects3d::TMesh
{
	typedef Fmx::Objects3d::TMesh inherited;
	
private:
	int fSubdivisionsX;
	int fSubdivisionsZ;
	int fFlou;
	int fHalfSubdivisionsX;
	int fHalfSubdivisionsZ;
	Fmx::Graphics::TBitmap* fHeightmap;
	bool fTracerLignes;
	bool FUseRamp;
	Fmx::Materialsources::TColorMaterialSource* fMaterialLignes;
	float fMiseAEchelle;
	float fMaxHauteur;
	float fMinHauteur;
	int __fastcall GetFlou();
	void __fastcall SetFlou(const int Value);
	bool __fastcall GetTracerLignes();
	void __fastcall SetTracerLignes(const bool Value);
	void __fastcall SetUseRamp(const bool Value);
	void __fastcall GenerateHeightmap(Fmx::Types3d::TMeshData* const aData);
	
protected:
	virtual void __fastcall Render();
	
public:
	__fastcall virtual TGBEHeightmap(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEHeightmap();
	void __fastcall RebuildMesh();
	void __fastcall LoadHeightmapFromFile(System::UnicodeString FileName);
	void __fastcall LoadHeightmapFromStream(System::Classes::TStream* Stream);
	void __fastcall LoadHeightmapFromResource(System::UnicodeString ResourceName);
	float __fastcall GetHeight(const System::Math::Vectors::TPoint3D &P);
	
__published:
	__property int Flou = {read=GetFlou, write=SetFlou, nodefault};
	__property bool ShowLines = {read=GetTracerLignes, write=SetTracerLignes, nodefault};
	__property Fmx::Materialsources::TColorMaterialSource* MaterialLines = {read=fMaterialLignes, write=fMaterialLignes};
	__property float MinHeight = {read=fMinHauteur};
	__property float MaxHeight = {read=fMaxHauteur};
	__property Locked = {default=1};
	__property HitTest = {default=0};
	__property bool UseRamp = {read=FUseRamp, write=SetUseRamp, nodefault};
	__property TwoSide = {default=1};
	__property Visible = {default=1};
	__property ZWrite = {default=1};
	__property float MiseAEchelle = {read=fMiseAEchelle};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Heightmap */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_HEIGHTMAP)
using namespace Gbe::Heightmap;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_HeightmapHPP
