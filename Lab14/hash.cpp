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
		while (table[temp] != NULL && temp < b)//���ݶ��������������ʵõ��ؼ���Ӧ�ô�ŵ�λ��
		{
			if (table[temp]->first > k) temp *= 2;
			else temp = temp * 2 + 1;
		}
		if (temp > b)//��������������������������ӱ��������Ӷ���ӹؼ���
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

	void expand()//�ӱ�����
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
	pair<const K, E>** table;//��ϣ��
	int b;//����
};