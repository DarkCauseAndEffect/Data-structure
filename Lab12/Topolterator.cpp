#include<queue>
#include"AdjacencyLists.h"

using namespace std;

class TopoIterator
{
public:
	TopoIterator(list* graph, int v)//graph为指向一个有向无环图的邻接表的指针,v为有向无环图的顶点数
	{
		g = graph;
		num = v;
		vertex = new int[v];
		//将所有顶点入度初始化为0
		for (int i = 0; i < v; i++)
		{
			vertex[i] = 0;
		}
		list* temp = NULL;
		//得到每个顶点的入度
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
				vertex[i] = -1;//-1表示该顶点入度为0且已经被输入到队列中
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
	int* vertex = NULL;//储存每个顶点的入度
};