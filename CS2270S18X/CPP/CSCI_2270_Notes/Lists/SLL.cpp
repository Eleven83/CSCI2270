#include <iostream>
using namespace std;

#include "SLL.h"

SLL::SLL() // constructor definition
{
	head = nullptr;
	tail = nullptr;
}

SLL::~SLL()
{
	Node *tmp, *current=head;
	while(current!=nullptr)
	{
		tmp=current->next;
		delete current;
		current=tmp;
	}
}

void SLL::growList(string newItem)
{
	if(head==nullptr)
	{
		head=new Node;
		head->item=newItem;
		head->next=nullptr;
		tail=head;
	}
	else
	{
		Node *temp=new Node;
		temp->item=newItem;
		// next, link tail with new node
		tail->next=temp;
		tail=temp;
		tail->next=nullptr;
	}
}

void SLL::displayList()
{
	Node *current=head;

	while(current!=nullptr)
	{
		cout<<current->item<<endl;
		current=current->next;
	}
}
