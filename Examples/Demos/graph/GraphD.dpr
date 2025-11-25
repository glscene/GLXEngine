program GraphD;

uses
  Vcl.Forms,
  fdGraph in 'fdGraph.pas' {FormGraph},
  fdFxy in 'fxy\fdFxy.pas' {FormFxy},
  fdHeightField in 'heightfield\fdHeightField.pas' {FormHeightField},
  fdPoints in 'points\fdPoints.pas' {FormPoints},
  fdProjection in 'projection\fdProjection.pas' {FormProjection},
  fdSplines in 'splines\fdSplines.pas' {FormSplines};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormGraph, FormGraph);
  Application.CreateForm(TFormHeightField, FormHeightField);
  Application.CreateForm(TFormPoints, FormPoints);
  Application.CreateForm(TFormProjection, FormProjection);
  Application.CreateForm(TFormSplines, FormSplines);
  Application.Run;
end.
