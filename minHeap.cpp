#include "stdafx.h"
#include "minHeap.h"
#include <vector>
#include <iostream>
using namespace std;

minHeap::minHeap()
{
	numberOfSwaps = 0;
}


int minHeap::getParentIndex(int index)
{
	return (index - 1) / 2;
}

void minHeap::insert(int x)
{
	elements.push_back(x);
	siftUp(elements.size()-1);
}

void minHeap::siftUp(int index)
{
	if (index == 0)
		return;
	int parentIndex = getParentIndex(index);

	while (index > 0 && elements[index] < elements[parentIndex])
	{
		int temp = elements[index];
		elements[index] = elements[parentIndex];
		elements[parentIndex] = temp;
		index = getParentIndex(index);
		parentIndex = getParentIndex(index);
		numberOfSwaps++;
	}
}

int minHeap::getMin()
{
	if (elements.size() == 0)
		throw "error found";
	if (elements.size() == 1)
	{
		int x = elements[0];
		elements.erase(elements.begin());
		return x;
	}

	int x = elements[0];
	elements[0] = elements[elements.size() - 1];
	elements.erase(elements.begin()+elements.size()-1);
	siftDown(0);
	return x;

}

void minHeap::siftDown(int index)
{
	while (1)
	{
		unsigned int leftChildIndex = 2 * index + 1;
		unsigned int rightChildIndex = 2 * index + 2;
		unsigned int minIndex = index;
		if (leftChildIndex<elements.size() && elements[leftChildIndex] < elements[minIndex])
			minIndex = leftChildIndex;
		if (rightChildIndex<elements.size() && elements[rightChildIndex] < elements[minIndex])
			minIndex = rightChildIndex;

		if (minIndex != index)
		{
			int temp = elements[index];
			elements[index] = elements[minIndex];
			elements[minIndex] = temp;
			index = minIndex;
			numberOfSwaps++;
		}
		else
		{
			break;
		}

	}

}




void minHeap::printHeap()
{
	for (unsigned int i = 0;i < elements.size();i++)
		cout << this->elements[i] << endl;
	cout << numberOfSwaps << endl;
}

int minHeap::getSize()
{
	return elements.size();
}
int minHeap::getNumberOfSwaps()
{
	return numberOfSwaps;
}



