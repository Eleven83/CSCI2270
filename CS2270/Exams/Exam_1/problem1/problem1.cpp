/*
Exam 1, Problem 1
CSCI 2270 Fall 2018, Gupta
*/
#include<iostream>

using namespace std;

//create the struct for our nodes
struct Node
{
    int data;
    Node *next;
};

//create a class to handle our functions
class list
{
private:
    Node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createNode(int value)
    {
        Node *temp=new Node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    void display()
    {
        Node *temp=new Node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
            if(temp==NULL)
                cout<<"NULL";
        }
    }
    int secondToLast()
    {
        Node *current=new Node;
        Node *previous=new Node;
        current=previous=head;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
            if(current->next==NULL)
            {
                return previous->data;
            }
        }
        return -1;
    }
};

int main()
{

    list obj;
    obj.createNode(3);
    // obj.createNode(9);
    // obj.createNode(2);
    // obj.createNode(4);

    cout<<"Displaying All Nodes"<<endl;
    obj.display();
    cout<<endl;
    cout<<obj.secondToLast()<<endl;

    return 0;
}
