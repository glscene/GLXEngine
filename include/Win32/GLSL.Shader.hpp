// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLSL.Shader.pas' rev: 36.00 (Windows)

#ifndef GLSL_ShaderHPP
#define GLSL_ShaderHPP

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
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Context.hpp>
#include <GLSL.CustomShader.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLSL.ShaderParameter.hpp>
#include <GLS.Material.hpp>
#include <GLS.State.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Glsl
{
namespace Shader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLSLShaderException;
struct TGLActiveAttrib;
class DELPHICLASS TGLCustomGLSLShader;
class DELPHICLASS TGLSLShaderParameter;
class DELPHICLASS TGLSLShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLSLShaderException : public Glsl::Customshader::EGLCustomShaderException
{
	typedef Glsl::Customshader::EGLCustomShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLSLShaderException(const System::UnicodeString Msg) : Glsl::Customshader::EGLCustomShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLSLShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Glsl::Customshader::EGLCustomShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLSLShaderException(System::NativeUInt Ident)/* overload */ : Glsl::Customshader::EGLCustomShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLSLShaderException(System::PResStringRec ResStringRec)/* overload */ : Glsl::Customshader::EGLCustomShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLSLShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Glsl::Customshader::EGLCustomShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLSLShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Glsl::Customshader::EGLCustomShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLSLShaderException(const System::UnicodeString Msg, int AHelpContext) : Glsl::Customshader::EGLCustomShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLSLShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Glsl::Customshader::EGLCustomShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLSLShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Glsl::Customshader::EGLCustomShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLSLShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Glsl::Customshader::EGLCustomShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLSLShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Glsl::Customshader::EGLCustomShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLSLShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Glsl::Customshader::EGLCustomShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLSLShaderException() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TGLSLShaderEvent)(TGLCustomGLSLShader* Shader);

typedef void __fastcall (__closure *TGLSLShaderUnApplyEvent)(TGLCustomGLSLShader* Shader, bool &ThereAreMorePasses);

typedef void __fastcall (__closure *TGLSLShaderEventEx)(TGLCustomGLSLShader* Shader, System::TObject* Sender);

struct DECLSPEC_DRECORD TGLActiveAttrib
{
public:
	System::UnicodeString Name;
	int Size;
	Glsl::Shaderparameter::TGLSLDataType AType;
	int Location;
};


typedef System::DynamicArray<TGLActiveAttrib> TGLActiveAttribArray;

class PASCALIMPLEMENTATION TGLCustomGLSLShader : public Glsl::Customshader::TGLCustomShader
{
	typedef Glsl::Customshader::TGLCustomShader inherited;
	
private:
	Gls::Context::TGLProgramHandle* FGLSLProg;
	TGLSLShaderParameter* FParam;
	System::Classes::TStrings* FActiveVarying;
	Glsl::Customshader::TGLTransformFeedBackMode FTransformFeedBackMode;
	TGLSLShaderEvent FOnInitialize;
	TGLSLShaderEvent FOnApply;
	TGLSLShaderUnApplyEvent FOnUnApply;
	TGLSLShaderEventEx FOnInitializeEx;
	TGLSLShaderEventEx FOnApplyEx;
	int FNextTexIndex;
	TGLSLShaderParameter* __fastcall GetParam(const System::UnicodeString Index);
	TGLSLShaderParameter* __fastcall GetDirectParam(const unsigned Index);
	void __fastcall OnChangeActiveVarying(System::TObject* Sender);
	
protected:
	__property TGLSLShaderEvent OnApply = {read=FOnApply, write=FOnApply};
	__property TGLSLShaderUnApplyEvent OnUnApply = {read=FOnUnApply, write=FOnUnApply};
	__property TGLSLShaderEvent OnInitialize = {read=FOnInitialize, write=FOnInitialize};
	__property TGLSLShaderEventEx OnInitializeEx = {read=FOnInitializeEx, write=FOnInitializeEx};
	__property TGLSLShaderEventEx OnApplyEx = {read=FOnApplyEx, write=FOnApplyEx};
	virtual Gls::Context::TGLProgramHandle* __fastcall GetGLSLProg();
	virtual TGLSLShaderParameter* __fastcall GetCurrentParam();
	void __fastcall SetActiveVarying(System::Classes::TStrings* const Value);
	void __fastcall SetTransformFeedBackMode(const Glsl::Customshader::TGLTransformFeedBackMode Value);
	virtual void __fastcall DoInitialize(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoFinalize();
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLCustomGLSLShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLShader();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall ShaderSupported();
	TGLActiveAttribArray __fastcall GetActiveAttribs();
	void __fastcall SetTex(const System::UnicodeString TexParamName, Gls::Texture::TGLTexture* Tex)/* overload */;
	void __fastcall SetTex(const System::UnicodeString TexParamName, Gls::Material::TGLLibMaterial* Mat)/* overload */;
	void __fastcall SetTex(TGLSLShaderParameter* TexParam, Gls::Texture::TGLTexture* Tex)/* overload */;
	void __fastcall SetTex(TGLSLShaderParameter* TexParam, Gls::Material::TGLLibMaterial* Mat)/* overload */;
	__property TGLSLShaderParameter* Param[const System::UnicodeString Index] = {read=GetParam};
	__property TGLSLShaderParameter* DirectParam[const unsigned Index] = {read=GetDirectParam};
	__property System::Classes::TStrings* ActiveVarying = {read=FActiveVarying, write=SetActiveVarying};
	__property Glsl::Customshader::TGLTransformFeedBackMode TransformFeedBackMode = {read=FTransformFeedBackMode, write=SetTransformFeedBackMode, default=0};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSLShaderParameter : public Glsl::Customshader::TGLCustomShaderParameter
{
	typedef Glsl::Customshader::TGLCustomShaderParameter inherited;
	
private:
	Gls::Context::TGLProgramHandle* FGLSLProg;
	int FParameterID;
	
protected:
	virtual float __fastcall GetAsVector1f();
	virtual Stage::Vectortypes::TVector2f __fastcall GetAsVector2f();
	virtual Stage::Vectortypes::TVector3f __fastcall GetAsVector3f();
	virtual Stage::Vectortypes::TGLVector __fastcall GetAsVector4f();
	virtual int __fastcall GetAsVector1i();
	virtual Stage::Vectortypes::TVector2i __fastcall GetAsVector2i();
	virtual Stage::Vectortypes::TVector3i __fastcall GetAsVector3i();
	virtual Stage::Vectortypes::TVector4i __fastcall GetAsVector4i();
	virtual unsigned __fastcall GetAsVector1ui();
	virtual Stage::Vectortypes::TVector2ui __fastcall GetAsVector2ui();
	virtual Stage::Vectortypes::TVector3ui __fastcall GetAsVector3ui();
	virtual Stage::Vectortypes::TVector4ui __fastcall GetAsVector4ui();
	virtual void __fastcall SetAsVector1f(const float Value);
	virtual void __fastcall SetAsVector2f(const Stage::Vectortypes::TVector2f &Value);
	virtual void __fastcall SetAsVector3f(const Stage::Vectortypes::TVector3f &Value);
	virtual void __fastcall SetAsVector4f(const Stage::Vectortypes::TVector4f &Value);
	virtual void __fastcall SetAsVector1i(const int Value);
	virtual void __fastcall SetAsVector2i(const Stage::Vectortypes::TVector2i &Value);
	virtual void __fastcall SetAsVector3i(const Stage::Vectortypes::TVector3i &Value);
	virtual void __fastcall SetAsVector4i(const Stage::Vectortypes::TVector4i &Value);
	virtual void __fastcall SetAsVector1ui(const unsigned Value);
	virtual void __fastcall SetAsVector2ui(const Stage::Vectortypes::TVector2ui &Value);
	virtual void __fastcall SetAsVector3ui(const Stage::Vectortypes::TVector3ui &Value);
	virtual void __fastcall SetAsVector4ui(const Stage::Vectortypes::TVector4ui &Value);
	virtual Stage::Vectortypes::TMatrix2f __fastcall GetAsMatrix2f();
	virtual Stage::Vectortypes::TMatrix3f __fastcall GetAsMatrix3f();
	virtual Stage::Vectortypes::TMatrix4f __fastcall GetAsMatrix4f();
	virtual void __fastcall SetAsMatrix2f(const Stage::Vectortypes::TMatrix2f &Value);
	virtual void __fastcall SetAsMatrix3f(const Stage::Vectortypes::TMatrix3f &Value);
	virtual void __fastcall SetAsMatrix4f(const Stage::Vectortypes::TMatrix4f &Value);
	virtual unsigned __fastcall GetAsCustomTexture(const int TextureIndex, Stage::Textureformat::TglTextureTarget TextureTarget);
	virtual void __fastcall SetAsCustomTexture(const int TextureIndex, Stage::Textureformat::TglTextureTarget TextureTarget, const unsigned Value);
	virtual unsigned __fastcall GetAsUniformBuffer();
	virtual void __fastcall SetAsUniformBuffer(unsigned UBO);
public:
	/* TObject.Create */ inline __fastcall TGLSLShaderParameter() : Glsl::Customshader::TGLCustomShaderParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLSLShaderParameter() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLSLShader : public TGLCustomGLSLShader
{
	typedef TGLCustomGLSLShader inherited;
	
__published:
	__property FragmentProgram;
	__property VertexProgram;
	__property GeometryProgram;
	__property OnApply;
	__property OnApplyEx;
	__property OnUnApply;
	__property OnInitialize;
	__property OnInitializeEx;
	__property ShaderStyle = {default=1};
	__property FailedInitAction = {default=1};
	__property ActiveVarying;
	__property TransformFeedBackMode = {default=0};
public:
	/* TGLCustomGLSLShader.Create */ inline __fastcall virtual TGLSLShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLShader(AOwner) { }
	/* TGLCustomGLSLShader.Destroy */ inline __fastcall virtual ~TGLSLShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shader */
}	/* namespace Glsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL_SHADER)
using namespace Glsl::Shader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL)
using namespace Glsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLSL_ShaderHPP
