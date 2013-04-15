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
	TListBox *lstCtcmd;
	TListBox *lstCmd;
	TPanel *Panel3;
	TListView *lstEvtlog;
	TPanel *Panel6;
	TSplitter *Splitter1;
	void __fastcall close1Click(TObject *Sender);
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall cbxPortClick(TObject *Sender);
	void __fastcall testOnClick(TObject *Sender);
	void __fastcall testOffClick(TObject *Sender);
	void __fastcall btnClear1Click(TObject *Sender);
	void __fastcall btnTestClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall lstCtcmdDblClick(TObject *Sender);
private:   	// User declarations
	void __fastcall vEventMessage(String msg);
	void __fastcall	CmdList(int cmd);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
