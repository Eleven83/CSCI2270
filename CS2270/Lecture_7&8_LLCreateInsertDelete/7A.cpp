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
    }
};
int main()
{
    node *x=new node(5, NULL); //using the constructor to create a node
    cout<<x->key<<endl; //(*x).key
    cout<<(*x).key<<endl; //(*x).key
    //Both the statements above perform the same task

    node *x2=new node(6, NULL); //creating another node
    x->next=x2; //setting the next pointer of x to x2
    cout<<x2<<endl; //should print the address of x2
    cout<<x->next<<endl; //should also print address of x2

    x2->key=10; //assigning a value to the key of x2

    //Traversal

    node *p=x; //point to same memory address as x
    while(p!=NULL)
    {
        cout<<p->key<<endl;
        p=p->next;
    }

    return 0;
}
