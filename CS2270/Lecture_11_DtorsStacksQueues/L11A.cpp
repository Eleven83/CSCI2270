/* Stack - Array Implementation */
#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class arrStack
{
public:
    arrStack();
    ~arrStack();
    bool isEmpty(); //Might want to make this private
    bool isFull(); //Might want to make this private
        //Modularizing your code is always a good idea
    int peek();
    int pop();
    bool push(int);
private:
    int stackOInts[MAX_SIZE]; //If we wanted to be able to resize this, what would we need to do?
    int currentSize;
};

arrStack::arrStack()
{
    currentSize=0;
    //constructor
}

arrStack::~arrStack()
{
    //Destructor
    //Destroys instances to free memory
}

bool arrStack::isEmpty()
{
    if(currentSize==0)
    {
        return true; //No elements left, hence empty
    }
    return false;
}

bool arrStack::isFull()
{
    if(currentSize==MAX_SIZE)
    {
        return true; //Array is filled to the brim, hence full
    }
    return false;
}

bool arrStack::push(int itemToAdd)
{
    //If push is successful, return true
    //Check if stack is full
    if(isFull())
    {
        return false;
    }else{
        stackOInts[currentSize]=itemToAdd;
        currentSize+=1;
        return true;
    }
}

int arrStack::pop()
{
    //Returns the element at the top (TopOfStack) and deletes it from the stack
    if(!isEmpty())
    {
        int itemToReturn=stackOInts[currentSize-1];
        currentSize-=1;
        return itemToReturn;
    }else{
        cout<<"Stack is empty!"<<endl;
        return -999999999; //If your stack stores pointers, you can return nullptr here
    }
}

int arrStack::peek()
{
    //Returns what is at the top of the stack but DOES NOT DELETE IT
    if(!isEmpty())
    {
        return stackOInts[currentSize-1];
    }else{
        cout<<"Stack is empty!"<<endl;
        return -999999999;
    }
}

int main()
{
    //Pilot function to demonstrate an array stack
    arrStack stackey;
    if(!stackey.isEmpty())
    {
        cout<<"Stack is empty!"<<endl;
    }
    if(stackey.push(33))
    {
        cout<<"33 added to the stack."<<endl;
    }
    if(stackey.push(44))
    {
        cout<<"44 added to the stack."<<endl;
    }
    if(stackey.push(2))
    {
        cout<<"2 added to the stack."<<endl;
    }
    if(stackey.push(19))
    {
        cout<<"19 added to the stack."<<endl;
    }
    if(stackey.push(4))
    {
        cout<<"4 added to the stack."<<endl;
    }
    if(stackey.push(13))
    {
        cout<<"13 added to the stack."<<endl;
    }else{
        cout<<"13 not added to the stack. -- Stack is full."<<endl;
    }
    cout<<"What's at the top of the stack? "<<stackey.peek()<<endl;
    stackey.pop();
    stackey.pop();
    cout<<"What's at the top of the stack? "<<stackey.peek()<<endl;
    stackey.push(100);
    cout<<"What's at the top of the stack? "<<stackey.peek()<<endl;

    return 0;
}
