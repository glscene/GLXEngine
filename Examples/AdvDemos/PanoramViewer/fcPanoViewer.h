//---------------------------------------------------------------------------

#ifndef fcPanoViewerH
#define fcPanoViewerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Vcl.Imaging.jpeg.hpp>

#include "GLS.Cadencer.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.Texture.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.Material.hpp"

#include "Stage.Keyboard.hpp"
#include "GLS.FileJPEG.hpp"
#include "Stage.Utils.hpp"

//---------------------------------------------------------------------------
class TFormPanorama : public TForm
{
  __published: // IDE-managed Components
	TGLSceneViewer *GLSceneViewer;
	TPanel* Panel1;
	TLabel* LabelYaw;
	TLabel* LabelPitch;
	TLabel* Label1;
	TLabel* Label2;
	TButton* BtnLoad;
	TTrackBar *TrackBarFocal;
	TGLScene *GLScene;
	TGLSphere* Sphere1;
	TGLCamera *Camera;
	TOpenPictureDialog *OpenPictureDialog;
	TGLMaterialLibrary *GLMaterialLibrary;
	TGLCadencer *GLCadencer;
	void __fastcall GLSceneViewerMouseDown(
		TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall GLSceneViewerMouseMove(
		TObject* Sender, TShiftState Shift, int X, int Y);
	void __fastcall BtnLoadClick(TObject* Sender);
	void __fastcall TrackBarFocalChange(TObject* Sender);
	void __fastcall GLCadencerProgress(
		TObject* Sender, const double deltaTime, const double newTime);
	void __fastcall FormKeyDown(TObject* Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormMouseWheel(TObject* Sender, TShiftState Shift,
		int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall FormCreate(TObject *Sender);
  private:
	int mx, my;
	float pitch, yaw; // in degrees
	void PanCameraAround(float dx, float dy);
  public:
    TFileName Path;
    __fastcall TFormPanorama(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPanorama* FormPanorama;
//---------------------------------------------------------------------------
#endif

