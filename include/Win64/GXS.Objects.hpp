// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Objects.pas' rev: 36.00 (Windows)

#ifndef GXS_ObjectsHPP
#define GXS_ObjectsHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Nodes.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Objects
{
//-- forward type declarations -----------------------------------------------
struct TVertexRec;
class DELPHICLASS TgxDummyCube;
class DELPHICLASS TgxPlane;
class DELPHICLASS TgxSprite;
class DELPHICLASS TgxPointParameters;
class DELPHICLASS TgxPoints;
class DELPHICLASS TgxLinesNode;
class DELPHICLASS TgxLinesNodes;
class DELPHICLASS TgxLineBase;
class DELPHICLASS TgxNodedLines;
class DELPHICLASS TgxLines;
class DELPHICLASS TgxCube;
class DELPHICLASS TgxQuadricObject;
class DELPHICLASS TgxSphere;
class DELPHICLASS TgxPolygonBase;
class DELPHICLASS TgxSuperellipsoid;
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TgxVisibilityDeterminationEvent)(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);

typedef TVertexRec *PVertexRec;

struct DECLSPEC_DRECORD TVertexRec
{
public:
	Stage::Vectortypes::TVector3f Position;
	Stage::Vectortypes::TVector3f Normal;
	Stage::Vectortypes::TVector3f Binormal;
	Stage::Vectortypes::TVector3f Tangent;
	Stage::Vectortypes::TVector2f TexCoord;
};


