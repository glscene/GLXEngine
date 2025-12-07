(*
  GLSLShaderLab Demo : Demo that show how to use some GLSLShader.
  If you want to use your own model, take care that models need to have UV Coordinates
  Original code by Jerome Delauney
*)
program ShadersLabD;

uses
  Vcl.Forms,
  fdShaderLab in 'fdShaderLab.pas' {FormShaderLab};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormShaderLab, FormShaderLab);
  Application.Run;
end.
