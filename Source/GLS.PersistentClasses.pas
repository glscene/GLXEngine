//
// The graphics engine GLXEngine. The unit of GLScene for Delphi
//
unit GLS.PersistentClasses;
(*
   Base persistence classes.
   The registered class is:
     [TGLPersistentObjectList]

   These classes are used in GLScene but are designed for generic purpose.
   They implement a slightly different persistence mechanism then that of the VCL,
   allowing for object-level versioning (100% backward compatibility) and full
   polymorphic persistence.

   Internal Note: stripped down versions of XClasses & XLists.
*)
interface

uses
  System.Classes,
  System.SysUtils,
  Stage.Strings;

type

  PObject = ^TObject;

  //Virtual layer similar to VCL's TReader (but reusable)
  TGLVirtualReader = class
  private
    FStream: TStream;
  public
    constructor Create(Stream: TStream); virtual;
    property Stream: TStream read FStream;
    procedure ReadTypeError;
    procedure Read(var Buf; Count: Longint); virtual; abstract;
    function NextValue: TValueType; virtual; abstract;
    function ReadInteger: Integer; virtual; abstract;
    function ReadBoolean: Boolean; virtual; abstract;
    function ReadString: String; virtual; abstract;
    function ReadFloat: Extended; virtual; abstract;
    procedure ReadListBegin; virtual; abstract;
    procedure ReadListEnd; virtual; abstract;
    function EndOfList: Boolean; virtual; abstract;
    procedure ReadTStrings(aStrings: TStrings);
  end;

  //Virtual layer similar to VCL's TWriter (but reusable)
  TGLVirtualWriter = class
  private
    FStream: TStream;
  public
    constructor Create(Stream: TStream); virtual;
    property Stream: TStream read FStream;
    procedure Write(const Buf; Count: Longint); virtual; abstract;
    procedure WriteInteger(anInteger: Integer); virtual; abstract;
    procedure WriteBoolean(aBoolean: Boolean); virtual; abstract;
    procedure WriteString(const aString: string); virtual; abstract;
    procedure WriteFloat(const aFloat: Extended); virtual; abstract;
    procedure WriteListBegin; virtual; abstract;
    procedure WriteListEnd; virtual; abstract;
    procedure WriteTStrings(const aStrings: TStrings; storeObjects: Boolean = True);
  end;

  TGLVirtualReaderClass = class of TGLVirtualReader;
  TGLVirtualWriterClass = class of TGLVirtualWriter;

  (*Interface for persistent objects.
     This interface does not really allow polymorphic persistence,
     but is rather intended as a way to unify persistence calls for iterators *)
  IGLPersistentObject = interface(IInterface)
  ['{A9A0198A-F11B-4325-A92C-2F24DB41652B}']
    procedure WriteToFiler(writer: TGLVirtualWriter);
    procedure ReadFromFiler(reader: TGLVirtualReader);
  end;

  (* Base class for persistent objects.
     The base requirement is implementation of ReadFromFiler & WriteToFiler
     in sub-classes, the immediate benefits are support of streaming (to stream,
     file or string), assignment and cloning.
     The other requirement being the use of a virtual constructor, which allows
     polymorphic construction (don't forget to register your subclasses).
     Note that TGLPersistentObject implements IUnknown, but does *not* implement
     reference counting *)
  TGLPersistentObject = class(TPersistent, IGLPersistentObject)
  protected
    procedure RaiseFilerException(const archiveVersion: Integer);
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  public
    constructor Create; virtual;
    constructor CreateFromFiler(reader: TGLVirtualReader);
    destructor Destroy; override;
    procedure Assign(source: TPersistent); override;
    function CreateClone: TGLPersistentObject; dynamic;
    class function FileSignature: string; virtual;
    class function FileVirtualWriter: TGLVirtualWriterClass; virtual;
    class function FileVirtualReader: TGLVirtualReaderClass; virtual;
    procedure WriteToFiler(writer: TGLVirtualWriter); dynamic;
    procedure ReadFromFiler(reader: TGLVirtualReader); dynamic;
    procedure SaveToStream(stream: TStream; writerClass: TGLVirtualWriterClass = nil); dynamic;
    procedure LoadFromStream(stream: TStream; readerClass: TGLVirtualReaderClass = nil); dynamic;
    procedure SaveToFile(const fileName: string; writerClass: TGLVirtualWriterClass = nil); dynamic;
    procedure LoadFromFile(const fileName: string; readerClass: TGLVirtualReaderClass = nil); dynamic;
    function SaveToString(writerClass: TGLVirtualWriterClass = nil): string; dynamic;
    procedure LoadFromString(const data: string; readerClass: TGLVirtualReaderClass = nil); dynamic;
  end;

  TGLPersistentObjectClass = class of TGLPersistentObject;

  PGLPointerObjectList = ^TGLPointerObjectList;
  TGLPointerObjectList = array[0..MaxInt div (2*SizeOf(Pointer))] of TObject;

  TGLObjectListSortCompare = function(item1, item2: TObject): Integer;

  (*A persistent Object list.
    Similar to TList but works on TObject items and has facilities for
    persistence of contained data. Unlike the VCL's TObjectList, this one
    does NOT free its objects upon destruction or Clear, use Clean and CleanFree
    for that, and as such can be used for object referral lists too.
    But only TGLPersistentObject items will be streamed appropriately.
    The list can be used in a stack-like fashion with Push & Pop, and can
    perform basic boolean set operations.
    Note: the IndexOf implementation is up to 3 times faster than that of TList *)
  TGLPersistentObjectList = class(TGLPersistentObject)
  private
    FList: PGLPointerObjectList;
    FCount: Integer;
    FCapacity: Integer;
    FGrowthDelta: Integer;
  protected
    procedure Error; virtual;
    function Get(Index: Integer): TObject; inline;
    procedure Put(Index: Integer; Item: TObject);
    procedure SetCapacity(newCapacity: Integer); inline;
    procedure SetCount(NewCount: Integer); inline;
    function GetFirst: TObject; inline;
    procedure SetFirst(item: TObject);
    function GetLast: TObject;
    procedure SetLast(item: TObject);
    // Default event for ReadFromFiler
    procedure AfterObjectCreatedByReader(Sender: TObject); virtual;
    procedure DoClean;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure WriteToFiler(writer: TGLVirtualWriter); override;
    procedure ReadFromFiler(reader: TGLVirtualReader); override;
    procedure ReadFromFilerWithEvent(reader: TGLVirtualReader;
      afterSenderObjectCreated: TNotifyEvent);
    function Add(const item: TObject): Integer; inline;
    procedure AddNils(nbVals: Cardinal);
    procedure Delete(index: Integer);
    procedure DeleteItems(index: Integer; nbVals: Cardinal);
    procedure Exchange(Index1, Index2: Integer);
    procedure Insert(Index: Integer; Item: TObject);
    procedure InsertNils(index: Integer; nbVals: Cardinal);
    procedure Move(CurIndex, NewIndex: Integer);
    function Remove(Item: TObject): Integer;
    procedure DeleteAndFree(index: Integer);
    procedure DeleteAndFreeItems(index: Integer; nbVals: Cardinal);
    function RemoveAndFree(item: TObject): Integer;
    property GrowthDelta: integer read FGrowthDelta write FGrowthDelta;
    function Expand: TGLPersistentObjectList;
    property Items[Index: Integer]: TObject read Get write Put; default;
    property Count: Integer read FCount write SetCount;
    property List: PGLPointerObjectList read FList;
    property Capacity: Integer read FCapacity write SetCapacity;
    //Makes sure capacity is at least aCapacity.
    procedure RequiredCapacity(aCapacity: Integer);
    (*Removes all "nil" from the list.
     Note: Capacity is unchanged, no memory us freed, the list is just
     made shorter. This functions is orders of magnitude faster than
     its TList eponymous. *)
    procedure Pack;
    //Empty the list without freeing the objects.
    procedure Clear; virtual;
    //Empty the list and free the objects.
    procedure Clean; virtual;
    //Empty the list, free the objects and Free self.
    procedure CleanFree;
    function IndexOf(Item: TObject): Integer;
    property First: TObject read GetFirst write SetFirst;
    property Last: TObject read GetLast write SetLast;
    procedure Push(item: TObject);
    function Pop: TObject;
    procedure PopAndFree;
    function AddObjects(const objectList: TGLPersistentObjectList): Integer;
    procedure RemoveObjects(const objectList: TGLPersistentObjectList);
    procedure Sort(compareFunc: TGLObjectListSortCompare);
  end;

  //Wraps a TReader-compatible reader.
  TGLBinaryReader = class(TGLVirtualReader)
  protected
    function ReadValue: TValueType;
    function ReadWideString(vType: TValueType): WideString;
  public
    procedure Read(var Buf; Count: Longint); override;
    function NextValue: TValueType; override;
    function ReadInteger: Integer; override;
    function ReadBoolean: Boolean; override;
    function ReadString: string; override;
    function ReadFloat: Extended; override;
    procedure ReadListBegin; override;
    procedure ReadListEnd; override;
    function EndOfList: Boolean; override;
  end;

  //Wraps a TWriter-compatible writer.
  TGLBinaryWriter = class(TGLVirtualWriter)
  protected
    procedure WriteAnsiString(const aString: AnsiString); virtual;
    procedure WriteWideString(const aString: WideString); virtual;
  public
    procedure Write(const Buf; Count: Longint); override;
    procedure WriteInteger(anInteger: Integer); override;
    procedure WriteBoolean(aBoolean: Boolean); override;
    procedure WriteString(const aString: string); override;
    procedure WriteFloat(const aFloat: Extended); override;
    procedure WriteListBegin; override;
    procedure WriteListEnd; override;
  end;

  //Reads object persistence in Text format.
  TGLTextReader = class(TGLVirtualReader)
  private
    FValueType: string;
    FData: string;
  protected
    procedure ReadLine(const requestedType: string = '');
  public
    procedure Read(var Buf; Count: Longint); override;
    function NextValue: TValueType; override;
    function ReadInteger: Integer; override;
    function ReadBoolean: Boolean; override;
    function ReadString: string; override;
    function ReadFloat: Extended; override;
    procedure ReadListBegin; override;
    procedure ReadListEnd; override;
    function EndOfList: Boolean; override;
  end;

  //Writes object persistence in Text format.
  TGLTextWriter = class(TGLVirtualWriter)
  private
    FIndentLevel: Integer;
  protected
    procedure WriteLine(const valueType, data: string);
  public
    constructor Create(aStream: TStream); override;
    destructor Destroy; override;
    procedure Write(const Buf; Count: Longint); override;
    procedure WriteInteger(anInteger: Integer); override;
    procedure WriteBoolean(aBoolean: Boolean); override;
    procedure WriteString(const aString: string); override;
    procedure WriteFloat(const aFloat: Extended); override;
    procedure WriteListBegin; override;
    procedure WriteListEnd; override;
  end;

  //TPersistent which has knowledge of its owner.
  TGLOwnedPersistent = class(TPersistent)
  private
    FOwner: TPersistent;
  protected
    function GetOwner: TPersistent; override;
  public
    constructor Create(AOwner: TPersistent); virtual;
  end;

  //TPersistent that inplements IInterface.
  TGLInterfacedPersistent = class(TPersistent, IInterface)
  protected
    // Implementing IInterface.
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  end;

  //TCollectionItem thet inplements IInterface.
  TGLInterfacedCollectionItem = class(TCollectionItem, IInterface)
  protected
    // Implementing IInterface.
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  end;

  //Triggered when file signature does not match.
  EInvalidFileSignature = class(Exception)
  end;

  //Usually triggered when a filing error is detected.
  EFilerException = class(Exception)
  end;

procedure RaiseFilerException(aClass: TClass; archiveVersion: Integer);
function UTF8ToWideString(const s: AnsiString): WideString;

implementation // -----------------------------------------------------------

const
  cDefaultListGrowthDelta = 64;
  cVTInteger = 'Int';
  cVTFloat = 'Float';
  cVTString = 'Str';
  cVTBoolean = 'Bool';
  cVTRaw = 'Raw';
  cVTListBegin = '{';
  cVTListEnd = '}';

  cTrue = 'True';
  cFalse = 'False';

procedure RaiseFilerException(aClass: TClass; archiveVersion: Integer);
begin
  raise EFilerException.Create(aClass.ClassName +
    strUnknownArchiveVersion + IntToStr(archiveVersion));
end;

function UTF8ToWideString(const s: AnsiString): WideString;
const
  bytesFromUTF8: packed array[0..255] of Byte = (
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5);
  offsetsFromUTF8: array[0..5] of Cardinal = (
    $00000000, $00003080, $000E2080, $03C82080, $FA082080, $82082080);
  MaximumUCS2: Cardinal = $0000FFFF;
  MaximumUCS4: Cardinal = $7FFFFFFF;
  ReplacementCharacter: Cardinal = $0000FFFD;
  halfShift: Integer = 10;
  halfBase: Cardinal = $0010000;
  halfMask: Cardinal = $3FF;
  SurrogateHighStart: Cardinal = $D800;
  SurrogateLowStart: Cardinal = $DC00;
var
  sLength, L, J, T: Cardinal;
  ch: Cardinal;
  extraBytesToWrite: Word;
begin
  sLength := Length(s);
  if sLength = 0 then
  begin
    Result := '';
    Exit;
  end;
  SetLength(Result, sLength); // creates enough room
  L := 1;
  T := 1;
  while L <= Cardinal(sLength) do
  begin
    ch := 0;
    extraBytesToWrite := bytesFromUTF8[Ord(S[L])];
    for J := extraBytesToWrite downto 1 do
    begin
      ch := ch + Ord(S[L]);
      Inc(L);
      ch := ch shl 6;
    end;
    ch := ch + Ord(S[L]);
    Inc(L);
    ch := ch - offsetsFromUTF8[extraBytesToWrite];

    if ch <= MaximumUCS2 then
    begin
      Result[T] := WideChar(ch);
      Inc(T);
    end
    else if ch > MaximumUCS4 then
    begin
      Result[T] := WideChar(ReplacementCharacter);
      Inc(T);
    end
    else
    begin
      ch := ch - halfBase;
      Result[T] := WideChar((ch shr halfShift) + SurrogateHighStart);
      Inc(T);
      Result[T] := WideChar((ch and halfMask) + SurrogateLowStart);
      Inc(T);
    end;
  end;
  SetLength(Result, T - 1); // now fix up length
end;

// ------------------
// ------------------ TGLVirtualReader ------------------
// ------------------

constructor TGLVirtualReader.Create(Stream: TStream);
begin
  FStream := Stream;
end;

procedure TGLVirtualReader.ReadTypeError;
begin
  raise EReadError.CreateFmt('%s, read type error', [ClassName]);
end;

procedure TGLVirtualReader.ReadTStrings(aStrings: TStrings);
var
  i: Integer;
  objectsStored: Boolean;
begin
  aStrings.BeginUpdate;
  aStrings.Clear;
  objectsStored := ReadBoolean;
  i := ReadInteger;
  if objectsStored then
    while i > 0 do
    begin
      aStrings.AddObject(ReadString, TObject(ReadInteger));
      Dec(i);
    end
  else
    while i > 0 do
    begin
      aStrings.Add(ReadString);
      Dec(i);
    end;
  aStrings.EndUpdate;
end;

// ------------------
// ------------------ TGLVirtualWriter ------------------
// ------------------

constructor TGLVirtualWriter.Create(Stream: TStream);
begin
  FStream := Stream;
end;

procedure TGLVirtualWriter.WriteTStrings(const aStrings: TStrings;
  storeObjects: Boolean = True);
var
  i: Integer;
begin
  writeBoolean(storeObjects);
  if Assigned(aStrings) then
  begin
    WriteInteger(aStrings.Count);
    if storeObjects then
      for i := 0 to aStrings.Count - 1 do
      begin
        WriteString(aStrings[i]);
        WriteInteger(Integer(aStrings.Objects[i]));
      end
    else
      for i := 0 to aStrings.Count - 1 do
        WriteString(aStrings[i]);
  end
  else
    WriteInteger(0);
end;

// ------------------
// ------------------ TGLPersistentObject ------------------
// ------------------

constructor TGLPersistentObject.Create;
begin
  inherited Create;
end;

constructor TGLPersistentObject.CreateFromFiler(reader: TGLVirtualReader);
begin
  Create;
  ReadFromFiler(reader);
end;

destructor TGLPersistentObject.Destroy;
begin
  inherited Destroy;
end;

procedure TGLPersistentObject.Assign(source: TPersistent);
var
  ms: TStringStream; // faster than a TMemoryStream...
begin
  if source.ClassType = Self.ClassType then
  begin
    ms := TStringStream.Create('');
    try
      TGLPersistentObject(source).SaveToStream(ms);
      ms.Position := 0;
      LoadFromStream(ms);
    finally
      ms.Free;
    end;
  end
  else
    inherited;
end;

function TGLPersistentObject.CreateClone: TGLPersistentObject;
begin
  Result := TGLPersistentObjectClass(Self.ClassType).Create;
  Result.Assign(Self);
end;

class function TGLPersistentObject.FileSignature: string;
begin
  Result := '';
end;

class function TGLPersistentObject.FileVirtualWriter: TGLVirtualWriterClass;
begin
  Result := TGLBinaryWriter;
end;

class function TGLPersistentObject.FileVirtualReader: TGLVirtualReaderClass;
begin
  Result := TGLBinaryReader;
end;

procedure TGLPersistentObject.WriteToFiler(writer: TGLVirtualWriter);
begin
  // nothing
  Assert(Assigned(writer));
end;

procedure TGLPersistentObject.ReadFromFiler(reader: TGLVirtualReader);
begin
  // nothing
  Assert(Assigned(reader));
end;

procedure TGLPersistentObject.RaiseFilerException(const archiveVersion: Integer);
begin
  raise EFilerException.Create(ClassName + strUnknownArchiveVersion + IntToStr(archiveVersion)); //IGNORE
end;

function TGLPersistentObject.QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
begin
  if GetInterface(IID, Obj) then
    Result := S_OK
  else
    Result := E_NOINTERFACE;
end;

function TGLPersistentObject._AddRef: Integer; stdcall;
begin
  // ignore
  Result := 1;
end;

function TGLPersistentObject._Release: Integer; stdcall;
begin
  // ignore
  Result := 0;
end;

procedure TGLPersistentObject.SaveToStream(stream: TStream; writerClass: TGLVirtualWriterClass = nil);
var
  wr: TGLVirtualWriter;
  fileSig: AnsiString;
begin
  if writerClass = nil then
    writerClass := TGLBinaryWriter;
  wr := writerClass.Create(stream);
  try
    if FileSignature <> '' then
    begin
      fileSig := AnsiString(FileSignature);
      wr.Write(fileSig[1], Length(fileSig));
    end;
    WriteToFiler(wr);
  finally
    wr.Free;
  end;
end;

procedure TGLPersistentObject.LoadFromStream(stream: TStream; readerClass: TGLVirtualReaderClass = nil);
var
  rd: TGLVirtualReader;
  sig: AnsiString;
begin
  if readerClass = nil then
    readerClass := TGLBinaryReader;
  rd := readerClass.Create(stream);
  try
    if FileSignature <> '' then
    begin
      SetLength(sig, Length(FileSignature));
      rd.Read(sig[1], Length(FileSignature));
      if sig <> AnsiString(FileSignature) then
        raise EInvalidFileSignature.Create(strInvalidFileSignature);
    end;
    ReadFromFiler(rd);
  finally
    rd.Free;
  end;
end;

procedure TGLPersistentObject.SaveToFile(const fileName: string; writerClass: TGLVirtualWriterClass = nil);
var
  fs: TStream;
begin
  if writerClass = nil then
    writerClass := FileVirtualWriter;
  fs := TFileStream.Create(fileName, fmCreate);
  try
    SaveToStream(fs, writerClass);
  finally
    fs.Free;
  end;
end;

procedure TGLPersistentObject.LoadFromFile(const fileName: string; readerClass: TGLVirtualReaderClass = nil);
var
  fs: TStream;
begin
  if readerClass = nil then
    readerClass := FileVirtualReader;
  fs := TFileStream.Create(fileName, fmOpenRead + fmShareDenyWrite);
  try
    LoadFromStream(fs, readerClass);
  finally
    fs.Free;
  end;
end;

function TGLPersistentObject.SaveToString(writerClass: TGLVirtualWriterClass = nil): string;
var
  ss: TStringStream;
begin
  ss := TStringStream.Create('');
  try
    SaveToStream(ss, writerClass);
    Result := ss.DataString;
  finally
    ss.Free;
  end;
end;

procedure TGLPersistentObject.LoadFromString(const data: string; readerClass: TGLVirtualReaderClass = nil);
var
  ss: TStringStream;
begin
  ss := TStringStream.Create(data);
  try
    LoadFromStream(ss, readerClass);
  finally
    ss.Free;
  end;
end;

// ------------------
// ------------------ TGLPersistentObjectList ------------------
// ------------------

constructor TGLPersistentObjectList.Create;
begin
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

destructor TGLPersistentObjectList.Destroy;
begin
  Clear;
  inherited Destroy;
end;

function TGLPersistentObjectList.Add(const item: TObject): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

procedure TGLPersistentObjectList.AddNils(nbVals: Cardinal);
begin
  if Integer(nbVals) + Count > Capacity then
    SetCapacity(Integer(nbVals) + Count);
  FillChar(FList[FCount], Integer(nbVals) * SizeOf(TObject), 0);
  FCount := FCount + Integer(nbVals);
end;

function TGLPersistentObjectList.AddObjects(const objectList: TGLPersistentObjectList): Integer;
begin
  if Assigned(objectList) then
  begin
    Result := FCount;
    SetCount(Result + objectList.Count);
    System.Move(objectList.FList^[0], FList^[Result],
      objectList.FCount * SizeOf(TObject));
  end
  else
    Result := 0;
end;

procedure TGLPersistentObjectList.RemoveObjects(const objectList: TGLPersistentObjectList);
var
  i: Integer;
begin
  for i := 0 to objectList.Count - 1 do
    Remove(objectList[i]);
end;

procedure TGLPersistentObjectList.Clear;
begin
  if Assigned(Self) and Assigned(FList) then
  begin
    SetCount(0);
    SetCapacity(0);
  end;
end;

procedure TGLPersistentObjectList.Delete(index: Integer);
begin
{$IFOPT R+}
  if Cardinal(Index) >= Cardinal(FCount) then
    Error;
{$ENDIF}
  Dec(FCount);
  if index < FCount then
    System.Move(FList[index + 1], FList[index], (FCount - index) * SizeOf(TObject));
end;

procedure TGLPersistentObjectList.DeleteItems(index: Integer; nbVals: Cardinal);
begin
{$IFOPT R+}
  Assert(Cardinal(index) < Cardinal(FCount));
{$ENDIF}
  if nbVals > 0 then
  begin
    if index + Integer(nbVals) < FCount then
    begin
      System.Move(FList[index + Integer(nbVals)],
        FList[index],
        (FCount - index - Integer(nbVals)) * SizeOf(TObject));
    end;
    Dec(FCount, nbVals);
  end;
end;

procedure TGLPersistentObjectList.Exchange(index1, index2: Integer);
var
  item: TObject;
  locList: PGLPointerObjectList;
begin
{$IFOPT R+}
  if (Cardinal(Index1) >= Cardinal(FCount)) or
    (Cardinal(Index2) >= Cardinal(FCount)) then
    Error;
{$ENDIF}
  locList := FList;
  item := locList^[index1];
  locList^[index1] := locList^[index2];
  locList^[index2] := item;
end;

function TGLPersistentObjectList.Expand: TGLPersistentObjectList;
begin
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  Result := Self;
end;

function TGLPersistentObjectList.GetFirst: TObject;
begin
{$IFOPT R+}
  if Cardinal(FCount) = 0 then
    Error;
{$ENDIF}
  Result := FList^[0];
end;

procedure TGLPersistentObjectList.SetFirst(item: TObject);
begin
{$IFOPT R+}
  if Cardinal(FCount) = 0 then
    Error;
{$ENDIF}
  FList^[0] := item;
end;

procedure TGLPersistentObjectList.Error;
begin
  raise EListError.Create(strListIndexError);
end;

function TGLPersistentObjectList.Get(Index: Integer): TObject;
begin
{$IFOPT R+}
  if Cardinal(Index) >= Cardinal(FCount) then
    Error;
{$ENDIF}
  Result := FList^[Index];
end;

// IndexOf
//
function TGLPersistentObjectList.IndexOf(Item: TObject): Integer;
var
  I: Integer;
begin
  if FCount <= 0 then
    Result := -1
  else
  begin
    Result := -1;
    for I := 0 to FCount - 1 do
      if FList^[I] = Item then
      begin
        Result := I;
        Exit;
      end;
  end;
end;

procedure TGLPersistentObjectList.Insert(index: Integer; item: TObject);
begin
{$IFOPT R+}
  if Cardinal(index) > Cardinal(FCount) then
    Error;
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[index], FList[index + 1],
      (FCount - index) * SizeOf(TObject));
  FList^[index] := item;
  Inc(FCount);
