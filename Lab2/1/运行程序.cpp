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

	//分别打印两个多项式a，b
	cout << "多项式a为";
	print(a);
	cout << "多项式b为";
	print(b);
	//加法
	Polynomial c = b.Add(a);
    cout << "相加后的多项式为：";
	print(c);

	//乘法
	Polynomial d = a.Mul(b);
	cout << "相乘的多项式为";
	print(d);

	//取值
	cout << "当x取4.5时，多项式a的值为" << a.getValue(4.5) << endl;

	//用户输入多项式
	int number = 0;
	cout<<"请输入所需输入多项式的项数" << endl;
	cin >> number;
	Polynomial e(number);
	cout << "输入的多项式为：";
	print(e);

	system("pause");
	return 0;
}