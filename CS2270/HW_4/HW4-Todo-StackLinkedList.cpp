#include "HW4-Todo-StackLinkedList.hpp"
#include <iostream>

using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
    stackHead=NULL;
}

bool TodoStackLinkedList::isEmpty()
{
    if(stackHead==NULL)
        return true;
    else
        return false;
}

void TodoStackLinkedList::push(std::string todoItem)
{
    if(isEmpty()==true)
    {
        TodoItem* newItem = new TodoItem;
        newItem->todo=todoItem;
        newItem->next=NULL;
        stackHead=newItem;
    }else{
        TodoItem* newItem = new TodoItem;
        newItem->todo=todoItem;;
        newItem->next=stackHead;
        stackHead=newItem;
    }
}

void TodoStackLinkedList::pop()
{
    if(isEmpty()==true)
        cout<<"Stack empty, cannot pop an item."<<endl;
    else{
        TodoItem* temp= stackHead;
        stackHead=stackHead->next;
        delete temp;
    }
}

TodoItem* TodoStackLinkedList::peek()
{
    if(isEmpty()==true)
    {
        cout<<"Stack empty, cannot peek."<<endl;
        return NULL;
    }else{
        return stackHead;
    }
}
