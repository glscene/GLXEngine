// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Scene.pas' rev: 36.00 (Windows)

#ifndef GXS_SceneHPP
#define GXS_SceneHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.UITypes.hpp>
#include <System.Math.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Strings.hpp>
#include <Stage.Utils.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Color.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Context.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.State.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Texture.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.Selection.hpp>
#include <GXS.ImageUtils.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Scene
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IgxInitializable;
typedef System::DelphiInterface<IgxInitializable> _di_IgxInitializable;
class DELPHICLASS TgxInitializableObjectList;
class DELPHICLASS TgxBaseSceneObject;
class DELPHICLASS TgxBaseBehaviour;
class DELPHICLASS TgxBehaviour;
class DELPHICLASS TgxBehaviours;
class DELPHICLASS TgxEffect;
class DELPHICLASS TgxObjectPreEffect;
class DELPHICLASS TgxObjectPostEffect;
class DELPHICLASS TgxObjectAfterEffect;
class DELPHICLASS TgxEffects;
class DELPHICLASS TgxCustomSceneObject;
class DELPHICLASS TgxSceneRootObject;
class DELPHICLASS TgxImmaterialSceneObject;
class DELPHICLASS TgxCameraInvariantObject;
class DELPHICLASS TgxSceneObject;
class DELPHICLASS TgxDirectOpenGL;
class DELPHICLASS TgxRenderPoint;
class DELPHICLASS TgxProxyObject;
class DELPHICLASS TgxLightSource;
class DELPHICLASS TgxCamera;
class DELPHICLASS TgxScene;
class DELPHICLASS TgxFogEnvironment;
class DELPHICLASS TgxSceneBuffer;
class DELPHICLASS TgxNonVisualViewer;
class DELPHICLASS TgxMemoryViewer;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxProxyObjectOption : unsigned char { pooEffects, pooObjects, pooTransformation };

typedef System::Set<TgxProxyObjectOption, TgxProxyObjectOption::pooEffects, TgxProxyObjectOption::pooTransformation> TgxProxyObjectOptions;

enum DECLSPEC_DENUM TgxCameraInvarianceMode : unsigned char { cimNone, cimPosition, cimOrientation };

enum DECLSPEC_DENUM TgxSceneViewerMode : unsigned char { svmDisabled, svmDefault, svmNavigation, svmGizmo };

enum DECLSPEC_DENUM TgxNormalDirection : unsigned char { ndInside, ndOutside };

enum DECLSPEC_DENUM TgxObjectChange : unsigned char { ocTransformation, ocAbsoluteMatrix, ocInvAbsoluteMatrix, ocStructure };

typedef System::Set<TgxObjectChange, TgxObjectChange::ocTransformation, TgxObjectChange::ocStructure> TgxObjectChanges;

enum DECLSPEC_DENUM TgxObjectBBChange : unsigned char { oBBcChild, oBBcStructure };

typedef System::Set<TgxObjectBBChange, TgxObjectBBChange::oBBcChild, TgxObjectBBChange::oBBcStructure> TgxObjectBBChanges;

enum DECLSPEC_DENUM TgxSceneOperation : unsigned char { soAdd, soRemove, soMove, soRename, soSelect, soBeginUpdate, soEndUpdate };

enum DECLSPEC_DENUM TgxContextOption : unsigned char { roSoftwareMode, roDoubleBuffer, roStencilBuffer, roRenderToWindow, roTwoSideLighting, roStereo, roDestinationAlpha, roNoColorBuffer, roNoColorBufferClear, roNoSwapBuffers, roNoDepthBufferClear, roDebugContext, roForwardContext, roOpenGL_ES2_Context };

typedef System::Set<TgxContextOption, TgxContextOption::roSoftwareMode, TgxContextOption::roOpenGL_ES2_Context> TgxContextOptions;

enum DECLSPEC_DENUM TgxLimitType : unsigned char { limClipPlanes, limEvalOrder, limLights, limListNesting, limModelViewStack, limNameStack, limPixelMapTable, limProjectionStack, limTextureSize, limTextureStack, limViewportDims, limAccumAlphaBits, limAccumBlueBits, limAccumGreenBits, limAccumRedBits, limAlphaBits, limAuxBuffers, limBlueBits, limGreenBits, limRedBits, limIndexBits, limStereo, limDoubleBuffer, limSubpixelBits, limDepthBits, limStencilBits, limNbTextureUnits };

_DECLARE_METACLASS(System::TMetaClass, TgxSceneObjectClass);

_DECLARE_METACLASS(System::TMetaClass, TgxBehaviourClass);

_DECLARE_METACLASS(System::TMetaClass, TgxEffectClass);

enum DECLSPEC_DENUM TgxObjectStyle : unsigned char { osDirectDraw, osIgnoreDepthBuffer, osNoVisibilityCulling };

typedef System::Set<TgxObjectStyle, TgxObjectStyle::osDirectDraw, TgxObjectStyle::osNoVisibilityCulling> TgxObjectStyles;

__interface  INTERFACE_UUID("{EA40AE8E-79B3-42F5-ADF2-7A901B665E12}") IgxInitializable  : public System::IInterface 
{
	virtual void __fastcall InitializeObject(System::TObject* ASender, const Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci) = 0 ;
};

class PASCALIMPLEMENTATION TgxInitializableObjectList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	_di_IgxInitializable operator[](const int Index) { return this->Items[Index]; }
	
private:
	_di_IgxInitializable __fastcall GetItems(const int Index);
	void __fastcall PutItems(const int Index, const _di_IgxInitializable Value);
	
public:
	HIDESBASE int __fastcall Add(const _di_IgxInitializable Item);
	__property _di_IgxInitializable Items[const int Index] = {read=GetItems, write=PutItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TgxInitializableObjectList() { }
	
public:
	/* TObject.Create */ inline __fastcall TgxInitializableObjectList() : System::Classes::TList() { }
	
};


