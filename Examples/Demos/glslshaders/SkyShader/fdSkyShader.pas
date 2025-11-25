unit fdSkyShader;

interface

uses
  System.Classes,
  System.SysUtils,
  Vcl.Dialogs,
  Vcl.Forms,
  Vcl.Controls,

  Stage.VectorGeometry,
  GLS.Cadencer,
  GLS.SceneViewer,
  GLS.Scene,
  Stage.VectorTypes,
  GLS.Objects,
  GLS.GeomObjects,
  GLS.Texture,
  Stage.TextureFormat,
  GLS.CompositeImage,
  GLS.Material,
  GLS.Coordinates,
  GLS.BaseClasses,

  GLS.Context,
  GLS.RenderContextInfo,
  Stage.Utils,

  GLS.FileDDS;

type
  TFormSkyShader = class(TForm)
    GLScene1: TGLScene;
    Cadencer: TGLCadencer;
    SceneViewer: TGLSceneViewer;
    Camera: TGLCamera;
    DummyCam: TGLDummyCube;
    Thor: TGLTorus;
    Sphere: TGLSphere;
    Sky: TGLSphere;
    DirectOGL: TGLDirectOpenGL;
    procedure CadencerProgress(Sender: TObject; const DeltaTime, NewTime: Double);
    procedure FormCreate(Sender: TObject);
    procedure DirectOGLRender(Sender: TObject; var rci: TGLRenderContextInfo);
  public
    Path: TFileName;
    GLSL_Sky: TGLProgramHandle;
    GLSL_Obj: TGLProgramHandle;
    Cubemap: TGLTexture;
    procedure LoadCubemap();
    procedure InitGLSL;
  end;

var
  FormSkyShader: TFormSkyShader;

implementation  //============================================================

{$R *.dfm}

procedure TFormSkyShader.FormCreate;
begin
  Path := GetCurrentAssetPath();
  SetCurrentDir(Path  + '\cubemap');
  LoadCubemap;
  Sky.Radius := Camera.DepthOfView;
  Sky.Material.Texture := Cubemap;
  Sphere.Material.Texture := Cubemap;
  Thor.Material.Texture := Cubemap;
end;

procedure TFormSkyShader.LoadCubemap();
begin
  Cubemap := TGLTexture.Create(self);
  // Loading a cubemap as TGLCompositeImage
  Cubemap.ImageClassName := 'TGLCompositeImage';
  Cubemap.Image.LoadFromFile('skybox.dds');
  Cubemap.TextureWrap := twNone;
  Cubemap.FilteringQuality := tfAnisotropic;
  Cubemap.Disabled := False;
end;

procedure TFormSkyShader.CadencerProgress;
begin
  DummyCam.Turn(deltaTime * 30);
  Thor.Pitch(deltaTime * 50);
  Camera.Position.Y := 3 * cos(NewTime / 3);
  Sky.AbsolutePosition := Camera.AbsolutePosition;
end;

// Direct OpenGL rendering
//
procedure TFormSkyShader.DirectOGLRender;
begin
  if not Cadencer.Enabled then
    initGLSL;
  // sky cubemap
  GLSL_sky.UseProgramObject;
  Sky.Render(rci);
  GLSL_sky.EndUseProgramObject;
  // object cubemap
  GLSL_obj.UseProgramObject;
  GLSL_obj.UniformMatrix4fv['m4'] := Sphere.AbsoluteMatrix;
  Sphere.Render(rci);
  GLSL_obj.UniformMatrix4fv['m4'] := Thor.AbsoluteMatrix;
  Thor.Render(rci);
  GLSL_obj.EndUseProgramObject;
end;

// GLSL Initialization
//
function Load(vp, fp: String): TGLProgramHandle;
begin
  Result := TGLProgramHandle.CreateAndAllocate;
  Result.AddShader(TGLVertexShaderHandle, LoadAnsiStringFromFile(vp));
  Result.AddShader(TGLFragmentShaderHandle, LoadAnsiStringFromFile(fp));
  if not Result.LinkProgram then
    raise Exception.Create(Result.InfoLog);
  if not Result.ValidateProgram then
    raise Exception.Create(Result.InfoLog);
end;

procedure TFormSkyShader.InitGLSL;
begin
  Cadencer.Enabled := True;

 // Loading shaders from asset
  SetCurrentDir(Path  + '\shader');
  GLSL_sky := Load('sky.vp', 'sky.fp');
  GLSL_obj := Load('obj.vp', 'obj.fp');

end;

end.
