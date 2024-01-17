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
		//ȷ����ϣ�����и�Ԫ��,���򱨴�
		if (table[temp] == NULL || table[temp]->first != k)
		{
			cout << "Not Found" << endl;
			return;
		}

		delete current;
		int a = temp;//��¼����Ҫ�ƶ�Ԫ��Ӧ���ƶ�����λ��
		int n = temp;//���ڶ�λ����ֹ���ѭ�� 

		temp = (temp + 1) % b;
		while (table[temp] != NULL && temp != n)//��������ָ����Ѿ�����������һ�κ�ѭ��ֹͣ
		{
			int m = (int)table[temp]->first % b;

			if ((temp > a && m > temp) || (a > temp && m > temp && a >= m) || (temp > a && temp > m && a >= m))
			{
				table[a] = table[temp];
				a = temp;
			}
			temp = (temp + 1) % b;
		}

		table[a] = NULL;//�����һ��Ԫ���Ƶ�ָ��λ�ú������һ��Ԫ�ص�ԭλ��Ϊ��
		return;
	}

private:
	pair<const K, E>** table;//��ϣ��
	int b;//����
};
//(1)˵����������Ҫɾ���ļ�¼����Ϊ����ļ�¼����ǰ��¼���ܽ���Ӧ�ö�Ӧ�ڴ˵ļ�¼��λ�ø�ռ�ݣ�ʹ�ö�Ӧ�ڴ˵ļ�¼��������ǰ��¼�ĺ���λ�ã���ˣ�ɾ����ǰ��¼����Ҫע����֮������м�¼��
//(2)�ڸ�ɾ�������£�get������������޸�
//(3)�¹ؼ��ְ��չ����������뼴��