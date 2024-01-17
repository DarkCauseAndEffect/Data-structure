#include<iostream>
#include"£¨b£©ÖĞµÄËã·¨.h"

using namespace std;

Matrix::Matrix(int m, int n, int num)
{
	A = m;
	B = n;
	number = num;
	int** a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		 a[i] = new int[n];
	}

	int* b = new int[num];
}

Matrix Matrix::Add(Matrix x)
{
	int count = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B; j++)
		{
			if (a[i][j] + x.a[i][j] == 0) continue;
			else count++;
		}
	}
	Matrix y(A, B, count);

	count = 0;
	int countX = 0;
	int countY = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B; j++)
		{
			if ((a[i][j] == 1) && (x.a[i][j] == 1))
			{
				y.a[i][j] = 1;
				y.b[countY] = b[count] + x.b[countX];
				count++;
				countX++;
				countY++;
			}
			else if ((a[i][j] == 0) && (x.a[i][j] == 1))
			{
				y.a[i][j] = 1;
				y.b[countY] = x.b[countX];
				countX++;
				countY++;

			}
			else if ((a[i][j] == 1) && (x.a[i][j] == 0))
			{
				y.a[i][j] = 1;
				y.b[countY] = b[count];
				count++;
				countY++;
			}
			else if ((a[i][j] == 0) && (x.a[i][j] == 0))
			{
				y.a[i][j] = 0;
			}
		}
	}

	return y;
}