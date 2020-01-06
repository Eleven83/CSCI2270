/* Queue - Linked List Implementation */
#include <iostream>

using namespace std;

//Done with classes. (You can also do this with structs)
struct Node
{
    int data;
    Node *next;
};
//Creating the class. Every Queue will be an instance of this class.
class Queue
{
private:
    Node *head;
    Node *tail;
    Node *prev;
    Node *temp;
    //Notice the methods are inline
    //In cpp this is possible, however, you can avoid doing this by using headers
    //When is the Queue empty?
        //When the head is NULL
    bool isEmpty()
    {
        return head==NULL;
    }
public:
    //Default constructor. Every instance of the class has head and tail initialized to NULL.
    Queue()
    {
        head=NULL;
        tail=NULL;
    }
    //Enqueuing the element x
    void enqueue(int x)
    {
        temp=new Node;
        temp->data=x;
        temp->next=NULL;
        if(isEmpty())
        {
            //Initializing the head and tail
            head=temp;
            tail=temp; //This happens for thefirst element in a Queue or
                        //while Enqueuing the next element after the Queue is empty
        }else{
            prev=tail;
            tail->next=temp; //FIFO, thus the element is enqueued at the rear.
            tail=temp;
        }
    }
    void dequeue()
    {
        temp=head;
        head=head->next;//Element is removed from the front
        delete temp;
    }
    void find(int x) //Extra function in case you have to search in a Queue
    {
        for(int i=0; head->next!=NULL; i++)
        {
            if(temp->data==x)
            {
                cout<<"Found at position: "<<i<<endl;
            }else if(temp->next==NULL){
                cout<<"Error: Number not found..."<<endl;
            }
        }
    }
    void display() //Displaying all the elements in the queue
    {
        if(!isEmpty())
        {
            for(temp=head; temp!=NULL; temp=temp->next)
            {
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }else{
            cout<<"Queue is empty!"<<endl;
        }
    }
};

int main()
{
    Queue q;
    q.display();
    q.enqueue(15);
    q.display();
    q.enqueue(25);
    q.display();
    q.enqueue(35);
    q.display();
    q.enqueue(45);
    q.display();
    //q.find(15);
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    return 0;
}
