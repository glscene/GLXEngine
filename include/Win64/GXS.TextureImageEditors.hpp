// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.TextureImageEditors.pas' rev: 36.00 (Windows)

#ifndef GXS_TextureImageEditorsHPP
#define GXS_TextureImageEditorsHPP

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
#include <GXS.Texture.hpp>
#include <GXS.ProcTextures.hpp>
#include <GXS.ImageUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Textureimageeditors
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxTextureImageEditor;
class DELPHICLASS TgxBlankTIE;
class DELPHICLASS TgxPersistentTIE;
class DELPHICLASS TgxPicFileTIE;
class DELPHICLASS TgxProcTextureNoiseTIE;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxTextureImageEditor : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual __classmethod bool __fastcall Edit(Gxs::Texture::TgxTextureImage* aTexImage) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TgxTextureImageEditor() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxTextureImageEditor() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TgxTextureImageEditorClass);

class PASCALIMPLEMENTATION TgxBlankTIE : public TgxTextureImageEditor
{
	typedef TgxTextureImageEditor inherited;
	
public:
	__classmethod virtual bool __fastcall Edit(Gxs::Texture::TgxTextureImage* aTexImage);
public:
	/* TObject.Create */ inline __fastcall TgxBlankTIE() : TgxTextureImageEditor() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxBlankTIE() { }
	
};


class PASCALIMPLEMENTATION TgxPersistentTIE : public TgxTextureImageEditor
{
	typedef TgxTextureImageEditor inherited;
	
public:
	__classmethod virtual bool __fastcall Edit(Gxs::Texture::TgxTextureImage* aTexImage);
public:
	/* TObject.Create */ inline __fastcall TgxPersistentTIE() : TgxTextureImageEditor() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxPersistentTIE() { }
	
};


class PASCALIMPLEMENTATION TgxPicFileTIE : public TgxTextureImageEditor
{
	typedef TgxTextureImageEditor inherited;
	
public:
	__classmethod virtual bool __fastcall Edit(Gxs::Texture::TgxTextureImage* aTexImage);
public:
	/* TObject.Create */ inline __fastcall TgxPicFileTIE() : TgxTextureImageEditor() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxPicFileTIE() { }
	
};


class PASCALIMPLEMENTATION TgxProcTextureNoiseTIE : public TgxTextureImageEditor
{
	typedef TgxTextureImageEditor inherited;
	
public:
	__classmethod virtual bool __fastcall Edit(Gxs::Texture::TgxTextureImage* aTexImage);
public:
	/* TObject.Create */ inline __fastcall TgxProcTextureNoiseTIE() : TgxTextureImageEditor() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TgxProcTextureNoiseTIE() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall EditTextureImage(Gxs::Texture::TgxTextureImage* aTexImage);
extern DELPHI_PACKAGE void __fastcall RegisterTextureImageEditor(Gxs::Texture::TgxTextureImageClass aTexImageClass, TgxTextureImageEditorClass texImageEditor);
extern DELPHI_PACKAGE void __fastcall UnRegisterTextureImageEditor(TgxTextureImageEditorClass texImageEditor);
}	/* namespace Textureimageeditors */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_TEXTUREIMAGEEDITORS)
using namespace Gxs::Textureimageeditors;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_TextureImageEditorsHPP
