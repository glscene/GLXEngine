unit fTransparencyD;

interface

uses
  Winapi.OpenGL,
  System.SysUtils,
  System.Classes,
  System.Math,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ExtCtrls,

  
  GLS.Scene,
  GLS.Objects,
  Vcl.StdCtrls,
  GLS.Cadencer,
  GLS.Behaviours,
  GLS.Texture,
  Stage.VectorGeometry,
  GLS.SceneViewer,
  GLS.GeomObjects,
  GLS.Coordinates,
 
  GLS.BaseClasses,
  GLS.Material,
  GLS.RenderContextInfo;

type
  TFormTransparency = class(TForm)
    GLSceneViewer1: TGLSceneViewer;
    GLScene1: TGLScene;
    GLCamera1: TGLCamera;
    GLLightSource1: TGLLightSource;
    Cone1: TGLCone;
    DCCentral: TGLDummyCube;
    CentralSphere: TGLSphere;
    Torus1: TGLTorus;
    OrbitingSphere1: TGLSphere;
    GLCadencer1: TGLCadencer;
    BaseDummyCube: TGLDummyCube;
    OrbitingSphere2: TGLSphere;
    Panel1: TPanel;
    Label1: TLabel;
    Label2: TLabel;
    RBSTC: TRadioButton;
    RBTSC: TRadioButton;
    RBTCS: TRadioButton;
    Label3: TLabel;
    CBAdditive: TCheckBox;
    CBSorting: TCheckBox;
    procedure RBSTCClick(Sender: TObject);
    procedure RBTSCClick(Sender: TObject);
    procedure RBTCSClick(Sender: TObject);
    procedure CBAdditiveClick(Sender: TObject);
    procedure CBSortingClick(Sender: TObject);
    procedure GLCadencer1Progress(Sender: TObject; const deltaTime,
      newTime: Double);
  private
    //
  end;

var
  FormTransparency: TFormTransparency;

implementation

{$R *.DFM}

procedure TFormTransparency.RBSTCClick(Sender: TObject);
begin
   // we have 3 objects, move up twice and we're on the top !
   CentralSphere.MoveUp;
   CentralSphere.MoveUp;
end;

procedure TFormTransparency.RBTSCClick(Sender: TObject);
begin
   // we have 3 objects, move down twice and we're on the top,
   // then once down, we're in the middle !
   CentralSphere.MoveUp;
   CentralSphere.MoveUp;
   CentralSphere.MoveDown;
end;

procedure TFormTransparency.RBTCSClick(Sender: TObject);
begin
   // we have 3 objects, move down twice and we're on the bottom !
   CentralSphere.MoveDown;
   CentralSphere.MoveDown;
end;

procedure TFormTransparency.CBAdditiveClick(Sender: TObject);
begin
   // adjust blending mode for both orbiting spheres
   if CBAdditive.Checked then
      OrbitingSphere1.Material.BlendingMode:=bmAdditive
   else OrbitingSphere1.Material.BlendingMode:=bmTransparency;
   OrbitingSphere2.Material.BlendingMode:=OrbitingSphere1.Material.BlendingMode;
end;

procedure TFormTransparency.CBSortingClick(Sender: TObject);
begin
   // adjust sorting on the parent object
   if CBSorting.Checked then
      BaseDummyCube.ObjectsSorting:=osRenderFarthestFirst
   else BaseDummyCube.ObjectsSorting:=osNone;
end;

procedure TFormTransparency.GLCadencer1Progress(Sender: TObject; const deltaTime,
  newTime: Double);
var
   alpha : Double;
begin
   // move the spheres
   alpha:=DegToRad(newTime*60);
   OrbitingSphere1.Position.SetPoint(1.5*cos(alpha), 1.5*sin(alpha), 1.5*sin(alpha));
   alpha:=alpha+PI/2;
   OrbitingSphere2.Position.SetPoint(1.5*cos(alpha), 1.5*sin(alpha), 1.5*sin(alpha));
end;

end.
