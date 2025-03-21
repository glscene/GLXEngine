//
// The graphics engine GLXEngine. The unit of GLScene for Delphi
//
unit GLS.TimeEventsMgr;

(*
  Time based events mannager using the Cadencer
  can be useful to make animations with GLScene
*)

interface

uses
  System.Classes,
  System.SysUtils,

  GLS.Cadencer,
  GLS.BaseClasses;

type
  TTimeEvent = class;
  TTimeEvents = class;

  TGLTimeEventsMGR = class(TGLUpdateAbleComponent)
  private
    FCadencer: TGLCadencer;
    FEnabled: boolean;
    FFreeEventOnEnd: boolean;
    FEvents: TTimeEvents;
  protected
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    procedure SetCadencer(const val: TGLCadencer);
    procedure SetEvents(const val: TTimeEvents);
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    procedure DoProgress(const progressTime: TGLProgressTimes); override;
    procedure Reset();
  published
    property Cadencer: TGLCadencer read FCadencer write SetCadencer;
    property Enabled: boolean read FEnabled write FEnabled default True;
    property FreeEventOnEnd: boolean read FFreeEventOnEnd write FFreeEventOnEnd
      default False;
    property Events: TTimeEvents read FEvents write SetEvents;
  end;

  TTimeEvents = class(TCollection)
  protected
    Owner: TComponent;
    function GetOwner: TPersistent; override;
    procedure SetItems(index: Integer; const val: TTimeEvent);
    function GetItems(index: Integer): TTimeEvent;
  public
    constructor Create(aOwner: TComponent);
    function Add: TTimeEvent;
    function FindItemID(ID: Integer): TTimeEvent;
    function EventByName(const name: String): TTimeEvent;
    property Items[index: Integer]: TTimeEvent read GetItems
      write SetItems; default;
  end;

  TTimeEventType = (etOneShot, etContinuous, etPeriodic);
  TTimeEventProc = procedure(event: TTimeEvent) of object;

  TTimeEvent = class(TCollectionItem)
  private
    FName: String;
    FStartTime, FEndTime, FElapsedTime: Double;
    FPeriod: Double;
    FEventType: TTimeEventType;
    FOnEvent: TTimeEventProc;
    FEnabled: boolean;
    FTickCount: Cardinal;
    procedure SetEnabled(const Value: boolean);
  protected
    function GetDisplayName: String; override;
    procedure SetName(const val: String);
    procedure DoEvent(const CurTime: Double);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    // Number of times the event was triggered since activation
    property TickCount: Cardinal read FTickCount;
    // Elapsed time since the event was activated
    property ElapsedTime: Double read FElapsedTime;
  published
    property Name: String read FName write SetName;
    property StartTime: Double read FStartTime write FStartTime;
    property EndTime: Double read FEndTime write FEndTime;
    property Period: Double read FPeriod write FPeriod;
    property EventType: TTimeEventType read FEventType write FEventType
      default etOneShot;
    property OnEvent: TTimeEventProc read FOnEvent write FOnEvent;
    property Enabled: boolean read FEnabled write SetEnabled default True;
  end;

// --------------------------------------------
implementation
// --------------------------------------------

// ------------------
// ------------------ TGLTimeEventsMGR ------------------
// ------------------

constructor TGLTimeEventsMGR.Create(aOwner: TComponent);
begin
  inherited;
  FEnabled := True;
  FFreeEventOnEnd := False;
  FEvents := TTimeEvents.Create(self);
end;

destructor TGLTimeEventsMGR.Destroy;
begin
  Cadencer := nil;
  FEvents.Free;
  inherited Destroy;
end;

procedure TGLTimeEventsMGR.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = Cadencer) then
    FCadencer := nil;
  inherited;
end;

procedure TGLTimeEventsMGR.SetCadencer(const val: TGLCadencer);
begin
  if FCadencer <> val then
  begin
    if Assigned(FCadencer) then
      FCadencer.UnSubscribe(self);
    FCadencer := val;
    if Assigned(FCadencer) then
      FCadencer.Subscribe(self);
  end;
end;

procedure TGLTimeEventsMGR.SetEvents(const val: TTimeEvents);
begin
  FEvents.Assign(val);
end;

