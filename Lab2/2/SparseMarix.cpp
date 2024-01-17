#include<iostream>
#include"SparseMatrix.h"
#include"MatrixTerm.h"

using namespace std;

SparseMatrix::SparseMatrix(int r, int c, int t)
{
	smArray = new MatrixTerm[terms];
	rows = r;
	cols = c;
	terms = t;
}

SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int* rowStart = new int[cols];
		for (int i = 0; i < cols; i++)
		{
			rowStart[i] = 0;
		}

		for (int i = 0; i < cols; i++) rowStart[i] = rowStart[i - 1] + smArray[i - 1].getCol() % 1;//�ڴ˴���rowSize��ΪsmArray[i - 1].getCol() % 1����Ϊ0�Ǿͼ�0������Ϊ0ʱ�ͼ�1

		for (int i = 0; i < terms; i++)
		{
			int j = rowStart[smArray[i].getCol()];
			b.smArray[j].setRow(smArray[i].getCol());
			b.smArray[j].setCol(smArray[i].getRow());
			smArray[i].setValue(smArray[i].getValue());
			rowStart[smArray[i].getCol()]++;
		}
	}
	return b;
}

MatrixTerm* SparseMatrix::getsmArray()
{
	return smArray;
}