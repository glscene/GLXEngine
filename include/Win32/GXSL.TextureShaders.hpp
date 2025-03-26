// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.TextureShaders.pas' rev: 36.00 (Windows)

#ifndef GXSL_TextureShadersHPP
#define GXSL_TextureShadersHPP

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
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Texture.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Color.hpp>
#include <GXS.Material.hpp>
#include <Stage.Strings.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.State.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.TextureCombiners.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Textureshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxShaderTextureSharingMaterial;
class DELPHICLASS TgxShaderTextureSharingMaterials;
class DELPHICLASS TgxShaderTextureSharing;
class DELPHICLASS TgxTexCombineShader;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxShaderTextureSharingMaterial : public Gxs::Persistentclasses::TgxInterfacedCollectionItem
{
	typedef Gxs::Persistentclasses::TgxInterfacedCollectionItem inherited;
	
private:
	Stage::Vectortypes::TMatrix4f FTextureMatrix;
	bool FNeedToUpdateTextureMatrix;
	bool FTextureMatrixIsUnitary;
	Gxs::Material::TgxLibMaterial* FLibMaterial;
	Gxs::Coordinates::TgxCoordinates2* FTexOffset;
	Gxs::Coordinates::TgxCoordinates2* FTexScale;
	Gxs::Material::TgxBlendingMode FBlendingMode;
	Gxs::Color::TgxColor* FSpecular;
	Gxs::Color::TgxColor* FAmbient;
	Gxs::Color::TgxColor* FDiffuse;
	Gxs::Color::TgxColor* FEmission;
	Gxs::Material::TgxShininess FShininess;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxLibMaterialName FLibMaterialName;
	void __fastcall SetAmbient(Gxs::Color::TgxColor* const Value);
	void __fastcall SetDiffuse(Gxs::Color::TgxColor* const Value);
	void __fastcall SetEmission(Gxs::Color::TgxColor* const Value);
	void __fastcall SetShininess(const Gxs::Material::TgxShininess Value);
	void __fastcall SetSpecular(Gxs::Color::TgxColor* const Value);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetLibMaterialName(const Gxs::Material::TgxLibMaterialName Value);
	void __fastcall SetBlendingMode(const Gxs::Material::TgxBlendingMode Value);
	void __fastcall SetLibMaterial(Gxs::Material::TgxLibMaterial* const Value);
	void __fastcall SetTexOffset(Gxs::Coordinates::TgxCoordinates2* const Value);
	void __fastcall SetTexScale(Gxs::Coordinates::TgxCoordinates2* const Value);
	Stage::Vectortypes::TMatrix4f __fastcall GetTextureMatrix();
	bool __fastcall GetTextureMatrixIsUnitary();
	
protected:
	void __fastcall coordNotifychange(System::TObject* Sender);
	void __fastcall OtherNotifychange(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetDisplayName();
	TgxShaderTextureSharing* __fastcall GetTextureSharingShader();
	virtual Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
public:
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__fastcall virtual TgxShaderTextureSharingMaterial(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxShaderTextureSharingMaterial();
	__property Gxs::Material::TgxLibMaterial* LibMaterial = {read=FLibMaterial, write=SetLibMaterial};
	__property Stage::Vectortypes::TMatrix4f TextureMatrix = {read=GetTextureMatrix};
	__property bool TextureMatrixIsUnitary = {read=GetTextureMatrixIsUnitary, nodefault};
	
__published:
	__property Gxs::Coordinates::TgxCoordinates2* TexOffset = {read=FTexOffset, write=SetTexOffset};
	__property Gxs::Coordinates::TgxCoordinates2* TexScale = {read=FTexScale, write=SetTexScale};
	__property Gxs::Material::TgxBlendingMode BlendingMode = {read=FBlendingMode, write=SetBlendingMode, nodefault};
	__property Gxs::Color::TgxColor* Emission = {read=FEmission, write=SetEmission};
	__property Gxs::Color::TgxColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property Gxs::Color::TgxColor* Diffuse = {read=FDiffuse, write=SetDiffuse};
	__property Gxs::Color::TgxColor* Specular = {read=FSpecular, write=SetSpecular};
	__property Gxs::Material::TgxShininess Shininess = {read=FShininess, write=SetShininess, nodefault};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName LibMaterialName = {read=FLibMaterialName, write=SetLibMaterialName};
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

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxShaderTextureSharingMaterials : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxShaderTextureSharingMaterial* operator[](const int AIndex) { return this->Items[AIndex]; }
	
protected:
	TgxShaderTextureSharingMaterial* __fastcall GetItems(const int AIndex);
	void __fastcall SetItems(const int AIndex, TgxShaderTextureSharingMaterial* const Value);
	TgxShaderTextureSharing* __fastcall GetParent();
	
public:
	HIDESBASE TgxShaderTextureSharingMaterial* __fastcall Add();
	__fastcall TgxShaderTextureSharingMaterials(TgxShaderTextureSharing* AOwner);
	__property TgxShaderTextureSharingMaterial* Items[const int AIndex] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxShaderTextureSharingMaterials() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxShaderTextureSharing : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	TgxShaderTextureSharingMaterials* FMaterials;
	int FCurrentPass;
	void __fastcall SetMaterials(TgxShaderTextureSharingMaterials* const Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxShaderTextureSharing(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxShaderTextureSharing();
	TgxShaderTextureSharingMaterial* __fastcall AddLibMaterial(Gxs::Material::TgxLibMaterial* const ALibMaterial);
	TgxShaderTextureSharingMaterial* __fastcall FindLibMaterial(Gxs::Material::TgxLibMaterial* const ALibMaterial);
	
__published:
	__property TgxShaderTextureSharingMaterials* Materials = {read=FMaterials, write=SetMaterials};
};


class PASCALIMPLEMENTATION TgxTexCombineShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	System::Classes::TStringList* FCombiners;
	Gxs::Texturecombiners::TgxCombinerCache FCommandCache;
	bool FCombinerIsValid;
	bool FDesignTimeEnabled;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	Gxs::Material::TgxLibMaterialName FLibMaterial3Name;
	Gxs::Material::TgxLibMaterial* CurrentLibMaterial3;
	Gxs::Material::TgxLibMaterialName FLibMaterial4Name;
	Gxs::Material::TgxLibMaterial* CurrentLibMaterial4;
	bool FApplied3;
	bool FApplied4;
	
protected:
	void __fastcall SetCombiners(System::Classes::TStringList* const val);
	void __fastcall SetDesignTimeEnabled(const bool val);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetLibMaterial3Name(const Gxs::Material::TgxLibMaterialName val);
	void __fastcall SetLibMaterial4Name(const Gxs::Material::TgxLibMaterialName val);
	void __fastcall NotifyLibMaterial3Destruction();
	void __fastcall NotifyLibMaterial4Destruction();
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoFinalize();
	
public:
	__fastcall virtual TgxTexCombineShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTexCombineShader();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property System::Classes::TStringList* Combiners = {read=FCombiners, write=SetCombiners};
	__property bool DesignTimeEnabled = {read=FDesignTimeEnabled, write=SetDesignTimeEnabled, nodefault};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property Gxs::Material::TgxLibMaterialName LibMaterial3Name = {read=FLibMaterial3Name, write=SetLibMaterial3Name};
	__property Gxs::Material::TgxLibMaterialName LibMaterial4Name = {read=FLibMaterial4Name, write=SetLibMaterial4Name};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Textureshaders */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_TEXTURESHADERS)
using namespace Gxsl::Textureshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_TextureShadersHPP
