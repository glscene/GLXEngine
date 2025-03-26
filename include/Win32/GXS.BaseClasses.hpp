// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.BaseClasses.pas' rev: 36.00 (Windows)

#ifndef GXS_BaseClassesHPP
#define GXS_BaseClassesHPP

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
#include <System.SysUtils.hpp>
#include <Stage.Strings.hpp>
#include <GXS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Baseclasses
{
//-- forward type declarations -----------------------------------------------
struct TgxProgressTimes;
__interface DELPHIINTERFACE IgxNotifyAble;
typedef System::DelphiInterface<IgxNotifyAble> _di_IgxNotifyAble;
__interface DELPHIINTERFACE IgxProgessAble;
typedef System::DelphiInterface<IgxProgessAble> _di_IgxProgessAble;
class DELPHICLASS TgxUpdateAbleObject;
class DELPHICLASS TgxCadenceAbleComponent;
class DELPHICLASS TgxUpdateAbleComponent;
class DELPHICLASS TGNotifyCollection;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxProgressTimes
{
public:
	double DeltaTime;
	double NewTime;
	float SqrDeltaTime;
	float InvSqrDeltaTime;
};
#pragma pack(pop)


typedef void __fastcall (__closure *TgxProgressEvent)(System::TObject* Sender, const double DeltaTime, const double NewTime);

__interface  INTERFACE_UUID("{00079A6C-D46E-4126-86EE-F9E2951B4593}") IgxNotifyAble  : public System::IInterface 
{
	virtual void __fastcall NotifyChange(System::TObject* Sender) = 0 ;
};

__interface  INTERFACE_UUID("{95E44548-B0FE-4607-98D0-CA51169AF8B5}") IgxProgessAble  : public System::IInterface 
{
	virtual void __fastcall DoProgress(const TgxProgressTimes &progressTime) = 0 ;
};

class PASCALIMPLEMENTATION TgxUpdateAbleObject : public Gxs::Persistentclasses::TgxInterfacedPersistent
{
	typedef Gxs::Persistentclasses::TgxInterfacedPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	int FUpdating;
	System::Classes::TNotifyEvent FOnNotifyChange;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner() _FINAL_ATTRIBUTE;
	
public:
	__fastcall virtual TgxUpdateAbleObject(System::Classes::TPersistent* AOwner);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Notification(System::TObject* Sender, System::Classes::TOperation Operation);
	__property int Updating = {read=FUpdating, nodefault};
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property System::Classes::TNotifyEvent OnNotifyChange = {read=FOnNotifyChange, write=FOnNotifyChange};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxUpdateAbleObject() { }
	
private:
	void *__IgxNotifyAble;	// IgxNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator _di_IgxNotifyAble()
	{
		_di_IgxNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxNotifyAble*(void) { return (IgxNotifyAble*)&__IgxNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxCadenceAbleComponent : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	virtual void __fastcall DoProgress(const TgxProgressTimes &progressTime);
public:
	/* TComponent.Create */ inline __fastcall virtual TgxCadenceAbleComponent(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TgxCadenceAbleComponent() { }
	
private:
	void *__IgxProgessAble;	// IgxProgessAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {95E44548-B0FE-4607-98D0-CA51169AF8B5}
	operator _di_IgxProgessAble()
	{
		_di_IgxProgessAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxProgessAble*(void) { return (IgxProgessAble*)&__IgxProgessAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxUpdateAbleComponent : public TgxCadenceAbleComponent
{
	typedef TgxCadenceAbleComponent inherited;
	
public:
	virtual void __fastcall NotifyChange(System::TObject* Sender);
public:
	/* TComponent.Create */ inline __fastcall virtual TgxUpdateAbleComponent(System::Classes::TComponent* AOwner) : TgxCadenceAbleComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TgxUpdateAbleComponent() { }
	
private:
	void *__IgxNotifyAble;	// IgxNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator _di_IgxNotifyAble()
	{
		_di_IgxNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IgxNotifyAble*(void) { return (IgxNotifyAble*)&__IgxNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TGNotifyCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
private:
	System::Classes::TNotifyEvent FOnNotifyChange;
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* item);
	
public:
	__fastcall TGNotifyCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass);
	__property System::Classes::TNotifyEvent OnNotifyChange = {read=FOnNotifyChange, write=FOnNotifyChange};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGNotifyCollection() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Baseclasses */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BASECLASSES)
using namespace Gxs::Baseclasses;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BaseClassesHPP
