object FormHierarchy: TFormHierarchy
  Left = 204
  Top = 101
  Caption = 'Hierarchy'
  ClientHeight = 763
  ClientWidth = 1221
  Color = clBtnFace
  Constraints.MinHeight = 200
  Constraints.MinWidth = 320
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnResize = FormResize
  DesignSize = (
    1221
    763)
  TextHeight = 13
  object SceneViewer: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 1221
    Height = 763
    Camera = Camera
    Buffer.BackgroundColor = clBlack
    FieldOfView = 150.623794555664100000
    PenAsTouch = False
    Align = alClient
    TabOrder = 0
  end
  object CBPlay: TCheckBox
    Left = 587
    Top = 31
    Width = 42
    Height = 16
    Anchors = [akLeft, akBottom]
    Caption = 'Play'
    TabOrder = 1
    ExplicitTop = 6
  end
  object GLScene1: TGLScene
    Left = 80
    Top = 24
    object Camera: TGLCamera
      DepthOfView = 100.000000000000000000
      FocalLength = 100.000000000000000000
      TargetObject = dcSun
      Position.Coordinates = {000020410000A040000020410000803F}
      object LightSource: TGLLightSource
        ConstAttenuation = 1.000000000000000000
        SpotCutOff = 180.000000000000000000
      end
    end
    object dcSun: TGLDummyCube
      CubeSize = 1.000000000000000000
      object diskEcliptic: TGLDisk
        Material.BackProperties.Ambient.Color = {00000000000000000000000000000000}
        Material.BackProperties.Diffuse.Color = {00000000000000000000000000000000}
        Material.BackProperties.Emission.Color = {00000000000000000000000000000000}
        Material.BackProperties.Specular.Color = {00000000000000000000000000000000}
        Material.FrontProperties.Ambient.Color = {000000000000003F000000000000803F}
        Material.FrontProperties.Diffuse.Color = {CDCC4C3E0000803FCDCC4C3E9A99993E}
        Material.BlendingMode = bmTransparency
        Material.FaceCulling = fcCull
        Direction.Coordinates = {000000000000803F2EBD3BB300000000}
        PitchAngle = 90.000000000000000000
        Up.Coordinates = {000000002EBD3BB3000080BF00000000}
        InnerRadius = 2.000000000000000000
        Loops = 1
        OuterRadius = 5.000000000000000000
        Slices = 64
        SweepAngle = 360.000000000000000000
      end
      object sfSun: TGLSphere
        Material.FrontProperties.Ambient.Color = {0000000000000000000000000000803F}
        Material.FrontProperties.Emission.Color = {0000803F0000803F000000000000803F}
        ShowAxes = True
        Radius = 0.500000000000000000
        Slices = 16
        Stacks = 16
      end
    end
    object dcEarth: TGLDummyCube
      CubeSize = 2.000000000000000000
      object sfEarth: TGLSphere
        Material.FrontProperties.Diffuse.Color = {0000003F0000003F0000803F0000803F}
        Material.FrontProperties.Emission.Color = {0000000000000000AE47213F0000803F}
        Position.Coordinates = {0000404000000000000000000000803F}
        Radius = 0.300000011920929000
        Slices = 16
        Stacks = 16
        object dcMoon: TGLDummyCube
          Direction.Coordinates = {00000000F304353FF304353F00000000}
          Up.Coordinates = {00000000F304353FF30435BF00000000}
          CubeSize = 1.000000000000000000
          object sfMoon: TGLSphere
            Material.BackProperties.Ambient.Color = {B1A8283FB1A8283FB1A8283F0000803F}
            Material.BackProperties.Diffuse.Color = {B1A8283FB1A8283FB1A8283F0000803F}
            Material.BackProperties.Emission.Color = {B1A8283FB1A8283FB1A8283F0000803F}
            Material.BackProperties.Specular.Color = {B1A8283FB1A8283FB1A8283F0000803F}
            Position.Coordinates = {0000803F00000000000000000000803F}
            Radius = 0.100000001490116100
            Slices = 16
            Stacks = 16
          end
        end
      end
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 68
    Top = 94
  end
  object GLSimpleNavigation1: TGLSimpleNavigation
    Form = Owner
    GLSceneViewer = SceneViewer
    FormCaption = 'Hierarchy - %FPS'
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
    Left = 176
    Top = 90
  end
  object GLMaterialLibrary1: TGLMaterialLibrary
    Materials = <
      item
        Name = 'Sun'
        Tag = 0
      end
      item
        Name = 'Earth'
        Tag = 0
      end
      item
        Name = 'Moon'
        Tag = 0
        Material.BackProperties.Ambient.Color = {B1A8283FB1A8283FB1A8283F0000803F}
        Material.BackProperties.Diffuse.Color = {B1A8283FB1A8283FB1A8283F0000803F}
        Material.BackProperties.Emission.Color = {B1A8283FB1A8283FB1A8283F0000803F}
        Material.BackProperties.Specular.Color = {B1A8283FB1A8283FB1A8283F0000803F}
      end>
    Left = 176
    Top = 24
  end
end
