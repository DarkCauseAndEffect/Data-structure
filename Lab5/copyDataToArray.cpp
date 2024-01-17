#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

template<class T>

T* copyDataToArray(list<T>l)
{
	int length = 0;
	for (auto i = l.begin(); i != l.end(); i++)
	{
		length++;
	}

	T* copyResult = new T[length];

	copy(l.begin(), l.end(), copyResult);

	return copyResult;
}