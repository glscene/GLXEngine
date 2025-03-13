// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.Parameter.pas' rev: 36.00 (Windows)

#ifndef GXSL_ParameterHPP
#define GXSL_ParameterHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Parameter
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IgxShaderParameter;
typedef System::DelphiInterface<IgxShaderParameter> _di_IgxShaderParameter;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSLDataType : unsigned char { GLSLTypeUndefined, GLSLType1F, GLSLType2F, GLSLType3F, GLSLType4F, GLSLType1I, GLSLType2I, GLSLType3I, GLSLType4I, GLSLType1UI, GLSLType2UI, GLSLType3UI, GLSLType4UI, GLSLTypeMat2F, GLSLTypeMat3F, GLSLTypeMat4F, GLSLTypeVoid };

enum DECLSPEC_DENUM TgxSLSamplerType : unsigned char { GLSLSamplerUndefined, GLSLSampler1D, GLSLSampler2D, GLSLSampler3D, GLSLSamplerCube, GLSLSampler1DShadow, GLSLSampler2DShadow, GLSLSampler1DArray, GLSLSampler2DArray, GLSLSampler1DArrayShadow, GLSLSampler2DArrayShadow, GLSLSamplerCubeShadow, GLSLIntSampler1D, GLSLIntSampler2D, GLSLIntSampler3D, GLSLIntSamplerCube, GLSLIntSampler1DArray, GLSLIntSampler2DArray, GLSLUIntSampler1D, GLSLUIntSampler2D, GLSLUIntSampler3D, GLSLUIntSamplerCube, GLSLUIntSampler1DArray, GLSLUIntSampler2DArray, GLSLSamplerRect, GLSLSamplerRectShadow, GLSLSamplerBuffer, GLSLIntSamplerRect, GLSLIntSamplerBuffer, GLSLUIntSamplerRect, GLSLUIntSamplerBuffer, GLSLSamplerMS, GLSLIntSamplerMS, GLSLUIntSamplerMS, GLSLSamplerMSArray, 
	GLSLIntSamplerMSArray, GLSLUIntSamplerMSArray };

enum DECLSPEC_DENUM TgxgsInTypes : unsigned char { gsInPoints, gsInLines, gsInAdjLines, gsInTriangles, gsInAdjTriangles };

enum DECLSPEC_DENUM TgxgsOutTypes : unsigned char { gsOutPoints, gsOutLineStrip, sOutTriangleStrip };

