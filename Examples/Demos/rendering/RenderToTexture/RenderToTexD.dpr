{:
 Rendering to texture demo
}
program RenderToTexD;

uses
  Forms,
  fdRenderToTex in 'fdRenderToTex.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
