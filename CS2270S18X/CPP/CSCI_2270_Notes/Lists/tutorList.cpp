#include <iostream>

using namespace std;

struct Node
{
    string data;
    string message;
    Node* next;
    Node* previous;
};

Node* addNode(Node* head, string s)
{
    //traverse the list to find null. That's where the new node goes
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    //temp->next is now null.
    //Now that I found null, make a newNode pointer to a new node.
    Node* newNode=new Node(); //parenthesis are for if this were a constructor
    //assign a value to the new nodes data.
    newNode->data=s;
    newNode->next=NULL; //because it's going in at the end.
    temp->next=newNode; //update temp->next to point to the new node.

    return head;
}

Node* insertAfter(Node* head, string oldData, string newData)
{
    Node* temp=head;
    while(temp->data!=oldData)
    {
        temp=temp->next;
    }
    Node* newNode=new Node();
    newNode->data=newData;
    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

Node* deleteNode(Node* head, string s)
{
    Node* temp=head;
    if(head->data==s)
    {
        head=head->next;
        delete(temp);
        return head;
    }
    while(temp->next->data!=s)
    {
        temp=temp->next;
    }
    Node* deleteVal=temp->next;
    temp->next=deleteVal->next;
    delete(deleteVal);

    return head;

}

void sendMsg(Node* head, string msg)
{
    Node* temp=head;
    temp->message=msg;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<endl;
        cout<<temp->message<<endl;
        temp->next->message=temp->message;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    cout<<temp->message<<endl;
}

void printList(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    Node* head= new Node();
    head->next=NULL;
    head->data="Dallas";

    addNode(head, "Denver");
    addNode(head, "Los Angeles");
    addNode(head, "Boulder");
    printList(head);

    deleteNode(head, "Boulder");
    printList(head);

    insertAfter(head, "Denver", "Sarasota");
    printList(head);

    sendMsg(head, "hi");

    return 0;
}
