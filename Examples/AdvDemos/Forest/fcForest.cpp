//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcForest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.BaseClasses"
#pragma link "GLS.BitmapFont"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"
#pragma link "GLS.HeightData"
#pragma link "GLS.HeightTileFileHDS"
#pragma link "GLS.HUDObjects"
#pragma link "GLS.Material"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.SkyDome"
#pragma link "GLS.TerrainRenderer"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.WindowsFont"
#pragma link "GLS.File3DS"
#pragma link "GLS.FileOBJ"
#pragma link "GLS.FileSMD"
#pragma link "GLS.FileMD2"
#pragma resource "*.dfm"
TForm1 *Form1;

#define cWaterLevel -10000
#define cWaterOpaqueDepth 2000
#define cWaveAmplitude 120

const float WolfSpeed = 0.25;
const float SharkSpeed = 0.5;
bool firstPos = true, secondPos = true, thirdPos = true, shark1Pos = true,
	 shark2Pos = true;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	int i, j;
	String name;
	TGLLibMaterial* libMat;
	TFileName FileName;

	AssetPath = GetCurrentAssetPath();
	// textures for terrain
	SetCurrentDir(AssetPath + "\\landscape");
	MLTerrain->AddTextureMaterial("Detail", "detail.jpg")->TextureScale->SetPoint(128, 128, 128);
	MLTerrain->AddTextureMaterial("Detail", "detail.jpg")->Material->Texture->TextureMode =	tmModulate;

	Terrain->Material->MaterialLibrary = MLTerrain;
	Terrain->Material->LibMaterialName = "Terrain";

	GLCustomHDS1->MaxPoolSize = 8 * 1024 * 1024;
	GLCustomHDS1->DefaultHeight = cWaterLevel;
	for (i = 0; i <= 3; i++)
		for (j = 0; j <= 3; j++) {
			name = Format("Tex_%d_%d.bmp", ARRAYOFCONST((i, j)));
			if (!FileExists(name)) {
				ShowMessage("Texture file " + name +
							" not found...\r\n  Did you run " +
							"splitter->exe" + " as said in the readme->txt?");
				Application->Terminate();
				Abort();
			}
			libMat = MLTerrain->AddTextureMaterial(name, name, true); // it was false ;)
			libMat->Material->Texture->TextureMode = tmReplace;
			libMat->Material->Texture->TextureWrap = twNone;
			libMat->Material->Texture->Compression = tcStandard;
			libMat->Material->Texture->FilteringQuality = tfAnisotropic;
			libMat->Texture2Name = "detail";
		}
	CamHeight = 30;
	WaterPlane = true;
	// load models
	SetCurrentDir(AssetPath + "\\model");
	FFSailBoat->LoadFromFile("boat.3ds");
	FFSailBoat->TurnAngle = -30;
	GLHouse->LoadFromFile("house.obj");
	GLHouse->Material->Texture->Image->LoadFromFile("house.jpg");
	GLTree->LoadFromFile("firtree.3ds");
	addTree();
	addGulls();
	GLWolf->LoadFromFile("wolf.md2");
	GLWolf->Material->Texture->Image->LoadFromFile("wolf_texture.png");
	GLShark1->LoadFromFile("shark.obj");
	GLShark1->Material->Texture->Image->LoadFromFile("shark_texture.png");
	GLShark2->LoadFromFile("shark.obj");
	GLShark2->Material->Texture->Image = GLShark1->Material->Texture->Image;
	for (i = 0; i < MLSailBoat->Materials->Count; i++)
		MLSailBoat->Materials->Items[i]
			->Material->FrontProperties->Ambient->Color =
			MLSailBoat->Materials->Items[i]
				->Material->FrontProperties->Diffuse->Color;
	HTHelp->Text = "Help:\r\
			  WASD : Camera control\r\
			  V : Hide/show sea surface\r\
			  P : Hide/show wireframe\r\
			  B : Hide/show ship\r\
			  Num4 & Num6 : Ship control\r\
			  F1: Show this message";
			  //* : Increase CLOD precision\r\
			  /// : decrease CLOD precision\r\
	HTHelp->Position->SetPoint(Screen->Width / 2 - 100, Screen->Height / 2 - 150, 0);
	HelpOpacity = 4;
	GLSceneViewer->Cursor = crNone;

	GLHeightTileFileHDS->HTFFileName = AssetPath + "\\landscape\\islands.htf";


}
//---------------------------------------------------------------------------
void __fastcall TForm1::addTree()
{
	TGLFreeForm* tree;
	TGLVector s;
	float f;
	int x[16] = { -230, -300, -400, -430, -437, -444, -460, -482, -350, -270,
		-500, -285, -600, -620, -635, -642 };
	int z[16] = { 290, 290, 320, 370, 340, 360, 310, 290, 270, 180, 360, 370,
		290, 260, 275, 185 };
	for (int i = 0; i < 16; i++) {
		tree =
			(TGLFreeForm*)(GLDummyTrees->AddNewChild(__classid(TGLFreeForm)));
		tree->LoadFromFile("firtree.3ds");
		tree->Material->FrontProperties->Ambient->SetColor(0, 0.225, 0, 1);
		tree->Material->FrontProperties->Diffuse->SetColor(0, 0.225, 0 ,1);

		s = GLTree->Scale->AsVector;
		f = (Random() + 0.3);
		ScaleVector(s, 1.9 * f);
		tree->Scale->AsVector = s;
		tree->Position->X = x[i];
		tree->PitchAngle = 90;
		switch (i) {
			case 8: {
				tree->Position->Y = -23;
				break;
			}
			case 9: {
				tree->Position->Y = -35;
				break;
			}
			case 11: {
				tree->Position->Y = 5;
				break;
			}
			case 15: {
				tree->Position->Y = -35;
				break;
			}
			default: {
				tree->Position->Y = -17;
				break;
			}
		}
		tree->Position->Z = z[i];
	}
}
//--------------------------------------------------------
void __fastcall TForm1::addGulls()
{
	GLGull1->LoadFromFile("eagle.obj");
	GLGull2->LoadFromFile("eagle.obj");
	GLGull3->LoadFromFile("eagle.obj");

	TGLMaterial* gullMaterial = new TGLMaterial(nullptr);
	if (FileExists("eagle_texture.jpg")) {
		gullMaterial->Texture->Image->LoadFromFile("eagle_texture.jpg");
		gullMaterial->Texture->Enabled = true;
		gullMaterial->Texture->TextureMode = tmModulate;
	} else {
		gullMaterial->FrontProperties->Diffuse->Color = clrWhite;
	}

	GLGull1->Material->Assign(gullMaterial);
	GLGull2->Material->Assign(gullMaterial);
	GLGull3->Material->Assign(gullMaterial);

	delete gullMaterial;
}
// ---------------------------------------------------------------------------
void TForm1::ResetMousePos(void)
{
	if (GLSceneViewer->Cursor == crNone)
		SetCursorPos(Screen->Width / 2, Screen->Height / 2);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::GLCadencerProgress(TObject *Sender, const double DeltaTime,
		  const double NewTime)
{
	float Speed, Alpha, f;
	float TerrainHeight, SurfaceHeight;
	TGLVector Sbp;
	POINT NewMousePos;

	if (shark1Pos) {
		GLShark1->Position->X -= SharkSpeed;
		if (GLShark1->Position->X == -500) {
			GLShark1->TurnAngle = -90;
			shark1Pos = false;
		}
	} else {
		GLShark1->Position->X += SharkSpeed;
		if (GLShark1->Position->X == -200) {
			GLShark1->TurnAngle = 90;
			shark1Pos = true;
		}
	}
	if (shark2Pos) {
		GLShark2->Position->X += SharkSpeed;
		if (GLShark2->Position->X == -200) {
			GLShark2->TurnAngle = 90;
			shark2Pos = false;
		}
	} else {
		GLShark2->Position->X -= SharkSpeed;
		if (GLShark2->Position->X == -500) {
			GLShark2->TurnAngle = -90;
			shark2Pos = true;
		}
	}
	if (firstPos == true) {
		GLWolf->Position->X -= WolfSpeed;
		if (GLWolf->Position->X == -300) {
			GLWolf->RollAngle = 45;
			firstPos = false;
		}
	} else if (secondPos == true) {
		GLWolf->Position->X -= WolfSpeed;
		GLWolf->Position->Z += WolfSpeed;
		if (GLWolf->Position->X == -350 && GLWolf->Position->Z == 220) {
			GLWolf->RollAngle = 225;
			secondPos = false;
		}
	} else if (thirdPos == true) {
		GLWolf->Position->X += WolfSpeed;
		GLWolf->Position->Z -= WolfSpeed;
		if (GLWolf->Position->X == -300) {
			GLWolf->RollAngle = 180;
			thirdPos = false;
		}
	} else {
		GLWolf->Position->X += WolfSpeed;
		if (GLWolf->Position->X == -240) {
			GLWolf->RollAngle = 0;
			firstPos = true, secondPos = true, thirdPos = true;
		}
	}

	TGLVector housePos = GLHouse->AbsolutePosition;
	const float circleRadius = 150.0f; // flying radius
	const float flightHeight = 100.0f; // height over house
	const float gullSpeed = 0.5f;      // velocity of flying

	gull1Angle += DeltaTime * gullSpeed;
	if (gull1Angle > 2 * M_PI) gull1Angle -= 2 * M_PI;

	GLGull1->Position->X = housePos.X + cos(gull1Angle) * circleRadius;
	GLGull1->Position->Z = housePos.Z + sin(gull1Angle) * circleRadius;
	GLGull1->Position->Y = flightHeight;

	GLGull1->TurnAngle = gull1Angle * 180 / M_PI + 90;

	gull2Angle += DeltaTime * gullSpeed * 0.8f;
	if (gull2Angle > 2 * M_PI) gull2Angle -= 2 * M_PI;

	GLGull2->Position->X = housePos.X + cos(gull2Angle) * (circleRadius + 20);
	GLGull2->Position->Z = housePos.Z + sin(gull2Angle) * (circleRadius + 20);
	GLGull2->Position->Y = flightHeight + 20;

	GLGull2->TurnAngle = gull2Angle * 180 / M_PI + 90;

	gull3Angle -= DeltaTime * gullSpeed * 0.6f;
	if (gull3Angle < 0) gull3Angle += 2 * M_PI;

	GLGull3->Position->X = housePos.X + cos(gull3Angle) * (circleRadius - 30);
	GLGull3->Position->Z = housePos.Z + sin(gull3Angle) * (circleRadius - 30);
	GLGull3->Position->Y = flightHeight + 40;

	GLGull3->TurnAngle = gull3Angle * 180 / M_PI + 90;

	if (IsKeyDown(VK_SHIFT))
		Speed = 100 * DeltaTime;
	else
		Speed = 20 * DeltaTime;

	if (IsKeyDown(87))
		DCCamera->Position->AddScaledVector(
			Speed, GLCamera->AbsoluteVectorToTarget());
	if (IsKeyDown(83))
		DCCamera->Position->AddScaledVector(
			-Speed, GLCamera->AbsoluteVectorToTarget());
	if (IsKeyDown(65))
		DCCamera->Position->AddScaledVector(
			-Speed, GLCamera->AbsoluteRightVectorToTarget());
	if (IsKeyDown(68))
		DCCamera->Position->AddScaledVector(
			Speed, GLCamera->AbsoluteRightVectorToTarget());
	if (IsKeyDown(VK_PRIOR))
		CamHeight = CamHeight + Speed;
	if (IsKeyDown(VK_NEXT))
		CamHeight = CamHeight - Speed;
	if (IsKeyDown(VK_ESCAPE))
		Close();
	if (IsKeyDown(VK_F1))
		HelpOpacity = ClampValue(HelpOpacity + DeltaTime * 5, 3, 5);
	if (IsKeyDown(VK_NUMPAD4))
		FFSailBoat->Turn(-DeltaTime * 3);
	if (IsKeyDown(VK_NUMPAD6))
		FFSailBoat->Turn(DeltaTime * 3);
	if (IsKeyDown(VK_LBUTTON)) {
		Alpha = DCCamera->Position->Y;
		DCCamera->Position->AddScaledVector(
			Speed, GLCamera->AbsoluteVectorToTarget());
		CamHeight = CamHeight + DCCamera->Position->Y - Alpha;
	}
	if (IsKeyDown(VK_RBUTTON)) {
		Alpha = DCCamera->Position->Y;
		DCCamera->Position->AddScaledVector(
			-Speed, GLCamera->AbsoluteVectorToTarget());
		CamHeight = CamHeight + DCCamera->Position->Y - Alpha;
	}
	GetCursorPos(&NewMousePos);
	GLCamera->MoveAroundTarget((Screen->Height / 2 - NewMousePos.y) * 0.25,
		(Screen->Width / 2 - NewMousePos.x) * 0.25);
	ResetMousePos();
	TerrainHeight =
		Terrain->InterpolatedHeight(DCCamera->Position->AsVector);
	SurfaceHeight = Terrain->Scale->Z * cWaterLevel / 128;
	if (TerrainHeight < SurfaceHeight)
		TerrainHeight = SurfaceHeight;
	DCCamera->Position->Y = TerrainHeight + CamHeight;
	if ((GLCamera->AbsolutePosition.Y > SurfaceHeight) || (!WaterPlane)) {
		if (!WasAboveWater) {
			SkyDome->Visible = true;

			GLSceneViewer->Buffer->FogEnvironment->FogColor->Color = clrWhite;
			GLSceneViewer->Buffer->FogEnvironment->FogEnd = 1000;
			GLSceneViewer->Buffer->FogEnvironment->FogStart = 500;

			GLSceneViewer->Buffer->BackgroundColor = clWhite;
			GLCamera->DepthOfView = 1000;
			WasAboveWater = true;
		}
	} else {
		if (WasAboveWater) {
			SkyDome->Visible = false;

			GLSceneViewer->Buffer->FogEnvironment->FogColor->AsWinColor =
				clNavy;
			GLSceneViewer->Buffer->FogEnvironment->FogEnd = 100;
			GLSceneViewer->Buffer->FogEnvironment->FogStart = 0;

			GLSceneViewer->Buffer->BackgroundColor = clNavy;
			GLCamera->DepthOfView = 100;
			WasAboveWater = false;
		}
	}
	if (HelpOpacity > 0) {
		HelpOpacity = HelpOpacity - DeltaTime;
		Alpha = ClampValue(HelpOpacity, 0, 1);
		if (Alpha > 0) {
			HTHelp->Visible = true;
			HTHelp->ModulateColor->Alpha = Alpha;
		} else
			HTHelp->Visible = false;
	}
	Sbp = Terrain->AbsoluteToLocal(FFSailBoat->AbsolutePosition);
	Alpha = WaterPhase(Sbp.X + Terrain->TileSize * 0.5,
		Sbp.Y + Terrain->TileSize * 0.5);
	FFSailBoat->Position->Y = (cWaterLevel + sin(Alpha) * cWaveAmplitude) *
								  (Terrain->Scale->Z / 128) -
							  1.5;
	f = cWaveAmplitude * 0.01;
	FFSailBoat->Up->SetVector(
		cos(Alpha) * 0.02 * f, 1, (sin(Alpha) * 0.02 - 0.005) * f);
	FFSailBoat->Move(DeltaTime * 2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	int i;
	TGLPolygonMode pm;
	switch (Key) {
		case 'p':
		case 'P': {
			if (MLTerrain->Materials->Items[0]->Material->PolygonMode ==
				pmLines)
				pm = pmFill;
			else
				pm = pmLines;
			for (i = 0; i < MLTerrain->Materials->Count; i++)
				MLTerrain->Materials->Items[i]->Material->PolygonMode =	pm;

			for (i = 0; i < MLSailBoat->Materials->Count; i++)
				MLSailBoat->Materials->Items[i]->Material->PolygonMode = pm;
			FFSailBoat->StructureChanged();
			break;
		}
		case 'v':
		case 'V':
			WaterPlane = !WaterPlane;
			break;
		case 'b':
		case 'B':
			FFSailBoat->Visible = !FFSailBoat->Visible;
			break;
		/*case '*':
			if (Terrain->CLODPrecision > 1)
				Terrain->CLODPrecision =
					(int)(Terrain->CLODPrecision * 0.8);
			break;
		case '/':
			if (Terrain->CLODPrecision < 1000)
				Terrain->CLODPrecision =
					(int)(Terrain->CLODPrecision * 1.2 + 1);
			break;*/
	}
	Key = 0x0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLCustomHDS1MarkDirtyEvent(const TRect &Area)
{
	GLHeightTileFileHDS->MarkDirty(Area);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLCustomHDS1StartPreparingData(TGLHeightData *HeightData)
{
	TGLHeightData* htfHD;
	int i, j, n;
	TTexPoint offset;

	htfHD = GLHeightTileFileHDS->GetData(HeightData->XLeft, HeightData->YTop,
		HeightData->Size, HeightData->DataType);
	if ((htfHD->DataState == hdsNone))
		HeightData->DataState = hdsNone;
	else {
		i = (HeightData->XLeft / 128);
		j = (HeightData->YTop / 128);
		if ((Cardinal(i) < 4) & (Cardinal(j) < 4)) {

			HeightData->MaterialName = Format("Tex_%d_%d.bmp", ARRAYOFCONST((i, j)));

			HeightData->TextureCoordinatesMode = tcmLocal;
			n = ((HeightData->XLeft / 32) & 3);
			offset.S = n * 0.25;
			n = ((HeightData->YTop / 32) & 3);
			offset.T = -n * 0.25;
			HeightData->TextureCoordinatesOffset = offset;
			HeightData->TextureCoordinatesScale = TexPointMake(0.25, 0.25);
			HeightData->DataType = hdtSmallInt;
			htfHD->DataType = hdtSmallInt;
			HeightData->Allocate(hdtSmallInt);
			Move(htfHD->SmallIntData, HeightData->SmallIntData, htfHD->DataSize);
			HeightData->DataState = hdsReady;
			HeightData->HeightMin = htfHD->HeightMin;
			HeightData->HeightMax = htfHD->HeightMax;
		} else
			HeightData->DataState = hdsNone;
	}
	GLHeightTileFileHDS->Release(htfHD);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewerBeforeRender(TObject *Sender)
{
	int i, n;

	PAProgress->Left = (Width - PAProgress->Width) / 2;
	PAProgress->Visible = true;
	n = MLTerrain->Materials->Count;
	ProgressBar->Max = n - 1;
	try {
		for (i = 0; i < n; i++) {
			ProgressBar->Position = i;
			MLTerrain->Materials->Items[i]->Material->Texture->Handle;
			PAProgress->Repaint();
		}
	} __finally
	{
		ResetMousePos();
		PAProgress->Visible = false;
		GLSceneViewer->BeforeRender = NULL;
	}
}
//---------------------------------------------------------------------------
float TForm1::WaterPhase(const float px, const float py)
{
	return GLCadencer->CurrentTime * 1.0 + px * 0.16 + py * 0.09;
}
// ---------------------------------------------------------------------------
float TForm1::WaterHeight(const float px, const float py)
{
	float alpha;
	alpha = WaterPhase(px + Terrain->TileSize * 0.5,
		py + Terrain->TileSize * 0.5);
	return (cWaterLevel + sin(alpha) * cWaveAmplitude) *
		   (Terrain->Scale->Z * (1.0 / 128));
}
// ---------------------------------------------------------------------------
void TForm1::IssuePoint(
	TGLHeightData* hd, int x, int y, int s2, float t, int rx, int ry)
{
	const float r = 0.75;
	const float g = 0.75;
	const float b = 1.0;
	float px, py;
	float alpha, colorRatio, ca, sa;

	px = x + rx + s2;
	py = y + ry + s2;
	//  if (hd->DataState == hdsNone) {
	alpha = 1;
	/*
	}
	 else {
		alpha = (cWaterLevel - hd->SmallIntHeight(rx, ry)) *
				(1 / cWaterOpaqueDepth);
		alpha = ClampValue(alpha, 0.5, 1.0);
	}
	*/
	SinCos(WaterPhase(px, py), sa, ca);
	colorRatio = 1 - alpha * 0.1;
	glColor4f(r * colorRatio, g * colorRatio, b, alpha);
	glTexCoord2f(px * 0.01 + 0.002 * sa, py * 0.01 + 0.0022 * ca - t * 0.002);
	glVertex3f(px, py, cWaterLevel + cWaveAmplitude * sa);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::TerrainHeightDataPostRender(TGLRenderContextInfo &rci,
		  TList *&HeightDatas)
{
	int i, x, y, s, s2;
	float t;
	TGLHeightData* hd;

	if (WaterPlane) {
		t = GLCadencer->CurrentTime;
		MLTerrain->ApplyMaterial("water", rci);
		do {
			if (!WasAboveWater)
				rci.GLStates->InvertFrontFace();
			glPushAttrib(GL_ENABLE_BIT);
			glDisable(GL_LIGHTING);
			glDisable(GL_NORMALIZE);
			glStencilFunc(GL_ALWAYS, 1, 255);
			glStencilMask(255);
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
			glEnable(GL_STENCIL_TEST);
			glNormal3f(0, 0, 1);
			for (i = 0; i < HeightDatas->Count; i++) {
				hd = (TGLHeightData*)(HeightDatas->List[i]);
				if ((hd->DataState == hdsReady) &&
					(hd->HeightMin > cWaterLevel))
					continue;
				x = hd->XLeft;
				y = hd->YTop;
				s = hd->Size - 1;
				s2 = s / 2;
				glBegin(GL_TRIANGLE_FAN);
				IssuePoint(hd, x, y, s2, t, s2, s2);
				IssuePoint(hd, x, y, s2, t, 0, 0);
				IssuePoint(hd, x, y, s2, t, s2, 0);
				IssuePoint(hd, x, y, s2, t, s, 0);
				IssuePoint(hd, x, y, s2, t, s, s2);
				IssuePoint(hd, x, y, s2, t, s, s);
				IssuePoint(hd, x, y, s2, t, s2, s);
				IssuePoint(hd, x, y, s2, t, 0, s);
				IssuePoint(hd, x, y, s2, t, 0, s2);
				IssuePoint(hd, x, y, s2, t, 0, 0);
				glEnd();
			}
			glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
			glPopAttrib();
			if (!WasAboveWater)
				rci.GLStates->InvertFrontFace();
			WaterPolyCount = HeightDatas->Count * 8;
		} while (MLTerrain->UnApplyMaterial(rci));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DOWakeProgress(TObject *Sender, const double DeltaTime, const double NewTime)
{
	int i;
	TGLVector sbp, sbr;
	if (WakeVertices == NULL) {
		WakeVertices = new TGLAffineVectorList();
		WakeStretch = new TGLAffineVectorList();
		WakeTime = new TGLSingleList();
	}
	i = 0;
	while (i < WakeVertices->Count) {
		WakeVertices->CombineItem(
			i, WakeStretch->Items[i >> 1], -0.45 * DeltaTime);
		WakeVertices->CombineItem(
			i + 1, WakeStretch->Items[i >> 1], 0.45 * DeltaTime);
		i += 2;
	}
	if (NewTime > DOWake->TagFloat) {
		if (DOWake->TagFloat == 0) {
			DOWake->TagFloat = NewTime + 0.2;
		} else {
			DOWake->TagFloat = NewTime + 1;
			sbp = VectorCombine(FFSailBoat->AbsolutePosition,
				FFSailBoat->AbsoluteDirection, 1, 3);
			sbr = FFSailBoat->AbsoluteRight();
			WakeVertices->Add(VectorCombine(sbp, sbr, 1, -2));
			WakeVertices->Add(VectorCombine(sbp, sbr, 1, 2));
			WakeStretch->Add(VectorScale(sbr, (0.95 + Random() * 0.1)));
			WakeTime->Add(NewTime * 0.1);
			if (WakeVertices->Count >= 80) {
				WakeVertices->Delete(0);
				WakeVertices->Delete(0);
				WakeStretch->Delete(0);
				WakeTime->Delete(0);
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DOWakeRender(TObject *Sender, TGLRenderContextInfo &rci)
{
	int i, n;
	TVector3f p;
	TGLVector sbp;
	float c;

	if (!(WakeVertices) && (!((FFSailBoat->Visible) || (WaterPlane)))) {
		MLTerrain->ApplyMaterial("wake", rci);
		do {
			glPushAttrib(GL_ENABLE_BIT);
			glDisable(GL_LIGHTING);
			glDisable(GL_FOG);
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE);
			glStencilFunc(GL_EQUAL, 1, 255);
			glStencilMask(255);
			glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
			glEnable(GL_STENCIL_TEST);
			glDisable(GL_DEPTH_TEST);
			if (!WasAboveWater)
				rci.GLStates->InvertFrontFace();
			glBegin(GL_TRIANGLE_STRIP);
			n = WakeVertices->Count;
			for (i = 0; i < n; i++) {
				p = WakeVertices->Items[i ^ 1];
				sbp = Terrain->AbsoluteToLocal(VectorMake(p, 0));
				if ((i & 1) == 0) {
					c = (i & 0xFFE) * 0.2 / n;
					glColor3f(c, c, c);
					glTexCoord2f(0, WakeTime->Items[i / 2]);
				} else
					glTexCoord2f(1, WakeTime->Items[i / 2]);
				glVertex3f(p.X, WaterHeight(sbp.X, sbp.Y), p.Z);
			}
			glEnd();
			if (!WasAboveWater)
				rci.GLStates->InvertFrontFace();
			glPopAttrib();
			glDisable(stStencilTest);
		} while (MLTerrain->UnApplyMaterial(rci));
	}
}
//---------------------------------------------------------------------------
