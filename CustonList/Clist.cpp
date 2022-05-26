#include "pch.h"
#include "Clist.h"
#include "Cliterator.h"

template<typename T>
Clist<T> ::Clist() : nSise(0), iterator(nullptr)
{
}

template<typename T>
Clist<T>::~Clist()
{
}
