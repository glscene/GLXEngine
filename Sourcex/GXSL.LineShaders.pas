//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXSL.LineShaders;

(*
   A shader that renders hidden (back-faced) lines differently from visible
   (front) lines. Polygon offset is used to displace fragments depths a little
   so that there is no z-fighting in rendering the same geometry multiple times.
*)

interface

uses
  Winapi.OpenGL,
  System.Classes,

  Stage.OpenGLTokens,
  Stage.VectorTypes,
  GXS.Scene,
  GXS.Color,
  GXS.Material,
  GXS.BaseClasses,
  GXS.RenderContextInfo,
  GXS.State,
  GXS.Context;

type
  TgxLineSettings = class(TgxUpdateAbleObject)
  private
    FColor: TgxColor;
    FWidth: Single;
    FPattern: TGLushort;
    FForceMaterial: Boolean;
    procedure SetPattern(const value: TGLushort);
    procedure SetColor(const v: TgxColor);
    procedure SetWidth(const Value: Single);
    procedure SetForceMaterial(v: boolean);
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Apply(var rci: TgxRenderContextInfo);
    procedure UnApply(var rci: TgxRenderContextInfo);
  published
    property Width: Single read FWidth write SetWidth;
    property Color: TgxColor read FColor write SetColor;
    property Pattern: TGLushort read FPattern write SetPattern default $FFFF;
    (* Set ForceMaterial to true to enforce the application of the line settings
       for objects that sets their own color, line width and pattern. *)
    property ForceMaterial: Boolean read FForceMaterial write SetForceMaterial
      default false;
  end;

  TgxHiddenLineShader = class(TgxShader)
  private
    FPassCount: integer;
    FLineSmooth: Boolean;
    FSolid: Boolean;
    FBackGroundColor: TgxColor;
    FFrontLine: TgxLineSettings;
    FBackLine: TgxLineSettings;
    FLighting: Boolean;
    FShadeModel: TgxShadeModel;
    procedure SetlineSmooth(v: boolean);
    procedure SetSolid(v: boolean);
    procedure SetBackgroundColor(AColor: TgxColor);
    procedure SetLighting(v: boolean);
    procedure SetShadeModel(const val: TgxShadeModel);
  protected
    procedure DoApply(var rci: TgxRenderContextInfo; Sender: TObject); override;
    function DoUnApply(var rci: TgxRenderContextInfo): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property FrontLine: TgxLineSettings read FFrontLine write FFrontLine;
    property BackLine: TgxLineSettings read FBackLine write FBackLine;
    // Line smoothing control
    property LineSmooth: Boolean read FlineSmooth write SetlineSmooth default
      false;
    // Solid controls if you can see through the front-line wireframe.
    property Solid: Boolean read FSolid write SetSolid default false;
    // Color used for solid fill.
    property BackgroundColor: TgxColor read FBackgroundColor write
      SetBackgroundColor;
    // When Solid is True, determines if lighting or background color is used.
    property SurfaceLit: Boolean read FLighting write SetLighting default true;
    // Shade model. Default is "Smooth".
    property ShadeModel: TgxShadeModel read FShadeModel write SetShadeModel
      default smDefault;
  end;

  TgxOutlineShader = class(TgxShader)
  private
    FPassCount: integer;
    FLineColor: TgxColor;
    FOutlineSmooth: Boolean;
    FOutlineWidth: Single;
    procedure SetOutlineWidth(v: single);
    procedure SetOutlineSmooth(v: boolean);
  protected
    procedure DoApply(var rci: TgxRenderContextInfo; Sender: TObject); override;
    function DoUnApply(var rci: TgxRenderContextInfo): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property LineColor: TgxColor read FLineColor write FLineColor;
    // Line smoothing control
    property LineSmooth: Boolean read FOutlineSmooth write SetOutlineSmooth
      default false;
    property LineWidth: Single read FOutlineWidth write SetOutlineWidth;
  end;


// ------------------------------------------------------------------
implementation
// ------------------------------------------------------------------

uses
  Stage.TextureFormat;

// ------------------
// ------------------ TgxLineSettings ------------------
// ------------------


constructor TgxLineSettings.Create(AOwner: TPersistent);
begin
  inherited;
  FColor := TgxColor.Create(Self);
  FColor.Initialize(clrGray20);
  FWidth := 2;
  Pattern := $FFFF;
  ForceMaterial := false;
