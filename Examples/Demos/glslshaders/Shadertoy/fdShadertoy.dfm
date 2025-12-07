object FormEiffie: TFormEiffie
  Left = 193
  Top = 127
  ClientHeight = 399
  ClientWidth = 648
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  OnResize = FormResize
  TextHeight = 13
  object SceneViewer: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 648
    Height = 399
    Cursor = crHandPoint
    Camera = cam
    Buffer.BackgroundColor = 15000804
    Buffer.AmbientColor.Color = {0000000000000000000000000000803F}
    FieldOfView = 117.945869445800800000
    PenAsTouch = False
    Align = alClient
    OnClick = SceneViewerClick
    TabOrder = 0
  end
  object GLScene: TGLScene
    Left = 64
    Top = 8
    object dcCamera: TGLDummyCube
      CubeSize = 1.000000000000000000
      EdgeColor.Color = {00000000000000000000803F0000803F}
      object cam: TGLCamera
        DepthOfView = 1000.000000000000000000
        FocalLength = 120.000000000000000000
        TargetObject = dcCamera
        Position.Coordinates = {000080400000C040000040400000803F}
      end
    end
    object dogl: TGLDirectOpenGL
      UseBuildList = False
      OnRender = doglRender
      Blend = False
      object hud: TGLHUDSprite
        Visible = False
        Rotation = 0.000000000000000000
      end
    end
  end
  object GLCadencer: TGLCadencer
    Scene = GLScene
    Mode = cmApplicationIdle
    SleepLength = 1
    OnProgress = GLCadencerProgress
    Left = 54
    Top = 134
  end
  object GLAsyncTimer: TGLAsyncTimer
    Enabled = True
    OnTimer = GLAsyncTimerTimer
    Left = 226
    Top = 8
  end
end
