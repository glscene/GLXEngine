// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Trail.pas' rev: 36.00 (Windows)

#ifndef GXS_TrailHPP
#define GXS_TrailHPP

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
#include <GXS.Scene.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.MeshUtils.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Mesh.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Material.hpp>
#include <Stage.Strings.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Trail
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTrail;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMarkStyle : unsigned char { msUp, msDirection, msFaceCamera, msRight };

class PASCALIMPLEMENTATION TgxTrail : public Gxs::Mesh::TgxMesh
{
	typedef Gxs::Mesh::TgxMesh inherited;
	
private:
	int fVertLimit;
	float fTimeLimit;
	float fMinDistance;
	float fAlpha;
	bool fAlphaFade;
	float fUVScale;
	System::StaticArray<Stage::Vectortypes::TVector3f, 2000> fVerts;
	System::StaticArray<Stage::Vectorgeometry::TTexPoint, 2000> fUVs;
	System::StaticArray<double, 2000> fTimeStamps;
	int fVertStart;
	int fVertEnd;
	int fVertCount;
	Stage::Vectortypes::TVector3f fLastV0Pos;
	Stage::Vectortypes::TVector3f fLastPos;
	Stage::Vectortypes::TVector3f fLastDir;
	Stage::Vectortypes::TVector3f fLastUp;
	float FLastUVs;
	Stage::Vectortypes::TVector3f fLastP1;
	Stage::Vectortypes::TVector3f fLastP2;
	Gxs::Scene::TgxBaseSceneObject* FTrailObject;
	TMarkStyle FMarkStyle;
	float FMarkWidth;
	bool FEnabled;
	float FAntiZFightOffset;
	void __fastcall SetTrailObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetMarkStyle(const TMarkStyle Value);
	void __fastcall SetAlpha(const float Value);
	void __fastcall SetAlphaFade(const bool Value);
	void __fastcall SetMinDistance(const float Value);
	void __fastcall SetTimeLimit(const float Value);
	void __fastcall SetUVScale(const float Value);
	void __fastcall SetVertLimit(const int Value);
	void __fastcall SetMarkWidth(const float Value);
	void __fastcall SetEnabled(const bool Value);
	bool __fastcall StoreAntiZFightOffset();
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	__fastcall virtual TgxTrail(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxTrail();
	void __fastcall CreateMark(Gxs::Scene::TgxBaseSceneObject* obj, float width, double CurrentTime)/* overload */;
	void __fastcall CreateMark(const Stage::Vectortypes::TVector3f &APos, const Stage::Vectortypes::TVector3f &ADir, const Stage::Vectortypes::TVector3f &AUp, float AWidth, double ACurrentTime)/* overload */;
	bool __fastcall CreateMark(const Stage::Vectortypes::TVector3f &p1, const Stage::Vectortypes::TVector3f &p2, double CurrentTime)/* overload */;
	void __fastcall ClearMarks();
	
__published:
	__property float AntiZFightOffset = {read=FAntiZFightOffset, write=FAntiZFightOffset, stored=StoreAntiZFightOffset};
	__property int VertLimit = {read=fVertLimit, write=SetVertLimit, default=150};
	__property float TimeLimit = {read=fTimeLimit, write=SetTimeLimit};
	__property float MinDistance = {read=fMinDistance, write=SetMinDistance};
	__property float Alpha = {read=fAlpha, write=SetAlpha};
	__property bool AlphaFade = {read=fAlphaFade, write=SetAlphaFade, default=1};
	__property float UVScale = {read=fUVScale, write=SetUVScale};
	__property TMarkStyle MarkStyle = {read=FMarkStyle, write=SetMarkStyle, default=2};
	__property Gxs::Scene::TgxBaseSceneObject* TrailObject = {read=FTrailObject, write=SetTrailObject, default=0};
	__property float MarkWidth = {read=FMarkWidth, write=SetMarkWidth};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxTrail(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Mesh::TgxMesh(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word cMaxVerts = System::Word(0x7d0);
}	/* namespace Trail */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TRAIL)
using namespace Gxs::Trail;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TrailHPP
