// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MultiPolygon.pas' rev: 36.00 (Windows)

#ifndef GXS_MultiPolygonHPP
#define GXS_MultiPolygonHPP

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
#include <GXS.XOpenGL.hpp>
#include <Stage.Spline.hpp>
#include <GXS.Context.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.Nodes.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Multipolygon
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxContourNodes;
class DELPHICLASS TgxContour;
class DELPHICLASS TgxContours;
class DELPHICLASS TgxPolygonList;
class DELPHICLASS TgxMultiPolygonBase;
class DELPHICLASS TgxMultiPolygon;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxContourNodes : public Gxs::Nodes::TgxNodes
{
	typedef Gxs::Nodes::TgxNodes inherited;
	
public:
	virtual void __fastcall NotifyChange();
public:
	/* TgxNodes.Create */ inline __fastcall TgxContourNodes(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass) : Gxs::Nodes::TgxNodes(AOwner, AItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxContourNodes() { }
	
};


class PASCALIMPLEMENTATION TgxContour : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TgxContourNodes* FNodes;
	int FDivision;
	Gxs::Objects::TgxLineSplineMode FSplineMode;
	System::UnicodeString FDescription;
	void __fastcall SetNodes(TgxContourNodes* const Value);
	void __fastcall SetDivision(int Value);
	void __fastcall SetSplineMode(const Gxs::Objects::TgxLineSplineMode Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall CreateNodes();
	void __fastcall NodesChanged(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxContour(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxContour();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription};
	__property TgxContourNodes* Nodes = {read=FNodes, write=SetNodes};
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property Gxs::Objects::TgxLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
};


_DECLARE_METACLASS(System::TMetaClass, TgxContourClass);

class PASCALIMPLEMENTATION TgxContours : public Gxs::Baseclasses::TGNotifyCollection
{
	typedef Gxs::Baseclasses::TGNotifyCollection inherited;
	
public:
	TgxContour* operator[](int index) { return this->Items[index]; }
	
private:
	TgxContour* __fastcall GetItems(int index);
	void __fastcall SetItems(int index, TgxContour* const Value);
	
public:
	__fastcall TgxContours(System::Classes::TComponent* AOwner)/* overload */;
	HIDESBASE TgxContour* __fastcall Add();
	HIDESBASE TgxContour* __fastcall FindItemID(int ID);
	__property TgxContour* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxContours() { }
	
};


class PASCALIMPLEMENTATION TgxPolygonList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
private:
	Gxs::Vectorlists::TgxAffineVectorList* FAktList;
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall GetList(int I);
	
public:
	HIDESBASE void __fastcall Add();
	__property Gxs::Vectorlists::TgxAffineVectorList* AktList = {read=FAktList};
	__property Gxs::Vectorlists::TgxAffineVectorList* List[int I] = {read=GetList};
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxPolygonList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	/* TgxPersistentObjectList.Destroy */ inline __fastcall virtual ~TgxPolygonList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxPolygonList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxMultiPolygonBase : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxContours* FContours;
	TgxPolygonList* FOutline;
	Stage::Vectorgeometry::TAffineVector FContoursNormal;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	void __fastcall SetContours(TgxContours* const Value);
	TgxContourNodes* __fastcall GetPath(int i);
	void __fastcall SetPath(int i, TgxContourNodes* const value);
	TgxPolygonList* __fastcall GetOutline();
	void __fastcall SetContoursNormal(const Stage::Vectorgeometry::TAffineVector &Value);
	
protected:
	void __fastcall RenderTesselatedPolygon(bool textured, Stage::Vectorgeometry::PAffineVector normal, bool invertNormals);
	void __fastcall RetrieveOutline(TgxPolygonList* List);
	virtual void __fastcall ContourChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TgxMultiPolygonBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMultiPolygonBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddNode(const int i, Gxs::Coordinates::TgxCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const int i, const float X, const float Y, const float Z)/* overload */;
	void __fastcall AddNode(const int i, const Stage::Vectortypes::TVector4f &value)/* overload */;
	void __fastcall AddNode(const int i, const Stage::Vectorgeometry::TAffineVector &value)/* overload */;
	__property TgxContourNodes* Path[int i] = {read=GetPath, write=SetPath};
	__property TgxPolygonList* Outline = {read=GetOutline};
	__property Stage::Vectorgeometry::TAffineVector ContoursNormal = {read=FContoursNormal, write=SetContoursNormal};
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall StructureChanged();
	
__published:
	__property TgxContours* Contours = {read=FContours, write=SetContours};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMultiPolygonBase(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxMultiPolygon : public TgxMultiPolygonBase
{
	typedef TgxMultiPolygonBase inherited;
	
private:
	Gxs::Geomobjects::TgxPolygonParts FParts;
	
protected:
	void __fastcall SetParts(const Gxs::Geomobjects::TgxPolygonParts value);
	
public:
	__fastcall virtual TgxMultiPolygon(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property Gxs::Geomobjects::TgxPolygonParts Parts = {read=FParts, write=SetParts, default=3};
public:
	/* TgxMultiPolygonBase.Destroy */ inline __fastcall virtual ~TgxMultiPolygon() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMultiPolygon(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxMultiPolygonBase(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Multipolygon */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MULTIPOLYGON)
using namespace Gxs::Multipolygon;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MultiPolygonHPP
