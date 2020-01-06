#ifndef LinkList_H
#define LinkList_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "patStruct.h"

using namespace std;

struct Node
{
    string name;
    int priority, treatment;
    Node* next;
    Node* prev;
    Node(string x, int y, int z)
    {
        name=x;
        priority=y;
        treatment=z;
        next=prev=NULL;
    }
};

class PQLL
{
public:
    PQLL();
    ~PQLL();
    void push(string, int, int);
    string pop();
    bool isEmpty();
    void display();
    int length();
    void search(string);
    Node* pop2();

private:
    Node* head;
    Node* tail;
    int size;
    bool compare(Node*,Node*);
};

#endif
