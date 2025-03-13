// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.VerletClothify.pas' rev: 36.00 (Windows)

#ifndef GXS_VerletClothifyHPP
#define GXS_VerletClothifyHPP

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
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VerletTypes.hpp>
#include <GXS.Texture.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>
#include <GXS.SpacePartition.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Verletclothify
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TFace;
class DELPHICLASS TFaceList;
class DELPHICLASS TFaceExtractor;
class DELPHICLASS TEdge;
class DELPHICLASS TEdgeList;
class DELPHICLASS TEdgeDetector;
class DELPHICLASS TgxMeshObjectVerletNode;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TFace : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::StaticArray<int, 3> Vertices;
	Stage::Vectorgeometry::TAffineVector Normal;
	Gxs::Vectorfileobjects::TgxMeshObject* MeshObject;
	bool Active;
	void __fastcall UpdateNormal();
	__fastcall TFace(Gxs::Vectorfileobjects::TgxMeshObject* aMeshObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TFace() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFaceList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TFace* operator[](int i) { return this->Items[i]; }
	
private:
	TFace* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TFace* const Value);
	
public:
	__property TFace* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TFaceList() { }
	
public:
	/* TObject.Create */ inline __fastcall TFaceList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFaceExtractor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TFaceList* FFaceList;
	Gxs::Vectorfileobjects::TgxBaseMesh* FGLBaseMesh;
	Gxs::Verlettypes::TgxVerletNodeList* FNodeList;
	float FWeldDistance;
	int FEdgeDoublesSkipped;
	void __fastcall SetWeldDistance(const float Value);
	
protected:
	virtual void __fastcall ProcessMeshObject(Gxs::Vectorfileobjects::TgxMeshObject* const MeshObject);
	
public:
	void __fastcall ExtractFacesFromVertexIndexList(Gxs::Vectorfileobjects::TgxFGVertexIndexList* const FaceGroup, Gxs::Vectorfileobjects::TgxMeshObject* const MeshObject);
	__property TFaceList* FaceList = {read=FFaceList};
	virtual void __fastcall Clear();
	virtual void __fastcall ProcessMesh();
	__property float WeldDistance = {read=FWeldDistance, write=SetWeldDistance};
	__property int EdgeDoublesSkipped = {read=FEdgeDoublesSkipped, nodefault};
	__property Gxs::Vectorfileobjects::TgxBaseMesh* GLBaseMesh = {read=FGLBaseMesh};
	__property Gxs::Verlettypes::TgxVerletNodeList* NodeList = {read=FNodeList};
	virtual TFace* __fastcall AddFace(const int Vi0, const int Vi1, const int Vi2, Gxs::Vectorfileobjects::TgxMeshObject* const MeshObject);
	__fastcall virtual TFaceExtractor(Gxs::Vectorfileobjects::TgxBaseMesh* const aGLBaseMesh);
	__fastcall virtual ~TFaceExtractor();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TEdge : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FSolid;
	float FLength;
	Gxs::Vectorfileobjects::TgxMeshObject* FMeshObject;
	TEdgeDetector* FOwner;
	
public:
	System::StaticArray<int, 2> Vertices;
	System::StaticArray<TFace*, 2> Faces;
	void __fastcall Contract();
	__property TEdgeDetector* Owner = {read=FOwner};
	__property Gxs::Vectorfileobjects::TgxMeshObject* MeshObject = {read=FMeshObject, write=FMeshObject};
	__property float Length = {read=FLength, write=FLength};
	__property bool Solid = {read=FSolid, write=FSolid, nodefault};
	void __fastcall UpdateEdgeLength();
	__fastcall TEdge(TEdgeDetector* const AOwner, int AVi0, int AVi1, TFace* AFace0, TFace* AFace1, Gxs::Vectorfileobjects::TgxMeshObject* AMeshObject, bool ASolid);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TEdge() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TEdgeList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TEdge* operator[](int i) { return this->Items[i]; }
	
private:
	TEdge* __fastcall GetItems(int i);
	void __fastcall SetItems(int i, TEdge* const Value);
	
public:
	__property TEdge* Items[int i] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall SortByLength();
	int __fastcall InsertSorted(TEdge* AEdge);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TEdgeList() { }
	
public:
	/* TObject.Create */ inline __fastcall TEdgeList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TEdgeDetector : public TFaceExtractor
{
	typedef TFaceExtractor inherited;
	
private:
	TEdgeList* FEdgeList;
	int FCurrentNodeOffset;
	bool FNodesAdded;
	void __fastcall BuildOpposingEdges();
	
protected:
	bool FCalcEdgeLength;
	
public:
	__property TEdgeList* EdgeList = {read=FEdgeList};
	virtual void __fastcall Clear();
	virtual void __fastcall ProcessMesh();
	TEdge* __fastcall AddEdge(const int Vi0, const int Vi1, TFace* const Face, Gxs::Vectorfileobjects::TgxMeshObject* const AMeshObject);
	virtual TFace* __fastcall AddFace(const int Vi0, const int Vi1, const int Vi2, Gxs::Vectorfileobjects::TgxMeshObject* const MeshObject);
	virtual Gxs::Verlettypes::TgxVerletNode* __fastcall AddNode(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld, Gxs::Vectorfileobjects::TgxMeshObject* const MeshObject, const int VertexIndex);
	void __fastcall AddNodes(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld);
	void __fastcall AddEdgesAsSticks(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld, const float Slack);
	void __fastcall AddEdgesAsSprings(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld, const float Strength, const float Damping, const float Slack);
	void __fastcall AddEdgesAsSolidEdges(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld);
	void __fastcall AddOuterEdgesAsSolidEdges(Gxs::Verlettypes::TgxVerletWorld* const VerletWorld);
	void __fastcall RenderEdges(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property int CurrentNodeOffset = {read=FCurrentNodeOffset, nodefault};
	__property bool NodesAdded = {read=FNodesAdded, nodefault};
	void __fastcall ReplaceVertexIndex(const int ViRemove, const int ViReplaceWith);
	__fastcall virtual TEdgeDetector(Gxs::Vectorfileobjects::TgxBaseMesh* const aGLBaseMesh);
	__fastcall virtual ~TEdgeDetector();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxMeshObjectVerletNode : public Gxs::Verlettypes::TgxVerletNode
{
	typedef Gxs::Verlettypes::TgxVerletNode inherited;
	
private:
	Gxs::Vectorfileobjects::TgxMeshObject* MeshObject;
	Gxs::Vectorlists::TgxIntegerList* VertexIndices;
	
public:
	virtual void __fastcall AfterProgress();
	__fastcall virtual TgxMeshObjectVerletNode(Gxs::Verlettypes::TgxVerletWorld* const aOwner);
	__fastcall virtual ~TgxMeshObjectVerletNode();
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxMeshObjectVerletNode() : Gxs::Verlettypes::TgxVerletNode() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMeshObjectVerletNode(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Verlettypes::TgxVerletNode(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Verletclothify */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_VERLETCLOTHIFY)
using namespace Gxs::Verletclothify;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_VerletClothifyHPP
