object FormFire2d_GR32: TFormFire2d_GR32
  Left = 89
  Top = 65
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'Fire 2D'
  ClientHeight = 413
  ClientWidth = 734
  Color = clBtnFace
  Constraints.MinHeight = 246
  Constraints.MinWidth = 256
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  TextHeight = 13
  object Label5: TLabel
    Left = 0
    Top = 0
    Width = 734
    Height = 19
    Align = alTop
    Caption = 'Dynamic Texture'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 128
  end
  object GLSceneViewer1: TGLSceneViewer
    Left = 328
    Top = 8
    Width = 392
    Height = 392
    Camera = GLCamera1
    Buffer.BackgroundColor = 3881787
    Buffer.Lighting = False
    FieldOfView = 125.938278198242200000
    PenAsTouch = False
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    OnMouseUp = GLSceneViewer1MouseUp
    TabOrder = 0
  end
  object PaintBox32: TPaintBox32
    Left = 0
    Top = 136
    Width = 322
    Height = 264
    TabOrder = 1
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    OnMouseUp = GLSceneViewer1MouseUp
  end
  object Memo1: TMemo
    Left = 0
    Top = 25
    Width = 256
    Height = 105
    Lines.Strings = (
      'The 2D fire animation below is a pure 2D '
      'animated'
      'texture using Graphics32 '
      '(www.graphics32.org)'
      'It is refreshed every 40 ms and used to '
      'update'
      'the cube'#39's texture you see on the right.')
    TabOrder = 2
  end
  object AsyncTimer1: TGLAsyncTimer
    Interval = 80
    OnTimer = AsyncTimer1Timer
    Left = 40
    Top = 144
  end
  object GLScene1: TGLScene
    Left = 296
    Top = 16
    object Cube1: TGLCube
      Material.Texture.MinFilter = miLinear
      Material.Texture.TextureMode = tmReplace
      Material.Texture.Compression = tcNone
      Material.MaterialLibrary = GLMaterialLibrary1
    end
    object GLCamera1: TGLCamera
      DepthOfView = 100.000000000000000000
      FocalLength = 100.000000000000000000
      SceneScale = 1.500000000000000000
      TargetObject = Cube1
      Position.Coordinates = {0000804000000000000000400000803F}
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 136
    Top = 144
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 384
    Top = 16
  end
  object GLMaterialLibrary1: TGLMaterialLibrary
    Materials = <
      item
        Name = 'LibMaterial'
        Tag = 0
        Material.Texture.ImageClassName = 'TGLPicFileImage'
        Material.MaterialLibrary = GLMaterialLibrary1
      end>
    Left = 488
    Top = 16
  end
end
