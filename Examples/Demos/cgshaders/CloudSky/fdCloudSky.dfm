object MainForm: TMainForm
  Left = 307
  Top = 542
  Caption = 'Sky Clouds'
  ClientHeight = 450
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 13
  object SceneViewer: TGLSceneViewer
    Left = 105
    Top = 0
    Width = 519
    Height = 450
    Camera = Camera
    FieldOfView = 136.397186279296900000
    PenAsTouch = False
    Align = alClient
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 105
    Height = 450
    Align = alLeft
    Alignment = taRightJustify
    TabOrder = 1
    ExplicitHeight = 425
    object Label1: TLabel
      Left = 3
      Top = 105
      Width = 45
      Height = 13
      Caption = 'N = Night'
    end
    object Label2: TLabel
      Left = 3
      Top = 48
      Width = 39
      Height = 13
      Caption = 'D = Day'
    end
    object Label3: TLabel
      Left = 2
      Top = 67
      Width = 66
      Height = 13
      Caption = 'C = Weather1'
    end
    object Label4: TLabel
      Left = 2
      Top = 86
      Width = 66
      Height = 13
      Caption = 'S = Weather2'
    end
    object Label5: TLabel
      Left = 16
      Top = 8
      Width = 26
      Height = 13
      Caption = 'Keys:'
    end
  end
  object GLScene: TGLScene
    Left = 120
    Top = 20
    object SkyBoxBkg: TGLSkyBox
      CloudsPlaneOffset = 0.200000002980232200
      CloudsPlaneSize = 32.000000000000000000
      object Moons: TGLDummyCube
        Position.Coordinates = {0000A0C1000020410000A0C10000803F}
        CubeSize = 1.000000000000000000
        object sprMasser: TGLSprite
          Width = 10.000000000000000000
          Height = 10.000000000000000000
          Rotation = 0.000000000000000000
        end
        object sprSecunda: TGLSprite
          Position.Coordinates = {00000000000000000000A0400000803F}
          Width = 5.000000000000000000
          Height = 5.000000000000000000
          Rotation = 0.000000000000000000
        end
      end
      object sprSun: TGLSprite
        Position.Coordinates = {000040C000004040000020C10000803F}
        Width = 5.000000000000000000
        Height = 5.000000000000000000
        Rotation = 0.000000000000000000
      end
    end
    object SkyBoxClouds: TGLSkyBox
      Position.Coordinates = {0000A0C1000020410000A0C10000803F}
      CloudsPlaneOffset = 0.200000002980232200
      CloudsPlaneSize = 32.000000000000000000
    end
    object dcCamera: TGLDummyCube
      CubeSize = 1.000000000000000000
      object Camera: TGLCamera
        DepthOfView = 500.000000000000000000
        FocalLength = 90.000000000000000000
        TargetObject = dcCamera
        Position.Coordinates = {0000204100000000000020410000803F}
      end
    end
  end
  object Cadencer: TGLCadencer
    Scene = GLScene
    OnProgress = CadencerProgress
    Left = 196
    Top = 20
  end
  object Timer: TGLAsyncTimer
    ThreadPriority = tpNormal
    Left = 120
    Top = 108
  end
  object MatLib: TGLMaterialLibrary
    Left = 196
    Top = 108
  end
  object CgBackground: TCgShader
    FragmentProgram.OnApply = CgBackgroundApplyFP
    FragmentProgram.OnUnApply = CgBackgroundUnApplyFP
    OnApplyFP = CgBackgroundApplyFP
    OnUnApplyFP = CgBackgroundUnApplyFP
    Left = 154
    Top = 244
  end
  object CgClouds: TCgShader
    VertexProgram.OnApply = CgCloudsApplyVP
    FragmentProgram.OnApply = CgCloudsApplyFP
    FragmentProgram.OnUnApply = CgCloudsUnApplyFP
    OnApplyVP = CgCloudsApplyVP
    OnApplyFP = CgCloudsApplyFP
    OnUnApplyFP = CgCloudsUnApplyFP
    Left = 258
    Top = 244
  end
  object CgMasser: TCgShader
    FragmentProgram.OnApply = CgMasserApplyFP
    FragmentProgram.OnUnApply = CgMasserUnApplyFP
    OnApplyFP = CgMasserApplyFP
    OnUnApplyFP = CgMasserUnApplyFP
    Left = 354
    Top = 244
  end
  object CgSecunda: TCgShader
    FragmentProgram.OnApply = CgSecundaApplyFP
    FragmentProgram.OnUnApply = CgSecundaUnApplyFP
    OnApplyFP = CgSecundaApplyFP
    OnUnApplyFP = CgSecundaUnApplyFP
    Left = 458
    Top = 244
  end
  object CgSun: TCgShader
    FragmentProgram.OnApply = CgSunApplyFP
    FragmentProgram.OnUnApply = CgSunUnApplyFP
    OnApplyFP = CgSunApplyFP
    OnUnApplyFP = CgSunUnApplyFP
    Left = 554
    Top = 244
  end
  object GLSimpleNavigation: TGLSimpleNavigation
    Form = Owner
    GLSceneViewer = SceneViewer
    FormCaption = 'Sky Clouds - %FPS'
    KeyCombinations = <
      item
        ShiftState = [ssLeft, ssRight]
        Action = snaZoom
      end
      item
        ShiftState = [ssLeft]
        Action = snaMoveAroundTarget
      end
      item
        ShiftState = [ssRight]
        Action = snaMoveAroundTarget
      end>
    Left = 160
    Top = 328
  end
end
