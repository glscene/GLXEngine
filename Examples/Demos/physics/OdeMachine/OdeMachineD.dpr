program OdeMachineD;

uses
  Forms,
  fdOdeMachine in 'fdOdeMachine.pas' {FormOdeMachine};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormOdeMachine, FormOdeMachine);
  Application.Run;
end.
