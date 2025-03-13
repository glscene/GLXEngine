// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Nodes.pas' rev: 36.00 (Windows)

#ifndef GXS_NodesHPP
#define GXS_NodesHPP

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
#include <System.Math.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Spline.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Nodes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxNode;
class DELPHICLASS TgxNodes;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNode : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Stage::Vectortypes::TVector4f FCoords;
	System::TObject* FTagObject;
	void __fastcall SetAsVector(const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetAsAffineVector(const Stage::Vectorgeometry::TAffineVector &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetAsAffineVector();
	void __fastcall SetCoordinate(int AIndex, float AValue);
	float __fastcall GetCoordinate(const int Index);
	
protected:
	bool __fastcall StoreCoordinate(int AIndex);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxNode(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TgxNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Winapi::Opengl::PGLfloat __fastcall AsAddress();
	__property Stage::Vectortypes::TVector4f AsVector = {read=FCoords, write=SetAsVector};
	__property Stage::Vectorgeometry::TAffineVector AsAffineVector = {read=GetAsAffineVector, write=SetAsAffineVector};
	__property float W = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=3};
	__property System::TObject* TagObject = {read=FTagObject, write=FTagObject};
	
__published:
	__property float X = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=0};
	__property float Y = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=1};
	__property float Z = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=2};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxNodes : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxNode* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int Index, TgxNode* const Val);
	TgxNode* __fastcall GetItems(int Index);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TgxNodes(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass);
	TgxNodes* __fastcall CreateCopy(System::Classes::TPersistent* AOwner);
	HIDESBASE TgxNode* __fastcall Add();
	HIDESBASE TgxNode* __fastcall FindItemID(int ID);
	__property TgxNode* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TgxNode* __fastcall First();
	TgxNode* __fastcall Last();
	virtual void __fastcall NotifyChange();
	virtual void __fastcall EndUpdate();
	void __fastcall AddNode(Gxs::Coordinates::TgxCustomCoordinates* const Coords)/* overload */;
	void __fastcall AddNode(const float X, const float Y, const float Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TVector4f &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	void __fastcall AddXYArc(float XRadius, float YRadius, float StartAngle, float StopAngle, int NbSegments, const Stage::Vectorgeometry::TAffineVector &Center);
	Stage::Vectorgeometry::TAffineVector __fastcall Barycenter();
	Stage::Vectorgeometry::TAffineVector __fastcall Normal();
	Stage::Vectorgeometry::TAffineVector __fastcall Vector(int I);
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &Min, Stage::Vectorgeometry::TAffineVector &Max);
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &Tv);
	void __fastcall Scale(const Stage::Vectorgeometry::TAffineVector &Fv)/* overload */;
	void __fastcall Scale(float F)/* overload */;
	void __fastcall RotateAroundX(float Angle);
	void __fastcall RotateAroundY(float Angle);
	void __fastcall RotateAroundZ(float Angle);
	void __fastcall RenderTesselatedPolygon(bool ATextured, Stage::Vectorgeometry::PAffineVector ANormal = (Stage::Vectorgeometry::PAffineVector)(0x0), int ASplineDivisions = 0x1, bool AInvertNormals = false);
	Stage::Spline::TCubicSpline* __fastcall CreateNewCubicSpline();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxNodes() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TgxNodesClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Nodes */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_NODES)
using namespace Gxs::Nodes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_NodesHPP
