#pragma once
#include "Cnode.h"
#include "Cliterator.h"

template<typename T>
class Clist
{
	Clist();

	virtual ~Clist();
	
private:
	Cnode<T>*		Dumynode;
	Cliterator  iterator;
	int			nSise;
};

