// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.CustomShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_CustomShaderHPP
#define GXSL_CustomShaderHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Scene.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXSL.Parameter.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Customshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS ECustomShaderException;
__interface DELPHIINTERFACE IgxShaderDescription;
typedef System::DelphiInterface<IgxShaderDescription> _di_IgxShaderDescription;
__interface DELPHIINTERFACE IgxPostShader;
typedef System::DelphiInterface<IgxPostShader> _di_IgxPostShader;
class DELPHICLASS TgxCustomShader;
class DELPHICLASS TgxShaderProgram;
class DELPHICLASS TgxVertexProgram;
class DELPHICLASS TgxFragmentProgram;
class DELPHICLASS TgxGeometryProgram;
class DELPHICLASS TgxCustomShaderParameter;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxShaderFogSupport : unsigned char { sfsEnabled, sfsDisabled, sfsAuto };

enum DECLSPEC_DENUM TgxTransformFeedBackMode : unsigned char { tfbmInterleaved, tfbmSeparate };

#pragma pack(push,4)
class PASCALIMPLEMENTATION ECustomShaderException : public Gxs::Texture::EShaderException
{
	typedef Gxs::Texture::EShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECustomShaderException(const System::UnicodeString Msg) : Gxs::Texture::EShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECustomShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxs::Texture::EShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECustomShaderException(System::NativeUInt Ident)/* overload */ : Gxs::Texture::EShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECustomShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxs::Texture::EShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECustomShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Texture::EShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECustomShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECustomShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxs::Texture::EShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECustomShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxs::Texture::EShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECustomShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECustomShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECustomShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECustomShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECustomShaderException() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TgxShaderEvent)(TgxCustomShader* Shader);

typedef void __fastcall (__closure *TgxShaderUnAplyEvent)(TgxCustomShader* Shader, bool &ThereAreMorePasses);

typedef System::Int8 TgxLightSourceEnum;

typedef System::Set<TgxLightSourceEnum, 1, 8> TgxLightSourceSet;

__interface  INTERFACE_UUID("{04089C64-60C2-43F5-AC9C-38ED46264812}") IgxShaderDescription  : public System::IInterface 
{
	virtual void __fastcall SetShaderTextures(Gxs::Texture::TgxTexture* const *Textures, const System::NativeInt Textures_High) = 0 ;
	virtual void __fastcall GetShaderTextures(Gxs::Texture::TgxTexture* *Textures, const System::NativeInt Textures_High) = 0 ;
	virtual void __fastcall SetShaderColorParams(const Stage::Vectortypes::TVector4f &AAmbientColor, const Stage::Vectortypes::TVector4f &ADiffuseColor, const Stage::Vectortypes::TVector4f &ASpecularcolor) = 0 ;
	virtual void __fastcall GetShaderColorParams(Stage::Vectortypes::TVector4f &AAmbientColor, Stage::Vectortypes::TVector4f &ADiffuseColor, Stage::Vectortypes::TVector4f &ASpecularcolor) = 0 ;
	virtual void __fastcall SetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* const ACadencer, Gxs::Material::TgxMaterialLibrary* const AMatLib, const TgxLightSourceSet ALightSources) = 0 ;
	virtual void __fastcall GetShaderMiscParameters(Gxs::Cadencer::TgxCadencer* &ACadencer, Gxs::Material::TgxMaterialLibrary* &AMatLib, TgxLightSourceSet &ALightSources) = 0 ;
	virtual float __fastcall GetShaderAlpha() = 0 ;
	virtual void __fastcall SetShaderAlpha(const float Value) = 0 ;
	virtual System::UnicodeString __fastcall GetShaderDescription() = 0 ;
};

__interface  INTERFACE_UUID("{68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}") IgxPostShader  : public System::IInterface 
{
	virtual void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget) = 0 ;
	virtual Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget() = 0 ;
};

class PASCALIMPLEMENTATION TgxCustomShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	TgxFragmentProgram* FFragmentProgram;
	TgxVertexProgram* FVertexProgram;
	TgxGeometryProgram* FGeometryProgram;
	System::TObject* FTagObject;
	void __fastcall SetFragmentProgram(TgxFragmentProgram* const Value);
	void __fastcall SetGeometryProgram(TgxGeometryProgram* const Value);
	void __fastcall SetVertexProgram(TgxVertexProgram* const Value);
	bool __fastcall StoreFragmentProgram();
	bool __fastcall StoreGeometryProgram();
	bool __fastcall StoreVertexProgram();
	
