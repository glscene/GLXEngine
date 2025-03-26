// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.AsmShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_AsmShaderHPP
#define GXSL_AsmShaderHPP

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
#include <System.SysUtils.hpp>
#include <GXS.Context.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Texture.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Asmshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxAsmShaderParameter;
class DELPHICLASS TgxCustomAsmShader;
class DELPHICLASS TgxAsmShader;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TgxAsmShaderEvent)(TgxCustomAsmShader* Shader);

typedef void __fastcall (__closure *TgxAsmShaderUnUplyEvent)(TgxCustomAsmShader* Shader, bool &ThereAreMorePasses);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxAsmShaderParameter : public Gxsl::Customshader::TgxCustomShaderParameter
{
	typedef Gxsl::Customshader::TgxCustomShaderParameter inherited;
	
public:
	/* TObject.Create */ inline __fastcall TgxAsmShaderParameter() : Gxsl::Customshader::TgxCustomShaderParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxAsmShaderParameter() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TgxCustomAsmShader : public Gxsl::Customshader::TgxCustomShader
{
	typedef Gxsl::Customshader::TgxCustomShader inherited;
	
private:
	Gxs::Context::TgxVertexProgramHandle* FVPHandle;
	Gxs::Context::TgxFragmentProgramHandle* FFPHandle;
	Gxs::Context::TgxGeometryProgramHandle* FGPHandle;
	TgxAsmShaderEvent FOnInitialize;
	TgxAsmShaderEvent FOnApply;
	TgxAsmShaderUnUplyEvent FOnUnApply;
	
protected:
	void __fastcall ApplyShaderPrograms();
	void __fastcall UnApplyShaderPrograms();
	virtual void __fastcall DestroyARBPrograms();
	__property TgxAsmShaderEvent OnApply = {read=FOnApply, write=FOnApply};
	__property TgxAsmShaderUnUplyEvent OnUnApply = {read=FOnUnApply, write=FOnUnApply};
	__property TgxAsmShaderEvent OnInitialize = {read=FOnInitialize, write=FOnInitialize};
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoFinalize();
	
public:
	__fastcall virtual TgxCustomAsmShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomAsmShader();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall ShaderSupported();
};


class PASCALIMPLEMENTATION TgxAsmShader : public TgxCustomAsmShader
{
	typedef TgxCustomAsmShader inherited;
	
__published:
	__property FragmentProgram;
	__property VertexProgram;
	__property GeometryProgram;
	__property OnApply;
	__property OnUnApply;
	__property OnInitialize;
	__property ShaderStyle = {default=1};
	__property FailedInitAction = {default=1};
public:
	/* TgxCustomAsmShader.Create */ inline __fastcall virtual TgxAsmShader(System::Classes::TComponent* AOwner) : TgxCustomAsmShader(AOwner) { }
	/* TgxCustomAsmShader.Destroy */ inline __fastcall virtual ~TgxAsmShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Asmshader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_ASMSHADER)
using namespace Gxsl::Asmshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_AsmShaderHPP
