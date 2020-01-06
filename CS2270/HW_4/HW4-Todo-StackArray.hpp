#ifndef HW4_TODO_STACKARRAY
#define HW4_TODO_STACKARRAY
#include <string>

struct TodoItem
{
    std::string todo;
};

const int MAX_STACK_SIZE = 5;

class TodoStackArray
{
public:
    TodoStackArray();
    bool isEmpty();
    bool isFull();
    void push(std::string todoItem);
    void pop();
    TodoItem peek();
    int getStackTop() { return stackTop; }
    TodoItem* getStack() { return stack; }
private:
    int stackTop; //the index in stack[] that will be popped next
    TodoItem stack[MAX_STACK_SIZE];
};
#endif
