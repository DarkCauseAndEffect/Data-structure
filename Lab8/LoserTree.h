#pragma once

#ifndef LOSERTREE_H

#define LOSERTREE_H

#include<iostream>

using namespace std;

class LoserTree
{
public:
	LoserTree(int* b)
	{
        for (int i = 0; b[i] != NULL; i++) length++;
        ls = new int[length * 2];
        buf = new int[length];
        for (int i = length * 2 - 1; i >= length; i--) ls[i] = b[i - length];
	}
    void race()
    {
        int current = length - 1;

        for (int i = length - 1; current > 0;)
        {
            ls[current] = ls[i] < ls[i - 1] ? ls[i] : ls[i - 1];
            i -= 2;
            current--;
        }
        ls[0] = ls[1];

        //转换使胜者树转为败者树
        for (int i = 1; i < length; i++)
        {
            if (ls[i] == ls[i * 2]) ls[i] = ls[i * 2 + 1];
            else ls[i] = ls[i * 2];
        }
    }
private:
	int* ls;
	int* buf;
	int length, ls;
	int MIN = -1;
};
#endif
