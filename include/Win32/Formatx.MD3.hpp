// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formatx.MD3.pas' rev: 36.00 (Windows)

#ifndef Formatx_MD3HPP
#define Formatx_MD3HPP

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
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formatx
{
namespace Md3
{
//-- forward type declarations -----------------------------------------------
struct TMD3Tag;
struct TMD3Bone;
struct TMD3Triangle;
struct TMD3Face;
struct TMD3TexCoord;
struct TMD3Skin;
struct TMD3Header;
struct TMD3MeshHeader;
struct TMD3MeshData;
class DELPHICLASS TFileMD3;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TMD3Tag
{
public:
	System::StaticArray<char, 64> strName;
	Stage::Vectortypes::TVector3f vPosition;
	Stage::Vectortypes::TMatrix3f rotation;
};


struct DECLSPEC_DRECORD TMD3Bone
{
public:
	Stage::Vectortypes::TVector3f mins;
	Stage::Vectortypes::TVector3f maxs;
	Stage::Vectortypes::TVector3f position;
	float scale;
	System::StaticArray<char, 16> creator;
};


struct DECLSPEC_DRECORD TMD3Triangle
{
public:
	Stage::Vectortypes::TVector3s vertex;
	Stage::Vectortypes::TVector2b normal;
};


struct DECLSPEC_DRECORD TMD3Face
{
public:
	Stage::Vectortypes::TVector3i vertexIndices;
};


struct DECLSPEC_DRECORD TMD3TexCoord
{
public:
	Stage::Vectortypes::TVector2f textureCoord;
};


struct DECLSPEC_DRECORD TMD3Skin
{
public:
	System::StaticArray<char, 64> strName;
	int shaderIndex;
};


struct DECLSPEC_DRECORD TMD3Header
{
public:
	System::StaticArray<char, 4> fileID;
	int version;
	System::StaticArray<char, 64> strFile;
	int flags;
	int numFrames;
	int numTags;
	int numMeshes;
	int numMaxSkins;
	int headerSize;
	int tagStart;
	int tagEnd;
	int fileSize;
};


struct DECLSPEC_DRECORD TMD3MeshHeader
{
public:
	System::StaticArray<char, 4> meshID;
	System::StaticArray<char, 64> strName;
	int flags;
	int numMeshFrames;
	int numSkins;
	int numVertices;
	int numTriangles;
	int triStart;
	int headerSize;
	int uvStart;
	int vertexStart;
	int meshSize;
};


struct DECLSPEC_DRECORD TMD3MeshData
{
	
private:
	typedef System::DynamicArray<TMD3Skin> _TMD3MeshData__1;
	
	typedef System::DynamicArray<TMD3Face> _TMD3MeshData__2;
	
	typedef System::DynamicArray<TMD3TexCoord> _TMD3MeshData__3;
	
	typedef System::DynamicArray<TMD3Triangle> _TMD3MeshData__4;
	
	
public:
	TMD3MeshHeader MeshHeader;
	_TMD3MeshData__1 Skins;
	_TMD3MeshData__2 Triangles;
	_TMD3MeshData__3 TexCoords;
	_TMD3MeshData__4 Vertices;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TFileMD3 : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TMD3Bone> _TFileMD3__1;
	
	typedef System::DynamicArray<TMD3Tag> _TFileMD3__2;
	
	typedef System::DynamicArray<TMD3MeshData> _TFileMD3__3;
	
	
public:
	TMD3Header ModelHeader;
	_TFileMD3__1 Bones;
	_TFileMD3__2 Tags;
	_TFileMD3__3 MeshData;
	void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TObject.Create */ inline __fastcall TFileMD3() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TFileMD3() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Md3 */
}	/* namespace Formatx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX_MD3)
using namespace Formatx::Md3;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX)
using namespace Formatx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formatx_MD3HPP
