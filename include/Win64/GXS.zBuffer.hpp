// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.zBuffer.pas' rev: 36.00 (Windows)

#ifndef GXS_zBufferHPP
#define GXS_zBufferHPP

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
#include <System.Math.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Color.hpp>
#include <GXS.Scene.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Context.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>
#include <Stage.TextureFormat.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Zbuffer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EZBufferException;
class DELPHICLASS TgxZBuffer;
class DELPHICLASS TgxZShadows;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION EZBufferException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EZBufferException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EZBufferException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EZBufferException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EZBufferException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EZBufferException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EZBufferException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EZBufferException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EZBufferException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EZBufferException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EZBufferException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EZBufferException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EZBufferException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EZBufferException() { }
	
};


typedef System::StaticArray<float, 268435456> TZArray;

typedef TZArray *PZArray;

typedef System::DynamicArray<PZArray> TZArrayIdx;

typedef System::StaticArray<System::Byte, 268435456> TAArray;

typedef TAArray *PAArray;

typedef System::DynamicArray<PAArray> TAArrayIdx;

enum DECLSPEC_DENUM TOptimise : unsigned char { opNone, op4in1, op9in1, op16in1 };

class PASCALIMPLEMENTATION TgxZBuffer : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	PZArray FData;
	TZArrayIdx FDataIdx;
	TZArrayIdx FDataInvIdx;
	int FWidth;
	int FHeight;
	int FDataSize;
	float ang1;
	float ang2;
	float scal;
	float c1;
	float s1;
	float c2;
	float s2;
	float vw;
	float vh;
	Stage::Vectorgeometry::TAffineVector lt;
	Stage::Vectorgeometry::TAffineVector rt;
	Stage::Vectorgeometry::TAffineVector lb;
	Stage::Vectorgeometry::TAffineVector rb;
	Stage::Vectorgeometry::TAffineVector UpVec;
	Stage::Vectorgeometry::TAffineVector riVec;
	Stage::Vectorgeometry::TAffineVector ltW;
	Stage::Vectorgeometry::TAffineVector rtW;
	Stage::Vectorgeometry::TAffineVector lbW;
	Stage::Vectorgeometry::TAffineVector rbW;
	Stage::Vectorgeometry::TAffineVector UpVecW;
	Stage::Vectorgeometry::TAffineVector riVecW;
	float OrthInvDov;
	float OrthAddX;
	float OrthMulX;
	float OrthAddY;
	float OrthMulY;
	float dov;
	float np;
	float fp;
	float NpFp;
	float OneMinNp_Fp;
	float invOneMinNp_Fp;
	Gxs::Scene::TgxCamera* cam;
	void __fastcall DoCalcVectors();
	
protected:
	void __fastcall PrepareBufferMemory();
	void __fastcall SetWidth(int val);
	void __fastcall SetHeight(const int val);
	
public:
	Gxs::Sceneviewer::TgxSceneViewer* SceneViewer;
	Gxs::Scene::TgxMemoryViewer* MemoryViewer;
	Gxs::Scene::TgxSceneBuffer* Buffer;
	Stage::Vectorgeometry::TAffineVector Normal;
	__fastcall TgxZBuffer();
	__fastcall virtual ~TgxZBuffer();
	void __fastcall LinkToViewer(Gxs::Sceneviewer::TgxSceneViewer* viewer)/* overload */;
	void __fastcall LinkToViewer(Gxs::Scene::TgxMemoryViewer* viewer)/* overload */;
	PZArray __fastcall GetDepthBuffer(bool CalcVectors, bool ContextIsActive);
	float __fastcall GetPixelzDepth(int x, int y);
	float __fastcall PixelToDistance_OLD(int x, int y);
	float __fastcall PixelToDistance(int x, int y);
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property int DataSize = {read=FDataSize, nodefault};
	__property PZArray Data = {read=FData};
	__property TZArrayIdx DataIdx = {read=FDataIdx};
	__property TZArrayIdx DataInvIdx = {read=FDataIdx};
	void __fastcall Refresh();
	Stage::Vectorgeometry::TAffineVector __fastcall FastScreenToVector(int x, int y);
	Stage::Vectorgeometry::TAffineVector __fastcall FastVectorToScreen(const Stage::Vectorgeometry::TAffineVector &vec);
	Stage::Vectorgeometry::TAffineVector __fastcall PixelToWorld(const int x, const int y);
	bool __fastcall WorldToPixel(const Stage::Vectorgeometry::TAffineVector &aPoint, /* out */ int &pixX, /* out */ int &pixY, /* out */ float &pixZ);
	bool __fastcall WorldToPixelZ(const Stage::Vectorgeometry::TAffineVector &aPoint, /* out */ int &pixX, /* out */ int &pixY, /* out */ float &pixZ)/* overload */;
	bool __fastcall WorldToPixelZ(const Stage::Vectorgeometry::TAffineVector &aPoint, /* out */ float &pixX, /* out */ float &pixY, /* out */ float &pixZ)/* overload */;
	bool __fastcall OrthWorldToPixelZ(const Stage::Vectorgeometry::TAffineVector &aPoint, /* out */ float &pixX, /* out */ float &pixY, /* out */ float &pixZ);
};


