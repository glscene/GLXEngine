// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.NGDRagdoll.pas' rev: 36.00 (Windows)

#ifndef GXS_NGDRagdollHPP
#define GXS_NGDRagdollHPP

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
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <NGD.Import.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Ngdragdoll
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TNewtonRagdoll;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TNewtonRagdoll : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<void *> _TNewtonRagdoll__1;
	
	typedef System::DynamicArray<Stage::Vectortypes::TMatrix4f> _TNewtonRagdoll__2;
	
	#pragma pack(push,8)
	struct DECLSPEC_DRECORD _TNewtonRagdoll__3
	{
	public:
		System::Byte kind;
		Stage::Vectortypes::TMatrix4f Mat;
		Stage::Vectortypes::TVector3f Pt;
		float W;
		float D;
		float H;
		float Mass;
	};
	#pragma pack(pop)
	
	
	typedef System::DynamicArray<_TNewtonRagdoll__3> _TNewtonRagdoll__4;
	
	
private:
	float FERP;
	float FSlideLimit;
	float FAngleLimit;
	bool FEnabled;
	Ngd::Import::PNewtonWorld newtonworld;
	void __fastcall SetSlideLimit(float value);
	void __fastcall SetAngleLimit(float value);
	void __fastcall SetERP(float value);
	void __fastcall SetEnabled(bool value);
	void __fastcall Clean();
	
public:
	Gxs::Vectorfileobjects::TgxActor* Actor;
	System::Classes::TList* Bodies;
	_TNewtonRagdoll__1 Joints;
	_TNewtonRagdoll__2 Norm_matrices;
	_TNewtonRagdoll__4 Envelopes;
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
	__property float SlideLimit = {read=FSlideLimit, write=SetSlideLimit};
	__property float AngleLimit = {read=FAngleLimit, write=SetAngleLimit};
	__property float ERP = {read=FERP, write=SetERP};
	__fastcall TNewtonRagdoll(Gxs::Vectorfileobjects::TgxActor* model, Ngd::Import::PNewtonWorld world, float min_env_size, float slide_limit, float erp_, float angle_limit, bool full);
	void __fastcall Conform();
	__fastcall virtual ~TNewtonRagdoll();
	void __fastcall LoadFromFile(System::UnicodeString filename);
	void __fastcall SaveToFile(System::UnicodeString filename);
	Stage::Vectortypes::TVector4f __fastcall TranslatePos(int n, bool add);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall GetBoneParent(Gxs::Vectorfileobjects::TgxActor* actor, int bone);
}	/* namespace Ngdragdoll */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_NGDRAGDOLL)
using namespace Gxs::Ngdragdoll;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_NGDRagdollHPP
