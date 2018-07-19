#include "stdafx.h"
#include "node.h"


node::node()
{
	this->next = NULL;
}
node::node(int data)
{
	this->data = data;
	this->next = NULL;
}
int node:: getData()
{
	return this->data;
}

node* node::getNext()
{
	return next;
}