#include <iostream>

using namespace std;

//create a struct
struct node
{
    int data;
    node *next;
};

node* addNode(node* head, int score)//this inserts the new node at the 1st null spot.
{
    node* temp=head;
    while(temp->next!=NULL)//traverse the ll
    {
        temp=temp->next;
    }
    //found null. Now make a pointer to a new node.
    node* newNode= new node;
    //assign the score input to the data member of newNode
    newNode->data=score;
    //assign newNode next to point to NULL because it's the end of the list
    newNode->next=NULL;
    temp->next=newNode;

    return head;
}
//Print the list of data in each node
void printList(node* head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}
int main()
{
    node* head=new node;
    head->data=0;
    head->next=NULL;
    addNode(head, 50);
    addNode(head, 55);
    addNode(head, 100);
    addNode(head, 105);
    addNode(head, 150);
    addNode(head, 350);
    printList(head);

    return 0;
}