class PASCALIMPLEMENTATION TgxBaseSceneObject : public Gxs::Coordinates::TgxCoordinatesUpdateAbleComponent
{
	typedef Gxs::Coordinates::TgxCoordinatesUpdateAbleComponent inherited;
	
public:
	TgxBaseSceneObject* operator[](int Index) { return this->Children[Index]; }
	
private:
	Stage::Vectortypes::TMatrix4f FAbsoluteMatrix;
	Stage::Vectortypes::TMatrix4f FInvAbsoluteMatrix;
	Stage::Vectortypes::TMatrix4f FLocalMatrix;
	TgxObjectStyles FObjectStyle;
	Gxs::Context::TgxListHandle* FListHandle;
	Gxs::Coordinates::TgxCoordinates* FPosition;
	Gxs::Coordinates::TgxCoordinates* FDirection;
	Gxs::Coordinates::TgxCoordinates* FUp;
	Gxs::Coordinates::TgxCoordinates* FScaling;
	TgxObjectChanges FChanges;
	TgxBaseSceneObject* FParent;
	TgxScene* FScene;
	TgxObjectBBChanges FBBChanges;
	Gxs::Geometrybb::THmgBoundingBox FBoundingBoxPersonalUnscaled;
	Gxs::Geometrybb::THmgBoundingBox FBoundingBoxOfChildren;
	Gxs::Geometrybb::THmgBoundingBox FBoundingBoxIncludingChildren;
	Gxs::Persistentclasses::TgxPersistentObjectList* FChildren;
	bool FVisible;
	int FUpdateCount;
	bool FShowAxes;
	Gxs::Coordinates::TgxCoordinates* FRotation;
	bool FIsCalculating;
	Gxs::Rendercontextinfo::TgxObjectsSorting FObjectsSorting;
	Gxs::Rendercontextinfo::TgxVisibilityCulling FVisibilityCulling;
	Gxs::Baseclasses::TgxProgressEvent FOnProgress;
	System::Classes::TNotifyEvent FOnAddedToParent;
	TgxBehaviours* FBehaviours;
	TgxEffects* FEffects;
	bool FPickable;
	System::Classes::TNotifyEvent FOnPicked;
	System::TObject* FTagObject;
	float FTagFloat;
	Gxs::Persistentclasses::TgxPersistentObjectList* ObjList;
	Gxs::Vectorlists::TgxSingleList* DistList;
	TgxBaseSceneObject* __fastcall Get(int Index);
	int __fastcall GetCount();
	int __fastcall GetIndex();
	void __fastcall SetParent(TgxBaseSceneObject* const val);
	void __fastcall SetIndex(int aValue);
	void __fastcall SetDirection(Gxs::Coordinates::TgxCoordinates* AVector);
	void __fastcall SetUp(Gxs::Coordinates::TgxCoordinates* AVector);
	Stage::Vectortypes::PMatrix4f __fastcall GetMatrix();
	void __fastcall SetPosition(Gxs::Coordinates::TgxCoordinates* APosition);
	void __fastcall SetPitchAngle(float AValue);
	void __fastcall SetRollAngle(float AValue);
	void __fastcall SetTurnAngle(float AValue);
	void __fastcall SetRotation(Gxs::Coordinates::TgxCoordinates* aRotation);
	float __fastcall GetPitchAngle();
	float __fastcall GetTurnAngle();
	float __fastcall GetRollAngle();
	void __fastcall SetShowAxes(bool AValue);
	void __fastcall SetScaling(Gxs::Coordinates::TgxCoordinates* AValue);
	void __fastcall SetObjectsSorting(const Gxs::Rendercontextinfo::TgxObjectsSorting val);
	void __fastcall SetVisibilityCulling(const Gxs::Rendercontextinfo::TgxVisibilityCulling val);
	void __fastcall SetBehaviours(TgxBehaviours* const val);
	TgxBehaviours* __fastcall GetBehaviours();
	void __fastcall SetEffects(TgxEffects* const val);
	TgxEffects* __fastcall GetEffects();
	Stage::Vectorgeometry::TAffineVector __fastcall GetAbsoluteAffineScale();
	Stage::Vectortypes::TVector4f __fastcall GetAbsoluteScale();
	void __fastcall SetAbsoluteAffineScale(const Stage::Vectorgeometry::TAffineVector &Value);
	void __fastcall SetAbsoluteScale(const Stage::Vectortypes::TVector4f &Value);
	Stage::Vectortypes::TMatrix4f __fastcall GetAbsoluteMatrix();
	void __fastcall SetAbsoluteMatrix(const Stage::Vectortypes::TMatrix4f &Value);
	void __fastcall SetBBChanges(const TgxObjectBBChanges Value);
	Stage::Vectortypes::PMatrix4f __fastcall GetDirectAbsoluteMatrix();
	Stage::Vectortypes::PMatrix4f __fastcall GetLocalMatrix();
	
protected:
	virtual void __fastcall Loaded();
	virtual void __fastcall SetScene(TgxScene* const Value);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteBehaviours(System::Classes::TStream* stream);
	void __fastcall ReadBehaviours(System::Classes::TStream* stream);
	void __fastcall WriteEffects(System::Classes::TStream* stream);
	void __fastcall ReadEffects(System::Classes::TStream* stream);
	void __fastcall WriteRotations(System::Classes::TStream* stream);
	void __fastcall ReadRotations(System::Classes::TStream* stream);
	virtual bool __fastcall GetVisible();
	virtual bool __fastcall GetPickable();
	virtual void __fastcall SetVisible(bool aValue);
	virtual void __fastcall SetPickable(bool aValue);
	void __fastcall SetAbsolutePosition(const Stage::Vectortypes::TVector4f &v);
	Stage::Vectortypes::TVector4f __fastcall GetAbsolutePosition();
	void __fastcall SetAbsoluteUp(const Stage::Vectortypes::TVector4f &v);
	Stage::Vectortypes::TVector4f __fastcall GetAbsoluteUp();
	void __fastcall SetAbsoluteDirection(const Stage::Vectortypes::TVector4f &v);
	Stage::Vectortypes::TVector4f __fastcall GetAbsoluteDirection();
	Stage::Vectorgeometry::TAffineVector __fastcall GetAbsoluteAffinePosition();
	void __fastcall SetAbsoluteAffinePosition(const Stage::Vectorgeometry::TAffineVector &Value);
	void __fastcall SetAbsoluteAffineUp(const Stage::Vectorgeometry::TAffineVector &v);
	Stage::Vectorgeometry::TAffineVector __fastcall GetAbsoluteAffineUp();
	void __fastcall SetAbsoluteAffineDirection(const Stage::Vectorgeometry::TAffineVector &v);
	Stage::Vectorgeometry::TAffineVector __fastcall GetAbsoluteAffineDirection();
	void __fastcall RecTransformationChanged();
	void __fastcall DrawAxes(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Word pattern);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc AProc, System::Classes::TComponent* Root);
	virtual bool __fastcall Blended();
	void __fastcall RebuildMatrix();
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual void __fastcall DestroyHandle();
	void __fastcall DestroyHandles();
	void __fastcall DeleteChildCameras();
	virtual void __fastcall DoOnAddedToParent();
	virtual void __fastcall CalculateBoundingBoxPersonalUnscaled(Gxs::Geometrybb::THmgBoundingBox &ANewBoundingBox);
	
