//This is the implementation file for the QUEUE_H header file that contains the
//Queue class.
#include <iostream>
#include <sstream>
#include "Queue.h"

using namespace std;


//Queue constructor. Called when a Queue object is instantiated.
//It takes an integer argument for the size of the queue. It dynamically creates a
//new array of strings of the given size and initializes the head, tail, and count
//members.
Queue::Queue(int qs)
{
    queueSize=qs;
    //The return value from 'new' is a memory address, it must be assigned a pointer.
    arrayQueue=new string[queueSize]; //allocate memory for the array on the heap. arrayQueue is a private member (pointer) of the Queue class.
    queueHead=0; //head position
    queueTail=0; //tail position
    queueCount=0; //How many words are in the queue.
}

//Queue destructor. It handles the deletion of arrayQueue object.
Queue::~Queue()
{
    //'delete' returns the memory to the heap and it must be called on the pointer itself. If not, you get a memory leak.
    delete [] arrayQueue; //frees the memory
    arrayQueue=NULL; //sets the pointer to NULL so you can re-use it.
}
//The enqueue method will take a string as input and add it to the queue. It will also
//print out the string and the index of the head and tail positions.
//Circular queue elements are always added to the tail.
void Queue::enqueue(string word)
{
    int temp=queueTail; //The tail position assigned to a temp variable.
    if(!queueIsFull()) //Check to see if the queue is not full. If not, then there is room to add a string.
    {
        arrayQueue[temp]=word; //the word is added to the queue at the tail.
        temp++; //increment the tail position.
        queueCount++; //increment the word count.
        if(temp==queueSize) //If tail position is at the end of the queue.
        {
            temp=0; //Circle around to the first position.
        }
        queueTail=temp; //Position of tail is updated to position of temp.
        cout<<"E: "<<word<<endl; //The word added to the queue.
        cout<<"H: "<<queueHead<<endl; //The position of the head.
        cout<<"T: "<<queueTail<<endl; //The position of the tail.
    }else
        cout<<"Queue is full."<<endl; //No room.
}

//Circular queue elements are always dequeued from the front
void Queue::dequeue()
{
    string word;
    while(!queueIsEmpty())
    {
        word=arrayQueue[queueHead]; //Store the contents of the queue at the head position in the word variable.
        if(queueHead==queueSize-1) //If the head is at the end of the queue.
        {
            queueHead=-1; //
        }
        queueCount--; //Decrement the word count.
        queueHead++; //Increment the position of the head.
        cout<<"H: "<<queueHead<<endl; //Position of the head.
        cout<<"T: "<<queueTail<<endl; //Position of the tail.
        cout<<"word: "<<word<<endl; //The word removed from the queue.
        return;
    }
    cout<<"Queue is empty."<<endl;
}

void Queue::printQueue()
{
    int current=queueHead;
    while(!queueIsEmpty())
    {
        for(int i=0; i<queueCount; i++)
        {
            cout<<current<<": "<<arrayQueue[current]<<endl; //print the index and the word at that index position.
            if(current==(queueSize-1)) //If at the last position, wrap around, else, increment.
            {
                current=0;
            }else
                current++;
        }
        return;
    }
    cout<<"Empty"<<endl;
}

void Queue::enqueueSentence(string sentence)
{
    string word;
    stringstream sso;
    sso<<sentence;
    while(getline(sso, word, ' '))
    {
        if(!queueIsFull())
        {
            enqueue(word);
        }else
            cout<<"Queue is full."<<endl;
    }
}

bool Queue::queueIsFull()
{
    return(queueCount==queueSize);
}

bool Queue::queueIsEmpty()
{
    return((queueCount==0)||(queueHead==-1 && queueTail==-1));
}
