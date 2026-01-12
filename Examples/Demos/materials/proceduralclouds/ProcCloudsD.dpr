//
// Procedural Textures for Clouds / Tobias Peirick
//
program ProcCloudsD;

uses
  Forms,
  fdProcClouds in 'fdProcClouds.pas' {FormClouds};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormClouds, FormClouds);
  Application.Run;
end.
