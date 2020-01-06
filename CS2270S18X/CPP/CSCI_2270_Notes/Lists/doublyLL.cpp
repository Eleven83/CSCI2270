#include <iostream>
#include "doublyLL.h"
using namespace std;


doublyLL::doublyLL() {
	//default constructor does nothing explicit
}

doublyLL::doublyLL(int nodeID) {
	head = createNode(nodeID,nullptr,nullptr);
	tail = head;
}

doublyLL::~doublyLL() {
	//iterate through list and delete it
	deleteList();
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}

	return true;
}

void doublyLL::deleteList() {
	Node* currentNode = head;
	Node* tmpNode;
	while (currentNode != nullptr) {
		tmpNode = currentNode->next;
		cout << "deleting node " << currentNode->id << endl;	//this is useful to make sure what you think should happen does, but it's not necessary
		delete currentNode;
		currentNode = tmpNode;
	}
}

void doublyLL::printList(string whereToStart) {
	if (head == nullptr) {
		cout << "empty list, nothing to print" << endl;
	}
	else {
		if (whereToStart == "head") {
			//start at the head
			Node* currentNode = head;
			cout << "NULL ";
			while (currentNode != nullptr) {
				cout << " <-> " << currentNode->id;
				currentNode = currentNode->next;
			}
			cout << " <-> NULL" << endl;
		}
		else if (whereToStart == "tail") {
			//start at the tail and go backwards
			Node * currentNode = tail;
			cout << "NULL ";
			while (currentNode != nullptr) {
				cout << " <-> " << currentNode->id;
				currentNode = currentNode->prev;
			}
			cout << " <-> NULL" << endl;
		}
		else {
			cout << "invalid start point parameter" << endl;
		}
	}
}
