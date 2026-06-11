(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
program TerrainerD;

uses
  Forms,
  fdTerrainer in 'fdTerrainer.pas' {FormTerrainer};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormTerrainer, FormTerrainer);
  Application.Run;
end.