public:
	__fastcall virtual TgxBaseSceneObject(System::Classes::TComponent* AOwner);
	__fastcall TgxBaseSceneObject(TgxBaseSceneObject* aParentOwner);
	__fastcall virtual ~TgxBaseSceneObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TgxObjectStyles ObjectStyle = {read=FObjectStyle, write=FObjectStyle, nodefault};
	unsigned __fastcall GetHandle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	bool __fastcall ListHandleAllocated();
	void __fastcall SetMatrix(const Stage::Vectortypes::TMatrix4f &aValue);
	__property Stage::Vectortypes::PMatrix4f Matrix = {read=GetMatrix};
	__property Stage::Vectortypes::PMatrix4f LocalMatrix = {read=GetLocalMatrix};
	void __fastcall ForceLocalMatrix(const Stage::Vectortypes::TMatrix4f &aMatrix);
	Stage::Vectortypes::PMatrix4f __fastcall AbsoluteMatrixAsAddress();
	__property Stage::Vectortypes::PMatrix4f DirectAbsoluteMatrix = {read=GetDirectAbsoluteMatrix};
	Stage::Vectortypes::TMatrix4f __fastcall InvAbsoluteMatrix();
	Stage::Vectortypes::PMatrix4f __fastcall InvAbsoluteMatrixAsAddress();
	__property Stage::Vectortypes::TMatrix4f AbsoluteMatrix = {read=GetAbsoluteMatrix, write=SetAbsoluteMatrix};
	__property Stage::Vectortypes::TVector4f AbsoluteDirection = {read=GetAbsoluteDirection, write=SetAbsoluteDirection};
	__property Stage::Vectorgeometry::TAffineVector AbsoluteAffineDirection = {read=GetAbsoluteAffineDirection, write=SetAbsoluteAffineDirection};
	__property Stage::Vectortypes::TVector4f AbsoluteScale = {read=GetAbsoluteScale, write=SetAbsoluteScale};
	__property Stage::Vectorgeometry::TAffineVector AbsoluteAffineScale = {read=GetAbsoluteAffineScale, write=SetAbsoluteAffineScale};
	__property Stage::Vectortypes::TVector4f AbsoluteUp = {read=GetAbsoluteUp, write=SetAbsoluteUp};
	__property Stage::Vectorgeometry::TAffineVector AbsoluteAffineUp = {read=GetAbsoluteAffineUp, write=SetAbsoluteAffineUp};
	Stage::Vectortypes::TVector4f __fastcall AbsoluteRight();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteLeft();
	__property Stage::Vectortypes::TVector4f AbsolutePosition = {read=GetAbsolutePosition, write=SetAbsolutePosition};
	__property Stage::Vectorgeometry::TAffineVector AbsoluteAffinePosition = {read=GetAbsoluteAffinePosition, write=SetAbsoluteAffinePosition};
	Stage::Vectortypes::PVector4f __fastcall AbsolutePositionAsAddress();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteXVector();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteYVector();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteZVector();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteToLocal(const Stage::Vectortypes::TVector4f &v)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall AbsoluteToLocal(const Stage::Vectorgeometry::TAffineVector &v)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall LocalToAbsolute(const Stage::Vectortypes::TVector4f &v)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall LocalToAbsolute(const Stage::Vectorgeometry::TAffineVector &v)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall Right();
	Stage::Vectortypes::TVector4f __fastcall LeftVector();
	Stage::Vectorgeometry::TAffineVector __fastcall AffineRight();
	Stage::Vectorgeometry::TAffineVector __fastcall AffineLeftVector();
	float __fastcall SqrDistanceTo(TgxBaseSceneObject* anObject)/* overload */;
	float __fastcall SqrDistanceTo(const Stage::Vectortypes::TVector4f &pt)/* overload */;
	float __fastcall SqrDistanceTo(const Stage::Vectorgeometry::TAffineVector &pt)/* overload */;
	float __fastcall DistanceTo(TgxBaseSceneObject* anObject)/* overload */;
	float __fastcall DistanceTo(const Stage::Vectorgeometry::TAffineVector &pt)/* overload */;
	float __fastcall DistanceTo(const Stage::Vectortypes::TVector4f &pt)/* overload */;
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	float __fastcall BarycenterSqrDistanceTo(const Stage::Vectortypes::TVector4f &pt);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensions();
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBox(const bool AIncludeChilden = true);
	Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBoxUnscaled(const bool AIncludeChilden = true);
	Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBoxAbsolute(const bool AIncludeChilden = true, const bool AUseBaryCenter = false);
	Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBoxEx();
	Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBoxAbsoluteEx();
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBox(const bool AIncludeChilden = true, const bool AUseBaryCenter = false);
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBoxUnscaled(const bool AIncludeChilden = true, const bool AUseBaryCenter = false);
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBoxAbsolute(const bool AIncludeChilden = true, const bool AUseBaryCenter = false);
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBoxPersonalUnscaledEx();
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBoxOfChildrenEx();
	Gxs::Geometrybb::THmgBoundingBox __fastcall BoundingBoxIncludingChildrenEx();
	float __fastcall BoundingSphereRadius();
	float __fastcall BoundingSphereRadiusUnscaled();
	virtual bool __fastcall PointInObject(const Stage::Vectortypes::TVector4f &point);
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	__property TgxBaseSceneObject* Children[int Index] = {read=Get/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	virtual TgxBaseSceneObject* __fastcall AddNewChild(TgxSceneObjectClass AChild);
	virtual TgxBaseSceneObject* __fastcall AddNewChildFirst(TgxSceneObjectClass AChild);
	virtual void __fastcall AddChild(TgxBaseSceneObject* AChild);
	TgxBehaviour* __fastcall GetOrCreateBehaviour(TgxBehaviourClass aBehaviour);
	TgxBehaviour* __fastcall AddNewBehaviour(TgxBehaviourClass aBehaviour);
	TgxEffect* __fastcall GetOrCreateEffect(TgxEffectClass anEffect);
	TgxEffect* __fastcall AddNewEffect(TgxEffectClass anEffect);
	bool __fastcall HasSubChildren();
	virtual void __fastcall DeleteChildren();
	HIDESBASE virtual void __fastcall Insert(int AIndex, TgxBaseSceneObject* AChild);
	HIDESBASE virtual void __fastcall Remove(TgxBaseSceneObject* AChild, bool keepChildren);
	int __fastcall IndexOfChild(TgxBaseSceneObject* AChild);
	TgxBaseSceneObject* __fastcall FindChild(const System::UnicodeString aName, bool ownChildrenOnly);
	void __fastcall ExchangeChildrenSafe(int anIndex1, int anIndex2);
	void __fastcall ExchangeChildren(int anIndex1, int anIndex2);
	void __fastcall MoveChildUp(int anIndex);
	void __fastcall MoveChildDown(int anIndex);
	void __fastcall MoveChildFirst(int anIndex);
	void __fastcall MoveChildLast(int anIndex);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall MoveTo(TgxBaseSceneObject* newParent);
	void __fastcall MoveUp();
	void __fastcall MoveDown();
	void __fastcall MoveFirst();
	void __fastcall MoveLast();
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent();
	DYNAMIC bool __fastcall HasParent() _FINAL_ATTRIBUTE;
	bool __fastcall IsUpdating();
	void __fastcall Lift(float ADistance);
	void __fastcall Move(float ADistance);
	void __fastcall Translate(float tx, float ty, float tz);
	void __fastcall MoveObjectAround(TgxBaseSceneObject* anObject, float pitchDelta, float turnDelta);
	void __fastcall MoveObjectAllAround(TgxBaseSceneObject* anObject, float pitchDelta, float turnDelta);
	void __fastcall Pitch(float angle);
	void __fastcall Roll(float angle);
	void __fastcall Turn(float angle);
	void __fastcall ResetRotations();
	void __fastcall ResetAndPitchTurnRoll(const float degX, const float degY, const float degZ);
	void __fastcall RotateAbsolute(const float rx, const float ry, const float rz)/* overload */;
	void __fastcall RotateAbsolute(const Stage::Vectorgeometry::TAffineVector &axis, float angle)/* overload */;
	void __fastcall Slide(float ADistance);
	void __fastcall PointTo(TgxBaseSceneObject* const ATargetObject, const Stage::Vectortypes::TVector4f &AUpVector)/* overload */;
	void __fastcall PointTo(const Stage::Vectortypes::TVector4f &AAbsolutePosition, const Stage::Vectortypes::TVector4f &AUpVector)/* overload */;
	void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	void __fastcall RenderChildren(int firstChildIndex, int lastChildIndex, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall StructureChanged();
	void __fastcall ClearStructureChanged();
	virtual void __fastcall CoordinateChanged(Gxs::Coordinates::TgxCustomCoordinates* Sender);
	void __fastcall TransformationChanged();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	__property Gxs::Coordinates::TgxCoordinates* Rotation = {read=FRotation, write=SetRotation};
	__property float PitchAngle = {read=GetPitchAngle, write=SetPitchAngle};
	__property float RollAngle = {read=GetRollAngle, write=SetRollAngle};
	__property float TurnAngle = {read=GetTurnAngle, write=SetTurnAngle};
	__property bool ShowAxes = {read=FShowAxes, write=SetShowAxes, default=0};
	__property TgxObjectChanges Changes = {read=FChanges, nodefault};
	__property TgxObjectBBChanges BBChanges = {read=FBBChanges, write=SetBBChanges, nodefault};
	__property TgxBaseSceneObject* Parent = {read=FParent, write=SetParent};
	__property Gxs::Coordinates::TgxCoordinates* Position = {read=FPosition, write=SetPosition};
	__property Gxs::Coordinates::TgxCoordinates* Direction = {read=FDirection, write=SetDirection};
	__property Gxs::Coordinates::TgxCoordinates* Up = {read=FUp, write=SetUp};
	__property Gxs::Coordinates::TgxCoordinates* Scale = {read=FScaling, write=SetScaling};
	__property TgxScene* Scene = {read=FScene};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property bool Pickable = {read=FPickable, write=SetPickable, default=1};
	__property Gxs::Rendercontextinfo::TgxObjectsSorting ObjectsSorting = {read=FObjectsSorting, write=SetObjectsSorting, default=0};
	__property Gxs::Rendercontextinfo::TgxVisibilityCulling VisibilityCulling = {read=FVisibilityCulling, write=SetVisibilityCulling, default=0};
	__property Gxs::Baseclasses::TgxProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property System::Classes::TNotifyEvent OnPicked = {read=FOnPicked, write=FOnPicked};
	__property System::Classes::TNotifyEvent OnAddedToParent = {read=FOnAddedToParent, write=FOnAddedToParent};
	__property TgxBehaviours* Behaviours = {read=GetBehaviours, write=SetBehaviours, stored=false};
	__property TgxEffects* Effects = {read=GetEffects, write=SetEffects, stored=false};
	__property System::TObject* TagObject = {read=FTagObject, write=FTagObject};
	
__published:
	__property float TagFloat = {read=FTagFloat, write=FTagFloat};
};


class PASCALIMPLEMENTATION TgxBaseBehaviour : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
protected:
	virtual void __fastcall SetName(const System::UnicodeString val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	TgxBaseSceneObject* __fastcall OwnerBaseSceneObject();
	
public:
	__fastcall virtual TgxBaseBehaviour(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxBaseBehaviour();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
};


class PASCALIMPLEMENTATION TgxBehaviour : public TgxBaseBehaviour
{
	typedef TgxBaseBehaviour inherited;
	
public:
	/* TgxBaseBehaviour.Create */ inline __fastcall virtual TgxBehaviour(Gxs::Xcollection::TXCollection* AOwner) : TgxBaseBehaviour(AOwner) { }
	/* TgxBaseBehaviour.Destroy */ inline __fastcall virtual ~TgxBehaviour() { }
	
};


class PASCALIMPLEMENTATION TgxBehaviours : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	TgxBehaviour* operator[](int index) { return this->Behaviour[index]; }
	
protected:
	TgxBehaviour* __fastcall GetBehaviour(int Index);
	
public:
	__fastcall virtual TgxBehaviours(System::Classes::TPersistent* AOwner);
	DYNAMIC System::UnicodeString __fastcall GetNamePath();
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	__property TgxBehaviour* Behaviour[int index] = {read=GetBehaviour/*, default*/};
	virtual bool __fastcall CanAdd(Gxs::Xcollection::TXCollectionItemClass aClass);
	void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTimes);
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxBehaviours() { }
	
};


