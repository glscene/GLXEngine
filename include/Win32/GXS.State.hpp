// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.State.pas' rev: 36.00 (Windows)

#ifndef GXS_StateHPP
#define GXS_StateHPP

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
#include <Stage.Strings.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <GXS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace State
{
//-- forward type declarations -----------------------------------------------
struct TgxLightSourceState;
struct TgxShaderLightSourceState;
struct TUBOStates;
class DELPHICLASS TgxStateCache;
struct TgxStateRecord;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxStateType : unsigned char { sttCurrent, sttPoint, sttLine, sttPolygon, sttPolygonStipple, sttPixelMode, sttLighting, sttFog, sttDepthBuffer, sttAccumBuffer, sttStencilBuffer, sttViewport, sttTransform, sttEnable, sttColorBuffer, sttHint, sttEval, sttList, sttTexture, sttScissor, sttMultisample };

typedef System::Set<TgxStateType, TgxStateType::sttCurrent, TgxStateType::sttMultisample> TgxStateTypes;

enum DECLSPEC_DENUM TgxMeshPrimitive : unsigned char { mpNOPRIMITIVE, mpTRIANGLES, mpTRIANGLE_STRIP, mpTRIANGLE_FAN, mpPOINTS, mpLINES, mpLINE_LOOP, mpLINE_STRIP, mpLINES_ADJACENCY, mpLINE_STRIP_ADJACENCY, mpTRIANGLES_ADJACENCY, mpTRIANGLE_STRIP_ADJACENCY, mpPATCHES };

typedef System::Set<TgxMeshPrimitive, TgxMeshPrimitive::mpNOPRIMITIVE, TgxMeshPrimitive::mpPATCHES> TgxMeshPrimitives;

enum DECLSPEC_DENUM TgxState : unsigned char { stAlphaTest, stAutoNormal, stBlend, stColorMaterial, stCullFace, stDepthTest, stDither, stFog, stLighting, stLineSmooth, stLineStipple, stIndexLogicOp, stColorLogicOp, stNormalize, stPointSmooth, stPointSprite, stPolygonSmooth, stPolygonStipple, stScissorTest, stStencilTest, stPolygonOffsetPoint, stPolygonOffsetLine, stPolygonOffsetFill, stDepthClamp };

typedef System::Set<TgxState, TgxState::stAlphaTest, TgxState::stDepthClamp> TgxStates;

enum DECLSPEC_DENUM TgxComparisonFunction : unsigned char { cfNever, cfAlways, cfLess, cfLEqual, cfEqual, cfGreater, cfNotEqual, cfGEqual };

typedef TgxComparisonFunction TgxStencilFunction;

typedef TgxComparisonFunction TgxDepthFunction;

enum DECLSPEC_DENUM TgxBlendFunction : unsigned char { bfZero, bfOne, bfSrcColor, bfOneMinusSrcColor, bfDstColor, bfOneMinusDstColor, bfSrcAlpha, bfOneMinusSrcAlpha, bfDstAlpha, bfOneMinusDstAlpha, bfConstantColor, bfOneMinusConstantColor, bfConstantAlpha, bfOneMinusConstantAlpha, bfSrcAlphaSat };

typedef TgxBlendFunction TgxDstBlendFunction;

enum DECLSPEC_DENUM TgxBlendEquation : unsigned char { beAdd, beSubtract, beReverseSubtract, beMin, beMax };

enum DECLSPEC_DENUM TgxStencilOp : unsigned char { soKeep, soZero, soReplace, soIncr, soDecr, soInvert, soIncrWrap, soDecrWrap };

enum DECLSPEC_DENUM TgxLogicOp : unsigned char { loClear, loAnd, loAndReverse, loCopy, loAndInverted, loNoOp, loXOr, loOr, loNor, loEquiv, loInvert, loOrReverse, loCopyInverted, loOrInverted, loNAnd, loSet };

enum DECLSPEC_DENUM TgxQueryType : unsigned char { qrySamplesPassed, qryPrimitivesGenerated, qryTransformFeedbackPrimitivesWritten, qryTimeElapsed, qryAnySamplesPassed };

enum DECLSPEC_DENUM TgxFaceWinding : unsigned char { fwCounterClockWise, fwClockWise };

enum DECLSPEC_DENUM TgxPolygonMode : unsigned char { pmFill, pmLines, pmPoints };

enum DECLSPEC_DENUM TgxCullFaceMode : unsigned char { cmFront, cmBack, cmFrontAndBack };

enum DECLSPEC_DENUM TgxColorComponent : unsigned char { ccRed, ccGreen, ccBlue, ccAlpha };

typedef System::Set<TgxColorComponent, TgxColorComponent::ccRed, TgxColorComponent::ccAlpha> TgxColorMask;

enum DECLSPEC_DENUM TgxHintType : unsigned char { hintDontCare, hintFastest, hintNicest };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxLightSourceState
{
public:
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> Position;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> Ambient;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> Diffuse;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> Specular;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> SpotDirection;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> SpotCosCutoffExponent;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> Attenuation;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxShaderLightSourceState
{
public:
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> Position;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> Ambient;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> Diffuse;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> Specular;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> SpotDirection;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> SpotCosCutoffExponent;
	System::StaticArray<Stage::Vectortypes::TVector4f, 8> Attenuation;
};
#pragma pack(pop)


typedef void __fastcall (*TgxOnLightsChanged)(System::TObject* Sender);

enum DECLSPEC_DENUM TgxBufferBindingTarget : unsigned char { bbtUniform, bbtTransformFeedBack };

struct DECLSPEC_DRECORD TUBOStates
{
public:
	unsigned FUniformBufferBinding;
	int *FOffset;
	Winapi::Opengl::PGLSizei FSize;
};


enum DECLSPEC_DENUM TgxMaterialLevel : unsigned char { mlAuto, mlFixedFunction, mlMultitexturing, mlSM3, mlSM4, mlSM5 };

class PASCALIMPLEMENTATION TgxStateCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TgxStateTypes> _TgxStateCache__1;
	
	
private:
	System::StaticArray<System::StaticArray<Stage::Vectortypes::TVector4f, 4>, 2> FFrontBackColors;
	System::StaticArray<int, 2> FFrontBackShininess;
	TgxComparisonFunction FAlphaFunc;
	float FAlphaRef;
	TgxPolygonMode FPolygonBackMode;
	unsigned FMaxLights;
	System::StaticArray<bool, 16> FLightEnabling;
	System::StaticArray<int, 16> FLightIndices;
	int FLightNumber;
	TgxLightSourceState FLightStates;
	System::StaticArray<float, 16> FSpotCutoff;
	TgxShaderLightSourceState FShaderLightStates;
	bool FShaderLightStatesChanged;
	bool FColorWriting;
	TgxStates FStates;
	_TgxStateCache__1 FListStates;
	unsigned FCurrentList;
	System::StaticArray<bool, 4> FTextureMatrixIsIdentity;
	bool FForwardContext;
	bool FFFPLight;
	unsigned FVertexArrayBinding;
	unsigned FArrayBufferBinding;
	unsigned FElementBufferBinding;
	unsigned FTextureBufferBinding;
	System::Byte FEnablePrimitiveRestart;
	unsigned FPrimitiveRestartIndex;
	Stage::Vectortypes::TVector4i FViewPort;
	System::StaticArray<double, 2> FDepthRange;
	System::StaticArray<System::Byte, 8> FEnableClipDistance;
	System::Byte FEnableDepthClamp;
	unsigned FClampReadColor;
	unsigned FProvokingVertex;
	float FPointSize;
	float FPointFadeThresholdSize;
	unsigned FPointSpriteCoordOrigin;
	float FLineWidth;
	int FLineStippleFactor;
	System::Word FLineStipplePattern;
	System::Byte FEnableLineSmooth;
	System::Byte FEnableCullFace;
	TgxCullFaceMode FCullFaceMode;
	TgxFaceWinding FFrontFace;
	System::Byte FEnablePolygonSmooth;
	TgxPolygonMode FPolygonMode;
	float FPolygonOffsetFactor;
	float FPolygonOffsetUnits;
	System::Byte FEnablePolygonOffsetPoint;
	System::Byte FEnablePolygonOffsetLine;
	System::Byte FEnablePolygonOffsetFill;
	System::Byte FEnableMultisample;
	System::Byte FEnableSampleAlphaToCoverage;
	System::Byte FEnableSampleAlphaToOne;
	System::Byte FEnableSampleCoverage;
	float FSampleCoverageValue;
	System::Byte FSampleCoverageInvert;
	System::Byte FEnableSampleMask;
	System::StaticArray<unsigned, 16> FSampleMaskValue;
	unsigned FMaxTextureSize;
	unsigned FMax3DTextureSize;
	unsigned FMaxCubeTextureSize;
	unsigned FMaxArrayTextureSize;
	unsigned FMaxTextureImageUnits;
	unsigned FMaxTextureAnisotropy;
	unsigned FMaxSamples;
	System::StaticArray<System::StaticArray<unsigned, 12>, 48> FTextureBinding;
	System::StaticArray<System::StaticArray<double, 12>, 48> FTextureBindingTime;
	System::StaticArray<unsigned, 48> FSamplerBinding;
	int FActiveTexture;
	System::StaticArray<System::StaticArray<bool, 12>, 48> FActiveTextureEnabling;
	System::Byte FEnableScissorTest;
	Stage::Vectortypes::TVector4i FScissorBox;
	System::Byte FEnableStencilTest;
	TgxStencilFunction FStencilFunc;
	unsigned FStencilValueMask;
	int FStencilRef;
	TgxStencilOp FStencilFail;
	TgxStencilOp FStencilPassDepthFail;
	TgxStencilOp FStencilPassDepthPass;
	TgxStencilFunction FStencilBackFunc;
	unsigned FStencilBackValueMask;
	unsigned FStencilBackRef;
	TgxStencilOp FStencilBackFail;
	TgxStencilOp FStencilBackPassDepthPass;
	TgxStencilOp FStencilBackPassDepthFail;
	System::Byte FEnableDepthTest;
	TgxDepthFunction FDepthFunc;
	System::StaticArray<System::Byte, 16> FEnableBlend;
	TgxBlendFunction FBlendSrcRGB;
	TgxBlendFunction FBlendSrcAlpha;
	TgxDstBlendFunction FBlendDstRGB;
	TgxDstBlendFunction FBlendDstAlpha;
	TgxBlendEquation FBlendEquationRGB;
	TgxBlendEquation FBlendEquationAlpha;
	Stage::Vectortypes::TVector4f FBlendColor;
	System::Byte FEnableFramebufferSRGB;
	System::Byte FEnableDither;
	System::Byte FEnableColorLogicOp;
	TgxLogicOp FLogicOpMode;
	System::StaticArray<TgxColorMask, 16> FColorWriteMask;
	bool FDepthWriteMask;
	unsigned FStencilWriteMask;
	unsigned FStencilBackWriteMask;
	Stage::Vectortypes::TVector4f FColorClearValue;
	float FDepthClearValue;
	unsigned FStencilClearValue;
	unsigned FDrawFrameBuffer;
	unsigned FReadFrameBuffer;
	unsigned FRenderBuffer;
	System::Byte FUnpackSwapBytes;
	System::Byte FUnpackLSBFirst;
	unsigned FUnpackImageHeight;
	unsigned FUnpackSkipImages;
	unsigned FUnpackRowLength;
	unsigned FUnpackSkipRows;
	unsigned FUnpackSkipPixels;
	unsigned FUnpackAlignment;
	System::Byte FPackSwapBytes;
	System::Byte FPackLSBFirst;
	unsigned FPackImageHeight;
	unsigned FPackSkipImages;
	unsigned FPackRowLength;
	unsigned FPackSkipRows;
	unsigned FPackSkipPixels;
	unsigned FPackAlignment;
	unsigned FPixelPackBufferBinding;
	unsigned FPixelUnpackBufferBinding;
	unsigned FCurrentProgram;
	unsigned FMaxTextureUnits;
	unsigned FUniformBufferBinding;
	System::StaticArray<System::StaticArray<TUBOStates, 75>, 2> FUBOStates;
	System::StaticArray<Stage::Vectortypes::TVector4f, 16> FCurrentVertexAttrib;
	System::Byte FEnableProgramPointSize;
	unsigned FTransformFeedbackBufferBinding;
	TgxHintType FTextureCompressionHint;
	TgxHintType FPolygonSmoothHint;
	TgxHintType FFragmentShaderDerivitiveHint;
	TgxHintType FLineSmoothHint;
	TgxHintType FMultisampleFilterHint;
	System::StaticArray<unsigned, 5> FCurrentQuery;
	unsigned FCopyReadBufferBinding;
	unsigned FCopyWriteBufferBinding;
	System::Byte FEnableTextureCubeMapSeamless;
	bool FInsideList;
	TgxOnLightsChanged FOnLightsChanged;
	
protected:
	void __fastcall SetVertexArrayBinding(const unsigned Value);
	unsigned __fastcall GetArrayBufferBinding();
	void __fastcall SetArrayBufferBinding(const unsigned Value);
	unsigned __fastcall GetElementBufferBinding();
	void __fastcall SetElementBufferBinding(const unsigned Value);
	System::Byte __fastcall GetEnablePrimitiveRestart();
	unsigned __fastcall GetPrimitiveRestartIndex();
	void __fastcall SetEnablePrimitiveRestart(const System::Byte enabled);
	void __fastcall SetPrimitiveRestartIndex(const unsigned index);
	void __fastcall SetTextureBufferBinding(const unsigned Value);
	void __fastcall SetViewPort(const Stage::Vectortypes::TVector4i &Value);
	System::Byte __fastcall GetEnableClipDistance(unsigned ClipDistance);
	void __fastcall SetEnableClipDistance(unsigned Index, const System::Byte Value);
	double __fastcall GetDepthRangeFar();
	void __fastcall SetDepthRangeFar(const double Value);
	double __fastcall GetDepthRangeNear();
	void __fastcall SetDepthRangeNear(const double Value);
	void __fastcall SetEnableDepthClamp(const System::Byte enabled);
	void __fastcall SetClampReadColor(const unsigned Value);
	void __fastcall SetProvokingVertex(const unsigned Value);
	void __fastcall SetPointSize(const float Value);
	void __fastcall SetPointFadeThresholdSize(const float Value);
	void __fastcall SetPointSpriteCoordOrigin(const unsigned Value);
	void __fastcall SetLineWidth(const float Value);
	void __fastcall SetLineStippleFactor(const int Value);
	void __fastcall SetLineStipplePattern(const System::Word Value);
	void __fastcall SetEnableLineSmooth(const System::Byte Value);
	void __fastcall SetEnableCullFace(const System::Byte Value);
	void __fastcall SetCullFaceMode(const TgxCullFaceMode Value);
	void __fastcall SetFrontFace(const TgxFaceWinding Value);
	void __fastcall SetEnablePolygonSmooth(const System::Byte Value);
	void __fastcall SetPolygonMode(const TgxPolygonMode Value);
	void __fastcall SetPolygonOffsetFactor(const float Value);
	void __fastcall SetPolygonOffsetUnits(const float Value);
	void __fastcall SetEnablePolygonOffsetPoint(const System::Byte Value);
	void __fastcall SetEnablePolygonOffsetLine(const System::Byte Value);
	void __fastcall SetEnablePolygonOffsetFill(const System::Byte Value);
	void __fastcall SetEnableMultisample(const System::Byte Value);
	void __fastcall SetEnableSampleAlphaToCoverage(const System::Byte Value);
	void __fastcall SetEnableSampleAlphaToOne(const System::Byte Value);
	void __fastcall SetEnableSampleCoverage(const System::Byte Value);
	void __fastcall SetSampleCoverageValue(const float Value);
	void __fastcall SetSampleCoverageInvert(const System::Byte Value);
	void __fastcall SetEnableSampleMask(const System::Byte Value);
	unsigned __fastcall GetSampleMaskValue(int Index);
	void __fastcall SetSampleMaskValue(int Index, const unsigned Value);
	unsigned __fastcall GetMaxTextureSize();
	unsigned __fastcall GetMax3DTextureSize();
	unsigned __fastcall GetMaxCubeTextureSize();
	unsigned __fastcall GetMaxArrayTextureSize();
	unsigned __fastcall GetMaxTextureImageUnits();
	unsigned __fastcall GetMaxTextureAnisotropy();
	unsigned __fastcall GetMaxSamples();
	unsigned __fastcall GetTextureBinding(int Index, Stage::Textureformat::TglTextureTarget target);
	double __fastcall GetTextureBindingTime(int Index, Stage::Textureformat::TglTextureTarget target);
	void __fastcall SetTextureBinding(int Index, Stage::Textureformat::TglTextureTarget target, const unsigned Value);
	bool __fastcall GetActiveTextureEnabled(Stage::Textureformat::TglTextureTarget Target);
	void __fastcall SetActiveTextureEnabled(Stage::Textureformat::TglTextureTarget Target, const bool Value);
	unsigned __fastcall GetSamplerBinding(unsigned Index);
	void __fastcall SetSamplerBinding(unsigned Index, const unsigned Value);
	void __fastcall SetActiveTexture(const int Value);
	void __fastcall SetEnableScissorTest(const System::Byte Value);
	void __fastcall SetScissorBox(const Stage::Vectortypes::TVector4i &Value);
	void __fastcall SetEnableStencilTest(const System::Byte Value);
	void __fastcall SetEnableDepthTest(const System::Byte Value);
	void __fastcall SetDepthFunc(const TgxDepthFunction Value);
	System::Byte __fastcall GetEnableBlend(int Index);
	void __fastcall SetEnableBlend(int Index, const System::Byte Value);
	void __fastcall SetBlendColor(const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetEnableFramebufferSRGB(const System::Byte Value);
	void __fastcall SetEnableDither(const System::Byte Value);
	void __fastcall SetEnableColorLogicOp(const System::Byte Value);
	void __fastcall SetLogicOpMode(const TgxLogicOp Value);
	TgxColorMask __fastcall GetColorWriteMask(int Index);
	void __fastcall SetColorWriteMask(int Index, const TgxColorMask Value);
	void __fastcall SetDepthWriteMask(const bool Value);
	void __fastcall SetStencilWriteMask(const unsigned Value);
	void __fastcall SetStencilBackWriteMask(const unsigned Value);
	void __fastcall SetColorClearValue(const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetDepthClearValue(const float Value);
	void __fastcall SetStencilClearValue(const unsigned Value);
	void __fastcall SetDrawFrameBuffer(const unsigned Value);
	void __fastcall SetReadFrameBuffer(const unsigned Value);
	void __fastcall SetRenderBuffer(const unsigned Value);
	void __fastcall SetUnpackSwapBytes(const System::Byte Value);
	void __fastcall SetUnpackLSBFirst(const System::Byte Value);
	void __fastcall SetUnpackImageHeight(const unsigned Value);
	void __fastcall SetUnpackSkipImages(const unsigned Value);
	void __fastcall SetUnpackRowLength(const unsigned Value);
	void __fastcall SetUnpackSkipRows(const unsigned Value);
	void __fastcall SetUnpackSkipPixels(const unsigned Value);
	void __fastcall SetUnpackAlignment(const unsigned Value);
	void __fastcall SetPackSwapBytes(const System::Byte Value);
	void __fastcall SetPackLSBFirst(const System::Byte Value);
	void __fastcall SetPackImageHeight(const unsigned Value);
	void __fastcall SetPackSkipImages(const unsigned Value);
	void __fastcall SetPackRowLength(const unsigned Value);
	void __fastcall SetPackSkipRows(const unsigned Value);
	void __fastcall SetPackSkipPixels(const unsigned Value);
	void __fastcall SetPackAlignment(const unsigned Value);
	void __fastcall SetPixelPackBufferBinding(const unsigned Value);
	void __fastcall SetPixelUnpackBufferBinding(const unsigned Value);
	void __fastcall SetCurrentProgram(const unsigned Value);
	void __fastcall SetUniformBufferBinding(const unsigned Value);
	unsigned __fastcall GetMaxTextureUnits();
	Stage::Vectortypes::TVector4f __fastcall GetCurrentVertexAttrib(int Index);
	void __fastcall SetCurrentVertexAttrib(int Index, const Stage::Vectortypes::TVector4f &Value);
	void __fastcall SetEnableProgramPointSize(const System::Byte Value);
	void __fastcall SetTransformFeedbackBufferBinding(const unsigned Value);
	void __fastcall SetLineSmoothHint(const TgxHintType Value);
	void __fastcall SetPolygonSmoothHint(const TgxHintType Value);
	void __fastcall SetTextureCompressionHint(const TgxHintType Value);
	void __fastcall SetFragmentShaderDerivitiveHint(const TgxHintType Value);
	void __fastcall SetMultisampleFilterHint(const TgxHintType Value);
	unsigned __fastcall GetCurrentQuery(TgxQueryType Index);
	void __fastcall SetCopyReadBufferBinding(const unsigned Value);
	void __fastcall SetCopyWriteBufferBinding(const unsigned Value);
	void __fastcall SetEnableTextureCubeMapSeamless(const System::Byte Value);
	void __fastcall SetFFPLight(bool Value);
	int __fastcall GetMaxLights();
	bool __fastcall GetLightEnabling(int I);
	void __fastcall SetLightEnabling(int I, bool Value);
	Stage::Vectortypes::TVector4f __fastcall GetLightPosition(int I);
	void __fastcall SetLightPosition(int I, const Stage::Vectortypes::TVector4f &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetLightSpotDirection(int I);
	void __fastcall SetLightSpotDirection(int I, const Stage::Vectorgeometry::TAffineVector &Value);
	Stage::Vectortypes::TVector4f __fastcall GetLightAmbient(int I);
	void __fastcall SetLightAmbient(int I, const Stage::Vectortypes::TVector4f &Value);
	Stage::Vectortypes::TVector4f __fastcall GetLightDiffuse(int I);
	void __fastcall SetLightDiffuse(int I, const Stage::Vectortypes::TVector4f &Value);
	Stage::Vectortypes::TVector4f __fastcall GetLightSpecular(int I);
	void __fastcall SetLightSpecular(int I, const Stage::Vectortypes::TVector4f &Value);
	float __fastcall GetSpotCutoff(int I);
	void __fastcall SetSpotCutoff(int I, const float Value);
	float __fastcall GetSpotExponent(int I);
	void __fastcall SetSpotExponent(int I, const float Value);
	float __fastcall GetConstantAtten(int I);
	void __fastcall SetConstantAtten(int I, const float Value);
	float __fastcall GetLinearAtten(int I);
	void __fastcall SetLinearAtten(int I, const float Value);
	float __fastcall GetQuadAtten(int I);
	void __fastcall SetQuadAtten(int I, const float Value);
	void __fastcall SetForwardContext(bool Value);
	Stage::Vectortypes::TVector4f __fastcall GetMaterialAmbient(const TgxCullFaceMode aFace);
	Stage::Vectortypes::TVector4f __fastcall GetMaterialDiffuse(const TgxCullFaceMode aFace);
	Stage::Vectortypes::TVector4f __fastcall GetMaterialSpecular(const TgxCullFaceMode aFace);
	Stage::Vectortypes::TVector4f __fastcall GetMaterialEmission(const TgxCullFaceMode aFace);
	int __fastcall GetMaterialShininess(const TgxCullFaceMode aFace);
	
public:
	__fastcall virtual TgxStateCache();
	__fastcall virtual ~TgxStateCache();
	void __fastcall PushAttrib(TgxStateTypes stateTypes);
	void __fastcall PopAttrib();
	void __fastcall Enable(const TgxState aState);
	void __fastcall Disable(const TgxState aState);
	void __fastcall PerformEnable(const TgxState aState);
	void __fastcall PerformDisable(const TgxState aState);
	void __fastcall SetVxState _DEPRECATED_ATTRIBUTE0 (const TgxState aState);
	void __fastcall UnSetVxState _DEPRECATED_ATTRIBUTE0 (const TgxState aState);
	void __fastcall ResetPolygonMode _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetMaterialColors _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetTexture _DEPRECATED_ATTRIBUTE0 (const int TextureUnit);
	void __fastcall ResetCurrentTexture _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetFrontFace _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall SetGLFrontFaceCW _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetAll _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall SetMaterialColors(const TgxCullFaceMode aFace, const Stage::Vectortypes::TVector4f &emission, const Stage::Vectortypes::TVector4f &ambient, const Stage::Vectortypes::TVector4f &diffuse, const Stage::Vectortypes::TVector4f &specular, const int shininess);
	__property Stage::Vectortypes::TVector4f MaterialAmbient[const TgxCullFaceMode aFace] = {read=GetMaterialAmbient};
	__property Stage::Vectortypes::TVector4f MaterialDiffuse[const TgxCullFaceMode aFace] = {read=GetMaterialDiffuse};
	__property Stage::Vectortypes::TVector4f MaterialSpecular[const TgxCullFaceMode aFace] = {read=GetMaterialSpecular};
	__property Stage::Vectortypes::TVector4f MaterialEmission[const TgxCullFaceMode aFace] = {read=GetMaterialEmission};
	__property int MaterialShininess[const TgxCullFaceMode aFace] = {read=GetMaterialShininess};
	void __fastcall SetMaterialAlphaChannel(const unsigned aFace, const float alpha);
	void __fastcall SetMaterialDiffuseColor(const unsigned aFace, const Stage::Vectortypes::TVector4f &diffuse);
	__property bool FixedFunctionPipeLight = {read=FFFPLight, write=SetFFPLight, nodefault};
	__property int MaxLights = {read=GetMaxLights, nodefault};
	__property bool LightEnabling[int Index] = {read=GetLightEnabling, write=SetLightEnabling};
	__property Stage::Vectortypes::TVector4f LightPosition[int Index] = {read=GetLightPosition, write=SetLightPosition};
	__property Stage::Vectorgeometry::TAffineVector LightSpotDirection[int Index] = {read=GetLightSpotDirection, write=SetLightSpotDirection};
	__property Stage::Vectortypes::TVector4f LightAmbient[int Index] = {read=GetLightAmbient, write=SetLightAmbient};
	__property Stage::Vectortypes::TVector4f LightDiffuse[int Index] = {read=GetLightDiffuse, write=SetLightDiffuse};
	__property Stage::Vectortypes::TVector4f LightSpecular[int Index] = {read=GetLightSpecular, write=SetLightSpecular};
	__property float LightSpotCutoff[int Index] = {read=GetSpotCutoff, write=SetSpotCutoff};
	__property float LightSpotExponent[int Index] = {read=GetSpotExponent, write=SetSpotExponent};
	__property float LightConstantAtten[int Index] = {read=GetConstantAtten, write=SetConstantAtten};
	__property float LightLinearAtten[int Index] = {read=GetLinearAtten, write=SetLinearAtten};
	__property float LightQuadraticAtten[int Index] = {read=GetQuadAtten, write=SetQuadAtten};
	Winapi::Opengl::PGLInt __fastcall GetLightIndicesAsAddress();
	void * __fastcall GetLightStateAsAddress();
	__property int LightNumber = {read=FLightNumber, nodefault};
	__property TgxOnLightsChanged OnLightsChanged = {read=FOnLightsChanged, write=FOnLightsChanged};
	void __fastcall SetAlphaFunction(TgxComparisonFunction func, float ref);
	__property unsigned VertexArrayBinding = {read=FVertexArrayBinding, write=SetVertexArrayBinding, nodefault};
	__property unsigned ArrayBufferBinding = {read=GetArrayBufferBinding, write=SetArrayBufferBinding, nodefault};
	__property unsigned ElementBufferBinding = {read=GetElementBufferBinding, write=SetElementBufferBinding, nodefault};
	__property System::Byte EnablePrimitiveRestart = {read=GetEnablePrimitiveRestart, write=SetEnablePrimitiveRestart, nodefault};
	__property unsigned PrimitiveRestartIndex = {read=GetPrimitiveRestartIndex, write=SetPrimitiveRestartIndex, nodefault};
	__property unsigned TextureBufferBinding = {read=FTextureBufferBinding, write=SetTextureBufferBinding, nodefault};
	__property Stage::Vectortypes::TVector4i ViewPort = {read=FViewPort, write=SetViewPort};
	void __fastcall SetDepthRange(const double ZNear, const double ZFar);
	__property double DepthRangeNear = {read=GetDepthRangeNear, write=SetDepthRangeNear};
	__property double DepthRangeFar = {read=GetDepthRangeFar, write=SetDepthRangeFar};
	__property System::Byte EnableClipDistance[unsigned Index] = {read=GetEnableClipDistance, write=SetEnableClipDistance};
	__property System::Byte EnableDepthClamp = {read=FEnableDepthClamp, write=SetEnableDepthClamp, nodefault};
	__property unsigned ClampReadColor = {read=FClampReadColor, write=SetClampReadColor, nodefault};
	__property unsigned ProvokingVertex = {read=FProvokingVertex, write=SetProvokingVertex, nodefault};
	__property float PointSize = {read=FPointSize, write=SetPointSize};
	__property float PointFadeThresholdSize = {read=FPointFadeThresholdSize, write=SetPointFadeThresholdSize};
	__property unsigned PointSpriteCoordOrigin = {read=FPointSpriteCoordOrigin, write=SetPointSpriteCoordOrigin, nodefault};
	__property float LineWidth = {read=FLineWidth, write=SetLineWidth};
	__property int LineStippleFactor = {read=FLineStippleFactor, write=SetLineStippleFactor, nodefault};
	__property System::Word LineStipplePattern = {read=FLineStipplePattern, write=SetLineStipplePattern, nodefault};
	__property System::Byte EnableLineSmooth = {read=FEnableLineSmooth, write=SetEnableLineSmooth, nodefault};
	__property System::Byte EnableCullFace = {read=FEnableCullFace, write=SetEnableCullFace, nodefault};
	__property TgxCullFaceMode CullFaceMode = {read=FCullFaceMode, write=SetCullFaceMode, nodefault};
	__property TgxFaceWinding FrontFace = {read=FFrontFace, write=SetFrontFace, nodefault};
	__property System::Byte EnablePolygonSmooth = {read=FEnablePolygonSmooth, write=SetEnablePolygonSmooth, nodefault};
	__property TgxPolygonMode PolygonMode = {read=FPolygonMode, write=SetPolygonMode, nodefault};
	__property float PolygonOffsetFactor = {read=FPolygonOffsetFactor, write=SetPolygonOffsetFactor};
	__property float PolygonOffsetUnits = {read=FPolygonOffsetUnits, write=SetPolygonOffsetUnits};
	void __fastcall SetPolygonOffset(const float factor, const float units);
	__property System::Byte EnablePolygonOffsetPoint = {read=FEnablePolygonOffsetPoint, write=SetEnablePolygonOffsetPoint, nodefault};
	__property System::Byte EnablePolygonOffsetLine = {read=FEnablePolygonOffsetLine, write=SetEnablePolygonOffsetLine, nodefault};
	__property System::Byte EnablePolygonOffsetFill = {read=FEnablePolygonOffsetFill, write=SetEnablePolygonOffsetFill, nodefault};
	__property System::Byte EnableMultisample = {read=FEnableMultisample, write=SetEnableMultisample, nodefault};
	__property System::Byte EnableSampleAlphaToCoverage = {read=FEnableSampleAlphaToCoverage, write=SetEnableSampleAlphaToCoverage, nodefault};
	__property System::Byte EnableSampleAlphaToOne = {read=FEnableSampleAlphaToOne, write=SetEnableSampleAlphaToOne, nodefault};
	__property System::Byte EnableSampleCoverage = {read=FEnableSampleCoverage, write=SetEnableSampleCoverage, nodefault};
	__property float SampleCoverageValue = {read=FSampleCoverageValue, write=SetSampleCoverageValue};
	__property System::Byte SampleCoverageInvert = {read=FSampleCoverageInvert, write=SetSampleCoverageInvert, nodefault};
	void __fastcall SetSampleCoverage(const float Value, System::Byte invert);
	__property System::Byte EnableSampleMask = {read=FEnableSampleMask, write=SetEnableSampleMask, nodefault};
	__property unsigned SampleMaskValue[int Index] = {read=GetSampleMaskValue, write=SetSampleMaskValue};
	__property unsigned TextureBinding[int Index][Stage::Textureformat::TglTextureTarget target] = {read=GetTextureBinding, write=SetTextureBinding};
	__property double TextureBindingTime[int Index][Stage::Textureformat::TglTextureTarget target] = {read=GetTextureBindingTime};
	__property bool ActiveTextureEnabled[Stage::Textureformat::TglTextureTarget Target] = {read=GetActiveTextureEnabled, write=SetActiveTextureEnabled};
	__property unsigned SamplerBinding[unsigned Index] = {read=GetSamplerBinding, write=SetSamplerBinding};
	__property unsigned MaxTextureSize = {read=GetMaxTextureSize, nodefault};
	__property unsigned Max3DTextureSize = {read=GetMax3DTextureSize, nodefault};
	__property unsigned MaxCubeTextureSize = {read=GetMaxCubeTextureSize, nodefault};
	__property unsigned MaxArrayTextureSize = {read=GetMaxArrayTextureSize, nodefault};
	__property unsigned MaxTextureImageUnits = {read=GetMaxTextureImageUnits, nodefault};
	__property unsigned MaxTextureAnisotropy = {read=GetMaxTextureAnisotropy, nodefault};
	__property unsigned MaxSamples = {read=GetMaxSamples, nodefault};
	__property int ActiveTexture = {read=FActiveTexture, write=SetActiveTexture, nodefault};
	__property System::Byte EnableScissorTest = {read=FEnableScissorTest, write=SetEnableScissorTest, nodefault};
	__property Stage::Vectortypes::TVector4i ScissorBox = {read=FScissorBox, write=SetScissorBox};
	__property System::Byte EnableStencilTest = {read=FEnableStencilTest, write=SetEnableStencilTest, nodefault};
	__property TgxStencilFunction StencilFunc = {read=FStencilFunc, nodefault};
	__property unsigned StencilValueMask = {read=FStencilValueMask, nodefault};
	__property int StencilRef = {read=FStencilRef, nodefault};
	__property TgxStencilOp StencilFail = {read=FStencilFail, nodefault};
	__property TgxStencilOp StencilPassDepthFail = {read=FStencilPassDepthFail, nodefault};
	__property TgxStencilOp StencilPassDepthPass = {read=FStencilPassDepthPass, nodefault};
	__property TgxStencilFunction StencilBackFunc = {read=FStencilBackFunc, nodefault};
	__property unsigned StencilBackValueMask = {read=FStencilBackValueMask, nodefault};
	__property unsigned StencilBackRef = {read=FStencilBackRef, nodefault};
	__property TgxStencilOp StencilBackFail = {read=FStencilBackFail, nodefault};
	__property TgxStencilOp StencilBackPassDepthFail = {read=FStencilBackPassDepthFail, nodefault};
	__property TgxStencilOp StencilBackPassDepthPass = {read=FStencilBackPassDepthPass, nodefault};
	void __fastcall SetStencilFunc(const TgxStencilFunction func, const int ref, const unsigned mask);
	void __fastcall SetStencilFuncSeparate(const TgxCullFaceMode face, const TgxStencilFunction func, const int ref, const unsigned mask);
	void __fastcall SetStencilOp(const TgxStencilOp fail, const TgxStencilOp zfail, const TgxStencilOp zpass);
	void __fastcall SetStencilOpSeparate(const TgxCullFaceMode face, const TgxStencilOp sfail, const TgxStencilOp dpfail, const TgxStencilOp dppass);
	__property System::Byte EnableDepthTest = {read=FEnableDepthTest, write=SetEnableDepthTest, nodefault};
	__property TgxDepthFunction DepthFunc = {read=FDepthFunc, write=SetDepthFunc, nodefault};
	__property System::Byte EnableBlend[int Index] = {read=GetEnableBlend, write=SetEnableBlend};
	__property TgxBlendFunction BlendSrcRGB = {read=FBlendSrcRGB, nodefault};
	__property TgxBlendFunction BlendSrcAlpha = {read=FBlendSrcAlpha, nodefault};
	__property TgxDstBlendFunction BlendDstRGB = {read=FBlendDstRGB, nodefault};
	__property TgxDstBlendFunction BlendDstAlpha = {read=FBlendDstAlpha, nodefault};
	void __fastcall SetBlendFunc(const TgxBlendFunction Src, const TgxDstBlendFunction Dst);
	void __fastcall SetBlendFuncSeparate(const TgxBlendFunction SrcRGB, const TgxDstBlendFunction DstRGB, const TgxBlendFunction SrcAlpha, const TgxDstBlendFunction DstAlpha);
	__property TgxBlendEquation BlendEquationRGB = {read=FBlendEquationRGB, nodefault};
	__property TgxBlendEquation BlendEquationAlpha = {read=FBlendEquationAlpha, nodefault};
	void __fastcall SetBlendEquation(const TgxBlendEquation mode);
	void __fastcall SetBlendEquationSeparate(const TgxBlendEquation modeRGB, const TgxBlendEquation modeAlpha);
	__property Stage::Vectortypes::TVector4f BlendColor = {read=FBlendColor, write=SetBlendColor};
	__property System::Byte EnableFramebufferSRGB = {read=FEnableFramebufferSRGB, write=SetEnableFramebufferSRGB, nodefault};
	__property System::Byte EnableDither = {read=FEnableDither, write=SetEnableDither, nodefault};
	__property System::Byte EnableColorLogicOp = {read=FEnableColorLogicOp, write=SetEnableColorLogicOp, nodefault};
	__property TgxLogicOp LogicOpMode = {read=FLogicOpMode, write=SetLogicOpMode, nodefault};
	__property TgxColorMask ColorWriteMask[int Index] = {read=GetColorWriteMask, write=SetColorWriteMask};
	void __fastcall SetColorMask(TgxColorMask mask);
	__property bool DepthWriteMask = {read=FDepthWriteMask, write=SetDepthWriteMask, nodefault};
	__property unsigned StencilWriteMask = {read=FStencilWriteMask, write=SetStencilWriteMask, nodefault};
	__property unsigned StencilBackWriteMask = {read=FStencilBackWriteMask, write=SetStencilBackWriteMask, nodefault};
	__property Stage::Vectortypes::TVector4f ColorClearValue = {read=FColorClearValue, write=SetColorClearValue};
	__property float DepthClearValue = {read=FDepthClearValue, write=SetDepthClearValue};
	__property unsigned StencilClearValue = {read=FStencilClearValue, write=SetStencilClearValue, nodefault};
	__property unsigned DrawFrameBuffer = {read=FDrawFrameBuffer, write=SetDrawFrameBuffer, nodefault};
	__property unsigned ReadFrameBuffer = {read=FReadFrameBuffer, write=SetReadFrameBuffer, nodefault};
	void __fastcall SetFrameBuffer(const unsigned Value);
	__property unsigned RenderBuffer = {read=FRenderBuffer, write=SetRenderBuffer, nodefault};
	__property System::Byte UnpackSwapBytes = {read=FUnpackSwapBytes, write=SetUnpackSwapBytes, nodefault};
	__property System::Byte UnpackLSBFirst = {read=FUnpackLSBFirst, write=SetUnpackLSBFirst, nodefault};
	__property unsigned UnpackImageHeight = {read=FUnpackImageHeight, write=SetUnpackImageHeight, nodefault};
	__property unsigned UnpackSkipImages = {read=FUnpackSkipImages, write=SetUnpackSkipImages, nodefault};
	__property unsigned UnpackRowLength = {read=FUnpackRowLength, write=SetUnpackRowLength, nodefault};
	__property unsigned UnpackSkipRows = {read=FUnpackSkipRows, write=SetUnpackSkipRows, nodefault};
	__property unsigned UnpackSkipPixels = {read=FUnpackSkipPixels, write=SetUnpackSkipPixels, nodefault};
	__property unsigned UnpackAlignment = {read=FUnpackAlignment, write=SetUnpackAlignment, nodefault};
	__property System::Byte PackSwapBytes = {read=FPackSwapBytes, write=SetPackSwapBytes, nodefault};
	__property System::Byte PackLSBFirst = {read=FPackLSBFirst, write=SetPackLSBFirst, nodefault};
	__property unsigned PackImageHeight = {read=FPackImageHeight, write=SetPackImageHeight, nodefault};
	__property unsigned PackSkipImages = {read=FPackSkipImages, write=SetPackSkipImages, nodefault};
	__property unsigned PackRowLength = {read=FPackRowLength, write=SetPackRowLength, nodefault};
	__property unsigned PackSkipRows = {read=FPackSkipRows, write=SetPackSkipRows, nodefault};
	__property unsigned PackSkipPixels = {read=FPackSkipPixels, write=SetPackSkipPixels, nodefault};
	__property unsigned PackAlignment = {read=FPackAlignment, write=SetPackAlignment, nodefault};
	__property unsigned PixelPackBufferBinding = {read=FPixelPackBufferBinding, write=SetPixelPackBufferBinding, nodefault};
	__property unsigned PixelUnpackBufferBinding = {read=FPixelUnpackBufferBinding, write=SetPixelUnpackBufferBinding, nodefault};
	__property unsigned CurrentProgram = {read=FCurrentProgram, write=SetCurrentProgram, nodefault};
	__property unsigned MaxTextureUnits = {read=GetMaxTextureUnits, nodefault};
	__property unsigned UniformBufferBinding = {read=FUniformBufferBinding, write=SetUniformBufferBinding, nodefault};
	void __fastcall SetBufferIndexedBinding(const unsigned Value, TgxBufferBindingTarget ATarget, unsigned AIndex, Winapi::Opengl::PGLSizei ABufferSize)/* overload */;
	void __fastcall SetBufferIndexedBinding(const unsigned Value, TgxBufferBindingTarget ATarget, unsigned AIndex, int AOffset, Winapi::Opengl::PGLSizei ARangeSize)/* overload */;
	__property Stage::Vectortypes::TVector4f CurrentVertexAttrib[int Index] = {read=GetCurrentVertexAttrib, write=SetCurrentVertexAttrib};
	__property System::Byte EnableProgramPointSize = {read=FEnableProgramPointSize, write=SetEnableProgramPointSize, nodefault};
	__property unsigned TransformFeedbackBufferBinding = {read=FTransformFeedbackBufferBinding, write=SetTransformFeedbackBufferBinding, nodefault};
	__property TgxHintType LineSmoothHint = {read=FLineSmoothHint, write=SetLineSmoothHint, nodefault};
	__property TgxHintType PolygonSmoothHint = {read=FPolygonSmoothHint, write=SetPolygonSmoothHint, nodefault};
	__property TgxHintType TextureCompressionHint = {read=FTextureCompressionHint, write=SetTextureCompressionHint, nodefault};
	__property TgxHintType FragmentShaderDerivitiveHint = {read=FFragmentShaderDerivitiveHint, write=SetFragmentShaderDerivitiveHint, nodefault};
	__property TgxHintType MultisampleFilterHint = {read=FMultisampleFilterHint, write=SetMultisampleFilterHint, nodefault};
	__property unsigned CurrentQuery[TgxQueryType Index] = {read=GetCurrentQuery};
	void __fastcall BeginQuery(const TgxQueryType Target, const unsigned Value);
	void __fastcall EndQuery(const TgxQueryType Target);
	__property unsigned CopyReadBufferBinding = {read=FCopyReadBufferBinding, write=SetCopyReadBufferBinding, nodefault};
	__property unsigned CopyWriteBufferBinding = {read=FCopyWriteBufferBinding, write=SetCopyWriteBufferBinding, nodefault};
	__property System::Byte EnableTextureCubeMapSeamless = {read=FEnableTextureCubeMapSeamless, write=SetEnableTextureCubeMapSeamless, nodefault};
	__property bool InsideList = {read=FInsideList, nodefault};
	void __fastcall NewList(unsigned list, unsigned mode);
	void __fastcall EndList();
	void __fastcall CallList(unsigned list);
	void __fastcall SetTextureMatrix(const Stage::Vectortypes::TMatrix4f &matrix);
	void __fastcall ResetTextureMatrix();
	void __fastcall ResetAllTextureMatrix();
	void __fastcall SetColorWriting(bool flag);
	void __fastcall InvertFrontFace();
	__property TgxStates States = {read=FStates, nodefault};
	__property bool ForwardContext = {read=FForwardContext, write=SetForwardContext, nodefault};
};


struct DECLSPEC_DRECORD TgxStateRecord
{
public:
	unsigned GLConst;
	unsigned VKConst;
	bool IsDeprecated;
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 VERTEX_ATTR_NUM = System::Int8(0x10);
#define cAllAttribBits (System::Set<TgxStateType, TgxStateType::sttCurrent, TgxStateType::sttMultisample>() << TgxStateType::sttCurrent << TgxStateType::sttPoint << TgxStateType::sttLine << TgxStateType::sttPolygon << TgxStateType::sttPolygonStipple << TgxStateType::sttPixelMode << TgxStateType::sttLighting << TgxStateType::sttFog << TgxStateType::sttDepthBuffer << TgxStateType::sttAccumBuffer << TgxStateType::sttStencilBuffer << TgxStateType::sttViewport << TgxStateType::sttTransform << TgxStateType::sttEnable << TgxStateType::sttColorBuffer << TgxStateType::sttHint << TgxStateType::sttEval << TgxStateType::sttList << TgxStateType::sttTexture << TgxStateType::sttScissor << TgxStateType::sttMultisample )
#define cAllMeshPrimitive (System::Set<TgxMeshPrimitive, TgxMeshPrimitive::mpNOPRIMITIVE, TgxMeshPrimitive::mpPATCHES>() << TgxMeshPrimitive::mpTRIANGLES << TgxMeshPrimitive::mpTRIANGLE_STRIP << TgxMeshPrimitive::mpTRIANGLE_FAN << TgxMeshPrimitive::mpPOINTS << TgxMeshPrimitive::mpLINES << TgxMeshPrimitive::mpLINE_LOOP << TgxMeshPrimitive::mpLINE_STRIP << TgxMeshPrimitive::mpLINES_ADJACENCY << TgxMeshPrimitive::mpLINE_STRIP_ADJACENCY << TgxMeshPrimitive::mpTRIANGLES_ADJACENCY << TgxMeshPrimitive::mpTRIANGLE_STRIP_ADJACENCY << TgxMeshPrimitive::mpPATCHES )
#define cAllColorComponents (System::Set<TgxColorComponent, TgxColorComponent::ccRed, TgxColorComponent::ccAlpha>() << TgxColorComponent::ccRed << TgxColorComponent::ccGreen << TgxColorComponent::ccBlue << TgxColorComponent::ccAlpha )
static _DELPHI_CONST System::Int8 MAX_HARDWARE_LIGHT = System::Int8(0x10);
static _DELPHI_CONST System::Int8 MAX_SHADER_LIGHT = System::Int8(0x8);
static _DELPHI_CONST System::Int8 MAX_HARDWARE_TEXTURE_UNIT = System::Int8(0x30);
static _DELPHI_CONST System::Int8 MAX_HARDWARE_UNIFORM_BUFFER_BINDING = System::Int8(0x4b);
extern DELPHI_PACKAGE System::StaticArray<unsigned, 21> cGLStateTypeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<TgxStateRecord, 24> cGLStateToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 12> cGLTexTypeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 5> cGLQueryTypeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 8> cGLStencilOpToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 16> cGLLogicOpToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 8> cGLComparisonFunctionToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 15> cGLBlendFunctionToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 5> cGLBlendEquationToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 2> cGLFaceWindingToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 3> cGLPolygonModeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 3> cGLCullFaceModeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 3> cGLHintToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<unsigned, 2> cGLBufferBindingTarget;
}	/* namespace State */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_STATE)
using namespace Gxs::State;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_StateHPP
