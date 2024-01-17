#pragma once

//�ú���ʱ�临�Ӷ�ΪO��n�����ռ临�Ӷ�ΪO��n����nΪ���Ľڵ����

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
