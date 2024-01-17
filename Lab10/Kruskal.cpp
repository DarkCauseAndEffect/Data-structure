#include<iostream>
#include<queue>

using namespace std;

//�˴�����Set���е�WeightedUnion��Collapsing�㷨������ʵ�ַ�ʽ����5.10��ɢ���ϱ�ʾ
class Set
{
public:
	void WeightedUnion(int i, int j) {}
	int CollapsingFind(int i)
	{
		return -1;
	};
private:
	int* parent;
	int n;
};

struct Edge
{
	int v1, v2;
};

struct TV
{
	int n = 0;//n�����ж�TV������ӵ���˼�����
	Edge* e = NULL;//�����м���ıߴ�����һ��Edge��������
};

void Kruskal(int v)//vΪͼ�еĵ�ĸ���
{
	Set s;
	queue<Edge> E;//����˴���queue��ʵ���˿α�5.6���е�С���ѣ�ʹ��queue��Ϊ�˲�����

	TV tv;
	int size = v - 1;//sizeΪtv���������
	tv.e = new Edge[size];

	while ((tv.n < v - 1) && (!E.empty()))
	{
		Edge temp = E.front();
		E.pop();

		if (s.CollapsingFind(temp.v1) != s.CollapsingFind(temp.v2))//���ÿα�����˵��ʵ�ַ��������������������ͬһ�����ϣ���ѡȡ������
		{
			tv.n++;
			s.WeightedUnion(temp.v1, temp.v2);//�������㲢���㵽ͬһ��������
			tv.e[tv.n - 1] = temp;//�ڹ����б�����ĵ� i ���߱����浽tv����e�еĵڣ�i - 1����
		}
	}

	if (tv.n < v - 1) cout << "no spanning tree" << endl;
	else
	{
		cout << "��С�����������£�" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << tv.e[i].v1 << " -- " << tv.e[i].v2 << endl;
		}
		cout << endl;
	}
}