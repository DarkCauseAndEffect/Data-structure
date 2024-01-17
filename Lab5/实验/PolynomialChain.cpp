#include<iostream>
#include"PolynomialChain.h"
#include<math.h>

using namespace std;

istream& operator>>(istream& is, PolynomialChain& x)
{
	is >> x.end->coef >> x.end->exp;
	x.end->Link = new PolynomialNode;
	x.end = x.end->Link;
	return is;
}

ostream& operator<<(ostream& os, PolynomialChain& x)
{
	for (auto i = x.first;i!=x.end;i=i->Link)
	{
		if (i == x.first)
		{
			cout << i->coef << "X^" << i->exp;
		}
		else cout << "+" << i->coef << "X^" << i->exp;
	}
	return os;
}

PolynomialChain::PolynomialChain()
{
}

PolynomialChain::PolynomialChain(const PolynomialChain& a)
{
	for (auto i = a.first;i!=a.end;i=i->Link)
	{
		this->end->coef = i->coef;
		this->end->exp = i->exp;
		this->end->Link = new PolynomialNode;
		this->end = this->end->Link;
	}
}

PolynomialChain& PolynomialChain::operator=(const PolynomialChain& a)
{
	while (first->Link != NULL)
	{
		auto temp = first;
		first = temp->Link;
		delete[]temp;
	}

	for (auto i = a.first;i!=a.end; i = i->Link)
	{
		this->end->coef = i->coef;
		this->end->exp = i->exp;
		this->end->Link = new PolynomialNode;
		this->end = this->end->Link;
	}
	return *this;
}

PolynomialChain PolynomialChain::operator+(const PolynomialChain& b) const
{
	PolynomialChain temp;
	auto tempb = b.first;
	auto tempt = this->first;
	while ((tempb != b.end) && (tempt != this->end))
	{
		if (tempb->exp == tempt->exp)
		{
			temp.end->coef = tempb->coef + tempt->coef;
			temp.end->exp = tempb->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempb = tempb->Link;
			tempt = tempt->Link;
		}
		else if (tempb->exp > tempt->exp)
		{
			temp.end->coef = tempb->coef;
			temp.end->exp = tempb->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempb = tempb->Link;
		}

		else
		{
			temp.end->coef = tempt->coef;
			temp.end->exp = tempt->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempt = tempt->Link;
		}
	}

	for (; tempb!=b.end; tempb=tempb->Link)
	{
		temp.end->coef = tempb->coef;
		temp.end->exp = tempb->exp;
		temp.end->Link = new PolynomialNode;
		temp.end = temp.end->Link;
	}
	for (; tempt!=this->end; tempt=tempt->Link)
	{
		temp.end->coef = tempt->coef;
		temp.end->exp = tempt->exp;
		temp.end->Link = new PolynomialNode;
		temp.end = temp.end->Link;
	}
	return temp;
}

PolynomialChain PolynomialChain::operator-(const PolynomialChain& b) const
{

	PolynomialChain temp;
	auto tempb = b.first;
	auto tempt = this->first;
	while ((tempb != b.end) && (tempt != this->end))
	{
		if (tempb->exp == tempt->exp)
		{
			temp.end->coef = tempt->coef - tempb->coef;
			temp.end->exp = tempb->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempb = tempb->Link;
			tempt = tempt->Link;
		}
		else if (tempb->exp > tempt->exp)
		{
			temp.end->coef = -tempb->coef;
			temp.end->exp = tempb->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempb = tempb->Link;
		}

		else
		{
			temp.end->coef = tempt->coef;
			temp.end->exp = tempt->exp;
			temp.end->Link = new PolynomialNode;
			temp.end = temp.end->Link;
			tempt = tempt->Link;
		}
	}

	for (; tempb != b.end; tempb = tempb->Link)
	{
		temp.end->coef = -tempb->coef;
		temp.end->exp = tempb->exp;
		temp.end->Link = new PolynomialNode;
		temp.end = temp.end->Link;
	}
	for (; tempt != this->end; tempt = tempt->Link)
	{
		temp.end->coef = tempt->coef;
		temp.end->exp = tempt->exp;
		temp.end->Link = new PolynomialNode;
		temp.end = temp.end->Link;
	}
	return temp;
}

PolynomialChain PolynomialChain::operator*(const PolynomialChain& b) const
{
	PolynomialChain Temp;



	for (auto tempt = first; tempt != end; tempt = tempt->Link)
	{
		for (auto tempb = b.first;tempb!=b.end; tempb = tempb->Link)
		{
			if (tempt==this->first)
			{
				Temp.end->coef = tempt->coef * tempb->coef;
				Temp.end->exp = tempt->exp + tempb->exp;
				Temp.end->Link = new PolynomialNode;
				Temp.end = Temp.end->Link;
			}
			else
			{
				int judgeExp = tempt->exp + tempb->exp;
				int A = 0;
				for (auto n = Temp.first; n != Temp.end; n = n->Link)
				{
					if (n->exp == judgeExp)
					{
						n->coef += tempb->coef * tempt->coef;
						A++;
						break;
					}
				}

				if (A == 0)
				{
					Temp.end->coef = tempt->coef * tempb->coef;
					Temp.end->exp = tempt->exp + tempb->exp;
					Temp.end->Link = new PolynomialNode;
					Temp.end = Temp.end->Link;
				}
			}
		}
	}

	//对Temp进行次数由高到低的排序
	auto location = Temp.first;//用以记录当前判断节点的前一个节点
	for (auto temp = Temp.first->Link; temp != end;)
	{
		if (temp == NULL)break;
		if (temp->exp <location->exp)
		{
			temp = temp->Link;
			location = location->Link;
		}
		else
		{
			auto judgeOrder = Temp.first;
			while(judgeOrder)
			{
				//交换节点
				if ((judgeOrder->exp > temp->exp) && (judgeOrder->Link->exp < temp->exp))
				{
					auto temp1 = new PolynomialNode;
					auto temp2 = judgeOrder->Link;
					temp1 = temp;
					judgeOrder->Link = temp1;
					temp1->Link = temp2;
					//删除现在temp所指的节点
					auto deleteNode = temp;
					temp = temp->Link;
					deleteNode = NULL;
					temp2 = NULL;
				}
				else judgeOrder=judgeOrder->Link;
			}
		}
	}

	return Temp;
}

float PolynomialChain::Evaluate(float x) const
{
	float temp = 0;
	auto i = this->first;
	while (i != end)
	{
		temp += i->coef * pow(x, i->exp);
		i = i->Link;
	}
	return temp;
}

PolynomialChain::~PolynomialChain()
{
	while (first != NULL)
	{
		PolynomialNode* temp = first;
		first = first->Link;
		temp = NULL;
	}
	if (end != NULL) end=NULL;
}
