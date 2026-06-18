(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit fdTerrainer;
(*
  Ñreating and modifying terrain using a bitmap
*)

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  System.Math,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.Menus,

  Stage.VectorTypes,
  GLS.Scene,
  GLS.Objects,
  GLS.Cadencer,
  GLS.Texture,
  GLS.SceneViewer,
  GLS.GeomObjects,
  GLS.Material,
  Stage.Coordinates,

  Stage.BaseClasses,
  GLS.RenderContextInfo,
  GLS.Terrainer, Vcl.ExtDlgs;

type
  TFormTerrainer = class(TForm)
    GLScene1: TGLScene;
    GLSceneViewer1: TGLSceneViewer;
    GLMaterialLibrary1: TGLMaterialLibrary;
    GLCadencer1: TGLCadencer;
    GLCamera1: TGLCamera;
    GLLightSource1: TGLLightSource;
    GLDummyCube1: TGLDummyCube;
    GLDirectOpenGL1: TGLDirectOpenGL;
    GLCone1: TGLCone;
    MainMenu1: TMainMenu;
    miFile: TMenuItem;
    miFileOpen: TMenuItem;
    miFileSaveAs: TMenuItem;
    N4: TMenuItem;
    miExit: TMenuItem;
    OpenPictureDialog1: TOpenPictureDialog;
    SavePictureDialog1: TSavePictureDialog;
    procedure FormDestroy(Sender: TObject);
    procedure GLSceneViewer1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
    procedure GLDirectOpenGL1Render(Sender: TObject; var rci: TGLRenderContextInfo);
    procedure FormMouseWheel(Sender: TObject; Shift: TShiftState;
      WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
    procedure miExitClick(Sender: TObject);
    procedure miFileSaveAsClick(Sender: TObject);
    procedure miFileOpenClick(Sender: TObject);
  private
    MediaDir: TFileName;
    FTerrain: TGLTerrainer;
    GPoint: TPoint;
    FBrush: TGLTerrainerBrush;
    FModifier: TGLTerrainerHeightModifier;
    procedure UpdateCursor;
  public
  end;

var
  FormTerrainer: TFormTerrainer;

implementation //=============================================================

{$R *.dfm}

//----------------------------------------------------------------------------
procedure TFormTerrainer.FormCreate(Sender: TObject);
var
  FimeName: TFileName;
begin
  MediaDir := ExtractFilePath(ParamStr(0)) + 'media\';
  SetCurrentDir(MediaDir);
  GLSceneViewer1.Align:= alClient;
  GLSceneViewer1.Cursor:= crNone;

  FimeName := MediaDir + 'terrain.bmp';
  FTerrain:= TGLTerrainer.Create(FimeName, 0.05, 0.5);

  GPoint.X:= FTerrain.Data.XDim div 2;
  GPoint.Y:= FTerrain.Data.YDim div 2;

  UpdateCursor;
  FBrush:= TGLTerrainerCircularBrush.Create;
  FModifier:= TGLTerrainerModifier.Create(FTerrain.Data);
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.FormDestroy(Sender: TObject);
begin
  FBrush.Free;
  FModifier.Free;
  FTerrain.Free;
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.FormMouseWheel(Sender: TObject; Shift: TShiftState;
  WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
begin
  GLCamera1.AdjustDistanceToTarget(Power(1.1, WheelDelta/120));
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.GLDirectOpenGL1Render(Sender: TObject; var rci: TGLRenderContextInfo);
begin
  GLMaterialLibrary1.ApplyMaterial('TerrainMat', rci);
  FTerrain.Render;
  GLMaterialLibrary1.UnApplyMaterial(rci);
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.GLSceneViewer1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  GPoint.X:= round(((X / ClientWidth - 0.2) * 1.5) * FTerrain.Data.XDim);
  GPoint.Y:= round(((Y / ClientHeight - 0.2) * 1.5) * FTerrain.Data.YDim);

  UpdateCursor;
  if ssLeft in Shift then
  begin
    // increase elevation
    FModifier.Modify(GPoint.X, GPoint.Y, FBrush, 0.1);
    FTerrain.Data.CalculateNormals;
  end
  else if ssRight in Shift then
  begin
    // decrease elevation
    FModifier.Modify(GPoint.X, GPoint.Y, FBrush, -0.1);
    FTerrain.Data.CalculateNormals;
  end;
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.UpdateCursor;
begin
  GLCone1.Position.AsAffineVector:= FTerrain.GridPointPosition(GPoint.X, GPoint.Y);
  GLCone1.Position.Y:= GLCone1.Position.Y + GLCone1.Height / 2;
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.miFileOpenClick(Sender: TObject);
begin
  // OpenPictureDialog1.Execute
end;

procedure TFormTerrainer.miFileSaveAsClick(Sender: TObject);
begin
  // SavePictureDialog1.Execute
end;

//----------------------------------------------------------------------------
procedure TFormTerrainer.miExitClick(Sender: TObject);
begin
  Close;
end;

end.
