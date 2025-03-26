// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ProjectedTextures.pas' rev: 36.00 (Windows)

#ifndef GXS_ProjectedTexturesHPP
#define GXS_ProjectedTexturesHPP

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
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Texture.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Projectedtextures
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTextureEmitter;
class DELPHICLASS TgxTextureEmitterItem;
class DELPHICLASS TgxTextureEmitters;
class DELPHICLASS TgxProjectedTextures;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxProjectedTexturesStyle : unsigned char { ptsOriginal, ptsInverse };

class PASCALIMPLEMENTATION TgxTextureEmitter : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	float FFOVy;
	float FAspect;
	
protected:
	void __fastcall SetupTexMatrix(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	
public:
	__fastcall virtual TgxTextureEmitter(System::Classes::TComponent* AOwner);
	
__published:
	__property float FOVy = {read=FFOVy, write=FFOVy};
	__property float Aspect = {read=FAspect, write=FAspect};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxTextureEmitter() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTextureEmitter(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxTextureEmitterItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxTextureEmitter* FEmitter;
	
protected:
	void __fastcall SetEmitter(TgxTextureEmitter* const val);
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxTextureEmitterItem(System::Classes::TCollection* ACollection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxTextureEmitter* Emitter = {read=FEmitter, write=SetEmitter};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxTextureEmitterItem() { }
	
};


class PASCALIMPLEMENTATION TgxTextureEmitters : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxTextureEmitterItem* operator[](int index) { return this->Items[index]; }
	
private:
	TgxProjectedTextures* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	TgxTextureEmitterItem* __fastcall GetItems(int index);
	void __fastcall RemoveNotification(System::Classes::TComponent* aComponent);
	
public:
	void __fastcall AddEmitter(TgxTextureEmitter* texEmitter);
	__property TgxTextureEmitterItem* Items[int index] = {read=GetItems/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TgxTextureEmitters(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxTextureEmitters() { }
	
};


class PASCALIMPLEMENTATION TgxProjectedTextures : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	TgxTextureEmitters* FEmitters;
	TgxProjectedTexturesStyle FStyle;
	
public:
	__fastcall virtual TgxProjectedTextures(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxProjectedTextures();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	
__published:
	__property TgxTextureEmitters* Emitters = {read=FEmitters, write=FEmitters};
	__property TgxProjectedTexturesStyle Style = {read=FStyle, write=FStyle, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxProjectedTextures(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Projectedtextures */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_PROJECTEDTEXTURES)
using namespace Gxs::Projectedtextures;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ProjectedTexturesHPP
