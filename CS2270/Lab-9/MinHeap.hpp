#include<iostream>

using namespace std;

class MinHeap
{
  int *heapArr;
  int capacity;
  int currentSize;

public:
  MinHeap(int capacity);
  int parent(int index);
  int leftChild(int index);
  int rightChild(int index);

  int getMin();
  void heapify(int index);
  int extractMin();
  void insertElement(int value);
  void print();

};

/*
Swaps two integer values
*/
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
Constructor for our MinHeap implementation
*/
MinHeap::MinHeap(int cap)
{
  currentSize = 0;
  capacity = cap;
  heapArr = new int[capacity+1];

  // Dummy value at position 1
  heapArr[0] = -9999;
}

/*
Finds the parent of a node, given its index.
*/
int MinHeap::parent(int index)
{
  return (index)/2;
}

/*
Returns the left child of a node.
*/
int MinHeap::leftChild(int index)
{
  return (2*index);
}

/*
Returns the right child of a node.
*/
int MinHeap::rightChild(int index)
{
  return (2*index)+1;
}

/*
Returns the smallest element from the heap.
*/
int MinHeap::getMin()
{
  return heapArr[1];
}

/*
When an element is removed/deleted. This method make sures the array
satisfies the heap property.
*/
void MinHeap::heapify(int i)
{
  int l = leftChild(i);
  int r = rightChild(i);

  // Finds the smallest of node, left Child, and right child
 // The parent is swapped with the smallest of all 3
  int smallest = i;
  if (l <= currentSize && heapArr[l] < heapArr[i])
      smallest = l;
  if (r <= currentSize && heapArr[r] < heapArr[smallest])
      smallest = r;

  // Similarly do this till the leaf
  if (smallest != i)
  {
      swap(&heapArr[i], &heapArr[smallest]);
      heapify(smallest);
  }
}

/*
Inserts an element into the heap by maintaining the heap property.
*/
void MinHeap::insertElement(int value)
{
  if(currentSize > capacity)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize;
  heapArr[index] = value;

  while (index != 1 && heapArr[parent(index)] > heapArr[index])
    {
       swap(&heapArr[index], &heapArr[parent(index)]);
       index = parent(index);
    }
}

/*
Prints the elements in the heap
*/
void MinHeap::print()
{
  int iter = 1;
  while(iter <= currentSize)
  {
    cout<<heapArr[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}
