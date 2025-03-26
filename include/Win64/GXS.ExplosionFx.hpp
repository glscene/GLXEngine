// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ExplosionFx.pas' rev: 36.00 (Windows)

#ifndef GXS_ExplosionFxHPP
#define GXS_ExplosionFxHPP

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
#include <GXS.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Explosionfx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxBExplosionFX;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxBExplosionFX : public Gxs::Scene::TgxObjectPreEffect
{
	typedef Gxs::Scene::TgxObjectPreEffect inherited;
	
private:
	Gxs::Vectorlists::TgxAffineVectorList* FTriList;
	Gxs::Vectorlists::TgxAffineVectorList* FRotList;
	Gxs::Vectorlists::TgxAffineVectorList* FDirList;
	Gxs::Vectorlists::TgxAffineVectorList* FPosList;
	bool FEnabled;
	int FFaceCount;
	float FSpeed;
	Gxs::Coordinates::TgxCoordinates* FDirection;
	int FMaxSteps;
	int FStep;
	void __fastcall SetTriList(Gxs::Vectorlists::TgxAffineVectorList* Value);
	void __fastcall SetRotList(Gxs::Vectorlists::TgxAffineVectorList* Value);
	void __fastcall SetDirList(Gxs::Vectorlists::TgxAffineVectorList* Value);
	void __fastcall SetPosList(Gxs::Vectorlists::TgxAffineVectorList* Value);
	void __fastcall SetDirection(Gxs::Coordinates::TgxCoordinates* value);
	void __fastcall SetEnabled(bool value);
	
protected:
	__property Gxs::Vectorlists::TgxAffineVectorList* TriList = {read=FTriList, write=SetTriList};
	__property Gxs::Vectorlists::TgxAffineVectorList* RotList = {read=FRotList, write=SetRotList};
	__property Gxs::Vectorlists::TgxAffineVectorList* DirList = {read=FDirList, write=SetDirList};
	__property Gxs::Vectorlists::TgxAffineVectorList* PosList = {read=FPosList, write=SetPosList};
	__property int FaceCount = {read=FFaceCount, write=FFaceCount, nodefault};
	void __fastcall CacheInfo();
	
public:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
	__property int Step = {read=FStep, nodefault};
	__fastcall virtual TgxBExplosionFX(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxBExplosionFX();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	void __fastcall Reset();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property int MaxSteps = {read=FMaxSteps, write=FMaxSteps, nodefault};
	__property float Speed = {read=FSpeed, write=FSpeed};
	__property Gxs::Coordinates::TgxCoordinates* Direction = {read=FDirection, write=SetDirection};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Explosionfx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_EXPLOSIONFX)
using namespace Gxs::Explosionfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ExplosionFxHPP
