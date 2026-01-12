(*
  GLAtmosphere Demo.
  Note: object "Not_a_planet" is used to test atmosphere transparency issues.
*)

program AtmosphereD;

uses
  Forms,
  fdAtmosphere in 'fdAtmosphere.pas' {FormAtmosphere};

{$R *.res}
  
begin
  Application.Initialize;
  Application.CreateForm(TFormAtmosphere, FormAtmosphere);
  Application.Run;
end.
