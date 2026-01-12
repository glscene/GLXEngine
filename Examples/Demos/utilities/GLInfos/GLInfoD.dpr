program GLInfoD;

uses
  Vcl.Forms,
  fdInfoGL in 'fdInfoGL.pas' {MainForm};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
