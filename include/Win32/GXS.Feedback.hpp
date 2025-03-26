// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Feedback.pas' rev: 36.00 (Windows)

#ifndef GXS_FeedbackHPP
#define GXS_FeedbackHPP

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
#include <GXS.PersistentClasses.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <Stage.PipelineTransform.hpp>
#include <GXS.MeshUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Feedback
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxFeedback;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TFeedbackMode : unsigned char { fm2D, fm3D, fm3DColor, fm3DColorTexture, fm4DColorTexture };

class PASCALIMPLEMENTATION TgxFeedback : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	bool FActive;
	Gxs::Vectorlists::TgxSingleList* FBuffer;
	unsigned FMaxBufferSize;
	bool FBuffered;
	float FCorrectionScaling;
	TFeedbackMode FMode;
	
protected:
	void __fastcall SetMaxBufferSize(const unsigned Value);
	void __fastcall SetMode(const TFeedbackMode Value);
	
public:
	__fastcall virtual TgxFeedback(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxFeedback();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	void __fastcall BuildMeshFromBuffer(Gxs::Vectorlists::TgxAffineVectorList* Vertices = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* Normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxVectorList* Colors = (Gxs::Vectorlists::TgxVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* TexCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxIntegerList* VertexIndices = (Gxs::Vectorlists::TgxIntegerList*)(0x0));
	__property bool Buffered = {read=FBuffered, nodefault};
	__property Gxs::Vectorlists::TgxSingleList* Buffer = {read=FBuffer};
	__property float CorrectionScaling = {read=FCorrectionScaling};
	
__published:
	__property unsigned MaxBufferSize = {read=FMaxBufferSize, write=SetMaxBufferSize, nodefault};
	__property bool Active = {read=FActive, write=FActive, nodefault};
	__property TFeedbackMode Mode = {read=FMode, write=SetMode, nodefault};
	__property Visible = {default=1};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFeedback(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Feedback */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FEEDBACK)
using namespace Gxs::Feedback;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_FeedbackHPP
