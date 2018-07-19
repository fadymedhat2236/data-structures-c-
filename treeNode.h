#pragma once
class treeNode
{
	friend class bst;
private:
	int data;
	treeNode *left;
	treeNode *right;
public:
	treeNode();
	treeNode(int data);
	int getData();
	void setData(int data);
	treeNode* inOrderSuccessor();
};

