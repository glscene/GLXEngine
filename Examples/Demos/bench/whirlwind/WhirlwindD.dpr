program WhirlwindD;

uses
  Vcl.Forms,
  fdWhirl in 'fdWhirl.pas' {FormWhirl};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormWhirl, FormWhirl);
  Application.Run;
end.
