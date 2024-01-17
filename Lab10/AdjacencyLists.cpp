#include<iostream>
#include<windows.h> 

using namespace std;

struct list
{
	int vertex = -1;
	list* l = NULL;
};
struct Edge
{
	int v1, v2;
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
	void fillTemp()
	{
		int v1 = -1, v2 = -1;
		for (int i = 0; i < e; i++)
		{
			cout << "请输入第" << i + 1 << "条边" << endl;
			cin >> v1 >> v2;
			temp[i].v1 = v1;
			temp[i].v2 = v2;
		}

	}
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
					}
					else
					{
						while (count->l != NULL)
						{
							count = count->l;
						}
						count->l = new list;
						count->l->vertex = temp[i].v2;
					}
				}

				if (temp[i].v2 == graph[j].vertex)
				{
					if (count == NULL)
					{
						graph[j].l = new list;
						graph[j].l->vertex = temp[i].v1;
					}
					else
					{
						while (count->l != NULL)
						{
							count = count->l;
						}
						count->l = new list;
						count->l->vertex = temp[i].v1;
					}
				}
				count = NULL;
			}
		}
	}
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

private:
	int e = 0;
	int v = 0;
	list* graph = NULL;
	Edge* temp = NULL;//用于存储用户输入的边
};

int main()
{
	int edge, vertex;
	cout << "请依次输入需要构建的邻接表的边数和顶点数" << endl;
	cin >> edge >> vertex;

	AdjacencyLists test(edge, vertex);
	test.fillTemp();


	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	//进行邻接表的构建
	test.create();

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;

	//打印邻接表
	test.print();

	system("pause");
	return 0;
}