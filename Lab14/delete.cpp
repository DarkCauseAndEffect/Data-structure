#include<iostream>
#include<utility>

using namespace std;

template<class K, class E>
class hashTable
{
public:
	int search(const K&) {}
	void erase(const K& k)
	{
		int temp = search(k);
		pair<const K, E>* current = table[temp];
		//确定哈希表中有该元素,否则报错
		if (table[temp] == NULL || table[temp]->first != k)
		{
			cout << "Not Found" << endl;
			return;
		}

		delete current;
		int a = temp;//记录所需要移动元素应该移动到的位置
		int n = temp;//用于定位，防止多次循环 

		temp = (temp + 1) % b;
		while (table[temp] != NULL && temp != n)//当遇到空指针或已经遍历了数组一次后，循环停止
		{
			int m = (int)table[temp]->first % b;

			if ((temp > a && m > temp) || (a > temp && m > temp && a >= m) || (temp > a && temp > m && a >= m))
			{
				table[a] = table[temp];
				a = temp;
			}
			temp = (temp + 1) % b;
		}

		table[a] = NULL;//将最后一个元素移到指定位置后，令最后一个元素的原位置为空
		return;
	}

private:
	pair<const K, E>** table;//哈希表
	int b;//除数
};
//(1)说明：当所需要删除的记录正好为溢出的记录，则当前记录可能将本应该对应于此的记录的位置给占据，使得对应于此的记录被移至当前记录的后面位置，因此，删除当前记录后，需要注意检查之后的所有记录。
//(2)在该删除函数下，get函数无需进行修改
//(3)新关键字按照规则正常插入即可