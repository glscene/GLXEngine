//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXS.ParametricSurfaces;

(*
  Parametric surface implementation (like Bezier and BSpline surfaces)

  Notes:
  The MOParametricSurface is a TgxMeshObject descendant that can be used
  to render parametric surfaces. The Renderer property defines if the
  surface should be rendered using mesh evaluators (through GLU
  Nurbs for BSplines) or through GLScene using the CurvesAndSurfaces.pas
  routines to generate the mesh vertices and then rendered through the
  standard TgxMeshObject render routine. Please note that BSplines aren't
  correctly handled yet in the CurvesAndSurfaces unit so the output mesh
  in rendering mode is wrong. I'll have it fixed when I know
  what's going wrong. The GLU Nurbs and glMeshEval Beziers work well
  though.

  The FGBezierSurface is a face group decendant that renders the surface
  using mesh evaluators. The ControlPointIndices point to the mesh object
  vertices much the same as vertex indices for other face group flavours.
  The MinU, MaxU, MinV and MaxV properties allow for drawing specific
  parts of the bezier surface, which can be used to blend a patch with
  other patches.
*)

interface

{$I Stage.Defines.inc}

uses
  Winapi.OpenGL,

  Stage.VectorTypes,
  GXS.CurvesAndSurfaces,
  Stage.VectorGeometry,

  GXS.VectorLists,
  GXS.PersistentClasses,
  GXS.VectorFileObjects,
  GXS.Texture,
  GXS.State,
  GXS.Context,
  GXS.RenderContextInfo;

