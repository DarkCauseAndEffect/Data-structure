#include<iostream>
#include<queue>

using namespace std;

class Plane
{
public:
	int Id = -1;
	int Time = -1;
	int leftTime=-1;
};

class takeOff
{
public:
	int Id;
	int Time;

};

int main()
{
	queue<Plane>W1, W2, W3;
	queue<takeOff> T1, T2, T3;

	int IdO[25] = {};//��������
	int IdE[25] = {};//ż������
	for (int i = 0; i < 25; i++)//��ֵ
	{
		IdO[i] = 2 * i + 1;
		IdE[i] = 2 * i;
	}

	Plane temp;
	takeOff Temp;
	int O=0, E=0;//O,E�ֱ�����IdO��IdE������������ɻ�Id��ֵ
	double waitingLeftTime = 0, waitingTime = 0, landTime = 0;
	int danger = 0;
	int standardTime = 0;

	int Time[7] = { 3,2,0,3,1,2,2 };

	for (int i = 0; i < 7; i++)
	{
		temp.Time = Time[i];
		temp.leftTime = Time[i];
		temp.Id = IdO[O];
		O++;
		waitingTime+=Time[i];

		standardTime++;

		if (i == 0) W1.push(temp);
		else
		{
			if (temp.Time == 0)
			{
				W3.push(temp);
				danger++;
				Temp.Id = IdE[E];
				T3.push(Temp);
				E++;
			}
			else if (temp.Time != 0 && temp.Time >= W1.back().leftTime) W1.push(temp);
			else if (temp.Time != 0 && temp.Time < W1.back().leftTime) W2.push(temp);
		}
		if (W1.size() > 0)
		{
			if (W1.front().leftTime == 0)
			{
				int t = W1.front().Time;
				waitingLeftTime += W1.front().leftTime;
				Temp.Id = IdE[E];
				T1.push(Temp);
				W1.pop();
				E++;
				W1.front().leftTime = W1.front().leftTime - t + 1;

				if (W1.front().leftTime == 0)
				{
					int t = W1.front().Time;
					waitingLeftTime += W1.front().leftTime;
					Temp.Id = IdE[E];
					T2.push(Temp);
					W1.pop();
					E++;
					W1.front().leftTime = W1.front().leftTime - t + 1;

					if (W1.front().leftTime == 0)
					{
						int t = W1.front().Time;
						waitingLeftTime += W1.front().leftTime;
						Temp.Id = IdE[E];
						T3.push(Temp);
						W1.pop();
						E++;
						W1.front().leftTime = W1.front().leftTime - t + 1;
					}
				}
			}
			W1.front().leftTime--;
		}
		if (W2.size() > 0)
		{
			if(W2.front().leftTime == 0)
			{
				int t = W2.front().Time;
				waitingLeftTime += W2.front().leftTime;
				Temp.Id = IdE[E];
				T2.push(Temp);
				W2.pop();
				E++;
				W2.front().Time = W2.front().Time - t + 1;

				if (W2.front().leftTime == 0)
				{
					int t = W2.front().Time;
					waitingLeftTime += W2.front().leftTime;
					Temp.Id = IdE[E];
					T1.push(Temp);
					W2.pop();
					E++;
					W2.front().Time = W2.front().Time - t + 1;

					if (W2.front().leftTime == 0)
					{
						int t = W2.front().Time;
						waitingLeftTime += W2.front().leftTime;
						Temp.Id = IdE[E];
						T3.push(Temp);
						W2.pop();
						E++;
						W2.front().Time = W2.front().Time - t + 1;
					}
				}
			}
			W2.front().leftTime--;
		}
		if (T1.size() + T2.size() + T3.size() == 0)
		{
			landTime = 0; 
			waitingLeftTime = 0;
		}
		else
		{
			landTime += T1.size() + T2.size() + T3.size();
			landTime /= T1.size() + T2.size() + T3.size();
			waitingLeftTime /= T1.size() + T2.size() + T3.size();
		}
		if (T1.size() + T2.size() + T3.size() + W1.size() + W2.size() + W3.size() == 0) waitingTime = 0;
		else waitingTime /= T1.size() + T2.size() + T3.size() + W1.size() + W2.size() + W3.size();

		
		cout << "�ܵ�1�ȴ�������" << W1.size() << "�ܷɻ�" << endl;
		cout << "�ܵ�2�ȴ�������" << W2.size() << "�ܷɻ�" << endl;
		cout << "�ܵ�1��½������" << T1.size() << "�ܷɻ�" << endl;
		cout << "�ܵ�2��½������" << T2.size() << "�ܷɻ�" << endl;
		cout << "�ܵ�3��½������" << T3.size() << "�ܷɻ�" << endl;
		cout << "��ɵ�ƽ���ȴ�ʱ��Ϊ" << landTime << endl;
		cout << "��½��ƽ���ȴ�ʱ��Ϊ" << waitingTime << endl;
		cout << "��½��ƽ��ʣ��ʱ��Ϊ" << waitingLeftTime << endl;
		cout << "��������ķɻ���Ϊ" << danger << endl;
		cout << endl;

	}

	system("pause");
	return 0;
}