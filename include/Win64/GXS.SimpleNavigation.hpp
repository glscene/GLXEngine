// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SimpleNavigation.pas' rev: 36.00 (Windows)

#ifndef GXS_SimpleNavigationHPP
#define GXS_SimpleNavigationHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.TypInfo.hpp>
#include <System.Math.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.Types.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Scene.hpp>
#include <GXS.SceneViewer.hpp>
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Simplenavigation
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSimpleNavigationKeyCombination;
class DELPHICLASS TgxSimpleNavigationKeyCombinations;
class DELPHICLASS TgxSimpleNavigation;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSimpleNavigationOption : unsigned char { snoInvertMoveAroundX, snoInvertMoveAroundY, snoInvertZoom, snoInvertMouseWheel, snoInvertRotateX, snoInvertRotateY, snoMouseWheelHandled, snoShowFPS };

typedef System::Set<TgxSimpleNavigationOption, TgxSimpleNavigationOption::snoInvertMoveAroundX, TgxSimpleNavigationOption::snoShowFPS> TgxSimpleNavigationOptions;

enum DECLSPEC_DENUM TgxSimpleNavigationAction : unsigned char { snaNone, snaMoveAroundTarget, snaZoom, snaRotateTarget, snaCustom };

typedef void __fastcall (__closure *TSimpleNavigationCustomActionEvent)(TgxSimpleNavigationKeyCombination* Sender, System::Classes::TShiftState Shift, float X, float Y);

class PASCALIMPLEMENTATION TgxSimpleNavigationKeyCombination : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FExitOnMatch;
	TgxSimpleNavigationAction FAction;
	TSimpleNavigationCustomActionEvent FOnCustomAction;
	System::Classes::TShiftState FShiftState;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	virtual void __fastcall DoOnCustomAction(System::Classes::TShiftState Shift, float X, float Y);
	
public:
	__fastcall virtual TgxSimpleNavigationKeyCombination(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TShiftState ShiftState = {read=FShiftState, write=FShiftState, default=0};
	__property bool ExitOnMatch = {read=FExitOnMatch, write=FExitOnMatch, default=1};
	__property TgxSimpleNavigationAction Action = {read=FAction, write=FAction, default=0};
	__property TSimpleNavigationCustomActionEvent OnCustomAction = {read=FOnCustomAction, write=FOnCustomAction};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TgxSimpleNavigationKeyCombination() { }
	
};


class PASCALIMPLEMENTATION TgxSimpleNavigationKeyCombinations : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxSimpleNavigationKeyCombination* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxSimpleNavigationKeyCombination* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TgxSimpleNavigationKeyCombination* const Value);
	
public:
	HIDESBASE TgxSimpleNavigationKeyCombination* __fastcall Add()/* overload */;
	HIDESBASE TgxSimpleNavigationKeyCombination* __fastcall Add(const System::Classes::TShiftState AShiftState, const TgxSimpleNavigationAction AAction, const bool AExitOnMatch = true)/* overload */;
	__property TgxSimpleNavigationKeyCombination* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxSimpleNavigationKeyCombinations(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxSimpleNavigationKeyCombinations() { }
	
};


class PASCALIMPLEMENTATION TgxSimpleNavigation : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Fmx::Types::TTimer* FTimer;
	Fmx::Forms::TCustomForm* FForm;
	Gxs::Sceneviewer::TgxSceneViewer* FGLXceneViewer;
	float FOldX;
	float FOldY;
	System::UnicodeString FFormCaption;
	float FMoveAroundTargetSpeed;
	float FZoomSpeed;
	TgxSimpleNavigationOptions FOptions;
	TgxSimpleNavigationKeyCombinations* FKeyCombinations;
	float FRotateTargetSpeed;
	Fmx::Types::TMouseMoveEvent FOnMouseMove;
	void __fastcall ShowFPS(System::TObject* Sender);
	void __fastcall ViewerMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, float X, float Y);
	void __fastcall ViewerMouseWheel(System::TObject* Sender, System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall SetGLXceneViewer(Gxs::Sceneviewer::TgxSceneViewer* const Value);
	void __fastcall SetForm(Fmx::Forms::TCustomForm* const Value);
	bool __fastcall StoreFormCaption();
	bool __fastcall StoreMoveAroundTargetSpeed();
	bool __fastcall StoreZoomSpeed();
	void __fastcall SetKeyCombinations(TgxSimpleNavigationKeyCombinations* const Value);
	bool __fastcall StoreRotateTargetSpeed();
	void __fastcall SetOptions(const TgxSimpleNavigationOptions Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxSimpleNavigation(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSimpleNavigation();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Fmx::Forms::TCustomForm* Form = {read=FForm, write=SetForm};
	__property Gxs::Sceneviewer::TgxSceneViewer* GLXceneViewer = {read=FGLXceneViewer, write=SetGLXceneViewer};
	__property float ZoomSpeed = {read=FZoomSpeed, write=FZoomSpeed, stored=StoreZoomSpeed};
	__property float MoveAroundTargetSpeed = {read=FMoveAroundTargetSpeed, write=FMoveAroundTargetSpeed, stored=StoreMoveAroundTargetSpeed};
	__property float RotateTargetSpeed = {read=FRotateTargetSpeed, write=FRotateTargetSpeed, stored=StoreRotateTargetSpeed};
	__property System::UnicodeString FormCaption = {read=FFormCaption, write=FFormCaption, stored=StoreFormCaption};
	__property TgxSimpleNavigationOptions Options = {read=FOptions, write=SetOptions, default=192};
	__property TgxSimpleNavigationKeyCombinations* KeyCombinations = {read=FKeyCombinations, write=SetKeyCombinations};
	__property Fmx::Types::TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Simplenavigation */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SIMPLENAVIGATION)
using namespace Gxs::Simplenavigation;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SimpleNavigationHPP
