program ShadertoyD;

uses
  Forms,
  fdShadertoy in 'fdShadertoy.pas' {FormEiffie};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormEiffie, FormEiffie);
  Application.Run;
end.
