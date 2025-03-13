// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.CyborgManager.pas' rev: 36.00 (Windows)

#ifndef GLS_CyborgManagerHPP
#define GLS_CyborgManagerHPP

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
#include <GLS.Scene.hpp>
#include <GLS.Objects.hpp>
#include <GLS.SmartObjects.hpp>
#include <GLS.File3DS.hpp>
#include <GLS.FilePLY.hpp>
#include <GLS.FileOBJ.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Cyborgmanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLCyborgManager;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLCyborgManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gls::Objects::TGLDummyCube* FMasterObject;
	System::Classes::TStringList* FModelList;
	System::UnicodeString FModelPath;
	void __fastcall SetPathToModel(const System::UnicodeString Value);
	
public:
	__fastcall virtual TGLCyborgManager(Gls::Objects::TGLDummyCube* AMaster, System::UnicodeString APath);
	__fastcall virtual ~TGLCyborgManager();
	Gls::Smartobjects::TGLCyborg* __fastcall LoadModel(System::UnicodeString AFilename);
	__property Gls::Objects::TGLDummyCube* MasterObject = {read=FMasterObject};
	__property System::Classes::TStringList* ModelList = {read=FModelList};
	__property System::UnicodeString Path = {read=FModelPath, write=SetPathToModel};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cyborgmanager */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_CYBORGMANAGER)
using namespace Gls::Cyborgmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_CyborgManagerHPP
