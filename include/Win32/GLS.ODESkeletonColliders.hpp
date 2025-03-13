// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ODESkeletonColliders.pas' rev: 36.00 (Windows)

#ifndef GLS_ODESkeletonCollidersHPP
#define GLS_ODESkeletonCollidersHPP

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
#include <Stage.VectorTypes.hpp>
#include <GLS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.VectorFileObjects.hpp>
#include <ODE.Import.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Odeskeletoncolliders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TSCODEBase;
class DELPHICLASS TSCODESphere;
class DELPHICLASS TSCODECCylinder;
class DELPHICLASS TSCODEBox;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TSCODEBase : public Gls::Vectorfileobjects::TGLSkeletonCollider
{
	typedef Gls::Vectorfileobjects::TGLSkeletonCollider inherited;
	
private:
	Ode::Import::PdxGeom FGeom;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	virtual void __fastcall AlignCollider();
	__property Ode::Import::PdxGeom Geom = {read=FGeom};
public:
	/* TGLSkeletonCollider.Create */ inline __fastcall virtual TSCODEBase() : Gls::Vectorfileobjects::TGLSkeletonCollider() { }
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TSCODEBase(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : Gls::Vectorfileobjects::TGLSkeletonCollider(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TSCODEBase(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Vectorfileobjects::TGLSkeletonCollider(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TSCODEBase() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSCODESphere : public TSCODEBase
{
	typedef TSCODEBase inherited;
	
private:
	Ode::Import::TdReal FRadius;
	
protected:
	void __fastcall SetRadius(const Ode::Import::TdReal val);
	
public:
	__fastcall virtual TSCODESphere();
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property Ode::Import::TdReal Radius = {read=FRadius, write=SetRadius};
public:
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TSCODESphere(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : TSCODEBase(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TSCODESphere(Gls::Persistentclasses::TGLVirtualReader* reader) : TSCODEBase(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TSCODESphere() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
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
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property float Radius = {read=FRadius, write=SetRadius};
	__property float Length = {read=FLength, write=SetLength};
public:
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TSCODECCylinder(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : TSCODEBase(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TSCODECCylinder(Gls::Persistentclasses::TGLVirtualReader* reader) : TSCODEBase(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TSCODECCylinder() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
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
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	virtual void __fastcall AddToSpace(Ode::Import::PdxSpace Space);
	__property Ode::Import::TdReal BoxWidth = {read=FBoxWidth, write=SetBoxWidth};
	__property Ode::Import::TdReal BoxHeight = {read=FBoxHeight, write=SetBoxHeight};
	__property Ode::Import::TdReal BoxDepth = {read=FBoxDepth, write=SetBoxDepth};
public:
	/* TGLSkeletonCollider.CreateOwned */ inline __fastcall TSCODEBox(Gls::Vectorfileobjects::TGLSkeletonColliderList* AOwner) : TSCODEBase(AOwner) { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TSCODEBox(Gls::Persistentclasses::TGLVirtualReader* reader) : TSCODEBase(reader) { }
	/* TGLPersistentObject.Destroy */ inline __fastcall virtual ~TSCODEBox() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall AddSCODEGeomsToODESpace(Gls::Vectorfileobjects::TGLSkeletonColliderList* colliders, Ode::Import::PdxSpace Space);
}	/* namespace Odeskeletoncolliders */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ODESKELETONCOLLIDERS)
using namespace Gls::Odeskeletoncolliders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ODESkeletonCollidersHPP
