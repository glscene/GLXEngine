(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
program ShadowsD;
(*
  Shadow casting with GLzBuffer by Rene Lindsay.
*)
uses
  Forms,
  fdShadows in 'fdShadows.pas' {FormShadows};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormShadows, FormShadows);
  Application.Run;
end.
