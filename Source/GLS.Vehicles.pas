//
// The graphics GaLaXy Engine. The unit of GLScene
//
unit GLS.Vehicles;
(*
  Implements Object Steerining Behaviours as in
  "Steering Behaviors For Autonomous Characters" by Craig Reynolds.
  Collision Code is based in GLS.Collision.
*)
interface

uses
  System.Types,
  System.Classes,
  System.Contnrs,
  System.SysUtils,
  System.Math,

  Stage.VectorGeometry,
  Stage.VectorTypes,
  Stage.Manager,
  Stage.Keyboard,

  GLS.Scene,
  GLS.Coordinates,
  GLS.Behaviours,
  GLS.Collision,
  GLS.Cadencer,
  GLS.VectorFileObjects,
  GLS.BaseClasses,
  GLS.XCollection;

type
  TGLSteerBehaviours = (sbhSeek, sbhFlee, sbhPursuit, sbhEvasion, sbhOffsetPursuit, sbhArrival,
    sbhObstacleAvoidance, sbhWander);
  TGLSteeringBehaviours = set of TGLSteerBehaviours;

  TGLBVehicle = class;
  TGLVehicleManager = class;

  TGLBaseSteerBehaviour = class;
  TGLSteerBehaviourClass = class of TGLBaseSteerBehaviour;

  // TGLBaseSteerBehaviour - Base Class for implementing Steering Behaviours
  TGLBaseSteerBehaviour = class(TComponent)
  private
    FVehicle: TGLBVehicle;
    FSteerRatio: Single;
  protected
    procedure SetVehicle(const AValue: TGLBVehicle); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; virtual; abstract;
    property Vehicle: TGLBVehicle read FVehicle write SetVehicle;
    property Ratio: Single read FSteerRatio write FSteerRatio;

  end;

  // TGLWanderSteer - Implementation of Wander Steering Behaviour
  TGLWanderSteer = class(TGLBaseSteerBehaviour)
  private
    FWanderModifier: TGLVector;
    FRate, FStrength: Double;
  protected
    procedure SetVehicle(const AValue: TGLBVehicle); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; override;
    property Rate: Double read FRate write FRate;
    property Strength: Double read FStrength write FStrength;
    property WanderModifier: TGLVector read FWanderModifier write FWanderModifier;
  end;

  // TGLSeekSteer - Implementation of Seek Steering Behaviour
  TGLSeekSteer = class(TGLBaseSteerBehaviour)
  private
    FTarget: TGLBaseSceneObject;
    FTurnRate: Single;
    procedure SetTarget(const Value: TGLBaseSceneObject);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; override;
    property Target: TGLBaseSceneObject read FTarget write SetTarget;
  end;

  // TGLFleeSteer
  TGLFleeSteer = class(TGLBaseSteerBehaviour)
  private
    FTarget: TGLBaseSceneObject;
    procedure SetTarget(const Value: TGLBaseSceneObject);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; override;
    property Target: TGLBaseSceneObject read FTarget write SetTarget;
  end;

  // TGLPursueSteer
  TGLPursueSteer = class(TGLBaseSteerBehaviour)
  private
    FTarget: TGLBaseSceneObject;
    procedure SetTarget(const Value: TGLBaseSceneObject);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; override;
    property Target: TGLBaseSceneObject read FTarget write SetTarget;
  end;

  // TGLWorldCollisionSteer
  TGLWorldCollisionSteer = class(TGLBaseSteerBehaviour)
  private
    FMap: TGLFreeForm;
    FCollided: Boolean;
    oldPosition, velocity: TGLVector;
    FTurnRate: Single;
    procedure SetMap(const Value: TGLFreeForm);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function SphereSweepAndSlide(freeform: TGLFreeForm; SphereStart: TGLVector;
      var velocity, newPosition: TGLVector; sphereRadius: Single): Boolean;
    procedure SetVehicle(const AValue: TGLBVehicle); override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ApplySteerForce; override;
    property Map: TGLFreeForm read FMap write SetMap;
    property Collided: Boolean read FCollided;
    property TurnRate: Single read FTurnRate write FTurnRate;
  end;

  // TGLBVehicle
  TGLBVehicle = class(TGLBehaviour)
  private
    FSteerUpdateInterval: Double;
    FMass: Integer;
    FSpeed, FMaxForce, FMaxSpeed: Double;
    FUp, FVelocity, FAccumulator: TGLCoordinates;
    FProgressTime: TGLProgressTimes;
    FAccumulatedTime: Double;
    FManager: TGLVehicleManager;
    FGroupIndex: Integer;
    FManagerName: String; // NOT persistent, temporarily used for persistence
    FSteerBehaviours: TObjectList;
    FGLSteeringBehaviours: TGLSteeringBehaviours;
    FSeekSteer: TGLSeekSteer;
    FWanderSteer: TGLWanderSteer;
    FPursueSteer: TGLPursueSteer;
    FFleeSteer: TGLFleeSteer;
    FWorldCollisionSteer: TGLWorldCollisionSteer;
    FCollisionObject: TGLBaseSceneObject;
  protected
    procedure SetGLSteeringBehaviours(const Value: TGLSteeringBehaviours);
    procedure SetManager(const Value: TGLVehicleManager);
    procedure SetGroupIndex(const Value: Integer);
    function GetVelocity: TGLCoordinates;
    procedure SetVelocity(const Value: TGLCoordinates);
    function GetSpeed: Double;
    procedure SetSpeed(const Value: Double);
    procedure WriteToFiler(writer: TWriter); override;
    procedure ReadFromFiler(reader: TReader); override;
    procedure Loaded; override;
  public
    constructor Create(AOwner: TXCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    class function FriendlyName: String; override;
    class function FriendlyDescription: String; override;
    procedure DoProgress(const progressTime: TGLProgressTimes); override;
    procedure DoSteering;
    property progressTime: TGLProgressTimes read FProgressTime write FProgressTime;
    property AccumulatedTime: Double read FAccumulatedTime write FAccumulatedTime;
    property CollisionObject: TGLBaseSceneObject read FCollisionObject write FCollisionObject;
    property Accumulator: TGLCoordinates read FAccumulator;
    property Flee: TGLFleeSteer read FFleeSteer write FFleeSteer;
    property Seek: TGLSeekSteer read FSeekSteer write FSeekSteer;
    property Pursue: TGLPursueSteer read FPursueSteer write FPursueSteer;
    property Wander: TGLWanderSteer read FWanderSteer write FWanderSteer;
    property WorldCollision: TGLWorldCollisionSteer read FWorldCollisionSteer
      write FWorldCollisionSteer;
  published
    property Manager: TGLVehicleManager read FManager write SetManager;
    property GroupIndex: Integer read FGroupIndex write SetGroupIndex;
    property Mass: Integer read FMass write FMass;
    // property Velocity: TGLCoordinates read GetVelocity write SetVelocity;
    property MaxForce: Double read FMaxForce write FMaxForce;
    property MaxSpeed: Double read FMaxSpeed write FMaxSpeed;
    property Speed: Double read GetSpeed write SetSpeed;
    property SteeringBehaviours: TGLSteeringBehaviours read FGLSteeringBehaviours
      write SetGLSteeringBehaviours;
    property SteerUpdateInterval: Double read FSteerUpdateInterval write FSteerUpdateInterval;
    property SteerBehaviours: TObjectList read FSteerBehaviours write FSteerBehaviours;
    property Up: TGLCoordinates read FUp write FUp;
  end;

  // Manager of Vehicles
  TGLVehicleManager = class(TComponent)
  private
    FSteerInterval: Double;
    FClients: TList;
    FCadencer: TGLCadencer;
    FWorldCollisionMap: TGLFreeForm;
    procedure SetCadencer(const Value: TGLCadencer);
    function GetCadencer: TGLCadencer;
    procedure SetSteerInterval(const Value: Double);
    procedure SetWorldCollisionMap(const Value: TGLFreeForm);
  protected
    procedure RegisterClient(aClient: TGLBVehicle);
    procedure DeRegisterClient(aClient: TGLBVehicle);
    procedure DeRegisterAllClients;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DoSteering;
    property Clients: TList read FClients;
  published
    property Cadencer: TGLCadencer read GetCadencer write SetCadencer;
    property SteerInterval: Double read FSteerInterval write SetSteerInterval;
    property WorldCollisionMap: TGLFreeForm read FWorldCollisionMap write SetWorldCollisionMap;
  end;

(* Returns or creates the TGLBVehicle within the given behaviours.
   This helper function is convenient way to access a TGLBVehicle. *)
function GetOrCreateVehicle(Behaviours: TGLBehaviours): TGLBVehicle; overload;
(* Returns or creates the TGLBVehicle within the given object's behaviours.
  This helper function is convenient way to access a TGLBVehicle. *)
function GetOrCreateVehicle(obj: TGLBaseSceneObject): TGLBVehicle; overload;

implementation //=============================================================

//----------------------------------------------------------------------------
// GetOrCreateVehicle (TGLBehaviours)
//----------------------------------------------------------------------------
function GetOrCreateVehicle(Behaviours: TGLBehaviours): TGLBVehicle;
var
  i: Integer;
begin
  i := Behaviours.IndexOfClass(TGLBVehicle);
  if i >= 0 then
    Result := TGLBVehicle(Behaviours[i])
  else
    Result := TGLBVehicle.Create(Behaviours);
end;

//----------------------------------------------------------------------------
// GetOrCreateVehicle (TGLBaseSceneObject)
//----------------------------------------------------------------------------
function GetOrCreateVehicle(obj: TGLBaseSceneObject): TGLBVehicle;
begin
  Result := GetOrCreateVehicle(obj.Behaviours);
end;

//----------------------------------------------------------------------------
(* TGLVehicleManager *)
// TGLVehicleManager.Create
//----------------------------------------------------------------------------
constructor TGLVehicleManager.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FClients := TList.Create;
  RegisterManager(Self);
  FSteerInterval := 0;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.Destroy
//----------------------------------------------------------------------------
destructor TGLVehicleManager.Destroy;
begin
  if Assigned(FCadencer) then
    FCadencer.RemoveFreeNotification(Self);
  FCadencer := nil;
  DeRegisterAllClients;
  DeRegisterManager(Self);
  FClients.Free;
  inherited Destroy;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.DeRegisterAllClients
//----------------------------------------------------------------------------
procedure TGLVehicleManager.DeRegisterAllClients;
var
  i: Integer;
begin
  // Fast deregistration
  for i := 0 to FClients.Count - 1 do
    TGLBVehicle(FClients[i]).FManager := nil;
  FClients.Clear;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.DeRegisterClient
//----------------------------------------------------------------------------
procedure TGLVehicleManager.DeRegisterClient(aClient: TGLBVehicle);
begin
  if Assigned(aClient) then
  begin
    aClient.FManager := nil;
    FClients.Remove(aClient);
  end;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.RegisterClient
//----------------------------------------------------------------------------
procedure TGLVehicleManager.RegisterClient(aClient: TGLBVehicle);
begin
  if Assigned(aClient) then
    if FClients.IndexOf(aClient) < 0 then
    begin
      FClients.Add(aClient);
      aClient.FManager := Self;
    end;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.DoSteering
//----------------------------------------------------------------------------
procedure TGLVehicleManager.DoSteering;
var
  i: Integer;
begin
  for i := 0 to FClients.Count - 1 do
    TGLBVehicle(FClients[i]).DoSteering;
end;

//----------------------------------------------------------------------------
(* TGLBVehicle *)
// TGLBVehicle.Create
//----------------------------------------------------------------------------
constructor TGLBVehicle.Create(AOwner: TXCollection);
begin
  inherited Create(AOwner);

  FSteerUpdateInterval := 0;
  FAccumulatedTime := 0;
  FMass := 10;
  FSpeed := 1;
  FMaxForce := 1;
  FMaxSpeed := 1;

  FUp := TGLCoordinates.CreateInitialized(Self, VectorMake(0, 1, 0), csVector);
  FVelocity := TGLCoordinates.CreateInitialized(Self, VectorMake(1, 0, 1), csVector);
  FVelocity.Normalize;

  FAccumulator := TGLCoordinates.CreateInitialized(Self, VectorMake(1, 0, 1), csVector);
  FSteerBehaviours := TObjectList.Create(True);
  FWanderSteer := TGLWanderSteer.Create(nil);
  FWanderSteer.Vehicle := Self;
  FSteerBehaviours.Add(FWanderSteer);

  FSeekSteer := TGLSeekSteer.Create(nil);
  FSeekSteer.Vehicle := Self;
  FSteerBehaviours.Add(FSeekSteer);

  FFleeSteer := TGLFleeSteer.Create(nil);
  FFleeSteer.Vehicle := Self;
  FSteerBehaviours.Add(FFleeSteer);

  FPursueSteer := TGLPursueSteer.Create(nil);
  FFleeSteer.Vehicle := Self;
  FSteerBehaviours.Add(FPursueSteer);

end;

//----------------------------------------------------------------------------
// TGLBVehicle.Destroy
//----------------------------------------------------------------------------
destructor TGLBVehicle.Destroy;
begin
  Manager := nil;
  FreeAndNil(FSteerBehaviours);
  FWanderSteer := nil;
  FSeekSteer := nil;
  FPursueSteer := nil;
  FWorldCollisionSteer := nil;
  FreeAndNil(FAccumulator);
  FreeAndNil(FUp);
  inherited Destroy;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.SetManager
//----------------------------------------------------------------------------
procedure TGLBVehicle.SetManager(const Value: TGLVehicleManager);
begin
  if Value <> FManager then
  begin
    if Assigned(FManager) then
      FManager.DeRegisterClient(Self);
    if Assigned(Value) then
    begin
      Value.RegisterClient(Self);
      Self.SteerUpdateInterval := Value.SteerInterval;

      FWorldCollisionSteer := TGLWorldCollisionSteer.Create(nil);
      FWorldCollisionSteer.Vehicle := Self;
      FWorldCollisionSteer.Map := Value.WorldCollisionMap;
      FSteerBehaviours.Add(FWorldCollisionSteer);
    end;
  end;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.SetGroupIndex
//----------------------------------------------------------------------------
procedure TGLBVehicle.SetGroupIndex(const Value: Integer);
begin
  FGroupIndex := Value;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.FriendlyName
//----------------------------------------------------------------------------
class function TGLBVehicle.FriendlyName: String;
begin
  Result := 'Steering';
end;

//----------------------------------------------------------------------------
class function TGLBVehicle.FriendlyDescription: String;
begin
  Result := 'Steering-behaviour registration';
end;

//----------------------------------------------------------------------------
// TGLBVehicle.Assign
//----------------------------------------------------------------------------
procedure TGLBVehicle.Assign(Source: TPersistent);
begin
  if Source is TGLBVehicle then
  begin
    Manager := TGLBVehicle(Source).Manager;
    Mass := TGLBVehicle(Source).Mass;
    Speed := TGLBVehicle(Source).Speed;
    MaxForce := TGLBVehicle(Source).MaxForce;
    MaxSpeed := TGLBVehicle(Source).MaxSpeed;
    GroupIndex := TGLBVehicle(Source).GroupIndex;
  end;
  inherited Assign(Source);
end;

//----------------------------------------------------------------------------
// TGLBVehicle.Loaded
//----------------------------------------------------------------------------
procedure TGLBVehicle.Loaded;
var
  mng: TComponent;
begin
  inherited;
  if FManagerName <> '' then
  begin
    mng := FindManager(TGLVehicleManager, FManagerName);
    if Assigned(mng) then
      Manager := TGLVehicleManager(mng);
    FManagerName := '';
  end;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.WriteToFiler
//----------------------------------------------------------------------------
procedure TGLBVehicle.WriteToFiler(writer: TWriter);
begin
  with writer do
  begin
    WriteInteger(1); // ArchiveVersion 1, added FGroupIndex
    if Assigned(FManager) then
      WriteString(FManager.GetNamePath)
    else
      WriteString('');
    WriteInteger(FGroupIndex);
    WriteInteger(FMass);
    WriteFloat(FSpeed);
    WriteFloat(FMaxForce);
    WriteFloat(FMaxSpeed);
    FVelocity.WriteToFiler(writer);
  end;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.ReadFromFiler
//----------------------------------------------------------------------------
procedure TGLBVehicle.ReadFromFiler(reader: TReader);
var
  archiveVersion: Integer;
begin
  with reader do
  begin
    archiveVersion := ReadInteger;
    Assert(archiveVersion in [0 .. 1]);
    FManagerName := ReadString;
    Manager := nil;
    if archiveVersion >= 1 then
      FGroupIndex := ReadInteger
    else
      FGroupIndex := 0;
    FMass := ReadInteger;
    FSpeed := ReadFloat;
    FMaxForce := ReadFloat;
    FMaxSpeed := ReadFloat;
    FVelocity.ReadFromFiler(reader);
  end;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.GetVelocity
//----------------------------------------------------------------------------
function TGLBVehicle.GetVelocity: TGLCoordinates;
begin
  Result := FVelocity;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.SetVelocity
//
procedure TGLBVehicle.SetVelocity(const Value: TGLCoordinates);
begin
  FVelocity := Value;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.GetSpeed
//----------------------------------------------------------------------------
function TGLBVehicle.GetSpeed: Double;
begin
  Result := FSpeed;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.SetSpeed
//----------------------------------------------------------------------------
procedure TGLBVehicle.SetSpeed(const Value: Double);
begin
  FSpeed := Value;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.DoSteering
//----------------------------------------------------------------------------
procedure TGLBVehicle.DoSteering;
var
  acceleration: Double;
  newLeft: TGLVector;
begin
  if AccumulatedTime < SteerUpdateInterval then
    exit;
  FAccumulator.SetVector(OwnerBaseSceneObject.Direction.AsVector);
  FAccumulator.Normalize;
  // FAccumulator.AsVector := NullHmgVector;
  // FAccumulator.Scale(Speed * AccumulatedTime);

  with OwnerBaseSceneObject do
  begin
    // Collision
    FWorldCollisionSteer.ApplySteerForce;
    if not FWorldCollisionSteer.Collided then
    begin
      FSeekSteer.ApplySteerForce;
      FWanderSteer.ApplySteerForce;
      FFleeSteer.ApplySteerForce;
    end
    else
    begin
      FWanderSteer.WanderModifier := OwnerBaseSceneObject.Direction.AsVector;
    end;
    Direction.AddScaledVector(AccumulatedTime, FAccumulator.AsVector);
    VectorCrossProduct(VectorNormalize(Direction.DirectVector), FUp.DirectVector, newLeft);
    Up.AsVector := VectorCrossProduct(VectorNormalize(Direction.DirectVector), newLeft);

    acceleration := 1 / Mass;
    Speed := Lerp(Speed, MaxSpeed, acceleration);

    Move(Speed * AccumulatedTime);

  end;
  AccumulatedTime := 0;
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.Notification
//----------------------------------------------------------------------------
procedure TGLVehicleManager.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = Cadencer) then
    Cadencer := nil
  else if (Operation = opRemove) and (AComponent = FWorldCollisionMap) then
  begin
    FWorldCollisionMap.RemoveFreeNotification(Self);
    FWorldCollisionMap := nil;
  end
  else
    inherited;
