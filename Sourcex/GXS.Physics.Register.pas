(*****************************************************************************
                          GXScene Graphics Engine
******************************************************************************)
unit GXS.Physics.Register;
(*
  Design time registration code for the ODE Manager
*)
interface

uses
  System.Classes,
  GXS.Phys.Manager,
  GXS.ODE.Manager,
  GXS.NGD.Manager;

procedure Register;

implementation //============================================================

procedure Register;
begin
  RegisterClasses([TgxODEManager, TgxODEJointList, TgxODEJoints, TgxODEElements,
    TgxNGDManager, TgxNGDDynamic, TgxNGDStatic {, TgxPhysManager}]);
  RegisterComponents('GXScene Physics Managers',[TgxNGDManager, TgxODEManager,
                   TgxODEJointList {, TgxPhysManager}]);
end;

end.
