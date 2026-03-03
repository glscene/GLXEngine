program EventsD;

uses
  Forms,
  fdEvents in 'fdEvents.pas' {FormEvents};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormEvents, FormEvents);
  Application.Run;
end.
