// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.ROAMPatch.pas' rev: 36.00 (Windows)

#ifndef GXS_ROAMPatchHPP
#define GXS_ROAMPatchHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.XOpenGL.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.Strings.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.Isolines.hpp>
#include <GXS.Context.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Roampatch
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLROAMException;
struct TgxROAMTriangleNode;
struct TgxROAMRenderPoint;
class DELPHICLASS TgxROAMPatch;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EGLROAMException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLROAMException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLROAMException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLROAMException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLROAMException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLROAMException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLROAMException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLROAMException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLROAMException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLROAMException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLROAMException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLROAMException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLROAMException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLROAMException() { }
	
};

#pragma pack(pop)

typedef TgxROAMTriangleNode *PROAMTriangleNode;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxROAMTriangleNode
{
public:
	PROAMTriangleNode Base;
	PROAMTriangleNode Left;
	PROAMTriangleNode Right;
	PROAMTriangleNode LeftChild;
	PROAMTriangleNode RightChild;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxROAMRenderPoint
{
public:
	int X;
	int Y;
	int Idx;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TgxROAMPatch : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<unsigned> _TgxROAMPatch__1;
	
	
private:
	int FID;
	Gxs::Heightdata::TgxHeightData* FHeightData;
	Gxs::Heightdata::PSmallIntRaster FHeightRaster;
	PROAMTriangleNode FTLNode;
	PROAMTriangleNode FBRNode;
	_TgxROAMPatch__1 FTLVariance;
	_TgxROAMPatch__1 FBRVariance;
	int FPatchSize;
	int FTriangleCount;
	Gxs::Context::TgxListHandle* FListHandle;
	int FTag;
	Stage::Vectorgeometry::TAffineVector FObserverPosition;
	TgxROAMPatch* FNorth;
	TgxROAMPatch* FSouth;
	TgxROAMPatch* FWest;
	TgxROAMPatch* FEast;
	bool FHighRes;
	int FMaxDepth;
	Stage::Vectorgeometry::TAffineVector FVertexScale;
	Stage::Vectorgeometry::TAffineVector FVertexOffset;
	Stage::Vectorgeometry::TAffineVector FTextureScale;
	Stage::Vectorgeometry::TAffineVector FTextureOffset;
	int FMaxTLVarianceDepth;
	int FMaxBRVarianceDepth;
	Gxs::Context::TgxOcclusionQueryHandle* FOcclusionQuery;
	int FOcclusionSkip;
	int FOcclusionCounter;
	bool FLastOcclusionTestPassed;
	int FContourInterval;
	int FContourWidth;
	
protected:
	void __fastcall SetHeightData(Gxs::Heightdata::TgxHeightData* Val);
	void __fastcall SetOcclusionSkip(int Val);
	void __fastcall RenderROAM(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, Gxs::Vectorlists::TgxTexPointList* TexCoords);
	void __fastcall RenderAsStrips(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, Gxs::Vectorlists::TgxTexPointList* TexCoords);
	
public:
	__fastcall TgxROAMPatch();
	__fastcall virtual ~TgxROAMPatch();
	void __fastcall ComputeVariance(int Variance);
	void __fastcall ResetTessellation();
	void __fastcall ConnectToTheWest(TgxROAMPatch* WestPatch);
	void __fastcall ConnectToTheNorth(TgxROAMPatch* NorthPatch);
	bool __fastcall Tesselate();
	bool __fastcall SafeTesselate();
	void __fastcall RenderHighRes(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, Gxs::Vectorlists::TgxTexPointList* TexCoords, bool ForceROAM);
	void __fastcall RenderAccum(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, Gxs::Vectorlists::TgxTexPointList* TexCoords, int AutoFlushVertexCount);
	__classmethod void __fastcall FlushAccum(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, Gxs::Vectorlists::TgxTexPointList* TexCoords);
	__property Gxs::Heightdata::TgxHeightData* HeightData = {read=FHeightData, write=SetHeightData};
	__property Stage::Vectorgeometry::TAffineVector VertexScale = {read=FVertexScale, write=FVertexScale};
	__property Stage::Vectorgeometry::TAffineVector VertexOffset = {read=FVertexOffset, write=FVertexOffset};
	__property Stage::Vectorgeometry::TAffineVector ObserverPosition = {read=FObserverPosition, write=FObserverPosition};
	__property Stage::Vectorgeometry::TAffineVector TextureScale = {read=FTextureScale, write=FTextureScale};
	__property Stage::Vectorgeometry::TAffineVector TextureOffset = {read=FTextureOffset, write=FTextureOffset};
	__property bool HighRes = {read=FHighRes, write=FHighRes, nodefault};
	__property int OcclusionSkip = {read=FOcclusionSkip, write=SetOcclusionSkip, nodefault};
	__property int OcclusionCounter = {read=FOcclusionCounter, write=FOcclusionCounter, nodefault};
	__property bool LastOcclusionTestPassed = {read=FLastOcclusionTestPassed, nodefault};
	__property int ID = {read=FID, nodefault};
	__property int TriangleCount = {read=FTriangleCount, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property int ContourInterval = {read=FContourInterval, write=FContourInterval, default=0};
	__property int ContourWidth = {read=FContourWidth, write=FContourWidth, default=1};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall SetROAMTrianglesCapacity(int nb);
extern DELPHI_PACKAGE int __fastcall GetROAMTrianglesCapacity(void);
extern DELPHI_PACKAGE void __fastcall DrawContours(Gxs::Vectorlists::TgxAffineVectorList* Vertices, Gxs::Vectorlists::TgxIntegerList* VertexIndices, int ContourInterval, int ContourWidth, int DecVal);
}	/* namespace Roampatch */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ROAMPATCH)
using namespace Gxs::Roampatch;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_ROAMPatchHPP
