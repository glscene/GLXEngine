// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.GizmoEx.pas' rev: 36.00 (Windows)

#ifndef GXS_GizmoExHPP
#define GXS_GizmoExHPP

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
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <FMX.TextLayout.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Strings.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Color.hpp>
#include <GXS.Material.hpp>
#include <GXS.Objects.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Canvas.hpp>
#include <GXS.Screen.hpp>
#include <GXS.State.hpp>
#include <GXS.Selection.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Gizmoex
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxGizmoExObjectItem;
class DELPHICLASS TgxGizmoExObjectCollection;
class DELPHICLASS TgxGizmoExActionHistoryItem;
class DELPHICLASS TgxGizmoExActionHistoryCollection;
class DELPHICLASS TgxGizmoExUIFrustrum;
class DELPHICLASS TgxGizmoExUISphere;
class DELPHICLASS TgxGizmoExUIDisk;
class DELPHICLASS TgxGizmoExUITorus;
class DELPHICLASS TgxGizmoExUIPolygon;
class DELPHICLASS TgxGizmoExUIArrowLine;
class DELPHICLASS TgxGizmoExUILines;
class DELPHICLASS TgxGizmoExUIFlatText;
class DELPHICLASS TgxGizmoEx;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxGizmoExObjectItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Stage::Vectortypes::TVector4f FOldAutoScaling;
	Gxs::Scene::TgxBaseSceneObject* FEffectedObject;
	Gxs::Scene::TgxBaseSceneObject* FParentOldObject;
	int FIndexOldObject;
	System::UnicodeString FNameOldObject;
	bool FReturnObject;
	Stage::Vectortypes::TMatrix4f FOldMatrix;
	Gxs::Scene::TgxBaseSceneObject* FGizmoTmpRoot;
	void __fastcall SetEffectedObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetOldMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	
protected:
	void __fastcall DoUndo();
	TgxGizmoExObjectCollection* __fastcall GetParent();
	TgxGizmoEx* __fastcall GetGizmo();
	
public:
	__property Gxs::Scene::TgxBaseSceneObject* GizmoTmpRoot = {read=FGizmoTmpRoot, write=FGizmoTmpRoot};
	__fastcall virtual TgxGizmoExObjectItem(System::Classes::TCollection* AOwner);
	__fastcall virtual ~TgxGizmoExObjectItem();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall AssignFromObject(Gxs::Scene::TgxBaseSceneObject* const AObject, bool AssignAndRemoveObj = false);
	__property Stage::Vectortypes::TMatrix4f OldMatrix = {read=FOldMatrix, write=SetOldMatrix};
	
__published:
	__property Gxs::Scene::TgxBaseSceneObject* EffectedObject = {read=FEffectedObject, write=SetEffectedObject};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxGizmoExObjectCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxGizmoExObjectItem* operator[](const int Index) { return this->Items[Index]; }
	
private:
	TgxGizmoExObjectItem* __fastcall GetItems(const int Index);
	void __fastcall SetItems(const int Index, TgxGizmoExObjectItem* const Value);
	
protected:
	TgxGizmoEx* __fastcall GetParent();
	void __fastcall DoUndo();
	
