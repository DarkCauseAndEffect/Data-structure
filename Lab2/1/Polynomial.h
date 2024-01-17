#pragma once

#include<iostream>
#include"Term.h"

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
	Polynomial();
	Polynomial(int num);
	Polynomial(int sta,int fin);
	~Polynomial();

	Term* getTermarray();

	void setFree(int fre);
	void setStart(int sta);
	void setFinish(int fin);
	int getStart();
	int getFinish();
	int getFree();

	Polynomial Add(Polynomial a);

	Polynomial Mul(Polynomial a);

	float getValue(float a);

private:
	static Term* termarray;
	static int capacity;
	static int free;
	int start = 0, finish = 0;
};


#endif