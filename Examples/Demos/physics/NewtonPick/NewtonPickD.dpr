(* Newton Game Dynamics Physics Engine demo.

  This example show how to move a body by calling the pick function of joint.
  Change kinematicControllerOptions.PickModeLinear to feel the difference.
  Most of the code must be written by developer in mouse events.

  Created by Franck Papouin 17/09/10
*)
program NewtonPickD;

uses
  Forms,
  fdMousePick in 'fdMousePick.pas' {FormNewtonMousePick};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormNewtonMousePick, FormNewtonMousePick);
  Application.Run;
end.
