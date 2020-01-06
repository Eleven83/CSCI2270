#include "HW4-Todo-StackArray.hpp"
#include <iostream>

using namespace std;

TodoStackArray::TodoStackArray()
{
    stackTop=-1;
}

bool TodoStackArray::isEmpty()
{
    return (stackTop==-1);
}

bool TodoStackArray::isFull()
{
    return(stackTop==MAX_STACK_SIZE-1);
}

void TodoStackArray::push(std::string todoItem)
{
    if(isFull())
    {
        cout<<"Stack full, cannot add new todo item."<<endl;
    }else{
        stackTop=0;
        stack[stackTop].todo=todoItem;
        return;
    }
    stackTop++;
}
void TodoStackArray::pop()
{
    if(isEmpty())
    {
        cout<<"Stack empty, cannot pop an item."<<endl;
        return;
    }
    stackTop--;
}
TodoItem TodoStackArray::peek()
{
    if(isEmpty())
    {
        cout<<"Stack empty, cannot peek."<<endl;
    }
    return stack[stackTop];
}
