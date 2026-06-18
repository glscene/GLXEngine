//
// Graphic Scene Engine, http://glscene.org
//
{
   DelphiWebScript symbol creation for base GLScene classes. 

   This unit is dependent on DwsClasses and DwsVectorGeometry.
   These components must be associated with the same compiler
   for the GLScene classes to inherit from. 
}
unit VXS.DWSScene;

interface

uses
  System.Classes, 
  System.SysUtils,
  DwsExprs, 
  DwsSymbols, 
  DwsComp, 
  DwsCompStrings, 
  DwsStack, 
  DwsFunctions, 
  DwsHelperFunc, 
  GXS.Scene, 
  Stage.VectorGeometry,
  Stage.Coordinates;

type
  TDwsGLXceneUnit = class(TDwsUnitComponent)
    private
    procedure AddClassTGSCoordinates(SymbolTable : TSymbolTable);
      procedure AddClassTgxBaseSceneObject(SymbolTable : TSymbolTable);
    protected
      procedure AddUnitSymbols(SymbolTable: TSymbolTable); override;
    public
      constructor Create(AOwner: TComponent); override;
  end;

procedure Register;

//============================================
implementation
//============================================

// ----------
// ---------- Internal class method class declarations ----------
// ----------

type

  
  TGSCoordinatesSetXMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetXMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetYMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetYMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetZMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetZMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetWMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetWMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetVectorMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetPointMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetToZeroMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesSetAsVectorMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetAsVectorMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesGetAsStringMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesTranslateMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesAddScaledVectorMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesRotateMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesNormalizeMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesInvertMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesScaleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TGSCoordinatesEqualsMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;


  // TgxBaseSceneObject

  TgxBaseSceneObjectSetVisibleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetVisibleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetMatrixMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetMatrixMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectAbsoluteMatrixMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectInvAbsoluteMatrixMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetAbsolutePositionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetAbsolutePositionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetAbsoluteUpMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetAbsoluteUpMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetAbsoluteDirectionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetAbsoluteDirectionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetPositionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetPositionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetDirectionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetDirectionMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetUpMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetUpMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetScaleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetScaleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetPitchAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetPitchAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetTurnAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetTurnAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectSetRollAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectGetRollAngleMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectPitchMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectTurnMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectRollMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectMoveMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;

  TgxBaseSceneObjectAddChildMethod = class(TInternalMethod)
    public
      procedure Execute(var ExternalObject: TObject); override;
  end;


// ----------
// ---------- Vector/Matrix to/from IInfo helper functions ----------
// ----------

// GetVectorFromInfo
//
function GetVectorFromInfo(Info : IInfo) : TVector4f;
begin
  Result:=VectorMake(Info.Element([0]).Value,
                     Info.Element([1]).Value,
                     Info.Element([2]).Value,
                     Info.Element([3]).Value);
end;

procedure SetInfoFromVector(Info : IInfo; vec : TVector4f);
var
  i : Integer;
begin
  for i:=0 to 3 do
    Info.Element([i]).Value:=vec[i];
end;

function GetMatrixFromInfo(Info : IInfo) : TMatrix4f;
var
  i : Integer;
begin
  for i:=0 to 3 do
    Result[i]:=VectorMake(Info.Element([i]).Element([0]).Value,
                          Info.Element([i]).Element([1]).Value,
                          Info.Element([i]).Element([2]).Value,
                          Info.Element([i]).Element([3]).Value);
end;

procedure SetInfoFromMatrix(Info : IInfo; mat : TMatrix4f);
var
  i,j : Integer;
begin
  for i:=0 to 3 do
    for j:=0 to 3 do
      Info.Element([i]).Element([j]).Value:=mat[i][j];
end;


// ----------
// ---------- Internal class method execute procedures ----------
// ----------

procedure TGSCoordinatesSetXMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).X:=Info['Value'];
end;

procedure TGSCoordinatesGetXMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  Info.Result:=TGSCoordinates(ExternalObject).X;
end;

// TGSCoordinates.Y write access
procedure TGSCoordinatesSetYMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).Y:=Info['Value'];
end;

// TGSCoordinates.Y read access
procedure TGSCoordinatesGetYMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  Info.Result:=TGSCoordinates(ExternalObject).Y;
end;

// TGSCoordinates.Z write access
procedure TGSCoordinatesSetZMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).Z:=Info['Value'];
end;

