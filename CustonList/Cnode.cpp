#include "pch.h"
#include "Cnode.h"

#pragma region 持失切
template<typename T>
Cnode<T>::Cnode()
{
	T  _pData = NULL;
	T* _PreAdress = nullptr;
	T* _NextAdress = nullptr;
}

template<typename T>
Cnode<T>::Cnode(const T& nValue)
{
	_PreAdress = nullptr;
	_NextAdress = nullptr;
	_pData = nValue;
}

template<typename T>
Cnode<T>::Cnode(T* PreAdress, T* NextAdress, const T& Data)
{
	_PreAdress = PreAdress;
	_NextAdress = NextAdress;
	_pData = Data;
}
#pragma endregion

#pragma region 社瑚切
template<typename T>
Cnode<T>::~Cnode()
{

}
#pragma endregion

template<typename T>
void Cnode<T>::SetDummyNode(Cnode* First, Cnode* Last)
{
	First->_NextAdress = Last;
	Last->_PreAdress = First;
}