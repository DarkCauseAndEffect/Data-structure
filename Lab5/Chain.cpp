#include<iostream>
#include<list>

using namespace std;

struct List
{
	List* next;
	int data;
};

class Chain
{
public:
	
	void rightMove(int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (r == NULL)
			{
				r = 0;
				break;
			}
			else
			{
				List* temp = r;
				r = r->next;
				temp->next = l;
				l = temp;
				delete[]temp;
			}
		}

	}

	void leftMove(int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (l == NULL)
			{
				l = 0;
				break;
			}
			else
			{
				List* temp = l;
				l = l->next;
				temp->next = r;
				r = temp;
				delete[]temp;
			}
		}
	}
private:
	List* l,*r;
};