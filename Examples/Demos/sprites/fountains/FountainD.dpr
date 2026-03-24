(*
  Fountain Particles
    2010-05-17 - modified for fired keyboards by Pavel Vassiliev
    2005-06-09 - original code using four textures by Dave Gravel
*)

 program FountainD;

uses
  Forms,
  fdFountain in 'fdFountain.pas' {FormFontain},
  GLS.Fountain in 'GLS.Fountain.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormFontain, FormFontain);
  Application.Run;
end.
