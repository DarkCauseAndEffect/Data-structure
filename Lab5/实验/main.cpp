#include<iostream>
#include"PolynomialChain.h"

using namespace std;

int main()
{
	PolynomialChain temp;
	PolynomialChain a;
	PolynomialChain b;

	int i = 0;
	cout << " 请按照系数，指数顺序输入，一个节点输入完成后，输入0以继续输入节点，输入-1以停止输入" << endl;
	cout << endl;
	cout << "请输入a的内容" << endl;
	while (1)
	{
		cin >> a;
		cin >> i;
		if (i == -1)
		{
			cout << "停止输入" << endl;
			break;
		}
	}
	i = 0;	
	cout << "请输入b的内容" << endl;
	while (1)
	{
		cin >> b;
		cin >> i;
		if (i == -1)
		{
			cout << "停止输入" << endl;
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
	cout << "当x=1时，a的值为：" << a.Evaluate(x) << endl;
	a = b;
	cout << "把b赋值给a后，a = " << a << endl;


	system("pause");
	return 0;
}