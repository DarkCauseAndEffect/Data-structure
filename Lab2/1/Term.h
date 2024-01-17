#pragma once

#include<iostream>

#ifndef TERM_H
#define TERM_H

class Term
{
public:
	void setCoef(float coefficient);
	float getCoef();

	void setExp(int exponent);
	int getExp()
	{
		return exp;
	}

private:
	float coef;
	int exp;
};

#endif