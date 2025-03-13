// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Ragdoll.pas' rev: 36.00 (Windows)

#ifndef GXS_RagdollHPP
#define GXS_RagdollHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Ragdoll
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxRagdolJoint;
class DELPHICLASS TgxRagdolBoneList;
class DELPHICLASS TgxRagdolBone;
class DELPHICLASS TgxRagdoll;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxRagdolJoint : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall TgxRagdolJoint() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxRagdolJoint() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxRagdolBoneList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	TgxRagdolBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxRagdoll* FRagdoll;
	
protected:
	TgxRagdolBone* __fastcall GetRagdollBone(int Index);
	
public:
	__fastcall TgxRagdolBoneList(TgxRagdoll* Ragdoll);
	__fastcall virtual ~TgxRagdolBoneList();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxRagdoll* Ragdoll = {read=FRagdoll};
	__property TgxRagdolBone* Items[int Index] = {read=GetRagdollBone/*, default*/};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxRagdolBoneList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxRagdolBone : public TgxRagdolBoneList
{
	typedef TgxRagdolBoneList inherited;
	
public:
	TgxRagdolBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TgxRagdolBoneList* FOwner;
	System::UnicodeString FName;
	int FBoneID;
	Stage::Vectorgeometry::TAffineVector FBoundMax;
	Stage::Vectorgeometry::TAffineVector FBoundMin;
	Stage::Vectorgeometry::TAffineVector FBoundBoneDelta;
	Stage::Vectorgeometry::TAffineVector FOrigin;
	Stage::Vectorgeometry::TAffineVector FSize;
	Stage::Vectortypes::TMatrix4f FBoneMatrix;
	TgxRagdolJoint* FJoint;
	Stage::Vectortypes::TMatrix4f FOriginalMatrix;
	Stage::Vectortypes::TMatrix4f FReferenceMatrix;
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
	HIDESBASE TgxRagdolBone* __fastcall GetRagdollBone(int Index);
	virtual void __fastcall Start() = 0 ;
	virtual void __fastcall Align() = 0 ;
	virtual void __fastcall Update() = 0 ;
	virtual void __fastcall Stop() = 0 ;
	
public:
	__fastcall TgxRagdolBone(TgxRagdolBoneList* aOwner);
	__fastcall TgxRagdolBone(TgxRagdoll* Ragdoll);
	__fastcall virtual ~TgxRagdolBone();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property TgxRagdolBoneList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int BoneID = {read=FBoneID, write=FBoneID, nodefault};
	__property Stage::Vectorgeometry::TAffineVector Origin = {read=FOrigin};
	__property Stage::Vectorgeometry::TAffineVector Size = {read=FSize};
	__property Stage::Vectortypes::TMatrix4f BoneMatrix = {read=FBoneMatrix};
	__property Stage::Vectortypes::TMatrix4f ReferenceMatrix = {read=FReferenceMatrix};
	__property Stage::Vectorgeometry::TAffineVector Anchor = {read=FAnchor};
	__property TgxRagdolJoint* Joint = {read=FJoint, write=FJoint};
	__property TgxRagdolBone* Items[int Index] = {read=GetRagdollBone/*, default*/};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxRagdolBone(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxRagdolBoneList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxRagdoll : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
private:
	Gxs::Vectorfileobjects::TgxBaseMesh* FOwner;
	TgxRagdolBone* FRootBone;
	bool FEnabled;
	bool FBuilt;
	
public:
	__fastcall TgxRagdoll(Gxs::Vectorfileobjects::TgxBaseMesh* AOwner);
	__fastcall virtual ~TgxRagdoll();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	void __fastcall SetRootBone(TgxRagdolBone* RootBone);
	void __fastcall BuildRagdoll();
	void __fastcall Start();
	void __fastcall Update();
	void __fastcall Stop();
	__property Gxs::Vectorfileobjects::TgxBaseMesh* Owner = {read=FOwner};
	__property TgxRagdolBone* RootBone = {read=FRootBone};
	__property bool Enabled = {read=FEnabled, nodefault};
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxRagdoll(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ragdoll */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_RAGDOLL)
using namespace Gxs::Ragdoll;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_RagdollHPP
