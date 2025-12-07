//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcBunnyBump.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.AsyncTimer"
#pragma link "GLS.BaseClasses"
#pragma link "GLSL.BumpShaders"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.FileOBJ"

#pragma resource "*.dfm"
TFormBunny *FormBunny;
//---------------------------------------------------------------------------
__fastcall TFormBunny::TFormBunny(TComponent* Owner): TForm(Owner){}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::FormCreate(TObject *Sender)
{
  TFileName Path = GetCurrentAssetPath();
  SetCurrentDir(Path + "\\modelext");
  // Load the bunny mesh and scale for viewing
  Bunny->LoadFromFile("bunny.glsm");
  Bunny->Scale->Scale((float)(2/Bunny->BoundingSphereRadius()));
  Bunny->PitchAngle = 90;
  Bunny->RollAngle = 90;

  // Load the normal map
	SetCurrentDir(Path + "\\skin");
  GLMaterialLibrary1->Materials->Items[0]->Material->Texture->Image->LoadFromFile("bunnynormals.jpg");

  // Link the lights to their toggles
  CheckBox1->Tag = Integer(WhiteLight);
  CheckBox2->Tag = Integer(RedLight);
  CheckBox3->Tag = Integer(BlueLight);
  Shape1->Tag = Integer(WhiteLight);
  Shape2->Tag = Integer(RedLight);
  Shape3->Tag = Integer(BlueLight);

  ComboBox1->ItemIndex = 0;
  ComboBox1Change(NULL);
  StartHeight = Height;
  CheckBox3Click(this);
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::GLCadencer1Progress(TObject *Sender, const double deltaTime,
		  const double newTime)
{
  // Orbit the camera
  if ((dx != 0) || (dy != 0))
  {
	Camera->MoveAroundTarget(dy, dx);
	dx = 0;
	dy = 0;
  }
  // Rotate the light sources
  if (cbSpin->Checked)
	DCLights->Turn(deltaTime*20);

  GLSceneViewer1->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::CheckBox1Click(TObject *Sender)
{
  WhiteLight->Shining = CheckBox1->Checked;
  CheckBox1->Tag = CheckBox1->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::CheckBox2Click(TObject *Sender)
{
  RedLight->Shining = CheckBox2->Checked;
  CheckBox2->Tag = CheckBox2->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::CheckBox3Click(TObject *Sender)
{
  BlueLight->Shining = CheckBox3->Checked;
  CheckBox3->Tag = CheckBox3->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::Shape1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
  // WhiteLight Color Dialog
  ColorDialog1->Color = Shape1->Brush->Color;
  if (ColorDialog1->Execute())
  {
	Shape1->Brush->Color = ColorDialog1->Color;
	WhiteLight->Diffuse->AsWinColor = ColorDialog1->Color;
  }
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::Shape2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
  // RedLight Color Dialog
  ColorDialog1->Color = Shape2->Brush->Color;
  if (ColorDialog1->Execute())
  {
	Shape2->Brush->Color = ColorDialog1->Color;
	RedLight->Diffuse->AsWinColor = ColorDialog1->Color;
 }
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::Shape3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
  // BlueLight Color Dialog
  ColorDialog1->Color = Shape3->Brush->Color;
  if (ColorDialog1->Execute())
  {
	Shape3->Brush->Color = ColorDialog1->Color;
	BlueLight->Diffuse->AsWinColor = ColorDialog1->Color;
   }
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::ComboBox1Change(TObject *Sender)
{
  if (ComboBox1->Text == "Per-Vertex")
	Bunny->Material->LibMaterialName = " ";
  else
  if (ComboBox1->Text == "Dot3 Texture Combiner")
  {
	Bunny->Material->LibMaterialName = "Bump";
	GLBumpShader1->BumpMethod = bmDot3TexCombiner;
  }
  else
  if (ComboBox1->Text == "Basic Fragment Program")
  {
	Bunny->Material->LibMaterialName = "Bump";
	GLBumpShader1->BumpMethod = bmBasicARBFP;
  }
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
  mx = X;
  my = Y;
  dx = 0;
  dy = 0;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
  if (Shift.Contains(ssLeft))
  {
	dx += (mx-X);
	dy += (my-Y);
  }
  else
  {
	dx = 0;
	dy = 0;
  }
  mx = X;
  my = Y;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::AsyncTimer1Timer(TObject *Sender)
{
  LabelFPS->Caption  = GLSceneViewer1->FramesPerSecondText();
  GLSceneViewer1->ResetPerformanceMonitor();
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::FormResize(TObject *Sender)
{
  Camera->SceneScale = (float)Height/StartHeight;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::GLSceneViewer1BeforeRender(TObject *Sender)
{
  if (IsInitialized)
	exit;

  if  (GL->ARB_multitexture && GL->ARB_vertex_program && GL->ARB_texture_env_dot3)
	ComboBox1->Items->Add("Dot3 Texture Combiner");
  if  (GL->ARB_multitexture && GL->ARB_vertex_program && GL->ARB_fragment_program)
  {
	ComboBox1->Items->Add("Basic Fragment Program");
	if (GLSceneViewer1->Buffer->LimitOf[limNbTextureUnits] < 3)
	  GLBumpShader1->SpecularMode = smOff;
  }
  IsInitialized = true;
}

//---------------------------------------------------------------------------
void __fastcall TFormBunny::ComboBox2Change(TObject *Sender)
{
 switch (ComboBox2->ItemIndex)
 {
  case 0 : GLBumpShader1->SpecularMode = smOff; break;
  case 1 : GLBumpShader1->SpecularMode = smBlinn; break;
  case 2 : GLBumpShader1->SpecularMode = smPhong; break;
 default: ;
 }
}
//---------------------------------------------------------------------------

