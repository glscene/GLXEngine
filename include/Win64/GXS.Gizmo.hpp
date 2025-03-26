// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Gizmo.pas' rev: 36.00 (Windows)

#ifndef GXS_GizmoHPP
#define GXS_GizmoHPP

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
#include <FMX.TextLayout.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Color.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Material.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.Selection.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Gizmo
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxGizmoUndoItem;
class DELPHICLASS TgxGizmoUndoCollection;
class DELPHICLASS TgxGizmoRayCastHitData;
class DELPHICLASS TgxGizmoPickCube;
class DELPHICLASS TgxGizmoPickTorus;
class DELPHICLASS TgxGizmo;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxGizmoUndoItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FOldLibMaterialName;
	Gxs::Coordinates::TgxCoordinates* FOldAutoScaling;
	Gxs::Scene::TgxCustomSceneObject* FEffectedObject;
	Stage::Vectortypes::TMatrix4f FOldMatr;
	Stage::Vectortypes::TMatrix4f FOldMatrix;
	void __fastcall SetEffectedObject(Gxs::Scene::TgxCustomSceneObject* const Value);
	void __fastcall SetOldAutoScaling(Gxs::Coordinates::TgxCoordinates* const Value);
	void __fastcall SetOldMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	
protected:
	virtual void __fastcall DoUndo();
	TgxGizmoUndoCollection* __fastcall GetParent();
	TgxGizmo* __fastcall GetGizmo();
	
public:
	__fastcall virtual TgxGizmoUndoItem(System::Classes::TCollection* AOwner);
	__fastcall virtual ~TgxGizmoUndoItem();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall AssignFromObject(Gxs::Scene::TgxCustomSceneObject* const AObject);
	__property Stage::Vectortypes::TMatrix4f OldMatrix = {read=FOldMatrix, write=SetOldMatrix};
	
__published:
	__property Gxs::Scene::TgxCustomSceneObject* EffectedObject = {read=FEffectedObject, write=SetEffectedObject};
	__property Gxs::Coordinates::TgxCoordinates* OldAutoScaling = {read=FOldAutoScaling, write=SetOldAutoScaling};
	__property System::UnicodeString OldLibMaterialName = {read=FOldLibMaterialName, write=FOldLibMaterialName};
};


class PASCALIMPLEMENTATION TgxGizmoUndoCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxGizmoUndoItem* operator[](const int Index) { return this->Items[Index]; }
	
private:
	TgxGizmoUndoItem* __fastcall GetItems(const int Index);
	void __fastcall SetItems(const int Index, TgxGizmoUndoItem* const Value);
	
protected:
	TgxGizmo* __fastcall GetParent();
	
public:
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RemoveByObject(Gxs::Scene::TgxCustomSceneObject* const AObject);
	HIDESBASE TgxGizmoUndoItem* __fastcall Add();
	__property TgxGizmoUndoItem* Items[const int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxGizmoUndoCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxGizmoUndoCollection() { }
	
};


enum DECLSPEC_DENUM TgxGizmoElement : unsigned char { geMove, geRotate, geScale, geAxisLabel, geObjectInfos, geBoundingBox };

typedef System::Set<TgxGizmoElement, TgxGizmoElement::geMove, TgxGizmoElement::geBoundingBox> TgxGizmoElements;

enum DECLSPEC_DENUM TgxGizmoVisibleInfoLabel : unsigned char { vliName, vliOperation, vliCoords };

typedef System::Set<TgxGizmoVisibleInfoLabel, TgxGizmoVisibleInfoLabel::vliName, TgxGizmoVisibleInfoLabel::vliCoords> TgxGizmoVisibleInfoLabels;

enum DECLSPEC_DENUM TgxGizmoAxis : unsigned char { gaNone, gaX, gaY, gaZ, gaXY, gaXZ, gaYZ };

enum DECLSPEC_DENUM TgxGizmoOperation : unsigned char { gopMove, gopRotate, gopScale, gopNone, gpMoveGizmo, gpRotateGizmo };

