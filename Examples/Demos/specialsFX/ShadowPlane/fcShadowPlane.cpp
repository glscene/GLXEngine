//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcShadowPlane.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"

#pragma link "GLS.GeomObjects"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.ShadowPlane"
#pragma link "GLS.SceneViewer"
#pragma resource "*.dfm"
TFormShadowPlane *FormShadowPlane;
//---------------------------------------------------------------------------
__fastcall TFormShadowPlane::TFormShadowPlane(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormShadowPlane::FormCreate(TObject *Sender)
{
  TFileName Path = GetCurrentAssetPath();
  SetCurrentDir(Path  + "\\texture");
  GLMaterialLibrary->Materials->Items[0]->Material->Texture->Image->LoadFromFile("beigemarble.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TFormShadowPlane::GLCadencer1Progress(TObject *Sender, const double deltaTime,
		  const double newTime)
{
   DCLight->PitchAngle = Sin(newTime)*60;
   DCShadowing->TurnAngle = newTime*10;

}
//---------------------------------------------------------------------------

void __fastcall TFormShadowPlane::CBShadowsClick(TObject *Sender)
{
   if (CBShadows->Checked)
	  GLShadowPlane1->ShadowedLight = GLLightSource1;
   else
	  GLShadowPlane1->ShadowedLight = NULL;
   GLShadowPlane2->ShadowedLight = GLShadowPlane1->ShadowedLight;
   GLShadowPlane3->ShadowedLight = GLShadowPlane1->ShadowedLight;

}
//---------------------------------------------------------------------------

void __fastcall TFormShadowPlane::CBStencilClick(TObject *Sender)
{
   if (CBStencil->Checked)
	 GLShadowPlane1->ShadowOptions = GLShadowPlane1->ShadowOptions << spoUseStencil, spoScissor;
   else
	 GLShadowPlane1->ShadowOptions = GLShadowPlane1->ShadowOptions << spoScissor;
   GLShadowPlane2->ShadowOptions = GLShadowPlane1->ShadowOptions;
   GLShadowPlane3->ShadowOptions = GLShadowPlane1->ShadowOptions;
}
//---------------------------------------------------------------------------

void __fastcall TFormShadowPlane::Timer1Timer(TObject *Sender)
{
  Caption  = "Shadow Plane - " + Format("%.1f FPS",
	ARRAYOFCONST ((GLSceneViewer1->FramesPerSecond())));
  GLSceneViewer1->ResetPerformanceMonitor();
}
//---------------------------------------------------------------------------

