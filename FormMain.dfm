object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = '34401A MultiMeter '
  ClientHeight = 666
  ClientWidth = 612
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
    Width = 612
    Height = 33
    Align = alTop
    BorderWidth = 5
    TabOrder = 0
    ExplicitLeft = -8
    object Label1: TLabel
      Left = 6
      Top = 6
      Width = 51
      Height = 21
      Align = alLeft
      Caption = #53685#49888' '#49444#51221
      Layout = tlCenter
      ExplicitLeft = 9
    end
    object btnConnect: TSpeedButton
      Left = 531
      Top = 6
      Width = 75
      Height = 21
      Align = alRight
      Caption = 'Disconnect'
      OnClick = btnConnectClick
      ExplicitLeft = 571
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
      ItemIndex = 3
      TabOrder = 0
      Text = 'COM4'
      OnClick = cbxPortClick
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6'
        'COM7'
        'COM9')
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
      Width = 308
      Height = 21
      Align = alLeft
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = '34401A Multi Meter'
      TabOrder = 2
      ExplicitTop = 3
      ExplicitWidth = 346
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 612
    Height = 72
    Align = alTop
    BorderWidth = 5
    TabOrder = 1
    ExplicitLeft = 8
    object Label2: TLabel
      Left = 308
      Top = 6
      Width = 51
      Height = 60
      Align = alLeft
      Caption = #52636#47141' '#45236#50857
      Layout = tlCenter
      ExplicitLeft = 312
      ExplicitTop = 1
      ExplicitHeight = 13
    end
    object Label3: TLabel
      Left = 6
      Top = 6
      Width = 51
      Height = 60
      Align = alLeft
      Caption = #47749#47161' '#51077#47141
      Layout = tlCenter
      ExplicitHeight = 13
    end
    object mmIn: TMemo
      Left = 57
      Top = 6
      Width = 176
      Height = 60
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
    end
    object testOn: TButton
      Left = 233
      Top = 6
      Width = 75
      Height = 60
      Align = alLeft
      Caption = 'b1'
      TabOrder = 1
      OnClick = testOnClick
      ExplicitLeft = 237
      ExplicitTop = 1
      ExplicitHeight = 70
    end
    object testOff: TButton
      Left = 536
      Top = 6
      Width = 75
      Height = 60
      Align = alLeft
      Caption = 'b2'
      TabOrder = 2
      OnClick = testOffClick
      ExplicitLeft = 566
      ExplicitTop = 1
      ExplicitHeight = 70
    end
    object mmOut: TMemo
      Left = 359
      Top = 6
      Width = 177
      Height = 60
      Align = alLeft
      ImeName = 'Microsoft Office IME 2007'
      TabOrder = 3
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 514
    Width = 612
    Height = 32
    Align = alBottom
    BorderWidth = 5
    TabOrder = 2
    ExplicitTop = 576
    ExplicitWidth = 624
    object Label5: TLabel
      AlignWithMargins = True
      Left = 9
      Top = 9
      Width = 51
      Height = 14
      Align = alLeft
      Alignment = taCenter
      Caption = #53685#49888' '#47196#44536
      Layout = tlCenter
      ExplicitLeft = 6
      ExplicitHeight = 24
    end
    object btnClear1: TButton
      Left = 63
      Top = 6
      Width = 75
      Height = 20
      Align = alLeft
      Caption = #47196#44536' '#49325#51228
      TabOrder = 0
      OnClick = btnClear1Click
      ExplicitLeft = 0
      ExplicitTop = 2
      ExplicitHeight = 22
    end
    object Button2: TButton
      Left = 138
      Top = 6
      Width = 75
      Height = 20
      Align = alLeft
      Caption = 'Button1'
      TabOrder = 1
      ExplicitLeft = 96
      ExplicitTop = 8
      ExplicitHeight = 25
    end
  end
  object scrBox: TScrollBox
    Left = 0
    Top = 105
    Width = 612
    Height = 409
    Align = alClient
    TabOrder = 3
    ExplicitWidth = 624
    ExplicitHeight = 497
    object Splitter1: TSplitter
      Left = 0
      Top = 402
      Width = 608
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      ExplicitLeft = 82
      ExplicitTop = 65
      ExplicitWidth = 359
    end
    object lstCtcmd: TListBox
      Left = 88
      Top = 73
      Width = 520
      Height = 97
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      Items.Strings = (
        'Measure? Commands'
        'Configure Commands'
        'Measurement Configuration Commands'
        'Math Operation Commands'
        'Triggering Commands'
        'System-Related Commands'
        'Status Reporting Commands'
        'Calibration Commands'
        'RS-232 Interface Commands'
        'IEEE-488.2 Common Commands'
        'etc.'
        '')
      TabOrder = 0
      OnDblClick = lstCtcmdDblClick
    end
    object lstCmd: TListBox
      Left = 88
      Top = 176
      Width = 519
      Height = 105
      ImeName = 'Microsoft Office IME 2007'
      ItemHeight = 13
      TabOrder = 1
    end
    object Panel3: TPanel
      Left = 0
      Top = 65
      Width = 82
      Height = 337
      Align = alLeft
      TabOrder = 2
      ExplicitLeft = 5
      ExplicitTop = 71
    end
    object Panel6: TPanel
      Left = 0
      Top = 0
      Width = 608
      Height = 65
      Align = alTop
      TabOrder = 3
      ExplicitWidth = 632
    end
  end
  object lstEvtlog: TListView
    Left = 0
    Top = 546
    Width = 612
    Height = 120
    Align = alBottom
    Columns = <
      item
        Caption = 'Time'
        Width = 150
      end
      item
        Caption = 'Log'
        Width = 400
      end>
    FlatScrollBars = True
    Items.ItemData = {
      01270000000100000000000000FFFFFFFFFFFFFFFF0100000000000000047400
      69006D006500036C006F006700FFFF}
    RowSelect = True
    TabOrder = 4
    ViewStyle = vsReport
    ExplicitTop = 608
    ExplicitWidth = 624
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 464
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
    Port = 'COM4'
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
    Left = 48
    Top = 432
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 16
    Top = 432
  end
end
