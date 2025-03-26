// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FBORenderer.pas' rev: 36.00 (Windows)

#ifndef GXS_FBORendererHPP
#define GXS_FBORendererHPP

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
#include <FMX.Dialogs.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Context.hpp>
#include <GXS.FBO.hpp>
#include <GXS.Color.hpp>
#include <GXS.Material.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.MultisampleImage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fborenderer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFBORenderer;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxEnabledRenderBuffer : unsigned char { erbDepth, erbStencil };

typedef System::Set<TgxEnabledRenderBuffer, TgxEnabledRenderBuffer::erbDepth, TgxEnabledRenderBuffer::erbStencil> TgxEnabledRenderBuffers;

enum DECLSPEC_DENUM TgxFBOTargetVisibility : unsigned char { tvDefault, tvFBOOnly };

enum DECLSPEC_DENUM TgxFBOClearOption : unsigned char { coColorBufferClear, coDepthBufferClear, coStencilBufferClear, coUseBufferBackground };

typedef System::Set<TgxFBOClearOption, TgxFBOClearOption::coColorBufferClear, TgxFBOClearOption::coUseBufferBackground> TgxFBOClearOptions;

typedef System::DynamicArray<Gxs::Texture::TgxTexture*> TgxTextureArray;

typedef void __fastcall (__closure *TSetTextureTargetsEvent)(System::TObject* Sender, TgxTextureArray &colorTexs);