protected:
	bool FDebugMode;
	virtual void __fastcall SetDebugMode(const bool Value);
	__property TgxFragmentProgram* FragmentProgram = {read=FFragmentProgram, write=SetFragmentProgram, stored=StoreFragmentProgram};
	__property TgxVertexProgram* VertexProgram = {read=FVertexProgram, write=SetVertexProgram, stored=StoreVertexProgram};
	__property TgxGeometryProgram* GeometryProgram = {read=FGeometryProgram, write=SetGeometryProgram, stored=StoreGeometryProgram};
	__property bool DebugMode = {read=FDebugMode, write=SetDebugMode, default=0};
	__property System::TObject* TagObject = {read=FTagObject, write=FTagObject, default=0};
	
public:
	__fastcall virtual TgxCustomShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomShader();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall LoadShaderPrograms(const System::UnicodeString VPFilename, const System::UnicodeString FPFilename, System::UnicodeString GPFilename = System::UnicodeString());
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxShaderProgram : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TgxCustomShader* FParent;
	bool FEnabled;
	System::Classes::TStrings* FCode;
	void __fastcall SetCode(System::Classes::TStrings* const Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall OnChangeCode(System::TObject* Sender);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	virtual void __fastcall Apply();
	__fastcall virtual TgxShaderProgram(TgxCustomShader* const AParent);
	__fastcall virtual ~TgxShaderProgram();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TStrings* Code = {read=FCode, write=SetCode};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=0};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxVertexProgram : public TgxShaderProgram
{
	typedef TgxShaderProgram inherited;
	
__published:
	__property Code;
	__property Enabled = {default=0};
public:
	/* TgxShaderProgram.Create */ inline __fastcall virtual TgxVertexProgram(TgxCustomShader* const AParent) : TgxShaderProgram(AParent) { }
	/* TgxShaderProgram.Destroy */ inline __fastcall virtual ~TgxVertexProgram() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxFragmentProgram : public TgxShaderProgram
{
	typedef TgxShaderProgram inherited;
	
__published:
	__property Code;
	__property Enabled = {default=0};
public:
	/* TgxShaderProgram.Create */ inline __fastcall virtual TgxFragmentProgram(TgxCustomShader* const AParent) : TgxShaderProgram(AParent) { }
	/* TgxShaderProgram.Destroy */ inline __fastcall virtual ~TgxFragmentProgram() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxGeometryProgram : public TgxShaderProgram
{
	typedef TgxShaderProgram inherited;
	
private:
	Gxsl::Parameter::TgxgsInTypes FInputPrimitiveType;
	Gxsl::Parameter::TgxgsOutTypes FOutputPrimitiveType;
	int FVerticesOut;
	void __fastcall SetInputPrimitiveType(const Gxsl::Parameter::TgxgsInTypes Value);
	void __fastcall SetOutputPrimitiveType(const Gxsl::Parameter::TgxgsOutTypes Value);
	void __fastcall SetVerticesOut(const int Value);
	
public:
	__fastcall virtual TgxGeometryProgram(TgxCustomShader* const AParent);
	
__published:
	__property Code;
	__property Enabled = {default=0};
	__property Gxsl::Parameter::TgxgsInTypes InputPrimitiveType = {read=FInputPrimitiveType, write=SetInputPrimitiveType, default=0};
	__property Gxsl::Parameter::TgxgsOutTypes OutputPrimitiveType = {read=FOutputPrimitiveType, write=SetOutputPrimitiveType, default=0};
	__property int VerticesOut = {read=FVerticesOut, write=SetVerticesOut, default=0};
public:
	/* TgxShaderProgram.Destroy */ inline __fastcall virtual ~TgxGeometryProgram() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxCustomShaderParameter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual float __fastcall GetAsVector1f() = 0 ;
	virtual Stage::Vectortypes::TVector2f __fastcall GetAsVector2f() = 0 ;
	virtual Stage::Vectortypes::TVector3f __fastcall GetAsVector3f() = 0 ;
	virtual Stage::Vectortypes::TVector4f __fastcall GetAsVector4f() = 0 ;
	virtual int __fastcall GetAsVector1i() = 0 ;
	virtual Stage::Vectortypes::TVector2i __fastcall GetAsVector2i() = 0 ;
	virtual Stage::Vectortypes::TVector3i __fastcall GetAsVector3i() = 0 ;
	virtual Stage::Vectortypes::TVector4i __fastcall GetAsVector4i() = 0 ;
	virtual unsigned __fastcall GetAsVector1ui() = 0 ;
	virtual Stage::Vectortypes::TVector2ui __fastcall GetAsVector2ui() = 0 ;
	virtual Stage::Vectortypes::TVector3ui __fastcall GetAsVector3ui() = 0 ;
	virtual Stage::Vectortypes::TVector4ui __fastcall GetAsVector4ui() = 0 ;
	virtual void __fastcall SetAsVector1f(const float Value) = 0 ;
	virtual void __fastcall SetAsVector2f(const Stage::Vectortypes::TVector2f &Value) = 0 ;
	virtual void __fastcall SetAsVector3f(const Stage::Vectortypes::TVector3f &Value) = 0 ;
	virtual void __fastcall SetAsVector4f(const Stage::Vectortypes::TVector4f &Value) = 0 ;
	virtual void __fastcall SetAsVector1i(const int Value) = 0 ;
	virtual void __fastcall SetAsVector2i(const Stage::Vectortypes::TVector2i &Value) = 0 ;
	virtual void __fastcall SetAsVector3i(const Stage::Vectortypes::TVector3i &Value) = 0 ;
	virtual void __fastcall SetAsVector4i(const Stage::Vectortypes::TVector4i &Value) = 0 ;
	virtual void __fastcall SetAsVector1ui(const unsigned Value) = 0 ;
	virtual void __fastcall SetAsVector2ui(const Stage::Vectortypes::TVector2ui &Value) = 0 ;
	virtual void __fastcall SetAsVector3ui(const Stage::Vectortypes::TVector3ui &Value) = 0 ;
	virtual void __fastcall SetAsVector4ui(const Stage::Vectortypes::TVector4ui &Value) = 0 ;
	virtual Stage::Vectortypes::TMatrix2f __fastcall GetAsMatrix2f() = 0 ;
	virtual Stage::Vectortypes::TMatrix3f __fastcall GetAsMatrix3f() = 0 ;
	virtual Stage::Vectortypes::TMatrix4f __fastcall GetAsMatrix4f() = 0 ;
	virtual void __fastcall SetAsMatrix2f(const Stage::Vectortypes::TMatrix2f &Value) = 0 ;
	virtual void __fastcall SetAsMatrix3f(const Stage::Vectortypes::TMatrix3f &Value) = 0 ;
	virtual void __fastcall SetAsMatrix4f(const Stage::Vectortypes::TMatrix4f &Value) = 0 ;
	void __fastcall SetAsTexture(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetAsTexture1D(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetAsTexture2D(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetAsTexture3D(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetAsTextureCube(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetAsTextureRect(const int TextureIndex, Gxs::Texture::TgxTexture* const Value);
	virtual unsigned __fastcall GetAsCustomTexture(const int TextureIndex, Stage::Textureformat::TglTextureTarget TextureTarget) = 0 ;
	virtual void __fastcall SetAsCustomTexture(const int TextureIndex, Stage::Textureformat::TglTextureTarget TextureTarget, const unsigned Value) = 0 ;
	virtual unsigned __fastcall GetAsUniformBuffer() = 0 ;
	virtual void __fastcall SetAsUniformBuffer(unsigned UBO) = 0 ;
	
public:
	void __fastcall SetAsVectorF(const float *Values, const System::NativeInt Values_High)/* overload */;
	void __fastcall SetAsVectorI(const int *Values, const System::NativeInt Values_High)/* overload */;
	void __fastcall SetToTextureOf(Gxs::Material::TgxLibMaterial* const LibMaterial, const int TextureIndex)/* overload */;
	void __fastcall SetToTextureOf(Gxs::Texture::TgxTexture* const Texture, const int TextureIndex)/* overload */;
	__property Stage::Vectortypes::TVector4f AsVector = {read=GetAsVector4f, write=SetAsVector4f};
	__property Stage::Vectorgeometry::TAffineVector AsAffineVector = {read=GetAsVector3f, write=SetAsVector3f};
	__property float AsFloat = {read=GetAsVector1f, write=SetAsVector1f};
	__property int AsInteger = {read=GetAsVector1i, write=SetAsVector1i, nodefault};
	__property float AsVector1f = {read=GetAsVector1f, write=SetAsVector1f};
	__property Stage::Vectortypes::TVector2f AsVector2f = {read=GetAsVector2f, write=SetAsVector2f};
	__property Stage::Vectortypes::TVector3f AsVector3f = {read=GetAsVector3f, write=SetAsVector3f};
	__property Stage::Vectortypes::TVector4f AsVector4f = {read=GetAsVector4f, write=SetAsVector4f};
	__property int AsVector1i = {read=GetAsVector1i, write=SetAsVector1i, nodefault};
	__property Stage::Vectortypes::TVector2i AsVector2i = {read=GetAsVector2i, write=SetAsVector2i};
	__property Stage::Vectortypes::TVector3i AsVector3i = {read=GetAsVector3i, write=SetAsVector3i};
	__property Stage::Vectortypes::TVector4i AsVector4i = {read=GetAsVector4i, write=SetAsVector4i};
	__property unsigned AsVector1ui = {read=GetAsVector1ui, write=SetAsVector1ui, nodefault};
	__property Stage::Vectortypes::TVector2ui AsVector2ui = {read=GetAsVector2ui, write=SetAsVector2ui};
	__property Stage::Vectortypes::TVector3ui AsVector3ui = {read=GetAsVector3ui, write=SetAsVector3ui};
	__property Stage::Vectortypes::TVector4ui AsVector4ui = {read=GetAsVector4ui, write=SetAsVector4ui};
	__property Stage::Vectortypes::TMatrix2f AsMatrix2f = {read=GetAsMatrix2f, write=SetAsMatrix2f};
	__property Stage::Vectortypes::TMatrix3f AsMatrix3f = {read=GetAsMatrix3f, write=SetAsMatrix3f};
	__property Stage::Vectortypes::TMatrix4f AsMatrix4f = {read=GetAsMatrix4f, write=SetAsMatrix4f};
	__property Gxs::Texture::TgxTexture* AsTexture[const int TextureIndex] = {write=SetAsTexture};
	__property Gxs::Texture::TgxTexture* AsTexture1D[const int TextureIndex] = {write=SetAsTexture1D};
	__property Gxs::Texture::TgxTexture* AsTexture2D[const int TextureIndex] = {write=SetAsTexture2D};
	__property Gxs::Texture::TgxTexture* AsTexture3D[const int TextureIndex] = {write=SetAsTexture3D};
	__property Gxs::Texture::TgxTexture* AsTextureRect[const int TextureIndex] = {write=SetAsTextureRect};
	__property Gxs::Texture::TgxTexture* AsTextureCube[const int TextureIndex] = {write=SetAsTextureCube};
	__property unsigned AsCustomTexture[const int TextureIndex][Stage::Textureformat::TglTextureTarget TextureTarget] = {read=GetAsCustomTexture, write=SetAsCustomTexture};
	__property unsigned AsUniformBuffer = {read=GetAsUniformBuffer, write=SetAsUniformBuffer, nodefault};
public:
	/* TObject.Create */ inline __fastcall TgxCustomShaderParameter() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxCustomShaderParameter() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TgxBlendingModeEx : unsigned char { bmxOpaque, bmxTransparency, bmxAdditive, bmxAlphaTest50, bmxAlphaTest100, bmxModulate, bmxDestColorOne, bmxDestAlphaOne };

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 gxsShaderMaxLightSources = System::Int8(0x8);
extern DELPHI_PACKAGE void __fastcall GetActiveLightsList(Gxs::Vectorlists::TgxIntegerList* const ALightIDs);
extern DELPHI_PACKAGE bool __fastcall IsFogEnabled(const TgxShaderFogSupport AFogSupportMode, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
extern DELPHI_PACKAGE void __fastcall CopyScreentoTexture(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize, const System::Word TextureTarget = (System::Word)(0xde1));
extern DELPHI_PACKAGE void __fastcall CopyScreentoTexture2(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize, const System::Word TextureTarget = (System::Word)(0xde1));
extern DELPHI_PACKAGE void __fastcall ApplyBlendingModeEx(const TgxBlendingModeEx BlendingMode);
extern DELPHI_PACKAGE void __fastcall UnApplyBlendingModeEx(void);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad(void);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad2(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad4(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad5(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad6(const Gxs::Rendercontextinfo::TGXSize &ViewPortSize);
extern DELPHI_PACKAGE void __fastcall DrawTexturedScreenQuad3(void);
extern DELPHI_PACKAGE void __fastcall InitTexture(const unsigned TextureHandle, const Gxs::Rendercontextinfo::TGXSize &TextureSize, const Stage::Textureformat::TglTextureTarget TextureTarget = (Stage::Textureformat::TglTextureTarget)(0x2));
}	/* namespace Customshader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_CUSTOMSHADER)
using namespace Gxsl::Customshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_CustomShaderHPP
