// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.State.pas' rev: 36.00 (Windows)

#ifndef GLS_StateHPP
#define GLS_StateHPP

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
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Utils.hpp>
#include <GLS.Color.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace State
{
//-- forward type declarations -----------------------------------------------
struct TGLLightSourceState;
struct TGLShaderLightSourceState;
struct TUBOStates;
class DELPHICLASS TGLStateCache;
struct TStateRecord;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLStateType : unsigned char { sttCurrent, sttPoint, sttLine, sttPolygon, sttPolygonStipple, sttPixelMode, sttLighting, sttFog, sttDepthBuffer, sttAccumBuffer, sttStencilBuffer, sttViewport, sttTransform, sttEnable, sttColorBuffer, sttHint, sttEval, sttList, sttTexture, sttScissor, sttMultisample };

typedef System::Set<TGLStateType, TGLStateType::sttCurrent, TGLStateType::sttMultisample> TGLStateTypes;

enum DECLSPEC_DENUM TGLMeshPrimitive : unsigned char { mpNOPRIMITIVE, mpTRIANGLES, mpTRIANGLE_STRIP, mpTRIANGLE_FAN, mpPOINTS, mpLINES, mpLINE_LOOP, mpLINE_STRIP, mpLINES_ADJACENCY, mpLINE_STRIP_ADJACENCY, mpTRIANGLES_ADJACENCY, mpTRIANGLE_STRIP_ADJACENCY, mpPATCHES };

typedef System::Set<TGLMeshPrimitive, TGLMeshPrimitive::mpNOPRIMITIVE, TGLMeshPrimitive::mpPATCHES> TGLMeshPrimitives;

enum DECLSPEC_DENUM TGLState : unsigned char { stAlphaTest, stAutoNormal, stBlend, stColorMaterial, stCullFace, stDepthTest, stDither, stFog, stLighting, stLineSmooth, stLineStipple, stIndexLogicOp, stColorLogicOp, stNormalize, stPointSmooth, stPointSprite, stPolygonSmooth, stPolygonStipple, stScissorTest, stStencilTest, stPolygonOffsetPoint, stPolygonOffsetLine, stPolygonOffsetFill, stDepthClamp };

typedef System::Set<TGLState, TGLState::stAlphaTest, TGLState::stDepthClamp> TGLStates;

enum DECLSPEC_DENUM TGLComparisonFunction : unsigned char { cfNever, cfAlways, cfLess, cfLEqual, cfEqual, cfGreater, cfNotEqual, cfGEqual };

typedef TGLComparisonFunction TGLStencilFunction;

typedef TGLComparisonFunction TGLDepthFunction;

enum DECLSPEC_DENUM TGLBlendFunction : unsigned char { bfZero, bfOne, bfSrcColor, bfOneMinusSrcColor, bfDstColor, bfOneMinusDstColor, bfSrcAlpha, bfOneMinusSrcAlpha, bfDstAlpha, bfOneMinusDstAlpha, bfConstantColor, bfOneMinusConstantColor, bfConstantAlpha, bfOneMinusConstantAlpha, bfSrcAlphaSat };

typedef TGLBlendFunction TGLDstBlendFunction;

enum DECLSPEC_DENUM TGLBlendEquation : unsigned char { beAdd, beSubtract, beReverseSubtract, beMin, beMax };

enum DECLSPEC_DENUM TGLStencilOp : unsigned char { soKeep, soZero, soReplace, soIncr, soDecr, soInvert, soIncrWrap, soDecrWrap };

enum DECLSPEC_DENUM TGLLogicOp : unsigned char { loClear, loAnd, loAndReverse, loCopy, loAndInverted, loNoOp, loXOr, loOr, loNor, loEquiv, loInvert, loOrReverse, loCopyInverted, loOrInverted, loNAnd, loSet };

enum DECLSPEC_DENUM TGLQueryType : unsigned char { qrySamplesPassed, qryPrimitivesGenerated, qryTransformFeedbackPrimitivesWritten, qryTimeElapsed, qryAnySamplesPassed };

enum DECLSPEC_DENUM TGLFaceWinding : unsigned char { fwCounterClockWise, fwClockWise };

enum DECLSPEC_DENUM TGLPolygonMode : unsigned char { pmFill, pmLines, pmPoints };

enum DECLSPEC_DENUM TGLCullFaceMode : unsigned char { cmFront, cmBack, cmFrontAndBack };

enum DECLSPEC_DENUM TGLColorComponent : unsigned char { ccRed, ccGreen, ccBlue, ccAlpha };

typedef System::Set<TGLColorComponent, TGLColorComponent::ccRed, TGLColorComponent::ccAlpha> TGLColorMask;

enum DECLSPEC_DENUM TGLHintType : unsigned char { hintDontCare, hintFastest, hintNicest };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGLLightSourceState
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
struct DECLSPEC_DRECORD TGLShaderLightSourceState
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


typedef void __fastcall (*TGLOnLightsChanged)(System::TObject* Sender);

enum DECLSPEC_DENUM TGLBufferBindingTarget : unsigned char { bbtUniform, bbtTransformFeedBack };

struct DECLSPEC_DRECORD TUBOStates
{
public:
	unsigned FUniformBufferBinding;
	Stage::Opengltokens::TGLintptr FOffset;
	Stage::Opengltokens::TGLsizeiptr FSize;
};


enum DECLSPEC_DENUM TGLMaterialLevel : unsigned char { mlAuto, mlFixedFunction, mlMultitexturing, mlSM3, mlSM4, mlSM5 };

class PASCALIMPLEMENTATION TGLStateCache : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TGLStateTypes> _TGLStateCache__1;
	
	
private:
	System::StaticArray<System::StaticArray<Stage::Vectortypes::TVector4f, 4>, 2> FFrontBackColors;
	System::StaticArray<int, 2> FFrontBackShininess;
	TGLComparisonFunction FAlphaFunc;
	float FAlphaRef;
	TGLPolygonMode FPolygonBackMode;
	unsigned FMaxLights;
	System::StaticArray<bool, 16> FLightEnabling;
	System::StaticArray<int, 16> FLightIndices;
	int FLightNumber;
	TGLLightSourceState FLightStates;
	System::StaticArray<float, 16> FSpotCutoff;
	TGLShaderLightSourceState FShaderLightStates;
	bool FShaderLightStatesChanged;
	bool FColorWriting;
	TGLStates FStates;
	_TGLStateCache__1 FListStates;
	unsigned FCurrentList;
	System::StaticArray<bool, 4> FTextureMatrixIsIdentity;
	bool FFFPLight;
	unsigned FVertexArrayBinding;
	unsigned FArrayBufferBinding;
	unsigned FElementBufferBinding;
	unsigned FTextureBufferBinding;
	Stage::Opengltokens::TGLboolean FEnablePrimitiveRestart;
	unsigned FPrimitiveRestartIndex;
	Stage::Vectortypes::TVector4i FViewPort;
	System::StaticArray<double, 2> FDepthRange;
	System::StaticArray<System::ByteBool, 8> FEnableClipDistance;
	Stage::Opengltokens::TGLboolean FEnableDepthClamp;
	unsigned FClampReadColor;
	unsigned FProvokingVertex;
	Stage::Opengltokens::TGLfloat FPointSize;
	Stage::Opengltokens::TGLfloat FPointFadeThresholdSize;
	unsigned FPointSpriteCoordOrigin;
	float FLineWidth;
	Stage::Opengltokens::TGLint FLineStippleFactor;
	Stage::Opengltokens::TGLushort FLineStipplePattern;
	Stage::Opengltokens::TGLboolean FEnableLineSmooth;
	Stage::Opengltokens::TGLboolean FEnableCullFace;
	TGLCullFaceMode FCullFaceMode;
	TGLFaceWinding FFrontFace;
	Stage::Opengltokens::TGLboolean FEnablePolygonSmooth;
	TGLPolygonMode FPolygonMode;
	Stage::Opengltokens::TGLfloat FPolygonOffsetFactor;
	Stage::Opengltokens::TGLfloat FPolygonOffsetUnits;
	Stage::Opengltokens::TGLboolean FEnablePolygonOffsetPoint;
	Stage::Opengltokens::TGLboolean FEnablePolygonOffsetLine;
	Stage::Opengltokens::TGLboolean FEnablePolygonOffsetFill;
	Stage::Opengltokens::TGLboolean FEnableMultisample;
	Stage::Opengltokens::TGLboolean FEnableSampleAlphaToCoverage;
	Stage::Opengltokens::TGLboolean FEnableSampleAlphaToOne;
	Stage::Opengltokens::TGLboolean FEnableSampleCoverage;
	Stage::Opengltokens::TGLfloat FSampleCoverageValue;
	Stage::Opengltokens::TGLboolean FSampleCoverageInvert;
	Stage::Opengltokens::TGLboolean FEnableSampleMask;
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
	Stage::Opengltokens::TGLint FActiveTexture;
	System::StaticArray<System::StaticArray<bool, 12>, 48> FActiveTextureEnabling;
	Stage::Opengltokens::TGLboolean FEnableScissorTest;
	Stage::Vectortypes::TVector4i FScissorBox;
	Stage::Opengltokens::TGLboolean FEnableStencilTest;
	TGLStencilFunction FStencilFunc;
	unsigned FStencilValueMask;
	Stage::Opengltokens::TGLint FStencilRef;
	TGLStencilOp FStencilFail;
	TGLStencilOp FStencilPassDepthFail;
	TGLStencilOp FStencilPassDepthPass;
	TGLStencilFunction FStencilBackFunc;
	unsigned FStencilBackValueMask;
	unsigned FStencilBackRef;
	TGLStencilOp FStencilBackFail;
	TGLStencilOp FStencilBackPassDepthPass;
	TGLStencilOp FStencilBackPassDepthFail;
	Stage::Opengltokens::TGLboolean FEnableDepthTest;
	TGLDepthFunction FDepthFunc;
	System::StaticArray<System::ByteBool, 16> FEnableBlend;
	TGLBlendFunction FBlendSrcRGB;
	TGLBlendFunction FBlendSrcAlpha;
	TGLDstBlendFunction FBlendDstRGB;
	TGLDstBlendFunction FBlendDstAlpha;
	TGLBlendEquation FBlendEquationRGB;
	TGLBlendEquation FBlendEquationAlpha;
	Stage::Vectortypes::TGLVector FBlendColor;
	Stage::Opengltokens::TGLboolean FEnableFramebufferSRGB;
	Stage::Opengltokens::TGLboolean FEnableDither;
	Stage::Opengltokens::TGLboolean FEnableColorLogicOp;
	TGLLogicOp FLogicOpMode;
	System::StaticArray<TGLColorMask, 16> FColorWriteMask;
	Stage::Opengltokens::TGLboolean FDepthWriteMask;
	unsigned FStencilWriteMask;
	unsigned FStencilBackWriteMask;
	Stage::Vectortypes::TGLVector FColorClearValue;
	Stage::Opengltokens::TGLfloat FDepthClearValue;
	unsigned FStencilClearValue;
	unsigned FDrawFrameBuffer;
	unsigned FReadFrameBuffer;
	unsigned FRenderBuffer;
	Stage::Opengltokens::TGLboolean FUnpackSwapBytes;
	Stage::Opengltokens::TGLboolean FUnpackLSBFirst;
	unsigned FUnpackImageHeight;
	unsigned FUnpackSkipImages;
	unsigned FUnpackRowLength;
	unsigned FUnpackSkipRows;
	unsigned FUnpackSkipPixels;
	unsigned FUnpackAlignment;
	Stage::Opengltokens::TGLboolean FPackSwapBytes;
	Stage::Opengltokens::TGLboolean FPackLSBFirst;
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
	Stage::Opengltokens::TGLboolean FEnableProgramPointSize;
	unsigned FTransformFeedbackBufferBinding;
	TGLHintType FTextureCompressionHint;
	TGLHintType FPolygonSmoothHint;
	TGLHintType FFragmentShaderDerivitiveHint;
	TGLHintType FLineSmoothHint;
	TGLHintType FMultisampleFilterHint;
	System::StaticArray<unsigned, 5> FCurrentQuery;
	unsigned FCopyReadBufferBinding;
	unsigned FCopyWriteBufferBinding;
	Stage::Opengltokens::TGLboolean FEnableTextureCubeMapSeamless;
	bool FInsideList;
	TGLOnLightsChanged FOnLightsChanged;
	
protected:
	void __fastcall SetVertexArrayBinding(const unsigned Value);
	unsigned __fastcall GetArrayBufferBinding();
	void __fastcall SetArrayBufferBinding(const unsigned Value);
	unsigned __fastcall GetElementBufferBinding();
	void __fastcall SetElementBufferBinding(const unsigned Value);
	Stage::Opengltokens::TGLboolean __fastcall GetEnablePrimitiveRestart();
	unsigned __fastcall GetPrimitiveRestartIndex();
	void __fastcall SetEnablePrimitiveRestart(const Stage::Opengltokens::TGLboolean enabled);
	void __fastcall SetPrimitiveRestartIndex(const unsigned index);
	void __fastcall SetTextureBufferBinding(const unsigned Value);
	void __fastcall SetViewPort(const Stage::Vectortypes::TVector4i &Value);
	Stage::Opengltokens::TGLboolean __fastcall GetEnableClipDistance(unsigned ClipDistance);
	void __fastcall SetEnableClipDistance(unsigned index, const Stage::Opengltokens::TGLboolean Value);
	Stage::Opengltokens::TGLclampd __fastcall GetDepthRangeFar();
	void __fastcall SetDepthRangeFar(const Stage::Opengltokens::TGLclampd Value);
	Stage::Opengltokens::TGLclampd __fastcall GetDepthRangeNear();
	void __fastcall SetDepthRangeNear(const Stage::Opengltokens::TGLclampd Value);
	void __fastcall SetEnableDepthClamp(const Stage::Opengltokens::TGLboolean enabled);
	void __fastcall SetClampReadColor(const unsigned Value);
	void __fastcall SetProvokingVertex(const unsigned Value);
	void __fastcall SetPointSize(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetPointFadeThresholdSize(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetPointSpriteCoordOrigin(const unsigned Value);
	void __fastcall SetLineWidth(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetLineStippleFactor(const Stage::Opengltokens::TGLint Value);
	void __fastcall SetLineStipplePattern(const Stage::Opengltokens::TGLushort Value);
	void __fastcall SetEnableLineSmooth(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableCullFace(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetCullFaceMode(const TGLCullFaceMode Value);
	void __fastcall SetFrontFace(const TGLFaceWinding Value);
	void __fastcall SetEnablePolygonSmooth(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetPolygonMode(const TGLPolygonMode Value);
	void __fastcall SetPolygonOffsetFactor(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetPolygonOffsetUnits(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetEnablePolygonOffsetPoint(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnablePolygonOffsetLine(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnablePolygonOffsetFill(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableMultisample(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableSampleAlphaToCoverage(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableSampleAlphaToOne(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableSampleCoverage(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetSampleCoverageValue(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetSampleCoverageInvert(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableSampleMask(const Stage::Opengltokens::TGLboolean Value);
	Stage::Opengltokens::TGLbitfield __fastcall GetSampleMaskValue(int index);
	void __fastcall SetSampleMaskValue(int index, const Stage::Opengltokens::TGLbitfield Value);
	unsigned __fastcall GetMaxTextureSize();
	unsigned __fastcall GetMax3DTextureSize();
	unsigned __fastcall GetMaxCubeTextureSize();
	unsigned __fastcall GetMaxArrayTextureSize();
	unsigned __fastcall GetMaxTextureImageUnits();
	unsigned __fastcall GetMaxTextureAnisotropy();
	unsigned __fastcall GetMaxSamples();
	unsigned __fastcall GetTextureBinding(int index, Stage::Textureformat::TglTextureTarget target);
	double __fastcall GetTextureBindingTime(int index, Stage::Textureformat::TglTextureTarget target);
	void __fastcall SetTextureBinding(int index, Stage::Textureformat::TglTextureTarget target, const unsigned Value);
	bool __fastcall GetActiveTextureEnabled(Stage::Textureformat::TglTextureTarget target);
	void __fastcall SetActiveTextureEnabled(Stage::Textureformat::TglTextureTarget target, const bool Value);
	unsigned __fastcall GetSamplerBinding(unsigned index);
	void __fastcall SetSamplerBinding(unsigned index, const unsigned Value);
	void __fastcall SetActiveTexture(const Stage::Opengltokens::TGLint Value);
	void __fastcall SetEnableScissorTest(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetScissorBox(const Stage::Vectortypes::TVector4i &Value);
	void __fastcall SetEnableStencilTest(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableDepthTest(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetDepthFunc(const TGLDepthFunction Value);
	Stage::Opengltokens::TGLboolean __fastcall GetEnableBlend(int index);
	void __fastcall SetEnableBlend(int index, const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetBlendColor(const Stage::Vectortypes::TGLVector &Value);
	void __fastcall SetEnableFramebufferSRGB(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableDither(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetEnableColorLogicOp(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetLogicOpMode(const TGLLogicOp Value);
	TGLColorMask __fastcall GetColorWriteMask(int index);
	void __fastcall SetColorWriteMask(int index, const TGLColorMask Value);
	void __fastcall SetDepthWriteMask(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetStencilWriteMask(const unsigned Value);
	void __fastcall SetStencilBackWriteMask(const unsigned Value);
	void __fastcall SetColorClearValue(const Stage::Vectortypes::TGLVector &Value);
	void __fastcall SetDepthClearValue(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetStencilClearValue(const unsigned Value);
	void __fastcall SetDrawFrameBuffer(const unsigned Value);
	void __fastcall SetReadFrameBuffer(const unsigned Value);
	void __fastcall SetRenderBuffer(const unsigned Value);
	void __fastcall SetUnpackSwapBytes(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetUnpackLSBFirst(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetUnpackImageHeight(const unsigned Value);
	void __fastcall SetUnpackSkipImages(const unsigned Value);
	void __fastcall SetUnpackRowLength(const unsigned Value);
	void __fastcall SetUnpackSkipRows(const unsigned Value);
	void __fastcall SetUnpackSkipPixels(const unsigned Value);
	void __fastcall SetUnpackAlignment(const unsigned Value);
	void __fastcall SetPackSwapBytes(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetPackLSBFirst(const Stage::Opengltokens::TGLboolean Value);
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
	Stage::Vectortypes::TGLVector __fastcall GetCurrentVertexAttrib(int index);
	void __fastcall SetCurrentVertexAttrib(int index, const Stage::Vectortypes::TGLVector &Value);
	void __fastcall SetEnableProgramPointSize(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetTransformFeedbackBufferBinding(const unsigned Value);
	void __fastcall SetLineSmoothHint(const TGLHintType Value);
	void __fastcall SetPolygonSmoothHint(const TGLHintType Value);
	void __fastcall SetTextureCompressionHint(const TGLHintType Value);
	void __fastcall SetFragmentShaderDerivitiveHint(const TGLHintType Value);
	void __fastcall SetMultisampleFilterHint(const TGLHintType Value);
	unsigned __fastcall GetCurrentQuery(TGLQueryType index);
	void __fastcall SetCopyReadBufferBinding(const unsigned Value);
	void __fastcall SetCopyWriteBufferBinding(const unsigned Value);
	void __fastcall SetEnableTextureCubeMapSeamless(const Stage::Opengltokens::TGLboolean Value);
	void __fastcall SetFFPLight(bool Value);
	int __fastcall GetMaxLights();
	bool __fastcall GetLightEnabling(int I);
	void __fastcall SetLightEnabling(int I, bool Value);
	Stage::Vectortypes::TGLVector __fastcall GetLightPosition(int I);
	void __fastcall SetLightPosition(int I, const Stage::Vectortypes::TGLVector &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetLightSpotDirection(int I);
	void __fastcall SetLightSpotDirection(int I, const Stage::Vectorgeometry::TAffineVector &Value);
	Stage::Vectortypes::TGLVector __fastcall GetLightAmbient(int I);
	void __fastcall SetLightAmbient(int I, const Stage::Vectortypes::TGLVector &Value);
	Stage::Vectortypes::TGLVector __fastcall GetLightDiffuse(int I);
	void __fastcall SetLightDiffuse(int I, const Stage::Vectortypes::TGLVector &Value);
	Stage::Vectortypes::TGLVector __fastcall GetLightSpecular(int I);
	void __fastcall SetLightSpecular(int I, const Stage::Vectortypes::TGLVector &Value);
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
	Stage::Vectortypes::TGLVector __fastcall GetMaterialAmbient(const TGLCullFaceMode aFace);
	Stage::Vectortypes::TGLVector __fastcall GetMaterialDiffuse(const TGLCullFaceMode aFace);
	Stage::Vectortypes::TGLVector __fastcall GetMaterialSpecular(const TGLCullFaceMode aFace);
	Stage::Vectortypes::TGLVector __fastcall GetMaterialEmission(const TGLCullFaceMode aFace);
	int __fastcall GetMaterialShininess(const TGLCullFaceMode aFace);
	
public:
	__fastcall virtual TGLStateCache();
	__fastcall virtual ~TGLStateCache();
	void __fastcall PushAttrib(const TGLStateTypes stateTypes);
	void __fastcall PopAttrib();
	void __fastcall Enable(const TGLState aState);
	void __fastcall Disable(const TGLState aState);
	void __fastcall PerformEnable(const TGLState aState);
	void __fastcall PerformDisable(const TGLState aState);
	void __fastcall SetGLState _DEPRECATED_ATTRIBUTE0 (const TGLState aState);
	void __fastcall UnSetGLState _DEPRECATED_ATTRIBUTE0 (const TGLState aState);
	void __fastcall ResetGLPolygonMode _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetGLMaterialColors _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetGLTexture _DEPRECATED_ATTRIBUTE0 (const int TextureUnit);
	void __fastcall ResetGLCurrentTexture _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetGLFrontFace _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall SetGLFrontFaceCW _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall ResetAll _DEPRECATED_ATTRIBUTE0 ();
	void __fastcall SetGLMaterialColors(const TGLCullFaceMode aFace, const Stage::Vectortypes::TGLVector &emission, const Stage::Vectortypes::TGLVector &Ambient, const Stage::Vectortypes::TGLVector &Diffuse, const Stage::Vectortypes::TGLVector &Specular, const int shininess);
	__property Stage::Vectortypes::TGLVector MaterialAmbient[const TGLCullFaceMode aFace] = {read=GetMaterialAmbient};
	__property Stage::Vectortypes::TGLVector MaterialDiffuse[const TGLCullFaceMode aFace] = {read=GetMaterialDiffuse};
	__property Stage::Vectortypes::TGLVector MaterialSpecular[const TGLCullFaceMode aFace] = {read=GetMaterialSpecular};
	__property Stage::Vectortypes::TGLVector MaterialEmission[const TGLCullFaceMode aFace] = {read=GetMaterialEmission};
	__property int MaterialShininess[const TGLCullFaceMode aFace] = {read=GetMaterialShininess};
	void __fastcall SetGLMaterialAlphaChannel(const unsigned aFace, const Stage::Opengltokens::TGLfloat alpha);
	void __fastcall SetGLMaterialDiffuseColor(const unsigned aFace, const Stage::Vectortypes::TGLVector &Diffuse);
	__property bool FixedFunctionPipeLight = {read=FFFPLight, write=SetFFPLight, nodefault};
	__property int MaxLights = {read=GetMaxLights, nodefault};
	__property bool LightEnabling[int Index] = {read=GetLightEnabling, write=SetLightEnabling};
	__property Stage::Vectortypes::TGLVector LightPosition[int Index] = {read=GetLightPosition, write=SetLightPosition};
	__property Stage::Vectorgeometry::TAffineVector LightSpotDirection[int Index] = {read=GetLightSpotDirection, write=SetLightSpotDirection};
	__property Stage::Vectortypes::TGLVector LightAmbient[int Index] = {read=GetLightAmbient, write=SetLightAmbient};
	__property Stage::Vectortypes::TGLVector LightDiffuse[int Index] = {read=GetLightDiffuse, write=SetLightDiffuse};
	__property Stage::Vectortypes::TGLVector LightSpecular[int Index] = {read=GetLightSpecular, write=SetLightSpecular};
	__property float LightSpotCutoff[int Index] = {read=GetSpotCutoff, write=SetSpotCutoff};
	__property float LightSpotExponent[int Index] = {read=GetSpotExponent, write=SetSpotExponent};
	__property float LightConstantAtten[int Index] = {read=GetConstantAtten, write=SetConstantAtten};
	__property float LightLinearAtten[int Index] = {read=GetLinearAtten, write=SetLinearAtten};
	__property float LightQuadraticAtten[int Index] = {read=GetQuadAtten, write=SetQuadAtten};
	Stage::Opengltokens::PGLint __fastcall GetLightIndicesAsAddress();
	void * __fastcall GetLightStateAsAddress();
	__property int LightNumber = {read=FLightNumber, nodefault};
	__property TGLOnLightsChanged OnLightsChanged = {read=FOnLightsChanged, write=FOnLightsChanged};
	void __fastcall SetGLAlphaFunction(TGLComparisonFunction func, float ref);
	__property unsigned VertexArrayBinding = {read=FVertexArrayBinding, write=SetVertexArrayBinding, nodefault};
	__property unsigned ArrayBufferBinding = {read=GetArrayBufferBinding, write=SetArrayBufferBinding, nodefault};
	__property unsigned ElementBufferBinding = {read=GetElementBufferBinding, write=SetElementBufferBinding, nodefault};
	__property Stage::Opengltokens::TGLboolean EnablePrimitiveRestart = {read=GetEnablePrimitiveRestart, write=SetEnablePrimitiveRestart, nodefault};
	__property unsigned PrimitiveRestartIndex = {read=GetPrimitiveRestartIndex, write=SetPrimitiveRestartIndex, nodefault};
	__property unsigned TextureBufferBinding = {read=FTextureBufferBinding, write=SetTextureBufferBinding, nodefault};
	__property Stage::Vectortypes::TVector4i ViewPort = {read=FViewPort, write=SetViewPort};
	void __fastcall SetDepthRange(const Stage::Opengltokens::TGLclampd ZNear, const Stage::Opengltokens::TGLclampd ZFar);
	__property Stage::Opengltokens::TGLclampd DepthRangeNear = {read=GetDepthRangeNear, write=SetDepthRangeNear};
	__property Stage::Opengltokens::TGLclampd DepthRangeFar = {read=GetDepthRangeFar, write=SetDepthRangeFar};
	__property Stage::Opengltokens::TGLboolean EnableClipDistance[unsigned Index] = {read=GetEnableClipDistance, write=SetEnableClipDistance};
	__property Stage::Opengltokens::TGLboolean EnableDepthClamp = {read=FEnableDepthClamp, write=SetEnableDepthClamp, nodefault};
	__property unsigned ClampReadColor = {read=FClampReadColor, write=SetClampReadColor, nodefault};
	__property unsigned ProvokingVertex = {read=FProvokingVertex, write=SetProvokingVertex, nodefault};
	__property Stage::Opengltokens::TGLfloat PointSize = {read=FPointSize, write=SetPointSize};
	__property Stage::Opengltokens::TGLfloat PointFadeThresholdSize = {read=FPointFadeThresholdSize, write=SetPointFadeThresholdSize};
	__property unsigned PointSpriteCoordOrigin = {read=FPointSpriteCoordOrigin, write=SetPointSpriteCoordOrigin, nodefault};
	__property Stage::Opengltokens::TGLfloat LineWidth = {read=FLineWidth, write=SetLineWidth};
	__property Stage::Opengltokens::TGLint LineStippleFactor = {read=FLineStippleFactor, write=SetLineStippleFactor, nodefault};
	__property Stage::Opengltokens::TGLushort LineStipplePattern = {read=FLineStipplePattern, write=SetLineStipplePattern, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableLineSmooth = {read=FEnableLineSmooth, write=SetEnableLineSmooth, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableCullFace = {read=FEnableCullFace, write=SetEnableCullFace, nodefault};
	__property TGLCullFaceMode CullFaceMode = {read=FCullFaceMode, write=SetCullFaceMode, nodefault};
	__property TGLFaceWinding FrontFace = {read=FFrontFace, write=SetFrontFace, nodefault};
	__property Stage::Opengltokens::TGLboolean EnablePolygonSmooth = {read=FEnablePolygonSmooth, write=SetEnablePolygonSmooth, nodefault};
	__property TGLPolygonMode PolygonMode = {read=FPolygonMode, write=SetPolygonMode, nodefault};
	__property Stage::Opengltokens::TGLfloat PolygonOffsetFactor = {read=FPolygonOffsetFactor, write=SetPolygonOffsetFactor};
	__property Stage::Opengltokens::TGLfloat PolygonOffsetUnits = {read=FPolygonOffsetUnits, write=SetPolygonOffsetUnits};
	void __fastcall SetPolygonOffset(const Stage::Opengltokens::TGLfloat factor, const Stage::Opengltokens::TGLfloat units);
	__property Stage::Opengltokens::TGLboolean EnablePolygonOffsetPoint = {read=FEnablePolygonOffsetPoint, write=SetEnablePolygonOffsetPoint, nodefault};
	__property Stage::Opengltokens::TGLboolean EnablePolygonOffsetLine = {read=FEnablePolygonOffsetLine, write=SetEnablePolygonOffsetLine, nodefault};
	__property Stage::Opengltokens::TGLboolean EnablePolygonOffsetFill = {read=FEnablePolygonOffsetFill, write=SetEnablePolygonOffsetFill, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableMultisample = {read=FEnableMultisample, write=SetEnableMultisample, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableSampleAlphaToCoverage = {read=FEnableSampleAlphaToCoverage, write=SetEnableSampleAlphaToCoverage, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableSampleAlphaToOne = {read=FEnableSampleAlphaToOne, write=SetEnableSampleAlphaToOne, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableSampleCoverage = {read=FEnableSampleCoverage, write=SetEnableSampleCoverage, nodefault};
	__property Stage::Opengltokens::TGLfloat SampleCoverageValue = {read=FSampleCoverageValue, write=SetSampleCoverageValue};
	__property Stage::Opengltokens::TGLboolean SampleCoverageInvert = {read=FSampleCoverageInvert, write=SetSampleCoverageInvert, nodefault};
	void __fastcall SetSampleCoverage(const Stage::Opengltokens::TGLfloat Value, Stage::Opengltokens::TGLboolean invert);
	__property Stage::Opengltokens::TGLboolean EnableSampleMask = {read=FEnableSampleMask, write=SetEnableSampleMask, nodefault};
	__property Stage::Opengltokens::TGLbitfield SampleMaskValue[int Index] = {read=GetSampleMaskValue, write=SetSampleMaskValue};
	__property unsigned TextureBinding[int Index][Stage::Textureformat::TglTextureTarget target] = {read=GetTextureBinding, write=SetTextureBinding};
	__property double TextureBindingTime[int Index][Stage::Textureformat::TglTextureTarget target] = {read=GetTextureBindingTime};
	__property bool ActiveTextureEnabled[Stage::Textureformat::TglTextureTarget target] = {read=GetActiveTextureEnabled, write=SetActiveTextureEnabled};
	__property unsigned SamplerBinding[unsigned Index] = {read=GetSamplerBinding, write=SetSamplerBinding};
	__property unsigned MaxTextureSize = {read=GetMaxTextureSize, nodefault};
	__property unsigned Max3DTextureSize = {read=GetMax3DTextureSize, nodefault};
	__property unsigned MaxCubeTextureSize = {read=GetMaxCubeTextureSize, nodefault};
	__property unsigned MaxArrayTextureSize = {read=GetMaxArrayTextureSize, nodefault};
	__property unsigned MaxTextureImageUnits = {read=GetMaxTextureImageUnits, nodefault};
	__property unsigned MaxTextureAnisotropy = {read=GetMaxTextureAnisotropy, nodefault};
	__property unsigned MaxSamples = {read=GetMaxSamples, nodefault};
	__property Stage::Opengltokens::TGLint ActiveTexture = {read=FActiveTexture, write=SetActiveTexture, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableScissorTest = {read=FEnableScissorTest, write=SetEnableScissorTest, nodefault};
	__property Stage::Vectortypes::TVector4i ScissorBox = {read=FScissorBox, write=SetScissorBox};
	__property Stage::Opengltokens::TGLboolean EnableStencilTest = {read=FEnableStencilTest, write=SetEnableStencilTest, nodefault};
	__property TGLStencilFunction StencilFunc = {read=FStencilFunc, nodefault};
	__property unsigned StencilValueMask = {read=FStencilValueMask, nodefault};
	__property Stage::Opengltokens::TGLint StencilRef = {read=FStencilRef, nodefault};
	__property TGLStencilOp StencilFail = {read=FStencilFail, nodefault};
	__property TGLStencilOp StencilPassDepthFail = {read=FStencilPassDepthFail, nodefault};
	__property TGLStencilOp StencilPassDepthPass = {read=FStencilPassDepthPass, nodefault};
	__property TGLStencilFunction StencilBackFunc = {read=FStencilBackFunc, nodefault};
	__property unsigned StencilBackValueMask = {read=FStencilBackValueMask, nodefault};
	__property unsigned StencilBackRef = {read=FStencilBackRef, nodefault};
	__property TGLStencilOp StencilBackFail = {read=FStencilBackFail, nodefault};
	__property TGLStencilOp StencilBackPassDepthFail = {read=FStencilBackPassDepthFail, nodefault};
	__property TGLStencilOp StencilBackPassDepthPass = {read=FStencilBackPassDepthPass, nodefault};
	void __fastcall SetStencilFunc(const TGLStencilFunction func, const Stage::Opengltokens::TGLint ref, const unsigned mask);
	void __fastcall SetStencilFuncSeparate(const TGLCullFaceMode face, const TGLStencilFunction func, const Stage::Opengltokens::TGLint ref, const unsigned mask);
	void __fastcall SetStencilOp(const TGLStencilOp fail, const TGLStencilOp zfail, const TGLStencilOp zpass);
	void __fastcall SetStencilOpSeparate(const TGLCullFaceMode face, const TGLStencilOp sfail, const TGLStencilOp dpfail, const TGLStencilOp dppass);
	__property Stage::Opengltokens::TGLboolean EnableDepthTest = {read=FEnableDepthTest, write=SetEnableDepthTest, nodefault};
	__property TGLDepthFunction DepthFunc = {read=FDepthFunc, write=SetDepthFunc, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableBlend[int Index] = {read=GetEnableBlend, write=SetEnableBlend};
	__property TGLBlendFunction BlendSrcRGB = {read=FBlendSrcRGB, nodefault};
	__property TGLBlendFunction BlendSrcAlpha = {read=FBlendSrcAlpha, nodefault};
	__property TGLDstBlendFunction BlendDstRGB = {read=FBlendDstRGB, nodefault};
	__property TGLDstBlendFunction BlendDstAlpha = {read=FBlendDstAlpha, nodefault};
	void __fastcall SetBlendFunc(const TGLBlendFunction Src, const TGLDstBlendFunction Dst);
	void __fastcall SetBlendFuncSeparate(const TGLBlendFunction SrcRGB, const TGLDstBlendFunction DstRGB, const TGLBlendFunction SrcAlpha, const TGLDstBlendFunction DstAlpha);
	__property TGLBlendEquation BlendEquationRGB = {read=FBlendEquationRGB, nodefault};
	__property TGLBlendEquation BlendEquationAlpha = {read=FBlendEquationAlpha, nodefault};
	void __fastcall SetBlendEquation(const TGLBlendEquation mode);
	void __fastcall SetBlendEquationSeparate(const TGLBlendEquation modeRGB, const TGLBlendEquation modeAlpha);
	__property Stage::Vectortypes::TGLVector BlendColor = {read=FBlendColor, write=SetBlendColor};
	__property Stage::Opengltokens::TGLboolean EnableFramebufferSRGB = {read=FEnableFramebufferSRGB, write=SetEnableFramebufferSRGB, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableDither = {read=FEnableDither, write=SetEnableDither, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableColorLogicOp = {read=FEnableColorLogicOp, write=SetEnableColorLogicOp, nodefault};
	__property TGLLogicOp LogicOpMode = {read=FLogicOpMode, write=SetLogicOpMode, nodefault};
	__property TGLColorMask ColorWriteMask[int Index] = {read=GetColorWriteMask, write=SetColorWriteMask};
	void __fastcall SetColorMask(TGLColorMask mask);
	__property Stage::Opengltokens::TGLboolean DepthWriteMask = {read=FDepthWriteMask, write=SetDepthWriteMask, nodefault};
	__property unsigned StencilWriteMask = {read=FStencilWriteMask, write=SetStencilWriteMask, nodefault};
	__property unsigned StencilBackWriteMask = {read=FStencilBackWriteMask, write=SetStencilBackWriteMask, nodefault};
	__property Stage::Vectortypes::TGLVector ColorClearValue = {read=FColorClearValue, write=SetColorClearValue};
	__property Stage::Opengltokens::TGLfloat DepthClearValue = {read=FDepthClearValue, write=SetDepthClearValue};
	__property unsigned StencilClearValue = {read=FStencilClearValue, write=SetStencilClearValue, nodefault};
	__property unsigned DrawFrameBuffer = {read=FDrawFrameBuffer, write=SetDrawFrameBuffer, nodefault};
	__property unsigned ReadFrameBuffer = {read=FReadFrameBuffer, write=SetReadFrameBuffer, nodefault};
	void __fastcall SetFrameBuffer(const unsigned Value);
	__property unsigned RenderBuffer = {read=FRenderBuffer, write=SetRenderBuffer, nodefault};
	__property Stage::Opengltokens::TGLboolean UnpackSwapBytes = {read=FUnpackSwapBytes, write=SetUnpackSwapBytes, nodefault};
	__property Stage::Opengltokens::TGLboolean UnpackLSBFirst = {read=FUnpackLSBFirst, write=SetUnpackLSBFirst, nodefault};
	__property unsigned UnpackImageHeight = {read=FUnpackImageHeight, write=SetUnpackImageHeight, nodefault};
	__property unsigned UnpackSkipImages = {read=FUnpackSkipImages, write=SetUnpackSkipImages, nodefault};
	__property unsigned UnpackRowLength = {read=FUnpackRowLength, write=SetUnpackRowLength, nodefault};
	__property unsigned UnpackSkipRows = {read=FUnpackSkipRows, write=SetUnpackSkipRows, nodefault};
	__property unsigned UnpackSkipPixels = {read=FUnpackSkipPixels, write=SetUnpackSkipPixels, nodefault};
	__property unsigned UnpackAlignment = {read=FUnpackAlignment, write=SetUnpackAlignment, nodefault};
	__property Stage::Opengltokens::TGLboolean PackSwapBytes = {read=FPackSwapBytes, write=SetPackSwapBytes, nodefault};
	__property Stage::Opengltokens::TGLboolean PackLSBFirst = {read=FPackLSBFirst, write=SetPackLSBFirst, nodefault};
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
	void __fastcall SetBufferIndexedBinding(const unsigned Value, TGLBufferBindingTarget ATarget, unsigned AIndex, Stage::Opengltokens::TGLsizeiptr ABufferSize)/* overload */;
	void __fastcall SetBufferIndexedBinding(const unsigned Value, TGLBufferBindingTarget ATarget, unsigned AIndex, Stage::Opengltokens::TGLintptr AOffset, Stage::Opengltokens::TGLsizeiptr ARangeSize)/* overload */;
	__property Stage::Vectortypes::TGLVector CurrentVertexAttrib[int Index] = {read=GetCurrentVertexAttrib, write=SetCurrentVertexAttrib};
	__property Stage::Opengltokens::TGLboolean EnableProgramPointSize = {read=FEnableProgramPointSize, write=SetEnableProgramPointSize, nodefault};
	__property unsigned TransformFeedbackBufferBinding = {read=FTransformFeedbackBufferBinding, write=SetTransformFeedbackBufferBinding, nodefault};
	__property TGLHintType LineSmoothHint = {read=FLineSmoothHint, write=SetLineSmoothHint, nodefault};
	__property TGLHintType PolygonSmoothHint = {read=FPolygonSmoothHint, write=SetPolygonSmoothHint, nodefault};
	__property TGLHintType TextureCompressionHint = {read=FTextureCompressionHint, write=SetTextureCompressionHint, nodefault};
	__property TGLHintType FragmentShaderDerivitiveHint = {read=FFragmentShaderDerivitiveHint, write=SetFragmentShaderDerivitiveHint, nodefault};
	__property TGLHintType MultisampleFilterHint = {read=FMultisampleFilterHint, write=SetMultisampleFilterHint, nodefault};
	__property unsigned CurrentQuery[TGLQueryType Index] = {read=GetCurrentQuery};
	void __fastcall BeginQuery(const TGLQueryType target, const unsigned Value);
	void __fastcall EndQuery(const TGLQueryType target);
	__property unsigned CopyReadBufferBinding = {read=FCopyReadBufferBinding, write=SetCopyReadBufferBinding, nodefault};
	__property unsigned CopyWriteBufferBinding = {read=FCopyWriteBufferBinding, write=SetCopyWriteBufferBinding, nodefault};
	__property Stage::Opengltokens::TGLboolean EnableTextureCubeMapSeamless = {read=FEnableTextureCubeMapSeamless, write=SetEnableTextureCubeMapSeamless, nodefault};
	__property bool InsideList = {read=FInsideList, nodefault};
	void __fastcall NewList(unsigned list, unsigned mode);
	void __fastcall EndList();
	void __fastcall CallList(unsigned list);
	void __fastcall SetTextureMatrix(const Stage::Vectortypes::TGLMatrix &matrix);
	void __fastcall ResetTextureMatrix();
	void __fastcall ResetAllTextureMatrix();
	void __fastcall SetColorWriting(bool flag);
	void __fastcall InvertFrontFace();
	__property TGLStates States = {read=FStates, nodefault};
};


struct DECLSPEC_DRECORD TStateRecord
{
public:
	unsigned GLConst;
	bool GLDeprecated;
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 GLS_VERTEX_ATTR_NUM = System::Int8(0x10);
#define cAllAttribBits (System::Set<TGLStateType, TGLStateType::sttCurrent, TGLStateType::sttMultisample>() << TGLStateType::sttCurrent << TGLStateType::sttPoint << TGLStateType::sttLine << TGLStateType::sttPolygon << TGLStateType::sttPolygonStipple << TGLStateType::sttPixelMode << TGLStateType::sttLighting << TGLStateType::sttFog << TGLStateType::sttDepthBuffer << TGLStateType::sttAccumBuffer << TGLStateType::sttStencilBuffer << TGLStateType::sttViewport << TGLStateType::sttTransform << TGLStateType::sttEnable << TGLStateType::sttColorBuffer << TGLStateType::sttHint << TGLStateType::sttEval << TGLStateType::sttList << TGLStateType::sttTexture << TGLStateType::sttScissor << TGLStateType::sttMultisample )
#define cAllMeshPrimitive (System::Set<TGLMeshPrimitive, TGLMeshPrimitive::mpNOPRIMITIVE, TGLMeshPrimitive::mpPATCHES>() << TGLMeshPrimitive::mpTRIANGLES << TGLMeshPrimitive::mpTRIANGLE_STRIP << TGLMeshPrimitive::mpTRIANGLE_FAN << TGLMeshPrimitive::mpPOINTS << TGLMeshPrimitive::mpLINES << TGLMeshPrimitive::mpLINE_LOOP << TGLMeshPrimitive::mpLINE_STRIP << TGLMeshPrimitive::mpLINES_ADJACENCY << TGLMeshPrimitive::mpLINE_STRIP_ADJACENCY << TGLMeshPrimitive::mpTRIANGLES_ADJACENCY << TGLMeshPrimitive::mpTRIANGLE_STRIP_ADJACENCY << TGLMeshPrimitive::mpPATCHES )
#define cAllColorComponents (System::Set<TGLColorComponent, TGLColorComponent::ccRed, TGLColorComponent::ccAlpha>() << TGLColorComponent::ccRed << TGLColorComponent::ccGreen << TGLColorComponent::ccBlue << TGLColorComponent::ccAlpha )
static _DELPHI_CONST System::Int8 MAX_HARDWARE_LIGHT = System::Int8(0x10);
static _DELPHI_CONST System::Int8 MAX_SHADER_LIGHT = System::Int8(0x8);
static _DELPHI_CONST System::Int8 MAX_HARDWARE_TEXTURE_UNIT = System::Int8(0x30);
static _DELPHI_CONST System::Int8 MAX_HARDWARE_UNIFORM_BUFFER_BINDING = System::Int8(0x4b);
extern DELPHI_PACKAGE System::StaticArray<unsigned, 21> cGLStateTypeToGLEnum;
extern DELPHI_PACKAGE System::StaticArray<TStateRecord, 24> cGLStateToGLEnum;
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
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_STATE)
using namespace Gls::State;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_StateHPP
