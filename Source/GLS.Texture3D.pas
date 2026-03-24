//
// The GaLaXy Engine graphics. The unit of GLScene
//
unit GLS.Texture3D;
(*
  A class for 3D textures
*)
interface

uses
  Winapi.Messages,
  Winapi.OpenGL,
  System.SysUtils,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ExtCtrls,
  Vcl.ComCtrls,
  Vcl.StdCtrls,

  Stage.VectorGeometry,
  GLS.Scene,
  GLS.Objects,
  GLS.SceneViewer,
  GLS.Texture,
  GLS.Context,
  GLS.Cadencer,
  GLS.BaseClasses;


type
  TGLTexture3D = class (TGLUpdateAbleObject)
  protected
    FDataType : Longword;
    FSizeX : Integer;
    FSizeY : Integer;
    FSizeZ : Integer;
    FTexelByteSize : Integer;
    M_Data : String;
    function Data_Type_To_Texel_Byte_Size (F_Data_Type : Integer) : Integer;
    procedure Set_Data_Type (AValue : Longword);
    procedure SetSizeX (AValue : Integer);
    procedure SetSizeY (AValue : Integer);
    procedure SetSizeZ (AValue : Integer);
    procedure Set_Data (const AValue : String);
  public
    constructor Create;
    destructor Destroy; override;
    // Save 3d texture to a file                                                                 }
    procedure SaveToFile (const FileName : String);
    // Load 3d texture from a file                                                                 }
    procedure LoadFromFile (const FileName : String);
    property DataType : Longword read FDataType write Set_Data_Type;
    property SizeX: Integer read FSizeX write SetSizeX;
    property SizeY: Integer read FSizeY write SetSizeY;
    property SizeZ: Integer read FSizeZ write SetSizeZ;
    property Texel_Byte_Size : Integer read FTexelByteSize;
    property Data: string read M_Data write Set_Data;
  end; // TGLTexture3D


implementation //==============================================================

//----------------------- Initializes dynamical data ------------------------------
constructor TGLTexture3D.Create;
begin
  inherited Create(nil);

  // Initialize variables
  FDataType := GL_RGBA;
  FSizeX := 0;
  FSizeY := 0;
  FSizeZ := 0;
  FTexelByteSize := Data_Type_To_Texel_Byte_Size (FDataType);
  SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
end;

//---------------- Calculates texel size in bytes -----------------------------
function TGLTexture3D.Data_Type_To_Texel_Byte_Size (F_Data_Type : Integer) : Integer;
begin
  case F_Data_Type Of
    GL_COLOR_INDEX : Result := 1;
    GL_STENCIL_INDEX : Result := 1;
    GL_DEPTH_COMPONENT : Result := 1;
    GL_RED : Result := 1;
    GL_GREEN : Result := 1;
    GL_BLUE : Result := 1;
    GL_ALPHA : Result := 1;
    GL_RGB : Result := 3;
    GL_RGBA : Result := 4;
    GL_LUMINANCE : Result := 1;
    GL_LUMINANCE_ALPHA : Result := 2;
    else
      Result := 4;
  end;
end;


//---------------------- Sets data type ---------------------------------------
procedure TGLTexture3D.Set_Data_Type (AValue : Longword);
begin
  FDataType := AValue;

  FTexelByteSize := Data_Type_To_Texel_Byte_Size (FDataType);
  SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
end;


//-------------------------- Sets X size  -------------------------------------
procedure TGLTexture3D.SetSizeX (AValue : Integer);
begin
  FSizeX := AValue;

  SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
end;


//---------------------------- Sets Y size ------------------------------------
procedure TGLTexture3D.SetSizeY (AValue : Integer);
begin
  FSizeY := AValue;

  SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
end;


//----------------------------- Sets Z size -----------------------------------
procedure TGLTexture3D.SetSizeZ (AValue : Integer);
begin
  FSizeZ := AValue;

  SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
end;


//----------------------------- Sets data -------------------------------------
procedure TGLTexture3D.Set_Data (const AValue : String);
begin
  SetLength (M_Data, Length (AValue));
  M_Data := AValue;
end;


//----------------------- Save data to file -----------------------------------
procedure TGLTexture3D.SaveToFile (const FileName : String);
var
  File_Stream : TFileStream;
begin
  File_Stream := TFileStream.Create (FileName, fmCreate or fmShareDenyWrite);
  try
    File_Stream.WriteBuffer (FDataType, SizeOf (Longword));
    File_Stream.WriteBuffer (FSizeX, SizeOf (Integer));
    File_Stream.WriteBuffer (FSizeY, SizeOf (Integer));
    File_Stream.WriteBuffer (FSizeZ, SizeOf (Integer));
    File_Stream.WriteBuffer (PChar (M_Data)^, Length (M_Data));
  finally
    File_Stream.Free;
  end;
end;


//-------------------------- Load data from file ------------------------------
procedure TGLTexture3D.LoadFromFile (const FileName : String);
var
  FileStream : TFileStream;

begin
  FileStream := TFileStream.Create (FileName, fmOpenRead or fmShareDenyWrite);
  try
    FileStream.ReadBuffer (FDataType, SizeOf (Longword));
    FileStream.ReadBuffer (FSizeX, SizeOf (Integer));
    FileStream.ReadBuffer (FSizeY, SizeOf (Integer));
    FileStream.ReadBuffer (FSizeZ, SizeOf (Integer));
    FTexelByteSize := Data_Type_To_Texel_Byte_Size (FDataType);
    SetLength (M_Data, FSizeX * FSizeY * FSizeZ * FTexelByteSize);
    FileStream.ReadBuffer (PChar (M_Data)^, Length (M_Data));
  finally
    FileStream.Free;
  end;
end;

//------------------------- Release dynamic data ----------------------------------
destructor TGLTexture3D.Destroy;
begin
  // Free data
  SetLength (M_Data, 0);
  Inherited Destroy;
end;

initialization //=============================================================

//RegisterClasses(TGLTexture3D);

end.

