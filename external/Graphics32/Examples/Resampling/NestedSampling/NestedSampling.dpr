program NestedSampling;

{$R 'Media.res' 'Media.rc'}

uses
  Forms,
  SimplePropEdit in 'SimplePropEdit.pas',
  MainUnit in 'MainUnit.pas' {MainForm};

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
