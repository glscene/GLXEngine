program ArchiverEditD;

{$R 'icons.res' 'icons.rc'}

uses
  Forms,
  fdArchiveEdit in 'fdArchiveEdit.pas' {Form1},
  fdFolderDlg in 'fdFolderDlg.pas' {FDialog},
  fdFolderSelect in 'fdFolderSelect.pas' {FolderSel};

{$R *.res}
{.$R Icons.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TFDialog, FDialog);
  Application.CreateForm(TFDialog, FDialog);
  Application.CreateForm(TFolderSel, FolderSel);
  Application.Run;
end.
