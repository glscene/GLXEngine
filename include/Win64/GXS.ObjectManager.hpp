// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ObjectManager.pas' rev: 36.00 (Windows)

#ifndef GXS_ObjectManagerHPP
#define GXS_ObjectManagerHPP

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
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Menus.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Scene.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Objectmanager
{
//-- forward type declarations -----------------------------------------------
struct TgxSceneObjectEntry;
class DELPHICLASS TgxObjectManager;
//-- type declarations -------------------------------------------------------
typedef TgxSceneObjectEntry *PSceneObjectEntry;

struct DECLSPEC_DRECORD TgxSceneObjectEntry
{
public:
	Gxs::Scene::TgxSceneObjectClass ObjectClass;
	System::UnicodeString Name;
	System::UnicodeString Category;
	int Index;
	int ImageIndex;
};


class PASCALIMPLEMENTATION TgxObjectManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* FSceneObjectList;
	Fmx::Controls::TStyleBook* FObjectIcons;
	int FOverlayIndex;
	int FSceneRootIndex;
	int FCameraRootIndex;
	int FLightsourceRootIndex;
	int FObjectRootIndex;
	
protected:
	void __fastcall DestroySceneObjectList();
	PSceneObjectEntry __fastcall FindSceneObjectClass(Gxs::Scene::TgxSceneObjectClass AObjectClass, const System::UnicodeString ASceneObject = System::UnicodeString());
	
public:
	__fastcall virtual TgxObjectManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxObjectManager();
	void __fastcall CreateDefaultObjectIcons(unsigned ResourceModule);
	Gxs::Scene::TgxSceneObjectClass __fastcall GetClassFromIndex(int Index);
	int __fastcall GetImageIndex(Gxs::Scene::TgxSceneObjectClass ASceneObject);
	System::UnicodeString __fastcall GetCategory(Gxs::Scene::TgxSceneObjectClass ASceneObject);
	void __fastcall GetRegisteredSceneObjects(System::Classes::TStringList* ObjectList);
	void __fastcall PopulateMenuWithRegisteredSceneObjects(Fmx::Menus::TMenuItem* AMenuItem, System::Classes::TNotifyEvent AClickEvent);
	void __fastcall RegisterSceneObject(Gxs::Scene::TgxSceneObjectClass ASceneObject, const System::UnicodeString AName, const System::UnicodeString ACategory)/* overload */;
	void __fastcall RegisterSceneObject(Gxs::Scene::TgxSceneObjectClass ASceneObject, const System::UnicodeString AName, const System::UnicodeString ACategory, Fmx::Graphics::TBitmap* ABitmap)/* overload */;
	void __fastcall RegisterSceneObject(Gxs::Scene::TgxSceneObjectClass ASceneObject, const System::UnicodeString AName, const System::UnicodeString ACategory, unsigned ResourceModule, System::UnicodeString ResourceName = System::UnicodeString())/* overload */;
	void __fastcall UnRegisterSceneObject(Gxs::Scene::TgxSceneObjectClass ASceneObject);
	__property Fmx::Controls::TStyleBook* ObjectIcons = {read=FObjectIcons};
	__property int SceneRootIndex = {read=FSceneRootIndex, nodefault};
	__property int LightsourceRootIndex = {read=FLightsourceRootIndex, nodefault};
	__property int CameraRootIndex = {read=FCameraRootIndex, nodefault};
	__property int ObjectRootIndex = {read=FObjectRootIndex, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Objectmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_OBJECTMANAGER)
using namespace Gxs::Objectmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ObjectManagerHPP
