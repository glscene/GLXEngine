//---------------------------------------------------------------------------

#include <vcl.h>
#include <tchar.h>
#include <math.h>
#pragma hdrstop

#include "fcPanoViewer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.Texture"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Material"
#pragma link "Stage.Keyboard"
#pragma resource "*.dfm"
TFormPanorama* FormPanorama;

//---------------------------------------------------------------------------
__fastcall TFormPanorama::TFormPanorama(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFormPanorama::FormCreate(TObject* Sender)
{
  Path = GetCurrentAssetPath();
  SetCurrentDir(Path + "\\panorana");
  OpenPictureDialog->InitialDir = Path + "\\panorama";
  OpenPictureDialog->FileName = "sejourstmathieu2048.jpg";
}

void __fastcall TFormPanorama::BtnLoadClick(TObject* Sender)
{
	if (OpenPictureDialog->Execute())
		GLMaterialLibrary->Materials->Items[0]
			->Material->Texture->Image->LoadFromFile(
				OpenPictureDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TFormPanorama::TrackBarFocalChange(TObject* Sender)
{
	Camera->FocalLength = TrackBarFocal->Position;
}

//---------------------------------------------------------------------------
void __fastcall TFormPanorama::GLCadencerProgress(
	TObject* Sender, const double deltaTime, const double newTime)
{
	const int step_size = 20;
	float delta;
	float dx, dy;
	delta = step_size * 40 / Camera->FocalLength * deltaTime;
	dx = 0;
	dy = 0;
	if (IsKeyDown(VK_LEFT))
		dx = dx + delta;
	if (IsKeyDown(VK_UP))
		dy = dy + delta;
	if (IsKeyDown(VK_RIGHT))
		dx = dx - delta;
	if (IsKeyDown(VK_DOWN))
		dy = dy - delta;
	PanCameraAround(dx, dy);
}
//---------------------------------------------------------------------------
void __fastcall TFormPanorama::FormKeyDown(
	TObject* Sender, WORD &Key, TShiftState Shift)
{
	Key = 0; // all keys handled by FormPanorama
}
//---------------------------------------------------------------------------
void TFormPanorama::PanCameraAround(float dx, float dy)
{
	pitch = pitch + dy;
	yaw = yaw - dx;

	if (pitch > 90)
		pitch = 90;
	if (pitch < -90)
		pitch = -90;
	if (yaw > 360)
		yaw = yaw - 360;
	if (yaw < 0)
		yaw = yaw + 360;

	Camera->Up->SetVector(0, 1, 0);
	Camera->Direction->SetVector(
		sin(DegToRad(yaw)), sin(DegToRad(pitch)), -cos(DegToRad(yaw)));

	LabelPitch->Caption = Format("Pitch: %3f", ARRAYOFCONST((pitch)));
	LabelYaw->Caption = Format("Yaw: %3f", ARRAYOFCONST((yaw)));
}

//---------------------------------------------------------------------------
void __fastcall TFormPanorama::GLSceneViewerMouseDown(
	TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	mx = X;
	my = Y;
}

//---------------------------------------------------------------------------
void __fastcall TFormPanorama::GLSceneViewerMouseMove(
	TObject* Sender, TShiftState Shift, int X, int Y)
{
	float dx, dy, f;
	if (Shift.Contains(ssLeft)) {
		f = 0.2 * 40 / Camera->FocalLength;
		dx = (X - mx) * f;
		dy = (Y - my) * f;
		PanCameraAround(dx, dy);
	}
	mx = X;
	my = Y;
}

//---------------------------------------------------------------------------
void __fastcall TFormPanorama::FormMouseWheel(TObject* Sender, TShiftState Shift,
	int WheelDelta, TPoint &MousePos, bool &Handled)
{
	TrackBarFocal->Position = TrackBarFocal->Position + (int)(2 * WheelDelta / 120);
}
//---------------------------------------------------------------------------

