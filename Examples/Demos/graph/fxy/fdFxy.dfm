object FormFxy: TFormFxy
  Left = 179
  Top = 106
  BorderWidth = 4
  Caption = 'Fxy'
  ClientHeight = 610
  ClientWidth = 890
  Color = clBtnFace
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Position = poScreenCenter
  OnMouseWheel = FormMouseWheel
  TextHeight = 13
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 675
    Height = 610
    Camera = GLCamera1
    Buffer.BackgroundColor = clCream
    FieldOfView = 135.428817749023400000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 0
    ExplicitWidth = 593
  end
  object Panel1: TPanel
    Left = 675
    Top = 0
    Width = 215
    Height = 610
    Align = alRight
    TabOrder = 1
    ExplicitLeft = 584
    ExplicitHeight = 585
    object Label2: TLabel
      Left = 46
      Top = 5
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object Label3: TLabel
      Left = 101
      Top = 5
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object Label4: TLabel
      Left = 150
      Top = 5
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object TBXYPosition: TTrackBar
      Left = 138
      Top = 24
      Width = 45
      Height = 193
      Min = -10
      Orientation = trVertical
      TabOrder = 0
      TickMarks = tmBoth
      OnChange = TBXYPositionChange
    end
    object TBYZPosition: TTrackBar
      Left = 36
      Top = 24
      Width = 45
      Height = 193
      Min = -10
      Orientation = trVertical
      TabOrder = 1
      TickMarks = tmBoth
      OnChange = TBYZPositionChange
    end
    object TBXZPosition: TTrackBar
      Left = 87
      Top = 24
      Width = 45
      Height = 193
      Min = -10
      Orientation = trVertical
      TabOrder = 2
      TickMarks = tmBoth
      OnChange = TBXZPositionChange
    end
    object rgFormula: TRadioGroup
      Left = -2
      Top = 215
      Width = 211
      Height = 105
      Caption = 'Formula'
      ItemIndex = 2
      Items.Strings = (
        'x*y'
        'x*y*z'
        'sin(z*12)/(2*(z*6.28+1))'
        '(pow(x,2)+pow(y,2))*sin(8*atan2(x,y))')
      TabOrder = 3
      OnClick = rgFormulaClick
    end
    object rgPolygonMode: TRadioGroup
      Left = 6
      Top = 326
      Width = 203
      Height = 83
      Caption = 'Mode'
      ItemIndex = 0
      Items.Strings = (
        'pmFill'
        'pmLines'
        'pmPoints')
      TabOrder = 4
      OnClick = rgPolygonModeClick
    end
    object CBCentered: TCheckBox
      Left = 40
      Top = 422
      Width = 97
      Height = 17
      Caption = 'Centered grids'
      TabOrder = 5
      OnClick = CBCenteredClick
    end
  end
  object GLScene1: TGLScene
    Left = 24
    Top = 24
    object GLLightSource1: TGLLightSource
      ConstAttenuation = 1.000000000000000000
      Position.Coordinates = {0000F041000048420000C8420000803F}
      SpotCutOff = 180.000000000000000000
    end
    object GLCamera1: TGLCamera
      DepthOfView = 1000.000000000000000000
      FocalLength = 125.000000000000000000
      TargetObject = HeightField
      Position.Coordinates = {0000404000008040000080400000803F}
      Left = 208
      Top = 168
    end
    object HeightField: TGLHeightField
      Material.BlendingMode = bmTransparency
      Direction.Coordinates = {0044F4970000803F2EBD3BB300000000}
      ShowAxes = True
      Up.Coordinates = {0000803F583DAF262EBD3B3300000000}
      XSamplingScale.Min = -1.000000000000000000
      XSamplingScale.Max = 1.000000000000000000
      XSamplingScale.Step = 0.009999999776482582
      YSamplingScale.Min = -1.000000000000000000
      YSamplingScale.Max = 1.000000000000000000
      YSamplingScale.Step = 0.009999999776482582
      object YZGrid: TGLXYZGrid
        LineColor.Color = {0000803F00000000000000000000803F}
        XSamplingScale.Min = -1.000000000000000000
        XSamplingScale.Max = 1.000000000000000000
        XSamplingScale.Origin = -1.000000000000000000
        XSamplingScale.Step = 0.100000001490116100
        YSamplingScale.Min = -1.000000000000000000
        YSamplingScale.Max = 1.000000000000000000
        YSamplingScale.Origin = -1.000000000000000000
        YSamplingScale.Step = 0.100000001490116100
        ZSamplingScale.Min = -1.000000000000000000
        ZSamplingScale.Max = 1.000000000000000000
        ZSamplingScale.Origin = -1.000000000000000000
        ZSamplingScale.Step = 0.100000001490116100
        Parts = [gpY, gpZ]
      end
      object XZGrid: TGLXYZGrid
        LineColor.Color = {000000000000803F000000000000803F}
        XSamplingScale.Min = -1.000000000000000000
        XSamplingScale.Max = 1.000000000000000000
        XSamplingScale.Origin = -1.000000000000000000
        XSamplingScale.Step = 0.100000001490116100
        YSamplingScale.Min = -1.000000000000000000
        YSamplingScale.Max = 1.000000000000000000
        YSamplingScale.Origin = -1.000000000000000000
        YSamplingScale.Step = 0.100000001490116100
        ZSamplingScale.Min = -1.000000000000000000
        ZSamplingScale.Max = 1.000000000000000000
        ZSamplingScale.Origin = -1.000000000000000000
        ZSamplingScale.Step = 0.100000001490116100
        Parts = [gpX, gpZ]
      end
      object XYGrid: TGLXYZGrid
        LineColor.Color = {00000000000000000000803F0000803F}
        XSamplingScale.Min = -1.000000000000000000
        XSamplingScale.Max = 1.000000000000000000
        XSamplingScale.Origin = -1.000000000000000000
        XSamplingScale.Step = 0.100000001490116100
        YSamplingScale.Min = -1.000000000000000000
        YSamplingScale.Max = 1.000000000000000000
        YSamplingScale.Origin = -1.000000000000000000
        YSamplingScale.Step = 0.100000001490116100
        ZSamplingScale.Min = -1.000000000000000000
        ZSamplingScale.Max = 1.000000000000000000
        ZSamplingScale.Origin = -1.000000000000000000
        ZSamplingScale.Step = 0.100000001490116100
      end
    end
  end
  object GLAsyncTimer1: TGLAsyncTimer
    OnTimer = GLAsyncTimer1Timer
    Left = 125
    Top = 21
  end
end
