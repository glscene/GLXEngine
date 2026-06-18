(*****************************************************************************
                          GLStage Graphics Engine
******************************************************************************)
unit Stage.BaseClasses;
(*
  Base classes common to both GLScene & GXScene components
*)
interface

uses
  System.Classes,
  System.SysUtils,

  Stage.Strings,
  Stage.PersistentClasses;

type
  TGSProgressTimes = packed record
    DeltaTime, NewTime: Double;
    SqrDeltaTime, InvSqrDeltaTime: Single;
  end;

  (* Progression event for time-base animations/simulations.
     deltaTime is the time delta since last progress and newTime is the new
     time after the progress event is completed. *)
  TGSProgressEvent = procedure(Sender: TObject; const DeltaTime, NewTime: Double) of object;

  IGSNotifyAble = interface(IInterface)
    ['{00079A6C-D46E-4126-86EE-F9E2951B4593}']
    procedure NotifyChange(Sender: TObject);
  end;

  IGSProgessAble = interface(IInterface)
    ['{95E44548-B0FE-4607-98D0-CA51169AF8B5}']
    procedure DoProgress(const progressTime: TGSProgressTimes);
  end;

  // An abstract class describing the "update" interface.
  TGSUpdateAbleObject = class(TGSInterfacedPersistent, IGSNotifyAble)
  private
    FOwner: TPersistent;
    FUpdating: Integer;
    FOnNotifyChange: TNotifyEvent;
  protected
    function GetOwner: TPersistent; override; final;
  public
    constructor Create(AOwner: TPersistent); virtual;
    procedure NotifyChange(Sender: TObject); virtual;
    procedure Notification(Sender: TObject; Operation: TOperation); virtual;
    property Updating: Integer read FUpdating;
    procedure BeginUpdate; inline;
    procedure EndUpdate; inline;
    property Owner: TPersistent read FOwner;
    property OnNotifyChange: TNotifyEvent read FOnNotifyChange write FOnNotifyChange;
  end;

  // A base class describing the "cadenceing" interface.
  TGSCadenceAbleComponent = class(TComponent, IGSProgessAble)
  public
    procedure DoProgress(const progressTime: TGSProgressTimes); virtual;
  end;

  // A base class describing the "update" interface.
  TGSUpdateAbleComponent = class(TGSCadenceAbleComponent, IGSNotifyAble)
  public
    procedure NotifyChange(Sender: TObject); virtual;
  end;

  TGSNotifyCollection = class(TOwnedCollection)
  strict private
    FOnNotifyChange: TNotifyEvent;
  strict protected
    procedure Update(item: TCollectionItem); override;
  public
    constructor Create(AOwner: TPersistent; AItemClass: TCollectionItemClass);
    property OnNotifyChange: TNotifyEvent read FOnNotifyChange write FOnNotifyChange;
  end;

implementation //============================================================

constructor TGSUpdateAbleObject.Create(AOwner: TPersistent);
begin
  inherited Create;
  FOwner := AOwner;
end;

//---------------------------------------------------------------------------
procedure TGSUpdateAbleObject.NotifyChange(Sender: TObject);
begin
  if FUpdating = 0 then
  begin
    if Assigned(FOwner) then
    begin
      if FOwner is TGSUpdateAbleObject then
        TGSUpdateAbleObject(FOwner).NotifyChange(Self)
      else if FOwner is TGSUpdateAbleComponent then
        TGSUpdateAbleComponent(FOwner).NotifyChange(Self);
    end;
    if Assigned(FOnNotifyChange) then
      FOnNotifyChange(Self);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSUpdateAbleObject.Notification(Sender: TObject; Operation: TOperation);
begin
end;

//---------------------------------------------------------------------------
function TGSUpdateAbleObject.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

//---------------------------------------------------------------------------
procedure TGSUpdateAbleObject.BeginUpdate;
begin
  Inc(FUpdating);
end;

//---------------------------------------------------------------------------
procedure TGSUpdateAbleObject.EndUpdate;
begin
  Dec(FUpdating);
  if FUpdating <= 0 then
  begin
    Assert(FUpdating = 0);
    NotifyChange(Self);
  end;
end;

// ------------------
// ------------------ TGSCadenceAbleComponent ------------------
// ------------------
procedure TGSCadenceAbleComponent.DoProgress(const progressTime: TGSProgressTimes);
begin
  // nothing
end;

// ------------------
// ------------------ TGSUpdateAbleObject ------------------
// ------------------
procedure TGSUpdateAbleComponent.NotifyChange(Sender: TObject);
begin
  if Assigned(Owner) then
    if (Owner is TGSUpdateAbleComponent) then
      (Owner as TGSUpdateAbleComponent).NotifyChange(Self);
end;

// ------------------
// ------------------ TGSNotifyCollection ------------------
// ------------------
constructor TGSNotifyCollection.Create(AOwner: TPersistent; AItemClass: TCollectionItemClass);
begin
  inherited Create(AOwner, AItemClass);
  if Assigned(AOwner) and (AOwner is TGSUpdateAbleComponent) then
    FOnNotifyChange := TGSUpdateAbleComponent(AOwner).NotifyChange;
end;

//---------------------------------------------------------------------------
procedure TGSNotifyCollection.Update(Item: TCollectionItem);
begin
  inherited;
  if Assigned(FOnNotifyChange) then
    FOnNotifyChange(Self);
end;

//----------------------------------------------------------------------------
end.



