program GLSViewerD;

uses
  Forms,
  fdGLForm in 'Source\fdGLForm.pas' {GLForm},
  fdGLDialog in 'Source\fdGLDialog.pas' {GLDialog},
  fdGLSViewer in 'Source\fdGLSViewer.pas' {FormGLSViewer},
  udGlobals in 'Source\udGlobals.pas',
  udRegistry in 'Source\udRegistry.pas',
  ddImages in 'Source\ddImages.pas' {DataModuleImages: TDataModule},
  fdGLAbout in 'Source\fdGLAbout.pas' {GLAbout},
  fdGLOptions in 'Source\fdGLOptions.pas' {FormOptions},
  ddDialogs in 'Source\ddDialogs.pas' {dmDialogs: TDataModule};

{$R *.res}

begin
 // Application.Initialize;
 // Application.Title := 'GLSViewer';
  Application.CreateForm(TFormGLSViewer, FormGLSViewer);
  Application.CreateForm(TDataModuleImages, DataModuleImages);
  Application.CreateForm(TdmDialogs, dmDialogs);
  Application.CreateForm(TGLForm, GLForm);
  Application.CreateForm(TFormOptions, FormOptions);
  Application.Run;
end.