public:
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RemoveByObject(Gxs::Scene::TgxCustomSceneObject* const AObject);
	HIDESBASE TgxGizmoExObjectItem* __fastcall Add();
	__property TgxGizmoExObjectItem* Items[const int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TgxGizmoExObjectCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxGizmoExObjectCollection() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxGizmoExActionHistoryItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::TObject* FObject;
	TgxGizmoExObjectCollection* FGizmoObjectCollection;
	void __fastcall SetObject(System::TObject* aValue);
	void __fastcall SetGizmoObjectCollection(TgxGizmoExObjectCollection* aValue);
	
public:
	__fastcall virtual TgxGizmoExActionHistoryItem(System::Classes::TCollection* AOwner);
	__fastcall virtual ~TgxGizmoExActionHistoryItem();
	__property System::TObject* BaseObject = {read=FObject, write=SetObject};
	__property TgxGizmoExObjectCollection* GizmoObjectCollection = {read=FGizmoObjectCollection, write=SetGizmoObjectCollection};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxGizmoExActionHistoryCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxGizmoExActionHistoryItem* operator[](const int Index) { return this->Items[Index]; }
	
private:
	int FItemIndex;
	int FItemsMaxCount;
	Gxs::Scene::TgxBaseSceneObject* FGizmoTmpRoot;
	TgxGizmoExActionHistoryItem* __fastcall GetItems(const int Index);
	void __fastcall SetItems(const int Index, TgxGizmoExActionHistoryItem* const Value);
	HIDESBASE TgxGizmoExActionHistoryItem* __fastcall Add();
	
public:
	__fastcall TgxGizmoExActionHistoryCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property int ItemIndex = {read=FItemIndex, write=FItemIndex, nodefault};
	TgxGizmoExActionHistoryItem* __fastcall Undo();
	TgxGizmoExActionHistoryItem* __fastcall Redo();
	void __fastcall AddObjects(Gxs::Selection::TgxPickList* objs);
	void __fastcall AddObject(System::TObject* obj);
	void __fastcall RemoveObjects(Gxs::Selection::TgxPickList* objs);
	__property int MaxCount = {read=FItemsMaxCount, write=FItemsMaxCount, nodefault};
	__property TgxGizmoExActionHistoryItem* Items[const int Index] = {read=GetItems, write=SetItems/*, default*/};
	__property Gxs::Scene::TgxBaseSceneObject* GizmoTmpRoot = {read=FGizmoTmpRoot, write=FGizmoTmpRoot};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxGizmoExActionHistoryCollection() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TgxGizmoExVisibleInfoLabel : unsigned char { vliName, vliOperation, vliCoords };

typedef System::Set<TgxGizmoExVisibleInfoLabel, TgxGizmoExVisibleInfoLabel::vliName, TgxGizmoExVisibleInfoLabel::vliCoords> TgxGizmoExVisibleInfoLabels;

enum DECLSPEC_DENUM TInfoLabelCoordType : unsigned char { ilcChanging, ilcChangeRate };

enum DECLSPEC_DENUM TgxGizmoExAxis : unsigned char { gaNone, gaX, gaY, gaZ, gaXY, gaXZ, gaYZ, gaXYZ };

enum DECLSPEC_DENUM TgxGizmoExSelectionRegion : unsigned char { gsrRectangular, gsrCircular, gsrFence, gsrLasso };

enum DECLSPEC_DENUM TgxGizmoExReferenceCoordinateSystem : unsigned char { rcsView, rcsLocal };

typedef System::DynamicArray<System::Types::TPoint> TgxGizmoExSelRec;

enum DECLSPEC_DENUM TgxGizmoExOperation : unsigned char { gopMove, gopRotate, gopScale, gopNone };

enum DECLSPEC_DENUM TgxGizmoExOperationMode : unsigned char { gomNone, gomSelect, gomMove, gomRotate, gomScale };

typedef void __fastcall (__closure *TgxGizmoExAcceptEvent)(System::TObject* Sender, Gxs::Selection::TgxPickList* &objs);

typedef void __fastcall (__closure *TgxGizmoExAxisSelected)(System::TObject* Sender, TgxGizmoExAxis &Axis);

enum DECLSPEC_DENUM TgxGizmoExPickMode : unsigned char { pmGetPickedObjects, pmRayCast };

class PASCALIMPLEMENTATION TgxGizmoExUIFrustrum : public Gxs::Geomobjects::TgxFrustrum
{
	typedef Gxs::Geomobjects::TgxFrustrum inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUIFrustrum(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoExUIFrustrum() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUIFrustrum(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxFrustrum(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUISphere : public Gxs::Objects::TgxSphere
{
	typedef Gxs::Objects::TgxSphere inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUISphere(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoExUISphere() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUISphere(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxSphere(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUIDisk : public Gxs::Geomobjects::TgxDisk
{
	typedef Gxs::Geomobjects::TgxDisk inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUIDisk(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoExUIDisk() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUIDisk(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxDisk(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUITorus : public Gxs::Geomobjects::TgxTorus
{
	typedef Gxs::Geomobjects::TgxTorus inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUITorus(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoExUITorus() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUITorus(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxTorus(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUIPolygon : public Gxs::Geomobjects::TgxPolygon
{
	typedef Gxs::Geomobjects::TgxPolygon inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUIPolygon(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxPolygon.Destroy */ inline __fastcall virtual ~TgxGizmoExUIPolygon() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUIPolygon(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxPolygon(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUIArrowLine : public Gxs::Geomobjects::TgxArrowLine
{
	typedef Gxs::Geomobjects::TgxArrowLine inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUIArrowLine(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxGizmoExUIArrowLine() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUIArrowLine(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Geomobjects::TgxArrowLine(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUILines : public Gxs::Objects::TgxLines
{
	typedef Gxs::Objects::TgxLines inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUILines(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxLines.Destroy */ inline __fastcall virtual ~TgxGizmoExUILines() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUILines(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxLines(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoExUIFlatText : public Gxs::Bitmapfont::TgxFlatText
{
	typedef Gxs::Bitmapfont::TgxFlatText inherited;
	
private:
	bool FNoZWrite;
	
public:
	__fastcall virtual TgxGizmoExUIFlatText(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property bool NoZWrite = {read=FNoZWrite, write=FNoZWrite, nodefault};
public:
	/* TgxFlatText.Destroy */ inline __fastcall virtual ~TgxGizmoExUIFlatText() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxGizmoExUIFlatText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Bitmapfont::TgxFlatText(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxGizmoEx : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Gxs::Scene::TgxBaseSceneObject* FUIBaseGizmo;
	Gxs::Scene::TgxBaseSceneObject* FUIRootHelpers;
	Gxs::Scene::TgxBaseSceneObject* FUIRootSelect;
	Gxs::Scene::TgxBaseSceneObject* FUIRootMovement;
	Gxs::Scene::TgxBaseSceneObject* FUIRootRotate;
	Gxs::Scene::TgxBaseSceneObject* FUIRootRotateAxisLabel;
	Gxs::Scene::TgxBaseSceneObject* FUIRootScale;
	Gxs::Scene::TgxBaseSceneObject* FUIRootAxisLabel;
	Gxs::Scene::TgxBaseSceneObject* FUIRootVisibleInfoLabels;
	Gxs::Scene::TgxDirectOpenGL* FInterfaceRender;
	Gxs::Scene::TgxDirectOpenGL* FInternalRender;
	TgxGizmoExUILines* FUISelectLineX;
	TgxGizmoExUILines* FUISelectLineY;
	TgxGizmoExUILines* FUISelectLineZ;
	TgxGizmoExUIFrustrum* FUIICMovementLineX;
	TgxGizmoExUIFrustrum* FUIICMovementLineY;
	TgxGizmoExUIFrustrum* FUIICMovementLineZ;
	TgxGizmoExUIFrustrum* FUIICMovementLineXY;
	TgxGizmoExUIFrustrum* FUIICMovementLineXZ;
	TgxGizmoExUIFrustrum* FUIICMovementLineYZ;
	TgxGizmoExUIArrowLine* FUIMovementArrowX;
	TgxGizmoExUIArrowLine* FUIMovementArrowY;
	TgxGizmoExUIArrowLine* FUIMovementArrowZ;
	TgxGizmoExUILines* FUIMovementLineX;
	TgxGizmoExUILines* FUIMovementLineY;
	TgxGizmoExUILines* FUIMovementLineZ;
	TgxGizmoExUILines* FUIMovementLineXY;
	TgxGizmoExUILines* FUIMovementLineXZ;
	TgxGizmoExUILines* FUIMovementLineYZ;
	TgxGizmoExUIPolygon* FUIMovementPlaneXY;
	TgxGizmoExUIPolygon* FUIMovementPlaneXZ;
	TgxGizmoExUIPolygon* FUIMovementPlaneYZ;
	TgxGizmoExUILines* FUIRotateLineX;
	TgxGizmoExUILines* FUIRotateLineY;
	TgxGizmoExUILines* FUIRotateLineZ;
	TgxGizmoExUILines* FUIRotateLineXY;
	TgxGizmoExUILines* FUIRotateLineXZ;
	TgxGizmoExUITorus* FUIICRotateTorusX;
	TgxGizmoExUITorus* FUIICRotateTorusY;
	TgxGizmoExUITorus* FUIICRotateTorusZ;
	TgxGizmoExUITorus* FUIICRotateTorusXZ;
	TgxGizmoExUIDisk* FUIRotateDiskXY;
	TgxGizmoExUIDisk* FUIRotateDiskX;
	TgxGizmoExUIDisk* FUIRotateDiskX2;
	TgxGizmoExUIDisk* FUIRotateDiskY;
	TgxGizmoExUIDisk* FUIRotateDiskY2;
	TgxGizmoExUIDisk* FUIRotateDiskZ;
	TgxGizmoExUIDisk* FUIRotateDiskZ2;
	TgxGizmoExUILines* FUIRotateLineArrowX;
	TgxGizmoExUILines* FUIRotateLineArrowY;
	TgxGizmoExUILines* FUIRotateLineArrowZ;
	TgxGizmoExUISphere* FUIICRotateSphereXY;
	TgxGizmoExUIFlatText* FUIRotateAxisLabelX;
	TgxGizmoExUIFlatText* FUIRotateAxisLabelY;
	TgxGizmoExUIFlatText* FUIRotateAxisLabelZ;
	TgxGizmoExUISphere* FUIScaleArrowX;
	TgxGizmoExUISphere* FUIScaleArrowY;
	TgxGizmoExUISphere* FUIScaleArrowZ;
	TgxGizmoExUILines* FUIScaleLineX;
	TgxGizmoExUILines* FUIScaleLineY;
	TgxGizmoExUILines* FUIScaleLineZ;
	TgxGizmoExUILines* FUIScaleLineXY;
	TgxGizmoExUILines* FUIScaleLineYZ;
	TgxGizmoExUILines* FUIScaleLineXZ;
	TgxGizmoExUIFrustrum* FUIICScaleLineX;
	TgxGizmoExUIFrustrum* FUIICScaleLineY;
	TgxGizmoExUIFrustrum* FUIICScaleLineZ;
	TgxGizmoExUIFrustrum* FUIICScaleLineXY;
	TgxGizmoExUIFrustrum* FUIICScaleLineXZ;
	TgxGizmoExUIFrustrum* FUIICScaleLineYZ;
	TgxGizmoExUIFrustrum* FUIICScaleLineXYZ;
	TgxGizmoExUIPolygon* FUIScalePlaneXY;
	TgxGizmoExUIPolygon* FUIScalePlaneXZ;
	TgxGizmoExUIPolygon* FUIScalePlaneYZ;
	TgxGizmoExUIPolygon* FUIScalePlaneXYZ;
	TgxGizmoExUIFlatText* FUIAxisLabelX;
	TgxGizmoExUIFlatText* FUIAxisLabelY;
	TgxGizmoExUIFlatText* FUIAxisLabelZ;
	TgxGizmoExUIFlatText* FUIVisibleInfoLabels;
	Gxs::Scene::TgxBaseSceneObject* FRootGizmo;
	Gxs::Scene::TgxBaseSceneObject* FRootObjects;
	Gxs::Scene::TgxBaseSceneObject* FGizmoTmpRoot;
	Gxs::Scene::TgxBaseSceneObject* FSelectedObj;
	TgxGizmoExOperation FOperation;
	TgxGizmoExOperationMode FOperationMode;
	TgxGizmoExAxis FSelAxis;
	TInfoLabelCoordType fInfoLabelCoordType;
	TgxGizmoExReferenceCoordinateSystem FReferenceCoordSystem;
	Gxs::Color::TgxColor* FBoundingBoxColor;
	Gxs::Color::TgxColor* FSelectedColor;
	Gxs::Color::TgxColor* FVisibleInfoLabelsColor;
	Gxs::Color::TgxColor* FSelectionRegionColor;
	bool FVisibleInfoLabelsColorChanged;
	bool FAutoZoom;
	bool FExcludeObjects;
	bool FExcludeClassname;
	bool FNoZWrite;
	bool FEnabled;
	float FAutoZoomFactor;
	float FZoomFactor;
	float FMoveCoef;
	float FRotationCoef;
	Gxs::Sceneviewer::TgxSceneViewer* FViewer;
	TgxGizmoExVisibleInfoLabels FVisibleVisibleInfoLabels;
	System::Classes::TStrings* FExcludeObjectsList;
	System::Classes::TStrings* FExcludeClassNameList;
	TgxGizmoExSelectionRegion FSelectionRegion;
	bool FEnableMultiSelection;
	bool FShowMultiSelecting;
	TgxGizmoExSelRec FSelectionRec;
	bool FCanAddObjToSelectionList;
	bool FCanRemoveObjFromSelectionList;
	Gxs::Selection::TgxPickList* FSelectedObjects;
	bool FAntiAliasedLines;
	bool FShowAxisLabel;
	bool FShowObjectInfos;
	bool FShowBoundingBox;
	bool FCanChangeWithChildren;
	bool moving;
	int mx;
	int my;
	System::Types::TPoint fCursorPos;
	System::Types::TPoint fLastCursorPos;
	Stage::Vectorgeometry::TAffineVector fChangeRate;
	bool FEnableLoopCursorMoving;
	Stage::Vectortypes::TVector4f lastMousePos;
	System::Classes::TNotifyEvent FOnUpdate;
	TgxGizmoExAcceptEvent FOnSelect;
	System::Classes::TNotifyEvent FOnOperationChange;
	System::Classes::TNotifyEvent FOnOperationModeChange;
	System::Classes::TNotifyEvent FOnSelectionLost;
	TgxGizmoExAxisSelected FOnAxisSelected;
	float FScaleCoef;
	float FGizmoThickness;
	TgxGizmoExPickMode FPickMode;
	bool FEnableHistory;
	TgxGizmoExActionHistoryCollection* FHistory;
	int FHistoryStepsCount;
	Gxs::Bitmapfont::TgxCustomBitmapFont* FLabelFont;
	void __fastcall SetRootGizmo(Gxs::Scene::TgxBaseSceneObject* const AValue);
	void __fastcall SetRootObjects(Gxs::Scene::TgxBaseSceneObject* const AValue);
	void __fastcall SetGizmoTmpRoot(Gxs::Scene::TgxBaseSceneObject* const AValue);
	void __fastcall SetGizmoExVisibleInfoLabels(const TgxGizmoExVisibleInfoLabels AValue);
	void __fastcall SetBoundingBoxColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetSelectedColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetVisibleInfoLabelsColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetSelectionRegionColor(Gxs::Color::TgxColor* const AValue);
	void __fastcall SetCanChangeWithChildren(bool AValue);
	void __fastcall SetAALines(bool aValue);
	void __fastcall SetInfoLabelCoordType(TInfoLabelCoordType aValue);
	void __fastcall SetReferenceCoordSystem(TgxGizmoExReferenceCoordinateSystem aValue);
	void __fastcall SetHistoryStepsCount(int aValue);
	void __fastcall SetExcludeObjectsList(System::Classes::TStrings* const AValue);
	void __fastcall SetExcludeClassNameList(System::Classes::TStrings* const AValue);
	Stage::Vectortypes::TVector4f __fastcall MouseWorldPos(const int X, const int Y);
	bool __fastcall CheckObjectInExcludeList(Gxs::Scene::TgxBaseSceneObject* const Obj);
	bool __fastcall CheckClassNameInExcludeList(Gxs::Scene::TgxBaseSceneObject* const Obj);
	void __fastcall UpdateVisibleInfoLabels();
	void __fastcall SetGizmoExThickness(const float Value);
	void __fastcall ActivatingElements(Gxs::Selection::TgxPickList* PickList);
	void __fastcall InterfaceRender(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall InternalRender(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	Gxs::Selection::TgxPickList* __fastcall InternalGetPickedObjects(const int x1, const int y1, const int x2, const int y2, const int guessCount = 0x8);
	void __fastcall SetViewer(Gxs::Sceneviewer::TgxSceneViewer* const Value);
	void __fastcall SetLabelFont(Gxs::Bitmapfont::TgxCustomBitmapFont* const Value);
	void __fastcall SetSelectedObj(Gxs::Scene::TgxBaseSceneObject* const Value);
	Gxs::Scene::TgxBaseSceneObject* __fastcall GetSelectedObj();
	void __fastcall SetNoZWrite(const bool Value);
	void __fastcall SetOperation(const TgxGizmoExOperation Value);
	void __fastcall SetOperationMode(const TgxGizmoExOperationMode Value);
	void __fastcall SetAngleDisk(float aAngle);
	void __fastcall SetEnableLoopCursorMoving(const bool AValue);
	void __fastcall SetEnableMultiSelection(const bool AValue);
	void __fastcall SetSelectionRegion(const TgxGizmoExSelectionRegion AValue);
	void __fastcall SetShowAxisLabel(const bool AValue);
	void __fastcall SetShowObjectInfos(const bool AValue);
	void __fastcall SetShowBoundingBox(const bool AValue);
	void __fastcall SetAutoZoomFactor(const float AValue);
	void __fastcall SetZoomFactor(const float AValue);
	void __fastcall SetSelAxis(TgxGizmoExAxis aValue);
	void __fastcall SetPickMode(TgxGizmoExPickMode APickMode);
	void __fastcall AssignPickList(Gxs::Selection::TgxPickList* aList, bool RemoveObj = false);
	void __fastcall AddObjToSelectionList(Gxs::Scene::TgxBaseSceneObject* Obj);
	void __fastcall RemoveObjFromSelectionList(Gxs::Scene::TgxBaseSceneObject* Obj);
	void __fastcall MultiSelMouseDown(int X, int Y);
	void __fastcall MultiSelMouseUp(int X, int Y);
	void __fastcall MultiSelMouseMove(int X, int Y);
	Gxs::Selection::TgxPickList* __fastcall GetPickList();
	void __fastcall SetPickList(Gxs::Selection::TgxPickList* aValue);
	__property TgxGizmoExAxis SelAxis = {read=FSelAxis, write=SetSelAxis, nodefault};
	__property TgxGizmoExOperation Operation = {read=FOperation, write=SetOperation, nodefault};
	void __fastcall ClearSelection();
	void __fastcall SetVisible(const bool AValue);
	bool __fastcall GetVisible();
	
public:
	__fastcall virtual TgxGizmoEx(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxGizmoEx();
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ViewerMouseMove(const int X, const int Y);
	void __fastcall ViewerMouseDown(const int X, const int Y);
	void __fastcall ViewerMouseUp(const int X, const int Y);
	void __fastcall UpdateGizmo()/* overload */;
	virtual void __fastcall LooseSelection();
	void __fastcall UndoAdd(System::TObject* const AObject);
	void __fastcall RemoveSelectedObjects();
	TgxGizmoExActionHistoryItem* __fastcall Undo();
	TgxGizmoExActionHistoryItem* __fastcall Redo();
	__property bool CanAddObjToSelectionList = {read=FCanAddObjToSelectionList, write=FCanAddObjToSelectionList, nodefault};
	__property bool CanRemoveObjFromSelectionList = {read=FCanRemoveObjFromSelectionList, write=FCanRemoveObjFromSelectionList, nodefault};
	void __fastcall LooseCursorSelection();
	__property bool CursorSelectingRegion = {read=FShowMultiSelecting, nodefault};
	__property Gxs::Scene::TgxBaseSceneObject* RootObjects = {read=FRootObjects, write=SetRootObjects};
	__property Gxs::Scene::TgxBaseSceneObject* RootGizmo = {read=FRootGizmo, write=SetRootGizmo};
	__property Gxs::Scene::TgxBaseSceneObject* GizmoTmpRoot = {read=FGizmoTmpRoot, write=SetGizmoTmpRoot};
	
__published:
	__property Gxs::Sceneviewer::TgxSceneViewer* Viewer = {read=FViewer, write=SetViewer};
	__property Gxs::Color::TgxColor* BoundingBoxColor = {read=FBoundingBoxColor, write=SetBoundingBoxColor};
	__property Gxs::Color::TgxColor* SelectedColor = {read=FSelectedColor, write=SetSelectedColor};
	__property Gxs::Color::TgxColor* SelectionRegionColor = {read=FSelectionRegionColor, write=SetSelectionRegionColor};
	__property Gxs::Scene::TgxBaseSceneObject* SelectedObj = {read=GetSelectedObj, write=SetSelectedObj};
	__property Gxs::Selection::TgxPickList* SelectedObjects = {read=GetPickList, write=SetPickList};
	__property TgxGizmoExOperationMode OperationMode = {read=FOperationMode, write=SetOperationMode, default=1};
	__property bool ExcludeObjects = {read=FExcludeObjects, write=FExcludeObjects, nodefault};
	__property System::Classes::TStrings* ExcludeObjectsList = {read=FExcludeObjectsList, write=SetExcludeObjectsList};
	__property bool ExcludeClassname = {read=FExcludeClassname, write=FExcludeClassname, nodefault};
	__property System::Classes::TStrings* ExcludeClassnameList = {read=FExcludeClassNameList, write=SetExcludeClassNameList};
	__property TgxGizmoExVisibleInfoLabels VisibleInfoLabels = {read=FVisibleVisibleInfoLabels, write=SetGizmoExVisibleInfoLabels, nodefault};
	__property Gxs::Color::TgxColor* VisibleInfoLabelsColor = {read=FVisibleInfoLabelsColor, write=SetVisibleInfoLabelsColor};
	__property bool AutoZoom = {read=FAutoZoom, write=FAutoZoom, default=1};
	__property float AutoZoomFactor = {read=FAutoZoomFactor, write=SetAutoZoomFactor};
	__property float ZoomFactor = {read=FZoomFactor, write=SetZoomFactor};
	__property float MoveCoef = {read=FMoveCoef, write=FMoveCoef};
	__property float RotationCoef = {read=FRotationCoef, write=FRotationCoef};
	__property float ScaleCoef = {read=FScaleCoef, write=FScaleCoef};
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, default=1};
	__property float GizmoThickness = {read=FGizmoThickness, write=SetGizmoExThickness};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property Gxs::Bitmapfont::TgxCustomBitmapFont* LabelFont = {read=FLabelFont, write=SetLabelFont, default=0};
	__property System::Classes::TNotifyEvent OnSelectionLost = {read=FOnSelectionLost, write=FOnSelectionLost};
	__property System::Classes::TNotifyEvent OnOperationChange = {read=FOnOperationChange, write=FOnOperationChange};
	__property System::Classes::TNotifyEvent OnOperationModeChange = {read=FOnOperationModeChange, write=FOnOperationModeChange};
	__property TgxGizmoExAcceptEvent OnSelect = {read=FOnSelect, write=FOnSelect};
	__property TgxGizmoExAxisSelected OnAxisSelected = {read=FOnAxisSelected, write=FOnAxisSelected};
	__property System::Classes::TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	__property TgxGizmoExPickMode PickMode = {read=FPickMode, write=SetPickMode, default=0};
	__property bool EnableActionHistory = {read=FEnableHistory, write=FEnableHistory, default=1};
	__property int HistoryStepsCount = {read=FHistoryStepsCount, write=SetHistoryStepsCount, nodefault};
	__property bool EnableLoopCursorMoving = {read=FEnableLoopCursorMoving, write=SetEnableLoopCursorMoving, default=1};
	__property bool EnableMultiSelection = {read=FEnableMultiSelection, write=SetEnableMultiSelection, default=1};
	__property bool CanChangeWithChildren = {read=FCanChangeWithChildren, write=SetCanChangeWithChildren, nodefault};
	__property bool AntiAliasedLines = {read=FAntiAliasedLines, write=SetAALines, default=1};
	__property TInfoLabelCoordType InfoLabelCoordType = {read=fInfoLabelCoordType, write=SetInfoLabelCoordType, default=1};
	__property TgxGizmoExSelectionRegion SelectionRegion = {read=FSelectionRegion, write=SetSelectionRegion, default=0};
	__property bool ShowAxisLabel = {read=FShowAxisLabel, write=SetShowAxisLabel, default=1};
	__property bool ShowObjectInfos = {read=FShowObjectInfos, write=SetShowObjectInfos, default=1};
	__property bool ShowBoundingBox = {read=FShowBoundingBox, write=SetShowBoundingBox, default=1};
	__property TgxGizmoExReferenceCoordinateSystem ReferenceCoordSystem = {read=FReferenceCoordSystem, write=SetReferenceCoordSystem, default=0};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gizmoex */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GIZMOEX)
using namespace Gxs::Gizmoex;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GizmoExHPP
