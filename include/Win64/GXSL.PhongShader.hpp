// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.PhongShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_PhongShaderHPP
#define GXSL_PhongShaderHPP

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
#include <GXS.Texture.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXSL.AsmShader.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXS.State.hpp>
#include <GXS.Material.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Phongshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxPhongShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxPhongShader : public Gxsl::Asmshader::TgxCustomAsmShader
{
	typedef Gxsl::Asmshader::TgxCustomAsmShader inherited;
	
private:
	Gxs::Vectorlists::TgxIntegerList* FLightIDs;
	bool FDesignTimeEnabled;
	bool FAmbientPass;
	void __fastcall SetDesignTimeEnabled(const bool Value);
	
protected:
	virtual void __fastcall DoLightPass(unsigned lightID);
	virtual void __fastcall DoAmbientPass(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall UnApplyLights(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	
public:
	__fastcall virtual TgxPhongShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxPhongShader();
	virtual bool __fastcall ShaderSupported();
	
__published:
	__property bool DesignTimeEnabled = {read=FDesignTimeEnabled, write=SetDesignTimeEnabled, default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Phongshader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_PHONGSHADER)
using namespace Gxsl::Phongshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_PhongShaderHPP
