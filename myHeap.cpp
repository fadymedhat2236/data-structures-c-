#include "stdafx.h"
#include "myHeap.h"
#include <iostream>
using namespace std;

myHeap::myHeap()
{
	elements = NULL;
	maxSize = 100;
	actualSize = 0;
}

myHeap::myHeap(int maxSize)
{
	elements = new int[maxSize];
	this->maxSize = maxSize;
	this->actualSize = 0;
}

int myHeap::getParentIndex(int index)
{
	return (index - 1) / 2;
}

void myHeap::insert(int x)
{
	elements[actualSize] = x;
	actualSize++;
	siftUp(actualSize - 1);
}

void myHeap::siftUp(int index)
{
	if (index == 0)
		return;
	int parentIndex = getParentIndex(index);

	while (index > 0 && elements[parentIndex] < elements[index])
	{
		int temp = elements[index];
		elements[index] = elements[parentIndex];
		elements[parentIndex] = temp;
		index = getParentIndex(index);
		parentIndex = getParentIndex(index);
	}
}

int myHeap::getMax()
{
	if (actualSize == 0)
		throw "error";
	if (actualSize == 1)
	{
		actualSize--;
		return elements[0];
	}

	int x = elements[0];
	elements[0] = elements[actualSize - 1];
	actualSize--;
	siftDown(0);
	return x;

}

void myHeap::siftDown(int index)
{
	while (1)
	{
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;
		int maxIndex = index;
		if (leftChildIndex<actualSize && elements[leftChildIndex] >elements[maxIndex])
			maxIndex = leftChildIndex;
		if (rightChildIndex<actualSize && elements[rightChildIndex] >elements[maxIndex])
			maxIndex = rightChildIndex;

		if (maxIndex != index)
		{
			int temp = elements[index];
			elements[index] = elements[maxIndex];
			elements[maxIndex] = temp;
			index = maxIndex;
		}
		else
		{
			break;
		}

	}

}




void myHeap::printHeap()
{
	for (int i = 0;i < actualSize;i++)
		cout << this->elements[i] << endl;
}


myHeap::~myHeap()
{
	if (elements)
	{
		delete[] elements;
	}
	maxSize = 0;
	actualSize = 0;
}