type

  (* psrGLXcene tells the surface to render using GLScene code to build
    the mesh, whereas, psrOpenVX uses glEvalMesh2 or gluNurbsRenderer
    calls to render the surface. *)
  TParametricSurfaceRenderer = (psrGLXcene, psrOpenVX);

  (* psbBezier indicates building the surface with Bernstein basis
    functions, no knot or order properties are used.
    psbBSpline indicates building the surface using BSpline basis
    functions, these require orders and knot vectors to define the
    control point influences on the surface. *)
  TParametricSurfaceBasis = (psbBezier, psbBSpline);

  TMOParametricSurface = class(TgxMeshObject)
  private
    FControlPoints, FWeightedControlPoints: TgxAffineVectorList;
    FKnotsU, FKnotsV, FWeights: TgxSingleList;
    FOrderU, FOrderV, FCountU, FCountV, FResolution: Integer;
    FAutoKnots: Boolean;
    FContinuity: TBSplineContinuity;
    FRenderer: TParametricSurfaceRenderer;
    FBasis: TParametricSurfaceBasis;
    procedure SetControlPoints(Value: TgxAffineVectorList);
    procedure SetKnotsU(Value: TgxSingleList);
    procedure SetKnotsV(Value: TgxSingleList);
    procedure SetWeights(Value: TgxSingleList);
    procedure SetRenderer(Value: TParametricSurfaceRenderer);
    procedure SetBasis(Value: TParametricSurfaceBasis);
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure WriteToFiler(writer: TgxVirtualWriter); override;
    procedure ReadFromFiler(reader: TgxVirtualReader); override;
    procedure BuildList(var mrci: TgxRenderContextInfo); override;
    procedure Prepare; override;
    procedure Clear; override;
    (* Generates a mesh approximation of the surface defined by the
      properties below. This is used to construct the mesh when using
      Renderer = psrGLXcene. If you want to render using OpenGL calls
      but would like to obtain the mesh data also use this call to
      generate the mesh data. Fills in Vertices, Normals, etc. *)
    procedure GenerateMesh;
    // Control points define the parametric surface.
    property ControlPoints: TgxAffineVectorList read FControlPoints write SetControlPoints;
    { KnotsU and KnotsV are the knot vectors in the U and V direction. Knots
      define the continuity of curves and how control points influence the
      parametric values to build the surface. }
    property KnotsU: TgxSingleList read FKnotsU write SetKnotsU;
    property KnotsV: TgxSingleList read FKnotsV write SetKnotsV;
    { Weights define how much a control point effects the surface. }
    property Weights: TgxSingleList read FWeights write SetWeights;
    // OrderU and OrderV defines the curve order in the U and V direction
    property OrderU: Integer read FOrderU write FOrderU;
    property OrderV: Integer read FOrderV write FOrderV;
    { CountU and CountV describe the number of control points in the
      U and V direciton. Basically a control point width and height
      in (u,v) space. }
    property CountU: Integer read FCountU write FCountU;
    property CountV: Integer read FCountV write FCountV;
    { Defines how fine the resultant mesh will be. Higher values create
      finer meshes. Resolution = 50 would produce a 50x50 mesh.
      The GLU Nurbs rendering uses resolution as the U_STEP and V_STEP
      using the sampling method GLU_DOMAIN_DISTANCE, so the resolution
      works a little differently there. }
    property Resolution: Integer read FResolution write FResolution;
    { Automatically generate the knot vectors based on the Continuity.
      Only applies to BSpline surfaces. }
    property AutoKnots: Boolean read FAutoKnots write FAutoKnots;
    property Continuity: TBSplineContinuity read FContinuity write FContinuity;
    { Determines whether to use OpenGL calls (psrOpenGL) or the GLScene
      mesh objects (psrGLScene) to render the surface. }
    property Renderer: TParametricSurfaceRenderer read FRenderer write SetRenderer;
    // Basis determines the style of curve, psbBezier or psbBSpline
    property Basis: TParametricSurfaceBasis read FBasis write SetBasis;
  end;

  (* A 3d bezier surface implemented through facegroups. The ControlPointIndices
    is an index to control points stored in the MeshObject.Vertices affine
    vector list. Similarly the TexCoordIndices point to the owner
    MeshObject.TexCoords, one for each control point.
    CountU and CountV define the width and height of the surface.
    Resolution sets the detail level of the mesh evaluation.
    MinU, MaxU, MinV and MaxV define the region of the surface to be rendered,
    this is especially useful for blending with neighbouring patches. *)
  TFGBezierSurface = class(TgxFaceGroup)
  private
    FCountU, FCountV: Integer;
    FControlPointIndices, FTexCoordIndices: TgxIntegerList;
    FResolution: Integer;
    FMinU, FMaxU, FMinV, FMaxV: Single;
    FTempControlPoints, FTempTexCoords: TgxAffineVectorList;
  protected
    procedure SetControlPointIndices(const Value: TgxIntegerList);
    procedure SetTexCoordIndices(const Value: TgxIntegerList);
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure WriteToFiler(writer: TgxVirtualWriter); override;
    procedure ReadFromFiler(reader: TgxVirtualReader); override;
    procedure BuildList(var mrci: TgxRenderContextInfo); override;
    procedure Prepare; override;
    property CountU: Integer read FCountU write FCountU;
    property CountV: Integer read FCountV write FCountV;
    property Resolution: Integer read FResolution write FResolution;
    property MinU: Single read FMinU write FMinU;
    property MaxU: Single read FMaxU write FMaxU;
    property MinV: Single read FMinV write FMinV;
    property MaxV: Single read FMaxV write FMaxV;
    property ControlPointIndices: TgxIntegerList read FControlPointIndices write SetControlPointIndices;
    property TexCoordIndices: TgxIntegerList read FTexCoordIndices write SetTexCoordIndices;
  end;

// ----------------------------------------------------------------------
implementation
// ----------------------------------------------------------------------

// ------------------
// ------------------ TMOParametricSurface ------------------
// ------------------

constructor TMOParametricSurface.Create;
begin
  inherited;

  FControlPoints := TgxAffineVectorList.Create;
  FWeightedControlPoints := TgxAffineVectorList.Create;
  FKnotsU := TgxSingleList.Create;
  FKnotsV := TgxSingleList.Create;
  FWeights := TgxSingleList.Create;

  Resolution := 20;
end;

destructor TMOParametricSurface.Destroy;
begin
  FControlPoints.Free;
  FWeightedControlPoints.Free;
  FKnotsU.Free;
  FKnotsV.Free;
  FWeights.Free;
  inherited;
end;

