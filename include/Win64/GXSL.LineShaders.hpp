// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.LineShaders.pas' rev: 36.00 (Windows)

#ifndef GXSL_LineShadersHPP
#define GXSL_LineShadersHPP

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
#include <System.Classes.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Color.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Lineshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxLineSettings;
class DELPHICLASS TgxHiddenLineShader;
class DELPHICLASS TgxOutlineShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxLineSettings : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	Gxs::Color::TgxColor* FColor;
	float FWidth;
	Stage::Opengltokens::TGLushort FPattern;
	bool FForceMaterial;
	void __fastcall SetPattern(const Stage::Opengltokens::TGLushort value);
	void __fastcall SetColor(Gxs::Color::TgxColor* const v);
	void __fastcall SetWidth(const float Value);
	void __fastcall SetForceMaterial(bool v);
	
public:
	__fastcall virtual TgxLineSettings(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TgxLineSettings();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property float Width = {read=FWidth, write=SetWidth};
	__property Gxs::Color::TgxColor* Color = {read=FColor, write=SetColor};
	__property Stage::Opengltokens::TGLushort Pattern = {read=FPattern, write=SetPattern, default=65535};
	__property bool ForceMaterial = {read=FForceMaterial, write=SetForceMaterial, default=0};
};


class PASCALIMPLEMENTATION TgxHiddenLineShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	int FPassCount;
	bool FLineSmooth;
	bool FSolid;
	Gxs::Color::TgxColor* FBackGroundColor;
	TgxLineSettings* FFrontLine;
	TgxLineSettings* FBackLine;
	bool FLighting;
	Gxs::Scene::TgxShadeModel FShadeModel;
	void __fastcall SetlineSmooth(bool v);
	void __fastcall SetSolid(bool v);
	void __fastcall SetBackgroundColor(Gxs::Color::TgxColor* AColor);
	void __fastcall SetLighting(bool v);
	void __fastcall SetShadeModel(const Gxs::Scene::TgxShadeModel val);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxHiddenLineShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHiddenLineShader();
	
__published:
	__property TgxLineSettings* FrontLine = {read=FFrontLine, write=FFrontLine};
	__property TgxLineSettings* BackLine = {read=FBackLine, write=FBackLine};
	__property bool LineSmooth = {read=FLineSmooth, write=SetlineSmooth, default=0};
	__property bool Solid = {read=FSolid, write=SetSolid, default=0};
	__property Gxs::Color::TgxColor* BackgroundColor = {read=FBackGroundColor, write=SetBackgroundColor};
	__property bool SurfaceLit = {read=FLighting, write=SetLighting, default=1};
	__property Gxs::Scene::TgxShadeModel ShadeModel = {read=FShadeModel, write=SetShadeModel, default=0};
};


class PASCALIMPLEMENTATION TgxOutlineShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	int FPassCount;
	Gxs::Color::TgxColor* FLineColor;
	bool FOutlineSmooth;
	float FOutlineWidth;
	void __fastcall SetOutlineWidth(float v);
	void __fastcall SetOutlineSmooth(bool v);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxOutlineShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxOutlineShader();
	
__published:
	__property Gxs::Color::TgxColor* LineColor = {read=FLineColor, write=FLineColor};
	__property bool LineSmooth = {read=FOutlineSmooth, write=SetOutlineSmooth, default=0};
	__property float LineWidth = {read=FOutlineWidth, write=SetOutlineWidth};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Lineshaders */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_LINESHADERS)
using namespace Gxsl::Lineshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_LineShadersHPP
