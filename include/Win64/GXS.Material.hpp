// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Material.pas' rev: 36.00 (Windows)

#ifndef GXS_MaterialHPP
#define GXS_MaterialHPP

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
#include <Winapi.OpenGLext.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Graphics.hpp>
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.Strings.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.Utils.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.Texture.hpp>
#include <GXS.State.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Material
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IgxMaterialLibrarySupported;
typedef System::DelphiInterface<IgxMaterialLibrarySupported> _di_IgxMaterialLibrarySupported;
class DELPHICLASS TgxShader;
class DELPHICLASS TgxFaceProperties;
class DELPHICLASS TgxDepthProperties;
class DELPHICLASS TgxBlendingParameters;
class DELPHICLASS TgxMaterial;
class DELPHICLASS TgxAbstractLibMaterial;
class DELPHICLASS TgxLibMaterial;
class DELPHICLASS TgxAbstractLibMaterials;
class DELPHICLASS TgxLibMaterials;
class DELPHICLASS TgxAbstractMaterialLibrary;
class DELPHICLASS TgxMaterialLibrary;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{8E442AF9-D212-4A5E-8A88-92F798BABFD1}") IgxMaterialLibrarySupported  : public System::IInterface 
{
	virtual TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary() = 0 ;
};

enum DECLSPEC_DENUM TgxShaderStyle : unsigned char { ssHighLevel, ssLowLevel, ssReplace };

enum DECLSPEC_DENUM TgxShaderFailedInitAction : unsigned char { fiaSilentDisable, fiaRaiseStandardException, fiaRaiseHandledException, fiaReRaiseException };

class PASCALIMPLEMENTATION TgxShader : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	bool FEnabled;
	System::Classes::TList* FLibMatUsers;
	Gxs::Context::TgxVirtualHandle* FVirtualHandle;
	TgxShaderStyle FShaderStyle;
	int FUpdateCount;
	bool FShaderActive;
	TgxShaderFailedInitAction FFailedInitAction;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender) = 0 ;
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci) = 0 ;
	virtual void __fastcall DoFinalize();
	bool __fastcall GetShaderInitialized();
	void __fastcall InitializeShader(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	void __fastcall FinalizeShader();
	void __fastcall OnVirtualHandleAllocate(Gxs::Context::TgxVirtualHandle* Sender, unsigned &handle);
	void __fastcall OnVirtualHandleDestroy(Gxs::Context::TgxVirtualHandle* Sender, unsigned &handle);
	void __fastcall SetEnabled(bool val);
	__property bool ShaderInitialized = {read=GetShaderInitialized, nodefault};
	__property bool ShaderActive = {read=FShaderActive, nodefault};
	void __fastcall RegisterUser(TgxLibMaterial* libMat);
	void __fastcall UnRegisterUser(TgxLibMaterial* libMat);
	virtual void __fastcall HandleFailedInitialization(const System::UnicodeString LastErrorMessage = System::UnicodeString());
	virtual System::UnicodeString __fastcall GetStardardNotSupportedMessage();
	
public:
	__fastcall virtual TgxShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxShader();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	bool __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property TgxShaderStyle ShaderStyle = {read=FShaderStyle, write=FShaderStyle, default=1};
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall ShaderSupported();
	__property TgxShaderFailedInitAction FailedInitAction = {read=FFailedInitAction, write=FFailedInitAction, default=1};
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
};


_DECLARE_METACLASS(System::TMetaClass, TgxShaderClass);

typedef System::Byte TgxShininess;

class PASCALIMPLEMENTATION TgxFaceProperties : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	Gxs::Color::TgxColor* FAmbient;
	Gxs::Color::TgxColor* FDiffuse;
	Gxs::Color::TgxColor* FSpecular;
	Gxs::Color::TgxColor* FEmission;
	TgxShininess FShininess;
	
protected:
	void __fastcall SetAmbient(Gxs::Color::TgxColor* AValue);
	void __fastcall SetDiffuse(Gxs::Color::TgxColor* AValue);
	void __fastcall SetEmission(Gxs::Color::TgxColor* AValue);
	void __fastcall SetSpecular(Gxs::Color::TgxColor* AValue);
	void __fastcall SetShininess(TgxShininess AValue);
	
