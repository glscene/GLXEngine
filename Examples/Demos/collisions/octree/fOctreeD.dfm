object FormOctreedemo: TFormOctreedemo
  Left = 175
  Top = 104
  Caption = 'Octree Demo'
  ClientHeight = 436
  ClientWidth = 615
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 13
  object GLSceneViewer2: TGLSceneViewer
    Left = 0
    Top = 49
    Width = 615
    Height = 387
    Camera = GLCamera2
    Buffer.BackgroundColor = clBlack
    Buffer.ShadeModel = smSmooth
    FieldOfView = 151.023590087890600000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer2MouseDown
    OnMouseMove = GLSceneViewer2MouseMove
    TabOrder = 0
    ExplicitWidth = 554
    ExplicitHeight = 337
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 615
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 546
    object Label1: TLabel
      Left = 312
      Top = 1
      Width = 32
      Height = 13
      Caption = 'Label1'
    end
    object Label2: TLabel
      Left = 312
      Top = 16
      Width = 32
      Height = 13
      Caption = 'Label2'
    end
    object Label3: TLabel
      Left = 311
      Top = 30
      Width = 32
      Height = 13
      Caption = 'Label3'
    end
    object Label5: TLabel
      Left = 8
      Top = 8
      Width = 32
      Height = 13
      Caption = 'Label5'
    end
    object LABuild: TLabel
      Left = 8
      Top = 24
      Width = 36
      Height = 13
      Caption = 'LABuild'
    end
    object Label4: TLabel
      Left = 168
      Top = 32
      Width = 32
      Height = 13
      Caption = 'Label4'
    end
    object LabelFPS: TLabel
      Left = 472
      Top = 16
      Width = 20
      Height = 13
      Caption = 'FPS'
    end
    object CheckBox1: TCheckBox
      Left = 168
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Auto collide'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object CBOctree: TCheckBox
      Left = 168
      Top = 0
      Width = 97
      Height = 17
      Caption = 'Octree enabled'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
  end
  object GLScene1: TGLScene
    Left = 112
    Top = 80
    object GLLightSource1: TGLLightSource
      Ambient.Color = {000000001283003F0000803F0000803F}
      ConstAttenuation = 1.000000000000000000
      Position.Coordinates = {00004842000016430000C8420000803F}
      LightStyle = lsOmni
      Specular.Color = {0000803F00000000000000000000803F}
      SpotCutOff = 180.000000000000000000
    end
    object DummyCube1: TGLDummyCube
      CubeSize = 1.000000000000000000
      object FreeForm1: TGLFreeForm
        Direction.Coordinates = {000000000000803F0000000000000000}
        Scale.Coordinates = {CDCCCC3DCDCCCC3DCDCCCC3D00000000}
        Up.Coordinates = {00000000000000000000803F00000000}
      end
    end
    object Sphere1: TGLSphere
      Material.FrontProperties.Emission.Color = {0000803F0000803F000000000000803F}
      Direction.Coordinates = {000000000000803F0000000000000000}
      Up.Coordinates = {E9DC72BF000000009BE8A13E00000000}
      Radius = 0.300000011920929000
      Slices = 6
      Stacks = 6
      object ArrowLine1: TGLArrowLine
        Material.FrontProperties.Diffuse.Color = {CDCC4C3FCDCC4C3FCDCC4C3F9A99193F}
        Material.FrontProperties.Emission.Color = {1283803E1283803E000000000000803F}
        Material.BlendingMode = bmTransparency
        Position.Coordinates = {0000000000000000CDCCCC3D0000803F}
        BottomRadius = 0.050000000745058060
        Height = 1.000000000000000000
        TopRadius = 0.100000001490116100
        TopArrowHeadHeight = 0.500000000000000000
        TopArrowHeadRadius = 0.200000002980232200
        BottomArrowHeadHeight = 0.500000000000000000
        BottomArrowHeadRadius = 0.200000002980232200
      end
    end
    object GLCamera2: TGLCamera
      DepthOfView = 100.000000000000000000
      FocalLength = 50.000000000000000000
      TargetObject = DummyCube1
      Position.Coordinates = {0000A040000010C10000A0410000803F}
      Direction.Coordinates = {00000000000000000000803F00000000}
      Up.Coordinates = {67C57BBF3B5B393E0000000000000000}
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 16
    Top = 80
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
    Left = 64
    Top = 80
  end
end
