// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Tree.pas' rev: 36.00 (Windows)

#ifndef GXS_TreeHPP
#define GXS_TreeHPP

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
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.State.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Tree
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTreeLeaves;
class DELPHICLASS TgxTreeBranch;
class DELPHICLASS TgxTreeBranches;
class DELPHICLASS TgxTreeBranchNoise;
class DELPHICLASS TgxTree;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTreeLeaves : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxTree* FOwner;
	int FCount;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FNormals;
	Gxs::Vectorlists::TgxAffineVectorList* FTexCoords;
	
public:
	__fastcall TgxTreeLeaves(TgxTree* AOwner);
	__fastcall virtual ~TgxTreeLeaves();
	void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall AddNew(const Stage::Vectortypes::TMatrix4f &matrix);
	void __fastcall Clear();
	__property TgxTree* Owner = {read=FOwner};
	__property int Count = {read=FCount, nodefault};
	__property Gxs::Vectorlists::TgxAffineVectorList* Vertices = {read=FVertices};
	__property Gxs::Vectorlists::TgxAffineVectorList* Normals = {read=FNormals};
	__property Gxs::Vectorlists::TgxAffineVectorList* TexCoords = {read=FTexCoords};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTreeBranch : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxTreeBranches* FOwner;
	TgxTreeBranch* FLeft;
	TgxTreeBranch* FCenter;
	TgxTreeBranch* FRight;
	TgxTreeBranch* FParent;
	int FBranchID;
	int FParentID;
	Stage::Vectortypes::TMatrix4f FMatrix;
	Gxs::Vectorlists::TgxIntegerList* FLower;
	Gxs::Vectorlists::TgxIntegerList* FUpper;
	bool FCentralLeader;
	void __fastcall BuildBranch(TgxTreeBranchNoise* branchNoise, const Stage::Vectortypes::TMatrix4f &matrix, float TexCoordY, float Twist, int Level);
	
public:
	__fastcall TgxTreeBranch(TgxTreeBranches* AOwner, TgxTreeBranch* AParent);
	__fastcall virtual ~TgxTreeBranch();
	__property TgxTreeBranches* Owner = {read=FOwner};
	__property TgxTreeBranch* Left = {read=FLeft};
	__property TgxTreeBranch* Center = {read=FCenter};
	__property TgxTreeBranch* Right = {read=FRight};
	__property TgxTreeBranch* Parent = {read=FParent};
	__property Stage::Vectortypes::TMatrix4f matrix = {read=FMatrix};
	__property Gxs::Vectorlists::TgxIntegerList* Lower = {read=FLower};
	__property Gxs::Vectorlists::TgxIntegerList* Upper = {read=FUpper};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTreeBranches : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxTree* FOwner;
	Gxs::Vectorlists::TgxSingleList* FSinList;
	Gxs::Vectorlists::TgxSingleList* FCosList;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FNormals;
	Gxs::Vectorlists::TgxAffineVectorList* FTexCoords;
	Gxs::Vectorlists::TgxIntegerList* FIndices;
	TgxTreeBranch* FRoot;
	int FCount;
	System::Classes::TList* FBranchCache;
	Gxs::Vectorlists::TgxIntegerList* FBranchIndices;
	void __fastcall BuildBranches();
	
