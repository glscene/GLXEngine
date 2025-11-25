//---------------------------------------------------------------------------
#include <vcl.h>
#include <tchar.h>
#pragma hdrstop

#include "fcCgBombShader.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Graph"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SimpleNavigation"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.FileMD2"
#pragma link "GLS.File3DS"

#pragma link "GLS.CgShader"
#pragma link "GLS.CgBombShader"

#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::ResetPositions()
{
  TrackBarDisplacement->Position = InterpolateCombinedSafe(0.01, 10, MyShader->Displacement, 0, 100, 1, itLinear);
  TrackBarSharpness->Position = InterpolateCombinedSafe(-0.13, 10, MyShader->Sharpness, 0, 100, 1, itLinear);
  TrackBarColorSharpness->Position = InterpolateCombinedSafe(0.01, 6, MyShader->ColorSharpness, 0, 100, 1, itLinear);
  TrackBarSpeed->Position = InterpolateCombinedSafe(0.1, 1, MyShader->Speed, 0, 100, 1, itLinear);
  TrackBarTurbDensity->Position = InterpolateCombinedSafe(0.01, 8, MyShader->TurbDensity, 0, 100, 1, itLinear);
  TrackBarColorRange->Position = InterpolateCombinedSafe(-0.5, 0.5, MyShader->ColorRange, 0, 100, 1, itLinear);
  TrackBarAlpha->Position = InterpolateCombinedSafe(0, 1, MyShader->Alpha, 0, 100, 1, itLinear);
  TrackBarMainTextureShare->Position = InterpolateCombinedSafe(0, 2, MyShader->MainTextureShare, 0, 100, 1, itLinear);
  TrackBarGradientTextureShare->Position = InterpolateCombinedSafe(0, 2, MyShader->GradientTextureShare, 0, 100, 1, itLinear);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  // First load models from asset directory
  TFileName Path = GetCurrentAssetPath();

  // First loading static models from asset directory
  SetCurrentDir(Path  + "\\model");
  ffTeapot->LoadFromFile("Teapot.3ds");
  ffSphere1->LoadFromFile("Sphere.3DS");
  ffSphere2->LoadFromFile("Sphere_big.3DS");
  ffSphere2->Scale->Scale(20);

  // Second load dynamic models with texture and animation
  SetCurrentDir(Path  + "\\modelext");
  GLActor1->LoadFromFile("waste.md2"); //Fighter
  GLActor1->SwitchToAnimation(0, True);
  GLActor1->AnimationMode = aamLoop;
  GLActor1->Scale->Scale(0.05);
  GLMaterialLibrary1->LibMaterialByName("FighterTexture")->
	Material->Texture->Image->LoadFromFile("waste.jpg");

  // Next loading other textures
  SetCurrentDir(Path  + "\\texture");
  GLMaterialLibrary1->LibMaterialByName("marbles1")->
	 Material->Texture->Image->LoadFromFile("beigemarble.jpg");
  GLMaterialLibrary1->LibMaterialByName("marbles2")->
	 Material->Texture->Image->LoadFromFile("marbletiles.jpg");
  GLMaterialLibrary1->LibMaterialByName("snow")->
	 Material->Texture->Image->LoadFromFile("snow512.jpg");
  GLMaterialLibrary1->LibMaterialByName("Fire")->
	 Material->Texture->Image->LoadFromFile("FireGrade.png");

  MyShader = new TCgBombShader(this);
  MyShader->MainTexture = GLMaterialLibrary1->LibMaterialByName("FighterTexture")->Material->Texture;
  MyShader->Cadencer = GLCadencer1;

  // All models are linked with this material
  GLMaterialLibrary1->LibMaterialByName("LibMaterial")->Shader = MyShader;

  ResetPositions();
  ComboBox1Change(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
  MyShader->GradientTexture = GLMaterialLibrary1->LibMaterialByName(ComboBox1->Text)->Material->Texture;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  GLActor1->Visible = CheckBox1->Checked;
  ffTeapot->Visible = CheckBox2->Checked;
  ffSphere1->Visible = CheckBox3->Checked;
  ffSphere2->Visible = CheckBox4->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarDisplacementChange(TObject *Sender)
{
  if (MyShader == NULL)
	exit;
  MyShader->Displacement = InterpolateCombinedSafe(0, 100, TrackBarDisplacement->Position, 0.01, 10, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarSharpnessChange(TObject *Sender)
{
  MyShader->Sharpness = InterpolateCombinedSafe(0, 100, TrackBarSharpness->Position, -0.13, 10, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarColorSharpnessChange(TObject *Sender)
{
  MyShader->ColorSharpness = InterpolateCombinedSafe(0, 100, TrackBarColorSharpness->Position, 0.01, 6, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarSpeedChange(TObject *Sender)
{
  MyShader->Speed = InterpolateCombinedSafe(0, 100, TrackBarSpeed->Position, 0.1, 1, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarTurbDensityChange(TObject *Sender)
{
  MyShader->TurbDensity = InterpolateCombinedSafe(0, 100, TrackBarTurbDensity->Position, 0.1, 8, 1, itLinear);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBarColorRangeChange(TObject *Sender)
{
  MyShader->ColorRange = InterpolateCombinedSafe(0, 100, TrackBarColorRange->Position, -0.5, 0.5, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarAlphaChange(TObject *Sender)
{
 MyShader->Alpha = InterpolateCombinedSafe(0, 100, TrackBarAlpha->Position, 0, 1, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarMainTextureShareChange(TObject *Sender)
{
 MyShader->MainTextureShare = InterpolateCombinedSafe(0, 100, TrackBarMainTextureShare->Position, 0, 2, 1, itLinear);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBarGradientTextureShareChange(TObject *Sender)
{
  MyShader->GradientTextureShare = InterpolateCombinedSafe(0, 100, TrackBarGradientTextureShare->Position, 0, 2, 1, itLinear);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GLCadencer1Progress(TObject *Sender, const double deltaTime,
          const double newTime)
{
  GLSceneViewer1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShaderEnabledCheckBoxClick(TObject *Sender)
{
  MyShader->Enabled = ShaderEnabledCheckBox->Checked;
}
//---------------------------------------------------------------------------

