//
(* Using Verlet Hair with ODE; Fur Balls *)
//
program OdeFurballD;

uses
  Forms,
  fdOdeFurball in 'fdOdeFurball.pas' {FormFurball};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormFurball, FormFurball);
  Application.Run;
end.
