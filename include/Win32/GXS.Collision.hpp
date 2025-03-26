// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Collision.pas' rev: 36.00 (Windows)

#ifndef GXS_CollisionHPP
#define GXS_CollisionHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Manager.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Collision
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCollisionManager;
class DELPHICLASS TgxBCollision;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TObjectCollisionEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* object1, Gxs::Scene::TgxBaseSceneObject* object2);

enum DECLSPEC_DENUM TCollisionBoundingMode : unsigned char { cbmPoint, cbmSphere, cbmEllipsoid, cbmCube, cbmFaces };

typedef bool __fastcall (*TFastCollisionChecker)(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);

typedef TFastCollisionChecker *PFastCollisionChecker;

class PASCALIMPLEMENTATION TgxCollisionManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* FClients;
	TObjectCollisionEvent FOnCollision;
	
protected:
	void __fastcall RegisterClient(TgxBCollision* aClient);
	void __fastcall DeRegisterClient(TgxBCollision* aClient);
	void __fastcall DeRegisterAllClients();
	
public:
	__fastcall virtual TgxCollisionManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCollisionManager();
	void __fastcall CheckCollisions();
	
__published:
	__property TObjectCollisionEvent OnCollision = {read=FOnCollision, write=FOnCollision};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBCollision : public Gxs::Scene::TgxBehaviour
{
	typedef Gxs::Scene::TgxBehaviour inherited;
	
private:
	TCollisionBoundingMode FBoundingMode;
	TgxCollisionManager* FManager;
	System::UnicodeString FManagerName;
	int FGroupIndex;
	
protected:
	void __fastcall SetGroupIndex(const int value);
	void __fastcall SetManager(TgxCollisionManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TgxBCollision(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxBCollision();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property TgxCollisionManager* Manager = {read=FManager, write=SetManager};
	__property TCollisionBoundingMode BoundingMode = {read=FBoundingMode, write=FBoundingMode, nodefault};
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall FastCheckPointVsPoint(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckPointVsSphere(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckPointVsEllipsoid(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckPointVsCube(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckSphereVsPoint(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckSphereVsSphere(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckSphereVsEllipsoid(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckSphereVsCube(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckEllipsoidVsPoint(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckEllipsoidVsSphere(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckEllipsoidVsEllipsoid(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckEllipsoidVsCube(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckCubeVsPoint(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckCubeVsSphere(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckCubeVsEllipsoid(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckCubeVsCube(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckCubeVsFace(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckFaceVsCube(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall FastCheckFaceVsFace(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2);
extern DELPHI_PACKAGE bool __fastcall IntersectCubes(Gxs::Scene::TgxBaseSceneObject* obj1, Gxs::Scene::TgxBaseSceneObject* obj2)/* overload */;
extern DELPHI_PACKAGE TgxBCollision* __fastcall GetOrCreateCollision(Gxs::Scene::TgxBehaviours* behaviours)/* overload */;
extern DELPHI_PACKAGE TgxBCollision* __fastcall GetOrCreateCollision(Gxs::Scene::TgxBaseSceneObject* obj)/* overload */;
}	/* namespace Collision */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_COLLISION)
using namespace Gxs::Collision;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CollisionHPP