end;

procedure TGLPersistentObjectList.InsertNils(index: Integer; nbVals: Cardinal);
var
  nc: Integer;
begin
{$IFOPT R+}
  Assert(Cardinal(Index) <= Cardinal(FCount));
{$ENDIF}
  if nbVals > 0 then
  begin
    nc := FCount + Integer(nbVals);
    if nc > FCapacity then
      SetCapacity(nc);
    if Index < FCount then
      System.Move(FList[Index], FList[Index + Integer(nbVals)],
        (FCount - Index) * SizeOf(TObject));
    FillChar(FList[Index], Integer(nbVals) * SizeOf(TObject), 0);
    FCount := nc;
  end;
end;

function TGLPersistentObjectList.GetLast: TObject;
begin
{$IFOPT R+}
  if Cardinal(FCount) = 0 then
    Error;
{$ENDIF}
  Result := FList^[FCount - 1];
end;

procedure TGLPersistentObjectList.SetLast(item: TObject);
begin
{$IFOPT R+}
  if Cardinal(FCount) = 0 then
    Error;
{$ENDIF}
  FList^[FCount - 1] := item;
end;

procedure TGLPersistentObjectList.Move(CurIndex, NewIndex: Integer);
var
  item: Pointer;
begin
  if curIndex <> newIndex then
  begin
{$IFOPT R+}
    if Cardinal(newIndex) >= Cardinal(Count) then
      Error;
    if Cardinal(curIndex) >= Cardinal(Count) then
      Error;
{$ENDIF}
    item := FList^[curIndex];
    if curIndex < newIndex then
    begin
      // curIndex+1 necessarily exists since curIndex<newIndex and newIndex<Count
      System.Move(List[curIndex + 1], List[curIndex], (NewIndex - CurIndex) * SizeOf(TObject));
    end
    else
    begin
      // newIndex+1 necessarily exists since newIndex<curIndex and curIndex<Count
      System.Move(List[newIndex], List[newIndex + 1], (CurIndex - NewIndex) * SizeOf(TObject));
    end;
    FList^[newIndex] := TObject(item);
  end;
