// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Skydome.pas' rev: 36.00 (Windows)

#ifndef GXS_SkydomeHPP
#define GXS_SkydomeHPP

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
#include <System.UITypes.hpp>
#include <System.Math.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Color.hpp>
#include <GXS.Material.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Skydome
{
//-- forward type declarations -----------------------------------------------
struct TgxStarRecord;
class DELPHICLASS TgxSkyBox;
class DELPHICLASS TgxSkyDomeBand;
class DELPHICLASS TgxSkyDomeBands;
class DELPHICLASS TgxSkyDomeStar;
class DELPHICLASS TgxSkyDomeStars;
class DELPHICLASS TgxSkyDome;
class DELPHICLASS TgxEarthSkyDome;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxStarRecord
{
public:
	System::Word RA;
	short DEC;
	System::Byte BVColorIndex;
	System::Byte VMagnitude;
};
#pragma pack(pop)


typedef TgxStarRecord *PgxStarRecord;

enum DECLSPEC_DENUM TgxSkyBoxStyle : unsigned char { sbsFull, sbsTopHalf, sbsBottomHalf, sbTopTwoThirds, sbsTopHalfClamped };

class PASCALIMPLEMENTATION TgxSkyBox : public Gxs::Scene::TgxCameraInvariantObject
{
	typedef Gxs::Scene::TgxCameraInvariantObject inherited;
	
private:
	System::UnicodeString FMatNameTop;
	System::UnicodeString FMatNameRight;
	System::UnicodeString FMatNameFront;
	System::UnicodeString FMatNameLeft;
	System::UnicodeString FMatNameBack;
	System::UnicodeString FMatNameBottom;
	System::UnicodeString FMatNameClouds;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	float FCloudsPlaneOffset;
	float FCloudsPlaneSize;
	TgxSkyBoxStyle FStyle;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetMatNameBack(const System::UnicodeString Value);
	void __fastcall SetMatNameBottom(const System::UnicodeString Value);
	void __fastcall SetMatNameFront(const System::UnicodeString Value);
	void __fastcall SetMatNameLeft(const System::UnicodeString Value);
	void __fastcall SetMatNameRight(const System::UnicodeString Value);
	void __fastcall SetMatNameTop(const System::UnicodeString Value);
	void __fastcall SetMatNameClouds(const System::UnicodeString Value);
	void __fastcall SetCloudsPlaneOffset(const float Value);
	void __fastcall SetCloudsPlaneSize(const float Value);
	void __fastcall SetStyle(const TgxSkyBoxStyle value);
	
public:
	__fastcall virtual TgxSkyBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSkyBox();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName MatNameTop = {read=FMatNameTop, write=SetMatNameTop};
	__property Gxs::Material::TgxLibMaterialName MatNameBottom = {read=FMatNameBottom, write=SetMatNameBottom};
	__property Gxs::Material::TgxLibMaterialName MatNameLeft = {read=FMatNameLeft, write=SetMatNameLeft};
	__property Gxs::Material::TgxLibMaterialName MatNameRight = {read=FMatNameRight, write=SetMatNameRight};
	__property Gxs::Material::TgxLibMaterialName MatNameFront = {read=FMatNameFront, write=SetMatNameFront};
	__property Gxs::Material::TgxLibMaterialName MatNameBack = {read=FMatNameBack, write=SetMatNameBack};
	__property Gxs::Material::TgxLibMaterialName MatNameClouds = {read=FMatNameClouds, write=SetMatNameClouds};
	__property float CloudsPlaneOffset = {read=FCloudsPlaneOffset, write=SetCloudsPlaneOffset};
	__property float CloudsPlaneSize = {read=FCloudsPlaneSize, write=SetCloudsPlaneSize};
	__property TgxSkyBoxStyle Style = {read=FStyle, write=FStyle, default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSkyBox(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxCameraInvariantObject(aParentOwner) { }
	
private:
	void *__IgxMaterialLibrarySupported;	// Gxs::Material::IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gxs::Material::_di_IgxMaterialLibrarySupported()
	{
		Gxs::Material::_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Material::IgxMaterialLibrarySupported*(void) { return (Gxs::Material::IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxSkyDomeBand : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	float FStartAngle;
	float FStopAngle;
	Gxs::Color::TgxColor* FStartColor;
	Gxs::Color::TgxColor* FStopColor;
	int FSlices;
	int FStacks;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetStartAngle(const float val);
	void __fastcall SetStartColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetStopAngle(const float val);
	void __fastcall SetStopColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetSlices(const int val);
	void __fastcall SetStacks(const int val);
	void __fastcall OnColorChange(System::TObject* sender);
	
public:
	__fastcall virtual TgxSkyDomeBand(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxSkyDomeBand();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property float StartAngle = {read=FStartAngle, write=SetStartAngle};
	__property Gxs::Color::TgxColor* StartColor = {read=FStartColor, write=SetStartColor};
	__property float StopAngle = {read=FStopAngle, write=SetStopAngle};
	__property Gxs::Color::TgxColor* StopColor = {read=FStopColor, write=SetStopColor};
	__property int Slices = {read=FSlices, write=SetSlices, default=12};
	__property int Stacks = {read=FStacks, write=SetStacks, default=1};
};


class PASCALIMPLEMENTATION TgxSkyDomeBands : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxSkyDomeBand* operator[](int index) { return this->Items[index]; }
	
protected:
	System::Classes::TComponent* owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxSkyDomeBand* const val);
	TgxSkyDomeBand* __fastcall GetItems(int index);
	
public:
	__fastcall TgxSkyDomeBands(System::Classes::TComponent* AOwner);
	HIDESBASE TgxSkyDomeBand* __fastcall Add();
	HIDESBASE TgxSkyDomeBand* __fastcall FindItemID(int ID);
	__property TgxSkyDomeBand* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall NotifyChange();
	void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxSkyDomeBands() { }
	
};


class PASCALIMPLEMENTATION TgxSkyDomeStar : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	float FRA;
	float FDec;
	float FMagnitude;
	System::Uitypes::TColor FColor;
	Stage::Vectorgeometry::TAffineVector FCacheCoord;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxSkyDomeStar(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxSkyDomeStar();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float RA = {read=FRA, write=FRA};
	__property float DEC = {read=FDec, write=FDec};
	__property float Magnitude = {read=FMagnitude, write=FMagnitude};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, nodefault};
};


class PASCALIMPLEMENTATION TgxSkyDomeStars : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxSkyDomeStar* operator[](int index) { return this->Items[index]; }
	
protected:
	System::Classes::TComponent* owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int index, TgxSkyDomeStar* const val);
	TgxSkyDomeStar* __fastcall GetItems(int index);
	void __fastcall PrecomputeCartesianCoordinates();
	
public:
	__fastcall TgxSkyDomeStars(System::Classes::TComponent* AOwner);
	HIDESBASE TgxSkyDomeStar* __fastcall Add();
	HIDESBASE TgxSkyDomeStar* __fastcall FindItemID(int ID);
	__property TgxSkyDomeStar* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool twinkle);
	void __fastcall AddRandomStars(const int nb, const System::Uitypes::TColor Color, const bool limitToTopDome = false)/* overload */;
	void __fastcall AddRandomStars(const int nb, const Stage::Vectortypes::TVector3b ColorMin, const Stage::Vectortypes::TVector3b ColorMax, const float Magnitude_min, const float Magnitude_max, const bool limitToTopDome = false)/* overload */;
	void __fastcall LoadStarsFile(const System::UnicodeString starsFileName);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxSkyDomeStars() { }
	
};


enum DECLSPEC_DENUM TgxSkyDomeOption : unsigned char { sdoEquatorialGrid, sdoEclipticGrid, sdoGalacticGrid, sdoSupergalacticGrid, sdoTwinkle };

typedef System::Set<TgxSkyDomeOption, TgxSkyDomeOption::sdoEquatorialGrid, TgxSkyDomeOption::sdoTwinkle> TgxSkyDomeOptions;

class PASCALIMPLEMENTATION TgxSkyDome : public Gxs::Scene::TgxCameraInvariantObject
{
	typedef Gxs::Scene::TgxCameraInvariantObject inherited;
	
private:
	TgxSkyDomeOptions FOptions;
	TgxSkyDomeBands* FBands;
	TgxSkyDomeStars* FStars;
	
protected:
	void __fastcall SetBands(TgxSkyDomeBands* const val);
	void __fastcall SetStars(TgxSkyDomeStars* const val);
	void __fastcall SetOptions(const TgxSkyDomeOptions val);
	
public:
	__fastcall virtual TgxSkyDome(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSkyDome();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TgxSkyDomeBands* Bands = {read=FBands, write=SetBands};
	__property TgxSkyDomeStars* Stars = {read=FStars, write=SetStars};
	__property TgxSkyDomeOptions Options = {read=FOptions, write=SetOptions, default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSkyDome(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxCameraInvariantObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TEarthSkydomeOption : unsigned char { esoFadeStarsWithSun, esoRotateOnTwelveHours, esoDepthTest };

typedef System::Set<TEarthSkydomeOption, TEarthSkydomeOption::esoFadeStarsWithSun, TEarthSkydomeOption::esoDepthTest> TEarthSkydomeOptions;

class PASCALIMPLEMENTATION TgxEarthSkyDome : public TgxSkyDome
{
	typedef TgxSkyDome inherited;
	
private:
	float FSunElevation;
	float FTurbidity;
	Gxs::Color::TgxColorVector FCurSunColor;
	Gxs::Color::TgxColorVector FCurSkyColor;
	Gxs::Color::TgxColorVector FCurHazeColor;
	float FCurHazeTurbid;
	float FCurSunSkyTurbid;
	Gxs::Color::TgxColor* FSunZenithColor;
	Gxs::Color::TgxColor* FSunDawnColor;
	Gxs::Color::TgxColor* FHazeColor;
	Gxs::Color::TgxColor* FSkyColor;
	Gxs::Color::TgxColor* FNightColor;
	Gxs::Color::TgxColor* FDeepColor;
	int FSlices;
	int FStacks;
	TEarthSkydomeOptions FExtendedOptions;
	bool FMorning;
	
protected:
	virtual void __fastcall Loaded();
	void __fastcall SetSunElevation(const float val);
	void __fastcall SetTurbidity(const float val);
	void __fastcall SetSunZenithColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetSunDawnColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetHazeColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetSkyColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetNightColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetDeepColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetSlices(const int val);
	void __fastcall SetStacks(const int val);
	void __fastcall OnColorChanged(System::TObject* sender);
	void __fastcall PreCalculate();
	void __fastcall RenderDome();
	Gxs::Color::TgxColorVector __fastcall CalculateColor(const float theta, const float cosGamma);
	
public:
	__fastcall virtual TgxEarthSkyDome(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxEarthSkyDome();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall SetSunAtTime(float HH, float MM);
	
__published:
	__property float SunElevation = {read=FSunElevation, write=SetSunElevation};
	__property float Turbidity = {read=FTurbidity, write=SetTurbidity};
	__property Gxs::Color::TgxColor* SunZenithColor = {read=FSunZenithColor, write=SetSunZenithColor};
	__property Gxs::Color::TgxColor* SunDawnColor = {read=FSunDawnColor, write=SetSunDawnColor};
	__property Gxs::Color::TgxColor* HazeColor = {read=FHazeColor, write=SetHazeColor};
	__property Gxs::Color::TgxColor* SkyColor = {read=FSkyColor, write=SetSkyColor};
	__property Gxs::Color::TgxColor* NightColor = {read=FNightColor, write=SetNightColor};
	__property Gxs::Color::TgxColor* DeepColor = {read=FDeepColor, write=SetDeepColor};
	__property TEarthSkydomeOptions ExtendedOptions = {read=FExtendedOptions, write=FExtendedOptions, nodefault};
	__property int Slices = {read=FSlices, write=SetSlices, default=24};
	__property int Stacks = {read=FStacks, write=SetStacks, default=48};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxEarthSkyDome(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxSkyDome(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall StarRecordPositionYUp(const TgxStarRecord &starRecord);
extern DELPHI_PACKAGE Stage::Vectorgeometry::TAffineVector __fastcall StarRecordPositionZUp(const TgxStarRecord &starRecord);
extern DELPHI_PACKAGE Stage::Vectortypes::TVector4f __fastcall StarRecordColor(const TgxStarRecord &starRecord, float bias);
}	/* namespace Skydome */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SKYDOME)
using namespace Gxs::Skydome;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SkydomeHPP
