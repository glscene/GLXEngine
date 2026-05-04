//
// GXScene Graphics Engine
//
unit GXS.Sounds.Register;

(* Design time registration code for the Sounds *)

interface

uses
  System.Classes,

  GXS.Sounds.BASS,
  GXS.Sounds.FMOD,
  GXS.Sounds.OpenAL,
  GXS.Sounds.WaveOut;

procedure Register;

implementation //------------------------------------------------------------

procedure Register;
begin
  RegisterComponents('GXScene',[TgxsmBASS, TgxsmOpenAL,TgxsmWaveOut]);
end;

end.