class PASCALIMPLEMENTATION TgxEffect : public TgxBaseBehaviour
{
	typedef TgxBaseBehaviour inherited;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseBehaviour.Create */ inline __fastcall virtual TgxEffect(Gxs::Xcollection::TXCollection* AOwner) : TgxBaseBehaviour(AOwner) { }
	/* TgxBaseBehaviour.Destroy */ inline __fastcall virtual ~TgxEffect() { }
	
};


class PASCALIMPLEMENTATION TgxObjectPreEffect : public TgxEffect
{
	typedef TgxEffect inherited;
	
public:
	/* TgxBaseBehaviour.Create */ inline __fastcall virtual TgxObjectPreEffect(Gxs::Xcollection::TXCollection* AOwner) : TgxEffect(AOwner) { }
	/* TgxBaseBehaviour.Destroy */ inline __fastcall virtual ~TgxObjectPreEffect() { }
	
};


class PASCALIMPLEMENTATION TgxObjectPostEffect : public TgxEffect
{
	typedef TgxEffect inherited;
	
public:
	/* TgxBaseBehaviour.Create */ inline __fastcall virtual TgxObjectPostEffect(Gxs::Xcollection::TXCollection* AOwner) : TgxEffect(AOwner) { }
	/* TgxBaseBehaviour.Destroy */ inline __fastcall virtual ~TgxObjectPostEffect() { }
	
};


class PASCALIMPLEMENTATION TgxObjectAfterEffect : public TgxEffect
{
	typedef TgxEffect inherited;
	
public:
	/* TgxBaseBehaviour.Create */ inline __fastcall virtual TgxObjectAfterEffect(Gxs::Xcollection::TXCollection* AOwner) : TgxEffect(AOwner) { }
	/* TgxBaseBehaviour.Destroy */ inline __fastcall virtual ~TgxObjectAfterEffect() { }
	
};


class PASCALIMPLEMENTATION TgxEffects : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	TgxEffect* operator[](int index) { return this->ObjectEffect[index]; }
	
protected:
	TgxEffect* __fastcall GetEffect(int Index);
	
