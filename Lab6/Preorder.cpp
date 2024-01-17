#include<iostream>
#include<stack>
#include<vector>

using namespace std;

template<class T>class Tree;

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

			if (current->right) current = current->right;
			if (current->left) current = current->left;
		}

		return vData;
	}
private:
	TreeNode<T>* root;
};