program ImposterD;

uses
  Forms,
  fdImposter in 'fdImposter.pas' {FormImposter};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormImposter, FormImposter);
  Application.Run;
end.