class PASCALIMPLEMENTATION TgxFBORenderer : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	Gxs::Fbo::TgxFrameBuffer* FFbo;
	Gxs::Fbo::TgxDepthRBO* FDepthRBO;
	Gxs::Fbo::TgxStencilRBO* FStencilRBO;
	int FColorAttachment;
	bool FRendering;
	bool FHasColor;
	bool FHasDepth;
	bool FHasStencil;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxLibMaterialName FColorTextureName;
	Gxs::Material::TgxLibMaterialName FDepthTextureName;
	int FWidth;
	int FHeight;
	bool FForceTextureDimensions;
	Gxs::Fbo::TgxStencilPrecision FStencilPrecision;
	Gxs::Scene::TgxBaseSceneObject* FRootObject;
	bool FRootVisible;
	Gxs::Scene::TgxCamera* FCamera;
	TgxEnabledRenderBuffers FEnabledRenderBuffers;
	TgxFBOTargetVisibility FTargetVisibility;
	Gxs::Scene::TDirectRenderEvent FBeforeRender;
	System::Classes::TNotifyEvent FPostInitialize;
	Gxs::Scene::TDirectRenderEvent FAfterRender;
	System::Classes::TNotifyEvent FPreInitialize;
	Gxs::Color::TgxColor* FBackgroundColor;
	TgxFBOClearOptions FClearOptions;
	float FAspect;
	float FSceneScaleFactor;
	bool FUseLibraryAsMultiTarget;
	bool FPostGenerateMipmap;
	int FMaxSize;
	int FMaxAttachment;
	System::StaticArray<Stage::Vectortypes::TVector4f, 3> FStoreCamera;
	TSetTextureTargetsEvent FOnSetTextureTargets;
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxAbstractMaterialLibrary* const Value);
	void __fastcall SetDepthTextureName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetColorTextureName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetForceTextureDimentions(const bool Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetLayer(const int Value);
	int __fastcall GetLayer();
	void __fastcall SetLevel(const int Value);
	int __fastcall GetLevel();
	void __fastcall SetStencilPrecision(const Gxs::Fbo::TgxStencilPrecision Value);
	void __fastcall SetRootObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	Stage::Vectorgeometry::TRectangle __fastcall GetViewport();
	void __fastcall SetCamera(Gxs::Scene::TgxCamera* const Value);
	void __fastcall SetEnabledRenderBuffers(const TgxEnabledRenderBuffers Value);
	void __fastcall SetTargetVisibility(const TgxFBOTargetVisibility Value);
	void __fastcall SetBackgroundColor(Gxs::Color::TgxColor* const Value);
	bool __fastcall StoreSceneScaleFactor();
	bool __fastcall StoreAspect();
	void __fastcall SetUseLibraryAsMultiTarget(bool Value);
	void __fastcall SetPostGenerateMipmap(const bool Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall Initialize();
	void __fastcall ForceDimensions(Gxs::Texture::TgxTexture* Texture);
	void __fastcall RenderToFBO(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall ApplyCamera(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall UnApplyCamera(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall DoBeforeRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall DoAfterRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	void __fastcall DoPreInitialize();
	void __fastcall DoPostInitialize();
	__property bool HasColor = {read=FHasColor, nodefault};
	__property bool HasDepth = {read=FHasDepth, nodefault};
	__property bool HasStencil = {read=FHasStencil, nodefault};
	__property Stage::Vectorgeometry::TRectangle Viewport = {read=GetViewport};
	
public:
	__fastcall virtual TgxFBORenderer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxFBORenderer();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__property int Layer = {read=GetLayer, write=SetLayer, nodefault};
	__property int Level = {read=GetLevel, write=SetLevel, nodefault};
	
__published:
	__property bool Active = {read=GetVisible, write=SetVisible, default=1};
	__property bool PickableTarget = {read=GetPickable, write=SetPickable, default=0};
	__property bool ForceTextureDimensions = {read=FForceTextureDimensions, write=SetForceTextureDimentions, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=256};
	__property int Height = {read=FHeight, write=SetHeight, default=256};
	__property float Aspect = {read=FAspect, write=FAspect, stored=StoreAspect};
	__property Gxs::Material::TgxLibMaterialName ColorTextureName = {read=FColorTextureName, write=SetColorTextureName};
	__property Gxs::Material::TgxLibMaterialName DepthTextureName = {read=FDepthTextureName, write=SetDepthTextureName};
	__property Gxs::Material::TgxAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Color::TgxColor* BackgroundColor = {read=FBackgroundColor, write=SetBackgroundColor};
	__property TgxFBOClearOptions ClearOptions = {read=FClearOptions, write=FClearOptions, nodefault};
	__property Gxs::Scene::TgxCamera* Camera = {read=FCamera, write=SetCamera};
	__property float SceneScaleFactor = {read=FSceneScaleFactor, write=FSceneScaleFactor, stored=StoreSceneScaleFactor};
	__property Gxs::Scene::TgxBaseSceneObject* RootObject = {read=FRootObject, write=SetRootObject};
	__property TgxFBOTargetVisibility TargetVisibility = {read=FTargetVisibility, write=SetTargetVisibility, default=0};
	__property TgxEnabledRenderBuffers EnabledRenderBuffers = {read=FEnabledRenderBuffers, write=SetEnabledRenderBuffers, nodefault};
	__property Gxs::Fbo::TgxStencilPrecision StencilPrecision = {read=FStencilPrecision, write=SetStencilPrecision, default=0};
	__property Gxs::Scene::TDirectRenderEvent BeforeRender = {read=FBeforeRender, write=FBeforeRender};
	__property Gxs::Scene::TDirectRenderEvent AfterRender = {read=FAfterRender, write=FAfterRender};
	__property System::Classes::TNotifyEvent PreInitialize = {read=FPreInitialize, write=FPreInitialize};
	__property System::Classes::TNotifyEvent PostInitialize = {read=FPostInitialize, write=FPostInitialize};
	__property bool UseLibraryAsMultiTarget = {read=FUseLibraryAsMultiTarget, write=SetUseLibraryAsMultiTarget, default=0};
	__property bool PostGenerateMipmap = {read=FPostGenerateMipmap, write=SetPostGenerateMipmap, default=1};
	__property TSetTextureTargetsEvent OnSetTextureTargets = {read=FOnSetTextureTargets, write=FOnSetTextureTargets};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFBORenderer(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
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
}	/* namespace Fborenderer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FBORENDERER)
using namespace Gxs::Fborenderer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FBORendererHPP
