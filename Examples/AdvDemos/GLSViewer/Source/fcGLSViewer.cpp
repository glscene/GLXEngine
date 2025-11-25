//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcGLSViewer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.AsyncTimer"
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"
#pragma link "GLS.Graph"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.MultiPolygon"
#pragma link "GLS.Extrusion"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.SimpleNavigation"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.SkyDome"
#pragma link "GLS.Navigator"
#pragma resource "*.dfm"
TFormViewer *FormViewer;
TGLNaviCube *NaviCube;
//---------------------------------------------------------------------------
__fastcall TFormViewer::TFormViewer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormViewer::tvSceneClick(TObject *Sender)
{
 //
}
//---------------------------------------------------------------------------
void __fastcall TFormViewer::FormCreate(TObject *Sender)
{
  AssetPath = GetCurrentAssetPath();
  TextureDir = AssetPath + '\\texture';
  SetCurrentDir(TextureDir);

//  NaviCube = TGLNaviCube->CreateAsChild(Scene->Objects);
//  NaviCube->SceneViewer = snViewer;
//  NaviCube->FPS = 30;

 // instantiate our specific hidden-lines shader
//  hlShader = THiddenLineShader.Create(Self);
  ffObject->IgnoreMissingTextures = True;

  tvScene->FullExpand();
//  tvScene->Select(tvScene->Items[9]);  // goto to Cube
  tvSceneClick(this);
}
//---------------------------------------------------------------------------

