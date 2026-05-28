object FormTerraNavi: TFormTerraNavi
  Left = 0
  Top = 0
  Caption = 'Terrain navigation'
  ClientHeight = 761
  ClientWidth = 1084
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnDestroy = FormDestroy
  OnKeyPress = FormKeyPress
  TextHeight = 15
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 1084
    Height = 761
    Camera = GLCamera1
    Buffer.FogEnvironment.FogColor.Color = {0000803F0000803F0000803F0000803F}
    Buffer.FogEnvironment.FogStart = 400.000000000000000000
    Buffer.FogEnvironment.FogEnd = 800.000000000000000000
    Buffer.FogEnvironment.FogDistance = fdEyeRadial
    Buffer.BackgroundColor = clGray
    Buffer.FogEnable = True
    Buffer.Lighting = False
    FieldOfView = 165.027755737304700000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 0
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 80
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    TabOrder = 1
    Visible = False
    OnClick = CheckBox1Click
  end
  object GLScene1: TGLScene
    ObjectsSorting = osNone
    Left = 16
    Top = 16
    object GLDummyCube1: TGLDummyCube
      CubeSize = 1.000000000000000000
    end
    object GLDummyCube2: TGLDummyCube
      Position.Coordinates = {0000000000000041000000000000803F}
      CubeSize = 1.000000000000000000
      object GLCamera1: TGLCamera
        DepthOfView = 800.000000000000000000
        FocalLength = 50.000000000000000000
        TargetObject = GLDummyCube2
        Position.Coordinates = {0000A040000020410000C8410000803F}
      end
    end
    object GLLensFlare1: TGLLensFlare
      Size = 100
      Seed = 978
      FlareIsNotOccluded = True
      PreRenderPoint = GLRenderPoint1
      Position.Coordinates = {9A620252C9B28B51B743BAD10000803F}
      Visible = False
      object GLDummyCube3: TGLDummyCube
        CubeSize = 100.000000000000000000
        VisibleAtRunTime = True
      end
    end
    object GLRenderPoint1: TGLRenderPoint
    end
    object GLSkyDome1: TGLSkyDome
      Direction.Coordinates = {000000000000803F2EBD3BB300000000}
      Up.Coordinates = {000000802EBD3BB3000080BF00000000}
      Bands = <
        item
          StartColor.Color = {0000803F0000803F0000803F0000803F}
          StopAngle = 15.000000000000000000
        end
        item
          StartAngle = 15.000000000000000000
          StopAngle = 90.000000000000000000
          StopColor.Color = {938C0C3E938C0C3E938E0E3F0000803F}
          Stacks = 4
        end>
      Stars = <>
      Options = [sdoTwinkle]
      object moon: TGLSprite
        Material.FrontProperties.Ambient.Color = {0000000000000000000000000000803F}
        Material.FrontProperties.Diffuse.Color = {0000000000000000000000000000803F}
        Material.FrontProperties.Emission.Color = {0000803F0000803F0000803F0000803F}
        Material.BlendingMode = bmTransparency
        Material.Texture.ImageAlpha = tiaSuperBlackTransparent
        Material.Texture.TextureMode = tmReplace
        Material.Texture.Disabled = False
        Position.Coordinates = {00000C430000C842000096420000803F}
        Visible = False
        Width = 30.000000000000000000
        Height = 30.000000000000000000
        Rotation = 0.000000000000000000
      end
      object sun: TGLSprite
        Material.FrontProperties.Ambient.Color = {0000000000000000000000000000803F}
        Material.FrontProperties.Diffuse.Color = {0000000000000000000000000000803F}
        Material.BlendingMode = bmAdditive
        Material.Texture.TextureMode = tmReplace
        Material.Texture.Disabled = False
        Position.Coordinates = {00000C430000C842000096420000803F}
        Width = 60.000000000000000000
        Height = 60.000000000000000000
        Rotation = 0.000000000000000000
      end
    end
    object GLTerrainRenderer1: TGLTerrainRenderer
      Material.MaterialLibrary = GLMaterialLibrary1
      Material.LibMaterialName = 'ground'
      Direction.Coordinates = {000000000000803F0000000000000000}
      Scale.Coordinates = {00008040000080400000803E00000000}
      Up.Coordinates = {00000000000000000000803F00000000}
      HeightDataSource = GLBitmapHDS1
      TileSize = 32
      TilesPerTexture = 8.000000000000000000
      ContourWidth = 0
    end
    object GLSprite1: TGLSprite
      Material.BlendingMode = bmTransparency
      Material.Texture.ImageAlpha = tiaSuperBlackTransparent
      Material.Texture.TextureMode = tmReplace
      Material.Texture.Disabled = False
      Width = 70.000000000000000000
      Height = 75.000000000000000000
      Rotation = 0.000000000000000000
    end
    object GLDummyCube4: TGLDummyCube
      ObjectsSorting = osRenderFarthestFirst
      CubeSize = 1.000000000000000000
    end
    object GLTree1: TGLTree
      Direction.Coordinates = {000000000000803F2EBD3BB300000000}
      PitchAngle = 90.000000000000000000
      Scale.Coordinates = {00002041000020410000204100000000}
      Up.Coordinates = {000000002EBD3BB3000080BF00000000}
      Depth = 4
      BranchFacets = 50
      LeafSize = 0.600000023841857900
      BranchSize = 0.899999976158142100
      BranchNoise = 1.500000000000000000
      BranchAngleBias = 1.299999952316284000
      BranchAngle = 0.500000000000000000
      BranchTwist = 90.000000000000000000
      BranchRadius = 0.029999999329447750
      LeafThreshold = 0.019999999552965160
      CentralLeader = False
      Seed = 0
      AutoCenter = False
      AutoRebuild = True
      CenterBranchConstant = 0.899999976158142100
    end
    object GLFreeForm1: TGLFreeForm
      Material.BackProperties.Diffuse.Color = {0000000000000000000000000000803F}
      Material.FrontProperties.Diffuse.Color = {0000000000000000000000000000803F}
      Material.BlendingMode = bmTransparency
      Material.Texture.ImageAlpha = tiaOpaque
      Material.Texture.TextureMode = tmReplace
      Material.Texture.Disabled = False
      Direction.Coordinates = {000000000000803F2EBD3BB300000000}
      PitchAngle = 90.000000000000000000
      Scale.Coordinates = {00004041000040410000404100000000}
      Up.Coordinates = {000000002EBD3BB3000080BF00000000}
    end
    object GLHUDText1: TGLHUDText
      Position.Coordinates = {0000000000002041000000000000803F}
      BitmapFont = GLWindowsBitmapFont1
      Rotation = 0.000000000000000000
      ModulateColor.Color = {E4DB5B3FE4DB5B3FEBE0E03E0000803F}
    end
    object GLDirectOpenGL1: TGLDirectOpenGL
      UseBuildList = False
      OnRender = GLDirectOpenGL1Render
      Blend = False
    end
    object GLDirectOpenGL2: TGLDirectOpenGL
      Visible = False
      UseBuildList = False
      OnRender = GLDirectOpenGL2Render
      Blend = False
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 88
    Top = 16
  end
  object GLBitmapHDS1: TGLBitmapHDS
    MaxPoolSize = 0
    Left = 176
    Top = 16
  end
  object GLSoundLibrary1: TGLSoundLibrary
    Samples = <>
    Left = 272
    Top = 16
  end
  object GLSMBASS1: TGLSMBASS
    Active = True
    MaxChannels = 32
    MasterVolume = 1.000000000000000000
    Listener = GLCamera1
    Sources = <>
    Cadencer = GLCadencer1
    Environment = seForest
    Algorithm3D = algFull
    Left = 360
    Top = 16
    Doppler = 0.000000000000000000
  end
  object GLMaterialLibrary1: TGLMaterialLibrary
    Materials = <
      item
        Name = 'ground'
        Tag = 0
        Material.FrontProperties.Emission.Color = {9B9A9A3E9B9A9A3E9B9A9A3E0000803F}
        Material.Texture.TextureMode = tmReplace
        Material.Texture.Disabled = False
        Texture2Name = 'details'
      end
      item
        Name = 'details'
        Tag = 0
        Material.Texture.TextureMode = tmModulate
        Material.Texture.Disabled = False
        TextureScale.Coordinates = {00000043000000430000004300000000}
      end>
    Left = 600
    Top = 16
  end
  object Timer1: TTimer
    Interval = 3000
    OnTimer = Timer1Timer
    Left = 680
    Top = 16
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 728
    Top = 16
  end
  object GLWindowsBitmapFont1: TGLWindowsBitmapFont
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clOlive
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 472
    Top = 16
  end
end
