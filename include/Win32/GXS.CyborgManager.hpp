// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CyborgManager.pas' rev: 36.00 (Windows)

#ifndef GXS_CyborgManagerHPP
#define GXS_CyborgManagerHPP

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
#include <GXS.SmartObjects.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.FileGLTF.hpp>
#include <GXS.File3DS.hpp>
#include <GXS.FilePLY.hpp>
#include <GXS.FileOBJ.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cyborgmanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxCyborgManager;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxCyborgManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Gxs::Objects::TgxDummyCube* FMasterObject;
	System::Classes::TStringList* FModelList;
	System::UnicodeString FModelPath;
	void __fastcall SetPathToModel(const System::UnicodeString Value);
	
public:
	__fastcall virtual TgxCyborgManager(Gxs::Objects::TgxDummyCube* AMaster, System::UnicodeString APath);
	__fastcall virtual ~TgxCyborgManager();
	Gxs::Smartobjects::TgxCyborg* __fastcall LoadModel(System::UnicodeString AFilename);
	__property Gxs::Objects::TgxDummyCube* MasterObject = {read=FMasterObject};
	__property System::Classes::TStringList* ModelList = {read=FModelList};
	__property System::UnicodeString Path = {read=FModelPath, write=SetPathToModel};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cyborgmanager */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CYBORGMANAGER)
using namespace Gxs::Cyborgmanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CyborgManagerHPP
