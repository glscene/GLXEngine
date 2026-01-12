program ObjMaterialD;

uses
  Vcl.Forms,
  fdObjMaterial in 'fdObjMaterial.pas' {FormMO};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormMO, FormMO);
  Application.Run;
end.
