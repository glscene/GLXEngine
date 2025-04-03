//---------------------------------------
// This unit is part of the GLSViewer
//---------------------------------------

unit fGLForm;

(* The fGLForm unit for TGLForm class as parent for all child forms of GLSViewer *)

interface

uses
  Winapi.Windows,
  System.SysUtils,
  System.IniFiles,
  Vcl.Forms,
  Vcl.Graphics,
  Vcl.Menus,
  Vcl.Actnlist,
  uGlobals
  ;

type
  TGLForm = class(TForm)
  private
     
  public
    IniFile : TIniFile;
    procedure ReadIniFile; virtual;
  end;

var
  GLForm: TGLForm;

implementation  //---------------------------------------------------------

{$R *.dfm}

//Here goes the translation of all component strings
//
procedure TGLForm.ReadIniFile;
begin
  IniFile := TIniFile.Create(ChangeFileExt(ParamStr(0), '.ini'));
  with IniFile do
    try
      LanguageID := ReadInteger('FormOptions', 'rgLanguage', 0);
    finally
      IniFile.Free;
    end;
end;

end.
