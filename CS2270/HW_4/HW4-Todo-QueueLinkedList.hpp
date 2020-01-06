#ifndef MADLIBLINKEDLIST
#define MADLIBLINKEDLIST

#include <string>

struct MadLibNode
{
    string word;
    MadLib *next;
};

class MadLibLinkedList
{
public:
    MadLibLinkedList();
    ~MadLibLinkedList();
    bool isEmpty();
    void enqueue(string wordToInput);
    void dequeue();
    MadLibNode* peek();
    MadLibNode* getQueueFront() { return queueFront; }
    MadLibNode* getQueueEnd() { return queueEnd; }
private:
    MadLibNode* queueFront; // the item in the list that will be dequeued next
    MadLibNode* queueEnd; // the item in the list that was most recently enqueued
};
#endif