// TGSCoordinates.Z read access
procedure TGSCoordinatesGetZMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  Info.Result:=TGSCoordinates(ExternalObject).Z;
end;

// TGSCoordinates.W write access
procedure TGSCoordinatesSetWMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).W:=Info['Value'];
end;

// TGSCoordinates.W read access
procedure TGSCoordinatesGetWMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  Info.Result:=TGSCoordinates(ExternalObject).W;
end;

// TGSCoordinates.SetVector
procedure TGSCoordinatesSetVectorMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).SetVector(Info['x'],Info['y'],Info['z'],Info['w']);
end;

// TGSCoordinates.SetPoint
procedure TGSCoordinatesSetPointMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).SetPoint(Info['x'],Info['y'],Info['z']);
end;

// TGSCoordinates.AsVector write access
procedure TGSCoordinatesSetAsVectorMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=GetVectorFromInfo(Info.Vars['Value']);
  TGSCoordinates(ExternalObject).AsVector:=v;
end;

// TGSCoordinates.AsVector read access
procedure TGSCoordinatesGetAsVectorMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=TGSCoordinates(ExternalObject).AsVector;
  SetInfoFromVector(Info.Vars['Result'], v);
end;

// TGSCoordinates.AsString read access
procedure TGSCoordinatesGetAsStringMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  Info.Result:=TGSCoordinates(ExternalObject).AsString;
end;

// TGSCoordinates.Translate
procedure TGSCoordinatesTranslateMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=GetVectorFromInfo(Info.Vars['translationVector']);
  TGSCoordinates(ExternalObject).Translate(v);
end;

// TGSCoordinates.AddScaledVector
procedure TGSCoordinatesAddScaledVectorMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=GetVectorFromInfo(Info.Vars['translationVector']);
  TGSCoordinates(ExternalObject).AddScaledVector(Info['factor'],v);
end;

// TGSCoordinates.Rotate
procedure TGSCoordinatesRotateMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=GetVectorFromInfo(Info.Vars['anAxis']);
  TGSCoordinates(ExternalObject).Rotate(v, Info['anAngle']);
end;

// TGSCoordinates.Normalize
procedure TGSCoordinatesNormalizeMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).Normalize;
end;

// TGSCoordinates.Invert
procedure TGSCoordinatesInvertMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).Invert;
end;

// TGSCoordinates.Scale
procedure TGSCoordinatesScaleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).Scale(Info['factor']);
end;

// TGSCoordinates.Equals
procedure TGSCoordinatesEqualsMethod.Execute(var ExternalObject: TObject);
var
  v : TVector4f;
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  v:=GetVectorFromInfo(Info.Vars['aVector']);
  Info.Result:=TGSCoordinates(ExternalObject).Equals(v);
end;

// TGSCoordinates.SetToZero
procedure TGSCoordinatesSetToZeroMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TGSCoordinates);
  TGSCoordinates(ExternalObject).SetToZero;
end;


// TgxBaseSceneObject internal class methods

procedure TgxBaseSceneObjectSetVisibleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Visible:=Info.Vars['Value'].Value;
end;

// TgxBaseSceneObject.GetVisible
procedure TgxBaseSceneObjectGetVisibleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=TgxBaseSceneObject(ExternalObject).Visible;
end;

// TgxBaseSceneObject.SetMatrix
procedure TgxBaseSceneObjectSetMatrixMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Matrix:=GetMatrixFromInfo(Info.Vars['Value']);
end;

// TgxBaseSceneObject.GetMatrix
procedure TgxBaseSceneObjectGetMatrixMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromMatrix(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).Matrix);
end;

// TgxBaseSceneObject.AbsoluteMatrix
procedure TgxBaseSceneObjectAbsoluteMatrixMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromMatrix(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).AbsoluteMatrix);
end;

// TgxBaseSceneObject.InvAbsoluteMatrix
procedure TgxBaseSceneObjectInvAbsoluteMatrixMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromMatrix(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).InvAbsoluteMatrix);
end;

// TgxBaseSceneObject.SetAbsolutePosition
procedure TgxBaseSceneObjectSetAbsolutePositionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).AbsolutePosition:=GetVectorFromInfo(Info.Vars['Value']);
end;

// TgxBaseSceneObject.GetAbsolutePosition
procedure TgxBaseSceneObjectGetAbsolutePositionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromVector(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).AbsolutePosition);
end;

