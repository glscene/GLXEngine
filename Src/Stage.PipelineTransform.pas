(*****************************************************************************
                          GLStage Graphics Engine
******************************************************************************)
unit Stage.PipelineTransform;

(* Pipeline transformations *)

interface

{$I Stage.Defines.inc}

uses
  Winapi.OpenGL,

  Stage.VectorTypes,
  Stage.VectorGeometry;

const
  MAX_MATRIX_STACK_DEPTH = 128;

type
  TGSPipelineTransformationState =
  (
    trsModelViewChanged,
    trsInvModelViewChanged,
    trsInvModelChanged,
    trsNormalModelChanged,
    trsViewProjChanged,
    trsFrustum
  );
  TGSPipelineTransformationStates = set of TGSPipelineTransformationState;

const
  cAllStatesChanged = [trsModelViewChanged, trsInvModelViewChanged, trsInvModelChanged, trsViewProjChanged, trsNormalModelChanged, trsFrustum];

type
  PGSTransformationRec = ^TGSTransformationRec;
  TGSTransformationRec = record
    FStates: TGSPipelineTransformationStates;
    FModelMatrix: TGSMatrix;
    FViewMatrix: TGSMatrix;
    FProjectionMatrix: TGSMatrix;
    FInvModelMatrix: TGSMatrix;
    FNormalModelMatrix: TAffineMatrix;
    FModelViewMatrix: TGSMatrix;
    FInvModelViewMatrix: TGSMatrix;
    FViewProjectionMatrix: TGSMatrix;
    FFrustum: TFrustum;
  end;

type
  TGSOnMatricesPush = procedure() of object;

  TgTransformation = class(TObject)
  private
    FStackPos: Integer;
    FStack: array of TGSTransformationRec;
    FLoadMatricesEnabled: Boolean;
    FOnPush: TGSOnMatricesPush;
    function GetModelMatrix: PGSMatrix; inline;
    function GetViewMatrix: PGSMatrix; inline;
    function GetProjectionMatrix: PGSMatrix; inline;
    function GetModelViewMatrix: PGSMatrix; inline;
    function GetInvModelViewMatrix: PGSMatrix; inline;
    function GetInvModelMatrix: PGSMatrix; inline;
    function GetNormalModelMatrix: PAffineMatrix; inline;
    function GetViewProjectionMatrix: PGSMatrix; inline;
    function GetFrustum: TFrustum; inline;
  protected
    procedure LoadModelViewMatrix; inline;
    procedure LoadProjectionMatrix; inline;
    procedure DoMatricesLoaded; inline;
    property OnPush: TGSOnMatricesPush read FOnPush write FOnPush;
  public
    constructor Create;
    procedure SetModelMatrix(const AMatrix: TGSMatrix); inline;
    procedure SetViewMatrix(const AMatrix: TGSMatrix); inline;
    procedure SetProjectionMatrix(const AMatrix: TGSMatrix); inline;
    procedure IdentityAll; inline;
    procedure Push(AValue: PGSTransformationRec); overload;
    procedure Push(); overload; inline;
    procedure Pop;
    procedure ReplaceFromStack;
    function StackTop: TGSTransformationRec; inline;
    property ModelMatrix: PGSMatrix read GetModelMatrix;
    property ViewMatrix: PGSMatrix read GetViewMatrix;
    property ProjectionMatrix: PGSMatrix read GetProjectionMatrix;
    property InvModelMatrix: PGSMatrix read GetInvModelMatrix;
    property ModelViewMatrix: PGSMatrix read GetModelViewMatrix;
    property NormalModelMatrix: PAffineMatrix read GetNormalModelMatrix;
    property InvModelViewMatrix: PGSMatrix read GetInvModelViewMatrix;
    property ViewProjectionMatrix: PGSMatrix read GetViewProjectionMatrix;
    property Frustum: TFrustum read GetFrustum;
    property LoadMatricesEnabled: Boolean read FLoadMatricesEnabled write FLoadMatricesEnabled;
  end;

implementation //============================================================

