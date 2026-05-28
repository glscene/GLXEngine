(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
program Terrainer;

uses
  Forms,
  fdTerrainer in 'fdTerrainer.pas' {FormTerrainer},
  GLS.Terrainer in 'GLS.Terrainer.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormTerrainer, FormTerrainer);
  Application.Run;
end.
