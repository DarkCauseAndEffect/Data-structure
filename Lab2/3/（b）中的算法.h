#pragma once

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix(int m, int n, int num);

	Matrix Add(Matrix x);

private:
	int A, B, number;//A��BΪ������к���,numberΪ�����з�0�����ݸ���
	int** a;//�洢�����0,1��
	int* b;//�洢���������
};

#endif