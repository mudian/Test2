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
void __fastcall TfrmMain::close1Click(TObject *Sender) //매뉴->close 버튼시 창닫기
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnConnectClick(TObject *Sender) // 연결 접속 시도 버튼
{
	if(ComPort1->Connected)
	{                        
		btnConnect->Down = 0;
		btnConnect->Caption ="Disconnect";
		ComPort1->Close();
		Timer1->Enabled = false;
	}
	else 
	{
		try
		{
			btnConnect->Down = 1;
			btnConnect->Caption ="Connect";
			
			ComPort1->Port = cbxPort->Text;
			ComPort1->Open();
			Timer1->Enabled = ComPort1->Connected;

		}catch(...)
		{
			btnConnect->Down = 0;
			btnConnect->Caption ="Disconnect";
			ComPort1->Close();
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::cbxPortClick(TObject *Sender) // 포트번호 설정 클릭
{
/*	//사용 가능한 포트 찾기
	int portl = length(Comport1->PortIndex)
	for(int i=0;i< portl; i++)
	{
	cbxProt->Item[i] = c
	ComPort1

	}
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::testOnClick(TObject *Sender) //테스트 버튼 전송
{
    
	AnsiString StrMsg1,strT, strIn;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			StrMsg1 = mmIn->Lines->GetText();
			int iRlt = ComPort1->WriteStr(StrMsg1 + "\n");
			if(iRlt == StrMsg1.Length() + 1)
			{

				strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//				strIn = strT + "- " +StrMsg1;
				TListItem * evtLog = lstEvtlog-> Items ->Add();
				evtLog ->Caption = strT;
				evtLog ->SubItems->Add("Tx:"+StrMsg1);
//				int pp = lstEvtlog-> Items ->Count-1;
//				lstEvtlog ->ItemFocused->Index = pp;  				
//				lstEvtlog ->ItemIndex = pp;
//				lstEvtlog ->Scroll(0,0);
//				evtLog -> OverlayIndex = pp;
//				lstEvtlog->Items->Add(strIn,1);
//				lstEvtlog->ItemIndex = lstEvtlog->Items->Count-1;
			}
			else
			{

			}
		}catch(...)
		{
			mmOut->Lines->Clear();
			mmOut->Lines->Add("실패");
		}
	}else
	{   
		mmOut->Lines->Clear();
		mmOut->Lines->Add("연결하세요");
	}
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::testOffClick(TObject *Sender) //테스트 버튼 수신
{
	AnsiString StrMsg2,strT,strOut;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			int iRx = ComPort1->ReadStr(StrMsg2,256);
			if(iRx > 0)
			{
				mmOut->Lines->Clear();
				mmOut->Lines->Add(StrMsg2);
//				strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//				strOut = strT + "- " +StrMsg2;
//				lstEvtlog->Items->Add(strOut);
//				lstEvtlog->ItemIndex = lstEvtlog->Items->Count-1; //기존 코드
				strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//				strIn = strT + "- " +StrMsg1;
				TListItem * evtLog = lstEvtlog-> Items ->Add();
				evtLog ->Caption = strT;
				evtLog ->SubItems->Add("Rx:"+StrMsg2);
				lstEvtlog ->ItemIndex = lstEvtlog-> Items ->Count-1;
//				lstEvtlog->Items->Add(strIn,1);
//				lstEvtlog->ItemIndex = lstEvtlog->Items->Count-1;
			}
		}catch(...)
		{
			mmOut->Lines->Add("실패");
		}
	}else
	{
		mmOut->Lines->Add("연결하세요");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClear1Click(TObject *Sender)
{
	lstEvtlog->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::vEventMessage(String msg)
{
	String strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
	mmOut->Lines->Add(strT + " : " + msg);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnTestClick(TObject *Sender)
{
	//측정 상태 설정 - 전압값 읽기
	ComPort1->WriteStr("MEAS: VOLT: DC? DEF, DEF");


}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)
{
	AnsiString StrMsg2,strT,strOut;
	AnsiString strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			int iRx = ComPort1->ReadStr(StrMsg2,256);
			if(StrMsg2.Length() > 0)
			{
				mmOut->Lines->Clear();
				mmOut->Lines->Add(StrMsg2);
				strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//				strIn = strT + "- " +StrMsg1;
				TListItem * evtLog = lstEvtlog-> Items ->Add();
				evtLog ->Caption = strT;
				evtLog ->SubItems->Add("Rx:"+StrMsg2);
				lstEvtlog ->ItemIndex = lstEvtlog-> Items ->Count-1;
			
			}
		}catch(...)
		{
			mmOut->Lines->Add("실패");
		}
	}else
	{
		mmOut->Lines->Add("연결하세요");
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::lstCtcmdDblClick(TObject *Sender)
{
	int CtCmd;
//	AnsiString Ct1;
	CtCmd = lstCtcmd->ItemIndex;
//	0:Measure? Commands
//	1:Configure Commands
//	2:Measurement Configuration Commands
//	3:Math Operation Commands
//	4:Triggering Commands
//	5:System-Related Commands
//	6:Status Reporting Commands
//	7:Calibration Commands
//	8:RS-232 Interface Commands
//	9:IEEE-488.2 Common Commands
//	10:etc.

    CmdList(CtCmd);

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::CmdList(int cmd)
{
//	AnsiString Cmd1,Cmd2,Cmd3,Cmd4;
//	switch(cmd)
//	{
//		case 0:
//			lstCmd->Items->Clear();
//			lstCmd->Items->Add("MEAS: VOLT: DC? ");
//			lstCmd->Items->Add("MEAS: VOLT: DC: RAT? ");
//			lstCmd->Items->Add("MEAS: VOLT: AC? ");
//			lstCmd->Items->Add("MEAS: CURR: DC? ");
//			lstCmd->Items->Add("MEAS: CURR: AC? ");
//			lstCmd->Items->Add("MEAS: RES? ");
//			lstCmd->Items->Add("MEAS: FRES? ");
//			lstCmd->Items->Add("MEAS: PER? ");
//			lstCmd->Items->Add("MEAS: CONT? ");
//			lstCmd->Items->Add("MEAS: DIOD? ");
//			break;
//		case 1:
//			lstCmd->Items->Clear();
//			lstCmd->Items->Add("CONF: VOLT: DC? ");
//			lstCmd->Items->Add("CONF: VOLT: DC: RAT? ");
//			lstCmd->Items->Add("CONF: VOLT: AC? ");
//			lstCmd->Items->Add("CONF: CURR: DC? ");
//			lstCmd->Items->Add("CONF: CURR: AC? ");
//			lstCmd->Items->Add("CONF: RES? ");
//			lstCmd->Items->Add("CONF: FRES? ");
//			lstCmd->Items->Add("CONF: PER? ");
//			lstCmd->Items->Add("CONF: CONT? ");
//			lstCmd->Items->Add("CONF: DIOD? ");
//			lstCmd->Items->Add("CONF? " + "\n");
//			// 설정치를 입력 or 바로 확인 (엔터)
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//		case 7:
//			break;
//		case 8:
//			break;
//		case 9:
//			break;
//		case 10:
//			break; 
//	}

}

//---------------------------------------------------------------------------

