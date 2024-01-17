#include<iostream>

using namespace std;

struct List
{
	int num = 0;
	List* l = NULL;
};

void ListInsert(List* begin, int value)
{
	if (begin == NULL)
	{
		begin->num = value;
		return;
	}
	//为value增加一个节点
	List* add;
	add->l = begin;
	begin = add;
	List* current = begin;
	List* temp = begin->l;
	while (value > temp->num)
	{
		current->num = temp->num;
		temp = temp->l;
		current = current->l;
	}
	current->num = value;
	current = NULL;
	temp = NULL;
}