#pragma once

template<typename T>
class Cnode
{
public:
	Cnode();
	Cnode(const T& nValue);
	Cnode(T* PreAdress, T* NextAdress, const T& Data);
	virtual ~Cnode();

public:
	static void SetDummyNode(Cnode* First, Cnode* Last);
	void SetPreAdress(Cnode* Adress) { _PreAdress = Adress; }
	void SetNextAdress(Cnode* Adress) {_NextAdress = Adress; }
	Cnode* GetPreAdress() { return _PreAdress; }
	Cnode* GetNextAdress() { return _NextAdress; }
	T& GetValue() { return _pData; }

private:
	T  _pData = 0;
	Cnode* _PreAdress = nullptr;
	Cnode* _NextAdress = nullptr;
};
