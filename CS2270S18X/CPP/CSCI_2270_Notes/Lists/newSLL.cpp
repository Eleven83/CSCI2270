#include <iostream>

using namespace std;

struct Node
{
	string cityName;
	string message;
	Node *next;
};

Node *addNode(Node *head, string s)
{
	Node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node *newNode=new Node;
	newNode->cityName=s;
	newNode->next=NULL;
	temp->next=newNode;
	
	return head;
}
Node *insertAfter(Node *head, string newCity, string prevCity)
{
	Node *temp=head;
	while(temp->cityName!=newCity)
	{
		temp=temp->next;
	}


	return head;
}
Node *delNode(Node *head, string delCity)
{

	return head;
}
void printList(Node *head)
{
	Node *temp=new Node();
	while(temp!=next)	
}

int main()
{
	Node *head=new Node();
	head->cityName="Los Angeles";
	head->next=NULL;

	
	return 0;
}