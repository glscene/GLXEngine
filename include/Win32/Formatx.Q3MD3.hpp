// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formatx.Q3MD3.pas' rev: 36.00 (Windows)

#ifndef Formatx_Q3MD3HPP
#define Formatx_Q3MD3HPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Material.hpp>
#include <Formatx.MD3.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formatx
{
namespace Q3md3
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TMD3TagList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TMD3TagList : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<Formatx::Md3::TMD3Tag> _TMD3TagList__1;
	
	
private:
	_TMD3TagList__1 FTags;
	int FNumTags;
	int FNumFrames;
	Formatx::Md3::TMD3Tag __fastcall GetTag(int index);
	
public:
	void __fastcall LoadFromFile(System::UnicodeString FileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	Stage::Vectortypes::TMatrix4f __fastcall GetTransform(System::UnicodeString TagName, int Frame);
	__property int TagCount = {read=FNumTags, nodefault};
	__property int FrameCount = {read=FNumFrames, nodefault};
	__property Formatx::Md3::TMD3Tag Tags[int index] = {read=GetTag};
public:
	/* TObject.Create */ inline __fastcall TMD3TagList() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMD3TagList() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall LoadQ3Anims(Gxs::Vectorfileobjects::TgxActorAnimations* Animations, System::UnicodeString FileName, System::UnicodeString NamePrefix)/* overload */;
extern DELPHI_PACKAGE void __fastcall LoadQ3Anims(Gxs::Vectorfileobjects::TgxActorAnimations* Animations, System::Classes::TStrings* Strings, System::UnicodeString NamePrefix)/* overload */;
extern DELPHI_PACKAGE void __fastcall LoadQ3Skin(System::UnicodeString FileName, Gxs::Vectorfileobjects::TgxActor* Actor);
}	/* namespace Q3md3 */
}	/* namespace Formatx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX_Q3MD3)
using namespace Formatx::Q3md3;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX)
using namespace Formatx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formatx_Q3MD3HPP
