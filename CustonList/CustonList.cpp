// CustonList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "Cnode.cpp"
#include "Clist.cpp"
#include "Citerator.cpp"

int main()
{
	Clist<int32> customList;

	customList.push_back(1);
	customList.push_back(2);
	customList.push_back(3);
	customList.push_back(4);

	customList.push_front(10);
	customList.push_front(11);
	customList.push_front(12);
	customList.push_front(13);
  	customList.push_front(14);

	Clist<int32>::iterator it = customList.begin();

	cout << "---------iterator 반복문---------" << endl;
	for (it ; it != customList.end(); ++it)
	{
		std::cout << (*it)<< std::endl;
	}

	cout << "---------front, back---------" << endl;
	cout << "front : " << customList.front() << endl;
	cout << "back : " << customList.back() << endl;

	cout << "---------pop_front, back---------" << endl;
	customList.pop_front();
	customList.pop_back();

	cout << "---------iterator 반복문---------" << endl;
	for (it = customList.begin(); it != customList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	it = customList.begin();
	it = ++it;
	customList.insert(it, 1000);

	it = customList.end();
	it = --(--it);
	customList.erase(it);

	cout << "---------insert, erase 반복문---------" << endl;
	for (it = customList.begin(); it != customList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}
