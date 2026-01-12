program BenchD;

uses
  Vcl.Forms,
  fdBench in 'fdBench.pas' {FormBench},
  fdCanvas in 'canvas\fdCanvas.pas' {FormCanvas},
  fdMegaCube in 'megacube\fdMegaCube.pas' {FormMegacube},
  fdMegaglass in 'megaglasscube\fdMegaglass.pas' {FormMegaglasscube},
  fdSmoking in 'smoking\fdSmoking.pas' {FormSmoking},
  fdVolcano in 'volcano\fdVolcano.pas' {FormVolcano},
  fdWhirl in 'whirlwind\fdWhirl.pas' {FormWhirl};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormBench, FormBench);
  Application.CreateForm(TFormCanvas, FormCanvas);
  Application.CreateForm(TFormMegacube, FormMegacube);
  Application.CreateForm(TFormMegaglasscube, FormMegaglasscube);
  Application.CreateForm(TFormSmoking, FormSmoking);
  Application.CreateForm(TFormVolcano, FormVolcano);
  Application.CreateForm(TFormWhirl, FormWhirl);
  Application.Run;
end.
