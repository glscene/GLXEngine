//---------------------------------------------------------------------------

#ifndef fcPickH
#define fcPickH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"

#include "GLS.GeomObjects.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
//---------------------------------------------------------------------------
class TFormPick : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *glsViewer;
	TGLScene *GLScene1;
	TGLDummyCube *DummyCube1;
	TGLLightSource *GLLightSource1;
	TGLSphere *Sphere;
	TGLCylinder *Cylinder;
	TGLTorus *Torus;
	TGLCone *Cone;
	TGLCamera *GLCamera1;
	void __fastcall glsViewerMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y);
	void __fastcall glsViewerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
private:	// User declarations
	 TGLCustomSceneObject *oldPick;

public:		// User declarations
	__fastcall TFormPick(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPick *FormPick;
//---------------------------------------------------------------------------
#endif
