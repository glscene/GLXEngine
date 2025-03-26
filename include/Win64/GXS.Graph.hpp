// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Graph.pas' rev: 36.00 (Windows)

#ifndef GXS_GraphHPP
#define GXS_GraphHPP

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
#include <Stage.OpenGL4.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Material.hpp>
#include <GXS.Objects.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Color.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Graph
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSamplingScale;
class DELPHICLASS TgxHeightField;
class DELPHICLASS TgxXYZGrid;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxSamplingScale : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	float FMin;
	float FMax;
	float FOrigin;
	float FStep;
	
protected:
	void __fastcall SetMin(const float val);
	void __fastcall SetMax(const float val);
	void __fastcall SetOrigin(const float val);
	void __fastcall SetStep(const float val);
	
public:
	__fastcall virtual TgxSamplingScale(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxSamplingScale();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	float __fastcall StepBase();
	int __fastcall MaxStepCount();
	bool __fastcall IsValid();
	void __fastcall SetBaseStepMaxToVars(float &Base, float &Step, float &Max, bool SamplingEnabled = true);
	
__published:
	__property float Min = {read=FMin, write=SetMin};
	__property float Max = {read=FMax, write=SetMax};
	__property float Origin = {read=FOrigin, write=SetOrigin};
	__property float Step = {read=FStep, write=SetStep};
};


typedef void __fastcall (__closure *TgxHeightFieldGetHeightEvent)(const float x, const float y, float &z, Gxs::Color::TgxColorVector &Color, Stage::Vectorgeometry::TTexPoint &TexPoint);

typedef void __fastcall (__closure *TgxHeightFieldGetHeight2Event)(System::TObject* Sender, const float x, const float y, float &z, Gxs::Color::TgxColorVector &Color, Stage::Vectorgeometry::TTexPoint &TexPoint);

enum DECLSPEC_DENUM TgxHeightFieldOption : unsigned char { hfoTextureCoordinates, hfoTwoSided };

typedef System::Set<TgxHeightFieldOption, TgxHeightFieldOption::hfoTextureCoordinates, TgxHeightFieldOption::hfoTwoSided> TgxHeightFieldOptions;

enum DECLSPEC_DENUM TgxHeightFieldColorMode : unsigned char { hfcmNone, hfcmEmission, hfcmAmbient, hfcmDiffuse, hfcmAmbientAndDiffuse };

class PASCALIMPLEMENTATION TgxHeightField : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxHeightFieldGetHeightEvent FOnGetHeight;
	TgxHeightFieldGetHeight2Event FOnGetHeight2;
	TgxSamplingScale* FXSamplingScale;
	TgxSamplingScale* FYSamplingScale;
	TgxHeightFieldOptions FOptions;
	int FTriangleCount;
	TgxHeightFieldColorMode FColorMode;
	
protected:
	void __fastcall SetXSamplingScale(TgxSamplingScale* const val);
	void __fastcall SetYSamplingScale(TgxSamplingScale* const val);
	void __fastcall SetOptions(const TgxHeightFieldOptions val);
	void __fastcall SetOnGetHeight(const TgxHeightFieldGetHeightEvent val);
	void __fastcall SetOnGetHeight2(const TgxHeightFieldGetHeight2Event val);
	void __fastcall SetColorMode(const TgxHeightFieldColorMode val);
	void __fastcall DefaultHeightField(const float x, const float y, float &z, Gxs::Color::TgxColorVector &Color, Stage::Vectorgeometry::TTexPoint &TexPoint);
	void __fastcall Height2Field(const float x, const float y, float &z, Gxs::Color::TgxColorVector &Color, Stage::Vectorgeometry::TTexPoint &texPoint);
	
public:
	__fastcall virtual TgxHeightField(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHeightField();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	__property int TriangleCount = {read=FTriangleCount, nodefault};
	
__published:
	__property TgxSamplingScale* XSamplingScale = {read=FXSamplingScale, write=SetXSamplingScale};
	__property TgxSamplingScale* YSamplingScale = {read=FYSamplingScale, write=SetYSamplingScale};
	__property TgxHeightFieldColorMode ColorMode = {read=FColorMode, write=SetColorMode, default=0};
	__property TgxHeightFieldOptions Options = {read=FOptions, write=SetOptions, default=2};
	__property TgxHeightFieldGetHeightEvent OnGetHeight = {read=FOnGetHeight, write=SetOnGetHeight};
	__property TgxHeightFieldGetHeight2Event OnGetHeight2 = {read=FOnGetHeight2, write=SetOnGetHeight2};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxHeightField(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TXYZGridPart : unsigned char { gpX, gpY, gpZ };

typedef System::Set<TXYZGridPart, TXYZGridPart::gpX, TXYZGridPart::gpZ> TXYZGridParts;

enum DECLSPEC_DENUM TXYZGridLinesStyle : unsigned char { strLine, glsSegments };

class PASCALIMPLEMENTATION TgxXYZGrid : public Gxs::Objects::TgxLineBase
{
	typedef Gxs::Objects::TgxLineBase inherited;
	
private:
	TgxSamplingScale* FXSamplingScale;
	TgxSamplingScale* FYSamplingScale;
	TgxSamplingScale* FZSamplingScale;
	TXYZGridParts FParts;
	TXYZGridLinesStyle FLinesStyle;
	
protected:
	void __fastcall SetXSamplingScale(TgxSamplingScale* const val);
	void __fastcall SetYSamplingScale(TgxSamplingScale* const val);
	void __fastcall SetZSamplingScale(TgxSamplingScale* const val);
	void __fastcall SetParts(const TXYZGridParts val);
	void __fastcall SetLinesStyle(const TXYZGridLinesStyle val);
	void __fastcall SetLinesSmoothing(const bool val);
	
public:
	__fastcall virtual TgxXYZGrid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxXYZGrid();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property TgxSamplingScale* XSamplingScale = {read=FXSamplingScale, write=SetXSamplingScale};
	__property TgxSamplingScale* YSamplingScale = {read=FYSamplingScale, write=SetYSamplingScale};
	__property TgxSamplingScale* ZSamplingScale = {read=FZSamplingScale, write=SetZSamplingScale};
	__property TXYZGridParts Parts = {read=FParts, write=SetParts, default=3};
	__property TXYZGridLinesStyle LinesStyle = {read=FLinesStyle, write=SetLinesStyle, default=1};
	__property bool LinesSmoothing = {write=SetLinesSmoothing, stored=false, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxXYZGrid(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxLineBase(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Graph */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GRAPH)
using namespace Gxs::Graph;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GraphHPP
