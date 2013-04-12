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
	TPanel *Panel3;
	TListBox *lstInlog;
	TLabel *Label4;
	TButton *btnClear1;
	TPanel *Panel4;
	TPanel *Panel5;
	TLabel *Label5;
	TListBox *lstOutlog;
	TButton *btnClear2;
	TButton *btnInit;
	void __fastcall close1Click(TObject *Sender);
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall cbxPortClick(TObject *Sender);
	void __fastcall testOnClick(TObject *Sender);
	void __fastcall testOffClick(TObject *Sender);
	void __fastcall btnClear1Click(TObject *Sender);
	void __fastcall btnClear2Click(TObject *Sender);
private:   	// User declarations
	void __fastcall vEventMessage(String msg);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
