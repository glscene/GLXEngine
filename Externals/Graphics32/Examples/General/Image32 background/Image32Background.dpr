program Image32Background;

{$R 'Media.res' 'Media.rc'}
{$R '..\..\manifest.res'}

uses
  Forms,
  Main in 'Main.pas' {FormMain};

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormMain, FormMain);
  Application.Run;
end.
