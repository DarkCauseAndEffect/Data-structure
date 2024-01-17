//助教，我的这个程序，当运动的步数在50左右时，程序能够正常运行，但是当步数变为75或以上时，程序就无法输出结果，不知道是哪里出了问题
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
	//创建imove和jmove数组
	int imove[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };
	int jmove[8] = {  1, 1, 1, 0,-1,-1,-1, 0 };

	int count[15][15] = {};	//创建数组计数器

	srand((unsigned)time(NULL));

	int k = 0;	//创建随机数k
	int x = 50;//移动次数
	count[9][9] = 1;//初始位置
	int a = 9, b = 9;//a表示行，b表示列，用以记录蟑螂的位置
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

	//打印出实验结束后数组内的结果，同时打印出数组内所有数字之和，用以确定的确执行了50步
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << count[i][j] << " ";
		}
		cout << endl;
	}
	int caculate = -1;//此处赋值为-1而不是0，是因为初始位置（9,9）在未开始移动是便被记录为1表示蟑螂到过此处，因此计算步数应减去1
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			caculate += count[i][j];
		}
	}
	cout << "数组内所有数据之和为：" << caculate << endl;

	system("pause");
	return 0;
}