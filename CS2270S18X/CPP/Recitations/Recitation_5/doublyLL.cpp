#include <iostream>
#include "doublyLL.h"

using namespace std;

doublyLL::doublyLL()
{

}

doublyLL::doublyLL(int nodeID)
{
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL()
{

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext)
{
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID)
{
	if (head == nullptr)
	{
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else
	{
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}
void doublyLL::delElm(Node *head, int idVal)
{
	Node *current=head;
	while(current!=NULL)
	{
		if(current->id==idVal)
		{
			if(current==head)
			{
				Node *temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
			}else if(current==tail){
				Node *temp=tail;
				tail=tail->prev;
				tail->next=NULL;
				delete temp;
			}else{
				current->prev->next=current->next;
				current->next->prev=current->prev;
				delete current;
			}
		}else{

		}
	}
}
void doublyLL::dispItem(Node *head)
{

}

Node * searchLL( Node *head, string target )
{
	Node *current;
	current = head;

	while(current!=nullptr)
	{
		if(current->item == target)
			return current;
		else
			current = current->next;
	}

	return nullptr;
}
