// a Demo with absolutely no code :)
program SimpleNaviD;

uses
  Forms,
  fdSimpleNavi in 'fdSimpleNavi.pas' {FormSimpleNavigation};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormSimpleNavigation, FormSimpleNavigation);
  Application.Run;
end.
