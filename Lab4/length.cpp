//ʱ�临�Ӷ�ΪO(n)

struct Node
{
	Node* line;
	int Data;
};

Node* first;

int getLength()
{
	int length = 0;
	if (first == NULL) return 0;//�ж������Ƿ�Ϊ��
	int* temp = first;
	while (temp!=NULL)
	{
		length++;
		temp = temp -> line;
	}
	return length;
}