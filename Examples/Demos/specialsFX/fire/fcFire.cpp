/*****************************************************************************
						  GLScene Graphics Engine
******************************************************************************/
#include <vcl.h>
#pragma hdrstop
#include "fcFire.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.BaseClasses"
#pragma link "Stage.Coordinates"
#pragma link "GLS.Behaviours"
#pragma link "GLS.Cadencer"
#pragma link "GLS.FireFX"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma resource "*.dfm"
TFormFire *FormFire;
int mx,my;
//---------------------------------------------------------------------------
__fastcall TFormFire::TFormFire(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormFire::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
		  TPoint &MousePos, bool &Handled)
{
 GLCamera1->AdjustDistanceToTarget(Power(1.1, WheelDelta/120));
}
//---------------------------------------------------------------------------
void __fastcall TFormFire::Timer1Timer(TObject *Sender)
{
  Caption = "Fire - "+ Format("%.1f FPS", ARRAYOFCONST((GLSceneViewer1->FramesPerSecond())));
  GLSceneViewer1->ResetPerformanceMonitor();
}
//---------------------------------------------------------------------------
void __fastcall TFormFire::GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
  if (Shift.Contains(ssLeft))
	  GLCamera1->MoveAroundTarget(my-Y, mx-X);
   mx = X;
   my = Y;
}
//---------------------------------------------------------------------------
void __fastcall TFormFire::GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   mx = X; my = Y;
}
//---------------------------------------------------------------------------