//---------------------------------------------------------------------------
constructor TGTransformation.Create;
begin
  FStackPos := 0;
  SetLength(FStack, MAX_MATRIX_STACK_DEPTH);
  IdentityAll;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.LoadProjectionMatrix;
begin
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(@FStack[FStackPos].FProjectionMatrix);
  glMatrixMode(GL_MODELVIEW);
end;

//---------------------------------------------------------------------------
function TGTransformation.GetModelViewMatrix: PGSMatrix;
begin
  if trsModelViewChanged in FStack[FStackPos].FStates then
  begin
    FStack[FStackPos].FModelViewMatrix :=
      MatrixMultiply(FStack[FStackPos].FModelMatrix, FStack[FStackPos].FViewMatrix);
    Exclude(FStack[FStackPos].FStates, trsModelViewChanged);
  end;
  Result := @FStack[FStackPos].FModelViewMatrix;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.LoadModelViewMatrix;
begin
  glLoadMatrixf(PGLFloat(GetModelViewMatrix));
end;

//---------------------------------------------------------------------------
procedure TGTransformation.IdentityAll;
begin
  with FStack[FStackPos] do
  begin
    FModelMatrix := IdentityHmgMatrix;
    FViewMatrix := IdentityHmgMatrix;
    FProjectionMatrix := IdentityHmgMatrix;
    FStates := cAllStatesChanged;
  end;
  if LoadMatricesEnabled then
  begin
    LoadModelViewMatrix;
    LoadProjectionMatrix;
  end;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.DoMatricesLoaded;
begin
  if Assigned(FOnPush) then
    FOnPush();
end;

//---------------------------------------------------------------------------
procedure TGTransformation.Push;
var
  prevPos: Integer;
begin
  prevPos := FStackPos;
  Inc(FStackPos);
  FStack[FStackPos] := FStack[prevPos];
end;

//---------------------------------------------------------------------------
procedure TGTransformation.Push(AValue: PGSTransformationRec);
var
  prevPos: Integer;
begin
  {$IFDEF USE_LOGGING}
  if FStackPos > MAX_MATRIX_STACK_DEPTH then
  begin
    GSLogger.LogWarningFmt('Transformation stack overflow, more then %d values',
      [MAX_MATRIX_STACK_DEPTH]);
  end;
  {$ENDIF}
  prevPos := FStackPos;
  Inc(FStackPos);

  if Assigned(AValue) then
  begin
    FStack[FStackPos] := AValue^;
    if LoadMatricesEnabled then
    begin
      LoadModelViewMatrix;
      LoadProjectionMatrix;
    end;
    DoMatricesLoaded;
  end
  else
    FStack[FStackPos] := FStack[prevPos];
end;

//---------------------------------------------------------------------------
procedure TGTransformation.Pop;
begin
  {$IFDEF USE_LOGGING}
  if FStackPos = 0 then
  begin
    GSLogger.LogError('Transformation stack underflow');
    exit;
  end;
  {$ENDIF}

  Dec(FStackPos);
  if LoadMatricesEnabled then
  begin
    LoadModelViewMatrix;
    LoadProjectionMatrix;
  end;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.ReplaceFromStack;
var
  prevPos: Integer;
begin
  {$IFDEF USE_LOGGING}
  if FStackPos = 0 then
  begin
    GSLogger.LogError('Transformation stack underflow');
    exit;
  end;
  {$ENDIF}
  prevPos := FStackPos - 1;
  FStack[FStackPos].FModelMatrix := FStack[prevPos].FModelMatrix;
  FStack[FStackPos].FViewMatrix:= FStack[prevPos].FViewMatrix;
  FStack[FStackPos].FProjectionMatrix:= FStack[prevPos].FProjectionMatrix;
  FStack[FStackPos].FStates := FStack[prevPos].FStates;
  if LoadMatricesEnabled then
  begin
    LoadModelViewMatrix;
    LoadProjectionMatrix;
  end;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetModelMatrix: PGSMatrix;
begin
  Result := @FStack[FStackPos].FModelMatrix;
