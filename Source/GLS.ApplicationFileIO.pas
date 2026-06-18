(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit GLS.ApplicationFileIO;
(*
  Components and functions that abstract file I/O access for an application.
  Allows re-routing file reads to reads from a single archive file f.i.
*)
interface

{$I Stage.Defines.inc}

uses
  Winapi.Windows,
  System.Classes,
  System.SysUtils,

  Stage.BaseClasses,
  Stage.Strings,
  Stage.Logger;

const
  GLS_RC_DDS_Type = RT_RCDATA;
  GLS_RC_JPG_Type = RT_RCDATA;
  GLS_RC_XML_Type = RT_RCDATA;
  GLS_RC_String_Type = RT_RCDATA;

type
  TGSApplicationResource = (aresNone, aresSplash, aresTexture, aresMaterial,
    aresSampler, aresFont, aresMesh);

  TGSAFIOCreateFileStream = function(const fileName: string; mode: Word): TStream;
  TGSAFIOFileStreamExists = function(const fileName: string): Boolean;
  TGSAFIOFileStreamEvent = procedure(const fileName: String; mode: Word;
    var Stream: TStream) of object;
  TGSAFIOFileStreamExistsEvent = function(const fileName: string)
    : Boolean of object;

  (* Allows specifying a custom behaviour for CreateFileStream.
    The component should be considered a helper only, you can directly specify
    a function via the vAFIOCreateFileStream variable.
    If multiple ApplicationFileIO components exist in the application,
    the last one created will be the active one. *)
  TGLApplicationFileIO = class(TComponent)
  private
    FOnFileStream: TGSAFIOFileStreamEvent;
    FOnFileStreamExists: TGSAFIOFileStreamExistsEvent;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    (* Event that allows you to specify a stream for the file.
      Destruction of the stream is at the discretion of the code that
      invoked CreateFileStream. Return nil to let the default mechanism
      take place (ie. attempt a regular file system access). *)
    property OnFileStream: TGSAFIOFileStreamEvent read FOnFileStream
      write FOnFileStream;
    // Event that allows you to specify if a stream for the file exists.
    property OnFileStreamExists: TGSAFIOFileStreamExistsEvent
      read FOnFileStreamExists write FOnFileStreamExists;
  end;

  TGSDataFileCapability = (dfcRead, dfcWrite);
  TGSDataFileCapabilities = set of TGSDataFileCapability;

  (* Abstract base class for data file formats interfaces.
    This class declares base file-related behaviours, ie. ability to load/save
    from a file or a stream.
    It is highly recommended to overload ONLY the stream based methods, as the
    file-based one just call these, and stream-based behaviours allow for more
    enhancement (such as other I/O abilities, compression, cacheing, etc.)
    to this class, without the need to rewrite subclasses. *)
  TGSDataFile = class(TGSUpdateAbleObject)
  private
    FResourceName: string;
    procedure SetResourceName(const AName: string);
  public
    // Describes what the TGSDataFile is capable of. Default value is [dfcRead].
    class function Capabilities: TGSDataFileCapabilities; virtual;
    // Duplicates Self and returns a copy. Subclasses should override this method to duplicate their data.
    function CreateCopy(AOwner: TPersistent): TGSDataFile; virtual;
    procedure LoadFromFile(const fileName: string); virtual;
    procedure SaveToFile(const fileName: string); virtual;
    procedure LoadFromStream(Stream: TStream); virtual;
    procedure SaveToStream(Stream: TStream); virtual;
    procedure Initialize; virtual;
    (* Optionnal resource name.
      When using LoadFromFile/SaveToFile, the filename is placed in it,
      when using the Stream variants, the caller may place the resource
      name in it for parser use. *)
    property ResourceName: string read FResourceName write SetResourceName;
  end;

  TGSDataFileClass = class of TGSDataFile;
  TGSResourceStream = TResourceStream;

// Returns true if an ApplicationFileIO has been defined
function ApplicationFileIODefined: Boolean;
// Queries is a file stream corresponding to the fileName exists.
function FileStreamExists(const fileName: string): Boolean;
function CreateResourceStream(const ResName: string; ResType: PChar)
  : TGSResourceStream;
function StrToGLSResType(const AStrRes: string): TGSApplicationResource;

var
  vAFIOCreateFileStream: TGSAFIOCreateFileStream = nil;
  vAFIOFileStreamExists: TGSAFIOFileStreamExists = nil;

implementation //============================================================

var
  vAFIO: TGLApplicationFileIO = nil;

//---------------------------------------------------------------------------
function ApplicationFileIODefined: Boolean;
begin
  Result := (Assigned(vAFIOCreateFileStream) and Assigned(vAFIOFileStreamExists)
    ) or Assigned(vAFIO);
end;

//---------------------------------------------------------------------------
function FileStreamExists(const fileName: string): Boolean;
begin
  if Assigned(vAFIOFileStreamExists) then
    Result := vAFIOFileStreamExists(fileName)
  else
  begin
    if Assigned(vAFIO) and Assigned(vAFIO.FOnFileStreamExists) then
      Result := vAFIO.FOnFileStreamExists(fileName)
    else
      Result := FileExists(fileName);
  end;
end;

//---------------------------------------------------------------------------
function CreateResourceStream(const ResName: string; ResType: PChar)
  : TGSResourceStream;
var
  InfoBlock: HRSRC;
begin
  Result := nil;
  InfoBlock := FindResource(HInstance, PChar(ResName), ResType);
  if InfoBlock <> 0 then
    Result := TResourceStream.Create(HInstance, ResName, ResType)
  else
    GSLogger.LogError
      (Format('Can''t create stream of application resource "%s"', [ResName]));
end;

// ------------------
// ------------------ TGLApplicationFileIO ------------------
// ------------------
constructor TGLApplicationFileIO.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  vAFIO := Self;
end;

//---------------------------------------------------------------------------
destructor TGLApplicationFileIO.Destroy;
begin
  vAFIO := nil;
  inherited Destroy;
end;

// ------------------
// ------------------ TGSDataFile ------------------
// ------------------
class function TGSDataFile.Capabilities: TGSDataFileCapabilities;
begin
  Result := [dfcRead];
end;

//---------------------------------------------------------------------------
function TGSDataFile.CreateCopy(AOwner: TPersistent): TGSDataFile;
begin
  if Self <> nil then
    Result := TGSDataFileClass(Self.ClassType).Create(AOwner)
  else
    Result := nil;
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.LoadFromFile(const fileName: string);
var
  fs: TStream;
begin
  ResourceName := ExtractFileName(fileName);
  fs := TFileStream.Create(fileName, fmOpenRead + fmShareDenyNone);
  try
    LoadFromStream(fs);
  finally
    fs.Free;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.SaveToFile(const fileName: string);
var
  fs: TStream;
begin
  ResourceName := ExtractFileName(fileName);
  fs := TFileStream.Create(fileName, fmCreate);
  try
    SaveToStream(fs);
  finally
    fs.Free;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.LoadFromStream(Stream: TStream);
begin
  Assert(False, 'Import for ' + ClassName + ' to ' + Stream.ClassName +
    ' not available.');
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.SaveToStream(Stream: TStream);
begin
  Assert(False, 'Export for ' + ClassName + ' to ' + Stream.ClassName +
    ' not available.');
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.Initialize;
begin
end;

//---------------------------------------------------------------------------
procedure TGSDataFile.SetResourceName(const AName: string);
begin
  FResourceName := AName;
end;

//---------------------------------------------------------------------------
function StrToGLSResType(const AStrRes: string): TGSApplicationResource;
begin
  if AStrRes = '[SAMPLERS]' then
  begin
    Result := aresSampler;
  end
  else if AStrRes = '[TEXTURES]' then
  begin
    Result := aresTexture;
  end
  else if AStrRes = '[MATERIALS]' then
  begin
    Result := aresMaterial;
  end
  else if AStrRes = '[STATIC MESHES]' then
  begin
    Result := aresMesh;
  end
  else if AStrRes = '[SPLASH]' then
  begin
    Result := aresSplash;
  end
  else if AStrRes = '[FONTS]' then
  begin
    Result := aresFont;
  end
  else
    Result := aresNone;
end;

//----------------------------------------------------------------------------

end.
