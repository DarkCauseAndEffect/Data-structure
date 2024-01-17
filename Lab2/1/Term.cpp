#include<iostream>
#include"Term.h"

using namespace std;

void Term::setCoef(float coeficient)
{
	coef = coeficient;
}

float Term::getCoef()
{
	return coef;
}

void Term::setExp(int exponent)
{
	exp = exponent;
}

/*int Term::getExp()
{
	return exp;
}
*/