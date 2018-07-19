#include "stdafx.h"
#include "bst.h"
#include <queue>
#include <iostream>
using namespace std;
bst::bst()
{
	root = NULL;
}
treeNode* bst::getRoot()
{
	return root;
}
void bst::insert(int data)
{
	if (root == NULL)
		root = new treeNode(data);
	else
	{
		treeNode *p = root;
		while (p != NULL)
		{
			if (data == p->data)
				return;
			else if (data > p->data)
			{
				if (p->right == NULL)
				{
					p->right = new treeNode(data);
					return;
				}
				else
					p = p->right;
			}
			else
			{
				if (p->left == NULL)
				{
					p->left = new treeNode(data);
					return;
				}
				else
					p = p->left;
			}
		}
	}
}
void bst::initialize()
{
	this->insert(5);
	this->insert(2);this->insert(7);this->insert(1);this->insert(6);
	this->insert(3);this->insert(8);this->insert(4);this->insert(9);
}
void bst::remove(treeNode* &root,int data)
{
	treeNode* target = root;
	treeNode* parent = NULL;
	bool leftChild;
	while (target->data != data)
	{
		if (data<target->data)
		{
			parent = target;
			target = target->left;
			leftChild = true;
		}
		else
		{
			parent = target;
			target = target->right;
			leftChild = false;
		}
	}
	if (target->left == NULL && target->right == NULL)
	{
		if (parent == NULL)
		{
			root = NULL;
			delete[] target;
			return;
		}
		
		if (leftChild)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete[] target;
	}
	else if (target->left != NULL && target->right == NULL)
	{
		if (parent == NULL)
			root = target->left;
		else
			parent->left = target->left;
		delete[] target;
	}
	else if (target->left == NULL && target->right != NULL)
	{
		if (parent == NULL)
			root = target->right;
		else
			parent->right = target->right;
		delete[] target;
	}
	else
	{
		treeNode * temp = target->right;
		while (temp->left != NULL)
			temp = temp->left;
		target->data = temp->data;
		remove(target->right, target->data);
	}
}
void bst::remove(int data)
{
	remove(root, data);
}
void bst::preOrderTraverse(treeNode* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}
void bst::inOrderTraverse(treeNode* root)
{
	if (root == NULL)
		return;
	inOrderTraverse(root->left);
	cout << root->data  << " ";
	inOrderTraverse(root->right);
}
void bst::postOrderTraverse(treeNode* root)
{
	if (root == NULL)
		return;
	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	cout << root->data << " ";
}
void bst::levelOrderTraverse()
{
	if (root == NULL)
		return;
	queue<treeNode*> q1;
	q1.push(root);
	while (!q1.empty())
	{
		treeNode* temp = q1.front();
		cout << temp->data << " ";
		if (temp->left)
			q1.push(temp->left);
		if (temp->right)
			q1.push(temp->right);
		q1.pop();
	}
}
bst::~bst()
{
	if (root == NULL)
		return;
	queue<treeNode*> q1;
	q1.push(root);
	while (!q1.empty())
	{
		treeNode* temp = q1.front();
		if (temp->left != NULL)
			q1.push(temp->left);
		if (temp->right != NULL)
			q1.push(temp->right);
		delete[] temp;
		q1.pop();
	}
}