end;

//----------------------------------------------------------------------------
procedure TGLVehicleManager.SetCadencer(const Value: TGLCadencer);
begin
  if FCadencer = Value then
    exit;

  if Assigned(FCadencer) then
    FCadencer.RemoveFreeNotification(Self);

  FCadencer := Value;

  if FCadencer <> nil then
    FCadencer.FreeNotification(Self);
end;

function TGLVehicleManager.GetCadencer: TGLCadencer;
begin
  Result := FCadencer;
end;

//----------------------------------------------------------------------------
(* TGLBaseSteerBehaviour *)
//----------------------------------------------------------------------------
constructor TGLBaseSteerBehaviour.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FVehicle := nil;
  FSteerRatio := 1;
end;

//----------------------------------------------------------------------------
procedure TGLBaseSteerBehaviour.SetVehicle(const AValue: TGLBVehicle);
begin
  FVehicle := AValue;
end;

//----------------------------------------------------------------------------
(* TGLWanderSteer *)
//----------------------------------------------------------------------------
procedure TGLWanderSteer.ApplySteerForce;
var
  vWander: TGLVector;
  vStrength: TGLVector;
  vDesiredDirection: TGLVector;
const
  c2PI = 2 * pi;
begin
  with Vehicle do
  begin
    MakeVector(vWander, VectorAdd(VectorMake(cos(random * c2PI) * FRate,
      ClampValue(cos(random * c2PI) * FRate, -0.01 * FRate, 0.01 * FRate),
      cos(random * c2PI) * FRate), FWanderModifier));
    NormalizeVector(vWander);
    ScaleVector(vWander, 10);
    FWanderModifier := vWander;

    MakeVector(vStrength, OwnerBaseSceneObject.Direction.AsVector);
    NormalizeVector(vStrength);
    ScaleVector(vStrength, FStrength);
    VectorAdd(vStrength, vWander, vDesiredDirection);
    NormalizeVector(vDesiredDirection);
    VectorSubtract(vDesiredDirection, OwnerBaseSceneObject.Direction.AsVector, vDesiredDirection);
    // NormalizeVector(vDesiredDirection);

    FAccumulator.AddScaledVector(Ratio, vDesiredDirection);
  end;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.SetGLSteeringBehaviours
