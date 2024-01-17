#include<queue>
#include"AdjacencyLists.h"

using namespace std;

class TopoIterator
{
public:
	TopoIterator(list* graph, int v)//graphΪָ��һ�������޻�ͼ���ڽӱ��ָ��,vΪ�����޻�ͼ�Ķ�����
	{
		g = graph;
		num = v;
		vertex = new int[v];
		//�����ж�����ȳ�ʼ��Ϊ0
		for (int i = 0; i < v; i++)
		{
			vertex[i] = 0;
		}
		list* temp = NULL;
		//�õ�ÿ����������
		for (int i = 0; i < v; i++)
		{
			temp = graph[i].l;
			while (temp != NULL)
			{
				vertex[temp->vertex]++;
				temp = temp->l;
			}
		}
		for (int i = 0; i < v; i++)
		{
			if (vertex[i] == 0)
			{
				ToOrder.push(i);
				vertex[i] = -1;//-1��ʾ�ö������Ϊ0���Ѿ������뵽������
			}
		}
		temp = NULL;
		if (ToOrder.empty()) throw "The graph has circle.";
	}

	TopoIterator& operator++()
	{
		int current = ToOrder.front();
		ToOrder.pop();
		cout << current << endl;
		list* temp = g[current].l;
		while (temp != NULL)
		{
			vertex[temp->vertex]--;
			temp = temp->l;
		}
		for (int i = 0; i < num; i++)
		{
			if (vertex[i] == 0)
			{
				ToOrder.push(i);
				vertex[i] = -1;
			}
		}
	}

private:
	list* g = NULL;
	int num = 0;
	queue<int> ToOrder;
	int* vertex = NULL;//����ÿ����������
};