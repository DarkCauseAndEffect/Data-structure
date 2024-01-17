#pragma once

#ifndef MINHEAP_H
#define MINHEAP_H

#include"MinPQ.h"

template<class T>

class MinHeap :public MinPQ<T>
{
public:
	MinHeap(int Capacity)
	{
		if (Capacity < 1) throw "Capacity must be >=1";
		capacity = Capacity;
		heapSize = 0;
		heap = new T[capacity + 1];
	}

	bool IsEmpty()
	{
		if (heapSize == 0) return 1;
		else return 0;
	}

	T Top()
	{
		return heap[1]
	}
	void Push(const T& e)
	{
		if (heapSize == capacity)
		{
			capacity *= 2;
			T* temp = new T[capacity];
			for (int i = 1; i <= heapSize; i++)
			{
				temp[i] = heap[i];
			}
			heap = temp;
			temp = NULL;
		}
		int temp = ++heapSize;
		while (temp != 1 && heap[temp / 2] > e)
		{
			heap[temp] = heap[temp / 2];
			temp /= 2;
		}
		heap[temp] = e;
	}
	void Pop()
	{
		if (IsE
			mpty()) throw"heap is empty";

		T last = heap[heapSize--];

		int temp = 1, child = 2;
		while (child <= heapSize)
		{
			if (child<heapSize && heap[child]>heap[child + 1]) child++;
			if (last <= heap[child]) break;

			heap[temp] = heap[child];
			temp = child;
			child *= 2;
		}
		heap[temp] = last;
	}


private:
	T* heap;
	int heapSize;
	int capacity;
};
#endif