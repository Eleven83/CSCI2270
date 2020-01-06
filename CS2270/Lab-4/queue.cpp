#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
    string word;
    Node *next;
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue();
    int size;
    int capacity;
    void enqueue(string word);
    Node* dequeue();
    void createQueue();
    void printQueue();
    bool isEmpty();
    bool isFull();
};

Queue::Queue()
{
    this->head = NULL;
    this->tail = NULL;
    int size = 0;
    int capacity = 10;
}

void Queue::enqueue(string word)
{
    cout<<"Enqueuing: "<<word<<endl;
    Node *temp=new Node;
    if(!isFull())
    {
        tail->next=temp;
        temp->word=word;
        tail=temp;
        temp->next=NULL;
    }else{
        cout<<"Queue is full, cannot add word."<<endl;
    }
    size++;
}

void Queue::createQueue()
{
    string name, fruit, city, animal;
    cout<<"Please enter a name:\n";
    getline(cin, name);
    cout<<"Please enter a fruit:\n";
    getline(cin, fruit);
    cout<<"Please enter a city:\n";
    getline(cin, city);
    cout<<"Please enter your favorite animal:\n";
    getline(cin, animal);

    Node *node1 = new Node;
    node1->word=name;
    node1->next = NULL;
    this->head = this->tail = node1;
    this->size++;

    Node *node2 = new Node;
    node2->word=fruit;
    node2->next = NULL;
    this->head->next = node2;
    this->tail = node2;
    this->size++;

    Node *node3 = new Node;
    node3->word=city;
    node3->next = NULL;
    this->head->next->next = node3;
    this->tail = node3;
    this->size++;

    Node *node4 = new Node;
    node4->word=animal;
    node4->next = NULL;
    this->head->next->next->next = node4;
    this->tail = node4;
    this->size++;
}

void Queue::printQueue()
{
    cout<<"QUEUE ELEMENTS:"<<endl;
    Node *iterator=this->head;
    while(iterator->next!=NULL)
    {
        cout<<iterator->word<<" ";
        iterator=iterator->next;
    }
    cout<<iterator->word<<endl;
}

bool Queue::isEmpty()
{
    return (size == 0);
}

bool Queue::isFull()
{
    return (size == 10);
}

/*
/////////////////////////////////////
*************************************
      Implement this function
*************************************
/////////////////////////////////////
*/
// void Queue::enqueue(string word)
// {
//     cout<<"Enqueuing: "<<word<<endl;
//     Node *temp=new Node;
//     if(!isFull())
//     {
//         tail->next=temp;
//         temp->word=word;
//         tail=temp;
//         temp->next=NULL;
//     }else{
//         cout<<"Queue is full, cannot add word."<<endl;
//     }
//     size++;
// }

/*
/////////////////////////////////////
*************************************
      Implement this function
*************************************
/////////////////////////////////////
*/
struct Node* Queue::dequeue()
{
    cout<<"Dequeuing..."<<endl;
    Node *trash;
    trash=head;
    head=head->next;
    delete trash;
    size--;

    return NULL;
}

int main()
{
    Queue q;
    q.createQueue();

    // 1 --> 2 --> 3 --> 4
    q.printQueue();
    /*
    TODO:UNCOMMENT THE BELOW CODE ONCE enqueue() and dequeue() are implemented
    */
    cout<<"PERFORMING QUEUE OPERATIONS\n";
    cout<<"===========================\n";
    // Expected  1 --> 2 --> 3 --> 4 --> 5
    q.dequeue();
    q.printQueue();
    // Expected 2 --> 3 --> 4 --> 5
    q.dequeue();
    q.printQueue();
    // Expected 3 --> 4 --> 5
    q.dequeue();
    q.printQueue();
    // Expected 3 --> 4 --> 5 --> 6
    q.enqueue("Apple");
    q.printQueue();
    // Expected 4 --> 5 --> 6
    q.dequeue();
    q.printQueue();

    return 0;
}
