#include<iostream>
#include<vector>

using namespace std;

template<class T> class ThreadedTree;

template<class T>

class TreeNode
{
	friend class TreadedTree;
private:
	bool leftTreaded = true;
	bool rightThreaded = false;
	TreeNode<T>* left = left;
	TreeNode<T>* right = NULL;
	T data;
};

template<class T>

class ThreadedTree
{
private:
	TreeNode<T>* root;
};

template<class T>

void InsertLeft(TreeNode<T>* s, TreeNode<T>* l)
{
	l->left = s->left;
	l->rightThreaded = 1;
	l->right = s;
	l->leftTreaded = s->leftTreaded;

	s->left = l;
	if (l->leftTreaded == 0)
	{
		TreeNode<T>* temp = l->left;
		while (!temp->rightThreaded)
		{
			temp = temp->right;
		}
		temp->right = l;
		temp = NULL;
	}
}