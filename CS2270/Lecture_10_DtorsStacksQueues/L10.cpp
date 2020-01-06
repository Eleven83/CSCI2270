/* Demonstrating Destructors */
#include <iostream>

using namespace std;

struct node
{
    int key;
    node *next;
    node(int k, node *n)
    {
        key=k;
        next=n;
        cout<<"node constructor called..."<<endl;
    }
    node(){};
    //this code is called when the object is deleted
    ~node(){
        cout<<"node destructor called..."<<endl;
        cout<<"delete "<<key<<endl;
    }
};

//Your code should separate these into .cpp and .h files
class myClass{
private:
    node *head;
    node n;

public:
    myClass()
    {
        head=new node(1, NULL);
        cout<<"myClass constructor called..."<<endl;
    }
    ~myClass()
    {
        //Destroy memory here
        cout<<"myClass destructor called..."<<endl;
        delete head;
    }
};

int main()
{
    node *a=new node(1, NULL);
    cout<<a<<endl; //Prints out hexadecimal address
    node *head=new node(2, NULL);
    cout<<head<<endl; //some other address
    head=a; //change header pointer, memory leak
    cout<<"Head: "<<head<<endl; //Can never go back to memory allocated
    //Correct way is to not allocate memory for head
    //Just point head to a
    node *current=NULL;
    int i=10;
    while(i<19)
    {
        current=new node(i, NULL);
        head->next=current;
        head=current;
        i++;
    }
    cout<<"after loop: "<<endl;
    cout<<"head: "<<head<<endl;
    cout<<"current: "<<current<<endl;
    cout<<"a: "<<a<<endl;

    head=a;
    for(int i=0; i<10; i++)
    {
        cout<<a->key<<" "<<a<<" "<<a->next<<endl;
        a=a->next;
    }
    delete current; //calls a default destructor for the object
    myClass mc;

    cout<<"Dynamic memory example: "<<endl;

    myClass *mc2=new myClass;

    node n(1, NULL); //Destructor called for this object when program is cleaning up for exit
    //Destructor never called for dynamically allocated objects, unless you call it.
    //Modified the myClass destructor to free the head node

    return 0;
}
