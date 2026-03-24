program ImpostersD;

uses
  Forms,
  fdImposters in 'fdImposters.pas' {FormImposters};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormImposters, FormImposters);
  Application.Run;
end.
