(* Shaded terrain rendering demo *)
program ShadedTerrainD;
uses
  Forms,
  fdShadedTerrain in 'fdShadedTerrain.pas' {FormShadedTerrain};

{$R *.RES}
begin
  Application.Initialize;
  Application.CreateForm(TFormShadedTerrain, FormShadedTerrain);
  Application.Run;
end.
