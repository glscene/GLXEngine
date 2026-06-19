(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit udGlobals;

interface

uses
  System.SysUtils,
  System.IniFiles;


const
  // cRegistryKey = 'Software\GLSViewer';
  RegGLSViewer = PathDelim + 'SOFTWARE' + PathDelim + 'GLSViewer' + PathDelim;


var
  ExePath: TFileName;
  ModelPath:   TFileName;
  TexturePath: TFileName;
  IniFile: TIniFile;

  LanguageID: integer;
  GeneralSection: string = RegGLSViewer + 'General';

  SplashStart : Boolean;
  TipOfTheDay : Boolean;


implementation //===========================================================

end.
