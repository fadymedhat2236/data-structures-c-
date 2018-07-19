#include "stdafx.h"
#include "myLinkedList.h"


myLinkedList::myLinkedList()
{
	this->head = NULL;
	size = 0;
}


myLinkedList::myLinkedList(int data)
{
	head = new node();
	head->data = data;
	head->next = NULL;
	size = 1;
}

myLinkedList::myLinkedList(myLinkedList &l)
{
	this->head = NULL;
	this->size = l.size;
	if (l.head == NULL)
		return;
	head = new node(l.head->data);
	node * temp1, *temp2;
	temp1 = l.head;temp2=this->head;
	while (temp1->next)
	{
		temp2->next = new node(temp1->next->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	/*
	this->head = NULL;
	if (l.head)
		this->head = new node();
	node *temp1 = l.head;node *temp2 = this->head;
	while (temp1)
	{
		temp2->data = temp1->data;
		if (temp1->next != NULL)
			temp2->next = new node();
		temp2 = temp2->next;
		temp1 = temp1->next;
	}

	*/
}
void myLinkedList::setHead(node *n)
{
	head = n;
}
int myLinkedList::getSize()
{
	return this->size;
}
node* myLinkedList::getHead()
{
	return this->head;
}
void myLinkedList::addFirst(int d)
{
	if (head)
	{
		node *n = new node(d);
		n->next = head;
		head = n;
	}
	else
	{
		head = new node(d);
	}
	size++;
}

void myLinkedList::addLast(int data)
{
	if (head)
	{
		node* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = new node(data);
	}
	else
		head = new node(data);
	size++;
}
void myLinkedList::remove(int data)
{
	if (head->data == data)
	{
		node*temp = head->next;
		delete[] head;
		head = temp;
	}
	else
	{
		node* left = head;node* temp = head->next;node* right = temp->next;
		while (temp->data != data)
		{
			if (right->next == NULL)
				throw "no element with this value exists in the list";
			left = temp;temp = right;right = right->next;
		}
		delete[] temp;
		left->next = right;
	}
}
myLinkedList::~myLinkedList()
{
	while (head)
	{
		node *temp = head->next;
		delete[] head;
		head = temp;
	}
}
void myLinkedList::printRec(node* n)
{
	if (n != NULL)
	{
		cout << n->data << endl;
		printRec(n->next);
	}
}
void myLinkedList::selectionSort()
{

	if (head == NULL)
		return;
	node * temp1=this->head;
	while (temp1->next)
	{
		node * temp2 = temp1->next;node * temp3 = temp1;
		while (temp2)
		{
			if (temp2->data < temp1->data)
				temp3 = temp2;
			temp2=temp2->next;
		}
		int x = temp1->data;
		temp1->data = temp3->data;
		temp3->data = x;
		temp1 = temp1->next;
	}
}
void myLinkedList::bubbleSort()
{
	if (head == NULL || head->next == NULL)
		return;
	node *endNode = NULL;bool isSorted;
	do
	{
		isSorted = true;
		node* temp2 = head;
		while (temp2->next != endNode)
		{
			if (temp2->data > temp2->next->data)
			{
				isSorted = false;
				int x = temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data = x;
			}
			temp2 = temp2->next;
		}
		endNode = temp2;
	} while (isSorted==false);
}
bool myLinkedList::isEqual(myLinkedList & l)
{
	node *temp1 = this->head;
	node* temp2 = l.head;
	while (temp1 && temp2)
	{
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp1 || temp2)
		return false;
	return true;
}
int myLinkedList::getFromEnd(int index)
{
	node *leadingPointer = head;node *previousPointer = head;
	for (int i = 0;i < index;i++)
		leadingPointer = leadingPointer->next;

	while (leadingPointer->next)
	{
		previousPointer = previousPointer->next;
		leadingPointer = leadingPointer->next;
	}
	return previousPointer->data;
}
int myLinkedList::getMiddle()
{
	if (head == NULL || head->next == NULL)
		throw "invalid operation";
	node *fastPointer = head;node *slowPointer = head;
	while (fastPointer != NULL && fastPointer->next)
	{
		fastPointer = fastPointer->next->next;
		slowPointer = slowPointer->next;
	}
	return slowPointer->data;
}
void myLinkedList::reverse(node *left,node* right)
{
	if (head == NULL || head->next == NULL)
		return;
	if (right->next)
	{
		reverse(left->next, right->next);
	}
	if (right->next == NULL)
	{
		head->next = NULL;
		head = right;
	}
	right->next = left;
}
ostream& operator<<(ostream& o, myLinkedList &l)
{
	node *temp = l.head;
	while (temp)
	{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	}
	return o;
}