//----------------------------------------------------------------------------
procedure TGLBVehicle.SetGLSteeringBehaviours(const Value: TGLSteeringBehaviours);
begin
  FGLSteeringBehaviours := Value;

end;

//----------------------------------------------------------------------------
// TGLVehicleManager.SetSteerInterval
//----------------------------------------------------------------------------
procedure TGLVehicleManager.SetSteerInterval(const Value: Double);
var
  i: Integer;
begin
  FSteerInterval := Value;
  for i := 0 to FClients.Count - 1 do
    TGLBVehicle(FClients.Items[i]).SteerUpdateInterval := FSteerInterval;
end;

//----------------------------------------------------------------------------
// TGLBVehicle.DoProgress
//----------------------------------------------------------------------------
procedure TGLBVehicle.DoProgress(const progressTime: TGLProgressTimes);
begin
  FProgressTime := progressTime;
  AccumulatedTime := AccumulatedTime + progressTime.deltaTime;
end;

//----------------------------------------------------------------------------
constructor TGLWanderSteer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FRate := 1;
  FStrength := 1;
end;

//----------------------------------------------------------------------------
(* TGLSeekSteer *)
// TGLSeekSteer.ApplySteerForce
//----------------------------------------------------------------------------
procedure TGLSeekSteer.ApplySteerForce;
var
  vDesiredDirection: TGLVector;
  vDistance: TGLVector;
  lDistance: Single;
