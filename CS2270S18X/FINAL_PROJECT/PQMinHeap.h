#ifndef PQMinHeap_H
#define PQMinHeap_H
#include <iostream>
#include <queue>
#include <ctime>
#include "patStruct.h"

using namespace std;

class MinHeap
{
public:
    MinHeap(int);
    ~MinHeap();
    void MinHeapify(int);
    void push(int);
    int pop();
    int peek()
    {
        return heapArray[0];
    }
    void printHeap();
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i + 2);
    }
    void swap(int *x, int *y);
private:
    Patient* heapArray; //pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int currentSize; // Current number of elements in min heap
};

#endif
