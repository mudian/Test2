//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include "CPort.hpp"
#include <DBCtrls.hpp>
#include <ComCtrls.hpp>
#include "FormCmd.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TComboBox *cbxPort;
	TComboBox *bps;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *close1;
	TSpeedButton *btnConnect;
	TComPort *ComPort1;
	TPanel *Panel2;
	TMemo *mmIn;
	TButton *testOn;
	TButton *testOff;
	TMemo *mmOut;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnClear1;
	TPanel *Panel4;
	TTimer *Timer1;
	TPanel *Panel5;
	TScrollBox *scrBox;
	TButton *Button2;
	TLabel *Label5;
	TListBox *lstStat;
	TListBox *lstCmd;
	TPanel *Panel3;
	TListView *lstEvtlog;
	TSplitter *Splitter1;
	TPanel *Panel6;
	TButton *Button1;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *btnInit;
	TPanel *Panel7;
	TPanel *Panel8;
	TMemo *mmoDisp;
	TPanel *pnl1;
	TButton *btnDisp1;
	TButton *btnDisp2;
	TButton *btnDisp3;
	TPanel *pnl2;
	TComboBox *cbbSetting;
	TComboBox *cbbFunc;
	void __fastcall close1Click(TObject *Sender);
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall testOnClick(TObject *Sender);
	void __fastcall testOffClick(TObject *Sender);
	void __fastcall btnClear1Click(TObject *Sender);
	void __fastcall btnTestClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall lstStatClick(TObject *Sender);
	void __fastcall cbbSettingChange(TObject *Sender);
	void __fastcall lstStatDblClick(TObject *Sender);
	void __fastcall cbbFuncChange(TObject *Sender);
private:   	// User declarations
	TCmd_ID m_Cmd_ID;

	void __fastcall vEventMessage(String msg);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);

	
};

//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
