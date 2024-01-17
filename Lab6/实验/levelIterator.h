#pragma once

#ifndef LEVELITERATOR_H
#define LEVELITERATOR_H

#include<queue>
using namespace std;

template<class T> class Tree;
template<class T> class TreeNode;

template<class T>
class LevelIterator
{
public:
	LevelIterator(TreeNode<T>*r)
	{
		current = r;
		if (current != NULL)
		{
			if (current->getLeft() != NULL) temp.push(current->getLeft());
			if (current->getRight() != NULL) temp.push(current->getRight());
		}
	}

	TreeNode<T>* getCurrent()
	{
		return current;
	}

	LevelIterator<T>& operator++()
	{
		if (!temp.empty()) 
		{
			current = temp.front();
			temp.pop();
			if (current->getLeft() != NULL) temp.push(current->getLeft());
			if (current->getRight() != NULL) temp.push(current->getRight());
		}
		else
		{
			current = NULL;
		}
		return *this;
	}

private:
	TreeNode<T>* current;
	queue<TreeNode<T>*> temp;
};

#endif