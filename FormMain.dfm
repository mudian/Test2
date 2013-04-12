object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'frmMain'
  ClientHeight = 401
  ClientWidth = 643
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 643
    Height = 33
    Align = alTop
    BorderWidth = 5
    TabOrder = 0
    object Label1: TLabel
      Left = 6
      Top = 6
      Width = 51
      Height = 21
      Align = alLeft
      Caption = #53685#49888' '#49444#51221
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object btnConnect: TSpeedButton
      Left = 566
      Top = 6
      Width = 73
      Height = 21
      Align = alLeft
      Caption = 'Disconnect'
      OnClick = btnConnectClick
      ExplicitLeft = 552
      ExplicitHeight = 22
    end
    object cbxPort: TComboBox
      Left = 57
      Top = 6
      Width = 72
      Height = 21
      Align = alLeft
      Style = csDropDownList
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'COM1'
      OnClick = cbxPortClick
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6')
    end
    object bps: TComboBox
      Left = 129
      Top = 6
      Width = 96
      Height = 21
      Align = alLeft
      Style = csDropDownList
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 1
      Text = '300'
      Items.Strings = (
        '300'
        '600'
        '1200'
        '2400'
        '4800'
        '9600')
    end
    object Panel4: TPanel
      Left = 225
      Top = 6
      Width = 341
      Height = 21
      Align = alLeft
      Caption = '34401A Multi Meter'
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 643
    Height = 72
    Align = alTop
    TabOrder = 1
    object Label2: TLabel
      Left = 312
      Top = 1
      Width = 51
      Height = 70
      Align = alLeft
      Caption = #52636#47141' '#45236#50857
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object Label3: TLabel
      Left = 1
      Top = 1
      Width = 51
      Height = 70
      Align = alLeft
      Caption = #51077#47141' '#47749#47161
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object mmIn: TMemo
      Left = 52
      Top = 1
      Width = 185
      Height = 70
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
    end
    object testOn: TButton
      Left = 237
      Top = 1
      Width = 75
      Height = 70
      Align = alLeft
      Caption = 'b1'
      TabOrder = 1
      OnClick = testOnClick
    end
    object testOff: TButton
      Left = 566
      Top = 1
      Width = 75
      Height = 70
      Align = alLeft
      Caption = 'b2'
      TabOrder = 2
      OnClick = testOffClick
    end
    object mmOut: TMemo
      Left = 363
      Top = 1
      Width = 203
      Height = 70
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      TabOrder = 3
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 105
    Width = 643
    Height = 88
    Align = alTop
    TabOrder = 2
    object Label4: TLabel
      Left = 1
      Top = 1
      Width = 51
      Height = 86
      Align = alLeft
      Alignment = taCenter
      Caption = #51077#47141' '#47196#44536
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object lstInlog: TListBox
      Left = 52
      Top = 1
      Width = 514
      Height = 86
      Style = lbOwnerDrawVariable
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 16
      TabOrder = 0
    end
    object btnClear1: TButton
      Left = 566
      Top = 1
      Width = 75
      Height = 86
      Align = alLeft
      Caption = #47196#44536' '#49325#51228
      TabOrder = 1
      OnClick = btnClear1Click
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 193
    Width = 643
    Height = 88
    Align = alTop
    TabOrder = 3
    object Label5: TLabel
      Left = 1
      Top = 1
      Width = 51
      Height = 86
      Align = alLeft
      Alignment = taCenter
      Caption = #52636#47141' '#47196#44536
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object lstOutlog: TListBox
      Left = 52
      Top = 1
      Width = 514
      Height = 86
      Style = lbOwnerDrawVariable
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 16
      TabOrder = 0
    end
    object btnClear2: TButton
      Left = 566
      Top = 1
      Width = 75
      Height = 86
      Align = alLeft
      Caption = #47196#44536' '#49325#51228
      TabOrder = 1
      OnClick = btnClear2Click
    end
  end
  object btnInit: TButton
    Left = 568
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Initialize'
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 608
    Top = 368
    object File1: TMenuItem
      Caption = 'File'
      object close1: TMenuItem
        Caption = 'close'
        OnClick = close1Click
      end
    end
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM5'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    Left = 568
    Top = 368
  end
end
