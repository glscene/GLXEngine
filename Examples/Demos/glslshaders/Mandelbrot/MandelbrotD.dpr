(*
  Mandelbrot fractal
*)
program MandelbrotD;

uses
  Forms,
  fdMandelbrot in 'fdMandelbrot.pas' {FormMandelbrot};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormMandelbrot, FormMandelbrot);
  Application.Run;
end.
