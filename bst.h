#pragma once
#include "treeNode.h"
#include <iostream>
class bst
{
private:
	treeNode *root;
public:
	bst();
	treeNode* getRoot();
	void initialize();
	void insert(int data);
	void remove(treeNode* &root, int data);
	void remove(int data);
	void preOrderTraverse(treeNode* root);
	void inOrderTraverse(treeNode* root);
	void postOrderTraverse(treeNode* root);
	void levelOrderTraverse();
	~bst();
};

