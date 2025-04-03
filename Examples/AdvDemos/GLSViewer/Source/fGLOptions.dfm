inherited FormOptions: TFormOptions
  HelpContext = 0
  Caption = 'Options'
  ClientHeight = 313
  ClientWidth = 460
  Font.Height = -21
  StyleElements = [seFont, seClient, seBorder]
  OnClose = FormClose
  ExplicitWidth = 476
  ExplicitHeight = 352
  TextHeight = 30
  object CheckBoxAxis: TCheckBox
    Left = 80
    Top = 132
    Width = 183
    Height = 29
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = 'Axis'
    TabOrder = 0
    OnClick = CheckBoxAxisClick
  end
  object PanelBackground: TPanel
    Left = 310
    Top = 126
    Width = 57
    Height = 40
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Color = clBlack
    ParentBackground = False
    TabOrder = 1
    OnClick = PanelBackgroundClick
  end
  object ButtonOk: TButton
    Left = 318
    Top = 278
    Width = 75
    Height = 25
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = 'Ok'
    TabOrder = 2
    OnClick = ButtonOKClick
  end
end
