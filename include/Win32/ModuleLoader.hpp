// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ModuleLoader.pas' rev: 36.00 (Windows)

#ifndef ModuleLoaderHPP
#define ModuleLoaderHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>

//-- user supplied -----------------------------------------------------------

namespace Moduleloader
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef Winapi::Windows::HINST TModuleHandle;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST unsigned INVALID_MODULEHANDLE_VALUE = unsigned(0x0);
extern DELPHI_PACKAGE bool __stdcall LoadModule(TModuleHandle &Module, System::WideChar * FileName);
extern DELPHI_PACKAGE bool __stdcall LoadModuleEx(TModuleHandle &Module, System::WideChar * FileName, unsigned Flags);
extern DELPHI_PACKAGE void __stdcall UnloadModule(TModuleHandle &Module);
extern DELPHI_PACKAGE void * __stdcall GetModuleSymbol(TModuleHandle Module, System::WideChar * SymbolName);
extern DELPHI_PACKAGE void * __stdcall GetModuleSymbolEx(TModuleHandle Module, System::WideChar * SymbolName, bool &Accu);
extern DELPHI_PACKAGE bool __stdcall ReadModuleData(TModuleHandle Module, System::WideChar * SymbolName, void *Buffer, unsigned Size);
extern DELPHI_PACKAGE bool __stdcall WriteModuleData(TModuleHandle Module, System::WideChar * SymbolName, void *Buffer, unsigned Size);
}	/* namespace Moduleloader */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_MODULELOADER)
using namespace Moduleloader;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ModuleLoaderHPP
