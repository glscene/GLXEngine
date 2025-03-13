// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Nodes.pas' rev: 36.00 (Windows)

#ifndef GLS_NodesHPP
#define GLS_NodesHPP

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
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.OpenGLAdapter.hpp>
#include <GLS.Context.hpp>
#include <GLS.BaseClasses.hpp>
#include <Stage.Spline.hpp>
#include <GLS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Nodes
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLNode;
class DELPHICLASS TGLNodes;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLNode : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Stage::Vectortypes::TGLVector FCoords;
	System::TObject* FTagObject;
	void __fastcall SetAsVector(const Stage::Vectortypes::TGLVector &Value);
	void __fastcall SetAsAffineVector(const Stage::Vectorgeometry::TAffineVector &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetAsAffineVector();
	void __fastcall SetCoordinate(int AIndex, Stage::Opengltokens::TGLfloat AValue);
	Stage::Opengltokens::TGLfloat __fastcall GetCoordinate(const int Index);
	
protected:
	bool __fastcall StoreCoordinate(int AIndex);
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TGLNode(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TGLNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Stage::Opengltokens::PGLfloat __fastcall AsAddress();
	__property Stage::Vectortypes::TGLVector AsVector = {read=FCoords, write=SetAsVector};
	__property Stage::Vectorgeometry::TAffineVector AsAffineVector = {read=GetAsAffineVector, write=SetAsAffineVector};
	__property Stage::Opengltokens::TGLfloat W = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=3};
	__property System::TObject* TagObject = {read=FTagObject, write=FTagObject};
	
__published:
	__property Stage::Opengltokens::TGLfloat X = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=0};
	__property Stage::Opengltokens::TGLfloat Y = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=1};
	__property Stage::Opengltokens::TGLfloat Z = {read=GetCoordinate, write=SetCoordinate, stored=StoreCoordinate, index=2};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLNodes : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TGLNode* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int Index, TGLNode* const Val);
	TGLNode* __fastcall GetItems(int Index);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TGLNodes(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass);
	TGLNodes* __fastcall CreateCopy(System::Classes::TPersistent* AOwner);
	HIDESBASE TGLNode* __fastcall Add();
	HIDESBASE TGLNode* __fastcall FindItemID(int ID);
	__property TGLNode* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TGLNode* __fastcall First();
	TGLNode* __fastcall Last();
	virtual void __fastcall NotifyChange();
	virtual void __fastcall EndUpdate();
	void __fastcall AddNode(Gls::Coordinates::TGLCustomCoordinates* const Coords)/* overload */;
	void __fastcall AddNode(const Stage::Opengltokens::TGLfloat X, const Stage::Opengltokens::TGLfloat Y, const Stage::Opengltokens::TGLfloat Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TGLVector &Value)/* overload */;
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
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLNodes() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGLNodesClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Nodes */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_NODES)
using namespace Gls::Nodes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_NodesHPP
