#include <iostream>
#include <time.h>

using namespace std;

// A class for Min Heap
class MinHeap
{
public:
    MinHeap(int capacity);
    ~MinHeap();
    void push(int k);
    int pop();
    int peek()
    {
        return heap[1];
    }
    void printHeap();
private:
    int *heap; //pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int currentSize; // Current number of elements in min heap
    void MinHeapify(int index);
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
};

MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap;
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

void MinHeap::push(int k)
{
    if (currentSize == capacity)
    {
        cout << "At capacity, cannot insert key." << endl;
    }

    else {
        currentSize++;
        int i = currentSize - 1;
        heap[i] = k; // we can insert at currentSize b/c we ignore 0
        // Fix the min heap property if it is violated
        while (i != 0 && heap[parent(i)] > heap[i])//compare(heap[i],heap[parent(i)])
        {
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
    }
}

// for now, just return -1 if there's nothing to pop
int MinHeap::pop()
{
    if (currentSize <= 0)
        return -1;
    if (currentSize == 1)
    {
        currentSize--;
        return heap[0];
    }
    int poppedVal = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    MinHeapify(0);

    return poppedVal;
}

// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int leftChild = left(i);
    int rightChild = right(i);
    int smallest = i;
    if (leftChild < currentSize && heap[leftChild] < heap[i]) // compare(heap[leftChild],heap[i])
        smallest = leftChild;
    if (rightChild < currentSize && heap[rightChild] < heap[smallest])//similar as above
        smallest = rightChild;
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::printHeap()
{
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++)
    {
        cout << heap[i];
        if (i < currentSize-1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main()
{
    const int arrSize = 10;
    int arr[arrSize];
    // Create random integers to fill array
    for( int i = 0; i < arrSize; i++ )
        arr[i] = rand()%1000;

    cout << "the array is: " << endl;

    for(int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";

    cout << endl;

    MinHeap heap2(arrSize);

    // start timer
    int startTime, endTime;
    startTime=clock();

    for(int i = 0; i < arrSize; i++)
        heap2.push( arr[i] );

    for(int i = 0; i < arrSize; i++)
        arr[i] = heap2.pop();
    endTime = clock();
    float execTime=(float)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"heap execTime "<<execTime<<endl;
    // end timer
    for(int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";

    for( int i = 0; i < arrSize; i++ )
        arr[i] = rand()%1000;

    cout << "the array is: " << endl;

    for(int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";

    // bubble sort
    // for(int i = arrSize-1; i>0; i++)
    // {
    //     for(int j=0; j<i; j++)
    //     {
    //         if(arr[j] > arr[j+1])
    //         {
    //             int temp = arr[j+1];
    //             arr[j+1]=arr[j];
    //             arr[j]=temp;
    //         }
    //     }
    // }
    // cout << "the array is: " << endl;
return 0;
}