public:
	__fastcall TgxTreeBranches(TgxTree* AOwner);
	__fastcall virtual ~TgxTreeBranches();
	void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall Clear();
	__property TgxTree* Owner = {read=FOwner};
	__property Gxs::Vectorlists::TgxSingleList* SinList = {read=FSinList};
	__property Gxs::Vectorlists::TgxSingleList* CosList = {read=FCosList};
	__property Gxs::Vectorlists::TgxAffineVectorList* Vertices = {read=FVertices};
	__property Gxs::Vectorlists::TgxAffineVectorList* Normals = {read=FNormals};
	__property Gxs::Vectorlists::TgxAffineVectorList* TexCoords = {read=FTexCoords};
	__property int Count = {read=FCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxTreeBranchNoise : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	float FBranchNoise;
	TgxTreeBranchNoise* FLeft;
	TgxTreeBranchNoise* FRight;
	TgxTreeBranchNoise* FCenter;
	TgxTreeBranchNoise* __fastcall GetLeft();
	TgxTreeBranchNoise* __fastcall GetCenter();
	TgxTreeBranchNoise* __fastcall GetRight();
	
public:
	__fastcall TgxTreeBranchNoise();
	__fastcall virtual ~TgxTreeBranchNoise();
	__property TgxTreeBranchNoise* Left = {read=GetLeft};
	__property TgxTreeBranchNoise* Center = {read=GetCenter};
	__property TgxTreeBranchNoise* Right = {read=GetRight};
	__property float branchNoise = {read=FBranchNoise};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxTree : public Gxs::Scene::TgxImmaterialSceneObject
{
	typedef Gxs::Scene::TgxImmaterialSceneObject inherited;
	
private:
	int FDepth;
	int FBranchFacets;
	float FLeafSize;
	float FBranchSize;
	float FBranchNoise;
	float FBranchAngleBias;
	float FBranchAngle;
	float FBranchTwist;
	float FBranchRadius;
	float FLeafThreshold;
	float FCentralLeaderBias;
	bool FCentralLeader;
	int FSeed;
	bool FAutoCenter;
	bool FAutoRebuild;
	float FCenterBranchConstant;
	TgxTreeLeaves* FLeaves;
	TgxTreeBranches* FBranches;
	TgxTreeBranchNoise* FNoise;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxLibMaterialName FLeafMaterialName;
	Gxs::Material::TgxLibMaterialName FLeafBackMaterialName;
	Gxs::Material::TgxLibMaterialName FBranchMaterialName;
	bool FRebuildTree;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	
protected:
	void __fastcall SetDepth(const int Value);
	void __fastcall SetBranchFacets(const int Value);
	void __fastcall SetLeafSize(const float Value);
	void __fastcall SetBranchSize(const float Value);
	void __fastcall SetBranchNoise(const float Value);
	void __fastcall SetBranchAngleBias(const float Value);
	void __fastcall SetBranchAngle(const float Value);
	void __fastcall SetBranchTwist(const float Value);
	void __fastcall SetBranchRadius(const float Value);
	void __fastcall SetLeafThreshold(const float Value);
	void __fastcall SetCentralLeaderBias(const float Value);
	void __fastcall SetCentralLeader(const bool Value);
	void __fastcall SetSeed(const int Value);
	void __fastcall SetAutoCenter(const bool Value);
	void __fastcall SetAutoRebuild(const bool Value);
	void __fastcall SetCenterBranchConstant(const float Value);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetLeafMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetLeafBackMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetBranchMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	virtual void __fastcall Loaded();
	
public:
	__fastcall virtual TgxTree(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTree();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall StructureChanged();
	void __fastcall BuildMesh(Gxs::Vectorfileobjects::TgxBaseMesh* GLBaseMesh);
	void __fastcall RebuildTree();
	void __fastcall ForceTotalRebuild();
	void __fastcall Clear();
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	void __fastcall SaveToStream(System::Classes::TStream* aStream);
	void __fastcall LoadFromFile(System::UnicodeString aFileName);
	void __fastcall SaveToFile(System::UnicodeString aFileName);
	__property TgxTreeLeaves* Leaves = {read=FLeaves};
	__property TgxTreeBranches* Branches = {read=FBranches};
	__property TgxTreeBranchNoise* Noise = {read=FNoise};
	
__published:
	__property int Depth = {read=FDepth, write=SetDepth, nodefault};
	__property int BranchFacets = {read=FBranchFacets, write=SetBranchFacets, nodefault};
	__property float LeafSize = {read=FLeafSize, write=SetLeafSize};
	__property float BranchSize = {read=FBranchSize, write=SetBranchSize};
	__property float branchNoise = {read=FBranchNoise, write=SetBranchNoise};
	__property float BranchAngleBias = {read=FBranchAngleBias, write=SetBranchAngleBias};
	__property float BranchAngle = {read=FBranchAngle, write=SetBranchAngle};
	__property float BranchTwist = {read=FBranchTwist, write=SetBranchTwist};
	__property float BranchRadius = {read=FBranchRadius, write=SetBranchRadius};
	__property float LeafThreshold = {read=FLeafThreshold, write=SetLeafThreshold};
	__property float CentralLeaderBias = {read=FCentralLeaderBias, write=SetCentralLeaderBias};
	__property bool CentralLeader = {read=FCentralLeader, write=SetCentralLeader, nodefault};
	__property int Seed = {read=FSeed, write=SetSeed, nodefault};
	__property bool AutoCenter = {read=FAutoCenter, write=SetAutoCenter, nodefault};
	__property bool AutoRebuild = {read=FAutoRebuild, write=SetAutoRebuild, nodefault};
	__property float CenterBranchConstant = {read=FCenterBranchConstant, write=SetCenterBranchConstant};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName LeafMaterialName = {read=FLeafMaterialName, write=SetLeafMaterialName};
	__property Gxs::Material::TgxLibMaterialName LeafBackMaterialName = {read=FLeafBackMaterialName, write=SetLeafBackMaterialName};
	__property Gxs::Material::TgxLibMaterialName BranchMaterialName = {read=FBranchMaterialName, write=SetBranchMaterialName};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTree(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxImmaterialSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Tree */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TREE)
using namespace Gxs::Tree;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TreeHPP
