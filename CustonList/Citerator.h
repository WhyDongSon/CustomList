#pragma once

template<typename T>
class Citerator
{
public:
	Citerator();
	Citerator(Cnode<T>* node);
	virtual ~Citerator();

	Citerator<T>& operator++();
	Citerator<T>  operator++(int);
	Citerator<T>& operator--();
	Citerator<T>  operator--(int);
	boolean operator==(const Citerator& node);
	boolean operator!=(const Citerator& node);
	T& operator*();

	Cnode<T>* GetNode() { return _node; }
	void	  SetNode(Cnode<T>* node) { _node = node; }

private:
	Cnode<T>* _node;
};