//�ó����ʱ�临�Ӷ�ΪO(m * p)


#include<iostream>
#include<stack>

using namespace std;


//�������������ʾ8�����򣬷ֱ�ΪN,NE,E,SE,S,SW,W,NW
static int movei[8] = { -1,-1,0,1,1,1,0,-1 };//�б任
static int movej[8] = { 0,1,1,1,0,-1,-1,-1 };//�б任

offsets temp = { 1,1,0 };//��ʼ���Թ������λ��

struct offsets
{
	int i, j, dir;
};

//�Թ���0��ʾ����ͨ����1��ʾǽ��2��ʾ�޷���ͨ��·��3��ʾ����

bool Path(int** M, stack<offsets>&Item)
{
	while (!Item.empty())
	{
		offsets temp = Item.top();
		int tempi = temp.i;
		int tempj = temp.j;
		int tempdir = temp.dir;

		if (M[tempi][tempj] == 3)
		{
			return 1;
		}
		else if (M[tempi][tempj] == 0)
		{
			//����λ�ÿ����߹����򴢴��stack�в����λ�ý��еݹ��жϸ�λ���Ƿ���·����
			offsets temp1 = { tempi,tempj,0 };
			Item.push(temp1);
			if (Path(M, Item)) return 1;
			else
			{
				tempdir++;
				if (tempdir < 8)
				{
					tempi += movei[tempdir];
					tempj += movej[tempdir];
					temp = { tempi,tempj,tempdir };
					Item.pop();
					Item.push(temp);
				}
				//����ǰλ�ø��������޷���ͨ����Ѹ�λ�ü�Ϊ2�����Ƴ�stack�����������
				else
				{
					M[tempi][tempj] = 2;
					Item.pop();
				}
			}
		}
		else
		{
			//����ǰλ���߲�ͨ���͸ı䷽���Ҹ��ǵ�ԭ���޷��߹������ݴ����stack�е�λ��
			tempdir++;
			if (tempdir < 8)
			{
				tempi += movei[tempdir];
				tempj += movej[tempdir];
				temp = { tempi,tempj,tempdir };
				Item.pop();
				Item.push(temp);
			}
			//����ǰλ�ø��������޷���ͨ����Ѹ�λ�ü�Ϊ2�����Ƴ�stack�����������
			else
			{
				M[tempi][tempj] = 2;
				Item.pop();
			}
		}
	}

	return 0;

}