//����ʤ����������ʱ��Ϊlog��k����֮�����ʤ����ת��Ϊ������������ʱ��Ϊk��������ʱ��ΪO��k����
#include<iostream>
using namespace std;

int* loserTree(int* b)
{
	int length = 0;
	for (int i = 0; b[i] != NULL; i++)
	{
		length++;
	}
    int* temp = new int[length * 2];
    for (int i = length * 2 - 1; i >= length; i--) temp[i] = b[i - length];
    int current = length - 1;

    for (int i = length - 1; current > 0;)
    {
        temp[current] = temp[i] < temp[i - 1] ? temp[i] : temp[i - 1];
        i -= 2;
        current--;
    }
    temp[0] = temp[1];

    //ת��ʹʤ����תΪ������
    for (int i = 1; i < length; i++)
    {
        if (temp[i] == temp[i * 2]) temp[i] = temp[i * 2 + 1];
        else temp[i] = temp[i * 2];
    }

}