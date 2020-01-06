/*
Exam 1, Problem 2
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
    Node *swapHeadAndTail(Node *head)
    {
        Node *current=new Node;
        Node *previous=new Node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=head->next;
        head=previous->next;
        head=tail;
        tail->next=NULL;

        return head;
    }
};

int main()
{
    swapHeadAndTail();
    list obj;
    obj.createNode(3);
    obj.createNode(9);
    obj.createNode(2);
    obj.createNode(4);

    cout<<"Displaying All Nodes"<<endl;
    obj.display();
    cout<<endl;

    return 0;
}
