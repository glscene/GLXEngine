// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CgPostTransformationShader.pas' rev: 36.00 (Windows)

#ifndef GXS_CgPostTransformationShaderHPP
#define GXS_CgPostTransformationShaderHPP

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
#include <GXS.Texture.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Context.hpp>
#include <GXS.Scene.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXSL.CustomShader.hpp>
#include <Cg.GL.hpp>
#include <Cg.Import.hpp>
#include <GXS.CgShader.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cgposttransformationshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCGxCustomPostTransformationShader;
class DELPHICLASS TCGxPostTransformationShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCGxCustomPostTransformationShader : public Gxs::Cgshader::TCGxCustomShader
{
	typedef Gxs::Cgshader::TCGxCustomShader inherited;
	
private:
	float FTransformationPower;
	Gxs::Texture::TgxTexture* FTransformationTexture;
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	void __fastcall DoUseTempTexture(Gxs::Context::TgxTextureHandle* const TempTexture, Stage::Textureformat::TglTextureTarget TextureTarget);
	Stage::Textureformat::TglTextureTarget __fastcall GetTextureTarget();
	
public:
	__fastcall virtual TCGxCustomPostTransformationShader(System::Classes::TComponent* AOwner);
	__property float TransformationPower = {read=FTransformationPower, write=FTransformationPower};
	__property Gxs::Texture::TgxTexture* TransformationTexture = {read=FTransformationTexture, write=FTransformationTexture};
public:
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxCustomPostTransformationShader() { }
	
private:
	void *__IgxPostShader;	// Gxsl::Customshader::IgxPostShader 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68A62362-AF0A-4CE8-A9E1-714FE02AFA4A}
	operator Gxsl::Customshader::_di_IgxPostShader()
	{
		Gxsl::Customshader::_di_IgxPostShader intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxsl::Customshader::IgxPostShader*(void) { return (Gxsl::Customshader::IgxPostShader*)&__IgxPostShader; }
	#endif
	
};


class PASCALIMPLEMENTATION TCGxPostTransformationShader : public TCGxCustomPostTransformationShader
{
	typedef TCGxCustomPostTransformationShader inherited;
	
__published:
	__property TransformationPower = {default=0};
	__property TransformationTexture;
public:
	/* TCGxCustomPostTransformationShader.Create */ inline __fastcall virtual TCGxPostTransformationShader(System::Classes::TComponent* AOwner) : TCGxCustomPostTransformationShader(AOwner) { }
	
public:
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxPostTransformationShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cgposttransformationshader */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CGPOSTTRANSFORMATIONSHADER)
using namespace Gxs::Cgposttransformationshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CgPostTransformationShaderHPP