end;

procedure TGLPersistentObjectList.Put(Index: Integer; Item: TObject);
begin
{$IFOPT R+}
  if Cardinal(Index) >= Cardinal(FCount) then
    Error;
{$ENDIF}
  FList^[Index] := Item;
end;

function TGLPersistentObjectList.Remove(item: TObject): Integer;
begin
  Result := IndexOf(item);
  if Result >= 0 then
    Delete(Result);
end;

procedure TGLPersistentObjectList.Pack;
var
  i, j, n: Integer;
  p: PGLPointerObjectList;
  pk: PObject;
begin
  p := List;
  n := Count - 1;
  while (n >= 0) and (p^[n] = nil) do
    Dec(n);
  for i := 0 to n do
  begin
    if p^[i] = nil then
    begin
      pk := @(p^[i]);
      for j := i + 1 to n do
      begin
        if p^[j] <> nil then
        begin
          pk^ := p^[j];
          Inc(pk);
        end;
      end;
      SetCount((Cardinal(pk) - Cardinal(p)) div SizeOf(TObject));
      Exit;
    end;
  end;
  SetCount(n + 1);
end;

procedure TGLPersistentObjectList.SetCapacity(newCapacity: Integer);
begin
  if newCapacity <> FCapacity then
  begin
    if newCapacity < FCount then
      FCount := newCapacity;
    ReallocMem(FList, newCapacity * SizeOf(TObject));
    FCapacity := newCapacity;
  end;
