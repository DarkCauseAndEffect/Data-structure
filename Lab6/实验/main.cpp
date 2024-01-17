#include<iostream>
#include"BinaryTree.h"
#include"PreorderIterator.h"
#include"InorderIterator.h"
#include"PostIterator.h"
#include"levelIterator.h"
#include<vector>

using namespace std;

int main()
{
	Tree<int> test;	

	TreeNode<int>* in = new TreeNode<int>;
	in->setData(8);

	TreeNode<int>* temp = new TreeNode<int>;
	temp->setData(4);
	in->setLeft(temp);

	temp = new TreeNode<int>;
	temp->setData(1);
	in->getLeft()->setLeft(temp);
	
	temp = new TreeNode<int>;
	temp->setData(7);
	in->getLeft()->setRight(temp);
	
	temp = new TreeNode<int>;
	temp->setData(6);
	in->getLeft()->getRight()->setLeft(temp);

	temp = new TreeNode<int>;
	temp->setData(9);
	in->setRight(temp);

	Tree<int> second;

	TreeNode<int>* sec = new TreeNode<int>;
	sec->setData(8);

	temp = new TreeNode<int>;
	temp->setData(4);
	sec->setLeft(temp);

	temp = new TreeNode<int>;
	temp->setData(1);
	sec->getLeft()->setLeft(temp);

	temp = new TreeNode<int>;
	temp->setData(7);
    sec->getLeft()->setRight(temp);

	temp = new TreeNode<int>;
	temp->setData(6);
	sec->getLeft()->getRight()->setLeft(temp);

	temp = new TreeNode<int>;
	temp->setData(10);
	sec->setRight(temp);
	second.setRoot(sec);

	temp = NULL;

	test.setRoot(in);
	cout << "使用前序遍历得到的结果: ";
	for (auto tempIter = test.begin(); tempIter.getCurrent() != NULL; ++tempIter)
	{
		cout << tempIter.getCurrent()->getData() << " ";
	}
	cout << endl;
	
	cout << "使用中序遍历得到的结果: ";
	for (auto tempIter = test.begin(1); tempIter.getCurrent() != NULL; ++tempIter)
	{
		cout << tempIter.getCurrent()->getData() << " ";
	}
	cout << endl;
	
	cout << "使用后序遍历得到的结果: ";
	for (auto tempIter = test.begin(2.3); tempIter.getCurrent() != NULL; ++tempIter)
	{
		cout << tempIter.getCurrent()->getData() << " ";
	}
	cout << endl;
	
	cout << "使用层次遍历得到的结果: ";
	for (auto tempIter = test.begin('a'); tempIter.getCurrent() != NULL; ++tempIter)
	{
		cout << tempIter.getCurrent()->getData() << " ";
	}
	cout << endl;
	
	//验证复制构造函数，为简化，仅将根节点的右节点由9改为10

	Tree<int> test1(second);
	cout << endl;
	cout << "使用中序遍历得到复制构造函数调用后的结果: ";
	for (auto tempIter = test1.begin(1); tempIter.getCurrent() != NULL; ++tempIter)
	{
		cout << tempIter.getCurrent()->getData() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}