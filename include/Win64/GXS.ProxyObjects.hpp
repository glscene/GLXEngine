// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ProxyObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_ProxyObjectsHPP
#define GXS_ProxyObjectsHPP

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
#include <GXS.XCollection.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.Context.hpp>
#include <Stage.PipelineTransform.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Proxyobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EProxyException;
class DELPHICLASS TgxColorProxy;
class DELPHICLASS TgxMaterialProxy;
class DELPHICLASS TgxFreeFormProxy;
class DELPHICLASS TBoneMatrixObj;
class DELPHICLASS TgxActorProxy;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION EProxyException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EProxyException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EProxyException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EProxyException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EProxyException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EProxyException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EProxyException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EProxyException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EProxyException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProxyException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProxyException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProxyException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProxyException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EProxyException() { }
	
};


class PASCALIMPLEMENTATION TgxColorProxy : public Gxs::Scene::TgxProxyObject
{
	typedef Gxs::Scene::TgxProxyObject inherited;
	
private:
	Gxs::Material::TgxFaceProperties* FFrontColor;
	Gxs::Scene::TgxCustomSceneObject* __fastcall GetMasterMaterialObject();
	void __fastcall SetMasterMaterialObject(Gxs::Scene::TgxCustomSceneObject* const Value);
	void __fastcall SetFrontColor(Gxs::Material::TgxFaceProperties* AValue);
	
public:
	__fastcall virtual TgxColorProxy(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxColorProxy();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	
__published:
	__property Gxs::Material::TgxFaceProperties* FrontColor = {read=FFrontColor, write=SetFrontColor};
	__property Gxs::Scene::TgxCustomSceneObject* MasterObject = {read=GetMasterMaterialObject, write=SetMasterMaterialObject};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxColorProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxProxyObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxMaterialProxy : public Gxs::Scene::TgxProxyObject
{
	typedef Gxs::Scene::TgxProxyObject inherited;
	
private:
	System::UnicodeString FTempLibMaterialName;
	Gxs::Material::TgxLibMaterial* FMasterLibMaterial;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	Gxs::Material::TgxLibMaterialName __fastcall GetMasterLibMaterialName();
	void __fastcall SetMasterLibMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Scene::TgxCustomSceneObject* __fastcall GetMasterMaterialObject();
	void __fastcall SetMasterMaterialObject(Gxs::Scene::TgxCustomSceneObject* const Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
public:
	__fastcall virtual TgxMaterialProxy(System::Classes::TComponent* AOwner);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__fastcall virtual ~TgxMaterialProxy();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__property Gxs::Material::TgxLibMaterial* MasterLibMaterial = {read=FMasterLibMaterial, write=FMasterLibMaterial, stored=false};
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName MasterLibMaterialName = {read=GetMasterLibMaterialName, write=SetMasterLibMaterialName};
	__property Gxs::Scene::TgxCustomSceneObject* MasterObject = {read=GetMasterMaterialObject, write=SetMasterMaterialObject};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMaterialProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxProxyObject(aParentOwner) { }
	
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


class PASCALIMPLEMENTATION TgxFreeFormProxy : public Gxs::Scene::TgxProxyObject
{
	typedef Gxs::Scene::TgxProxyObject inherited;
	
private:
	Gxs::Vectorfileobjects::TgxFreeForm* __fastcall GetMasterFreeFormObject();
	void __fastcall SetMasterFreeFormObject(Gxs::Vectorfileobjects::TgxFreeForm* const Value);
	
public:
	bool __fastcall OctreeRayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	bool __fastcall OctreeSphereSweepIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, const float velocity, const float radius, const float modelscale, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property Gxs::Vectorfileobjects::TgxFreeForm* MasterObject = {read=GetMasterFreeFormObject, write=SetMasterFreeFormObject};
public:
	/* TgxProxyObject.Create */ inline __fastcall virtual TgxFreeFormProxy(System::Classes::TComponent* AOwner) : Gxs::Scene::TgxProxyObject(AOwner) { }
	/* TgxProxyObject.Destroy */ inline __fastcall virtual ~TgxFreeFormProxy() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFreeFormProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxProxyObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TBoneMatrixObj : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Stage::Vectortypes::TMatrix4f Matrix;
	System::UnicodeString BoneName;
	int BoneIndex;
public:
	/* TObject.Create */ inline __fastcall TBoneMatrixObj() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBoneMatrixObj() { }
	
};


enum DECLSPEC_DENUM TgxActorProxyAnimationMode : unsigned char { pamInherited, pamNone, pamPlayOnce };

class PASCALIMPLEMENTATION TgxActorProxy : public Gxs::Scene::TgxProxyObject
{
	typedef Gxs::Scene::TgxProxyObject inherited;
	
private:
	int FCurrentFrame;
	int FStartFrame;
	int FEndFrame;
	int FLastFrame;
	float FCurrentFrameDelta;
	Gxs::Baseclasses::TgxProgressTimes FCurrentTime;
	Gxs::Vectorfileobjects::TgxActorAnimationName FAnimation;
	System::UnicodeString FTempLibMaterialName;
	Gxs::Material::TgxLibMaterial* FMasterLibMaterial;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	System::Classes::TStringList* FBonesMatrices;
	bool FStoreBonesMatrix;
	System::Classes::TStrings* FStoredBoneNames;
	Gxs::Baseclasses::TgxProgressEvent FOnBeforeRender;
	TgxActorProxyAnimationMode FAnimationMode;
	void __fastcall SetAnimation(const Gxs::Vectorfileobjects::TgxActorAnimationName Value);
	void __fastcall SetMasterActorObject(Gxs::Vectorfileobjects::TgxActor* const Value);
	Gxs::Vectorfileobjects::TgxActor* __fastcall GetMasterActorObject();
	Gxs::Material::TgxLibMaterialName __fastcall GetLibMaterialName();
	void __fastcall SetLibMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetStoreBonesMatrix(const bool Value);
	void __fastcall SetStoredBoneNames(System::Classes::TStrings* const Value);
	void __fastcall SetOnBeforeRender(const Gxs::Baseclasses::TgxProgressEvent Value);
	
protected:
	void __fastcall DoStoreBonesMatrices();
	
public:
	__fastcall virtual TgxActorProxy(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxActorProxy();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__property int CurrentFrame = {read=FCurrentFrame, nodefault};
	__property int StartFrame = {read=FStartFrame, nodefault};
	__property int EndFrame = {read=FEndFrame, nodefault};
	__property float CurrentFrameDelta = {read=FCurrentFrameDelta};
	__property Gxs::Baseclasses::TgxProgressTimes CurrentTime = {read=FCurrentTime};
	Stage::Vectortypes::TMatrix4f __fastcall BoneMatrix(int BoneIndex)/* overload */;
	Stage::Vectortypes::TMatrix4f __fastcall BoneMatrix(System::UnicodeString BoneName)/* overload */;
	void __fastcall BoneMatricesClear();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	bool __fastcall RayCastIntersectEx(Gxs::Vectorfileobjects::TgxActor* RefActor, const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0))/* overload */;
	
__published:
	__property TgxActorProxyAnimationMode AnimationMode = {read=FAnimationMode, write=FAnimationMode, default=0};
	__property Gxs::Vectorfileobjects::TgxActorAnimationName Animation = {read=FAnimation, write=SetAnimation};
	__property Gxs::Vectorfileobjects::TgxActor* MasterObject = {read=GetMasterActorObject, write=SetMasterActorObject};
	__property ProxyOptions = {default=3};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName LibMaterialName = {read=GetLibMaterialName, write=SetLibMaterialName};
	__property bool StoreBonesMatrix = {read=FStoreBonesMatrix, write=SetStoreBonesMatrix, nodefault};
	__property System::Classes::TStrings* StoredBoneNames = {read=FStoredBoneNames, write=SetStoredBoneNames};
	__property Gxs::Baseclasses::TgxProgressEvent OnBeforeRender = {read=FOnBeforeRender, write=SetOnBeforeRender};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxActorProxy(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxProxyObject(aParentOwner) { }
	
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


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Proxyobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PROXYOBJECTS)
using namespace Gxs::Proxyobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ProxyObjectsHPP
