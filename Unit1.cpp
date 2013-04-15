//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <windows.h>

using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
	 cout<<"list1: ";
	 copy(l1.begin(),l1.end(), ostream_iterator<int>(cout," "));
	 cout<<endl<<"list2: ";
	 copy(l2.begin(),l2.end(), ostream_iterator<int>(cout," "));
	 cout<<endl<<endl;
}

int main()
{
//	ansistring inMsg;
//	ComPort1->WriteStr("msg");

//	// 초기화 과정
//	ComPort1->WriteStr("DET:BAND 20");
//	ComPort1->WriteStr("ZERO:AUTO ON");
//	ComPort1->WriteStr("INP:IMP:AUTO OFF");
//	ComPort1->WriteStr("SAMP:COUN 1");
//	ComPort1->WriteStr("TRIG:DEL:AUTO ON");
//	ComPort1->WriteStr("TRIG:SOUR IMM");
//	ComPort1->WriteStr("CALC:STAT OFF");

//	//측정 상태 설정 - 전압값 읽기
//	ComPort1->WriteStr("MEAS: VOLT: DC? DEF, DEF");
//	ComPort1->WriteStr("CONF: VOLT: DC? DEF, DEF");
//	//트리거 조건 설정
//	ComPort1->WriteStr("TRIG: SOUR EXT");
//	//멀티미터 시작
//	ComPort1->WriteStr("INIT");
//	//기록을 받음
//	ComPort1->WriteStr("FETC?");
//	//기록을 읽음
//    ComPort1->ReadStr(inMsg,6);
}
