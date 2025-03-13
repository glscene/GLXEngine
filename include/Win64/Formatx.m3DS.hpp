// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formatx.m3DS.pas' rev: 36.00 (Windows)

#ifndef Formatx_m3DSHPP
#define Formatx_m3DSHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Formatx.m3DSTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formatx
{
namespace M3ds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TMaterialList;
class DELPHICLASS TObjectList;
class DELPHICLASS TKeyFramer;
class DELPHICLASS TFile3DS;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TLoadProgress)(System::LongInt StreamPos, System::LongInt StreamMax);

class PASCALIMPLEMENTATION TMaterialList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Formatx::M3dstypes::PMaterial3DS operator[](int Index) { return this->Material[Index]; }
	
private:
	TFile3DS* FOwner;
	System::Classes::TList* FLocalList;
	int __fastcall GetCount();
	Formatx::M3dstypes::PMaterial3DS __fastcall GetMaterial(int Index);
	Formatx::M3dstypes::PMaterial3DS __fastcall GetMaterialByName(const System::UnicodeString Name);
	
public:
	__fastcall virtual TMaterialList(TFile3DS* AOwner);
	__fastcall virtual ~TMaterialList();
	void __fastcall ClearList();
	__property int Count = {read=GetCount, nodefault};
	__property Formatx::M3dstypes::PMaterial3DS Material[int Index] = {read=GetMaterial/*, default*/};
	__property Formatx::M3dstypes::PMaterial3DS MaterialByName[const System::UnicodeString Name] = {read=GetMaterialByName};
};


class PASCALIMPLEMENTATION TObjectList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TFile3DS* FOwner;
	System::Classes::TList* FMeshList;
	System::Classes::TList* FOmniList;
	System::Classes::TList* FSpotList;
	System::Classes::TList* FCameraList;
	Formatx::M3dstypes::PCamera3DS __fastcall GetCamera(int Index);
	int __fastcall GetCamCount();
	int __fastcall GetMeshObjectCount();
	Formatx::M3dstypes::PMesh3DS __fastcall GetMesh(int Index);
	int __fastcall GetOmniCount();
	Formatx::M3dstypes::PLight3DS __fastcall GetOmniLight(int Index);
	int __fastcall GetSpotCount();
	Formatx::M3dstypes::PLight3DS __fastcall GetSpotLight(int Index);
	
public:
	__fastcall virtual TObjectList(TFile3DS* AOwner);
	__fastcall virtual ~TObjectList();
	void __fastcall ClearLists();
	__property int CameraCount = {read=GetCamCount, nodefault};
	__property int MeshCount = {read=GetMeshObjectCount, nodefault};
	__property int OmniLightCount = {read=GetOmniCount, nodefault};
	__property int SpotLightCount = {read=GetSpotCount, nodefault};
	__property Formatx::M3dstypes::PMesh3DS Mesh[int Index] = {read=GetMesh};
	__property Formatx::M3dstypes::PCamera3DS Camera[int Index] = {read=GetCamera};
	__property Formatx::M3dstypes::PLight3DS OmniLight[int Index] = {read=GetOmniLight};
	__property Formatx::M3dstypes::PLight3DS SpotLight[int Index] = {read=GetSpotLight};
};


class PASCALIMPLEMENTATION TKeyFramer : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Formatx::M3dstypes::PKFMesh3DS operator[](int Index) { return this->MeshMotion[Index]; }
	
private:
	TFile3DS* FOwner;
	System::Classes::TList* FMeshMotionList;
	System::Classes::TList* FOmniMotionList;
	System::Classes::TList* FSpotMotionList;
	System::Classes::TList* FCameraMotionList;
	Formatx::M3dstypes::PKFAmbient3DS FAmbientMotion;
	Formatx::M3dstypes::PKFAmbient3DS __fastcall GetAmbientMotion();
	Formatx::M3dstypes::PKFCamera3DS __fastcall GetCameraMotion(int Index);
	int __fastcall GetCamMotionCount();
	Formatx::M3dstypes::TKFSets3DS __fastcall GetKFSets();
	int __fastcall GetMeshMotionCount();
	Formatx::M3dstypes::PKFMesh3DS __fastcall GetMeshMotion(int Index);
	int __fastcall GetOmniMotionCount();
	Formatx::M3dstypes::PKFOmni3DS __fastcall GetOmniLightMotion(int Index);
	int __fastcall GetSpotMotionCount();
	Formatx::M3dstypes::PKFSpot3DS __fastcall GetSpotLightMotion(int Index);
	
