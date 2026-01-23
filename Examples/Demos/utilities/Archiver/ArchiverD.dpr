program ArchiverD;

uses
  Forms,
  fdArchiver in 'fdArchiver.pas' {FormArchiver};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormArchiver, FormArchiver);
  Application.Run;
end.

