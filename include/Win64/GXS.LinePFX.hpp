// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.LinePFX.pas' rev: 36.00 (Windows)

#ifndef GXS_LinePFXHPP
#define GXS_LinePFXHPP

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
#include <Winapi.OpenGLext.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.ParticleFX.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Color.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.Cadencer.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Linepfx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxLineParticle;
class DELPHICLASS TgxLinePFXManager;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxLineParticle : public Gxs::Particlefx::TgxParticle
{
	typedef Gxs::Particlefx::TgxParticle inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FDirection;
	float FLength;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* reader);
	__property Stage::Vectorgeometry::TAffineVector Direction = {read=FDirection, write=FDirection};
	__property float Length = {read=FLength, write=FLength};
public:
	/* TgxParticle.Create */ inline __fastcall virtual TgxLineParticle() : Gxs::Particlefx::TgxParticle() { }
	/* TgxParticle.Destroy */ inline __fastcall virtual ~TgxLineParticle() { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxLineParticle(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Particlefx::TgxParticle(reader) { }
	
};


class PASCALIMPLEMENTATION TgxLinePFXManager : public Gxs::Particlefx::TgxLifeColoredPFXManager
{
	typedef Gxs::Particlefx::TgxLifeColoredPFXManager inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector Fvx;
	Stage::Vectorgeometry::TAffineVector Fvy;
	Stage::Vectorgeometry::TAffineVector FNvx;
	Stage::Vectorgeometry::TAffineVector FNvy;
	float FDefaultLength;
	
protected:
	bool __fastcall StoreDefaultLength();
	virtual unsigned __fastcall TexturingMode();
	virtual void __fastcall InitializeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall BeginParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall RenderParticle(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, Gxs::Particlefx::TgxParticle* aParticle);
	virtual void __fastcall EndParticles(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
public:
	__fastcall virtual TgxLinePFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TgxLinePFXManager();
	__classmethod virtual Gxs::Particlefx::TgxParticleClass __fastcall ParticlesClass();
	virtual Gxs::Particlefx::TgxParticle* __fastcall CreateParticle();
	
__published:
	__property float DefaultLength = {read=FDefaultLength, write=FDefaultLength, stored=StoreDefaultLength};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Linepfx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_LINEPFX)
using namespace Gxs::Linepfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_LinePFXHPP
