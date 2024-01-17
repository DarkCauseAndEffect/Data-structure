#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"PreorderIterator.h"
#include"InorderIterator.h"
#include"PostIterator.h"
#include"levelIterator.h"

using namespace std;

template<class T> class Tree;
template<class T> class PreorderIterator;
template<class T> class InorderIterator;
template<class T> class PostIterator;
template<class T> class LevelIteratir;

template<class T>

class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode() {}
	TreeNode(T d,TreeNode<T>* l, TreeNode<T>* r)
	{
		data = d;
		left = l;
		right = r;
	}

	void setLeft(TreeNode<T>* temp)
	{
		left = temp;
	}

	TreeNode<T>* getLeft()
	{
		return left;
	}

	void setRight(TreeNode<T>* temp)
	{
		right = temp;
	}

	TreeNode<T>* getRight()
	{
		return right;
	}

	void setData(T d)
	{
		data = d;
	}

	T getData()
	{
		return data;
	}

private:
	T data;
	TreeNode<T>* left = NULL;
	TreeNode<T>* right = NULL;
};

template<class T>

class Tree
{
public:
	//构造函数
	Tree() {}
	//复制构造
	Tree(Tree<T>& r) 
	{
		root = copy(r.root);
	}

	TreeNode<T>* copy(TreeNode<T>* r)
	{
		if (!r) return 0;
		return new TreeNode<T>(r->getData(), copy(r->getLeft()), copy(r->getRight()));
	}

	bool IsEmpty()
	{
		if (root) return 1;
		else return 0;
	}

	void setRoot(TreeNode<T>* r)
	{
		root = r;
	}

	TreeNode<T>* getLeft()
	{
		if (root->getLeft()) return root->getLeft();
		else return NULL;
	}

	TreeNode<T>* getRight()
	{
		if (root->getRight()) return root->getRight(
		);
		else return NULL;
	}

	T getData()
	{
		return root->getData();
	}


	PreorderIterator<T> begin()
	{
		PreorderIterator<T> temp(root);
		return temp;
	}

	InorderIterator<T> begin(int in)
	{
		InorderIterator<T> temp(root);
		return temp;
	}

	PostIterator<T> begin(double b)
	{
		PostIterator<T> temp(root);
		return temp;
	}

	LevelIterator<T> begin(char s)
	{
		LevelIterator<T> temp(root);
		return temp;
	}
	
	~Tree()
	{
		if (root != NULL)
        {
        	queue<TreeNode<T>*> temp;
        	temp.push(root);
			while (!temp.empty())
			{
				TreeNode<T>* current = temp.front();
				if (current->getLeft() != NULL) temp.push(current->getLeft());
				if (current->getRight() != NULL) temp.push(current->getRight());
				delete current;
				temp.pop();
			}
        	root = NULL;
        }
	}


private:
	TreeNode<T>* root = NULL;
};
#endif