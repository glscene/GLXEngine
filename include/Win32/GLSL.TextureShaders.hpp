// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLSL.TextureShaders.pas' rev: 36.00 (Windows)

#ifndef GLSL_TextureShadersHPP
#define GLSL_TextureShadersHPP

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
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.Texture.hpp>
#include <GLS.TextureCombiners.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.Color.hpp>
#include <GLS.Material.hpp>
#include <Stage.Strings.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <GLS.XOpenGL.hpp>
#include <GLS.State.hpp>
#include <GLS.PersistentClasses.hpp>
#include <GLS.Coordinates.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.ImageUtils.hpp>
#include <Stage.Utils.hpp>
#include <GLS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Glsl
{
namespace Textureshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLTextureSharingShaderMaterial;
class DELPHICLASS TGLTextureSharingShaderMaterials;
class DELPHICLASS TGLTextureSharingShader;
class DELPHICLASS TGLTexCombineShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTextureSharingShaderMaterial : public Gls::Persistentclasses::TGLInterfacedCollectionItem
{
	typedef Gls::Persistentclasses::TGLInterfacedCollectionItem inherited;
	
private:
	Stage::Vectortypes::TGLMatrix FTextureMatrix;
	bool FNeedToUpdateTextureMatrix;
	bool FTextureMatrixIsUnitary;
	Gls::Material::TGLLibMaterial* FLibMaterial;
	Gls::Coordinates::TGLCoordinates2* FTexOffset;
	Gls::Coordinates::TGLCoordinates2* FTexScale;
	Gls::Material::TGLBlendingMode FBlendingMode;
	Gls::Color::TGLColor* FSpecular;
	Gls::Color::TGLColor* FAmbient;
	Gls::Color::TGLColor* FDiffuse;
	Gls::Color::TGLColor* FEmission;
	Gls::Material::TGLShininess FShininess;
	Gls::Material::TGLMaterialLibrary* FMaterialLibrary;
	Gls::Material::TGLLibMaterialName FLibMaterialName;
	void __fastcall SetAmbient(Gls::Color::TGLColor* const Value);
	void __fastcall SetDiffuse(Gls::Color::TGLColor* const Value);
	void __fastcall SetEmission(Gls::Color::TGLColor* const Value);
	void __fastcall SetShininess(const Gls::Material::TGLShininess Value);
	void __fastcall SetSpecular(Gls::Color::TGLColor* const Value);
	void __fastcall SetMaterialLibrary(Gls::Material::TGLMaterialLibrary* const Value);
	void __fastcall SetLibMaterialName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetBlendingMode(const Gls::Material::TGLBlendingMode Value);
	void __fastcall SetLibMaterial(Gls::Material::TGLLibMaterial* const Value);
	void __fastcall SetTexOffset(Gls::Coordinates::TGLCoordinates2* const Value);
	void __fastcall SetTexScale(Gls::Coordinates::TGLCoordinates2* const Value);
	Stage::Vectortypes::TGLMatrix __fastcall GetTextureMatrix();
	bool __fastcall GetTextureMatrixIsUnitary();
	
protected:
	void __fastcall coordNotifychange(System::TObject* Sender);
	void __fastcall OtherNotifychange(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetDisplayName();
	TGLTextureSharingShader* __fastcall GetTextureSharingShader();
	virtual Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
public:
	void __fastcall Apply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	void __fastcall UnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__fastcall virtual TGLTextureSharingShaderMaterial(System::Classes::TCollection* Collection);
	__fastcall virtual ~TGLTextureSharingShaderMaterial();
	__property Gls::Material::TGLLibMaterial* LibMaterial = {read=FLibMaterial, write=SetLibMaterial};
	__property Stage::Vectortypes::TGLMatrix TextureMatrix = {read=GetTextureMatrix};
	__property bool TextureMatrixIsUnitary = {read=GetTextureMatrixIsUnitary, nodefault};
	
__published:
	__property Gls::Coordinates::TGLCoordinates2* TexOffset = {read=FTexOffset, write=SetTexOffset};
	__property Gls::Coordinates::TGLCoordinates2* TexScale = {read=FTexScale, write=SetTexScale};
	__property Gls::Material::TGLBlendingMode BlendingMode = {read=FBlendingMode, write=SetBlendingMode, nodefault};
	__property Gls::Color::TGLColor* Emission = {read=FEmission, write=SetEmission};
	__property Gls::Color::TGLColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property Gls::Color::TGLColor* Diffuse = {read=FDiffuse, write=SetDiffuse};
	__property Gls::Color::TGLColor* Specular = {read=FSpecular, write=SetSpecular};
	__property Gls::Material::TGLShininess Shininess = {read=FShininess, write=SetShininess, nodefault};
	__property Gls::Material::TGLMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Material::TGLLibMaterialName LibMaterialName = {read=FLibMaterialName, write=SetLibMaterialName};
private:
	void *__IGLMaterialLibrarySupported;	// Gls::Material::IGLMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gls::Material::_di_IGLMaterialLibrarySupported()
	{
		Gls::Material::_di_IGLMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gls::Material::IGLMaterialLibrarySupported*(void) { return (Gls::Material::IGLMaterialLibrarySupported*)&__IGLMaterialLibrarySupported; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTextureSharingShaderMaterials : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TGLTextureSharingShaderMaterial* operator[](const int AIndex) { return this->Items[AIndex]; }
	
protected:
	TGLTextureSharingShaderMaterial* __fastcall GetItems(const int AIndex);
	void __fastcall SetItems(const int AIndex, TGLTextureSharingShaderMaterial* const Value);
	TGLTextureSharingShader* __fastcall GetParent();
	
public:
	HIDESBASE TGLTextureSharingShaderMaterial* __fastcall Add();
	__fastcall TGLTextureSharingShaderMaterials(TGLTextureSharingShader* AOwner);
	__property TGLTextureSharingShaderMaterial* Items[const int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLTextureSharingShaderMaterials() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLTextureSharingShader : public Gls::Material::TGLShader
{
	typedef Gls::Material::TGLShader inherited;
	
private:
	TGLTextureSharingShaderMaterials* FMaterials;
	int FCurrentPass;
	void __fastcall SetMaterials(TGLTextureSharingShaderMaterials* const Value);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLTextureSharingShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLTextureSharingShader();
	TGLTextureSharingShaderMaterial* __fastcall AddLibMaterial(Gls::Material::TGLLibMaterial* const ALibMaterial);
	TGLTextureSharingShaderMaterial* __fastcall FindLibMaterial(Gls::Material::TGLLibMaterial* const ALibMaterial);
	
__published:
	__property TGLTextureSharingShaderMaterials* Materials = {read=FMaterials, write=SetMaterials};
};


class PASCALIMPLEMENTATION TGLTexCombineShader : public Gls::Material::TGLShader
{
	typedef Gls::Material::TGLShader inherited;
	
private:
	System::Classes::TStringList* FCombiners;
	Gls::Texturecombiners::TCombinerCache FCommandCache;
	bool FCombinerIsValid;
	bool FDesignTimeEnabled;
	Gls::Material::TGLMaterialLibrary* FMaterialLibrary;
	Gls::Material::TGLLibMaterialName FLibMaterial3Name;
	Gls::Material::TGLLibMaterial* currentLibMaterial3;
	Gls::Material::TGLLibMaterialName FLibMaterial4Name;
	Gls::Material::TGLLibMaterial* currentLibMaterial4;
	bool FApplied3;
	bool FApplied4;
	
protected:
	void __fastcall SetCombiners(System::Classes::TStringList* const val);
	void __fastcall SetDesignTimeEnabled(const bool val);
	void __fastcall SetMaterialLibrary(Gls::Material::TGLMaterialLibrary* const val);
	void __fastcall SetLibMaterial3Name(const Gls::Material::TGLLibMaterialName val);
	void __fastcall SetLibMaterial4Name(const Gls::Material::TGLLibMaterialName val);
	void __fastcall NotifyLibMaterial3Destruction();
	void __fastcall NotifyLibMaterial4Destruction();
	virtual void __fastcall DoInitialize(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall DoFinalize();
	
public:
	__fastcall virtual TGLTexCombineShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLTexCombineShader();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property System::Classes::TStringList* Combiners = {read=FCombiners, write=SetCombiners};
	__property bool DesignTimeEnabled = {read=FDesignTimeEnabled, write=SetDesignTimeEnabled, nodefault};
	__property Gls::Material::TGLMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Material::TGLLibMaterialName LibMaterial3Name = {read=FLibMaterial3Name, write=SetLibMaterial3Name};
	__property Gls::Material::TGLLibMaterialName LibMaterial4Name = {read=FLibMaterial4Name, write=SetLibMaterial4Name};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Textureshaders */
}	/* namespace Glsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL_TEXTURESHADERS)
using namespace Glsl::Textureshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL)
using namespace Glsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLSL_TextureShadersHPP
