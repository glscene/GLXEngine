(*
Bump Mapping
Author: Antic (edited by Da Stranger)
Date:  09 June 2006
*)
program CgBumpMapD;

uses
  Forms,
  fdBumpMap in 'fdBumpMap.pas' {FormBumpMap};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormBumpMap, FormBumpMap);
  Application.Run;
end.
