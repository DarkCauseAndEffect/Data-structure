//AdjacencyLists类为有向图的邻接表，其中的Shortest为计算最短路径的函数
//在初始化dist数组时复杂度为O（n），n为节点数
//接下来进行邻接表的遍历，求得最短路径，而遍历的邻接表中有e条边，故遍历也最多进行e次操作，所以复杂度为O（e）
//因此该Shortest函数总复杂度为O（n+e）

#include<iostream>

using namespace std;

struct list
{
	int vertex = -1;
	int length = 0;
	list* l = NULL;
};
struct Edge
{
	int v1 = 0, v2 = 0;//此处v1、v2有顺序，表示v1->v2，即<v1,v2>
	int length = 0;
};

class AdjacencyLists
{
public:
	AdjacencyLists(int edge, int vertex)
	{
		e = edge;
		v = vertex;
		graph = new list[v];
		temp = new Edge[e];
	}
	//用户输入边的函数
	void fillTemp()
	{
		int v1 = -1, v2 = -1, length = 0;
		for (int i = 0; i < e; i++)
		{
			cout << "请输入第" << i + 1 << "条边及其对应的权重" << endl;
			cin >> v1 >> v2>>length;
			temp[i].v1 = v1;
			temp[i].v2 = v2;
			temp[i].length = length;
		}

	}
	//构建邻接表函数
	void create()
	{
		int current = 0;
		//将所有点存入graph中
		for (int i = 0; i < e; i++)
		{

			int count = 1;
			for (int j = 0; graph[j].vertex != -1; j++)
			{
				if (graph[j].vertex == temp[i].v1)
				{
					count = 0;
					break;
				}
			}
			if (count == 1)
			{
				graph[current].vertex = temp[i].v1;
				current++;
			}

			count = 1;
			for (int j = 0; graph[j].vertex != -1; j++)
			{
				if (graph[j].vertex == temp[i].v2)
				{
					count = 0;
					break;
				}
			}
			if (count == 1)
			{
				graph[current].vertex = temp[i].v2;
				current++;
			}
		}
		//对graph中的点标号进行由小到大的排序
		for (int i = 1; i < v; i++)
		{
			current = i;
			while (graph[current].vertex < graph[current - 1].vertex && (current - 1) >= 0)
			{
				int temp = graph[current - 1].vertex;
				graph[current - 1].vertex = graph[current].vertex;
				graph[current].vertex = temp;
				current--;
			}
		}

		//构建邻接表
		for (int i = 0; i < e; i++)
		{
			for (int j = 0; j < v; j++)
			{
				list* count = graph[j].l;
				if (temp[i].v1 == graph[j].vertex)
				{
					if (count == NULL)
					{
						graph[j].l = new list;
						graph[j].l->vertex = temp[i].v2;
						graph[j].l->length = temp[i].length;
					}
					else
					{
						while (count->l != NULL)
						{
							count = count->l;
						}
						count->l = new list;
						count->l->vertex = temp[i].v2;
						count->l->length = temp[i].length;
					}
				}
				count = NULL;
			}
		}
	}
	//打印邻接表函数
	void print()
	{
		cout << "邻接表为：" << endl;
		for (int i = 0; i < v; i++)
		{
			cout << graph[i].vertex;
			list* temp = graph[i].l;
			while (temp != NULL)
			{
				cout << "->" << temp->vertex;
				temp = temp->l;
			}
			cout << endl;
		}
		cout << endl;
	}
	//求最短路径的函数
	void ShortestPath()
	{
		int* dist = new int[v];
		//初始化dist数组
		dist[0] = 0;
		for (int i = 1; i < v; i++)
		{
			dist[i] = 999;//默认999为无穷大，即为无法到达
		}

		list* temp = graph[0].l;

		for (int i = 0; i < v; i++)
		{
			temp = graph[i].l;
			while (temp != NULL)
			{
				if ((dist[i] + temp->length) < dist[temp->vertex])
				{
					dist[temp->vertex] = dist[i] + temp->length;
				}
				temp = temp->l;
			}
		}

		cout<<"计算出的最短路径为："<<endl;
		for (int i = 0; i < v; i++)
		{
			cout << i << "  " << dist[i] << endl;
		}
	}

private:
	int e = 0;
	int v = 0;
	list* graph = NULL;//存储构建的邻接表
	Edge* temp = NULL;//用于存储用户输入的边
};

int main()
{
	int e = 0, v = 0;
	cout << "请依次输入边数和点数" << endl;
	cin >> e >> v;
	AdjacencyLists test(e,v);
	test.fillTemp();
	test.create();
	test.print();
	test.ShortestPath();

	system("pause");
	return 0;
}