public:
	__fastcall virtual TgxFaceProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxFaceProperties();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::State::TgxCullFaceMode AFace);
	void __fastcall ApplyNoLighting(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::State::TgxCullFaceMode AFace);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Color::TgxColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property Gxs::Color::TgxColor* Diffuse = {read=FDiffuse, write=SetDiffuse};
	__property Gxs::Color::TgxColor* Emission = {read=FEmission, write=SetEmission};
	__property TgxShininess Shininess = {read=FShininess, write=SetShininess, default=0};
	__property Gxs::Color::TgxColor* Specular = {read=FSpecular, write=SetSpecular};
};


class PASCALIMPLEMENTATION TgxDepthProperties : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	bool FDepthTest;
	bool FDepthWrite;
	float FZNear;
	float FZFar;
	Gxs::State::TgxDepthFunction FCompareFunc;
	bool FDepthClamp;
	
protected:
	void __fastcall SetZNear(float Value);
	void __fastcall SetZFar(float Value);
	void __fastcall SetCompareFunc(Gxs::Texture::TgxDepthCompareFunc Value);
	void __fastcall SetDepthTest(bool Value);
	void __fastcall SetDepthWrite(bool Value);
	void __fastcall SetDepthClamp(bool Value);
	bool __fastcall StoreZNear();
	bool __fastcall StoreZFar();
	
public:
	__fastcall virtual TgxDepthProperties(System::Classes::TPersistent* AOwner);
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float ZNear = {read=FZNear, write=SetZNear, stored=StoreZNear};
	__property float ZFar = {read=FZFar, write=SetZFar, stored=StoreZFar};
	__property Gxs::State::TgxDepthFunction DepthCompareFunction = {read=FCompareFunc, write=SetCompareFunc, default=3};
	__property bool DepthTest = {read=FDepthTest, write=SetDepthTest, default=1};
	__property bool DepthWrite = {read=FDepthWrite, write=SetDepthWrite, default=0};
	__property bool DepthClamp = {read=FDepthClamp, write=SetDepthClamp, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxDepthProperties() { }
	
};


typedef System::UnicodeString TgxLibMaterialName;

typedef Gxs::State::TgxComparisonFunction TgxAlphaFunc;

class PASCALIMPLEMENTATION TgxBlendingParameters : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	bool FUseAlphaFunc;
	bool FUseBlendFunc;
	bool FSeparateBlendFunc;
	TgxAlphaFunc FAlphaFuncType;
	float FAlphaFuncRef;
	Gxs::State::TgxBlendFunction FBlendFuncSFactor;
	Gxs::State::TgxBlendFunction FBlendFuncDFactor;
	Gxs::State::TgxBlendFunction FAlphaBlendFuncSFactor;
	Gxs::State::TgxBlendFunction FAlphaBlendFuncDFactor;
	void __fastcall SetUseAlphaFunc(const bool Value);
	void __fastcall SetUseBlendFunc(const bool Value);
	void __fastcall SetSeparateBlendFunc(const bool Value);
	void __fastcall SetAlphaFuncRef(const float Value);
	void __fastcall SetAlphaFuncType(const TgxAlphaFunc Value);
	void __fastcall SetBlendFuncDFactor(const Gxs::State::TgxBlendFunction Value);
	void __fastcall SetBlendFuncSFactor(const Gxs::State::TgxBlendFunction Value);
	void __fastcall SetAlphaBlendFuncDFactor(const Gxs::State::TgxBlendFunction Value);
	void __fastcall SetAlphaBlendFuncSFactor(const Gxs::State::TgxBlendFunction Value);
	bool __fastcall StoreAlphaFuncRef();
	
