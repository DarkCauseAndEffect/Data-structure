//比较：当parent的长度较小时，simple组合运行时间较短；而当parent的长度逐渐增长时，Weight组合的运行时间开始小于simple组合
//尤其是当parent中每个数据都要被查找时，Weight的运行时间会大大低于simple的组合
#include<iostream>
#include<windows.h>

using namespace std;

class Sets
{
public:
	Sets(int numberOfElements)
	{
		if (numberOfElements < 2) throw "Must have at least 2 element.";
		n = numberOfElements;
		parent = new int[n];
		//此处给parent数组赋值
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
		}
	}

	void SimpleUnion(int i, int j)
	{
		parent[i] = j;
	}
	void WeightUnion(int i,int j)
	{
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j])
		{
			parent[i] = j;
			parent[j] = temp;
		}
		else
		{
			parent[j] = i;
			parent[i] = temp;
		}
	}

	int SimpleFind(int i)
	{
		while (parent[i] >= 0) i = parent[i];
		return i;
	}
	int CollapsingFind(int i)
	{
		int r = i;
		while (parent[r] >= 0) r = parent[r];
		while (i != r)
		{
			int s = parent[i];
			parent[i] = r;
			i = s;
		}
		return r;
	}

private:
	int* parent;
	int n;
};


int main()
{
	int n = 1000;

	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);


	Sets test01(n);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	for (int i = 0; i < n; i += 3)
	{

		test01.SimpleUnion(i, i + 2);

	}


	for (int i = 0; i < n; i++)
	{
		test01.SimpleFind(i);
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "Simple组合程序执行时间：" << time * 1000 << "ms" << endl;

	Sets test02(n);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	for (int i = 0; i < n; i += 3)
	{

		test02.WeightUnion(i, i + 2);

	}


	for (int i = 0; i < n; i++)
	{
		test01.CollapsingFind(i);
	}

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "Weight组合程序执行时间：" << time * 1000 << "ms" << endl;

	system("pause");
	return 0;
}