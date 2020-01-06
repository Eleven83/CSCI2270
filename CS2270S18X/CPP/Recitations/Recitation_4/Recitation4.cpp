#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* next;
};

Node* addNode(Node* head, int s)
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newNode=new Node;
    newNode->key=s;
    newNode->next=NULL;
    temp->next=newNode;

    return head;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->key<<endl;
        temp=temp->next;
    }
}

int main()
{
    Node* head=new Node;
    head->key=5;
    head->next=NULL;
    int arr[]={2,5,6,7,4,3};
    for(int i=0; i<6; i++)
    {
        addNode(head, arr[i]);
    }
    cout<<"Before: "<<endl;
    display(head);

    return 0;
}
