program SkyShaderD;

uses
  Forms,
  fdSkyShader in 'fdSkyShader.pas' {FormSkyShader};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormSkyShader, FormSkyShader);
  Application.Run;
end.
