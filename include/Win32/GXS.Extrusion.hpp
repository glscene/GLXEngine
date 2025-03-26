// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Extrusion.pas' rev: 36.00 (Windows)

#ifndef GXS_ExtrusionHPP
#define GXS_ExtrusionHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Spline.hpp>
#include <GXS.Context.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Scene.hpp>
#include <GXS.MultiPolygon.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Nodes.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Extrusion
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxRevolutionSolid;
class DELPHICLASS TgxExtrusionSolid;
class DELPHICLASS TgxPipeNode;
class DELPHICLASS TgxPipeNodes;
class DELPHICLASS TgxPipe;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxExtrusionSolidPart : unsigned char { espOutside, espInside, espStartPolygon, espStopPolygon };

typedef System::Set<TgxExtrusionSolidPart, TgxExtrusionSolidPart::espOutside, TgxExtrusionSolidPart::espStopPolygon> TgxExtrusionSolidParts;

enum DECLSPEC_DENUM TgxRevolutionSolidPart : unsigned char { rspOutside, rspInside, rspStartPolygon, rspStopPolygon };

typedef System::Set<TgxRevolutionSolidPart, TgxRevolutionSolidPart::rspOutside, TgxRevolutionSolidPart::rspStopPolygon> TgxRevolutionSolidParts;

