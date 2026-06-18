//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcTerraNavi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.BaseClasses"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.Cadencer"
#pragma link "GLS.HeightData"
#pragma link "GLS.SoundManager"
#pragma link "GLS.Sounds.BASS"
#pragma link "GLS.BitmapFont"
#pragma link "GLS.Material"
#pragma link "Stage.Coordinates"
#pragma link "GLS.Objects"
#pragma link "GLS.LensFlare"
#pragma link "GLS.HUDObjects"
#pragma link "GLS.SkyDome"
#pragma link "GLS.TerrainRenderer"
#pragma link "GLS.SpacePartition"
#pragma link "GLS.Tree"
#pragma link "GLS.FileTGA"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.File3DS"
#pragma link "GLS.HeightData"
#pragma link "GLS.WindowsFont"
#pragma resource "*.dfm"
TFormTerraNavi *FormTerraNavi;

float random(void)
{
	return (float)(rand() & 0x1FFF) / (float)0x1FFF;
}

//---------------------------------------------------------------------------
__fastcall TFormTerraNavi::TFormTerraNavi(TComponent* Owner)
	: TForm(Owner)
{
	TFileName Path = GetCurrentAssetPath();
	SetCurrentDir(Path  + "\\texture");
	SpacePartition1 = new TGLQuadtreeSpacePartition();
	SpacePartition1->LeafThreshold = 50;
	SpacePartition1->MaxTreeDepth = 10;
	SpacePartition1->GrowGravy = 0.01;
	GLBitmapHDS1->MaxPoolSize = 8 * 1024 * 1024;
	GLBitmapHDS1->Picture->LoadFromFile("terrain.bmp");
	GLMaterialLibrary1->Materials->Items[0]->Material->Texture->Image->LoadFromFile("snow512.jpg");
	GLMaterialLibrary1->Materials->Items[1]->Material->Texture->Image->LoadFromFile("detailmap.jpg");
	moon->Material->Texture->Image->LoadFromFile("moon.bmp");
	sun->Material->Texture->Image->LoadFromFile("flare1.bmp");

	GLSprite1->Material->Texture->Image->LoadFromFile("tree1.bmp");
	GLSprite1->Position->Y = GLTerrainRenderer1->InterpolatedHeight(GLSprite1->Position->AsVector) + GLSprite1->Height / 2;
	GLMaterialLibrary1->AddTextureMaterial("LeafFront", "leaf.tga");
	GLMaterialLibrary1->Materials->Items[2]->Material->BlendingMode = bmAlphaTest50;
	GLMaterialLibrary1->Materials->Items[2]->Material->Texture->TextureMode = tmModulate;
	GLMaterialLibrary1->Materials->Items[2]->Material->Texture->TextureFormat = tfRGBA;
	GLMaterialLibrary1->AddTextureMaterial("LeafBack", "leaf.tga");
	GLMaterialLibrary1->Materials->Items[3]->Material->BlendingMode = bmAlphaTest50;
	GLMaterialLibrary1->Materials->Items[3]->Material->Texture->TextureMode = tmModulate;
	GLMaterialLibrary1->Materials->Items[3]->Material->Texture->TextureFormat = tfRGBA;
	GLMaterialLibrary1->AddTextureMaterial("Branch", "zbark_016.jpg");
	GLMaterialLibrary1->Materials->Items[4]->Material->Texture->TextureMode = tmModulate;
	GLFreeForm1->Material->Texture->Image->LoadFromFile("leafyellow.jpg");

	SetCurrentDir(Path  + "\\audio");
	GLSoundLibrary1->Samples->Add()->LoadFromFile("ChillyWind.mp3");
	GLSoundLibrary1->Samples->Add()->LoadFromFile("howl.mp3");
	GLDummyCube2->Position->X = 570;
	GLDummyCube2->Position->Z = -385;
	GLDummyCube2->Turn(90);
	FCamHeight = 10;
	GLTree1->MaterialLibrary = GLMaterialLibrary1;
	GLTree1->LeafMaterialName = "LeafFront";
	GLTree1->LeafBackMaterialName = "LeafBack";
	GLTree1->BranchMaterialName = "Branch";
	GLTree1->Position->X = 300;
	GLTree1->Position->Y = GLTerrainRenderer1->InterpolatedHeight(GLTree1->Position->AsVector) - 6;
	GLTree1->Position->Z = 60;
	SetCurrentDir(Path  + "\\model");
	GLFreeForm1->LoadFromFile("firtree.3ds");
	GLFreeForm1->Position->X = -40;
	GLFreeForm1->Position->Y = GLTerrainRenderer1->InterpolatedHeight(GLFreeForm1->Position->AsVector) - 5;
	GLFreeForm1->Position->Z = -40;
	CreateTrees();
	GLHUDText1->Text = " Press \"up left down right\" to navigate, \"PgUp\" - up, \"PgDn\" - down.\r\n Press \"N\" - night, \"D\" - day.\r\n Press \"Q\" to Show Quadtree.\r\n Press \"Esc\" to quit.";
	GLSceneViewer1->Buffer->BackgroundColor = clWhite;
	GLTerrainRenderer1->TilesPerTexture = 256.0 / GLTerrainRenderer1->TileSize;
}
//---------------------------------------------------------------------------
void __fastcall TFormTerraNavi::GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	my = Y;
	mx = X;
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
	if (Shift.Contains(ssLeft))
	{
		GLCamera1->MoveAroundTarget(my - Y, mx - X);
	}
	else if (Shift.Contains(ssRight))
	{
		GLCamera1->RotateTarget(my - Y, mx - X, 0);
    }
	mx = X;
	my = Y;
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	TGLMaterial *fp;
	TGLFogEnvironment *fe;
	TGIFColor  Color;
	switch (Key)
	{
	case 'w':
	case 'W':
		fp = GLMaterialLibrary1->Materials->Items[0]->Material;
		if(fp->PolygonMode == pmLines)
		{
			fp->PolygonMode = pmFill;
		}
		else
		{
			fp->PolygonMode = pmLines;
        }
		break;
	case '+':
		if(GLCamera1->DepthOfView < 3000)
		{
			GLCamera1->DepthOfView = GLCamera1->DepthOfView * 1.2;
			fe = GLSceneViewer1->Buffer->FogEnvironment;
			fe->FogEnd = fe->FogEnd * 1.2;
			fe->FogStart = fe->FogStart * 1.2;
		}
		break;
	case '-':
		if(GLCamera1->DepthOfView > 600)
		{
			GLCamera1->DepthOfView = GLCamera1->DepthOfView / 1.2;
			fe = GLSceneViewer1->Buffer->FogEnvironment;
			fe->FogEnd = fe->FogEnd / 1.2;
			fe->FogStart = fe->FogStart / 1.2;
		}
		break;
	case '*':
		if(GLTerrainRenderer1->CLODPrecision > 20)
		{
			GLTerrainRenderer1->CLODPrecision = round(GLTerrainRenderer1->CLODPrecision * 0.8);
		}
		break;
	case '/':
		if(GLTerrainRenderer1->CLODPrecision < 1000)
		{
			GLTerrainRenderer1->CLODPrecision = round(GLTerrainRenderer1->CLODPrecision * 1.2);
		}
		break;
	case '8':
		if(GLTerrainRenderer1->QualityDistance > 40)
		{
			GLTerrainRenderer1->QualityDistance = round(GLTerrainRenderer1->QualityDistance * 0.8);
		}
		break;
	case '9':
		if(GLTerrainRenderer1->QualityDistance < 1000)
		{
			GLTerrainRenderer1->QualityDistance = round(GLTerrainRenderer1->QualityDistance * 1.2);
		}
		break;
	case 'n':
	case 'N':
		if(GLSkyDome1->Stars->Count == 0)
		{
			// turn on 'night' mode
			Color.Red = 0; Color.Green = 0; Color.Blue = 8;
			GLSkyDome1->Bands->Items[0]->StopColor->AsWinColor = TGIFColorMap::RGB2Color(Color);
			Color.Red = 0; Color.Green = 0; Color.Blue = 0;
			GLSkyDome1->Bands->Items[0]->StartColor->AsWinColor = TGIFColorMap::RGB2Color(Color);
			Color.Red = 0; Color.Green = 0; Color.Blue = 16;
			GLSkyDome1->Bands->Items[1]->StopColor->AsWinColor = TGIFColorMap::RGB2Color(Color);
			Color.Red = 0; Color.Green = 0; Color.Blue = 8;
			GLSkyDome1->Bands->Items[1]->StartColor->AsWinColor = TGIFColorMap::RGB2Color(Color);
			GLSkyDome1->Stars->AddRandomStars(700, clWhite, True);      // many white stars
			Color.Red = 255; Color.Green = 100; Color.Blue = 100;
			GLSkyDome1->Stars->AddRandomStars(100, TGIFColorMap::RGB2Color(Color), True); // some redish ones
			Color.Red = 100; Color.Green = 100; Color.Blue = 255;
			GLSkyDome1->Stars->AddRandomStars(100, TGIFColorMap::RGB2Color(Color), True); // some blueish ones
			Color.Red = 255; Color.Green = 255; Color.Blue = 100;
			GLSkyDome1->Stars->AddRandomStars(100, TGIFColorMap::RGB2Color(Color), True); // some yellowish ones
			GLSceneViewer1->Buffer->BackgroundColor = clBlack;
			fe = GLSceneViewer1->Buffer->FogEnvironment;
			fe->FogColor->AsWinColor = clBlack;
			fe->FogStart = -fe->FogStart;     // Fog is used to make things darker
			moon->Visible = True;
			sun->Visible = False;
			GLLensFlare1->Visible = False;
		}
		break;
	case 'd':
	case 'D':
		if(GLSkyDome1->Stars->Count > 0)
		{
			// turn on 'day' mode
			GLSkyDome1->Bands->Items[1]->StopColor->Color = clrNavy;
			GLSkyDome1->Bands->Items[1]->StartColor->Color = clrBlue;
			GLSkyDome1->Bands->Items[0]->StopColor->Color = clrBlue;
			GLSkyDome1->Bands->Items[0]->StartColor->Color = clrWhite;
			GLSkyDome1->Stars->Clear();
			GLSceneViewer1->Buffer->BackgroundColor = clWhite;
			fe = GLSceneViewer1->Buffer->FogEnvironment;
			fe->FogColor->AsWinColor = clWhite;
			fe->FogStart = -fe->FogStart;
			GLSceneViewer1->Buffer->FogEnvironment->FogStart = 200;
			moon->Visible = False;
			sun->Visible = True;
		}
		break;
	case 't':
		if(GLSkyDome1->Options.Contains(sdoTwinkle))
		{
			GLSkyDome1->Options = GLSkyDome1->Options << sdoTwinkle;
		}
		else
		{
			GLSkyDome1->Options = GLSkyDome1->Options >> sdoTwinkle;
        }
		break;
	case 'l':
		GLLensFlare1->Visible = (!GLLensFlare1->Visible) && sun->Visible;
		break;
	case 'q':
	case 'Q':
		CheckBox1->Checked = !CheckBox1->Checked;
		CheckBox1Click(Sender);
	}
  	Key = '\0';
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::GLCadencer1Progress(TObject *Sender, const double DeltaTime,
          const double NewTime)
{
	float speed;
	// handle keypresses
	if(IsKeyDown(VK_SHIFT))
		speed = 5 * DeltaTime;
	else
		speed = DeltaTime;
	TGSCoordinates *c = GLCamera1->Position;
	if(IsKeyDown(VK_UP))
		GLDummyCube2->Translate(c->Z * speed * 10, 0, -c->X * speed * 10);
	if(IsKeyDown(VK_DOWN))
		GLDummyCube2->Translate(-c->Z * speed * 10, 0, c->X * speed * 10);
	if(IsKeyDown(VK_LEFT))
		GLDummyCube2->Translate(-c->X * speed * 10, 0, -c->Z * speed * 10);
	if(IsKeyDown(VK_RIGHT))
		GLDummyCube2->Translate(c->X * speed * 10, 0, c->Z * speed * 10);
	if(IsKeyDown(VK_PRIOR))
		FCamHeight = FCamHeight + 300 * speed;
	if(IsKeyDown(VK_NEXT))
		FCamHeight = FCamHeight - 300 * speed;
	if(IsKeyDown(VK_ESCAPE))
		Close();
	// don't drop through terrain!
	GLDummyCube2->Position->Y = GLTerrainRenderer1->InterpolatedHeight(GLDummyCube2->Position->AsVector) + FCamHeight;
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::Timer1Timer(TObject *Sender)
{
	TGSVector wolfPos;
	float c, s;
	TGLBSoundEmitter *be;
	if(!GLSMBASS1->Active)
		return;
	if(GLSkyDome1->Stars->Count == 0)
	{
		// wind blows around camera
		be = GetOrCreateSoundEmitter(GLCamera1);
		be->Source->SoundLibrary = GLSoundLibrary1;
		be->Source->SoundName = GLSoundLibrary1->Samples->Items[0]->Name;
		be->Source->Volume = random() * 0.5 + 0.5;
		be->Playing = true;
	}
	else
	{
		// wolf howl at some distance, at ground level
		wolfPos = GLCamera1->AbsolutePosition;
		SinCosine(random() * Vectorgeometry::c2PI, 100 + random(1000), s, c);
		wolfPos.X = wolfPos.X + c;
		wolfPos.Z = wolfPos.Z + s;
		wolfPos.Y = GLTerrainRenderer1->InterpolatedHeight(wolfPos);
		GLDummyCube1->Position->AsVector = wolfPos;
		be = GetOrCreateSoundEmitter(GLDummyCube1);
		be->Source->SoundLibrary = GLSoundLibrary1;
		be->Source->SoundName = GLSoundLibrary1->Samples->Items[1]->Name;
		be->Source->MinDistance = 100;
		be->Source->MaxDistance = 4000;
		be->Playing = True;
	}
	Timer1->Enabled = False;
	Timer1->Interval = 10000 + random(10000);
	Timer1->Enabled = True;
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::CreateTrees()
{
	const int crange = 40;
	for (int i = -crange; i < crange; i++)
	{
		for (int j = -crange; j < crange; j++)
		{
			TGLProxyObject *obj1 = new TGLProxyObject(GLDummyCube4);
			obj1->ProxyOptions = obj1->ProxyOptions << pooObjects;
			obj1->MasterObject = GLSprite1;
			int a = ((rand() % 12 + 9) * 1.0 / 10);
			obj1->Scale->X = a;
			obj1->Scale->Y = a;
			obj1->Scale->Z = a;
			obj1->Position->X = i * 125 + rand() % 50;
			obj1->Position->Z = j * 125 + rand() % 50;
			obj1->Position->Y = GLTerrainRenderer1->InterpolatedHeight(obj1->Position->AsVector) + GLSprite1->Height / 2 * a - 1;
			if (i % 2 == 0 && j % 2 == 0 && i < 21 && i > -21 && j < 21 && j > -21)
			{
				a = ((rand() % 7 + 9) * 1.0 / 10);
				TGLProxyObject *obj2 = new TGLProxyObject(GLDummyCube4);
				obj2->ProxyOptions = obj2->ProxyOptions << pooObjects;
				obj2->MasterObject = GLFreeForm1;
				obj2->Scale->X = GLFreeForm1->Scale->X * a;
				obj2->Scale->Y = GLFreeForm1->Scale->Y * a;
				obj2->Scale->Z = GLFreeForm1->Scale->Z * a;
				obj2->PitchAngle = 90;
				obj2->Position->X = i * 125 + rand() % 50 - 50;
				obj2->Position->Z = j * 125 + rand() % 50 - 50;
				obj2->Position->Y = GLTerrainRenderer1->InterpolatedHeight(obj2->Position->AsVector) - 1 * a;
                TGLSceneObj *obj4 = new TGLSceneObj(SpacePartition1, obj2);
			}
			TGLSceneObj *obj3 = new TGLSceneObj(SpacePartition1, obj1);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::Timer2Timer(TObject *Sender)
{
	FormTerraNavi->Caption = "Terrain Navigation - " + GLSceneViewer1->FramesPerSecondText() + " - " + GLTerrainRenderer1->LastTriangleCount;
    GLSceneViewer1->ResetPerformanceMonitor();
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::FormDestroy(TObject *Sender)
{
	SpacePartition1->Free();
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::GLDirectOpenGL1Render(TObject *Sender, TGLRenderContextInfo &rci)
{
	for (int i = 0; i < GLDummyCube4->Count - 1; i++)
	{
		GLDummyCube4->Children[i]->Visible = false;
	}
	SpacePartition1->QueryFrustum(rci.Rcci.Frustum);
	for (int i = 0; i < SpacePartition1->QueryResult->Count - 1; i++)
	{
		if (TGLSceneObj *leafsobj = dynamic_cast<TGLSceneObj*>(SpacePartition1->QueryResult->Items[i]))
		{
			leafsobj->Obj->Visible = true;
			if (CheckBox1->Checked)
			{
				RenderAABB(rci, leafsobj->FCachedAABB);
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::CheckBox1Click(TObject *Sender)
{
	GLDirectOpenGL2->Visible = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFormTerraNavi::GLDirectOpenGL2Render(TObject *Sender, TGLRenderContextInfo &rci)
{
	RenderSpatialPartitioning(rci, SpacePartition1);
}
//---------------------------------------------------------------------------

