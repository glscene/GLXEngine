(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit GLS.GizmoArrows;
(*
  Arrows based on Gizmo
*)
interface

uses
  Winapi.OpenGL,
  Winapi.OpenGLext,
  System.SysUtils,
  System.Classes,

  Stage.VectorGeometry,
  Stage.OpenGLTokens,
  Stage.VectorTypes,
  Stage.VectorLists,
  Stage.Color,

  GLS.Scene,
  GLS.Context,
  GLS.Objects,
  GLS.RenderContextInfo,
  GLS.State;

type
  TGizmoArrowType = (gtAxisX, gtAxisY, gtAxisZ);
  TGizmoCornerType = (gtPlaneXY, gtPlaneXZ, gtPlaneYZ);

  TGLGizmoArrow = class(TGLQuadricObject)
  private
    FGizmoType: TGizmoArrowType;
    FBottomRadius: Single;
    FHeight: Single;
    FArrowHeadHeight: Single;
    FSelected: Boolean;
    FSelectedColor: TGSColor;
    procedure SetGizmoType(const Value: TGizmoArrowType);
    procedure SetBottomRadius(const Value: Single);
    procedure SetHeight(const Value: Single);
    procedure SetArrowHeadHeight(const Value: Single);
    procedure SetSelected(const Value: Boolean);
    procedure SetSelectedColor(const Value: TGSColor);
  protected
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure BuildList(var rci: TGLRenderContextInfo); override;
  published
    property GizmoType: TGizmoArrowType read FGizmoType write SetGizmoType;
    property BottomRadius: Single read FBottomRadius write SetBottomRadius;
    property Height: Single read FHeight write SetHeight;
    property ArrowHeadHeight: Single read FArrowHeadHeight
      write SetArrowHeadHeight;
    property Selected: Boolean read FSelected write SetSelected;
    property SelectedColor: TGSColor read FSelectedColor write SetSelectedColor;
  end;

  TGLGizmoCorner = class(TGLQuadricObject)
  private
    FGizmoType: TGizmoCornerType;
    FHeight: Single;
    FDistance: Single;
    FSelected: Boolean;
    FSelectedColor: TGSColor;
    procedure SetGizmoType(const Value: TGizmoCornerType);
    procedure SetHeight(const Value: Single);
    procedure SetDistance(const Value: Single);
    procedure SetSelected(const Value: Boolean);
    procedure SetSelectedColor(const Value: TGSColor);
  protected
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure BuildList(var rci: TGLRenderContextInfo); override;
  published
    property GizmoType: TGizmoCornerType read FGizmoType write SetGizmoType;
    property Height: Single read FHeight write SetHeight;
    property Distance: Single read FDistance write SetDistance;
    property Selected: Boolean read FSelected write SetSelected;
    property SelectedColor: TGSColor read FSelectedColor write SetSelectedColor;
  end;

implementation //============================================================

//-----------------------------------------------
// TGLGizmoArrow
//-----------------------------------------------
procedure TGLGizmoArrow.Assign(Source: TPersistent);
begin
  inherited;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoArrow.BuildList(var rci: TGLRenderContextInfo);
var
  color: TGSColorVector;
  quadric: GLUquadricObj;
  MultiplierX, MultiplierY, MultiplierZ: Byte;
begin // Shut up compuiler
  MultiplierX := 1;
  MultiplierY := 0;
  MultiplierZ := 0;
  case FGizmoType of
    gtAxisX:
      begin
        color := clrRed;
        MultiplierX := 1;
        MultiplierY := 0;
        MultiplierZ := 0;
      end;
    gtAxisY:
      begin
        color := clrGreen;
        MultiplierX := 0;
        MultiplierY := 1;
        MultiplierZ := 0;
      end;
    gtAxisZ:
      begin
        color := clrBlue;
        MultiplierX := 0;
        MultiplierY := 0;
        MultiplierZ := 1;
      end;
  end;
  glDisable(GL_DEPTH_TEST);
  glPushAttrib(GL_ENABLE_BIT or GL_CURRENT_BIT or GL_LIGHTING_BIT or
    GL_LINE_BIT or GL_COLOR_BUFFER_BIT);
  glDisable(GL_LIGHTING);
  glEnable(GL_LINE_SMOOTH);
  glLineWidth(1);
  // ResetGLMaterialColors;
  glColorMaterial(GL_FRONT, GL_EMISSION);
  glEnable(GL_COLOR_MATERIAL);
  if Selected then
  begin
    GL.Color4fv(SelectedColor.AsAddress);
  end
  else
  begin
    glColor4fv(@color);
  end;

  glBegin(GL_LINES);
  glVertex3f(0, 0, 0);
  glVertex3f((FHeight - FArrowHeadHeight) * MultiplierX,
   (FHeight - FArrowHeadHeight) * MultiplierY, (FHeight - FArrowHeadHeight)*MultiplierZ);
  glEnd;

  glPushMatrix;
  glColor4fv(@color);
  quadric := gluNewQuadric();
  SetupQuadricParams(PGLUQuadric(quadric));

  case FGizmoType of
    gtAxisX:
      begin
        glRotated(90, 0, 1, 0);
        glTranslatef(0, 0, FHeight - FArrowHeadHeight); // {FHeight}0.2*0.5
      end;
    gtAxisY:
      begin
        glRotated(-90, 1, 0, 0);
        glTranslatef(0, 0, FHeight - FArrowHeadHeight); // {FHeight}0.2*0.5
      end;
    gtAxisZ:
      begin
        glRotated(-90, 0, 0, 1);
        glTranslatef(0, 0, FHeight - FArrowHeadHeight); // {FHeight}0.2*0.5
      end;
  end;

  gluCylinder(quadric, BottomRadius, 0, FArrowHeadHeight, { Slices } 8, { Stacks } 2);
  SetInvertedQuadricOrientation(PGLUQuadric(quadric));
  // color := clrBlack;
  glColor4fv(@color);
  gluDisk(quadric, 0, BottomRadius, { Slices } 8, { FLoops } 1);
  gluDeleteQuadric(quadric);
  glPopMatrix;
  glPopAttrib;
  // Switch back to the normal rendering mode
  glEnable(GL_DEPTH_TEST);
end;

//---------------------------------------------------------------------------
constructor TGLGizmoArrow.Create(AOwner: TComponent);
begin
  inherited;
  FBottomRadius := 0.05;
  FHeight := 1;
  FArrowHeadHeight := 0.2;
  ObjectStyle := ObjectStyle + [osDirectDraw];
  FSelected := False;
  FSelectedColor := TGSColor.Create(Self);
  FSelectedColor.color := clrYellow;
end;

//---------------------------------------------------------------------------
destructor TGLGizmoArrow.Destroy;
begin
  FSelectedColor.Free;
  inherited;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetArrowHeadHeight(const Value: TGLFloat);
begin
  if FArrowHeadHeight <> Value then
  begin
    FArrowHeadHeight := Value;
    StructureChanged;
  end;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetBottomRadius(const Value: TGLFloat);
begin
  if FBottomRadius <> Value then
  begin
    FBottomRadius := Value;
    StructureChanged;
  end;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetGizmoType(const Value: TGizmoArrowType);
begin
  if FGizmoType <> Value then
  begin
    FGizmoType := Value;
    StructureChanged;
  end;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetHeight(const Value: TGLFloat);
begin
  if FHeight <> Value then
  begin
    FHeight := Value;
    StructureChanged;
  end;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetSelected(const Value: Boolean);
begin
  if FSelected <> Value then
  begin
    FSelected := Value;
    NotifyChange(Self);
  end;
end;

//-----------------------------------------------------------------------------
procedure TGLGizmoArrow.SetSelectedColor(const Value: TGSColor);
begin
  FSelectedColor.color := Value.color;
  NotifyChange(Self);
end;

//-----------------------------------------------
// TGLGizmoCorner
//-----------------------------------------------
procedure TGLGizmoCorner.Assign(Source: TPersistent);
begin
  inherited;

end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.BuildList(var rci: TGLRenderContextInfo);
var
  color: TGSColorVector;
  MultiplierX, MultiplierY, MultiplierZ: Byte;
begin
  glDisable(GL_DEPTH_TEST);
  // Shut up compiler
  MultiplierX := 1;
  MultiplierY := 1;
  MultiplierZ := 0;
  case FGizmoType of
    gtPlaneXY:
      begin
        MultiplierX := 1;
        MultiplierY := 1;
        MultiplierZ := 0;
      end;
    gtPlaneXZ:
      begin
        MultiplierX := 1;
        MultiplierY := 0;
        MultiplierZ := 1;
      end;
    gtPlaneYZ:
      begin
        MultiplierX := 0;
        MultiplierY := 1;
        MultiplierZ := 1;
      end;
  end;

  glPushAttrib(GL_ENABLE_BIT or GL_CURRENT_BIT or GL_LIGHTING_BIT or
    GL_LINE_BIT or GL_COLOR_BUFFER_BIT);
  glDisable(GL_LIGHTING);
  glEnable(GL_LINE_SMOOTH);

  glLineWidth(1);

  glColorMaterial(GL_FRONT, GL_EMISSION);
  glEnable(GL_COLOR_MATERIAL);

  if Selected then
  begin
    GL.Color4fv(SelectedColor.AsAddress);
  end
  else
  begin
    if MultiplierY = 1 then
    begin
      color := clrGreen;
      glColor4fv(@color);
    end
    else
    begin
      color := clrBlue;
      glColor4fv(@color);
    end;
  end;

  glBegin(GL_LINES);
  // x part of the corner
  glVertex3f(FDistance * MultiplierX, FDistance * MultiplierY,
    FDistance * MultiplierZ);
  glVertex3f((FDistance - FHeight) * MultiplierX, FDistance * MultiplierY,
    FDistance * MultiplierZ);
  glEnd;

  if Selected then
  begin
    GL.Color4fv(SelectedColor.AsAddress);
  end
  else
  begin
    if MultiplierX = 1 then
    begin
      color := clrRed;
      glColor4fv(@color);
    end
    else
    begin
      color := clrBlue;
      glColor4fv(@color);
    end;
  end;

  glBegin(GL_LINES);
  // y part of the corner
  glVertex3f(FDistance * MultiplierX, FDistance * MultiplierY,
    FDistance * MultiplierZ);
  glVertex3f(FDistance * MultiplierX, (FDistance - FHeight) * MultiplierY,
    FDistance * MultiplierZ);
  glEnd;

  if Selected then
  begin
    GL.Color4fv(SelectedColor.AsAddress);
  end
  else
  begin
    if MultiplierX = 1 then
    begin
      color := clrRed;
      glColor4fv(@color);
    end
    else
    begin
      color := clrGreen;
      glColor4fv(@color);
    end;
  end;

  glBegin(GL_LINES);
  // z part of the corner
  glVertex3f(FDistance * MultiplierX, FDistance * MultiplierY,
    FDistance * MultiplierZ);
  glVertex3f(FDistance * MultiplierX, FDistance * MultiplierY,
    (FDistance - FHeight) * MultiplierZ);
  glEnd;

  glPopAttrib;

  // Switch back to the normal rendering mode
  glEnable(GL_DEPTH_TEST);
end;

//---------------------------------------------------------------------------
constructor TGLGizmoCorner.Create(AOwner: TComponent);
begin
  inherited;
  FHeight := 0.2;
  FDistance := 1;
  ObjectStyle := ObjectStyle + [osDirectDraw];

  FSelectedColor := TGSColor.Create(Self);
  FSelectedColor.color := clrYellow;
end;

//---------------------------------------------------------------------------
destructor TGLGizmoCorner.Destroy;
begin
  FSelectedColor.Free;
  inherited;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.SetDistance(const Value: TGLFloat);
begin
  if FDistance <> Value then
  begin
    FDistance := Value;
    StructureChanged;
  end;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.SetGizmoType(const Value: TGizmoCornerType);
begin
  if FGizmoType <> Value then
  begin
    FGizmoType := Value;
    StructureChanged;
  end;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.SetHeight(const Value: TGLFloat);
begin
  if FHeight <> Value then
  begin
    FHeight := Value;
    StructureChanged;
  end;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.SetSelected(const Value: Boolean);
begin
  if FSelected <> Value then
  begin
    FSelected := Value;
    NotifyChange(Self);
  end;
end;

//---------------------------------------------------------------------------
procedure TGLGizmoCorner.SetSelectedColor(const Value: TGSColor);
begin
  FSelectedColor.color := Value.color;
  NotifyChange(Self);
end;

end.
