// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.PipelineTransform.pas' rev: 36.00 (Windows)

#ifndef Stage_PipelineTransformHPP
#define Stage_PipelineTransformHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Logger.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Pipelinetransform
{
//-- forward type declarations -----------------------------------------------
struct TgTransformationRec;
class DELPHICLASS TgTransformation;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgPipelineTransformationState : unsigned char { trsModelViewChanged, trsInvModelViewChanged, trsInvModelChanged, trsNormalModelChanged, trsViewProjChanged, trsFrustum };

typedef System::Set<TgPipelineTransformationState, TgPipelineTransformationState::trsModelViewChanged, TgPipelineTransformationState::trsFrustum> TgPipelineTransformationStates;

typedef TgTransformationRec *PgTransformationRec;

struct DECLSPEC_DRECORD TgTransformationRec
{
public:
	TgPipelineTransformationStates FStates;
	Stage::Vectortypes::TGLMatrix FModelMatrix;
	Stage::Vectortypes::TGLMatrix FViewMatrix;
	Stage::Vectortypes::TGLMatrix FProjectionMatrix;
	Stage::Vectortypes::TGLMatrix FInvModelMatrix;
	Stage::Vectorgeometry::TAffineMatrix FNormalModelMatrix;
	Stage::Vectortypes::TGLMatrix FModelViewMatrix;
	Stage::Vectortypes::TGLMatrix FInvModelViewMatrix;
	Stage::Vectortypes::TGLMatrix FViewProjectionMatrix;
	Stage::Vectorgeometry::TFrustum FFrustum;
};


typedef void __fastcall (__closure *TgOnMatricesPush)(void);

class PASCALIMPLEMENTATION TgTransformation : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TgTransformationRec> _TgTransformation__1;
	
	
private:
	int FStackPos;
	_TgTransformation__1 FStack;
	bool FLoadMatricesEnabled;
	TgOnMatricesPush FOnPush;
	Stage::Vectortypes::PGLMatrix __fastcall GetModelMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetViewMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetProjectionMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetModelViewMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetInvModelViewMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetInvModelMatrix();
	Stage::Vectorgeometry::PAffineMatrix __fastcall GetNormalModelMatrix();
	Stage::Vectortypes::PGLMatrix __fastcall GetViewProjectionMatrix();
	Stage::Vectorgeometry::TFrustum __fastcall GetFrustum();
	
protected:
	void __fastcall LoadModelViewMatrix();
	void __fastcall LoadProjectionMatrix();
	void __fastcall DoMatricesLoaded();
	__property TgOnMatricesPush OnPush = {read=FOnPush, write=FOnPush};
	
public:
	__fastcall TgTransformation();
	void __fastcall SetModelMatrix(const Stage::Vectortypes::TGLMatrix &AMatrix);
	void __fastcall SetViewMatrix(const Stage::Vectortypes::TGLMatrix &AMatrix);
	void __fastcall SetProjectionMatrix(const Stage::Vectortypes::TGLMatrix &AMatrix);
	void __fastcall IdentityAll();
	void __fastcall Push(PgTransformationRec AValue)/* overload */;
	void __fastcall Push()/* overload */;
	void __fastcall Pop();
	void __fastcall ReplaceFromStack();
	TgTransformationRec __fastcall StackTop();
	__property Stage::Vectortypes::PGLMatrix ModelMatrix = {read=GetModelMatrix};
	__property Stage::Vectortypes::PGLMatrix ViewMatrix = {read=GetViewMatrix};
	__property Stage::Vectortypes::PGLMatrix ProjectionMatrix = {read=GetProjectionMatrix};
	__property Stage::Vectortypes::PGLMatrix InvModelMatrix = {read=GetInvModelMatrix};
	__property Stage::Vectortypes::PGLMatrix ModelViewMatrix = {read=GetModelViewMatrix};
	__property Stage::Vectorgeometry::PAffineMatrix NormalModelMatrix = {read=GetNormalModelMatrix};
	__property Stage::Vectortypes::PGLMatrix InvModelViewMatrix = {read=GetInvModelViewMatrix};
	__property Stage::Vectortypes::PGLMatrix ViewProjectionMatrix = {read=GetViewProjectionMatrix};
	__property Stage::Vectorgeometry::TFrustum Frustum = {read=GetFrustum};
	__property bool LoadMatricesEnabled = {read=FLoadMatricesEnabled, write=FLoadMatricesEnabled, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgTransformation() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte MAX_MATRIX_STACK_DEPTH = System::Byte(0x80);
#define cAllStatesChanged (System::Set<TgPipelineTransformationState, TgPipelineTransformationState::trsModelViewChanged, TgPipelineTransformationState::trsFrustum>() << TgPipelineTransformationState::trsModelViewChanged << TgPipelineTransformationState::trsInvModelViewChanged << TgPipelineTransformationState::trsInvModelChanged << TgPipelineTransformationState::trsNormalModelChanged << TgPipelineTransformationState::trsViewProjChanged << TgPipelineTransformationState::trsFrustum )
}	/* namespace Pipelinetransform */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_PIPELINETRANSFORM)
using namespace Stage::Pipelinetransform;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_PipelineTransformHPP
