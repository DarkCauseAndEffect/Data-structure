//该程序的时间复杂度为O(m * p)


#include<iostream>
#include<stack>

using namespace std;


//以下两个数组表示8个方向，分别为N,NE,E,SE,S,SW,W,NW
static int movei[8] = { -1,-1,0,1,1,1,0,-1 };//行变换
static int movej[8] = { 0,1,1,1,0,-1,-1,-1 };//列变换

offsets temp = { 1,1,0 };//初始化迷宫进入的位置

struct offsets
{
	int i, j, dir;
};

//迷宫中0表示可以通过，1表示墙，2表示无法走通的路，3表示出口

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
			//若该位置可以走过，则储存进stack中并与该位置进行递归判断该位置是否有路可走
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
				//若当前位置各个方向都无法走通，则把该位置记为2，并移除stack最上面的数据
				else
				{
					M[tempi][tempj] = 2;
					Item.pop();
				}
			}
		}
		else
		{
			//若当前位置走不通，就改变方向并且覆盖掉原来无法走过的数据储存的stack中的位置
			tempdir++;
			if (tempdir < 8)
			{
				tempi += movei[tempdir];
				tempj += movej[tempdir];
				temp = { tempi,tempj,tempdir };
				Item.pop();
				Item.push(temp);
			}
			//若当前位置各个方向都无法走通，则把该位置记为2，并移除stack最上面的数据
			else
			{
				M[tempi][tempj] = 2;
				Item.pop();
			}
		}
	}

	return 0;

}