public:
	__fastcall virtual TgxBlendingParameters(System::Classes::TPersistent* AOwner);
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property bool UseAlphaFunc = {read=FUseAlphaFunc, write=SetUseAlphaFunc, default=0};
	__property TgxAlphaFunc AlphaFunctType = {read=FAlphaFuncType, write=SetAlphaFuncType, default=5};
	__property float AlphaFuncRef = {read=FAlphaFuncRef, write=SetAlphaFuncRef, stored=StoreAlphaFuncRef};
	__property bool UseBlendFunc = {read=FUseBlendFunc, write=SetUseBlendFunc, default=1};
	__property bool SeparateBlendFunc = {read=FSeparateBlendFunc, write=SetSeparateBlendFunc, default=0};
	__property Gxs::State::TgxBlendFunction BlendFuncSFactor = {read=FBlendFuncSFactor, write=SetBlendFuncSFactor, default=6};
	__property Gxs::State::TgxBlendFunction BlendFuncDFactor = {read=FBlendFuncDFactor, write=SetBlendFuncDFactor, default=7};
	__property Gxs::State::TgxBlendFunction AlphaBlendFuncSFactor = {read=FAlphaBlendFuncSFactor, write=SetAlphaBlendFuncSFactor, default=6};
	__property Gxs::State::TgxBlendFunction AlphaBlendFuncDFactor = {read=FAlphaBlendFuncDFactor, write=SetAlphaBlendFuncDFactor, default=7};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxBlendingParameters() { }
	
};


enum DECLSPEC_DENUM TgxBlendingMode : unsigned char { bmOpaque, bmTransparency, bmAdditive, bmAlphaTest50, bmAlphaTest100, bmModulate, bmCustom };

enum DECLSPEC_DENUM TgxFaceCulling : unsigned char { fcBufferDefault, fcCull, fcNoCull };

enum DECLSPEC_DENUM TgxMaterialOption : unsigned char { moIgnoreFog, moNoLighting };

typedef System::Set<TgxMaterialOption, TgxMaterialOption::moIgnoreFog, TgxMaterialOption::moNoLighting> TgxMaterialOptions;

class PASCALIMPLEMENTATION TgxMaterial : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	TgxFaceProperties* FFrontProperties;
	TgxFaceProperties* FBackProperties;
	TgxDepthProperties* FDepthProperties;
	TgxBlendingMode FBlendingMode;
	TgxBlendingParameters* FBlendingParams;
	Gxs::Texture::TgxTexture* FTexture;
	Gxs::Texture::TgxTextureEx* FTextureEx;
	TgxAbstractMaterialLibrary* FMaterialLibrary;
	TgxLibMaterialName FLibMaterialName;
	TgxMaterialOptions FMaterialOptions;
	TgxFaceCulling FFaceCulling;
	Gxs::State::TgxPolygonMode FPolygonMode;
	TgxAbstractLibMaterial* currentLibMaterial;
	TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	TgxFaceProperties* __fastcall GetBackProperties();
	void __fastcall SetBackProperties(TgxFaceProperties* Values);
	void __fastcall SetFrontProperties(TgxFaceProperties* Values);
	void __fastcall SetDepthProperties(TgxDepthProperties* Values);
	void __fastcall SetBlendingMode(const TgxBlendingMode val);
	void __fastcall SetMaterialOptions(const TgxMaterialOptions val);
	Gxs::Texture::TgxTexture* __fastcall GetTexture();
	void __fastcall SetTexture(Gxs::Texture::TgxTexture* ATexture);
	void __fastcall SetMaterialLibrary(TgxAbstractMaterialLibrary* const val);
	void __fastcall SetLibMaterialName(const TgxLibMaterialName val);
	void __fastcall SetFaceCulling(const TgxFaceCulling val);
	void __fastcall SetPolygonMode(Gxs::State::TgxPolygonMode AValue);
	Gxs::Texture::TgxTextureEx* __fastcall GetTextureEx();
	void __fastcall SetTextureEx(Gxs::Texture::TgxTextureEx* const Value);
	bool __fastcall StoreTextureEx();
	void __fastcall SetBlendingParams(TgxBlendingParameters* const Value);
	void __fastcall NotifyLibMaterialDestruction();
	bool __fastcall StoreMaterialProps();
	
