// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Mesh.pas' rev: 36.00 (Windows)

#ifndef GXS_MeshHPP
#define GXS_MeshHPP

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
#include <Stage.OpenGL4.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Color.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>
#include <GXS.Scene.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Mesh
{
//-- forward type declarations -----------------------------------------------
struct TgxVertexData;
class DELPHICLASS TgxVertexList;
class DELPHICLASS TgxMesh;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMeshMode : unsigned char { mmTriangleStrip, mmTriangleFan, mmTriangles, mmQuadStrip, mmQuads, mmPolygon };

enum DECLSPEC_DENUM TVertexMode : unsigned char { vmV, vmVN, vmVNC, vmVNCT, vmVNT, vmVT };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxVertexData
{
public:
	Stage::Vectorgeometry::TTexPoint textCoord;
	Stage::Vectortypes::TVector4f color;
	Stage::Vectorgeometry::TAffineVector normal;
	Stage::Vectorgeometry::TVertex coord;
};
#pragma pack(pop)


typedef TgxVertexData *PgxVertexData;

typedef System::StaticArray<TgxVertexData, 33554432> TgxVertexDataArray;

typedef TgxVertexDataArray *PVKVertexDataArray;

class PASCALIMPLEMENTATION TgxVertexList : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
public:
	TgxVertexData operator[](int index) { return this->Vertices[index]; }
	
private:
	PVKVertexDataArray FValues;
	int FCount;
	int FCapacity;
	int FGrowth;
	PVKVertexDataArray FLockedOldValues;
	
protected:
	void __fastcall SetCapacity(const int val);
	void __fastcall SetGrowth(const int val);
	void __fastcall Grow();
	void __fastcall SetVertices(int index, const TgxVertexData &val);
	TgxVertexData __fastcall GetVertices(int index);
	void __fastcall SetVertexCoord(int index, const Stage::Vectorgeometry::TAffineVector &val);
	Stage::Vectorgeometry::TAffineVector __fastcall GetVertexCoord(int index);
	void __fastcall SetVertexNormal(int index, const Stage::Vectorgeometry::TAffineVector &val);
	Stage::Vectorgeometry::TAffineVector __fastcall GetVertexNormal(int index);
	void __fastcall SetVertexTexCoord(int index, const Stage::Vectorgeometry::TTexPoint &val);
	Stage::Vectorgeometry::TTexPoint __fastcall GetVertexTexCoord(int index);
	void __fastcall SetVertexColor(int index, const Stage::Vectortypes::TVector4f &val);
	Stage::Vectortypes::TVector4f __fastcall GetVertexColor(int index);
	Stage::Opengl4::PGLfloat __fastcall GetFirstEntry();
	Stage::Opengl4::PGLfloat __fastcall GetFirstColor();
	Stage::Opengl4::PGLfloat __fastcall GetFirstNormal();
	Stage::Opengl4::PGLfloat __fastcall GetFirstVertex();
	Stage::Opengl4::PGLfloat __fastcall GetFirstTexPoint();
	bool __fastcall GetLocked();
	void __fastcall SetLocked(bool val);
	
public:
	__fastcall virtual TgxVertexList(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxVertexList();
	TgxVertexList* __fastcall CreateInterpolatedCoords(TgxVertexList* list2, float lerpFactor);
	void __fastcall AddVertex(const TgxVertexData &vertexData)/* overload */;
	void __fastcall AddVertex3(const TgxVertexData &vd1, const TgxVertexData &vd2, const TgxVertexData &vd3)/* overload */;
	void __fastcall AddVertex(const Stage::Vectorgeometry::TVertex &aVertex, const Stage::Vectorgeometry::TAffineVector &aNormal, const Gxs::Color::TgxColorVector &aColor, const Stage::Vectorgeometry::TTexPoint &aTexPoint)/* overload */;
	void __fastcall AddVertex(const Stage::Vectorgeometry::TVertex &vertex, const Stage::Vectorgeometry::TAffineVector &normal, const Gxs::Color::TgxColorVector &color)/* overload */;
	void __fastcall AddVertex(const Stage::Vectorgeometry::TVertex &vertex, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	void __fastcall DuplicateVertex(int index);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Clear();
	__property TgxVertexData Vertices[int index] = {read=GetVertices, write=SetVertices/*, default*/};
	__property Stage::Vectorgeometry::TAffineVector VertexCoord[int index] = {read=GetVertexCoord, write=SetVertexCoord};
	__property Stage::Vectorgeometry::TAffineVector VertexNormal[int index] = {read=GetVertexNormal, write=SetVertexNormal};
	__property Stage::Vectorgeometry::TTexPoint VertexTexCoord[int index] = {read=GetVertexTexCoord, write=SetVertexTexCoord};
	__property Stage::Vectortypes::TVector4f VertexColor[int index] = {read=GetVertexColor, write=SetVertexColor};
	__property int Count = {read=FCount, nodefault};
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Growth = {read=FGrowth, write=SetGrowth, nodefault};
	Stage::Vectorgeometry::TAffineVector __fastcall SumVertexCoords();
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
	void __fastcall NormalizeNormals();
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &v);
	void __fastcall DefineOpenGLArrays();
	__property Stage::Opengl4::PGLfloat FirstColor = {read=GetFirstColor};
	__property Stage::Opengl4::PGLfloat FirstEntry = {read=GetFirstEntry};
	__property Stage::Opengl4::PGLfloat FirstNormal = {read=GetFirstNormal};
	__property Stage::Opengl4::PGLfloat FirstVertex = {read=GetFirstVertex};
	__property Stage::Opengl4::PGLfloat FirstTexPoint = {read=GetFirstTexPoint};
	__property bool Locked = {read=GetLocked, write=SetLocked, nodefault};
	void __fastcall EnterLockSection();
	void __fastcall LeaveLockSection();
};


class PASCALIMPLEMENTATION TgxMesh : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxVertexList* FVertices;
	TMeshMode FMode;
	TVertexMode FVertexMode;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	
protected:
	void __fastcall SetMode(TMeshMode AValue);
	void __fastcall SetVertices(TgxVertexList* AValue);
	void __fastcall SetVertexMode(TVertexMode AValue);
	void __fastcall VerticesChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TgxMesh(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMesh();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall CalcNormals(Gxs::State::TgxFaceWinding Frontface);
	__property TgxVertexList* Vertices = {read=FVertices, write=SetVertices};
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall StructureChanged();
	
__published:
	__property TMeshMode Mode = {read=FMode, write=SetMode, nodefault};
	__property TVertexMode VertexMode = {read=FVertexMode, write=SetVertexMode, default=3};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMesh(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::StaticArray<unsigned, 6> cMeshModeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 6> cVertexModeToGLEnum;
}	/* namespace Mesh */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MESH)
using namespace Gxs::Mesh;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MeshHPP
