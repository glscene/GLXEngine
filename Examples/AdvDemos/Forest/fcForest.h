//---------------------------------------------------------------------------

#ifndef fcForestH
#define fcForestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.BitmapFont.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.HeightData.hpp"
#include "GLS.HeightTileFileHDS.hpp"
#include "GLS.HUDObjects.hpp"
#include "GLS.Material.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.SkyDome.hpp"
#include "GLS.TerrainRenderer.hpp"
#include "GLS.VectorFileObjects.hpp"
#include "GLS.WindowsFont.hpp"
#include "Stage.Keyboard.hpp"
#include "Stage.Utils.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGLWindowsBitmapFont *BFLarge;
	TGLWindowsBitmapFont *BFSmall;
	TGLCadencer *GLCadencer;
	TGLCustomHDS *GLCustomHDS1;
	TGLHeightTileFileHDS *GLHeightTileFileHDS;
	TGLScene *GLScene1;
	TGLActor *GLWolf;
	TGLSkyDome *SkyDome;
	TGLTerrainRenderer *Terrain;
	TGLDirectOpenGL *DOWake;
	TGLLightSource *LSSun;
	TGLHUDText *HTHelp;
	TGLDummyCube *GLDummyCube1;
	TGLFreeForm *FFSailBoat;
	TGLDummyCube *DCCamera;
	TGLCamera *GLCamera;
	TGLFreeForm *GLHouse;
	TGLDummyCube *GLDummyTrees;
	TGLFreeForm *GLTree;
	TGLActor *GLShark1;
	TGLActor *GLShark2;
	TGLSceneViewer *GLSceneViewer;
	TGLMaterialLibrary *MLTerrain;
	TGLMaterialLibrary *MLSailBoat;
	TPanel *PAProgress;
	TLabel *Label1;
	TProgressBar *ProgressBar;
	TTimer *Timer1;
	TGLActor *GLGull1;
	TGLActor *GLGull2;
	TGLActor *GLGull3;
	void __fastcall GLCadencerProgress(TObject *Sender, const double DeltaTime, const double NewTime);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GLCustomHDS1MarkDirtyEvent(const TRect &Area);
	void __fastcall GLCustomHDS1StartPreparingData(TGLHeightData *HeightData);
	void __fastcall GLSceneViewerBeforeRender(TObject *Sender);
	void __fastcall TerrainHeightDataPostRender(TGLRenderContextInfo &rci, TList *&HeightDatas);
	void __fastcall DOWakeProgress(TObject *Sender, const double DeltaTime, const double NewTime);
	void __fastcall DOWakeRender(TObject *Sender, TGLRenderContextInfo &rci);
private:
	void __fastcall addTree();
	void __fastcall addGulls();
public:
	__fastcall TForm1(TComponent* Owner);
	bool FullScreen;
	float CamHeight;
	int WaterPolyCount;
	bool WaterPlane;
	bool WasAboveWater;
	float HelpOpacity;
	TGLAffineVectorList *WakeVertices;
	TGLAffineVectorList *WakeStretch;
	TGLSingleList *WakeTime;
	float gull1Angle, gull2Angle, gull3Angle;
	bool gull1Direction, gull2Direction, gull3Direction;
	void ResetMousePos(void);
	float WaterPhase(const float px, const float py);
	float WaterHeight(const float px, const float py);
	void IssuePoint(TGLHeightData *hd, int x, int y, int s2, float t, int rx, int ry);
private:
	TFileName AssetPath;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
