#pragma once

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix(int m, int n, int num);

	Matrix Add(Matrix x);

private:
	int A, B, number;//A，B为矩阵的行和列,number为矩阵中非0的数据个数
	int** a;//存储矩阵的0,1项
	int* b;//存储矩阵的数据
};

#endif