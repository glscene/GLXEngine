/*****************************************************************************
						  GLScene Graphics Engine
******************************************************************************/
#include <vcl.h>
#pragma hdrstop
#include "fcBeer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.BaseClasses"
#pragma link "Stage.Coordinates"
#pragma link "Stage.Utils"

#pragma link "GLS.Cadencer"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.Objects"
#pragma link "GLS.ParticleFX"
#pragma link "GLS.PerlinPFX"
#pragma link "GLS.Scene"
#pragma link "GLS.ShadowPlane"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.File3DS"
#pragma link "GLS.FileJPEG"

#pragma resource "*.dfm"
TFormBeer *FormBeer;
int mx, my;
//---------------------------------------------------------------------------
__fastcall TFormBeer::TFormBeer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBeer::FormActivate(TObject *Sender)
{
   TFileName Path = GetCurrentAssetPath();

   SetCurrentDir(Path  + "\\model");
   GLFreeForm1->LoadFromFile("beer.3ds");

   SetCurrentDir(Path  + "\\texture");
   GLFreeForm1->Material->Texture->Image->LoadFromFile("clouds.jpg");
   GLShadowPlane1->Material->Texture->Image->LoadFromFile("ashwood.jpg");
   GetOrCreateSourcePFX(GLDummyCube3)->Burst(0, 150);
}
//---------------------------------------------------------------------------
void __fastcall TFormBeer::GLSceneViewer1DblClick(TObject *Sender)
{
  GLCadencer1->Enabled = !GLCadencer1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TFormBeer::GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
  if (Shift.Contains(ssShift))
	  GLCamera1->MoveAroundTarget(my-Y, mx-X);
   mx = X;
   my = Y;

}
//---------------------------------------------------------------------------
void __fastcall TFormBeer::GLCadencer1Progress(TObject *Sender, const double deltaTime,
		  const double newTime)
{
  GLCamera1->MoveAroundTarget(0, 10*deltaTime);
}
//---------------------------------------------------------------------------
