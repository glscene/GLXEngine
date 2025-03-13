// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SmartObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_SmartObjectsHPP
#define GXS_SmartObjectsHPP

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
#include <System.Math.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Strings.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Color.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.Mesh.hpp>
#include <GXS.Octree.hpp>
#include <GXS.Objects.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Context.hpp>
#include <GXS.Selection.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.SoundManager.hpp>
#include <GXS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Smartobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCyborgThinks;
class DELPHICLASS TgxCyborgThinksList;
class DELPHICLASS TgxCyborg;
class DELPHICLASS TgxSwartSwarm;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSmartSwarmMode : unsigned char { isNone, isRandom, isTetra, isGrid };

enum DECLSPEC_DENUM TgxCyborgReference : unsigned char { crNone, crWeak, crStrong };

enum DECLSPEC_DENUM TgxCyborgThinkMode : unsigned char { ctmSelf, ctmSleep, ctmOutside, ctmZombie, ctmDeath };

enum DECLSPEC_DENUM TgxCyborgOption : unsigned char { coCollide, coContact, coJoin };

enum DECLSPEC_DENUM TgxCyborgSenceOrgans : unsigned char { csoVision, csoHearing, csoSmell, csoTouch, taste };

typedef System::Set<TgxCyborgOption, TgxCyborgOption::coCollide, TgxCyborgOption::coJoin> TgxCyborgOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxCyborgThinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	/* TCollection.Create */ inline __fastcall TgxCyborgThinks(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxCyborgThinks() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxCyborgThinksList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxCyborgThinksList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	/* TgxPersistentObjectList.Destroy */ inline __fastcall virtual ~TgxCyborgThinksList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxCyborgThinksList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxCyborg : public Gxs::Vectorfileobjects::TgxActor
{
	typedef Gxs::Vectorfileobjects::TgxActor inherited;
	
private:
	System::TDateTime FBirthTime;
	System::TDateTime FDeathTime;
	TgxCyborgReference FReference;
	TgxCyborgThinkMode FThinkMode;
	System::Classes::TList* FControlers;
	int FInterval;
	TgxCyborgOptions FOptions;
	TgxCyborgThinks* FThinkings;
	
protected:
	HIDESBASE void __fastcall SetReference(TgxCyborgReference val);
	void __fastcall SetThinking(const TgxCyborgThinkMode val);
	bool __fastcall StoreThinking();
	HIDESBASE void __fastcall SetOptions(const TgxCyborgOptions val);
	virtual void __fastcall DoThink();
	
public:
	__fastcall virtual TgxCyborg(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxCyborg();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall LoadFromStream(const System::UnicodeString Filename, System::Classes::TStream* aStream);
	void __fastcall SwitchToThinking(TgxCyborgThinks* anThinking, bool smooth = false);
	System::UnicodeString __fastcall CurrentThinking();
	bool __fastcall IsThinking();
	
__published:
	__property TgxCyborgThinkMode ThinkingMode = {read=FThinkMode, write=FThinkMode, default=0};
	__property TgxCyborgReference SmartReference = {read=FReference, write=FReference, default=0};
	__property int Interval = {read=FInterval, write=FInterval, nodefault};
	__property TgxCyborgOptions Options = {read=FOptions, write=SetOptions, default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCyborg(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxActor(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxSwartSwarm : public Gxs::Objects::TgxPoints
{
	typedef Gxs::Objects::TgxPoints inherited;
	
private:
	System::TDateTime FBirthTime;
	System::TDateTime FDeathTime;
	TgxCyborgReference FReference;
	TgxSmartSwarmMode FThinkMode;
	
public:
	__fastcall virtual TgxSwartSwarm(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxSwartSwarm();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxSmartSwarmMode ThinkingMode = {read=FThinkMode, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSwartSwarm(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxPoints(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultCyborgOptions (System::Set<TgxCyborgOption, TgxCyborgOption::coCollide, TgxCyborgOption::coJoin>() << TgxCyborgOption::coCollide )
extern DELPHI_PACKAGE bool vGLSmartObjectsAllocate;
extern DELPHI_PACKAGE bool vGLSmartObjectsEnableByDefault;
}	/* namespace Smartobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SMARTOBJECTS)
using namespace Gxs::Smartobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SmartObjectsHPP
