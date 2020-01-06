#include <iostream>

using namespace std;

#include "stack.h"

    Stack::Stack() //Constructor
    {
        top=NULL;
    }
    Stack::~Stack()
    {
        cout<<"destructor"<<endl;
        Node *current;
            while(!isEmpty())
            {
                current=top;
                top=top->next;
                cout<<"freeing node"<<endl;
                delete current;
            }
    }
    bool Stack::isEmpty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
    void Stack::push(string newItem)
    {
        Node *temp=new Node;
        temp->item=newItem;

        if(isEmpty())
        {
            top=temp;
            top->next=NULL;
        }else
        {
            temp->next=top;
            top=temp;
        }

    }
    Node* Stack::pop()
    {
        Node* temp;
        if(!isEmpty())
        {

        }else{

        }
    }
    void Stack::disp()
    {
        Node *current=top;
        cout<<"Top of stack: "<<endl;

    }
