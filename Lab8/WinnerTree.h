#pragma once

#ifndef WINNERTREE_H

#define WINNNERTREE_H

#include<iostream>

using namespace std;

class WinnerTree
{
public:
    WinnerTree(int* w)
    {
        for (int i = 0; w[i] != NULL; i++) length++;
        ls = new int[length];
        buf = new int[length];
        for (int i = 0; i<length; i++) buf[i] = w[i];
    }

    void race()
    {
        int current = length - 1;
        if (length % 2 == 0)
        {
            for (int i = length - 1; i >= 0;)
            {
                ls[current] = buf[i] < buf[i - 1] ? i : (i - 1);
                i -= 2;
                current--;
            }
        }
        else
        {
            for (int i = length - 1; i > 0;)
            {
                ls[current] = buf[i] < buf[i - 1] ? i : (i - 1);
                i -= 2;
                current--;
            }
            ls[current] = buf[0];
            current;
        }
        for (int i = length - 1; current > 0;)
        {
            ls[current] = ls[i] < ls[i - 1] ? i : (i - 1);
            i -= 2;
            current--;
        }

        ls[0] = ls[1];
    }
private:
	int* ls;
	int* buf;
    int length = 0;
	int MIN = -1;
};
#endif

