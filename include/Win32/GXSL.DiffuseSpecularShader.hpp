// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.DiffuseSpecularShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_DiffuseSpecularShaderHPP
#define GXSL_DiffuseSpecularShaderHPP

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
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Color.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXSL.Shader.hpp>
#include <GXS.Texture.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Diffusespecularshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EgxslDiffuseSpecularShaderException;
class DELPHICLASS TgxBaseCustomGLSLDiffuseSpecular;
class DELPHICLASS TgxBaseGLSLDiffuseSpecularShaderMT;
class DELPHICLASS TgxCustomGLSLDiffuseSpecularShader;
class DELPHICLASS TgxCustomGLSLDiffuseSpecularShaderMT;
struct TLightRecord;
class DELPHICLASS TgxCustomGLSLMLDiffuseSpecularShader;
class DELPHICLASS TgxCustomGLSLMLDiffuseSpecularShaderMT;
class DELPHICLASS TgxSLDiffuseSpecularShaderMT;
class DELPHICLASS TgxSLDiffuseSpecularShader;
class DELPHICLASS TgxSLMLDiffuseSpecularShaderMT;
class DELPHICLASS TgxSLMLDiffuseSpecularShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EgxslDiffuseSpecularShaderException : public Gxsl::Shader::EGXSLShaderException
{
	typedef Gxsl::Shader::EGXSLShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EgxslDiffuseSpecularShaderException(const System::UnicodeString Msg) : Gxsl::Shader::EGXSLShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EgxslDiffuseSpecularShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxsl::Shader::EGXSLShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EgxslDiffuseSpecularShaderException(System::NativeUInt Ident)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EgxslDiffuseSpecularShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxslDiffuseSpecularShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EgxslDiffuseSpecularShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxsl::Shader::EGXSLShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxsl::Shader::EGXSLShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EgxslDiffuseSpecularShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxsl::Shader::EGXSLShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EgxslDiffuseSpecularShaderException() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxBaseCustomGLSLDiffuseSpecular : public Gxsl::Shader::TGXSLCustomShader
{
	typedef Gxsl::Shader::TGXSLCustomShader inherited;
	
private:
	float FLightPower;
	bool FRealisticSpecular;
	Gxsl::Customshader::TgxShaderFogSupport FFogSupport;
	void __fastcall SetRealisticSpecular(const bool Value);
	void __fastcall SetFogSupport(const Gxsl::Customshader::TgxShaderFogSupport Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxBaseCustomGLSLDiffuseSpecular(System::Classes::TComponent* AOwner);
	__property float LightPower = {read=FLightPower, write=FLightPower};
	__property bool RealisticSpecular = {read=FRealisticSpecular, write=SetRealisticSpecular, nodefault};
	__property Gxsl::Customshader::TgxShaderFogSupport FogSupport = {read=FFogSupport, write=SetFogSupport, default=2};
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxBaseCustomGLSLDiffuseSpecular() { }
	
};


class PASCALIMPLEMENTATION TgxBaseGLSLDiffuseSpecularShaderMT : public TgxBaseCustomGLSLDiffuseSpecular
{
	typedef TgxBaseCustomGLSLDiffuseSpecular inherited;
	
private:
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Texture::TgxTexture* FMainTexture;
	Gxs::Material::TgxLibMaterialName FMainTextureName;
	Gxs::Material::TgxLibMaterialName __fastcall GetMainTextureName();
	void __fastcall SetMainTextureName(const Gxs::Material::TgxLibMaterialName Value);
	Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
protected:
	virtual void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__property Gxs::Texture::TgxTexture* MainTexture = {read=FMainTexture, write=FMainTexture};
	__property Gxs::Material::TgxLibMaterialName MainTextureName = {read=GetMainTextureName, write=SetMainTextureName};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
public:
	/* TgxBaseCustomGLSLDiffuseSpecular.Create */ inline __fastcall virtual TgxBaseGLSLDiffuseSpecularShaderMT(System::Classes::TComponent* AOwner) : TgxBaseCustomGLSLDiffuseSpecular(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxBaseGLSLDiffuseSpecularShaderMT() { }
	
private:
	void *__IgxMaterialLibrarySupported;	// Gxs::Material::IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gxs::Material::_di_IgxMaterialLibrarySupported()
	{
		Gxs::Material::_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Material::IgxMaterialLibrarySupported*(void) { return (Gxs::Material::IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLDiffuseSpecularShader : public TgxBaseCustomGLSLDiffuseSpecular
{
	typedef TgxBaseCustomGLSLDiffuseSpecular inherited;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
public:
	/* TgxBaseCustomGLSLDiffuseSpecular.Create */ inline __fastcall virtual TgxCustomGLSLDiffuseSpecularShader(System::Classes::TComponent* AOwner) : TgxBaseCustomGLSLDiffuseSpecular(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxCustomGLSLDiffuseSpecularShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLDiffuseSpecularShaderMT : public TgxBaseGLSLDiffuseSpecularShaderMT
{
	typedef TgxBaseGLSLDiffuseSpecularShaderMT inherited;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
public:
	/* TgxBaseCustomGLSLDiffuseSpecular.Create */ inline __fastcall virtual TgxCustomGLSLDiffuseSpecularShaderMT(System::Classes::TComponent* AOwner) : TgxBaseGLSLDiffuseSpecularShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxCustomGLSLDiffuseSpecularShaderMT() { }
	
};


struct DECLSPEC_DRECORD TLightRecord
{
public:
	bool Enabled;
	Gxs::Scene::TgxLightStyle Style;
};


class PASCALIMPLEMENTATION TgxCustomGLSLMLDiffuseSpecularShader : public TgxBaseCustomGLSLDiffuseSpecular
{
	typedef TgxBaseCustomGLSLDiffuseSpecular inherited;
	
private:
	System::StaticArray<TLightRecord, 8> FLightTrace;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxCustomGLSLMLDiffuseSpecularShader(System::Classes::TComponent* AOwner);
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxCustomGLSLMLDiffuseSpecularShader() { }
	
};


class PASCALIMPLEMENTATION TgxCustomGLSLMLDiffuseSpecularShaderMT : public TgxBaseGLSLDiffuseSpecularShaderMT
{
	typedef TgxBaseGLSLDiffuseSpecularShaderMT inherited;
	
private:
	System::StaticArray<TLightRecord, 8> FLightTrace;
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxCustomGLSLMLDiffuseSpecularShaderMT(System::Classes::TComponent* AOwner);
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxCustomGLSLMLDiffuseSpecularShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxSLDiffuseSpecularShaderMT : public TgxCustomGLSLDiffuseSpecularShaderMT
{
	typedef TgxCustomGLSLDiffuseSpecularShaderMT inherited;
	
__published:
	__property MainTextureName = {default=0};
	__property LightPower = {default=0};
	__property FogSupport = {default=2};
public:
	/* TgxBaseCustomGLSLDiffuseSpecular.Create */ inline __fastcall virtual TgxSLDiffuseSpecularShaderMT(System::Classes::TComponent* AOwner) : TgxCustomGLSLDiffuseSpecularShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxSLDiffuseSpecularShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxSLDiffuseSpecularShader : public TgxCustomGLSLDiffuseSpecularShader
{
	typedef TgxCustomGLSLDiffuseSpecularShader inherited;
	
__published:
	__property LightPower = {default=0};
	__property FogSupport = {default=2};
public:
	/* TgxBaseCustomGLSLDiffuseSpecular.Create */ inline __fastcall virtual TgxSLDiffuseSpecularShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLDiffuseSpecularShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxSLDiffuseSpecularShader() { }
	
};


class PASCALIMPLEMENTATION TgxSLMLDiffuseSpecularShaderMT : public TgxCustomGLSLMLDiffuseSpecularShaderMT
{
	typedef TgxCustomGLSLMLDiffuseSpecularShaderMT inherited;
	
__published:
	__property MainTextureName = {default=0};
	__property LightPower = {default=0};
	__property FogSupport = {default=2};
public:
	/* TgxCustomGLSLMLDiffuseSpecularShaderMT.Create */ inline __fastcall virtual TgxSLMLDiffuseSpecularShaderMT(System::Classes::TComponent* AOwner) : TgxCustomGLSLMLDiffuseSpecularShaderMT(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxSLMLDiffuseSpecularShaderMT() { }
	
};


class PASCALIMPLEMENTATION TgxSLMLDiffuseSpecularShader : public TgxCustomGLSLMLDiffuseSpecularShader
{
	typedef TgxCustomGLSLMLDiffuseSpecularShader inherited;
	
__published:
	__property LightPower = {default=0};
	__property FogSupport = {default=2};
public:
	/* TgxCustomGLSLMLDiffuseSpecularShader.Create */ inline __fastcall virtual TgxSLMLDiffuseSpecularShader(System::Classes::TComponent* AOwner) : TgxCustomGLSLMLDiffuseSpecularShader(AOwner) { }
	
public:
	/* TGXSLCustomShader.Destroy */ inline __fastcall virtual ~TgxSLMLDiffuseSpecularShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Diffusespecularshader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_DIFFUSESPECULARSHADER)
using namespace Gxsl::Diffusespecularshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_DiffuseSpecularShaderHPP