end;

function TGTransformation.GetViewMatrix: PGSMatrix;
begin
  Result := @FStack[FStackPos].FViewMatrix;
end;

function TGTransformation.GetProjectionMatrix: PGSMatrix;
begin
  Result := @FStack[FStackPos].FProjectionMatrix;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.SetModelMatrix(const AMatrix: TGSMatrix);
begin
  FStack[FStackPos].FModelMatrix := AMatrix;
  FStack[FStackPos].FStates := FStack[FStackPos].FStates +
    [trsModelViewChanged, trsInvModelViewChanged, trsInvModelChanged, trsNormalModelChanged];
  if LoadMatricesEnabled then
    LoadModelViewMatrix;
end;

//---------------------------------------------------------------------------
procedure TGTransformation.SetViewMatrix(const AMatrix: TGSMatrix);
begin
  FStack[FStackPos].FViewMatrix:= AMatrix;
  FStack[FStackPos].FStates := FStack[FStackPos].FStates +
    [trsModelViewChanged, trsInvModelViewChanged, trsViewProjChanged, trsFrustum];
  if LoadMatricesEnabled then
    LoadModelViewMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.StackTop: TGSTransformationRec;
begin
  Result := FStack[FStackPos];
end;

//---------------------------------------------------------------------------
procedure TGTransformation.SetProjectionMatrix(const AMatrix: TGSMatrix);
begin
  FStack[FStackPos].FProjectionMatrix := AMatrix;
  FStack[FStackPos].FStates := FStack[FStackPos].FStates +
    [trsViewProjChanged, trsFrustum];
  if LoadMatricesEnabled then
    LoadProjectionMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetInvModelViewMatrix: PGSMatrix;
begin
  if trsInvModelViewChanged in FStack[FStackPos].FStates then
  begin
    FStack[FStackPos].FInvModelViewMatrix := GetModelViewMatrix^;
    InvertMatrix(FStack[FStackPos].FInvModelViewMatrix);
    Exclude(FStack[FStackPos].FStates, trsInvModelViewChanged);
  end;
  Result := @FStack[FStackPos].FInvModelViewMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetInvModelMatrix: PGSMatrix;
begin
  if trsInvModelChanged in FStack[FStackPos].FStates then
  begin
    FStack[FStackPos].FInvModelMatrix := MatrixInvert(FStack[FStackPos].FModelMatrix);
    Exclude(FStack[FStackPos].FStates, trsInvModelChanged);
  end;
  Result := @FStack[FStackPos].FInvModelMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetNormalModelMatrix: PAffineMatrix;
var
  M: TGSMatrix;
begin
  if trsNormalModelChanged in FStack[FStackPos].FStates then
  begin
    M := FStack[FStackPos].FModelMatrix;
    NormalizeMatrix(M);
    SetMatrix(FStack[FStackPos].FNormalModelMatrix, M);
    Exclude(FStack[FStackPos].FStates, trsNormalModelChanged);
  end;
  Result := @FStack[FStackPos].FNormalModelMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetViewProjectionMatrix: PGSMatrix;
begin
  if trsViewProjChanged in FStack[FStackPos].FStates then
  begin
    FStack[FStackPos].FViewProjectionMatrix :=
      MatrixMultiply(FStack[FStackPos].FViewMatrix, FStack[FStackPos].FProjectionMatrix);
    Exclude(FStack[FStackPos].FStates, trsViewProjChanged);
  end;
  Result := @FStack[FStackPos].FViewProjectionMatrix;
end;

//---------------------------------------------------------------------------
function TGTransformation.GetFrustum: TFrustum;
begin
  if trsFrustum in FStack[FStackPos].FStates then
  begin
    FStack[FStackPos].FFrustum := ExtractFrustumFromModelViewProjection(GetViewProjectionMatrix^);
    Exclude(FStack[FStackPos].FStates, trsFrustum);
  end;
  Result := FStack[FStackPos].FFrustum;
end;

//---------------------------------------------------------------------------

end.
