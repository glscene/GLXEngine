// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.LinePFX.pas' rev: 36.00 (Windows)

#ifndef GLS_LinePFXHPP
#define GLS_LinePFXHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.ParticleFX.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Color.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.Context.hpp>
#include <Stage.VectorTypes.hpp>
#include <GLS.Cadencer.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Linepfx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLLineParticle;
class DELPHICLASS TGLLinePFXManager;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLLineParticle : public Gls::Particlefx::TGLParticle
{
	typedef Gls::Particlefx::TGLParticle inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FDirection;
	float FLength;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	__property Stage::Vectorgeometry::TAffineVector Direction = {read=FDirection, write=FDirection};
	__property float Length = {read=FLength, write=FLength};
public:
	/* TGLParticle.Create */ inline __fastcall virtual TGLLineParticle() : Gls::Particlefx::TGLParticle() { }
	/* TGLParticle.Destroy */ inline __fastcall virtual ~TGLLineParticle() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLLineParticle(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Particlefx::TGLParticle(reader) { }
	
};


class PASCALIMPLEMENTATION TGLLinePFXManager : public Gls::Particlefx::TGLLifeColoredPFXManager
{
	typedef Gls::Particlefx::TGLLifeColoredPFXManager inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector Fvx;
	Stage::Vectorgeometry::TAffineVector Fvy;
	Stage::Vectorgeometry::TAffineVector FNvx;
	Stage::Vectorgeometry::TAffineVector FNvy;
	float FDefaultLength;
	
protected:
	bool __fastcall StoreDefaultLength();
	virtual unsigned __fastcall TexturingMode();
	virtual void __fastcall InitializeRendering(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall BeginParticles(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall RenderParticle(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, Gls::Particlefx::TGLParticle* aParticle);
	virtual void __fastcall EndParticles(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall FinalizeRendering(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLLinePFXManager(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLLinePFXManager();
	__classmethod virtual Gls::Particlefx::TGLParticleClass __fastcall ParticlesClass();
	virtual Gls::Particlefx::TGLParticle* __fastcall CreateParticle();
	
__published:
	__property float DefaultLength = {read=FDefaultLength, write=FDefaultLength, stored=StoreDefaultLength};
	__property ParticleSize = {default=0};
	__property ColorInner;
	__property ColorOuter;
	__property LifeColors;
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Linepfx */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_LINEPFX)
using namespace Gls::Linepfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_LinePFXHPP
