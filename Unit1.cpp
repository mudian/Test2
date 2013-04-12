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
     //두개의 빈 list를 생성한다.
	 list<int> list1,list2;

     //0~6의 값으로 두 list를 채운다.
     for(int i=0; i<6; ++i)
	 {
      list1.push_back(i);
      list2.push_front(i);
     }
	 printLists(list1,list2);
	 Sleep(5000);

	 //list2에서 값을 3으로 가지는 원소의 위치에 list1의 모든 원소들을 삽입한다.
	 //find()는 값이 3인 최초의 원소의 위치를 반환한다.
	 list2.splice(find(list2.begin(),list2.end(),3), list1);
	 printLists(list1, list2);
	 Sleep(5000);
	 //첫 번째 원소를 마지막으로 이동시킨다.
	 list2.splice(list2.end(),list2,list2.begin());
	 printLists(list1, list2);
	 Sleep(5000);
	 //list2를 정렬한후 list1에 할당한다. 그리고 나서 list2의 중복된 값들을 제거한다.
	 list2.sort();
	 list1=list2;
	 list2.unique();
	 printLists(list1,list2);
	 Sleep(5000);
	 //list2를 list1에 병합한다.
	 list1.merge(list2);
	 printLists(list1,list2);
	 Sleep(5000);
}