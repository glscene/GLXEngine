// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Atmosphere.pas' rev: 36.00 (Windows)

#ifndef GXS_AtmosphereHPP
#define GXS_AtmosphereHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Cadencer.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Atmosphere
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLAtmosphereException;
class DELPHICLASS TgxCustomAtmosphere;
class DELPHICLASS TgxAtmosphere;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION EGLAtmosphereException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLAtmosphereException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLAtmosphereException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLAtmosphereException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLAtmosphereException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLAtmosphereException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLAtmosphereException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLAtmosphereException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLAtmosphereException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLAtmosphereException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLAtmosphereException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLAtmosphereException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLAtmosphereException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLAtmosphereException() { }
	
};


enum DECLSPEC_DENUM TgxAtmosphereBlendingMode : unsigned char { abmOneMinusDstColor, abmOneMinusSrcAlpha };

class PASCALIMPLEMENTATION TgxCustomAtmosphere : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<float> _TgxCustomAtmosphere__1;
	
	
private:
	_TgxCustomAtmosphere__1 cosCache;
	_TgxCustomAtmosphere__1 sinCache;
	Stage::Vectorgeometry::PVectorArray pVertex;
	Stage::Vectorgeometry::PVectorArray pColor;
	int FSlices;
	TgxAtmosphereBlendingMode FBlendingMode;
	float FPlanetRadius;
	float FAtmosphereRadius;
	float FOpacity;
	Gxs::Color::TgxColor* FLowAtmColor;
	Gxs::Color::TgxColor* FHighAtmColor;
	Gxs::Scene::TgxBaseSceneObject* FSun;
	void __fastcall SetSun(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetAtmosphereRadius(const float Value);
	void __fastcall SetPlanetRadius(const float Value);
	void __fastcall EnableGLBlendingMode(Gxs::State::TgxStateCache* StateCache);
	bool __fastcall StoreAtmosphereRadius();
	bool __fastcall StoreOpacity();
	bool __fastcall StorePlanetRadius();
	void __fastcall SetSlices(const int Value);
	void __fastcall SetLowAtmColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetHighAtmColor(Gxs::Color::TgxColor* const AValue);
	bool __fastcall StoreLowAtmColor();
	bool __fastcall StoreHighAtmColor();
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__property Gxs::Scene::TgxBaseSceneObject* Sun = {read=FSun, write=SetSun};
	__property int Slices = {read=FSlices, write=SetSlices, default=60};
	__property float Opacity = {read=FOpacity, write=FOpacity, stored=StoreOpacity};
	__property float AtmosphereRadius = {read=FAtmosphereRadius, write=SetAtmosphereRadius, stored=StoreAtmosphereRadius};
	__property float PlanetRadius = {read=FPlanetRadius, write=SetPlanetRadius, stored=StorePlanetRadius};
	__property Gxs::Color::TgxColor* LowAtmColor = {read=FLowAtmColor, write=SetLowAtmColor, stored=StoreLowAtmColor};
	__property Gxs::Color::TgxColor* HighAtmColor = {read=FHighAtmColor, write=SetHighAtmColor, stored=StoreHighAtmColor};
	__property TgxAtmosphereBlendingMode BlendingMode = {read=FBlendingMode, write=FBlendingMode, default=1};
	void __fastcall SetOptimalAtmosphere(const float ARadius);
	void __fastcall SetOptimalAtmosphere2(const float ARadius);
	void __fastcall TogleBlendingMode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__fastcall virtual TgxCustomAtmosphere(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomAtmosphere();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCustomAtmosphere(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxAtmosphere : public TgxCustomAtmosphere
{
	typedef TgxCustomAtmosphere inherited;
	
__published:
	__property Sun;
	__property Slices = {default=60};
	__property Opacity = {default=0};
	__property AtmosphereRadius = {default=0};
	__property PlanetRadius = {default=0};
	__property LowAtmColor;
	__property HighAtmColor;
	__property BlendingMode = {default=1};
	__property Position;
	__property ObjectsSorting = {default=0};
	__property ShowAxes = {default=0};
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
public:
	/* TgxCustomAtmosphere.Create */ inline __fastcall virtual TgxAtmosphere(System::Classes::TComponent* AOwner) : TgxCustomAtmosphere(AOwner) { }
	/* TgxCustomAtmosphere.Destroy */ inline __fastcall virtual ~TgxAtmosphere() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxAtmosphere(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCustomAtmosphere(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Atmosphere */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ATMOSPHERE)
using namespace Gxs::Atmosphere;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_AtmosphereHPP
