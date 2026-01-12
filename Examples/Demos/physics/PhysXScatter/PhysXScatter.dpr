program PhysXScatter;

uses
  Forms,
  fdPhysXScatter in 'fdPhysXScatter.pas' {FormPhysXScatter};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormPhysXScatter, FormPhysXScatter);
  Application.Run;
end.
