object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 513
  ClientWidth = 762
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
    Width = 762
    Height = 402
    Proportional = True
    Stretch = True
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Panel1: TPanel
    Left = 0
    Top = 432
    Width = 329
    Height = 41
    TabOrder = 0
    object Button1: TButton
      Left = 89
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Rotate Left'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Rotate Right'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 168
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Scale'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 249
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Crop'
      TabOrder = 3
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 494
    Width = 762
    Height = 19
    Panels = <>
    ExplicitTop = 493
    ExplicitWidth = 758
  end
  object MainMenu1: TMainMenu
    Left = 656
    Top = 448
    object Fil1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Open2: TMenuItem
        Caption = 'Save'
        OnClick = Open2Click
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
    Left = 712
    Top = 448
  end
  object SaveDialog1: TSaveDialog
    Filter = 'JPG files (*.jpg)|*.jpg|All files (*.*)|*.*'
    Left = 592
    Top = 448
  end
end
