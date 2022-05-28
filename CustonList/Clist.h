#pragma once
template<typename T>
class Clist
{
public:
	//생성자
	Clist();
	Clist(int32 nSize);
	Clist(int32 nSize, const T& nNum);
	Clist(Clist& list);

	//소멸자
	virtual ~Clist();

	//기타 함수
	void push_front(const T& nElement);
	void pop_front();
	void push_back(const T& nElement);
	void pop_back();

	boolean empty() { return (_nSize == 0); }
	int32 size() { return _nSize; }

public:
	using iterator = Citerator<T>;
	iterator begin();
	iterator end();

private:
	void AddNode(Cnode<T>* Pos, const T& nValue);
	void DeleteNode(Cnode<T>* Pos);
	void CreateDummyNode();
	void FreeDummyNode();

private:
	Cnode<T> *Dumynode[static_cast<int32>(DumyNode::DumyNode_Max)] = {nullptr, nullptr};
	int32	 _nSize = 0;
};