{ Simple Cg Shader Cubemap Demo (incomplete)}
program CgReflectD;


uses
  Forms,
  fdReflect in 'fdReflect.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
