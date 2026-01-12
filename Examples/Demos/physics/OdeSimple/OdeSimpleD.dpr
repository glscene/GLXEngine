program OdeSimpleD;

uses
  Forms,
  fdOdeSimple in 'fdOdeSimple.pas' {FormOdeSimple};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormOdeSimple, FormOdeSimple);
  Application.Run;
end.
