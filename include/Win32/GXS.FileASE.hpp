// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileASE.pas' rev: 36.00 (Windows)

#ifndef GXS_FileASEHPP
#define GXS_FileASEHPP

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
#include <GXS.VectorFileObjects.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Filease
{
//-- forward type declarations -----------------------------------------------
struct TgxASEFaceTexure;
struct TgxASEFaceTexureChannels;
struct TgxASESmoothingGroups;
class DELPHICLASS TgxASEFace;
class DELPHICLASS TgxASEFaceList;
class DELPHICLASS TgxASEMeshObject;
struct TgxASEMaterialTextureMap;
struct TgxASEMaterialTextureMaps;
struct TgxASESubMaterial;
struct TgxASESubMaterialList;
class DELPHICLASS TgxASEMaterial;
class DELPHICLASS TgxASEMaterialList;
class DELPHICLASS TgxASEVectorFile;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TgxASEFaceTexure
{
public:
	int Idx0;
	int Idx1;
	int Idx2;
};


struct DECLSPEC_DRECORD TgxASEFaceTexureChannels
{
public:
	int Count;
	System::StaticArray<TgxASEFaceTexure, 12> ChanelTexture;
};


struct DECLSPEC_DRECORD TgxASESmoothingGroups
{
public:
	int Count;
	System::StaticArray<int, 6> Groups;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxASEFace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::StaticArray<int, 3> FV;
	Stage::Vectorgeometry::TAffineVector FNormal;
	System::StaticArray<Stage::Vectortypes::TVector3f, 3> FN;
	TgxASESmoothingGroups FSmoothing;
	int FSubMaterialID;
	TgxASEFaceTexureChannels FTextChannels;
	
public:
	__fastcall TgxASEFace();
	// [SKIPPED] __property int VertIdx1 = {read=FV[0], nodefault};
	// [SKIPPED] __property int VertIdx2 = {read=FV[1], nodefault};
	// [SKIPPED] __property int VertIdx3 = {read=FV[2], nodefault};
	__property Stage::Vectorgeometry::TAffineVector Normal = {read=FNormal};
	// [SKIPPED] __property Stage::Vectorgeometry::TAffineVector Normal1 = {read=FN[0]};
	// [SKIPPED] __property Stage::Vectorgeometry::TAffineVector Normal2 = {read=FN[1]};
	// [SKIPPED] __property Stage::Vectorgeometry::TAffineVector Normal3 = {read=FN[2]};
	__property TgxASEFaceTexureChannels TextChannels = {read=FTextChannels};
	__property TgxASESmoothingGroups Smoothing = {read=FSmoothing};
	__property int SubMaterialID = {read=FSubMaterialID, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxASEFace() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxASEFaceList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TgxASEFace* operator[](int Index) { return this->Face[Index]; }
	
private:
	System::Classes::TList* FItems;
	TgxASEFace* __fastcall GetFace(int Index);
	int __fastcall GetCount();
	
public:
	__fastcall TgxASEFaceList();
	__fastcall virtual ~TgxASEFaceList();
	TgxASEFace* __fastcall Add();
	void __fastcall Delete(int aIndex);
	void __fastcall Clear();
	__property TgxASEFace* Face[int Index] = {read=GetFace/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxASEMeshObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TgxASEFaceList* FFaces;
	Gxs::Vectorlists::TgxAffineVectorList* FVertices;
	Stage::Vectortypes::TMatrix4f FMatrix;
	Stage::Vectorgeometry::TAffineVector FInheritedPosition;
	Stage::Vectorgeometry::TAffineVector FInheritedScale;
	Stage::Vectorgeometry::TAffineVector FInheritedRotation;
	float FRotationAngle;
	Stage::Vectorgeometry::TAffineVector FRotationAxis;
	Stage::Vectortypes::TVector4f FPosition;
	Stage::Vectorgeometry::TAffineVector FScale;
	float FScaleAxisAngle;
	Stage::Vectorgeometry::TAffineVector FScaleAxis;
	System::StaticArray<Gxs::Vectorlists::TgxAffineVectorList*, 12> FTexChannels;
	int FTexChannelsCount;
	bool FHasNormals;
	int FMaterialID;
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall AddTexChannel();
	Gxs::Vectorlists::TgxAffineVectorList* __fastcall GetTextChannel(int Channel);
	
public:
	__fastcall TgxASEMeshObject();
	__fastcall virtual ~TgxASEMeshObject();
	__property TgxASEFaceList* Faces = {read=FFaces};
	__property Gxs::Vectorlists::TgxAffineVectorList* Vertices = {read=FVertices};
	__property Gxs::Vectorlists::TgxAffineVectorList* TextChannel[int Channel] = {read=GetTextChannel};
	__property int TextChannelsCount = {read=FTexChannelsCount, nodefault};
	__property Stage::Vectortypes::TMatrix4f Matrix = {read=FMatrix};
	__property Stage::Vectorgeometry::TAffineVector InheritedPosition = {read=FInheritedPosition};
	__property Stage::Vectorgeometry::TAffineVector InheritedRotation = {read=FInheritedRotation};
	__property Stage::Vectorgeometry::TAffineVector InheritedScale = {read=FInheritedScale};
	__property Stage::Vectortypes::TVector4f Position = {read=FPosition};
	__property Stage::Vectorgeometry::TAffineVector RotationAxis = {read=FRotationAxis};
	__property float RotationAngle = {read=FRotationAngle};
	__property Stage::Vectorgeometry::TAffineVector Scale = {read=FScale};
	__property Stage::Vectorgeometry::TAffineVector ScaleAxis = {read=FScaleAxis};
	__property float ScaleAxisAngle = {read=FScaleAxisAngle};
	__property bool HasNormals = {read=FHasNormals, nodefault};
	__property int MaterialID = {read=FMaterialID, nodefault};
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TgxASEMaterialTextureMap
{
public:
	System::UnicodeString Kind;
	System::UnicodeString Name;
	System::UnicodeString _Class;
	int No;
	float Amount;
	System::UnicodeString Bitmap;
	float UOffset;
	float VOffset;
	float UTiling;
	float VTiling;
	float Angle;
	float Blur;
	float BlurOffset;
	float NouseAmount;
	float NoiseSize;
	int NoiseLevel;
	float NoisePhase;
};


struct DECLSPEC_DRECORD TgxASEMaterialTextureMaps
{
	
private:
	typedef System::StaticArray<TgxASEMaterialTextureMap, 12> _TgxASEMaterialTextureMaps__1;
	
	
public:
	_TgxASEMaterialTextureMaps__1 Map;
	int Count;
};


struct DECLSPEC_DRECORD TgxASESubMaterial
{
public:
	System::UnicodeString Name;
	Stage::Vectorgeometry::TAffineVector Ambient;
	Stage::Vectorgeometry::TAffineVector Diffuse;
	Stage::Vectorgeometry::TAffineVector Specular;
	float Shiness;
	float ShineStrength;
	float Transparency;
	float WireSize;
	float SelfIllumination;
	TgxASEMaterialTextureMaps TextureMaps;
};


struct DECLSPEC_DRECORD TgxASESubMaterialList
{
	
private:
	typedef System::StaticArray<TgxASESubMaterial, 5> _TgxASESubMaterialList__1;
	
	
public:
	_TgxASESubMaterialList__1 SubMaterial;
	int Count;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxASEMaterial : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	float FWireSize;
	float FShineStrength;
	float FShiness;
	float FTransparency;
	System::UnicodeString FName;
	Stage::Vectorgeometry::TAffineVector FDiffuse;
	Stage::Vectorgeometry::TAffineVector FAmbient;
	Stage::Vectorgeometry::TAffineVector FSpecular;
	TgxASESubMaterialList FSubMaterials;
	TgxASEMaterialTextureMaps FTextureMaps;
	
public:
	__fastcall TgxASEMaterial();
	__property System::UnicodeString Name = {read=FName};
	__property Stage::Vectorgeometry::TAffineVector Ambient = {read=FAmbient};
	__property Stage::Vectorgeometry::TAffineVector Diffuse = {read=FDiffuse};
	__property Stage::Vectorgeometry::TAffineVector Specular = {read=FSpecular};
	__property float Shiness = {read=FShiness};
	__property float ShineStrength = {read=FShineStrength};
	__property float Transparency = {read=FTransparency};
	__property float WireSize = {read=FWireSize};
	__property TgxASEMaterialTextureMaps TextureMaps = {read=FTextureMaps};
	__property TgxASESubMaterialList SubMaterials = {read=FSubMaterials};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgxASEMaterial() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxASEMaterialList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TgxASEMaterial* operator[](int Index) { return this->Material[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount();
	TgxASEMaterial* __fastcall GetMaterial(int Index);
	
public:
	__fastcall TgxASEMaterialList();
	__fastcall virtual ~TgxASEMaterialList();
	TgxASEMaterial* __fastcall Add();
	void __fastcall Delete(int aIndex);
	void __fastcall Clear();
	__property TgxASEMaterial* Material[int Index] = {read=GetMaterial/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxASEVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
private:
	System::Classes::TStringList* FStringData;
	System::UnicodeString FHeader;
	System::UnicodeString FComment;
	bool FRECVShadow;
	bool FCastShadow;
	bool FMotionBlur;
	TgxASEMaterialList* FMaterialList;
	bool __fastcall ContainString(const System::UnicodeString aData, const System::UnicodeString aString);
	int __fastcall GetTagOnData(const System::UnicodeString aData);
	bool __fastcall IsEndOfSection(const System::UnicodeString aData);
	Stage::Vectorgeometry::TAffineVector __fastcall GetValue3D(const System::UnicodeString aData);
	Stage::Vectorgeometry::TAffineVector __fastcall GetValue4D(const System::UnicodeString aData, int &Value0);
	System::UnicodeString __fastcall GetStringValue(const System::UnicodeString aData);
	double __fastcall GetDoubleValue(const System::UnicodeString aData);
	System::UnicodeString __fastcall GetFirstValue(System::UnicodeString aData);
	int __fastcall GetEndOfFirstValue(const System::UnicodeString aData);
	void __fastcall SkipSection(int &aLineIndex);
	bool __fastcall IsSectionBegingin(const System::UnicodeString aData);
	bool __fastcall CheckUnknownData(int &aLineIndex);
	void __fastcall ParseFaceString(const System::UnicodeString aData, int &Index, int &A, int &B, int &C, int &AB, int &BC, int &CA, int &MatID, TgxASESmoothingGroups &Smooth);
	void __fastcall ParseScene(int &aLineIndex);
	void __fastcall ParseGeomObject(int &aLineIndex);
	void __fastcall ParseMeshOptions(int &aLineIndex, TgxASEMeshObject* aMesh);
	void __fastcall ParseMeshGeom(int &aLineIndex, TgxASEMeshObject* aMesh);
	void __fastcall ParseMappingChannel(int &aLineIndex, TgxASEMeshObject* aMesh);
	void __fastcall ParseMeshVertices(int &aLineIndex, TgxASEMeshObject* aMesh, int VerticesCount);
	void __fastcall ParseMeshFaces(int &aLineIndex, TgxASEMeshObject* aMesh, int FacesCount);
	void __fastcall ParseMeshNormals(int &aLineIndex, TgxASEMeshObject* aMesh, int FacesCount);
	void __fastcall ParseMeshTextureVertices(int &aLineIndex, TgxASEMeshObject* aMesh, int TextureVerticesCount);
	void __fastcall ParseMeshTextureFaces(int &aLineIndex, TgxASEMeshObject* aMesh, int TextureFacesCount);
	void __fastcall ParseMaterialList(int &aLineIndex);
	void __fastcall ParseMaterial(int &aLineIndex, TgxASEMaterial* aMaterial);
	void __fastcall ParseSubMaterial(int &aLineIndex, TgxASEMaterial* aMaterial);
	bool __fastcall CheckTextureMap(int &aLineIndex, TgxASEMaterialTextureMaps &aMaps);
	void __fastcall ParseTextureMap(int &aLineIndex, TgxASEMaterialTextureMaps &aMaps, const System::UnicodeString aMapKind);
	bool __fastcall GetPropMBlur(const System::UnicodeString aData);
	bool __fastcall GetPropCastShadow(const System::UnicodeString aData);
	bool __fastcall GetPropRECVShadow(const System::UnicodeString aData);
	void __fastcall Parse();
	
public:
	__fastcall virtual TgxASEVectorFile(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxASEVectorFile();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	__property System::UnicodeString Header = {read=FHeader};
	__property System::UnicodeString Comment = {read=FComment};
	__property bool MotionBlur = {read=FMotionBlur, nodefault};
	__property bool CastShadow = {read=FCastShadow, nodefault};
	__property bool RECVShadow = {read=FRECVShadow, nodefault};
};


enum DECLSPEC_DENUM TASETextureMap : unsigned char { tmGeneric, tmAmbient, tmDiffuse, tmSpecular, tmShine, tmShinestrength, tmSelfillum, tmOpacity, tmFiltercolor, tmBump, tmReflect, tmRefract };

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 GL_ASE_MAX_TEXURE_CHANNELS = System::Int8(0xc);
static _DELPHI_CONST System::Int8 GL_ASE_MAX_SUBMATERIALS = System::Int8(0x5);
static _DELPHI_CONST System::Int8 GL_ASE_MAX_SMOOTH_GROUPS = System::Int8(0x5);
static _DELPHI_CONST System::Int8 GL_ASE_MAX_TEXTURE_MAPS = System::Int8(0xc);
extern DELPHI_PACKAGE void __fastcall ASESetPreferredTexture(TASETextureMap aMap, int aSubMaterialIndex = 0xffffffff);
extern DELPHI_PACKAGE void __fastcall ASESetPreferredLightmap(TASETextureMap aMap, int aSubMaterialIndex = 0xffffffff);
}	/* namespace Filease */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEASE)
using namespace Gxs::Filease;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileASEHPP
