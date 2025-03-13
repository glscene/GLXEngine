// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.GeomObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_GeomObjectsHPP
#define GXS_GeomObjectsHPP

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
#include <System.Math.hpp>
#include <System.Classes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.State.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Silhouette.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Polynomials.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.Material.hpp>
#include <GXS.Texture.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.Context.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Mesh.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Geomobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTetrahedron;
class DELPHICLASS TgxOctahedron;
class DELPHICLASS TgxHexahedron;
class DELPHICLASS TgxDodecahedron;
class DELPHICLASS TgxIcosahedron;
class DELPHICLASS TgxDisk;
class DELPHICLASS TgxCylinderBase;
class DELPHICLASS TgxCone;
class DELPHICLASS TgxCylinder;
class DELPHICLASS TgxCapsule;
class DELPHICLASS TgxAnnulus;
class DELPHICLASS TgxTorus;
class DELPHICLASS TgxArrowLine;
class DELPHICLASS TgxArrowArc;
class DELPHICLASS TgxPolygon;
class DELPHICLASS TgxFrustrum;
class DELPHICLASS TgxTeapot;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxTetrahedron : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseMesh.Create */ inline __fastcall virtual TgxTetrahedron(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aOwner) { }
	/* TgxBaseMesh.Destroy */ inline __fastcall virtual ~TgxTetrahedron() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTetrahedron(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxOctahedron : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseMesh.Create */ inline __fastcall virtual TgxOctahedron(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aOwner) { }
	/* TgxBaseMesh.Destroy */ inline __fastcall virtual ~TgxOctahedron() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxOctahedron(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxHexahedron : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseMesh.Create */ inline __fastcall virtual TgxHexahedron(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aOwner) { }
	/* TgxBaseMesh.Destroy */ inline __fastcall virtual ~TgxHexahedron() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxHexahedron(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxDodecahedron : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseMesh.Create */ inline __fastcall virtual TgxDodecahedron(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aOwner) { }
	/* TgxBaseMesh.Destroy */ inline __fastcall virtual ~TgxDodecahedron() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxDodecahedron(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxIcosahedron : public Gxs::Vectorfileobjects::TgxBaseMesh
{
	typedef Gxs::Vectorfileobjects::TgxBaseMesh inherited;
	
public:
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
public:
	/* TgxBaseMesh.Create */ inline __fastcall virtual TgxIcosahedron(System::Classes::TComponent* aOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aOwner) { }
	/* TgxBaseMesh.Destroy */ inline __fastcall virtual ~TgxIcosahedron() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxIcosahedron(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Vectorfileobjects::TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxDisk : public Gxs::Objects::TgxQuadricObject
{
	typedef Gxs::Objects::TgxQuadricObject inherited;
	
private:
	float FStartAngle;
	float FSweepAngle;
	float FOuterRadius;
	float FInnerRadius;
	int FSlices;
	int FLoops;
	void __fastcall SetOuterRadius(const float aValue);
	void __fastcall SetInnerRadius(const float aValue);
	void __fastcall SetSlices(int aValue);
	void __fastcall SetLoops(int aValue);
	void __fastcall SetStartAngle(const float aValue);
	void __fastcall SetSweepAngle(const float aValue);
	
public:
	__fastcall virtual TgxDisk(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property float InnerRadius = {read=FInnerRadius, write=SetInnerRadius};
	__property int Loops = {read=FLoops, write=SetLoops, default=2};
	__property float OuterRadius = {read=FOuterRadius, write=SetOuterRadius};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property float StartAngle = {read=FStartAngle, write=SetStartAngle};
	__property float SweepAngle = {read=FSweepAngle, write=SetSweepAngle};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxDisk() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxDisk(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxQuadricObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxCylinderBase : public Gxs::Objects::TgxQuadricObject
{
	typedef Gxs::Objects::TgxQuadricObject inherited;
	
private:
	float FBottomRadius;
	int FSlices;
	int FStacks;
	int FLoops;
	float FHeight;
	
protected:
	void __fastcall SetBottomRadius(const float aValue);
	void __fastcall SetHeight(const float aValue);
	void __fastcall SetSlices(int aValue);
	void __fastcall SetStacks(int aValue);
	void __fastcall SetLoops(int aValue);
	virtual float __fastcall GetTopRadius();
	
public:
	__fastcall virtual TgxCylinderBase(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &silhouetteParameters);
	
__published:
	__property float BottomRadius = {read=FBottomRadius, write=SetBottomRadius};
	__property float Height = {read=FHeight, write=SetHeight};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property int Stacks = {read=FStacks, write=SetStacks, default=4};
	__property int Loops = {read=FLoops, write=SetLoops, default=1};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCylinderBase() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCylinderBase(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxQuadricObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxConePart : unsigned char { coSides, coBottom };

typedef System::Set<TgxConePart, TgxConePart::coSides, TgxConePart::coBottom> TgxConeParts;

class PASCALIMPLEMENTATION TgxCone : public TgxCylinderBase
{
	typedef TgxCylinderBase inherited;
	
private:
	TgxConeParts FParts;
	
protected:
	void __fastcall SetParts(TgxConeParts aValue);
	virtual float __fastcall GetTopRadius();
	
public:
	__fastcall virtual TgxCone(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property TgxConeParts Parts = {read=FParts, write=SetParts, default=3};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCone() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCone(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCylinderBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxCylinderPart : unsigned char { cySides, cyBottom, cyTop };

typedef System::Set<TgxCylinderPart, TgxCylinderPart::cySides, TgxCylinderPart::cyTop> TgxCylinderParts;

enum DECLSPEC_DENUM TgxCylinderAlignment : unsigned char { caCenter, caTop, caBottom };

class PASCALIMPLEMENTATION TgxCylinder : public TgxCylinderBase
{
	typedef TgxCylinderBase inherited;
	
private:
	TgxCylinderParts FParts;
	float FTopRadius;
	TgxCylinderAlignment FAlignment;
	
protected:
	void __fastcall SetTopRadius(const float aValue);
	void __fastcall SetParts(TgxCylinderParts aValue);
	void __fastcall SetAlignment(TgxCylinderAlignment val);
	virtual float __fastcall GetTopRadius();
	
public:
	__fastcall virtual TgxCylinder(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	void __fastcall Align(const Stage::Vectortypes::TVector4f &startPoint, const Stage::Vectortypes::TVector4f &endPoint)/* overload */;
	void __fastcall Align(Gxs::Scene::TgxBaseSceneObject* const startObj, Gxs::Scene::TgxBaseSceneObject* const endObj)/* overload */;
	void __fastcall Align(const Stage::Vectorgeometry::TAffineVector &startPoint, const Stage::Vectorgeometry::TAffineVector &endPoint)/* overload */;
	
__published:
	__property float TopRadius = {read=FTopRadius, write=SetTopRadius};
	__property TgxCylinderParts Parts = {read=FParts, write=SetParts, default=7};
	__property TgxCylinderAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCylinder() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCylinder(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCylinderBase(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxCapsule : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxCylinderParts FParts;
	float FRadius;
	int FSlices;
	int FStacks;
	float FHeight;
	TgxCylinderAlignment FAlignment;
	
protected:
	void __fastcall SetHeight(const float aValue);
	void __fastcall SetRadius(const float aValue);
	void __fastcall SetSlices(const int aValue);
	void __fastcall SetStacks(const int aValue);
	void __fastcall SetParts(TgxCylinderParts aValue);
	void __fastcall SetAlignment(TgxCylinderAlignment val);
	
public:
	__fastcall virtual TgxCapsule(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	void __fastcall Align(const Stage::Vectortypes::TVector4f &startPoint, const Stage::Vectortypes::TVector4f &endPoint)/* overload */;
	void __fastcall Align(Gxs::Scene::TgxBaseSceneObject* const startObj, Gxs::Scene::TgxBaseSceneObject* const endObj)/* overload */;
	void __fastcall Align(const Stage::Vectorgeometry::TAffineVector &startPoint, const Stage::Vectorgeometry::TAffineVector &endPoint)/* overload */;
	
__published:
	__property float Height = {read=FHeight, write=SetHeight};
	__property int Slices = {read=FSlices, write=SetSlices, nodefault};
	__property int Stacks = {read=FStacks, write=SetStacks, nodefault};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property TgxCylinderParts Parts = {read=FParts, write=SetParts, default=7};
	__property TgxCylinderAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxCapsule() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCapsule(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxAnnulusPart : unsigned char { anInnerSides, anOuterSides, anBottom, anTop };

typedef System::Set<TgxAnnulusPart, TgxAnnulusPart::anInnerSides, TgxAnnulusPart::anTop> TgxAnnulusParts;

class PASCALIMPLEMENTATION TgxAnnulus : public TgxCylinderBase
{
	typedef TgxCylinderBase inherited;
	
private:
	TgxAnnulusParts FParts;
	float FBottomInnerRadius;
	float FTopInnerRadius;
	float FTopRadius;
	
protected:
	void __fastcall SetTopRadius(const float aValue);
	void __fastcall SetTopInnerRadius(const float aValue);
	void __fastcall SetBottomInnerRadius(const float aValue);
	void __fastcall SetParts(TgxAnnulusParts aValue);
	
public:
	__fastcall virtual TgxAnnulus(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property float BottomInnerRadius = {read=FBottomInnerRadius, write=SetBottomInnerRadius};
	__property float TopInnerRadius = {read=FTopInnerRadius, write=SetTopInnerRadius};
	__property float TopRadius = {read=FTopRadius, write=SetTopRadius};
	__property TgxAnnulusParts Parts = {read=FParts, write=SetParts, default=15};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxAnnulus() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxAnnulus(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCylinderBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxTorusPart : unsigned char { toSides, toStartDisk, toStopDisk };

typedef System::Set<TgxTorusPart, TgxTorusPart::toSides, TgxTorusPart::toStopDisk> TgxTorusParts;

class PASCALIMPLEMENTATION TgxTorus : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<Gxs::Objects::TVertexRec> _TgxTorus__1;
	
	typedef System::DynamicArray<System::DynamicArray<Gxs::Objects::TVertexRec> > _TgxTorus__2;
	
	
private:
	TgxTorusParts FParts;
	unsigned FRings;
	unsigned FSides;
	float FStartAngle;
	float FStopAngle;
	float FMinorRadius;
	float FMajorRadius;
	_TgxTorus__2 FMesh;
	
protected:
	void __fastcall SetMajorRadius(const float aValue);
	void __fastcall SetMinorRadius(const float aValue);
	void __fastcall SetRings(unsigned aValue);
	void __fastcall SetSides(unsigned aValue);
	void __fastcall SetStartAngle(const float aValue);
	void __fastcall SetStopAngle(const float aValue);
	void __fastcall SetParts(TgxTorusParts aValue);
	
public:
	__fastcall virtual TgxTorus(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	
__published:
	__property float MajorRadius = {read=FMajorRadius, write=SetMajorRadius};
	__property float MinorRadius = {read=FMinorRadius, write=SetMinorRadius};
	__property unsigned Rings = {read=FRings, write=SetRings, default=25};
	__property unsigned Sides = {read=FSides, write=SetSides, default=15};
	__property float StartAngle = {read=FStartAngle, write=SetStartAngle};
	__property float StopAngle = {read=FStopAngle, write=SetStopAngle};
	__property TgxTorusParts Parts = {read=FParts, write=SetParts, default=1};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxTorus() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTorus(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxArrowLinePart : unsigned char { alLine, alTopArrow, alBottomArrow };

typedef System::Set<TgxArrowLinePart, TgxArrowLinePart::alLine, TgxArrowLinePart::alBottomArrow> TgxArrowLineParts;

enum DECLSPEC_DENUM TgxArrowHeadStyle : unsigned char { ahssStacked, ahssCentered, ahssIncluded };

class PASCALIMPLEMENTATION TgxArrowLine : public TgxCylinderBase
{
	typedef TgxCylinderBase inherited;
	
private:
	TgxArrowLineParts FParts;
	float FTopRadius;
	float fTopArrowHeadHeight;
	float fTopArrowHeadRadius;
	float fBottomArrowHeadHeight;
	float fBottomArrowHeadRadius;
	TgxArrowHeadStyle FHeadStackingStyle;
	
protected:
	void __fastcall SetTopRadius(const float aValue);
	void __fastcall SetTopArrowHeadHeight(const float aValue);
	void __fastcall SetTopArrowHeadRadius(const float aValue);
	void __fastcall SetBottomArrowHeadHeight(const float aValue);
	void __fastcall SetBottomArrowHeadRadius(const float aValue);
	void __fastcall SetParts(TgxArrowLineParts aValue);
	void __fastcall SetHeadStackingStyle(const TgxArrowHeadStyle val);
	
public:
	__fastcall virtual TgxArrowLine(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float TopRadius = {read=FTopRadius, write=SetTopRadius};
	__property TgxArrowHeadStyle HeadStackingStyle = {read=FHeadStackingStyle, write=SetHeadStackingStyle, default=0};
	__property TgxArrowLineParts Parts = {read=FParts, write=SetParts, default=3};
	__property float TopArrowHeadHeight = {read=fTopArrowHeadHeight, write=SetTopArrowHeadHeight};
	__property float TopArrowHeadRadius = {read=fTopArrowHeadRadius, write=SetTopArrowHeadRadius};
	__property float BottomArrowHeadHeight = {read=fBottomArrowHeadHeight, write=SetBottomArrowHeadHeight};
	__property float BottomArrowHeadRadius = {read=fBottomArrowHeadRadius, write=SetBottomArrowHeadRadius};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxArrowLine() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxArrowLine(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCylinderBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxArrowArcPart : unsigned char { aaArc, aaTopArrow, aaBottomArrow };

typedef System::Set<TgxArrowArcPart, TgxArrowArcPart::aaArc, TgxArrowArcPart::aaBottomArrow> TgxArrowArcParts;

class PASCALIMPLEMENTATION TgxArrowArc : public TgxCylinderBase
{
	typedef TgxCylinderBase inherited;
	
	
private:
	typedef System::DynamicArray<Gxs::Objects::TVertexRec> _TgxArrowArc__1;
	
	typedef System::DynamicArray<System::DynamicArray<Gxs::Objects::TVertexRec> > _TgxArrowArc__2;
	
	
private:
	float fArcRadius;
	float FStartAngle;
	float FStopAngle;
	TgxArrowArcParts FParts;
	float FTopRadius;
	float fTopArrowHeadHeight;
	float fTopArrowHeadRadius;
	float fBottomArrowHeadHeight;
	float fBottomArrowHeadRadius;
	TgxArrowHeadStyle FHeadStackingStyle;
	_TgxArrowArc__2 FMesh;
	
protected:
	void __fastcall SetArcRadius(const float aValue);
	void __fastcall SetStartAngle(const float aValue);
	void __fastcall SetStopAngle(const float aValue);
	void __fastcall SetTopRadius(const float aValue);
	void __fastcall SetTopArrowHeadHeight(const float aValue);
	void __fastcall SetTopArrowHeadRadius(const float aValue);
	void __fastcall SetBottomArrowHeadHeight(const float aValue);
	void __fastcall SetBottomArrowHeadRadius(const float aValue);
	void __fastcall SetParts(TgxArrowArcParts aValue);
	void __fastcall SetHeadStackingStyle(const TgxArrowHeadStyle val);
	
public:
	__fastcall virtual TgxArrowArc(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float ArcRadius = {read=fArcRadius, write=SetArcRadius};
	__property float StartAngle = {read=FStartAngle, write=SetStartAngle};
	__property float StopAngle = {read=FStopAngle, write=SetStopAngle};
	__property float TopRadius = {read=FTopRadius, write=SetTopRadius};
	__property TgxArrowHeadStyle HeadStackingStyle = {read=FHeadStackingStyle, write=SetHeadStackingStyle, default=0};
	__property TgxArrowArcParts Parts = {read=FParts, write=SetParts, default=3};
	__property float TopArrowHeadHeight = {read=fTopArrowHeadHeight, write=SetTopArrowHeadHeight};
	__property float TopArrowHeadRadius = {read=fTopArrowHeadRadius, write=SetTopArrowHeadRadius};
	__property float BottomArrowHeadHeight = {read=fBottomArrowHeadHeight, write=SetBottomArrowHeadHeight};
	__property float BottomArrowHeadRadius = {read=fBottomArrowHeadRadius, write=SetBottomArrowHeadRadius};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxArrowArc() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxArrowArc(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCylinderBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxPolygonPart : unsigned char { ppTop, ppBottom };

typedef System::Set<TgxPolygonPart, TgxPolygonPart::ppTop, TgxPolygonPart::ppBottom> TgxPolygonParts;

class PASCALIMPLEMENTATION TgxPolygon : public Gxs::Objects::TgxPolygonBase
{
	typedef Gxs::Objects::TgxPolygonBase inherited;
	
private:
	TgxPolygonParts FParts;
	
protected:
	void __fastcall SetParts(const TgxPolygonParts val);
	
public:
	__fastcall virtual TgxPolygon(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPolygon();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TgxPolygonParts Parts = {read=FParts, write=SetParts, default=3};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPolygon(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxPolygonBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TFrustrumPart : unsigned char { fpTop, fpBottom, fpFront, fpBack, fpLeft, fpRight };

typedef System::Set<TFrustrumPart, TFrustrumPart::fpTop, TFrustrumPart::fpRight> TFrustrumParts;

class PASCALIMPLEMENTATION TgxFrustrum : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	float FApexHeight;
	float FBaseDepth;
	float FBaseWidth;
	float FHeight;
	TFrustrumParts FParts;
	Gxs::Scene::TgxNormalDirection FNormalDirection;
	void __fastcall SetApexHeight(const float aValue);
	void __fastcall SetBaseDepth(const float aValue);
	void __fastcall SetBaseWidth(const float aValue);
	void __fastcall SetHeight(const float aValue);
	void __fastcall SetParts(TFrustrumParts aValue);
	void __fastcall SetNormalDirection(Gxs::Scene::TgxNormalDirection aValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TgxFrustrum(System::Classes::TComponent* AOwner);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	float __fastcall TopDepth();
	float __fastcall TopWidth();
	HIDESBASE Gxs::Geometrybb::TAABB __fastcall AxisAlignedBoundingBoxUnscaled();
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	
__published:
	__property float ApexHeight = {read=FApexHeight, write=SetApexHeight, stored=false};
	__property float BaseDepth = {read=FBaseDepth, write=SetBaseDepth, stored=false};
	__property float BaseWidth = {read=FBaseWidth, write=SetBaseWidth, stored=false};
	__property float Height = {read=FHeight, write=SetHeight, stored=false};
	__property Gxs::Scene::TgxNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
	__property TFrustrumParts Parts = {read=FParts, write=SetParts, default=63};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxFrustrum() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFrustrum(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxTeapot : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	unsigned FGrid;
	
public:
	__fastcall virtual TgxTeapot(System::Classes::TComponent* AOwner);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxTeapot() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTeapot(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cAllFrustrumParts (System::Set<TFrustrumPart, TFrustrumPart::fpTop, TFrustrumPart::fpRight>() << TFrustrumPart::fpTop << TFrustrumPart::fpBottom << TFrustrumPart::fpFront << TFrustrumPart::fpBack << TFrustrumPart::fpLeft << TFrustrumPart::fpRight )
}	/* namespace Geomobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_GEOMOBJECTS)
using namespace Gxs::Geomobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_GeomObjectsHPP
