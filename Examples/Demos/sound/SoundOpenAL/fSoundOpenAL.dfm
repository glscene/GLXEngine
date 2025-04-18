object Form1: TForm1
  Left = 209
  Top = 92
  Margins.Left = 5
  Margins.Top = 5
  Margins.Right = 5
  Margins.Bottom = 5
  Caption = 'Sound OpenAL'
  ClientHeight = 712
  ClientWidth = 1131
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OnCreate = FormCreate
  PixelsPerInch = 168
  TextHeight = 24
  object GLSceneViewer: TGLSceneViewer
    Left = 0
    Top = 116
    Width = 1131
    Height = 549
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Camera = GLCamera1
    Buffer.BackgroundColor = clBlack
    Buffer.AntiAliasing = aaNone
    FieldOfView = 159.353576660156300000
    PenAsTouch = False
    Align = alClient
    TabOrder = 0
  end
  object TrackBar: TTrackBar
    Left = 0
    Top = 665
    Width = 1131
    Height = 47
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alBottom
    Max = 180
    Min = -180
    PageSize = 45
    Frequency = 45
    TabOrder = 1
    ThumbLength = 18
    TickMarks = tmBoth
    OnChange = TrackBarChange
  end
  object TrackBar1: TTrackBar
    Left = 0
    Top = 58
    Width = 1131
    Height = 58
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alTop
    Max = 50
    Min = -50
    PageSize = 45
    Frequency = 10
    TabOrder = 2
    ThumbLength = 18
    TickMarks = tmBoth
    OnChange = TrackBar1Change
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1131
    Height = 58
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    DesignSize = (
      1131
      58)
    object LabelFPS: TLabel
      Left = 14
      Top = 25
      Width = 36
      Height = 24
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Caption = 'FPS'
    end
    object btnChimes: TButton
      Left = 957
      Top = 5
      Width = 146
      Height = 44
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Anchors = [akTop, akRight]
      Caption = 'Chimes (WAV)'
      TabOrder = 0
      OnClick = btnChimesClick
    end
    object btnHowl: TButton
      Left = 802
      Top = 5
      Width = 145
      Height = 44
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Anchors = [akTop, akRight]
      Caption = 'Howl (MP3)'
      TabOrder = 1
      OnClick = btnHowlClick
    end
  end
  object GLSMOpenAL: TGLSMOpenAL
    Active = True
    MaxChannels = 32
    MasterVolume = 1.000000000000000000
    Listener = Mickey
    Sources = <>
    Cadencer = GLCadencer1
    Environment = seAuditorium
    Left = 280
    Top = 72
  end
  object GLSoundLibrary: TGLSoundLibrary
    Samples = <>
    Left = 192
    Top = 72
  end
  object GLScene: TGLScene
    Left = 24
    Top = 72
    object DummyCube: TGLDummyCube
      CubeSize = 1.000000000000000000
      object Torus1: TGLTorus
        Material.FrontProperties.Diffuse.Color = {00000000000000000000803F0000803F}
        Material.FrontProperties.Emission.Color = {000000008180803E8180003F0000803F}
        Direction.Coordinates = {000000000000803F2EBD3BB300000000}
        Position.Coordinates = {00000000000000BF000000000000803F}
        Scale.Coordinates = {0000803F0000803F0000003F00000000}
        Up.Coordinates = {000000002EBD3BB3000080BF00000000}
        MajorRadius = 5.000000000000000000
        MinorRadius = 0.100000001490116100
        Rings = 16
        Sides = 3
        StopAngle = 360.000000000000000000
        Parts = [toSides, toStartDisk, toStopDisk]
      end
      object Mickey: TGLSphere
        Position.Coordinates = {000000000000003F000000000000803F}
        Radius = 0.500000000000000000
        Slices = 9
        Stacks = 9
        BehavioursData = {
          0458434F4C02010201061054474C42536F756E64456D69747465720200060D53
          6F756E6420456D69747465720200020002000200050000000000000080FF3F05
          0000000000000080FF3F0500000000000000C805400500000000000000B40740
          0500000000000000B407400500000000000000000000060E474C536F756E644C
          69627261727912000000000808020109}
        object Sphere2: TGLSphere
          Position.Coordinates = {CDCCCC3ECDCC4C3E000000000000803F}
          Radius = 0.300000011920929000
          Slices = 6
          Stacks = 6
        end
        object Sphere3: TGLSphere
          Position.Coordinates = {CDCCCCBECDCC4C3E000000000000803F}
          Radius = 0.300000011920929000
          Slices = 6
          Stacks = 6
        end
        object Cone1: TGLCone
          Direction.Coordinates = {2EF964BF2EF9E43E0000000000000000}
          Position.Coordinates = {00000000000000000000003F0000803F}
          Up.Coordinates = {00000000000000000000803F00000000}
          BottomRadius = 0.300000011920929000
          Height = 0.500000000000000000
          Slices = 8
          Stacks = 2
          Parts = [coSides]
        end
      end
      object Plane1: TGLPlane
        Direction.Coordinates = {000000000000803F2EBD3BB300000000}
        Position.Coordinates = {00000000000000BF000000000000803F}
        Up.Coordinates = {000000002EBD3BB3000080BF00000000}
        Height = 10.000000000000000000
        Width = 0.500000000000000000
      end
    end
    object SphereSound: TGLSphere
      Material.FrontProperties.Diffuse.Color = {0000803F00000000000000000000803F}
      Material.FrontProperties.Emission.Color = {8180003F00000000000000000000803F}
      Position.Coordinates = {000000400000003F000000000000803F}
      OnProgress = SphereSoundProgress
      Radius = 0.500000000000000000
      Slices = 9
      Stacks = 9
      BehavioursData = {
        0458434F4C02010201061054474C42536F756E64456D69747465720200120000
        00000200020002000200050000000000000080FF3F050000000000000080FF3F
        0500000000000000C805400500000000000000B407400500000000000000B407
        400500000000000000000000060E474C536F756E644C696272617279060C6472
        756D6C6F6F702E7761760808020309}
      object Disk1: TGLDisk
        Direction.Coordinates = {000000000000803F2EBD3BB300000000}
        Position.Coordinates = {00000000000080BF000000000000803F}
        Up.Coordinates = {000000002EBD3BB3000080BF00000000}
        OuterRadius = 0.500000000000000000
        Slices = 12
        SweepAngle = 360.000000000000000000
      end
    end
    object GLLightSource: TGLLightSource
      ConstAttenuation = 1.000000000000000000
      Position.Coordinates = {0000204100002041000020410000803F}
      SpotCutOff = 180.000000000000000000
    end
    object GLCamera1: TGLCamera
      DepthOfView = 100.000000000000000000
      FocalLength = 50.000000000000000000
      TargetObject = Plane1
      Position.Coordinates = {000000400000A040000020410000803F}
      Left = 256
      Top = 160
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene
    SleepLength = 1
    Left = 96
    Top = 72
  end
  object Timer: TTimer
    OnTimer = TimerTimer
    Left = 486
    Top = 80
  end
end
