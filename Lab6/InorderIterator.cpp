#include<iostream>
#include<stack>

using namespace std;

template<class T>class Tree;
template<class T>class InorderIterator;

template<class T>

class TreeNode
{
	friend class Tree<T>;
private:
	TreeNode<T>* left;
	TreeNode<T>* right;
	T data;
};

template<class T>
class Tree
{
private:
	TreeNode<T>* root;
};

template<class T>

class InorderIterator
{
public:
	InorderIterator(TreeNode<T>* r)
	{
		current = r;
		while (current != NULL)
		{
			temp.push(current);
			current = current->getLeft();
		}
		if (!temp.empty())
		{
			current = temp.top();
			temp.pop();
		}
	}

	InorderIterator& operator++()
	{
		current = current->getRight();

		while (current != NULL)
		{
			temp.push(current);
			current = current->getLeft();
		}
		if (!temp.empty())
		{
			current = temp.top();
			temp.pop();
		}
		else
		{
			current = NULL;
		}
		return *this;
	}

private:
	TreeNode<T>* current;
	stack<TreeNode<T>*> temp;
};
