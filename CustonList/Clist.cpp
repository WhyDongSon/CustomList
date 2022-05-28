#include "pch.h"
#include "Cnode.h"
#include "Citerator.h"
#include "Clist.h"

#pragma region 생성자
template<typename T>
Clist<T>::Clist()
{
	CreateDummyNode();

	_nSize = 0;
}

template<typename T>
Clist<T>::Clist(int32 nSize)
{
	CreateDummyNode();

	_nSize = nSize;
}

template<typename T>
Clist<T>::Clist(int32 nSize, const T& nNum)
{
	CreateDummyNode();

	_nSize = nSize;
}

template<typename T>
Clist<T>::Clist(Clist& list)
{
	CreateDummyNode();

	for (int32 i = 0; i < _nSize; i++)
	{

	}
	
	_nSize = list._nSize;
}
#pragma endregion

#pragma region 소멸자
template<typename T>
Clist<T>::~Clist()
{
	FreeDummyNode();

	for (int32 i = 0; i < _nSize; i++)
	{

	}
}
#pragma endregion

#pragma region 기본 함수
template<typename T>
void Clist<T>::pop_back()
{

}

template<typename T>
void Clist<T>::push_back(const T& nElement)
{
	AddNode(Dumynode[static_cast<int32>(DumyNode::Last)], nElement);
}

template<typename T>
void Clist<T>::pop_front()
{

}

template<typename T>
void Clist<T>::push_front(const T& nElement)
{
	AddNode(Dumynode[static_cast<int32>(DumyNode::First)]->GetNextAdress(), nElement);
}

template<typename T>
Citerator<T> Clist<T>::begin()
{
	Citerator<T> Result = (Dumynode[static_cast<int32>(DumyNode::First)]->GetNextAdress());

	return Result;
}

template<typename T>
Citerator<T> Clist<T>::end()
{
 	Citerator<T> Result = (Dumynode[static_cast<int32>(DumyNode::Last)]);
 
 	return Result;
}
#pragma endregion

#pragma region 커스텀 함수
//Private
template<typename T>
void Clist<T>::CreateDummyNode()
{
	Dumynode[static_cast<int32>(DumyNode::First)] = new Cnode<T>;
	Dumynode[static_cast<int32>(DumyNode::Last)] = new Cnode<T>;

 	Cnode<T>::SetDummyNode(Dumynode[static_cast<int32>(DumyNode::First)],
 		Dumynode[static_cast<int32>(DumyNode::Last)]);
}

template<typename T>
void Clist<T>::FreeDummyNode()
{
	//delete[] Dumynode;
}

template<typename T>
void Clist<T>::AddNode(Cnode<T>* Pos, const T& nValue)
{
	Cnode<T>* newNode = new Cnode<T>(nValue);

	//새로운 노드
	newNode->SetPreAdress(Pos->GetPreAdress());
	newNode->SetNextAdress(Pos);
	//기존 노드
	Pos->GetPreAdress()->SetNextAdress(newNode);
	Pos->SetPreAdress(newNode);

	_nSize++;
}

template<typename T>
void Clist<T>::DeleteNode(Cnode<T>* Pos)
{
	delete[] Pos;
	_nSize--;
}
#pragma endregion
