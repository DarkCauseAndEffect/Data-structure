//�ش𣺸ó�Ա�����ĸ��Ӷ�ΪO(n)��nΪQUEUE�д����Ԫ�ظ���


#include<iostream>
#include<queue>
#include"QUEUE.h"

using namespace std;

queue<int> QUEUE::divide()
{
	queue<int> temp1;//�ӵ�һ����ʼ��Ԫ���γɵĶ��д洢��temp1�У�Ȼ���ڸ�ֵ��Item�������û��õ�
	queue<int>temp2;//ʣ�µ�Ԫ���γɵĶ��д洢��temp2�У�Ȼ���Է���ֵ����ʽ���û��õ�

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

	//��temp1�е�ֵ���Ƶ�Item��
	while (temp1.size() != 0)
	{
		Item.push(temp1.front());
		temp1.pop();
	}

	return temp2;
}