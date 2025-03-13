// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.SpaceText.pas' rev: 36.00 (Windows)

#ifndef GXS_SpaceTextHPP
#define GXS_SpaceTextHPP

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
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <System.SysUtils.hpp>
#include <FMX.Graphics.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Strings.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Texture.hpp>
#include <GXS.Context.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Spacetext
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTextAdjust;
struct TFontEntry;
class DELPHICLASS TgxSpaceText;
class DELPHICLASS TFontManager;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TgxSpaceTextCharRange : unsigned char { stcrDefault, stcrAlphaNum, stcrNumbers, stcrWide };

enum DECLSPEC_DENUM TgxTextHorzAdjust : unsigned char { haLeft, haCenter, haRight, haAligned, haCentrically, haFitIn };

enum DECLSPEC_DENUM TgxTextVertAdjust : unsigned char { vaTop, vaCenter, vaBottom, vaBaseLine };

class PASCALIMPLEMENTATION TgxTextAdjust : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TgxTextHorzAdjust FHorz;
	TgxTextVertAdjust FVert;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetHorz(const TgxTextHorzAdjust Value);
	void __fastcall SetVert(const TgxTextVertAdjust Value);
	
public:
	__fastcall TgxTextAdjust();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property TgxTextHorzAdjust Horz = {read=FHorz, write=SetHorz, default=0};
	__property TgxTextVertAdjust Vert = {read=FVert, write=SetVert, default=3};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TgxTextAdjust() { }
	
};


typedef TFontEntry *PFontEntry;

struct DECLSPEC_DRECORD TFontEntry
{
	
private:
	typedef System::DynamicArray<_GLYPHMETRICSFLOAT> _TFontEntry__1;
	
	
public:
	System::UnicodeString Name;
	Gxs::Context::TgxVirtualHandleTransf* FVirtualHandle;
	System::Uitypes::TFontStyles Styles;
	float Extrusion;
	int RefCount;
	float allowedDeviation;
	int firstChar;
	int lastChar;
	_TFontEntry__1 glyphMetrics;
	System::Classes::TList* FClients;
};


class PASCALIMPLEMENTATION TgxSpaceText : public Gxs::Scene::TgxSceneObject
{
	typedef Gxs::Scene::TgxSceneObject inherited;
	
private:
	Fmx::Graphics::TFont* FFont;
	float FExtrusion;
	float FAllowedDeviation;
	TgxSpaceTextCharRange FCharacterRange;
	TgxTextAdjust* FAdjust;
	float FAspectRatio;
	float FOblique;
	float FTextHeight;
	System::Classes::TStringList* FLines;
	void __fastcall SetCharacterRange(const TgxSpaceTextCharRange val);
	void __fastcall SetAllowedDeviation(const float val);
	void __fastcall SetExtrusion(float AValue);
	void __fastcall SetFont(Fmx::Graphics::TFont* AFont);
	System::WideString __fastcall GetText();
	void __fastcall SetLines(System::Classes::TStringList* const Value);
	void __fastcall SetText(const System::WideString AText);
	void __fastcall SetAdjust(TgxTextAdjust* const Value);
	void __fastcall SetAspectRatio(const float Value);
	void __fastcall SetOblique(const float Value);
	void __fastcall SetTextHeight(const float Value);
	
protected:
	PFontEntry FTextFontEntry;
	bool FontChanged;
	virtual void __fastcall DestroyHandle();
	void __fastcall OnFontChange(System::TObject* sender);
	void __fastcall GetFirstAndLastChar(int &firstChar, int &lastChar);
	virtual void __fastcall DoOnLinesChange(System::TObject* sender);
	
public:
	__fastcall virtual TgxSpaceText(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxSpaceText();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	float __fastcall TextWidth(const System::WideString str = System::WideString());
	float __fastcall TextMaxHeight(const System::WideString str = System::WideString());
	float __fastcall TextMaxUnder(const System::WideString str = System::WideString());
	void __fastcall TextMetrics(const System::WideString str, /* out */ float &width, /* out */ float &maxHeight, /* out */ float &maxUnder);
	void __fastcall NotifyFontChanged();
	virtual void __fastcall NotifyChange(System::TObject* sender);
	virtual void __fastcall DefaultHandler(void *Message);
	virtual Stage::Vectortypes::TVector4f __fastcall AxisAlignedDimensionsUnscaled();
	virtual Stage::Vectortypes::TVector4f __fastcall BarycenterAbsolutePosition();
	
__published:
	__property float Extrusion = {read=FExtrusion, write=SetExtrusion};
	__property Fmx::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property System::WideString Text = {read=GetText, write=SetText, stored=false};
	__property System::Classes::TStringList* Lines = {read=FLines, write=SetLines};
	__property float allowedDeviation = {read=FAllowedDeviation, write=SetAllowedDeviation};
	__property TgxSpaceTextCharRange CharacterRange = {read=FCharacterRange, write=SetCharacterRange, default=0};
	__property float AspectRatio = {read=FAspectRatio, write=SetAspectRatio};
	__property float TextHeight = {read=FTextHeight, write=SetTextHeight};
	__property float Oblique = {read=FOblique, write=SetOblique};
	__property TgxTextAdjust* Adjust = {read=FAdjust, write=SetAdjust};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxSpaceText(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxSceneObject(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TFontManager : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	int FCurrentBase;
	
protected:
	void __fastcall NotifyClients(System::Classes::TList* Clients);
	void __fastcall VirtualHandleAlloc(Gxs::Context::TgxVirtualHandle* sender, unsigned &handle);
	void __fastcall VirtualHandleDestroy(Gxs::Context::TgxVirtualHandle* sender, unsigned &handle);
	
public:
	__fastcall TFontManager();
	__fastcall virtual ~TFontManager();
	PFontEntry __fastcall FindFont(System::UnicodeString AName, System::Uitypes::TFontStyles FStyles, float FExtrusion, float FAllowedDeviation, int FFirstChar, int FLastChar);
	PFontEntry __fastcall GetFontBase(System::UnicodeString AName, System::Uitypes::TFontStyles FStyles, float FExtrusion, float allowedDeviation, int firstChar, int lastChar, System::TObject* client);
	void __fastcall Release(PFontEntry entry, System::TObject* client);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE unsigned vFontManagerMsgID;
extern DELPHI_PACKAGE TFontManager* __fastcall FontManager(void);
extern DELPHI_PACKAGE void __fastcall ReleaseFontManager(void);
}	/* namespace Spacetext */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_SPACETEXT)
using namespace Gxs::Spacetext;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_SpaceTextHPP
