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

	for (auto it = list.begin() ; it != list.end() ; ++it)
	{
		list.push_back(*it);
	}
	
	_nSize = list._nSize;
}
#pragma endregion

#pragma region 소멸자
template<typename T>
Clist<T>::~Clist()
{
	for (int32 i = 0; i < _nSize; i++)
	{
		pop_back();
	}

	FreeDummyNode();
}
#pragma endregion

#pragma region 기본 함수
template<typename T>
void Clist<T>::pop_back()
{
	Cnode<T> *LastNode = Dumynode[static_cast<int32>(DumyNode::Last)]->GetPreAdress();

	DeleteNode(LastNode);
}

template<typename T>
void Clist<T>::push_back(const T& nElement)
{
	AddNode(Dumynode[static_cast<int32>(DumyNode::Last)], nElement);
}

template<typename T>
void Clist<T>::pop_front()
{
	Cnode<T> *FistNode = Dumynode[static_cast<int32>(DumyNode::First)]->GetNextAdress();

	DeleteNode(FistNode);
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

template<typename T>
T& Clist<T>::front()
{
	Cnode<T> *FirstNode = Dumynode[static_cast<int32>(DumyNode::First)]->GetNextAdress();

	return FirstNode->GetValue();
}

template<typename T>
T& Clist<T>::back()
{
	Cnode<T>* LastNode = Dumynode[static_cast<int32>(DumyNode::Last)]->GetPreAdress();

	return LastNode->GetValue();
}

template<typename T>
Citerator<T> Clist<T>::insert(Citerator<T>& it, T value)
{
	Cnode<T>* node = it.GetNode();
	it.SetNode(AddNode(node, value));

	return it;
}

template<typename T>
Citerator<T> Clist<T>::erase(Citerator<T>& it)
{
	Cnode<T>* node = it.GetNode();
	it.SetNode(DeleteNode(node));

	return it;
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
	for (int32 i = 0; i < static_cast<int32>(DumyNode::DumyNode_Max); i++)
	{
		delete Dumynode[i];
		Dumynode[i] = nullptr;
	}
}

template<typename T>
Cnode<T>* Clist<T>::AddNode(Cnode<T>* Pos, const T& nValue)
{
	Cnode<T>* newNode = new Cnode<T>(nValue);

	//새로운 노드
	newNode->SetPreAdress(Pos->GetPreAdress());
	newNode->SetNextAdress(Pos);
	//기존 노드
	Pos->GetPreAdress()->SetNextAdress(newNode);
	Pos->SetPreAdress(newNode);

	_nSize++;

	return newNode;
}

template<typename T>
Cnode<T>* Clist<T>::DeleteNode(Cnode<T>* Pos)
{
	Cnode<T>* PreNode = Pos->GetPreAdress();
	Cnode<T>* NextNode = Pos->GetNextAdress();

	PreNode->SetNextAdress(NextNode);
	NextNode->SetPreAdress(PreNode);

	if (Pos)
	{
		delete Pos;
		Pos = nullptr;
	}

	_nSize--;

	return NextNode;
}
#pragma endregion
