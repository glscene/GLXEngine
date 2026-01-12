program ForestD;

uses
  Forms,
  fdForest in 'fdForest.pas' {FormForest};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormForest, FormForest);
  Application.Run;
end.
