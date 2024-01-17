#pragma once

//该函数时间复杂度为O（n），空间复杂度为O（n），n为树的节点个数

#ifndef TREADEDTREE_H
#define TREADEDTREE_H

#include<vector>
#include<stack>

template<class T> class ThreadedTree;

template<class T>

class TreeNode
{
private:
	bool leftThreaded = true;
	bool rightThreaded = false;
	TreeNode<T>* left = left;
	TreeNode<T>* right = NULL;
	T data;
};

template<class T>

class ThreadedTree
{
public:
	vector<T> Preorder()
	{
		TreeNode<T>* current = root;
		stack<T> temp;
		vector<T> vData;
		if (!current) return vData;

		vData.push_back(current->data);
		temp.push(current);
		while (!temp.empty())
		{
			vData.push_back(current->data);
			current = temp.top();
			temp.pop();

			if (current->rightThreaded == 0) current = current->right;
			if (current->leftThreaded == 0) current = current->left;
		}
		return vData;
	}
private:
	TreeNode<T>* root;
};
#endif
