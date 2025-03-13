// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Ragdoll.pas' rev: 36.00 (Windows)

#ifndef GLS_RagdollHPP
#define GLS_RagdollHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <GLS.Scene.hpp>
#include <GLS.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.VectorLists.hpp>
#include <GLS.Objects.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Ragdoll
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLRagdolJoint;
class DELPHICLASS TGLRagdolBoneList;
class DELPHICLASS TGLRagdolBone;
class DELPHICLASS TGLRagdoll;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLRagdolJoint : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall TGLRagdolJoint() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLRagdolJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLRagdolBoneList : public Gls::Persistentclasses::TGLPersistentObjectList
{
	typedef Gls::Persistentclasses::TGLPersistentObjectList inherited;
	
public:
	TGLRagdolBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLRagdoll* FRagdoll;
	
protected:
	TGLRagdolBone* __fastcall GetRagdollBone(int Index);
	
public:
	__fastcall TGLRagdolBoneList(TGLRagdoll* Ragdoll);
	__fastcall virtual ~TGLRagdolBoneList();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	__property TGLRagdoll* Ragdoll = {read=FRagdoll};
	__property TGLRagdolBone* Items[int Index] = {read=GetRagdollBone/*, default*/};
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLRagdolBoneList(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Persistentclasses::TGLPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLRagdolBone : public TGLRagdolBoneList
{
	typedef TGLRagdolBoneList inherited;
	
public:
	TGLRagdolBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLRagdolBoneList* FOwner;
	System::UnicodeString FName;
	int FBoneID;
	Stage::Vectorgeometry::TAffineVector FBoundMax;
	Stage::Vectorgeometry::TAffineVector FBoundMin;
	Stage::Vectorgeometry::TAffineVector FBoundBoneDelta;
	Stage::Vectorgeometry::TAffineVector FOrigin;
	Stage::Vectorgeometry::TAffineVector FSize;
	Stage::Vectortypes::TGLMatrix FBoneMatrix;
	TGLRagdolJoint* FJoint;
	Stage::Vectortypes::TGLMatrix FOriginalMatrix;
	Stage::Vectortypes::TGLMatrix FReferenceMatrix;
	Stage::Vectorgeometry::TAffineVector FAnchor;
	void __fastcall CreateBoundingBox();
	void __fastcall SetAnchor(const Stage::Vectorgeometry::TAffineVector &Anchor);
	void __fastcall AlignToSkeleton();
	void __fastcall CreateBoundsChild();
	void __fastcall StartChild();
	void __fastcall AlignChild();
	void __fastcall UpdateChild();
	void __fastcall StopChild();
	
protected:
	HIDESBASE TGLRagdolBone* __fastcall GetRagdollBone(int Index);
	virtual void __fastcall Start() = 0 ;
	virtual void __fastcall Align() = 0 ;
	virtual void __fastcall Update() = 0 ;
	virtual void __fastcall Stop() = 0 ;
	
public:
	__fastcall TGLRagdolBone(TGLRagdolBoneList* aOwner);
	__fastcall TGLRagdolBone(TGLRagdoll* Ragdoll);
	__fastcall virtual ~TGLRagdolBone();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	__property TGLRagdolBoneList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int BoneID = {read=FBoneID, write=FBoneID, nodefault};
	__property Stage::Vectorgeometry::TAffineVector Origin = {read=FOrigin};
	__property Stage::Vectorgeometry::TAffineVector Size = {read=FSize};
	__property Stage::Vectortypes::TGLMatrix BoneMatrix = {read=FBoneMatrix};
	__property Stage::Vectortypes::TGLMatrix ReferenceMatrix = {read=FReferenceMatrix};
	__property Stage::Vectorgeometry::TAffineVector Anchor = {read=FAnchor};
	__property TGLRagdolJoint* Joint = {read=FJoint, write=FJoint};
	__property TGLRagdolBone* Items[int Index] = {read=GetRagdollBone/*, default*/};
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLRagdolBone(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLRagdolBoneList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLRagdoll : public Gls::Persistentclasses::TGLPersistentObject
{
	typedef Gls::Persistentclasses::TGLPersistentObject inherited;
	
private:
	Gls::Vectorfileobjects::TGLBaseMesh* FOwner;
	TGLRagdolBone* FRootBone;
	bool FEnabled;
	bool FBuilt;
	
public:
	__fastcall TGLRagdoll(Gls::Vectorfileobjects::TGLBaseMesh* aOwner);
	__fastcall virtual ~TGLRagdoll();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	void __fastcall SetRootBone(TGLRagdolBone* RootBone);
	void __fastcall BuildRagdoll();
	void __fastcall Start();
	void __fastcall Update();
	void __fastcall Stop();
	__property Gls::Vectorfileobjects::TGLBaseMesh* Owner = {read=FOwner};
	__property TGLRagdolBone* RootBone = {read=FRootBone};
	__property bool Enabled = {read=FEnabled, nodefault};
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLRagdoll(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Persistentclasses::TGLPersistentObject(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ragdoll */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_RAGDOLL)
using namespace Gls::Ragdoll;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_RagdollHPP