procedure TMOParametricSurface.WriteToFiler(writer: TgxVirtualWriter);
begin
  inherited WriteToFiler(writer);
  with writer do
  begin
    WriteInteger(0); // Archive Version
    FControlPoints.WriteToFiler(writer);
    FKnotsU.WriteToFiler(writer);
    FKnotsV.WriteToFiler(writer);
    FWeights.WriteToFiler(writer);
    WriteInteger(FOrderU);
    WriteInteger(FOrderV);
    WriteInteger(FCountU);
    WriteInteger(FCountV);
    WriteInteger(FResolution);
    WriteBoolean(FAutoKnots);
    WriteInteger(Integer(FContinuity));
    WriteInteger(Integer(FRenderer));
    WriteInteger(Integer(FBasis));
  end;
end;

procedure TMOParametricSurface.ReadFromFiler(reader: TgxVirtualReader);
var
  archiveVersion: Integer;
begin
  inherited ReadFromFiler(reader);
  archiveVersion := reader.ReadInteger;
  if archiveVersion = 0 then
    with reader do
    begin
      FControlPoints.ReadFromFiler(reader);
      FKnotsU.ReadFromFiler(reader);
      FKnotsV.ReadFromFiler(reader);
      FWeights.ReadFromFiler(reader);
      FOrderU := ReadInteger;
      FOrderV := ReadInteger;
      FCountU := ReadInteger;
      FCountV := ReadInteger;
      FResolution := ReadInteger;
      FAutoKnots := ReadBoolean;
      FContinuity := TBSplineContinuity(ReadInteger);
      FRenderer := TParametricSurfaceRenderer(ReadInteger);
      FBasis := TParametricSurfaceBasis(ReadInteger);
    end
  else
    RaiseFilerException(archiveVersion);
end;

procedure TMOParametricSurface.BuildList(var mrci: TgxRenderContextInfo);
var
  NurbsRenderer: GLUnurbsObj;
begin
  case FRenderer of
    psrGLXcene:
      inherited;
    psrOpenVX:
      begin
        glPushAttrib(GL_ENABLE_BIT or GL_EVAL_BIT); // [sttEnable, sttEval]);
        // glEnable(GL_MAP2_TEXTURE_COORD_3);
        glEnable(GL_MAP2_VERTEX_3);
        glEnable(GL_AUTO_NORMAL);
        glEnable(GL_NORMALIZE);

        case FBasis of
          psbBezier:
            begin
              glMapGrid2f(FResolution, 1, 0, FResolution, 0, 1);
              glMap2f(GL_MAP2_TEXTURE_COORD_3, 0, 1, 3, FOrderU, 0, 1, 3 * FCountU, FOrderV, @FWeightedControlPoints.List[0]);
              glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, FCountU, 0, 1, 3 * FCountU, FCountV, @FWeightedControlPoints.List[0]);
              glEvalMesh2(GL_FILL, 0, FResolution, 0, FResolution);
            end;

          psbBSpline:
            begin
              NurbsRenderer := @gluNewNurbsRenderer;
              gluNurbsProperty(@NurbsRenderer, GLU_DISPLAY_MODE, GLU_FILL);

              gluNurbsProperty(@NurbsRenderer, GLU_SAMPLING_METHOD, GLU_DOMAIN_DISTANCE);
              gluNurbsProperty(@NurbsRenderer, GLU_U_STEP, FResolution);
              gluNurbsProperty(@NurbsRenderer, GLU_V_STEP, FResolution);

              gluBeginSurface(@NurbsRenderer);
              gluNurbsSurface(@NurbsRenderer, FKnotsU.Count, @FKnotsU.List[0], FKnotsV.Count, @FKnotsV.List[0], 3, FCountU * 3,
                @FWeightedControlPoints.List[0], FOrderU, FOrderV, GL_MAP2_TEXTURE_COORD_3);
              gluNurbsSurface(@NurbsRenderer, FKnotsU.Count, @FKnotsU.List[0], FKnotsV.Count, @FKnotsV.List[0], 3, FCountU * 3,
                @FWeightedControlPoints.List[0], FOrderU, FOrderV, GL_MAP2_VERTEX_3);
              gluEndSurface(@NurbsRenderer);
              gluDeleteNurbsRenderer(@NurbsRenderer);
            end;

        end;
        mrci.gxStates.PopAttrib;
      end;
  end;
