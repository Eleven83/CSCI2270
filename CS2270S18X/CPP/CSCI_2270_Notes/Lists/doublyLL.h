#ifndef doublyLL_H	//header guards prevent multiple inclusions breaking things
#define doublyLL_H

using namespace std;

struct Node {
	int id = -1;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class doublyLL {
	private:
		Node* createNode(int,Node*,Node*);
		void deleteList();
		Node* head = nullptr;
		Node* tail = nullptr;

	public:
		bool insertNodeAtEnd(int);
		void printList(string);
		doublyLL();
		doublyLL(int);	//overloaded constructor
		~doublyLL();	//destructor
};


#endif