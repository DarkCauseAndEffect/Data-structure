#pragma once

#ifndef PREORDER_ITERATOR_H
#define PREORDER_ITERATOR_H

#include"BinaryTree.h"
#include<stack>
#include<vector>

using namespace std;

template<class T> class Tree;
template<class T> class TreeNode;

template<class T>

class PreorderIterator
{
public:

	PreorderIterator(TreeNode<T>* r)
	{
		temp.push(nullptr);
		current = r;
	}

	TreeNode<T>* getCurrent()
	{
		return current;
	}

	PreorderIterator<T>& operator++()
	{

		if (current != NULL || !temp.empty())
		{
			if (current->getRight() != NULL) temp.push(current->getRight());

			if (current->getLeft() != NULL)	current = current->getLeft();
			else
			{
				current = temp.top();
				temp.pop();
			}
		}
		return *this;
	}

private:
	TreeNode<T>* current;
	stack<TreeNode<T>*> temp;
};
#endif
