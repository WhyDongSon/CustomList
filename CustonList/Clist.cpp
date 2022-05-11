#include "Clist.h"

template<typename T>
Clist<T> ::Clist() : nSise(0), iterator(nullptr)
{
	Dumynode = new Cnode<T>();
}

template<typename T>
Clist<T>::~Clist()
{
	if (Dumynode)
		delete Dumynode;
}
