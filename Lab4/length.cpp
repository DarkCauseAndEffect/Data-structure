//时间复杂度为O(n)

struct Node
{
	Node* line;
	int Data;
};

Node* first;

int getLength()
{
	int length = 0;
	if (first == NULL) return 0;//判断链表是否为空
	int* temp = first;
	while (temp!=NULL)
	{
		length++;
		temp = temp -> line;
	}
	return length;
}