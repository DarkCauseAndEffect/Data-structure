//�˴�ʹ�õ�AdjacencyLists�༴Ϊ������ҵP340 (9)����ɵ��ڽӱ����
#include<iostream>
#include<queue>

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
			cout << "�������" << i + 1 << "����" << endl;
			cin >> v1 >> v2;
			temp[i].v1 = v1;
			temp[i].v2 = v2;
		}

	}
	void create()
	{
		int current = 0;
		//�����е����graph��
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
		//��graph�еĵ��Ž�����С���������
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

		//�����ڽӱ�
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
		cout << "�ڽӱ�Ϊ��" << endl;
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

	void BFS(int V)
	{
		int Max = graph[v - 1].vertex;//�õ����ŵ����ֵ�Թ���visited����
		int max = Max + 1;//ʹvisited�����ܹ�����0-Max��Max+1������
		int* visited = new int[max];
		for (int i = 0; i <= Max; i++)
		{
			visited[i] = 0;
		}
		visited[V] = 1;
		
		list* current = NULL;
		queue<int> q;
		q.push(V);

		while (!q.empty())
		{
			V = q.front();
			q.pop();
			for (int i = 0; i < v; i++)
			{
				if (graph[i].vertex == V)
				{
					current = graph[i].l;
					break;
				}
			}

			while (current != NULL)
			{
				if (visited[current->vertex] == 0)
				{
					q.push(current->vertex);
					visited[current->vertex] = 1;
				}
				current = current->l;
			}
		}
		current = NULL;

		cout << "����������£�" << endl;
		for (int i = 0; i <= Max; i++)
		{
			if (visited[i] == 1) cout << i << " ";
		}
		cout << endl;

		delete[]visited;
	}

private:
	int e = 0;
	int v = 0;
	list* graph = NULL;
	Edge* temp = NULL;//���ڴ洢�û�����ı�
};

int main()
{
	int edge, vertex;
	cout << "������������Ҫ�������ڽӱ�ı����Ͷ�����" << endl;
	cin >> edge >> vertex;

	AdjacencyLists test(edge, vertex);
	test.fillTemp();

	//�����ڽӱ�Ĺ���
	test.create();

	//��ӡ�ڽӱ�
	test.print();

	int v;
	cout << "��������Ҫ���������Ŀ�ʼ�ڵ���" << endl;
	cin >> v;
	test.BFS(v);

	system("pause");
	return 0;
}