public:
	__fastcall virtual TgxMaterial(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxMaterial();
	void __fastcall PrepareBuildList();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	bool __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall NotifyTexMapChange(System::TObject* Sender);
	void __fastcall DestroyHandles();
	void __fastcall Loaded();
	bool __fastcall Blended();
	bool __fastcall HasSecondaryTexture();
	bool __fastcall MaterialIsLinkedToLib();
	Gxs::Texture::TgxTexture* __fastcall GetActualPrimaryTexture();
	TgxMaterial* __fastcall GetActualPrimaryMaterial();
	TgxLibMaterial* __fastcall GetLibMaterial();
	void __fastcall QuickAssignMaterial(TgxMaterialLibrary* const MaterialLibrary, TgxLibMaterial* const Material);
	
__published:
	__property TgxFaceProperties* BackProperties = {read=GetBackProperties, write=SetBackProperties, stored=StoreMaterialProps};
	__property TgxFaceProperties* FrontProperties = {read=FFrontProperties, write=SetFrontProperties, stored=StoreMaterialProps};
	__property TgxDepthProperties* DepthProperties = {read=FDepthProperties, write=SetDepthProperties, stored=StoreMaterialProps};
	__property TgxBlendingMode BlendingMode = {read=FBlendingMode, write=SetBlendingMode, stored=StoreMaterialProps, default=0};
	__property TgxBlendingParameters* BlendingParams = {read=FBlendingParams, write=SetBlendingParams};
	__property TgxMaterialOptions MaterialOptions = {read=FMaterialOptions, write=SetMaterialOptions, default=0};
	__property Gxs::Texture::TgxTexture* Texture = {read=GetTexture, write=SetTexture, stored=StoreMaterialProps};
	__property TgxFaceCulling FaceCulling = {read=FFaceCulling, write=SetFaceCulling, default=0};
	__property TgxAbstractMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property TgxLibMaterialName LibMaterialName = {read=FLibMaterialName, write=SetLibMaterialName};
	__property Gxs::Texture::TgxTextureEx* TextureEx = {read=GetTextureEx, write=SetTextureEx, stored=StoreTextureEx};
	__property Gxs::State::TgxPolygonMode PolygonMode = {read=FPolygonMode, write=SetPolygonMode, default=0};
private:
	void *__IgxTextureNotifyAble;	// Gxs::Texture::IgxTextureNotifyAble 
	void *__IgxMaterialLibrarySupported;	// IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0D9DC0B0-ECE4-4513-A8A1-5AE7022C9426}
	operator Gxs::Texture::_di_IgxTextureNotifyAble()
	{
		Gxs::Texture::_di_IgxTextureNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Texture::IgxTextureNotifyAble*(void) { return (Gxs::Texture::IgxTextureNotifyAble*)&__IgxTextureNotifyAble; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator Gxs::Baseclasses::_di_IgxNotifyAble()
	{
		Gxs::Baseclasses::_di_IgxNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Baseclasses::IgxNotifyAble*(void) { return (Gxs::Baseclasses::IgxNotifyAble*)&__IgxTextureNotifyAble; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator _di_IgxMaterialLibrarySupported()
	{
		_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxMaterialLibrarySupported*(void) { return (IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxAbstractLibMaterial : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
protected:
	System::Classes::TList* FUserList;
	TgxLibMaterialName FName;
	int FNameHashKey;
	int FTag;
	bool FNotifying;
	TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	virtual System::UnicodeString __fastcall GetDisplayName();
	__classmethod int __fastcall ComputeNameHashKey(const System::UnicodeString name);
	void __fastcall SetName(const TgxLibMaterialName val);
	virtual void __fastcall Loaded() = 0 ;
	
public:
	__fastcall virtual TgxAbstractLibMaterial(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxAbstractLibMaterial();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci) = 0 ;
	virtual bool __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci) = 0 ;
	void __fastcall RegisterUser(Gxs::Baseclasses::TgxUpdateAbleObject* Obj)/* overload */;
	void __fastcall UnRegisterUser(Gxs::Baseclasses::TgxUpdateAbleObject* Obj)/* overload */;
	void __fastcall RegisterUser(Gxs::Baseclasses::TgxUpdateAbleComponent* comp)/* overload */;
	void __fastcall UnRegisterUser(Gxs::Baseclasses::TgxUpdateAbleComponent* comp)/* overload */;
	void __fastcall RegisterUser(TgxLibMaterial* libMaterial)/* overload */;
	void __fastcall UnRegisterUser(TgxLibMaterial* libMaterial)/* overload */;
	void __fastcall NotifyUsers();
	bool __fastcall IsUsed();
	__property int NameHashKey = {read=FNameHashKey, nodefault};
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual bool __fastcall Blended();
	__property TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary};
	
__published:
	__property TgxLibMaterialName Name = {read=FName, write=SetName};
	__property int Tag = {read=FTag, write=FTag, nodefault};
private:
	void *__IgxNotifyAble;	// Gxs::Baseclasses::IgxNotifyAble 
	void *__IgxMaterialLibrarySupported;	// IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator Gxs::Baseclasses::_di_IgxNotifyAble()
	{
		Gxs::Baseclasses::_di_IgxNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Baseclasses::IgxNotifyAble*(void) { return (Gxs::Baseclasses::IgxNotifyAble*)&__IgxNotifyAble; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator _di_IgxMaterialLibrarySupported()
	{
		_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxMaterialLibrarySupported*(void) { return (IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxLibMaterial : public TgxAbstractLibMaterial
{
	typedef TgxAbstractLibMaterial inherited;
	
private:
	TgxMaterial* FMaterial;
	Gxs::Coordinates::TgxCoordinates* FTextureOffset;
	Gxs::Coordinates::TgxCoordinates* FTextureScale;
	float FTextureRotate;
	bool FTextureMatrixIsIdentity;
	bool FTextureOverride;
	Stage::Vectortypes::TMatrix4f FTextureMatrix;
	TgxLibMaterialName FTexture2Name;
	TgxShader* FShader;
	TgxLibMaterial* libMatTexture2;
	
protected:
	virtual void __fastcall Loaded();
	void __fastcall SetMaterial(TgxMaterial* const val);
	void __fastcall SetTextureOffset(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetTextureScale(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetTextureMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	void __fastcall SetTexture2Name(const TgxLibMaterialName val);
	void __fastcall SetShader(TgxShader* const val);
	void __fastcall SetTextureRotate(float Value);
	bool __fastcall StoreTextureRotate();
	void __fastcall CalculateTextureMatrix();
	void __fastcall DestroyHandles();
	void __fastcall DoOnTextureNeeded(System::TObject* Sender, System::UnicodeString &textureFileName);
	void __fastcall OnNotifyChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxLibMaterial(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxLibMaterial();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall PrepareBuildList();
	virtual void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual bool __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall NotifyUsersOfTexMapChange();
	__property Stage::Vectortypes::TMatrix4f TextureMatrix = {read=FTextureMatrix, write=SetTextureMatrix};
	__property bool TextureMatrixIsIdentity = {read=FTextureMatrixIsIdentity, nodefault};
	void __fastcall NotifyTexMapChange(System::TObject* Sender);
	virtual bool __fastcall Blended();
	
__published:
	__property TgxMaterial* Material = {read=FMaterial, write=SetMaterial};
	__property Gxs::Coordinates::TgxCoordinates* TextureOffset = {read=FTextureOffset, write=SetTextureOffset};
	__property Gxs::Coordinates::TgxCoordinates* TextureScale = {read=FTextureScale, write=SetTextureScale};
	__property float TextureRotate = {read=FTextureRotate, write=SetTextureRotate, stored=StoreTextureRotate};
	__property TgxLibMaterialName Texture2Name = {read=FTexture2Name, write=SetTexture2Name};
	__property TgxShader* Shader = {read=FShader, write=SetShader};
private:
	void *__IgxTextureNotifyAble;	// Gxs::Texture::IgxTextureNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0D9DC0B0-ECE4-4513-A8A1-5AE7022C9426}
	operator Gxs::Texture::_di_IgxTextureNotifyAble()
	{
		Gxs::Texture::_di_IgxTextureNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Texture::IgxTextureNotifyAble*(void) { return (Gxs::Texture::IgxTextureNotifyAble*)&__IgxTextureNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxAbstractLibMaterials : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
protected:
	void __fastcall Loaded();
	TgxAbstractLibMaterial* __fastcall GetMaterial(const TgxLibMaterialName AName);
	
public:
	virtual TgxLibMaterialName __fastcall MakeUniqueName(const TgxLibMaterialName nameRoot);
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxAbstractLibMaterials(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxAbstractLibMaterials() { }
	
};


class PASCALIMPLEMENTATION TgxLibMaterials : public TgxAbstractLibMaterials
{
	typedef TgxAbstractLibMaterials inherited;
	
public:
	TgxLibMaterial* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TgxLibMaterial* const val);
	TgxLibMaterial* __fastcall GetItems(int index);
	void __fastcall DestroyHandles();
	
public:
	__fastcall TgxLibMaterials(System::Classes::TComponent* AOwner);
	HIDESBASE System::Classes::TPersistent* __fastcall Owner();
	int __fastcall IndexOf(TgxLibMaterial* const Item);
	HIDESBASE TgxLibMaterial* __fastcall Add();
	HIDESBASE TgxLibMaterial* __fastcall FindItemID(int ID);
	__property TgxLibMaterial* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TgxLibMaterial* __fastcall GetLibMaterialByName(const TgxLibMaterialName AName);
	int __fastcall GetTextureIndex(Gxs::Texture::TgxTexture* const Texture);
	int __fastcall GetMaterialIndex(TgxMaterial* const Material);
	TgxLibMaterialName __fastcall GetNameOfTexture(Gxs::Texture::TgxTexture* const Texture);
	TgxLibMaterialName __fastcall GetNameOfLibMaterial(TgxLibMaterial* const Material);
	void __fastcall PrepareBuildList();
	void __fastcall DeleteUnusedMaterials();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxLibMaterials() { }
	
};


class PASCALIMPLEMENTATION TgxAbstractMaterialLibrary : public Gxs::Baseclasses::TgxCadenceAbleComponent
{
	typedef Gxs::Baseclasses::TgxCadenceAbleComponent inherited;
	
protected:
	TgxAbstractLibMaterials* FMaterials;
	TgxAbstractLibMaterial* FLastAppliedMaterial;
	System::UnicodeString FTexturePaths;
	System::Classes::TStringList* FTexturePathList;
	void __fastcall SetTexturePaths(const System::UnicodeString val);
	__property System::UnicodeString TexturePaths = {read=FTexturePaths, write=SetTexturePaths};
	virtual void __fastcall Loaded();
	
public:
	void __fastcall SetNamesToTStrings(System::Classes::TStrings* AStrings);
	virtual bool __fastcall ApplyMaterial(const System::UnicodeString AName, Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual bool __fastcall UnApplyMaterial(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
public:
	/* TComponent.Create */ inline __fastcall virtual TgxAbstractMaterialLibrary(System::Classes::TComponent* AOwner) : Gxs::Baseclasses::TgxCadenceAbleComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TgxAbstractMaterialLibrary() { }
	
};


class PASCALIMPLEMENTATION TgxMaterialLibrary : public TgxAbstractMaterialLibrary
{
	typedef TgxAbstractMaterialLibrary inherited;
	
private:
	bool FDoNotClearMaterialsOnLoad;
	Gxs::Texture::TgxTextureNeededEvent FOnTextureNeeded;
	
protected:
	TgxLibMaterials* __fastcall GetMaterials();
	void __fastcall SetMaterials(TgxLibMaterials* const val);
	bool __fastcall StoreMaterials();
	
public:
	__fastcall virtual TgxMaterialLibrary(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMaterialLibrary();
	void __fastcall DestroyHandles();
	void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	void __fastcall AddMaterialsFromStream(System::Classes::TStream* aStream);
	void __fastcall SaveToFile(const System::UnicodeString fileName);
	void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall AddMaterialsFromFile(const System::UnicodeString fileName);
	TgxLibMaterial* __fastcall AddTextureMaterial(const System::UnicodeString MaterialName, const System::UnicodeString fileName, bool persistent = true)/* overload */;
	TgxLibMaterial* __fastcall AddTextureMaterial(const System::UnicodeString MaterialName, Fmx::Graphics::TBitmap* Graphic)/* overload */;
	TgxLibMaterial* __fastcall LibMaterialByName(const TgxLibMaterialName AName);
	Gxs::Texture::TgxTexture* __fastcall TextureByName(const TgxLibMaterialName LibMatName);
	TgxLibMaterialName __fastcall GetNameOfTexture(Gxs::Texture::TgxTexture* const Texture);
	TgxLibMaterialName __fastcall GetNameOfLibMaterial(TgxLibMaterial* const libMat);
	
__published:
	__property TgxLibMaterials* Materials = {read=GetMaterials, write=SetMaterials, stored=StoreMaterials};
	__property Gxs::Texture::TgxTextureNeededEvent OnTextureNeeded = {read=FOnTextureNeeded, write=FOnTextureNeeded};
	__property TexturePaths = {default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Material */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MATERIAL)
using namespace Gxs::Material;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MaterialHPP
