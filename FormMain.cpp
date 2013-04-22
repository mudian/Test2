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
//	char c;
//	switch(c)
//	{}
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::testOnClick(TObject *Sender) //테스트 버튼 전송
{
    
	String StrMsg1,strT, strIn;
	String strMon,strday,strHour,strMin,strsec;
	if(ComPort1->Connected)
	{
		try
		{
			StrMsg1 = mmIn->Lines->GetText();
			int iRlt = ComPort1->WriteStr(StrMsg1+ "\n");  //
			if(iRlt == StrMsg1.Length()+ 1)// 
			{

				strT   = FormatDateTime("YYYY.MM.DD HH:NN:SS:ZZZ", Now());
//				strIn = strT + "- " +StrMsg1;
				TListItem * evtLog = lstEvtlog-> Items ->Add();
				evtLog ->Caption = strT;
				evtLog ->SubItems->Add("Tx:"+StrMsg1);
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
	String StrMsg2,strT,strOut;
	String strMon,strday,strHour,strMin,strsec;
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
	String StrMsg2,strT,strOut;
	String strMon,strday,strHour,strMin,strsec;
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


void __fastcall TfrmMain::lstStatClick(TObject *Sender)
{
	//
//	frmCmd->Cmd_ID = &m_Cmd_ID;
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("설정 대기"))
	{
		lstStat->Clear();
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Measure?"))
	{
		if(lstStat->ItemIndex == 0)
		{
			m_Cmd_ID.Name = "MEAS: VOLT: DC?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "범위값, 분해능 입력";
			mmoDisp->Clear();   
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 1)
		{
			m_Cmd_ID.Name = "MEAS: VOLT: DC: RAT?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();     
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 2)
		{
			m_Cmd_ID.Name = "MEAS: VOLT: AC?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();      
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 3)
		{
			m_Cmd_ID.Name = "MEAS: CURR: DC?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();      
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 4)
		{
			m_Cmd_ID.Name = "MEAS: CURR: AC?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();      
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 5)
		{
			m_Cmd_ID.Name = "MEAS: RES?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();        
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 6)
		{
			m_Cmd_ID.Name = "MEAS: FRES?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();        
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 7)
		{
			m_Cmd_ID.Name = "MEAS: FREQ?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();         
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 8)
		{
			m_Cmd_ID.Name = "MEAS: PER?";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();   
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 9)
		{
			m_Cmd_ID.Name = "MEAS: CONT?";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();        
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 10)
		{
			m_Cmd_ID.Name = "MEAS: DIOD?";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();        
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Configure"))        //configure 
	{
    	if(lstStat->ItemIndex == 0)
		{
			m_Cmd_ID.Name = "CONF: VOLT: DC";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "범위값, 분해능 입력";
			mmoDisp->Clear();        
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 1)
		{
			m_Cmd_ID.Name = "CONF: VOLT: DC: RAT";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();          
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 2)
		{
			m_Cmd_ID.Name = "CONF: VOLT: AC";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();           
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 3)
		{
			m_Cmd_ID.Name = "CONF: CURR: DC";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();           
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 4)
		{
			m_Cmd_ID.Name = "CONF: CURR: AC";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 5)
		{
			m_Cmd_ID.Name = "CONF: RES";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 6)
		{
			m_Cmd_ID.Name = "CONF: FRES";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();             
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 7)
		{
			m_Cmd_ID.Name = "CONF: FREQ";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 8)
		{
			m_Cmd_ID.Name = "CONF: PER";
			m_Cmd_ID.Type = "Value";
			m_Cmd_ID.VarNum = 2;
			m_Cmd_ID.Var1 = "Range";
			m_Cmd_ID.Var2 = "Resolution";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();       
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 9)
		{
			m_Cmd_ID.Name = "CONF: CONT";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 10)
		{
			m_Cmd_ID.Name = "CONF: DIOD";
			m_Cmd_ID.Type = "Select";
			m_Cmd_ID.VarNum = 4;
			m_Cmd_ID.Var1 = "Value";
			m_Cmd_ID.Var2 = "MIN";
			m_Cmd_ID.Var3 = "MAX";
			m_Cmd_ID.Var4 = "DEF";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
		if(lstStat->ItemIndex == 11)
		{
			m_Cmd_ID.Name = "CONF?";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();       
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}

	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("MEasurement Configuration"))  //
	{
		if(lstStat->ItemIndex == 0)
		{
			m_Cmd_ID.Name = "RANG ";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}if(lstStat->ItemIndex == 1)
		{
			m_Cmd_ID.Name = "RANG? ";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}if(lstStat->ItemIndex == 2)
		{
			m_Cmd_ID.Name = "RANG: AUTO ";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}if(lstStat->ItemIndex == 3)
		{
			m_Cmd_ID.Name = "RANG: AUTO? ";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}if(lstStat->ItemIndex == 4)
		{
			m_Cmd_ID.Name = "RES ";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}if(lstStat->ItemIndex == 5)
		{
			m_Cmd_ID.Name = "RES?";
			m_Cmd_ID.Type = "Non";
			m_Cmd_ID.VarNum = 0;
			m_Cmd_ID.Var1 = "";
			m_Cmd_ID.Var2 = "";
			m_Cmd_ID.Var3 = "";
			m_Cmd_ID.Var4 = "";
			m_Cmd_ID.Memo = "";
			mmoDisp->Clear();
			mmoDisp->Lines->Add("원하는 명령을 더블 클릭 하세요.");
			mmoDisp->Lines->Add(m_Cmd_ID.Name);
			mmoDisp->Lines->Add("입력값: " + m_Cmd_ID.Var1 + " " + m_Cmd_ID.Var2 + " " + m_Cmd_ID.Var3 + " " + m_Cmd_ID.Var4);
			mmoDisp->Lines->Add("");
		}
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Math Operation"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Triggering"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("System-Related"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Status Reporting"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Calibration"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("RS-232 Interface"));
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("etc."));


}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cbbSettingChange(TObject *Sender)
{

	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("설정 대기"))
	{
		lstStat->Clear();
		m_Cmd_ID.FName ="";
		cbbFunc->Visible = 0; 
		cbbFunc->ItemIndex = 0;


	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Measure?"))
	{
		lstStat->Clear();    
		cbbFunc->Visible = 0;
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("DC 전압 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("Dc 비율 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("AC 전압 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("DC 전류 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("AC 전류 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("2전선의 저항 측정이 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("4선 저항 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("주파수 측정이 설정한 range와 resolution으로 생성된다.");
		lstStat->Items->Add("주기의 측정이 설정한 range와 resolution으로 설정. Range 범위는 0.33sec ~ 0.3 micro sec");
		lstStat->Items->Add("연속성 측정을 설정 및 생성함. 범위와 분해능은 고정되어있음.");
		lstStat->Items->Add("다이오드 측정을 설정 및 생성함. Range와 resolution은 고정됨.");
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Configure"))
	{
		lstStat->Clear();       
		cbbFunc->Visible = 0;
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("멀티미터가 DC 전압 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 DC 전압 비율 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 AC 전압 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 DC 전류 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 AC 전류 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 2전선의 저항 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 4선 저항 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 주파수 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 주기의 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 연속성 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("멀티미터가 다이오드 측정을 위해 설정한 range와 resolution으로 설정된다.");
		lstStat->Items->Add("설정 확인");
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("MEasurement Configuration"))
	{
		lstStat->Clear();
		cbbFunc->Visible = 1; 
		cbbFunc->ItemIndex = 0;
		lstStat->Items->Add("선택함수의 범위를 지정한다");
		lstStat->Items->Add("선택함수의 범위를 물어본다");
		lstStat->Items->Add("선택함수의 자동 범위 지정을 키고 끈");
		lstStat->Items->Add("선택함수의 자동 범위 지정을 확인한다");
		lstStat->Items->Add("선택함수의 resolution을 선택한다");
		lstStat->Items->Add("선택함수의 resolution을 확인한다");
		lstStat->Items->Add("선택함수의 integration time 을 선택한다");
		lstStat->Items->Add("선택함수의 integration time 을 확인한다");
		lstStat->Items->Add("주파수 측정에서 aperture time을 선택한다");
		lstStat->Items->Add("주파수 측정에서 aperture time을 확인한다");
		lstStat->Items->Add("주기 측정에서 aperture time을 선택한다");
		lstStat->Items->Add("주기 측정에서 aperture time을 확인한다");
		lstStat->Items->Add("선택함수의 입력신호에서 기대되는 가장 낮은 주파수를 설정한다");
		lstStat->Items->Add("선택함수의 입력신호에서 기대되는 가장 낮은 주파수를 확인한다");
		lstStat->Items->Add("선택함수의 AutoZero 모드를 키고 끈다");
		lstStat->Items->Add("선택함수의 AutoZero 모드를 확인한다");
		lstStat->Items->Add("DC 전압 측정에대한 자동 입력 저항 모드를 설정한다.");
		lstStat->Items->Add("DC 전압 측정에대한 자동 입력 저항 모드를 확인한다.");
		lstStat->Items->Add("입력 터미널의 Front/Rear을 확인한다.");
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Math Operation"))
	{
		lstStat->Clear();   
		cbbFunc->Visible = 0;
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("Math Function 선택");
		lstStat->Items->Add("선택된 Function 확인");
		lstStat->Items->Add("선택된 함수의 온오프 상태를 선택한다.");
		lstStat->Items->Add("선택된 함수의 온오프 상태를 확인한다.");
		lstStat->Items->Add("최소값을 읽는다");
		lstStat->Items->Add("최대값을 읽는다");
		lstStat->Items->Add("평균값을 읽는다");
		lstStat->Items->Add("Reading이 되는 숫자를 읽는다");
		lstStat->Items->Add("멀티메터의 NULL register에서 NULL 값을 저장한다.");
		lstStat->Items->Add("NULL 값을 확인한다.");
		lstStat->Items->Add("dB Relative Register에서의 Relative 값을 저장한다");
		lstStat->Items->Add("Relative 값을 확인한다");
		lstStat->Items->Add("dBm 참조값을 선택한다");
		lstStat->Items->Add("dBm 참조값을 확인한다");
		lstStat->Items->Add("최저 한계치를 설정한다");
		lstStat->Items->Add("최저 한계치를 확인한다");
		lstStat->Items->Add("최대 한계치를 설정한다");
		lstStat->Items->Add("최대 한계치를 확인한다.");
		lstStat->Items->Add("INIT 명령어를 사용하여 멀티미터 내부 메모리에 저장 여부를 설정한다");
		lstStat->Items->Add("INIT 명령어를 사용하여 멀티미터 내부 메모리에 저장 여부를 확인한다");
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Triggering"))
	{
		lstStat->Clear();  
		cbbFunc->Visible = 0;   
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("트리거 시스템을 '트리거를 위한 대기'상태로 변경, 이후 트리거 조건이 만족할때 측정을 시작한다");
		lstStat->Items->Add("트리거 시스템을 '트리거를 위한 대기'상태로 변경, READ 명령을 수령 받는동안 트리거 조건이 만족할때 측정을 시작한다.");
		lstStat->Items->Add("멀티미터가 받아들일 트리거의 소스를 선택한다");
		lstStat->Items->Add("멀티미터가 받아들일 트리거의 소스를 확인한다");
		lstStat->Items->Add("트리거 신호들 사이의 딜레이를 설정한다");
		lstStat->Items->Add("트리거 신호들 사이의 딜레이를 확인한다");
		lstStat->Items->Add("자동 트리거 딜레이 설정의 온오프 상태를 선택한다");
		lstStat->Items->Add("자동 트리거 딜레이 설정의 온오프 상태를 확인한다");
		lstStat->Items->Add("트리거당 멀티미터가 읽어들일 샘플의 숫자를 설정한다");
		lstStat->Items->Add("트리거당 멀티미터가 읽어들일 샘플의 숫자를 확인한다");
		lstStat->Items->Add("멀티미터가 다시 'idle'상태로 돌아갈때까지의 트리거 숫자를 설정한다");
		lstStat->Items->Add("멀티미터가 다시 'idle'상태로 돌아갈때까지의 트리거 숫자를 확인한다");
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("System-Related"))
	{
		lstStat->Clear();
		cbbFunc->Visible = 0; 
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("INIT 명령으로 외부 메모리에 저장된 기록을 버스컨트롤러로 읽을수 있는 출력 버퍼로 옮긴다");
		lstStat->Items->Add("트리거에 있음");
		lstStat->Items->Add("프론트 페널의 디스플레이 셋팅");
		lstStat->Items->Add("쿼리");
		lstStat->Items->Add("프론트페널로 보낸 메시지와 반환된 문자를 물어본다");
		lstStat->Items->Add("프론트패널에 표시된 메시지를 지운다");
		lstStat->Items->Add("경보음 1회 발생");
		lstStat->Items->Add("경보음을 키고끔");
		lstStat->Items->Add("경보음 상태를 확인");
		lstStat->Items->Add("멀티메터의 에러 대기열을 확인");
		lstStat->Items->Add("제공된 SCPI의 버전확인");
		lstStat->Items->Add("내장 메모리에 저장된 기록의 수를 확인");
		lstStat->Items->Add("전원 공급 구성을 초기화");
		lstStat->Items->Add("멀티미터 자가진단을 완전히 수행함. 0 이 리턴되면 성공적임");
		lstStat->Items->Add("멀티미터의 식별자를 읽음");

	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Status Reporting"))
	{
		lstStat->Clear();      
		cbbFunc->Visible = 0; 
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("멀티메터의 에러 대기열을 확인");
		lstStat->Items->Add("문제성 데이터 활성화 레지스터의 비트를 활성화");
		lstStat->Items->Add("쿼리");
		lstStat->Items->Add("문제성 데이터 이벤트 레지스터를 확인. 활성화 레지스터의 bit 집합의 2진합을 반환");
		lstStat->Items->Add("문제성 데이터 활성화 레지스터 및 표준 작동 활성화 레지스터의 모든 비트를 삭제");
		lstStat->Items->Add("상태 삭제 명령");
		lstStat->Items->Add("이벤트 상태 활성화 명령");
		lstStat->Items->Add("이벤트 상태 쿼리");
		lstStat->Items->Add("표준 이벤트 레지스터 쿼리");
		lstStat->Items->Add("현재 작업이 완료 되면 표준 이벤트 레지스터에서 작동 완료(0)를 설정");
		lstStat->Items->Add("보류중인 모든 명령이 완료된후 출력 버퍼로 1을 반환");
		lstStat->Items->Add("전원 켜기 상태 삭제");
		lstStat->Items->Add("쿼리");
		lstStat->Items->Add("서비스 요청 활성화");
		lstStat->Items->Add("쿼리");
		lstStat->Items->Add("읽기 상태 바이트 쿼리");
		
	}
	if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("Calibration"))
	{
		lstStat->Clear();  
		cbbFunc->Visible = 0; 
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("교정값(CAL:VAL)을 사용하여 교정을 수행");
		lstStat->Items->Add("수행된 교정 회수를 반환");
		lstStat->Items->Add("교정방지를 위한 보안코드 설정");
		lstStat->Items->Add("교정을 위해 계측기 보안을 해제,설정");
		lstStat->Items->Add("쿼리");
		lstStat->Items->Add("교정 메모리에 메시지를 저장");
		lstStat->Items->Add("메시지 확인");
		lstStat->Items->Add("알려진 교정 신호의 값을 지정");
	}
	else if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("RS-232 Interface"))
	{
		lstStat->Clear();  
		cbbFunc->Visible = 0;    
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("msg");
	}
	else if(cbbSetting->ItemIndex == cbbSetting->Items->IndexOf("etc."))
	{
		lstStat->Clear();
		cbbFunc->Visible = 0;   
		cbbFunc->ItemIndex = 0;
		m_Cmd_ID.FName ="";
		lstStat->Items->Add("msg");
	}


}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::lstStatDblClick(TObject *Sender)
{

	frmCmd = new TfrmCmd(this);
    
	frmCmd->cbbVar->Clear();
	frmCmd->cbbVar->Items->Add("");
	frmCmd->cbbVar->Visible = 0;
	frmCmd->edtVar1->Clear();
	frmCmd->edtVar1->Visible = 0;
	frmCmd->edtVar2->Clear();
	frmCmd->edtVar2->Visible = 0;
	frmCmd->lblVar2->Caption = " ";
	frmCmd->mmoName->Clear();
	frmCmd->mmoName->Lines->Add("Name 	:" + m_Cmd_ID.Name);
	frmCmd->mmoName->Lines->Add("Command:" + m_Cmd_ID.Cmd);

	// 버튼 초기화
	if(m_Cmd_ID.Type == "Select")
	{
		frmCmd->cbbVar->Visible = 1;
		frmCmd->cbbVar->Items->Add(m_Cmd_ID.Var1);
		if(m_Cmd_ID.VarNum>1)
		{
			frmCmd->cbbVar->Items->Add(m_Cmd_ID.Var2);
		}
		if(m_Cmd_ID.VarNum>2)
		{
			frmCmd->cbbVar->Items->Add(m_Cmd_ID.Var3);
		}
		if(m_Cmd_ID.VarNum>3)
		{
			frmCmd->cbbVar->Items->Add(m_Cmd_ID.Var4);
		}
	}
	else if(m_Cmd_ID.Type == "Value")
	{
		if(m_Cmd_ID.VarNum>1)
		{
			frmCmd->edtVar2->Visible = 1;
			frmCmd->edtVar2->Text = m_Cmd_ID.Var2;
		}
		frmCmd->edtVar1->Visible = 1;
		frmCmd->edtVar1->Text = m_Cmd_ID.Var1;

	}

	if(frmCmd->ShowModal() == mrOk)
	{
		String Cmd0,Cmd1,Cmd2,Cmd3;
		Cmd1 = m_Cmd_ID.FName + m_Cmd_ID.Name;
		Cmd2 = frmCmd->cbbVar->Text;
		if((Cmd2 == "Value" || Cmd2 == "second") && m_Cmd_ID.Type == "Select")
		{
			Cmd2 == "";
		}
		Cmd3 = frmCmd->edtVar1->Text + frmCmd->edtVar2->Text;
		Cmd0 = Cmd1 + " " + Cmd2 + " " + Cmd3;
		mmoDisp->Text = Cmd0;
//		ComPort1->WriteStr(Cmd0);
	}
	delete frmCmd;
}
//---------------------------------------------------------------------------

typedef enum
{
	fiFunc,//0
	fiVoltDC,//1
}TFuncID;

void __fastcall TfrmMain::cbbFuncChange(TObject *Sender)
{
	
	//
	if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("함수"))
	{
		m_Cmd_ID.FName = "";

	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Voltage:DC:"))
	{
		m_Cmd_ID.FName = "VOLT";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Voltage:DC:Ratio:"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Voltage:AC:"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Current:DC:"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Current:AC:"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Resistance (2-wire ohms)"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Fresistance (4-wire ohms)"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Frequency"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Period"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Continuity"))
	{
		m_Cmd_ID.FName = "";
	}
	else if(cbbFunc->ItemIndex == cbbFunc->Items->IndexOf("Diode"))
	{
		m_Cmd_ID.FName = "";
	}
}
//---------------------------------------------------------------------------


