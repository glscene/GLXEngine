//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcBench.h"

#pragma link "fCanvasC"
#pragma link "fMegaCubeC"
#pragma link "fMegaglassC"
#pragma link "fSmokingC"
#pragma link "fVolcanoC"
#pragma link "fWhirlC"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBench *FormBench;
//---------------------------------------------------------------------------
__fastcall TFormBench::TFormBench(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormBench::FormShow(TObject *Sender)
{
   // Canvas
  FormCanvas = new TFormCanvas(tsCanvas);
  FormCanvas->Parent = tsCanvas;
  FormCanvas->Align = alClient;
  FormCanvas->BorderStyle = bsNone;
  FormCanvas->Show();

  // Megacube
  FormMegacube = new TFormMegacube(tsMegacube);
  FormMegacube->Parent = tsMegacube;
  FormMegacube->Align = alClient;
  FormMegacube->BorderStyle = bsNone;
  FormMegacube->Show();

  // Megaglasscube
  FormMegaglasscube = new TFormMegaglasscube(tsMegaglasscube);
  FormMegaglasscube->Parent = tsMegaglasscube;
  FormMegaglasscube->Align = alClient;
  FormMegaglasscube->BorderStyle = bsNone;
  FormMegaglasscube->Show();

   // Smoking
  FormSmoking = new TFormSmoking(tsSmoking);
  FormSmoking->Parent = tsSmoking;
  FormSmoking->Align = alClient;
  FormSmoking->BorderStyle = bsNone;
  FormSmoking->Show();

  // Volcano
  FormVolcano = new TFormVolcano(tsVolcano);
  FormVolcano->Parent = tsVolcano;
  FormVolcano->Align = alClient;
  FormVolcano->BorderStyle = bsNone;
  FormVolcano->Show();

  // Whirlwind
  FormWhirl = new TFormWhirl(tsWhirlwind);
  FormWhirl->Parent = tsWhirlwind;
  FormWhirl->Align = alClient;
  FormWhirl->BorderStyle = bsNone;
  FormWhirl->Show();


  PageControl->ActivePage = tsMegacube;
  // tvBench->Select(tvBench->Items[2]);  // goto to node 2
}

//---------------------------------------------------------------------------

void __fastcall TFormBench::tvBenchClick(TObject *Sender)
{
   switch (tvBench->Selected->Index) {
	case 0: {
	  PageControl->ActivePage = tsCanvas; break;
	}
	case 1: {
	  PageControl->ActivePage = tsMegacube; break;
	}
	case 2: {
	  PageControl->ActivePage = tsMegaglasscube; break;
	}
	case 3: {
	  PageControl->ActivePage = tsSmoking; break;
	}
	case 4: {
	  PageControl->ActivePage = tsVolcano; break;
	}
	default: {
	  PageControl->ActivePage = tsWhirlwind; break;
	}
   }

}
//---------------------------------------------------------------------------

