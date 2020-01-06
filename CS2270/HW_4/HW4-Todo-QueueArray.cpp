#include "HW4-Todo-QueueArray.hpp"
#include <iostream>

using namespace std;

TodoQueueArray::TodoQueueArray()
{
    queueFront=-1;
    queueEnd=-1;
}

bool TodoQueueArray::isEmpty()
{
    return(queueFront==-1 && queueEnd==-1);
}

bool TodoQueueArray::isFull()
{
    return(queueEnd+1)%MAX_QUEUE_SIZE==queueFront ? true : false;
}

void TodoQueueArray::enqueue(std::string todoItem)
{
    if(isFull())
    {
        cout<<"Queue full, cannot add new todo item."<<endl;
        return;
    }
    if(isEmpty())
    {
        queueFront=0;
        queueEnd=0;
    }else{
        queueEnd=(queueEnd+1)%MAX_QUEUE_SIZE;
    }
    TodoItem* temp=new TodoItem;
    temp->todo=todoItem;
    queue[queueEnd]=*temp;
}

void TodoQueueArray::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue empty, cannot dequeue an item."<<endl;
        return;
    }else if(queueFront==queueEnd)
    {
        queueFront=-1;
        queueEnd=-1;
    }else{
        queueFront=(queueFront+1)%MAX_QUEUE_SIZE;
    }
}

TodoItem TodoQueueArray::peek()
{
    if(queueFront==-1)
    {
        cout<<"Queue empty, cannot peek."<<endl;
    }
    return queue[queueFront];
}
