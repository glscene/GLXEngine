// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.AVIRecorder.pas' rev: 36.00 (Windows)

#ifndef GXS_AVIRecorderHPP
#define GXS_AVIRecorderHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.UITypes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Types.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Scene.hpp>
#include <GXS.SceneViewer.hpp>
#include <Formatx.VFW.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Avirecorder
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxAVIRecorder;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TAVICompressor : unsigned char { acDefault, acShowDialog, acDivX };

typedef Formatx::Vfw::_di_IAVIStream *PAVIStream;

enum DECLSPEC_DENUM TAVISizeRestriction : unsigned char { srNoRestriction, srForceBlock2x2, srForceBlock4x4, srForceBlock8x8 };

enum DECLSPEC_DENUM TAVIRecorderState : unsigned char { rsNone, rsRecording };

enum DECLSPEC_DENUM TAVIImageRetrievalMode : unsigned char { irmSnapShot, irmRenderToBitmap, irmBitBlt };

typedef void __fastcall (__closure *TAVIRecorderPostProcessEvent)(System::TObject* Sender, Fmx::Graphics::TBitmap* frame);

class PASCALIMPLEMENTATION TgxAVIRecorder : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Fmx::Graphics::TBitmap* AVIBitmap;
	int AVIFrameIndex;
	int AVI_DPI;
	Formatx::Vfw::TAVIStreamInfo asi;
	Formatx::Vfw::_di_IAVIFile pfile;
	Formatx::Vfw::_di_IAVIStream Stream;
	Formatx::Vfw::_di_IAVIStream Stream_c;
	Winapi::Windows::PBitmapInfoHeader FBitmapInfo;
	void *FBitmapBits;
	unsigned FBitmapSize;
	System::UnicodeString FTempName;
	System::UnicodeString FAVIFilename;
	System::Byte FFPS;
	int FWidth;
	int FHeight;
	TAVISizeRestriction FSizeRestriction;
	TAVIImageRetrievalMode FImageRetrievalMode;
	TAVIRecorderState RecorderState;
	TAVIRecorderPostProcessEvent FOnPostProcessEvent;
	Gxs::Scene::TgxSceneBuffer* FBuffer;
	void __fastcall SetHeight(const int val);
	void __fastcall SetWidth(const int val);
	void __fastcall SetSizeRestriction(const TAVISizeRestriction val);
	void __fastcall SetGLXceneViewer(Gxs::Sceneviewer::TgxSceneViewer* const Value);
	void __fastcall SetVKNonVisualViewer(Gxs::Scene::TgxNonVisualViewer* const Value);
	
protected:
	Gxs::Sceneviewer::TgxSceneViewer* FGLXceneViewer;
	Gxs::Scene::TgxNonVisualViewer* FVKNonVisualViewer;
	TAVICompressor FCompressor;
	int __fastcall Restricted(int s);
	void __fastcall InternalAddAVIFrame();
	
public:
	__fastcall virtual TgxAVIRecorder(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxAVIRecorder();
	bool __fastcall CreateAVIFile(int DPI = 0x0);
	void __fastcall AddAVIFrame()/* overload */;
	void __fastcall AddAVIFrame(Fmx::Graphics::TBitmap* bmp)/* overload */;
	void __fastcall CloseAVIFile(bool UserAbort = false);
	bool __fastcall Recording();
	
__published:
	__property System::Byte FPS = {read=FFPS, write=FFPS, default=25};
	__property Gxs::Sceneviewer::TgxSceneViewer* GLXceneViewer = {read=FGLXceneViewer, write=SetGLXceneViewer};
	__property Gxs::Scene::TgxNonVisualViewer* VKNonVisualViewer = {read=FVKNonVisualViewer, write=SetVKNonVisualViewer};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property System::UnicodeString Filename = {read=FAVIFilename, write=FAVIFilename};
	__property TAVICompressor Compressor = {read=FCompressor, write=FCompressor, default=0};
	__property TAVISizeRestriction SizeRestriction = {read=FSizeRestriction, write=SetSizeRestriction, default=3};
	__property TAVIImageRetrievalMode ImageRetrievalMode = {read=FImageRetrievalMode, write=FImageRetrievalMode, default=2};
	__property TAVIRecorderPostProcessEvent OnPostProcessEvent = {read=FOnPostProcessEvent, write=FOnPostProcessEvent};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Avirecorder */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_AVIRECORDER)
using namespace Gxs::Avirecorder;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_AVIRecorderHPP
