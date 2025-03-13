// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CUDA.Compiler.pas' rev: 36.00 (Windows)

#ifndef GXS_CUDA_CompilerHPP
#define GXS_CUDA_CompilerHPP

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
#include <Winapi.Messages.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Winapi.TlHelp32.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.Strings.hpp>
#include <CUDA.Parser.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cuda
{
namespace Compiler
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSCUDACompiler;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSCUDACompilerOutput : unsigned char { codeUndefined, codePtx, codeCubin, codeGpu };

enum DECLSPEC_DENUM TgxSCUDAVirtArch : unsigned char { compute_10, compute_11, compute_12, compute_13, compute_20 };

enum DECLSPEC_DENUM TgxSCUDARealArch : unsigned char { sm_10, sm_11, sm_12, sm_13, sm_20, sm_21 };

typedef System::Set<TgxSCUDARealArch, TgxSCUDARealArch::sm_10, TgxSCUDARealArch::sm_21> TgxSCUDARealArchs;

class PASCALIMPLEMENTATION TgxSCUDACompiler : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::UnicodeString FNVCCPath;
	System::UnicodeString FCppCompilerPath;
	System::Classes::TStringList* FProduct;
	System::UnicodeString FProjectModule;
	System::UnicodeString FSourceCodeFile;
	System::UnicodeString FConsoleContent;
	TgxSCUDACompilerOutput FOutputCodeType;
	TgxSCUDAVirtArch FVirtualArch;
	TgxSCUDARealArchs FRealArch;
	int FMaxRegisterCount;
	Cuda::Parser::TCUDAModuleInfo* FModuleInfo;
	void __fastcall SetMaxRegisterCount(int Value);
	void __fastcall SetOutputCodeType(const TgxSCUDACompilerOutput Value);
	bool __fastcall StoreProjectModule();
	void __fastcall SetRealArch(TgxSCUDARealArchs AValue);
	void __fastcall SetNVCCPath(const System::UnicodeString AValue);
	void __fastcall SetCppCompilerPath(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Loaded();
	
public:
	__fastcall virtual TgxSCUDACompiler(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSCUDACompiler();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetSourceCodeFile(const System::UnicodeString AFileName);
	bool __fastcall Compile();
	__property System::Classes::TStringList* Product = {read=FProduct, write=FProduct};
	__property Cuda::Parser::TCUDAModuleInfo* ModuleInfo = {read=FModuleInfo};
	__property System::UnicodeString ConsoleContent = {read=FConsoleContent};
	
__published:
	__property System::UnicodeString NVCCPath = {read=FNVCCPath, write=SetNVCCPath};
	__property System::UnicodeString CppCompilerPath = {read=FCppCompilerPath, write=SetCppCompilerPath};
	__property System::UnicodeString SourceCodeFile = {read=FSourceCodeFile};
	__property System::UnicodeString ProjectModule = {read=FProjectModule, write=FProjectModule, stored=StoreProjectModule};
	__property TgxSCUDACompilerOutput OutputCodeType = {read=FOutputCodeType, write=SetOutputCodeType, default=1};
	__property TgxSCUDARealArchs RealArchitecture = {read=FRealArch, write=SetRealArch, default=8};
	__property TgxSCUDAVirtArch VirtualArchitecture = {read=FVirtualArch, write=FVirtualArch, default=3};
	__property int MaxRegisterCount = {read=FMaxRegisterCount, write=SetMaxRegisterCount, default=32};
};


typedef bool __fastcall (*TFindCuFileFunc)(System::UnicodeString &AModuleName);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TFindCuFileFunc vFindCuFileFunc;
}	/* namespace Compiler */
}	/* namespace Cuda */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CUDA_COMPILER)
using namespace Gxs::Cuda::Compiler;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CUDA)
using namespace Gxs::Cuda;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CUDA_CompilerHPP
