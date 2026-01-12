(*
  Walk and carry demo.
  Created by Dev 25/12/10
*)
program NewtonWalkCarryD;

uses
  Forms,
  fdWalkCarry in 'fdWalkCarry.pas' {FormNewtonWalkCarry};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormNewtonWalkCarry, FormNewtonWalkCarry);
  Application.Run;
end.