class PASCALIMPLEMENTATION TgxRevolutionSolid : public Gxs::Objects::TgxPolygonBase
{
	typedef Gxs::Objects::TgxPolygonBase inherited;
	
private:
	int FSlices;
	float FStartAngle;
	float FStopAngle;
	Gxs::Objects::TgxNormalSmoothing FNormals;
	float FYOffsetPerTurn;
	int FTriangleCount;
	Gxs::Scene::TgxNormalDirection FNormalDirection;
	TgxRevolutionSolidParts FParts;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	
protected:
	void __fastcall SetStartAngle(const float val);
	void __fastcall SetStopAngle(const float val);
	bool __fastcall StoreStopAngle();
	void __fastcall SetSlices(const int val);
	void __fastcall SetNormals(const Gxs::Objects::TgxNormalSmoothing val);
	void __fastcall SetYOffsetPerTurn(const float val);
	void __fastcall SetNormalDirection(const Gxs::Scene::TgxNormalDirection val);
	void __fastcall SetParts(const TgxRevolutionSolidParts val);
	
public:
	__fastcall virtual TgxRevolutionSolid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxRevolutionSolid();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property int TriangleCount = {read=FTriangleCount, nodefault};
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall StructureChanged();
	
__published:
	__property TgxRevolutionSolidParts Parts = {read=FParts, write=SetParts, default=1};
	__property float StartAngle = {read=FStartAngle, write=SetStartAngle};
	__property float StopAngle = {read=FStopAngle, write=SetStopAngle, stored=StoreStopAngle};
	__property float YOffsetPerTurn = {read=FYOffsetPerTurn, write=SetYOffsetPerTurn};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property Gxs::Objects::TgxNormalSmoothing Normals = {read=FNormals, write=SetNormals, default=0};
	__property Gxs::Scene::TgxNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxRevolutionSolid(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxPolygonBase(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxExtrusionSolid : public Gxs::Multipolygon::TgxMultiPolygonBase
{
	typedef Gxs::Multipolygon::TgxMultiPolygonBase inherited;
	
private:
	int FStacks;
	Gxs::Objects::TgxNormalSmoothing FNormals;
	int FTriangleCount;
	Gxs::Scene::TgxNormalDirection FNormalDirection;
	TgxExtrusionSolidParts FParts;
	float FHeight;
	float FMinSmoothAngle;
	float FMinSmoothAngleCos;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	void __fastcall SetHeight(const float Value);
	void __fastcall SetMinSmoothAngle(const float Value);
	
protected:
	void __fastcall SetStacks(const int val);
	void __fastcall SetNormals(const Gxs::Objects::TgxNormalSmoothing val);
	void __fastcall SetNormalDirection(const Gxs::Scene::TgxNormalDirection val);
	void __fastcall SetParts(const TgxExtrusionSolidParts val);
	
public:
	__fastcall virtual TgxExtrusionSolid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxExtrusionSolid();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property int TriangleCount = {read=FTriangleCount, nodefault};
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual void __fastcall StructureChanged();
	
__published:
	__property TgxExtrusionSolidParts Parts = {read=FParts, write=SetParts, default=1};
	__property float Height = {read=FHeight, write=SetHeight};
	__property int Stacks = {read=FStacks, write=SetStacks, default=1};
	__property Gxs::Objects::TgxNormalSmoothing Normals = {read=FNormals, write=SetNormals, default=0};
	__property Gxs::Scene::TgxNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
	__property float MinSmoothAngle = {read=FMinSmoothAngle, write=SetMinSmoothAngle};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxExtrusionSolid(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Multipolygon::TgxMultiPolygonBase(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPipeNode : public Gxs::Nodes::TgxNode
{
	typedef Gxs::Nodes::TgxNode inherited;
	
private:
	float FRadiusFactor;
	Gxs::Color::TgxColor* FColor;
	float FTexCoordT;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	void __fastcall SetRadiusFactor(const float val);
	bool __fastcall StoreRadiusFactor();
	void __fastcall SetColor(Gxs::Color::TgxColor* const val);
	void __fastcall ColorChanged(System::TObject* sender);
	bool __fastcall StoreTexCoordT();
	
public:
	__fastcall virtual TgxPipeNode(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxPipeNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float RadiusFactor = {read=FRadiusFactor, write=SetRadiusFactor, stored=StoreRadiusFactor};
	__property Gxs::Color::TgxColor* Color = {read=FColor, write=SetColor};
	__property float TexCoordT = {read=FTexCoordT, write=FTexCoordT, stored=StoreTexCoordT};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxPipeNodes : public Gxs::Objects::TgxLinesNodes
{
	typedef Gxs::Objects::TgxLinesNodes inherited;
	
public:
	TgxPipeNode* operator[](int index) { return this->Items[index]; }
	
protected:
	HIDESBASE void __fastcall SetItems(int index, TgxPipeNode* const val);
	HIDESBASE TgxPipeNode* __fastcall GetItems(int index);
	
public:
	__fastcall TgxPipeNodes(System::Classes::TComponent* AOwner);
	HIDESBASE TgxPipeNode* __fastcall Add();
	HIDESBASE TgxPipeNode* __fastcall FindItemID(int ID);
	__property TgxPipeNode* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxPipeNodes() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TPipePart : unsigned char { ppOutside, ppInside, ppStartDisk, ppStopDisk };

typedef System::Set<TPipePart, TPipePart::ppOutside, TPipePart::ppStopDisk> TPipeParts;

enum DECLSPEC_DENUM TPipeNodesColorMode : unsigned char { pncmNone, pncmEmission, pncmAmbient, pncmDiffuse, pncmAmbientAndDiffuse };

enum DECLSPEC_DENUM TPipeTexCoordMode : unsigned char { ptcmDefault, ptcmManual };

enum DECLSPEC_DENUM TPipeNormalMode : unsigned char { pnmDefault, pnmAdvanced };

class PASCALIMPLEMENTATION TgxPipe : public Gxs::Objects::TgxPolygonBase
{
	typedef Gxs::Objects::TgxPolygonBase inherited;
	
private:
	int FSlices;
	TPipeParts FParts;
	int FTriangleCount;
	float FRadius;
	TPipeNodesColorMode FNodesColorMode;
	TPipeTexCoordMode FTextCoordMode;
	float FTextCoordTileS;
	float FTextCoordTileT;
	TPipeNormalMode FNormalMode;
	float FNormalSmoothAngle;
	
protected:
	virtual void __fastcall CreateNodes();
	void __fastcall SetSlices(const int val);
	void __fastcall SetParts(const TPipeParts val);
	void __fastcall SetRadius(const float val);
	bool __fastcall StoreRadius();
	void __fastcall SetNodesColorMode(const TPipeNodesColorMode val);
	void __fastcall SetTextCoordMode(const TPipeTexCoordMode val);
	void __fastcall SetTextCoordTileS(const float val);
	void __fastcall SetTextCoordTileT(const float val);
	bool __fastcall StoreTextCoordTileS();
	bool __fastcall StoreTextCoordTileT();
	void __fastcall SetNormalMode(const TPipeNormalMode val);
	void __fastcall SetNormalSmoothAngle(const float val);
	
public:
	__fastcall virtual TgxPipe(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPipe();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property int TriangleCount = {read=FTriangleCount, nodefault};
	
__published:
	__property TPipeParts Parts = {read=FParts, write=SetParts, default=1};
	__property int Slices = {read=FSlices, write=SetSlices, default=16};
	__property float Radius = {read=FRadius, write=SetRadius};
	__property TPipeNodesColorMode NodesColorMode = {read=FNodesColorMode, write=SetNodesColorMode, default=0};
	__property TPipeTexCoordMode TexCoordMode = {read=FTextCoordMode, write=SetTextCoordMode, default=0};
	__property float TexCoordTileS = {read=FTextCoordTileS, write=SetTextCoordTileS, stored=StoreTextCoordTileS};
	__property float TexCoordTileT = {read=FTextCoordTileT, write=SetTextCoordTileT, stored=StoreTextCoordTileT};
	__property TPipeNormalMode NormalMode = {read=FNormalMode, write=SetNormalMode, default=0};
	__property float NormalSmoothAngle = {read=FNormalSmoothAngle, write=SetNormalSmoothAngle};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxPipe(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Objects::TgxPolygonBase(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Extrusion */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_EXTRUSION)
using namespace Gxs::Extrusion;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ExtrusionHPP
