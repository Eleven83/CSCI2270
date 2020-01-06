#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    node* next;
};

class List
{
private:
    node* head;
    node* tail;
public:
    void createNode(int);
    void displayList();
    void insert_start(int);
    void insert_position(int, int);
    void delete_first();
    void delete_last();
    void delete_position(int);
    List()
    {
        head=NULL;
        tail=NULL;
    }
    ~List();
};

List::~List()
{
    //dtor
}
void List::createNode(int value)
{
    node* temp=new node;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->data=value;
        temp->next=NULL;
    }else{
        temp->data=value;
        tail->next=temp;
        tail=temp;
    }
}

void List::displayList()
{
    node* temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<'\n';
        temp=temp->next;
    }
}

void List::insert_start(int value)
{
    node* temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
}

void List::insert_position(int pos, int value)
{
    node* pre=new node;
    node* curr=new node;
    node* temp=new node;
    curr=head;
    for(int i=1; i<pos; i++)
    {
        pre=curr;
        curr=curr->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=curr;
}

void List::delete_first()
{
    node* temp=head;
    head=head->next;
    delete temp;
}

void List::delete_last()
{
    node* curr=new node;
    node* prev=new node;
    curr=head;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    tail=prev;
    prev->next=NULL;
    delete curr;
}

void List::delete_position(int pos)
{
    node* curr=new node;
    node* prev=new node;
    curr=head;
    for(int i=1; i<pos; i++)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    delete curr;
}

int main()
{
    List L;
    L.createNode(15);
    for(int i=14; i>=1; i--)
    {
        L.insert_start(i);
    }
    L.displayList();
    L.insert_position(10, 100); //inserts 100 between 9 & 10
    L.displayList();
    L.delete_first(); //deletes the first node (the 1)
    L.displayList();
    L.delete_last(); //deletes the last node (the 15)
    L.displayList();
    L.delete_position(3); //deletes the 3rd position which equals 4
    L.displayList();
    return 0;
}
