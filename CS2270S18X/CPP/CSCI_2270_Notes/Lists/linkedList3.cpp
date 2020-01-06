#include <iostream>

using namespace std;

// Circularly defined type
struct Node
{
	string item;
	Node *next;
};

Node *searchLL(Node *head, string target);

// Insert a blank node at beginning of list
Node *insertHead(Node *head, string newItem);

// Insert after given node
void insertAfter(Node *prevNode, string newItem);

// Append new node at the end
void appendEnd(Node *head, string newItem);

// Delete a node, return new head
Node *deleteNode(Node *head, Node *delTgt);

int main()
{
	string a[]={"uno", "dos", "tres", "cuatro"};

	Node *head, *current, *tmp;
	head=new Node;
	current=new Node;

	head->item=a[0];
	head->next=nullptr;

	current=head;
	int i=0;
	while(i<4)
	{
		// create new node; use tmp to point to it
		tmp=new Node;

		// populate the payload of tmp with i-th array element
		tmp->item=a[i];
		// in case it's the last element, set current node to indicate end
		tmp->next=nullptr;

		// at this point "current" is still pointing to previous element
		// (could be head)
		// connect the previous element such that it is pointing to the newly created one (tmp)
		current->next=tmp;

		// move forward. Make current point to the new element
		current=tmp;
		i++;
	}
	head = insertHead( head, "cero");
	Node *targetAddress = searchLL( head, "dos" );
	insertAfter( targetAddress, "dos y medio" );
	appendEnd( head, "cinco" );
	appendEnd( head, "seis" );
	Node *deleteTarget = searchLL( head, "dos y medio" );
	head = deleteNode( head, deleteTarget );
	cout<<"Traverse and print the LL: "<<endl;
	current=head;

	while(current!=nullptr)
	{
		cout<<current->item<<endl;
		cout<<current<<endl;
		current=current->next;
	}

	return 0;
}

Node *searchLL(Node *head, string target)
{
	Node *current;
	current=head;

	while(current!=nullptr)
	{
		if(current->item==target)
			return current;
		else
			current=current->next;
	}

	return nullptr;
}

Node *insertHead(Node *head, string newItem)
{
	// Create a new node and tmp poitner
	Node *tmp=new Node;
	tmp->item=newItem;
	// Link new node with old head
	tmp->next=head;
	// Return head pointer (pointing to new head)
	return tmp;
}

void insertAfter(Node *prevNode, string newItem)
{
	// Create new node
	Node *tmp=new Node;
	tmp->item=newItem;
	// Link new node with next node
	tmp->next=prevNode->next;
	// Link prevNode with new node
	prevNode->next=tmp;
	tmp=nullptr;
}

void appendEnd(Node *head, string newItem)
{
	Node *tmp=new Node;
	tmp->item=newItem;
	// set current to head
	Node *current=head;
	// create node for keeping track of last (previous) node
	Node *last;
	// find the tail of list
	while(current!=nullptr )
	{
		last=current;
		current=current->next;
	}
	// link previous node with new node
	last->next=tmp;
	// make new tail point to null
	tmp->next=nullptr;
}

Node *deleteNode(Node *head, Node *delTgt)
{
	Node *prev, *current;
	current=head;
	// If the node to be deleted is head
	if(delTgt==head)
	{
		// make new head point to next node
		head=head->next;
		// deallocate memory for deleted node
		delete delTgt;
		// return the new head
		return head;
	}
	else
	{
		// if delTgt is not head, look for node previous to delTgt
		while(current!=delTgt)
		{
			prev=current;
			current=current->next;
			cout<<current<<endl;
		}
		// Link previous node with next node
		prev->next=current->next;
		delete current;
		return head;
	}
}
