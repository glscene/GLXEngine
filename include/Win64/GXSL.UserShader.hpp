// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXSL.UserShader.pas' rev: 36.00 (Windows)

#ifndef GXSL_UserShaderHPP
#define GXSL_UserShaderHPP

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
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxsl
{
namespace Usershader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxUserShader;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnDoApplyEvent)(System::TObject* Sender, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);

typedef void __fastcall (__closure *TOnDoUnApplyEvent)(System::TObject* Sender, int Pass, Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, bool &Continue);

class PASCALIMPLEMENTATION TgxUserShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	int FPass;
	TOnDoApplyEvent FOnDoApply;
	TOnDoUnApplyEvent FOnDoUnApply;
	
protected:
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TOnDoApplyEvent OnDoApply = {read=FOnDoApply, write=FOnDoApply};
	__property TOnDoUnApplyEvent OnDoUnApply = {read=FOnDoUnApply, write=FOnDoUnApply};
	__property ShaderStyle = {default=1};
public:
	/* TgxShader.Create */ inline __fastcall virtual TgxUserShader(System::Classes::TComponent* AOwner) : Gxs::Material::TgxShader(AOwner) { }
	/* TgxShader.Destroy */ inline __fastcall virtual ~TgxUserShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Usershader */
}	/* namespace Gxsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL_USERSHADER)
using namespace Gxsl::Usershader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSL)
using namespace Gxsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXSL_UserShaderHPP
