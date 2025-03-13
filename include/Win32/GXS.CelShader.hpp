// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CelShader.pas' rev: 36.00 (Windows)

#ifndef GXS_CelShaderHPP
#define GXS_CelShaderHPP

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
#include <GXS.Color.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Context.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.State.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Celshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCelShader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxCelShaderOption : unsigned char { csoOutlines, csoTextured, csoNoBuildShadeTexture };

typedef System::Set<TgxCelShaderOption, TgxCelShaderOption::csoOutlines, TgxCelShaderOption::csoNoBuildShadeTexture> TgxCelShaderOptions;

typedef void __fastcall (__closure *TgxCelShaderGetIntensity)(System::TObject* Sender, System::Byte &intensity);

class PASCALIMPLEMENTATION TgxCelShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	float FOutlineWidth;
	TgxCelShaderOptions FCelShaderOptions;
	Gxs::Context::TgxVertexProgramHandle* FVPHandle;
	Gxs::Texture::TgxTexture* FShadeTexture;
	TgxCelShaderGetIntensity FOnGetIntensity;
	bool FOutlinePass;
	bool FUnApplyShadeTexture;
	Gxs::Color::TgxColor* FOutlineColor;
	
protected:
	void __fastcall SetCelShaderOptions(const TgxCelShaderOptions val);
	void __fastcall SetOutlineWidth(const float val);
	void __fastcall SetOutlineColor(Gxs::Color::TgxColor* const val);
	void __fastcall BuildShadeTexture();
	virtual void __fastcall Loaded();
	System::UnicodeString __fastcall GenerateVertexProgram();
	
public:
	__fastcall virtual TgxCelShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCelShader();
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	__property Gxs::Texture::TgxTexture* ShadeTexture = {read=FShadeTexture};
	
__published:
	__property TgxCelShaderOptions CelShaderOptions = {read=FCelShaderOptions, write=SetCelShaderOptions, nodefault};
	__property Gxs::Color::TgxColor* OutlineColor = {read=FOutlineColor, write=SetOutlineColor};
	__property float OutlineWidth = {read=FOutlineWidth, write=SetOutlineWidth};
	__property TgxCelShaderGetIntensity OnGetIntensity = {read=FOnGetIntensity, write=FOnGetIntensity};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Celshader */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CELSHADER)
using namespace Gxs::Celshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CelShaderHPP
