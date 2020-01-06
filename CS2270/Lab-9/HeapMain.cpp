#include "MinHeap.hpp"

/*
Complete the extract minimum function
Case1:
      If the heap is empty
Case2:
      If heap has only one Element
Case3:
      1. Extract the smallest element.
      2. Replace that slot with the last element from the heap.
      3. Call heapify to maintain the heap property.
*/
int MinHeap::extractMin()
{
    //Case1
    if (currentSize <= 0)
        return INT_MAX;
    //Case2
    if (currentSize == 1)
    {
        currentSize--;
        return heapArr[1];
    }
    //Case3
    int minimum = heapArr[1];
    heapArr[1]=heapArr[currentSize];
    currentSize--;
    heapify(1);

    return minimum;
}

int main()
{
  MinHeap heap(5);
  heap.insertElement(20);
  heap.insertElement(15);
  heap.insertElement(18);
  heap.insertElement(12);
  heap.insertElement(9);

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.print();
  cout<<endl;

  cout << "Smallest element extracted is: "<<heap.extractMin() <<endl<<endl;
  cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  heap.print();
  cout<<endl;
  return 0;
}
