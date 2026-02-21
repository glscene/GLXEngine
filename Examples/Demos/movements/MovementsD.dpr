program MovementsD;

uses
  Vcl.Forms,
  fdMovements in 'fdMovements.pas' {FormMovements},
  fdColumn in 'column\fdColumn.pas' {FormColumn},
  fdEvents in 'events\fdEvents.pas' {FormEvents},
  fdHierarch in 'hierarch\fdHierarch.pas' {FormHierarchy},
  fdManual in 'manual\fdManual.pas' {FormManual},
  fdObjmove in 'objmove\fdObjmove.pas' {FormObjmove},
  fdPointto in 'pointto\fdPointto.pas' {FormPointto},
  fdPong in 'pong\fdPong.pas' {FormPong},
  fdSmoothNavi in 'smoothnavi\fdSmoothNavi.pas' {FormSmoothNavigator},
  fdTweening in 'tweening\fdTweening.pas' {FormTweening};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormMovements, FormMovements);
  Application.Run;
end.
