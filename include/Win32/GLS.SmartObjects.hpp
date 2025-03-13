// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.SmartObjects.pas' rev: 36.00 (Windows)

#ifndef GLS_SmartObjectsHPP
#define GLS_SmartObjectsHPP

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
#include <Vcl.Consts.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <Stage.Strings.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GLS.Scene.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Silhouette.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Material.hpp>
#include <GLS.Mesh.hpp>
#include <GLS.Octree.hpp>
#include <GLS.GeometryBB.hpp>
#include <GLS.Objects.hpp>
#include <GLS.GeomObjects.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.Context.hpp>
#include <GLS.Color.hpp>
#include <GLS.Selection.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.BaseClasses.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.SoundManager.hpp>
#include <GLS.SoundFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Smartobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLCyborgThinks;
class DELPHICLASS TGLCyborgThinksList;
class DELPHICLASS TGLCyborg;
class DELPHICLASS TGLSwartSwarm;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLSmartSwarmMode : unsigned char { isNone, isRandom, isTetra, isGrid };

enum DECLSPEC_DENUM TGLCyborgReference : unsigned char { crNone, crWeak, crStrong };

enum DECLSPEC_DENUM TGLCyborgThinkMode : unsigned char { ctmSelf, ctmSleep, ctmOutside, ctmZombie, ctmDeath };

enum DECLSPEC_DENUM TGLCyborgOption : unsigned char { coCollide, coContact, coJoin };

enum DECLSPEC_DENUM TGLCyborgSenceOrgans : unsigned char { csoVision, csoHearing, csoSmell, csoTouch, taste };

typedef System::Set<TGLCyborgOption, TGLCyborgOption::coCollide, TGLCyborgOption::coJoin> TGLCyborgOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLCyborgThinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	/* TCollection.Create */ inline __fastcall TGLCyborgThinks(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLCyborgThinks() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLCyborgThinksList : public Gls::Persistentclasses::TGLPersistentObjectList
{
	typedef Gls::Persistentclasses::TGLPersistentObjectList inherited;
	
public:
	/* TGLPersistentObjectList.Create */ inline __fastcall virtual TGLCyborgThinksList() : Gls::Persistentclasses::TGLPersistentObjectList() { }
	/* TGLPersistentObjectList.Destroy */ inline __fastcall virtual ~TGLCyborgThinksList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLCyborgThinksList(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Persistentclasses::TGLPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLCyborg : public Gls::Vectorfileobjects::TGLActor
{
	typedef Gls::Vectorfileobjects::TGLActor inherited;
	
private:
	System::TDateTime FBirthTime;
	System::TDateTime FDeathTime;
	TGLCyborgReference FReference;
	TGLCyborgThinkMode FThinkMode;
	System::Classes::TList* FControlers;
	int FInterval;
	TGLCyborgOptions FOptions;
	TGLCyborgThinks* FThinkings;
	
protected:
	HIDESBASE void __fastcall SetReference(TGLCyborgReference val);
	void __fastcall SetThinking(const TGLCyborgThinkMode val);
	bool __fastcall StoreThinking();
	HIDESBASE void __fastcall SetOptions(const TGLCyborgOptions val);
	virtual void __fastcall DoThink();
	
public:
	__fastcall virtual TGLCyborg(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLCyborg();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gls::Baseclasses::TGLProgressTimes &progressTime);
	virtual void __fastcall LoadFromStream(const System::UnicodeString Filename, System::Classes::TStream* aStream);
	void __fastcall SwitchToThinking(TGLCyborgThinks* anThinking, bool smooth = false);
	System::UnicodeString __fastcall CurrentThinking();
	bool __fastcall IsThinking();
	
__published:
	__property TGLCyborgThinkMode ThinkingMode = {read=FThinkMode, write=FThinkMode, default=0};
	__property TGLCyborgReference SmartReference = {read=FReference, write=FReference, default=0};
	__property int Interval = {read=FInterval, write=FInterval, nodefault};
	__property TGLCyborgOptions Options = {read=FOptions, write=SetOptions, default=1};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLCyborg(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Vectorfileobjects::TGLActor(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLSwartSwarm : public Gls::Objects::TGLPoints
{
	typedef Gls::Objects::TGLPoints inherited;
	
private:
	System::TDateTime FBirthTime;
	System::TDateTime FDeathTime;
	TGLCyborgReference FReference;
	TGLSmartSwarmMode FThinkMode;
	
public:
	__fastcall virtual TGLSwartSwarm(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLSwartSwarm();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TGLSmartSwarmMode ThinkingMode = {read=FThinkMode, nodefault};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLSwartSwarm(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Objects::TGLPoints(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultCyborgOptions (System::Set<TGLCyborgOption, TGLCyborgOption::coCollide, TGLCyborgOption::coJoin>() << TGLCyborgOption::coCollide )
extern DELPHI_PACKAGE bool vGLSmartObjectsAllocate;
extern DELPHI_PACKAGE bool vGLSmartObjectsEnableByDefault;
}	/* namespace Smartobjects */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SMARTOBJECTS)
using namespace Gls::Smartobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_SmartObjectsHPP
