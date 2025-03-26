// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uGBEOptionsUtils.pas' rev: 36.00 (Windows)

#ifndef uGBEOptionsUtilsHPP
#define uGBEOptionsUtilsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <FMX.Types3D.hpp>
#include <System.IniFiles.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ugbeoptionsutils
{
//-- forward type declarations -----------------------------------------------
struct TGBEOptions;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TKeyboardType : unsigned char { QWERTY, AZERTY };

struct DECLSPEC_DRECORD TGBEOptions
{
public:
	bool afficherLignes;
	bool activerMusiques;
	bool activerSons;
	bool activerVagues;
	bool activerHerbe;
	bool activerHerbeVent;
	bool activerNuages;
	bool afficherFPS;
	bool utilisationTasks;
	bool pleinEcran;
	float volumeSons;
	float volumeMusiques;
	int detailsHeightmap;
	int nbNuages;
	int nbHerbe;
	int detailsVagues;
	Fmx::Types3d::TMultisample Filter;
	TKeyboardType Keyboard;
	void __fastcall WriteConfig(System::UnicodeString configFile);
	void __fastcall SaveOption(System::UnicodeString configFile, System::UnicodeString section, System::UnicodeString option, System::UnicodeString value);
	void __fastcall ReadConfig(System::UnicodeString configFile);
	System::UnicodeString __fastcall ReadOption(System::UnicodeString configFile, System::UnicodeString section, System::UnicodeString option);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ugbeoptionsutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UGBEOPTIONSUTILS)
using namespace Ugbeoptionsutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uGBEOptionsUtilsHPP
