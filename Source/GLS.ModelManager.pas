(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit GLS.ModelManager;
(*
  The ModelManager is a class that provides an easy way to manage
  models and master objects of proxies at runtime.  You just need to
  have the model filename and it will load it into the list or return
  the already existing model
*)
interface

uses
  System.SysUtils,
  System.Classes,

  GLS.Objects,
  GLS.VectorFileObjects,
  GLS.File3DS,
  GLS.FilePly,
  GLS.FileOBJ;

type
  TGLModelManager = class
  private
    FMasterObject: TGLDummyCube;
    FModelList: TStringList;
    FModelPath: string;
    (* Changing the path to the models and refresh the
      already existing freeforms *)
    procedure SetPathToModel(const Value: String);
  public
    (* It will create the list, assign the path to the
      models and the master object where the new models will be loaded *)
    constructor Create(AMaster: TGLDummyCube; APath: string); virtual;
    (* It will free all the loaded models *)
    destructor Destroy; override;
    (* It will load a new model if it's not in the list and then return the new
      freeform.  If it,s already in the list, it will return the existing freeform *)
    function LoadModel(AFilename: string): TGLFreeForm;
    property MasterObject: TGLDummyCube read FMasterObject;
    property ModelList: TStringList read FModelList;
    property Path: string read FModelPath write SetPathToModel;
  end;

implementation //============================================================

constructor TGLModelManager.Create(AMaster: TGLDummyCube; APath: string);
begin
  // Set the master object
  FMasterObject := AMaster;
  // Create the model list
  FModelList := TStringList.Create;
  FModelList.CaseSensitive := false;
  FModelList.Sorted := true;
  // Set the path to the models
  SetPathToModel(APath);
end;

//---------------------------------------------------------------------------
destructor TGLModelManager.Destroy;
var
  i: integer;
begin
  // Destroy every models
  for i := 0 to Pred(FModelList.Count) do
    FModelList.Objects[i].Destroy;
  // Destroy the list
  FModelList.Destroy;
  inherited;
end;

//---------------------------------------------------------------------------
function TGLModelManager.LoadModel(AFilename: string): TGLFreeForm;
var
  i: integer;
  NewFreeForm: TGLFreeForm;
begin
  with FModelList do
  begin
    if Find(AFilename, i) then
      Result := TGLFreeForm(Objects[i])
    else
    begin
      NewFreeForm := TGLFreeForm(FMasterObject.AddNewChild(TGLFreeForm));
      NewFreeForm.LoadFromFile(FModelPath + AFilename);
      FModelList.AddObject(AFilename, NewFreeForm);
      Result := NewFreeForm;
    end;
  end;
end;

//---------------------------------------------------------------------------
procedure TGLModelManager.SetPathToModel(const Value: String);
var
  Len: integer;
  i: integer;
begin
  // Set the path
  FModelPath := Value;
  Len := Length(Value);
  // Correct it if there is no '\'
  if (Len > 0) then
    if (Value[Len - 1] <> '\') then
      FModelPath := Value + '\';
  // Reload the models
  for i := 0 to Pred(FModelList.Count) do
    TGLFreeForm(FModelList.Objects[i])
      .LoadFromFile(FModelPath + FModelList.Strings[i]);
end;

//---------------------------------------------------------------------------
end.