__interface IgxShaderParameter  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall GetName() = 0 ;
	virtual TgxSLDataType __fastcall GetGLSLType() = 0 ;
	virtual TgxSLSamplerType __fastcall GetGLSLSamplerType() = 0 ;
	virtual System::UnicodeString __fastcall GetAutoSetMethod() = 0 ;
	virtual System::UnicodeString __fastcall GetTextureName() = 0 ;
	virtual System::UnicodeString __fastcall GetSamplerName() = 0 ;
	virtual Stage::Textureformat::TglSwizzleVector __fastcall GetTextureSwizzle() = 0 ;
	virtual void __fastcall SetTextureName(const System::UnicodeString AValue) = 0 ;
	virtual void __fastcall SetSamplerName(const System::UnicodeString AValue) = 0 ;
	virtual void __fastcall SetAutoSetMethod(const System::UnicodeString AValue) = 0 ;
	virtual void __fastcall SetTextureSwizzle(const Stage::Textureformat::TglSwizzleVector AValue) = 0 ;
	virtual float __fastcall GetFloat() = 0 ;
	virtual Stage::Vectortypes::TVector2f __fastcall GetVec2() = 0 ;
	virtual Stage::Vectortypes::TVector3f __fastcall GetVec3() = 0 ;
	virtual Stage::Vectortypes::TVector4f __fastcall GetVec4() = 0 ;
	virtual int __fastcall GetInt() = 0 ;
	virtual Stage::Vectortypes::TVector2i __fastcall GetIVec2() = 0 ;
	virtual Stage::Vectortypes::TVector3i __fastcall GetIVec3() = 0 ;
	virtual Stage::Vectortypes::TVector4i __fastcall GetIVec4() = 0 ;
	virtual unsigned __fastcall GetUInt() = 0 ;
	virtual Stage::Vectortypes::TVector2ui __fastcall GetUVec2() = 0 ;
	virtual Stage::Vectortypes::TVector3ui __fastcall GetUVec3() = 0 ;
	virtual Stage::Vectortypes::TVector4ui __fastcall GetUVec4() = 0 ;
	virtual void __fastcall SetFloat(const float Value) = 0 ;
	virtual void __fastcall SetVec2(const Stage::Vectortypes::TVector2f &Value) = 0 ;
	virtual void __fastcall SetVec3(const Stage::Vectortypes::TVector3f &Value) = 0 ;
	virtual void __fastcall SetVec4(const Stage::Vectortypes::TVector4f &Value) = 0 ;
	virtual void __fastcall SetInt(const int Value) = 0 ;
	virtual void __fastcall SetIVec2(const Stage::Vectortypes::TVector2i &Value) = 0 ;
	virtual void __fastcall SetIVec3(const Stage::Vectortypes::TVector3i &Value) = 0 ;
	virtual void __fastcall SetIVec4(const Stage::Vectortypes::TVector4i &Value) = 0 ;
	virtual void __fastcall SetUInt(const unsigned Value) = 0 ;
	virtual void __fastcall SetUVec2(const Stage::Vectortypes::TVector2ui &Value) = 0 ;
	virtual void __fastcall SetUVec3(const Stage::Vectortypes::TVector3ui &Value) = 0 ;
	virtual void __fastcall SetUVec4(const Stage::Vectortypes::TVector4ui &Value) = 0 ;
	virtual Stage::Vectortypes::TMatrix2f __fastcall GetMat2() = 0 ;
	virtual Stage::Vectortypes::TMatrix3f __fastcall GetMat3() = 0 ;
	virtual Stage::Vectortypes::TMatrix4f __fastcall GetMat4() = 0 ;
	virtual void __fastcall SetMat2(const Stage::Vectortypes::TMatrix2f &Value) = 0 ;
	virtual void __fastcall SetMat3(const Stage::Vectortypes::TMatrix3f &Value) = 0 ;
	virtual void __fastcall SetMat4(const Stage::Vectortypes::TMatrix4f &Value) = 0 ;
	virtual void __fastcall SetFloatArray(const Winapi::Opengl::PGLfloat Values, int Count) = 0 ;
	virtual void __fastcall SetIntArray(const Winapi::Opengl::PGLInt Values, int Count) = 0 ;
	virtual void __fastcall SetUIntArray(const Winapi::Opengl::PGLuint Values, int Count) = 0 ;
	__property System::UnicodeString Name = {read=GetName};
	__property TgxSLDataType GLSLType = {read=GetGLSLType};
	__property TgxSLSamplerType GLSLSamplerType = {read=GetGLSLSamplerType};
	__property float Float = {read=GetFloat, write=SetFloat};
	__property int Int = {read=GetInt, write=SetInt};
	__property unsigned uint = {read=GetUInt, write=SetUInt};
	__property Stage::Vectortypes::TVector2f vec2 = {read=GetVec2, write=SetVec2};
	__property Stage::Vectortypes::TVector3f vec3 = {read=GetVec3, write=SetVec3};
	__property Stage::Vectortypes::TVector4f vec4 = {read=GetVec4, write=SetVec4};
	__property Stage::Vectortypes::TVector2i ivec2 = {read=GetIVec2, write=SetIVec2};
	__property Stage::Vectortypes::TVector3i ivec3 = {read=GetIVec3, write=SetIVec3};
	__property Stage::Vectortypes::TVector4i ivec4 = {read=GetIVec4, write=SetIVec4};
	__property Stage::Vectortypes::TVector2ui uvec2 = {read=GetUVec2, write=SetUVec2};
	__property Stage::Vectortypes::TVector3ui uvec3 = {read=GetUVec3, write=SetUVec3};
	__property Stage::Vectortypes::TVector4ui uvec4 = {read=GetUVec4, write=SetUVec4};
	__property Stage::Vectortypes::TMatrix2f mat2 = {read=GetMat2, write=SetMat2};
	__property Stage::Vectortypes::TMatrix3f mat3 = {read=GetMat3, write=SetMat3};
	__property Stage::Vectortypes::TMatrix4f mat4 = {read=GetMat4, write=SetMat4};
	__property System::UnicodeString AutoSetMethod = {read=GetAutoSetMethod, write=SetAutoSetMethod};
	__property System::UnicodeString TextureName = {read=GetTextureName, write=SetTextureName};
	__property System::UnicodeString SamplerName = {read=GetSamplerName, write=SetSamplerName};
	__property Stage::Textureformat::TglSwizzleVector TextureSwizzle = {read=GetTextureSwizzle, write=SetTextureSwizzle};
};

typedef System::StaticArray<System::AnsiString, 17> Gxsl_Parameter__1;

typedef System::StaticArray<System::AnsiString, 37> Gxsl_Parameter__2;

typedef void __fastcall (__closure *TUniformAutoSetMethod)(_di_IgxShaderParameter Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Gxsl_Parameter__1 cGLXLTypeString;
extern DELPHI_PACKAGE Gxsl_Parameter__2 cGLXLSamplerString;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 5> cGXgsInTypes;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 3> cGXgsOutTypes;
extern DELPHI_PACKAGE unsigned __fastcall GLXLTypeEnum(TgxSLDataType AType);
extern DELPHI_PACKAGE int __fastcall GLXLTypeComponentCount(TgxSLDataType AType);
extern DELPHI_PACKAGE void __fastcall RegisterUniformAutoSetMethod(System::UnicodeString AMethodName, TgxSLDataType AType, TUniformAutoSetMethod AMethod);
extern DELPHI_PACKAGE void __fastcall FillUniformAutoSetMethodList(System::Classes::TStrings* AList, TgxSLDataType TypeFilter)/* overload */;
extern DELPHI_PACKAGE void __fastcall FillUniformAutoSetMethodList(System::Classes::TStrings* AList, TgxSLSamplerType TypeFilter)/* overload */;
extern DELPHI_PACKAGE TUniformAutoSetMethod __fastcall GetUniformAutoSetMethod(System::UnicodeString AMethodName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetUniformAutoSetMethodName(TUniformAutoSetMethod AMethod);
}	/* namespace Parameter */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_PARAMETER)
using namespace Gxsl::Parameter;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_ParameterHPP
