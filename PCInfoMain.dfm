object Main: TMain
  Left = 0
  Top = 0
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1089#1080#1089#1090#1077#1084#1077
  ClientHeight = 391
  ClientWidth = 584
  Color = clBtnFace
  Constraints.MinHeight = 430
  Constraints.MinWidth = 600
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 369
    Width = 584
    Height = 22
    Panels = <
      item
        Width = 300
      end
      item
        Width = 200
      end>
    ExplicitTop = 372
    ExplicitWidth = 494
  end
  object PanelMain: TPanel
    Left = 0
    Top = 0
    Width = 584
    Height = 369
    Align = alClient
    BevelOuter = bvNone
    Caption = 'PanelMain'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    Padding.Left = 8
    Padding.Top = 8
    Padding.Right = 8
    Padding.Bottom = 8
    ParentFont = False
    ShowCaption = False
    TabOrder = 1
    ExplicitLeft = 144
    ExplicitTop = 136
    ExplicitWidth = 185
    ExplicitHeight = 41
    object Memo: TMemo
      Left = 8
      Top = 8
      Width = 568
      Height = 353
      Align = alClient
      Lines.Strings = (
        'Memo')
      ReadOnly = True
      ScrollBars = ssBoth
      TabOrder = 0
      ExplicitWidth = 478
      ExplicitHeight = 356
    end
  end
end
