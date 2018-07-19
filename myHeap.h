#pragma once
#include <iostream>
using namespace std;
class myHeap
{
private:
	int* elements;
	int maxSize, actualSize;
	int getParentIndex(int index);
	void siftUp(int index);
	void siftDown(int index);
public:
	myHeap();
	myHeap(int maxSize);
	void insert(int x);
	int myHeap::getMax();
	void printHeap();
	~myHeap();
};

