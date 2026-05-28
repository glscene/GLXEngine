program OctreeRenderD;

uses
  Forms,
  fdOctreeRender in 'fdOctreeRender.pas' {frmOctreeDemo};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfrmOctreeDemo, frmOctreeDemo);
  Application.Run;
end.
