#pragma once
class node
{
private:
	int data;
	node *next;
public:
	node();
	node(int data);
	int getData();
	node* getNext();
	friend class myLinkedList;
};