public:
	__fastcall virtual TKeyFramer(TFile3DS* AOwner);
	__fastcall virtual ~TKeyFramer();
	void __fastcall ClearLists();
	__property Formatx::M3dstypes::PKFAmbient3DS AmbientLightMotion = {read=GetAmbientMotion};
	__property int CameraMotionCount = {read=GetCamMotionCount, nodefault};
	__property int MeshMotionCount = {read=GetMeshMotionCount, nodefault};
	__property int OmniLightMotionCount = {read=GetOmniMotionCount, nodefault};
	__property int SpotLightMotionCount = {read=GetSpotMotionCount, nodefault};
	__property Formatx::M3dstypes::PKFMesh3DS MeshMotion[int Index] = {read=GetMeshMotion/*, default*/};
	__property Formatx::M3dstypes::PKFCamera3DS CameraMotion[int Index] = {read=GetCameraMotion};
	__property Formatx::M3dstypes::PKFOmni3DS OmniLightMotion[int Index] = {read=GetOmniLightMotion};
	__property Formatx::M3dstypes::TKFSets3DS Settings = {read=GetKFSets};
	__property Formatx::M3dstypes::PKFSpot3DS SpotLightMotion[int Index] = {read=GetSpotLightMotion};
};


class PASCALIMPLEMENTATION TFile3DS : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Formatx::M3dstypes::PNodeList FNodeList;
	Formatx::M3dstypes::TDatabase3DS FDatabase;
	System::Classes::TStream* FStream;
	bool FOwnStream;
	TMaterialList* FMaterialList;
	TObjectList* FObjectList;
	TKeyFramer* FKeyFramer;
	System::UnicodeString FFileName;
	TLoadProgress FOnLoadProgress;
	Formatx::M3dstypes::TAtmosphere3DS __fastcall GetAtmosphereData();
	Formatx::M3dstypes::TBackground3DS __fastcall GetBackgroundData();
	Formatx::M3dstypes::TDBType3DS __fastcall GetDatabaseType();
	Formatx::M3dstypes::TMeshSet3DS __fastcall GetMeshSettings();
	Formatx::M3dstypes::TViewport3DS __fastcall GetViewportData();
	Formatx::M3dstypes::TReleaseLevel __fastcall GetDatabaseRelease();
	Formatx::M3dstypes::TReleaseLevel __fastcall GetMeshRelease();
	
protected:
	void __fastcall AddToNodeList(Formatx::M3dstypes::PChunk3DS Chunk);
	void __fastcall AssignParentNames();
	void __fastcall CheckListNodeIDs();
	void __fastcall CreateDatabase();
	Formatx::M3dstypes::PNodeList __fastcall FindNodeByID(short ID);
	short __fastcall GetChunkNodeID(Formatx::M3dstypes::PChunk3DS Chunk);
	void __fastcall InitDatabase();
	bool __fastcall IsNode(System::Word Tag);
	void __fastcall KFAddParentName(Formatx::M3dstypes::PChunk3DS Chunk, const Formatx::M3dstypes::String3DS Name);
	void __fastcall MakeNode(Formatx::M3dstypes::PNodeList &Node);
	void __fastcall ParseDatabase();
	void __fastcall ReadChildren(Formatx::M3dstypes::PChunk3DS Parent);
	void __fastcall ReadXDataEntryChildren(Formatx::M3dstypes::PChunk3DS Parent);
	void __fastcall ReleaseDatabase();
	void __fastcall ReleaseNodeList();
	void __fastcall ReleaseStream();
	
