#include "pch.h"
#include "Cnode.h"
#include "Citerator.h"

template<typename T>
Citerator<T>::Citerator()
{
	_node = nullptr;
}
template<typename T>
Citerator<T>::Citerator(Cnode<T>* node)
{
	_node = node;
}

template<typename T>
Citerator<T>::~Citerator()
{
	_node = nullptr;
}

#pragma region 오버로딩 연산자
template<typename T>
Citerator<T>& Citerator<T>::operator++()
{
	this->_node = this->_node->GetNextAdress();
	return *(this);
}

template<typename T>
Citerator<T> Citerator<T>::operator++(int)
{
	Citerator<T> temp = *(this);
	this->_node = this->_node->GetNextAdress();

	return temp;
}

template<typename T>
Citerator<T>& Citerator<T>::operator--()
{
	this->_node = this->_node->GetPreAdress();
	return *(this);
}

template<typename T>
Citerator<T> Citerator<T>::operator--(int)
{
	Citerator<T> temp = *(this);
	this->_node = this->_node->GetPreAdress();

	return temp;
}

template<typename T>
boolean Citerator<T>::operator==(const Citerator& node)
{
	return node._node == _node;
}

template<typename T>
boolean Citerator<T>::operator!=(const Citerator& node)
{
	return node._node != _node;
}

template<typename T>
T& Citerator<T>::operator*()
{
	return  _node->GetValue();
}
#pragma endregion