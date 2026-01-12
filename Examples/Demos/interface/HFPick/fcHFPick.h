//---------------------------------------------------------------------------

#ifndef fcHFPickH
#define fcHFPickH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"

#include "GLS.Graph.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormHFPick : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *glViewer;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TRadioButton *RBPaint;
	TRadioButton *RBRotate;
	TGLScene *GLScene1;
	TGLLightSource *GLLightSource1;
	TGLCamera *GLCamera1;
	TGLHeightField *HeightField;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall glViewerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall glViewerMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall HeightFieldGetHeight2(TObject *Sender, const float x, const float y,
          float &z, TGLColorVector &Color, TTexPoint &TexPoint);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	int mx, my;

public:		// User declarations
	__fastcall TFormHFPick(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHFPick *FormHFPick;
//---------------------------------------------------------------------------
#endif
