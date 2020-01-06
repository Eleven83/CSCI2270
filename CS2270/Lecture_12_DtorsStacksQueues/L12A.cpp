/* Queue - Circular Array Implementation */
#include <iostream>

using namespace std;

const int MAX_SIZE = 2; //Maximum size of the Array that will store the Queue

//Creating a class names Queue
class Queue
{
private:
    int A[MAX_SIZE];
    int front, rear;
public:
    //Notice in this program the methods are inline
    //In cpp this is possible, however, you can avoid doing this by using headers
    //Constructor - set front and rear as -1
    //We are assuming that, for an empty queue, both front and rear will be -1
    Queue()
    {
        front=-1;
        rear=-1;
    }
    //To check whether Queue is empty or not
    bool isEmpty()
    {
        return(front==-1&&rear==-1);
    }
    //To check whether Queue is full or not
    bool isFull()
    {
        return(rear+1)%MAX_SIZE==front ? true:false;
    }
    //Inserts element at rear
    void enqueue(int x)
    {
        cout<<"Enqueuing "<<x<<"\n";
        if(isFull())
        {
            cout<<"Error: Queue is Full."<<"\n";
            return;
        }
        if(isEmpty())
        {
            front=rear=0;
        }else{
            rear=(rear+1)%MAX_SIZE;
        }
        A[rear]=x;
    }
    //Removes an element from queue at the front
    void dequeue()
    {
        cout<<"Dequeuing \n";
        if(isEmpty())
        {
            cout<<"Error: Queue is Empty."<<"\n";
            return;
        }else if(front==rear){
            rear=front=-1;
        }else{
            front=(front+1)%MAX_SIZE;
        }
    }
    //Returns the element at front of the queue
    int peek()//Peek function to check what is element at the front
    {
        if(front==-1)
        {
            cout<<"Error: Cannot Return front from Empty Queue.\n";
            return -1;
        }
        return A[front];
    }
    /*
        Printing elements in queue from front to rear.
        This is only to test the code and is not a standard
        function used in Queue Implementation.
    */
    void print()
    {
        if(isEmpty())
        {
            cout<<"Cannot Print. Error: Queue is empty.\n";
            return;
        }
        //Finding number of elements in the queue
        int count=(rear+MAX_SIZE-front)%MAX_SIZE+1;
        cout<<"Queue    :";
        for(int i=0; i<count; i++)
        {
            int index=(front+i)%MAX_SIZE; //Index of element while traversing circularly from front
            cout<<A[index]<<" ";
        }
        cout<<"\n\n";
    }
};

int main()
{
    /*
        Printing elements in queue after each enqueue or dequeue
    */
    Queue Q; //Creating an instance of Queue
    Q.enqueue(2); Q.print();
    Q.enqueue(4); Q.print();
    Q.enqueue(6); Q.print();
    Q.dequeue(); Q.print();
    Q.enqueue(8); Q.print();

    return 0;
}