end;

procedure TMOParametricSurface.Prepare;
var
  i: Integer;
begin
  // We want to clear everything but the parametric surface
  // data (control points and knot vectors).
  inherited Clear;

  // Apply weights to control points
  FWeightedControlPoints.Assign(FControlPoints);
  if FWeights.Count = FControlPoints.Count then
    for i := 0 to FWeightedControlPoints.Count - 1 do
      FWeightedControlPoints[i] := VectorScale(FWeightedControlPoints[i], FWeights[i]);

  case FRenderer of
    psrGLXcene:
      begin
        GenerateMesh;
      end;
    psrOpenVX:
      begin
        if (FAutoKnots) and (FBasis = psbBSpline) then
        begin
          GenerateKnotVector(FKnotsU, FCountU, FOrderU, FContinuity);
          GenerateKnotVector(FKnotsV, FCountV, FOrderV, FContinuity);
        end;
      end;
  end;
end;

procedure TMOParametricSurface.Clear;
begin
  inherited;
  FControlPoints.Clear;
  FKnotsU.Clear;
  FKnotsV.Clear;
  FWeights.Clear;
end;

procedure TMOParametricSurface.GenerateMesh;
var
  i, j: Integer;
  fg: TgxFGVertexIndexList;
begin
  case FBasis of
    psbBezier:
      begin
        if FAutoKnots then
        begin
          FKnotsU.Clear;
          FKnotsV.Clear;
        end;
        GenerateBezierSurface(FResolution, FCountU, FCountV, FControlPoints, Vertices);
      end;
    psbBSpline:
      begin
        if FAutoKnots then
        begin
          GenerateKnotVector(FKnotsU, FCountU, FOrderU, FContinuity);
          GenerateKnotVector(FKnotsV, FCountV, FOrderV, FContinuity);
        end;
        GenerateBSplineSurface(FResolution, FOrderU, FOrderV, FCountU, FCountV, FKnotsU, FKnotsV, FControlPoints, Vertices);
      end;
  end;

  Mode := momFaceGroups;
  fg := TgxFGVertexIndexList.CreateOwned(FaceGroups);
  fg.Mode := fgmmTriangles;
  for j := 0 to FResolution - 2 do
    with fg do
      for i := 0 to FResolution - 2 do
      begin
        VertexIndices.Add(i + FResolution * j);
        VertexIndices.Add((i + 1) + FResolution * j);
        VertexIndices.Add(i + FResolution * (j + 1));

        VertexIndices.Add(i + FResolution * (j + 1));
        VertexIndices.Add((i + 1) + FResolution * j);
        VertexIndices.Add((i + 1) + FResolution * (j + 1));
      end;
  BuildNormals(fg.VertexIndices, momTriangles);
end;

procedure TMOParametricSurface.SetControlPoints(Value: TgxAffineVectorList);
begin
  FControlPoints.Assign(Value);
end;

procedure TMOParametricSurface.SetKnotsU(Value: TgxSingleList);
begin
  FKnotsU.Assign(Value);
end;

procedure TMOParametricSurface.SetKnotsV(Value: TgxSingleList);
begin
  FKnotsV.Assign(Value);
end;

procedure TMOParametricSurface.SetWeights(Value: TgxSingleList);
begin
  FWeights.Assign(Value);
end;

procedure TMOParametricSurface.SetRenderer(Value: TParametricSurfaceRenderer);
begin
  if Value <> FRenderer then
  begin
    FRenderer := Value;
    Owner.Owner.StructureChanged;
  end;
end;

procedure TMOParametricSurface.SetBasis(Value: TParametricSurfaceBasis);
begin
  if Value <> FBasis then
  begin
    FBasis := Value;
    Owner.Owner.StructureChanged;
  end;
end;

// ------------------
// ------------------ TFGBezierSurface ------------------
// ------------------