end;


destructor TgxLineSettings.Destroy;
begin
  FColor.Free;
  inherited;
end;

procedure TgxLineSettings.SetPattern(const value: TGLushort);
begin
  if FPattern <> value then
  begin
    FPattern := Value;
    NotifyChange(self);
  end;
end;

procedure TgxLineSettings.SetColor(const v: TgxColor);
begin
  FColor.Color := v.Color;
  NotifyChange(Self);
end;

procedure TgxLineSettings.SetWidth(const Value: Single);
begin
  FWidth := Value;
  NotifyChange(Self);
end;

var
  IgnoreMatSave: boolean;


procedure TgxLineSettings.Apply(var rci: TgxRenderContextInfo);
begin
  rci.gxStates.LineWidth := Width;
  glColor4fv(@Color.AsAddress^);
  if Pattern <> $FFFF then
  begin
    rci.gxStates.Enable(stLineStipple);
    rci.gxStates.LineStippleFactor := 1;
    rci.gxStates.LineStipplePattern := Pattern;
  end
  else
    rci.gxStates.Disable(stLineStipple);

  if ForceMaterial then
  begin
    IgnoreMatSave := rci.ignoreMaterials;
    rci.ignoreMaterials := true;
  end;
end;


procedure TgxLineSettings.UnApply(var rci: TgxRenderContextInfo);
begin
  if ForceMaterial then
    rci.ignoreMaterials := IgnoreMatSave;
end;


procedure TgxLineSettings.SetForceMaterial(v: boolean);
begin
  if FForceMaterial <> v then
  begin
    FForceMaterial := v;
    NotifyChange(self);
  end;
end;

// ------------------
// ------------------ TgxHiddenLineShader ------------------
// ------------------

constructor TgxHiddenLineShader.Create(AOwner: TComponent);
begin
  inherited;
  FFrontLine := TgxLineSettings.Create(self);
  FBackLine := TgxLineSettings.Create(self);
  FSolid := false;

  FBackgroundColor := TgxColor.Create(Self);
  FBackgroundColor.Initialize(clrBtnFace);

  FLineSmooth := False;
  FLighting := true;
  FShadeModel := smDefault;
end;

destructor TgxHiddenLineShader.Destroy;
begin
  FFrontLine.Free;
  FBackLine.Free;
  FBackgroundColor.Free;
  inherited;
end;


procedure TgxHiddenLineShader.DoApply(var rci: TgxRenderContextInfo; Sender:
  TObject);
begin
  FPassCount := 1;

  if solid then
    with rci.gxStates do
    begin
      // draw filled front faces in first pass
      PolygonMode := pmFill;
      CullFaceMode := cmBack;

      if FLighting then
      begin
        case ShadeModel of
          smDefault, smSmooth: glShadeModel(GL_SMOOTH);
          smFlat: glShadeModel(GL_FLAT);
        end
      end
      else
      begin
        Disable(stLighting);
        glColor4fv(@FBackgroundColor.AsAddress^); // use background color
      end;
      // enable and adjust polygon offset
      Enable(stPolygonOffsetFill);
    end
  else
    with rci.gxStates do
    begin
      Disable(stLighting);
      // draw back lines in first pass
      FBackLine.Apply(rci);
      CullFaceMode := cmFront;
      PolygonMode := pmLines;
      // enable and adjust polygon offset
      Enable(stPolygonOffsetLine);
    end;

  rci.gxStates.SetPolygonOffset(1, 2);
end;


function TgxHiddenLineShader.DoUnApply(var rci: TgxRenderContextInfo): Boolean;

  procedure SetLineSmoothBlend;
  begin
    with rci.gxStates do
    begin
      LineStippleFactor := 1;
      LineStipplePattern := $FFFF;
      if LineSmooth then
      begin
        LineSmoothHint := hintNicest;
        Enable(stLineSmooth);
      end
      else
        Disable(stLineSmooth);

      if LineSmooth or (FBackLine.FColor.Alpha < 1)
        or (FFrontLine.FColor.Alpha < 1) then
      begin
        Enable(stBlend);
        SetBlendFunc(bfSrcAlpha, bfOneMinusSrcAlpha);
      end
      else
        Disable(stBlend);
    end;
  end;

