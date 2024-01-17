#pragma once

#ifndef  POSTITERATOR_H
#define  POSTITERATOR_H

#include<stack>
using namespace std;

template<class T> class Tree;
template<class T> class TreeNode;

template<class T>

class PostIterator
{
public:
	PostIterator(TreeNode<T>* r)
	{
		current = r;
		while (current != NULL) 
		{
			while (current != NULL)
			{
				temp.push(current);
				current = current->getLeft();
			}
			current= temp.top()->getRight();
		}
		if (!temp.empty()) 
		{
			current = temp.top();
			temp.pop();
			lastNode = current;
		}
	}

	TreeNode<T>* getCurrent()
	{
		return current;
	}

	PostIterator<T>& operator++()
	{
		if (!temp.empty())
		{
			current = temp.top();

			if (current->getRight() != NULL && current->getRight() != lastNode)
			{
				current = current->getRight();

				while (current != NULL)
				{
					while (current != NULL)
					{
						temp.push(current);
						current = current->getLeft();
					}
					current = temp.top()->getRight();
				}
				current = temp.top();
				lastNode = current;
			}
			lastNode = current;
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
	TreeNode<T>* lastNode = NULL;
	stack<TreeNode<T>*> temp;
};
#endif