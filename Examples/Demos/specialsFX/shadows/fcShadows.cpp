//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcShadows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.AsyncTimer"
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Behaviours"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"

#pragma link "GLS.GeomObjects"
#pragma link "GLS.Graph"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.zBuffer"
#pragma resource "*.dfm"
TFormShadows *FormShadows;
//---------------------------------------------------------------------------
__fastcall TFormShadows::TFormShadows(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::FormCreate(TObject *Sender)
{
 TFileName Path = GetCurrentAssetPath();
 SetCurrentDir(Path  + "\\texture");
 GLMaterialLibrary1->Materials->Items[2]->Material->Texture->Image->LoadFromFile("marbletiles.jpg");
 GLMaterialLibrary1->Materials->Items[2]->Material->Texture->Disabled = false;
 GLMaterialLibrary1->Materials->Items[3]->Material->Texture->Image->LoadFromFile("beigemarble.jpg");
 GLMaterialLibrary1->Materials->Items[3]->Material->Texture->Disabled = false;
 RotateBoxClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::ViewerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
 mx = X; my = Y;
 ActiveControl = DistanceBar;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::ViewerMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
   if (Shift.Contains(ssLeft) || Shift.Contains(ssRight))
	 GLCamera1->MoveAroundTarget(my-Y, mx-X);
   mx = X; my = Y;
   GLCadencer1->Progress();
   Viewer->Refresh();
   Caster->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::CasterMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 mx2 = X; my2 = Y;
 ActiveControl = DistanceBar2;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::CasterMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
   if (Shift.Contains(ssLeft) || Shift.Contains(ssRight))
	 GLCamera2->MoveAroundTarget(my2-Y, mx2-X);
   mx2 = X; my2 = Y;
   if (Shift.Contains(ssLeft) || Shift.Contains(ssRight))
   {
	  Shadows1->CastShadow();
	  GLCadencer1->Progress();
	  Viewer->Refresh();
	  Caster->Refresh();
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::DistanceBarChange(TObject *Sender)
{
  float Dist = GLCamera1->DistanceToTarget();
  float  NewDist = ((float)DistanceBar->Position/4)*((float)DistanceBar->Position/4)+1;
  GLCamera1->Position->AsAffineVector = VectorScale(GLCamera1->Position->AsAffineVector, (float)NewDist/Dist);
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::DistanceBar2Change(TObject *Sender)
{
  float Dist = GLCamera2->DistanceToTarget();
  float  NewDist = ((float)DistanceBar2->Position/4)*((float)DistanceBar2->Position/4)+1;
  GLCamera2->Position->AsAffineVector = VectorScale(GLCamera2->Position->AsAffineVector, (float)NewDist/Dist);
  Shadows1->CastShadow();
  Caster->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::CastBtnClick(TObject *Sender)
{
 double RefTime = GLCadencer1->GetCurrenttime();
 Shadows1->CastShadow();
 Viewer->Refresh();
/// TimeLbl->Caption = IntToStr(Int((GLCadencer1->GetCurrenttime()-(int)RefTime)*100));

}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::ViewerMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  Viewer->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::CasterMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 Shadows1->CastShadow();
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::FadeBoxClick(TObject *Sender)
{
  Shadows1->DepthFade = FadeBox->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TFormShadows::HeightField1GetHeight2(TObject *Sender, const float x, const float y,
		  float &z, TGLColorVector &Color, TTexPoint &TexPoint)
{
  z = 0;
}

//---------------------------------------------------------------------------

void __fastcall TFormShadows::FrustBoxClick(TObject *Sender)
{
  Shadows1->FrustShadow = FrustBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::AsyncTimer1Timer(TObject *Sender)
{
  Caption = "Shadows " + Format("%.2f FPS",
	ARRAYOFCONST ((Viewer->FramesPerSecond())));
  Viewer->ResetPerformanceMonitor();
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::RotateBoxClick(TObject *Sender)
{
//GLAsyncTimer1->Enabled =RotateBox->Checked;
  GLCadencer1->Enabled = RotateBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::ShadowOnBoxClick(TObject *Sender)
{
  Shadows1->Visible = ShadowOnBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::SoftBoxClick(TObject *Sender)
{
 Shadows1->Soft = SoftBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::SkyShadBoxClick(TObject *Sender)
{
 Shadows1->SkyShadow = SkyShadBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::FocalChange(TObject *Sender)
{
 GLCamera2->FocalLength = Focal->Position;
 MemView->Render();
 Caster->Refresh();
 Shadows1->CastShadow();
 Viewer->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormShadows::dovBarChange(TObject *Sender)
{
 GLCamera2->DepthOfView = dovBar->Position;
 MemView->Render();
 Caster->Refresh();
 Shadows1->CastShadow();
 Viewer->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::AlphaBarChange(TObject *Sender)
{
  Shadows1->Color->Alpha = (float)AlphaBar->Position/256;
}
//---------------------------------------------------------------------------
void __fastcall TFormShadows::GLCadencer1Progress(TObject *Sender, const double deltaTime,
		  const double newTime)
{
   Shadows1->CastShadow();
}
//---------------------------------------------------------------------------

