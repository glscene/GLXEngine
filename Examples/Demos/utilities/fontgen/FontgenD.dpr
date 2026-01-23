program FontgenD;

uses
  Forms,
  fdFontgen in 'fdFontgen.pas' {FormFontGen};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormFontGen, FormFontGen);
  Application.Run;
end.