begin
  case FPassCount of
    1:
      with rci.gxStates do
      begin
        // draw front line in 2nd pass
        FPassCount := 2;

        FBackLine.UnApply(rci);
        FFrontLine.Apply(rci);

        SetLineSmoothBlend;

        if solid and FLighting then
          Disable(stLighting);

        PolygonMode := pmLines;
        CullFaceMode := cmBack;

        if solid then
          rci.gxStates.Disable(stPolygonOffsetFill)
        else
          rci.gxStates.Disable(stPolygonOffsetLine);

        Result := True;
      end;
    2:
      begin
        FFrontLine.UnApply(rci);
        rci.gxStates.PolygonMode := pmFill;
        Result := false;
      end;
  else
    Assert(False);
    Result := False;
  end;
end;


procedure TgxHiddenLineShader.SetBackgroundColor(AColor: TgxColor);
begin
  FBackgroundColor.Color := AColor.Color;
  NotifyChange(Self);
end;


procedure TgxHiddenLineShader.SetlineSmooth(v: boolean);
begin
  if FlineSmooth <> v then
  begin
    FlineSmooth := v;
    NotifyChange(self);
  end;
end;


procedure TgxHiddenLineShader.SetLighting(v: boolean);
begin
  if FLighting <> v then
  begin
    FLighting := v;
    NotifyChange(self);
  end;
end;


procedure TgxHiddenLineShader.SetSolid(v: boolean);
begin
  if FSolid <> v then
  begin
    FSolid := v;
    NotifyChange(self);
  end;
end;


procedure TgxHiddenLineShader.SetShadeModel(const val: TgxShadeModel);
begin
  if FShadeModel <> val then
  begin
    FShadeModel := val;
    NotifyChange(Self);
  end;
end;


(*--------------------------------------
 TgxOutlineShader
 --------------------------------------*)

constructor TgxOutlineShader.Create(AOwner: TComponent);
begin
  inherited;
  FOutlineSmooth := False;
  FOutLineWidth := 2;
  FLineColor := TgxColor.CreateInitialized(Self, clrBlack);
  ShaderStyle := ssLowLevel;
end;

destructor TgxOutlineShader.Destroy;
begin
  FLineColor.Free;
  inherited;
end;

procedure TgxOutlineShader.DoApply(var rci: TgxRenderContextInfo; Sender:
  TObject);
begin
  // We first draw the object as usual in the first pass. This allows objects
  // with color alpha < 1 to be rendered correctly with outline.
  FPassCount := 1;
end;

function TgxOutlineShader.DoUnApply(var rci: TgxRenderContextInfo): Boolean;
begin
  if rci.ignoreMaterials or (stStencilTest in rci.gxStates.States) then
  begin
    Result := False;
    Exit;
  end;
  case FPassCount of
    1:
      with rci.gxStates do
      begin
        // Now set up to draw the outline in the second pass

        Disable(stLighting);
        if FOutlineSmooth then
        begin
          LineSmoothHint := hintNicest;
          Enable(stLineSmooth);
        end
        else
          Disable(stLineSmooth);
        if FOutlineSmooth or (FlineColor.Alpha < 1) then
        begin
          Enable(stBlend);
          SetBlendFunc(bfSrcAlpha, bfOneMinusSrcAlpha);
        end
        else
          Disable(stBlend);
        glColor4fv(@FlineColor.AsAddress^);
        LineWidth := FOutlineWidth;
        Disable(stLineStipple);
        PolygonMode := pmLines;
        CullFaceMode := cmFront;
        DepthFunc := cfLEqual;
        ActiveTextureEnabled[ttTexture2D] := False;

        FPassCount := 2;
        Result := True; // go for next pass
      end;
    2:
      with rci.gxStates do
      begin
        // Restore settings
        PolygonMode := pmFill;
        CullFaceMode := cmBack;
        DepthFunc := cfLequal;
        Result := False; // we're done
      end;
  else
    Assert(False);
    Result := False;
  end;
end;

procedure TgxOutlineShader.SetOutlineWidth(v: single);
begin
  if FOutlineWidth <> v then
  begin
    FOutlineWidth := v;
    NotifyChange(self);
  end;
end;

procedure TgxOutlineShader.SetOutlineSmooth(v: boolean);
begin
  if FOutlineSmooth <> v then
  begin
    FOutlineSmooth := v;
    NotifyChange(self);
  end;
end;


end.

