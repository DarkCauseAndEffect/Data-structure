#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int caculate(list<int>l)
{
	int result = 0;
	int temp1 = 0;
	int temp2 = 0;
	auto i = l.begin();
	auto j = ++++++++l.begin();
	while ((i != l.end()) && (j != l.end()))
	{
		result += *i * *j;
		i++;
		j++;
	}

	return result;
}