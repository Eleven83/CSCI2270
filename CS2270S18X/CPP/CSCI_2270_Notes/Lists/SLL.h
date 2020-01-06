#ifndef SLL_H
#define SLL_H

struct Node
{
	string item;
	Node *next;
};

class SLL
{
private:
	Node *head, *tail;

public:
	SLL(); // constructor declaration

	~SLL();

	void growList( string newItem );


	void displayList();

};


#endif