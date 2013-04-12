//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"


#include <time.h> // timer
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma resource "*.dfm"
TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::close1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnConnectClick(TObject *Sender)
{
	if(ComPort1->Connected)
	{                        
		btnConnect->Down = 0;
		btnConnect->Caption ="Disconnect";
		ComPort1->Close();
	}
	else 
	{
		try
		{
			btnConnect->Down = 1;
			btnConnect->Caption ="Connect";

			ComPort1->Open();

		}catch(...)
		{
			mmOut->Lines->Add("?");
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::cbxPortClick(TObject *Sender)
{
/*	//��� ������ ��Ʈ ã��
	int portl = length(Comport1->PortIndex)
	for(int i=0;i< portl; i++)
	{
	cbxProt->Item[i] = c
	ComPort1

	}
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::testOnClick(TObject *Sender)
{
    
	AnsiString StrMsg1,strT, strIn;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			StrMsg1 = mmIn->Lines->GetText();
			ComPort1->WriteStr(StrMsg1);
//					  FormateDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//			time_t timer;
//			struct tm *t;
//			timer = time(NULL); // ���� �ð��� �� ������ ���
//			t = localtime(&timer);
//			strMon = IntToStr(t->tm_mon+1);
//			strday = IntToStr(t->tm_mday);
//			strHour= IntToStr(t->tm_hour);
//			strMin = IntToStr(t->tm_min);
//			strsec = IntToStr(t->tm_sec);
//			strT   = strMon + "M" + strday + "D" + strHour + ":" + strMin + ":" + strsec;
			strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
			strIn = strT + "- " +StrMsg1;
			lstInlog->Items->Add(strIn);
			lstInlog->ItemIndex = lstInlog->Items->Count-1;
		}catch(...)
		{
			mmOut->Lines->Clear();
			mmOut->Lines->Add("����");
		}
	}else
	{   
		mmOut->Lines->Clear();
		mmOut->Lines->Add("�����ϼ���");
	}
}
//---------------------------------------------------------------------------









void __fastcall TfrmMain::testOffClick(TObject *Sender)
{
	AnsiString StrMsg2,strT,strOut;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			ComPort1->ReadStr(StrMsg2,6);
			mmOut->Lines->Clear();
			mmOut->Lines->Add(StrMsg2);
			strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
			strOut = strT + "- " +StrMsg2;
			lstOutlog->Items->Add(strOut);
			lstOutlog->ItemIndex = lstInlog->Items->Count-1;
		}catch(...)
		{
			mmOut->Lines->Add("����");
		}
	}else
	{
		mmOut->Lines->Add("�����ϼ���");
	}
}
//---------------------------------------------------------------------------





void __fastcall TfrmMain::btnClear1Click(TObject *Sender)
{
	lstInlog->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClear2Click(TObject *Sender)
{
	lstOutlog->Items->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::vEventMessage(String msg)
{
	String strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
	mmOut->Lines->Add(strT + " : " + msg);
}
