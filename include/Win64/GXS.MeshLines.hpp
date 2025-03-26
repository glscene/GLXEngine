// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MeshLines.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshLinesHPP
#define GXS_MeshLinesHPP

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
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.Spline.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>
#include <GXS.Color.hpp>
#include <GXS.State.hpp>
#include <GXS.Nodes.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Meshlines
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TLineNode;
class DELPHICLASS TLineNodes;
class DELPHICLASS TLineItem;
class DELPHICLASS TLineCollection;
class DELPHICLASS TLightmapBounds;
class DELPHICLASS TgxMeshLines;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TLineNode : public Gxs::Nodes::TgxNode
{
	typedef Gxs::Nodes::TgxNode inherited;
	
private:
	void *FData;
	
public:
	__fastcall virtual TLineNode(System::Classes::TCollection* Collection);
	__fastcall virtual ~TLineNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property void * Data = {read=FData, write=FData};
};


class PASCALIMPLEMENTATION TLineNodes : public Gxs::Nodes::TgxNodes
{
	typedef Gxs::Nodes::TgxNodes inherited;
	
public:
	__fastcall TLineNodes(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TLineNodes();
	virtual void __fastcall NotifyChange();
	int __fastcall IndexOf(TLineNode* LineNode);
};


class PASCALIMPLEMENTATION TLineItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	float FBreakAngle;
	int FDivision;
	TLineNodes* FNodes;
	Gxs::Objects::TgxLineSplineMode FSplineMode;
	float FTextureLength;
	float FWidth;
	bool FTextureCorrection;
	bool FHide;
	void *FData;
	void __fastcall SetHide(const bool Value);
	void __fastcall SetTextureCorrection(const bool Value);
	void __fastcall SetBreakAngle(const float Value);
	void __fastcall SetDivision(const int Value);
	void __fastcall SetNodes(TLineNodes* const Value);
	void __fastcall SetSplineMode(const Gxs::Objects::TgxLineSplineMode Value);
	void __fastcall SetTextureLength(const float Value);
	void __fastcall SetWidth(const float Value);
	
protected:
	virtual void __fastcall DoChanged();
	
public:
	__property void * Data = {read=FData, write=FData};
	
__published:
	__fastcall virtual TLineItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TLineItem();
	__property bool Hide = {read=FHide, write=SetHide, nodefault};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property bool TextureCorrection = {read=FTextureCorrection, write=SetTextureCorrection, nodefault};
	__property float BreakAngle = {read=FBreakAngle, write=SetBreakAngle};
	__property int Division = {read=FDivision, write=SetDivision, nodefault};
	__property TLineNodes* Nodes = {read=FNodes, write=SetNodes};
	__property Gxs::Objects::TgxLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, nodefault};
	__property float TextureLength = {read=FTextureLength, write=SetTextureLength};
	__property float Width = {read=FWidth, write=SetWidth};
};


class PASCALIMPLEMENTATION TLineCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TLineItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	void __fastcall SetItems(int Index, TLineItem* const Val);
	TLineItem* __fastcall GetItems(int Index);
	
public:
	HIDESBASE TLineItem* __fastcall Add()/* overload */;
	HIDESBASE TLineItem* __fastcall Add(System::UnicodeString Name)/* overload */;
	__property TLineItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TLineCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TLineCollection() { }
	
};


class PASCALIMPLEMENTATION TLightmapBounds : public Gxs::Coordinates::TgxCustomCoordinates
{
	typedef Gxs::Coordinates::TgxCustomCoordinates inherited;
	
private:
	float __fastcall GetLeft();
	float __fastcall GetTop();
	float __fastcall GetRight();
	float __fastcall GetBottom();
	float __fastcall GetWidth();
	float __fastcall GetHeight();
	void __fastcall SetLeft(const float value);
	void __fastcall SetTop(const float value);
	void __fastcall SetRight(const float value);
	void __fastcall SetBottom(const float value);
	
__published:
	__property float Left = {read=GetLeft, write=SetLeft, stored=false};
	__property float Top = {read=GetTop, write=SetTop, stored=false};
	__property float Right = {read=GetRight, write=SetRight, stored=false};
	__property float Bottom = {read=GetBottom, write=SetBottom, stored=false};
	__property float Width = {read=GetWidth};
	__property float Height = {read=GetHeight};
public:
	/* TgxCustomCoordinates.CreateInitialized */ inline __fastcall TLightmapBounds(System::Classes::TPersistent* AOwner, const Stage::Vectortypes::TGLVector &AValue, const Gxs::Coordinates::TgxCoordinatesStyle AStyle) : Gxs::Coordinates::TgxCustomCoordinates(AOwner, AValue, AStyle) { }
	/* TgxCustomCoordinates.Destroy */ inline __fastcall virtual ~TLightmapBounds() { }
	
public:
	/* TgxUpdateAbleObject.Create */ inline __fastcall virtual TLightmapBounds(System::Classes::TPersistent* AOwner) : Gxs::Coordinates::TgxCustomCoordinates(AOwner) { }
	
};


