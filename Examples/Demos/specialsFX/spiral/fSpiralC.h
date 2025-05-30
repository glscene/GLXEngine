//---------------------------------------------------------------------------

#ifndef fSpiralCH
#define fSpiralCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include <Stage.VectorGeometry.hpp>
#include <GLS.Behaviours.hpp>
#include <GLS.SceneViewer.hpp>
#include <GLS.Objects.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Cadencer.hpp>
#include <GLS.ParticleFX.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.FullScreenViewer.hpp"
#include "GLS.SceneViewer.hpp"
#include "Stage.Keyboard.hpp"
#include "GLS.FullScreenViewer.hpp"

//---------------------------------------------------------------------------
class TForm1:public TForm
{
__published:                   // IDE-managed Components
  TGLScene * GLScene;
  TGLSceneViewer *GLSceneViewer;
  TGLDummyCube *DCBase;
  TGLDummyCube *DCSrc;
  TGLPolygonPFXManager *PFXSpiral;
  TGLCadencer *GLCadencer;
  TGLParticleFXRenderer *PFXRenderer;
  TGLCamera *GLCamera;
  TTimer *Timer;
  TGLPolygonPFXManager *PFXRing;
  TGLFullScreenViewer *GLFullScreenViewer;
  TPanel *Panel1;
  TSpeedButton *SpeedButton1;
  void __fastcall TimerTimer(TObject * Sender);
  void __fastcall FormResize(TObject * Sender);
  void __fastcall GLSceneViewerDblClick(TObject * Sender);
  void __fastcall GLFullScreenViewerDblClick(TObject * Sender);
  void __fastcall GLFullScreenViewerKeyPress(TObject * Sender, char &Key);
  void __fastcall GLSceneViewerMouseMove(TObject * Sender, TShiftState Shift,
                                         int X, int Y);
private:                       // User declarations
public:                        // User declarations
    __fastcall TForm1(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

