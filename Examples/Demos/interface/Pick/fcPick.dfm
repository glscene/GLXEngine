object FormPick: TFormPick
  Left = 0
  Top = 0
  Caption = 'Pick'
  ClientHeight = 354
  ClientWidth = 498
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 13
  object glsViewer: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 498
    Height = 354
    Camera = GLCamera1
    Buffer.BackgroundColor = clBlack
    FieldOfView = 148.451522827148400000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = glsViewerMouseDown
    OnMouseMove = glsViewerMouseMove
    TabOrder = 0
    ExplicitWidth = 412
    ExplicitHeight = 275
  end
  object GLScene1: TGLScene
    Left = 32
    Top = 8
    object DummyCube1: TGLDummyCube
      Position.Coordinates = {000000000000803F000000000000803F}
      CubeSize = 1.000000000000000000
    end
    object GLLightSource1: TGLLightSource
      ConstAttenuation = 1.000000000000000000
      Position.Coordinates = {000048420000C842000048420000803F}
      SpotCutOff = 180.000000000000000000
    end
    object Sphere: TGLSphere
      Position.Coordinates = {00000040000080BE000000000000803F}
      Radius = 1.000000000000000000
    end
    object Cylinder: TGLCylinder
      Position.Coordinates = {000000C0000080BE000000000000803F}
      BottomRadius = 1.000000000000000000
      Height = 1.500000000000000000
      TopRadius = 1.000000000000000000
    end
    object Torus: TGLTorus
      Direction.Coordinates = {F604B5BEF304353F70C41C3F00000000}
      Position.Coordinates = {000000C0CDCC0C40000000000000803F}
      Up.Coordinates = {F604B53EF304353F70C41CBF00000000}
      MajorRadius = 0.699999988079071000
      MinorRadius = 0.200000002980232200
      StopAngle = 360.000000000000000000
      Parts = [toSides, toStartDisk, toStopDisk]
    end
    object Cone: TGLCone
      Direction.Coordinates = {00000000F28384BEEA46773F00000000}
      Position.Coordinates = {0000004000002040000000000000803F}
      Up.Coordinates = {00000000EA46773FF283843E00000000}
      BottomRadius = 1.000000000000000000
      Height = 1.500000000000000000
    end
    object GLCamera1: TGLCamera
      DepthOfView = 100.000000000000000000
      FocalLength = 50.000000000000000000
      TargetObject = DummyCube1
      Position.Coordinates = {0000000000008040000020410000803F}
    end
  end
end
