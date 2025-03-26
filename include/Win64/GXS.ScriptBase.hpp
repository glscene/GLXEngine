// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ScriptBase.pas' rev: 36.00 (Windows)

#ifndef GXS_ScriptBaseHPP
#define GXS_ScriptBaseHPP

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
#include <GXS.XCollection.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Scriptbase
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxScriptBase;
class DELPHICLASS TgxScripts;
class DELPHICLASS TgxScriptLibrary;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxScriptState : unsigned char { ssUncompiled, ssCompileErrors, ssCompiled, ssRunningErrors, ssRunning };

class PASCALIMPLEMENTATION TgxScriptBase : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	System::Classes::TStringList* FText;
	System::UnicodeString FDescription;
	System::Classes::TStringList* FErrors;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual TgxScriptState __fastcall GetState() = 0 ;
	void __fastcall SetText(System::Classes::TStringList* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxScriptBase(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxScriptBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Compile() = 0 ;
	virtual void __fastcall Start() = 0 ;
	virtual void __fastcall Stop() = 0 ;
	virtual void __fastcall Execute() = 0 ;
	virtual void __fastcall Invalidate() = 0 ;
	virtual System::Variant __fastcall Call(System::UnicodeString aName, System::Variant *aParams, const System::NativeInt aParams_High) = 0 ;
	__property System::Classes::TStringList* Errors = {read=FErrors};
	__property TgxScriptState State = {read=GetState, nodefault};
	
__published:
	__property System::Classes::TStringList* Text = {read=FText, write=SetText};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
};


class PASCALIMPLEMENTATION TgxScripts : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	TgxScriptBase* operator[](int index) { return this->Items[index]; }
	
protected:
	HIDESBASE TgxScriptBase* __fastcall GetItems(int index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	virtual bool __fastcall CanAdd(Gxs::Xcollection::TXCollectionItemClass aClass);
	__property TgxScriptBase* Items[int index] = {read=GetItems/*, default*/};
public:
	/* TXCollection.Create */ inline __fastcall virtual TgxScripts(System::Classes::TPersistent* aOwner) : Gxs::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxScripts() { }
	
};


class PASCALIMPLEMENTATION TgxScriptLibrary : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TgxScripts* FScripts;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteScriptsData(System::Classes::TStream* Stream);
	void __fastcall ReadScriptsData(System::Classes::TStream* Stream);
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TgxScriptLibrary(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxScriptLibrary();
	
__published:
	__property TgxScripts* Scripts = {read=FScripts};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Scriptbase */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SCRIPTBASE)
using namespace Gxs::Scriptbase;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ScriptBaseHPP
