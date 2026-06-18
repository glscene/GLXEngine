//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcEarth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.BaseClasses"
#pragma link "GLS.Cadencer"
#pragma link "Stage.Coordinates"
#pragma link "GLS.LensFlare"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.SkyDome"
#pragma link "GLSL.TextureShaders"
#pragma resource "*.dfm"
TfrmEarth *frmEarth;
//---------------------------------------------------------------------------
__fastcall TfrmEarth::TfrmEarth(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