// TgxBaseSceneObject.SetAbsoluteUp
procedure TgxBaseSceneObjectSetAbsoluteUpMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).AbsoluteUp:=GetVectorFromInfo(Info.Vars['Value']);
end;

// TgxBaseSceneObject.GetAbsoluteUp
procedure TgxBaseSceneObjectGetAbsoluteUpMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromVector(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).AbsoluteUp);
end;

// TgxBaseSceneObject.SetAbsoluteDirection
procedure TgxBaseSceneObjectSetAbsoluteDirectionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).AbsoluteDirection:=GetVectorFromInfo(Info.Vars['Value']);
end;

// TgxBaseSceneObject.GetAbsoluteDirection
procedure TgxBaseSceneObjectGetAbsoluteDirectionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  SetInfoFromVector(Info.Vars['Result'], TgxBaseSceneObject(ExternalObject).AbsoluteDirection);
end;

// TgxBaseSceneObject.Position write access
procedure TgxBaseSceneObjectSetPositionMethod.Execute(var ExternalObject: TObject);
var
  Value : TGSCoordinates;
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Value:=TGSCoordinates(Info.GetExternalObjForVar('Value'));
  TgxBaseSceneObject(ExternalObject).Position:=Value;
end;

// TgxBaseSceneObject.Position read access
procedure TgxBaseSceneObjectGetPositionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=Info.RegisterExternalObject(TgxBaseSceneObject(ExternalObject).Position);
end;

// TgxBaseSceneObject.Direction write access
procedure TgxBaseSceneObjectSetDirectionMethod.Execute(var ExternalObject: TObject);
var
  Value : TGSCoordinates;
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Value:=TGSCoordinates(Info.GetExternalObjForVar('Value'));
  TgxBaseSceneObject(ExternalObject).Direction:=Value;
end;

// TgxBaseSceneObject.Direction read access
procedure TgxBaseSceneObjectGetDirectionMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=Info.RegisterExternalObject(TgxBaseSceneObject(ExternalObject).Direction);
end;

// TgxBaseSceneObject.Up write access
procedure TgxBaseSceneObjectSetUpMethod.Execute(var ExternalObject: TObject);
var
  Value : TGSCoordinates;
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Value:=TGSCoordinates(Info.GetExternalObjForVar('Value'));
  TgxBaseSceneObject(ExternalObject).Up:=Value;
end;

// TgxBaseSceneObject.Up read access
procedure TgxBaseSceneObjectGetUpMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=Info.RegisterExternalObject(TgxBaseSceneObject(ExternalObject).Up);
end;

// TgxBaseSceneObject.Scale write access
procedure TgxBaseSceneObjectSetScaleMethod.Execute(var ExternalObject: TObject);
var
  Value : TGSCoordinates;
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Value:=TGSCoordinates(Info.GetExternalObjForVar('Value'));
  TgxBaseSceneObject(ExternalObject).Scale:=Value;
end;

// TgxBaseSceneObject.Scale read access
procedure TgxBaseSceneObjectGetScaleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=Info.RegisterExternalObject(TgxBaseSceneObject(ExternalObject).Scale);
end;

// TgxBaseSceneObject.PitchAngle write access
procedure TgxBaseSceneObjectSetPitchAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).PitchAngle:=Info.Vars['Value'].Value;
end;

// TgxBaseSceneObject.PitchAngle read access
procedure TgxBaseSceneObjectGetPitchAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=TgxBaseSceneObject(ExternalObject).PitchAngle;
end;

// TgxBaseSceneObject.TurnAngle write access
procedure TgxBaseSceneObjectSetTurnAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).TurnAngle:=Info.Vars['Value'].Value;
end;

// TgxBaseSceneObject.TurnAngle read access
procedure TgxBaseSceneObjectGetTurnAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=TgxBaseSceneObject(ExternalObject).TurnAngle;
end;

// TgxBaseSceneObject.RollAngle write access
procedure TgxBaseSceneObjectSetRollAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).RollAngle:=Info.Vars['Value'].Value;
end;

// TgxBaseSceneObject.RollAngle read access
procedure TgxBaseSceneObjectGetRollAngleMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  Info.Result:=TgxBaseSceneObject(ExternalObject).RollAngle;
end;

// TgxBaseSceneObject.Pitch
procedure TgxBaseSceneObjectPitchMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Pitch(Info['angle']);
end;

// TgxBaseSceneObject.Turn
procedure TgxBaseSceneObjectTurnMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Turn(Info['angle']);
end;

