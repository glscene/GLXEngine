// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.EParticleMasksManager.pas' rev: 36.00 (Windows)

#ifndef GXS_EParticleMasksManagerHPP
#define GXS_EParticleMasksManagerHPP

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
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <GXS.Color.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.ParticleFX.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Eparticlemasksmanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxEParticleMask;
class DELPHICLASS TgxEParticleMasks;
class DELPHICLASS TgxEParticleMasksManager;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxEProjectedParticleMask : unsigned char { pptXMask, pptYMask, pptZMask };

class PASCALIMPLEMENTATION TgxEParticleMask : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	Gxs::Coordinates::TgxCoordinates* FScale;
	Gxs::Coordinates::TgxCoordinates* FPosition;
	Gxs::Material::TgxLibMaterialName FYMask;
	Gxs::Material::TgxLibMaterialName FZMask;
	Gxs::Material::TgxLibMaterialName FXMask;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	System::Uitypes::TColor FBackgroundColor;
	System::Uitypes::TColor FMaskColor;
	int FMaxX;
	int FMaxY;
	int FMaxZ;
	int FMinX;
	int FMinY;
	int FMinZ;
	int IXW;
	int IXH;
	int IYW;
	int IYH;
	int IZW;
	int IZH;
	int LX;
	int LY;
	int LZ;
	int MX;
	int MY;
	bool BogusMask;
	bool BogusMaskX;
	bool BogusMaskY;
	bool BogusMaskZ;
	float FRollAngle;
	float FPitchAngle;
	float FTurnAngle;
	void __fastcall SetName(const System::UnicodeString Value);
	void __fastcall SetXMask(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetYMask(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetZMask(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	Fmx::Graphics::TBitmap* __fastcall XCan();
	Fmx::Graphics::TBitmap* __fastcall YCan();
	Fmx::Graphics::TBitmap* __fastcall ZCan();
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxEParticleMask(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxEParticleMask();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall UpdateExtents();
	void __fastcall Roll(float Angle);
	void __fastcall Turn(float Angle);
	void __fastcall Pitch(float Angle);
	void __fastcall GenerateMaskFromProjection(TgxEProjectedParticleMask FromMask, TgxEProjectedParticleMask ToMask, int Depth);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Scale = {read=FScale, write=FScale};
	__property Gxs::Coordinates::TgxCoordinates* Position = {read=FPosition, write=FPosition};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName XMask = {read=FXMask, write=SetXMask};
	__property Gxs::Material::TgxLibMaterialName YMask = {read=FYMask, write=SetYMask};
	__property Gxs::Material::TgxLibMaterialName ZMask = {read=FZMask, write=SetZMask};
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=FBackgroundColor, nodefault};
	__property System::Uitypes::TColor MaskColor = {read=FMaskColor, write=FMaskColor, nodefault};
	__property float RollAngle = {read=FRollAngle, write=FRollAngle};
	__property float PitchAngle = {read=FPitchAngle, write=FPitchAngle};
	__property float TurnAngle = {read=FTurnAngle, write=FTurnAngle};
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


class PASCALIMPLEMENTATION TgxEParticleMasks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxEParticleMask* operator[](int Index) { return this->Items[Index]; }
	
protected:
	System::Classes::TComponent* Owner;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int Index, TgxEParticleMask* const Val);
	TgxEParticleMask* __fastcall GetItems(int Index);
	
public:
	HIDESBASE TgxEParticleMask* __fastcall Add();
	__fastcall TgxEParticleMasks(System::Classes::TComponent* AOwner);
	__property TgxEParticleMask* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxEParticleMasks() { }
	
};


class PASCALIMPLEMENTATION TgxEParticleMasksManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxEParticleMasks* FParticleMasks;
	
protected:
	void __fastcall ApplyOrthoGraphic(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask);
	void __fastcall ApplyRotation(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask);
	void __fastcall ApplyRotationTarget(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask, Gxs::Scene::TgxBaseSceneObject* TargetObject);
	void __fastcall ApplyScaleAndPosition(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask);
	void __fastcall ApplyScaleAndPositionTarget(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask, Gxs::Scene::TgxBaseSceneObject* TargetObject);
	void __fastcall FindParticlePosition(Stage::Vectortypes::TVector3f &Vec, TgxEParticleMask* Mask);
	
public:
	__fastcall virtual TgxEParticleMasksManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxEParticleMasksManager();
	Stage::Vectortypes::TVector3f __fastcall CreateParticlePositionFromMask(System::UnicodeString MaskName);
	Stage::Vectortypes::TVector3f __fastcall TargetParticlePositionFromMask(Gxs::Scene::TgxBaseSceneObject* TargetObject, System::UnicodeString MaskName);
	void __fastcall SetParticlePositionFromMask(Gxs::Particlefx::TgxParticle* Particle, System::UnicodeString MaskName);
	void __fastcall SetParticlePositionFromMaskTarget(Gxs::Particlefx::TgxParticle* Particle, System::UnicodeString MaskName, Gxs::Scene::TgxBaseSceneObject* TargetObject);
	TgxEParticleMask* __fastcall ParticleMaskByName(System::UnicodeString MaskName);
	
__published:
	__property TgxEParticleMasks* ParticleMasks = {read=FParticleMasks, write=FParticleMasks};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Eparticlemasksmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_EPARTICLEMASKSMANAGER)
using namespace Gxs::Eparticlemasksmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_EParticleMasksManagerHPP
