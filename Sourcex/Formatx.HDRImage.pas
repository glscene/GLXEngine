//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit Formatx.HDRImage;
(*
    Good for preview picture in OpenDialog,
    so you may include both HDRImage (preview) and GLFileHDR (loading)
*)
interface

{$I Stage.Defines.inc}

uses
  Winapi.OpenGL,
  Winapi.Windows,
  System.Classes,
  System.SysUtils,
  FMX.Graphics,

  Stage.VectorGeometry,
  GXS.Graphics;

type

  THDRImage = class(TBitmap)
  public
    { TODO : E2170 Cannot override a non-virtual method }
    procedure LoadFromStream(stream: TStream); //in VCL override;
    procedure SaveToStream(stream: TStream); //in VCL override;
  end;

//============================================================================
implementation
//============================================================================

uses
  GXS.FileHDR,
  Stage.TextureFormat;

// ------------------
// ------------------ THDRImage ------------------
// ------------------

procedure THDRImage.LoadFromStream(stream: TStream);
var
  FullHDR: TgxHDRImage;
  src, dst: PGLubyte;
  y: integer;
begin
  FullHDR := TgxHDRImage.Create;
  try
    FullHDR.LoadFromStream(stream);
  except
    FullHDR.Free;
    raise;
  end;
  FullHDR.Narrow;
  Width := FullHDR.LevelWidth[0];
  Height := FullHDR.LevelHeight[0];
  { TODO : E2064 Left side cannot be assigned to }
  (*
  Transparent := false;
  PixelFormat := glpf32bit;
  *)

  src := PGLubyte(FullHDR.Data);
  for y := 0 to Height - 1 do
  begin
    { TODO : E2003 Undeclared identifier: 'ScanLine' }
    (*dst := ScanLine[Height - 1 - y];*)
    Move(src^, dst^, Width * 4);
    Inc(src, Width * 4);
  end;
  FullHDR.Free;
end;

procedure THDRImage.SaveToStream(stream: TStream);
begin
  Assert(False, 'Not supported');
end;

// ------------------------------------------------------------------
initialization
// ------------------------------------------------------------------

  { TODO : E2003 Undeclared identifier: 'RegisterFileFormat', it needs to be added }
  (*TPicture.RegisterFileFormat('HDR', 'High Dynamic Range Image', THDRImage);*)

// ------------------------------------------------------------------
finalization
// ------------------------------------------------------------------

  { TODO : E2003 Undeclared identifier: 'UnregisterFileFormat', it needs to be added }
  (*TPicture.UnregisterGraphicClass(THDRImage);*)

end.

