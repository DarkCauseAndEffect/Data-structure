#include<iostream>
#include"PolynomialChain.h"

using namespace std;

int main()
{
	PolynomialChain temp;
	PolynomialChain a;
	PolynomialChain b;

	int i = 0;
	cout << " �밴��ϵ����ָ��˳�����룬һ���ڵ�������ɺ�����0�Լ�������ڵ㣬����-1��ֹͣ����" << endl;
	cout << endl;
	cout << "������a������" << endl;
	while (1)
	{
		cin >> a;
		cin >> i;
		if (i == -1)
		{
			cout << "ֹͣ����" << endl;
			break;
		}
	}
	i = 0;	
	cout << "������b������" << endl;
	while (1)
	{
		cin >> b;
		cin >> i;
		if (i == -1)
		{
			cout << "ֹͣ����" << endl;
			break;
		}
	}
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	temp = a + b;
	cout << "a + b = " << temp << endl;
	temp = a - b;
	cout << "a - b = " << temp << endl;
	temp = a * b;
	cout << "a * b = " << temp << endl;
	int x = 1;
	cout << "��x=1ʱ��a��ֵΪ��" << a.Evaluate(x) << endl;
	a = b;
	cout << "��b��ֵ��a��a = " << a << endl;


	system("pause");
	return 0;
}