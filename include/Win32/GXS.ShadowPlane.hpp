// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ShadowPlane.pas' rev: 36.00 (Windows)

#ifndef GXS_ShadowPlaneHPP
#define GXS_ShadowPlaneHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <FMX.Effects.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Scene.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Context.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Shadowplane
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxShadowPlane;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TShadowPlaneOption : unsigned char { spoUseStencil, spoScissor, spoTransparent, spoIgnoreZ };

typedef System::Set<TShadowPlaneOption, TShadowPlaneOption::spoUseStencil, TShadowPlaneOption::spoIgnoreZ> TShadowPlaneOptions;

class PASCALIMPLEMENTATION TgxShadowPlane : public Gxs::Objects::TgxPlane
{
	typedef Gxs::Objects::TgxPlane inherited;
	
private:
	bool FRendering;
	Gxs::Scene::TgxBaseSceneObject* FShadowingObject;
	Gxs::Scene::TgxLightSource* FShadowedLight;
	Gxs::Color::TgxColor* FShadowColor;
	TShadowPlaneOptions FShadowOptions;
	System::Classes::TNotifyEvent FOnBeginRenderingShadows;
	System::Classes::TNotifyEvent FOnEndRenderingShadows;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetShadowingObject(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetShadowedLight(Gxs::Scene::TgxLightSource* const val);
	void __fastcall SetShadowColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetShadowOptions(const TShadowPlaneOptions val);
	
public:
	__fastcall virtual TgxShadowPlane(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxShadowPlane();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* ShadowingObject = {read=FShadowingObject, write=SetShadowingObject};
	__property Gxs::Scene::TgxLightSource* ShadowedLight = {read=FShadowedLight, write=SetShadowedLight};
	__property Gxs::Color::TgxColor* ShadowColor = {read=FShadowColor, write=SetShadowColor};
	__property TShadowPlaneOptions ShadowOptions = {read=FShadowOptions, write=SetShadowOptions, default=3};
	__property System::Classes::TNotifyEvent OnBeginRenderingShadows = {read=FOnBeginRenderingShadows, write=FOnBeginRenderingShadows};
	__property System::Classes::TNotifyEvent OnEndRenderingShadows = {read=FOnEndRenderingShadows, write=FOnEndRenderingShadows};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxShadowPlane(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxPlane(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultShadowPlaneOptions (System::Set<TShadowPlaneOption, TShadowPlaneOption::spoUseStencil, TShadowPlaneOption::spoIgnoreZ>() << TShadowPlaneOption::spoUseStencil << TShadowPlaneOption::spoScissor )
}	/* namespace Shadowplane */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SHADOWPLANE)
using namespace Gxs::Shadowplane;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ShadowPlaneHPP
