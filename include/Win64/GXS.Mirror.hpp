// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Mirror.pas' rev: 36.00 (Windows)

#ifndef GXS_MirrorHPP
#define GXS_MirrorHPP

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
#include <GXS.XCollection.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Mirror
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMirror;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMirrorOption : unsigned char { moUseStencil, moOpaque, moMirrorPlaneClip, moClearZBuffer };

typedef System::Set<TMirrorOption, TMirrorOption::moUseStencil, TMirrorOption::moClearZBuffer> TMirrorOptions;

enum DECLSPEC_DENUM TMirrorShapes : unsigned char { msRect, msDisk };

class PASCALIMPLEMENTATION TgxMirror : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	bool FRendering;
	Gxs::Scene::TgxBaseSceneObject* FMirrorObject;
	float FWidth;
	float FHeight;
	TMirrorOptions FMirrorOptions;
	System::Classes::TNotifyEvent FOnBeginRenderingMirrors;
	System::Classes::TNotifyEvent FOnEndRenderingMirrors;
	TMirrorShapes FShape;
	float FRadius;
	int FSlices;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetMirrorObject(Gxs::Scene::TgxBaseSceneObject* const val);
	void __fastcall SetMirrorOptions(const TMirrorOptions val);
	void __fastcall ClearZBufferArea(Gxs::Scene::TgxSceneBuffer* aBuffer);
	void __fastcall SetHeight(float AValue);
	void __fastcall SetWidth(float AValue);
	void __fastcall SetRadius(const float aValue);
	void __fastcall SetSlices(const int aValue);
	void __fastcall SetShape(TMirrorShapes aValue);
	float __fastcall GetRadius();
	int __fastcall GetSlices();
	
public:
	__fastcall virtual TgxMirror(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* MirrorObject = {read=FMirrorObject, write=SetMirrorObject};
	__property TMirrorOptions MirrorOptions = {read=FMirrorOptions, write=SetMirrorOptions, default=1};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Width = {read=FWidth, write=SetWidth};
	__property System::Classes::TNotifyEvent OnBeginRenderingMirrors = {read=FOnBeginRenderingMirrors, write=FOnBeginRenderingMirrors};
	__property System::Classes::TNotifyEvent OnEndRenderingMirrors = {read=FOnEndRenderingMirrors, write=FOnEndRenderingMirrors};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property TMirrorShapes Shape = {read=FShape, write=SetShape, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxMirror() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMirror(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultMirrorOptions (System::Set<TMirrorOption, TMirrorOption::moUseStencil, TMirrorOption::moClearZBuffer>() << TMirrorOption::moUseStencil )
}	/* namespace Mirror */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MIRROR)
using namespace Gxs::Mirror;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MirrorHPP
