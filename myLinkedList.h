#pragma once
#include "node.h"
#include <iostream>
using namespace std;
class myLinkedList
{
private:
	node* head;
	int size;
public:
	myLinkedList();
	myLinkedList(int data);
	myLinkedList(myLinkedList &l);
	void setHead(node *n);
	int getSize();
	node* getHead();
	void addFirst(int data);
	void addLast(int data);
	void remove(int data);
	~myLinkedList();
	void printRec(node* n);

	void selectionSort();
	void bubbleSort();
	bool isEqual(myLinkedList & l);
	int getFromEnd(int index);
	int getMiddle();
	void reverse(node *left,node*right);
	void reverse()
	{
		reverse(head, head->next);
	}
	friend ostream& operator<<(ostream& o, myLinkedList &l);

};

