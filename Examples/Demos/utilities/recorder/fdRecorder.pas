unit fdRecorder;

interface

uses
  System.Classes, 
  System.SysUtils, 
  System.Math,
  Vcl.Forms, 
  Vcl.Graphics, 
  Vcl.Controls,
  Vcl.ComCtrls, 
  Vcl.ExtCtrls, 
  Vcl.StdCtrls,
  
  GLS.Scene, 
  GLS.Objects, 
  GLS.AsyncTimer,  
  GLS.Cadencer, 
  GLS.AVIRecorder, 
  GLS.SceneViewer,
  
  GLS.Coordinates, 
  GLS.BaseClasses;

type
  TFormAVI = class(TForm)
    GLScene1: TGLScene;
    GLSceneViewer1: TGLSceneViewer;
    TrackBar: TTrackBar;
    Cube1: TGLCube;
    Cube3: TGLCube;
    Cube2: TGLCube;
    GLCamera1: TGLCamera;
    GLLightSource1: TGLLightSource;
    StaticText1: TStaticText;
    DummyCube1: TGLDummyCube;
    DummyCube2: TGLDummyCube;
    GLCadencer1: TGLCadencer;
    ButtonRecord: TButton;
    AVIRecorder1: TGLAVIRecorder;
    procedure TrackBarChange(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure ButtonRecordClick(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
    procedure AVIRecorder1PostProcessEvent(Sender: TObject;
      frame: TBitmap);
    procedure FormCreate(Sender: TObject);
  private
      UserAbort : boolean;
  end;

var
  FormAVI: TFormAVI;

implementation //=============================================================

{$R *.DFM}

procedure TFormAVI.FormCreate(Sender: TObject);
begin
  SetCurrentDir(Application.ExeName);
end;


procedure TFormAVI.TrackBarChange(Sender: TObject);
var
   t : Integer;
begin
	t:=TrackBar.Position;
	// the "sun" spins slowly
	Cube1.TurnAngle:=t/4;
	// "earth" rotates around the sun and spins
	DummyCube1.TurnAngle:=-t;
	Cube2.TurnAngle:=t*2;
	// "moon" rotates around earth and spins
	DummyCube2.RollAngle:=3*t;
	Cube3.TurnAngle:=4*t;
   // update FPS count
   StaticText1.Caption:=IntToStr(Trunc(GLSceneViewer1.FramesPerSecond))+' FPS';
end;

procedure TFormAVI.FormResize(Sender: TObject);
begin
	GLSceneViewer1.ResetPerformanceMonitor;
  AVIRecorder1.Width := GLSceneViewer1.Width;
  AVIRecorder1.Height := GLSceneViewer1.Height;
end;

procedure TFormAVI.ButtonRecordClick(Sender: TObject);
var
  i : integer;
  SavedCap : string;

begin
   AVIRecorder1.Filename := GetCurrentDir() + 'Test.avi';
   if not AVIRecorder1.CreateAVIFile then Exit;
   // if AVIRecorder1.filename is empty, a dialog box will appear asking
   // for the filename. CreateAVIFile() will return a bool
   // indicating if user presses "cancel" in the dialog box.

   SavedCap := Caption;
   caption := 'Press ESC to abort';
   UserAbort := false;
   StaticText1.Visible := false; // the FPS shown is not correct now,
                               // so just hide it for the time being.
   i:=0;
   ButtonRecord.enabled := false;
   TrackBar.enabled := false;
   try
      while (i<360) and not UserAbort do begin
         TrackBar.Position:=i;
         TrackBarChange(self);
         AVIRecorder1.AddAVIFrame;
         // you might want to update your progress bar here.
         Application.ProcessMessages; // so that our app. is not freezed,
                                      // and will accept user abort.
         inc(i);
      end;
   finally
      AVIRecorder1.CloseAVIFile(UserAbort); // if UserAbort, CloseAVIFile will
                                            // also delete the unfinished file.
      caption:=SavedCap;
      StaticText1.Visible := true;
      ButtonRecord.Enabled := true;
      TrackBar.enabled := true;
   end;
end;

//--------------------- AVIRecorder1PostProcess ------------------------------
procedure TFormAVI.AVIRecorder1PostProcessEvent(Sender: TObject;
  frame: TBitmap);
begin
   // PostProcess event is used to add a "watermark"
   // that will be in the AVI, but isn't visible on-screen
   with frame.Canvas do
   begin
      Font.Color:=clAqua;
      Font.Name:='Courrier New';
      Font.Size:=24;
      Font.Style:=[fsBold];
      Brush.Style:=bsClear;
      TextOut(20, 20, Format('GLScene %.3d', [TrackBar.Position]));
   end;
end;

procedure TFormAVI.FormKeyPress(Sender: TObject; var Key: Char);
begin
  UserAbort := key = #27;
end;

end.
