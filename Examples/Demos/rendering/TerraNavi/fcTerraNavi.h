//---------------------------------------------------------------------------

#ifndef fcTerraNaviH
#define fcTerraNaviH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <GIFImg.hpp>
#include <Stage.Keyboard.hpp>
#include "Stage.BaseClasses.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.SoundManager.hpp"
#include "GLS.Sounds.BASS.hpp"
#include "GLS.BitmapFont.hpp"
#include "GLS.Material.hpp"
#include "Stage.Coordinates.hpp"
#include "GLS.Objects.hpp"
#include "GLS.LensFlare.hpp"
#include "GLS.HUDObjects.hpp"
#include "GLS.SkyDome.hpp"
#include "GLS.TerrainRenderer.hpp"
#include "GLS.SpacePartition.hpp"
#include "GLS.Tree.hpp"
#include "GLS.FileTGA.hpp"
#include "GLS.VectorFileObjects.hpp"
#include "GLS.File3DS.hpp"
#include "GLS.HeightData.hpp"
#include "GLS.WindowsFont.hpp"
//---------------------------------------------------------------------------
class TFormTerraNavi : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *GLSceneViewer1;
	TGLScene *GLScene1;
	TGLCadencer *GLCadencer1;
	TGLBitmapHDS *GLBitmapHDS1;
	TGLSoundLibrary *GLSoundLibrary1;
	TGLSMBASS *GLSMBASS1;
	TGLMaterialLibrary *GLMaterialLibrary1;
	TGLDummyCube *GLDummyCube1;
	TGLDummyCube *GLDummyCube2;
	TGLCamera *GLCamera1;
	TGLLensFlare *GLLensFlare1;
	TGLDummyCube *GLDummyCube3;
	TGLRenderPoint *GLRenderPoint1;
	TGLSkyDome *GLSkyDome1;
	TGLSprite *moon;
	TGLSprite *sun;
	TGLTerrainRenderer *GLTerrainRenderer1;
	TTimer *Timer1;
	TGLSprite *GLSprite1;
	TGLDummyCube *GLDummyCube4;
	TTimer *Timer2;
	TGLTree *GLTree1;
	TGLFreeForm *GLFreeForm1;
	TGLHUDText *GLHUDText1;
	TGLWindowsBitmapFont *GLWindowsBitmapFont1;
	TGLDirectOpenGL *GLDirectOpenGL1;
	TGLDirectOpenGL *GLDirectOpenGL2;
	TCheckBox *CheckBox1;
	void __fastcall GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GLCadencer1Progress(TObject *Sender, const double DeltaTime, const double NewTime);
	void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall CreateTrees();
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall GLDirectOpenGL1Render(TObject *Sender, TGLRenderContextInfo &rci);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall GLDirectOpenGL2Render(TObject *Sender, TGLRenderContextInfo &rci);

private:	// User declarations
public:		// User declarations
	__fastcall TFormTerraNavi(TComponent* Owner);
	int mx, my;
	bool fullScreen;
	float FCamHeight;
	TGLSectoredSpacePartition *SpacePartition1;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTerraNavi *FormTerraNavi;
//---------------------------------------------------------------------------
#endif
