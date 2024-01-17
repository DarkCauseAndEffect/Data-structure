//时间复杂度为O（n），n为节点数
//delete函数写在Tree类中，用~Tree（）实现

#include<iostream>
#include<stack>

using namespace std;

template<class T>class Tree;

template<class T>

class TreeNode
{
	friend class Tree<T>;
public:
	T data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

template<class T>

class Tree
{
public:

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
	TreeNode* root=NULL;
};
