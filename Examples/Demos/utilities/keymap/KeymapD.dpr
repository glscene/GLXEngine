(*
   Demonstrates how to check pressed keys and allow the user to remap controls.

   The panel react to the "key" written in their Caption property, default
   captions react to mouse buttons. If a panel is clicked, the user will be
   prompted to type a key, this key will then be mapped to the panel, by name.

   Note the some keynames are localized and may differ between Windows versions,
   this is the case for most control and num keypad keys.
*)
program KeymapD;

uses
  Forms,
  fdKeymap in 'fdKeymap.pas' {FormKeymap};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormKeymap, FormKeymap);
  Application.Run;
end.