begin
  if Assigned(FTarget) then
    with FVehicle do
    begin
      vDesiredDirection := VectorNormalize(VectorSubtract(OwnerBaseSceneObject.Position.AsVector,
        FTarget.Position.AsVector));

      vDistance := VectorSubtract(OwnerBaseSceneObject.Direction.AsVector, vDesiredDirection);
      lDistance := VectorLength(vDistance);
      FAccumulator.AddScaledVector(10 * FTurnRate * lDistance * Ratio, VectorNormalize(vDistance));
    end;
end;

//----------------------------------------------------------------------------
// TGLSeekSteer.Create
//----------------------------------------------------------------------------
constructor TGLSeekSteer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FTurnRate := 0.3;
end;

//----------------------------------------------------------------------------
// TGLSeekSteer.Notification
//----------------------------------------------------------------------------
procedure TGLSeekSteer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FTarget) then
  begin
    AComponent.RemoveFreeNotification(Self);
    FTarget := nil;
  end
  else
    inherited;
end;

//----------------------------------------------------------------------------
// TGLSeekSteer.SetTarget
//----------------------------------------------------------------------------
procedure TGLSeekSteer.SetTarget(const Value: TGLBaseSceneObject);
begin
  if Assigned(FTarget) then
    FTarget.RemoveFreeNotification(Self);
  FTarget := Value;
  if Assigned(FTarget) then
    FTarget.FreeNotification(Self);
