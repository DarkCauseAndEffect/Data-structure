#pragma once

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<iostream>
#include"MatrixTerm.h"

class SparseMatrix
{
public:
	SparseMatrix(int r, int c, int t);
	SparseMatrix FastTranspose();

	void print();

	MatrixTerm* getsmArray();

private:
	int rows, cols, terms;
	MatrixTerm* smArray;
};

#endif