end;

procedure TGLPersistentObjectList.RequiredCapacity(aCapacity: Integer);
begin
  if FCapacity < aCapacity then
    SetCapacity(aCapacity);
end;

procedure TGLPersistentObjectList.SetCount(newCount: Integer);
begin
  if newCount > FCapacity then
    SetCapacity(newCount);
  if newCount > FCount then
    FillChar(FList[FCount], (newCount - FCount) * SizeOf(TObject), 0);
  FCount := NewCount;
end;

procedure TGLPersistentObjectList.DeleteAndFree(index: Integer);
var
  obj: TObject;
begin
  obj := Get(index);
  Delete(index);
  obj.Free;
end;

procedure TGLPersistentObjectList.DeleteAndFreeItems(index: Integer; nbVals: Cardinal);
var
  i, n: Integer;
begin
{$IFOPT R+}
  Assert(Cardinal(index) < Cardinal(FCount));
{$ENDIF}
  n := index + Integer(nbVals);
  if n >= FCount then
    n := FCount - 1;
  for i := index to n do
    FList^[i].Free;
  DeleteItems(index, nbVals);
end;

function TGLPersistentObjectList.RemoveAndFree(item: TObject): Integer;
begin
  Result := IndexOf(item);
  if Result >= 0 then
  begin
    Delete(Result);
    item.Free;
  end;
