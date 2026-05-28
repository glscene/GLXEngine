program InvarianceD;

uses
  Forms,
  fdInvariance in 'fdInvariance.pas' {FormInvariance};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormInvariance, FormInvariance);
  Application.Run;
end.
