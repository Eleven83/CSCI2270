/* Stack Linked List Implementation */
#include <iostream>

using namespace std;

struct Node
{
    int id=-1;
    Node* next=nullptr;
};

class llStack{
private:
    Node* head=nullptr;
    void deleteStack();
    Node* createNode(int, Node*);
    bool isEmpty();
public:
    llStack();
    llStack(int);
    ~llStack();
    bool push(int);
    bool pop(int&);
    bool peek(int&);
};

llStack::llStack(){}; //Default constructor

llStack::llStack(int itemToAdd) //parameterized constructor
{
    Node* newNode=createNode(itemToAdd, nullptr);
    head=newNode;
}

Node* llStack::createNode(int nodeID, Node* nodeNext)//creates an instance of a node
{
    Node* newNode=new Node;
    newNode->id=nodeID;
    newNode->next=nodeNext;

    return newNode;
}

llStack::~llStack()//Destructor
{
    deleteStack();
}

//IMPLEMENT THIS FUNCTION
void llStack::deleteStack()
{
    Node* current, *temp;
    current=head;
    temp=head;
    while(current!=NULL)
    {
        current=current->next;
        delete temp;
        temp=current;
    }
    cout<<"Stack deleted."<<endl;
}

bool llStack::push(int itemToAdd)
{
    //new nodes in the stack go where?
        //The head
    Node* newNode=createNode(itemToAdd, head);
    head=newNode;

    return true;
}

bool llStack::pop(int& itemToGet)
{
    //Where do we always always pop from?
        //The head
    if(!isEmpty())
    {
        itemToGet=head->id;
        //Remove head
        Node* temp=head;
        head=head->next;
        //What becomes the new head?
        head=head->next;
        delete temp;

        return true;
    }else{
        cout<<"Stack is empty."<<endl;
        return false;
    }
}

bool llStack::isEmpty()
{
    //checks if the stack is empty by checking the status of null
    if(head==nullptr)
    {
        return true;
    }else
        return false;
}

int main()
{
    //Implement this in your system and your concepts will become crystal clear
    llStack stackOne(15);
    stackOne.push(33);

    int nodeIDToGet;
    if(stackOne.pop(nodeIDToGet))
    {
        cout<<"Node with id "<<nodeIDToGet<<" just removed from the stack."<<endl;
    }
    if(stackOne.pop(nodeIDToGet))
    {
        cout<<"Node with id "<<nodeIDToGet<<" just removed from the stack."<<endl;
    }
    if(stackOne.pop(nodeIDToGet))
    {
        cout<<"Node with id "<<nodeIDToGet<<" just removed from the stack."<<endl;
    }

    return 0;
}