end;

procedure TGLPersistentObjectList.DoClean;
var
  i: Integer;
begin
  // a 'for' loop could crash if freeing an item removes other items form the list
  i := FCount - 1;
  while i >= 0 do
  begin
    if i < FCount then
      FList^[i].Free;
    Dec(i);
  end;
end;

procedure TGLPersistentObjectList.Clean;
begin
  DoClean;
  Clear;
end;

procedure TGLPersistentObjectList.CleanFree;
begin
  if Self <> nil then
  begin
    Clean;
    Destroy;
  end;
end;

procedure TGLPersistentObjectList.WriteToFiler(writer: TGLVirtualWriter);
(*
   Object List Filer Format :
      Integer (Version)
      ListBegin
         ...[Object]...[Object]...
      ListEnd
   with [Object] being either (read vertically)
      Boolean (unused)        String (ClassName)        Integer (reference)
      Integer                 Object Data               Object Data
*)
var
  i, objId: integer;
  objTypes: TList;
  aType: TClass;
begin
  objTypes := TList.Create;
  try
    with writer do
    begin
      WriteInteger(0); // Archive Version 0 (uh... not exactly... but...)
      WriteListBegin;
      for i := 0 to FCount - 1 do
      begin
        if FList^[i] = nil then
        begin
          // store nil as... nil
          WriteBoolean(False);
          WriteInteger(0);
        end
        else if (FList^[i] is TGLPersistentObject) then
        begin
          // yeah, a TGLPersistentObject
          aType := FList^[i].ClassType;
          objId := objTypes.IndexOf(aType);
          if objId < 0 then
          begin
            // class is unknown
            objTypes.Add(aType);
            WriteString(aType.ClassName);
          end
          else
          begin
            // class already registered
            WriteInteger(objId);
          end;
          TGLPersistentObject(FList^[i]).WriteToFiler(writer);
        end
        else
        begin
          // Dunno that stuff here, store as is
          WriteBoolean(False);
          WriteInteger(Integer(FList^[i]));
        end;
      end;
      WriteListEnd;
    end;
  finally
    objTypes.Free;
  end;
