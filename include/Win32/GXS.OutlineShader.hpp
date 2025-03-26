// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.OutlineShader.pas' rev: 36.00 (Windows)

#ifndef GXS_OutlineShaderHPP
#define GXS_OutlineShaderHPP

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
#include <GXS.Material.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Outlineshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxOutlineShader;
//-- type declarations -------------------------------------------------------
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
}	/* namespace Outlineshader */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_OUTLINESHADER)
using namespace Gxs::Outlineshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_OutlineShaderHPP
