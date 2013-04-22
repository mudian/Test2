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
  Position = poDesigned
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
    object Label2: TLabel
      Left = 308
      Top = 6
      Width = 51
      Height = 60
      Align = alLeft
      Caption = #52636#47141' '#45236#50857
      Layout = tlCenter
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
      ExplicitHeight = 13
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
    end
    object Button2: TButton
      Left = 138
      Top = 6
      Width = 75
      Height = 20
      Align = alLeft
      Caption = 'Button1'
      TabOrder = 1
    end
  end
  object scrBox: TScrollBox
    Left = 0
    Top = 105
    Width = 612
    Height = 409
    Align = alClient
    TabOrder = 3
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
    object Panel3: TPanel
      Left = 0
      Top = 0
      Width = 82
      Height = 402
      Align = alLeft
      TabOrder = 0
      object Button1: TButton
        Left = 1
        Top = 151
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 0
      end
      object Button3: TButton
        Left = 1
        Top = 126
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 1
      end
      object Button4: TButton
        Left = 1
        Top = 101
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 2
      end
      object Button5: TButton
        Left = 1
        Top = 76
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 3
      end
      object Button6: TButton
        Left = 1
        Top = 51
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 4
      end
      object Button7: TButton
        Left = 1
        Top = 26
        Width = 80
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 5
      end
      object btnInit: TButton
        Left = 1
        Top = 1
        Width = 80
        Height = 25
        Align = alTop
        Caption = #49444#51221' '#52488#44592#54868
        TabOrder = 6
      end
    end
    object Panel6: TPanel
      Left = 82
      Top = 0
      Width = 526
      Height = 402
      Align = alClient
      TabOrder = 1
      object lstCmd: TListBox
        Left = 1
        Top = 180
        Width = 524
        Height = 103
        Align = alClient
        ImeName = 'Microsoft Office IME 2007'
        ItemHeight = 13
        TabOrder = 0
      end
      object lstStat: TListBox
        Left = 1
        Top = 26
        Width = 524
        Height = 154
        Align = alTop
        ImeName = 'Microsoft Office IME 2007'
        ItemHeight = 13
        TabOrder = 1
        OnClick = lstStatClick
        OnDblClick = lstStatDblClick
      end
      object Panel7: TPanel
        Left = 1
        Top = 376
        Width = 524
        Height = 25
        Align = alBottom
        TabOrder = 2
      end
      object Panel8: TPanel
        Left = 1
        Top = 283
        Width = 524
        Height = 93
        Align = alBottom
        TabOrder = 3
        object mmoDisp: TMemo
          Left = 65
          Top = 1
          Width = 458
          Height = 91
          Align = alClient
          ImeName = 'Microsoft Office IME 2007'
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
        object pnl1: TPanel
          Left = 1
          Top = 1
          Width = 64
          Height = 91
          Align = alLeft
          Caption = 'pnl1'
          TabOrder = 1
          object btnDisp1: TButton
            Left = 1
            Top = 1
            Width = 62
            Height = 30
            Align = alTop
            Caption = 'Button1'
            TabOrder = 0
          end
          object btnDisp2: TButton
            Left = 1
            Top = 61
            Width = 62
            Height = 30
            Align = alTop
            Caption = 'Button1'
            TabOrder = 1
          end
          object btnDisp3: TButton
            Left = 1
            Top = 31
            Width = 62
            Height = 30
            Align = alTop
            Caption = 'Button1'
            TabOrder = 2
          end
        end
      end
      object pnl2: TPanel
        Left = 1
        Top = 1
        Width = 524
        Height = 25
        Align = alTop
        TabOrder = 4
        object cbbSetting: TComboBox
          Left = 1
          Top = 1
          Width = 327
          Height = 21
          HelpType = htKeyword
          Align = alClient
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImeName = 'Microsoft Office IME 2007'
          ItemHeight = 13
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          OnChange = cbbSettingChange
          Items.Strings = (
            #49444#51221' '#45824#44592
            'Measure?'
            'Configure'
            'MEasurement Configuration'
            'Math Operation'
            'Triggering'
            'System-Related'
            'Status Reporting'
            'Calibration '
            'RS-232 Interface'
            'etc.')
        end
        object cbbFunc: TComboBox
          Left = 328
          Top = 1
          Width = 195
          Height = 21
          HelpType = htKeyword
          Align = alRight
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImeName = 'Microsoft Office IME 2007'
          ItemHeight = 13
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 1
          Visible = False
          OnChange = cbbFuncChange
          Items.Strings = (
            #54632#49688
            'Voltage:DC:'
            'Voltage:DC:Ratio:'
            'Voltage:AC:'
            'Current:DC:'
            'Current:AC:'
            'Resistance (2-wire ohms)'
            'Fresistance (4-wire ohms)'
            'Frequency'
            'Period'
            'Continuity'
            'Diode')
          ExplicitLeft = 334
          ExplicitTop = -1
        end
      end
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
