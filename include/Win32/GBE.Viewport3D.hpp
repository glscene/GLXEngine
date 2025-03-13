// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GBE.Viewport3D.pas' rev: 36.00 (Windows)

#ifndef GBE_Viewport3DHPP
#define GBE_Viewport3DHPP

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
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Types.hpp>
#include <System.Math.Vectors.hpp>
#include <System.DateUtils.hpp>
#include <System.UITypes.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Viewport3D.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Layouts.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gbe
{
namespace Viewport3d
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS THelpOpenControl3D;
class DELPHICLASS TGBEViewport3D;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION THelpOpenControl3D : public Fmx::Controls3d::TControl3D
{
	typedef Fmx::Controls3d::TControl3D inherited;
	
public:
	/* TControl3D.Create */ inline __fastcall virtual THelpOpenControl3D(System::Classes::TComponent* AOwner) : Fmx::Controls3d::TControl3D(AOwner) { }
	/* TControl3D.Destroy */ inline __fastcall virtual ~THelpOpenControl3D() { }
	
};


class PASCALIMPLEMENTATION TGBEViewport3D : public Fmx::Viewport3d::TViewport3D
{
	typedef Fmx::Viewport3d::TViewport3D inherited;
	
private:
	bool FDrawing;
	bool fActiveFPS;
	int fFPS;
	int fComputeFPS;
	Fmx::Graphics::TBitmap* FMyBitmap;
	Fmx::Types3d::TTexture* FMyTexture;
	Fmx::Types3d::TContext3D* fMyContext;
	unsigned fBackgroundColor;
	
protected:
	System::Generics::Collections::TList__1<Fmx::Controls3d::TControl3D*>* FMyRenderingList;
	System::Generics::Collections::TDictionary__2<Fmx::Controls3d::TCamera*,Fmx::Graphics::TBitmap*>* FMyViewList;
	System::TTime fheureDebut;
	HIDESBASE void __fastcall RebuildRenderingList();
	virtual void __fastcall Paint();
	virtual void __fastcall Resize();
	virtual void __fastcall DoAddObject(Fmx::Types::TFmxObject* const AObject);
	virtual void __fastcall DoRemoveObject(Fmx::Types::TFmxObject* const AObject);
	
public:
	__fastcall virtual TGBEViewport3D(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGBEViewport3D();
	Fmx::Graphics::TBitmap* __fastcall getBitmapFromView(Fmx::Controls3d::TCamera* camera);
	void __fastcall DoAddView(Fmx::Controls3d::TCamera* camera);
	void __fastcall DoRemoveView(Fmx::Controls3d::TCamera* camera);
	void __fastcall DoClearListView();
	__property Fmx::Types3d::TContext3D* MyContext = {read=fMyContext, write=fMyContext};
	__property unsigned BackgroundColor = {read=fBackgroundColor, write=fBackgroundColor, nodefault};
	
__published:
	__property bool ActiveFPS = {read=fActiveFPS, write=fActiveFPS, nodefault};
	__property int FPS = {read=fFPS, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Viewport3d */
}	/* namespace Gbe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE_VIEWPORT3D)
using namespace Gbe::Viewport3d;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GBE)
using namespace Gbe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GBE_Viewport3DHPP
