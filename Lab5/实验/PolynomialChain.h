#pragma once

#ifndef POLYNOMIALCHAIN_H
#define POLYNOMIALCHAIN_H

#include<iostream>

using namespace std;

struct PolynomialNode
{
	float coef = 0;
	int exp = 0;
	PolynomialNode* Link = NULL;
};

class PolynomialChain
{
public:
	friend istream& operator>>(istream& is, PolynomialChain& x);
	friend ostream& operator<< (ostream& os, PolynomialChain& x);

	PolynomialChain();
	PolynomialChain(const PolynomialChain& a);
	PolynomialChain& operator=(const PolynomialChain& a);
	PolynomialChain operator+(const PolynomialChain& b)const;
	PolynomialChain operator-(const PolynomialChain& b)const;
	PolynomialChain operator*(const PolynomialChain& b)const;
	float Evaluate(float x) const;
	~PolynomialChain();


private:
	PolynomialNode* first = new PolynomialNode;
	PolynomialNode* end = first;
};

#endif