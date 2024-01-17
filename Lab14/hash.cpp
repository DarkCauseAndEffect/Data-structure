#include<iostream>
#include<utility>
#include<string>

using namespace std;

template<class K, class E>
class hashTable
{
public:
	void insert(const K& k)
	{
		int temp = k % b;
		while (table[temp] != NULL && temp < b)//根据二叉搜索树的性质得到关键字应该存放的位置
		{
			if (table[temp]->first > k) temp *= 2;
			else temp = temp * 2 + 1;
		}
		if (temp > b)//如果数组容量不够，则调用数组加倍函数，从而添加关键字
		{
			expand();
		}
		table[temp] = k;
	}
	int search(const K& k)
	{
		int temp = k % b;
		while (table[temp]->first != k && table[temp] != NULL)
		{
			if (table[temp]->first > k) temp *= 2;
			else temp = temp * 2 + 1;
		}
		if (table[temp] == NULL)
		{
			cout << "Not Found" << endl;
			return 0;
		}
		return temp;
	}

	void expand()//加倍数组
	{
		pair<K, E>** temp = new pair<K, E>*[2b];
		for (int i = 0; i < b; i++)
		{
			temp[i] = table[i];
		}
		table = temp;
		temp = NULL;
	}
private:
	pair<const K, E>** table;//哈希表
	int b;//除数
};