public:
	__fastcall virtual TFile3DS();
	__fastcall virtual TFile3DS(const System::UnicodeString FileName);
	__fastcall virtual ~TFile3DS();
	void __fastcall ClearLists();
	void __fastcall DumpDataBase(System::Classes::TStrings* Strings, Formatx::M3dstypes::TDumpLevel DumpLevel);
	void __fastcall LoadFromFile(const System::UnicodeString FileName);
	void __fastcall LoadFromStream(System::Classes::TStream* const aStream);
	System::Byte __fastcall ReadByte();
	unsigned __fastcall ReadCardinal();
	void __fastcall ReadChunkData(Formatx::M3dstypes::PChunk3DS Chunk);
	void __fastcall ReadData(int Size, void * Data);
	double __fastcall ReadDouble();
	Formatx::M3dstypes::TFace3DS __fastcall ReadFace();
	void __fastcall ReadHeader(System::Word &ChunkType, unsigned &ChunkSize);
	int __fastcall ReadInteger();
	Formatx::M3dstypes::TKeyHeader3DS __fastcall ReadKeyHeader();
	Formatx::M3dstypes::TPoint3DS __fastcall ReadPoint();
	short __fastcall ReadShort();
	float __fastcall ReadSingle();
	Formatx::M3dstypes::PChar3DS __fastcall ReadString();
	Formatx::M3dstypes::TTexVert3DS __fastcall ReadTexVert();
	Formatx::M3dstypes::TTrackHeader3DS __fastcall ReadTrackHeader();
	System::Word __fastcall ReadWord();
	void __fastcall FinishHeader(unsigned StartPos, unsigned EndPos);
	void * __fastcall InitChunkData(Formatx::M3dstypes::PChunk3DS Chunk);
	void __fastcall SeekChild(Formatx::M3dstypes::PChunk3DS Chunk);
	void __fastcall Skip(int AValue);
	void __fastcall WriteByte(System::Byte AValue);
	void __fastcall WriteCardinal(unsigned AValue);
	void __fastcall WriteData(int Size, void * Data);
	void __fastcall WriteDouble(double AValue);
	void __fastcall WriteFace(const Formatx::M3dstypes::TFace3DS &F);
	void __fastcall WriteFixedString(const Formatx::M3dstypes::String3DS AValue, int Len);
	void __fastcall WriteHeader(System::Word ChunkType, unsigned ChunkSize);
	void __fastcall WriteInteger(int AValue);
	void __fastcall WriteKeyHeader(const Formatx::M3dstypes::TKeyHeader3DS &K);
	void __fastcall WritePoint(const Formatx::M3dstypes::TPoint3DS &P);
	void __fastcall WriteShort(short AValue);
	void __fastcall WriteSingle(float AValue);
	void __fastcall WriteString(const Formatx::M3dstypes::String3DS AValue);
	void __fastcall WriteTexVertex(const Formatx::M3dstypes::TTexVert3DS &T);
	void __fastcall WriteTrackHeader(const Formatx::M3dstypes::TTrackHeader3DS &T);
	void __fastcall WriteWord(System::Word AValue);
	__property Formatx::M3dstypes::TAtmosphere3DS Atmosphere = {read=GetAtmosphereData};
	__property Formatx::M3dstypes::TBackground3DS Background = {read=GetBackgroundData};
	__property Formatx::M3dstypes::TReleaseLevel DatabaseRelease = {read=GetDatabaseRelease, nodefault};
	__property Formatx::M3dstypes::TDBType3DS DatabaseType = {read=GetDatabaseType, nodefault};
	__property System::UnicodeString FileName = {read=FFileName};
	__property TKeyFramer* KeyFramer = {read=FKeyFramer};
	__property TMaterialList* Materials = {read=FMaterialList};
	__property Formatx::M3dstypes::TReleaseLevel MeshRelease = {read=GetMeshRelease, nodefault};
	__property Formatx::M3dstypes::TMeshSet3DS MeshSettings = {read=GetMeshSettings};
	__property TObjectList* Objects = {read=FObjectList};
	__property Formatx::M3dstypes::TViewport3DS Viewport = {read=GetViewportData};
	__property TLoadProgress OnLoadProgress = {read=FOnLoadProgress, write=FOnLoadProgress};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace M3ds */
}	/* namespace Formatx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX_M3DS)
using namespace Formatx::M3ds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX)
using namespace Formatx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formatx_m3DSHPP
