// CustonList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "Cnode.cpp"
#include "Clist.cpp"
#include "Citerator.cpp"

int main()
{
	Clist<int32> test;

	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);

	test.push_front(10);
	test.push_front(11);
	test.push_front(12);
	test.push_front(13);
  	test.push_front(14);

	Clist<int32>::iterator it = test.begin();

	for (it ; it != test.end(); ++it)
	{
		std::cout << (*it)<< std::endl;
	}
}
