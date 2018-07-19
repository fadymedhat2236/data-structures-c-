#pragma once
#include <vector>
#include <iostream>
using namespace std;
class minHeap
{
private:
	vector <int> elements;
	int numberOfSwaps;
	int getParentIndex(int index);
	void siftUp(int index);
	void siftDown(int index);
public:
	minHeap::minHeap();
	void insert(int x);
	int minHeap::getMin();
	void printHeap();
	int getSize();
	int getNumberOfSwaps();
};

