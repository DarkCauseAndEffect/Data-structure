//���̣��ҵ�������򣬵��˶��Ĳ�����50����ʱ�������ܹ��������У����ǵ�������Ϊ75������ʱ��������޷�����������֪���������������
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
	//����imove��jmove����
	int imove[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };
	int jmove[8] = {  1, 1, 1, 0,-1,-1,-1, 0 };

	int count[15][15] = {};	//�������������

	srand((unsigned)time(NULL));

	int k = 0;	//���������k
	int x = 50;//�ƶ�����
	count[9][9] = 1;//��ʼλ��
	int a = 9, b = 9;//a��ʾ�У�b��ʾ�У����Լ�¼����λ��
	for (int i = 0; i < x;i++) 
	{

		k = rand() % 8;

		if ((a + imove[k] < 15) && (a + imove[k] >= 0) && (b + imove[k] < 15) && (b + imove[k] >= 0))
		{
			a += imove[k];
			b += jmove[k];
			count[a][b] += 1;
		}
		else i--;
	}

	//��ӡ��ʵ������������ڵĽ����ͬʱ��ӡ����������������֮�ͣ�����ȷ����ȷִ����50��
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << count[i][j] << " ";
		}
		cout << endl;
	}
	int caculate = -1;//�˴���ֵΪ-1������0������Ϊ��ʼλ�ã�9,9����δ��ʼ�ƶ��Ǳ㱻��¼Ϊ1��ʾ��뵽���˴�����˼��㲽��Ӧ��ȥ1
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			caculate += count[i][j];
		}
	}
	cout << "��������������֮��Ϊ��" << caculate << endl;

	system("pause");
	return 0;
}