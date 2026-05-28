program CelShadingD;

uses
  Forms,
  fdCelShading in 'fdCelShading.pas' {FormCelShading};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormCelShading, FormCelShading);
  Application.Run;
end.
