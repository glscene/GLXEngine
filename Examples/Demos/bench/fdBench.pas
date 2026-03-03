unit fdBench;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.Menus,
  Vcl.ComCtrls,
  Vcl.ExtCtrls,

  fdCanvas,
  fdMegacube,
  fdMegaglass,
  fdSmoking,
  fdVolcano,
  fdWhirl;

type
  TFormBench = class(TForm)
    PanelLeft: TPanel;
    tvBench: TTreeView;
    PageControl: TPageControl;
    tsCanvas: TTabSheet;
    tsMegacube: TTabSheet;
    tsMegaglasscube: TTabSheet;
    tsSmoking: TTabSheet;
    tsVolcano: TTabSheet;
    tsWhirlwind: TTabSheet;
    procedure FormShow(Sender: TObject);
    procedure tvBenchClick(Sender: TObject);
  private
  public
  end;

var
  FormBench: TFormBench;

implementation //==============================================================

{$R *.dfm}

//----------------------------------------------------------------------

procedure TFormBench.FormShow(Sender: TObject);
begin
  // Canvas
  FormCanvas.Parent := tsCanvas;
  FormCanvas.Align := alClient;
  FormCanvas.BorderStyle := bsNone;
  FormCanvas.RBPenWidth2.Checked := True;
  FormCanvas.Show;

  // Megacube
  FormMegacube.Parent := tsMegacube;
  FormMegacube.Align := alClient;
  FormMegacube.BorderStyle := bsNone;
  FormMegacube.Show;

  // Megaglasscube
  FormMegaglasscube.Parent := tsMegaglasscube;
  FormMegaglasscube.Align := alClient;
  FormMegaglasscube.BorderStyle := bsNone;
  FormMegaglasscube.Show;

   // Smoking
  FormSmoking.Parent := tsSmoking;
  FormSmoking.Align := alClient;
  FormSmoking.BorderStyle := bsNone;
  FormSmoking.Show;

  // Volcano
  FormVolcano.Parent := tsVolcano;
  FormVolcano.Align := alClient;
  FormVolcano.BorderStyle := bsNone;
  FormVolcano.Show;

  // Whirlwind
  FormWhirl.Parent := tsWhirlwind;
  FormWhirl.Align := alClient;
  FormWhirl.BorderStyle := bsNone;
  FormWhirl.Show;

  tvBench.Select(tvBench.Items[3]);  // goto to column 0
  tvBenchClick(Sender);
end;

//----------------------------------------------------------------------

procedure TFormBench.tvBenchClick(Sender: TObject);
begin
  tvBench.Items[0].DropHighlighted := False;
   case tvBench.Selected.Index of
    0:
      PageControl.ActivePage := tsCanvas;
    1:
      PageControl.ActivePage := tsMegacube;
    2:
      PageControl.ActivePage := tsMegaglasscube;
    3:
      PageControl.ActivePage := tsSmoking;
    4:
      PageControl.ActivePage := tsVolcano;
    5:
      PageControl.ActivePage := tsWhirlwind;
  end;
end;


end.
