// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ThorFX.pas' rev: 36.00 (Windows)

#ifndef GXS_ThorFXHPP
#define GXS_ThorFXHPP

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
#include <System.Math.hpp>
#include <GXS.XCollection.hpp>
#include <GXS.Scene.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Color.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <Stage.Manager.hpp>
#include <GXS.State.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Thorfx
{
//-- forward type declarations -----------------------------------------------
struct TThorpoint;
class DELPHICLASS TgxThorFXManager;
class DELPHICLASS TgxBThorFX;
//-- type declarations -------------------------------------------------------
typedef TThorpoint *PThorpoint;

struct DECLSPEC_DRECORD TThorpoint
{
public:
	Stage::Vectortypes::TVector4f Position;
	float Size;
};


typedef System::StaticArray<TThorpoint, 33554432> TThorpointArray;

typedef TThorpointArray *PThorpointArray;

typedef void __fastcall (__closure *TCalcPointEvent)(System::TObject* Sender, int PointNo, float &x, float &y, float &z);

class PASCALIMPLEMENTATION TgxThorFXManager : public Gxs::Baseclasses::TgxCadenceAbleComponent
{
	typedef Gxs::Baseclasses::TgxCadenceAbleComponent inherited;
	
private:
	System::Classes::TList* FClients;
	PThorpointArray FThorpoints;
	Gxs::Coordinates::TgxCoordinates* FTarget;
	Gxs::Cadencer::TgxCadencer* FCadencer;
	int FMaxpoints;
	float FGlowSize;
	float FVibrate;
	float FWildness;
	int NP;
	Gxs::Color::TgxColor* FInnerColor;
	Gxs::Color::TgxColor* FOuterColor;
	Gxs::Color::TgxColor* FCoreColor;
	bool FDisabled;
	bool FCore;
	bool FGlow;
	TCalcPointEvent FOnCalcPoint;
	
protected:
	void __fastcall RegisterClient(TgxBThorFX* aClient);
	void __fastcall DeRegisterClient(TgxBThorFX* aClient);
	void __fastcall DeRegisterAllClients();
	void __fastcall SetTarget(Gxs::Coordinates::TgxCoordinates* const val);
	void __fastcall SetCadencer(Gxs::Cadencer::TgxCadencer* const val);
	void __fastcall SetMaxpoints(const int val);
	bool __fastcall StoreGlowSize();
	bool __fastcall StoreVibrate();
	void __fastcall SetInnerColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetOuterColor(Gxs::Color::TgxColor* const val);
	void __fastcall SetCoreColor(Gxs::Color::TgxColor* const val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ThorInit();
	void __fastcall CalcThor();
	void __fastcall CalcFrac(int left, int right, float lh, float rh, int xyz);
	
public:
	__fastcall virtual TgxThorFXManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxThorFXManager();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	
__published:
	__property Gxs::Coordinates::TgxCoordinates* Target = {read=FTarget, write=SetTarget};
	__property Gxs::Cadencer::TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	__property int Maxpoints = {read=FMaxpoints, write=SetMaxpoints, default=256};
	__property float GlowSize = {read=FGlowSize, write=FGlowSize, stored=StoreGlowSize};
	__property float Vibrate = {read=FVibrate, write=FVibrate, stored=StoreVibrate};
	__property Gxs::Color::TgxColor* InnerColor = {read=FInnerColor, write=SetInnerColor};
	__property Gxs::Color::TgxColor* OuterColor = {read=FOuterColor, write=SetOuterColor};
	__property Gxs::Color::TgxColor* CoreColor = {read=FCoreColor, write=SetCoreColor};
	__property bool Disabled = {read=FDisabled, write=FDisabled, nodefault};
	__property bool Core = {read=FCore, write=FCore, nodefault};
	__property bool Glow = {read=FGlow, write=FGlow, nodefault};
	__property float Wildness = {read=FWildness, write=FWildness};
	__property TCalcPointEvent OnCalcPoint = {read=FOnCalcPoint, write=FOnCalcPoint};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxBThorFX : public Gxs::Scene::TgxObjectPostEffect
{
	typedef Gxs::Scene::TgxObjectPostEffect inherited;
	
private:
	TgxThorFXManager* FManager;
	System::UnicodeString FManagerName;
	Gxs::Coordinates::TgxCoordinates* FTarget;
	
protected:
	void __fastcall SetManager(TgxThorFXManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetTarget(Gxs::Coordinates::TgxCoordinates* const val);
	
public:
	__fastcall virtual TgxBThorFX(Gxs::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TgxBThorFX();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Render(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	
__published:
	__property TgxThorFXManager* Manager = {read=FManager, write=SetManager};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TgxBThorFX* __fastcall GetOrCreateThorFX(Gxs::Scene::TgxBaseSceneObject* obj, const System::UnicodeString name = System::UnicodeString());
}	/* namespace Thorfx */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_THORFX)
using namespace Gxs::Thorfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ThorFXHPP