end;

procedure TGLPersistentObjectList.ReadFromFilerWithEvent(reader: TGLVirtualReader; afterSenderObjectCreated: TNotifyEvent);
var
  obj: TGLPersistentObject;
  m: TGLPersistentObjectClass;
  version: integer;
  objTypes: TList;
begin
  objTypes := TList.Create;
  try
    Clean;
    with reader do
    begin
      version := ReadInteger;
      if version = 0 then
      begin
        ReadListBegin;
        while not EndOfList do
          case Cardinal(NextValue) of
            Cardinal(vaFalse), Cardinal(vaTrue):
              begin
                // stored 'as was' value
                ReadBoolean; // ignored
                Add(TObject(Cardinal(ReadInteger)));
              end;
            Cardinal(vaString), Cardinal(vaLString), Cardinal(vaWString),
              Cardinal(vaInt64) + 1 { vaUTF8String }:
              begin
                // Unknown class, to be registered
                m := TGLPersistentObjectClass(FindClass(ReadString));
                objTypes.Add(m);
                obj := m.Create;
                if Assigned(afterSenderObjectCreated) then
                  afterSenderObjectCreated(obj);
                obj.ReadFromFiler(reader);
                Add(obj);
              end;
            Cardinal(vaInt8), Cardinal(vaInt16), Cardinal(vaInt32):
              begin
                // known class, direct retrieve
                m := TGLPersistentObjectClass(objTypes[ReadInteger]);
                obj := m.Create;
                if Assigned(afterSenderObjectCreated) then
                  afterSenderObjectCreated(obj);
                obj.ReadFromFiler(reader);
                Add(obj);
              end;
          else
            raise Exception.Create(strBrokenObjectListArchive);
          end;
        ReadListEnd;
      end
      else
        RaiseFilerException(version);
    end;
  finally
    objTypes.Free;
  end;
end;

procedure TGLPersistentObjectList.ReadFromFiler(reader: TGLVirtualReader);
begin
  ReadFromFilerWithEvent(reader, AfterObjectCreatedByReader);
end;

procedure TGLPersistentObjectList.AfterObjectCreatedByReader(Sender: TObject);
begin
  // nothing
end;

procedure TGLPersistentObjectList.Push(item: TObject);
begin
  Add(item);
end;

function TGLPersistentObjectList.Pop: TObject;
begin
  if FCount > 0 then
  begin
    Result := FList^[FCount - 1];
    Dec(FCount);
  end
  else
    Result := nil;
end;

procedure TGLPersistentObjectList.PopAndFree;
begin
  Pop.Free;
end;

procedure POListQuickSort(SortList: PGLPointerObjectList; L, R: Integer;
  compareFunc: TGLObjectListSortCompare);
var
  I, J: Integer;
  P, T: TObject;
begin
  repeat
    I := L;
    J := R;
    P := SortList^[(L + R) shr 1];
    repeat
      while compareFunc(SortList^[I], P) < 0 do
        Inc(I);
      while compareFunc(SortList^[J], P) > 0 do
        Dec(J);
      if I <= J then
      begin
        T := SortList^[I];
        SortList^[I] := SortList^[J];
        SortList^[J] := T;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then
      POListQuickSort(SortList, L, J, compareFunc);
    L := I;
  until I >= R;
end;

procedure TGLPersistentObjectList.Sort(compareFunc: TGLObjectListSortCompare);
begin
  if Count > 1 then
    POListQuickSort(FList, 0, Count - 1, compareFunc);
end;

// ------------------
// ------------------ TGLBinaryReader ------------------
// ------------------

procedure TGLBinaryReader.Read(var Buf; Count: Longint);
begin
  FStream.Read(Buf, Count);
end;

function TGLBinaryReader.ReadValue: TValueType;
var
  b: byte;
begin
  Read(b, 1);
  Result := TValueType(b);
end;

function TGLBinaryReader.NextValue: TValueType;
var
  pos: Int64;
begin
  pos := FStream.Position;
  Result := ReadValue;
  FStream.Position := pos;
end;

function TGLBinaryReader.ReadInteger: Integer;
var
  tempShort: ShortInt;
  tempSmallInt: SmallInt;
begin
  case ReadValue of
    vaInt8:
      begin
        Read(tempShort, 1);
        Result := tempShort;
      end;
    vaInt16:
      begin
        Read(tempSmallInt, 2);
        Result := tempSmallInt;
      end;
    vaInt32: Read(Result, 4);
  else
    Result := 0;
    ReadTypeError;
  end;
end;

function TGLBinaryReader.ReadBoolean: Boolean;
begin
  case ReadValue of
    vaTrue: Result := True;
    vaFalse: Result := False;
  else
    ReadTypeError;
    Result := False;
  end;
end;

function TGLBinaryReader.ReadString: string;
var
  n: Cardinal;
  vType: TValueType;
  tempString: AnsiString;
begin
  n := 0;
  vType := ReadValue;
  case Cardinal(vType) of
    Cardinal(vaWString),
      Cardinal(vaInt64) + 1:
      begin // vaUTF8String
        Result := ReadWideString(vType);
        Exit;
      end;
    Cardinal(vaString): Read(n, 1);
    Cardinal(vaLString): Read(n, 4);
  else
    ReadTypeError;
  end;
  SetLength(tempString, n);
  if n > 0 then
    Read(tempString[1], n);
  Result := string(tempString);
end;

