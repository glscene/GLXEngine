// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.MultiMaterialShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_MultiMaterialShaderHPP
#define GXSL_MultiMaterialShaderHPP

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
#include <GXS.Material.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Multimaterialshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxMultiMaterialShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxMultiMaterialShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	int FPass;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	bool FVisibleAtDesignTime;
	bool FShaderActiveAtDesignTime;
	Gxs::Material::TgxShaderStyle FShaderStyle;
	void __fastcall SetVisibleAtDesignTime(const bool Value);
	void __fastcall SetShaderStyle(const Gxs::Material::TgxShaderStyle Value);
	
protected:
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxMultiMaterialShader(System::Classes::TComponent* aOwner);
	
__published:
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property bool VisibleAtDesignTime = {read=FVisibleAtDesignTime, write=SetVisibleAtDesignTime, nodefault};
	__property Gxs::Material::TgxShaderStyle ShaderStyle = {read=FShaderStyle, write=SetShaderStyle, nodefault};
public:
	/* TgxShader.Destroy */ inline __fastcall virtual ~TgxMultiMaterialShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Multimaterialshader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_MULTIMATERIALSHADER)
using namespace Gxsl::Multimaterialshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_MultiMaterialShaderHPP
