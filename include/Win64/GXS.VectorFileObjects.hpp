// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.VectorFileObjects.pas' rev: 36.00 (Windows)

#ifndef GXS_VectorFileObjectsHPP
#define GXS_VectorFileObjectsHPP

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
#include <System.Math.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <Stage.Utils.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.Mesh.hpp>
#include <GXS.Octree.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.Context.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.MeshUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Vectorfileobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBaseMeshObject;
class DELPHICLASS TgxSkeletonFrame;
class DELPHICLASS TgxSkeletonFrameList;
class DELPHICLASS TgxSkeletonBoneList;
class DELPHICLASS TgxSkeletonRootBoneList;
class DELPHICLASS TgxSkeletonBone;
class DELPHICLASS TgxSkeletonCollider;
class DELPHICLASS TgxSkeletonColliderList;
struct TGXBlendedLerpInfo;
class DELPHICLASS TgxSkeleton;
class DELPHICLASS TgxMeshObject;
class DELPHICLASS TgxMeshObjectList;
class DELPHICLASS TgxMeshMorphTarget;
class DELPHICLASS TgxMeshMorphTargetList;
class DELPHICLASS TgxMorphableMeshObject;
struct TgxVertexBoneWeight;
class DELPHICLASS TgxSkeletonMeshObject;
class DELPHICLASS TgxFaceGroup;
class DELPHICLASS TgxFGVertexIndexList;
class DELPHICLASS TFGVertexNormalTexIndexList;
class DELPHICLASS TgxFGIndexTexCoordList;
class DELPHICLASS TgxFaceGroups;
class DELPHICLASS TgxVectorFile;
class DELPHICLASS TgxVectorFileGLSM;
class DELPHICLASS TgxBaseMesh;
class DELPHICLASS TgxFreeForm;
class DELPHICLASS TgxActorAnimation;
class DELPHICLASS TgxActorAnimations;
class DELPHICLASS TgxBaseAnimationControler;
class DELPHICLASS TgxAnimationControler;
class DELPHICLASS TgxActor;
class DELPHICLASS TgxVectorFileFormat;
class DELPHICLASS TgxVectorFileFormatsList;
class DELPHICLASS EgxInvalidVectorFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxMeshAutoCentering : unsigned char { macCenterX, macCenterY, macCenterZ, macUseBarycenter, macRestorePosition };

typedef System::Set<TgxMeshAutoCentering, TgxMeshAutoCentering::macCenterX, TgxMeshAutoCentering::macRestorePosition> TgxMeshAutoCenterings;

enum DECLSPEC_DENUM TgxMeshObjectMode : unsigned char { momTriangles, momTriangleStrip, momFaceGroups };

class PASCALIMPLEMENTATION TgxBaseMeshObject : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	System::UnicodeString FName;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Gxs::Vectorlists::TgxAffineVectorList* FNormals;
	bool FVisible;
	
