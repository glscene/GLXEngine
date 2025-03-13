// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.MultiPolygon.pas' rev: 36.00 (Windows)

#ifndef GLS_MultiPolygonHPP
#define GLS_MultiPolygonHPP

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
#include <Stage.OpenGLTokens.hpp>
#include <GLS.OpenGLAdapter.hpp>
#include <Stage.Spline.hpp>
#include <GLS.XOpenGL.hpp>
#include <GLS.Context.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Objects.hpp>
#include <GLS.GeomObjects.hpp>
#include <GLS.Nodes.hpp>
#include <GLS.BaseClasses.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Multipolygon
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLContourNodes;
class DELPHICLASS TGLContour;
class DELPHICLASS TGLContours;
class DELPHICLASS TGLPolygonList;
class DELPHICLASS TGLMultiPolygonBase;
class DELPHICLASS TGLMultiPolygon;
class DELPHICLASS TGLVectorPool;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLContourNodes : public Gls::Nodes::TGLNodes
{
	typedef Gls::Nodes::TGLNodes inherited;
	
public:
	virtual void __fastcall NotifyChange();
public:
	/* TGLNodes.Create */ inline __fastcall TGLContourNodes(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass) : Gls::Nodes::TGLNodes(AOwner, AItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLContourNodes() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLContour : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TGLContourNodes* FNodes;
	int FDivision;
	Gls::Objects::TGLLineSplineMode FSplineMode;
	System::UnicodeString FDescription;
	void __fastcall SetNodes(TGLContourNodes* const Value);
	void __fastcall SetDivision(int Value);
	void __fastcall SetSplineMode(const Gls::Objects::TGLLineSplineMode Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	
protected:
	void __fastcall CreateNodes();
	void __fastcall NodesChanged(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TGLContour(System::Classes::TCollection* Collection);
	__fastcall virtual ~TGLContour();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription};
	__property TGLContourNodes* Nodes = {read=FNodes, write=SetNodes};
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property Gls::Objects::TGLLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
};

#pragma pack(pop)

typedef System::TMetaClass* TGLContourClass;

class PASCALIMPLEMENTATION TGLContours : public Gls::Baseclasses::TGNotifyCollection
{
	typedef Gls::Baseclasses::TGNotifyCollection inherited;
	
public:
	TGLContour* operator[](int index) { return this->Items[index]; }
	
private:
	TGLContour* __fastcall GetItems(int index);
	void __fastcall SetItems(int index, TGLContour* const Value);
	
public:
	__fastcall TGLContours(System::Classes::TComponent* AOwner)/* overload */;
	HIDESBASE TGLContour* __fastcall Add();
	HIDESBASE TGLContour* __fastcall FindItemID(int ID);
	__property TGLContour* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLContours() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLPolygonList : public Gls::Persistentclasses::TGLPersistentObjectList
{
	typedef Gls::Persistentclasses::TGLPersistentObjectList inherited;
	
private:
	Gls::Vectorlists::TGLAffineVectorList* FAktList;
	Gls::Vectorlists::TGLAffineVectorList* __fastcall GetList(int I);
	
public:
	HIDESBASE void __fastcall Add();
	__property Gls::Vectorlists::TGLAffineVectorList* AktList = {read=FAktList};
	__property Gls::Vectorlists::TGLAffineVectorList* List[int I] = {read=GetList};
public:
	/* TGLPersistentObjectList.Create */ inline __fastcall virtual TGLPolygonList() : Gls::Persistentclasses::TGLPersistentObjectList() { }
	/* TGLPersistentObjectList.Destroy */ inline __fastcall virtual ~TGLPolygonList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLPolygonList(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Persistentclasses::TGLPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLMultiPolygonBase : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	TGLContours* FContours;
	TGLPolygonList* FOutline;
	Stage::Vectorgeometry::TAffineVector FContoursNormal;
	Stage::Vectortypes::TGLVector FAxisAlignedDimensionsCache;
	void __fastcall SetContours(TGLContours* const Value);
	TGLContourNodes* __fastcall GetPath(int i);
	void __fastcall SetPath(int i, TGLContourNodes* const value);
	TGLPolygonList* __fastcall GetOutline();
	void __fastcall SetContoursNormal(const Stage::Vectorgeometry::TAffineVector &Value);
	
protected:
	void __fastcall RenderTesselatedPolygon(bool textured, Stage::Vectorgeometry::PAffineVector normal, bool invertNormals);
	void __fastcall RetrieveOutline(TGLPolygonList* List);
	virtual void __fastcall ContourChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TGLMultiPolygonBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLMultiPolygonBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddNode(const int i, Gls::Coordinates::TGLCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const int i, const Stage::Opengltokens::TGLfloat X, const Stage::Opengltokens::TGLfloat Y, const Stage::Opengltokens::TGLfloat Z)/* overload */;
	void __fastcall AddNode(const int i, const Stage::Vectortypes::TGLVector &value)/* overload */;
	void __fastcall AddNode(const int i, const Stage::Vectorgeometry::TAffineVector &value)/* overload */;
	__property TGLContourNodes* Path[int i] = {read=GetPath, write=SetPath};
	__property TGLPolygonList* Outline = {read=GetOutline};
	__property Stage::Vectorgeometry::TAffineVector ContoursNormal = {read=FContoursNormal, write=SetContoursNormal};
	virtual Stage::Vectortypes::TGLVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall StructureChanged();
	
__published:
	__property TGLContours* Contours = {read=FContours, write=SetContours};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLMultiPolygonBase(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLMultiPolygon : public TGLMultiPolygonBase
{
	typedef TGLMultiPolygonBase inherited;
	
private:
	Gls::Geomobjects::TGLPolygonParts FParts;
	
protected:
	void __fastcall SetParts(const Gls::Geomobjects::TGLPolygonParts value);
	
public:
	__fastcall virtual TGLMultiPolygon(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
__published:
	__property Gls::Geomobjects::TGLPolygonParts Parts = {read=FParts, write=SetParts, default=3};
public:
	/* TGLMultiPolygonBase.Destroy */ inline __fastcall virtual ~TGLMultiPolygon() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLMultiPolygon(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLMultiPolygonBase(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVectorPool : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	int FEntrySize;
	int FPageSize;
	int FArrSize;
	int FUsedEntries;
	Stage::Vectorgeometry::PByteArray FAktArray;
	void __fastcall CreatePage();
	
public:
	__fastcall TGLVectorPool(int APageSize, int AEntrySize);
	__fastcall virtual ~TGLVectorPool();
	void __fastcall GetNewVector(void * &P);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Multipolygon */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_MULTIPOLYGON)
using namespace Gls::Multipolygon;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_MultiPolygonHPP
