#include <iostream>
#include <climits>

using namespace std;

//Prototype of a utility function to swap two ints
void swap(int *x, int *y);

//Class for MinHeap
class MinHeap
{
    int *harr; //Pointer to an array of elements in the heap
    int capacity; //Maximum possible size of the min heap
    int heap_size; //Current number of elements in the min heap
public:
    //Constructor
    MinHeap(int capacity);

    //To heapify a subtree with root at given index
    void MinHeapify(int );

    int parent(int i)
    {
        return (i/2);
    }

    //To get index of left child of node at index i
    int left(int i)
    {
        return (2*i);
    }

    //To get index of right child of node at index i
    int right(int i)
    {
        return (2*i+1);
    }

    //To extract the root whichis the minimum element
    int extractMin();

    //Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    //Returns the minimum key(key at root) from min heap
    int getMin()
    {
        return harr[1];
    }

    //Deletes key stored at index i
    void deleteKey(int i);

    //Inserts a new key 'k'
    void insertKey(int k);

};

//Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 1;
    capacity = cap;
    harr = new int[cap+1];
    harr[0] = INT_MIN;
}

//Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"\nOverflow. Could not insert key.\n";
        return;
    }
    //First insert the new key at the end
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;

    //Fix the min heap property if it is violated
    while(i!=1 && harr[parent(i)]>harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i=parent(i);
    }
}

//Decreases value of key at index 'i' to new_val. It is assumed that
//new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i]=new_val;
    while(i != 1 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i=parent(i);
    }
}

//Method to remove the minimum element (or root) from a min heap
int MinHeap::extractMin()
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        heap_size--;
        return harr[1];
    }
    //Store the min value and remove it from the heap
    int root=harr[1];
    harr[1]=harr[heap_size-1];
    heap_size--;
    MinHeapify(1);

    return root;
}

//Method to delete key at index 'i'. It first reduces value to minus infinity
//then calls extractMin().
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

//A recursive method to heapify a subtree with the root at given index
//This method assumes that the subtrees are already heapified.
void MinHeap::MinHeapify(int i)
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l < heap_size && harr[l] < harr[i])
        smallest=l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest=r;
    if(smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

//Helper function to swap to elements
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout<<h.extractMin()<<" ";
    cout<<h.getMin()<<" ";
    h.decreaseKey(2,1);
    cout<<h.getMin()<<" ";

    return 0;
}
