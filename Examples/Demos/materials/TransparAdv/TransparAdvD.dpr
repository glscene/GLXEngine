program TransparAdvD;

uses
  Forms,
  fdTransparAdv in 'fdTransparAdv.pas' {FormTransparAdv};

{$R *.res}

begin
  Application.Initialize;
{$IFDEF DELPHI2009UP}
  Application.MainFormOnTaskbar := True;
{$ENDIF}
  Application.CreateForm(TFormTransparAdv, FormTransparAdv);
  Application.Run;
end.
