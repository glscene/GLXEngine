// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TexLensFlare.pas' rev: 36.00 (Windows)

#ifndef GXS_TexLensFlareHPP
#define GXS_TexLensFlareHPP

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
#include <GXS.Scene.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.State.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Texlensflare
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTextureLensFlare;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxTextureLensFlare : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	int FSize;
	float FCurrSize;
	int FNumSecs;
	bool FAutoZTest;
	double FDeltaTime;
	Gxs::Texture::TgxTexture* FImgSecondaries;
	Gxs::Texture::TgxTexture* FImgRays;
	Gxs::Texture::TgxTexture* FImgRing;
	Gxs::Texture::TgxTexture* FImgGlow;
	int FSeed;
	void __fastcall SetImgGlow(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetImgRays(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetImgRing(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetImgSecondaries(Gxs::Texture::TgxTexture* const Value);
	void __fastcall SetSeed(const int Value);
	
protected:
	void __fastcall SetSize(int aValue);
	void __fastcall SetNumSecs(int aValue);
	void __fastcall SetAutoZTest(bool aValue);
	
public:
	__fastcall virtual TgxTextureLensFlare(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTextureLensFlare();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	
__published:
	__property int Size = {read=FSize, write=SetSize, default=50};
	__property int Seed = {read=FSeed, write=SetSeed, nodefault};
	__property int NumSecs = {read=FNumSecs, write=SetNumSecs, default=8};
	__property bool AutoZTest = {read=FAutoZTest, write=SetAutoZTest, default=1};
	__property Gxs::Texture::TgxTexture* ImgGlow = {read=FImgGlow, write=SetImgGlow};
	__property Gxs::Texture::TgxTexture* ImgRays = {read=FImgRays, write=SetImgRays};
	__property Gxs::Texture::TgxTexture* ImgRing = {read=FImgRing, write=SetImgRing};
	__property Gxs::Texture::TgxTexture* ImgSecondaries = {read=FImgSecondaries, write=SetImgSecondaries};
	__property ObjectsSorting = {default=0};
	__property Position;
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTextureLensFlare(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Texlensflare */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TEXLENSFLARE)
using namespace Gxs::Texlensflare;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TexLensFlareHPP
