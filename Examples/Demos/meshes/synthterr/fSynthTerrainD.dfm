object FormSynthTerrain: TFormSynthTerrain
  Left = 159
  Top = 120
  Margins.Left = 5
  Margins.Top = 5
  Margins.Right = 5
  Margins.Bottom = 5
  Caption = 'Synthetic Terrain'
  ClientHeight = 793
  ClientWidth = 1335
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 168
  TextHeight = 24
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 1335
    Height = 793
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Camera = GLCamera1
    VSync = vsmSync
    Buffer.FogEnvironment.FogColor.Color = {0000803F0000803F0000803F0000803F}
    Buffer.FogEnvironment.FogStart = 400.000000000000000000
    Buffer.FogEnvironment.FogEnd = 1200.000000000000000000
    Buffer.FogEnvironment.FogDistance = fdEyeRadial
    Buffer.BackgroundColor = clBlack
    Buffer.FogEnable = True
    Buffer.Lighting = False
    FieldOfView = 165.625488281250000000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 0
  end
  object GLScene1: TGLScene
    ObjectsSorting = osNone
    Left = 40
    Top = 24
    object DummyCube1: TGLDummyCube
      Position.Coordinates = {0000000000000041000000000000803F}
      CubeSize = 1.000000000000000000
      object GLCamera1: TGLCamera
        DepthOfView = 1200.000000000000000000
        FocalLength = 50.000000000000000000
        TargetObject = DummyCube1
        Position.Coordinates = {0000A040000020410000C8410000803F}
        Left = 264
        Top = 160
      end
    end
    object TerrainRenderer1: TGLTerrainRenderer
      Material.FrontProperties.Emission.Color = {0000803F0000803F0000803F0000803F}
      Direction.Coordinates = {000000000000803F0000000000000000}
      Scale.Coordinates = {00008040000080400000003F00000000}
      Up.Coordinates = {00000000000000000000803F00000000}
      HeightDataSource = GLCustomHDS
      TileSize = 32
      TilesPerTexture = 1.000000000000000000
      QualityDistance = 50.000000000000000000
      CLODPrecision = 20
      ContourWidth = 0
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 256
    Top = 24
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 152
    Top = 24
  end
  object GLMaterialLibrary1: TGLMaterialLibrary
    Left = 40
    Top = 88
  end
  object GLCustomHDS: TGLCustomHDS
    MaxPoolSize = 0
    OnStartPreparingData = GLCustomHDSStartPreparingData
    Left = 152
    Top = 88
  end
  object GLShadowHDS: TGLShadowHDS
    MaxPoolSize = 0
    Active = True
    ShadowmapLibrary = GLMaterialLibrary1
    ScanDistance = 64
    SoftRange = 1
    Diffuse = 0.750000000000000000
    Ambient = 0.250000000000000000
    MaxTextures = 0
    Left = 256
    Top = 88
  end
end