// TgxBaseSceneObject.Roll
procedure TgxBaseSceneObjectRollMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Roll(Info['angle']);
end;

// TgxBaseSceneObject.Move
procedure TgxBaseSceneObjectMoveMethod.Execute(var ExternalObject: TObject);
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  TgxBaseSceneObject(ExternalObject).Move(Info['ADistance']);
end;

// TgxBaseSceneObject.AddChild
procedure TgxBaseSceneObjectAddChildMethod.Execute(var ExternalObject: TObject);
var
  AChild : TObject;
begin
  ValidateExternalObject(ExternalObject, TgxBaseSceneObject);
  AChild:=Info.GetExternalObjForVar('AChild');
  if not Assigned(AChild) then raise Exception.Create('AChild parameter is unassigned.');
  if not (AChild is TgxBaseSceneObject) then Exception.Create('AChild parameter is not inheriting from TgxBaseSceneObject.');
  TgxBaseSceneObject(ExternalObject).AddChild(TgxBaseSceneObject(AChild));
end;


// ----------
// ---------- Global procedures/functions ----------
// ----------

procedure Register;
begin
  RegisterComponents('GXScene Dws', [TDwsGLXceneUnit]);
end;


// ----------
// ---------- TDwsGLXceneUnit ----------
// ----------

constructor TDwsGLXceneUnit.Create(AOwner: TComponent);
begin
  inherited;
  FUnitName:='GXScene';
  with FDependencies do begin
    Add('Classes');
    Add('Stage.VectorGeometry');
  end;
end;

procedure TDwsGLXceneUnit.AddClassTGSCoordinates(
  SymbolTable: TSymbolTable);
var
  ClassSym : TClassSymbol;
