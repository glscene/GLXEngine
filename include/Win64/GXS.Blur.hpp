// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.Blur.pas' rev: 36.00 (Windows)

#ifndef GXS_BlurHPP
#define GXS_BlurHPP

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
#include <System.UITypes.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Objects.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Material.hpp>
#include <GXS.HUDObjects.hpp>
#include <GXS.Color.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <Stage.Strings.hpp>
#include <Stage.TextureFormat.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Blur
{
//-- forward type declarations -----------------------------------------------
struct TRGBPixel;
class DELPHICLASS EGLMotionBlurException;
class DELPHICLASS TgxBlur;
class DELPHICLASS TgxMotionBlur;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxBlurPreset : unsigned char { pNone, pGlossy, pBeastView, pOceanDepth, pDream, pOverBlur, pAdvancedBlur };

enum DECLSPEC_DENUM TgxBlurkind : unsigned char { bNone, bSimple, bAdvanced };

struct DECLSPEC_DRECORD TRGBPixel
{
public:
	System::Byte R;
	System::Byte G;
	System::Byte B;
};


typedef System::DynamicArray<TRGBPixel> TRGBPixelBuffer;

typedef void __fastcall (__closure *TgxAdvancedBlurImagePrepareEvent)(System::TObject* Sender, Gxs::Graphics::TgxBitmap32* BMP32, bool &DoBlur);

class PASCALIMPLEMENTATION EGLMotionBlurException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLMotionBlurException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLMotionBlurException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLMotionBlurException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLMotionBlurException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLMotionBlurException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLMotionBlurException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLMotionBlurException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLMotionBlurException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLMotionBlurException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLMotionBlurException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLMotionBlurException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLMotionBlurException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLMotionBlurException() { }
	
};


