//价值：在面对n较大的优先队列时，能够用更小的代价找到目标位置进行插入
template<class T>

class MinHeap :public MinPQ<T>
{
public:
	void Push(const T& e)
	{
		//存储空间不够则进行加倍
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
		while (temp != 1 && heap[temp / 4] < e)
		{
			heap[temp] = heap[temp / 4];
			temp /= 4;
		}
		if(heap[temp / 2] < e)
		{
			heap[temp] = heap[temp / 2];
			temp /= 2;
		}
		heap[temp] = e;
	}

private:
	T* heap;
	int heapSize;
	int capacity;
};