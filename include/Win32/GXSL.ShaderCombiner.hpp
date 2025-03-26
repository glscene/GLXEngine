// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.ShaderCombiner.pas' rev: 36.00 (Windows)

#ifndef GXSL_ShaderCombinerHPP
#define GXSL_ShaderCombinerHPP

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
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Shadercombiner
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCustomShaderCombiner;
class DELPHICLASS TgxShaderCombiner;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxShaderCombinerType : unsigned char { sctOneSPTwoAP, sctTwoSPOneAP, sctOneMPTwoSP, sctTwoMPOneSP };

class PASCALIMPLEMENTATION TgxCustomShaderCombiner : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	int FCurrentPass;
	TgxShaderCombinerType FCombinerType;
	Gxs::Material::TgxShader* FShaderOne;
	Gxs::Material::TgxShader* FShaderTwo;
	void __fastcall SetShaderOne(Gxs::Material::TgxShader* const Value);
	void __fastcall SetShaderTwo(Gxs::Material::TgxShader* const Value);
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property TgxShaderCombinerType CombinerType = {read=FCombinerType, write=FCombinerType, default=0};
	__property Gxs::Material::TgxShader* ShaderOne = {read=FShaderOne, write=SetShaderOne};
	__property Gxs::Material::TgxShader* ShaderTwo = {read=FShaderTwo, write=SetShaderTwo};
	__property int CurrentPass = {read=FCurrentPass, stored=false, nodefault};
	
public:
	__fastcall virtual TgxCustomShaderCombiner(System::Classes::TComponent* AOwner);
	virtual bool __fastcall ShaderSupported();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TgxShader.Destroy */ inline __fastcall virtual ~TgxCustomShaderCombiner() { }
	
};


class PASCALIMPLEMENTATION TgxShaderCombiner : public TgxCustomShaderCombiner
{
	typedef TgxCustomShaderCombiner inherited;
	
__published:
	__property CombinerType = {default=0};
	__property ShaderOne;
	__property ShaderTwo;
	__property ShaderStyle = {default=1};
public:
	/* TgxCustomShaderCombiner.Create */ inline __fastcall virtual TgxShaderCombiner(System::Classes::TComponent* AOwner) : TgxCustomShaderCombiner(AOwner) { }
	
public:
	/* TgxShader.Destroy */ inline __fastcall virtual ~TgxShaderCombiner() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shadercombiner */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_SHADERCOMBINER)
using namespace Gxsl::Shadercombiner;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_ShaderCombinerHPP
