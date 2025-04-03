unit fGLOptions;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.UITypes,
  System.Variants,
  System.Classes,
  System.IniFiles,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.StdCtrls,
  Vcl.ExtCtrls,

  //
  dImages,
  dDialogs,
  fGLForm;

type
  TFormOptions = class(TGLForm)
    CheckBoxAxis: TCheckBox;
    PanelBackground: TPanel;
    ButtonOk: TButton;
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure ButtonOKClick(Sender: TObject);
    procedure PanelBackgroundClick(Sender: TObject);
    procedure CheckBoxAxisClick(Sender: TObject);
  private
  public
    CurLangID : Word;
    procedure ReadIniFile; override;
    procedure WriteIniFile;
  end;

var
  FormOptions: TFormOptions;

//---------------------------------------------------------------------------
implementation

{$R *.dfm}

uses
  fGLSViewer;


procedure TFormOptions.FormCreate(Sender: TObject);
begin
  inherited;
  ReadIniFile;
end;

procedure TFormOptions.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  WriteIniFile;
  inherited;
end;

procedure TFormOptions.ReadIniFile;
begin
  inherited;
  IniFile := TIniFile.Create(ChangeFileExt(ParamStr(0), '.ini'));
  with IniFile do
    try
      CheckBoxAxis.Checked := ReadBool(Name, CheckBoxAxis.Name, True);
      PanelBackground.Color  := ReadInteger(Name, PanelBackground.Name, 0);
    finally
      IniFile.Free;
    end;
end;

procedure TFormOptions.WriteIniFile;
begin
  IniFile := TIniFile.Create(ChangeFileExt(ParamStr(0), '.ini'));
  with IniFile do
    try
      WriteBool(Name, CheckBoxAxis.Name, CheckBoxAxis.Checked);
      WriteInteger(Name, PanelBackground.Name, PanelBackground.Color);
    finally
      IniFile.Free;
    end;
  inherited;
end;

procedure TFormOptions.CheckBoxAxisClick(Sender: TObject);
begin
  if CheckBoxAxis.Checked then
    frmGLSViewer.DCAxis.Visible := True
  else
    frmGLSViewer.DCAxis.Visible := False;
end;


procedure TFormOptions.PanelBackgroundClick(Sender: TObject);
begin
   dmDialogs.ColorDialog.Color := PanelBackground.Color;
   if dmDialogs.ColorDialog.Execute then
   begin
     PanelBackground.Color :=  dmDialogs.ColorDialog.Color;
     frmGLSViewer.ApplyBgColor;
   end;
end;

procedure TFormOptions.ButtonOKClick(Sender: TObject);
var
  FileName: TFileName;
begin
  FileName := ChangeFileExt(ParamStr(0), '.ini');
  if FileExists(UpperCase(FileName)) then
     DeleteFile(UpperCase(FileName)); //to exclude dublicated sections for each language
end;

end.
