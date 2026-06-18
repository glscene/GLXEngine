(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit GXS.Cg.Register;
(*
  Registration unit for Cg Shader package
*)
interface

uses
  System.Classes,
// ToDo
///  DesignIntf,       not implemented
///  DesignEditors,
///  FMXEditors,

  GXS.Material,

  Cg.Import,
  Cg.GL,
///  GXS.SceneRegister,  // for TgxLibMaterialNameProperty
  GXS.Cg.Shader,
  GXS.Cg.BombShader;

procedure Register;

implementation //============================================================

procedure Register;
begin
  RegisterComponents('GXScene Shaders', [TCGxShader, TCGxBombShader]);
///  RegisterPropertyEditor(TypeInfo(TgxLibMaterialName), TCGxBombShader, '', TgxLibMaterialNameProperty);
end;

end.
