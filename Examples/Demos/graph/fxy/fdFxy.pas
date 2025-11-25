unit fdFxy;

interface

uses
  System.SysUtils,
  System.Classes,
  System.Math,
  System.Types,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.StdCtrls,
  Vcl.ComCtrls,
  Vcl.ExtCtrls,

  Stage.VectorGeometry,
  Stage.VectorTypes,
  GLS.Objects,
  GLS.Graph,
  GLS.Color,
  GLS.Scene,
  GLS.State,
  GLS.SceneViewer,
  GLS.Coordinates,
  GLS.BaseClasses,
  GLS.AsyncTimer;

type
  TFormFxy = class(TForm)
    GLScene1: TGLScene;
    GLSceneViewer1: TGLSceneViewer;
    GLCamera1: TGLCamera;
    GLLightSource1: TGLLightSource;
    HeightField: TGLHeightField;
    YZGrid: TGLXYZGrid;
    XZGrid: TGLXYZGrid;
    XYGrid: TGLXYZGrid;
    Panel1: TPanel;
    TBXYPosition: TTrackBar;
    TBYZPosition: TTrackBar;
    TBXZPosition: TTrackBar;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    GLAsyncTimer1: TGLAsyncTimer;
    rgFormula: TRadioGroup;
    rgPolygonMode: TRadioGroup;
    CBCentered: TCheckBox;
    procedure GLSceneViewer1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure GLSceneViewer1MouseMove(Sender: TObject; Shift: TShiftState;
      X, Y: Integer);
    procedure CBCenteredClick(Sender: TObject);
    procedure TBXYPositionChange(Sender: TObject);
    procedure TBYZPositionChange(Sender: TObject);
    procedure TBXZPositionChange(Sender: TObject);
    procedure FormMouseWheel(Sender: TObject; Shift: TShiftState;
      WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
    procedure HeightField1GetHeight(const X, Y: Single; var z: Single;
      var Color: TVector4f; var TexPoint: TTexPoint);
    procedure GLAsyncTimer1Timer(Sender: TObject);
    procedure rgFormulaClick(Sender: TObject);
    procedure rgPolygonModeClick(Sender: TObject);
  public
    mx, my: Integer;
    procedure Formula0(const x: Single; const y: Single; var z: Single;
        var Color: TVector4f; var TexPoint: TTexPoint);
    procedure Formula1(const x: Single; const y: Single; var z: Single;
        var Color: TVector4f; var TexPoint: TTexPoint);
    procedure Formula2(const x: Single; const y: Single; var z: Single;
        var Color: TVector4f; var TexPoint: TTexPoint);
	  procedure Formula3(const x: Single; const y: Single; var z: Single;
        var Color: TVector4f; var TexPoint: TTexPoint);
  end;

var
  FormFxy: TFormFxy;


implementation //=============================================================

{$R *.DFM}

//------------------------- Formula ------------------------------------------
procedure TFormFxy.Formula0(const x, y: Single; var z: Single;
  var Color: TVector4f; var TexPoint: TTexPoint);
begin
 	// 0ro formula
	z := VectorNorm(x, y);
	z := x * y;
	VectorLerp(clrBlue, clrRed, (z + 1) / 2, color);
end;

procedure TFormFxy.Formula1(const x, y: Single; var z: Single;
  var Color: TVector4f; var TexPoint: TTexPoint);
begin
	// 1st formula
	z := VectorNorm(x, y);
	z := x * y * z;  // or z = (x*x)*(y*y);
	VectorLerp(clrBlue, clrRed, (z + 1) / 2, color);
end;

procedure TFormFxy.Formula2(const x, y: Single; var z: Single;
  var Color: TVector4f; var TexPoint: TTexPoint);
begin
	// 2nd formula
	z := VectorNorm(x, y);
	z := sin(z * 12) / (2 * (z * 6.28 + 1));
	VectorLerp(clrBlue, clrRed, (z + 1) / 2, color);
end;

procedure TFormFxy.Formula3(const x, y: Single; var z: Single;
  var Color: TVector4f; var TexPoint: TTexPoint);
begin
	// 3rd formula
	z := VectorNorm(x, y);
	z := (Power(x, 2) + Power(y, 2)) * sin(8 * ArcTan2(x, y));
	VectorLerp(clrBlue, clrRed, (z + 1) / 2, color);
end;

//------------------------ HeightField1GetHeight -----------------------------
procedure TFormFxy.HeightField1GetHeight(const X, Y: Single; var z: Single;
  var Color: TVector4f; var TexPoint: TTexPoint);
begin
  z := VectorNorm(X, Y);
  z := cos(z * 12) / (2 * (z * 6.28 + 1));
end;

//----------------------------------------------------------------------------
procedure TFormFxy.CBCenteredClick(Sender: TObject);
begin
  if CBCentered.Checked then
  begin
    XZGrid.YSamplingScale.Origin := 0;
    YZGrid.XSamplingScale.Origin := 0;
    XYGrid.ZSamplingScale.Origin := 0;
  end
  else
  begin
    XZGrid.YSamplingScale.Origin := -1;
    YZGrid.XSamplingScale.Origin := -1;
    XYGrid.ZSamplingScale.Origin := -1;
  end;
end;

procedure TFormFxy.TBXYPositionChange(Sender: TObject);
begin
  XYGrid.ZSamplingScale.Origin := -(TBXYPosition.Position / 10);
end;

procedure TFormFxy.TBYZPositionChange(Sender: TObject);
begin
  YZGrid.XSamplingScale.Origin := -(TBYZPosition.Position / 10);
end;

procedure TFormFxy.TBXZPositionChange(Sender: TObject);
begin
  XZGrid.YSamplingScale.Origin := -(TBXZPosition.Position / 10);
end;

//---------------------------------------------------------------------------
procedure TFormFxy.rgFormulaClick(Sender: TObject);
begin
 	case (rgFormula.ItemIndex) of
		0:
			HeightField.OnGetHeight := Formula0;
		1:
			HeightField.OnGetHeight := Formula1;
		2:
			HeightField.OnGetHeight := Formula2;
		3:
			HeightField.OnGetHeight := Formula3;
    else
  		HeightField.OnGetHeight := Formula0;
  end;
end;

//---------------------------- rgPolygonMode ---------------------------------
procedure TFormFxy.rgPolygonModeClick(Sender: TObject);
begin
 	case (rgPolygonMode.ItemIndex) of
		0:
			HeightField.Material.PolygonMode := pmFill;
		1:
			HeightField.Material.PolygonMode := pmLines;
		2:
			HeightField.Material.PolygonMode := pmPoints;
	end;
  HeightField.StructureChanged();
end;

//----------------------------------------------------------------------------
// following code takes care of camera movement, see camera & movement demos
// for explanations and more samples
procedure TFormFxy.GLAsyncTimer1Timer(Sender: TObject);
begin
  HeightField.StructureChanged;
end;

procedure TFormFxy.GLSceneViewer1MouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  mx := X;
  my := Y;
end;

procedure TFormFxy.GLSceneViewer1MouseMove(Sender: TObject; Shift: TShiftState;
  X, Y: Integer);
begin
  if Shift <> [] then
  begin
    GLCamera1.MoveAroundTarget(my - Y, mx - X);
    mx := X;
    my := Y;
  end;
end;

procedure TFormFxy.FormMouseWheel(Sender: TObject; Shift: TShiftState;
  WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
begin
  GLCamera1 := GLSceneViewer1.Camera;
  // Note that 1 wheel-step induces a WheelDelta of 120,
  // this code adjusts the distance to target with a 10% per wheel-step ratio
  GLCamera1.AdjustDistanceToTarget(Power(1.1, WheelDelta / 120));
end;

end.
