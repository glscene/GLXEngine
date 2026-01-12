(*
Loading and controlling a Quake 3 model
by Stuart Gooding and Marcus Oblak
*)

program QuakeActorD;

uses
  Forms,
  fdQuakeActor in 'fdQuakeActor.pas' {FormQuakeActor};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormQuakeActor, FormQuakeActor);
  Application.Run;
end.
