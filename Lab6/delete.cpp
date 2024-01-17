//ʱ�临�Ӷ�ΪO��n����nΪ�ڵ���
//delete����д��Tree���У���~Tree����ʵ��

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