class PASCALIMPLEMENTATION TgxBlur : public Gxs::Hudobjects::TgxHUDSprite
{
	typedef Gxs::Hudobjects::TgxHUDSprite inherited;
	
private:
	Gxs::Scene::TgxMemoryViewer* FViewer;
	double OldTime;
	bool FDoingMemView;
	double FBlurDeltaTime;
	float FBlurTop;
	float FBlurBottom;
	float FBlurLeft;
	float FBlurRight;
	int FRenderHeight;
	int FRenderWidth;
	TgxBlurPreset FPreset;
	Gxs::Scene::TgxBaseSceneObject* FTargetObject;
	TgxAdvancedBlurImagePrepareEvent FOnAdvancedBlurImagePrepareEvent;
	TgxBlurkind FBlur;
	TRGBPixelBuffer Pixelbuffer;
	int FAdvancedBlurPasses;
	System::Classes::TNotifyEvent FOnAfterTargetRender;
	System::Classes::TNotifyEvent FOnBeforeTargetRender;
	float FAdvancedBlurAmp;
	bool FBlurSelf;
	System::Byte FAdvancedBlurLowClamp;
	System::Byte FAdvancedBlurHiClamp;
	System::Uitypes::TColor FRenderBackgroundColor;
	void __fastcall DoMemView(Gxs::Scene::TgxBaseSceneObject* baseObject);
	void __fastcall SetRenderHeight(const int Value);
	void __fastcall SetRenderWidth(const int Value);
	void __fastcall UpdateImageSettings();
	void __fastcall SetPreset(const TgxBlurPreset Value);
	bool __fastcall StoreBlurBottom();
	bool __fastcall StoreBlurDeltaTime();
	bool __fastcall StoreBlurRight();
	bool __fastcall StoreBlurTop();
	bool __fastcall StoreBlurLeft();
	void __fastcall SetTargetObject(Gxs::Scene::TgxBaseSceneObject* const Value);
	void __fastcall SetOnAdvancedBlurImagePrepareEvent(const TgxAdvancedBlurImagePrepareEvent Value);
	void __fastcall SetBlur(const TgxBlurkind Value);
	void __fastcall SetAdvancedBlurPasses(const int Value);
	void __fastcall SetOnAfterTargetRender(const System::Classes::TNotifyEvent Value);
	void __fastcall SetOnBeforeTargetRender(const System::Classes::TNotifyEvent Value);
	void __fastcall SetAdvancedBlurAmp(const float Value);
	void __fastcall SetBlurSelf(const bool Value);
	void __fastcall SetAdvancedBlurLowClamp(const System::Byte Value);
	void __fastcall SetAdvancedBlurHiClamp(const System::Byte Value);
	void __fastcall SetRenderBackgroundColor(const System::Uitypes::TColor Value);
	
public:
	__fastcall virtual TgxBlur(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxBlur();
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
__published:
	__property TgxBlurkind Blur = {read=FBlur, write=SetBlur, nodefault};
	__property double BlurDeltaTime = {read=FBlurDeltaTime, write=FBlurDeltaTime, stored=StoreBlurDeltaTime};
	__property float BlurLeft = {read=FBlurLeft, write=FBlurLeft, stored=StoreBlurLeft};
	__property float BlurTop = {read=FBlurTop, write=FBlurTop, stored=StoreBlurTop};
	__property float BlurRight = {read=FBlurRight, write=FBlurRight, stored=StoreBlurRight};
	__property float BlurBottom = {read=FBlurBottom, write=FBlurBottom, stored=StoreBlurBottom};
	__property int RenderWidth = {read=FRenderWidth, write=SetRenderWidth, default=256};
	__property int RenderHeight = {read=FRenderHeight, write=SetRenderHeight, default=256};
	__property TgxBlurPreset Preset = {read=FPreset, write=SetPreset, stored=false, nodefault};
	__property Gxs::Scene::TgxBaseSceneObject* TargetObject = {read=FTargetObject, write=SetTargetObject};
	__property int AdvancedBlurPasses = {read=FAdvancedBlurPasses, write=SetAdvancedBlurPasses, nodefault};
	__property float AdvancedBlurAmp = {read=FAdvancedBlurAmp, write=SetAdvancedBlurAmp};
	__property System::Byte AdvancedBlurLowClamp = {read=FAdvancedBlurLowClamp, write=SetAdvancedBlurLowClamp, nodefault};
	__property System::Byte AdvancedBlurHiClamp = {read=FAdvancedBlurHiClamp, write=SetAdvancedBlurHiClamp, nodefault};
	__property bool BlurSelf = {read=FBlurSelf, write=SetBlurSelf, nodefault};
	__property System::Uitypes::TColor RenderBackgroundColor = {read=FRenderBackgroundColor, write=SetRenderBackgroundColor, nodefault};
	__property TgxAdvancedBlurImagePrepareEvent OnAdvancedBlurImagePrepareEvent = {read=FOnAdvancedBlurImagePrepareEvent, write=SetOnAdvancedBlurImagePrepareEvent};
	__property System::Classes::TNotifyEvent OnBeforeTargetRender = {read=FOnBeforeTargetRender, write=SetOnBeforeTargetRender};
	__property System::Classes::TNotifyEvent OnAfterTargetRender = {read=FOnAfterTargetRender, write=SetOnAfterTargetRender};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxBlur(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Hudobjects::TgxHUDSprite(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxMotionBlur : public Gxs::Scene::TgxCustomSceneObject
{
	typedef Gxs::Scene::TgxCustomSceneObject inherited;
	
private:
	float FIntensity;
	bool __fastcall StoreIntensity();
	
protected:
	virtual void __fastcall DoOnAddedToParent();
	virtual void __fastcall InitializeObject(System::TObject* ASender, const Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
	
public:
	bool __fastcall SupportsRequiredExtensions();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__fastcall virtual TgxMotionBlur(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property float Intensity = {read=FIntensity, write=FIntensity, stored=StoreIntensity};
	__property Visible = {default=1};
	__property OnProgress;
	__property Behaviours;
	__property Effects;
	__property Hint = {default=0};
public:
	/* TgxCustomSceneObject.Destroy */ inline __fastcall virtual ~TgxMotionBlur() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxMotionBlur(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxCustomSceneObject(aParentOwner) { }
	
private:
	void *__IgxInitializable;	// Gxs::Scene::IgxInitializable 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EA40AE8E-79B3-42F5-ADF2-7A901B665E12}
	operator Gxs::Scene::_di_IgxInitializable()
	{
		Gxs::Scene::_di_IgxInitializable intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Scene::IgxInitializable*(void) { return (Gxs::Scene::IgxInitializable*)&__IgxInitializable; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Blur */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_BLUR)
using namespace Gxs::Blur;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_BlurHPP
