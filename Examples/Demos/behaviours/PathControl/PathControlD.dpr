{: This Form demonstrates basic "Pathcontrol" movements.

   You can modified the Looped property of the path to enable the path-looping.
   Set ShowPath property to turn on or turn off the path-displaying
}
program PathControlD;

uses
  Forms,
  fdPathControl in 'fdPathControl.pas' {FormPathControl};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormPathControl, FormPathControl);
  Application.Run;
end.