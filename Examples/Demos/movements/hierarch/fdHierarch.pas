unit fdHierarch;

interface

uses
  System.Classes,
  System.SysUtils,
  System.Math,
  Vcl.Forms,
  Vcl.ComCtrls,
  Vcl.ExtCtrls,
  Vcl.StdCtrls,
  Vcl.Controls,

  Stage.VectorTypes,
  Stage.VectorGeometry,
  Stage.Utils,
  GLS.Scene,
  GLS.Objects,
  GLS.Cadencer,
  GLS.AsyncTimer,
  GLS.SceneViewer,
  GLS.Coordinates,
  GLS.BaseClasses,
  GLS.SimpleNavigation,
  GLS.Material,
  GLS.GeomObjects;

type
  TFormHierarchy = class(TForm)
    GLScene1: TGLScene;
    SceneViewer: TGLSceneViewer;
    Camera: TGLCamera;
    LightSource: TGLLightSource;
    CBPlay: TCheckBox;
    dcEarth: TGLDummyCube;
    dcMoon: TGLDummyCube;
    GLCadencer1: TGLCadencer;
    sfSun: TGLSphere;
    sfEarth: TGLSphere;
    sfMoon: TGLSphere;
    dcSun: TGLDummyCube;
    GLSimpleNavigation1: TGLSimpleNavigation;
    GLMaterialLibrary1: TGLMaterialLibrary;
    diskEcliptic: TGLDisk;
    procedure FormResize(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure GLCadencer1Progress(Sender: TObject;
      const deltaTime, newTime: Double);
    procedure FormCreate(Sender: TObject);
  private
  public
  end;

var
  FormHierarchy: TFormHierarchy;

implementation //==============================================================

{$R *.DFM}

//-----------------------------------------------------------------------------
procedure TFormHierarchy.FormCreate(Sender: TObject);
begin
  var Path: TFileName := GetCurrentAssetPath();
  SetCurrentDir(Path  + '\map');
  sfSun.Material.Texture.Disabled := False;
  sfSun.Material.Texture.Image.LoadFromFile('sun.jpg');
  sfEarth.Material.Texture.Disabled := False;
  sfEarth.Material.Texture.Image.LoadFromFile('earth.jpg');
  sfMoon.Material.Texture.Disabled := False;
  sfMoon.Material.Texture.Image.LoadFromFile('moon.jpg');
end;

//-----------------------------------------------------------------------------
procedure TFormHierarchy.GLCadencer1Progress(Sender: TObject;
  const deltaTime, newTime: Double);
begin
  if CBPlay.Checked and Visible then
  begin
    // the "sun" spins slowly
    dcSun.Turn(deltaTime * 10);
    // "earth" rotates around the sun and spins
    dcEarth.Turn(deltaTime * 20);
    sfEarth.Turn(deltaTime * 40);
    // "moon" rotates around earth and spins
    dcMoon.Turn(deltaTime * 40);
    sfMoon.Turn(deltaTime * 80);
  end;
  SceneViewer.Invalidate;
end;

//-----------------------------------------------------------------------------
procedure TFormHierarchy.FormResize(Sender: TObject);
begin
  SceneViewer.ResetPerformanceMonitor;
end;

//-----------------------------------------------------------------------------
procedure TFormHierarchy.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  // We need to stop playing here :
  // since the timer is asynchronous, if we don't stop play,
  // it may get triggered during the form's destruction
  CBPlay.Checked := False;
end;

//-----------------------------------------------------------------------------
end.