class PASCALIMPLEMENTATION TgxDummyCube : public Gxs::Scene::TgxCameraInvariantObject
{
	typedef Gxs::Scene::TgxCameraInvariantObject inherited;
	
private:
	float FCubeSize;
	Gxs::Color::TgxColor* FEdgeColor;
	bool FVisibleAtRunTime;
	bool FAmalgamate;
	Gxs::Context::TgxListHandle* FGroupList;
	TgxVisibilityDeterminationEvent FOnVisibilityDetermination;
	
protected:
	void __fastcall SetCubeSize(const float val);
	void __fastcall SetEdgeColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetVisibleAtRunTime(const bool val);
	void __fastcall SetAmalgamate(const bool val);
	
public:
	__fastcall virtual TgxDummyCube(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxDummyCube();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall StructureChanged();
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	
__published:
	__property float CubeSize = {read=FCubeSize, write=SetCubeSize};
	__property Gxs::Color::TgxColor* EdgeColor = {read=FEdgeColor, write=SetEdgeColor};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, default=0};
	__property bool Amalgamate = {read=FAmalgamate, write=SetAmalgamate, default=0};
	__property CamInvarianceMode = {default=0};
	__property TgxVisibilityDeterminationEvent OnVisibilityDetermination = {read=FOnVisibilityDetermination, write=FOnVisibilityDetermination};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxDummyCube(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxCameraInvariantObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxPlaneStyle : unsigned char { psSingleQuad, psTileTexture };

typedef System::Set<TgxPlaneStyle, TgxPlaneStyle::psSingleQuad, TgxPlaneStyle::psTileTexture> TgxPlaneStyles;

class PASCALIMPLEMENTATION TgxPlane : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<TVertexRec> _TgxPlane__1;
	
	typedef System::DynamicArray<System::DynamicArray<TVertexRec> > _TgxPlane__2;
	
	
private:
	float FXOffset;
	float FYOffset;
	float FXScope;
	float FYScope;
	float FWidth;
	float FHeight;
	unsigned FXTiles;
	unsigned FYTiles;
	TgxPlaneStyles FStyle;
	_TgxPlane__2 FMesh;
	
protected:
	void __fastcall SetHeight(const float aValue);
	void __fastcall SetWidth(const float aValue);
	void __fastcall SetXOffset(const float Value);
	void __fastcall SetXScope(const float Value);
	bool __fastcall StoreXScope();
	void __fastcall SetXTiles(const unsigned Value);
	void __fastcall SetYOffset(const float Value);
	void __fastcall SetYScope(const float Value);
	bool __fastcall StoreYScope();
	void __fastcall SetYTiles(const unsigned Value);
	void __fastcall SetStyle(const TgxPlaneStyles val);
	
public:
	__fastcall virtual TgxPlane(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	System::Types::TRect __fastcall ScreenRect(Gxs::Scene::TgxSceneBuffer* aBuffer);
	float __fastcall PointDistance(const Stage::Vectortypes::TVector4f &aPoint);
	
__published:
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Width = {read=FWidth, write=SetWidth};
	__property float XOffset = {read=FXOffset, write=SetXOffset};
	__property float XScope = {read=FXScope, write=SetXScope, stored=StoreXScope};
	__property unsigned XTiles = {read=FXTiles, write=SetXTiles, default=1};
	__property float YOffset = {read=FYOffset, write=SetYOffset};
	__property float YScope = {read=FYScope, write=SetYScope, stored=StoreYScope};
	__property unsigned YTiles = {read=FYTiles, write=SetYTiles, default=1};
	__property TgxPlaneStyles Style = {read=FStyle, write=SetStyle, default=3};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxPlane() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPlane(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxSprite : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	float FWidth;
	float FHeight;
	float FRotation;
	float FAlphaChannel;
	bool FMirrorU;
	bool FMirrorV;
	
protected:
	void __fastcall SetWidth(const float val);
	void __fastcall SetHeight(const float val);
	HIDESBASE void __fastcall SetRotation(const float val);
	void __fastcall SetAlphaChannel(const float val);
	bool __fastcall StoreAlphaChannel();
	void __fastcall SetMirrorU(const bool val);
	void __fastcall SetMirrorV(const bool val);
	
public:
	__fastcall virtual TgxSprite(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall SetSize(const float Width, const float Height);
	void __fastcall SetSquareSize(const float Size);
	
__published:
	__property float Width = {read=FWidth, write=SetWidth};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Rotation = {read=FRotation, write=SetRotation};
	__property float AlphaChannel = {read=FAlphaChannel, write=SetAlphaChannel, stored=StoreAlphaChannel};
	__property bool MirrorU = {read=FMirrorU, write=SetMirrorU, default=0};
	__property bool MirrorV = {read=FMirrorV, write=SetMirrorV, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxSprite() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSprite(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxPointStyle : unsigned char { psSquare, psRound, psSmooth, psSmoothAdditive, psSquareAdditive };

class PASCALIMPLEMENTATION TgxPointParameters : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	bool FEnabled;
	float FMinSize;
	float FMaxSize;
	float FFadeTresholdSize;
	Gxs::Coordinates::TgxCoordinates* FDistanceAttenuation;
	
protected:
	void __fastcall SetEnabled(const bool val);
	void __fastcall SetMinSize(const float val);
	void __fastcall SetMaxSize(const float val);
	void __fastcall SetFadeTresholdSize(const float val);
	void __fastcall SetDistanceAttenuation(Gxs::Coordinates::TgxCoordinates* const val);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TgxPointParameters(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxPointParameters();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Apply();
	void __fastcall UnApply();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=0};
	__property float MinSize = {read=FMinSize, write=SetMinSize, stored=false};
	__property float MaxSize = {read=FMaxSize, write=SetMaxSize, stored=false};
	__property float FadeTresholdSize = {read=FFadeTresholdSize, write=SetFadeTresholdSize, stored=false};
	__property Gxs::Coordinates::TgxCoordinates* DistanceAttenuation = {read=FDistanceAttenuation, write=SetDistanceAttenuation};
};


class PASCALIMPLEMENTATION TgxPoints : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	Gxs::Vectorlists::TgxAffineVectorList* FPositions;
	Gxs::Vectorlists::TgxVectorList* FColors;
	float FSize;
	TgxPointStyle FStyle;
	TgxPointParameters* FPointParameters;
	bool FStatic;
	bool FNoZWrite;
	
protected:
	bool __fastcall StoreSize();
	void __fastcall SetNoZWrite(const bool val);
	void __fastcall SetStatic(const bool val);
	void __fastcall SetSize(const float val);
	void __fastcall SetPositions(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetColors(Gxs::Vectorlists::TgxVectorList* const val);
	void __fastcall SetStyle(const TgxPointStyle val);
	void __fastcall SetPointParameters(TgxPointParameters* const val);
	
public:
	__fastcall virtual TgxPoints(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPoints();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property Gxs::Vectorlists::TgxAffineVectorList* Positions = {read=FPositions, write=SetPositions};
	__property Gxs::Vectorlists::TgxVectorList* Colors = {read=FColors, write=SetColors};
	
__published:
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, nodefault};
	__property bool Static = {read=FStatic, write=SetStatic, nodefault};
	__property float Size = {read=FSize, write=SetSize, stored=StoreSize};
	__property TgxPointStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property TgxPointParameters* PointParameters = {read=FPointParameters, write=SetPointParameters};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPoints(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TLineNodesAspect : unsigned char { lnaInvisible, lnaAxes, lnaCube };

enum DECLSPEC_DENUM TgxLineSplineMode : unsigned char { lsmLines, lsmCubicSpline, lsmBezierSpline, lsmNURBSCurve, lsmSegments, lsmLoop };

class PASCALIMPLEMENTATION TgxLinesNode : public Gxs::Nodes::TgxNode
{
	typedef Gxs::Nodes::TgxNode inherited;
	
private:
	Gxs::Color::TgxColor* FColor;
	
protected:
	void __fastcall SetColor(Gxs::Color::TgxColor* const val);
	void __fastcall OnColorChange(System::TObject* Sender);
	bool __fastcall StoreColor();
	
public:
	__fastcall virtual TgxLinesNode(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxLinesNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Color::TgxColor* Color = {read=FColor, write=SetColor, stored=StoreColor};
};


class PASCALIMPLEMENTATION TgxLinesNodes : public Gxs::Nodes::TgxNodes
{
	typedef Gxs::Nodes::TgxNodes inherited;
	
public:
	__fastcall TgxLinesNodes(System::Classes::TComponent* AOwner)/* overload */;
	virtual void __fastcall NotifyChange();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxLinesNodes() { }
	
};


class PASCALIMPLEMENTATION TgxLineBase : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	Gxs::Color::TgxColor* FLineColor;
	System::Word FLinePattern;
	float FLineWidth;
	bool FAntiAliased;
	
protected:
	void __fastcall SetLineColor(Gxs::Color::TgxColor* const Value);
	void __fastcall SetLinePattern(const System::Word Value);
	void __fastcall SetLineWidth(const float val);
	bool __fastcall StoreLineWidth();
	void __fastcall SetAntiAliased(const bool val);
	void __fastcall SetupLineStyle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxLineBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxLineBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property bool AntiAliased = {read=FAntiAliased, write=SetAntiAliased, default=0};
	__property Gxs::Color::TgxColor* LineColor = {read=FLineColor, write=SetLineColor};
	__property System::Word LinePattern = {read=FLinePattern, write=SetLinePattern, default=65535};
	__property float LineWidth = {read=FLineWidth, write=SetLineWidth, stored=StoreLineWidth};
	__property Visible = {default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxLineBase(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxNodedLines : public TgxLineBase
{
	typedef TgxLineBase inherited;
	
private:
	TgxLinesNodes* FNodes;
	TLineNodesAspect FNodesAspect;
	Gxs::Color::TgxColor* FNodeColor;
	float FNodeSize;
	Gxs::Color::TgxColorVector FOldNodeColor;
	
protected:
	void __fastcall SetNodesAspect(const TLineNodesAspect Value);
	void __fastcall SetNodeColor(Gxs::Color::TgxColor* const Value);
	void __fastcall OnNodeColorChanged(System::TObject* Sender);
	void __fastcall SetNodes(TgxLinesNodes* const aNodes);
	void __fastcall SetNodeSize(const float val);
	bool __fastcall StoreNodeSize();
	void __fastcall DrawNode(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, float X, float Y, float Z, Gxs::Color::TgxColor* Color);
	
public:
	__fastcall virtual TgxNodedLines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxNodedLines();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall AddNode(Gxs::Coordinates::TgxCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const float X, const float Y, const float Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TVector4f &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	
__published:
	__property Gxs::Color::TgxColor* NodeColor = {read=FNodeColor, write=SetNodeColor};
	__property TgxLinesNodes* Nodes = {read=FNodes, write=SetNodes};
	__property TLineNodesAspect NodesAspect = {read=FNodesAspect, write=SetNodesAspect, default=1};
	__property float NodeSize = {read=FNodeSize, write=SetNodeSize, stored=StoreNodeSize};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxNodedLines(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxLineBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TLinesOption : unsigned char { loUseNodeColorForLines, loColorLogicXor };

typedef System::Set<TLinesOption, TLinesOption::loUseNodeColorForLines, TLinesOption::loColorLogicXor> TgxLinesOptions;

class PASCALIMPLEMENTATION TgxLines : public TgxNodedLines
{
	typedef TgxNodedLines inherited;
	
private:
	int FDivision;
	TgxLineSplineMode FSplineMode;
	TgxLinesOptions FOptions;
	int FNURBSOrder;
	float FNURBSTolerance;
	Gxs::Vectorlists::TgxSingleList* FNURBSKnots;
	
protected:
	void __fastcall SetSplineMode(const TgxLineSplineMode val);
	void __fastcall SetDivision(const int Value);
	void __fastcall SetOptions(const TgxLinesOptions val);
	void __fastcall SetNURBSOrder(const int val);
	void __fastcall SetNURBSTolerance(const float val);
	
public:
	__fastcall virtual TgxLines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxLines();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property Gxs::Vectorlists::TgxSingleList* NURBSKnots = {read=FNURBSKnots};
	__property int NURBSOrder = {read=FNURBSOrder, write=SetNURBSOrder, nodefault};
	__property float NURBSTolerance = {read=FNURBSTolerance, write=SetNURBSTolerance};
	
__published:
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property TgxLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
	__property TgxLinesOptions Options = {read=FOptions, write=SetOptions, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxLines(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxNodedLines(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxCubePart : unsigned char { cpTop, cpBottom, cpFront, cpBack, cpLeft, cpRight };

typedef System::Set<TgxCubePart, TgxCubePart::cpTop, TgxCubePart::cpRight> TgxCubeParts;

class PASCALIMPLEMENTATION TgxCube : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FCubeSize;
	TgxCubeParts FParts;
	Gxs::Scene::TgxNormalDirection FNormalDirection;
	float __fastcall GetCubeWHD(const int Index);
	void __fastcall SetCubeWHD(int Index, float AValue);
	void __fastcall SetParts(TgxCubeParts aValue);
	void __fastcall SetNormalDirection(Gxs::Scene::TgxNormalDirection aValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TgxCube(System::Classes::TComponent* AOwner);
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &SilhouetteParameters);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property float CubeWidth = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=0};
	__property float CubeHeight = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=1};
	__property float CubeDepth = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=2};
	__property Gxs::Scene::TgxNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
	__property TgxCubeParts Parts = {read=FParts, write=SetParts, default=63};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCube() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCube(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxNormalSmoothing : unsigned char { nsFlat, nsSmooth, nsNone };

class PASCALIMPLEMENTATION TgxQuadricObject : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxNormalSmoothing FNormals;
	Gxs::Scene::TgxNormalDirection FNormalDirection;
	
protected:
	void __fastcall SetNormals(TgxNormalSmoothing aValue);
	void __fastcall SetNormalDirection(Gxs::Scene::TgxNormalDirection aValue);
	void __fastcall SetupQuadricParams(GLUquadricObj quadric);
	void __fastcall SetNormalQuadricOrientation(GLUquadricObj quadric);
	void __fastcall SetInvertedQuadricOrientation(GLUquadricObj quadric);
	
public:
	__fastcall virtual TgxQuadricObject(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TgxNormalSmoothing Normals = {read=FNormals, write=SetNormals, default=1};
	__property Gxs::Scene::TgxNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxQuadricObject() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxQuadricObject(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


typedef System::Int8 TAngleLimit1;

typedef System::Word TAngleLimit2;

enum DECLSPEC_DENUM TgxCapType : unsigned char { ctNone, ctCenter, ctFlat };

class PASCALIMPLEMENTATION TgxSphere : public TgxQuadricObject
{
	typedef TgxQuadricObject inherited;
	
private:
	float FRadius;
	int FSlices;
	int FStacks;
	TAngleLimit1 FTop;
	TAngleLimit1 FBottom;
	TAngleLimit2 FStart;
	TAngleLimit2 FStop;
	TgxCapType FTopCap;
	TgxCapType FBottomCap;
	void __fastcall SetBottom(TAngleLimit1 aValue);
	void __fastcall SetBottomCap(TgxCapType aValue);
	void __fastcall SetRadius(const float aValue);
	void __fastcall SetSlices(int aValue);
	void __fastcall SetStart(TAngleLimit2 aValue);
	void __fastcall SetStop(TAngleLimit2 aValue);
	void __fastcall SetStacks(int aValue);
	void __fastcall SetTop(TAngleLimit1 aValue);
	void __fastcall SetTopCap(TgxCapType aValue);
	
public:
	__fastcall virtual TgxSphere(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TAngleLimit1 Bottom = {read=FBottom, write=SetBottom, default=-90};
	__property TgxCapType BottomCap = {read=FBottomCap, write=SetBottomCap, default=0};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property int Stacks = {read=FStacks, write=SetStacks, default=16};
	__property TAngleLimit2 Start = {read=FStart, write=SetStart, default=0};
	__property TAngleLimit2 Stop = {read=FStop, write=SetStop, default=360};
	__property TAngleLimit1 Top = {read=FTop, write=SetTop, default=90};
	__property TgxCapType TopCap = {read=FTopCap, write=SetTopCap, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxSphere() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSphere(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxQuadricObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxPolygonBase : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	int FDivision;
	TgxLineSplineMode FSplineMode;
	
protected:
	Gxs::Nodes::TgxNodes* FNodes;
	virtual void __fastcall CreateNodes();
	void __fastcall SetSplineMode(const TgxLineSplineMode val);
	void __fastcall SetDivision(const int Value);
	void __fastcall SetNodes(Gxs::Nodes::TgxNodes* const aNodes);
	
public:
	__fastcall virtual TgxPolygonBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPolygonBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall AddNode(Gxs::Coordinates::TgxCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const float X, const float Y, const float Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TVector4f &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	
__published:
	__property Gxs::Nodes::TgxNodes* Nodes = {read=FNodes, write=SetNodes};
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property TgxLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPolygonBase(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxSuperellipsoid : public TgxQuadricObject
{
	typedef TgxQuadricObject inherited;
	
private:
	float FRadius;
	float FVCurve;
	float FHCurve;
	int FSlices;
	int FStacks;
	TAngleLimit1 FTop;
	TAngleLimit1 FBottom;
	TAngleLimit2 FStart;
	TAngleLimit2 FStop;
	TgxCapType FTopCap;
	TgxCapType FBottomCap;
	void __fastcall SetBottom(TAngleLimit1 aValue);
	void __fastcall SetBottomCap(TgxCapType aValue);
	void __fastcall SetRadius(const float aValue);
	void __fastcall SetVCurve(const float aValue);
	void __fastcall SetHCurve(const float aValue);
	void __fastcall SetSlices(int aValue);
	void __fastcall SetStart(TAngleLimit2 aValue);
	void __fastcall SetStop(TAngleLimit2 aValue);
	void __fastcall SetStacks(int aValue);
	void __fastcall SetTop(TAngleLimit1 aValue);
	void __fastcall SetTopCap(TgxCapType aValue);
	
public:
	__fastcall virtual TgxSuperellipsoid(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TAngleLimit1 Bottom = {read=FBottom, write=SetBottom, default=-90};
	__property TgxCapType BottomCap = {read=FBottomCap, write=SetBottomCap, default=0};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float VCurve = {read=FVCurve, write=SetVCurve};
	__property float HCurve = {read=FHCurve, write=SetHCurve};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property int Stacks = {read=FStacks, write=SetStacks, default=16};
	__property TAngleLimit2 Start = {read=FStart, write=SetStart, default=0};
	__property TAngleLimit2 Stop = {read=FStop, write=SetStop, default=360};
	__property TAngleLimit1 Top = {read=FTop, write=SetTop, default=90};
	__property TgxCapType TopCap = {read=FTopCap, write=SetTopCap, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxSuperellipsoid() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSuperellipsoid(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxQuadricObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float cDefaultPointSize;
extern DELPHI_PACKAGE System::AnsiString TangentAttributeName;
extern DELPHI_PACKAGE System::AnsiString BinormalAttributeName;
extern DELPHI_PACKAGE void __fastcall CubeWireframeBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, float Size, bool Stipple, const Gxs::Color::TgxColorVector &Color);
}	/* namespace Objects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_OBJECTS)
using namespace Gxs::Objects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ObjectsHPP
