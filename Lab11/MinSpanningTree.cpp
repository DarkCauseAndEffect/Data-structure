//ͨ���ڽӱ������ͼ��ʹ�����·���ķ���������С�������Ĺ���
#include<iostream>

using namespace std;

struct list
{
	int vertex = -1, length = 0;
	list* l = NULL;
};
struct Edge
{
	int v1 = -1, v2 = -1;
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
	//�û�����ߵĺ���
	void fillTemp()
	{
		int v1 = -1, v2 = -1, length = 0;
		for (int i = 0; i < e; i++)
		{
			cout << "�������" << i + 1 << "���߼����Ӧ��Ȩ��" << endl;
			cin >> v1 >> v2 >> length;
			temp[i].v1 = v1;
			temp[i].v2 = v2;
			temp[i].length = length;
		}

	}
	//�����ڽӱ���
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
	//��ӡ�ڽӱ���
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

	//����С�������ĺ���
	void MinSpanningTree()
	{
		int* TV = new int[v];//����5.10��ɢ���ϵķ���,���е�i��Ԫ�ش洢x��ʾ���ɱ��Ϊx�ĵ�ָ����Ϊi��·����ѡ����Ϊ��С�������ı�
		TV[0] = 0;

		int* dist = new int[v];
		//��ʼ��dist����
		dist[0] = 0;
		for (int i = 1; i < v; i++)
		{
			dist[i] = 999;//Ĭ��999Ϊ����󣬼�Ϊ�޷�����
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
					TV[temp->vertex] = i;

				}
				temp = temp->l;
			}
		}

		//��ӡ��С������
		for (int i = 0; i < v; i++)
		{
			cout << i << " " << TV[i] << endl;
		}
	}

private:
	int e = 0;
	int v = 0;
	list* graph = NULL;
	Edge* temp = NULL;//���ڴ洢�û�����ı�
};

int main()
{
	int e = 0, v = 0;
	cout << "��������������͵���" << endl;
	cin >> e >> v;
	AdjacencyLists test(e, v);
	test.fillTemp();
	test.create();
	test.print();
	test.MinSpanningTree();

	system("pause");
	return 0;
}