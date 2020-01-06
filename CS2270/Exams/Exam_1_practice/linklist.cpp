#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
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
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    void insertStart(int value)
    {
        Node *temp=new Node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }
    void insertAtPosition(int pos, int value)
    {
        Node *pre=new Node;
        Node *cur=new Node;
        Node *temp=new Node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }
    void deleteFirst()
    {
        Node *temp=new Node;
        temp=head;
        head=head->next;
        delete temp;
    }
    void deleteLast()
    {
        Node *current=new Node;
        Node *previous=new Node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    void deleteAtPosition(int pos)
    {
        Node *current=new Node;
        Node *previous=new Node;
        current=head;
        for(int i=1; i<pos; i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
};

int main()
{
    list obj;
    obj.createNode(25);
    obj.createNode(50);
    obj.createNode(90);
    obj.createNode(40);
    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying All nodes---------------";
    cout<<"\n--------------------------------------------------\n";
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Inserting At End-----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.createNode(55);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Inserting At Start----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insertStart(50);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-------------Inserting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insertAtPosition(5,60);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Deleting At Start-----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.deleteFirst();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Deleing At End-------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.deleteLast();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Deleting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    obj.deleteAtPosition(4);
    obj.display();
    cout<<"\n--------------------------------------------------\n";

    return 0;
}
