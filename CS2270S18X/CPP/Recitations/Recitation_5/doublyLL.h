#ifndef doublyLL_H
#define doublyLL_H

using namespace std;

struct Node
{
	int id=-1;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class doublyLL
{
	private:
		Node* createNode(int,Node*,Node*);
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		bool insertNodeAtEnd(int);
		void delElm(Node, string);
		void dispItem();
		doublyLL();	//default constructor
		doublyLL(int);	//overloaded constructor
		~doublyLL();	//destructor
};

#endif
