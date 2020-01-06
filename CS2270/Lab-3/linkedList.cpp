/*
Ryan Hoffman
CSCI 2270 - Lab 3
TA: Saumya
*/

#include <iostream>

using namespace std;

/*
Class Node
*/
class Node
{
public:
	int data;
	Node *next;
	Node(int data);
};
/*Struct Node
struct Node
{
    int data;
    Node *next;
};
*/

/*
Class List - Consists of all operations and data related to a linked list.
*/
class LinkedList
{
public:
	Node *head;
	int size;
	LinkedList();

	// Insert and traversal Functions
	void insertAtHead(int data);
	void insertAtIndex(int index, int data);
	void insertAtTail(int data);
	int getValAtIndex(int index);
	void printList();

  // Delete functions
	bool deleteAtHead();
	bool deleteAtIndex(int index);
	bool deleteAtTail();

};

/*
Node Constructor
*/
Node::Node(int data)
{
	this->data = data;
	this->next = NULL;
}

/*
LinkedList Constructor
*/
LinkedList::LinkedList()
{
	this->size = 0;
	this->head = NULL;
}

/*
Inserts a node at the start of the list.
*/
void LinkedList::insertAtHead(int data)
{
	Node *newNode = new Node(data);
	newNode->next = this->head;
	this->head = newNode;
	this->size++;
}

/*
Inserts a node at at a given index.
*/
void LinkedList::insertAtIndex(int index, int data)
{
	Node *newNode = new Node(data);

	if(index > this->size - 1)
	{
		cout<<"Cannot insert at this index"<<endl;
		return;
	}

	Node *prev = NULL;
	Node *temp = this->head;
	for(int i = 0; i < index; i++)
	{
		prev = temp;
		temp = temp->next ;
	}
	prev->next = newNode;
	newNode->next = temp;
	this->size++;
}

/*
Inserts a node at the end of the list.
*/
void LinkedList::insertAtTail(int data)
{
	Node *temp = this->head;
	Node *newNode = new Node(data);

	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	this->size++;
}

/*
Get the value of a node at a given index
*/
int LinkedList::getValAtIndex(int index)
{
	// If index is greater than size then the position does not exist
	if(index > size)
	{
		cout<<"Index greater than size";
		return -1;
	}

	Node *temp = this->head;
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

/*
Prints the values of all the nodes in order.
*/
void LinkedList::printList()
{
	Node *temp = this->head;
	while(temp->next != NULL)
	{
		cout<<temp->data;
		cout<<"->";
		temp = temp->next;
	}
	cout<<temp->data;
	cout<<" "<<endl;
}

// Implement these functions
bool LinkedList::deleteAtHead()
{
	bool isDeleted = false;

	if(this->size == 0)
	{
		cout<<"No nodes to delete"<<endl;
		return isDeleted;
	}
  Node *temp = this->head;
	this->head = temp->next;
	delete temp;
  isDeleted = true;
  this->size--;
	return isDeleted;
}
/******************************************************
*******************************************************
					Implement this function
*******************************************************
*******************************************************
*/
bool LinkedList::deleteAtIndex(int n)
{
	bool isDeleted = false;

    Node *temp=this->head;
    Node *prev=NULL;

    for(int i=0; i<n; i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
    this->size--;
    isDeleted=true;

	return isDeleted;
}

bool LinkedList::deleteAtTail()
{
	bool isDeleted = false;

	if(this->size == 0)
	{
		cout<<"No nodes to delete"<<endl;
		return isDeleted;
	}

	Node *pres = this->head;
	Node *prev = NULL;

	while(pres->next != NULL)
	{
		prev = pres;
		pres = pres->next;
	}
	prev->next = NULL;
	delete pres;
	this->size--;
	isDeleted = true;

	return isDeleted;
}


int main()
{
	LinkedList list;
	cout<<"Adding nodes to list:"<<endl;
	// 2
	list.insertAtHead(2);
	list.printList();
	// 1->2
	list.insertAtHead(1);
	list.printList();
	// 1->2->3
	list.insertAtTail(3);
	list.printList();
	// 1->2->7->3
	list.insertAtIndex(2, 7);
	list.printList();
	// 1->2->7->10->3
	list.insertAtIndex(3, 10);
	list.printList();
	cout<<endl;

	cout<<"Running delete functions."<<endl;



	// Expected - 2->7->10->3
	cout<<"Deleting node at head:"<<endl;
	if(!list.deleteAtHead())
	{
		cout<<"Delete failed!"<<endl;
	}
	list.printList();
	cout<<endl;

	/*******************************
			Implement this function
	********************************/
	// Expected - 2->7->3
	cout<<"Deleting node at index 2:"<<endl;
	if(!list.deleteAtIndex(2))
	{
		cout<<"Delete failed!"<<endl;
	}
	list.printList();
	cout<<endl;

	// Expected - 2->7
	cout<<"Deleting node at end:"<<endl;
	if(!list.deleteAtTail())
	{
		cout<<"Delete failed!"<<endl;
	}
	list.printList();
}