end;

//----------------------------------------------------------------------------
// TGLWanderSteer.SetVehicle
//----------------------------------------------------------------------------
procedure TGLWanderSteer.SetVehicle(const AValue: TGLBVehicle);
begin
  inherited SetVehicle(AValue);
  SetVector(FWanderModifier, Vehicle.OwnerBaseSceneObject.Direction.AsVector);
end;

//----------------------------------------------------------------------------
(* TGLFleeSteer *)
// TGLFleeSteer.ApplySteerForce
//----------------------------------------------------------------------------
procedure TGLFleeSteer.ApplySteerForce;
var
  vDesiredDirection: TGLVector;
begin
  if Assigned(FTarget) then
    with FVehicle do
    begin
      vDesiredDirection :=
        VectorNegate(VectorNormalize(VectorSubtract(OwnerBaseSceneObject.Position.AsVector,
        FTarget.Position.AsVector)));
      FAccumulator.AddScaledVector(0.3 * Speed * Ratio *
        VectorLength(VectorSubtract(OwnerBaseSceneObject.Direction.AsVector, vDesiredDirection)),
        VectorNormalize(VectorSubtract(OwnerBaseSceneObject.Direction.AsVector,
        vDesiredDirection)));
    end;
end;

//----------------------------------------------------------------------------
// TGLFleeSteer.Create
//----------------------------------------------------------------------------
constructor TGLFleeSteer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

