// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.AnimatedSprite.pas' rev: 36.00 (Windows)

#ifndef GXS_AnimatedSpriteHPP
#define GXS_AnimatedSpriteHPP

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
#include <System.Math.hpp>
#include <GXS.XCollection.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.PersistentClasses.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Context.hpp>
#include <GXS.Material.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.State.hpp>
#include <GXS.Coordinates.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Animatedsprite
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxSpriteAnimFrame;
class DELPHICLASS TgxSpriteAnimFrameList;
class DELPHICLASS TgxSpriteAnimMargins;
class DELPHICLASS TgxSpriteAnimation;
class DELPHICLASS TgxSpriteAnimationList;
class DELPHICLASS TgxAnimatedSprite;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxSpriteAnimFrame : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	int FOffsetX;
	int FOffsetY;
	int FWidth;
	int FHeight;
	void __fastcall DoChanged();
	
protected:
	void __fastcall SetOffsetX(const int Value);
	void __fastcall SetOffsetY(const int Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetHeight(const int Value);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	
public:
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	
__published:
	__property int OffsetX = {read=FOffsetX, write=SetOffsetX, nodefault};
	__property int OffsetY = {read=FOffsetY, write=SetOffsetY, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
public:
	/* TXCollectionItem.Create */ inline __fastcall virtual TgxSpriteAnimFrame(Gxs::Xcollection::TXCollection* aOwner) : Gxs::Xcollection::TXCollectionItem(aOwner) { }
	/* TXCollectionItem.Destroy */ inline __fastcall virtual ~TgxSpriteAnimFrame() { }
	
};


class PASCALIMPLEMENTATION TgxSpriteAnimFrameList : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	__fastcall virtual TgxSpriteAnimFrameList(System::Classes::TPersistent* aOwner);
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxSpriteAnimFrameList() { }
	
};


enum DECLSPEC_DENUM TgxSpriteFrameDimensions : unsigned char { sfdAuto, sfdManual };

class PASCALIMPLEMENTATION TgxSpriteAnimMargins : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TgxSpriteAnimation* FOwner;
	int FLeft;
	int FTop;
	int FRight;
	int FBottom;
	
protected:
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetRight(const int Value);
	void __fastcall SetBottom(const int Value);
	void __fastcall DoChanged();
	
public:
	__fastcall TgxSpriteAnimMargins(TgxSpriteAnimation* Animation);
	__property TgxSpriteAnimation* Owner = {read=FOwner};
	
__published:
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property int Right = {read=FRight, write=SetRight, nodefault};
	__property int Bottom = {read=FBottom, write=SetBottom, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxSpriteAnimMargins() { }
	
};


