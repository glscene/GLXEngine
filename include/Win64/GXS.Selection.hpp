// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Selection.pas' rev: 36.00 (Windows)

#ifndef GXS_SelectionHPP
#define GXS_SelectionHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <GXS.Context.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Selection
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TPickRecord;
class DELPHICLASS TgxPickList;
class DELPHICLASS TgxBaseSelectTechnique;
class DELPHICLASS TgxSelectRenderModeTechnique;
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<int> TPickSubObjects;

class PASCALIMPLEMENTATION TPickRecord : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Gxs::Baseclasses::TgxUpdateAbleComponent* AObject;
	TPickSubObjects SubObjects;
	float ZMin;
	float ZMax;
public:
	/* TObject.Create */ inline __fastcall TPickRecord() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TPickRecord() { }
	
};


enum DECLSPEC_DENUM TPickSortType : unsigned char { psDefault, psName, psMinDepth, psMaxDepth };

class PASCALIMPLEMENTATION TgxPickList : public Gxs::Persistentclasses::TgxPersistentObjectList
{
	typedef Gxs::Persistentclasses::TgxPersistentObjectList inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Hit[Index]; }
	
private:
	float __fastcall GetFar(int aValue);
	System::TObject* __fastcall GetHit(int aValue);
	float __fastcall GetNear(int aValue);
	TPickSubObjects __fastcall GetSubObjects(int aValue);
	
public:
	__fastcall TgxPickList(TPickSortType aSortType);
	void __fastcall AddHit(System::TObject* obj, const TPickSubObjects subObj, float zMin, float zMax);
	virtual void __fastcall Clear();
	int __fastcall FindObject(System::TObject* AObject);
	__property float FarDistance[int Index] = {read=GetFar};
	__property System::TObject* Hit[int Index] = {read=GetHit/*, default*/};
	__property float NearDistance[int Index] = {read=GetNear};
	__property TPickSubObjects SubObjects[int Index] = {read=GetSubObjects};
public:
	/* TgxPersistentObjectList.Destroy */ inline __fastcall virtual ~TgxPickList() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxPickList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObjectList(reader) { }
	
};


class PASCALIMPLEMENTATION TgxBaseSelectTechnique : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<System::TObject*> _TgxBaseSelectTechnique__1;
	
	
protected:
	_TgxBaseSelectTechnique__1 FObjectStack;
	System::StaticArray<unsigned, 256> FNameStack;
	unsigned FCurrentName;
	int FStackPosition;
	int FObjectCountGuess;
	int FHits;
	virtual System::TObject* __fastcall GetObject() = 0 ;
	virtual void __fastcall SetObject(System::TObject* Value) = 0 ;
	virtual int __fastcall GetHits() = 0 ;
	virtual void __fastcall SetHits(int Value) = 0 ;
	virtual void __fastcall SetObjectCountGuess(int Value) = 0 ;
	virtual System::TObject* __fastcall GetItems(int Value) = 0 ;
	
public:
	virtual __classmethod bool __fastcall IsSupported() = 0 ;
	virtual void __fastcall Start() = 0 ;
	virtual bool __fastcall Stop() = 0 ;
	virtual void __fastcall PushObject(System::TObject* AName) = 0 ;
	virtual void __fastcall PopObject() = 0 ;
	virtual void __fastcall LoadObject(System::TObject* AName) = 0 ;
	virtual void __fastcall FillPickingList(TgxPickList* &AList) = 0 ;
	__property System::TObject* CurrentObject = {read=GetObject, write=SetObject};
	__property int ObjectCountGuess = {read=FObjectCountGuess, write=SetObjectCountGuess, nodefault};
	__property int Hits = {read=GetHits, write=SetHits, nodefault};
public:
	/* TObject.Create */ inline __fastcall TgxBaseSelectTechnique() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxBaseSelectTechnique() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxBaseSelectTechniqueClass);

class PASCALIMPLEMENTATION TgxSelectRenderModeTechnique : public TgxBaseSelectTechnique
{
	typedef TgxBaseSelectTechnique inherited;
	
	
private:
	typedef System::DynamicArray<unsigned> _TgxSelectRenderModeTechnique__1;
	
	
private:
	_TgxSelectRenderModeTechnique__1 FBuffer;
	
protected:
	virtual System::TObject* __fastcall GetObject();
	virtual void __fastcall SetObject(System::TObject* Value);
	virtual int __fastcall GetHits();
	virtual void __fastcall SetHits(int Value);
	virtual void __fastcall SetObjectCountGuess(int Value);
	
public:
	__classmethod virtual bool __fastcall IsSupported();
	virtual void __fastcall Start();
	virtual bool __fastcall Stop();
	virtual void __fastcall FillPickingList(TgxPickList* &AList);
	__property ObjectCountGuess;
	__property Hits;
	__property CurrentObject;
public:
	/* TObject.Create */ inline __fastcall TgxSelectRenderModeTechnique() : TgxBaseSelectTechnique() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxSelectRenderModeTechnique() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word MAX_OBJECT_STACK_DEPTH = System::Word(0x200);
extern DELPHI_PACKAGE TgxBaseSelectTechniqueClass __fastcall GetBestSelectorClass(void);
}	/* namespace Selection */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SELECTION)
using namespace Gxs::Selection;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SelectionHPP