//----------------------------------------------------------------------------
// TGLFleeSteer.Notification
//----------------------------------------------------------------------------
procedure TGLFleeSteer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FTarget) then
  begin
    AComponent.RemoveFreeNotification(Self);
    FTarget := nil;
  end
  else
    inherited;
end;

//----------------------------------------------------------------------------
// TGLFleeSteer.SetTarget
//----------------------------------------------------------------------------
procedure TGLFleeSteer.SetTarget(const Value: TGLBaseSceneObject);
begin
  if Assigned(FTarget) then
    FTarget.RemoveFreeNotification(Self);
  FTarget := Value;
  if Assigned(FTarget) then
    FTarget.FreeNotification(Self);
end;

//----------------------------------------------------------------------------
(* TGLPursueSteer *)
// TGLPursueSteer.ApplySteerForce
//----------------------------------------------------------------------------
procedure TGLPursueSteer.ApplySteerForce;
var
  vDesiredDirection: TGLVector;
  vDistance: TGLVector;
  lDistance: Single;
begin
  if Assigned(FTarget) then
    with FVehicle do
    begin
      vDesiredDirection := VectorNormalize(VectorSubtract(OwnerBaseSceneObject.Position.AsVector,
        FTarget.LocalToAbsolute(FTarget.FindChild('GLDummyCube2', True).Position.AsVector)));

      FTarget.FindChild('GLDummyCube2', True).Position.Z :=
        1 - 1 * VectorDotProduct(OwnerBaseSceneObject.Direction.AsVector,
        FTarget.Direction.AsVector) / VectorDistance(OwnerBaseSceneObject.Position.AsVector,
        FTarget.Position.AsVector);

      vDistance := VectorSubtract(OwnerBaseSceneObject.Direction.AsVector, vDesiredDirection);
      lDistance := VectorLength(vDistance);
      FAccumulator.AddScaledVector(Speed * Ratio * lDistance, VectorNormalize(vDistance));
      // Ratio := Ratio -  0.00005;
    end;
