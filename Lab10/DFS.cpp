#include<iostream>

using namespace std;

struct list
{
	int vertex = -1;
	list* l = NULL;
};

class AdjacencyLists
{
public:

	void DFS()
	{
		bool* visited = new bool[n];
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		//�������һ�д���
		cout << 0 << " ";

		DFS(0);

		delete[visited];
	}

	void DFS(int V)
	{
		visited[V] = true;

		list* current = NULL;
		for (int i = 0; graph[i] != NULL; i++)
		{
			if (graph[i]->vertex = V)
			{
				current = graph[i].l;
				break;
			}
		}

		while (current!=NULL)
		{
			if (!visited[current->vertex])
			{
				//�������һ�д���
				cout << current->vertex << "";

				DFS(current->vertex);

			}
			current = current->l;
		}
	}

private:
	int n = 0;//��¼�����������	
	list* graph = NULL;//graphΪ�ڽӱ�
	bool* visited;
};