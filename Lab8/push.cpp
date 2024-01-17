//��ֵ�������n�ϴ�����ȶ���ʱ���ܹ��ø�С�Ĵ����ҵ�Ŀ��λ�ý��в���
template<class T>

class MinHeap :public MinPQ<T>
{
public:
	void Push(const T& e)
	{
		//�洢�ռ䲻������мӱ�
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