end;

//----------------------------------------------------------------------------
// TGLPursueSteer.Create
//----------------------------------------------------------------------------
constructor TGLPursueSteer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

//----------------------------------------------------------------------------
// TGLPursueSteer.Notification
//----------------------------------------------------------------------------
procedure TGLPursueSteer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FTarget) then
  begin
    AComponent.RemoveFreeNotification(Self);
    FTarget := nil;
  end
  else
    inherited;
end;

//----------------------------------------------------------------------------
// TGLPursueSteer.SetTarget
//----------------------------------------------------------------------------
procedure TGLPursueSteer.SetTarget(const Value: TGLBaseSceneObject);
begin
  if Assigned(FTarget) then
    FTarget.RemoveFreeNotification(Self);
  FTarget := Value;
  if Assigned(FTarget) then
    FTarget.FreeNotification(Self);
end;

//----------------------------------------------------------------------------
// TGLWorldCollisionSteer
//----------------------------------------------------------------------------
function TGLWorldCollisionSteer.SphereSweepAndSlide(freeform: TGLFreeForm; SphereStart: TGLVector;
  var velocity, newPosition: TGLVector; sphereRadius: Single): Boolean;
var
  oldPosition, ray: TGLVector;
  vel, slidedistance: Single;
  intPoint, intNormal: TGLVector;
  newDirection, newRay, collisionPosition, pointOnSphere, point2OnSphere: TGLVector;
  i: Integer;
  SphereRadiusRel: Single;
begin
  SphereRadiusRel := sphereRadius / freeform.Scale.x;
  oldPosition := SphereStart;
  Result := True;
  ray := VectorSubtract(newPosition, oldPosition);
  // ray := Velocity;
  // newPosition := VectorAdd(newPosition,ray);
  vel := VectorLength(ray);

  // loops
  if vel > 0 then
    for i := 0 to 6 do
    begin
      if (freeform.OctreeSphereSweepIntersect(oldPosition, ray, vel, SphereRadiusRel, @intPoint,
        @intNormal)) then
      begin
        if VectorDistance2(oldPosition, intPoint) <= sqr(sphereRadius) then
        begin
          intNormal := VectorScale(VectorSubtract(oldPosition, intPoint), 1.0001);
        end
        else
        begin
          // intNormal := VectorSubtract(oldPosition,intPoint);  //time steps.
          // intNormal := VectorScale(VectorNormalize(intNormal), SphereRadius + 0.0001);
          if RayCastSphereInterSect(intPoint, VectorNormalize(VectorNegate(ray)), oldPosition,
            sphereRadius, pointOnSphere, point2OnSphere) > 0 then
            intNormal := VectorScale(VectorSubtract(oldPosition, pointOnSphere), 1.0001)
            // intNormal := VectorScale(VectorNormalize(VectorSubtract(oldPosition, PointOnSphere)), SphereRadius + 0.001) //VectorDistance(oldPosition, PointOnSphere));
          else
          begin
            // Assert(False);  //debuging.
            intNormal := VectorScale(VectorSubtract(oldPosition, intPoint), 1.0001);
          end;

        end;

        // collision.
        collisionPosition := VectorAdd(intPoint, intNormal);
        oldPosition := collisionPosition;

        newRay := VectorSubtract(newPosition, collisionPosition);
        newDirection := VectorCrossProduct(intNormal, VectorCrossProduct(newRay, intNormal));
        if VectorNorm(newDirection) > 0 then
          NormalizeVector(newDirection);

        // collision plane with collision ray)
        slidedistance := VectorDotProduct(newRay, newDirection);
        // if abs(SlideDistance) < 10 * deltaTime then SlideDistance := 0;
        ScaleVector(newDirection, slidedistance);

        newPosition := VectorAdd(collisionPosition, newDirection);
        ray := newDirection;
        vel := VectorLength(ray);
        if i = 6 then
        begin
          newPosition := oldPosition;
          break;
        end;

        if vel < 1E-10 then
        begin
          newPosition := oldPosition;
          break;
        end;

      end
      else
      begin
        if i = 0 then
          Result := false;
        break;
      end;
    end; // loop
  velocity := ray;
