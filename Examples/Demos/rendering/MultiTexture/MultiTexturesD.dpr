(*
   GLScene Multisample texture demo
*)
program MultiTexturesD;

uses
  Forms,
  fdMultiTextures in 'fdMultiTextures.pas' {FormMultiSampleTextures};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormMultiSampleTextures, FormMultiSampleTextures);
  Application.Run;
end.
