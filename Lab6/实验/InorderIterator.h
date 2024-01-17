#pragma once

#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include<stack>

using namespace std;

template<class T>class Tree;
template<class T>class TreeNode;

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

	TreeNode<T>* getCurrent()
	{
		return current;
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

#endif