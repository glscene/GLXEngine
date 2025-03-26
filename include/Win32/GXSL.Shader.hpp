// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.Shader.pas' rev: 36.00 (Windows)

#ifndef GXSL_ShaderHPP
#define GXSL_ShaderHPP

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
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXSL.Parameter.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Shader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGXSLShaderException;
struct TgxActiveAttrib;
class DELPHICLASS TGXSLCustomShader;
class DELPHICLASS TGXSLShaderParameter;
class DELPHICLASS TGXSLShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EGXSLShaderException : public Gxsl::Customshader::ECustomShaderException
{
	typedef Gxsl::Customshader::ECustomShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGXSLShaderException(const System::UnicodeString Msg) : Gxsl::Customshader::ECustomShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGXSLShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxsl::Customshader::ECustomShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGXSLShaderException(System::NativeUInt Ident)/* overload */ : Gxsl::Customshader::ECustomShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGXSLShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxsl::Customshader::ECustomShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGXSLShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Customshader::ECustomShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGXSLShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Customshader::ECustomShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGXSLShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxsl::Customshader::ECustomShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGXSLShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxsl::Customshader::ECustomShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGXSLShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxsl::Customshader::ECustomShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGXSLShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxsl::Customshader::ECustomShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGXSLShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Customshader::ECustomShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGXSLShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Customshader::ECustomShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGXSLShaderException() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TGXSLShaderEvent)(TGXSLCustomShader* Shader);

typedef void __fastcall (__closure *TGXSLShaderUnApplyEvent)(TGXSLCustomShader* Shader, bool &ThereAreMorePasses);

typedef void __fastcall (__closure *TGXSLShaderEventEx)(TGXSLCustomShader* Shader, System::TObject* Sender);

struct DECLSPEC_DRECORD TgxActiveAttrib
{
public:
	System::UnicodeString Name;
	int Size;
	Gxsl::Parameter::TgxSLDataType AType;
	int Location;
};


typedef System::DynamicArray<TgxActiveAttrib> TgxActiveAttribArray;

class PASCALIMPLEMENTATION TGXSLCustomShader : public Gxsl::Customshader::TgxCustomShader
{
	typedef Gxsl::Customshader::TgxCustomShader inherited;
	
private:
	Gxs::Context::TgxProgramHandle* FGXSLProg;
	TGXSLShaderParameter* FParam;
	System::Classes::TStrings* FActiveVarying;
	Gxsl::Customshader::TgxTransformFeedBackMode FTransformFeedBackMode;
	TGXSLShaderEvent FOnInitialize;
	TGXSLShaderEvent FOnApply;
	TGXSLShaderUnApplyEvent FOnUnApply;
	TGXSLShaderEventEx FOnInitializeEx;
	TGXSLShaderEventEx FOnApplyEx;
	TGXSLShaderParameter* __fastcall GetParam(const System::UnicodeString Index);
	TGXSLShaderParameter* __fastcall GetDirectParam(const unsigned Index);
	void __fastcall OnChangeActiveVarying(System::TObject* Sender);
	
protected:
	__property TGXSLShaderEvent OnApply = {read=FOnApply, write=FOnApply};
	__property TGXSLShaderUnApplyEvent OnUnApply = {read=FOnUnApply, write=FOnUnApply};
	__property TGXSLShaderEvent OnInitialize = {read=FOnInitialize, write=FOnInitialize};
	__property TGXSLShaderEventEx OnInitializeEx = {read=FOnInitializeEx, write=FOnInitializeEx};
	__property TGXSLShaderEventEx OnApplyEx = {read=FOnApplyEx, write=FOnApplyEx};
	virtual Gxs::Context::TgxProgramHandle* __fastcall GetGXSLProg();
	virtual TGXSLShaderParameter* __fastcall GetCurrentParam();
	void __fastcall SetActiveVarying(System::Classes::TStrings* const Value);
	void __fastcall SetTransformFeedBackMode(const Gxsl::Customshader::TgxTransformFeedBackMode Value);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoFinalize();
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TGXSLCustomShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGXSLCustomShader();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall ShaderSupported();
	TgxActiveAttribArray __fastcall GetActiveAttribs();
	__property TGXSLShaderParameter* Param[const System::UnicodeString Index] = {read=GetParam};
	__property TGXSLShaderParameter* DirectParam[const unsigned Index] = {read=GetDirectParam};
	__property System::Classes::TStrings* ActiveVarying = {read=FActiveVarying, write=SetActiveVarying};
	__property Gxsl::Customshader::TgxTransformFeedBackMode TransformFeedBackMode = {read=FTransformFeedBackMode, write=SetTransformFeedBackMode, default=0};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGXSLShaderParameter : public Gxsl::Customshader::TgxCustomShaderParameter
{
	typedef Gxsl::Customshader::TgxCustomShaderParameter inherited;
	
private:
	Gxs::Context::TgxProgramHandle* FGXSLProg;
	int FParameterID;
	
protected:
	virtual float __fastcall GetAsVector1f();
	virtual Stage::Vectortypes::TVector2f __fastcall GetAsVector2f();
	virtual Stage::Vectortypes::TVector3f __fastcall GetAsVector3f();
	virtual Stage::Vectortypes::TVector4f __fastcall GetAsVector4f();
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
	/* TObject.Create */ inline __fastcall TGXSLShaderParameter() : Gxsl::Customshader::TgxCustomShaderParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGXSLShaderParameter() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGXSLShader : public TGXSLCustomShader
{
	typedef TGXSLCustomShader inherited;
	
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
	/* TGXSLCustomShader.Create */ inline __fastcall virtual TGXSLShader(System::Classes::TComponent* AOwner) : TGXSLCustomShader(AOwner) { }
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TGXSLShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_SHADER)
using namespace Gxsl::Shader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_ShaderHPP