class PASCALIMPLEMENTATION TgxSpriteAnimation : public Gxs::Xcollection::TXCollectionItem
{
	typedef Gxs::Xcollection::TXCollectionItem inherited;
	
private:
	System::NativeInt FCurrentFrame;
	System::NativeInt FStartFrame;
	System::NativeInt FEndFrame;
	System::NativeInt FFrameWidth;
	System::NativeInt FFrameHeight;
	System::NativeInt FInterval;
	TgxSpriteAnimFrameList* FFrames;
	Gxs::Material::TgxLibMaterialName FLibMaterialName;
	Gxs::Material::TgxLibMaterial* FLibMaterialCached;
	TgxSpriteFrameDimensions FDimensions;
	TgxSpriteAnimMargins* FMargins;
	void __fastcall DoChanged();
	
protected:
	void __fastcall SetCurrentFrame(const System::NativeInt Value);
	void __fastcall SetFrameWidth(const System::NativeInt Value);
	void __fastcall SetFrameHeight(const System::NativeInt Value);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	void __fastcall SetDimensions(const TgxSpriteFrameDimensions Value);
	void __fastcall SetLibMaterialName(const Gxs::Material::TgxLibMaterialName val);
	Gxs::Material::TgxLibMaterial* __fastcall GetLibMaterialCached();
	void __fastcall SetInterval(const System::NativeInt Value);
	void __fastcall SetFrameRate(const float Value);
	float __fastcall GetFrameRate();
	virtual Gxs::Material::TgxAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	
public:
	__fastcall virtual TgxSpriteAnimation(Gxs::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TgxSpriteAnimation();
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	__property Gxs::Material::TgxLibMaterial* LibMaterialCached = {read=GetLibMaterialCached};
	
__published:
	__property System::NativeInt CurrentFrame = {read=FCurrentFrame, write=SetCurrentFrame};
	__property System::NativeInt StartFrame = {read=FStartFrame, write=FStartFrame};
	__property System::NativeInt EndFrame = {read=FEndFrame, write=FEndFrame};
	__property System::NativeInt FrameWidth = {read=FFrameWidth, write=SetFrameWidth};
	__property System::NativeInt FrameHeight = {read=FFrameHeight, write=SetFrameHeight};
	__property Gxs::Material::TgxLibMaterialName LibMaterialName = {read=FLibMaterialName, write=SetLibMaterialName};
	__property TgxSpriteAnimFrameList* Frames = {read=FFrames};
	__property TgxSpriteFrameDimensions Dimensions = {read=FDimensions, write=SetDimensions, nodefault};
	__property System::NativeInt Interval = {read=FInterval, write=SetInterval};
	__property float FrameRate = {read=GetFrameRate, write=SetFrameRate};
	__property TgxSpriteAnimMargins* Margins = {read=FMargins};
private:
	void *__IgxMaterialLibrarySupported;	// Gxs::Material::IgxMaterialLibrarySupported 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E442AF9-D212-4A5E-8A88-92F798BABFD1}
	operator Gxs::Material::_di_IgxMaterialLibrarySupported()
	{
		Gxs::Material::_di_IgxMaterialLibrarySupported intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Gxs::Material::IgxMaterialLibrarySupported*(void) { return (Gxs::Material::IgxMaterialLibrarySupported*)&__IgxMaterialLibrarySupported; }
	#endif
	
};


class PASCALIMPLEMENTATION TgxSpriteAnimationList : public Gxs::Xcollection::TXCollection
{
	typedef Gxs::Xcollection::TXCollection inherited;
	
public:
	__fastcall virtual TgxSpriteAnimationList(System::Classes::TPersistent* aOwner);
	__classmethod virtual Gxs::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
public:
	/* TXCollection.Destroy */ inline __fastcall virtual ~TgxSpriteAnimationList() { }
	
};


enum DECLSPEC_DENUM TgxSpriteAnimationMode : unsigned char { samNone, samPlayOnce, samLoop, samBounceForward, samBounceBackward, samLoopBackward };

class PASCALIMPLEMENTATION TgxAnimatedSprite : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	TgxSpriteAnimationList* FAnimations;
	Gxs::Material::TgxMaterialLibrary* FMaterialLibrary;
	int FAnimationIndex;
	int FInterval;
	int FRotation;
	int FPixelRatio;
	bool FMirrorU;
	bool FMirrorV;
	TgxSpriteAnimationMode FAnimationMode;
	double FCurrentFrameDelta;
	System::Classes::TNotifyEvent FOnFrameChanged;
	System::Classes::TNotifyEvent FOnEndFrameReached;
	System::Classes::TNotifyEvent FOnStartFrameReached;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteAnimations(System::Classes::TStream* Stream);
	void __fastcall ReadAnimations(System::Classes::TStream* Stream);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetInterval(const int val);
	void __fastcall SetAnimationIndex(const int val);
	void __fastcall SetAnimationMode(const TgxSpriteAnimationMode val);
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const val);
	void __fastcall SetPixelRatio(const int val);
	HIDESBASE void __fastcall SetRotation(const int val);
	void __fastcall SetMirrorU(const bool val);
	void __fastcall SetMirrorV(const bool val);
	void __fastcall SetFrameRate(const float Value);
	float __fastcall GetFrameRate();
	
public:
	__fastcall virtual TgxAnimatedSprite(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxAnimatedSprite();
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Gxs::Baseclasses::TgxProgressTimes &progressTime);
	void __fastcall NextFrame();
	
__published:
	__property TgxSpriteAnimationList* Animations = {read=FAnimations};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property int Interval = {read=FInterval, write=SetInterval, nodefault};
	__property int AnimationIndex = {read=FAnimationIndex, write=SetAnimationIndex, nodefault};
	__property TgxSpriteAnimationMode AnimationMode = {read=FAnimationMode, write=SetAnimationMode, nodefault};
	__property int PixelRatio = {read=FPixelRatio, write=SetPixelRatio, nodefault};
	__property int Rotation = {read=FRotation, write=SetRotation, nodefault};
	__property bool MirrorU = {read=FMirrorU, write=SetMirrorU, nodefault};
	__property bool MirrorV = {read=FMirrorV, write=SetMirrorV, nodefault};
	__property float FrameRate = {read=GetFrameRate, write=SetFrameRate};
	__property Position;
	__property Scale;
	__property Visible = {default=1};
	__property System::Classes::TNotifyEvent OnFrameChanged = {read=FOnFrameChanged, write=FOnFrameChanged};
	__property System::Classes::TNotifyEvent OnEndFrameReached = {read=FOnEndFrameReached, write=FOnEndFrameReached};
	__property System::Classes::TNotifyEvent OnStartFrameReached = {read=FOnStartFrameReached, write=FOnStartFrameReached};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxAnimatedSprite(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Animatedsprite */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_ANIMATEDSPRITE)
using namespace Gxs::Animatedsprite;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_AnimatedSpriteHPP
