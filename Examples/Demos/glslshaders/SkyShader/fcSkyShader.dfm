object FormSkyShader: TFormSkyShader
  Left = 0
  Top = 0
  Caption = 'Sky shader'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 15
  object SceneViewer: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    Camera = Camera
    Buffer.BackgroundColor = clBlack
    Buffer.ContextOptions = [roDoubleBuffer, roRenderToWindow, roNoColorBufferClear]
    FieldOfView = 142.429962158203100000
    PenAsTouch = False
    Align = alClient
    TabOrder = 0
  end
  object GLScene1: TGLScene
    Left = 16
    Top = 8
    object DummyCam: TGLDummyCube
      CubeSize = 1.000000000000000000
      object Camera: TGLCamera
        DepthOfView = 100.000000000000000000
        FocalLength = 75.000000000000000000
        TargetObject = DummyCam
        Position.Coordinates = {0000004000004040000080400000803F}
      end
    end
    object DirectOGL: TGLDirectOpenGL
      UseBuildList = False
      Blend = False
      object Thor: TGLTorus
        Direction.Coordinates = {00000000F304353FF304353F00000000}
        PitchAngle = 45.000000000000000000
        Position.Coordinates = {0000004000000000000000000000803F}
        Up.Coordinates = {00000000F304353FF30435BF00000000}
        Visible = False
        MajorRadius = 1.000000000000000000
        MinorRadius = 0.300000011920929000
        Rings = 64
        Sides = 32
        StopAngle = 360.000000000000000000
        Parts = [toSides, toStartDisk, toStopDisk]
      end
      object Sphere: TGLSphere
        Position.Coordinates = {000000C000000000000000000000803F}
        Up.Coordinates = {000080270000803F0000008000000000}
        Visible = False
        Radius = 0.699999988079071000
        Slices = 32
        Stacks = 32
      end
      object Sky: TGLSphere
        Visible = False
        NormalDirection = ndInside
        Radius = 0.500000000000000000
      end
    end
  end
  object Cadencer: TGLCadencer
    Scene = GLScene1
    Enabled = False
    SleepLength = 1
    Left = 80
    Top = 8
  end
end