class PASCALIMPLEMENTATION TgxZShadows : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	Gxs::Sceneviewer::TgxSceneViewer* FViewer;
	Gxs::Scene::TgxMemoryViewer* FCaster;
	bool FDepthFade;
	bool FFrustShadow;
	bool FSkyShadow;
	TOptimise FOptimise;
	PAArray FData;
	TAArrayIdx FDataIdx;
	TAArrayIdx FDataInvIdx;
	int FDataSize;
	int FWidth;
	int FHeight;
	int FXRes;
	int FYRes;
	bool Fsoft;
	float FTolerance;
	Gxs::Color::TgxColor* FColor;
	Gxs::Graphics::TgxPixel32 SCol;
	bool FTexturePrepared;
	Gxs::Context::TgxTextureHandle* FTexHandle;
	
protected:
	void __fastcall PrepareAlphaMemory();
	Gxs::Sceneviewer::TgxSceneViewer* __fastcall GetViewer();
	void __fastcall SetViewer(Gxs::Sceneviewer::TgxSceneViewer* const val);
	Gxs::Scene::TgxMemoryViewer* __fastcall GetCaster();
	void __fastcall SetCaster(Gxs::Scene::TgxMemoryViewer* const val);
	void __fastcall CalcShadowTexture(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	System::Byte __fastcall HardSet(const int x, const int y);
	System::Byte __fastcall SoftTest(const int x, const int y);
	void __fastcall SetWidth(const int val);
	void __fastcall SetHeight(const int val);
	void __fastcall SetXRes(const int val);
	void __fastcall SetYRes(const int val);
	void __fastcall SetSoft(const bool val);
	void __fastcall BindTexture();
	
public:
	TgxZBuffer* ViewerZBuf;
	TgxZBuffer* CasterZBuf;
	__fastcall virtual TgxZShadows(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxZShadows();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	
__published:
	__property Gxs::Sceneviewer::TgxSceneViewer* Viewer = {read=GetViewer, write=SetViewer};
	__property Gxs::Scene::TgxMemoryViewer* Caster = {read=GetCaster, write=SetCaster};
	__property bool FrustShadow = {read=FFrustShadow, write=FFrustShadow, nodefault};
	__property bool SkyShadow = {read=FSkyShadow, write=FSkyShadow, nodefault};
	__property TOptimise Optimise = {read=FOptimise, write=FOptimise, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property Gxs::Color::TgxColor* Color = {read=FColor, write=FColor};
	__property bool Soft = {read=Fsoft, write=SetSoft, nodefault};
	__property float Tolerance = {read=FTolerance, write=FTolerance};
	__property ObjectsSorting = {default=0};
	__property Visible = {default=1};
	__property bool DepthFade = {read=FDepthFade, write=FDepthFade, nodefault};
	bool __fastcall CastShadow();
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxZShadows(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Zbuffer */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ZBUFFER)
using namespace Gxs::Zbuffer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_zBufferHPP
