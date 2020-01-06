#include "MadLibLinkedList.hpp"
#include <iostream>

using namespace std;

MadLibLinkedList::MadLibLinkedList()
{
    queueFront=NULL;
    queueEnd=NULL;
}
MadLibLinkedList::~MadLibLinkedList()
{
    while(queueFront!=NULL)
    {
        MadLibNode* temp=queueFront->next;
        delete queueFront;
        queueFront=temp;
    }
}
bool MadLibLinkedList::isEmpty()
{
    return queueFront==NULL;
}
void MadLibLinkedList::enqueue(string wordToInput)
{
    MadLibNode* newNode=new MadLibNode;
    newNode->word=wordToInput;
    newNode->next=NULL;
    if(isEmpty())
    {
        queueFront=newNode;
        queueEnd=newNode;
    }else{
        queueEnd->next=newNode;
        queueEnd=newNode;
    }

}
void MadLibLinkedList::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue empty, cannot dequeue an item."<<endl;
    }else{
        MadLibNode* nodeToDelete=queueFront;
        queueFront=queueFront->next;
        delete nodeToDelete;
    }
}
MadLibNode* MadLibLinkedList::peek()
{
    if(queueFront==NULL)
    {
        cout<<"Queue empty, cannot peek."<<endl;
    }else{
        cout<<"The first item in the queue is: "<<queueFront->word<<endl;
        return queueFront;
    }
    return queueFront;
}
