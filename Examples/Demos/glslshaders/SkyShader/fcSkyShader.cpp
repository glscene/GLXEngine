//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcSkyShader.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.Objects"
#pragma link "GLS.Texture"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma resource "*.dfm"
TFormSkyShader *FormSkyShader;
//---------------------------------------------------------------------------
__fastcall TFormSkyShader::TFormSkyShader(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSkyShader::FormCreate(TObject *Sender)
{
  Path = GetCurrentAssetPath();
  // Loading a cubemap as TGLCompositeImage
  SetCurrentDir(Path  + "\cubemap");
  Cubemap = new TGLTexture(this);
  LoadCubemap();
  Sky->Radius = Camera->DepthOfView;
  Sky->Material->Texture = Cubemap;
  Sphere->Material->Texture = Cubemap;
  Thor->Material->Texture = Cubemap;
}
//---------------------------------------------------------------------------


void __fastcall TFormSkyShader::LoadCubemap()
{
  Cubemap->ImageClassName = "TglCompositeImage";
  Cubemap->Image->LoadFromFile("skybox.dds");
  Cubemap->TextureWrap = twNone;
  Cubemap->FilteringQuality = tfAnisotropic;
  Cubemap->Disabled = False;
}
