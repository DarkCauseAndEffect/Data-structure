//回答：该成员函数的复杂度为O(n)，n为QUEUE中储存的元素个数


#include<iostream>
#include<queue>
#include"QUEUE.h"

using namespace std;

queue<int> QUEUE::divide()
{
	queue<int> temp1;//从第一个开始的元素形成的队列存储在temp1中，然后在赋值到Item中以让用户得到
	queue<int>temp2;//剩下的元素形成的队列存储在temp2中，然后以返回值的形式让用户得到

	int count = Item.size();

	for (int i = 0; i < count; i++)
	{
		if (i % 2 == 0)
		{
			temp1.push(Item.front());
			Item.pop();
		}
		else
		{
			temp2.push(Item.front());
			Item.pop();
		}
	}

	//将temp1中的值复制到Item中
	while (temp1.size() != 0)
	{
		Item.push(temp1.front());
		temp1.pop();
	}

	return temp2;
}