function TGLBinaryReader.ReadWideString(vType: TValueType): WideString;
var
  n: Cardinal;
  utf8buf: AnsiString;
begin
  Read(n, 4);
  case Cardinal(vType) of
    Cardinal(vaWString):
      begin
        SetLength(Result, n);
        if n > 0 then
          Read(Result[1], n * 2);
      end;
    Cardinal(vaInt64) + 1:
      begin // vaUTF8String
        SetLength(utf8buf, n);
        if n > 0 then
        begin
          Read(utf8buf[1], n);
          Result := UTF8ToWideString(utf8buf);
        end;
      end;
  else
    ReadTypeError;
  end;
end;

function TGLBinaryReader.ReadFloat: Extended;
{$IFDEF WIN64}
var
   C: TExtended80Rec; // Temporary variable to store 10 bytes floating point number in a Win64 application
{$ENDIF}
begin
  Result := 0.0;
  {$IFDEF WIN64}
  if ReadValue = vaExtended then
  begin
    Read(C, SizeOf(C));     // Load value into the temp variable
    Result := Extended(C); // Typecast into an Extended: in a win64 application is a Double
  end
  else
    ReadTypeError;
  {$ELSE}
  if ReadValue = vaExtended then
    Read(Result, SizeOf(Result))
  else
    ReadTypeError;
  {$ENDIF}
end;

procedure TGLBinaryReader.ReadListBegin;
begin
  if ReadValue <> vaList then
    ReadTypeError;
end;

procedure TGLBinaryReader.ReadListEnd;
begin
  if ReadValue <> vaNull then
    ReadTypeError;
end;

function TGLBinaryReader.EndOfList: Boolean;
begin
  Result := (NextValue = vaNull);
end;

// ------------------
// ------------------ TGLBinaryWriter ------------------
// ------------------

procedure TGLBinaryWriter.Write(const Buf; Count: Longint);
begin
  FStream.Write(Buf, Count);
end;

procedure TGLBinaryWriter.WriteInteger(anInteger: Integer);
type
  TIntStruct = packed record
    typ: byte;
    val: Integer;
  end;
var
  ins: TIntStruct;
begin
  ins.val := anInteger;
  if (anInteger >= Low(ShortInt)) and (anInteger <= High(ShortInt)) then
  begin
    ins.typ := byte(vaInt8);
    Write(ins, 2);
  end
  else if (anInteger >= Low(SmallInt)) and (anInteger <= High(SmallInt)) then
  begin
    ins.typ := byte(vaInt16);
    Write(ins, 3);
  end
  else
  begin
    ins.typ := byte(vaInt32);
    Write(ins, 5);
  end;
end;

procedure TGLBinaryWriter.WriteBoolean(aBoolean: Boolean);
const
  cBoolToType: array[False..True] of byte = (byte(vaFalse), byte(vaTrue));
begin
  Write(cBoolToType[aBoolean], 1);
end;

procedure TGLBinaryWriter.WriteAnsiString(const aString: AnsiString);
type
  TStringHeader = packed record
    typ: Byte;
    length: Integer;
  end;
var
  sh: TStringHeader;
begin
  sh.Length := Length(aString);
  if sh.Length <= 255 then
  begin
    sh.typ := byte(vaString);
    Write(sh, 2);
    if sh.Length > 0 then
      Write(aString[1], sh.Length);
  end
  else
  begin
    sh.typ := byte(vaLString);
    Write(sh, 5);
    Write(aString[1], sh.Length);
  end;
end;

procedure TGLBinaryWriter.WriteWideString(const aString: WideString);
type
  TStringHeader = packed record
    typ: Byte;
    length: Integer;
  end;
var
  sh: TStringHeader;
begin
  sh.Length := Length(aString);
  sh.typ := byte(vaWString);
  Write(sh, 5);
  if sh.Length > 0 then
    Write(aString[1], sh.length * SizeOf(WideChar));
end;

procedure TGLBinaryWriter.WriteString(const aString: string);
begin
{$IFDEF UNICODE}
  // TODO: should really check if the string can be simplified to: vaString / vaLString / vaUTF8String
  WriteWideString(aString);
{$ELSE}
  WriteAnsiString(aString);
{$ENDIF}
end;

procedure TGLBinaryWriter.WriteFloat(const aFloat: Extended);
type
  TExtendedStruct = packed record
    typ: Byte;
    {$IFDEF WIN64}
    val  :TExtended80Rec;  // Structure to handle a 10 bytes floating point value
    {$ELSE}
    val  :Extended;
    {$ENDIF}
  end;
var
  str: TExtendedStruct;
begin
  {$IFDEF WIN64}
  str.typ := byte(vaExtended);
  str.val := TExtended80Rec(aFloat);   // Typecast the float value (in a Win64 app the type is a Double) into the 10 bytes struct
  Write(str, SizeOf(str));
  {$ELSE}
  str.typ := byte(vaExtended);
  str.val := aFloat;
  Write(str, SizeOf(str));
  {$ENDIF}
end;

procedure TGLBinaryWriter.WriteListBegin;
const
  buf: byte = byte(vaList);
begin
  Write(buf, 1);
end;

procedure TGLBinaryWriter.WriteListEnd;
const
  buf: byte = byte(vaNull);
begin
  Write(buf, 1);
end;

// ------------------
// ------------------ TGLTextReader ------------------
// ------------------

procedure TGLTextReader.ReadLine(const requestedType: string = '');
var
  line: string;
  c: Byte;
  p: Integer;
begin
  // will need speed upgrade, someday...
  line := '';
  repeat
    Stream.Read(c, 1);
    if c >= 32 then
      line := line + chr(c);
  until c = 10;
  line := Trim(line);
  p := Pos(' ', line);
  if p > 0 then
  begin
    FValueType := Copy(line, 1, p - 1);
    FData := Trim(Copy(line, p + 1, MaxInt));
  end
  else
  begin
    FValueType := line;
    FData := '';
  end;
  if requestedType <> '' then
    if requestedType <> FValueType then
      raise EFilerException.Create('Invalid type, expected "'
        + requestedType + '", found "FValueType".');
end;

procedure TGLTextReader.Read(var Buf; Count: Longint);

  function HexCharToInt(const c: Char): Integer;
  begin
    if c <= '9' then
      Result := Integer(c) - Integer('0')
    else if c < 'a' then
      Result := Integer(c) - Integer('A') + 10
    else
      Result := Integer(c) - Integer('a') + 10;
  end;

var
  i, j: Integer;
begin
  ReadLine(cVTRaw);
  j := 1;
  for i := 0 to Count - 1 do
  begin
    PAnsiChar(@Buf)[i] := AnsiChar((HexCharToInt(FData[j]) shl 4)
      + HexCharToInt(FData[j + 1]));
    Inc(j, 2);
  end;
end;

function TGLTextReader.NextValue: TValueType;
var
  p: Int64;
begin
  p := Stream.Position;
  ReadLine;
  if FValueType = cVTInteger then
    Result := vaInt32
  else if FValueType = cVTFloat then
    Result := vaExtended
  else if FValueType = cVTString then
    Result := vaString
  else if FValueType = cVTBoolean then
    if FData = cTrue then
      Result := vaTrue
    else
      Result := vaFalse
  else if FValueType = cVTRaw then
    Result := vaBinary
  else if FValueType = cVTListBegin then
    Result := vaList
  else
    Result := vaNULL;
  Stream.Position := p;
end;

function TGLTextReader.ReadInteger: Integer;
begin
  ReadLine(cVTInteger);
  Result := StrToInt(FData);
end;

function TGLTextReader.ReadBoolean: Boolean;
begin
  ReadLine(cVTBoolean);
  Result := (FData = cTrue);
end;

function TGLTextReader.ReadString: string;
var
  i: Integer;
begin
  ReadLine(cVTString);
  Result := '';
  i := 1;
  while i < Length(FData) do
  begin
    if FData[i] = '#' then
    begin
      Result := Result + Char(StrToInt(Copy(FData, i + 1, 3)));
      Inc(i, 3);
    end
    else
      Result := Result + FData[i];
    Inc(i);
  end;
  Assert(FData[i] = '.', 'Invalid stored string.');
end;

function TGLTextReader.ReadFloat: Extended;
var
  oldDc: Char;
begin
  ReadLine(cVTInteger);
  oldDc := FormatSettings.DecimalSeparator;
  FormatSettings.DecimalSeparator := '.';
  Result := StrToFloat(FData);
  FormatSettings.DecimalSeparator := oldDc;
end;

procedure TGLTextReader.ReadListBegin;
begin
  ReadLine(cVTListBegin);
end;

procedure TGLTextReader.ReadListEnd;
begin
  ReadLine(cVTListEnd);
end;

function TGLTextReader.EndOfList: Boolean;
var
  p: Int64;
begin
  p := Stream.Position;
  ReadLine;
  Result := (FValueType = cVTListEnd);
  Stream.Position := p;
end;

// ------------------
// ------------------ TGLTextWriter ------------------
// ------------------

constructor TGLTextWriter.Create(aStream: TStream);
begin
  inherited;
end;

destructor TGLTextWriter.Destroy;
begin
  inherited;
end;

procedure TGLTextWriter.WriteLine(const valueType, data: string);
var
  buf: AnsiString;
begin
  buf := StringOfChar(AnsiChar(#32), FIndentLevel);
  buf := buf + AnsiString(valueType + ' ' + data) + #13#10;
  Stream.Write(buf[1], Length(buf));
end;

procedure TGLTextWriter.Write(const Buf; Count: Longint);
const
  cNibbleToHex: PChar = '0123456789ABCDEF';
var
  i, j, b: Integer;
  data: string;
begin
  SetLength(data, Count * 2);
  j := 1;
  for i := 0 to Count - 1 do
  begin
    b := Integer(PAnsiChar(@buf)[i]);
    data[j] := cNibbleToHex[b shr 4];
    data[j + 1] := cNibbleToHex[b and 15];
    Inc(j, 2);
  end;
  WriteLine(cVTRaw, data);
end;

procedure TGLTextWriter.WriteInteger(anInteger: Integer);
begin
  WriteLine(cVTInteger, IntToStr(anInteger));
end;

procedure TGLTextWriter.WriteBoolean(aBoolean: Boolean);
begin
  if aBoolean then
    WriteLine(cVTBoolean, cTrue)
  else
    WriteLine(cVTBoolean, cFalse);
end;

procedure TGLTextWriter.WriteString(const aString: string);
var
  i: Integer;
  s: string;
begin
  s := '';
  for i := 1 to Length(aString) do
    if aString[i] >= #32 then
      s := s + aString[i]
    else
      s := s + Format('#%.3d', [Integer(aString[i])]);
  WriteLine(cVTString, s + '.');
end;

procedure TGLTextWriter.WriteFloat(const aFloat: Extended);
begin
  WriteLine(cVTInteger, FloatToStr(aFloat));
end;

procedure TGLTextWriter.WriteListBegin;
begin
  WriteLine(cVTListBegin, '');
  Inc(FIndentLevel, 3);
end;

procedure TGLTextWriter.WriteListEnd;
begin
  Dec(FIndentLevel, 3);
  WriteLine(cVTListEnd, '');
end;

// ------------------
// ------------------ TGLOwnedPersistent ------------------
// ------------------

constructor TGLOwnedPersistent.Create(AOwner: TPersistent);
begin
  FOwner := AOwner;
end;

function TGLOwnedPersistent.GetOwner: TPersistent;
begin
  Result := FOwner;
end;

// ------------------
// ------------------ TGLInterfacedPersistent ------------------
// ------------------

function TGLInterfacedPersistent._AddRef: Integer; stdcall;
begin
  Result := -1; //ignore
end;

function TGLInterfacedPersistent._Release: Integer; stdcall;
begin
  Result := -1; //ignore
end;

function TGLInterfacedPersistent.QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
begin
  if GetInterface(IID, Obj) then
    Result := S_OK
  else
    Result := E_NOINTERFACE;
end;

// ------------------
// ------------------ TGLInterfacedCollectionItem ------------------
// ------------------


function TGLInterfacedCollectionItem._AddRef: Integer; stdcall;
begin
  Result := -1; //ignore
end;

function TGLInterfacedCollectionItem._Release: Integer; stdcall;
begin
  Result := -1; //ignore
end;

function TGLInterfacedCollectionItem.QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
begin
  if GetInterface(IID, Obj) then
    Result := S_OK
  else
    Result := E_NOINTERFACE;
end;

initialization // -------------------------------------------------------------

	// class registrations
  RegisterClass(TGLPersistentObjectList);

end.
