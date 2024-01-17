#pragma once

#ifndef MATRIXTERM_H
#define MATRIXTERM_H

#include<iostream>
#include"SparseMatrix.h"

class MatrixTerm
{
	friend class SparesMatrix;
public:
	void setRow(int a)
	{
		row = a;
	}

	void setCol(int a)
	{
		col = a;
	}

	void setValue(int a)
	{
		value = a;
	}

	int getRow()
	{
		return row;
	}

	int getCol()
	{
		return col;
	}

	int getValue()
	{
		return value;
	}

private:
	int row, col, value;
};

#endif