end;

//----------------------------------------------------------------------------
// TGLWorldCollisionSteer.ApplySteerForce
//----------------------------------------------------------------------------
procedure TGLWorldCollisionSteer.ApplySteerForce;
var
  vDesiredDirection, vDistance, newPosition: TGLVector;
  lDistance: Single;
begin
  FCollided := false;
  if not Assigned(FMap) then
    exit;
  newPosition := FVehicle.OwnerBaseSceneObject.Position.AsVector;
  FCollided := SphereSweepAndSlide(FMap, oldPosition, velocity, newPosition,
    FVehicle.OwnerBaseSceneObject.boundingSphereRadius + 2.3);
  oldPosition := newPosition;
  if FCollided then
    with FVehicle do
    begin
      vDesiredDirection := VectorNormalize(VectorSubtract(OwnerBaseSceneObject.Position.AsVector,
        newPosition));
      vDistance := VectorSubtract(OwnerBaseSceneObject.Direction.AsVector, vDesiredDirection);
      lDistance := VectorLength(vDistance);
      // collision
      Speed := Speed * 0.9;
      FAccumulator.AddScaledVector(10 * FTurnRate * VectorLength(VectorSubtract(newPosition,
        FVehicle.OwnerBaseSceneObject.Position.AsVector)),
        VectorNormalize(VectorSubtract(newPosition,
        FVehicle.OwnerBaseSceneObject.Position.AsVector)));
    end;
  // if FCollided then begin
  // FVehicle.FAccumulator.AddScaledVector(4, VectorNormalize(VectorSubtract(newPosition, FVehicle.OwnerBaseSceneObject.Position.AsVector)));
  // FVehicle.Speed := FVehicle.Speed * 0.95;
  // end;
end;

//----------------------------------------------------------------------------
// TGLWorldCollisionSteer.Create
//----------------------------------------------------------------------------
constructor TGLWorldCollisionSteer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FMap := nil;
  velocity := NullHmgVector;
  FTurnRate := 0.3;
end;

//----------------------------------------------------------------------------
// TGLWorldCollisionSteer.Notification
//----------------------------------------------------------------------------
procedure TGLWorldCollisionSteer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FMap) then
  begin
    AComponent.RemoveFreeNotification(Self);
    FMap := nil;
  end
  else
    inherited;
end;

//----------------------------------------------------------------------------
// TGLWorldCollisionSteer.SetMap
//----------------------------------------------------------------------------
procedure TGLWorldCollisionSteer.SetMap(const Value: TGLFreeForm);
begin
  if Assigned(FMap) then
    FMap.RemoveFreeNotification(Self);

  FMap := Value;

  if Assigned(FMap) and (FMap <> nil) then
    FMap.FreeNotification(Self);
end;

//----------------------------------------------------------------------------
// TGLVehicleManager.SetWorldCollisionMap
//----------------------------------------------------------------------------
procedure TGLVehicleManager.SetWorldCollisionMap(const Value: TGLFreeForm);
begin
  if Assigned(FWorldCollisionMap) then
  begin
    FWorldCollisionMap.RemoveFreeNotification(Self);
    FWorldCollisionMap := nil;
  end;
  FWorldCollisionMap := Value;
  if FWorldCollisionMap <> nil then
    FWorldCollisionMap.FreeNotification(Self);
end;

//----------------------------------------------------------------------------
procedure TGLWorldCollisionSteer.SetVehicle(const AValue: TGLBVehicle);
begin
  inherited;
  oldPosition := FVehicle.OwnerBaseSceneObject.Position.AsVector;
end;

initialization //=============================================================

RegisterXCollectionItemClass(TGLBVehicle);

end.
