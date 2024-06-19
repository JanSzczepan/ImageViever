object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 815
  ClientWidth = 1125
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 1117
    Height = 768
    Proportional = True
    Stretch = True
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Panel1: TPanel
    Left = 0
    Top = 766
    Width = 1110
    Height = 41
    TabOrder = 0
    object Button1: TButton
      Left = 6
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Rotate Left'
      TabOrder = 0
      OnClick = RotateImageLeft
    end
    object Button2: TButton
      Left = 87
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Rotate Right'
      TabOrder = 1
      OnClick = RotateImageRight
    end
    object Button4: TButton
      Left = 168
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Crop'
      TabOrder = 2
      OnClick = ButtonCropClick
    end
    object ButtonScaleUp: TButton
      Left = 249
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Scale Up'
      TabOrder = 3
      OnClick = ScaleImageUp
    end
    object ButtonScaleDown: TButton
      Left = 330
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Scale Down'
      TabOrder = 4
      OnClick = ScaleImageDown
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 796
    Width = 1125
    Height = 19
    Panels = <>
    ExplicitTop = 493
    ExplicitWidth = 758
  end
  object MainMenu1: TMainMenu
    Left = 696
    Top = 224
    object Fil1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = OpenImage
      end
      object Open2: TMenuItem
        Caption = 'Save'
        OnClick = SaveImage
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
    end
    object N1: TMenuItem
      Caption = 'Image'
      object Image2: TMenuItem
        Caption = 'Rotate Left'
      end
      object Rotateright1: TMenuItem
        Caption = 'Rotate Right'
      end
      object Rotateright2: TMenuItem
        Caption = 'Scale'
      end
      object Crop1: TMenuItem
        Caption = 'Crop'
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'JPG files (*.jpg)|*.jpg|All files (*.*)|*.*'
    Left = 752
    Top = 224
  end
  object SaveDialog1: TSaveDialog
    Filter = 'JPG files (*.jpg)|*.jpg|All files (*.*)|*.*'
    Left = 632
    Top = 224
  end
end
