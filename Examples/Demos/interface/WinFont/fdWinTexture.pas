unit fdWinTexture;

(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ExtCtrls;

type
  TFormFontTexture = class(TForm)
    Image1: TImage;
  private
  public
  end;

var
  FormFontTexture: TFormFontTexture;

implementation //============================================================

{$R *.DFM}

end.
