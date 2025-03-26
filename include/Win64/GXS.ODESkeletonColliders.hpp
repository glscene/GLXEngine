// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ODESkeletonColliders.pas' rev: 36.00 (Windows)

#ifndef GXS_ODESkeletonCollidersHPP
#define GXS_ODESkeletonCollidersHPP

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
#include <ODE.Import.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Odeskeletoncolliders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TSCODEBase;
class DELPHICLASS TSCODESphere;
class DELPHICLASS TSCODECCylinder;
class DELPHICLASS TSCODEBox;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TSCODEBase : public Gxs::Vectorfileobjects::TgxSkeletonCollider
{
	typedef Gxs::Vectorfileobjects::TgxSkeletonCollider inherited;
	
private:
	Ode::Import::PdxGeom FGeom;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	virtual void __fastcall AlignCollider();
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
public:
	/* TgxSkeletonCollider.Create */ inline __fastcall virtual TSCODEBase() : Gxs::Vectorfileobjects::TgxSkeletonCollider() { }
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TSCODEBase(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : Gxs::Vectorfileobjects::TgxSkeletonCollider(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSCODEBase(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxSkeletonCollider(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TSCODEBase() { }
	
};


class PASCALIMPLEMENTATION TSCODESphere : public TSCODEBase
{
	typedef TSCODEBase inherited;
	
private:
	Ode::Import::TdReal FRadius;
	
protected:
	void __fastcall SetRadius(const Ode::Import::TdReal val);
	
public:
	__fastcall virtual TSCODESphere();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property Ode::Import::TdReal Radius = {read=FRadius, write=SetRadius};
public:
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TSCODESphere(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : TSCODEBase(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSCODESphere(Gxs::Persistentclasses::TgxVirtualReader* reader) : TSCODEBase(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TSCODESphere() { }
	
};


class PASCALIMPLEMENTATION TSCODECCylinder : public TSCODEBase
{
	typedef TSCODEBase inherited;
	
private:
	float FRadius;
	float FLength;
	
protected:
	void __fastcall SetRadius(const float val);
	void __fastcall SetLength(const float val);
	
public:
	__fastcall virtual TSCODECCylinder();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TSCODECCylinder(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : TSCODEBase(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSCODECCylinder(Gxs::Persistentclasses::TgxVirtualReader* reader) : TSCODEBase(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TSCODECCylinder() { }
	
};


class PASCALIMPLEMENTATION TSCODEBox : public TSCODEBase
{
	typedef TSCODEBase inherited;
	
private:
	Ode::Import::TdReal FBoxWidth;
	Ode::Import::TdReal FBoxHeight;
	Ode::Import::TdReal FBoxDepth;
	
protected:
	void __fastcall SetBoxWidth(const Ode::Import::TdReal val);
	void __fastcall SetBoxHeight(const Ode::Import::TdReal val);
	void __fastcall SetBoxDepth(const Ode::Import::TdReal val);
	
public:
	__fastcall virtual TSCODEBox();
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property Ode::Import::TdReal BoxWidth = {read=FBoxWidth, write=SetBoxWidth};
	__property Ode::Import::TdReal BoxHeight = {read=FBoxHeight, write=SetBoxHeight};
	__property Ode::Import::TdReal BoxDepth = {read=FBoxDepth, write=SetBoxDepth};
public:
	/* TgxSkeletonCollider.CreateOwned */ inline __fastcall TSCODEBox(Gxs::Vectorfileobjects::TgxSkeletonColliderList* aOwner) : TSCODEBase(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TSCODEBox(Gxs::Persistentclasses::TgxVirtualReader* reader) : TSCODEBase(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TSCODEBox() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall AddSCODEGeomsToODESpace(Gxs::Vectorfileobjects::TgxSkeletonColliderList* colliders, Ode::Import::PdxSpace Space);
}	/* namespace Odeskeletoncolliders */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ODESKELETONCOLLIDERS)
using namespace Gxs::Odeskeletoncolliders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ODESkeletonCollidersHPP
