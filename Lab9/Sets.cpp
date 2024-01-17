//�Ƚϣ���parent�ĳ��Ƚ�Сʱ��simple�������ʱ��϶̣�����parent�ĳ���������ʱ��Weight��ϵ�����ʱ�俪ʼС��simple���
//�����ǵ�parent��ÿ�����ݶ�Ҫ������ʱ��Weight������ʱ��������simple�����
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
		//�˴���parent���鸳ֵ
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	for (int i = 0; i < n; i += 3)
	{

		test01.SimpleUnion(i, i + 2);

	}


	for (int i = 0; i < n; i++)
	{
		test01.SimpleFind(i);
	}
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "Simple��ϳ���ִ��ʱ�䣺" << time * 1000 << "ms" << endl;

	Sets test02(n);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  

	for (int i = 0; i < n; i += 3)
	{

		test02.WeightUnion(i, i + 2);

	}


	for (int i = 0; i < n; i++)
	{
		test01.CollapsingFind(i);
	}

	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "Weight��ϳ���ִ��ʱ�䣺" << time * 1000 << "ms" << endl;

	system("pause");
	return 0;
}