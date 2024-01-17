#include<iostream>
#include"Polynomial.h"
#include<math.h>

using namespace std;

Polynomial::Polynomial()
{
	start = finish = free;
}

//该函数为由用户输入多项式，其中num为用户所需输入的多项式的项数
Polynomial::Polynomial(int num)
{
	setStart(free);
	setFinish(free + num - 1);
	cout << "请依次由高次到低次输入多项式的系数和指数" << endl;
	for (int i = 0; i < num; i++)
	{
		int e;
		float c;
		cin >> c >> e;
		termarray[i + getStart()].setCoef(c);
		termarray[i + getStart()].setExp(e);
		free++;
	}
}

Polynomial::Polynomial(int sta, int fin)
{
	if (fin >= sta&&sta>=free)
	{
		start = sta;
		finish = fin;
	}
	else
	{
		cout << "输入的初始化数据错误" << endl;
		start = finish = free;
	}
}

Polynomial::~Polynomial()

{
}

Term* Polynomial::getTermarray()
{
	return termarray;
}

void Polynomial::setFree(int fre)
{
	free = fre;
}

void Polynomial::setStart(int sta)
{
	start = sta;
}

void Polynomial::setFinish(int fin)
{
	finish = fin;
}

int Polynomial::getStart()
{
	return start;
}

int Polynomial::getFinish()
{
	return finish;
}

int Polynomial::getFree()
{
	return free;
}

Polynomial Polynomial::Add(Polynomial a)
{
	Polynomial b;
	b.setStart(getFree());
	int length = 0;//用于记录生成b的多项式长度
	int location = start;
	int aLocation = a.getStart();

	while ((location <= finish) && (aLocation <= a.getFinish()))
	{
		if (termarray[location].getExp() == a.getTermarray()[aLocation].getExp())
		{
			b.getTermarray()[free].setExp(termarray[location].getExp());
			b.getTermarray()[free].setCoef(termarray[location].getCoef() + a.getTermarray()[aLocation].getCoef());
			free++;
			length++;
			location++;
			aLocation++;
		}
		else if (termarray[location].getExp() > a.getTermarray()[aLocation].getExp())
		{
			b.getTermarray()[free].setExp(termarray[location].getExp());
			b.getTermarray()[free].setCoef(termarray[location].getCoef());
			free++;
			length++;
			location++;
		}

		else 
		{
			b.getTermarray()[free].setExp(a.termarray[aLocation].getExp());
			b.getTermarray()[free].setCoef(a.termarray[aLocation].getCoef());
			free++;
			length++;
			aLocation++;
		}
	}

	for (; aLocation <= a.getFinish(); aLocation++)
	{
		b.getTermarray()[free].setExp(a.termarray[aLocation].getExp());
		b.getTermarray()[free].setCoef(a.termarray[aLocation].getCoef());
		free++;
		length++;
	}
	for (; location <= finish; location++)
	{
		b.getTermarray()[free].setExp(termarray[location].getExp());
		b.getTermarray()[free].setCoef(termarray[location].getCoef());
		free++;
		length++;
	}

	b.setFinish(b.getStart() + length - 1);
	return b;
}

Polynomial Polynomial::Mul(Polynomial a)
{
	Polynomial b;
	b.setStart(getFree());
	int length = 0;
	int ExpJudge = 0;

	for (int i = getStart(); i <= getFinish(); i++) 
	{
		for (int j = a.getStart(); j <= a.getFinish(); j++)
		{
			if (i == getStart())
			{
				getTermarray()[free].setExp(getTermarray()[i].getExp() + getTermarray()[j].getExp());
				getTermarray()[free].setCoef(getTermarray()[i].getCoef() * getTermarray()[j].getCoef());
				free++;
				length++;
			}
			else
			{
				ExpJudge = getTermarray()[i].getExp() + getTermarray()[j].getExp();
				int A = 0;
				for (int n = b.getStart(); n < b.getStart() + length; n++)
				{
					if (getTermarray()[n].getExp() == ExpJudge)
					{
						float B = getTermarray()[n].getCoef();
						getTermarray()[n].setCoef(getTermarray()[i].getCoef() * getTermarray()[j].getCoef() + B);
						A++;
						break;
					}
				}

				if (A == 0)
				{
					getTermarray()[free].setExp(getTermarray()[i].getExp() + getTermarray()[j].getExp());
					getTermarray()[free].setCoef(getTermarray()[i].getCoef() * getTermarray()[j].getCoef());
					free++;
					length++;
				}
			}
		}
	}

	b.setFinish(b.getStart() + length - 1);

	//对b进行次数由高到低的排序
	for (int i = b.getStart()+1; i < b.getFinish();)
	{
		if (b.getTermarray()[i].getExp() > b.getTermarray()[i + 1].getExp()) i++;
		else
		{
			int exp = 0;
			float coef = 0;
			for (int j = i;; j--)
			{
				if (b.getTermarray()[j].getExp() < b.getTermarray()[j + 1].getExp())
				{
					exp = b.getTermarray()[j].getExp();
					coef = b.getTermarray()[j].getCoef();
					b.getTermarray()[j].setExp(b.getTermarray()[j + 1].getExp());
					b.getTermarray()[j].setCoef(b.getTermarray()[j + 1].getCoef());
					b.getTermarray()[j + 1].setExp(exp);
					b.getTermarray()[j + 1].setCoef(coef);
				}
				else break;

			}
		}
	}

	return b;
}

float Polynomial::getValue(float a)
{
	float value = 0;
	for (int i = start; i <= finish; i++)
	{
		value += termarray[i].getCoef() * pow(a, termarray[i].getExp());
	}
	return value;
}

int Polynomial::capacity = 100;
Term* Polynomial::termarray = new Term[100];
int Polynomial::free = 0;