begin
  ClassSym:=TClassSymbol(AddClassSymbol(SymbolTable, 'TGSCoordinates', 'TPersistent'));

  // Methods
  if not Assigned(ClassSym.Members.FindLocal('SetX')) then
    TGSCoordinatesSetXMethod.Create(mkProcedure, [], 0, 'SetX', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetX')) then
    TGSCoordinatesGetXMethod.Create(mkFunction, [], 0, 'GetX', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetY')) then
    TGSCoordinatesSetYMethod.Create(mkProcedure, [], 0, 'SetY', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetY')) then
    TGSCoordinatesGetYMethod.Create(mkFunction, [], 0, 'GetY', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetZ')) then
    TGSCoordinatesSetZMethod.Create(mkProcedure, [], 0, 'SetZ', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetZ')) then
    TGSCoordinatesGetZMethod.Create(mkFunction, [], 0, 'GetZ', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetW')) then
    TGSCoordinatesSetWMethod.Create(mkProcedure, [], 0, 'SetW', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetW')) then
    TGSCoordinatesGetWMethod.Create(mkFunction, [], 0, 'GetW', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetVector')) then
    TGSCoordinatesSetVectorMethod.Create(mkProcedure, [], 0, 'SetVector', ['x', 'Float', 'y', 'Float', 'z', 'Float', 'w', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetPoint')) then
    TGSCoordinatesSetPointMethod.Create(mkProcedure, [], 0, 'SetPoint', ['x', 'Float', 'y', 'Float', 'z', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetToZero')) then
    TGSCoordinatesSetToZeroMethod.Create(mkProcedure, [], 0, 'SetToZero', [], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetAsVector')) then
    TGSCoordinatesSetAsVectorMethod.Create(mkProcedure, [], 0, 'SetAsVector', ['Value', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetAsVector')) then
    TGSCoordinatesGetAsVectorMethod.Create(mkFunction, [], 0, 'GetAsVector', [], 'TVector4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetAsString')) then
    TGSCoordinatesGetAsStringMethod.Create(mkFunction, [], 0, 'GetAsString', [], 'String', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Translate')) then
    TGSCoordinatesTranslateMethod.Create(mkProcedure, [], 0, 'Translate', ['translationVector', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('AddScaledVector')) then
    TGSCoordinatesAddScaledVectorMethod.Create(mkProcedure, [], 0, 'AddScaledVector', ['factor', 'Float', 'translationVector', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Rotate')) then
    TGSCoordinatesRotateMethod.Create(mkProcedure, [], 0, 'Rotate', ['anAxis', 'TVector4f', 'anAngle', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Normalize')) then
    TGSCoordinatesNormalizeMethod.Create(mkProcedure, [], 0, 'Normalize', [], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Invert')) then
    TGSCoordinatesInvertMethod.Create(mkProcedure, [], 0, 'Invert', [], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Scale')) then
    TGSCoordinatesScaleMethod.Create(mkProcedure, [], 0, 'Scale', ['factor', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Equals')) then
    TGSCoordinatesEqualsMethod.Create(mkFunction, [], 0, 'Equals', ['aVector', 'TVector4f'], 'Boolean', ClassSym, SymbolTable);

  // Properties
  AddPropertyToClass('X', 'Float', 'GetX', 'SetX', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Y', 'Float', 'GetY', 'SetY', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Z', 'Float', 'GetZ', 'SetZ', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('AsVector', 'TVector4f', 'GetAsVector', 'SetAsVector', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('AsString', 'String', 'GetAsString', '', '', False, ClassSym, SymbolTable);
end;

// AddClassTgxBaseSceneObject
//
procedure TDwsGLXceneUnit.AddClassTgxBaseSceneObject(
  SymbolTable: TSymbolTable);
var
  ClassSym : TClassSymbol;
begin
  ClassSym:=TClassSymbol(AddClassSymbol(SymbolTable, 'TgxBaseSceneObject', 'TComponent'));

  // Methods
  if not Assigned(ClassSym.Members.FindLocal('SetVisible')) then
    TgxBaseSceneObjectSetVisibleMethod.Create(mkProcedure, [], 0, 'SetVisible', ['Value', 'Boolean'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetVisible')) then
    TgxBaseSceneObjectGetVisibleMethod.Create(mkFunction, [], 0, 'GetVisible', [], 'Boolean', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetMatrix')) then
    TgxBaseSceneObjectSetMatrixMethod.Create(mkProcedure, [], 0, 'SetMatrix', ['Value', 'TMatrix4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetMatrix')) then
    TgxBaseSceneObjectGetMatrixMethod.Create(mkFunction, [], 0, 'GetMatrix', [], 'TMatrix4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('AbsoluteMatrix')) then
    TgxBaseSceneObjectAbsoluteMatrixMethod.Create(mkFunction, [], 0, 'AbsoluteMatrix', [], 'TMatrix4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('InvAbsoluteMatrix')) then
    TgxBaseSceneObjectInvAbsoluteMatrixMethod.Create(mkFunction, [], 0, 'InvAbsoluteMatrix', [], 'TMatrix4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetAbsolutePosition')) then
    TgxBaseSceneObjectSetAbsolutePositionMethod.Create(mkProcedure, [], 0, 'SetAbsolutePosition', ['Value', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetAbsolutePosition')) then
    TgxBaseSceneObjectGetAbsolutePositionMethod.Create(mkFunction, [], 0, 'GetAbsolutePosition', [], 'TVector4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetAbsoluteUp')) then
    TgxBaseSceneObjectSetAbsoluteUpMethod.Create(mkProcedure, [], 0, 'SetAbsoluteUp', ['Value', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetAbsoluteUp')) then
    TgxBaseSceneObjectGetAbsoluteUpMethod.Create(mkFunction, [], 0, 'GetAbsoluteUp', [], 'TVector4f', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetAbsoluteDirection')) then
    TgxBaseSceneObjectSetAbsoluteDirectionMethod.Create(mkProcedure, [], 0, 'SetAbsoluteDirection', ['Value', 'TVector4f'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetAbsoluteDirection')) then
    TgxBaseSceneObjectGetAbsoluteDirectionMethod.Create(mkFunction, [], 0, 'GetAbsoluteDirection', [], 'TVector4f', ClassSym, SymbolTable);

  if not Assigned(ClassSym.Members.FindLocal('SetPosition')) then
    TgxBaseSceneObjectSetPositionMethod.Create(mkProcedure, [], 0, 'SetPosition', ['Value', 'TGSCoordinates'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetPosition')) then
    TgxBaseSceneObjectGetPositionMethod.Create(mkFunction, [], 0, 'GetPosition', [], 'TGSCoordinates', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetDirection')) then
    TgxBaseSceneObjectSetDirectionMethod.Create(mkProcedure, [], 0, 'SetDirection', ['Value', 'TGSCoordinates'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetDirection')) then
    TgxBaseSceneObjectGetDirectionMethod.Create(mkFunction, [], 0, 'GetDirection', [], 'TGSCoordinates', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetUp')) then
    TgxBaseSceneObjectSetUpMethod.Create(mkProcedure, [], 0, 'SetUp', ['Value', 'TGSCoordinates'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetUp')) then
    TgxBaseSceneObjectGetUpMethod.Create(mkFunction, [], 0, 'GetUp', [], 'TGSCoordinates', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetScale')) then
    TgxBaseSceneObjectSetScaleMethod.Create(mkProcedure, [], 0, 'SetScale', ['Value', 'TGSCoordinates'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetScale')) then
    TgxBaseSceneObjectGetScaleMethod.Create(mkFunction, [], 0, 'GetScale', [], 'TGSCoordinates', ClassSym, SymbolTable);

  if not Assigned(ClassSym.Members.FindLocal('SetPitchAngle')) then
    TgxBaseSceneObjectSetPitchAngleMethod.Create(mkProcedure, [], 0, 'SetPitchAngle', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetPitchAngle')) then
    TgxBaseSceneObjectGetPitchAngleMethod.Create(mkFunction, [], 0, 'GetPitchAngle', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetTurnAngle')) then
    TgxBaseSceneObjectSetTurnAngleMethod.Create(mkProcedure, [], 0, 'SetTurnAngle', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetTurnAngle')) then
    TgxBaseSceneObjectGetTurnAngleMethod.Create(mkFunction, [], 0, 'GetTurnAngle', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('SetRollAngle')) then
    TgxBaseSceneObjectSetRollAngleMethod.Create(mkProcedure, [], 0, 'SetRollAngle', ['Value', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('GetRollAngle')) then
    TgxBaseSceneObjectGetRollAngleMethod.Create(mkFunction, [], 0, 'GetRollAngle', [], 'Float', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Pitch')) then
    TgxBaseSceneObjectPitchMethod.Create(mkProcedure, [], 0, 'Pitch', ['angle', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Turn')) then
    TgxBaseSceneObjectTurnMethod.Create(mkProcedure, [], 0, 'Turn', ['angle', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Roll')) then
    TgxBaseSceneObjectRollMethod.Create(mkProcedure, [], 0, 'Roll', ['angle', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('Move')) then
    TgxBaseSceneObjectMoveMethod.Create(mkProcedure, [], 0, 'Move', ['ADistance', 'Float'], '', ClassSym, SymbolTable);
  if not Assigned(ClassSym.Members.FindLocal('AddChild')) then
    TgxBaseSceneObjectAddChildMethod.Create(mkProcedure, [], 0, 'AddChild', ['AChild', 'TgxBaseSceneObject'], '', ClassSym, SymbolTable);

  // Properties
  AddPropertyToClass('Visible', 'Boolean', 'GetVisible', 'SetVisible', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Matrix', 'TMatrix4f', 'GetMatrix', 'SetMatrix', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('AbsolutePosition', 'TVector4f', 'GetAbsolutePosition', 'SetAbsolutePosition', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('AbsoluteUp', 'TVector4f', 'GetAbsoluteUp', 'SetAbsoluteUp', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('AbsoluteDirection', 'TVector4f', 'GetAbsoluteDirection', 'SetAbsoluteDirection', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Position', 'TgxBaseSceneObject', 'GetPosition', 'SetPosition', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Direction', 'TgxBaseSceneObject', 'GetDirection', 'SetDirection', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Up', 'TgxBaseSceneObject', 'GetUp', 'SetUp', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('Scale', 'TgxBaseSceneObject', 'GetScale', 'SetScale', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('PitchAngle', 'Float', 'GetPitchAngle', 'SetPitchAngle', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('TurnAngle', 'Float', 'GetTurnAngle', 'SetTurnAngle', '', False, ClassSym, SymbolTable);
  AddPropertyToClass('RollAngle', 'Float', 'GetRollAngle', 'SetRollAngle', '', False, ClassSym, SymbolTable);
end;

// AddUnitSymbols
//
procedure TDwsGLXceneUnit.AddUnitSymbols(SymbolTable: TSymbolTable);
begin
  // Forward class declaration
  AddForwardDeclaration('TGSCoordinates', SymbolTable);
  AddForwardDeclaration('TgxBaseSceneObject', SymbolTable);

  // Class types
  AddClassTGSCoordinates(SymbolTable);
  AddClassTgxBaseSceneObject(SymbolTable);
end;

end.
