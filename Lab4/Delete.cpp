//ʱ�临�Ӷ�Ϊ O(n)


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

//������������
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
