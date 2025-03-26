// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.CubeExtend.pas' rev: 36.00 (Windows)

#ifndef GBE_CubeExtendHPP
#define GBE_CubeExtendHPP

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
#include <FMX.MaterialSources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Cubeextend
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGBECubeExtend;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGBECubeExtend : public Fmx::Objects3d::TDummy
{
	typedef Fmx::Objects3d::TDummy inherited;
	
private:
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceFront;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceRight;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceBack;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceLeft;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceTop;
	Fmx::Materialsources::TMaterialSource* FMaterialSourceFaceBottom;
	int fSubdivisionsWidth;
	int fSubdivisionsHeight;
	int fSubdivisionsDepth;
	Fmx::Objects3d::TPlane* fFaceFront;
	Fmx::Objects3d::TPlane* fFaceRight;
	Fmx::Objects3d::TPlane* fFaceBack;
	Fmx::Objects3d::TPlane* fFaceLeft;
	Fmx::Objects3d::TPlane* fFaceTop;
	Fmx::Objects3d::TPlane* fFaceBottom;
	bool fFaceFrontVisible;
	bool fFaceRightVisible;
	bool fFaceBackVisible;
	bool fFaceLeftVisible;
	bool fFaceTopVisible;
	bool fFaceBottomVisible;
	float fWidth;
	float fDepth;
	float fHeight;
	void __fastcall SetMaterialSourceFaceFront(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceFaceBack(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceFaceBottom(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceFaceLeft(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceFaceRight(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetMaterialSourceFaceTop(Fmx::Materialsources::TMaterialSource* const Value);
	void __fastcall SetSubdivisionsDepth(const int Value);
	void __fastcall SetSubdivisionsHeight(const int Value);
	void __fastcall SetSubdivisionsWidth(const int Value);
	void __fastcall SetFaceFrontVisible(const bool Value);
	void __fastcall SetFaceRightVisible(const bool Value);
	void __fastcall SetFaceBackVisible(const bool Value);
	void __fastcall SetFaceLeftVisible(const bool Value);
	void __fastcall SetFaceTopVisible(const bool Value);
	void __fastcall SetFaceBottomVisible(const bool Value);
	void __fastcall DrawCube();
	HIDESBASE void __fastcall SetDepth(const float Value);
	HIDESBASE void __fastcall SetHeight(const float Value);
	HIDESBASE void __fastcall SetWidth(const float Value);
	
public:
	__fastcall virtual TGBECubeExtend(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBECubeExtend();
	
__published:
	__property int SubdivisionsDepth = {read=fSubdivisionsDepth, write=SetSubdivisionsDepth, nodefault};
	__property int SubdivisionsHeight = {read=fSubdivisionsHeight, write=SetSubdivisionsHeight, nodefault};
	__property int SubdivisionsWidth = {read=fSubdivisionsWidth, write=SetSubdivisionsWidth, nodefault};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceFront = {read=FMaterialSourceFaceFront, write=SetMaterialSourceFaceFront};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceRight = {read=FMaterialSourceFaceRight, write=SetMaterialSourceFaceRight};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceBack = {read=FMaterialSourceFaceBack, write=SetMaterialSourceFaceBack};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceLeft = {read=FMaterialSourceFaceLeft, write=SetMaterialSourceFaceLeft};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceTop = {read=FMaterialSourceFaceTop, write=SetMaterialSourceFaceTop};
	__property Fmx::Materialsources::TMaterialSource* MaterialSourceFaceBottom = {read=FMaterialSourceFaceBottom, write=SetMaterialSourceFaceBottom};
	__property float Width = {read=fWidth, write=SetWidth};
	__property float Height = {read=fHeight, write=SetHeight};
	__property float Depth = {read=fDepth, write=SetDepth};
	__property bool FaceFrontVisible = {read=fFaceFrontVisible, write=SetFaceFrontVisible, nodefault};
	__property bool FaceRightVisible = {read=fFaceRightVisible, write=SetFaceRightVisible, nodefault};
	__property bool FaceBackVisible = {read=fFaceBackVisible, write=SetFaceBackVisible, nodefault};
	__property bool FaceLeftVisible = {read=fFaceLeftVisible, write=SetFaceLeftVisible, nodefault};
	__property bool FaceTopVisible = {read=fFaceTopVisible, write=SetFaceTopVisible, nodefault};
	__property bool FaceBottomVisible = {read=fFaceBottomVisible, write=SetFaceBottomVisible, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Cubeextend */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_CUBEEXTEND)
using namespace Gbe::Cubeextend;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_CubeExtendHPP
