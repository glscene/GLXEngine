//---------------------------------------------------------------------------

#ifndef fcGraphH
#define fcGraphH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>

#include "fcGraph.h"

#include "fcFxy.h"
#include "fñHeightField.h"
#include "fcPoints.h"
#include "fñSplines.h"
///#include "fñProjection.h"


//---------------------------------------------------------------------------
class TFormGraph : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelLeft;
	TTreeView *tvGraph;
	TMainMenu *MainMenu;
	void __fastcall tvGraphClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGraph(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGraph *FormGraph;
//---------------------------------------------------------------------------
#endif
