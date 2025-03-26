// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.MaterialScript.pas' rev: 36.00 (Windows)

#ifndef GXS_MaterialScriptHPP
#define GXS_MaterialScriptHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Memo.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Utils.hpp>
#include <GXS.Texture.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Color.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Material.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Materialscript
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxShaderItem;
class DELPHICLASS TgxShaderItems;
class DELPHICLASS TgxMaterialLibraryItem;
class DELPHICLASS TgxMaterialLibraryItems;
class DELPHICLASS TgxMaterialScripter;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxShaderItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Material::TgxShader* FShader;
	System::UnicodeString FName;
	void __fastcall SetShader(Gxs::Material::TgxShader* const Value);
	void __fastcall SetName(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxShaderItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxShaderItem();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Material::TgxShader* Shader = {read=FShader, write=SetShader};
	__property System::UnicodeString Name = {read=FName, write=SetName};
};


class PASCALIMPLEMENTATION TgxShaderItems : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxShaderItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	void __fastcall SetItems(int Index, TgxShaderItem* const Val);
	TgxShaderItem* __fastcall GetItems(int Index);
	
public:
	__fastcall TgxShaderItems(System::Classes::TPersistent* AOwner);
	__property TgxShaderItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxShaderItems() { }
	
};


class PASCALIMPLEMENTATION TgxMaterialLibraryItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	System::UnicodeString FName;
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetName(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TgxMaterialLibraryItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TgxMaterialLibraryItem();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property System::UnicodeString Name = {read=FName, write=SetName};
};


class PASCALIMPLEMENTATION TgxMaterialLibraryItems : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TgxMaterialLibraryItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	void __fastcall SetItems(int Index, TgxMaterialLibraryItem* const Val);
	TgxMaterialLibraryItem* __fastcall GetItems(int Index);
	
public:
	__fastcall TgxMaterialLibraryItems(System::Classes::TPersistent* AOwner);
	__property TgxMaterialLibraryItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TgxMaterialLibraryItems() { }
	
};


class PASCALIMPLEMENTATION TgxMaterialScripter : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxShaderItems* FShaderItems;
	TgxMaterialLibraryItems* FMaterialLibraryItems;
	bool FAppend;
	bool FOverwrite;
	System::Classes::TStrings* FScript;
	Fmx::Memo::TMemo* FMemo;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	System::LongInt Count;
	System::LongInt infini;
	bool done;
	Gxs::Material::TgxLibMaterial* NewMat;
	Gxs::Coordinates::TgxCoordinates* tmpcoords;
	Gxs::Color::TgxColor* tmpcolor;
	Gxs::Coordinates::TgxCoordinates4* tmpcoords4;
	System::UnicodeString tmpstr;
	void __fastcall SeTgxShaderItems(TgxShaderItems* const Value);
	void __fastcall SeTgxMaterialLibraryItems(TgxMaterialLibraryItems* const Value);
	void __fastcall SetAppend(const bool Value);
	void __fastcall SetOverwrite(const bool Value);
	void __fastcall SetScript(System::Classes::TStrings* const Value);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetMemo(Fmx::Memo::TMemo* const Value);
	void __fastcall CheckError();
	bool __fastcall ClassExists(System::UnicodeString arguement);
	bool __fastcall CheckRepeatDone();
	System::UnicodeString __fastcall ExtractValue();
	void __fastcall ExtractCoords3();
	void __fastcall ExtractCoords4();
	void __fastcall ExtractColors();
	System::UnicodeString __fastcall DeleteSpaces(System::UnicodeString Value);
	bool __fastcall SubstrExists(System::UnicodeString substr);
	bool __fastcall ValueExists(System::UnicodeString Value);
	void __fastcall ZMaterial();
	void __fastcall XMaterial();
	void __fastcall XName();
	void __fastcall XShader();
	void __fastcall XTexture2Name();
	void __fastcall XTextureOffset();
	void __fastcall XTextureScale();
	void __fastcall XTexture();
	void __fastcall XCompression();
	void __fastcall XEnvColor();
	void __fastcall XFilteringQuality();
	void __fastcall XImageAlpha();
	void __fastcall XImageBrightness();
	void __fastcall XImageClass();
	void __fastcall XImageGamma();
	void __fastcall XMagFilter();
	void __fastcall XMappingMode();
	void __fastcall XMappingSCoordinates();
	void __fastcall XMappingTCoordinates();
	void __fastcall XMinFilter();
	void __fastcall XNormalMapScale();
	void __fastcall XTextureFormat();
	void __fastcall XTextureMode();
	void __fastcall XTextureWrap();
	void __fastcall XBlendingMode();
	void __fastcall XPolygonMode();
	void __fastcall XFacingCulling();
	void __fastcall XLibMaterialName();
	void __fastcall XMaterialOptions();
	void __fastcall XMaterialLibrary();
	void __fastcall XBackProperties();
	void __fastcall XBackAmbient();
	void __fastcall XBackDiffuse();
	void __fastcall XBackEmission();
	void __fastcall XBackShininess();
	void __fastcall XBackSpecular();
	void __fastcall XFrontProperties();
	void __fastcall XFrontAmbient();
	void __fastcall XFrontDiffuse();
	void __fastcall XFrontEmission();
	void __fastcall XFrontShininess();
	void __fastcall XFrontSpecular();
	void __fastcall XPersistantImage();
	void __fastcall XBlankImage();
	void __fastcall XPictureFileName();
	void __fastcall XPicturePX();
	void __fastcall XPictureNX();
	void __fastcall XPicturePY();
	void __fastcall XPictureNY();
	void __fastcall XPicturePZ();
	void __fastcall XPictureNZ();
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__property Fmx::Memo::TMemo* DebugMemo = {read=FMemo, write=SetMemo};
	__fastcall virtual TgxMaterialScripter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxMaterialScripter();
	void __fastcall CompileScript();
	
__published:
	__property System::Classes::TStrings* Script = {read=FScript, write=SetScript};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property TgxShaderItems* Shaders = {read=FShaderItems, write=SeTgxShaderItems};
	__property TgxMaterialLibraryItems* MaterialLibraries = {read=FMaterialLibraryItems, write=SeTgxMaterialLibraryItems};
	__property bool AppendToMaterialLibrary = {read=FAppend, write=SetAppend, nodefault};
	__property bool OverwriteToMaterialLibrary = {read=FOverwrite, write=SetOverwrite, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Materialscript */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_MATERIALSCRIPT)
using namespace Gxs::Materialscript;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_MaterialScriptHPP
