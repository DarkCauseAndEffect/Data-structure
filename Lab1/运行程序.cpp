#include<iostream>
#include<chrono>

using namespace std;
using namespace chrono;

time_point<high_resolution_clock> Start, End;
//auto Start = Clock::now(), End = Clock::now();

int BinarySearch(int* a, const int x, const int n)
{
	int left = 0, right = n - 1;

	Start = high_resolution_clock::now();
	
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle]) right = middle - 1;
		else if (x > a[middle]) left = middle + 1;
		else
		{
			End = high_resolution_clock::now();
			return middle;
		}
	}

	End = high_resolution_clock::now();

	return -1;
	
}

int main()
{
	int n = 0;
	cout << "请输入n的值" << endl;
	cin >> n;
	int* a = new int[n];

	double t = 0;
	for (int i = 0; i < n; i++)
	{
		*(a + i)= i;
	}

	for (int j = 1; j < n; j++)
	{
		BinarySearch(a, j, n);
		t += double(duration_cast<nanoseconds>(End - Start).count());
	}
	cout << "运行时间为："<<t/n<<"纳秒" << endl;


	a = NULL;
	system("pause");
	return 0;
}