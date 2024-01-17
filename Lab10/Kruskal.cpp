#include<iostream>
#include<queue>

using namespace std;

//此处定义Set类中的WeightedUnion和Collapsing算法，具体实现方式见数5.10离散集合表示
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
	int n = 0;//n用于判断TV集合里拥有了几条边
	Edge* e = NULL;//将所有加入的边储存在一个Edge的数组中
};

void Kruskal(int v)//v为图中的点的个数
{
	Set s;
	queue<Edge> E;//假设此处的queue类实现了课本5.6堆中的小顶堆（使用queue是为了不报错）

	TV tv;
	int size = v - 1;//size为tv数组的容量
	tv.e = new Edge[size];

	while ((tv.n < v - 1) && (!E.empty()))
	{
		Edge temp = E.front();
		E.pop();

		if (s.CollapsingFind(temp.v1) != s.CollapsingFind(temp.v2))//采用课本上所说的实现方法，即两个点如果不在同一个集合，则选取该条边
		{
			tv.n++;
			s.WeightedUnion(temp.v1, temp.v2);//将两个点并运算到同一个集合中
			tv.e[tv.n - 1] = temp;//在过程中被加入的第 i 条边被储存到tv数组e中的第（i - 1）个
		}
	}

	if (tv.n < v - 1) cout << "no spanning tree" << endl;
	else
	{
		cout << "最小生成树入如下：" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << tv.e[i].v1 << " -- " << tv.e[i].v2 << endl;
		}
		cout << endl;
	}
}