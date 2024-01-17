#include<iostream>

using namespace std;

struct DblListNode
{
	DblListNode* left, * right;
	int Data;
};

class DblList
{
public:
	void Concatenate(DblList m);
	DblListNode* getFirst();
	DblListNode* getEnd();
	~DblList();

private:
	DblListNode* first;
};

void DblList::Concatenate(DblList m)
{
	DblListNode* temp = getEnd();
	temp->right = m.getFirst();
	m.getFirst()->left = temp->left->right;
	m.~DblList();
}

DblListNode* DblList::getFirst()
{
	return first;
}

DblListNode* DblList::getEnd()
{
	DblListNode* temp = first;
	while (temp != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

DblList::~DblList()
{
	delete[]first;
}