public:
	__fastcall virtual TgxEffects(System::Classes::TPersistent* AOwner);
	DYNAMIC System::UnicodeString __fastcall GetNamePath();
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	__property TgxEffect* ObjectEffect[int index] = {read=GetEffect/*, default*/};
	virtual bool __fastcall CanAdd(Gxs::Xcollection::TXCollectionItemClass aClass);
	void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall RenderPreEffects(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall RenderPostEffects(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxEffects() { }
	
};


class PASCALIMPLEMENTATION TgxCustomSceneObject : public TgxBaseSceneObject
{
	typedef TgxBaseSceneObject inherited;
	
private:
	Gxs::Material::TgxMaterial* FMaterial;
	System::UnicodeString FHint;
	
protected:
	virtual bool __fastcall Blended();
	void __fastcall SetVKMaterial(Gxs::Material::TgxMaterial* aValue);
	virtual void __fastcall DestroyHandle();
	virtual void __fastcall Loaded();
	
public:
	__fastcall virtual TgxCustomSceneObject(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomSceneObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__property Gxs::Material::TgxMaterial* Material = {read=FMaterial, write=SetVKMaterial};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCustomSceneObject(TgxBaseSceneObject* aParentOwner) : TgxBaseSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxSceneRootObject : public TgxBaseSceneObject
{
	typedef TgxBaseSceneObject inherited;
	
public:
	__fastcall virtual TgxSceneRootObject(System::Classes::TComponent* AOwner);
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSceneRootObject(TgxBaseSceneObject* aParentOwner) : TgxBaseSceneObject(aParentOwner) { }
	/* TgxBaseSceneObject.Destroy */ inline __fastcall virtual ~TgxSceneRootObject() { }
	
};


class PASCALIMPLEMENTATION TgxImmaterialSceneObject : public TgxCustomSceneObject
{
	typedef TgxCustomSceneObject inherited;
	
public:
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	
__published:
	__property ObjectsSorting = {default=0};
	__property VisibilityCulling = {default=0};
	__property Direction;
	__property PitchAngle = {default=0};
	__property Position;
	__property RollAngle = {default=0};
	__property Scale;
	__property ShowAxes = {default=0};
	__property TurnAngle = {default=0};
	__property Up;
	__property Visible = {default=1};
	__property Pickable = {default=1};
	__property OnProgress;
	__property OnPicked;
	__property Behaviours;
	__property Effects;
	__property Hint = {default=0};
public:
	/* TgxCustomSceneObject.Create */ inline __fastcall virtual TgxImmaterialSceneObject(System::Classes::TComponent* AOwner) : TgxCustomSceneObject(AOwner) { }
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxImmaterialSceneObject() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxImmaterialSceneObject(TgxBaseSceneObject* aParentOwner) : TgxCustomSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxCameraInvariantObject : public TgxImmaterialSceneObject
{
	typedef TgxImmaterialSceneObject inherited;
	
private:
	TgxCameraInvarianceMode FCamInvarianceMode;
	
protected:
	void __fastcall SetCamInvarianceMode(const TgxCameraInvarianceMode val);
	__property TgxCameraInvarianceMode CamInvarianceMode = {read=FCamInvarianceMode, write=SetCamInvarianceMode, nodefault};
	
public:
	__fastcall virtual TgxCameraInvariantObject(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCameraInvariantObject() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCameraInvariantObject(TgxBaseSceneObject* aParentOwner) : TgxImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxSceneObject : public TgxCustomSceneObject
{
	typedef TgxCustomSceneObject inherited;
	
__published:
	__property Material;
	__property ObjectsSorting = {default=0};
	__property VisibilityCulling = {default=0};
	__property Direction;
	__property PitchAngle = {default=0};
	__property Position;
	__property RollAngle = {default=0};
	__property Scale;
	__property ShowAxes = {default=0};
	__property TurnAngle = {default=0};
	__property Up;
	__property Visible = {default=1};
	__property Pickable = {default=1};
	__property OnProgress;
	__property OnPicked;
	__property Behaviours;
	__property Effects;
	__property Hint = {default=0};
public:
	/* TgxCustomSceneObject.Create */ inline __fastcall virtual TgxSceneObject(System::Classes::TComponent* AOwner) : TgxCustomSceneObject(AOwner) { }
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxSceneObject() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSceneObject(TgxBaseSceneObject* aParentOwner) : TgxCustomSceneObject(aParentOwner) { }
	
};


typedef void __fastcall (__closure *TDirectRenderEvent)(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);

class PASCALIMPLEMENTATION TgxDirectOpenGL : public TgxImmaterialSceneObject
{
	typedef TgxImmaterialSceneObject inherited;
	
private:
	bool FUseBuildList;
	TDirectRenderEvent FOnRender;
	bool FBlend;
	
protected:
	void __fastcall SetUseBuildList(const bool val);
	virtual bool __fastcall Blended();
	void __fastcall SetBlend(const bool val);
	
public:
	__fastcall virtual TgxDirectOpenGL(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	
__published:
	__property bool UseBuildList = {read=FUseBuildList, write=SetUseBuildList, nodefault};
	__property TDirectRenderEvent OnRender = {read=FOnRender, write=FOnRender};
	__property bool Blend = {read=FBlend, write=SetBlend, nodefault};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxDirectOpenGL() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxDirectOpenGL(TgxBaseSceneObject* aParentOwner) : TgxImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxRenderPoint : public TgxImmaterialSceneObject
{
	typedef TgxImmaterialSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<TDirectRenderEvent> _TgxRenderPoint__1;
	
	typedef System::DynamicArray<System::Classes::TNotifyEvent> _TgxRenderPoint__2;
	
	
private:
	_TgxRenderPoint__1 FCallBacks;
	_TgxRenderPoint__2 FFreeCallBacks;
	
public:
	__fastcall virtual TgxRenderPoint(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxRenderPoint();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall RegisterCallBack(TDirectRenderEvent renderEvent, System::Classes::TNotifyEvent renderPointFreed);
	void __fastcall UnRegisterCallBack(TDirectRenderEvent renderEvent);
	void __fastcall Clear();
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxRenderPoint(TgxBaseSceneObject* aParentOwner) : TgxImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxProxyObject : public TgxBaseSceneObject
{
	typedef TgxBaseSceneObject inherited;
	
private:
	TgxBaseSceneObject* FMasterObject;
	TgxProxyObjectOptions FProxyOptions;
	
protected:
	bool FRendering;
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetMasterObject(TgxBaseSceneObject* const val);
	void __fastcall SetProxyOptions(const TgxProxyObjectOptions val);
	
public:
	__fastcall virtual TgxProxyObject(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxProxyObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensions();
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &SilhouetteParameters);
	
__published:
	__property TgxBaseSceneObject* MasterObject = {read=FMasterObject, write=SetMasterObject};
	__property TgxProxyObjectOptions ProxyOptions = {read=FProxyOptions, write=SetProxyOptions, default=7};
	__property ObjectsSorting = {default=0};
	__property Direction;
	__property PitchAngle = {default=0};
	__property Position;
	__property RollAngle = {default=0};
	__property Scale;
	__property ShowAxes = {default=0};
	__property TurnAngle = {default=0};
	__property Up;
	__property Visible = {default=1};
	__property Pickable = {default=1};
	__property OnProgress;
	__property OnPicked;
	__property Behaviours;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxProxyObject(TgxBaseSceneObject* aParentOwner) : TgxBaseSceneObject(aParentOwner) { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxProxyObjectClass);

enum DECLSPEC_DENUM TgxLightStyle : unsigned char { lsSpot, lsOmni, lsParallel, lsParallelSpot };

class PASCALIMPLEMENTATION TgxLightSource : public TgxBaseSceneObject
{
	typedef TgxBaseSceneObject inherited;
	
private:
	unsigned FLightID;
	Gxs::Coordinates::TgxCoordinates* FSpotDirection;
	float FSpotExponent;
	float FSpotCutOff;
	float FConstAttenuation;
	float FLinearAttenuation;
	float FQuadraticAttenuation;
	bool FShining;
	Gxs::Color::TgxColor* FAmbient;
	Gxs::Color::TgxColor* FDiffuse;
	Gxs::Color::TgxColor* FSpecular;
	TgxLightStyle FLightStyle;
	
protected:
	void __fastcall SetAmbient(Gxs::Color::TgxColor* aValue);
	void __fastcall SetDiffuse(Gxs::Color::TgxColor* aValue);
	void __fastcall SetSpecular(Gxs::Color::TgxColor* aValue);
	void __fastcall SetConstAttenuation(float aValue);
	void __fastcall SetLinearAttenuation(float aValue);
	void __fastcall SetQuadraticAttenuation(float aValue);
	void __fastcall SetShining(bool aValue);
	void __fastcall SetSpotDirection(Gxs::Coordinates::TgxCoordinates* AVector);
	void __fastcall SetSpotExponent(float aValue);
	void __fastcall SetSpotCutOff(const float val);
	void __fastcall SetLightStyle(const TgxLightStyle val);
	
public:
	__fastcall virtual TgxLightSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxLightSource();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual void __fastcall CoordinateChanged(Gxs::Coordinates::TgxCustomCoordinates* Sender);
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	__property unsigned LightID = {read=FLightID, nodefault};
	bool __fastcall Attenuated();
	
__published:
	__property Gxs::Color::TgxColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property float ConstAttenuation = {read=FConstAttenuation, write=SetConstAttenuation};
	__property Gxs::Color::TgxColor* Diffuse = {read=FDiffuse, write=SetDiffuse};
	__property float LinearAttenuation = {read=FLinearAttenuation, write=SetLinearAttenuation};
	__property float QuadraticAttenuation = {read=FQuadraticAttenuation, write=SetQuadraticAttenuation};
	__property Position;
	__property TgxLightStyle LightStyle = {read=FLightStyle, write=SetLightStyle, default=0};
	__property bool Shining = {read=FShining, write=SetShining, default=1};
	__property Gxs::Color::TgxColor* Specular = {read=FSpecular, write=SetSpecular};
	__property float SpotCutOff = {read=FSpotCutOff, write=SetSpotCutOff};
	__property Gxs::Coordinates::TgxCoordinates* SpotDirection = {read=FSpotDirection, write=SetSpotDirection};
	__property float SpotExponent = {read=FSpotExponent, write=SetSpotExponent};
	__property OnProgress;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxLightSource(TgxBaseSceneObject* aParentOwner) : TgxBaseSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxCameraStyle : unsigned char { csPerspective, csOrthogonal, csOrtho2D, csCustom, csInfinitePerspective, csPerspectiveKeepFOV };

enum DECLSPEC_DENUM TgxCameraKeepFOVMode : unsigned char { ckmHorizontalFOV, ckmVerticalFOV };

typedef void __fastcall (__closure *TgxOnCustomPerspective)(const Stage::Vectorgeometry::TRectangle &viewport, int width, int height, int DPI, float &viewPortRadius);

class PASCALIMPLEMENTATION TgxCamera : public TgxBaseSceneObject
{
	typedef TgxBaseSceneObject inherited;
	
private:
	float FFocalLength;
	float FDepthOfView;
	float FNearPlane;
	float FNearPlaneBias;
	float FViewPortRadius;
	TgxBaseSceneObject* FTargetObject;
	Stage::Vectortypes::TVector4f FLastDirection;
	TgxCameraStyle FCameraStyle;
	TgxCameraKeepFOVMode FKeepFOVMode;
	float FSceneScale;
	System::Classes::TNotifyEvent FDeferredApply;
	TgxOnCustomPerspective FOnCustomPerspective;
	bool FDesign;
	double FFOVY;
	double FFOVX;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetTargetObject(TgxBaseSceneObject* const val);
	void __fastcall SetDepthOfView(float aValue);
	void __fastcall SetFocalLength(float aValue);
	void __fastcall SetCameraStyle(const TgxCameraStyle val);
	void __fastcall SetKeepFOVMode(const TgxCameraKeepFOVMode val);
	void __fastcall SetSceneScale(float Value);
	bool __fastcall StoreSceneScale();
	void __fastcall SetNearPlaneBias(float Value);
	bool __fastcall StoreNearPlaneBias();
	
public:
	__fastcall virtual TgxCamera(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCamera();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property float NearPlane = {read=FNearPlane};
	void __fastcall Apply();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	void __fastcall ApplyPerspective(const Stage::Vectorgeometry::TRectangle &AViewport, int AWidth, int AHeight, int ADPI);
	void __fastcall AutoLeveling(float Factor);
	void __fastcall Reset(TgxSceneBuffer* aSceneBuffer);
	void __fastcall ZoomAll(TgxSceneBuffer* aSceneBuffer);
	void __fastcall RotateObject(TgxBaseSceneObject* obj, float pitchDelta, float turnDelta, float rollDelta = 0.000000E+00f);
	void __fastcall RotateTarget(float pitchDelta, float turnDelta, float rollDelta = 0.000000E+00f);
	void __fastcall MoveAroundTarget(float pitchDelta, float turnDelta);
	void __fastcall MoveAllAroundTarget(float pitchDelta, float turnDelta);
	void __fastcall MoveInEyeSpace(float forwardDistance, float rightDistance, float upDistance);
	void __fastcall MoveTargetInEyeSpace(float forwardDistance, float rightDistance, float upDistance);
	Stage::Vectortypes::TVector4f __fastcall AbsoluteEyeSpaceVector(float forwardDistance, float rightDistance, float upDistance);
	void __fastcall AdjustDistanceToTarget(float distanceRatio);
	float __fastcall DistanceToTarget();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteVectorToTarget();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteRightVectorToTarget();
	Stage::Vectortypes::TVector4f __fastcall AbsoluteUpVectorToTarget();
	Stage::Vectortypes::TVector4f __fastcall ScreenDeltaToVector(int deltaX, int deltaY, float ratio, const Stage::Vectortypes::TVector4f &planeNormal);
	Stage::Vectortypes::TVector4f __fastcall ScreenDeltaToVectorXY(int deltaX, int deltaY, float ratio);
	Stage::Vectortypes::TVector4f __fastcall ScreenDeltaToVectorXZ(int deltaX, int deltaY, float ratio);
	Stage::Vectortypes::TVector4f __fastcall ScreenDeltaToVectorYZ(int deltaX, int deltaY, float ratio);
	bool __fastcall PointInFront(const Stage::Vectortypes::TVector4f &point)/* overload */;
	float __fastcall GetFieldOfView(const float AViewportDimension);
	void __fastcall SetFieldOfView(const float AFieldOfView, const float AViewportDimension);
	
__published:
	__property float DepthOfView = {read=FDepthOfView, write=SetDepthOfView};
	__property float FocalLength = {read=FFocalLength, write=SetFocalLength};
	__property float SceneScale = {read=FSceneScale, write=SetSceneScale, stored=StoreSceneScale};
	__property float NearPlaneBias = {read=FNearPlaneBias, write=SetNearPlaneBias, stored=StoreNearPlaneBias};
	__property TgxBaseSceneObject* TargetObject = {read=FTargetObject, write=SetTargetObject};
	__property TgxCameraStyle CameraStyle = {read=FCameraStyle, write=SetCameraStyle, default=0};
	__property TgxCameraKeepFOVMode KeepFOVMode = {read=FKeepFOVMode, write=SetKeepFOVMode, default=0};
	__property TgxOnCustomPerspective OnCustomPerspective = {read=FOnCustomPerspective, write=FOnCustomPerspective};
	__property Position;
	__property Direction;
	__property Up;
	__property OnProgress;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCamera(TgxBaseSceneObject* aParentOwner) : TgxBaseSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxScene : public Gxs::Baseclasses::TgxUpdateAbleComponent
{
	typedef Gxs::Baseclasses::TgxUpdateAbleComponent inherited;
	
private:
	int FUpdateCount;
	TgxSceneRootObject* FObjects;
	Gxs::Context::TgxContext* FBaseContext;
	Gxs::Persistentclasses::TgxPersistentObjectList* FLights;
	Gxs::Persistentclasses::TgxPersistentObjectList* FBuffers;
	TgxCamera* FCurrentCamera;
	TgxSceneBuffer* FCurrentBuffer;
	Gxs::Rendercontextinfo::TgxObjectsSorting FObjectsSorting;
	Gxs::Rendercontextinfo::TgxVisibilityCulling FVisibilityCulling;
	Gxs::Baseclasses::TgxProgressEvent FOnBeforeProgress;
	Gxs::Baseclasses::TgxProgressEvent FOnProgress;
	double FCurrentDeltaTime;
	TgxInitializableObjectList* FInitializableObjects;
	
protected:
	void __fastcall AddLight(TgxLightSource* aLight);
	void __fastcall RemoveLight(TgxLightSource* aLight);
	void __fastcall AddLights(TgxBaseSceneObject* anObj);
	void __fastcall RemoveLights(TgxBaseSceneObject* anObj);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc AProc, System::Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* AChild, int Order);
	void __fastcall SetObjectsSorting(const Gxs::Rendercontextinfo::TgxObjectsSorting val);
	void __fastcall SetVisibilityCulling(const Gxs::Rendercontextinfo::TgxVisibilityCulling val);
	virtual void __fastcall ReadState(System::Classes::TReader* reader);
	
public:
	__fastcall virtual TgxScene(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxScene();
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	bool __fastcall IsUpdating();
	void __fastcall AddBuffer(TgxSceneBuffer* aBuffer);
	void __fastcall RemoveBuffer(TgxSceneBuffer* aBuffer);
	void __fastcall SetupLights(int maxLights);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall Progress(const double deltaTime, const double newTime);
	TgxBaseSceneObject* __fastcall FindSceneObject(const System::UnicodeString aName);
	virtual TgxBaseSceneObject* __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	void __fastcall ShutdownAllLights();
	void __fastcall SaveToFile(const System::UnicodeString fileName);
	void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall SaveToStream(System::Classes::TStream* aStream);
	void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	void __fastcall SaveToTextFile(const System::UnicodeString fileName);
	void __fastcall LoadFromTextFile(const System::UnicodeString fileName);
	__property TgxCamera* CurrentCamera = {read=FCurrentCamera};
	__property Gxs::Persistentclasses::TgxPersistentObjectList* Lights = {read=FLights};
	__property TgxSceneRootObject* Objects = {read=FObjects};
	__property TgxSceneBuffer* CurrentBuffer = {read=FCurrentBuffer};
	__property TgxInitializableObjectList* InitializableObjects = {read=FInitializableObjects};
	__property double CurrentDeltaTime = {read=FCurrentDeltaTime};
	
__published:
	__property Gxs::Rendercontextinfo::TgxObjectsSorting ObjectsSorting = {read=FObjectsSorting, write=SetObjectsSorting, default=3};
	__property Gxs::Rendercontextinfo::TgxVisibilityCulling VisibilityCulling = {read=FVisibilityCulling, write=SetVisibilityCulling, default=1};
	__property Gxs::Baseclasses::TgxProgressEvent OnBeforeProgress = {read=FOnBeforeProgress, write=FOnBeforeProgress};
	__property Gxs::Baseclasses::TgxProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
};


enum DECLSPEC_DENUM TgxFogMode : unsigned char { fmLinear, fmExp, fmExp2 };

enum DECLSPEC_DENUM TgxFogDistance : unsigned char { fdDefault, fdEyeRadial, fdEyePlane };

class PASCALIMPLEMENTATION TgxFogEnvironment : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	TgxSceneBuffer* FSceneBuffer;
	Gxs::Color::TgxColor* FFogColor;
	float FFogStart;
	float FFogEnd;
	TgxFogMode FFogMode;
	TgxFogDistance FFogDistance;
	
protected:
	void __fastcall SetFogColor(Gxs::Color::TgxColor* Value);
	void __fastcall SetFogStart(float Value);
	void __fastcall SetFogEnd(float Value);
	void __fastcall SetFogMode(TgxFogMode Value);
	void __fastcall SetFogDistance(const TgxFogDistance val);
	
public:
	__fastcall virtual TgxFogEnvironment(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxFogEnvironment();
	void __fastcall ApplyFog();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsAtDefaultValues();
	
__published:
	__property Gxs::Color::TgxColor* FogColor = {read=FFogColor, write=SetFogColor};
	__property float FogStart = {read=FFogStart, write=SetFogStart};
	__property float FogEnd = {read=FFogEnd, write=SetFogEnd};
	__property TgxFogMode FogMode = {read=FFogMode, write=SetFogMode, default=0};
	__property TgxFogDistance FogDistance = {read=FFogDistance, write=SetFogDistance, default=0};
};


enum DECLSPEC_DENUM TgxDepthPrecision : unsigned char { dpDefault, dp16bits, dp24bits, dp32bits };

enum DECLSPEC_DENUM TgxColorDepth : unsigned char { cdDefault, cd8bits, cd16bits, cd24bits, cdFloat64bits, cdFloat128bits };

enum DECLSPEC_DENUM TgxShadeModel : unsigned char { smDefault, smSmooth, smFlat };

class PASCALIMPLEMENTATION TgxSceneBuffer : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TMatrix4f> _TgxSceneBuffer__1;
	
	typedef System::DynamicArray<Stage::Vectortypes::TMatrix4f> _TgxSceneBuffer__2;
	
	
private:
	bool FRendering;
	Gxs::Context::TgxContext* FRenderingContext;
	Gxs::Persistentclasses::TgxPersistentObjectList* FAfterRenderEffects;
	_TgxSceneBuffer__1 FViewMatrixStack;
	_TgxSceneBuffer__2 FProjectionMatrixStack;
	Stage::Vectortypes::TMatrix4f FBaseProjectionMatrix;
	Stage::Vectortypes::TVector4f FCameraAbsolutePosition;
	Stage::Vectorgeometry::TRectangle FViewPort;
	Gxs::Selection::TgxBaseSelectTechnique* FSelector;
	bool FFaceCulling;
	bool FFogEnable;
	bool FLighting;
	bool FDepthTest;
	System::Uitypes::TColor FBackgroundColor;
	float FBackgroundAlpha;
	Gxs::Color::TgxColor* FAmbientColor;
	Gxs::Context::TgxAntiAliasing FAntiAliasing;
	TgxDepthPrecision FDepthPrecision;
	TgxColorDepth FColorDepth;
	TgxContextOptions FContextOptions;
	TgxShadeModel FShadeModel;
	int FRenderDPI;
	TgxFogEnvironment* FFogEnvironment;
	int FAccumBufferBits;
	Gxs::Context::TgxContextLayer FLayer;
	TgxCamera* FCamera;
	void *FFreezeBuffer;
	bool FFreezed;
	Stage::Vectorgeometry::TRectangle FFreezedViewPort;
	System::LongInt FFrameCount;
	float FFramesPerSecond;
	__int64 FFirstPerfCounter;
	float FLastFrameTime;
	System::Classes::TNotifyEvent FOnChange;
	System::Classes::TNotifyEvent FOnStructuralChange;
	System::Classes::TNotifyEvent FOnPrepareGLContext;
	System::Classes::TNotifyEvent FBeforeRender;
	System::Classes::TNotifyEvent FViewerBeforeRender;
	System::Classes::TNotifyEvent FPostRender;
	System::Classes::TNotifyEvent FAfterRender;
	TDirectRenderEvent FInitiateRendering;
	TDirectRenderEvent FWrapUpRendering;
	void __fastcall SetLayer(const Gxs::Context::TgxContextLayer Value);
	
protected:
	void __fastcall SetBackgroundColor(System::Uitypes::TColor AColor);
	void __fastcall SetBackgroundAlpha(float alpha);
	void __fastcall SetAmbientColor(Gxs::Color::TgxColor* AColor);
	int __fastcall GetLimit(TgxLimitType Which);
	void __fastcall SetCamera(TgxCamera* ACamera);
	void __fastcall SetContextOptions(TgxContextOptions Options);
	void __fastcall SetDepthTest(bool aValue);
	void __fastcall SetFaceCulling(bool aValue);
	void __fastcall SetLighting(bool aValue);
	void __fastcall SetAntiAliasing(const Gxs::Context::TgxAntiAliasing val);
	void __fastcall SetDepthPrecision(const TgxDepthPrecision val);
	void __fastcall SetColorDepth(const TgxColorDepth val);
	void __fastcall SetShadeModel(const TgxShadeModel val);
	void __fastcall SetFogEnable(bool aValue);
	void __fastcall SetFogEnvironment(TgxFogEnvironment* aValue);
	bool __fastcall StoreFog();
	void __fastcall SetAccumBufferBits(const int val);
	void __fastcall PrepareRenderingMatrices(const Stage::Vectorgeometry::TRectangle &AViewport, int resolution, Winapi::Windows::PRect pickingRect = (System::Types::PRect)(0x0));
	void __fastcall DoBaseRender(const Stage::Vectorgeometry::TRectangle &AViewport, int resolution, Gxs::Rendercontextinfo::TGXDrawState drawState, TgxBaseSceneObject* baseObject);
	void __fastcall SetupRenderingContext(Gxs::Context::TgxContext* Context);
	void __fastcall SetupRCOptions(Gxs::Context::TgxContext* Context);
	void __fastcall PrepareGLContext();
	void __fastcall DoChange();
	void __fastcall DoStructuralChange();
	__property int RenderDPI = {read=FRenderDPI, nodefault};
	__property System::Classes::TNotifyEvent OnPrepareGLContext = {read=FOnPrepareGLContext, write=FOnPrepareGLContext};
	
public:
	__fastcall virtual TgxSceneBuffer(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxSceneBuffer();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall CreateRC(Winapi::Windows::THandle AWindowHandle, bool memoryContext, int BufferCount = 0x1)/* overload */;
	void __fastcall ClearBuffers();
	void __fastcall DestroyRC();
	bool __fastcall RCInstantiated();
	void __fastcall Resize(int newLeft, int newTop, int newWidth, int newHeight);
	Gxs::Context::TgxContextAcceleration __fastcall Acceleration();
	__property Stage::Vectorgeometry::TRectangle viewport = {read=FViewPort};
	void __fastcall PickObjects(const Winapi::Windows::TRect &rect, Gxs::Selection::TgxPickList* pickList, int objectCountGuess);
	Gxs::Selection::TgxPickList* __fastcall GetPickedObjects(const Winapi::Windows::TRect &rect, int objectCountGuess = 0x40);
	TgxBaseSceneObject* __fastcall GetPickedObject(int x, int y);
	System::Uitypes::TColor __fastcall GetPixelColor(int x, int y);
	float __fastcall GetPixelDepth(int x, int y);
	float __fastcall PixelDepthToDistance(float aDepth);
	float __fastcall PixelToDistance(int x, int y);
	void __fastcall NotifyMouseMove(System::Classes::TShiftState Shift, float x, float y);
	void __fastcall Render(TgxBaseSceneObject* baseObject)/* overload */;
	void __fastcall Render()/* overload */;
	void __fastcall RenderScene(TgxScene* aScene, const int viewPortSizeX, const int viewPortSizeY, Gxs::Rendercontextinfo::TGXDrawState drawState, TgxBaseSceneObject* baseObject);
	void __fastcall RenderToBitmap(Fmx::Graphics::TBitmap* ABitmap, int DPI = 0x0);
	void __fastcall RenderToFile(const System::UnicodeString AFile, int DPI = 0x0)/* overload */;
	void __fastcall RenderToFile(const System::UnicodeString AFile, int bmpWidth, int bmpHeight)/* overload */;
	Gxs::Graphics::TgxImage* __fastcall CreateSnapShot();
	Fmx::Graphics::TBitmap* __fastcall CreateSnapShotBitmap();
	void __fastcall CopyToTexture(Gxs::Texture::TgxTexture* aTexture)/* overload */;
	void __fastcall CopyToTexture(Gxs::Texture::TgxTexture* aTexture, int xSrc, int ySrc, int AWidth, int AHeight, int xDest, int yDest, unsigned glCubeFace = (unsigned)(0x0))/* overload */;
	void __fastcall SaveAsFloatToFile(const System::UnicodeString aFilename);
	__property System::Classes::TNotifyEvent ViewerBeforeRender = {read=FViewerBeforeRender, write=FViewerBeforeRender, stored=false};
	void __fastcall SetViewPort(int x, int y, int W, int H);
	int __fastcall width();
	int __fastcall height();
	__property bool Freezed = {read=FFreezed, nodefault};
	void __fastcall Freeze();
	void __fastcall Melt();
	void __fastcall ShowInfo(bool Modal = false);
	__property bool Rendering = {read=FRendering, nodefault};
	__property float BackgroundAlpha = {read=FBackgroundAlpha, write=SetBackgroundAlpha};
	Stage::Vectortypes::TMatrix4f __fastcall ProjectionMatrix _DEPRECATED_ATTRIBUTE0 ();
	Stage::Vectortypes::TMatrix4f __fastcall ViewMatrix _DEPRECATED_ATTRIBUTE0 ();
	Stage::Vectortypes::TMatrix4f __fastcall ModelMatrix _DEPRECATED_ATTRIBUTE0 ();
	__property Stage::Vectortypes::TMatrix4f BaseProjectionMatrix = {read=FBaseProjectionMatrix};
	void __fastcall PushViewMatrix _DEPRECATED_ATTRIBUTE0 (const Stage::Vectortypes::TMatrix4f &newMatrix);
	void __fastcall PopViewMatrix _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall PushProjectionMatrix _DEPRECATED_ATTRIBUTE0 (const Stage::Vectortypes::TMatrix4f &newMatrix);
	void __fastcall PopProjectionMatrix _DEPRECATED_ATTRIBUTE0 ();
	Stage::Vectorgeometry::TAffineVector __fastcall OrthoScreenToWorld(int screenX, int screenY)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall ScreenToWorld(const Stage::Vectorgeometry::TAffineVector &aPoint)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall ScreenToWorld(const Stage::Vectortypes::TVector4f &aPoint)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall ScreenToWorld(int screenX, int screenY)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall WorldToScreen(const Stage::Vectorgeometry::TAffineVector &aPoint)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall WorldToScreen(const Stage::Vectortypes::TVector4f &aPoint)/* overload */;
	void __fastcall WorldToScreen(Stage::Vectortypes::PVector4f points, int nbPoints)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall ScreenToVector(const Stage::Vectorgeometry::TAffineVector &aPoint)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall ScreenToVector(const Stage::Vectortypes::TVector4f &aPoint)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall ScreenToVector(const int x, const int y)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall VectorToScreen(const Stage::Vectorgeometry::TAffineVector &VectToCam);
	bool __fastcall ScreenVectorIntersectWithPlane(const Stage::Vectortypes::TVector4f &aScreenPoint, const Stage::Vectortypes::TVector4f &planePoint, const Stage::Vectortypes::TVector4f &planeNormal, Stage::Vectortypes::TVector4f &intersectPoint);
	bool __fastcall ScreenVectorIntersectWithPlaneXY(const Stage::Vectortypes::TVector4f &aScreenPoint, const float z, Stage::Vectortypes::TVector4f &intersectPoint);
	bool __fastcall ScreenVectorIntersectWithPlaneYZ(const Stage::Vectortypes::TVector4f &aScreenPoint, const float x, Stage::Vectortypes::TVector4f &intersectPoint);
	bool __fastcall ScreenVectorIntersectWithPlaneXZ(const Stage::Vectortypes::TVector4f &aScreenPoint, const float y, Stage::Vectortypes::TVector4f &intersectPoint);
	Stage::Vectorgeometry::TAffineVector __fastcall PixelRayToWorld(int x, int y);
	__property float LastFrameTime = {read=FLastFrameTime};
	__property float FramesPerSecond = {read=FFramesPerSecond};
	void __fastcall ResetPerformanceMonitor();
	__property int LimitOf[TgxLimitType Which] = {read=GetLimit};
	__property Gxs::Context::TgxContext* RenderingContext = {read=FRenderingContext};
	__property TgxCamera* Camera = {read=FCamera, write=SetCamera};
	__property Gxs::Context::TgxContextLayer Layer = {read=FLayer, write=SetLayer, default=2};
	
__published:
	__property TgxFogEnvironment* FogEnvironment = {read=FFogEnvironment, write=SetFogEnvironment, stored=StoreFog};
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=SetBackgroundColor, default=-16777201};
	__property Gxs::Color::TgxColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property TgxContextOptions ContextOptions = {read=FContextOptions, write=SetContextOptions, default=2058};
	__property int AccumBufferBits = {read=FAccumBufferBits, write=SetAccumBufferBits, default=0};
	__property bool DepthTest = {read=FDepthTest, write=SetDepthTest, default=1};
	__property bool FaceCulling = {read=FFaceCulling, write=SetFaceCulling, default=1};
	__property bool FogEnable = {read=FFogEnable, write=SetFogEnable, default=0};
	__property bool Lighting = {read=FLighting, write=SetLighting, default=1};
	__property Gxs::Context::TgxAntiAliasing AntiAliasing = {read=FAntiAliasing, write=SetAntiAliasing, default=0};
	__property TgxDepthPrecision DepthPrecision = {read=FDepthPrecision, write=SetDepthPrecision, default=0};
	__property TgxColorDepth ColorDepth = {read=FColorDepth, write=SetColorDepth, default=0};
	__property TgxShadeModel ShadeModel = {read=FShadeModel, write=SetShadeModel, default=0};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange, stored=false};
	__property System::Classes::TNotifyEvent OnStructuralChange = {read=FOnStructuralChange, write=FOnStructuralChange, stored=false};
	__property System::Classes::TNotifyEvent BeforeRender = {read=FBeforeRender, write=FBeforeRender, stored=false};
	__property TDirectRenderEvent InitiateRendering = {read=FInitiateRendering, write=FInitiateRendering, stored=false};
	__property TDirectRenderEvent WrapUpRendering = {read=FWrapUpRendering, write=FWrapUpRendering, stored=false};
	__property System::Classes::TNotifyEvent PostRender = {read=FPostRender, write=FPostRender, stored=false};
	__property System::Classes::TNotifyEvent AfterRender = {read=FAfterRender, write=FAfterRender, stored=false};
};


class PASCALIMPLEMENTATION TgxNonVisualViewer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxSceneBuffer* FBuffer;
	int FWidth;
	int FHeight;
	int FCubeMapRotIdx;
	float FCubeMapZNear;
	float FCubeMapZFar;
	Stage::Vectorgeometry::TAffineVector FCubeMapTranslation;
	
protected:
	void __fastcall SetBeforeRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetBeforeRender();
	void __fastcall SetPostRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetPostRender();
	void __fastcall SetAfterRender(const System::Classes::TNotifyEvent val);
	System::Classes::TNotifyEvent __fastcall GetAfterRender();
	void __fastcall SetCamera(TgxCamera* const val);
	TgxCamera* __fastcall GetCamera();
	void __fastcall SetBuffer(TgxSceneBuffer* const val);
	void __fastcall SetWidth(const int val);
	void __fastcall SetHeight(const int val);
	void __fastcall SetupCubeMapCamera(System::TObject* Sender);
	void __fastcall DoOnPrepareVXContext(System::TObject* Sender);
	virtual void __fastcall PrepareVXContext();
	virtual void __fastcall DoBufferChange(System::TObject* Sender);
	virtual void __fastcall DoBufferStructuralChange(System::TObject* Sender);
	
public:
	__fastcall virtual TgxNonVisualViewer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxNonVisualViewer();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Render(TgxBaseSceneObject* baseObject = (TgxBaseSceneObject*)(0x0)) = 0 ;
	virtual void __fastcall CopyToTexture(Gxs::Texture::TgxTexture* aTexture)/* overload */;
	void __fastcall CopyToTexture(Gxs::Texture::TgxTexture* aTexture, int xSrc, int ySrc, int width, int height, int xDest, int yDest)/* overload */;
	virtual void __fastcall CopyToTextureMRT(Gxs::Texture::TgxTexture* aTexture, int BufferIndex)/* overload */;
	void __fastcall CopyToTextureMRT(Gxs::Texture::TgxTexture* aTexture, int xSrc, int ySrc, int width, int height, int xDest, int yDest, int BufferIndex)/* overload */;
	void __fastcall RenderCubeMapTextures(Gxs::Texture::TgxTexture* cubeMapTexture, float zNear = 0.000000E+00f, float zFar = 0.000000E+00f);
	
__published:
	__property TgxCamera* Camera = {read=GetCamera, write=SetCamera};
	__property int width = {read=FWidth, write=SetWidth, default=256};
	__property int height = {read=FHeight, write=SetHeight, default=256};
	__property System::Classes::TNotifyEvent BeforeRender = {read=GetBeforeRender, write=SetBeforeRender};
	__property System::Classes::TNotifyEvent PostRender = {read=GetPostRender, write=SetPostRender};
	__property System::Classes::TNotifyEvent AfterRender = {read=GetAfterRender, write=SetAfterRender};
	__property TgxSceneBuffer* Buffer = {read=FBuffer, write=SetBuffer};
};


class PASCALIMPLEMENTATION TgxMemoryViewer : public TgxNonVisualViewer
{
	typedef TgxNonVisualViewer inherited;
	
private:
	int FBufferCount;
	void __fastcall SetBufferCount(const int Value);
	
public:
	__fastcall virtual TgxMemoryViewer(System::Classes::TComponent* AOwner);
	void __fastcall InstantiateRenderingContext();
	virtual void __fastcall Render(TgxBaseSceneObject* baseObject = (TgxBaseSceneObject*)(0x0));
	
__published:
	__property int BufferCount = {read=FBufferCount, write=SetBufferCount, default=1};
public:
	/* TgxNonVisualViewer.Destroy */ inline __fastcall virtual ~TgxMemoryViewer() { }
	
};


typedef void __fastcall (*TInvokeInfoForm)(TgxSceneBuffer* aSceneBuffer, bool Modal);

//-- var, const, procedure ---------------------------------------------------
#define cDefaultProxyOptions (System::Set<TgxProxyObjectOption, TgxProxyObjectOption::pooEffects, TgxProxyObjectOption::pooTransformation>() << TgxProxyObjectOption::pooEffects << TgxProxyObjectOption::pooObjects << TgxProxyObjectOption::pooTransformation )
#define SCENE_REVISION L"$Revision: 2024$"
#define SCENE_VERSION L"v2.5 %s"
extern DELPHI_PACKAGE __int64 vCounterFrequency;
extern DELPHI_PACKAGE TgxBaseSceneObject* vCurrentRenderingObject;
extern DELPHI_PACKAGE TgxBaseSceneObject* __fastcall GetCurrentRenderingObject(void);
extern DELPHI_PACKAGE void __fastcall AxesBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::Word pattern, float AxisLen);
extern DELPHI_PACKAGE void __fastcall RegisterInfoForm(TInvokeInfoForm infoForm);
extern DELPHI_PACKAGE void __fastcall InvokeInfoForm(TgxSceneBuffer* aSceneBuffer, bool Modal);
extern DELPHI_PACKAGE void __fastcall RegisterBaseSceneObjectNameChangeEvent(System::Classes::TNotifyEvent notifyEvent);
extern DELPHI_PACKAGE void __fastcall DeRegisterBaseSceneObjectNameChangeEvent(System::Classes::TNotifyEvent notifyEvent);
extern DELPHI_PACKAGE void __fastcall RegisterBehaviourNameChangeEvent(System::Classes::TNotifyEvent notifyEvent);
extern DELPHI_PACKAGE void __fastcall DeRegisterBehaviourNameChangeEvent(System::Classes::TNotifyEvent notifyEvent);
}	/* namespace Scene */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SCENE)
using namespace Gxs::Scene;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SceneHPP
