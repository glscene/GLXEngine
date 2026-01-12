program MatScriptD;

uses
  Forms,
  fdMatScript in 'fdMatScript.pas' {FormMatScript};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormMatScript, FormMatScript);
  Application.Run;
end.