typedef void __fastcall (__closure *TgxGizmoAcceptEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* &Obj, bool &Accept, Stage::Vectortypes::TVector4f &Dimensions);

typedef void __fastcall (__closure *TgxGizmoUpdateEvent)(System::TObject* Sender, Gxs::Scene::TgxBaseSceneObject* Obj, TgxGizmoAxis Axis, TgxGizmoOperation Operation, Stage::Vectortypes::TVector4f &Vector);

enum DECLSPEC_DENUM TgxGizmoPickMode : unsigned char { pmGetPickedObjects, pmRayCast };

class PASCALIMPLEMENTATION TgxGizmoRayCastHitData : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	Gxs::Scene::TgxBaseSceneObject* Obj;
	Stage::Vectortypes::TVector4f Point;
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxGizmoRayCastHitData() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxGizmoRayCastHitData() : System::Classes::TPersistent() { }
	
};


class PASCALIMPLEMENTATION TgxGizmoPickCube : public Gxs::Objects::TgxCube
{
	typedef Gxs::Objects::TgxCube inherited;
	
public:
	/* TgxCube.Create */ inline __fastcall virtual TgxGizmoPickCube(System::Classes::TComponent* AOwner) : Gxs::Objects::TgxCube(AOwner) { }
	
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoPickCube() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoPickCube(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxCube(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoPickTorus : public Gxs::Geomobjects::TgxTorus
{
	typedef Gxs::Geomobjects::TgxTorus inherited;
	
public:
	/* TgxTorus.Create */ inline __fastcall virtual TgxGizmoPickTorus(System::Classes::TComponent* AOwner) : Gxs::Geomobjects::TgxTorus(AOwner) { }
	
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoPickTorus() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoPickTorus(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxTorus(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmo : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* _GZObaseGizmo;
	Gxs::Objects::TgxCube* _GZOBoundingcube;
	Gxs::Scene::TgxBaseSceneObject* _GZOrootHelpers;
	Gxs::Scene::TgxBaseSceneObject* _GZOrootLines;
	Gxs::Scene::TgxBaseSceneObject* _GZOrootTorus;
	Gxs::Scene::TgxBaseSceneObject* _GZOrootCubes;
	Gxs::Scene::TgxBaseSceneObject* _GZORootAxisLabel;
	Gxs::Scene::TgxBaseSceneObject* _GZORootVisibleInfoLabels;
	Gxs::Objects::TgxLines* _GZOlineX;
	Gxs::Objects::TgxLines* _GZOlineY;
	Gxs::Objects::TgxLines* _GZOlineZ;
	Gxs::Objects::TgxLines* _GZOplaneXY;
	Gxs::Objects::TgxLines* _GZOplaneXZ;
	Gxs::Objects::TgxLines* _GZOplaneYZ;
	TgxGizmoPickTorus* _GZOTorusX;
	TgxGizmoPickTorus* _GZOTorusY;
	TgxGizmoPickTorus* _GZOTorusZ;
	TgxGizmoPickCube* _GZOCubeX;
	TgxGizmoPickCube* _GZOCubeY;
	TgxGizmoPickCube* _GZOCubeZ;
	Gxs::Bitmapfont::TgxFlatText* _GZOAxisLabelX;
	Gxs::Bitmapfont::TgxFlatText* _GZOAxisLabelY;
	Gxs::Bitmapfont::TgxFlatText* _GZOAxisLabelZ;
	Gxs::Bitmapfont::TgxFlatText* _GZOVisibleInfoLabels;
	Gxs::Scene::TgxBaseSceneObject* FRootGizmo;
	Gxs::Scene::TgxBaseSceneObject* FSelectedObj;
	TgxGizmoOperation FOperation;
	TgxGizmoAxis FSelAxis;
	Gxs::Color::TgxColor* FBoundingBoxColor;
	Gxs::Color::TgxColor* FSelectedColor;
	Gxs::Color::TgxColor* FVisibleInfoLabelsColor;
	bool FBoundingBoxColorChanged;
	bool FVisibleInfoLabelsColorChanged;
	bool FForceOperation;
	bool FForceAxis;
	bool FForceUniformScale;
	bool FAutoZoom;
	bool FExcludeObjects;
	bool FNoZWrite;
	bool FEnabled;
	float FAutoZoomFactor;
	float FZoomFactor;
	float FMoveCoef;
	float FRotationCoef;
	Gxs::Sceneviewer::TgxSceneViewer* FViewer;
	TgxGizmoElements FGizmoElements;
	TgxGizmoVisibleInfoLabels FVisibleVisibleInfoLabels;
	System::Classes::TStrings* FExcludeObjectsList;
	bool Moving;
	int Mx;
	int My;
	int Rx;
	int Ry;
	Gxs::Scene::TgxDirectOpenGL* dglEnable;
	Gxs::Scene::TgxDirectOpenGL* dglDisable;
	Gxs::Scene::TgxDirectOpenGL* dgtEnable;
	Gxs::Scene::TgxDirectOpenGL* dgtDisable;
	Gxs::Scene::TgxDirectOpenGL* dgcEnable;
	Gxs::Scene::TgxDirectOpenGL* dgcDisable;
	Gxs::Scene::TgxDirectOpenGL* dglaEnable;
	Gxs::Scene::TgxDirectOpenGL* dglaDisable;
	Gxs::Scene::TgxDirectOpenGL* dgliEnable;
	Gxs::Scene::TgxDirectOpenGL* dgliDisable;
	Stage::Vectortypes::TVector4f LastMousePos;
	Stage::Vectortypes::TVector4f ObjDimensions;
	TgxGizmoAcceptEvent FOnBeforeSelect;
	TgxGizmoUpdateEvent FOnBeforeUpdate;
	System::Classes::TNotifyEvent FOnSelectionLost;
	float FScaleCoef;
	float FGizmoThickness;
	TgxGizmoPickMode FPickMode;
	System::Classes::TList* FInternalRaycastHitData;
	TgxGizmoUndoCollection* FUndoHistory;
	Gxs::Bitmapfont::TgxCustomBitmapFont* FLabelFont;
	void __fastcall SetRootGizmo(Gxs::Scene::TgxBaseSceneObject* const AValue);
	void __fastcall SetGizmoElements(const TgxGizmoElements AValue);
	void __fastcall SetGizmoVisibleInfoLabels(const TgxGizmoVisibleInfoLabels AValue);
	void __fastcall SetBoundingBoxColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetSelectedColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetVisibleInfoLabelsColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetExcludeObjectsList(System::Classes::TStrings* const AValue);
	void __fastcall DirectGLDisable(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &Rci);
	void __fastcall DirectGLEnable(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &Rci);
	Stage::Vectortypes::TVector4f __fastcall MouseWorldPos(const int X, const int Y);
	bool __fastcall CheckObjectInExcludeList(Gxs::Scene::TgxBaseSceneObject* const Obj);
	void __fastcall UpdateVisibleInfoLabels();
	void __fastcall SetGizmoThickness(const float Value);
	Gxs::Selection::TgxPickList* __fastcall InternalGetPickedObjects(const int X1, const int Y1, const int X2, const int Y2, const int GuessCount = 0x8);
	void __fastcall ClearInternalRaycastHitData();
	void __fastcall SetViewer(Gxs::Sceneviewer::TgxSceneViewer* const Value);
	void __fastcall SetLabelFont(Gxs::Bitmapfont::TgxCustomBitmapFont* const Value);
	void __fastcall SetSelectedObj(Gxs::Scene::TgxBaseSceneObject* const Value);
	
public:
	System::Classes::TList* PickableObjectsWithRayCast;
	__fastcall virtual TgxGizmo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxGizmo();
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ViewerMouseMove(const int X, const int Y);
	void __fastcall ViewerMouseDown(const int X, const int Y);
	void __fastcall ViewerMouseUp(const int X, const int Y);
	void __fastcall UpdateGizmo()/* overload */;
	void __fastcall UpdateGizmo(const Stage::Vectortypes::TVector4f &NewDimensions)/* overload */;
	void __fastcall SetVisible(const bool AValue);
	Stage::Vectortypes::TVector4f __fastcall GetPickedObjectPoint(Gxs::Scene::TgxBaseSceneObject* const Obj);
	virtual void __fastcall LooseSelection();
	void __fastcall UndoAdd(Gxs::Scene::TgxCustomSceneObject* const AObject);
	__property Gxs::Scene::TgxBaseSceneObject* RootGizmo = {read=FRootGizmo, write=SetRootGizmo};
	
__published:
	__property Gxs::Sceneviewer::TgxSceneViewer* Viewer = {read=FViewer, write=SetViewer};
	__property TgxGizmoElements GizmoElements = {read=FGizmoElements, write=SetGizmoElements, nodefault};
	__property Gxs::Color::TgxColor* BoundingBoxColor = {read=FBoundingBoxColor, write=SetBoundingBoxColor};
	__property Gxs::Color::TgxColor* SelectedColor = {read=FSelectedColor, write=SetSelectedColor};
	__property TgxGizmoAxis SelAxis = {read=FSelAxis, write=FSelAxis, nodefault};
	__property bool ForceAxis = {read=FForceAxis, write=FForceAxis, nodefault};
	__property Gxs::Scene::TgxBaseSceneObject* SelectedObj = {read=FSelectedObj, write=SetSelectedObj};
	__property TgxGizmoOperation Operation = {read=FOperation, write=FOperation, nodefault};
	__property bool ForceOperation = {read=FForceOperation, write=FForceOperation, nodefault};
	__property bool ForceUniformScale = {read=FForceUniformScale, write=FForceUniformScale, nodefault};
	__property bool ExcludeObjects = {read=FExcludeObjects, write=FExcludeObjects, nodefault};
	__property System::Classes::TStrings* ExcludeObjectsList = {read=FExcludeObjectsList, write=SetExcludeObjectsList};
	__property TgxGizmoVisibleInfoLabels VisibleInfoLabels = {read=FVisibleVisibleInfoLabels, write=SetGizmoVisibleInfoLabels, nodefault};
	__property Gxs::Color::TgxColor* VisibleInfoLabelsColor = {read=FVisibleInfoLabelsColor, write=SetVisibleInfoLabelsColor};
	__property bool AutoZoom = {read=FAutoZoom, write=FAutoZoom, nodefault};
	__property float AutoZoomFactor = {read=FAutoZoomFactor, write=FAutoZoomFactor};
	__property float ZoomFactor = {read=FZoomFactor, write=FZoomFactor};
	__property float MoveCoef = {read=FMoveCoef, write=FMoveCoef};
	__property float RotationCoef = {read=FRotationCoef, write=FRotationCoef};
	__property float ScaleCoef = {read=FScaleCoef, write=FScaleCoef};
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
	__property float GizmoThickness = {read=FGizmoThickness, write=SetGizmoThickness};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=0};
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* LabelFont = {read=FLabelFont, write=SetLabelFont, default=0};
	__property TgxGizmoAcceptEvent OnBeforeSelect = {read=FOnBeforeSelect, write=FOnBeforeSelect};
	__property System::Classes::TNotifyEvent OnSelectionLost = {read=FOnSelectionLost, write=FOnSelectionLost};
	__property TgxGizmoUpdateEvent OnBeforeUpdate = {read=FOnBeforeUpdate, write=FOnBeforeUpdate};
	__property TgxGizmoPickMode PickMode = {read=FPickMode, write=FPickMode, default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gizmo */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GIZMO)
using namespace Gxs::Gizmo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GizmoHPP