class PASCALIMPLEMENTATION TgxMeshLines : public Gxs::Vectorfileobjects::TgxFreeForm
{
	typedef Gxs::Vectorfileobjects::TgxFreeForm inherited;
	
private:
	TLineCollection* FLines;
	Gxs::Vectorfileobjects::TgxMeshObject* FMesh;
	TLightmapBounds* FLightmapBounds;
	int FLightmapIndex;
	System::UnicodeString FLightmapMaterialName;
	Gxs::Vectorfileobjects::TgxFGVertexIndexList* FFaceGroup;
	int FIndex;
	bool FNoZWrite;
	bool FShowNodes;
	int FUpdating;
	TLineItem* FSelectedLineItem;
	TLineNode* FSelectedNode;
	TLineNode* FNode1;
	TLineNode* FNode2;
	bool __fastcall GetUpdating();
	bool __fastcall PointNearLine(TLineItem* const LineItem, const float X, const float Z, float Tolerance = 1.000000E+00f);
	bool __fastcall PointNearSegment(TLineNode* const StartNode, TLineNode* const EndNode, const float X, const float Z, float LineWidth, float Tolerance = 1.000000E+00f);
	void __fastcall StitchStrips(Gxs::Vectorlists::TgxIntegerList* idx);
	void __fastcall AddStitchMarker(Gxs::Vectorlists::TgxIntegerList* idx);
	void __fastcall SetShowNodes(const bool Value);
	void __fastcall SetNoZWrite(const bool Value);
	void __fastcall SetLightmapIndex(const int value);
	void __fastcall SetLightmapMaterialName(const System::UnicodeString value);
	void __fastcall SetLightmapBounds(TLightmapBounds* const value);
	void __fastcall DoChanged();
	void __fastcall AddIndex();
	void __fastcall AddVertices(const Stage::Vectorgeometry::TAffineVector &Up, const Stage::Vectorgeometry::TAffineVector &Inner, const Stage::Vectorgeometry::TAffineVector &Outer, float S, float Correction, bool UseDegenerate, TLineItem* LineItem);
	void __fastcall BuildLineItem(TLineItem* LineItem);
	void __fastcall BuildGeometry();
	void __fastcall DrawNode(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, TLineNode* Node, float LineWidth);
	void __fastcall DrawCircle(float Radius);
	TLineNode* __fastcall SelectNode(TLineItem* LineItem, float X, float Z);
	
protected:
	virtual void __fastcall Loaded();
	
public:
	HIDESBASE void __fastcall BeginUpdate();
	HIDESBASE void __fastcall EndUpdate();
	void __fastcall Clear();
	TLineItem* __fastcall SelectLineItem(const float X, const float Z, float Tolerance = 1.000000E+00f)/* overload */;
	TLineItem* __fastcall SelectLineItem(TLineItem* LineItem)/* overload */;
	TLineItem* __fastcall SelectLineItem(TLineNode* LineNode)/* overload */;
	void __fastcall DeselectLineItem();
	void __fastcall DeselectLineNode();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	__property TLineItem* SelectedLineItem = {read=FSelectedLineItem};
	__property TLineNode* SelectedNode = {read=FSelectedNode};
	__property TLineNode* Node1 = {read=FNode1};
	__property TLineNode* Node2 = {read=FNode2};
	
__published:
	__fastcall virtual TgxMeshLines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMeshLines();
	__property bool Updating = {read=GetUpdating, nodefault};
	__property TLineCollection* Lines = {read=FLines};
	__property Material;
	__property TLightmapBounds* LightmapBounds = {read=FLightmapBounds, write=SetLightmapBounds};
	__property int LightmapIndex = {read=FLightmapIndex, write=SetLightmapIndex, nodefault};
	__property System::UnicodeString LightmapMaterialName = {read=FLightmapMaterialName, write=SetLightmapMaterialName};
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, nodefault};
	__property bool ShowNodes = {read=FShowNodes, write=SetShowNodes, nodefault};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMeshLines(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxFreeForm(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Meshlines */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESHLINES)
using namespace Gxs::Meshlines;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshLinesHPP
