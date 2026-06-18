(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit GLS.ArchiveManager;
(*
  Archive manager -  the class to work with archives
  RegisterClasses([TGLArchiveManager, TGSLibArchives]);
*)
interface

{$I Stage.Defines.inc}

uses
  System.Classes,
  System.SysUtils,

  GLS.ApplicationFileIO,
  Stage.PersistentClasses,
  Stage.Strings;

type
  TCompressionLevel = (clNone, clFastest, clDefault, clMax, clLevel1, clLevel2,
    clLevel3, clLevel4, clLevel5, clLevel6, clLevel7, clLevel8, clLevel9);

  // BaseArchive class
  TGSBaseArchive = class(TGSDataFile)
  protected
    FFileName: string;
    FContentList: TStrings;
    FCompressionLevel: TCompressionLevel;
    procedure SetCompressionLevel(aValue: TCompressionLevel); Virtual;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    property ContentList: TStrings read FContentList;
    property CompressionLevel: TCompressionLevel read FCompressionLevel
      write SetCompressionLevel default clNone;
    procedure Clear; virtual; abstract;
    function ContentExists(ContentName: string): boolean; virtual; abstract;
    function GetContent(Stream: TStream; index: integer): TStream; overload;
      virtual; abstract;
    function GetContent(ContentName: string): TStream; overload;
      virtual; abstract;
    function GetContent(index: integer): TStream; overload; virtual; abstract;
    function GetContentSize(index: integer): integer; overload;
      virtual; abstract;
    function GetContentSize(ContentName: string): integer; overload;
      virtual; abstract;
    procedure AddFromStream(ContentName, Path: string; FS: TStream);
      virtual; abstract;
    procedure AddFromFile(FileName, Path: string); virtual; abstract;
    procedure RemoveContent(index: integer); overload; virtual; abstract;
    procedure RemoveContent(ContentName: string); overload; virtual; abstract;
    procedure Extract(index: integer; NewName: string); overload;
      virtual; abstract;
    procedure Extract(ContentName, NewName: string); overload; virtual;
      abstract;
  end;

  TGSBaseArchiveClass = class of TGSBaseArchive;

  // Archive registration classes to use proper srchiver for extensions like:
  // GLFilePak, GLFileZLib etc.

  (* The type to record a registered class *)
  TGSArchiveFileFormat = class
  public
    BaseArchiveClass: TGSBaseArchiveClass;
    Extension: string;
    Description: string;
    DescResID: integer;
  end;

  // The list of registered classes
  TGSArchiveFileFormatsList = class(TGSPersistentObjectList)
  public
    destructor Destroy; override;
    procedure Add(const Ext, Desc: string; DescID: integer;
      AClass: TGSBaseArchiveClass);
    function FindExt(Ext: string): TGSBaseArchiveClass;
    function FindFromFileName(const FileName: string): TGSBaseArchiveClass;
    procedure Remove(AClass: TGSBaseArchiveClass);
  end;

  // Using the collection item for simultaneous work with several archives
  TGSLibArchive = class(TCollectionItem)
  private
    vArchive: TGSBaseArchive;
    ArcClass: TGSBaseArchiveClass;
    FFileName: string;
    FName: string;
    procedure SetCompressionLevel(aValue: TCompressionLevel);
    function GetCompressionLevel: TCompressionLevel;
    function GetContentList: TStrings;
    procedure SetName(const val: string);
  protected
    function GetDisplayName: string; override;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
    property CompressionLevel: TCompressionLevel read GetCompressionLevel
      write SetCompressionLevel default clDefault;
    procedure CreateArchive(FileName: string;
      OverwriteExistingFile: boolean = False);
    property ContentList: TStrings read GetContentList;
    procedure LoadFromFile(aFileName: string); overload;
    procedure LoadFromFile(aFileName, aAchiverType: string); overload;
    procedure Clear;
    function ContentExists(aContentName: string): boolean;
    property FileName: string read FFileName;
    function GetContent(aindex: integer): TStream; overload;
    function GetContent(aContentName: string): TStream; overload;
    function GetContentSize(aindex: integer): integer; overload;
    function GetContentSize(aContentName: string): integer; overload;
    procedure AddFromStream(aContentName, aPath: string; aF: TStream); overload;
    procedure AddFromStream(aContentName: string; aF: TStream); overload;
    procedure AddFromFile(aFileName, aPath: string); overload;
    procedure AddFromFile(aFileName: string); overload;
    procedure RemoveContent(aindex: integer); overload;
    procedure RemoveContent(aContentName: string); overload;
    procedure Extract(aindex: integer; aNewName: string); overload;
    procedure Extract(aContentName, aNewName: string); overload;
  published
    property Name: string read FName write SetName;
  end;

  TGSLibArchives = class(TOwnedCollection)
  protected
    procedure SetItems(index: integer; const val: TGSLibArchive);
    function GetItems(index: integer): TGSLibArchive;
  public
    constructor Create(AOwner: TComponent);
    function Owner: TPersistent;
    function IndexOf(const Item: TGSLibArchive): integer;
    function Add: TGSLibArchive;
    function FindItemID(ID: integer): TGSLibArchive;
    property Items[index: integer]: TGSLibArchive read GetItems
      write SetItems; default;
    // searching archiver by name
    function GetArchiveByFileName(const AName: string): TGSLibArchive;
    function GetFileNameOfArchive(aValue: TGSLibArchive): string;
    // searching needed item
    function MakeUniqueName(const nameRoot: string): string;
    function GetLibArchiveByName(const AName: string): TGSLibArchive;
    function GetNameOfLibArchive(const Archive: TGSLibArchive): string;
  end;

  // ArchiveManager class
  TGLArchiveManager = class(TComponent)
  private
    FArchives: TGSLibArchives;
    Procedure SetArchives(aValue: TGSLibArchives);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetArchiveByFileName(const AName: string): TGSLibArchive;
    function GetFileNameOfArchive(const aArchive: TGSLibArchive): string;
    function GetContent(aContentName: string): TStream;
    function ContentExists(aContentName: string): boolean;
    function OpenArchive(aFileName: string): TGSLibArchive; overload;
    function OpenArchive(aFileName, aAchiverType: string): TGSLibArchive;
      overload;
    procedure CloseArchive(aArchive: TGSLibArchive);
  published
    property Archives: TGSLibArchives read FArchives write SetArchives;
  end;

  EInvalidArchiveFile = class(Exception);

// getting a class of accessed archiver
function GetArchiveFileFormats: TGSArchiveFileFormatsList;
procedure RegisterArchiveFormat(const AExtension, ADescription: string;
  AClass: TGSBaseArchiveClass);
procedure UnregisterArchiveFormat(AClass: TGSBaseArchiveClass);

// Caution!!! Work for one archive manager only
function GetArchiveManager: TGLArchiveManager;

// GLS.ApplicationFileIO
// These functions are used to automate loading
// User enters LoadFromFile and through these functions gets the result

function ArcCreateFileStream(const FileName: string; mode: word): TStream;
function ArcFileStreamExists(const FileName: string): boolean;

implementation //============================================================

var
  vArchiveFileFormats: TGSArchiveFileFormatsList;
  vArchiveManager: TGLArchiveManager;

//---------------------------------------------------------------------------
function GetArchiveFileFormats: TGSArchiveFileFormatsList;
begin
  if not Assigned(vArchiveFileFormats) then
    vArchiveFileFormats := TGSArchiveFileFormatsList.Create;
  Result := vArchiveFileFormats;
end;

//---------------------------------------------------------------------------
procedure RegisterArchiveFormat(const AExtension, ADescription: string;
  AClass: TGSBaseArchiveClass);
begin
  RegisterClass(AClass);
  GetArchiveFileFormats.Add(AExtension, ADescription, 0, AClass);
end;

//---------------------------------------------------------------------------
procedure UnregisterArchiveFormat(AClass: TGSBaseArchiveClass);
begin
  if Assigned(vArchiveFileFormats) then
    vArchiveFileFormats.Remove(AClass);
end;

//---------------------------------------------------------------------------
function GetArchiveManager: TGLArchiveManager;
begin
  Result := vArchiveManager;
end;

//---------------------------------------------------------------------------
function ArcCreateFileStream(const FileName: string; mode: word): TStream;
begin
  If GetArchiveManager <> nil then
    with GetArchiveManager do
      if ContentExists(FileName) then
      begin
        Result := GetContent(FileName);
        Exit;
      end;
  if FileExists(FileName) then
  begin
    Result := TFileStream.Create(FileName, mode);
    Exit;
    // why create a file stream when a file is not found ???
    { end
      else begin
      Result := TFileStream.Create(FileName, fmCreate or fmShareDenyWrite);
      Exit; }
  end;
  Result := nil;
end;

//---------------------------------------------------------------------------
function ArcFileStreamExists(const FileName: string): boolean;
begin
  If GetArchiveManager <> nil then
    with GetArchiveManager do
      if ContentExists(FileName) then
      begin
        Result := True;
        Exit;
      end;
  Result := FileExists(FileName);
end;

//---------------------------------------------------------------------------
// TGSLibArchive
//---------------------------------------------------------------------------
constructor TGSLibArchive.Create(ACollection: TCollection);
begin
  inherited Create(ACollection);
  FName := TGSLibArchives(ACollection).MakeUniqueName('LibArchive');
end;

//---------------------------------------------------------------------------
destructor TGSLibArchive.Destroy;
begin
  Clear;
  inherited Destroy;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.SetCompressionLevel(aValue: TCompressionLevel);
begin
  if vArchive = nil then
    Exit;
  vArchive.CompressionLevel := aValue;
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetCompressionLevel: TCompressionLevel;
begin
  Result := clDefault;
  if vArchive = nil then
    Exit;
  Result := vArchive.CompressionLevel;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.CreateArchive(FileName: string;
  OverwriteExistingFile: boolean = False);
var
  fFile: TFileStream;
begin
  if OverwriteExistingFile or not FileExists(FileName) then
  begin
    fFile := TFileStream.Create(FileName, fmCreate);
    fFile.Free;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.LoadFromFile(aFileName: string);
var
  Ext: string;
begin
  Ext := LowerCase(ExtractFileExt(aFileName));
  Delete(Ext, 1, 1);
  LoadFromFile(aFileName, Ext);
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.LoadFromFile(aFileName, aAchiverType: string);
begin
  if not FileExists(aFileName) then
    Exit;
  ArcClass := GetArchiveFileFormats.FindExt(aAchiverType);
  If ArcClass = nil then
  begin
    raise Exception.Create(ClassName +
    ': Unable to find module archiver to expand ' + aAchiverType);
    Exit;
  end;
  vArchive := ArcClass.Create(nil);
  vArchive.LoadFromFile(aFileName);
  FFileName := aFileName;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.Clear;
begin
  if vArchive = nil then
    Exit;
  vArchive.Clear;
  vArchive.Free;
  ArcClass := nil;
  FFileName := '';
end;

//---------------------------------------------------------------------------
function TGSLibArchive.ContentExists(aContentName: string): boolean;
begin
  Result := False;
  if vArchive = nil then
    Exit;
  Result := vArchive.ContentExists(aContentName)
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetContent(aindex: integer): TStream;
begin
  Result := nil;
  if vArchive = nil then
    Exit;
  Result := vArchive.GetContent(aindex)
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetContent(aContentName: string): TStream;
begin
  Result := nil;
  if vArchive = nil then
    Exit;
  Result := vArchive.GetContent(aContentName)
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetContentSize(aindex: integer): integer;
begin
  Result := -1;
  if vArchive = nil then
    Exit;
  Result := vArchive.GetContentSize(aindex)
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetContentSize(aContentName: string): integer;
begin
  Result := -1;
  if vArchive = nil then
    Exit;
  Result := vArchive.GetContentSize(aContentName)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.AddFromStream(aContentName, aPath: string; aF: TStream);
begin
  if vArchive = nil then
    Exit;
  vArchive.AddFromStream(aContentName, aPath, aF)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.AddFromStream(aContentName: string; aF: TStream);
begin
  if vArchive = nil then
    Exit;
  vArchive.AddFromStream(aContentName, '', aF)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.AddFromFile(aFileName, aPath: string);
begin
  if vArchive = nil then
    Exit;
  vArchive.AddFromFile(aFileName, aPath)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.AddFromFile(aFileName: string);
begin
  if vArchive = nil then
    Exit;
  vArchive.AddFromFile(aFileName, '')
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.RemoveContent(aindex: integer);
begin
  if vArchive = nil then
    Exit;
  vArchive.RemoveContent(aindex)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.RemoveContent(aContentName: string);
begin
  if vArchive = nil then
    Exit;
  vArchive.RemoveContent(aContentName)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.Extract(aindex: integer; aNewName: string);
begin
  if vArchive = nil then
    Exit;
  vArchive.Extract(aindex, aNewName)
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.Extract(aContentName, aNewName: string);
begin
  if vArchive = nil then
    Exit;
  vArchive.Extract(aContentName, aNewName)
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetContentList: TStrings;
begin
  Result := nil;
  if vArchive = nil then
    Exit;
  Result := vArchive.ContentList;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchive.SetName(const val: string);
begin
  if val <> FName then
  begin
    if not(csLoading in TComponent(TGSLibArchives(Collection).GetOwner)
      .ComponentState) then
    begin
      if TGSLibArchives(Collection).GetLibArchiveByName(val) <> Self then
        FName := TGSLibArchives(Collection).MakeUniqueName(val)
      else
        FName := val;
    end
    else
      FName := val;
  end;
end;

//---------------------------------------------------------------------------
function TGSLibArchive.GetDisplayName: string;
begin
  Result := Name;
end;

//---------------------------------------------------------------------------
procedure TGSLibArchives.SetItems(index: integer; const val: TGSLibArchive);
begin
  GetItems(Index).Assign(val);
end;

//---------------------------------------------------------------------------
function TGSLibArchives.GetItems(index: integer): TGSLibArchive;
begin
  Result := TGSLibArchive(inherited GetItem(Index));
end;

//---------------------------------------------------------------------------
constructor TGSLibArchives.Create(AOwner: TComponent);
begin
  inherited Create(AOwner, TGSLibArchive);
end;

//---------------------------------------------------------------------------
function TGSLibArchives.Owner: TPersistent;
begin
  Result := GetOwner;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.IndexOf(const Item: TGSLibArchive): integer;
var
  I: integer;
begin
  Result := -1;
  if Count <> 0 then
    for I := 0 to Count - 1 do
      if GetItems(I) = Item then
      begin
        Result := I;
        Exit;
      end;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.Add: TGSLibArchive;
begin
  Result := (inherited Add) as TGSLibArchive;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.FindItemID(ID: integer): TGSLibArchive;
begin
  Result := (inherited FindItemID(ID)) as TGSLibArchive;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.GetArchiveByFileName(const AName: string): TGSLibArchive;
var
  I: integer;
  Arc: TGSLibArchive;
begin
  for I := 0 to Count - 1 do
  begin
    Arc := TGSLibArchive(inherited Items[I]);
    if Arc.FileName = AName then
    begin
      Result := Arc;
      Exit;
    end;
  end;
  Result := nil;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.GetFileNameOfArchive(aValue: TGSLibArchive): string;
var
  ArcIndex: integer;
begin
  ArcIndex := IndexOf(aValue);
  if ArcIndex <> -1 then
    Result := GetItems(ArcIndex).FileName
  else
    Result := '';
end;

//---------------------------------------------------------------------------
function TGSLibArchives.MakeUniqueName(const nameRoot: string): string;
var
  I: integer;
begin
  Result := nameRoot;
  I := 1;
  while GetLibArchiveByName(Result) <> nil do
  begin
    Result := nameRoot + IntToStr(I);
    Inc(I);
  end;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.GetLibArchiveByName(const AName: string): TGSLibArchive;
var
  I: integer;
  Arc: TGSLibArchive;
begin
  for I := 0 to Count - 1 do
  begin
    Arc := TGSLibArchive(inherited Items[I]);
    if (Arc.Name = AName) then
    begin
      Result := Arc;
      Exit;
    end;
  end;
  Result := nil;
end;

//---------------------------------------------------------------------------
function TGSLibArchives.GetNameOfLibArchive(const Archive: TGSLibArchive): string;
var
  MatIndex: integer;
begin
  MatIndex := IndexOf(Archive);
  if MatIndex <> -1 then
    Result := GetItems(MatIndex).Name
  else
    Result := '';
end;

//---------------------------------------------------------------------------
// TGSArchiveFileFormatsList
//---------------------------------------------------------------------------
destructor TGSArchiveFileFormatsList.Destroy;
begin
  Clean;
  inherited Destroy;
end;

//---------------------------------------------------------------------------
procedure TGSArchiveFileFormatsList.Add(const Ext, Desc: string;
  DescID: integer; AClass: TGSBaseArchiveClass);
var
  newRec: TGSArchiveFileFormat;
begin
  newRec := TGSArchiveFileFormat.Create;
  with newRec do
  begin
    Extension := AnsiLowerCase(Ext);
    BaseArchiveClass := AClass;
    Description := Desc;
    DescResID := DescID;
  end;
  inherited Add(newRec);
end;

//---------------------------------------------------------------------------
function TGSArchiveFileFormatsList.FindExt(Ext: string): TGSBaseArchiveClass;
var
  I: integer;
begin
  Ext := AnsiLowerCase(Ext);
  for I := Count - 1 downto 0 do
    with TGSArchiveFileFormat(Items[I]) do
    begin
      if Extension = Ext then
      begin
        Result := BaseArchiveClass;
        Exit;
      end;
    end;
  Result := nil;
end;

//---------------------------------------------------------------------------
function TGSArchiveFileFormatsList.FindFromFileName(const FileName: string)
  : TGSBaseArchiveClass;
var
  Ext: string;
begin
  Ext := ExtractFileExt(FileName);
  System.Delete(Ext, 1, 1);
  Result := FindExt(Ext);
  if not Assigned(Result) then
    raise EInvalidArchiveFile.CreateFmt(strUnknownExtension,
      [Ext, 'GLFile' + UpperCase(Ext)]);
end;

//---------------------------------------------------------------------------
procedure TGSArchiveFileFormatsList.Remove(AClass: TGSBaseArchiveClass);
var
  I: integer;
begin
  for I := Count - 1 downto 0 do
  begin
    if TGSArchiveFileFormat(Items[I]).BaseArchiveClass.InheritsFrom(AClass) then
      DeleteAndFree(I);
  end;
end;

//---------------------------------------------------------------------------
// TGSBaseArchive
//---------------------------------------------------------------------------
procedure TGSBaseArchive.SetCompressionLevel(aValue: TCompressionLevel);
begin
  if FCompressionLevel <> aValue then
    FCompressionLevel := aValue;
end;

//---------------------------------------------------------------------------
constructor TGSBaseArchive.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FContentList := TStringList.Create;
  FCompressionLevel := clDefault;
end;

//---------------------------------------------------------------------------
destructor TGSBaseArchive.Destroy;
begin
  FContentList.Free;
  inherited Destroy;
end;

//---------------------------------------------------------------------------
// TGLArchiveManager
//---------------------------------------------------------------------------
constructor TGLArchiveManager.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FArchives := TGSLibArchives.Create(Self);
  vArchiveManager := Self;
  vAFIOCreateFileStream := ArcCreateFileStream;
  vAFIOFileStreamExists := ArcFileStreamExists;
end;

//---------------------------------------------------------------------------
destructor TGLArchiveManager.Destroy;
begin
  vArchiveManager := nil;
  vAFIOCreateFileStream := nil;
  vAFIOFileStreamExists := nil;
  FArchives.Free;
  inherited Destroy;
end;

//---------------------------------------------------------------------------
procedure TGLArchiveManager.SetArchives(aValue: TGSLibArchives);
begin
  FArchives.Assign(aValue);
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.GetArchiveByFileName(const AName: string)
  : TGSLibArchive;
begin
  Result := FArchives.GetArchiveByFileName(AName);
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.GetFileNameOfArchive(const aArchive
  : TGSLibArchive): string;
begin
  Result := FArchives.GetFileNameOfArchive(aArchive)
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.GetContent(aContentName: string): TStream;
var
  I: integer;
begin
  Result := nil;
  With FArchives do
    for I := 0 to Count - 1 do
      if Items[I].ContentExists(aContentName) then
      begin
        Result := Items[I].GetContent(aContentName);
        Exit;
      end;
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.ContentExists(aContentName: string): boolean;
var
  I: integer;
begin
  Result := False;
  With FArchives do
    for I := 0 to Count - 1 do
      if Items[I].ContentExists(aContentName) then
      begin
        Result := Items[I].ContentExists(aContentName);
        Exit;
      end;
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.OpenArchive(aFileName: string): TGSLibArchive;
begin
  Result := FArchives.Add;
  Result.LoadFromFile(aFileName);
end;

//---------------------------------------------------------------------------
function TGLArchiveManager.OpenArchive(aFileName, aAchiverType: string)
  : TGSLibArchive;
begin
  Result := FArchives.Add;
  Result.LoadFromFile(aFileName, aAchiverType);
end;

//---------------------------------------------------------------------------
procedure TGLArchiveManager.CloseArchive(aArchive: TGSLibArchive);
begin
  FArchives.Delete(FArchives.IndexOf(aArchive));
end;

initialization //============================================================

RegisterClasses([TGLArchiveManager, TGSLibArchives]);

finalization //==============================================================

FreeAndNil(vArchiveFileFormats);

end.
