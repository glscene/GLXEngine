// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.FileOBJ.pas' rev: 36.00 (Windows)

#ifndef GXS_FileOBJHPP
#define GXS_FileOBJHPP

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
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Context.hpp>
#include <GXS.MeshUtils.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Fileobj
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxOBJVectorFile;
class DELPHICLASS EGLOBJFileError;
class DELPHICLASS TgxMTLFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxOBJVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
private:
	System::Classes::TStream* FSourceStream;
	System::AnsiString FBuffer;
	System::UnicodeString FLine;
	int FLineNo;
	bool FEof;
	int FBufPos;
	
protected:
	void __fastcall ReadLine();
	void __fastcall Error(const System::UnicodeString msg);
	void __fastcall CalcMissingOBJNormals(Gxs::Vectorfileobjects::TgxMeshObject* mesh);
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual TgxOBJVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~TgxOBJVectorFile() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLOBJFileError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
private:
	int FLineNo;
	
public:
	__property int LineNo = {read=FLineNo, nodefault};
public:
	/* Exception.Create */ inline __fastcall EGLOBJFileError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLOBJFileError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLOBJFileError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLOBJFileError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLOBJFileError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLOBJFileError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLOBJFileError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLOBJFileError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLOBJFileError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLOBJFileError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLOBJFileError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLOBJFileError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLOBJFileError() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxMTLFile : public System::Classes::TStringList
{
	typedef System::Classes::TStringList inherited;
	
public:
	void __fastcall Prepare();
	System::UnicodeString __fastcall MaterialStringProperty(const System::UnicodeString materialName, const System::UnicodeString propertyName);
	Stage::Vectortypes::TVector4f __fastcall MaterialVectorProperty(const System::UnicodeString materialName, const System::UnicodeString propertyName, const Stage::Vectortypes::TVector4f &defaultValue);
public:
	/* TStringList.Create */ inline __fastcall TgxMTLFile()/* overload */ : System::Classes::TStringList() { }
	/* TStringList.Create */ inline __fastcall TgxMTLFile(bool OwnsObjects)/* overload */ : System::Classes::TStringList(OwnsObjects) { }
	/* TStringList.Create */ inline __fastcall TgxMTLFile(System::WideChar QuoteChar, System::WideChar Delimiter)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter) { }
	/* TStringList.Create */ inline __fastcall TgxMTLFile(System::WideChar QuoteChar, System::WideChar Delimiter, System::Classes::TStringsOptions Options)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter, Options) { }
	/* TStringList.Create */ inline __fastcall TgxMTLFile(System::Classes::TDuplicates Duplicates, bool Sorted, bool CaseSensitive)/* overload */ : System::Classes::TStringList(Duplicates, Sorted, CaseSensitive) { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TgxMTLFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word BufSize = System::Word(0x2800);
static _DELPHI_CONST System::Int8 LineLen = System::Int8(0x64);
extern DELPHI_PACKAGE bool vFileOBJ_SplitMesh;
}	/* namespace Fileobj */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILEOBJ)
using namespace Gxs::Fileobj;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FileOBJHPP