protected:
	void __fastcall SetVertices(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetNormals(Gxs::Vectorlists::TgxAffineVectorList* const val);
	virtual void __fastcall ContributeToBarycenter(Stage::Vectorgeometry::TAffineVector &currentSum, int &nb);
	
public:
	__fastcall virtual TgxBaseMeshObject();
	__fastcall virtual ~TgxBaseMeshObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	void __fastcall BuildNormals(Gxs::Vectorlists::TgxIntegerList* vertexIndices, TgxMeshObjectMode mode, Gxs::Vectorlists::TgxIntegerList* normalIndices = (Gxs::Vectorlists::TgxIntegerList*)(0x0));
	virtual Gxs::Vectorlists::TgxAffineVectorList* __fastcall ExtractTriangles(Gxs::Vectorlists::TgxAffineVectorList* texCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property Gxs::Vectorlists::TgxAffineVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Gxs::Vectorlists::TgxAffineVectorList* normals = {read=FNormals, write=SetNormals};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxBaseMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


enum DECLSPEC_DENUM TgxSkeletonFrameTransform : unsigned char { sftRotation, sftQuaternion };

class PASCALIMPLEMENTATION TgxSkeletonFrame : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TgxSkeletonFrameList* FOwner;
	System::UnicodeString FName;
	Gxs::Vectorlists::TgxAffineVectorList* FPosition;
	Gxs::Vectorlists::TgxAffineVectorList* FRotation;
	Gxs::Vectorlists::TGQuaternionList* FQuaternion;
	Stage::Vectorgeometry::PMatrixArray FLocalMatrixList;
	TgxSkeletonFrameTransform FTransformMode;
	
protected:
	void __fastcall SetPosition(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetRotation(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetQuaternion(Gxs::Vectorlists::TGQuaternionList* const val);
	
public:
	__fastcall TgxSkeletonFrame(TgxSkeletonFrameList* aOwner);
	__fastcall virtual TgxSkeletonFrame();
	__fastcall virtual ~TgxSkeletonFrame();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxSkeletonFrameList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Gxs::Vectorlists::TgxAffineVectorList* Position = {read=FPosition, write=SetPosition};
	__property Gxs::Vectorlists::TgxAffineVectorList* Rotation = {read=FRotation, write=SetRotation};
	__property Gxs::Vectorlists::TGQuaternionList* Quaternion = {read=FQuaternion, write=SetQuaternion};
	__property TgxSkeletonFrameTransform TransformMode = {read=FTransformMode, write=FTransformMode, nodefault};
	Stage::Vectorgeometry::PMatrixArray __fastcall LocalMatrixList();
	void __fastcall FlushLocalMatrixList();
	void __fastcall ConvertQuaternionsToRotations(bool KeepQuaternions = true);
	void __fastcall ConvertRotationsToQuaternions(bool KeepRotations = true);
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonFrame(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonFrameList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxSkeletonFrame* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TgxSkeletonFrame* __fastcall GetSkeletonFrame(int Index);
	
public:
	__fastcall TgxSkeletonFrameList(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TgxSkeletonFrameList();
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall ConvertQuaternionsToRotations(bool KeepQuaternions = true, bool SetTransformMode = true);
	void __fastcall ConvertRotationsToQuaternions(bool KeepRotations = true, bool SetTransformMode = true);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TgxSkeletonFrame* Items[int Index] = {read=GetSkeletonFrame/*, default*/};
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxSkeletonFrameList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonFrameList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonBoneList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxSkeletonBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxSkeleton* FSkeleton;
	
protected:
	Stage::Vectortypes::TMatrix4f FGlobalMatrix;
	TgxSkeletonBone* __fastcall GetSkeletonBone(int Index);
	virtual void __fastcall AfterObjectCreatedByReader(System::TObject* Sender);
	
public:
	__fastcall TgxSkeletonBoneList(TgxSkeleton* aOwner);
	__fastcall virtual TgxSkeletonBoneList();
	__fastcall virtual ~TgxSkeletonBoneList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxSkeleton* Skeleton = {read=FSkeleton};
	__property TgxSkeletonBone* Items[int Index] = {read=GetSkeletonBone/*, default*/};
	virtual TgxSkeletonBone* __fastcall BoneByID(int anID);
	virtual TgxSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	int __fastcall BoneCount();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci) = 0 ;
	virtual void __fastcall PrepareGlobalMatrices();
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonBoneList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonRootBoneList : public TgxSkeletonBoneList
{
	typedef TgxSkeletonBoneList inherited;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	__property Stage::Vectortypes::TMatrix4f GlobalMatrix = {read=FGlobalMatrix, write=FGlobalMatrix};
public:
	/* TgxSkeletonBoneList.CreateOwned */ inline __fastcall TgxSkeletonRootBoneList(TgxSkeleton* aOwner) : TgxSkeletonBoneList(aOwner) { }
	/* TgxSkeletonBoneList.Create */ inline __fastcall virtual TgxSkeletonRootBoneList() : TgxSkeletonBoneList() { }
	/* TgxSkeletonBoneList.Destroy */ inline __fastcall virtual ~TgxSkeletonRootBoneList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonRootBoneList(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxSkeletonBoneList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonBone : public TgxSkeletonBoneList
{
	typedef TgxSkeletonBoneList inherited;
	
public:
	TgxSkeletonBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxSkeletonBoneList* FOwner;
	int FBoneID;
	System::UnicodeString FName;
	unsigned FColor;
	
protected:
	HIDESBASE TgxSkeletonBone* __fastcall GetSkeletonBone(int Index);
	void __fastcall SetColor(const unsigned val);
	
public:
	__fastcall TgxSkeletonBone(TgxSkeletonBoneList* aOwner);
	__fastcall virtual TgxSkeletonBone();
	__fastcall virtual ~TgxSkeletonBone();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	__property TgxSkeletonBoneList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int BoneID = {read=FBoneID, write=FBoneID, nodefault};
	__property unsigned Color = {read=FColor, write=SetColor, nodefault};
	__property TgxSkeletonBone* Items[int Index] = {read=GetSkeletonBone/*, default*/};
	virtual TgxSkeletonBone* __fastcall BoneByID(int anID);
	virtual TgxSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	void __fastcall SetGlobalMatrix(const Stage::Vectortypes::TMatrix4f &Matrix);
	void __fastcall SetGlobalMatrixForRagDoll(const Stage::Vectortypes::TMatrix4f &RagDollMatrix);
	virtual void __fastcall PrepareGlobalMatrices();
	__property Stage::Vectortypes::TMatrix4f GlobalMatrix = {read=FGlobalMatrix};
	virtual void __fastcall Clean();
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonBone(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxSkeletonBoneList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonCollider : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TgxSkeletonColliderList* FOwner;
	TgxSkeletonBone* FBone;
	int FBoneID;
	Stage::Vectortypes::TMatrix4f FLocalMatrix;
	Stage::Vectortypes::TMatrix4f FGlobalMatrix;
	bool FAutoUpdate;
	
protected:
	void __fastcall SetBone(TgxSkeletonBone* const val);
	void __fastcall SetLocalMatrix(const Stage::Vectortypes::TMatrix4f &val);
	
public:
	__fastcall virtual TgxSkeletonCollider();
	__fastcall TgxSkeletonCollider(TgxSkeletonColliderList* aOwner);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall AlignCollider();
	__property TgxSkeletonColliderList* Owner = {read=FOwner};
	__property TgxSkeletonBone* Bone = {read=FBone, write=SetBone};
	__property Stage::Vectortypes::TMatrix4f LocalMatrix = {read=FLocalMatrix, write=SetLocalMatrix};
	__property Stage::Vectortypes::TMatrix4f GlobalMatrix = {read=FGlobalMatrix};
	__property bool AutoUpdate = {read=FAutoUpdate, write=FAutoUpdate, nodefault};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonCollider(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxSkeletonCollider() { }
	
};


class PASCALIMPLEMENTATION TgxSkeletonColliderList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxSkeletonCollider* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TgxSkeletonCollider* __fastcall GetSkeletonCollider(int Index);
	
public:
	__fastcall TgxSkeletonColliderList(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TgxSkeletonColliderList();
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall Clear();
	void __fastcall AlignColliders();
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property TgxSkeletonCollider* Items[int Index] = {read=GetSkeletonCollider/*, default*/};
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxSkeletonColliderList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonColliderList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


struct DECLSPEC_DRECORD TGXBlendedLerpInfo
{
public:
	int frameIndex1;
	int frameIndex2;
	float lerpFactor;
	float weight;
	Gxs::Vectorlists::TgxAffineVectorList* externalPositions;
	Gxs::Vectorlists::TgxAffineVectorList* externalRotations;
	Gxs::Vectorlists::TGQuaternionList* externalQuaternions;
};


class PASCALIMPLEMENTATION TgxSkeleton : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TgxBaseMesh* FOwner;
	TgxSkeletonRootBoneList* FRootBones;
	TgxSkeletonFrameList* FFrames;
	TgxSkeletonFrame* FCurrentFrame;
	System::Classes::TList* FBonesByIDCache;
	TgxSkeletonColliderList* FColliders;
	bool FRagDollEnabled;
	bool FMorphInvisibleParts;
	
protected:
	void __fastcall SetRootBones(TgxSkeletonRootBoneList* const val);
	void __fastcall SetFrames(TgxSkeletonFrameList* const val);
	TgxSkeletonFrame* __fastcall GetCurrentFrame();
	void __fastcall SetCurrentFrame(TgxSkeletonFrame* val);
	void __fastcall SetColliders(TgxSkeletonColliderList* const val);
	
public:
	__fastcall TgxSkeleton(TgxBaseMesh* aOwner);
	__fastcall virtual TgxSkeleton();
	__fastcall virtual ~TgxSkeleton();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxBaseMesh* Owner = {read=FOwner};
	__property TgxSkeletonRootBoneList* RootBones = {read=FRootBones, write=SetRootBones};
	__property TgxSkeletonFrameList* Frames = {read=FFrames, write=SetFrames};
	__property TgxSkeletonFrame* CurrentFrame = {read=GetCurrentFrame, write=SetCurrentFrame};
	__property TgxSkeletonColliderList* Colliders = {read=FColliders, write=SetColliders};
	void __fastcall FlushBoneByIDCache();
	TgxSkeletonBone* __fastcall BoneByID(int anID);
	TgxSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	int __fastcall BoneCount();
	void __fastcall MorphTo(int frameIndex)/* overload */;
	void __fastcall MorphTo(TgxSkeletonFrame* frame)/* overload */;
	void __fastcall Lerp(int frameIndex1, int frameIndex2, float lerpFactor);
	void __fastcall BlendedLerps(const TGXBlendedLerpInfo *lerpInfos, const System::NativeInt lerpInfos_High);
	void __fastcall MakeSkeletalTranslationStatic(int startFrame, int endFrame);
	void __fastcall MakeSkeletalRotationDelta(int startFrame, int endFrame);
	void __fastcall MorphMesh(bool normalize);
	void __fastcall Synchronize(TgxSkeleton* reference);
	void __fastcall Clear();
	void __fastcall StartRagdoll();
	void __fastcall StopRagdoll();
	__property bool MorphInvisibleParts = {read=FMorphInvisibleParts, write=FMorphInvisibleParts, nodefault};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeleton(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


enum DECLSPEC_DENUM TgxMeshObjectRenderingOption : unsigned char { moroGroupByMaterial };

typedef System::Set<TgxMeshObjectRenderingOption, TgxMeshObjectRenderingOption::moroGroupByMaterial, TgxMeshObjectRenderingOption::moroGroupByMaterial> TgxMeshObjectRenderingOptions;

enum DECLSPEC_DENUM TVBOBuffer : unsigned char { vbVertices, vbNormals, vbColors, vbTexCoords, vbLightMapTexCoords, vbTexCoordsEx };

typedef System::Set<TVBOBuffer, TVBOBuffer::vbVertices, TVBOBuffer::vbTexCoordsEx> TVBOBuffers;

class PASCALIMPLEMENTATION TgxMeshObject : public TgxBaseMeshObject
{
	typedef TgxBaseMeshObject inherited;
	
	
private:
	typedef System::DynamicArray<Gxs::Context::TgxVBOHandle*> _TgxMeshObject__1;
	
	
private:
	TgxMeshObjectList* FOwner;
	unsigned FExtentCacheRevision;
	Gxs::Vectorlists::TgxAffineVectorList* FTexCoords;
	Gxs::Vectorlists::TgxAffineVectorList* FLightMapTexCoords;
	Gxs::Vectorlists::TgxVectorList* FColors;
	TgxFaceGroups* FFaceGroups;
	TgxMeshObjectMode FMode;
	TgxMeshObjectRenderingOptions FRenderingOptions;
	bool FArraysDeclared;
	bool FLightMapArrayEnabled;
	int FLastLightMapIndex;
	System::Classes::TList* FTexCoordsEx;
	int FBinormalsTexCoordIndex;
	int FTangentsTexCoordIndex;
	unsigned FLastXOpenGLTexMapping;
	bool FUseVBO;
	Gxs::Context::TgxVBOHandle* FVerticesVBO;
	Gxs::Context::TgxVBOHandle* FNormalsVBO;
	Gxs::Context::TgxVBOHandle* FColorsVBO;
	_TgxMeshObject__1 FTexCoordsVBO;
	Gxs::Context::TgxVBOHandle* FLightmapTexCoordsVBO;
	TVBOBuffers FValidBuffers;
	Gxs::Geometrybb::TAABB FExtentCache;
	void __fastcall SetUseVBO(const bool Value);
	void __fastcall SetValidBuffers(TVBOBuffers Value);
	
protected:
	void __fastcall SetTexCoords(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetLightmapTexCoords(Gxs::Vectorlists::TgxAffineVectorList* const val);
	void __fastcall SetColors(Gxs::Vectorlists::TgxVectorList* const val);
	void __fastcall BufferArrays();
	void __fastcall DeclareArraysToOpenGL(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci, bool evenIfAlreadyDeclared = false);
	void __fastcall DisableOpenGLArrays(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	void __fastcall EnableLightMapArray(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	void __fastcall DisableLightMapArray(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	void __fastcall SetTexCoordsEx(int Index, Gxs::Vectorlists::TgxVectorList* const val);
	Gxs::Vectorlists::TgxVectorList* __fastcall GetTexCoordsEx(int Index);
	void __fastcall SetBinormals(Gxs::Vectorlists::TgxVectorList* const val);
	Gxs::Vectorlists::TgxVectorList* __fastcall GetBinormals();
	void __fastcall SetBinormalsTexCoordIndex(const int val);
	void __fastcall SetTangents(Gxs::Vectorlists::TgxVectorList* const val);
	Gxs::Vectorlists::TgxVectorList* __fastcall GetTangents();
	void __fastcall SetTangentsTexCoordIndex(const int val);
	__property TVBOBuffers ValidBuffers = {read=FValidBuffers, write=SetValidBuffers, nodefault};
	
public:
	__fastcall TgxMeshObject(TgxMeshObjectList* aOwner);
	__fastcall virtual TgxMeshObject();
	__fastcall virtual ~TgxMeshObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual Gxs::Vectorlists::TgxAffineVectorList* __fastcall ExtractTriangles(Gxs::Vectorlists::TgxAffineVectorList* texCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount();
	void __fastcall PrepareMaterialLibraryCache(Gxs::Material::TgxMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max)/* overload */;
	virtual void __fastcall GetExtents(/* out */ Gxs::Geometrybb::TAABB &aabb)/* overload */;
	Stage::Vectortypes::TVector4f __fastcall GetBarycenter();
	virtual void __fastcall Prepare();
	virtual bool __fastcall PointInObject(const Stage::Vectorgeometry::TAffineVector &aPoint);
	void __fastcall GetTriangleData(int tri, Gxs::Vectorlists::TgxAffineVectorList* list, Stage::Vectorgeometry::TAffineVector &v0, Stage::Vectorgeometry::TAffineVector &v1, Stage::Vectorgeometry::TAffineVector &v2)/* overload */;
	void __fastcall GetTriangleData(int tri, Gxs::Vectorlists::TgxVectorList* list, Stage::Vectortypes::TVector4f &v0, Stage::Vectortypes::TVector4f &v1, Stage::Vectortypes::TVector4f &v2)/* overload */;
	void __fastcall SetTriangleData(int tri, Gxs::Vectorlists::TgxAffineVectorList* list, const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2)/* overload */;
	void __fastcall SetTriangleData(int tri, Gxs::Vectorlists::TgxVectorList* list, const Stage::Vectortypes::TVector4f &v0, const Stage::Vectortypes::TVector4f &v1, const Stage::Vectortypes::TVector4f &v2)/* overload */;
	void __fastcall BuildTangentSpace(bool buildBinormals = true, bool buildTangents = true);
	__property TgxMeshObjectList* Owner = {read=FOwner};
	__property TgxMeshObjectMode mode = {read=FMode, write=FMode, nodefault};
	__property Gxs::Vectorlists::TgxAffineVectorList* texCoords = {read=FTexCoords, write=SetTexCoords};
	__property Gxs::Vectorlists::TgxAffineVectorList* LightMapTexCoords = {read=FLightMapTexCoords, write=SetLightmapTexCoords};
	__property Gxs::Vectorlists::TgxVectorList* Colors = {read=FColors, write=SetColors};
	__property TgxFaceGroups* FaceGroups = {read=FFaceGroups};
	__property TgxMeshObjectRenderingOptions RenderingOptions = {read=FRenderingOptions, write=FRenderingOptions, nodefault};
	__property bool UseVBO = {read=FUseVBO, write=SetUseVBO, nodefault};
	__property Gxs::Vectorlists::TgxVectorList* TexCoordsEx[int index] = {read=GetTexCoordsEx, write=SetTexCoordsEx};
	__property Gxs::Vectorlists::TgxVectorList* Binormals = {read=GetBinormals, write=SetBinormals};
	__property Gxs::Vectorlists::TgxVectorList* Tangents = {read=GetTangents, write=SetTangents};
	__property int BinormalsTexCoordIndex = {read=FBinormalsTexCoordIndex, write=SetBinormalsTexCoordIndex, nodefault};
	__property int TangentsTexCoordIndex = {read=FTangentsTexCoordIndex, write=SetTangentsTexCoordIndex, nodefault};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxBaseMeshObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxMeshObjectList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxMeshObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxBaseMesh* FOwner;
	bool __fastcall GetUseVBO();
	void __fastcall SetUseVBO(const bool Value);
	
protected:
	TgxMeshObject* __fastcall GetMeshObject(int Index);
	
public:
	__fastcall TgxMeshObjectList(TgxBaseMesh* aOwner);
	__fastcall virtual ~TgxMeshObjectList();
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gxs::Material::TgxMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	void __fastcall MorphTo(int morphTargetIndex);
	void __fastcall Lerp(int morphTargetIndex1, int morphTargetIndex2, float lerpFactor);
	int __fastcall MorphTargetCount();
	void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max);
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall ExtractTriangles(Gxs::Vectorlists::TgxAffineVectorList* texCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	int __fastcall TriangleCount();
	void __fastcall BuildTangentSpace(bool buildBinormals = true, bool buildTangents = true);
	__property bool UseVBO = {read=GetUseVBO, write=SetUseVBO, nodefault};
	virtual void __fastcall Prepare();
	TgxMeshObject* __fastcall FindMeshByName(System::UnicodeString MeshName);
	__property TgxBaseMesh* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TgxMeshObject* Items[int Index] = {read=GetMeshObject/*, default*/};
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxMeshObjectList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMeshObjectList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxMeshObjectListClass);

class PASCALIMPLEMENTATION TgxMeshMorphTarget : public TgxBaseMeshObject
{
	typedef TgxBaseMeshObject inherited;
	
private:
	TgxMeshMorphTargetList* FOwner;
	
public:
	__fastcall TgxMeshMorphTarget(TgxMeshMorphTargetList* aOwner);
	__fastcall virtual ~TgxMeshMorphTarget();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxMeshMorphTargetList* Owner = {read=FOwner};
public:
	/* TgxBaseMeshObject.Create */ inline __fastcall virtual TgxMeshMorphTarget() : TgxBaseMeshObject() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMeshMorphTarget(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxBaseMeshObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxMeshMorphTargetList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxMeshMorphTarget* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TgxMeshMorphTarget* __fastcall GetMeshMorphTarget(int Index);
	
public:
	__fastcall TgxMeshMorphTargetList(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TgxMeshMorphTargetList();
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TgxMeshMorphTarget* Items[int Index] = {read=GetMeshMorphTarget/*, default*/};
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxMeshMorphTargetList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMeshMorphTargetList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxMorphableMeshObject : public TgxMeshObject
{
	typedef TgxMeshObject inherited;
	
private:
	TgxMeshMorphTargetList* FMorphTargets;
	
public:
	__fastcall virtual TgxMorphableMeshObject();
	__fastcall virtual ~TgxMorphableMeshObject();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	virtual void __fastcall MorphTo(int morphTargetIndex);
	virtual void __fastcall Lerp(int morphTargetIndex1, int morphTargetIndex2, float lerpFactor);
	__property TgxMeshMorphTargetList* MorphTargets = {read=FMorphTargets};
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxMorphableMeshObject(TgxMeshObjectList* aOwner) : TgxMeshObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxMorphableMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxMeshObject(reader) { }
	
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxVertexBoneWeight
{
public:
	int BoneID;
	float weight;
};
#pragma pack(pop)


typedef System::StaticArray<TgxVertexBoneWeight, 134217728> TgxVertexBoneWeightArray;

typedef TgxVertexBoneWeightArray *PgxVertexBoneWeightArray;

typedef System::StaticArray<PgxVertexBoneWeightArray, 134217728> TgxVerticesBoneWeights;

typedef TgxVerticesBoneWeights *PgxVerticesBoneWeights;

typedef System::DynamicArray<TgxVertexBoneWeight> TgxVertexBoneWeightDynArray;

class PASCALIMPLEMENTATION TgxSkeletonMeshObject : public TgxMorphableMeshObject
{
	typedef TgxMorphableMeshObject inherited;
	
private:
	PgxVerticesBoneWeights FVerticesBonesWeights;
	int FVerticeBoneWeightCount;
	int FVerticeBoneWeightCapacity;
	int FBonesPerVertex;
	int FLastVerticeBoneWeightCount;
	int FLastBonesPerVertex;
	System::Classes::TList* FBoneMatrixInvertedMeshes;
	System::Classes::TList* FBackupInvertedMeshes;
	void __fastcall BackupBoneMatrixInvertedMeshes();
	void __fastcall RestoreBoneMatrixInvertedMeshes();
	
protected:
	void __fastcall SetVerticeBoneWeightCount(const int val);
	void __fastcall SetVerticeBoneWeightCapacity(const int val);
	void __fastcall SetBonesPerVertex(const int val);
	void __fastcall ResizeVerticesBonesWeights();
	
public:
	__fastcall virtual TgxSkeletonMeshObject();
	__fastcall virtual ~TgxSkeletonMeshObject();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall Clear();
	__property PgxVerticesBoneWeights VerticesBonesWeights = {read=FVerticesBonesWeights};
	__property int VerticeBoneWeightCount = {read=FVerticeBoneWeightCount, write=SetVerticeBoneWeightCount, nodefault};
	__property int VerticeBoneWeightCapacity = {read=FVerticeBoneWeightCapacity, write=SetVerticeBoneWeightCapacity, nodefault};
	__property int BonesPerVertex = {read=FBonesPerVertex, write=SetBonesPerVertex, nodefault};
	int __fastcall FindOrAdd(int BoneID, const Stage::Vectorgeometry::TAffineVector &vertex, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	int __fastcall FindOrAdd(const TgxVertexBoneWeightDynArray boneIDs, const Stage::Vectorgeometry::TAffineVector &vertex, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	void __fastcall AddWeightedBone(int aBoneID, float aWeight);
	void __fastcall AddWeightedBones(const TgxVertexBoneWeightDynArray boneIDs);
	void __fastcall PrepareBoneMatrixInvertedMeshes();
	void __fastcall ApplyCurrentSkeletonFrame(bool normalize);
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxSkeletonMeshObject(TgxMeshObjectList* aOwner) : TgxMorphableMeshObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxSkeletonMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxMorphableMeshObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFaceGroup : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	TgxFaceGroups* FOwner;
	System::UnicodeString FMaterialName;
	Gxs::Material::TgxLibMaterial* FMaterialCache;
	int FLightMapIndex;
	int FRenderGroupID;
	
protected:
	void __fastcall AttachLightmap(Gxs::Texture::TgxTexture* lightMap, Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	void __fastcall AttachOrDetachLightmap(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	
public:
	__fastcall virtual TgxFaceGroup(TgxFaceGroups* aOwner);
	__fastcall virtual ~TgxFaceGroup();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gxs::Material::TgxMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci) = 0 ;
	virtual void __fastcall AddToTriangles(Gxs::Vectorlists::TgxAffineVectorList* aList, Gxs::Vectorlists::TgxAffineVectorList* aTexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* aNormals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount() = 0 ;
	virtual void __fastcall Reverse();
	virtual void __fastcall Prepare();
	__property TgxFaceGroups* Owner = {read=FOwner, write=FOwner};
	__property System::UnicodeString MaterialName = {read=FMaterialName, write=FMaterialName};
	__property Gxs::Material::TgxLibMaterial* MaterialCache = {read=FMaterialCache};
	__property int LightMapIndex = {read=FLightMapIndex, write=FLightMapIndex, nodefault};
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFaceGroup() : Gxs::Persistentclasses::TgxPersistentObject() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFaceGroup(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


enum DECLSPEC_DENUM TgxFaceGroupMeshMode : unsigned char { fgmmTriangles, fgmmTriangleStrip, fgmmFlatTriangles, fgmmTriangleFan, fgmmQuads };

class PASCALIMPLEMENTATION TgxFGVertexIndexList : public TgxFaceGroup
{
	typedef TgxFaceGroup inherited;
	
private:
	Gxs::Vectorlists::TgxIntegerList* FVertexIndices;
	Gxs::Context::TgxVBOElementArrayHandle* FIndexVBO;
	TgxFaceGroupMeshMode FMode;
	void __fastcall SetupVBO();
	void __fastcall InvalidateVBO();
	
protected:
	void __fastcall SetVertexIndices(Gxs::Vectorlists::TgxIntegerList* const val);
	void __fastcall AddToList(Gxs::Vectorlists::TgxAffineVectorList* Source, Gxs::Vectorlists::TgxAffineVectorList* destination, Gxs::Vectorlists::TgxIntegerList* indices);
	
public:
	__fastcall virtual TgxFGVertexIndexList();
	__fastcall virtual ~TgxFGVertexIndexList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Gxs::Vectorlists::TgxAffineVectorList* aList, Gxs::Vectorlists::TgxAffineVectorList* aTexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* aNormals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount();
	virtual void __fastcall Reverse();
	void __fastcall Add(int idx);
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
	void __fastcall ConvertToList();
	Stage::Vectorgeometry::TAffineVector __fastcall GetNormal();
	__property TgxFaceGroupMeshMode mode = {read=FMode, write=FMode, nodefault};
	__property Gxs::Vectorlists::TgxIntegerList* vertexIndices = {read=FVertexIndices, write=SetVertexIndices};
public:
	/* TgxFaceGroup.CreateOwned */ inline __fastcall virtual TgxFGVertexIndexList(TgxFaceGroups* aOwner) : TgxFaceGroup(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFGVertexIndexList(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFaceGroup(reader) { }
	
};


class PASCALIMPLEMENTATION TFGVertexNormalTexIndexList : public TgxFGVertexIndexList
{
	typedef TgxFGVertexIndexList inherited;
	
private:
	Gxs::Vectorlists::TgxIntegerList* FNormalIndices;
	Gxs::Vectorlists::TgxIntegerList* FTexCoordIndices;
	
protected:
	void __fastcall SetNormalIndices(Gxs::Vectorlists::TgxIntegerList* const val);
	void __fastcall SetTexCoordIndices(Gxs::Vectorlists::TgxIntegerList* const val);
	
public:
	__fastcall virtual TFGVertexNormalTexIndexList();
	__fastcall virtual ~TFGVertexNormalTexIndexList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Gxs::Vectorlists::TgxAffineVectorList* aList, Gxs::Vectorlists::TgxAffineVectorList* aTexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* aNormals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	HIDESBASE void __fastcall Add(int vertexIdx, int normalIdx, int texCoordIdx);
	__property Gxs::Vectorlists::TgxIntegerList* normalIndices = {read=FNormalIndices, write=SetNormalIndices};
	__property Gxs::Vectorlists::TgxIntegerList* TexCoordIndices = {read=FTexCoordIndices, write=SetTexCoordIndices};
public:
	/* TgxFaceGroup.CreateOwned */ inline __fastcall virtual TFGVertexNormalTexIndexList(TgxFaceGroups* aOwner) : TgxFGVertexIndexList(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TFGVertexNormalTexIndexList(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFGVertexIndexList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFGIndexTexCoordList : public TgxFGVertexIndexList
{
	typedef TgxFGVertexIndexList inherited;
	
private:
	Gxs::Vectorlists::TgxAffineVectorList* FTexCoords;
	
protected:
	void __fastcall SetTexCoords(Gxs::Vectorlists::TgxAffineVectorList* const val);
	
public:
	__fastcall virtual TgxFGIndexTexCoordList();
	__fastcall virtual ~TgxFGIndexTexCoordList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Gxs::Vectorlists::TgxAffineVectorList* aList, Gxs::Vectorlists::TgxAffineVectorList* aTexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* aNormals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	HIDESBASE void __fastcall Add(int idx, const Stage::Vectorgeometry::TAffineVector &texCoord)/* overload */;
	HIDESBASE void __fastcall Add(int idx, const float s, const float t)/* overload */;
	__property Gxs::Vectorlists::TgxAffineVectorList* texCoords = {read=FTexCoords, write=SetTexCoords};
public:
	/* TgxFaceGroup.CreateOwned */ inline __fastcall virtual TgxFGIndexTexCoordList(TgxFaceGroups* aOwner) : TgxFGVertexIndexList(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFGIndexTexCoordList(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFGVertexIndexList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFaceGroups : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxFaceGroup* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxMeshObject* FOwner;
	
protected:
	TgxFaceGroup* __fastcall GetFaceGroup(int Index);
	
public:
	__fastcall TgxFaceGroups(TgxMeshObject* aOwner);
	__fastcall virtual ~TgxFaceGroups();
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gxs::Material::TgxMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	__property TgxMeshObject* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TgxFaceGroup* Items[int Index] = {read=GetFaceGroup/*, default*/};
	void __fastcall AddToTriangles(Gxs::Vectorlists::TgxAffineVectorList* aList, Gxs::Vectorlists::TgxAffineVectorList* aTexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* aNormals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	Gxs::Material::TgxMaterialLibrary* __fastcall MaterialLibrary();
	void __fastcall SortByMaterial();
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxFaceGroups() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFaceGroups(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


enum DECLSPEC_DENUM TgxMeshNormalsOrientation : unsigned char { mnoDefault, mnoInvert };

class PASCALIMPLEMENTATION TgxVectorFile : public Gxs::Applicationfileio::TgxDataFile
{
	typedef Gxs::Applicationfileio::TgxDataFile inherited;
	
private:
	TgxMeshNormalsOrientation FNormalsOrientation;
	
protected:
	virtual void __fastcall SetNormalsOrientation(const TgxMeshNormalsOrientation val);
	
public:
	__fastcall virtual TgxVectorFile(System::Classes::TPersistent* aOwner);
	HIDESBASE TgxBaseMesh* __fastcall Owner();
	__property TgxMeshNormalsOrientation NormalsOrientation = {read=FNormalsOrientation, write=SetNormalsOrientation, nodefault};
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxVectorFile() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxVectorFileClass);

class PASCALIMPLEMENTATION TgxVectorFileGLSM : public TgxVectorFile
{
	typedef TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxVectorFileGLSM(System::Classes::TPersistent* aOwner) : TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxVectorFileGLSM() { }
	
};


class PASCALIMPLEMENTATION TgxBaseMesh : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	TgxMeshNormalsOrientation FNormalsOrientation;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxMaterialLibrary* FLightmapLibrary;
	Stage::Vectortypes::TVector4f FAxisAlignedDimensionsCache;
	bool FBaryCenterOffsetChanged;
	Stage::Vectortypes::TVector4f FBaryCenterOffset;
	bool FUseMeshMaterials;
	bool FOverlaySkeleton;
	bool FIgnoreMissingTextures;
	TgxMeshAutoCenterings FAutoCentering;
	Gxs::Coordinates::TgxCoordinates* FAutoScaling;
	bool FMaterialLibraryCachesPrepared;
	System::TObject* FConnectivity;
	System::UnicodeString FLastLoadedFilename;
	
protected:
	TgxMeshObjectList* FMeshObjects;
	TgxSkeleton* FSkeleton;
	void __fastcall SetUseMeshMaterials(const bool val);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetLightmapLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetNormalsOrientation(const TgxMeshNormalsOrientation val);
	void __fastcall SetOverlaySkeleton(const bool val);
	void __fastcall SetAutoScaling(Gxs::Coordinates::TgxCoordinates* const Value);
	virtual void __fastcall DestroyHandle();
	virtual void __fastcall PrepareVectorFile(TgxVectorFile* aFile);
	virtual void __fastcall PrepareMesh();
	void __fastcall PrepareMaterialLibraryCache();
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	
public:
	__fastcall virtual TgxBaseMesh(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxBaseMesh();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	Stage::Vectortypes::TVector4f __fastcall BarycenterOffset();
	Stage::Vectortypes::TVector4f __fastcall BarycenterPosition();
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall StructureChanged();
	void __fastcall StructureChangedNoPrepare();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	virtual Gxs::Silhouette::TgxSilhouette* __fastcall GenerateSilhouette(const Gxs::Silhouette::TgxSilhouetteParameters &SilhouetteParameters);
	void __fastcall BuildSilhouetteConnectivityData();
	__property TgxMeshObjectList* MeshObjects = {read=FMeshObjects};
	__property TgxSkeleton* Skeleton = {read=FSkeleton};
	void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max);
	Stage::Vectorgeometry::TAffineVector __fastcall GetBarycenter();
	virtual void __fastcall PerformAutoCentering();
	virtual void __fastcall PerformAutoScaling();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	virtual void __fastcall AddDataFromFile(const System::UnicodeString filename);
	virtual void __fastcall AddDataFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	System::UnicodeString __fastcall LastLoadedFilename();
	__property TgxMeshAutoCenterings AutoCentering = {read=FAutoCentering, write=FAutoCentering, default=0};
	__property Gxs::Coordinates::TgxCoordinates* AutoScaling = {read=FAutoScaling, write=FAutoScaling};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property bool UseMeshMaterials = {read=FUseMeshMaterials, write=SetUseMeshMaterials, default=1};
	__property Gxs::Material::TgxMaterialLibrary* LightmapLibrary = {read=FLightmapLibrary, write=SetLightmapLibrary};
	__property bool IgnoreMissingTextures = {read=FIgnoreMissingTextures, write=FIgnoreMissingTextures, default=0};
	__property TgxMeshNormalsOrientation NormalsOrientation = {read=FNormalsOrientation, write=SetNormalsOrientation, default=0};
	__property bool OverlaySkeleton = {read=FOverlaySkeleton, write=SetOverlaySkeleton, default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBaseMesh(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFreeForm : public TgxBaseMesh
{
	typedef TgxBaseMesh inherited;
	
private:
	Gxs::Octree::TgxOctree* FOctree;
	
protected:
	Gxs::Octree::TgxOctree* __fastcall GetOctree();
	
public:
	__fastcall virtual TgxFreeForm(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxFreeForm();
	bool __fastcall OctreeRayCastIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	bool __fastcall OctreeSphereSweepIntersect(const Stage::Vectortypes::TVector4f &rayStart, const Stage::Vectortypes::TVector4f &rayVector, const float velocity, const float radius, Stage::Vectortypes::PVector4f intersectPoint = (Stage::Vectortypes::PVector4f)(0x0), Stage::Vectortypes::PVector4f intersectNormal = (Stage::Vectortypes::PVector4f)(0x0));
	bool __fastcall OctreeTriangleIntersect(const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2, const Stage::Vectorgeometry::TAffineVector &v3);
	bool __fastcall OctreePointInMesh(const Stage::Vectortypes::TVector4f &Point);
	bool __fastcall OctreeAABBIntersect(const Gxs::Geometrybb::TAABB &aabb, const Stage::Vectortypes::TMatrix4f &objMatrix, const Stage::Vectortypes::TMatrix4f &invObjMatrix, Gxs::Vectorlists::TgxAffineVectorList* triangles = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	__property Gxs::Octree::TgxOctree* Octree = {read=GetOctree};
	void __fastcall BuildOctree(int TreeDepth = 0x3);
	
__published:
	__property AutoCentering = {default=0};
	__property AutoScaling;
	__property MaterialLibrary;
	__property LightmapLibrary;
	__property UseMeshMaterials = {default=1};
	__property NormalsOrientation = {default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFreeForm(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseMesh(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TgxActorOption : unsigned char { aoSkeletonNormalizeNormals };

typedef System::Set<TgxActorOption, TgxActorOption::aoSkeletonNormalizeNormals, TgxActorOption::aoSkeletonNormalizeNormals> TgxActorOptions;

enum DECLSPEC_DENUM TgxActorAnimationReference : unsigned char { aarMorph, aarSkeleton, aarNone };

class PASCALIMPLEMENTATION TgxActorAnimation : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	int FStartFrame;
	int FEndFrame;
	TgxActorAnimationReference FReference;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	int __fastcall FrameCount();
	void __fastcall SetStartFrame(const int val);
	void __fastcall SetEndFrame(const int val);
	void __fastcall SetReference(TgxActorAnimationReference val);
	void __fastcall SetAsString(const System::UnicodeString val);
	System::UnicodeString __fastcall GetAsString();
	
public:
	__fastcall virtual TgxActorAnimation(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxActorAnimation();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::UnicodeString AsString = {read=GetAsString, write=SetAsString};
	TgxActor* __fastcall OwnerActor();
	void __fastcall MakeSkeletalTranslationStatic();
	void __fastcall MakeSkeletalRotationDelta();
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int startFrame = {read=FStartFrame, write=SetStartFrame, nodefault};
	__property int endFrame = {read=FEndFrame, write=SetEndFrame, nodefault};
	__property TgxActorAnimationReference reference = {read=FReference, write=SetReference, default=0};
};


typedef System::UnicodeString TgxActorAnimationName;

class PASCALIMPLEMENTATION TgxActorAnimations : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TgxActorAnimation* operator[](int index) { return this->Items[index]; }
	
private:
	TgxActor* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int Index, TgxActorAnimation* const val);
	TgxActorAnimation* __fastcall GetItems(int Index);
	
public:
	__fastcall TgxActorAnimations(TgxActor* aOwner);
	HIDESBASE TgxActorAnimation* __fastcall Add();
	HIDESBASE TgxActorAnimation* __fastcall FindItemID(int ID);
	TgxActorAnimation* __fastcall FindName(const System::UnicodeString aName);
	TgxActorAnimation* __fastcall FindFrame(int aFrame, TgxActorAnimationReference aReference);
	void __fastcall SetToStrings(System::Classes::TStrings* aStrings);
	void __fastcall SaveToStream(System::Classes::TStream* aStream);
	void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	void __fastcall SaveToFile(const System::UnicodeString filename);
	void __fastcall LoadFromFile(const System::UnicodeString filename);
	__property TgxActorAnimation* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TgxActorAnimation* __fastcall Last();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxActorAnimations() { }
	
};


class PASCALIMPLEMENTATION TgxBaseAnimationControler : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FEnabled;
	TgxActor* FActor;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetEnabled(const bool val);
	void __fastcall SetActor(TgxActor* const val);
	virtual void __fastcall DoChange();
	virtual bool __fastcall Apply(TGXBlendedLerpInfo &lerpInfo);
	
public:
	__fastcall virtual TgxBaseAnimationControler(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxBaseAnimationControler();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TgxActor* Actor = {read=FActor, write=SetActor};
};


class PASCALIMPLEMENTATION TgxAnimationControler : public TgxBaseAnimationControler
{
	typedef TgxBaseAnimationControler inherited;
	
private:
	TgxActorAnimationName FAnimationName;
	float FRatio;
	
protected:
	void __fastcall SetAnimationName(const TgxActorAnimationName val);
	void __fastcall SetRatio(const float val);
	virtual void __fastcall DoChange();
	virtual bool __fastcall Apply(TGXBlendedLerpInfo &lerpInfo);
	
__published:
	__property System::UnicodeString AnimationName = {read=FAnimationName, write=SetAnimationName};
	__property float Ratio = {read=FRatio, write=SetRatio};
public:
	/* TgxBaseAnimationControler.Create */ inline __fastcall virtual TgxAnimationControler(System::Classes::TComponent* aOwner) : TgxBaseAnimationControler(aOwner) { }
	/* TgxBaseAnimationControler.Destroy */ inline __fastcall virtual ~TgxAnimationControler() { }
	
};


enum DECLSPEC_DENUM TgxActorFrameInterpolation : unsigned char { afpNone, afpLinear };

enum DECLSPEC_DENUM TgxActorAnimationMode : unsigned char { aamNone, aamPlayOnce, aamLoop, aamBounceForward, aamBounceBackward, aamLoopBackward, aamExternal };

class PASCALIMPLEMENTATION TgxActor : public TgxBaseMesh
{
	typedef TgxBaseMesh inherited;
	
private:
	int FStartFrame;
	int FEndFrame;
	TgxActorAnimationReference FReference;
	int FCurrentFrame;
	float FCurrentFrameDelta;
	TgxActorFrameInterpolation FFrameInterpolation;
	int FInterval;
	TgxActorAnimationMode FAnimationMode;
	System::Classes::TNotifyEvent FOnFrameChanged;
	System::Classes::TNotifyEvent FOnEndFrameReached;
	System::Classes::TNotifyEvent FOnStartFrameReached;
	TgxActorAnimations* FAnimations;
	TgxActorAnimation* FTargetSmoothAnimation;
	System::Classes::TList* FControlers;
	TgxActorOptions FOptions;
	
protected:
	void __fastcall SetCurrentFrame(int val);
	void __fastcall SetStartFrame(int val);
	void __fastcall SetEndFrame(int val);
	HIDESBASE void __fastcall SetReference(TgxActorAnimationReference val);
	void __fastcall SetAnimations(TgxActorAnimations* const val);
	bool __fastcall StoreAnimations();
	void __fastcall SetOptions(const TgxActorOptions val);
	virtual void __fastcall PrepareMesh();
	virtual void __fastcall PrepareBuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &mrci);
	virtual void __fastcall DoAnimate();
	void __fastcall RegisterControler(TgxBaseAnimationControler* aControler);
	void __fastcall UnRegisterControler(TgxBaseAnimationControler* aControler);
	
public:
	__fastcall virtual TgxActor(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxActor();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall LoadFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	void __fastcall SwitchToAnimation(TgxActorAnimation* anAnimation, bool smooth = false)/* overload */;
	void __fastcall SwitchToAnimation(const System::UnicodeString AnimationName, bool smooth = false)/* overload */;
	void __fastcall SwitchToAnimation(int animationIndex, bool smooth = false)/* overload */;
	System::UnicodeString __fastcall CurrentAnimation();
	void __fastcall Synchronize(TgxActor* referenceActor);
	void __fastcall SetCurrentFrameDirect(const int Value);
	int __fastcall NextFrameIndex();
	void __fastcall NextFrame(int nbSteps = 0x1);
	void __fastcall PrevFrame(int nbSteps = 0x1);
	int __fastcall FrameCount();
	bool __fastcall isSwitchingAnimation();
	
__published:
	__property int startFrame = {read=FStartFrame, write=SetStartFrame, default=0};
	__property int endFrame = {read=FEndFrame, write=SetEndFrame, default=0};
	__property TgxActorAnimationReference reference = {read=FReference, write=FReference, default=0};
	__property int CurrentFrame = {read=FCurrentFrame, write=SetCurrentFrame, default=0};
	__property float CurrentFrameDelta = {read=FCurrentFrameDelta, write=FCurrentFrameDelta};
	__property TgxActorFrameInterpolation FrameInterpolation = {read=FFrameInterpolation, write=FFrameInterpolation, default=1};
	__property TgxActorAnimationMode AnimationMode = {read=FAnimationMode, write=FAnimationMode, default=0};
	__property int Interval = {read=FInterval, write=FInterval, nodefault};
	__property TgxActorOptions Options = {read=FOptions, write=SetOptions, default=1};
	__property System::Classes::TNotifyEvent OnFrameChanged = {read=FOnFrameChanged, write=FOnFrameChanged};
	__property System::Classes::TNotifyEvent OnEndFrameReached = {read=FOnEndFrameReached, write=FOnEndFrameReached};
	__property System::Classes::TNotifyEvent OnStartFrameReached = {read=FOnStartFrameReached, write=FOnStartFrameReached};
	__property TgxActorAnimations* Animations = {read=FAnimations, write=SetAnimations, stored=StoreAnimations};
	__property AutoCentering = {default=0};
	__property MaterialLibrary;
	__property LightmapLibrary;
	__property UseMeshMaterials = {default=1};
	__property NormalsOrientation = {default=0};
	__property OverlaySkeleton = {default=0};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxActor(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxBaseMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxVectorFileFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TgxVectorFileClass VectorFileClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
public:
	/* TObject.Create */ inline __fastcall TgxVectorFileFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxVectorFileFormat() { }
	
};


class PASCALIMPLEMENTATION TgxVectorFileFormatsList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	__fastcall virtual ~TgxVectorFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TgxVectorFileClass AClass);
	TgxVectorFileClass __fastcall FindExt(System::UnicodeString Ext);
	TgxVectorFileClass __fastcall FindFromFileName(const System::UnicodeString filename);
	HIDESBASE void __fastcall Remove(TgxVectorFileClass AClass);
	void __fastcall BuildFilterStrings(TgxVectorFileClass VectorFileClass, /* out */ System::UnicodeString &descriptions, /* out */ System::UnicodeString &filters, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
	System::UnicodeString __fastcall FindExtByIndex(int Index, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
public:
	/* TgxPersistentObjectList.Create */ inline __fastcall virtual TgxVectorFileFormatsList() : Gxs::Persistentclasses::TgxPersistentObjectList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxVectorFileFormatsList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION EgxInvalidVectorFile : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EgxInvalidVectorFile(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EgxInvalidVectorFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EgxInvalidVectorFile(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EgxInvalidVectorFile(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxInvalidVectorFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxInvalidVectorFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EgxInvalidVectorFile(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EgxInvalidVectorFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxInvalidVectorFile(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxInvalidVectorFile(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxInvalidVectorFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxInvalidVectorFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EgxInvalidVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultActorOptions (System::Set<TgxActorOption, TgxActorOption::aoSkeletonNormalizeNormals, TgxActorOption::aoSkeletonNormalizeNormals>() << TgxActorOption::aoSkeletonNormalizeNormals )
extern DELPHI_PACKAGE bool vVectorFileObjectsAllocateMaterials;
extern DELPHI_PACKAGE bool vVectorFileObjectsEnableVBOByDefault;
extern DELPHI_PACKAGE TgxVectorFileFormatsList* __fastcall GetVectorFileFormats(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatsFilter(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatsSaveFilter(void);
extern DELPHI_PACKAGE void __fastcall RegisterVectorFileFormat(const System::UnicodeString aExtension, const System::UnicodeString aDescription, TgxVectorFileClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterVectorFileClass(TgxVectorFileClass AClass);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatExtensionByIndex(int Index);
}	/* namespace Vectorfileobjects */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_VECTORFILEOBJECTS)
using namespace Gxs::Vectorfileobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_VectorFileObjectsHPP