procedure TGLTimeEventsMGR.DoProgress(const progressTime: TGLProgressTimes);
var
  i: Integer;
begin
  if not Enabled then
    Exit;

  i := 0;
  with progressTime do
    while i <= Events.Count - 1 do
      with Events.Items[i] do
      begin
        if Enabled and Assigned(FOnEvent) then
        begin
          case EventType of
            etOneShot:
              if (newTime >= StartTime) and (TickCount = 0) then
                DoEvent(newTime);
            etContinuous:
              if (newTime >= StartTime) and
                ((newTime <= EndTime) or (EndTime <= 0)) then
                DoEvent(newTime);
            etPeriodic:
              if (newTime >= StartTime + TickCount * Period) and
                ((newTime <= EndTime) or (EndTime <= 0)) then
                DoEvent(newTime);
          else
            Assert(False);
          end;
        end;
        if FreeEventOnEnd and
          (((EventType <> etOneShot) and (newTime > EndTime) and (EndTime >= 0))
          or ((EventType = etOneShot) and (TickCount > 0))) then
          Events[i].Free
        else
        begin
          // if we delete current event, the next will have same index
          // so increment only if we don't delete
          Inc(i);
        end;
      end;
end;

procedure TGLTimeEventsMGR.Reset;
var
  i: Integer;
begin
  if FEvents.Count <> 0 then
    for i := 0 to FEvents.Count - 1 do
      FEvents[i].FTickCount := 0;
end;


// ------------------
// ------------------ TTimeEvents ------------------
// ------------------

constructor TTimeEvents.Create(aOwner: TComponent);
begin
  Owner := aOwner;
  inherited Create(TTimeEvent);
end;

function TTimeEvents.GetOwner: TPersistent;
begin
  Result := Owner;
end;

procedure TTimeEvents.SetItems(index: Integer; const val: TTimeEvent);
begin
  inherited Items[index] := val;
end;

function TTimeEvents.GetItems(index: Integer): TTimeEvent;
begin
  Result := TTimeEvent(inherited Items[index]);
end;

function TTimeEvents.Add: TTimeEvent;
begin
  Result := (inherited Add) as TTimeEvent;
end;

function TTimeEvents.FindItemID(ID: Integer): TTimeEvent;
begin
  Result := (inherited FindItemID(ID)) as TTimeEvent;
end;

function TTimeEvents.EventByName(const name: String): TTimeEvent;
var
  i: Integer;
begin
  i := 0;
  while (i < Count) and (Items[i].FName <> name) do
    Inc(i);

  if i = Count then
    Result := nil
  else
    Result := Items[i];
end;

// ------------------
// ------------------ TTimeEvent ------------------
// ------------------

constructor TTimeEvent.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FEventType := etOneShot;
  FName := Format('Event%d', [index]);
  // give a default name different for each event
  FEnabled := True;
end;

destructor TTimeEvent.Destroy;
begin
  inherited Destroy;
end;

function TTimeEvent.GetDisplayName: String;
begin
  case EventType of
    etOneShot:
      Result := Name + Format(' (OneShot ST=%g)', [StartTime]);
    etContinuous:
      Result := Name + Format(' (Continuous ST=%g ET=%g)',
        [StartTime, EndTime]);
    etPeriodic:
      Result := Name + Format(' (Periodic ST=%g ET=%g P=%g)',
        [StartTime, EndTime, Period]);
  end;
end;

procedure TTimeEvent.SetName(const val: String);
var
  i: Integer;
  ok: boolean;
begin
  ok := True;
  with self.Collection as TTimeEvents do
  // we mustn't have 2 events with the same name (for EventByName)
    for i := 0 to Count - 1 do
      if Items[i].FName = val then
        ok := False;

  if ok and (val <> '') then
    FName := val;
end;

procedure TTimeEvent.DoEvent(const CurTime: Double);
begin
  if Assigned(FOnEvent) then
  begin
    FElapsedTime := CurTime - StartTime;
    FOnEvent(self);
  end;
  Inc(FTickCount);
end;

procedure TTimeEvent.SetEnabled(const Value: boolean);
begin
  FEnabled := Value;
  FStartTime := ((GetOwner as TTimeEvents).Owner as TGLTimeEventsMGR)
    .Cadencer.CurrentTime;
end;

end.
