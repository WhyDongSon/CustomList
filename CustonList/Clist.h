#pragma once

class Cnode;
class Cliterator;

template<typename T>
class Clist
{
	Clist();

	virtual ~Clist();
	
private:
	Cnode* firstDumynode = nullptr;
	Cnode* endDumynode = nullptr;
	Cliterator* iterator;
	int			nSise;
};

