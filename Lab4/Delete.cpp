//时间复杂度为 O(n)


struct Node
{
	Node* line;
	int Data;
};

Node* first;

void Delete(Node* x)
{
	if (!first)
	{
		return;
	}
	Node* temp = first->line;
	Node* count = first;
	while (temp != NULL)
	{
		if (temp->Data == x->Data)
		{
			count->line = temp->line;
			temp->line = NULL;
			return;
		}
		temp = temp->line;
		count = count->line;
	}
	return;
}

//有序链表（升序）
void Insert(Node* x)
{
	if (!first)
	{
		return;
	}
	Node* temp = first->line;
	while (temp != NULL)
	{
		if (x->Data < temp->Data)
		{
			first->line = x;
			x->line = temp;
			temp = NULL;
			return;
		}
		temp = temp->line;
	}
}
