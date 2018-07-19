#include "stdafx.h"
#include "treeNode.h"


treeNode::treeNode()
{
	data = 0;
	left = NULL;
	right = NULL;
}
treeNode::treeNode(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}
int treeNode::getData()
{
	return this->data;
}
void treeNode::setData(int data)
{
	this->data = data;
}
treeNode* treeNode::inOrderSuccessor()
{
	treeNode *p = right;
	while (p->left != NULL)
		p = p->left;
	return p;
}
