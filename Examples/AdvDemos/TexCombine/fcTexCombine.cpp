//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fcTexCombine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.BaseClasses"
#pragma link "Stage.Coordinates"
#pragma link "GLS.HUDObjects"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SceneViewer"
#pragma resource "*.dfm"
TFormTexCombine *FormTexCombine;
//---------------------------------------------------------------------------
__fastcall TFormTexCombine::TFormTexCombine(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTexCombine::ACExportExecute(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
