#include<iostream>
#include"Polynomial.h"

using namespace std;

void print(Polynomial a)
{
	for (int i = a.getStart(); i <= a.getFinish(); i++)
	{
		if (i == a.getFinish()) cout << a.getTermarray()[i].getCoef() << "X^" << a.getTermarray()[i].getExp() << endl;
		else cout << a.getTermarray()[i].getCoef() << "X^" << a.getTermarray()[i].getExp() << " + ";
	}
}

int main()
{
	Polynomial a(0, 1), b(2, 4);
	
	a.getTermarray()[0].setCoef(2.5);
	a.getTermarray()[0].setExp(4);
	a.getTermarray()[1].setCoef(3.0);
	a.getTermarray()[1].setExp(1);

	b.getTermarray()[2].setCoef(4.0);
	b.getTermarray()[2].setExp(5);
	b.getTermarray()[3].setCoef(3.0);
	b.getTermarray()[3].setExp(4);
	b.getTermarray()[4].setCoef(6.0);
	b.getTermarray()[4].setExp(1);

	a.setFree(5);

	//�ֱ��ӡ��������ʽa��b
	cout << "����ʽaΪ";
	print(a);
	cout << "����ʽbΪ";
	print(b);
	//�ӷ�
	Polynomial c = b.Add(a);
    cout << "��Ӻ�Ķ���ʽΪ��";
	print(c);

	//�˷�
	Polynomial d = a.Mul(b);
	cout << "��˵Ķ���ʽΪ";
	print(d);

	//ȡֵ
	cout << "��xȡ4.5ʱ������ʽa��ֵΪ" << a.getValue(4.5) << endl;

	//�û��������ʽ
	int number = 0;
	cout<<"�����������������ʽ������" << endl;
	cin >> number;
	Polynomial e(number);
	cout << "����Ķ���ʽΪ��";
	print(e);

	system("pause");
	return 0;
}