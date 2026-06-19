(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit fdGLForm;
(*
  The unit for TGLForm class as a parent for all child forms
*)
interface

uses
  Winapi.Windows,
  System.SysUtils,
  System.IniFiles,
  Vcl.Forms,
  Vcl.Graphics,
  Vcl.Menus,
  Vcl.Actnlist,
  udGlobals
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

implementation //=============================================================

{$R *.dfm}

//---------------------------------------------------------------------------
//There are may be translations of all component strings
//---------------------------------------------------------------------------
procedure TGLForm.ReadIniFile;
begin
  IniFile := TIniFile.Create(ChangeFileExt(ParamStr(0), '.ini'));
  with IniFile do
    try
      LanguageID := ReadInteger('FormOptions', 'rgLanguage', 0);
      //...
    finally
      IniFile.Free;
    end;
end;

end.