constructor TFGBezierSurface.Create;
begin
  inherited;
  FControlPointIndices := TgxIntegerList.Create;
  FTexCoordIndices := TgxIntegerList.Create;
  FTempControlPoints := TgxAffineVectorList.Create;
  FTempTexCoords := TgxAffineVectorList.Create;

  // Default values
  FCountU := 4;
  FCountV := 4;
  FResolution := 20;
  FMinU := 0;
  FMaxU := 1;
  FMinV := 0;
  FMaxV := 1;
end;

destructor TFGBezierSurface.Destroy;
begin
  FControlPointIndices.Free;
  FTexCoordIndices.Free;
  FTempControlPoints.Free;
  FTempTexCoords.Free;
  inherited;
end;

procedure TFGBezierSurface.WriteToFiler(writer: TgxVirtualWriter);
begin
  inherited WriteToFiler(writer);
  with writer do
  begin
    WriteInteger(0); // Archive Version 0
    FControlPointIndices.WriteToFiler(writer);
    FTexCoordIndices.WriteToFiler(writer);
    WriteInteger(FCountU);
    WriteInteger(FCountV);
    WriteInteger(FResolution);
    WriteFloat(FMinU);
    WriteFloat(FMaxU);
    WriteFloat(FMinV);
    WriteFloat(FMaxV);
  end;
end;

procedure TFGBezierSurface.ReadFromFiler(reader: TgxVirtualReader);
var
  archiveVersion: Integer;
begin
  inherited ReadFromFiler(reader);
  archiveVersion := reader.ReadInteger;
  if archiveVersion = 0 then
    with reader do
    begin
      FControlPointIndices.ReadFromFiler(reader);
      FTexCoordIndices.ReadFromFiler(reader);
      FCountU := ReadInteger;
      FCountV := ReadInteger;
      FResolution := ReadInteger;
      FMinU := ReadFloat;
      FMaxU := ReadFloat;
      FMinV := ReadFloat;
      FMaxV := ReadFloat;
    end
  else
    RaiseFilerException(archiveVersion);
end;

procedure TFGBezierSurface.BuildList(var mrci: TgxRenderContextInfo);
begin
  if (FTempControlPoints.Count = 0) or (FTempControlPoints.Count <> FControlPointIndices.Count) then
    Exit;

  AttachOrDetachLightmap(mrci);

  mrci.gxStates.PushAttrib([sttEnable, sttEval]);
  mrci.gxStates.Enable(stAutoNormal);
  mrci.gxStates.Enable(stNormalize);

  glMapGrid2f(FResolution, MaxU, MinU, FResolution, MinV, MaxV);

  if FTempTexCoords.Count > 0 then
  begin
    glEnable(GL_MAP2_TEXTURE_COORD_3);
    glMap2f(GL_MAP2_TEXTURE_COORD_3, 0, 1, 3, FCountU, 0, 1, 3 * FCountU, FCountV, @FTempTexCoords.List[0]);
  end;

  glEnable(GL_MAP2_VERTEX_3);
  glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, FCountU, 0, 1, 3 * FCountU, FCountV, @FTempControlPoints.List[0]);

  glEvalMesh2(GL_FILL, 0, FResolution, 0, FResolution);

  mrci.gxStates.PopAttrib;
end;

procedure TFGBezierSurface.SetControlPointIndices(const Value: TgxIntegerList);
begin
  FControlPointIndices.Assign(Value);
end;

procedure TFGBezierSurface.SetTexCoordIndices(const Value: TgxIntegerList);
begin
  FTexCoordIndices.Assign(Value);
end;

procedure TFGBezierSurface.Prepare;
var
  i, j: Integer;
begin
  inherited;
  FTempControlPoints.Clear;
  FTempTexCoords.Clear;
  for j := 0 to CountV - 1 do
    for i := CountU - 1 downto 0 do
    begin
      FTempControlPoints.Add(Owner.Owner.Vertices[ControlPointIndices[i + CountU * j]]);
      if TexCoordIndices.Count = ControlPointIndices.Count then
        FTempTexCoords.Add(Owner.Owner.TexCoords[TexCoordIndices[i + CountU * j]]);
    end;
end;

end.
